"""Selector family (gen_29.py shape) for any function: 7818 effect, 8CC0, 8C0C, vcall 21, handler chain.

gen(path) -> (name, [candidate bodies]); bodies use asm("name") aliases for every callee.
"""
import re

HDR = '''EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
'''


def lines_of(t):
    return [re.sub(r'^\s*/\*.*?\*/\s*', '', l).strip() for l in t.splitlines() if '/*' in l]


def args7818(lines):
    reg = {'$zero': 0}
    for i in lines:
        if i.startswith('jal'):
            break
        mm = re.match(r'addiu\s+(\$\w+), (\$\w+), (-?0x[0-9A-Fa-f]+|-?\d+)', i)
        if mm:
            reg[mm.group(1)] = reg.get(mm.group(2), 0) + int(mm.group(3), 0)
        mm = re.match(r'addu\s+(\$\w+), (\$\w+), (\$\w+)', i)
        if mm and mm.group(1) in ('$a1', '$a2', '$a3'):
            reg[mm.group(1)] = reg.get(mm.group(2), 0) + reg.get(mm.group(3), 0)
    return reg['$a1'], reg['$a2'], reg['$a3']


def aliases(names):
    out = ''
    for n in dict.fromkeys(names):
        out += f'EXTERN_C int {n}_c(void *p, unsigned *flags) asm("{n}");\n'
    return out


def ret_variants(call, dummy_first=False):
    plain = f'    if ({call})\n        return 1;'
    dummy = f'    if ({call}) {{\n        if (p || flags)\n            return 1;\n        else\n            return 1;\n    }}'
    return [dummy, plain] if dummy_first else [plain, dummy]


def gen(path):
    t = open(path).read()
    name = re.search(r'glabel (\w+)', t).group(1)
    L = lines_of(t)
    N = re.findall(r'jal\s+(\w+)', t)
    assert len(N) == 11 and N[0] == 'func_800D7818' and N[4] == 'func_800D84C8' and N[5] == 'func_800D8350', (path, N)
    a1, a2, a3 = args7818(L)
    j = [k for k, i in enumerate(L) if i.startswith('sw') and '0x9F0' in i and L[k + 1].startswith('j')]
    last = max(k for k, i in enumerate(L) if i.startswith('jal'))
    retone = L[last + 2].startswith('addiu') and L[last + 2].endswith('0x1')
    cands = []
    for r9 in ret_variants(f'{N[9]}_c(p, flags)', bool(j)):
        for ro in ([retone, not retone]):
            tail = (f'    {N[10]}_c(p, flags);\n    return 1;') if ro else f'    return {N[10]}_c(p, flags);'
            cands.append(f'''{HDR}{aliases([N[k] for k in (3, 6, 7, 8, 9, 10)])}
EXTERN_C int {name}(BimMon *p, unsigned *flags)
{{
    func_800D7818(p, {a1}, {a2}, {a3}, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if ({N[3]}_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {{
        if (func_800D8350(p, 3)) {{
            if ((*flags & 2) && {N[6]}_c(p, flags) && !p->f9F0) {{
                p->f9F0 = 0x10;
                return 1;
            }}
            if ((*flags & 1) && {N[7]}_c(p, flags))
                return 1;
        }}
    }}
    if ({N[8]}_c(p, flags))
        return 1;
{r9}
{tail}
}}''')
    return name, cands
