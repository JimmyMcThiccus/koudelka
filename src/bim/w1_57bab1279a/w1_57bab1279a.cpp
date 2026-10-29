#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DBE3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DBDC0(int a, short b, int c, int d, int e)
{
    return func_800DBE3C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", func_800DBE3C);

EXTERN_C const BimVTable10 D_800DBBB0;
EXTERN_C char D_800DBC00[], D_800DBC18[], D_800DBC28[], D_800DBCC0[], D_800DBCE0[], D_800DBCF8[];

EXTERN_C void func_800DC004(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DBCE0;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DBCC0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DBC28;
    self->vt4A8 = D_800DBC18;
    self->vt980 = D_800DBC00;
    self->vt0 = D_800DBCF8;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DBBB0;
    if (!in_chrg) {
        BimVTable10 vt = D_800DBBB0;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DBBB0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DBBB0.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_ASM("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", bimf_41634af0);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", func_800DC3BC);

INCLUDE_ASM("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", func_800DC594);

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_92c79aea.cpp"

INCLUDE_ASM("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", func_800DC704);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", func_800DC824);

#include "../shared/bimf_814d219a.cpp"

INCLUDE_RODATA("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", D_800DBB8C);

INCLUDE_ASM("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", func_800DCA98);

INCLUDE_RODATA("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", D_800DBBB0);

INCLUDE_RODATA("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", D_800DBC00);

INCLUDE_RODATA("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", D_800DBC18);

INCLUDE_RODATA("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", D_800DBCC0);

INCLUDE_RODATA("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", D_800DBCE0);

INCLUDE_RODATA("asm/bim/w1_57bab1279a/nonmatchings/w1_57bab1279a", D_800DBCF8);
