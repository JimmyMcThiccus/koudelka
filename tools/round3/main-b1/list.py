import re, sys
from pathlib import Path
UNITS = ['main_b','u_80056E0C','u_8005F238','u_80062610','u_800658E0','u_80067450','u_80059A84']
rows=[]
for u in UNITS:
    for name in re.findall(r'INCLUDE_ASM\("[^"]+", (func_\w+)\);', Path(f'src/main/{u}.cpp').read_text()):
        t = Path(f'asm/main/nonmatchings/{u}/{name}.s').read_text()
        size = int(re.search(r'nonmatching \S+, (0x[0-9A-F]+)', t).group(1), 16)
        rows.append((size,u,name))
rows.sort()
for s,u,n in rows: print(f'{s:#x} {u} {n}')
print(len(rows))
