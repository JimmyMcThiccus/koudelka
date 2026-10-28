import re, sys
from pathlib import Path
src = Path("src/main/sound.cpp"); t = src.read_text()
hdr = Path("include/game/sound/sound.h"); h = hdr.read_text()
for name in sys.argv[1:]:
    m = re.search(r"struct %s \{.*?\n\};\n\n?" % name, t, re.S)
    if not m: print("no", name); continue
    t = t[:m.start()] + t[m.end():]
    i = h.index("EXTERN_C void func_80094990();")
    h = h[:i] + m.group(0).rstrip("\n") + "\n\n" + h[i:]
src.write_text(t); hdr.write_text(h)
