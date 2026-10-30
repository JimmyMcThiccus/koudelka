// Shared by 2 BIM.AR modules: fill the monster's (id, value) table at +0x9F8 and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_a1bcebde(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x18DEF;
    *(int *)(p + 0x9FC) = 0x800;
    *(int *)(p + 0xA00) = 0x18DF0;
    *(int *)(p + 0xA04) = 0x2800;
    *(int *)(p + 0xA08) = 0x18DEA;
    *(int *)(p + 0xA0C) = 0x2800;
    *(int *)(p + 0xA10) = 0x18DF5;
    *(int *)(p + 0xA14) = 0x2000;
    *(int *)(p + 0xA18) = 0x18DF9;
    *(int *)(p + 0xA1C) = 0x5800;
    *(int *)(p + 0xA20) = 0x18E04;
    *(int *)(p + 0xA24) = 0x4000;
    *(int *)(p + 0xA28) = 0x18E0C;
    *(int *)(p + 0xA2C) = 0x3000;
    *(int *)(p + 0xA30) = 0x18E12;
    *(int *)(p + 0xA34) = 0x800;
    *(int *)(p + 0xA38) = 0x18E13;
    *(int *)(p + 0xA3C) = 0x800;
    *(int *)(p + 0xA40) = 0x18E14;
    *(int *)(p + 0xA44) = 0x4000;
    *(int *)(p + 0xA48) = 0x18E14;
    *(int *)(p + 0xA4C) = 0x4000;
    *(int *)(p + 0xA50) = 0x18E28;
    *(int *)(p + 0xA54) = 0x5800;
    *(int *)(p + 0xA58) = 0x18E1C;
    *(int *)(p + 0xA5C) = 0x6000;
    *(int *)(p + 0xAD8) = 0x18E33;
    *(int *)(p + 0xADC) = 0x4000;
    *(int *)(p + 0xAE0) = 0x18E3B;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
