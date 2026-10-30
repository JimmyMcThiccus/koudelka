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
EXTERN_C void bimf_9ee8aced_c(void *self, int a) asm("bimf_9ee8aced");
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
    bimf_9ee8aced_c(self, b);
    func_800D8D64_c(self, 1, 1, 0, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 0;
    *(int *)((char *)r + 0x9D4) = 4;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_a85220b1.cpp"

#include "../shared/bimf_9ee8aced.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

#include "../shared/bimf_73046ab9.cpp"

#include "../shared/bimf_54e42f42.cpp"

#include "../shared/bimf_063a8822.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a1b3cda8.cpp"

EXTERN_C int bimf_063a8822_c(void *p, unsigned *flags) asm("bimf_063a8822");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");

EXTERN_C int func_800DB418(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (bimf_063a8822_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 2:
        if (bimf_af99c5b3_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 4:
        if (bimf_af99c5b3_1_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3_2_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_a1b3cda8_c(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

#include "../shared/bimf_584a2d1f.cpp"

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

#include "../shared/bimf_38dc0e9d.cpp"

INCLUDE_RODATA("asm/bim/w0_7d2921f5b2/nonmatchings/w0_7d2921f5b2", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_7d2921f5b2/nonmatchings/w0_7d2921f5b2", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_7d2921f5b2/nonmatchings/w0_7d2921f5b2", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_7d2921f5b2/nonmatchings/w0_7d2921f5b2", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_7d2921f5b2/nonmatchings/w0_7d2921f5b2", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_7d2921f5b2/nonmatchings/w0_7d2921f5b2", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_7d2921f5b2/nonmatchings/w0_7d2921f5b2", D_800DAA00);
