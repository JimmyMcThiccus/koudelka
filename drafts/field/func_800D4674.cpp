// func_800D4674: ~90 differing. Structure matches the landed loaders (Hg_E9650_o1/o2, Hg_L via Hg_Hw* hp=&L.h gives the fp=&L like retail). Open: retail does s1=F(o)+0x10 once then s1+=0x200, s1+=0x8000 in place; GCC folds to F(o)+0x210 (raw result kept in s1). Also retail does NOT CSE the lui of D_800EA2DC (t0,t1,t2 separately) because all callee-saved regs are taken.
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
        int a = func_8005F28C(o) + 0x10;
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
        a += 0x200;
        func_80024BF0(q, a, 0x80, 0x100);
        D_800EA2DC[0] = q;
        func_80025444(D_800B4C48, q, 0);
        ((VAt0*)D_800EA2DC[0])->vf02();
        q = (Hg_E9650_o2*)operator new(0x20);
        pp = D_800EA2E4[0];
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
        a += 0x8000;
        func_80024BF0(q, a, 0x40, 0x40);
        D_800EA2E0[0] = (int)q;
        func_80025444(D_800B4C48, q, 0);
        ((VAt0*)D_800EA2E0[0])->vf02();
        func_8005F3E0(o);
        func_8005F248(o, 2);
    }
}
