// Shared by 3 BIM.AR modules: fill the monster's (id, value) table at +0x9FC and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_17d53c09(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x19228;
    *(int *)(p + 0xA00) = 0x800;
    *(int *)(p + 0xA04) = 0x19229;
    *(int *)(p + 0xA08) = 0x6000;
    *(int *)(p + 0xA0C) = 0x1921C;
    *(int *)(p + 0xA10) = 0x6000;
    *(int *)(p + 0xA14) = 0x19235;
    *(int *)(p + 0xA18) = 0x1000;
    *(int *)(p + 0xA1C) = 0x19237;
    *(int *)(p + 0xA20) = 0x6000;
    *(int *)(p + 0xA24) = 0x19243;
    *(int *)(p + 0xA28) = 0x6000;
    *(int *)(p + 0xA2C) = 0x1924F;
    *(int *)(p + 0xA30) = 0x1800;
    *(int *)(p + 0xA34) = 0x19252;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x19253;
    *(int *)(p + 0xA40) = 0x800;
    *(int *)(p + 0xA44) = 0x19254;
    *(int *)(p + 0xA48) = 0x800;
    *(int *)(p + 0xA4C) = 0x19255;
    *(int *)(p + 0xA50) = 0x5800;
    *(int *)(p + 0xADC) = 0x19260;
    *(int *)(p + 0xAE0) = 0x6000;
    *(int *)(p + 0xAE4) = 0x1926C;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
