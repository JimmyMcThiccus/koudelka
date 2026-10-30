#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB34(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAAB8(int a, short b, int c, int d, int e)
{
    return func_800DAB34((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA908[], D_800DA920[], D_800DA930[], D_800DA9C8[], D_800DA9E8[], D_800DAA00[];
EXTERN_C const BimVTable10 D_800DA8B8;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void bimf_62bd47cb_c(void *self, int a) asm("bimf_62bd47cb");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");
EXTERN_C void func_800D817C_c(void *self, int a) asm("func_800D817C");

EXTERN_C BimDtor *func_800DAB34(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)(&self->vtAEC);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8B8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8B8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8B8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA8B8.e[6].delta + adj;
    }
    self->vt8C = D_800DA9E8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9C8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA930;
    self->vt4A8 = D_800DA920;
    self->vt980 = D_800DA908;
    self->vt0 = D_800DAA00;
    bimf_62bd47cb_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 0, 0, 0, 0, 0);
    self->f9DC = 0;
    *(int *)((char *)self + 0x9D4) = 157;
    self->f9D8 = 0;
    func_800D817C_c(self, 1);
    register BimDtor *r asm("$2") = self;
    *(int *)((char *)r + 0xAE8) = 0;
    return r;
}

#include "../shared/bimf_a85220b1.cpp"

#include "../shared/bimf_62bd47cb.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

#include "../shared/bimf_b1674f83.cpp"

#include "../shared/bimf_3655787d.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_1393ddd0.cpp"

EXTERN_C int bimf_3655787d_c(void *p, unsigned *flags) asm("bimf_3655787d");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_1393ddd0_c(void *p, unsigned *flags) asm("bimf_1393ddd0");

EXTERN_C int func_800DB270(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (!bimf_3655787d_c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 2:
    case 4:
        p->f9F0 = 0;
        return 0;
    case 8:
        if (!bimf_af99c5b3_c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~1;
        return 1;
    case 16:
        if (!bimf_1393ddd0_c(p, flags))
            return 0;
        p->f9F0 = 0;
        return 1;
    }
    return 0;
}


#include "../shared/bimf_6eb48601.cpp"

INCLUDE_ASM("asm/bim/w0_7ed42bdb0b/nonmatchings/w0_7ed42bdb0b", bimf_51caf7a0);

#include "../shared/bimf_ad7de1b4.cpp"

INCLUDE_RODATA("asm/bim/w0_7ed42bdb0b/nonmatchings/w0_7ed42bdb0b", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_7ed42bdb0b/nonmatchings/w0_7ed42bdb0b", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_7ed42bdb0b/nonmatchings/w0_7ed42bdb0b", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_7ed42bdb0b/nonmatchings/w0_7ed42bdb0b", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_7ed42bdb0b/nonmatchings/w0_7ed42bdb0b", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_7ed42bdb0b/nonmatchings/w0_7ed42bdb0b", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_7ed42bdb0b/nonmatchings/w0_7ed42bdb0b", D_800DAA00);
