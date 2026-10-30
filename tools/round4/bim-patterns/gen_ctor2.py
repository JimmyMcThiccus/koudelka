"""Virtual-base constructors of the BIM.AR monster classes (func_800DAB3C family), any tail.

gen(path) -> (name, [candidate C sources]) ; candidates differ only in the source order of the tail stores.
"""
import itertools, re

FIN = 'func_800D8D64'


def ins(path):
    out = []
    for l in open(path).read().splitlines():
        m = re.search(r'\*/\s+(.*)$', l)
        if m and '/*' in l:
            out.append(re.sub(r'\s+', ' ', m.group(1).strip()))
    return out


def ops(i):
    op, _, a = i.partition(' ')
    return op, [x.strip() for x in a.split(',')] if a else []


def num(x):
    return int(x, 0)


def fld(base, off):
    if off == 0x9D8:
        return f'{base}->f9D8'
    if off == 0x9DC:
        return f'{base}->f9DC'
    return f'*(int *)((char *){base} + 0x{off:X})'


class Unsupported(Exception):
    pass


def gen(path, tails=None, extra=()):
    text = open(path).read()
    name = re.search(r'glabel (\w+)', text).group(1)
    I = ins(path)
    sy = re.findall(r'%hi\((\w+)\)', text)
    d0178, d04a8, vt, _, v8c, _, v1e4, _, v49c, v4a8, v980, v0sym = sy[:12]
    assert d0178 == 'D_80010178' and d04a8 == 'D_800104A8', path
    jals = [ops(i)[1][0] for i in I if i.startswith('jal ')]
    ctor, tab, fin = jals[:3]
    assert fin == FIN, path
    vb = num(re.search(r'addiu \$v0, \$s[01], (0x[0-9A-F]+)', '\n'.join(I)).group(1))
    # self register
    selfreg = '$s0' if 'addu $s0, $a0, $zero' in I else '$s1'
    kfin = [n for n, x in enumerate(I) if x == f'jal {FIN}'][0]
    ktab = [n for n, x in enumerate(I) if x == f'jal {tab}'][0]
    # constants
    reg = {'$zero': 0}

    def setc(i):
        op, a = ops(i)
        if op == 'addiu' and a[1] == '$zero':
            reg[a[0]] = num(a[2])
        elif op == 'addu' and a[2] == '$zero' and a[1] in reg:
            reg[a[0]] = reg[a[1]]
        elif op == 'addu' and a[1] == '$zero' and a[2] in reg:
            reg[a[0]] = reg[a[2]]
        elif op in ('addiu', 'addu', 'lw', 'lui', 'ori', 'subu', 'sll', 'sra'):
            reg.pop(a[0], None)
    stack = {}
    for i in I[ktab + 2:kfin + 2]:
        setc(i)
        op, a = ops(i)
        if op == 'sw' and a[1].endswith('($sp)'):
            stack[num(a[1].split('(')[0])] = reg[a[0]]
    finargs = [reg['$a1'], reg['$a2'], reg['$a3']] + [stack[o] for o in (0x10, 0x14, 0x18, 0x1C, 0x20)]
    # tail
    tail = I[kfin + 2:]
    epi = [n for n, x in enumerate(tail) if x.startswith('lw $ra,')][0]
    body = tail[:epi]
    if tails is not None:
        body = []
    elif any(ops(i)[0].startswith('b') or ops(i)[0] == 'j' for i in body):
        raise Unsupported('branchy tail')
    segs = []   # list of (kind, stores, call)  kind 'call' or 'ret'
    cur = []
    a1set = None
    retseen = False
    n = 0
    while n < len(body):
        i = body[n]
        op, a = ops(i)
        if op == 'jal':
            # delay slot belongs to this call
            d = body[n + 1]
            dop, da = ops(d)
            if dop == 'sw':
                cur.append((num(da[1].split('(')[0]), reg[da[0]]))
            else:
                setc(d)
                if da and da[0] == '$a1':
                    a1set = reg['$a1']
            segs.append(('call', cur, (a[0], a1set)))
            cur = []
            a1set = None
            for r in ('$v0', '$v1', '$a0', '$a1', '$a2', '$a3', '$t0'):
                reg.pop(r, None)
            n += 2
            continue
        if op == 'addu' and a[1] == selfreg and a[2] == '$zero' and a[0] == '$v0':
            retseen = True
            n += 1
            continue
        if op == 'addu' and a[1] == selfreg and a[0] == '$a0':
            n += 1
            continue
        if op == 'sw':
            base = a[1].split('(')[1].rstrip(')')
            if retseen:
                assert base == '$v0', (path, i)
            else:
                assert base == selfreg, (path, i)
            if a[0] not in reg:
                raise Unsupported('store of unknown ' + i)
            cur.append((num(a[1].split('(')[0]), reg[a[0]]))
            n += 1
            continue
        setc(i)
        if a and a[0] == '$a1':
            a1set = reg.get('$a1')
        n += 1
    if not retseen and tails is None:
        raise Unsupported('no return copy')
    cands = list(tails) if tails is not None else []
    if tails is not None:
        segs = []
    else:
        segs.append(('ret', cur, None))
    orders = [list(itertools.permutations(s[1])) if len(s[1]) <= 5 else [tuple(s[1])] for s in segs]
    # asm order first
    for combo in (itertools.product(*orders) if segs else []):
        lines = []
        for (kind, _, call), st in zip(segs, combo):
            if kind == 'call':
                for o, v in st:
                    lines.append(f'    {fld("self", o)} = {v};')
                fn, a1 = call
                lines.append(f'    {fn}_c(self{", %d" % a1 if a1 is not None else ""});')
            else:
                lines.append('    register BimDtor *r asm("$2") = self;')
                for o, v in st:
                    lines.append(f'    {fld("r", o)} = {v};')
                lines.append('    return r;')
        cands.append('\n'.join(lines))
        if len(cands) >= 200:
            break
    calls = sorted({(s[2][0], s[2][1] is not None) for s in segs if s[0] == 'call'})
    vbexpr = '&self->vtAEC' if vb == 0xAEC else f'(char *)self + 0x{vb:X}'
    decl = ('EXTERN_C char D_80010178[], D_800104A8[];\n'
            f'EXTERN_C char {v980}[], {v4a8}[], {v49c}[], {v1e4}[], {v8c}[], {v0sym}[];\n'
            f'EXTERN_C const BimVTable10 {vt};\n'
            f'EXTERN_C void {ctor}_c(void *self, int a, int b, int c, int d, int e, int f) asm("{ctor}");\n'
            f'EXTERN_C void {tab}_c(void *self, int a) asm("{tab}");\n'
            f'EXTERN_C void {FIN}_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("{FIN}");\n')
    for d in extra:
        decl += d + '\n'
    for fn, has in calls:
        decl += f'EXTERN_C void {fn}_c(void *self{", int a" if has else ""}) asm("{fn}");\n'
    fa = ', '.join(str(x) for x in finargs)
    head = f'''EXTERN_C BimDtor *{name}(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{{
    if (in_chrg) {{
        BimVBase *vb = self->vb1DC = (BimVBase *)({vbexpr});
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }}
    {ctor}_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&{vt};
    if (!in_chrg) {{
        BimVTable10 vt = {vt};
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = {vt}.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0x{vb:X}));
        vt.e[6].delta = {vt}.e[6].delta + adj;
    }}
    self->vt8C = {v8c};
    self->vt1E0 = D_8001262C;
    self->vt1E4 = {v1e4};
    self->vt3FC = D_80017ADC;
    self->vt49C = {v49c};
    self->vt4A8 = {v4a8};
    self->vt980 = {v980};
    self->vt0 = {v0sym};
    {tab}_c(self, b);
    {FIN}_c(self, {fa});
'''
    return name, decl, [head + c + '\n}\n' for c in cands]
