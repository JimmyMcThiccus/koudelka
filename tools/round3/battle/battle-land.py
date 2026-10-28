"""land.py SCRATCH 'func_X [label]'...: move sections of SCRATCH into src/battle/*.cpp.
The prelude (minus #include lines) is appended to include/battle/battle.h (once per call); single-line
header declarations of the landed functions are removed first. The LAST block for a name wins."""
import re, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
src = Path(sys.argv[1]).read_text()
parts = re.split(r"^//@ (func_[0-9A-F]{8}[^\n]*)$", src, flags=re.M)
bodies = {}
for i in range(1, len(parts), 2):
    full = parts[i].strip()
    bodies[full] = parts[i + 1].strip()
    bodies[full.split()[0]] = parts[i + 1].strip()
names = sys.argv[2:] or [k for k in bodies if " " in k]
pre = "\n".join(l for l in parts[0].splitlines() if not l.startswith("#include")).strip()
h = ROOT / "include/battle/battle.h"
t = h.read_text()
for n in names:
    fn = n.split()[0]
    lines = t.split("\n")
    lines = [l for l in lines if not (re.match(r"\s*EXTERN_C\b.*\b" + fn + r"\(", l) and l.rstrip().endswith(";") and "asm" not in l)]
    t = "\n".join(lines)
decls = []
for n in names:
    fn = n.split()[0]
    b = bodies[n]
    sig = b[:b.index("{")].strip()
    if sig.startswith("EXTERN_C") and (sig + ";") not in pre and not re.search(re.escape(sig[:sig.index(fn)]) + fn + r"\([^)]*\);", pre):
        decls.append(sig + ";")
if decls: pre = (pre + "\n" + "\n".join(decls)).strip()
if pre:
    i = t.rindex("#endif")
    t = t[:i] + pre + "\n\n" + t[i:]
h.write_text(t)
for n in names:
    fn = n.split()[0]
    hit = 0
    for u in ("battle.cpp", "battle_b.cpp", "battle_c.cpp"):
        cpp = ROOT / "src/battle" / u
        text = cpp.read_text()
        for d in ("battle", u[:-4]):
            line = f'INCLUDE_ASM("asm/battle/nonmatchings/{d}", {fn});'
            if text.count(line) == 1:
                cpp.write_text(text.replace(line, bodies[n])); hit += 1; text = cpp.read_text()
    assert hit == 1, n
print("landed", len(names))
