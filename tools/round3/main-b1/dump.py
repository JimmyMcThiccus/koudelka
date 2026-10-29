import re, sys
from pathlib import Path
# usage: dump.py MIN MAX [unit] -> remaining INCLUDE_ASM funcs in size range, compact asm
UNITS = ['main_b','u_80056E0C','u_8005F238','u_80062610','u_800658E0','u_80067450','u_80059A84']
lo, hi = int(sys.argv[1], 0), int(sys.argv[2], 0)
for u in [a for a in sys.argv[3:] if not a.startswith('-')] or UNITS:
    for name in re.findall(r'INCLUDE_ASM\("[^"]+", (func_\w+)\);', Path(f'src/main/{u}.cpp').read_text()):
        t = Path(f'asm/main/nonmatchings/{u}/{name}.s').read_text()
        size = int(re.search(r'nonmatching \S+, (0x[0-9A-F]+)', t).group(1), 16)
        if not lo <= size <= hi: continue
        ins = []
        for line in t.splitlines():
            x = re.match(r'\s*/\* \S+ \S+ \S+ \*/\s+(.*)', line)
            if x: ins.append(re.sub(r'\s+', ' ', x.group(1)))
            elif line.strip().startswith('.L'): ins.append(line.strip())
        lui = any(m.group(1) == m.group(3) for m in re.finditer(r'l[whb]u?\s+(\$\w+), %lo\((\w+)\)\((\$\w+)\)', t))
        if lui and '--nolui' in sys.argv: continue
        print(f"{u} {name} {size:#x}{' LUI' if lui else ''}: " + ' | '.join(ins))
