import re
from pathlib import Path
UNITS = ['u_8006BFE4','u_80068770','u_8006CBCC','u_80071A74','u_80082174','u_80083EB4','u_80085168','u_80089024']
rows=[]
for u in UNITS:
    for name in re.findall(r'INCLUDE_ASM\("[^"]+", (func_\w+)\);', Path(f'src/main/{u}.cpp').read_text()):
        t = Path(f'asm/main/nonmatchings/{u}/{name}.s').read_text()
        size = int(re.search(r'nonmatching \S+, (0x[0-9A-F]+)', t).group(1), 16)
        lui = any(m.group(1) == m.group(3) for m in re.finditer(r'l[whb]u?\s+(\$\w+), %lo\((\w+)\)\((\$\w+)\)', t))
        vb = 'in_chrg' in t or '0x50' in t
        rows.append((size,u,name,lui))
rows.sort()
print(len(rows))
for s,u,n,l in rows: print(f'{s:#x} {u} {n}{" LUI" if l else ""}')
