"""Land sections into their units; the prelude goes at the end of include/game/b/decls_b.h.
usage: land.py file.cpp [names...]"""
import re, sys
from pathlib import Path
sys.path.insert(0, 'scratch_c')
from mb import unit_of
path = Path(sys.argv[1]); only = set(sys.argv[2:])
parts = re.split(r'^//// (func_[0-9A-F]{8})[^\n]*\n', path.read_text(), flags=re.M)
fix = lambda s: s.replace('extern "C"', 'EXTERN_C').strip('\n')
n = 0
for name, body in zip(parts[1::2], parts[2::2]):
    if only and name not in only: continue
    u = unit_of(name)
    if not u: continue
    t = u.read_text(); line = f'INCLUDE_ASM("asm/main/nonmatchings/{u.stem}", {name});'
    assert line in t
    u.write_text(t.replace(line, fix(body)), newline='\n'); n += 1
pre = fix(parts[0])
if pre and not (only and '--noprelude' in only):
    h = Path('include/game/b/decls_b.h'); s = h.read_text(); i = s.rindex('#endif')
    h.write_text(s[:i] + pre + '\n\n' + s[i:], newline='\n')
print('landed', n)
