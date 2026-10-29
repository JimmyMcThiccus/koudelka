# print compact asm for functions: sa.py func_X ...
import re, sys
from pathlib import Path
D = Path(__file__).resolve().parent.parent / "asm/field/nonmatchings/field"
DB = D.parent / "field_b"
for n in sys.argv[1:]:
    p = D / f"{n}.s"
    if not p.exists(): p = DB / f"{n}.s"
    if not p.exists():
        p = D.parent.parent / "matchings/field" / f"{n}.s"
    print("##", n)
    for l in p.read_text().splitlines():
        m = re.match(r"\s*/\* \w+ (\w+) \w+ \*/\s+(.*)", l)
        if m:
            if m.group(2).strip() != "nop": print(m.group(1)[-4:], m.group(2))
        elif l.startswith(".L") or l.startswith("glabel") or l.startswith("jlabel"):
            print(l)
