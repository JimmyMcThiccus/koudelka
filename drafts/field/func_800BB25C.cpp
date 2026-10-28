// func_800BB25C: 17 differing: constant materialisation order (retail loads 1 into v1 first).
#include "field/field.h"

struct Unk_800BB25C : Unk_800BFE48 { char pad100[0x53C]; int unk638; int unk63C; int unk640; int unk644; char pad648[4]; int unk64C; int unk650; int unk654; int unk658; int unk65C; int unk660; int unk664; int unk668; int unk66C; int unk670; int unk674; int unk678; void* unk67C; int unk680; int unk684; int unk688; };
EXTERN_C void* func_800BF9D8(void*);
EXTERN_C void* func_800BCFD0(void*, void*);
EXTERN_C void func_800BD010(void*);
EXTERN_C void func_8006BD34(void*);

EXTERN_C Unk_800BB25C* func_800BB25C(Unk_800BB25C* p) {
    func_800BF9D8(p);
    p->unk8C = D_800B6E9C;
    p->unkF8 = D_800B6E84;
    p->vtbl = D_800B6EB4;
    D_800EA0B0[0] = (int)p;
    p->unk638 = 0;
    p->unk63C = 0;
    p->unk640 = 1;
    p->unk644 = 0;
    p->unk64C = 0;
    p->unk650 = 1;
    p->unk654 = 1;
    p->unk658 = -1;
    p->unk65C = 0;
    p->unk660 = -1;
    p->unk664 = -1;
    p->unk668 = 1;
    p->unk66C = 0;
    p->unk670 = 0;
    p->unk674 = 0;
    p->unk678 = 0;
    p->unk680 = 2;
    p->unk684 = 0;
    p->unk688 = 0;
    p->unk67C = 0;
    p->unk67C = func_800BCFD0(operator new(8), p);
    func_800BD010(p->unk67C);
    func_8006BD34(D_800B4ED8[0]);
    return p;
}
