"""Write every function splat knows (all 7 targets) as "<space> <hex address> <name>" lines, for
tools/ghidra_scripts/KoudelkaSeedFunctions.java. <space> is "ram" for the EXE, else the overlay's
Ghidra block (FIELD, BATTLE, ...).

  python tools/ghidra_function_list.py [out file, default build/ghidra_functions.txt]
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SPACES = {"main": "ram", "field": "FIELD", "battle": "BATTLE", "movie": "MOVIE", "capture": "CAPTURE",
          "gameend": "GAMEEND", "effect": "EFFECT"}
GLABEL = re.compile(r"glabel (\S+)\n\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ")


def main():
    out = Path(sys.argv[1] if len(sys.argv) > 1 else ROOT / "build" / "ghidra_functions.txt")
    rows = set()
    for target, space in SPACES.items():
        # Per-function files, plus whole-segment asm files such as asm/main/psyq.s (the PsyQ library).
        files = [s for kind in ("nonmatchings", "matchings") for s in (ROOT / "asm" / target / kind).glob("*/*.s")]
        files += list((ROOT / "asm" / target).glob("*.s"))
        for s in files:
            for m in GLABEL.finditer(s.read_text()):
                rows.add((space, m.group(2).lower(), m.group(1)))
    out.parent.mkdir(exist_ok=True)
    out.write_text("".join(f"{s} {a} {n}\n" for s, a, n in sorted(rows)))
    print(f"{len(rows)} functions -> {out}")


if __name__ == "__main__":
    main()
