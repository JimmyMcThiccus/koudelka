#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB44(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAAC8(int a, short b, int c, int d, int e)
{
    return func_800DAB44((BimDtor *)operator new(0xB00), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA908[], D_800DA920[], D_800DA930[], D_800DA9C8[], D_800DA9E8[], D_800DAA00[];
EXTERN_C const BimVTable10 D_800DA8B8;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DAE50_c(void *self, int a) asm("func_800DAE50");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAB44(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)((char *)self + 0xAF8);
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
        vt.e[1].delta = D_800DA8B8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF8));
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
    func_800DAE50_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    *(int *)((char *)r + 0x9D4) = 159;
    r->f9DC = 0;
    r->f9D8 = 0;
    *(int *)((char *)r + 0x9FC) = 0;
    *(int *)((char *)r + 0xA00) = 2;
    *(int *)((char *)r + 0xA04) = 2;
    return r;
}

EXTERN_C const BimVTable10 D_800DA8B8;
EXTERN_C char D_800DA908[], D_800DA920[], D_800DA930[], D_800DA9C8[], D_800DA9E8[], D_800DAA00[];

EXTERN_C void func_800DAD0C(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DA9E8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9C8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA930;
    self->vt4A8 = D_800DA920;
    self->vt980 = D_800DA908;
    self->vt0 = D_800DAA00;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8B8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8B8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8B8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF8));
        vt.e[6].delta = D_800DA8B8.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

EXTERN_C void func_800DAE50(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0xA08) = 0x1A049;
    *(int *)(p + 0xA0C) = 0x1800;
    *(int *)(p + 0xA10) = 0x1A04C;
    *(int *)(p + 0xA14) = 0x4800;
    *(int *)(p + 0xA18) = 0x1A041;
    *(int *)(p + 0xA1C) = 0x4000;
    *(int *)(p + 0xA20) = 0x1A055;
    *(int *)(p + 0xA24) = 0x2000;
    *(int *)(p + 0xA28) = 0x1A059;
    *(int *)(p + 0xA2C) = 0x5800;
    *(int *)(p + 0xA30) = 0x1A064;
    *(int *)(p + 0xA34) = 0x4000;
    *(int *)(p + 0xA38) = 0x1A06C;
    *(int *)(p + 0xA3C) = 0x1000;
    *(int *)(p + 0xA40) = 0x1A06E;
    *(int *)(p + 0xA44) = 0x1800;
    *(int *)(p + 0xA48) = 0x1A071;
    *(int *)(p + 0xA4C) = 0x800;
    *(int *)(p + 0xA50) = 0x1A072;
    *(int *)(p + 0xA54) = 0x1000;
    *(int *)(p + 0xA58) = 0x1A083;
    *(int *)(p + 0xA5C) = 0x5000;
    *(int *)(p + 0xA60) = 0x1A074;
    *(int *)(p + 0xA64) = 0x6800;
    *(int *)(p + 0xA68) = 0x1A072;
    *(int *)(p + 0xA6C) = 0x1000;
    *(int *)(p + 0xA70) = 0x1A081;
    *(int *)(p + 0xA74) = 0x800;
    *(int *)(p + 0xA78) = 0x1A082;
    *(int *)(p + 0xA7C) = 0x800;
    *(int *)(p + 0xA80) = 0x1A08D;
    *(int *)(p + 0xA84) = 0x1800;
    *(int *)(p + 0xA88) = 0x1A090;
    *(int *)(p + 0xA8C) = 0x2000;
    *(int *)(p + 0xA90) = 0x1A090;
    *(int *)(p + 0xA94) = 0x2000;
    *(int *)(p + 0xA98) = 0x1A049;
    *(int *)(p + 0xA9C) = 0x1800;
    *(int *)(p + 0xAE8) = 0x1A098;
    *(int *)(p + 0xAEC) = 0x6000;
    *(int *)(p + 0xAF0) = 0x1A0A4;
    *(int *)(p + 0xAF4) = 0x1000;
    int *v = q + 642;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

EXTERN_C int func_800DB018(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 0xD);
        func_80082670(p + 0x2A4, 0x11, 0xE);
        break;
    case 2:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 3:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    }
    return r;
}

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB174);

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB448);

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

EXTERN_C int func_800DB584(BimMon *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x21);
        if (!q)
            return 0;
        if (*(int *)((char *)p + 0x9C8) & 1)
            func_800D7C7C_i(p, -3, 0);
        else
            func_800D7AC4(p, q, 1, 0);
        *flags &= ~1;
        return 1;
    }
    return 0;
}

EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_af99c5b3_3_c(void *p, unsigned *flags) asm("bimf_af99c5b3_3");
EXTERN_C int func_800DB584_c(void *p, unsigned *flags) asm("func_800DB584");

EXTERN_C int func_800DB634(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_af99c5b3_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 2:
        if (bimf_af99c5b3_1_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 4:
        if (bimf_af99c5b3_2_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3_3_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (func_800DB584_c(p, flags)) {
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

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_6
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB7BC);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DAA00);
