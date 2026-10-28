import re, subprocess, sys
from pathlib import Path
sys.path.insert(0, 'scratch_c')
from mb import unit_of
res = []
for d in sys.argv[1:]:
    for f in sorted(Path(d).glob('*.cpp')):
        if f.name.startswith('_'): continue
        t = f.read_text(errors='ignore')
        names = sorted(set(re.findall(r'^//// (func_[0-9A-F]{8})', t, re.M)))
        names = [n for n in names if unit_of(n)]
        if not names: continue
        r = subprocess.run([sys.executable, 'scratch_c/mb.py', str(f)] + names, capture_output=True, text=True)
        last = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else ''
        ok = last.split(':', 1)[1].split() if ' ok:' in last else []
        print(f, len(names), 'ok', ok, flush=True)
