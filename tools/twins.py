"""List functions still in asm whose code nearly matches one already decompiled (a "twin").

Compares normalised instructions (registers kept; labels, call targets, %hi/%lo symbols and nops
masked) of every nonmatchings function against every matchings one in the same target. A close twin
is often the same source with other constants or offsets: copy the landed C and adjust it.
From the round-3 FIELD session, where 11 of its first 24 landings came from it.

  python tools/twins.py <target asm dir, e.g. asm/field or asm/main> [--min 0.6] [--unit u_80056E0C]
"""
import argparse
import difflib
import re
from pathlib import Path


def norm(path):
    out = []
    for line in path.read_text().splitlines():
        m = re.match(r"\s*/\* \w+ \w+ \w+ \*/\s+(.*)", line)
        if not m or m.group(1).strip() == "nop":
            continue
        s = re.sub(r"\.L\w+", "L", m.group(1).strip())
        s = re.sub(r"(jal\s+)\w+", r"\1F", s)
        s = re.sub(r"%(hi|lo)\(\w+\)", r"%\1(S)", s)
        out.append(re.sub(r"\s+", " ", s))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("asm_dir")
    ap.add_argument("--min", type=float, default=0.6, help="lowest similarity ratio to list")
    ap.add_argument("--unit", help="only list remaining functions of this unit")
    a = ap.parse_args()
    base = Path(a.asm_dir)
    left = {p: norm(p) for p in (base / "nonmatchings").glob(f"{a.unit or '*'}/func_*.s")}
    done = {p: norm(p) for p in (base / "matchings").glob("*/*.s")}
    res = []
    for p, ins in left.items():
        if len(ins) < 10:
            continue
        best = (0, None)
        for q, other in done.items():
            if abs(len(ins) - len(other)) > len(ins) * 0.2:
                continue
            r = difflib.SequenceMatcher(None, ins, other, autojunk=False).ratio()
            if r > best[0]:
                best = (r, q)
        if best[0] >= a.min:
            res.append((best[0], p, best[1], len(ins)))
    for r, p, q, n in sorted(res, reverse=True):
        print(f"{r:.3f} {p.parent.name}/{p.stem} <- {q.parent.name}/{q.stem} ({n} insns)")


if __name__ == "__main__":
    main()
