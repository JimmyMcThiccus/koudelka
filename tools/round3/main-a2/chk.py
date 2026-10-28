# report prelude EXTERN_C function decls whose name is already declared (defs.h/a2.h/main_a.h) with a different text
import re,sys
from pathlib import Path
known={}
for f in ['scratch_c/defs.h','include/game/a2/a2.h','include/game/a/main_a.h','include/game/a/decls_a.h']:
    for l in Path(f).read_text().split('\n'):
        m=re.match(r'EXTERN_C .*?\b(func_[0-9A-F]{8}|D_[0-9A-F]{8})\b.*;',l)
        if m: known.setdefault(m.group(1),set()).add(re.sub(r'\s+',' ',l.strip()))
t=Path(sys.argv[1]).read_text()
for l in t.split('\n'):
    m=re.match(r'EXTERN_C .*?\b(func_[0-9A-F]{8}|D_[0-9A-F]{8})\b.*;',l)
    if m and m.group(1) in known and re.sub(r'\s+',' ',l.strip()) not in known[m.group(1)]:
        print('CONFLICT', l, '<->', known[m.group(1)])
