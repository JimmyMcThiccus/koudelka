"""Brute-force a near miss with decomp-permuter (bin/decomp-permuter).

The permuter rewrites a function's C at random (statement order, temporaries, types, ...), compiles
every candidate and keeps the ones whose code is closer to retail. It parses C only (pycparser), so
this works for functions whose body is plain C: free functions, structs, casts. Member functions,
references or classes in the headers make the parse fail.

  setup  <file.cpp> <func> --unit src/<area>/<file>.cpp [--dir D]
         Writes D (default permuter/<func>/, git-ignored) with:
           base.c      the draft preprocessed as C++ (the build's CPPPSX), then made C-parsable:
                       extern "C" -> extern, INCLUDE_ASM stubs and line markers removed
           target.o    the function's retail .s, assembled alone
           compile.sh  "permute.py compile": wraps a candidate in extern "C" { } (unmangled names)
                       and compiles it with tools/cc.py and the unit's flags from config/toolchain.toml
           settings.toml
         <file.cpp> is anything try_compile.py accepts. A draft without #include lines gets the
         unit's own #include lines in front of it.
  run    <dir> [permuter options, e.g. -j 32 --best-only]
         Runs the permuter on it. Improvements land in <dir>/output-<score>-<n>/source.c.
  compile <candidate.c> -o <out.o> --unit ...   (used by compile.sh)

Score 0 means the candidate matches; check it with try_compile.py before landing it.
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PERMUTER = ROOT / "bin" / "decomp-permuter"
OBJDUMP = ROOT / "bin" / "binutils" / "mips-ps2-decompals-objdump.exe"

sys.path.insert(0, str(ROOT / "tools"))
import cc  # noqa: E402  (CPPPSX defines, assembler flags)
import toolchain  # noqa: E402

try:
    import toml  # noqa: F401  (the permuter reads its settings with it)
except ImportError:
    # Worktree virtualenvs are copies that may predate it; the stdlib parser does the same job. At module
    # level, so the permuter's worker processes (which re-import this file) get it too.
    import tomllib
    import types
    sys.modules["toml"] = types.SimpleNamespace(load=lambda f: tomllib.loads(f.read()))


def find_asm(unit, func):
    asm_dir, _ = toolchain.target_of(unit)
    for kind in ("nonmatchings", "matchings"):
        hits = list((ROOT / asm_dir / kind).glob(f"*/{func}.s"))
        if hits:
            return hits[0]
    sys.exit(f"permute: {func}.s not found under {asm_dir}/")


def chunks(text):
    """Split C text into top-level declarations and definitions."""
    out, start, depth, i, n = [], 0, 0, 0, len(text)
    while i < n:
        c = text[i]
        if c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            i = j
        elif c in "{(":
            depth += 1
        elif c in "})":
            depth -= 1
            if c == "}" and depth == 0:
                head = text[start:i]
                # A function body ends the chunk; a struct/enum body runs on to its ';'.
                if head.find(")") != -1 and head.find(")") < head.find("{") and not re.match(r"\s*typedef\b", head):
                    out.append(text[start:i + 1])
                    start = i + 1
        elif c == ";" and depth == 0:
            out.append(text[start:i + 1])
            start = i + 1
        i += 1
    out.append(text[start:])
    return [c for c in out if c.strip()]


def first_problem(src, unit):
    """(line, message) of the first thing in src that pycparser or the unit's compiler rejects, or None.
    pycparser has no semantics, so both are needed: a struct with a field of a dropped class parses."""
    from perm_pycparser.c_parser import CParser, ParseError
    try:
        CParser().parse(src, "base.c")
    except ParseError as e:
        m = re.match(r"[^:]*:(\d+):", str(e))
        return (int(m.group(1)) if m else None), str(e)
    with tempfile.TemporaryDirectory() as tmp:
        (Path(tmp) / "base.c").write_text(src)
        r = subprocess.run([sys.executable, __file__, "compile", str(Path(tmp) / "base.c"), "-o",
                            str(Path(tmp) / "base.o"), "--unit", unit], capture_output=True, text=True)
    if r.returncode == 0:
        return None
    for m in re.finditer(r"cand\.cpp:(\d+): (.*)", r.stderr):
        if not m.group(2).startswith("warning"):
            return int(m.group(1)) - 1, m.group(2)  # compile wraps the file in a one-line extern "C" {
    return None, r.stderr.strip()[-500:]


def reduce_to_c(text, func, unit):
    """Drop top-level chunks that aren't C (C++ classes, and whatever then depends on them) until the
    rest parses and compiles. The target function must survive."""
    sys.path.insert(0, str(PERMUTER))
    # C++ names a struct without the keyword (`List *p`); C needs a typedef. Classes that get dropped
    # stay usable through pointers this way, which is all plain C does with them.
    tags = {name: ("union" if kw == "union" else "struct") for kw, name in
            re.findall(r"\b(struct|union|class)\s+([A-Za-z_]\w*)\s*[{;:]", text)}
    parts = [f"typedef {kw} {name} {name};" for name, kw in tags.items()] + chunks(text)
    dropped = 0
    while (problem := first_problem("\n".join(parts), unit)) is not None:
        line, msg = problem
        if line is None:
            sys.exit(f"permute: base.c doesn't build: {msg}")
        pos = 0
        for k, p in enumerate(parts):
            pos += p.count("\n") + 1
            if pos >= line:
                break
        if re.search(rf"\b{func}\s*\([^;]*\{{", parts[k]):
            sys.exit(f"permute: {func} itself isn't C ({msg}); this tool can't permute it")
        parts[k] = ""
        dropped += 1
    print(f"permute: base.c keeps {sum(1 for p in parts if p)} declarations, dropped {dropped} that aren't C")
    return "\n".join(parts) + "\n"


def c_parsable(i_text, func, unit):
    """The preprocessed C++ of a draft, as C that pycparser reads and the unit's compiler builds."""
    text = "\n".join(l for l in i_text.splitlines() if not l.startswith("#"))
    text = re.sub(r"void __maspsx_include_asm_hack_\w+\(\)\s*\{\s*__asm__\(.*?\);\s*\}", "", text, flags=re.S)
    text = re.sub(r'__asm__\("\.include \\"include/macro\.inc\\"\\n"\);', "", text)
    return reduce_to_c(text.replace('extern "C"', "extern"), func, unit)


def setup(a):
    src = Path(a.file).read_text()
    if not re.search(r"^\s*#\s*include", src, re.M):
        incs = re.findall(r"^\s*#\s*include.*$", (ROOT / a.unit).read_text(), re.M)
        src = "\n".join(incs) + "\n" + src
    out = Path(a.dir or ROOT / "permuter" / a.func)
    out.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        (tmp / "in.cpp").write_text(src)
        subprocess.run([str(ROOT / toolchain.settings(a.unit)["psyq"] / "CPPPSX.EXE"), *cc.CPP_DEFS,
                        *cc.CPP_LANG["c++"], f"-I{ROOT / 'include'}", str(tmp / "in.cpp"), str(tmp / "out.i")],
                       check=True, cwd=ROOT)
        (out / "base.c").write_text(c_parsable((tmp / "out.i").read_text(), a.func, a.unit))

        s = tmp / "target.s"
        s.write_text('.include "macro.inc"\n.set noat\n.set noreorder\n.text\n'
                     f'.include "{find_asm(a.unit, a.func).relative_to(ROOT).as_posix()}"\n')
        subprocess.run([str(cc.AS), *cc.AS_FLAGS, f"-I{ROOT / 'include'}", f"-I{ROOT}", "-o",
                        str(out / "target.o"), str(s)], check=True, cwd=ROOT)

    py = Path(sys.executable).as_posix()
    (out / "compile.sh").write_text(f'#!/bin/bash\nexec "{py}" "{Path(__file__).as_posix()}" compile "$1" '
                                    f'-o "$3" --unit {a.unit}\n')
    (out / "settings.toml").write_text(f'func_name = "{a.func}"\ncompiler_type = "gcc"\n'
                                       f'objdump_command = "{OBJDUMP.as_posix()} -drz -m mips:4300"\n')
    print(f"permute: wrote {out}. Next: python tools/permute.py run {out.as_posix()} -j 32")


def compile_candidate(a):
    with tempfile.TemporaryDirectory() as tmp:
        cand = Path(tmp) / "cand.cpp"
        cand.write_text('extern "C" {\n' + Path(a.file).read_text() + "\n}\n")
        # In-process: one Python start per candidate instead of two.
        os.chdir(ROOT)
        sys.argv = ["cc.py", *toolchain.cc_args(a.unit), "-Iinclude", "-o", a.out, str(cand)]
        cc.main()


def run(rest):
    sys.path.insert(0, str(PERMUTER))
    import src.main as permuter
    # base.c is already preprocessed (by the build's CPPPSX, in setup), and there is no host cpp.
    permuter.preprocess = lambda filename, cpp_args=[]: Path(filename).read_text()
    sys.argv = [str(PERMUTER / "permuter.py"), *rest]
    permuter.main()


def main():
    if len(sys.argv) > 1 and sys.argv[1] == "run":
        return run(sys.argv[2:])
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("setup")
    p.add_argument("file")
    p.add_argument("func")
    p.add_argument("--unit", required=True)
    p.add_argument("--dir")
    p = sub.add_parser("compile")
    p.add_argument("file")
    p.add_argument("-o", dest="out", required=True)
    p.add_argument("--unit", required=True)
    a = ap.parse_args()
    setup(a) if a.cmd == "setup" else compile_candidate(a)


if __name__ == "__main__":
    main()
