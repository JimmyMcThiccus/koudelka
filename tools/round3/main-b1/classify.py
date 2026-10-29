import re
from pathlib import Path
UNITS = ['main_b','u_80056E0C','u_8005F238','u_80062610','u_800658E0','u_80067450','u_80059A84']
rows=[]
for u in UNITS:
    for name in re.findall(r'INCLUDE_ASM\("[^"]+", (func_\w+)\);', Path(f'src/main/{u}.cpp').read_text()):
        t = Path(f'asm/main/nonmatchings/{u}/{name}.s').read_text()
        size = int(re.search(r'nonmatching \S+, (0x[0-9A-F]+)', t).group(1), 16)
        vb = bool(re.search(r'andi\s+\$\w+, \$\w+, 0x2\b', t)) and 'in_chrg' or ''
        vb = 'VB' if (re.search(r'addiu\s+\$\w+, \$\w+, 0x50\b', t) and re.search(r'andi\s+\$\w+, \$\w+, 0x2\b', t)) else ''
        jt = 'JT' if '.word' in t else ''
        ncall = len(re.findall(r'\bjal\b', t))
        rows.append((size,u,name,vb,jt,ncall))
rows.sort()
for r in rows:
    print(f'{r[0]:#x} {r[1]} {r[2]} {r[3]} {r[4]} calls={r[5]}')
