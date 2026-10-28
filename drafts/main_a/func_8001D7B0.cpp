// func_8001D7B0: constructor of the D_800AC57C object (base ctor func_8001E40C, members at 0xF8/0x100,
// registers itself with D_800A4544). Same size; retail keeps `this` in $s1 and the base pointer in $s2
// (here $s0/$s1), 15 instructions differ. Probably wants to be a real C++ ctor (mangled name).
struct S_8001D684b {
    void **vt; int unk4; int unk8; short unkC; int unk10;
    S_8001D684b(int a, short b, int c);
};
extern "C" void func_8001E40C(void *p, int a, int b, int c, int d);
extern "C" void func_8001D150(void *self, void *b);
extern "C" void *D_80010328[], *D_80010348[], *D_80010388[], *D_80010378[], *D_800103A0[], *D_800103B8[];
extern "C" int D_800A4544[];

extern "C" void *func_8001D7B0(void *v)
{
    char *p = (char *)v;
    func_8001E40C(p, 0, 1, 0x400, 0);
    *(void ***)(p + 0xF8) = D_80010328;
    *(void ***)(p + 0x100) = D_80010348;
    *(void ***)(p + 0x8C) = D_80010388;
    *(void ***)(p + 0xF8) = D_80010378;
    *(void ***)(p + 0x100) = D_800103A0;
    *(void ***)p = D_800103B8;
    *(int *)(p + 0xFC) = 0;
    *(int *)(p + 0x104) = 0;
    *(int *)(p + 0x108) = 0;
    char *b = p ? p + 0x100 : 0;
    int *o = D_800A4544;
    func_8001D150(o, new S_8001D684b((int)b, 0x80, 0));
    return p;
}
