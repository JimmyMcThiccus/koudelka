#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAAF4(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAA78(int a, short b, int c, int d, int e)
{
    return func_800DAAF4((BimDtor *)operator new(0xAF0), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA8C8[], D_800DA8E0[], D_800DA8F0[], D_800DA988[], D_800DA9A8[], D_800DA9C0[];
EXTERN_C const BimVTable10 D_800DA878;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void bimf_a1bcebde_c(void *self, int a) asm("bimf_a1bcebde");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAAF4(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)((char *)self + 0xAE8);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA878;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA878;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA878.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAE8));
        vt.e[6].delta = D_800DA878.e[6].delta + adj;
    }
    self->vt8C = D_800DA9A8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA988;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA8F0;
    self->vt4A8 = D_800DA8E0;
    self->vt980 = D_800DA8C8;
    self->vt0 = D_800DA9C0;
    bimf_a1bcebde_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 0;
    *(int *)((char *)r + 0x9D4) = 11;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_3dafacd3.cpp"

#include "../shared/bimf_a1bcebde.cpp"

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

#include "../shared/bimf_35f30ee4.cpp"

#include "../shared/bimf_bf95a37b.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_0d32b1e3.cpp"

#include "../shared/bimf_4cfb86f6.cpp"

#include "../shared/bimf_05e090a7.cpp"

#include "../shared/bimf_79606d43.cpp"

INCLUDE_RODATA("asm/bim/w0_6cf52725b2/nonmatchings/w0_6cf52725b2", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_6cf52725b2/nonmatchings/w0_6cf52725b2", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_6cf52725b2/nonmatchings/w0_6cf52725b2", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_6cf52725b2/nonmatchings/w0_6cf52725b2", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_6cf52725b2/nonmatchings/w0_6cf52725b2", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_6cf52725b2/nonmatchings/w0_6cf52725b2", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_6cf52725b2/nonmatchings/w0_6cf52725b2", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_6cf52725b2/nonmatchings/w0_6cf52725b2", D_800DA9C0);
