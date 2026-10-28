"""Land matched sections of a batch file (see multi.py; all sections in ONE unit).
Re-verifies each named section with try_compile first; lands only those that match.
The prelude goes to include/game/a/h_<unit>.h (created and #included by the unit if missing);
`extern "C"` becomes EXTERN_C. Afterwards the batch file is renamed to *.landed.
usage: land.py file.cpp [names...]   (default: all sections that match)"""
import re, subprocess, sys
from pathlib import Path
sys.path.insert(0, 'scratch_c')
from multi import unit_of

path = Path(sys.argv[1])
only = set(sys.argv[2:])
r = subprocess.run([sys.executable, 'scratch_c/multi.py', str(path)] + sorted(only), capture_output=True, text=True)
print(r.stdout.strip().splitlines()[-1])
ok = set(r.stdout.strip().splitlines()[-1].split(':', 1)[1].split())
parts = re.split(r'^//// ([A-Za-z0-9_]+)[^\n]*\n', path.read_text(), flags=re.M)
fix = lambda s: s.replace('extern "C"', 'EXTERN_C').strip('\n')
units = {unit_of(n) for n in parts[1::2]}
assert len(units) == 1, units
unit = units.pop()
src = Path('src/main/%s.cpp' % unit)
text = src.read_text()
n = 0
for name, body in zip(parts[1::2], parts[2::2]):
    if name not in ok:
        continue
    line = f'INCLUDE_ASM("asm/main/nonmatchings/{unit}", {name});'
    assert line in text, name
    text = text.replace(line, fix(body))
    n += 1
pre = fix(parts[0])
hname = 'game/a/h_%s.h' % unit
hp = Path('include/' + hname)
if n and pre:
    if not hp.exists():
        g = 'GAME_A_H_%s_H' % unit.upper()
        hp.write_text(f'#ifndef {g}\n#define {g}\n\n/* Declarations for src/main/{unit}.cpp only. */\n\n#endif /* {g} */\n', newline='\n')
    h = hp.read_text()
    i = h.rindex('#endif')
    hp.write_text(h[:i] + pre + '\n\n' + h[i:], newline='\n')
if hp.exists() and f'#include "{hname}"' not in text:
    text = text.replace('#include "game/a/decls_a.h"\n', f'#include "game/a/decls_a.h"\n#include "{hname}"\n', 1)
src.write_text(text, newline='\n')
if n:
    path.rename(path.with_suffix('.landed'))
print(f'landed {n} in {unit}: ' + ' '.join(sorted(ok)))
