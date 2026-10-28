import sys, re
from pathlib import Path
src = Path("src/main/sound.cpp")
text = src.read_text()
for fn in sys.argv[1:]:
    body = Path(f"scratch_c/{fn}.cpp").read_text()
    body = "\n".join(l for l in body.splitlines() if not l.startswith('#include "pre.h"')).strip("\n")
    line = f'INCLUDE_ASM("asm/main/nonmatchings/sound", {fn});'
    if line not in text:
        print("missing", fn); continue
    text = text.replace(line, body)
    print("landed", fn)
src.write_text(text)
