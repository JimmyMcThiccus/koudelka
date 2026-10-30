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
EXTERN_C void func_800DAE30_c(void *self, int a) asm("func_800DAE30");
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
    func_800DAE30_c(self, b);
    func_800D8D64_c(self, 1, 1, 0, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    r->f9DC = 0;
    r->f9D8 = 0;
    return r;
}

#include "../shared/bimf_a85220b1.cpp"

EXTERN_C void func_800DAE30(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x19531;
    *(int *)(p + 0xA00) = 0x2800;
    *(int *)(p + 0xA04) = 0x19536;
    *(int *)(p + 0xA08) = 0x3000;
    *(int *)(p + 0xA0C) = 0x19536;
    *(int *)(p + 0xA10) = 0x3000;
    *(int *)(p + 0xA14) = 0x1953C;
    *(int *)(p + 0xA18) = 0x6000;
    *(int *)(p + 0xA1C) = 0x19548;
    *(int *)(p + 0xA20) = 0x5800;
    *(int *)(p + 0xA24) = 0x19553;
    *(int *)(p + 0xA28) = 0x4000;
    *(int *)(p + 0xA2C) = 0x1955B;
    *(int *)(p + 0xA30) = 0x3800;
    *(int *)(p + 0xA34) = 0x19562;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x19563;
    *(int *)(p + 0xA40) = 0x1000;
    *(int *)(p + 0xA44) = 0x19565;
    *(int *)(p + 0xA48) = 0x5000;
    *(int *)(p + 0xA4C) = 0x1956F;
    *(int *)(p + 0xA50) = 0x5000;
    *(int *)(p + 0xA54) = 0x19565;
    *(int *)(p + 0xA58) = 0x5000;
    *(int *)(p + 0xADC) = 0x19579;
    *(int *)(p + 0xAE0) = 0x5800;
    *(int *)(p + 0xAE4) = 0x19584;
    *(int *)(p + 0xAE8) = 0x1000;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", func_800DAFE4);

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

EXTERN_C int bimf_131b36e3(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_1(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_2(void *p, unsigned *flags);
EXTERN_C int bimf_a1b3cda8(void *p, unsigned *flags);

EXTERN_C int func_800DB3A4(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (!bimf_131b36e3(p, flags))
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

#include "../shared/bimf_e310b46d.cpp"

INCLUDE_ASM("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", func_800DB624);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", func_800DB6EC);

EXTERN_C int func_800DB794(void *p, unsigned *flags)
{
    int ok = 0;
    if (func_800D84C8(p))
        ok = func_800D8350(p, 2) != 0;
    if (!ok) {
        if (p || flags)
            return 0;
        else
            return 0;
    }
    func_800D8E64(p, 2);
    func_800D7D64(p, (void *)(ok = func_800D7E8C(p, (int)p)));
    *flags &= ~2;
    return 1;
}

INCLUDE_RODATA("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_fb98fcc327/nonmatchings/w0_fb98fcc327", D_800DAA00);
