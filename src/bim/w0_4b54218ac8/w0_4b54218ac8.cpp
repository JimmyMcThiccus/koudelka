#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB5C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAE0(int a, short b, int c, int d, int e)
{
    return func_800DAB5C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", func_800DAB5C);

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

INCLUDE_ASM("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", func_800DAE68);

INCLUDE_ASM("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", func_800DAFE8);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_4b54218ac8/nonmatchings/w0_4b54218ac8", func_800DB17C);

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
