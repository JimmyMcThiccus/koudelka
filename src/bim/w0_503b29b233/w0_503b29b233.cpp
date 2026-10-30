#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB3C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C((BimDtor *)operator new(0xAF8), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA908[], D_800DA920[], D_800DA930[], D_800DA9C8[], D_800DA9E8[], D_800DAA00[];
EXTERN_C const BimVTable10 D_800DA8B8;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DAE50_c(void *self, int a) asm("func_800DAE50");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");
EXTERN_C void func_800D817C_c(void *self, int a) asm("func_800D817C");

EXTERN_C BimDtor *func_800DAB3C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)((char *)self + 0xAF0);
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
        vt.e[1].delta = D_800DA8B8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF0));
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
    func_800D8D64_c(self, 1, 1, 1, 1, 1, 0, 0, 0);
    self->f9DC = 3;
    *(int *)((char *)self + 0x9D4) = 154;
    self->f9D8 = 0;
    func_800D817C_c(self, 1);
    register BimDtor *r asm("$2") = self;
    *(int *)((char *)r + 0x9FC) = 0;
    return r;
}

#include "../shared/bimf_8a9e0866.cpp"

EXTERN_C void func_800DAE50(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0xA00) = 0x19EA4;
    *(int *)(p + 0xA04) = 0x1800;
    *(int *)(p + 0xA08) = 0x19EA4;
    *(int *)(p + 0xA0C) = 0x1800;
    *(int *)(p + 0xA10) = 0x19EA4;
    *(int *)(p + 0xA14) = 0x1800;
    *(int *)(p + 0xA18) = 0x19EA7;
    *(int *)(p + 0xA1C) = 0x5800;
    *(int *)(p + 0xA20) = 0x19EB2;
    *(int *)(p + 0xA24) = 0x5800;
    *(int *)(p + 0xA28) = 0x19EBD;
    *(int *)(p + 0xA2C) = 0x5800;
    *(int *)(p + 0xA30) = 0x19EC8;
    *(int *)(p + 0xA34) = 0x3800;
    *(int *)(p + 0xA38) = 0x19ECF;
    *(int *)(p + 0xA3C) = 0x2000;
    *(int *)(p + 0xA40) = 0x19ED3;
    *(int *)(p + 0xA44) = 0x1000;
    *(int *)(p + 0xA48) = 0x19ED5;
    *(int *)(p + 0xA4C) = 0x6000;
    *(int *)(p + 0xA50) = 0x19ED5;
    *(int *)(p + 0xA54) = 0x6000;
    *(int *)(p + 0xA58) = 0x19ED5;
    *(int *)(p + 0xA5C) = 0x6000;
    *(int *)(p + 0xA60) = 0x19ED5;
    *(int *)(p + 0xA64) = 0x6000;
    *(int *)(p + 0xA68) = 0x19ED5;
    *(int *)(p + 0xA6C) = 0x6000;
    *(int *)(p + 0xA70) = 0x19ED5;
    *(int *)(p + 0xA74) = 0x6000;
    *(int *)(p + 0xA78) = 0x19ED5;
    *(int *)(p + 0xA7C) = 0x6000;
    *(int *)(p + 0xAE0) = 0x19EE1;
    *(int *)(p + 0xAE4) = 0x7000;
    *(int *)(p + 0xAE8) = 0x19EEF;
    *(int *)(p + 0xAEC) = 0x800;
    int *v = q + 640;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_1a38796b.cpp"

EXTERN_C void func_800D8F50(void *p, int a, unsigned char b);

EXTERN_C void func_800DAFF4(BimM9 *p, int a, unsigned char b)
{
    p->f9FC++;
    func_800D8F50(p, a, b);
}

INCLUDE_ASM("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", func_800DB020);

EXTERN_C int func_800DB188(BimMon *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7914(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x121);
        if (q) {
            int r = 1;
            func_800D7AC4(p, q, 0, 0);
            p->f9F0 = r;
            *flags &= ~1;
            return r;
        }
        q = func_800D7A4C(p, 1, 0x21);
        if (!q)
            return 0;
        func_800D7BB4(p, (int)q, 0, 0);
        *flags &= ~1;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800DB25C(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0, 0xC8, 0x190, 0x190, 0, 0, 0, 0);
        int id = func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        if (id == 1 || id == 5)
            return 0;
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            func_800D7D64(p, q);
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_4379dd60.cpp"

EXTERN_C int func_800DB25C_c(void *p, unsigned *flags) asm("func_800DB25C");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_4379dd60_c(void *p, unsigned *flags) asm("bimf_4379dd60");

EXTERN_C int func_800DB3F4(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (func_800DB25C_c(p, flags)) {
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
        if (bimf_4379dd60_c(p, flags)) {
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

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", func_800DB57C);

INCLUDE_ASM("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", func_800DB764);

INCLUDE_RODATA("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_503b29b233/nonmatchings/w0_503b29b233", D_800DAA00);
