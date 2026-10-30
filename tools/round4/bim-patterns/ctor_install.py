import sys, re, json
sys.path.insert(0, 'scratch_c'); import gen_ctor2
ok = json.load(open('scratch_c/ctor_ok.json'))
n = 0
for key, k in sorted(ok.items()):
    mod, name = key.split('/')
    path = f'asm/bim/{mod}/nonmatchings/{mod}/{name}.s'
    _, decl, cands = gen_ctor2.gen(path)
    body = decl + '\n' + cands[k].rstrip('\n')
    f = f'src/bim/{mod}/{mod}.cpp'
    t = open(f).read()
    pat = re.compile(r'INCLUDE_ASM\("[^"]+", %s\);' % name)
    assert pat.search(t), key
    t = pat.sub(lambda _: body, t, 1)
    old = 'EXTERN_C void *%s(void *self, int in_chrg, int a, int b, int c, int d, int e);' % name
    assert old in t, key
    t = t.replace(old, 'EXTERN_C BimDtor *%s(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);' % name)
    t = t.replace('return %s(operator new(' % name, 'return %s((BimDtor *)operator new(' % name)
    if '"bim/shared.h"' not in t:
        t = t.replace('#include "common.h"\n', '#include "common.h"\n#include "bim/shared.h"\n', 1)
    open(f, 'w').write(t); n += 1
print(n, 'installed')
