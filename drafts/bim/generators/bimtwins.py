import re, sys, glob, difflib, os
sys.path.insert(0, 'tools')
from pathlib import Path
from twins import norm
rem = [l.split()[0] for l in open('scratch_c/remaining.txt')]
rem = [Path(p) for p in open('scratch_c/remaining.txt').read().split()]
done = {}
for p in glob.glob('asm/bim/*/matchings/*/*.s'):
    n = os.path.basename(p)[:-2]
    key = re.sub(r'_\d+$', '', n) if n.startswith('bimf') else p
    if key in done: continue
    done[key] = (p, norm(Path(p)))
seen = set()
for p in rem:
    n = p.stem; key = re.sub(r'_\d+$', '', n) if n.startswith('bimf') else str(p)
    if key in seen: continue
    seen.add(key)
    a = norm(p); best = (0, None)
    for k, (q, b) in done.items():
        if abs(len(a) - len(b)) > 0.3 * len(a): continue
        sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
        if sm.real_quick_ratio() < best[0] or sm.quick_ratio() < best[0]: continue
        r = sm.ratio()
        if r > best[0]: best = (r, q)
    print(f'{best[0]:.3f} {len(a)} {p} {best[1]}', flush=True)
