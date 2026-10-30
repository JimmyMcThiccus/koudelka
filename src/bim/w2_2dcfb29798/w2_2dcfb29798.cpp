#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DD154(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DD0D8(int a, short b, int c, int d, int e)
{
    return func_800DD154((BimDtor *)operator new(0xAF8), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DCF20[], D_800DCF38[], D_800DCF48[], D_800DCFE0[], D_800DD000[], D_800DD018[];
EXTERN_C const BimVTable10 D_800DCED0;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void bimf_2f8bc8bf_c(void *self, int a) asm("bimf_2f8bc8bf");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");
EXTERN_C void func_800D817C_c(void *self, int a) asm("func_800D817C");

EXTERN_C BimDtor *func_800DD154(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)((char *)self + 0xAF0);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DCED0;
    if (!in_chrg) {
        BimVTable10 vt = D_800DCED0;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DCED0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF0));
        vt.e[6].delta = D_800DCED0.e[6].delta + adj;
    }
    self->vt8C = D_800DD000;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DCFE0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DCF48;
    self->vt4A8 = D_800DCF38;
    self->vt980 = D_800DCF20;
    self->vt0 = D_800DD018;
    bimf_2f8bc8bf_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 0, 0, 0, 0, 0);
    self->f9DC = 0;
    *(int *)((char *)self + 0x9D4) = 28;
    self->f9D8 = 0;
    func_800D817C_c(self, 1);
    register BimDtor *r asm("$2") = self;
    *(int *)((char *)r + 0xAE8) = 4;
    *(int *)((char *)r + 0xAEC) = 0;
    return r;
}

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

#include "../shared/bimf_2f8bc8bf.cpp"

#include "../shared/bimf_d3d03f70.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_15ce46f8.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int func_800DDE94_c(void *p, unsigned *flags) asm("func_800DDE94");
EXTERN_C int bimf_096f4279_c(void *p, unsigned *flags) asm("bimf_096f4279");
EXTERN_C int bimf_e32ca3a9_c(void *p, unsigned *flags) asm("bimf_e32ca3a9");
EXTERN_C int bimf_d408bc6f_c(void *p, unsigned *flags) asm("bimf_d408bc6f");
EXTERN_C int bimf_6eb48601_c(void *p, unsigned *flags) asm("bimf_6eb48601");

EXTERN_C int func_800DD7E4(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 300, 400, 300, 0, 0, 0, 0, 0);
    if (func_800DDE94_c(p, flags))
        return 1;
    func_800D8C0C(p);
    if (((BimV *)p)->v22((int)flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_096f4279_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_e32ca3a9_c(p, flags))
                return 1;
        }
    }
    if (bimf_d408bc6f_c(p, flags)) {
        if (p || flags)
            return 1;
        else
            return 1;
    }
    return bimf_6eb48601_c(p, flags);
}

#include "../shared/bimf_096f4279.cpp"

#include "../shared/bimf_e32ca3a9.cpp"

#include "../shared/bimf_fddfe66d.cpp"

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
