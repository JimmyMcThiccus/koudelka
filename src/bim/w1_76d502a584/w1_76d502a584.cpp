#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DBE5C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DBDE0(int a, short b, int c, int d, int e)
{
    return func_800DBE5C((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DBC28[], D_800DBC40[], D_800DBC50[], D_800DBCE8[], D_800DBD08[], D_800DBD20[];
EXTERN_C const BimVTable10 D_800DBBD8;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void bimf_539de782_c(void *self, int a) asm("bimf_539de782");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DBE5C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)(&self->vtAEC);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DBBD8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DBBD8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DBBD8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DBBD8.e[6].delta + adj;
    }
    self->vt8C = D_800DBD08;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DBCE8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DBC50;
    self->vt4A8 = D_800DBC40;
    self->vt980 = D_800DBC28;
    self->vt0 = D_800DBD20;
    bimf_539de782_c(self, b);
    func_800D8D64_c(self, 1, 1, 0, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 1;
    *(int *)((char *)r + 0x9D4) = 1;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_ff339051.cpp"

#include "../shared/bimf_539de782.cpp"

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

#include "../shared/bimf_85fa9335.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_cba85eee.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_4379dd60.cpp"

EXTERN_C int bimf_cba85eee_c(void *p, unsigned *flags) asm("bimf_cba85eee");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_af99c5b3_3_c(void *p, unsigned *flags) asm("bimf_af99c5b3_3");
EXTERN_C int bimf_4379dd60_c(void *p, unsigned *flags) asm("bimf_4379dd60");

EXTERN_C int func_800DC604(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_cba85eee_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 2:
        if (bimf_af99c5b3_1_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 4:
        if (bimf_af99c5b3_2_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3_3_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_4379dd60_c(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

#include "../shared/bimf_6eb48601.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_6
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a4898870.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_7
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_8
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_RODATA("asm/bim/w1_76d502a584/nonmatchings/w1_76d502a584", D_800DBBD8);

INCLUDE_RODATA("asm/bim/w1_76d502a584/nonmatchings/w1_76d502a584", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_76d502a584/nonmatchings/w1_76d502a584", D_800DBC40);

INCLUDE_RODATA("asm/bim/w1_76d502a584/nonmatchings/w1_76d502a584", D_800DBC50);

INCLUDE_RODATA("asm/bim/w1_76d502a584/nonmatchings/w1_76d502a584", D_800DBCE8);

INCLUDE_RODATA("asm/bim/w1_76d502a584/nonmatchings/w1_76d502a584", D_800DBD08);

INCLUDE_RODATA("asm/bim/w1_76d502a584/nonmatchings/w1_76d502a584", D_800DBD20);
