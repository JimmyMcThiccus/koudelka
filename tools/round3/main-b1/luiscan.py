import re, sys
from pathlib import Path
# For each remaining function: list lui+load pairs of D_ symbols: same-reg (macro) vs split
UNITS = ['main_b', 'u_80056E0C', 'u_8005F238', 'u_80062610', 'u_800658E0', 'u_80071A74', 'u_80082174']
same = {}; split = {}
for u in UNITS:
    for name in re.findall(r'INCLUDE_ASM\("[^"]+", (func_\w+)\);', Path(f'src/main/{u}.cpp').read_text()):
        t = Path(f'asm/main/nonmatchings/{u}/{name}.s').read_text()
        his = dict()
        for m in re.finditer(r'lui\s+(\$\w+), %hi\((\w+)\)', t): his.setdefault(m.group(2), set()).add(m.group(1))
        for m in re.finditer(r'(lw|lh|lhu|lb|lbu|sw|sh|sb)\s+(\$\w+), %lo\((\w+)\)\((\$\w+)\)', t):
            op, rd, sym, base = m.groups()
            if op.startswith('l') and rd == base: same.setdefault(name, set()).add(sym)
for n, s in same.items(): print(n, ' '.join(sorted(s)))
