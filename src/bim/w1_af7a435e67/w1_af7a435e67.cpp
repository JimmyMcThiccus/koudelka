#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DBE34(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DBDB8(int a, short b, int c, int d, int e)
{
    return func_800DBE34((BimDtor *)operator new(0xAF8), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DBC00[], D_800DBC18[], D_800DBC28[], D_800DBCC0[], D_800DBCE0[], D_800DBCF8[];
EXTERN_C const BimVTable10 D_800DBBB0;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void bimf_2f8bc8bf_c(void *self, int a) asm("bimf_2f8bc8bf");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");
EXTERN_C void func_800D817C_c(void *self, int a) asm("func_800D817C");

EXTERN_C BimDtor *func_800DBE34(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)((char *)self + 0xAF0);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DBBB0;
    if (!in_chrg) {
        BimVTable10 vt = D_800DBBB0;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DBBB0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF0));
        vt.e[6].delta = D_800DBBB0.e[6].delta + adj;
    }
    self->vt8C = D_800DBCE0;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DBCC0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DBC28;
    self->vt4A8 = D_800DBC18;
    self->vt980 = D_800DBC00;
    self->vt0 = D_800DBCF8;
    bimf_2f8bc8bf_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 0, 0, 0, 0, 0);
    self->f9DC = 0;
    *(int *)((char *)self + 0x9D4) = 28;
    self->f9D8 = 0;
    func_800D817C_c(self, 1);
    register BimDtor *r asm("$2") = self;
    *(int *)((char *)r + 0xAE8) = 4;
    *(int *)((char *)r + 0xAEC) = 0;
    return r;
}

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
        vt.e[1].delta = D_800DBBB0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF0));
        vt.e[6].delta = D_800DBBB0.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

#include "../shared/bimf_2f8bc8bf.cpp"

#include "../shared/bimf_d3d03f70.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_15ce46f8.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", func_800DC4C4);

#include "../shared/bimf_096f4279.cpp"

#include "../shared/bimf_e32ca3a9.cpp"

#include "../shared/bimf_fddfe66d.cpp"

#include "../shared/bimf_6eb48601.cpp"

INCLUDE_ASM("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", bimf_d408bc6f);

INCLUDE_ASM("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", func_800DCB74);

INCLUDE_RODATA("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", D_800DBBB0);

INCLUDE_RODATA("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", D_800DBC00);

INCLUDE_RODATA("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", D_800DBC18);

INCLUDE_RODATA("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", D_800DBCC0);

INCLUDE_RODATA("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", D_800DBCE0);

INCLUDE_RODATA("asm/bim/w1_af7a435e67/nonmatchings/w1_af7a435e67", D_800DBCF8);
