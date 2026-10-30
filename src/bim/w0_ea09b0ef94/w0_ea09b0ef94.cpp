#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB14(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAA98(int a, short b, int c, int d, int e)
{
    return func_800DAB14((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA8E8[], D_800DA900[], D_800DA910[], D_800DA9A8[], D_800DA9C8[], D_800DA9E0[];
EXTERN_C const BimVTable10 D_800DA898;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DAE24_c(void *self, int a) asm("func_800DAE24");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");
EXTERN_C void func_800D817C_c(void *self, int a) asm("func_800D817C");

EXTERN_C BimDtor *func_800DAB14(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)(&self->vtAEC);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA898;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA898;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA898.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA898.e[6].delta + adj;
    }
    self->vt8C = D_800DA9C8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9A8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA910;
    self->vt4A8 = D_800DA900;
    self->vt980 = D_800DA8E8;
    self->vt0 = D_800DA9E0;
    func_800DAE24_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 0, 0, 0, 0, 0);
    self->f9DC = 0;
    self->f9D8 = 0;
    *(int *)((char *)self + 0x9D4) = 158;
    func_800D817C_c(self, 1);
    register BimDtor *r asm("$2") = self;
    *(int *)((char *)r + 0xAE8) = 1;
    return r;
}

EXTERN_C const BimVTable10 D_800DA898;
EXTERN_C char D_800DA8E8[], D_800DA900[], D_800DA910[], D_800DA9A8[], D_800DA9C8[], D_800DA9E0[];

EXTERN_C void func_800DACE0(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DA9C8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9A8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA910;
    self->vt4A8 = D_800DA900;
    self->vt980 = D_800DA8E8;
    self->vt0 = D_800DA9E0;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA898;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA898;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA898.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA898.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

EXTERN_C void func_800DAE24(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x19FCC;
    *(int *)(p + 0x9FC) = 0x1800;
    *(int *)(p + 0xA00) = 0x1A01D;
    *(int *)(p + 0xA04) = 0x4000;
    *(int *)(p + 0xA08) = 0x1A025;
    *(int *)(p + 0xA0C) = 0x5800;
    *(int *)(p + 0xA10) = 0x19FCF;
    *(int *)(p + 0xA14) = 0x5800;
    *(int *)(p + 0xA18) = 0x19FDA;
    *(int *)(p + 0xA1C) = 0x7800;
    *(int *)(p + 0xA20) = 0x19FDA;
    *(int *)(p + 0xA24) = 0x7800;
    *(int *)(p + 0xA28) = 0x19FE9;
    *(int *)(p + 0xA2C) = 0x6000;
    *(int *)(p + 0xA30) = 0x19FF5;
    *(int *)(p + 0xA34) = 0x800;
    *(int *)(p + 0xA38) = 0x19FF6;
    *(int *)(p + 0xA3C) = 0x800;
    *(int *)(p + 0xA40) = 0x19FF7;
    *(int *)(p + 0xA44) = 0x4800;
    *(int *)(p + 0xA48) = 0x1A000;
    *(int *)(p + 0xA4C) = 0x7000;
    *(int *)(p + 0xA50) = 0x1A00E;
    *(int *)(p + 0xA54) = 0x7800;
    *(int *)(p + 0xA58) = 0x19FF7;
    *(int *)(p + 0xA5C) = 0x4800;
    *(int *)(p + 0xA60) = 0x1A01D;
    *(int *)(p + 0xA64) = 0x4000;
    *(int *)(p + 0xA68) = 0x1A025;
    *(int *)(p + 0xA6C) = 0x5800;
    *(int *)(p + 0xAD8) = 0x1A030;
    *(int *)(p + 0xADC) = 0x7800;
    *(int *)(p + 0xAE0) = 0x1A03F;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", func_800DB01C);

INCLUDE_ASM("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", func_800DB208);

INCLUDE_ASM("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", func_800DB348);

EXTERN_C int func_800DB458(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0x190, 0x258, 0, 0, 0, 0, 0, 0);
        int id = func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            if (id == 2)
                func_800D81FC(p, 3);
            if (func_800D7D64(p, q)) {
                *flags &= ~2;
                return 1;
            }
        }
    }
    return 0;
}

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_1393ddd0.cpp"

EXTERN_C int func_800DB458(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_1393ddd0(void *p, unsigned *flags);

EXTERN_C int func_800DB5F0(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (func_800DB458(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_1393ddd0(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

#include "../shared/bimf_05e090a7.cpp"

INCLUDE_ASM("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", func_800DB718);

INCLUDE_ASM("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", func_800DBA44);

INCLUDE_RODATA("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", D_800DA898);

INCLUDE_RODATA("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", D_800DA8E8);

INCLUDE_RODATA("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", D_800DA900);

INCLUDE_RODATA("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", D_800DA910);

INCLUDE_RODATA("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_ea09b0ef94/nonmatchings/w0_ea09b0ef94", D_800DA9E0);
