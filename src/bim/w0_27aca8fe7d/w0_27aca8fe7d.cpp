#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB0C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAA90(int a, short b, int c, int d, int e)
{
    return func_800DAB0C((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA8E0[], D_800DA8F8[], D_800DA908[], D_800DA9A0[], D_800DA9C0[], D_800DA9D8[];
EXTERN_C const BimVTable10 D_800DA890;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DAE0C_c(void *self, int a) asm("func_800DAE0C");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAB0C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)(&self->vtAEC);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA890;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA890;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA890.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA890.e[6].delta + adj;
    }
    self->vt8C = D_800DA9C0;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9A0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA908;
    self->vt4A8 = D_800DA8F8;
    self->vt980 = D_800DA8E0;
    self->vt0 = D_800DA9D8;
    func_800DAE0C_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 1, 1, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 0;
    *(int *)((char *)r + 0x9D4) = 13;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_a9e82488.cpp"

EXTERN_C void func_800DAE0C(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x18E9E;
    *(int *)(p + 0xA00) = 0x1000;
    *(int *)(p + 0xA04) = 0x18EA0;
    *(int *)(p + 0xA08) = 0x5000;
    *(int *)(p + 0xA0C) = 0x18E94;
    *(int *)(p + 0xA10) = 0x5000;
    *(int *)(p + 0xA14) = 0x18EAA;
    *(int *)(p + 0xA18) = 0x3800;
    *(int *)(p + 0xA1C) = 0x18EB1;
    *(int *)(p + 0xA20) = 0x4000;
    *(int *)(p + 0xA24) = 0x18EB9;
    *(int *)(p + 0xA28) = 0x4000;
    *(int *)(p + 0xA2C) = 0x18EC1;
    *(int *)(p + 0xA30) = 0x3800;
    *(int *)(p + 0xA34) = 0x18EC8;
    *(int *)(p + 0xA38) = 0x1000;
    *(int *)(p + 0xA3C) = 0x18ECA;
    *(int *)(p + 0xA40) = 0x1000;
    *(int *)(p + 0xA44) = 0x18ECC;
    *(int *)(p + 0xA48) = 0x3000;
    *(int *)(p + 0xA4C) = 0x18ED2;
    *(int *)(p + 0xA50) = 0x5800;
    *(int *)(p + 0xA54) = 0x18ECC;
    *(int *)(p + 0xA58) = 0x3000;
    *(int *)(p + 0xA5C) = 0x18ECC;
    *(int *)(p + 0xA60) = 0x3000;
    *(int *)(p + 0xA64) = 0x18ECC;
    *(int *)(p + 0xA68) = 0x3000;
    *(int *)(p + 0xA6C) = 0x18ECC;
    *(int *)(p + 0xA70) = 0x3000;
    *(int *)(p + 0xADC) = 0x18EDD;
    *(int *)(p + 0xAE0) = 0x4000;
    *(int *)(p + 0xAE4) = 0x18EE5;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int func_800DB5F0_c(void *p, unsigned *flags) asm("func_800DB5F0");
EXTERN_C int bimf_cba85eee_c(void *p, unsigned *flags) asm("bimf_cba85eee");
EXTERN_C int func_800DB204_c(void *p, unsigned *flags) asm("func_800DB204");
EXTERN_C int func_800DB3C8_c(void *p, unsigned *flags) asm("func_800DB3C8");
EXTERN_C int bimf_db5f4bc4_c(void *p, unsigned *flags) asm("bimf_db5f4bc4");

EXTERN_C int func_800DAFF4(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 500, 100, 100, 100, 100, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    if (func_800DB5F0_c(p, flags))
        return 1;
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_cba85eee_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && func_800DB204_c(p, flags))
                return 1;
        }
    }
    if (func_800DB3C8_c(p, flags))
        return 1;
    bimf_db5f4bc4_c(p, flags);
    return 1;
}

#include "../shared/bimf_cba85eee.cpp"

#include "../shared/bimf_af99c5b3.cpp"

EXTERN_C int func_800DB204(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x21);
        if (!q)
            return 0;
        if (func_800D8064(p)) {
            *flags &= ~1;
            return 1;
        }
    }
    return 0;
}

EXTERN_C int bimf_cba85eee(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int func_800DB204(void *p, unsigned *flags);

EXTERN_C int func_800DB2A0(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_cba85eee(p, flags)) {
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
        if (func_800DB204(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

#include "../shared/bimf_db5f4bc4.cpp"

INCLUDE_ASM("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", func_800DB3C8);

INCLUDE_ASM("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", func_800DB5F0);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA890);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA8F8);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA9A0);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA9C0);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA9D8);
