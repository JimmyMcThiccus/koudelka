"""land.py SCRATCH [func_...]: move sections of SCRATCH into src/battle/battle.cpp.
Sections are '//@ func_X' blocks; with names given, only those; the LAST block for a name wins.
The prelude after the #include lines is appended to include/battle/battle.h."""
import re, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
src = Path(sys.argv[1]).read_text()
parts = re.split(r"^//@ (func_[0-9A-F]{8})\s*$", src, flags=re.M)
bodies = {}
for i in range(1, len(parts), 2):
    bodies[parts[i]] = parts[i + 1].strip()
names = sys.argv[2:] or list(bodies)
pre = "\n".join(l for l in parts[0].splitlines() if not l.startswith("#include")).strip()
if pre:
    h = ROOT / "include/battle/battle.h"
    t = h.read_text()
    i = t.rindex("#endif")
    h.write_text(t[:i] + pre + "\n\n" + t[i:])
for n in names:
    hit = 0
    for u in ("battle.cpp", "battle_b.cpp", "battle_c.cpp"):
        cpp = ROOT / "src/battle" / u
        text = cpp.read_text()
        for d in ("battle", u[:-4]):
            line = f'INCLUDE_ASM("asm/battle/nonmatchings/{d}", {n});'
            if text.count(line) == 1:
                cpp.write_text(text.replace(line, bodies[n])); hit += 1
    assert hit == 1, n
print("landed", len(names))
