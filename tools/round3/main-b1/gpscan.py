import re
from pathlib import Path
gp = {}; lui = {}
for s in Path('asm/main').rglob('func_*.s'):
    t = s.read_text(); f = int(s.stem[5:], 16)
    if f >= 0x8008B6B0: continue
    for m in set(re.findall(r'%gp_rel\((\w+)\)', t)): gp.setdefault(m, set()).add(f)
    for m in set(re.findall(r'%hi\((D_\w+)\)', t)): lui.setdefault(m, set()).add(f)
both = [k for k in gp if k in lui]
print('gp syms', len(gp), 'lui syms', len(lui), 'both', len(both))
# does every gp access to a symbol lie in a range not containing lui access?
bad = 0
for k in sorted(both):
    g = sorted(gp[k]); l = sorted(lui[k])
    inter = [x for x in l if g[0] <= x <= g[-1]]
    if inter: bad += 1
    print(k, 'gp %08X-%08X (%d)' % (g[0], g[-1], len(g)), 'lui n=%d' % len(l), 'lui-inside-gp-range=%d' % len(inter))
print('symbols with lui inside gp range:', bad)
