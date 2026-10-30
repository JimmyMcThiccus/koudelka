#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAAFC(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAA80(int a, short b, int c, int d, int e)
{
    return func_800DAAFC((BimDtor *)operator new(0xAF0), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA8C8[], D_800DA8E0[], D_800DA8F0[], D_800DA988[], D_800DA9A8[], D_800DA9C0[];
EXTERN_C const BimVTable10 D_800DA878;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DADF4_c(void *self, int a) asm("func_800DADF4");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAAFC(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
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
    func_800DADF4_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 1, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 0;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_3dafacd3.cpp"

EXTERN_C void func_800DADF4(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x19977;
    *(int *)(p + 0x9FC) = 0x2800;
    *(int *)(p + 0xA00) = 0x1997C;
    *(int *)(p + 0xA04) = 0x7800;
    *(int *)(p + 0xA08) = 0x19969;
    *(int *)(p + 0xA0C) = 0x7000;
    *(int *)(p + 0xA10) = 0x1998B;
    *(int *)(p + 0xA14) = 0x6000;
    *(int *)(p + 0xA18) = 0x19997;
    *(int *)(p + 0xA1C) = 0x5000;
    *(int *)(p + 0xA20) = 0x199A1;
    *(int *)(p + 0xA24) = 0x5000;
    *(int *)(p + 0xA28) = 0x199AB;
    *(int *)(p + 0xA2C) = 0x3000;
    *(int *)(p + 0xA30) = 0x199B1;
    *(int *)(p + 0xA34) = 0x1800;
    *(int *)(p + 0xA38) = 0x199B4;
    *(int *)(p + 0xA3C) = 0x1000;
    *(int *)(p + 0xA40) = 0x199B6;
    *(int *)(p + 0xA44) = 0x5800;
    *(int *)(p + 0xA48) = 0x199C1;
    *(int *)(p + 0xA4C) = 0x4800;
    *(int *)(p + 0xA50) = 0x199CA;
    *(int *)(p + 0xA54) = 0x6000;
    *(int *)(p + 0xA58) = 0x199B6;
    *(int *)(p + 0xA5C) = 0x5800;
    *(int *)(p + 0xA60) = 0x199E0;
    *(int *)(p + 0xA64) = 0x5800;
    *(int *)(p + 0xA68) = 0x199D6;
    *(int *)(p + 0xA6C) = 0x1800;
    *(int *)(p + 0xA70) = 0x199D9;
    *(int *)(p + 0xA74) = 0x3800;
    *(int *)(p + 0xAD8) = 0x199EB;
    *(int *)(p + 0xADC) = 0x5800;
    *(int *)(p + 0xAE0) = 0x199F6;
    *(int *)(p + 0xAE4) = 0x1800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

EXTERN_C int func_800DAF88(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 2:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 3:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 4:
        func_80082670(p + 0x2A4, 0x10, 0xE);
        func_80082670(p + 0x2A4, 0x11, 0xF);
        break;
    }
    return r;
}

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int func_800DB4D4_c(void *p, unsigned *flags) asm("func_800DB4D4");
EXTERN_C int bimf_05e090a7_c(void *p, unsigned *flags) asm("bimf_05e090a7");

EXTERN_C int func_800DB134(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 300, 300, 200, 200, 0, 0, 0, 0);
    if (((BimV *)p)->v22((int)flags))
        return 1;
    if (func_800D84C8(p))
        func_800D8350(p, 3);
    if (func_800DB4D4_c(p, flags))
        return 1;
    bimf_05e090a7_c(p, flags);
    return 1;
}

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB1E8);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_0d32b1e3.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB398);

#include "../shared/bimf_05e090a7.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB4D4);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA9C0);
