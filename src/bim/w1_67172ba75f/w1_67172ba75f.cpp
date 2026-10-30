#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DBE0C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DBD90(int a, short b, int c, int d, int e)
{
    return func_800DBE0C(operator new(0xAF0), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", func_800DBE0C);

#include "../shared/bimf_89f158d5.cpp"

EXTERN_C void func_800DC10C(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x19885;
    *(int *)(p + 0x9FC) = 0x800;
    *(int *)(p + 0xA00) = 0x19885;
    *(int *)(p + 0xA04) = 0x800;
    *(int *)(p + 0xA08) = 0x19885;
    *(int *)(p + 0xA0C) = 0x800;
    *(int *)(p + 0xA10) = 0x19886;
    *(int *)(p + 0xA14) = 0x6000;
    *(int *)(p + 0xA18) = 0x19892;
    *(int *)(p + 0xA1C) = 0x6000;
    *(int *)(p + 0xA20) = 0x19892;
    *(int *)(p + 0xA24) = 0x6000;
    *(int *)(p + 0xA28) = 0x1989E;
    *(int *)(p + 0xA2C) = 0x800;
    *(int *)(p + 0xA30) = 0x1989F;
    *(int *)(p + 0xA34) = 0x800;
    *(int *)(p + 0xA38) = 0x198A0;
    *(int *)(p + 0xA3C) = 0x800;
    *(int *)(p + 0xA40) = 0x198A1;
    *(int *)(p + 0xA44) = 0x800;
    *(int *)(p + 0xAD8) = 0x198A2;
    *(int *)(p + 0xADC) = 0x6000;
    *(int *)(p + 0xAE0) = 0x198AE;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", bimf_227b9b39);

#include "../shared/bimf_db5f4bc4.cpp"

INCLUDE_RODATA("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", D_800DBB8C);

INCLUDE_RODATA("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", D_800DBB98);

INCLUDE_RODATA("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", D_800DBBE8);

INCLUDE_RODATA("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", D_800DBC00);

INCLUDE_RODATA("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", D_800DBC10);

INCLUDE_RODATA("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", D_800DBCA8);

INCLUDE_RODATA("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", D_800DBCC8);

INCLUDE_RODATA("asm/bim/w1_67172ba75f/nonmatchings/w1_67172ba75f", D_800DBCE0);
