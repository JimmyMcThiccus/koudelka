#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB3C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA908[], D_800DA920[], D_800DA930[], D_800DA9C8[], D_800DA9E8[], D_800DAA00[];
EXTERN_C const BimVTable10 D_800DA8B8;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void bimf_17d53c09_c(void *self, int a) asm("bimf_17d53c09");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAB3C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)(&self->vtAEC);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8B8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8B8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8B8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA8B8.e[6].delta + adj;
    }
    self->vt8C = D_800DA9E8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9C8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA930;
    self->vt4A8 = D_800DA920;
    self->vt980 = D_800DA908;
    self->vt0 = D_800DAA00;
    bimf_17d53c09_c(self, b);
    func_800D8D64_c(self, 1, 0, 0, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 0;
    *(int *)((char *)r + 0x9D4) = 23;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_a85220b1.cpp"

#include "../shared/bimf_17d53c09.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_5663c35c_c(void *p, unsigned *flags) asm("bimf_5663c35c");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");
EXTERN_C int bimf_a6f0c006_c(void *p, unsigned *flags) asm("bimf_a6f0c006");
EXTERN_C int bimf_0ae2aad9_c(void *p, unsigned *flags) asm("bimf_0ae2aad9");
EXTERN_C int bimf_9b3b5928_c(void *p, unsigned *flags) asm("bimf_9b3b5928");

EXTERN_C int bimf_1d1122f5(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 1000, 0, 0, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_5663c35c_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_a1b3cda8_c(p, flags))
                return 1;
        }
    }
    if (bimf_a6f0c006_c(p, flags))
        return 1;
    if (bimf_0ae2aad9_c(p, flags))
        return 1;
    bimf_9b3b5928_c(p, flags);
    return 1;
}

#include "../shared/bimf_0ae2aad9.cpp"

#include "../shared/bimf_5663c35c.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a1b3cda8.cpp"

EXTERN_C int bimf_5663c35c(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_1(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_2(void *p, unsigned *flags);
EXTERN_C int bimf_a1b3cda8(void *p, unsigned *flags);

EXTERN_C int func_800DB3B4(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (!bimf_5663c35c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 2:
        if (!bimf_af99c5b3(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 4:
        if (!bimf_af99c5b3_1(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 8:
        if (!bimf_af99c5b3_2(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~1;
        return 1;
    case 16:
        if (!bimf_a1b3cda8(p, flags))
            return 0;
        p->f9F0 = 0;
        return 1;
    }
    return 0;
}

#include "../shared/bimf_9b3b5928.cpp"

EXTERN_C BimMon *func_800D8464();
EXTERN_C int bimf_af99c5b3_3_c(void *p, int a) asm("bimf_af99c5b3_3");

EXTERN_C int bimf_06b4d1a5(BimMon *p, int a)
{
    BimMon *o = func_800D8464();
    if (o && o != p) {
        if (rand() & 1) {
            if (!p->f9E4)
                return 0;
            if (!bimf_af99c5b3_3_c(p, a)) {
                if (p)
                    return 0;
                else
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    if (p->f9E8 && (rand() & 7) == 7)
        p->f9EC = 1;
    return 0;
}

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a6f0c006.cpp"

INCLUDE_RODATA("asm/bim/w0_b8c109c72f/nonmatchings/w0_b8c109c72f", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_b8c109c72f/nonmatchings/w0_b8c109c72f", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_b8c109c72f/nonmatchings/w0_b8c109c72f", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_b8c109c72f/nonmatchings/w0_b8c109c72f", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_b8c109c72f/nonmatchings/w0_b8c109c72f", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_b8c109c72f/nonmatchings/w0_b8c109c72f", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_b8c109c72f/nonmatchings/w0_b8c109c72f", D_800DAA00);
