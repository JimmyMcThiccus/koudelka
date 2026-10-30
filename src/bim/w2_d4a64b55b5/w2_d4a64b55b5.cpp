#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DD12C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DD0B0(int a, short b, int c, int d, int e)
{
    return func_800DD12C(operator new(0xAF0), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", func_800DD12C);

EXTERN_C const BimVTable10 D_800DCEB8;
EXTERN_C char D_800DCF08[], D_800DCF20[], D_800DCF30[], D_800DCFC8[], D_800DCFE8[], D_800DD000[];

EXTERN_C void func_800DD2E8(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DCFE8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DCFC8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DCF30;
    self->vt4A8 = D_800DCF20;
    self->vt980 = D_800DCF08;
    self->vt0 = D_800DD000;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DCEB8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DCEB8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DCEB8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAE8));
        vt.e[6].delta = D_800DCEB8.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

EXTERN_C void func_800DD42C(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x198B0;
    *(int *)(p + 0x9FC) = 0x800;
    *(int *)(p + 0xA00) = 0x198B0;
    *(int *)(p + 0xA04) = 0x800;
    *(int *)(p + 0xA08) = 0x198B0;
    *(int *)(p + 0xA0C) = 0x800;
    *(int *)(p + 0xA10) = 0x198B1;
    *(int *)(p + 0xA14) = 0x6000;
    *(int *)(p + 0xA18) = 0x198BD;
    *(int *)(p + 0xA1C) = 0x6000;
    *(int *)(p + 0xA20) = 0x198BD;
    *(int *)(p + 0xA24) = 0x6000;
    *(int *)(p + 0xA28) = 0x198C9;
    *(int *)(p + 0xA2C) = 0x800;
    *(int *)(p + 0xA30) = 0x198CA;
    *(int *)(p + 0xA34) = 0x800;
    *(int *)(p + 0xA38) = 0x198CB;
    *(int *)(p + 0xA3C) = 0x800;
    *(int *)(p + 0xA40) = 0x198CC;
    *(int *)(p + 0xA44) = 0x800;
    *(int *)(p + 0xAD8) = 0x198CD;
    *(int *)(p + 0xADC) = 0x6000;
    *(int *)(p + 0xAE0) = 0x198D9;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", bimf_227b9b39);

#include "../shared/bimf_db5f4bc4.cpp"

INCLUDE_RODATA("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", D_800DCEAC);

INCLUDE_RODATA("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", D_800DCEB8);

INCLUDE_RODATA("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", D_800DCF08);

INCLUDE_RODATA("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", D_800DCF20);

INCLUDE_RODATA("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", D_800DCF30);

INCLUDE_RODATA("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", D_800DCFC8);

INCLUDE_RODATA("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", D_800DCFE8);

INCLUDE_RODATA("asm/bim/w2_d4a64b55b5/nonmatchings/w2_d4a64b55b5", D_800DD000);
