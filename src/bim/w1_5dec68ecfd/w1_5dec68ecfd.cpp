#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DBE5C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DBDE0(int a, short b, int c, int d, int e)
{
    return func_800DBE5C(operator new(0xAF8), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", func_800DBE5C);

EXTERN_C const BimVTable10 D_800DBBD8;
EXTERN_C char D_800DBC28[], D_800DBC40[], D_800DBC50[], D_800DBCE8[], D_800DBD08[], D_800DBD20[];

EXTERN_C void func_800DC018(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DBD08;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DBCE8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DBC50;
    self->vt4A8 = D_800DBC40;
    self->vt980 = D_800DBC28;
    self->vt0 = D_800DBD20;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DBBD8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DBBD8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DBBD8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF0));
        vt.e[6].delta = D_800DBBD8.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_ASM("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", bimf_9813409c);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", bimf_6d10f24e);

INCLUDE_ASM("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", bimf_dd77db6b);

#include "../shared/bimf_5663c35c.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_f955403b.cpp"

INCLUDE_ASM("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", func_800DC6D4);

INCLUDE_ASM("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", bimf_e310b46d);

INCLUDE_ASM("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", bimf_06b4d1a5);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_b4962b94.cpp"

#include "../shared/bimf_5bce61f8.cpp"

INCLUDE_RODATA("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", D_800DBBD8);

INCLUDE_RODATA("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", D_800DBC40);

INCLUDE_RODATA("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", D_800DBC50);

INCLUDE_RODATA("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", D_800DBCE8);

INCLUDE_RODATA("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", D_800DBD08);

INCLUDE_RODATA("asm/bim/w1_5dec68ecfd/nonmatchings/w1_5dec68ecfd", D_800DBD20);
