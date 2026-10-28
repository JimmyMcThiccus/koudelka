"""usage: land.py scratch.cpp  -- for each ok section `//// name unit`, replace INCLUDE_ASM line in unit with body (prelude NOT added)
Sections are given as landing text only: file format `//// name unit` then code. Replaces INCLUDE_ASM(.., name);"""
import re, sys
from pathlib import Path
parts = re.split(r'^//// (\S+) (\S+)[^\n]*\n', Path(sys.argv[1]).read_text(), flags=re.M)
only = sys.argv[2:]
for name, unit, body in zip(parts[1::3], parts[2::3], parts[3::3]):
    if only and name not in only: continue
    s = Path(unit).read_text()
    m = re.search(r'^INCLUDE_ASM\([^)]*\b%s\);\n' % re.escape(name), s, flags=re.M)
    if not m: print('no INCLUDE_ASM', name); continue
    s = s[:m.start()] + body.strip('\n') + '\n' + s[m.end():]
    Path(unit).write_text(s)
    print('landed', name)
