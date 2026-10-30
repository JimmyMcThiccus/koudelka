#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB5C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAAE0(int a, short b, int c, int d, int e)
{
    return func_800DAB5C((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA920[], D_800DA938[], D_800DA948[], D_800DA9E0[], D_800DAA00[], D_800DAA18[];
EXTERN_C const BimVTable10 D_800DA8D0;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DAE68_c(void *self, int a) asm("func_800DAE68");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");
EXTERN_C void func_800D817C_c(void *self, int a) asm("func_800D817C");

EXTERN_C BimDtor *func_800DAB5C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)(&self->vtAEC);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8D0;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8D0;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8D0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA8D0.e[6].delta + adj;
    }
    self->vt8C = D_800DAA00;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9E0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA948;
    self->vt4A8 = D_800DA938;
    self->vt980 = D_800DA920;
    self->vt0 = D_800DAA18;
    func_800DAE68_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 1, 1, 0, 0, 0);
    self->f9DC = 0;
    *(int *)((char *)self + 0x9D4) = 144;
    self->f9D8 = 0;
    func_800D817C_c(self, 1);
    register BimDtor *r asm("$2") = self;
    return r;
}

EXTERN_C const BimVTable10 D_800DA8D0;
EXTERN_C char D_800DA920[], D_800DA938[], D_800DA948[], D_800DA9E0[], D_800DAA00[], D_800DAA18[];

EXTERN_C void func_800DAD24(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DAA00;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9E0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA948;
    self->vt4A8 = D_800DA938;
    self->vt980 = D_800DA920;
    self->vt0 = D_800DAA18;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8D0;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8D0;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8D0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA8D0.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

EXTERN_C void func_800DAE68(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x198DC;
    *(int *)(p + 0xA00) = 0x3000;
    *(int *)(p + 0xA04) = 0x198DC;
    *(int *)(p + 0xA08) = 0x3000;
    *(int *)(p + 0xA0C) = 0x198DC;
    *(int *)(p + 0xA10) = 0x3000;
    *(int *)(p + 0xA14) = 0x198E2;
    *(int *)(p + 0xA18) = 0x7000;
    *(int *)(p + 0xA1C) = 0x198F0;
    *(int *)(p + 0xA20) = 0x7800;
    *(int *)(p + 0xA24) = 0x198F0;
    *(int *)(p + 0xA28) = 0x7800;
    *(int *)(p + 0xA2C) = 0x198FF;
    *(int *)(p + 0xA30) = 0x3800;
    *(int *)(p + 0xA34) = 0x19906;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x19907;
    *(int *)(p + 0xA40) = 0x2800;
    *(int *)(p + 0xA44) = 0x1990C;
    *(int *)(p + 0xA48) = 0x8000;
    *(int *)(p + 0xA4C) = 0x1991C;
    *(int *)(p + 0xA50) = 0x7800;
    *(int *)(p + 0xA54) = 0x1990C;
    *(int *)(p + 0xA58) = 0x8000;
    *(int *)(p + 0xA5C) = 0x1992B;
    *(int *)(p + 0xA60) = 0x8000;
    *(int *)(p + 0xA64) = 0x19943;
    *(int *)(p + 0xA68) = 0x7800;
    *(int *)(p + 0xA6C) = 0x19943;
    *(int *)(p + 0xA70) = 0x7800;
    *(int *)(p + 0xA7C) = 0x1993B;
    *(int *)(p + 0xA80) = 0x1800;
    *(int *)(p + 0xA84) = 0x1993E;
    *(int *)(p + 0xA88) = 0x2800;
    *(int *)(p + 0xA8C) = 0x19906;
    *(int *)(p + 0xA90) = 0x800;
    *(int *)(p + 0xA94) = 0x19907;
    *(int *)(p + 0xA98) = 0x2800;
    *(int *)(p + 0xADC) = 0x19952;
    *(int *)(p + 0xAE0) = 0xA000;
    *(int *)(p + 0xAE4) = 0x19966;
    *(int *)(p + 0xAE8) = 0x1000;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

EXTERN_C int func_800DAFE8(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 0x7);
        func_80082670(p + 0x2A4, 0x11, 0x8);
        break;
    case 2:
        func_80082670(p + 0x2A4, 0x10, 0x12);
        func_80082670(p + 0x2A4, 0x11, 0x13);
        break;
    case 3:
        func_80082670(p + 0x2A4, 0x10, 0x12);
        func_80082670(p + 0x2A4, 0x11, 0x13);
        break;
    case 4:
    case 5:
        func_80082670(p + 0x2A4, 0x10, 0x10);
        func_80082670(p + 0x2A4, 0x11, 0x11);
        break;
    }
    return r;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800DB514(void *p, unsigned *flags);
EXTERN_C int bimf_6eb48601_c(void *p, unsigned *flags) asm("bimf_6eb48601");

EXTERN_C int func_800DB17C(BimV *p, unsigned *flags)
{
    func_800D7818(p, 0x12C, 0xC8, 0xC8, 0x12C, 0, 0, 0, 0);
    if (p->v22((int)flags))
        return 1;
    if (func_800DB514(p, flags))
        return 1;
    bimf_6eb48601_c(p, flags);
    return 1;
}

#include "../shared/bimf_af99c5b3.cpp"

INCLUDE_ASM("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", func_800DB220);

INCLUDE_ASM("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", func_800DB410);

#include "../shared/bimf_6eb48601.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", func_800DB514);

INCLUDE_RODATA("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", D_800DA8D0);

INCLUDE_RODATA("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", D_800DA938);

INCLUDE_RODATA("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", D_800DA948);

INCLUDE_RODATA("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", D_800DA9E0);

INCLUDE_RODATA("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", D_800DAA00);

INCLUDE_RODATA("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", D_800DAA18);
