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

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DAE2C);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB0A0);

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB27C);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_92c79aea.cpp"

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB3B8);

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB4B4);

#include "../shared/bimf_814d219a.cpp"

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA86C);

INCLUDE_ASM("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", func_800DB720);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA890);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA8F8);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA9A0);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA9C0);

INCLUDE_RODATA("asm/bim/w0_486fb41932/nonmatchings/w0_486fb41932", D_800DA9D8);
