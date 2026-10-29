#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB24(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAA8(int a, short b, int c, int d, int e)
{
    return func_800DAB24(operator new(0xAF0), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", func_800DAB24);

EXTERN_C const BimVTable10 D_800DA8A8;
EXTERN_C char D_800DA8F8[], D_800DA910[], D_800DA920[], D_800DA9B8[], D_800DA9D8[], D_800DA9F0[];

EXTERN_C void func_800DACD4(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DA9D8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9B8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA920;
    self->vt4A8 = D_800DA910;
    self->vt980 = D_800DA8F8;
    self->vt0 = D_800DA9F0;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8A8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8A8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8A8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAE8));
        vt.e[6].delta = D_800DA8A8.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_ASM("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", func_800DAE18);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", func_800DB024);

INCLUDE_ASM("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", func_800DB0C4);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_0d32b1e3.cpp"

EXTERN_C int func_800DB0C4(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_0d32b1e3(void *p, unsigned *flags);

EXTERN_C int func_800DB2C4(BimMon *p, unsigned *flags)
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
        if (bimf_af99c5b3(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_0d32b1e3(p, flags)) {
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

INCLUDE_ASM("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", func_800DB3EC);

INCLUDE_RODATA("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", D_800DA8A8);

INCLUDE_RODATA("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", D_800DA8F8);

INCLUDE_RODATA("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", D_800DA910);

INCLUDE_RODATA("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", D_800DA9B8);

INCLUDE_RODATA("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", D_800DA9D8);

INCLUDE_RODATA("asm/bim/w0_cf9d9baf7a/nonmatchings/w0_cf9d9baf7a", D_800DA9F0);
