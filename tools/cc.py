"""Compile one C/C++ source to an object with the PsyQ toolchain.

  CPPPSX.EXE (with the defines CCPSX.EXE passes) -> CC1PSX.EXE / CC1PLPSX.EXE
  -> maspsx (tools/maspsx_extern.py) -> GNU as

Also writes <out>.d, a depfile listing the headers (from the preprocessor's
line markers) and the INCLUDE_ASM/INCLUDE_RODATA .s files the object pulls in.

Usage: python cc.py --psyq bin/psyq4.4 --aspsx 2.79 --cflags "-O2 -G8" [--as-G N] [--expand-div]
       [-I include ...] -o build/src/x.cpp.o src/x.cpp
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
AS = ROOT / "bin" / "binutils" / "mips-ps2-decompals-as.exe"
AS_FLAGS = ["-EL", "-march=r3000", "-mtune=r3000", "-mabi=32", "-no-pad-sections", "-G0"]

# What CCPSX.EXE passes to CPPPSX.EXE for the PSX target
CPP_DEFS = ["-undef", "-D__GNUC__=2", "-D__OPTIMIZE__", "-D_MIPSEL", "-D__mips", "-D__mips__", "-Dmips",
            "-D__psx", "-D__psx__", "-Dpsx"]
CPP_LANG = {
    "c": ["-lang-c", "-DLANGUAGE_C", "-D_LANGUAGE_C"],
    "c++": ["-lang-c++", "-D__cplusplus", "-D_LANGUAGE_C_PLUS_PLUS"],
}


def run(cmd, **kw):
    res = subprocess.run(cmd, **kw)
    if res.returncode != 0:
        sys.stderr.write(f"cc.py: failed ({res.returncode}): {' '.join(map(str, cmd))}\n")
        if res.stderr:
            sys.stderr.write(res.stderr if isinstance(res.stderr, str) else res.stderr.decode())
        sys.exit(1)
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("-o", dest="out", required=True)
    ap.add_argument("--psyq", required=True)
    ap.add_argument("--aspsx", required=True)
    ap.add_argument("--cflags", default="-O2 -G8")
    ap.add_argument("--as-G", dest="as_g", type=int, help="assembler -G (default: the -G in --cflags)")
    ap.add_argument("--expand-div", action="store_true", help="maspsx expands div/rem with zero checks")
    ap.add_argument("-I", dest="incs", action="append", default=[])
    a = ap.parse_args()

    lang = "c++" if Path(a.src).suffix in (".cpp", ".cc") else "c"
    psyq = ROOT / a.psyq
    cflags = a.cflags.split()
    gflag = [f for f in cflags if f.startswith("-G")] if a.as_g is None else [f"-G{a.as_g}"]
    out = Path(a.out)
    out.parent.mkdir(parents=True, exist_ok=True)

    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        # The GCC 2.x tools put temp files in $TMPDIR (falling back to "\"); Git Bash exports /c/... paths.
        env = {**os.environ, "TMPDIR": str(tmp)}
        i_file, s_file = tmp / "out.i", tmp / "out.s"
        run([str(psyq / "CPPPSX.EXE"), *CPP_DEFS, *CPP_LANG[lang], *[f"-I{i}" for i in a.incs],
             a.src, str(i_file)], env=env)
        cc1 = "CC1PLPSX.EXE" if lang == "c++" else "CC1PSX.EXE"
        run([str(psyq / cc1), "-quiet", *cflags, str(i_file), "-o", str(s_file)], env=env,
            capture_output=True, text=True)
        # maspsx reads stdin whenever it isn't a tty, so always feed it that way.
        mas = run([sys.executable, str(ROOT / "tools" / "maspsx_extern.py"), f"--aspsx-version={a.aspsx}",
                   *gflag, *(["--expand-div"] if a.expand_div else [])], input=s_file.read_text(), capture_output=True, text=True)
        m_file = tmp / "out.mas.s"
        m_file.write_text(mas.stdout)
        run([str(AS), *AS_FLAGS, *[f"-I{i}" for i in a.incs], "-o", str(out), str(m_file)])

        deps = {Path(a.src).as_posix()}
        for m in re.finditer(r'^# \d+ "([^"<][^"]*)"', i_file.read_text(), re.M):
            deps.add(Path(m.group(1)).as_posix())
        for m in re.finditer(r'\.include\s+"([^"]+)"', s_file.read_text()):
            deps.add(m.group(1))
    deps = sorted(d for d in deps if Path(d).exists())
    with open(str(out) + ".d", "w") as f:
        f.write(f"{out.as_posix()}: " + " \\\n  ".join(d.replace(" ", "\\ ") for d in deps) + "\n")


if __name__ == "__main__":
    main()
