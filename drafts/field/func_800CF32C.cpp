// func_800CF32C: 21 differing: statement order after each new+ctor call (a1=obj copy, D_800B4C38 load, fp+=0x20, vptr load, global store).
#include "field/field.h"

EXTERN_C void* func_8005F238_r(void*) asm("func_8005F238");
struct Hg_Hw2 { short a, b; Hg_Hw2(short x, short y) { a = x; b = y; } };
struct Hg_L2 { int x; Hg_Hw2 h; int y, z; Hg_L2(short a, short b) : h(a, b) {} };
struct Hg_CF_o2 { void* vtbl; int unk4; void* vtbl2; void* unkC; Hg_Hw2 unk10; short unk14; short unk16; int unk18; short unk1C; short unk1E; };

EXTERN_C void func_800CF32C() {
    if (D_800EA11C[0] == 0) {
        void* o = 0;
        char* fp = 0;
        int flag = 1;
        while (flag) {
            o = func_8005F238_r(operator new(8));
            func_8005F298(o, 0x14339, 0x6800);
            fp = (char*)func_8005F28C(o);
            if (((unsigned short*)fp)[0] == 0x5854 && ((unsigned short*)fp)[1] == 0x3134 && ((unsigned short*)fp)[2] == 0xC30) {
                flag = 0;
            } else {
                func_8005F3E0(o);
                if (o) func_8005F248(o, 3);
                o = 0;
                Unk_800E5404_e* e = (Unk_800E5404_e*)func_8001ED2C(D_800B4C18[0], 0x1E, 1);
                if (e) {
                    if (e->unkA == 4 && e->unkC) {
                        e->unkC->vf00(3);
                    }
                    e->vf01();
                }
            }
        }
        fp += 0x10;
        {
            Hg_E9650_o1* a = (Hg_E9650_o1*)operator new(0x2C);
            a->vtbl = D_80010178;
            a->unk4 = 0;
            a->vtbl = D_800106EC;
            a->unk8 = 0;
            a->unkA = 0;
            a->vtbl = D_80010654;
            func_80021ACC(a, (int)fp);
            fp += 0x20;
            D_800EA128[0] = (Unk_Deletable*)a;
            ((VAt<0x10>*)D_800B4C38[0])->vf00(a);
        }
        {
            Hg_CF_o2* q = (Hg_CF_o2*)operator new(0x20);
            void* pp = D_800EA128[0];
            q->vtbl = D_80010178;
            q->unk4 = 0;
            q->vtbl2 = D_80010888;
            q->vtbl = D_800108A0;
            q->unkC = pp;
            Hg_L2 L(-1, -1);
            q->unk10 = L.h;
            q->unk14 = 0;
            q->unk16 = 0;
            q->unk18 = 0;
            q->unk1E = 0;
            func_80024BF0(q, (int)fp, 0x20, 0xC0);
            D_800EA11C[0] = (int)q;
            func_80025444(D_800B4C48, q, 0);
            fp += 0xC10;
            ((VAt0*)D_800EA11C[0])->vf02();
        }
        {
            Hg_E9650_o1* a = (Hg_E9650_o1*)operator new(0x20C);
            a->vtbl = D_80010178;
            a->unk4 = 0;
            a->vtbl = D_800106EC;
            a->unk8 = 0;
            a->unkA = 0;
            a->vtbl = D_80010624;
            func_80021F48(a, (int)fp);
            fp += 0x200;
            D_800EA12C[0] = (Unk_Deletable*)a;
            ((VAt<0x10>*)D_800B4C38[0])->vf00(a);
        }
        {
            Hg_CF_o2* q = (Hg_CF_o2*)operator new(0x20);
            Unk_Deletable* pp = D_800EA12C[0];
            q->vtbl = D_80010178;
            q->unk4 = 0;
            q->vtbl2 = D_80010888;
            q->vtbl = D_800108A0;
            q->unkC = pp;
            Hg_L2 L(-1, -1);
            q->unk10 = L.h;
            q->unk14 = 0;
            q->unk16 = 0;
            q->unk18 = 0;
            q->unk1E = 0;
            func_80024BF0(q, (int)fp, 0x60, 0xC0);
            D_800EA120[0] = q;
            func_80025444(D_800B4C48, q, 0);
            fp += 0x4810;
            ((VAt0*)D_800EA120[0])->vf02();
        }
        {
            Hg_E9650_o1* a = (Hg_E9650_o1*)operator new(0x2C);
            a->vtbl = D_80010178;
            a->unk4 = 0;
            a->vtbl = D_800106EC;
            a->unk8 = 0;
            a->unkA = 0;
            a->vtbl = D_80010654;
            func_80021ACC(a, (int)fp);
            fp += 0x20;
            D_800EA130[0] = (Unk_Deletable*)a;
            ((VAt<0x10>*)D_800B4C38[0])->vf00(a);
        }
        {
            Hg_CF_o2* q = (Hg_CF_o2*)operator new(0x20);
            Unk_Deletable* pp = D_800EA130[0];
            q->vtbl = D_80010178;
            q->unk4 = 0;
            q->vtbl2 = D_80010888;
            q->vtbl = D_800108A0;
            q->unkC = pp;
            Hg_L2 L(-1, -1);
            q->unk10 = L.h;
            q->unk14 = 0;
            q->unk16 = 0;
            q->unk18 = 0;
            q->unk1E = 0;
            func_80024BF0(q, (int)fp, 0x20, 0xC0);
            D_800EA124[0] = q;
            func_80025444(D_800B4C48, q, 0);
            ((VAt0*)D_800EA124[0])->vf02();
        }
        func_8005F3E0(o);
        if (o) func_8005F248(o, 3);
    }
}
