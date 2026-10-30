"""Table initialisers: fill an (id, value) int table in the monster and register it in D_800B4D38[0]->tbl[slot].

usage: gen_tbl2.py <asm .s> [out.cpp]  -> prints/writes the function (with includes)
"""
import re, sys


def gen(path):
    t = open(path).read()
    name = re.search(r'glabel (\w+)', t).group(1)
    reg = {'$zero': 0}
    st = {}
    base = None
    for l in t.splitlines():
        mm = re.search(r'\*/\s+(\w+)\s+(.*)', l)
        if not mm:
            continue
        op, a = mm.group(1), mm.group(2).strip()
        if op == 'lui':
            r, v = a.split(', ', 1)
            mv = re.match(r'\(0x([0-9A-F]+) >> 16\)', v)
            if mv:
                reg[r] = int(mv.group(1), 16)
            else:
                reg.pop(r, None)
        elif op == 'ori':
            r, r2, v = a.split(', ', 2)
            mv = re.match(r'\(0x([0-9A-F]+) &', v)
            if r2 == '$zero':
                reg[r] = int(v, 0)
            elif mv:
                reg[r] = int(mv.group(1), 16)
            else:
                reg.pop(r, None)
        elif op == 'addiu':
            p = a.split(', ')
            if p[0] == '$a0':
                base = int(p[2], 0)
            elif p[1] == '$zero':
                reg[p[0]] = int(p[2], 0) & 0xFFFFFFFF
            else:
                reg.pop(p[0], None)
        elif op == 'sw':
            mo = re.match(r'(\$\w+), (0x[0-9A-F]+|\d+)\(\$a0\)', a)
            if mo:
                assert mo.group(1) in reg, (path, l)
                o = int(mo.group(2), 0)
                assert o not in st, (path, l)
                st[o] = reg[mo.group(1)]
    assert base is not None and base % 4 == 0, path
    lines = [f'EXTERN_C void {name}(char *p, int slot)', '{',
             '    int *q = (int *)p;', '    int s = (short)slot;', '    char **b = D_800B4D38;']
    for o in sorted(st):
        v = st[o]
        vs = f'0x{v:X}' if v < 0x80000000 else f'(int)0x{v:X}'
        lines.append(f'    *(int *)(p + 0x{o:X}) = {vs};')
    lines += [f'    int *v = q + {base // 4};', '    int **t = (int **)(*b + 0xF8);', '    t[s] = v;', '}']
    return name, '\n'.join(lines) + '\n', len(st), base


if __name__ == '__main__':
    name, body, n, base = gen(sys.argv[1])
    src = '#include "common.h"\n#include "bim/shared.h"\n\n' + body
    if len(sys.argv) > 2:
        open(sys.argv[2], 'w').write(src)
    else:
        print(src)
