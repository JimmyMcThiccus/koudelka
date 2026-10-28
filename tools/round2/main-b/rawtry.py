import sys, subprocess, re
from pathlib import Path
sys.path.insert(0, 'scratch_c')
from mb import unit_of
# usage: rawtry.py files... : run each self-contained file (name = func_X from filename) via try_compile
for f in sys.argv[1:]:
    name = re.search(r'func_[0-9A-F]{8}', Path(f).name).group(0)
    u = unit_of(name)
    if not u: continue
    r = subprocess.run([sys.executable, 'tools/try_compile.py', f, name, '--unit', u.as_posix(), '--quiet'], capture_output=True, text=True)
    last = (r.stdout.strip().splitlines() or ['compile error: ' + r.stderr.strip()[-200:].replace('\n',' ')])[-1]
    print(name, u.stem, last, flush=True)
