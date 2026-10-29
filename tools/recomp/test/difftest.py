"""Differential tests for tools/recomp: decompiled C (built natively) vs the recompiled original asm.

  .venv/Scripts/python.exe tools/recomp/test/difftest.py [--trials 1000] [--seed 1] [--target main ...]

Steps:
  1. Compile each src/ file for the host (clang, i686-pc-windows-msvc, C++) with the shim in
     tools/recomp/test/shim. Files that fail are recorded (that is the host-compile measurement)
     and their functions are not tested.
  2. Pick decompiled free functions with C linkage that have no GTE or inline asm, take only
     integer/pointer arguments and return void, an integer or a pointer, and are leaves or call only
     functions that are in the native build too (--no-calls: leaves only). Signatures come from
     clang's AST of the decompiled source; the asm is the original under asm/<target>/matchings/.
  3. Recompile those functions from their original asm (prefix recomp_).
  4. Generate globals.s (every data symbol either side uses, laid out at its PS1 address offsets)
     and cases.c, link one runner per target with harness.c, run it, and report.

Output goes to build/recomp-test/ (git-ignored). Exit status 1 if any function outside KNOWN mismatches.
See docs/RECOMP.md, "Differential tests".
"""
import argparse
import json
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT))

from tools.recomp import hostcc  # noqa: E402
from tools.recomp.analyze import Program, TARGETS  # noqa: E402
from tools.recomp.cli import translate  # noqa: E402
from tools.recomp.emit import Protos  # noqa: E402

BUILD = ROOT / "build" / "recomp-test"
RUNTIME = HERE.parent / "runtime"
SHIM = HERE / "shim"
NM = hostcc.LLVM_BIN / "llvm-nm.exe"
FUNC_RE = re.compile(r"^func_[0-9A-F]{8}$")
DSYM_RE = re.compile(r"^D_([0-9A-F]{8})$")
GTE_OPS = {"cop2", "mtc2", "mfc2", "ctc2", "cfc2", "lwc2", "swc2"}
CALL_KINDS = {"call", "icall", "tail", "itail", "condtail"}
WINDOW = 0x1000
PROG = None
# Functions whose two builds differ for a reason that is not the recompiler's. They are run and reported,
# and do not fail the test.
KNOWN = {
    "func_80020368": "stores the address of a stack temporary (its vtable copy) into the object; the two "
                     "builds have different stacks, so that word differs",
    "func_8008D5E8": "the decompiled C reads e[6] after its store to v[0xA]; the original asm (and so the "
                     "recompiled code) reads it before. They differ only when the random pointers make e and "
                     "v overlap",
    "func_800193AC": "copies a 20-byte struct through a pointer it loads from memory; when the random pointer "
                     "overlaps the destination the word-by-word copy (asm) and memcpy (clang) differ",
    "func_800627E8": "copies a 160-byte struct from a table whose address it loads from memory: same overlapping-copy "
                     "case as func_800193AC",
}
DECOMP_FLAGS = ["-w", "-Dmain=game_main", "-fno-finite-loops", "-fno-exceptions", "-fno-rtti"]


def run(cmd, **kw):
    return subprocess.run([str(c) for c in cmd], capture_output=True, text=True, **kw)


# ------------------------------------------------------------------ step 1: decompiled C on the host
def src_target(src):
    return "main" if src.parent.name == "main" else src.parent.name


def compile_src(src):
    obj = BUILD / "decomp" / (src.parent.name + "_" + src.stem + ".obj")
    obj.parent.mkdir(parents=True, exist_ok=True)
    cmd = hostcc.compile_cmd(src, obj, includes=[SHIM, ROOT / "include"], lang="c++", extra=DECOMP_FLAGS)
    r = run(cmd, cwd=ROOT)
    errors = [ln for ln in r.stderr.splitlines() if ": error:" in ln]
    return src, obj if r.returncode == 0 else None, errors


def ast_functions(src):
    """FunctionDecls with a body, from clang's JSON AST: name -> decl dict."""
    cmd = [hostcc.CLANG] + hostcc.COMMON_FLAGS + hostcc.sys_includes() + \
        ["-x", "c++", "-I", SHIM, "-I", ROOT / "include", "-w", "-fsyntax-only",
         "-Xclang", "-ast-dump=json", "-Xclang", "-ast-dump-filter=func_", str(src)]
    r = run(cmd, cwd=ROOT)
    out = {}
    dec = json.JSONDecoder()
    s = r.stdout
    i = 0
    while i < len(s):
        while i < len(s) and s[i].isspace():
            i += 1
        if i >= len(s):
            break
        obj, i = dec.raw_decode(s, i)
        if obj.get("kind") != "FunctionDecl":
            continue
        inner = obj.get("inner", [])
        if not any(x.get("kind") == "CompoundStmt" for x in inner):
            continue
        out[obj["name"]] = obj
    return out


def walk(node):
    yield node
    for c in node.get("inner", []) or []:
        yield from walk(c)


def type_kind(t):
    """Argument/return class from a (desugared) clang type string, or None if unsupported."""
    t = t.replace("const ", "").replace("volatile ", "").strip()
    if "(*)" in t or t.endswith("*") or t.endswith("&") or "[" in t:
        return "p"
    base = {"char": "c", "signed char": "c", "unsigned char": "C", "short": "s", "unsigned short": "S",
            "int": "i", "unsigned int": "i", "long": "i", "unsigned long": "i", "bool": "b", "void": "v",
            "u8": "C", "s8": "c", "u16": "S", "s16": "s", "u32": "i", "s32": "i", "uint": "i", "ushort": "S",
            "uchar": "C"}
    return base.get(t)


def ret_bits(kind):
    return {"v": 0, "c": 8, "C": 8, "b": 8, "s": 16, "S": 16, "i": 32, "p": 32}[kind]


def qual(node):
    ty = node.get("type", {})
    return ty.get("desugaredQualType", ty.get("qualType", ""))


def signature(decl):
    """(ret kind, [param kinds]) or None."""
    ftype = decl["type"]["qualType"]
    ret = ftype[:ftype.index("(")].strip()
    rk = type_kind(ret)
    params = [x for x in decl.get("inner", []) if x.get("kind") == "ParmVarDecl"]
    kinds = [type_kind(qual(p)) for p in params]
    if rk is None or any(k is None or k == "v" for k in kinds):
        return None
    if "..." in ftype:
        return None
    return rk, kinds


# ------------------------------------------------------------------ symbols and globals layout
def load_symbol_addrs():
    addrs = {}
    for p in sorted((ROOT / "config" / "symbols").glob("*.txt")):
        for ln in p.read_text(encoding="utf-8", errors="replace").splitlines():
            m = re.match(r"\s*([A-Za-z_$][\w$]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", ln)
            if m and "type:func" not in ln:
                addrs.setdefault(m.group(1), int(m.group(2), 16))
    return addrs


def data_addr(name, symaddrs):
    m = DSYM_RE.match(name)
    if m:
        return int(m.group(1), 16)
    return symaddrs.get(name)


def undefined_symbols(obj):
    r = run([NM, "-u", obj])
    return [ln.split()[-1] for ln in r.stdout.splitlines() if ln.strip()]


def defined_symbols(obj):
    r = run([NM, "--defined-only", obj])
    return {ln.split()[-1] for ln in r.stdout.splitlines() if len(ln.split()) >= 3}


def coff_to_plain(sym):
    """C name behind a COFF symbol: _name for C, ?name@@3... for a C++ variable. None for C++ functions."""
    if sym.startswith("?"):
        m = re.match(r"^\?([A-Za-z_$][\w$]*)@@3", sym)
        return m.group(1) if m else None
    if sym.startswith("_"):
        return sym[1:]
    return None


def write_globals(path, syms):
    """syms: {coff label: ps1 address}. Lays them out at their PS1 offsets, 4 KB-aligned clusters."""
    by_addr = sorted(set(syms.values()))
    clusters = []
    for a in by_addr:
        lo, hi = a & ~0xFFF, a + WINDOW
        if clusters and lo <= clusters[-1][1] + 0x1000:
            clusters[-1][1] = max(clusters[-1][1], hi)
        else:
            clusters.append([lo, hi])
    lines = ['    .section .rcgdata,"dw"', "    .p2align 12", "    .globl _recomp_globals_start",
             "_recomp_globals_start:"]
    total = 0
    for lo, hi in clusters:
        lines.append("    .p2align 12")
        here = lo
        for a in sorted(x for x in by_addr if lo <= x < hi):
            if a > here:
                lines.append(f"    .space 0x{a - here:X}")
                here = a
            for lab, sa in sorted(syms.items()):
                if sa == a:
                    q = f'"{lab}"' if not re.match(r"^[A-Za-z_.$][\w.$]*$", lab) else lab
                    lines.append(f"    .globl {q}")
                    lines.append(f"{q}:")
        lines.append(f"    .space 0x{hi - here:X}")
        total += hi - lo
    lines += ["    .globl _recomp_globals_end", "_recomp_globals_end:", ""]
    path.write_text("\n".join(lines), encoding="utf-8")
    return total


# ------------------------------------------------------------------ main
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--trials", type=int, default=1000)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--target", action="append", choices=TARGETS)
    ap.add_argument("--funcs", help="only these function names (comma-separated)")
    ap.add_argument("--no-calls", dest="calls", action="store_false",
                    help="leaf functions only (default: also functions that call native decompiled code)")
    ap.add_argument("-v", action="store_true")
    a = ap.parse_args()
    targets = a.target or TARGETS
    only = set(a.funcs.split(",")) if a.funcs else None
    BUILD.mkdir(parents=True, exist_ok=True)

    print("difftest: loading asm ...")
    global PROG
    prog = PROG = Program()
    prog.load()
    prog.analyze_all()
    protos = Protos(prog)
    symaddrs = load_symbol_addrs()

    # 1. host-compile the decompiled sources
    srcs = sorted(p for p in (ROOT / "src").rglob("*.cpp") if src_target(p) in targets)
    with ThreadPoolExecutor(12) as ex:
        compiled = list(ex.map(compile_src, srcs))
    host = {"files": len(compiled), "ok": 0, "errors": 0, "per_file": {}, "by_kind": {}}
    for src, obj, errs in compiled:
        rel = src.relative_to(ROOT).as_posix()
        host["per_file"][rel] = len(errs) if obj is None else 0
        host["errors"] += len(errs) if obj is None else 0
        host["ok"] += obj is not None
        for e in errs:
            kind = re.sub(r"'[^']*'", "X", e.split(": error: ", 1)[-1])
            host["by_kind"][kind] = host["by_kind"].get(kind, 0) + 1
    print(f"difftest: host compile of src/: {host['ok']}/{host['files']} files, "
          f"{host['errors']} errors in the rest")

    results = {"host_compile": host, "targets": {}, "skipped": {}}
    exit_bad = False
    for t in targets:
        objs = [(s, o) for s, o, _ in compiled if o is not None and src_target(s) == t]
        if not objs:
            continue
        # 2. candidates
        cands = []
        skipped = {}
        for src, obj in objs:
            decls = ast_functions(src)
            for name, decl in sorted(decls.items()):
                if not FUNC_RE.match(name) or (only and name not in only):
                    continue
                fi = prog.funcs[t].get(name)
                if fi is None or fi.nonmatching or "matchings" not in fi.func.path.parts:
                    skipped[name] = "no original asm"
                    continue
                if fi.problems:
                    skipped[name] = "recomp: " + "; ".join(fi.problems)
                    continue
                callees = sorted({fi.insns[i].tsym for i, k in fi.kind.items()
                                  if k in ("call", "tail", "condtail") and fi.insns[i].tsym})
                leaf = not any(k in CALL_KINDS for k in fi.kind.values())
                if not leaf and not a.calls:
                    skipped[name] = "not a leaf"
                    continue
                if any(i.op.name in GTE_OPS for i in fi.insns):
                    skipped[name] = "GTE"
                    continue
                if any(n.get("kind") == "GCCAsmStmt" for n in walk(decl)):
                    skipped[name] = "inline asm"
                    continue
                if not decl.get("mangledName", "").startswith("_" + name):
                    skipped[name] = "C++ linkage"
                    continue
                sig = signature(decl)
                if sig is None:
                    skipped[name] = "struct/64-bit/varargs signature"
                    continue
                rk, kinds = sig
                nargs = max(4 + fi.stack_args, len(kinds))
                if nargs > 26:
                    skipped[name] = "too many arguments"
                    continue
                argk = "".join(kinds) + "i" * (nargs - len(kinds))
                # globals either side touches
                gl = set()
                for ins in fi.insns:
                    if ins.reloc and not prog.is_function(t, ins.reloc[1]):
                        gl.add(ins.reloc[1])
                for n in walk(decl):
                    rd = n.get("referencedDecl")
                    if rd and rd.get("kind") == "VarDecl" and data_addr(rd.get("name", ""), symaddrs) is not None:
                        gl.add(rd["name"])
                if any(data_addr(g, symaddrs) is None for g in gl):
                    skipped[name] = "global without a known address"
                    continue
                cands.append(dict(name=name, src=src, fi=fi, ret=rk, argk=argk, nargs=nargs, globals=sorted(gl),
                                  leaf=leaf, callees=callees,
                                  bits=64 if fi.ret_pair and rk == "i" else ret_bits(rk)))
        # non-leaf: every direct callee must be a native (decompiled) function both builds can reach
        defined = set()
        for _, obj in objs:
            defined |= defined_symbols(obj)
        keep = []
        for c in cands:
            missing = [x for x in c["callees"] if "_" + x not in defined and x not in defined]
            if missing:
                skipped[c["name"]] = "calls a function with no native build: " + ", ".join(missing[:3])
            else:
                keep.append(c)
        cands = keep
        results["skipped"][t] = skipped
        if not cands:
            continue
        print(f"difftest: {t}: {len(cands)} candidate functions")
        tdir = BUILD / t
        tdir.mkdir(parents=True, exist_ok=True)
        # 3. recompile the originals
        rc_objs = []
        for c in cands:
            code, ok = translate(prog, protos, c["fi"], prefix="recomp_", rodata_static=True)
            cpath = tdir / f"recomp_{c['name']}.c"
            cpath.write_text(code, encoding="utf-8", newline="\n")
            rc_objs.append(cpath.with_suffix(".obj"))

        def cc_recomp(cpath):
            r = run(hostcc.compile_cmd(cpath, cpath.with_suffix(".obj"), includes=[RUNTIME], extra=["-w"]))
            return cpath, r.returncode, r.stderr
        with ThreadPoolExecutor(12) as ex:
            for cpath, rc, err in ex.map(cc_recomp, [o.with_suffix(".c") for o in rc_objs]):
                if rc:
                    sys.exit(f"difftest: recompiled {cpath} does not compile:\n{err}")
        # 4. globals: everything the decompiled objects and the recompiled functions need
        syms = {"_recomp_scratchpad": 0x1F800000, "_D_1F800000": 0x1F800000}
        for _, obj in objs:
            for u in undefined_symbols(obj):
                plain = coff_to_plain(u)
                if plain is None or prog.is_function(t, plain):
                    continue
                ad = data_addr(plain, symaddrs)
                if ad is not None:
                    syms[u] = ad
        for c in cands:
            for g in c["globals"]:
                syms["_" + g] = data_addr(g, symaddrs)
        gsize = write_globals(tdir / "globals.s", syms)
        write_cases(tdir, cands)
        harness_objs = []
        for src in (tdir / "cases.c", HERE / "harness.c", tdir / "globals.s"):
            o = tdir / (src.stem + ".obj")
            r = run(hostcc.compile_cmd(src, o, includes=[HERE], extra=["-w"]))
            if r.returncode:
                sys.exit(f"difftest: {src} does not compile:\n{r.stderr}")
            harness_objs.append(o)
        exe = tdir / f"difftest_{t}.exe"
        decomp_objs = [o for _, o in objs]
        while True:
            if exe.exists():
                exe.unlink()
            cmd = hostcc.link_cmd(decomp_objs + rc_objs + harness_objs, exe,
                                  ["-Wl,/force:unresolved", "-Wl,/force:multiple", "-Wl,/safeseh:no"] +
                                  alias_flags(decomp_objs))
            rsp = tdir / "link.rsp"
            rsp.write_text("\n".join('"' + str(x).replace("\\", "/") + '"' for x in cmd[1:]), encoding="utf-8")
            r = run([cmd[0], "@" + str(rsp)])
            if exe.exists():
                break
            # objects lld cannot take (e.g. top-level `.set sym, other` aliases of undefined symbols):
            # leave them out; their functions then resolve to nothing and are dropped below
            bad = {Path(m.group(1)).resolve() for m in re.finditer(r"lld-link: error: (\S+\.obj):", r.stderr)}
            bad = {o for o in decomp_objs if o.resolve() in bad}
            if not bad:
                sys.exit(f"difftest: link failed:\n{r.stderr[-4000:]}")
            for o in bad:
                why = re.search(re.escape(o.name) + r": (.*)", r.stderr.replace("\\", "/"))
                host.setdefault("link_rejected", {})[o.name] = why.group(1) if why else "link error"
                print(f"difftest: {t}: leaving out {o.name}: {host['link_rejected'][o.name]}")
            decomp_objs = [o for o in decomp_objs if o not in bad]
            gone = {s.resolve() for s, o in objs if o in bad}
            for c in cands:
                if c["src"].resolve() in gone:
                    skipped[c["name"]] = "source object rejected by the linker"
            cands = [c for c in cands if c["src"].resolve() not in gone]
            write_cases(tdir, cands)
            r = run(hostcc.compile_cmd(tdir / "cases.c", tdir / "cases.obj", includes=[HERE], extra=["-w"]))
            keep = {f"recomp_{c['name']}.obj" for c in cands}
            rc_objs = [o for o in rc_objs if o.name in keep]
        dups = [ln for ln in r.stderr.splitlines() if "duplicate symbol" in ln and
                any(f"_{c['name']}" in ln for c in cands)]
        if dups:
            print("difftest: warning: tested functions defined twice:\n  " + "\n  ".join(dups[:10]))
        # run
        print(f"difftest: {t}: running {len(cands)} functions x {a.trials} trials (globals area 0x{gsize:X} bytes)")
        res = run_exe(exe, len(cands), a.trials, a.seed, a.v)
        tres = {}
        for k, c in enumerate(cands):
            r = res.get(c["name"]) or {"error": "no result (crashed?)"}
            r["insns"] = len(c["fi"].insns)
            r["leaf"] = c["leaf"]
            r["features"] = features(c["fi"])
            r["src"] = c["src"].relative_to(ROOT).as_posix()
            tres[c["name"]] = r
            if r.get("mismatch", 1) and c["name"] not in KNOWN:
                exit_bad = True
        results["targets"][t] = tres
    summarize(results, a.trials)
    (BUILD / "results.json").write_text(json.dumps(results, indent=1), encoding="utf-8")
    sys.exit(1 if exit_bad else 0)


def alias_flags(objs):
    """asm("func_X") declarations name the COFF symbol func_X (no leading underscore) while C code
    uses _func_X. Alias each such label to the other spelling so both builds reach one function."""
    out = []
    seen = set()
    for o in objs:
        r = run([NM, o])
        for ln in r.stdout.splitlines():
            parts = ln.split()
            if not parts:
                continue
            sym = parts[-1]
            if not re.match(r"^_?func_[0-9A-F]{8}$", sym) or sym in seen:
                continue
            seen.add(sym)
            kind = parts[-2] if len(parts) >= 2 else ""
            other = sym[1:] if sym.startswith("_") else "_" + sym
            if kind == "U":
                out.append(f"-Wl,/alternatename:{sym}={other}")
            else:
                out.append(f"-Wl,/alternatename:{other}={sym}")
    return out


def features(fi):
    """Translator features a function exercises."""
    names = {i.op.name for i in fi.insns}
    kinds = set(fi.kind.values())
    out = []
    if "switch" in kinds:
        out.append("jump table")
    if fi.stack_args:
        out.append("incoming stack args")
    if any(k in ("call", "tail", "condtail") and fi.insns[i].tsym and
           (lambda ce: ce is not None and ce.stack_args)(PROG.lookup(fi.target, fi.insns[i].tsym))
           for i, k in fi.kind.items()):
        out.append("outgoing stack args")
    if kinds & {"call"}:
        out.append("direct call")
    if kinds & {"icall", "itail"}:
        out.append("indirect call")
    if kinds & {"tail", "condtail"}:
        out.append("tail call")
    if names & {"lwl", "lwr", "swl", "swr"}:
        out.append("lwl/lwr/swl/swr")
    if names & {"div", "divu"}:
        out.append("div")
    if names & {"mult", "multu"}:
        out.append("mult")
    if any(i.reloc and i.reloc[0] == "gp_rel" for i in fi.insns):
        out.append("gp_rel")
    if any(fi.v1_live_after_call.values()) or fi.ret_pair:
        out.append("v0/v1 pair")
    if any(fi.insns[i].op.has_delay and fi.insns[i + 1].op.word and
           (lambda u, d: bool(d & u))(*_branch_reads_delay_writes(fi, i)) for i in fi.kind):
        out.append("delay slot writes a branch operand")
    return out


def _branch_reads_delay_writes(fi, i):
    from tools.recomp.mips import uses_defs
    bu, _ = uses_defs(fi.insns[i].op)
    _, dd = uses_defs(fi.insns[i + 1].op)
    return bu, dd


def write_cases(tdir, cands):
    lines = ['#include "difftest.h"', ""]
    for k, c in enumerate(cands):
        lines.append(f'extern char dec_{k} __asm__("_{c["name"]}");')
        lines.append(f'extern char rec_{k} __asm__("_recomp_{c["name"]}");')
    lines.append("const Case cases[] = {")
    for k, c in enumerate(cands):
        lines.append(f'    {{ "{c["name"]}", &dec_{k}, &rec_{k}, {c["nargs"]}, {c["bits"]}, "{c["argk"]}" }},')
    lines += ["};", f"const int ncases = {len(cands)};", ""]
    (tdir / "cases.c").write_text("\n".join(lines), encoding="utf-8")


def run_exe(exe, n, trials, seed, verbose, jobs=8):
    """Run the cases in parallel chunks; rerun one by one any chunk that died."""
    out = {}
    step = max(1, (n + jobs - 1) // jobs)
    chunks = [(k, min(n, k + step)) for k in range(0, n, step)]

    def one(sel):
        try:
            r = subprocess.run([str(exe), sel, str(trials), str(seed)] + (["-v"] if verbose else []),
                               capture_output=True, text=True, timeout=900)
            return r.stdout
        except subprocess.TimeoutExpired as e:
            return e.stdout.decode() if isinstance(e.stdout, bytes) else (e.stdout or "")
    with ThreadPoolExecutor(jobs) as ex:
        for text in ex.map(one, [f"{a}:{b}" for a, b in chunks]):
            parse_results(text, out)
    if len(out) < n:
        with ThreadPoolExecutor(jobs) as ex:
            for text in ex.map(one, [str(k) for k in range(n)]):
                parse_results(text, out)
    return out


def parse_results(text, out):
    cur = None
    for ln in text.splitlines():
        if ln.startswith("RESULT "):
            parts = ln.split()
            d = {k: int(v) for k, v in (p.split("=") for p in parts[2:])}
            d["detail"] = out.get(parts[1], {}).get("detail", [])
            out[parts[1]] = d
        elif ln.startswith("  MISMATCH "):
            name = ln.split()[1]
            det = out.setdefault(name, {}).setdefault("detail", [])
            if ln.strip() not in det:
                det.append(ln.strip())


def summarize(results, trials):
    rows = []
    for t, tres in results["targets"].items():
        for name, r in tres.items():
            rows.append((t, name, r))
    known = [x for x in rows if x[1] in KNOWN]
    rows_t = [x for x in rows if x[1] not in KNOWN]
    passed = [x for x in rows_t if x[2].get("mismatch") == 0]
    failed = [x for x in rows_t if x[2].get("mismatch", 1) != 0]
    weak = [x for x in passed if x[2].get("ok", 0) < trials // 10]
    tot = {k: sum(x[2].get(k, 0) for x in rows) for k in ("ok", "both_fault", "decomp_only_fault",
                                                             "recomp_only_read_fault", "skipped", "mismatch")}
    print()
    print(f"difftest: {len(rows)} functions: {len(passed)} pass, {len(failed)} fail, {len(known)} known differences "
          f"({len(weak)} passes have under 10% of trials returning normally)")
    for t, name, r in failed:
        print(f"  FAIL {t}:{name} {r}")
    for t, name, r in known:
        print(f"  KNOWN {t}:{name} mismatch={r.get('mismatch')}: {KNOWN[name]}")
    for lf in (True, False):
        sub = [x for x in rows_t if bool(x[2].get("leaf")) == lf]
        print(f"difftest:   {'leaf' if lf else 'non-leaf'}: {len(sub)} functions, "
              f"{sum(1 for x in sub if x[2].get('mismatch') == 0)} pass")
    feat = {}
    for t, name, r in rows_t:
        for f in r.get("features", []):
            feat.setdefault(f, [0, 0])
            feat[f][0] += 1
            feat[f][1] += r.get("mismatch") == 0
    results["features"] = feat
    print("difftest: features exercised (functions passing / tested): " +
          ", ".join(f"{k} {v[1]}/{v[0]}" for k, v in sorted(feat.items())))
    print(f"difftest: trials: {tot['ok']} returned in both and matched, {tot['both_fault']} faulted in both, "
          f"{tot['decomp_only_fault']} faulted only in the decompiled build (read or x/0), "
          f"{tot['recomp_only_read_fault']} only in the recompiled build (read), {tot['skipped']} skipped (decompiled "
          f"build hung), {tot['mismatch']} mismatched")
    results["summary"] = dict(functions=len(rows), passed=len(passed), failed=len(failed), known=len(known),
                              weak=len(weak), trials=trials, totals=tot)
    lines = ["# Differential test results (generated by tools/recomp/test/difftest.py)", "",
             f"{len(rows)} functions, {len(passed)} pass, {len(failed)} fail, {len(known)} known differences; "
             f"{trials} trials each.", "",
             "| target | function | leaf | insns | ok | both fault | decomp-only fault | recomp-only read fault | "
             "skipped | mismatch |",
             "|---|---|---|---:|---:|---:|---:|---:|---:|---:|"]
    for t, name, r in rows:
        lines.append(f"| {t} | {name}{' (known)' if name in KNOWN else ''} | {'yes' if r.get('leaf') else 'no'} | "
                     f"{r.get('insns')} | {r.get('ok')} | "
                     f"{r.get('both_fault')} | {r.get('decomp_only_fault')} | {r.get('recomp_only_read_fault')} | "
                     f"{r.get('skipped')} | "
                     f"{r.get('mismatch')} |")
    lines += ["", "## Features exercised (passing / tested)", ""]
    lines += [f"- {k}: {v[1]}/{v[0]}" for k, v in sorted(feat.items())]
    lines += ["", "## Known differences", ""] + [f"- `{k}`: {v}" for k, v in KNOWN.items()]
    hc = results["host_compile"]
    lines += ["", "## Host compile of src/ (clang, i686-pc-windows-msvc, C++, shim common.h)", "",
              f"{hc['ok']}/{hc['files']} files compile; {hc['errors']} errors in the others.", ""]
    lines += [f"- `{f}`: {n} errors" for f, n in sorted(hc["per_file"].items(), key=lambda x: -x[1]) if n]
    lines += ["", "By kind:", ""]
    lines += [f"- {n} x {k}" for k, n in sorted(hc["by_kind"].items(), key=lambda x: -x[1])]
    for o, why in hc.get("link_rejected", {}).items():
        lines.append(f"- `{o}` compiles but lld rejects it: {why}")
    (BUILD / "results.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    return failed


if __name__ == "__main__":
    main()
