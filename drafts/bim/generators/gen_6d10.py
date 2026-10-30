import gen_sel2
BLOCKS = [
'''    int c = p->f9CC;
    if (c >= 2 && !*(int *)((char *)p + 0x9FC)) {
        *(int *)((char *)p + 0x9FC) = c & 3;
        p->f9CC = 0;
    }''',
'''    if (p->f9CC >= 2 && !*(int *)((char *)p + 0x9FC)) {
        *(int *)((char *)p + 0x9FC) = p->f9CC & 3;
        p->f9CC = 0;
    }''',
]
def gen(path):
    name, cands = gen_sel2.gen(path)
    out = []
    for b in BLOCKS:
        for c in cands:
            out.append(c.replace('func_800D8CC0(p, flags))\n        return 1;\n', 'func_800D8CC0(p, flags))\n        return 1;\n' + b + '\n', 1))
    return name, out
