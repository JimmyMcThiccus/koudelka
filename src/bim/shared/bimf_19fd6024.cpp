// Shared by 2 BIM.AR modules: fill the monster's (id, value) table at +0x9FC and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_19fd6024(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x1905C;
    *(int *)(p + 0xA00) = 0x800;
    *(int *)(p + 0xA04) = 0x1905D;
    *(int *)(p + 0xA08) = 0x1800;
    *(int *)(p + 0xA0C) = 0x19055;
    *(int *)(p + 0xA10) = 0x3800;
    *(int *)(p + 0xA14) = 0x19060;
    *(int *)(p + 0xA18) = 0x5800;
    *(int *)(p + 0xA1C) = 0x1906B;
    *(int *)(p + 0xA20) = 0x5800;
    *(int *)(p + 0xA24) = 0x19076;
    *(int *)(p + 0xA28) = 0x5800;
    *(int *)(p + 0xA2C) = 0x19081;
    *(int *)(p + 0xA30) = 0x5800;
    *(int *)(p + 0xA34) = 0x1908C;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x1908D;
    *(int *)(p + 0xA40) = 0x800;
    *(int *)(p + 0xA44) = 0x1908E;
    *(int *)(p + 0xA48) = 0x800;
    *(int *)(p + 0xA4C) = 0x1908F;
    *(int *)(p + 0xA50) = 0x4000;
    *(int *)(p + 0xADC) = 0x19097;
    *(int *)(p + 0xAE0) = 0x6800;
    *(int *)(p + 0xAE4) = 0x190A4;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
