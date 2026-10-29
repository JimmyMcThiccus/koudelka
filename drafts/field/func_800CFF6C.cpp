// func_800CFF6C: 80 differing (736 vs 732 bytes). Same loader pattern as func_800D4674 (see its draft): 4 objects with a += 0x200 after each vf00 call. Open: store of the global (D_800EA13C etc.) vs vptr load ordering, and retail keeps g in a2 (we use v1).
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"
EXTERN_C void func_800CFF6C() {
    if (D_800EA134[0] == 0) {
        char o[8];
        Hg_L L;
        Hg_Hw* hp = &L.h;
        func_8005F238(o);
        func_8005F298(o, 0x14370, 0x9000);
        int a = func_8005F28C(o);
        a += 0x10;
        Hg_E9650_o1* t0 = (Hg_E9650_o1*)operator new(0x20C);
        t0->vtbl = D_80010178;
        t0->unk4 = 0;
        t0->vtbl = D_800106EC;
        t0->unk8 = 0;
        t0->unkA = 0;
        t0->vtbl = D_80010624;
        func_80021F48(t0, a);
        D_800EA13C[0] = (Unk_Deletable*)t0;
        VAt<0x10>* gt0 = (VAt<0x10>*)D_800B4C38[0];
        gt0->vf00(t0);
        a += 0x200;
        Hg_E9650_o1* t1 = (Hg_E9650_o1*)operator new(0x20C);
        t1->vtbl = D_80010178;
        t1->unk4 = 0;
        t1->vtbl = D_800106EC;
        t1->unk8 = 0;
        t1->unkA = 0;
        t1->vtbl = D_80010624;
        func_80021F48(t1, a);
        D_800EA140[0] = (Unk_Deletable*)t1;
        VAt<0x10>* gt1 = (VAt<0x10>*)D_800B4C38[0];
        gt1->vf00(t1);
        a += 0x200;
        Hg_E9650_o1* t2 = (Hg_E9650_o1*)operator new(0x20C);
        t2->vtbl = D_80010178;
        t2->unk4 = 0;
        t2->vtbl = D_800106EC;
        t2->unk8 = 0;
        t2->unkA = 0;
        t2->vtbl = D_80010624;
        func_80021F48(t2, a);
        D_800EA144[0] = (Unk_Deletable*)t2;
        VAt<0x10>* gt2 = (VAt<0x10>*)D_800B4C38[0];
        gt2->vf00(t2);
        a += 0x200;
        Hg_E9650_o1* t3 = (Hg_E9650_o1*)operator new(0x20C);
        t3->vtbl = D_80010178;
        t3->unk4 = 0;
        t3->vtbl = D_800106EC;
        t3->unk8 = 0;
        t3->unkA = 0;
        t3->vtbl = D_80010624;
        func_80021F48(t3, a);
        D_800EA138[0] = (Unk_Deletable*)t3;
        VAt<0x10>* gt3 = (VAt<0x10>*)D_800B4C38[0];
        gt3->vf00(t3);
        a += 0x200;
        Hg_E9650_o2* q = (Hg_E9650_o2*)operator new(0x20);
        void* pp = D_800EA13C[0];
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
        D_800EA134[0] = (Unk_Deletable*)q;
        func_80025444(D_800B4C48, q, 0);
        ((VAt0*)D_800EA134[0])->vf02();
        func_8005F3E0(o);
        func_8005F248(o, 2);
    }
}
