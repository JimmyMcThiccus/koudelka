#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DD154(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DD0D8(int a, short b, int c, int d, int e)
{
    return func_800DD154(operator new(0xAF8), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", func_800DD154);

EXTERN_C const BimVTable10 D_800DCED0;
EXTERN_C char D_800DCF20[], D_800DCF38[], D_800DCF48[], D_800DCFE0[], D_800DD000[], D_800DD018[];

EXTERN_C void func_800DD324(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DD000;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DCFE0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DCF48;
    self->vt4A8 = D_800DCF38;
    self->vt980 = D_800DCF20;
    self->vt0 = D_800DD018;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DCED0;
    if (!in_chrg) {
        BimVTable10 vt = D_800DCED0;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DCED0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF0));
        vt.e[6].delta = D_800DCED0.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_ASM("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", bimf_2f8bc8bf);

#include "../shared/bimf_d3d03f70.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_15ce46f8.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", func_800DD7E4);

INCLUDE_ASM("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", bimf_096f4279);

#include "../shared/bimf_e32ca3a9.cpp"

INCLUDE_ASM("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", bimf_fddfe66d);

#include "../shared/bimf_6eb48601.cpp"

INCLUDE_ASM("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", bimf_d408bc6f);

INCLUDE_ASM("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", func_800DDE94);

INCLUDE_RODATA("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", D_800DCED0);

INCLUDE_RODATA("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", D_800DCF20);

INCLUDE_RODATA("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", D_800DCF38);

INCLUDE_RODATA("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", D_800DCF48);

INCLUDE_RODATA("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", D_800DCFE0);

INCLUDE_RODATA("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", D_800DD000);

INCLUDE_RODATA("asm/bim/w2_2dcfb29798/nonmatchings/w2_2dcfb29798", D_800DD018);
