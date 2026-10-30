// Shared by 3 BIM.AR modules: fill the monster's (id, value) table at +0x9FC and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_57069eeb(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x18EE7;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x18EE7;
    *(int *)(p + 0xA08) = 0x1800;
    *(int *)(p + 0xA0C) = 0x18EE7;
    *(int *)(p + 0xA10) = 0x1800;
    *(int *)(p + 0xA14) = 0x18EEA;
    *(int *)(p + 0xA18) = 0x6000;
    *(int *)(p + 0xA1C) = 0x18EF6;
    *(int *)(p + 0xA20) = 0x5800;
    *(int *)(p + 0xA24) = 0x18F01;
    *(int *)(p + 0xA28) = 0x5800;
    *(int *)(p + 0xA2C) = 0x18F0C;
    *(int *)(p + 0xA30) = 0x6000;
    *(int *)(p + 0xA34) = 0x18F18;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x18F19;
    *(int *)(p + 0xA40) = 0x800;
    *(int *)(p + 0xA44) = 0x18F1A;
    *(int *)(p + 0xA48) = 0x5000;
    *(int *)(p + 0xA4C) = 0x18F1A;
    *(int *)(p + 0xA50) = 0x5000;
    *(int *)(p + 0xA54) = 0x18F24;
    *(int *)(p + 0xA58) = 0x1000;
    *(int *)(p + 0xA5C) = 0x18F29;
    *(int *)(p + 0xA60) = 0x4800;
    *(int *)(p + 0xA64) = 0x18F26;
    *(int *)(p + 0xA68) = 0x800;
    *(int *)(p + 0xA6C) = 0x18F27;
    *(int *)(p + 0xA70) = 0x1000;
    *(int *)(p + 0xA74) = 0x18F29;
    *(int *)(p + 0xA78) = 0x4800;
    *(int *)(p + 0xADC) = 0x18F32;
    *(int *)(p + 0xAE0) = 0x6000;
    *(int *)(p + 0xAE4) = 0x18F3E;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
