import sys, subprocess, re
sys.path.insert(0, 'scratch_c'); import gen_ctor2
A = ['''    self->f9DC = 3;
    *(int *)((char *)self + 0x9D4) = 0xE;
    if (func_800D8350_c(self, 2)) self->f9D8 = 1; else self->f9D8 = 0;
    func_800D817C_c(self, 1);
    return self;''',
'''    self->f9DC = 3;
    *(int *)((char *)self + 0x9D4) = 0xE;
    if (func_800D8350_c(self, 2)) self->f9D8 = 1; else self->f9D8 = 0;
    func_800D817C_c(self, 1);
    register BimDtor *r asm("$2") = self;
    return r;''',
'''    *(int *)((char *)self + 0x9D4) = 0xE;
    self->f9DC = 3;
    if (func_800D8350_c(self, 2)) self->f9D8 = 1; else self->f9D8 = 0;
    func_800D817C_c(self, 1);
    return self;''',
'''    self->f9DC = 3;
    *(int *)((char *)self + 0x9D4) = 0xE;
    self->f9D8 = func_800D8350_c(self, 2) ? 1 : 0;
    func_800D817C_c(self, 1);
    return self;''']
AX = ['EXTERN_C int func_800D8350_c(void *self, int a) asm("func_800D8350");',
      'EXTERN_C void func_800D817C_c(void *self, int a) asm("func_800D817C");']
B = ['''    self->f9DC = 0;
    *(int *)((char *)self + 0x9E8) = 1;
    *(int *)((char *)self + 0x9D4) = 8;
    if (func_800D8350_c(self, 2)) self->f9D8 = 1; else self->f9D8 = 0;
    if (func_800D8350_c(self, 2)) func_800D83E0_c(self);
    return self;''',
'''    self->f9DC = 0;
    *(int *)((char *)self + 0x9E8) = 1;
    *(int *)((char *)self + 0x9D4) = 8;
    if (func_800D8350_c(self, 2)) self->f9D8 = 1; else self->f9D8 = 0;
    if (func_800D8350_c(self, 2)) func_800D83E0_c(self);
    register BimDtor *r asm("$2") = self;
    return r;''',
'''    *(int *)((char *)self + 0x9D4) = 8;
    self->f9DC = 0;
    *(int *)((char *)self + 0x9E8) = 1;
    if (func_800D8350_c(self, 2)) self->f9D8 = 1; else self->f9D8 = 0;
    if (func_800D8350_c(self, 2)) func_800D83E0_c(self);
    return self;''']
BX = ['EXTERN_C int func_800D8350_c(void *self, int a) asm("func_800D8350");',
      'EXTERN_C void func_800D83E0_c(void *self) asm("func_800D83E0");']
for path in open('scratch_c/ctors.txt').read().split():
    mod = path.split('/')[2]
    if mod in ('w0_7c6f4c78ec', 'w1_04f19c3154', 'w2_03a917c186'): T, X = A, AX
    elif mod in ('w0_e43bb5c67a', 'w1_5bab5b7862', 'w2_2d4fae84c5'): T, X = B, BX
    else: continue
    name, decl, cands = gen_ctor2.gen(path, T, X)
    for k, c in enumerate(cands):
        out = f'scratch_c/ctor/{mod}_{name}.cpp'
        open(out, 'w').write('#include "common.h"\n#include "bim/shared.h"\n' + decl + '\n' + c)
        r = subprocess.run([sys.executable, 'tools/try_compile.py', out, name, '--unit', f'src/bim/{mod}/{mod}.cpp'], capture_output=True, text=True)
        last = (r.stdout + r.stderr).strip().splitlines()[-1]
        print(mod, k, last)
        if ' 0 differing' in last: break
