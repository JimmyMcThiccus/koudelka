"""Compile one C function and compare it with the retail bytes.

Pipeline: CC1PSX.EXE, or CC1PLPSX.EXE for .cpp/.cc (from a PsyQ dir) -> maspsx -> GNU as. The function's
retail size and ROM offset come from its splat .s file. Relocated fields
(jal targets, %hi/%lo immediates) are masked before comparing.

CC1PSX/CC1PLPSX don't preprocess, so test files can't use #define or #include.

Usage: python try_compile.py <file.c|.cpp> <func> [--psyq bin/psyq4.4] [--aspsx 2.79]
       [--cflags "-O2 -G8"] [--asm-dir asm/main] [--target extracted/disc1/SLUS_010.51]
Defaults follow config/toolchain.toml. For an overlay function pass its --asm-dir and --target.
"""
import argparse
import os
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

import rabbitizer

ROOT = Path(__file__).resolve().parent.parent
BIN = ROOT / "bin" / "binutils"


def retail_bytes(asm_dir, func):
    for s in Path(asm_dir).rglob("*.s"):
        text = s.read_text()
        m = re.search(rf"nonmatching {func}, (0x[0-9A-F]+)", text)
        if not m:
            continue
        rom = re.search(rf"glabel {func}\n\s*/\* ([0-9A-F]+) ", text)
        return int(rom.group(1), 16), int(m.group(1), 16)
    sys.exit(f"{func} not found under {asm_dir}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cfile")
    ap.add_argument("func")
    ap.add_argument("--psyq", default="bin/psyq4.4")
    ap.add_argument("--aspsx", default="2.79")
    ap.add_argument("--cflags", default="-O2 -G8")
    ap.add_argument("--asm-dir", default="asm/main")
    ap.add_argument("--target", default="extracted/disc1/SLUS_010.51")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()

    rom, size = retail_bytes(ROOT / a.asm_dir, a.func)
    want = open(ROOT / a.target, "rb").read()[rom:rom + size]

    gflag = [f for f in a.cflags.split() if f.startswith("-G")]
    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        s1, s2, obj = tmp / "out.s", tmp / "out.mas.s", tmp / "out.o"
        cc1 = "CC1PLPSX.EXE" if Path(a.cfile).suffix in (".cpp", ".cc") else "CC1PSX.EXE"
        cc = [str(ROOT / a.psyq / cc1), "-quiet", *a.cflags.split(), str(a.cfile), "-o", str(s1)]
        # GCC 2.7.2 builds (PsyQ <= 4.1) put temp files in $TMPDIR, falling back to "\"; give
        # them a native path (Git Bash exports TMPDIR as /c/...).
        subprocess.run(cc, check=True, env={**os.environ, "TMPDIR": str(tmp)})
        # maspsx reads stdin whenever it isn't a tty, so feed the file through it (else it blocks).
        mas = subprocess.run([sys.executable, str(ROOT / "bin/maspsx/maspsx.py"), f"--aspsx-version={a.aspsx}",
                              *gflag], input=s1.read_text(), capture_output=True, text=True, check=True)
        s2.write_text(mas.stdout)
        subprocess.run([str(BIN / "mips-ps2-decompals-as.exe"), "-EL", "-march=r3000", "-mtune=r3000",
                        "-mabi=32", "-no-pad-sections", "-G0", "-o", str(obj), str(s2)], check=True)
        # .text bytes of the function and its relocation offsets
        dump = subprocess.run([str(BIN / "mips-ps2-decompals-objcopy.exe"), "-O", "binary", "-j", ".text",
                               str(obj), str(tmp / "t.bin")], check=True)
        got = (tmp / "t.bin").read_bytes()
        rel = subprocess.run([str(BIN / "mips-ps2-decompals-readelf.exe"), "-r", str(obj)],
                             capture_output=True, text=True).stdout
        relocs = {int(l.split()[0], 16) for l in rel.splitlines()
                  if re.match(r"^[0-9a-f]{8} ", l) and "R_MIPS" in l}
        if not a.quiet:
            print(s2.read_text())

    n = max(len(got), len(want)) // 4
    diffs = 0
    for i in range(n):
        w = struct.unpack_from("<I", want, i * 4)[0] if i * 4 < len(want) else None
        g = struct.unpack_from("<I", got, i * 4)[0] if i * 4 < len(got) else None
        mask = 0xFFFFFFFF
        if g is not None and i * 4 in relocs:
            mask = 0xFC000000 if g >> 26 in (2, 3) else 0xFFFF0000
        same = w is not None and g is not None and (w & mask) == (g & mask)
        diffs += not same
        dis = lambda x: rabbitizer.Instruction(x).disassemble() if x is not None else "-"
        print(f"{'  ' if same else '!!'} {i*4:04x}  {dis(w):40s} {dis(g)}")
    print(f"{a.func}: retail {len(want)} bytes, built {len(got)} bytes, {diffs} differing instructions")
    return 0 if diffs == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
