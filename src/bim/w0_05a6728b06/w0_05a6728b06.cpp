#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAAFC(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAA80(int a, short b, int c, int d, int e)
{
    return func_800DAAFC((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA8C8[], D_800DA8E0[], D_800DA8F0[], D_800DA988[], D_800DA9A8[], D_800DA9C0[];
EXTERN_C const BimVTable10 D_800DA878;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DADF8_c(void *self, int a) asm("func_800DADF8");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAAFC(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)(&self->vtAEC);
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
        vt.e[1].delta = D_800DA878.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
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
    func_800DADF8_c(self, b);
    func_800D8D64_c(self, 1, 1, 0, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 0;
    *(int *)((char *)r + 0x9D4) = 156;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_77c7ba37.cpp"

EXTERN_C void func_800DADF8(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x19F02;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x19F02;
    *(int *)(p + 0xA08) = 0x1800;
    *(int *)(p + 0xA0C) = 0x19F02;
    *(int *)(p + 0xA10) = 0x1800;
    *(int *)(p + 0xA14) = 0x19F05;
    *(int *)(p + 0xA18) = 0x6800;
    *(int *)(p + 0xA1C) = 0x19F12;
    *(int *)(p + 0xA20) = 0x6000;
    *(int *)(p + 0xA24) = 0x19F12;
    *(int *)(p + 0xA28) = 0x6000;
    *(int *)(p + 0xA2C) = 0x19F1E;
    *(int *)(p + 0xA30) = 0x6000;
    *(int *)(p + 0xA34) = 0x19F2A;
    *(int *)(p + 0xA38) = 0x1000;
    *(int *)(p + 0xA3C) = 0x19F2C;
    *(int *)(p + 0xA40) = 0x1000;
    *(int *)(p + 0xA44) = 0x19F2E;
    *(int *)(p + 0xA48) = 0x6000;
    *(int *)(p + 0xA4C) = 0x19F3A;
    *(int *)(p + 0xA50) = 0x6800;
    *(int *)(p + 0xA54) = 0x19F2E;
    *(int *)(p + 0xA58) = 0x6000;
    *(int *)(p + 0xADC) = 0x19F47;
    *(int *)(p + 0xAE0) = 0x8000;
    *(int *)(p + 0xAE4) = 0x19F57;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int func_800DB0EC_c(void *p, unsigned *flags) asm("func_800DB0EC");
EXTERN_C int bimf_db5f4bc4_c(void *p, unsigned *flags) asm("bimf_db5f4bc4");

EXTERN_C int func_800DAF90(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 600, 400, 0, 0, 0, 0, 0, 0);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (func_800D84C8(p))
        func_800D8350(p, 3);
    if (func_800DB0EC_c(p, flags))
        return 1;
    bimf_db5f4bc4_c(p, flags);
    return 1;
}

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_92c79aea.cpp"

#include "../shared/bimf_db5f4bc4.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_6
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_7
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_8
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", func_800DB0EC);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA9C0);
