// Shared by 2 BIM.AR modules: fill the monster's (id, value) table at +0x9FC and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_9ee8aced(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x18B41;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x18B44;
    *(int *)(p + 0xA08) = 0x5000;
    *(int *)(p + 0xA0C) = 0x18B37;
    *(int *)(p + 0xA10) = 0x5000;
    *(int *)(p + 0xA14) = 0x18B4E;
    *(int *)(p + 0xA18) = 0x2000;
    *(int *)(p + 0xA1C) = 0x18B52;
    *(int *)(p + 0xA20) = 0x4000;
    *(int *)(p + 0xA24) = 0x18B5A;
    *(int *)(p + 0xA28) = 0x4000;
    *(int *)(p + 0xA2C) = 0x18B62;
    *(int *)(p + 0xA30) = 0x1800;
    *(int *)(p + 0xA34) = 0x18B65;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x18B66;
    *(int *)(p + 0xA40) = 0x800;
    *(int *)(p + 0xA44) = 0x18B67;
    *(int *)(p + 0xA48) = 0x4800;
    *(int *)(p + 0xA4C) = 0x18B70;
    *(int *)(p + 0xA50) = 0x7000;
    *(int *)(p + 0xA54) = 0x18B67;
    *(int *)(p + 0xA58) = 0x4800;
    *(int *)(p + 0xADC) = 0x18B7E;
    *(int *)(p + 0xAE0) = 0x4800;
    *(int *)(p + 0xAE4) = 0x18B87;
    *(int *)(p + 0xAE8) = 0x1000;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
