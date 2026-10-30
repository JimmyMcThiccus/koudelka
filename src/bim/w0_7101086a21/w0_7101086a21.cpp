#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB14(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAA98(int a, short b, int c, int d, int e)
{
    return func_800DAB14((BimDtor *)operator new(0xAF0), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA8E8[], D_800DA900[], D_800DA910[], D_800DA9A8[], D_800DA9C8[], D_800DA9E0[];
EXTERN_C const BimVTable10 D_800DA898;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DAE0C_c(void *self, int a) asm("func_800DAE0C");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAB14(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)((char *)self + 0xAE8);
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
        vt.e[1].delta = D_800DA898.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAE8));
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
    func_800DAE0C_c(self, b);
    func_800D8D64_c(self, 1, 0, 0, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    *(int *)((char *)r + 0x9D4) = 7;
    r->f9D8 = 0;
    return r;
}

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

EXTERN_C void func_800DAE0C(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x18C75;
    *(int *)(p + 0x9FC) = 0x1800;
    *(int *)(p + 0xA00) = 0x18C78;
    *(int *)(p + 0xA04) = 0x5800;
    *(int *)(p + 0xA08) = 0x18C6E;
    *(int *)(p + 0xA0C) = 0x3800;
    *(int *)(p + 0xA10) = 0x18C83;
    *(int *)(p + 0xA14) = 0x3000;
    *(int *)(p + 0xA18) = 0x18C89;
    *(int *)(p + 0xA1C) = 0x7800;
    *(int *)(p + 0xA20) = 0x18C98;
    *(int *)(p + 0xA24) = 0x6000;
    *(int *)(p + 0xA28) = 0x18CA4;
    *(int *)(p + 0xA2C) = 0x4000;
    *(int *)(p + 0xA30) = 0x18CAC;
    *(int *)(p + 0xA34) = 0x1800;
    *(int *)(p + 0xA38) = 0x18CAF;
    *(int *)(p + 0xA3C) = 0x1800;
    *(int *)(p + 0xA40) = 0x18CB2;
    *(int *)(p + 0xA44) = 0x6800;
    *(int *)(p + 0xA48) = 0x18CBF;
    *(int *)(p + 0xA4C) = 0x6800;
    *(int *)(p + 0xAD8) = 0x18CCC;
    *(int *)(p + 0xADC) = 0x8000;
    *(int *)(p + 0xAE0) = 0x18CDC;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int func_800DB464_c(void *p, unsigned *flags) asm("func_800DB464");
EXTERN_C int func_800DB1DC_c(void *p, unsigned *flags) asm("func_800DB1DC");
EXTERN_C int bimf_05e090a7_c(void *p, unsigned *flags) asm("bimf_05e090a7");
EXTERN_C int func_800DB624_c(void *p, unsigned *flags) asm("func_800DB624");

EXTERN_C int func_800DAFE0(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 1000, 0, 0, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800DB624_c(p, flags))
        return 1;
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (func_800DB464_c(p, flags))
        return 1;
    if (func_800DB1DC_c(p, flags))
        return 1;
    bimf_05e090a7_c(p, flags);
    return 1;
}

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DB0C4);

EXTERN_C int func_800DB1DC(void *p, unsigned *flags)
{
    if (*flags & 1) {
        int ret;
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 2, 0x21);
        if (q && func_800D7BB4(p, (int)q, 0, 0)) {
            ret = 1;
            ((BimMon *)p)->f9F0 = ret;
            *flags &= ~1;
            return ret;
        }
    }
    return 0;
}

EXTERN_C int func_800DB288(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        if (!func_800D8064(p)) {
            void *q = func_800D7A4C(p, 1, 0x21);
            if (!q)
                return 0;
            if (!func_800D7AC4(p, q, 1, 0))
                return 0;
        }
        *flags &= ~1;
        return 1;
    }
    return 0;
}

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

EXTERN_C int func_800DB624(void *p, unsigned *flags)
{
    int ret;
    if (*flags & 1) {
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        if (!func_800D8064(p))
            return 0;
        ret = 1;
        *flags &= ~1;
        return ret;
    }
    return 0;
}

INCLUDE_ASM("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", func_800DB6A8);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA898);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA8E8);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA900);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA910);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_7101086a21/nonmatchings/w0_7101086a21", D_800DA9E0);
