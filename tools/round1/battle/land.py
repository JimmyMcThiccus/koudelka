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
cpp = ROOT / "src/battle/battle.cpp"
text = cpp.read_text()
for n in names:
    line = f'INCLUDE_ASM("asm/battle/nonmatchings/battle", {n});'
    assert text.count(line) == 1, n
    text = text.replace(line, bodies[n])
cpp.write_text(text)
print("landed", len(names))
