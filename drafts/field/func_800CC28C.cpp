// func_800CC28C: Retail copies `this` into v0 before the last store (real-constructor behaviour); as a plain function v0 is set at the end. A real ctor needs the EXE base ctor func_8005F0E4 to have a mangled name, and existing C callers use func_800CC28C.
#include "field/field.h"

struct Unk_800CC28C { void* vtbl; char pad4[0xC]; POLY_FT4 unk10[2]; unsigned char unk60; unsigned char unk61; };
EXTERN_C char D_800B82CC[];
EXTERN_C char D_800B4C88[];
EXTERN_C void func_8005F0E4(void*, int);
EXTERN_C void func_8005F148(void*, int);
EXTERN_C void func_800CC754(void*, int);
EXTERN_C void func_800CC85C(void*, int);
EXTERN_C void func_800CC9E4(Unk_Ft4_10*, Unk_ColorSrc*);
EXTERN_C void* func_800CC28C(Unk_800CC28C* p, void* a, int b, void* c, int d) {
    func_8005F0E4(p, d);
    p->vtbl = D_800B82CC;
    p->unk60 = 0;
    p->unk61 = 0;
    ((unsigned char*)&p->unk10[0].tag)[3] = 9;
    p->unk10[0].code = 0x2C;
    ((unsigned char*)&p->unk10[1].tag)[3] = 9;
    p->unk10[1].code = 0x2C;
    func_8005F148(p, (int)a);
    func_800CC9E4((Unk_Ft4_10*)p, (Unk_ColorSrc*)D_800B4C88);
    func_800CC754(p, b);
    func_800CC85C(p, (int)c);
    {
        int bf = D_800B4CF0[0];
        POLY_FT4* dst = &p->unk10[bf ^ 1];
        POLY_FT4* src = &p->unk10[bf];
        int* dd = (int*)dst;
        int* s = (int*)src;
        unsigned int i;
        for (i = 0; i < 8; i += 4) {
            int w0, w1, w2, w3;
            w0 = s[i + 1]; w1 = s[i + 2]; w2 = s[i + 3]; w3 = s[i + 4];
            dd[i + 1] = w0; dd[i + 2] = w1; dd[i + 3] = w2; dd[i + 4] = w3;
        }
        ((int*)dst)[9] = ((int*)src)[9];
    }
    return p;
}
