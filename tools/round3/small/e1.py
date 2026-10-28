import subprocess, sys
pre = '#include "effect/effect.h"\n'
V = {
'e': '''EXTERN_C Vec4 func_800E2490(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x50);
    VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
    void *adj = (char *)p + vt[4].delta;
    Vec4 (*fn)(void *) = (Vec4 (*)(void *))vt[4].pfn;
    return fn(adj);
}''',
'f': '''EXTERN_C Vec4 func_800E2490(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x50);
    VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
    VtEntry *e = &vt[4];
    return ((Vec4 (*)(void *))e->pfn)((char *)p + e->delta);
}''',
'g': '''EXTERN_C Vec4 func_800E2490(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x50);
    VtEntry *e = &p->vptr[4];
    void *adj = (char *)p + e->delta;
    return ((Vec4 (*)(void *))e->pfn)(adj);
}''',
'h': '''EXTERN_C Vec4 func_800E2490(void *self)
{
    char *p = FIELD_AT(self, char *, 0x50);
    VtEntry *vt = *(VtEntry **)(p + 8);
    return ((Vec4 (*)(void *))vt[4].pfn)(p + vt[4].delta);
}''',
}
for k, v in V.items():
    open('scratch_c/e1.cpp', 'w').write(pre + v + '\n')
    r = subprocess.run([sys.executable, 'tools/try_compile.py', 'scratch_c/e1.cpp', 'func_800E2490', '--unit', 'src/effect/effect_b.cpp'], capture_output=True, text=True)
    print(k, (r.stdout.strip().splitlines() or ['err'])[-1])
