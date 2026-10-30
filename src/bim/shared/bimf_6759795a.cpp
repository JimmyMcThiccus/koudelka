// Shared by 2 BIM.AR modules: fill the monster's (id, value) table at +0x9FC and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_6759795a(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x189DE;
    *(int *)(p + 0xA00) = 0x800;
    *(int *)(p + 0xA04) = 0x189DF;
    *(int *)(p + 0xA08) = 0x3000;
    *(int *)(p + 0xA0C) = 0x189DF;
    *(int *)(p + 0xA10) = 0x3000;
    *(int *)(p + 0xA14) = 0x189E5;
    *(int *)(p + 0xA18) = 0x3000;
    *(int *)(p + 0xA1C) = 0x189EB;
    *(int *)(p + 0xA20) = 0x3800;
    *(int *)(p + 0xA24) = 0x189F2;
    *(int *)(p + 0xA28) = 0x3800;
    *(int *)(p + 0xA2C) = 0x189F9;
    *(int *)(p + 0xA30) = 0x2000;
    *(int *)(p + 0xA34) = 0x189FD;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x189FE;
    *(int *)(p + 0xA40) = 0x1000;
    *(int *)(p + 0xA44) = 0x18A00;
    *(int *)(p + 0xA48) = 0x4800;
    *(int *)(p + 0xA4C) = 0x18A09;
    *(int *)(p + 0xA50) = 0x2800;
    *(int *)(p + 0xADC) = 0x18A0E;
    *(int *)(p + 0xAE0) = 0x2800;
    *(int *)(p + 0xAE4) = 0x18A13;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
