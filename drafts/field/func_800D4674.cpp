// func_800D4674: 4 differing instructions, scheduling order only: retail has addiu s1,0x200 / lw v0,0x10(v1) / lui s7;sw a1 (E4 store) in that order, ours has the store first. Found: int a = F28C(o); a += 0x10; (T3 form) keeps retail s1 chaining; separate variable q2 for the third object; Hg_Hw* hp = &L.h gives the fp=&L. Tried: add position x store form x arg form (20 variants).
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"
EXTERN_C void func_800D4674() {
    if (D_800EA2DC[0] == 0) {
        char o[8];
        Hg_L L;
        Hg_Hw* hp = &L.h;
        func_8005F238(o);
        func_8005F298(o, 0x14326, 0x9800);
        int a = func_8005F28C(o);
        a += 0x10;
        Hg_E9650_o1* t = (Hg_E9650_o1*)operator new(0x20C);
        t->vtbl = D_80010178;
        t->unk4 = 0;
        t->vtbl = D_800106EC;
        t->unk8 = 0;
        t->unkA = 0;
        t->vtbl = D_80010624;
        func_80021F48(t, a);
        D_800EA2E4[0] = (Unk_Deletable*)t;
        VAt<0x10>* g = (VAt<0x10>*)D_800B4C38[0];
        g->vf00(t);
        a += 0x200;
        Hg_E9650_o2* q = (Hg_E9650_o2*)operator new(0x20);
        void* pp = D_800EA2E4[0];
        q->vtbl = D_80010178;
        q->unk4 = 0;
        q->vtbl2 = D_80010888;
        q->vtbl = D_800108A0;
        q->unkC = pp;
        hp->a = -1;
        hp->b = -1;
        q->unk10 = *hp;
        q->unk14 = 0;
        q->unk16 = 0;
        q->unk18 = 0;
        q->unk1E = 0;
        func_80024BF0(q, a, 0x80, 0x100);
        D_800EA2DC[0] = q;
        func_80025444(D_800B4C48, q, 0);
        ((VAt0*)D_800EA2DC[0])->vf02();
        a += 0x8000;
        Hg_E9650_o2* q2 = (Hg_E9650_o2*)operator new(0x20);
        pp = D_800EA2E4[0];
        q2->vtbl = D_80010178;
        q2->unk4 = 0;
        q2->vtbl2 = D_80010888;
        q2->vtbl = D_800108A0;
        q2->unkC = pp;
        hp->a = -1;
        hp->b = -1;
        q2->unk10 = *hp;
        q2->unk14 = 0;
        q2->unk16 = 0;
        q2->unk18 = 0;
        q2->unk1E = 0;
        func_80024BF0(q2, a, 0x40, 0x40);
        D_800EA2E0[0] = (int)q2;
        func_80025444(D_800B4C48, q2, 0);
        ((VAt0*)D_800EA2E0[0])->vf02();
        func_8005F3E0(o);
        func_8005F248(o, 2);
    }
}
