"""Link-time stubs for the PC port (docs/PORT_PHASE2.md section 7).

    python tools/port/gen_stubs.py --rsp build/port/objs.rsp --out build/port/stubs -- <link args...>

Links once with /force:unresolved to get every undefined symbol (the libraries included, so only real
gaps are left), then writes into --out:

  stubs.s     a stub for each undefined function (it calls port_stub_hit: log "STOP <kind>: <name>" and
              exit), 64 zero bytes for each undefined data symbol
  link.rsp    /alternatename lines: GCC 2.8 .set aliases (build/port/aliases.txt), undecorated asm-label
              names, MSVC-mangled names of plain C globals
  stubs.txt   every stub and alias by kind, with counts: the "unresolved symbols" number

Kinds: overlay (an EXE call to a function in the overlay area, >= 0x800B6DF0: it jumps to the function of
whichever linked overlay is resident and defines it, and stops only when none does), psyq (a PsyQ library function
neither PsyCross nor port/psyq_missing.c defines), method (an MSVC-mangled C++ function: a member still in
asm, or reached only through GCC 2.8 names), gcc-name (a GCC 2.8 mangled or library-internal name from asm
code or data), unimplemented (any other func_X), data.
"""
import argparse
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from tools.recomp import hostcc  # noqa: E402
from tools.port import overlays as ovl  # noqa: E402

LLVM_NM = hostcc.LLVM_BIN / "llvm-nm.exe"
UNDNAME = hostcc.LLVM_BIN / "llvm-undname.exe"
UNDEF_RE = re.compile(r"undefined symbol: (\S+)")
PSYQ_LO, PSYQ_HI = 0x80094910, 0x800A4514
HIRAM = 0x800B6DF0


def psyq_names():
    out = set()
    for line in (ROOT / "config" / "symbols" / "main.txt").read_text().splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)", line)
        if m and PSYQ_LO <= int(m.group(2), 16) < PSYQ_HI:
            out.add(m.group(1))
    return out


def defined_symbols(objs):
    out = set()
    for i in range(0, len(objs), 200):
        r = subprocess.run([str(LLVM_NM), "--defined-only", "-g", "-j"] + [str(o) for o in objs[i:i + 200]],
                           capture_output=True, text=True)
        out.update(l.strip() for l in r.stdout.splitlines() if l.strip() and not l.endswith(":"))
    return out


def demangle(names):
    if not names:
        return {}
    exe = UNDNAME if UNDNAME.exists() else hostcc.LLVM_BIN / "llvm-cxxfilt.exe"
    r = subprocess.run([str(exe)], input="\n".join(names) + "\n", capture_output=True, text=True)
    lines = [l for l in r.stdout.splitlines() if l.strip()]
    if exe.name.startswith("llvm-undname"):  # prints "name\nresult\n\n" pairs
        out, it = {}, iter(lines)
        for a in it:
            out[a] = next(it, a)
        return out
    return dict(zip(names, lines))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rsp", required=True, help="response file listing the objects")
    ap.add_argument("--out", required=True)
    ap.add_argument("--aliases", default=str(ROOT / "build" / "port" / "aliases.txt"))
    ap.add_argument("link", nargs=argparse.REMAINDER, help="-- then the probe link command line")
    a = ap.parse_args()
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    link = [x for x in a.link if x != "--"]
    objs = [Path(l.strip().strip('"')) for l in Path(a.rsp).read_text().splitlines() if l.strip()]

    probe = out / "probe.exe"
    r = subprocess.run(link + [f"@{a.rsp}", "-o", str(probe), "-Wl,/force:unresolved", "-Wl,/demangle:no"],
                       capture_output=True, text=True)
    (out / "probe.log").write_text(r.stdout + r.stderr, encoding="utf-8")
    undef = sorted(set(UNDEF_RE.findall(r.stdout + r.stderr)))
    if r.returncode and not undef:
        sys.exit(f"gen_stubs: probe link failed:\n{r.stderr[-4000:]}")

    defined = defined_symbols(objs)
    psyq = psyq_names()
    aliases = {}
    if Path(a.aliases).exists():
        for line in Path(a.aliases).read_text().splitlines():
            x, y = line.split()
            aliases["_" + x] = "_" + y
    dem = demangle([n for n in undef if n.startswith("?")])

    alt, funcs, datas, thunks = [], [], [], []  # (from, to) / (name, kind, label) / (name, why) / (name, n, target)
    rthunks = []                                # (cdecl name, n, thiscall definition)
    thiscall_defs = {}
    for d in defined:
        m = re.fullmatch(r"_port_thiscall(\d+)_(.+)", d)
        if m:
            thiscall_defs["_" + m.group(2)] = (int(m.group(1)), d)
    report = defaultdict(list)
    work = list(undef)
    for n in work:
        if n in thiscall_defs:  # a constructor defined in C++ (thiscall), called by its C name: cdecl -> thiscall
            nbytes, d = thiscall_defs[n]
            rthunks.append((n, nbytes, d))
            report["cdecl thunk"].append(f"{n} -> {d}")
            continue
        m = re.fullmatch(r"_port_thiscall(\d+)_(.+)", n)
        if m:  # an asm-labelled constructor/destructor (tools/port/hostify.py): thiscall -> cdecl
            target = "_" + m.group(2)
            thunks.append((n, int(m.group(1)), target))
            report["thiscall thunk"].append(f"{n} -> {target}")
            if target not in defined and target not in work:
                work.append(target)
            continue
        if n.startswith("__imp_"):
            report["import (unresolved DLL import)"].append(n)
            continue
        if n in aliases:
            alt.append((n, aliases[n]))
            report["alias (.set)"].append(f"{n} -> {aliases[n]}")
            continue
        if n.startswith("?"):
            m = re.match(r"\?(\w+)@@3", n)
            if m and "_" + m.group(1) in defined:
                alt.append((n, "_" + m.group(1)))
                report["alias (C++ name of a C global)"].append(f"{n} -> _{m.group(1)}")
            elif m:
                datas.append((n, dem.get(n, n)))
                report["data"].append(f"{n}  {dem.get(n, '')}")
            else:
                funcs.append((n, "method", dem.get(n, n)))
                report["method"].append(f"{n}  {dem.get(n, '')}")
            continue
        if not n.startswith("_"):
            if "_" + n in defined:
                alt.append((n, "_" + n))
                report["alias (undecorated asm label)"].append(f"{n} -> _{n}")
            else:
                funcs.append((n, "unimplemented", n))
                report["unimplemented"].append(n)
            continue
        c = n[1:]
        m = re.fullmatch(r"(func|D)_([0-9A-F]{8})\w*", c)
        if m and m.group(1) == "D":
            datas.append((n, c))
            report["data"].append(c)
        elif m:
            addr = int(m.group(2), 16)
            kind = "overlay" if addr >= HIRAM else "psyq" if PSYQ_LO <= addr < PSYQ_HI else "unimplemented"
            funcs.append((n, kind, c))
            report[kind].append(c)
        elif c in psyq:
            funcs.append((n, "psyq", c))
            report["psyq"].append(c)
        elif c.startswith("_vt.") or c.startswith("_vt$"):
            datas.append((n, c))
            report["data"].append(c)
        else:
            funcs.append((n, "gcc-name", c))
            report["gcc-name"].append(c)

    s = ["# Generated by tools/port/gen_stubs.py. Do not edit.", "    .text"]
    strs = ["    .section .rdata,\"dr\""]
    kinds = {}
    for i, (n, kind, label) in enumerate(funcs):
        if kind not in kinds:
            kinds[kind] = f"Lkind_{len(kinds)}"
            strs.append(f'{kinds[kind]}: .asciz "{kind}"')
        strs.append(f'Lname_{i}: .asciz "{label.replace(chr(34), "")}"')
        s += [f'    .globl "{n}"', f'"{n}":']
        if kind == "overlay":
            # EXE -> overlay: jump to the function of the overlay that is resident (port/overlays.cpp keeps
            # port_ovl_slot / port_ovl_effect), with the caller's arguments in place; none: stop as before
            # EFFECT first: it shares addresses with FIELD's top, and port/overlays.cpp forgets it when a slot
            # overlay loads over it, so a resident EFFECT is the newer one
            order = sorted(enumerate(ovl.OVERLAYS), key=lambda ko: ovl.OVERLAYS[ko[1]][0] == HIRAM)
            for k, o in order:
                target = f"_{o}_{label}"
                if target in defined:
                    var = "_port_ovl_effect" if ovl.OVERLAYS[o][0] != HIRAM else "_port_ovl_slot"
                    s += [f"    cmpl ${k}, {var}", f'    je "{target}"']
                    report["overlay dispatch"].append(f"{label} -> {o}_{label}")
        s += ["    pushl (%esp)", f"    pushl $Lname_{i}", f"    pushl ${kinds[kind]}", "    calll _port_stub_hit"]
    # thiscall (this in ECX, callee pops N bytes) -> cdecl f(this, args...); returns this, as MSVC constructors do
    for n, nbytes, target in thunks:
        s += [f'    .globl "{n}"', f'"{n}":', "    pushl %ebp", "    movl %esp, %ebp", "    pushl %ecx"]
        s += [f"    pushl {8 + off}(%ebp)" for off in range(nbytes - 4, -4, -4)]
        s += ["    pushl %ecx", f'    calll "{target}"', "    movl -4(%ebp), %eax", "    movl %ebp, %esp",
              "    popl %ebp", f"    retl ${nbytes}" if nbytes else "    retl"]
    # cdecl f(this, args...) -> the thiscall definition (callee pops N)
    for n, nbytes, d in rthunks:
        s += [f'    .globl "{n}"', f'"{n}":', "    pushl %ebp", "    movl %esp, %ebp"]
        s += [f"    pushl {12 + off}(%ebp)" for off in range(nbytes - 4, -4, -4)]
        s += ["    movl 8(%ebp), %ecx", f'    calll "{d}"', "    movl %ebp, %esp", "    popl %ebp", "    retl"]
    s += strs
    s.append("    .data")
    for n, _ in datas:
        s += ["    .p2align 4", f'    .globl "{n}"', f'"{n}":', "    .space 64"]
    (out / "stubs.s").write_text("\n".join(s) + "\n", encoding="utf-8", newline="\n")
    (out / "link.rsp").write_text("".join(f'"-Wl,/alternatename:{x}={y}"\n' for x, y in alt), encoding="utf-8")
    lines = [f"{len(undef)} undefined symbols after the probe link: {len(funcs)} function stubs, {len(datas)} data "
             f"stubs, {len(alt)} aliases, {len(thunks)} thiscall thunks, {len(rthunks)} cdecl thunks", ""]
    for k in sorted(report):
        lines.append(f"## {k} ({len(report[k])})")
        lines += [f"  {x}" for x in report[k]]
        lines.append("")
    (out / "stubs.txt").write_text("\n".join(lines), encoding="utf-8")
    print("gen_stubs: " + lines[0] + " | " + ", ".join(f"{k} {len(v)}" for k, v in sorted(report.items())))


if __name__ == "__main__":
    main()
