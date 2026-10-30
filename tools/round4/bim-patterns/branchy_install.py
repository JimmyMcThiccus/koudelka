import re, glob, os
n = 0
MODS = ('w0_7c6f4c78ec', 'w1_04f19c3154', 'w2_03a917c186', 'w0_e43bb5c67a', 'w1_5bab5b7862', 'w2_2d4fae84c5')
for out in glob.glob('scratch_c/ctor/*.cpp'):
    m = re.match(r'(w\d_[0-9a-f]+)_(func_[0-9A-F]+)\.cpp', os.path.basename(out))
    mod, name = m.groups()
    if mod not in MODS: continue
    body = open(out).read().split('#include "bim/shared.h"', 1)[1].strip()
    f = f'src/bim/{mod}/{mod}.cpp'; t = open(f).read()
    pat = re.compile(r'INCLUDE_ASM\("[^"]+", %s\);' % name)
    assert pat.search(t)
    t = pat.sub(lambda _: body, t, 1)
    old = 'EXTERN_C void *%s(void *self, int in_chrg, int a, int b, int c, int d, int e);' % name
    assert old in t
    t = t.replace(old, 'EXTERN_C BimDtor *%s(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);' % name)
    t = t.replace('return %s(operator new(' % name, 'return %s((BimDtor *)operator new(' % name)
    open(f, 'w').write(t); n += 1
print(n)
