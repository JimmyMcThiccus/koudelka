"""Test several functions at once. File: prelude, then sections `//// func_XXXXXXXX`.
usage: multi.py file.cpp [-v] [names...]   (unit inferred from address)"""
import re, subprocess, sys
from pathlib import Path
UNITS=[(0x80032264,'u_80032264'),(0x80033ECC,'u_80033ECC'),(0x800372C0,'u_800372C0'),(0x80037398,'u_80037398'),(0x8003852C,'u_8003852C')]
def unit(name):
    a=int(name[5:13],16); u=None
    for s,n in UNITS:
        if a>=s: u=n
    return u
path = Path(sys.argv[1])
verbose = '-v' in sys.argv
only = [a for a in sys.argv[2:] if a != '-v']
parts = re.split(r'^//// (func_[0-9A-F]{8}(?: \w+)?)[^\n]*\n', path.read_text(), flags=re.M)
hdr = '#include "common.h"\n#include "shared/vbase.h"\n#include "game/a/main_a.h"\n#include "game/a/decls_a.h"\n'
import subprocess as _sp; _sp.run([sys.executable,'scratch_c/gendefs.py'],capture_output=True)
for h in [Path('include/game/a2/a2.h')]:
    hdr += f'#include "game/a2/{h.name}"\n'
_c=_sp.run([sys.executable,'scratch_c/chk.py',str(path)],capture_output=True,text=True).stdout
if _c: print(_c)
prelude = hdr + '#include "defs.h"\n' + parts[0]
ok = []
for label, body in zip(parts[1::2], parts[2::2]):
    name=label.split()[0]
    if only and name not in only and label not in only: continue
    f = Path('scratch_c/_m_' + name + '.cpp')
    _h=set(Path('include/game/a2/a2.h').read_text().split('\n'))
    f.write_text('\n'.join(l for l in (prelude + body).split('\n') if not (l.startswith('struct ') and l in _h)))
    r = subprocess.run(["C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe", "tools/try_compile.py", str(f), name, '--unit', f'src/main/{unit(name)}.cpp'] + ([] if verbose else ['--quiet']), capture_output=True, text=True)
    errs=[l for l in r.stderr.splitlines() if '.cpp:' in l or '.h:' in l]
    last = (r.stdout.strip().splitlines() or ['compile error: '+' | '.join(errs[:4])[:400]])[-1]
    good = ' 0 differing' in last
    ok += [label] if good else []
    print(('OK  ' if good else 'BAD ') + label + ' ' + last)
    if not good and verbose:
        print(r.stdout[-6000:] + r.stderr[-2000:])
print(f'{len(ok)} ok: ' + ' '.join(ok))
