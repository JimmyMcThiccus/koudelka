import re
decl = set()
secs = []
for l in open('scratch_c/d32.txt'):
    m = re.match(r'([0-9A-F]{8}): addiu \$sp, \$sp, -0x18 \| sw \$ra, 0x10\(\$sp\) \| jal (func_\w+) \| nop \| lw', l)
    if not m:
        continue
    a, g = m.groups()
    decl.add(g)
    secs.append(f'//// func_{a}\nextern "C" void func_{a}(void *p)\n{{\n    {g}(p);\n}}\n')
open('scratch_c/b3w.cpp', 'w').write(''.join(f'extern "C" void {d}(void *p);\n' for d in sorted(decl)) + ''.join(secs))
print(len(secs), sorted(decl))
