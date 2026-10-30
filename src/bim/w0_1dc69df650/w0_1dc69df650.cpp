#include "common.h"
#include "bim/shared.h"

EXTERN_C BimDtor *func_800DAB34(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);

EXTERN_C void *func_800DAAB8(int a, short b, int c, int d, int e)
{
    return func_800DAB34((BimDtor *)operator new(0xAF4), 1, a, b, c, d, e);
}

EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C char D_800DA908[], D_800DA920[], D_800DA930[], D_800DA9C8[], D_800DA9E8[], D_800DAA00[];
EXTERN_C const BimVTable10 D_800DA8B8;
EXTERN_C void func_800D73E8_c(void *self, int a, int b, int c, int d, int e, int f) asm("func_800D73E8");
EXTERN_C void func_800DAE34_c(void *self, int a) asm("func_800DAE34");
EXTERN_C void func_800D8D64_c(void *self, int a, int b, int c, int d, int e, int f, int g, int h) asm("func_800D8D64");

EXTERN_C BimDtor *func_800DAB34(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
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
    func_800DAE34_c(self, b);
    func_800D8D64_c(self, 1, 1, 1, 0, 0, 0, 0, 0);
    register BimDtor *r asm("$2") = self;
    *(int *)((char *)r + 0x9D4) = 12;
    r->f9DC = 0;
    r->f9D8 = 1;
    return r;
}

#include "../shared/bimf_a85220b1.cpp"

EXTERN_C void func_800DAE34(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x18E3D;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x18E40;
    *(int *)(p + 0xA08) = 0x6000;
    *(int *)(p + 0xA0C) = 0x18E40;
    *(int *)(p + 0xA10) = 0x6000;
    *(int *)(p + 0xA14) = 0x18E4C;
    *(int *)(p + 0xA18) = 0x5800;
    *(int *)(p + 0xA1C) = 0x18E57;
    *(int *)(p + 0xA20) = 0x6000;
    *(int *)(p + 0xA24) = 0x18E63;
    *(int *)(p + 0xA28) = 0x6000;
    *(int *)(p + 0xA2C) = 0x18E6F;
    *(int *)(p + 0xA30) = 0x5000;
    *(int *)(p + 0xA34) = 0x18E79;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x18E7A;
    *(int *)(p + 0xA40) = 0x800;
    *(int *)(p + 0xA44) = 0x18E7B;
    *(int *)(p + 0xA48) = 0x5800;
    *(int *)(p + 0xA4C) = 0x18E7B;
    *(int *)(p + 0xA50) = 0x5800;
    *(int *)(p + 0xA54) = 0x18E7B;
    *(int *)(p + 0xA58) = 0x5800;
    *(int *)(p + 0xA5C) = 0x18E7B;
    *(int *)(p + 0xA60) = 0x5800;
    *(int *)(p + 0xADC) = 0x18E86;
    *(int *)(p + 0xAE0) = 0x6000;
    *(int *)(p + 0xAE4) = 0x18E92;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DAFD8);

#include "../shared/bimf_dd77db6b.cpp"

EXTERN_C int func_800DB244(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D8E64(p, 3);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
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

#include "../shared/bimf_a1b3cda8.cpp"

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DB36C);

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DB454);

EXTERN_C BimMon *func_800D8464();
EXTERN_C int bimf_af99c5b3_1_c(void *p, int a) asm("bimf_af99c5b3_1");

EXTERN_C int bimf_06b4d1a5(BimMon *p, int a)
{
    BimMon *o = func_800D8464();
    if (o && o != p) {
        if (rand() & 1) {
            if (!p->f9E4)
                return 0;
            if (!bimf_af99c5b3_1_c(p, a)) {
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

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DB724);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DAA00);
