import re, sys
from pathlib import Path
UNITS = ['u_8006BFE4','u_80068770','u_8006CBCC','u_80071A74','u_80082174','u_80083EB4','u_80085168','u_80089024']
# usage: dump.py func_X ... ; prints asm
names=set(sys.argv[1:])
for u in UNITS:
    for name in re.findall(r'INCLUDE_ASM\("[^"]+", (func_\w+)\);', Path(f'src/main/{u}.cpp').read_text()):
        if name not in names: continue
        t = Path(f'asm/main/nonmatchings/{u}/{name}.s').read_text()
        print(f'==== {u} {name}')
        for line in t.splitlines():
            x = re.match(r'\s*/\* \S+ \S+ \S+ \*/\s+(.*)', line)
            if x: print('  ', re.sub(r'\s+', ' ', x.group(1)))
            elif line.strip().startswith(('.L','jlabel','glabel')) : print(line.strip())
