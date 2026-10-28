// func_800E8640: 6 differing: which callee-saved registers hold the three flags (retail a=s4, b=s3 via b=a, c=s5).
#include "field/field.h"

struct Unk_800E8640 : VAt<0x18> { Unk_DualList unk1C; char pad28[0x48]; VAt<0x18>* unk70; char pad74[8]; void* unk7C; int unk80; char pad84[0x5C]; int unkE0; int unkE4; void* unkE8_[3]; void* unkF4; void* unkF8; };
EXTERN_C int func_80053D00(void*, void*);
EXTERN_C char D_800BA530[];
EXTERN_C char D_800BA53C[];
EXTERN_C int D_800B4D8C[];
EXTERN_C void func_800E8EF4(void*);
EXTERN_C void func_800E83C4(char*);
EXTERN_C void func_80054FE0(void*);

EXTERN_C void func_800E8640(Unk_800E8640* p) {
    if (p->unkE4) {
        unsigned int i;
        func_8008EF40(9);
        func_800E8EF4(p);
        if (first(&p->unk1C)->unk4 == p->unkE0) {
            func_800E83C4((char*)p);
        }
        p->vf04();
        i = 0;
        func_80055330(0);
        for (; i < 4; i++) {
            func_8005556C(2, 1);
        }
        func_800553D8(0);
    } else {
        if (p->unkF8) {
            func_8002B27C(p->unkF4, p->unkF8);
            p->unkF8 = 0;
            func_8002B27C(D_800A4578[0], p->unkF4);
            p->unkF4 = 0;
        }
        func_80054FE0(p);
        void* o = func_800550BC(p);
        int b = 0; int c = 0; int a = 0; 
        char sa[0x20];
        char sb[0x20];
        if (o) {
            func_800538CC(sa, D_800BA530, 4);
            a = 1;
            if (func_80053D00(o, sa)) {
                c = 1;
            } else {
                func_800538CC(sb, D_800BA53C, 3);
                b = a;
                if (func_80053D00(o, sb)) {
                    c = 1;
                }
            }
        }
        if (b) {
            func_80053964(sb, 2);
        }
        if (a) {
            func_80053964(sa, 2);
        }
        if (c) {
            D_800B4D8C[0] = 1;
        }
        func_80056874(p);
        func_8005783C(0);
        if (p->unk70) {
            p->unk70->vf02();
        }
        if (p->unk7C) {
            int x = p->unk80;
            Unk_800BCA88* q = (Unk_800BCA88*)func_8001CA10(0x14);
            q->vtbl = D_80010178;
            q->unk4 = 0;
            q->vtbl = D_80010300;
            q->unk8 = 2;
            q->unkA = 7;
            q->unkC = p;
            q->vtbl = D_800102D0;
            q->unk10 = x;
            func_8001EFE4(p->unk7C, q);
        }
        if (D_800EA89C[0] == p) {
            D_800EA89C[0] = 0;
        }
    }
}
