"""usage: var.py draft func unit variants.py  -- variants.py defines V = {name: (old, new)} replaced in draft text (old must occur)."""
import subprocess, sys, runpy
from pathlib import Path
draft, fn, unit, vf = sys.argv[1:5]
src = Path(draft).read_text()
V = runpy.run_path(vf)['V']
for k, v in V.items():
    t = src
    for old, new in (v if isinstance(v, list) else [v]):
        assert old in t, (k, old)
        t = t.replace(old, new)
    Path('scratch_c/_var.cpp').write_text(t)
    r = subprocess.run([sys.executable, 'tools/try_compile.py', 'scratch_c/_var.cpp', fn, '--unit', unit, '--quiet', '-I', 'drafts/sound'], capture_output=True, text=True)
    print(k, (r.stdout.strip().splitlines() or [r.stderr[-300:]])[-1])
