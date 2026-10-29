#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB14(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA98(int a, short b, int c, int d, int e)
{
    return func_800DAB14(operator new(0xAF0), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DAB14);

EXTERN_C const BimVTable10 D_800DA898;
EXTERN_C char D_800DA8E8[], D_800DA900[], D_800DA910[], D_800DA9A8[], D_800DA9C8[], D_800DA9E0[];

EXTERN_C void func_800DACC8(BimDtor *self, int in_chrg)
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
        vt.e[1].delta = D_800DA898.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAE8));
        vt.e[6].delta = D_800DA898.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DAE0C);

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DAFE0);

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DB0C4);

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DB1DC);

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DB288);

EXTERN_C int func_800DB0C4(void *p, unsigned *flags);
EXTERN_C int func_800DB1DC(void *p, unsigned *flags);
EXTERN_C int func_800DB288(void *p, unsigned *flags);

EXTERN_C int func_800DB33C(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (func_800DB0C4(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (func_800DB1DC(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (func_800DB288(p, flags)) {
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

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DB464);

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DB624);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA86C);

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DB6A8);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA898);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA8E8);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA900);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA910);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA9E0);
