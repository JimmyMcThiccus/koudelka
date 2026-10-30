// Shared by 3 BIM.AR modules: fill the monster's (id, value) table at +0x9F8 and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_2f8bc8bf(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x193BA;
    *(int *)(p + 0x9FC) = 0x1800;
    *(int *)(p + 0xA00) = 0x193BA;
    *(int *)(p + 0xA04) = 0x1800;
    *(int *)(p + 0xA08) = 0x193BA;
    *(int *)(p + 0xA0C) = 0x1800;
    *(int *)(p + 0xA10) = 0x193BD;
    *(int *)(p + 0xA14) = 0x6800;
    *(int *)(p + 0xA18) = 0x193CA;
    *(int *)(p + 0xA1C) = 0x3800;
    *(int *)(p + 0xA20) = 0x193D1;
    *(int *)(p + 0xA24) = 0x5800;
    *(int *)(p + 0xA28) = 0x193DC;
    *(int *)(p + 0xA2C) = 0x2000;
    *(int *)(p + 0xA30) = 0x193E0;
    *(int *)(p + 0xA34) = 0x800;
    *(int *)(p + 0xA38) = 0x193E1;
    *(int *)(p + 0xA3C) = 0x1800;
    *(int *)(p + 0xA40) = 0x193E4;
    *(int *)(p + 0xA44) = 0x4800;
    *(int *)(p + 0xA48) = 0x193E4;
    *(int *)(p + 0xA4C) = 0x4800;
    *(int *)(p + 0xA50) = 0x193E4;
    *(int *)(p + 0xA54) = 0x4800;
    *(int *)(p + 0xA58) = 0x193FB;
    *(int *)(p + 0xA5C) = 0x2000;
    *(int *)(p + 0xA60) = 0x193EE;
    *(int *)(p + 0xA64) = 0x800;
    *(int *)(p + 0xA68) = 0x193ED;
    *(int *)(p + 0xA6C) = 0x800;
    *(int *)(p + 0xA70) = 0x193EF;
    *(int *)(p + 0xA74) = 0x4800;
    *(int *)(p + 0xA78) = 0x193F8;
    *(int *)(p + 0xA7C) = 0x1000;
    *(int *)(p + 0xA80) = 0x193FA;
    *(int *)(p + 0xA84) = 0x800;
    *(int *)(p + 0xAD8) = 0x193FF;
    *(int *)(p + 0xADC) = 0x3800;
    *(int *)(p + 0xAE0) = 0x19406;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
