#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DBE5C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DBDE0(int a, short b, int c, int d, int e)
{
    return func_800DBE5C((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DBC28[], D_800DBC40[], D_800DBC50[], D_800DBCE8[], D_800DBD08[], D_800DBD20[];
EXTERN_C const BimVTable10 D_800DBBD8;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DC158_c(void *self, int a) asm("func_800DC158");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DBE5C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)(&self->vtAEC);
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8_c(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DBBD8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DBBD8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DBBD8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DBBD8.e[6].delta + adj;
    }
    self->vt8C = D_800DBD08;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DBCE8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DBC50;
    self->vt4A8 = D_800DBC40;
    self->vt980 = D_800DBC28;
    self->vt0 = D_800DBD20;
    func_800DC158_c(self, b);
    func_800D8D64_c(self, 1, 0, 0, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 0;
    *(int *)((char *)r + 0x9D4) = 30;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_ff339051.cpp"

EXTERN_C void func_800DC158(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x1944A;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x1944D;
    *(int *)(p + 0xA08) = 0x1800;
    *(int *)(p + 0xA0C) = 0x19448;
    *(int *)(p + 0xA10) = 0x1000;
    *(int *)(p + 0xA14) = 0x19450;
    *(int *)(p + 0xA18) = 0x3000;
    *(int *)(p + 0xA1C) = 0x19456;
    *(int *)(p + 0xA20) = 0x5000;
    *(int *)(p + 0xA24) = 0x19460;
    *(int *)(p + 0xA28) = 0x4800;
    *(int *)(p + 0xA2C) = 0x19469;
    *(int *)(p + 0xA30) = 0x3000;
    *(int *)(p + 0xA34) = 0x1946F;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x19470;
    *(int *)(p + 0xA40) = 0x800;
    *(int *)(p + 0xA44) = 0x19471;
    *(int *)(p + 0xA48) = 0x3800;
    *(int *)(p + 0xA4C) = 0x19478;
    *(int *)(p + 0xA50) = 0x5000;
    *(int *)(p + 0xA54) = 0x19471;
    *(int *)(p + 0xA58) = 0x3800;
    *(int *)(p + 0xA5C) = 0x19482;
    *(int *)(p + 0xA60) = 0x4000;
    *(int *)(p + 0xADC) = 0x1948A;
    *(int *)(p + 0xAE0) = 0x4000;
    *(int *)(p + 0xAE4) = 0x19492;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_131b36e3_c(void *p, unsigned *flags) asm("bimf_131b36e3");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");
EXTERN_C int bimf_b4962b94_c(void *p, unsigned *flags) asm("bimf_b4962b94");
EXTERN_C int bimf_dd77db6b_c(void *p, unsigned *flags) asm("bimf_dd77db6b");
EXTERN_C int bimf_e310b46d_c(void *p, unsigned *flags) asm("bimf_e310b46d");

EXTERN_C int bimf_29503d9b(BimMon *p, unsigned *flags)
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
            if ((*flags & 2) && bimf_131b36e3_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_a1b3cda8_c(p, flags))
                return 1;
        }
    }
    if (bimf_b4962b94_c(p, flags))
        return 1;
    if (bimf_dd77db6b_c(p, flags)) {
        if (p || flags)
            return 1;
        else
            return 1;
    }
    return bimf_e310b46d_c(p, flags);
}

#include "../shared/bimf_dd77db6b.cpp"

#include "../shared/bimf_131b36e3.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a1b3cda8.cpp"

EXTERN_C int bimf_131b36e3_c(void *p, unsigned *flags) asm("bimf_131b36e3");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");

EXTERN_C int func_800DC6F8(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (bimf_131b36e3_c(p, flags)) {
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

INCLUDE_ASM("asm/bim/w1_4904b03fb2/nonmatchings/w1_4904b03fb2", bimf_e310b46d);

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

#include "../shared/bimf_b4962b94.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_RODATA("asm/bim/w1_4904b03fb2/nonmatchings/w1_4904b03fb2", D_800DBBD8);

INCLUDE_RODATA("asm/bim/w1_4904b03fb2/nonmatchings/w1_4904b03fb2", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_4904b03fb2/nonmatchings/w1_4904b03fb2", D_800DBC40);

INCLUDE_RODATA("asm/bim/w1_4904b03fb2/nonmatchings/w1_4904b03fb2", D_800DBC50);

INCLUDE_RODATA("asm/bim/w1_4904b03fb2/nonmatchings/w1_4904b03fb2", D_800DBCE8);

INCLUDE_RODATA("asm/bim/w1_4904b03fb2/nonmatchings/w1_4904b03fb2", D_800DBD08);

INCLUDE_RODATA("asm/bim/w1_4904b03fb2/nonmatchings/w1_4904b03fb2", D_800DBD20);
