import re, sys
sys.path.insert(0, 'scratch_c')
import gen_sel2, gen_cmd
def gen(path):
    t = open(path).read()
    name = re.search(r'glabel (\w+)', t).group(1)
    pre = ''
    if 'jal        func_800D7818' in t:
        a = gen_sel2.args7818(gen_sel2.lines_of(t))
        pre = f'    func_800D7818(p, {", ".join(str(x) for x in a)});\n'
    e = gen_cmd.call_args(t, 'func_800D8E64', 1)[0][0]
    b = gen_cmd.body_of('src/bim/shared/bimf_a6f0c006.cpp')
    b = b.replace('bimf_a6f0c006(', name + '(').replace('    func_800D8E64(p, 1);\n', '')
    cands = []
    for where in ('first', 'after'):
        if where == 'first':
            x = b.replace('{\n    if (!(*flags & 2))', '{\n' + pre + '    if (!(*flags & 2))', 1).replace('        return 0;\n    int a', f'        return 0;\n    func_800D8E64(p, {e});\n    int a', 1)
        else:
            x = b.replace('        return 0;\n    int a', f'        return 0;\n{pre}    func_800D8E64(p, {e});\n    int a', 1)
        cands.append(x)
        cands.append(x.replace('    if (!(func_800D7A78(p, s) & 0x10)) {\n        if (p || flags)\n            return 0;\n        else\n            return 0;\n    }', '    if (!(func_800D7A78(p, s) & 0x10))\n        return 0;'))
    return name, cands
