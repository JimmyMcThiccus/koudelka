"""usage: multi.py file.cpp [-v] [names...]; file = prelude, then `//// func_XXXXXXXX` sections"""
import re, subprocess, sys
from pathlib import Path
UNITS=[(0x8003C510,'u_8003C510'),(0x8003F7E8,'u_8003F7E8'),(0x80044BE4,'u_80044BE4'),(0x80045850,'u_80045850')]
def unit(n):
    a=int(n[5:13],16); u=None
    for st,nm in UNITS:
        if a>=st: u=nm
    return u
PY="C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe"
path = Path(sys.argv[1]); verbose = '-v' in sys.argv
only = [a for a in sys.argv[2:] if a != '-v']
parts = re.split(r'^//// (func_[0-9A-F]{8}(?: \w+)?)[^\n]*\n', path.read_text(), flags=re.M)
hdr = '#include "common.h"\n#include "shared/vbase.h"\n#include "game/a/main_a.h"\n#include "game/a/decls_a.h"\n#include "game/a2/a2.h"\n#include "game/a2b/a2b.h"\n'
prelude = hdr + parts[0]
ok = []
for label, body in zip(parts[1::2], parts[2::2]):
    name=label.split()[0]
    if only and name not in only and label not in only: continue
    f = Path('scratch_c/_m_' + name + '.cpp')
    f.write_text(prelude + body)
    r = subprocess.run([PY, "tools/try_compile.py", str(f), name, '--unit', f'src/main/{unit(name)}.cpp'] + ([] if verbose else ['--quiet']), capture_output=True, text=True)
    errs=[l for l in r.stderr.splitlines() if 'error' in l]
    last = (r.stdout.strip().splitlines() or ['compile error: '+' | '.join(errs[:4])[:400]])[-1]
    good = ' 0 differing' in last
    ok += [label] if good else []
    print(('OK  ' if good else 'BAD ') + label + ' ' + last)
    if not good and verbose:
        print(r.stdout[-6000:] + r.stderr[-2000:])
print(f'{len(ok)} ok: ' + ' '.join(ok))
