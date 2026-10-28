"""usage: multi.py file.cpp [-v] [names]
file: prelude, then sections `//// func_X src/path.cpp`; each compiled with that unit's #includes + prelude."""
import re, subprocess, sys
from pathlib import Path
path = Path(sys.argv[1]); verbose = '-v' in sys.argv
only = [a for a in sys.argv[2:] if a != '-v']
parts = re.split(r'^//// (\S+) (\S+)[^\n]*\n', path.read_text(), flags=re.M)
ok = []
for name, unit, body in zip(parts[1::3], parts[2::3], parts[3::3]):
    if only and name not in only: continue
    src = Path(unit).read_text()
    inc = ''.join(l + '\n' for l in src.splitlines() if l.startswith('#include'))
    f = Path('scratch_c/_m_' + name + '.cpp')
    f.write_text(inc + parts[0] + body)
    r = subprocess.run([sys.executable, 'tools/try_compile.py', str(f), name, '--unit', unit], capture_output=True, text=True)
    last = (r.stdout.strip().splitlines() or ['compile error'])[-1]
    good = ' 0 differing' in last
    if good: ok.append(name)
    print(('OK  ' if good else 'BAD ') + name + ': ' + last)
    if not good and verbose: print(r.stdout[-5000:] + r.stderr[-3000:])
print(f'{len(ok)} ok: ' + ' '.join(ok))
