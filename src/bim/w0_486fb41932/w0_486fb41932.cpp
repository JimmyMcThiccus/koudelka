#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB14(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA98(int a, short b, int c, int d, int e)
{
    return func_800DAB14(operator new(0xAF0), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DAB14);

EXTERN_C const BimVTable10 D_800DA890;
EXTERN_C char D_800DA8E0[], D_800DA8F8[], D_800DA908[], D_800DA9A0[], D_800DA9C0[], D_800DA9D8[];

EXTERN_C void func_800DACE8(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DA9C0;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9A0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA908;
    self->vt4A8 = D_800DA8F8;
    self->vt980 = D_800DA8E0;
    self->vt0 = D_800DA9D8;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA890;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA890;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA890.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAE8));
        vt.e[6].delta = D_800DA890.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

EXTERN_C void func_800DAE2C(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x19D15;
    *(int *)(p + 0x9FC) = 0x2000;
    *(int *)(p + 0xA00) = 0x19D15;
    *(int *)(p + 0xA04) = 0x2000;
    *(int *)(p + 0xA08) = 0x19D15;
    *(int *)(p + 0xA0C) = 0x2000;
    *(int *)(p + 0xA10) = 0x19D19;
    *(int *)(p + 0xA14) = 0x6000;
    *(int *)(p + 0xA18) = 0x19D25;
    *(int *)(p + 0xA1C) = 0x6000;
    *(int *)(p + 0xA20) = 0x19D31;
    *(int *)(p + 0xA24) = 0x6000;
    *(int *)(p + 0xA28) = 0x19D3D;
    *(int *)(p + 0xA2C) = 0x7000;
    *(int *)(p + 0xA30) = 0x19D4B;
    *(int *)(p + 0xA34) = 0x800;
    *(int *)(p + 0xA38) = 0x19D4C;
    *(int *)(p + 0xA3C) = 0x1800;
    *(int *)(p + 0xA40) = 0x19D4F;
    *(int *)(p + 0xA44) = 0x4800;
    *(int *)(p + 0xA48) = 0x19D73;
    *(int *)(p + 0xA4C) = 0x5800;
    *(int *)(p + 0xA50) = 0x19D4F;
    *(int *)(p + 0xA54) = 0x4800;
    *(int *)(p + 0xA58) = 0x19D58;
    *(int *)(p + 0xA5C) = 0x1800;
    *(int *)(p + 0xA60) = 0x19D81;
    *(int *)(p + 0xA64) = 0x5800;
    *(int *)(p + 0xA68) = 0x19D5B;
    *(int *)(p + 0xA6C) = 0x5000;
    *(int *)(p + 0xA70) = 0x19D65;
    *(int *)(p + 0xA74) = 0x5800;
    *(int *)(p + 0xA78) = 0x19D70;
    *(int *)(p + 0xA7C) = 0x800;
    *(int *)(p + 0xA80) = 0x19D71;
    *(int *)(p + 0xA84) = 0x1000;
    *(int *)(p + 0xA88) = 0x19D7E;
    *(int *)(p + 0xA8C) = 0x800;
    *(int *)(p + 0xA90) = 0x19D7F;
    *(int *)(p + 0xA94) = 0x1000;
    *(int *)(p + 0xAD8) = 0x19D8C;
    *(int *)(p + 0xADC) = 0x6000;
    *(int *)(p + 0xAE0) = 0x19D98;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB0A0);

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB27C);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_92c79aea.cpp"

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB3B8);

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB4B4);

#include "../shared/bimf_814d219a.cpp"

EXTERN_C int func_800DB720(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 0x10);
        func_80082670(p + 0x2A4, 0x11, 0x11);
        break;
    case 4:
        func_80082670(p + 0x2A4, 0x10, 0x12);
        func_80082670(p + 0x2A4, 0x11, 0x13);
        break;
    case 2:
    case 3:
    case 5:
    case 6:
        func_80082670(p + 0x2A4, 0x10, 0x7);
        func_80082670(p + 0x2A4, 0x11, 0x8);
        break;
    }
    return r;
}

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA890);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA8F8);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA9A0);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA9C0);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA9D8);
