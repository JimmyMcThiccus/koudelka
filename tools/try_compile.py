"""Compile one C function and compare it with the retail bytes.

Compiles through tools/cc.py, the build's own pipeline (CPPPSX -> CC1PLPSX/CC1PSX
-> maspsx -> GNU as). The function's retail size and ROM offset come from its
splat .s file (nonmatchings/ or matchings/). Relocated fields (jal targets,
%hi/%lo immediates) are masked before comparing.

Usage: python try_compile.py <file.c|.cpp> <func> --unit src/<area>/<file>.cpp
       [-I dir ...] [--quiet]
--unit takes the build's flags for that file from config/toolchain.toml, and picks its asm dir
and retail binary. Without it: the EXE's game-code defaults. To experiment, override any of
--psyq, --aspsx, --cflags, --as-G, --[no-]expand-div, --asm-dir, --target.
"""
import argparse
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

import rabbitizer

sys.path.insert(0, str(Path(__file__).resolve().parent))
import toolchain  # noqa: E402

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
    ap.add_argument("--unit", help="source file the function belongs to (e.g. src/field/field.cpp): use its "
                    "build flags, asm dir and retail binary from config/toolchain.toml; the options below override")
    ap.add_argument("--psyq")
    ap.add_argument("--aspsx")
    ap.add_argument("--cflags")
    ap.add_argument("--as-G", dest="as_g", type=int, help="assembler -G (default: the -G in --cflags); overlays: 0")
    ap.add_argument("--expand-div", action=argparse.BooleanOptionalAction, default=None,
                    help="maspsx expands div/rem with zero checks")
    ap.add_argument("--asm-dir")
    ap.add_argument("--target")
    ap.add_argument("-I", dest="incs", action="append", default=["include"], help="include dir (repeatable)")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()
    unit = a.unit or "src/main/main_a.cpp"
    s = toolchain.settings(unit)
    asm_dir, target = toolchain.target_of(unit)
    a.psyq = a.psyq or s["psyq"]
    a.aspsx = a.aspsx or s["aspsx"]
    a.cflags = a.cflags or s["cflags"]
    a.as_g = a.as_g if a.as_g is not None else s.get("as_G")
    a.expand_div = s["expand_div"] if a.expand_div is None else a.expand_div
    a.asm_dir = a.asm_dir or asm_dir
    a.target = a.target or target

    rom, size = retail_bytes(ROOT / a.asm_dir, a.func)
    want = open(ROOT / a.target, "rb").read()[rom:rom + size]

    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        obj = tmp / "out.o"
        # The build's own pipeline (preprocessor, both -G settings, maspsx wrapper).
        cc = [sys.executable, str(ROOT / "tools" / "cc.py"), "--psyq", a.psyq, "--aspsx", a.aspsx,
              "--cflags", a.cflags, *(["--as-G", str(a.as_g)] if a.as_g is not None else []),
              *(["--expand-div"] if a.expand_div else []),
              *[f"-I{i}" for i in a.incs], "-o", str(obj), str(a.cfile)]
        if subprocess.run(cc, cwd=ROOT).returncode != 0:
            sys.exit(f"{a.func}: compile failed")
        # .text bytes of the function and its relocation offsets
        dump = subprocess.run([str(BIN / "mips-ps2-decompals-objcopy.exe"), "-O", "binary", "-j", ".text",
                               str(obj), str(tmp / "t.bin")], check=True)
        got = (tmp / "t.bin").read_bytes()
        rel = subprocess.run([str(BIN / "mips-ps2-decompals-readelf.exe"), "-r", str(obj)],
                             capture_output=True, text=True).stdout
        relocs = {int(l.split()[0], 16) for l in rel.splitlines()
                  if re.match(r"^[0-9a-f]{8} ", l) and "R_MIPS" in l}
        if not a.quiet:
            print(subprocess.run([str(BIN / "mips-ps2-decompals-objdump.exe"), "-dr", str(obj)],
                                 capture_output=True, text=True).stdout)

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
