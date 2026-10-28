import re
from pathlib import Path

h = Path('include/game/a/main_a.h')
c = Path('src/main/game.cpp')
ht = h.read_text()
ct = c.read_text()
callees = re.findall(r'^EXTERN_C void (func_[0-9A-F]{8})\(void \*p\);$', ht, flags=re.M)
for g in callees:
    ht = ht.replace(f'EXTERN_C void {g}(void *p);', f'EXTERN_C void {g}(void *p, int a);')
    # wrapper bodies
    ct, n = re.subn(r'EXTERN_C void (func_[0-9A-F]{8})\(void \*p\)\n\{\n    ' + g + r'\(p\);\n\}',
                    lambda m: f'EXTERN_C void {m[1]}(void *p, int a)\n{{\n    {g}(p, a);\n}}', ct)
    print(g, n)
# D_800B4C18 is a pointer to an object with a u16 at 0x94
ht = ht.replace('EXTERN_C int D_800B4C18;\n', '')
ht = ht.replace('typedef struct S_8001F1BC {\n    char pad0[0x94];\n    unsigned short unk94;\n} S_8001F1BC;\n',
                'typedef struct S_8001F1BC {\n    char pad0[0x94];\n    unsigned short unk94;\n} S_8001F1BC;\n\n'
                'EXTERN_C S_8001F1BC *D_800B4C18;\nEXTERN_C S_8001F1BC *D_800B4C1C;\n')
assert 'D_800B4C1C' in ht
old = 'EXTERN_C int func_8001F1E4()\n{\n    return D_800B4C18;\n}'
assert old in ct
ct = ct.replace(old, 'EXTERN_C S_8001F1BC *func_8001F1E4()\n{\n    return D_800B4C18;\n}')
h.write_text(ht, newline='\n')
c.write_text(ct, newline='\n')
