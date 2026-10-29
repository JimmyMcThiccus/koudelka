// func_800C4A18: 16 differing (best of ~30 forms). First vf07 arg block matches: x/5*23 - (x%5*28 - 0xF7) via temps t0,t1 (GCC folds the constant otherwise). Second block: registers only (retail: x in a3, q2 stays in v0; ours x in a1, q2 in t0). Class is VAt<0x2C> + pad8 + Unk_Base (vptr at 0x2C, Unk_Base at 0x38).
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"
EXTERN_C int func_80053868_b(Unk_Base*) asm("func_80053868");
struct Unk_Pad8_4A18 { char pad0[8]; };
struct Unk_800C4A18 : VAt<0x2C>, Unk_Pad8_4A18, Unk_Base { char pad3C[8]; int unk44; short unk48; short unk4A; short unk4C; };
EXTERN_C void func_800C4A18(Unk_800C4A18* p) {
    int n = func_80053874_b(p);
    int d = func_80053868_b(p);
    int q1 = p->unk4A * (n - 1) / d;
    int x = p->unk44;
    int t0 = x / 5 * 23;
    int t1 = x % 5 * 28 - 0xF7;
    int a1 = t0 - t1 - q1;
    int n2 = func_80053874_b(p);
    int d2 = func_80053868_b(p);
    int q2 = p->unk4C * (n2 - 1) / d2;
    p->vf07(a1, 0xBA - (p->unk44 / 5 * 11 + p->unk44 % 5 * 9) - q2);
    func_80053830_b(p);
}
