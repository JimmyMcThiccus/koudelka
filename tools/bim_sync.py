"""Put each shared BIM.AR function's one definition into every module that has it (docs/BIM_AR.md, step 4).

A shared function (tools/bim_shared.py names it bimf_<hash> in every module) is decompiled once, into
src/bim/shared/bimf_<hash>.cpp. That file holds just the function, plus the #includes it needs (headers have
include guards, so including them again mid-unit is harmless). This replaces the function's INCLUDE_ASM line in
every module source with an #include of it:

  #include "../shared/bimf_<hash>.cpp"

and a repeat inside one module (bimf_<hash>_1, _2, ...) with the same file compiled under that name:

  #define bimf_<hash> bimf_<hash>_1
  #include "../shared/bimf_<hash>.cpp"
  #undef bimf_<hash>

It also undoes a swap whose shared file is gone. Idempotent; run it after adding or removing a shared file, then
rebuild: every module that uses the function is checked by the build.

  python tools/bim_sync.py
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SHARED = ROOT / "src" / "bim" / "shared"
ASM_LINE = re.compile(r'^INCLUDE_ASM\("([^"]+)", (bimf_([0-9a-f]{8})(?:_\d+)?)\);$', re.M)
INC_LINE = re.compile(r'^(?:#define (bimf_[0-9a-f]{8}) (bimf_[0-9a-f]{8}_\d+)\n)?#include "\.\./shared/(bimf_[0-9a-f]{8})\.cpp"\n'
                      r'(?:#undef bimf_[0-9a-f]{8}\n)?', re.M)


def main():
    have = {p.stem for p in SHARED.glob("bimf_*.cpp")}
    swapped = restored = 0
    for src in sorted((ROOT / "src" / "bim").glob("*/*.cpp")):
        if src.parent == SHARED:
            continue
        mod = src.parent.name
        text = src.read_text()

        def to_include(m):
            nonlocal swapped
            name, base = m.group(2), "bimf_" + m.group(3)
            if base not in have:
                return m.group(0)
            swapped += 1
            inc = f'#include "../shared/{base}.cpp"'
            return inc if name == base else f"#define {base} {name}\n{inc}\n#undef {base}"

        def to_asm(m):
            nonlocal restored
            base = m.group(3)
            if base in have:
                return m.group(0)
            restored += 1
            return f'INCLUDE_ASM("asm/bim/{mod}/nonmatchings/{mod}", {m.group(2) or base});\n'

        new = INC_LINE.sub(to_asm, ASM_LINE.sub(to_include, text))
        if new != text:
            src.write_text(new)
    print(f"bim_sync: {len(have)} shared definitions; {swapped} INCLUDE_ASM lines swapped in, {restored} restored")


if __name__ == "__main__":
    main()
