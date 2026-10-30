"""Selector family, general: C built from the call sequence of the asm.

Blocks: 7818 effect (args from a1-a3 and the stack), 8CC0 (f9C8 test), 8C0C, vcall 21 (jalr), handler
'if (H(p, flags)) return 1;', the 84C8/8350 block (two handlers inside), and the last handler (returned, or
called then 'return 1'). Candidates vary the dummy on each handler block and the last-return form.
"""
import itertools, re

HDR = '''EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
'''


def lines_of(t):
    return [re.sub(r'^\s*/\*.*?\*/\s*', '', l).strip() for l in t.splitlines() if '/*' in l]


def args7818(L):
    reg = {'$zero': 0}
    st = {}
    stop = [n for n, i in enumerate(L) if i.startswith('jal')][0] + 2
    for i in L[:stop]:
        mm = re.match(r'addiu\s+(\$\w+), (\$\w+), (-?0x[0-9A-Fa-f]+|-?\d+)$', i)
        if mm and mm.group(2) in reg:
            reg[mm.group(1)] = reg[mm.group(2)] + int(mm.group(3), 0)
        mm = re.match(r'addu\s+(\$\w+), (\$\w+), (\$\w+)$', i)
        if mm and mm.group(2) in reg and mm.group(3) in reg:
            reg[mm.group(1)] = reg[mm.group(2)] + reg[mm.group(3)]
        mm = re.match(r'sw\s+(\$\w+), (0x[0-9A-F]+)\(\$sp\)$', i)
        if mm and int(mm.group(2), 16) in (0x10, 0x14, 0x18, 0x1C, 0x20):
            st[int(mm.group(2), 16)] = reg[mm.group(1)]
    return [reg['$a1'], reg['$a2'], reg['$a3']] + [st[o] for o in (0x10, 0x14, 0x18, 0x1C, 0x20)]


class Unsupported(Exception):
    pass


def gen(path, maxc=64):
    t = open(path).read()
    name = re.search(r'glabel (\w+)', t).group(1)
    L = lines_of(t)
    seq = [('r' if i.startswith('jalr') else re.match(r'jal\s+(\w+)', i).group(1))
           for i in L if i.startswith('jal')]
    if seq[0] != 'func_800D7818':
        raise Unsupported('head')
    has8cc0 = seq[1] == 'func_800D8CC0' or bool(re.search(r'jal\s+func_800D7818\n.*\n.*lw\s+\$v0, 0x9C8\(\$s0\)', t))
    f8cc0 = seq[1] if seq[1] == 'func_800D8CC0' else seq[1] + '_c'
    xh = [seq[1]] if has8cc0 and seq[1] != 'func_800D8CC0' else []
    a = args7818(L)
    last = max(k for k, i in enumerate(L) if i.startswith('jal'))
    retone = L[last + 2].startswith('addiu') and L[last + 2].endswith('0x1')
    cmd = 0x10
    for n, i in enumerate(L):
        if re.match(r'sw\s+\$v0, 0x9F0\(\$s0\)', i):
            for b in L[n - 3:n][::-1]:
                mm = re.match(r'addiu\s+\$v0, \$zero, (0x[0-9A-F]+)$', b)
                if mm:
                    cmd = int(mm.group(1), 16); break
            break
    vslots = [int(m, 16) // 8 - 1 for m in re.findall(r'lh\s+\$a0, (0x[0-9A-F]+)\(\$v0\)', t)]
    a8350s = [int(m, 16) for m in re.findall(r'jal\s+func_800D8350\n\s*/\*.*?\*/\s+addiu\s+\$a1, \$zero, (0x[0-9A-F]+)', t)]
    blocks = []
    handlers = []
    k = 2 if has8cc0 else 1
    while k < len(seq) - 1:
        s = seq[k]
        if s == 'func_800D8C0C':
            blocks.append(('stmt', '    func_800D8C0C(p);'))
        elif s == 'r':
            blocks.append(('stmt', f'    if (((BimV *)p)->v{vslots.pop(0)}((int)flags))\n        return 1;'))
        elif s == 'func_800D84C8' and seq[k + 1] == 'func_800D8350' and \
                not re.search(r'jal\s+func_800D8350\n.*\n\s*/\*.*?\*/\s+b(eq|ne)z\s+\$v0', t):
            a8350 = a8350s.pop(0)
            blocks.append(('stmt', f'    if (func_800D84C8(p))\n        func_800D8350(p, {a8350});'))
            k += 1
        elif s == 'func_800D84C8' and seq[k + 1] == 'func_800D8350' and k + 2 < len(seq) and \
                re.search(r'jal\s+func_800D8350\n(?:.*\n){1,3}?\s*/\*.*?\*/\s+addu\s+\$a0.*\n\s*/\*.*?\*/\s+jal\s+%s\b' % seq[k + 2], t):
            h1 = seq[k + 2]
            handlers.append(h1)
            a8350 = a8350s.pop(0)
            blocks.append(('stmt', f'    if (func_800D84C8(p)) {{\n        if (func_800D8350(p, {a8350})) {{\n'
                                   f'            if ({h1}_c(p, flags))\n                return 1;\n        }}\n    }}'))
            k += 2
        elif s == 'func_800D84C8' and seq[k + 1] == 'func_800D8350' and k + 3 < len(seq):
            h1, h2 = seq[k + 2], seq[k + 3]
            handlers += [h1, h2]
            a8350 = a8350s.pop(0)
            blocks.append(('stmt', f'''    if (func_800D84C8(p)) {{
        if (func_800D8350(p, {a8350})) {{
            if ((*flags & 2) && {h1}_c(p, flags) && !p->f9F0) {{
                p->f9F0 = 0x{cmd:X};
                return 1;
            }}
            if ((*flags & 1) && {h2}_c(p, flags))
                return 1;
        }}
    }}'''))
            k += 3
        elif s.startswith('bimf_') or re.match(r'func_800D[B-F]', s):
            handlers.append(s)
            blocks.append(('h', s))
        else:
            raise Unsupported('call ' + s)
        k += 1
    lastfn = seq[-1]
    if not (lastfn.startswith('bimf_') or re.match(r'func_800D[B-F]', lastfn)):
        raise Unsupported('last ' + lastfn)
    handlers.append(lastfn)
    handlers += xh
    hs = [i for i, b in enumerate(blocks) if b[0] == 'h']
    decl = HDR + ''.join(f'EXTERN_C int {n}_c(void *p, unsigned *flags) asm("{n}");\n' for n in dict.fromkeys(handlers))
    cands = []
    # dummy subsets: none, each single one (last handler first), then pairs
    subsets = [()] + [(i,) for i in reversed(hs)] + list(itertools.combinations(hs, 2))
    for ro in (retone, not retone):
        for sub in subsets:
            body = [f'    func_800D7818(p, {", ".join(str(x) for x in a)});']
            if has8cc0:
                body.append('    if (!(p->f9C8 > 0) && (*flags & 1) && ' + f8cc0 + '(p, flags))\n        return 1;')
            for i, (kind, x) in enumerate(blocks):
                if kind == 'stmt':
                    body.append(x)
                elif i in sub:
                    body.append(f'    if ({x}_c(p, flags)) {{\n        if (p || flags)\n            return 1;\n'
                                f'        else\n            return 1;\n    }}')
                else:
                    body.append(f'    if ({x}_c(p, flags))\n        return 1;')
            body.append(f'    {lastfn}_c(p, flags);\n    return 1;' if ro else f'    return {lastfn}_c(p, flags);')
            cands.append(decl + f'\nEXTERN_C int {name}(BimMon *p, unsigned *flags)\n{{\n' + '\n'.join(body) + '\n}')
            if len(cands) >= maxc:
                return name, cands
    return name, cands
