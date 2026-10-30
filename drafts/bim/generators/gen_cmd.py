"""Command handlers (0x421 / 0x121 / 0x21 actions): bimf_e310b46d / bimf_dd77db6b shapes with an optional
leading func_800D7818 effect and other call arguments, all read from the asm."""
import re, sys
sys.path.insert(0, 'scratch_c')
import gen_sel2

TEMPLATES = ['src/bim/shared/bimf_e310b46d.cpp', 'src/bim/shared/bimf_dd77db6b.cpp']


def body_of(path):
    t = open(path).read()
    i = t.index('EXTERN_C int')
    return t[i:]


def call_args(t, fn, nargs):
    """values of a1..a(nargs) at each call of fn (constants only)"""
    L = [re.sub(r'\s+', ' ', x) for x in gen_sel2.lines_of(t)]
    out = []
    reg = {'$zero': 0}

    def step(i):
        mm = re.match(r'addiu (\$\w+), (\$\w+), (-?0x[0-9A-Fa-f]+|-?\d+)$', i)
        if mm:
            if mm.group(2) in reg:
                reg[mm.group(1)] = reg[mm.group(2)] + int(mm.group(3), 0)
            else:
                reg.pop(mm.group(1), None)
            return
        mm = re.match(r'addu (\$\w+), (\$\w+), (\$\w+)$', i)
        if mm:
            if mm.group(2) in reg and mm.group(3) in reg:
                reg[mm.group(1)] = reg[mm.group(2)] + reg[mm.group(3)]
            else:
                reg.pop(mm.group(1), None)
            return
        mm = re.match(r'\w+ (\$\w+),', i)
        if mm and not i.startswith('s') and not i.startswith('b'):
            reg.pop(mm.group(1), None)
    k = 0
    while k < len(L):
        i = L[k]
        if i.startswith('jal'):
            if k + 1 < len(L):
                step(L[k + 1])
            if i.split(' ')[1] == fn:
                out.append([reg.get(f'$a{j}') for j in range(1, nargs + 1)])
            for r in ('$v0', '$v1', '$a0', '$a1', '$a2', '$a3'):
                reg.pop(r, None)
            k += 2
            continue
        step(i)
        k += 1
    return out


def gen(path):
    t = open(path).read()
    name = re.search(r'glabel (\w+)', t).group(1)
    pre = ''
    if 'jal        func_800D7818' in t:
        a = gen_sel2.args7818(gen_sel2.lines_of(t))
        pre = f'    func_800D7818(p, {", ".join(str(x) for x in a)});\n'
    e = call_args(t, 'func_800D8E64', 1)[0][0]
    ac4 = call_args(t, 'func_800D7AC4', 3)[0]
    bb4 = call_args(t, 'func_800D7BB4', 3)[0]
    cands = []
    for tp in TEMPLATES:
        b = body_of(tp)
        b = re.sub(r'EXTERN_C int bimf_\w+\(', f'EXTERN_C int {name}(', b, count=1)
        b = b.replace('{\n    func_800D8E64(p, -1);', '{\n' + pre + f'    func_800D8E64(p, {e});')
        b = b.replace('func_800D7AC4(p, q, 0, 0)', f'func_800D7AC4(p, q, {ac4[1]}, {ac4[2]})')
        b = b.replace('func_800D7BB4(p, (int)q, 0, 0)', f'func_800D7BB4(p, (int)q, {bb4[1]}, {bb4[2]})')
        cands.append(b)
        if re.search(r'addiu\s+\$a0, \$zero, -0x3\n.*\n.*\n.*addiu\s+\$v1, \$zero, 0x10\n', t):
            for x in ('        *flags &= ~2;\n        p->f9F0 = 0x10;\n        return 1;',
                      '        int r = 1;\n        *flags &= ~2;\n        p->f9F0 = 0x10;\n        return r;'):
                cands.append(b.replace('        *flags &= ~2;\n        return 1;', x, 1))
    return name, cands
