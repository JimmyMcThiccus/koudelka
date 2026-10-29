// func_800E75BC: 62 differing (500 vs 496 bytes). Loop is unrotated (for (unsigned i = 0; i < 4; i++), block-scoped locals), L.h used directly (no pointer). Open: retail reloads &D_800EA88C (lui/addiu a0) inside the loop and has frame 0x48 / saves s0-s5; ours hoists it into a callee-saved register (frame 0x50). Declaring the array [4]/int or via a pointer did not change that.
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"
EXTERN_C void func_800E75BC() {
    if (D_800EA888[0] == 0) {
        char o[8];
        Hg_L L;
        func_8005F238(o);
        func_8005F298(o, 0x1426A, 0x8800);
        int a = func_8005F28C(o);
        a += 0x10;
        for (unsigned i = 0; i < 4; i++) {
            Hg_E9650_o1* t = (Hg_E9650_o1*)operator new(0x2C);
            t->vtbl = D_80010178;
            t->unk4 = 0;
            t->vtbl = D_800106EC;
            t->unk8 = 0;
            t->unkA = 0;
            t->vtbl = D_80010654;
            func_80021ACC(t, a);
            D_800EA88C[i] = (Unk_Deletable*)t;
            a += 0x20;
            VAt<0x10>* g = (VAt<0x10>*)D_800B4C38[0];
            g->vf00(t);
        }
        Hg_E9650_o2* q = (Hg_E9650_o2*)operator new(0x20);
        void* pp = D_800EA88C[3];
        q->vtbl = D_80010178;
        q->unk4 = 0;
        q->vtbl2 = D_80010888;
        q->vtbl = D_800108A0;
        q->unkC = pp;
        L.h.a = -1;
        L.h.b = -1;
        q->unk10 = L.h;
        q->unk14 = 0;
        q->unk16 = 0;
        q->unk18 = 0;
        q->unk1E = 0;
        func_80024BF0(q, a, 0x100, 0x100);
        D_800EA888[0] = q;
        func_80025444(D_800B4C48, q, 0);
        ((VAt0*)D_800EA888[0])->vf02();
        func_8005F3E0(o);
        func_8005F248(o, 2);
    }
}
