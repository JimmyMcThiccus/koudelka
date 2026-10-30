#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB24(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAAA8(int a, short b, int c, int d, int e)
{
    return func_800DAB24((BimDtor *)operator new(0xAF0), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA8F8[], D_800DA910[], D_800DA920[], D_800DA9B8[], D_800DA9D8[], D_800DA9F0[];
EXTERN_C const BimVTable10 D_800DA8A8;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DAE18_c(void *self, int a) asm("func_800DAE18");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAB24(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)((char *)self + 0xAE8);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8A8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8A8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8A8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAE8));
        vt.e[6].delta = D_800DA8A8.e[6].delta + adj;
    }
    self->vt8C = D_800DA9D8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9B8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA920;
    self->vt4A8 = D_800DA910;
    self->vt980 = D_800DA8F8;
    self->vt0 = D_800DA9F0;
    func_800DAE18_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 1, 1, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9D8 = 0;
    return r;
}

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

EXTERN_C void func_800DAE18(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x199FA;
    *(int *)(p + 0x9FC) = 0x4000;
    *(int *)(p + 0xA00) = 0x19A13;
    *(int *)(p + 0xA04) = 0xA000;
    *(int *)(p + 0xA08) = 0x19A13;
    *(int *)(p + 0xA0C) = 0xA000;
    *(int *)(p + 0xA10) = 0x19A02;
    *(int *)(p + 0xA14) = 0x8800;
    *(int *)(p + 0xA18) = 0x19A27;
    *(int *)(p + 0xA1C) = 0x9800;
    *(int *)(p + 0xA20) = 0x19A3A;
    *(int *)(p + 0xA24) = 0x9800;
    *(int *)(p + 0xA28) = 0x19A4D;
    *(int *)(p + 0xA2C) = 0x5800;
    *(int *)(p + 0xA30) = 0x19A58;
    *(int *)(p + 0xA34) = 0x800;
    *(int *)(p + 0xA38) = 0x19A59;
    *(int *)(p + 0xA3C) = 0x2800;
    *(int *)(p + 0xA40) = 0x19A5E;
    *(int *)(p + 0xA44) = 0x5000;
    *(int *)(p + 0xA48) = 0x19A68;
    *(int *)(p + 0xA4C) = 0x9000;
    *(int *)(p + 0xA50) = 0x19A7A;
    *(int *)(p + 0xA54) = 0xB000;
    *(int *)(p + 0xA58) = 0x19A90;
    *(int *)(p + 0xA5C) = 0x9000;
    *(int *)(p + 0xA60) = 0x19AA2;
    *(int *)(p + 0xA64) = 0xB000;
    *(int *)(p + 0xA68) = 0x19A5E;
    *(int *)(p + 0xA6C) = 0x5000;
    *(int *)(p + 0xAD8) = 0x19AB8;
    *(int *)(p + 0xADC) = 0x8000;
    *(int *)(p + 0xAE0) = 0x19AC8;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800DB3EC(void *p, unsigned *flags);
EXTERN_C int bimf_05e090a7_c(void *p, unsigned *flags) asm("bimf_05e090a7");

EXTERN_C int func_800DB024(BimV *p, unsigned *flags)
{
    func_800D7818(p, 0x12C, 0x64, 0x12C, 0x64, 0xC8, 0, 0, 0);
    if (p->v21((int)flags))
        return 1;
    if (func_800DB3EC(p, flags))
        return 1;
    bimf_05e090a7_c(p, flags);
    return 1;
}

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
