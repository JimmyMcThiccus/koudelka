import re, gen_sel2
B = [
'''    if (func_800D84C8(p)) {
        if (func_800D8350(p, 2) && (*flags & 2)) {
            func_800D8E64(p, 3);
            void *q = func_800D7A4C(p, 1, 0x421);
            if (q && func_800D7D64(p, q)) {
                *flags &= ~2;
                p->f9F0 = 0x10;
                return 1;
            }
        }
    }''',
'''    if (func_800D84C8(p)) {
        if (func_800D8350(p, 2) && (*flags & 2)) {
            func_800D8E64(p, 3);
            void *q = func_800D7A4C(p, 1, 0x421);
            if (q && func_800D7D64(p, q)) {
                int r = 1;
                *flags &= ~2;
                p->f9F0 = 0x10;
                return r;
            }
        }
    }''',
'''    if (func_800D84C8(p)) {
        if (func_800D8350(p, 2)) {
            if (*flags & 2) {
                func_800D8E64(p, 3);
                void *q = func_800D7A4C(p, 1, 0x421);
                if (q && func_800D7D64(p, q)) {
                    *flags &= ~2;
                    p->f9F0 = 0x10;
                    return 1;
                }
            }
        }
    }''',
]
def gen(path):
    t = open(path).read()
    t2 = t
    # make gen_sel2 see a plain chain: drop the inline calls from its view
    name = re.search(r'glabel (\w+)', t).group(1)
    import tempfile, os
    fake = re.sub(r'jal\s+func_800D84C8.*?(?=jal\s+bimf_f35df0eb)', '', t, flags=re.S)
    p2 = 'scratch_c/try/_fake.s'; open(p2, 'w').write(fake)
    _, cands = gen_sel2.gen(p2)
    out = []
    for b in B:
        for c in cands:
            c = c.replace('    if (bimf_f35df0eb_c', b + '\n    if (bimf_f35df0eb_c', 1)
            out.append(c)
    return name, out
