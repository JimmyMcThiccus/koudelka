import re
from pathlib import Path
UNITS = ['main_b', 'u_80056E0C', 'u_8005F238', 'u_80062610', 'u_800658E0', 'u_80071A74', 'u_80082174']
defs = {}
for u in UNITS:
    for m in re.finditer(r'^EXTERN_C ([^\n(]*?)\b(func_[0-9A-F]{8})\(([^)]*)\)\s*\n\{', Path(f'src/main/{u}.cpp').read_text(), re.M):
        defs[m.group(2)] = (m.group(1).strip(), m.group(3))
norm = lambda ps: [re.sub(r'\s*\b\w+$', '', p.strip()).replace(' ', '') for p in ps.split(',')] if ps.strip() not in ('', 'void') else []
for f in Path('include/game/b').glob('*.h'):
    for m in re.finditer(r'^EXTERN_C ([^\n(]*?)\b(func_[0-9A-F]{8})\(([^)]*)\);', f.read_text(), re.M):
        n = m.group(2)
        if n in defs:
            r, ps = defs[n]
            if r.replace(' ', '') != m.group(1).strip().replace(' ', '') or norm(ps) != norm(m.group(3)):
                print(f'{f.name}: {m.group(0)}  <->  DEF {r} {n}({ps})')
