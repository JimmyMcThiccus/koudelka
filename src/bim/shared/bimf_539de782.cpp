// Shared by 2 BIM.AR modules: fill the monster's (id, value) table at +0x9FC and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_539de782(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x18A15;
    *(int *)(p + 0xA00) = 0x1000;
    *(int *)(p + 0xA04) = 0x18A17;
    *(int *)(p + 0xA08) = 0x3000;
    *(int *)(p + 0xA0C) = 0x18A17;
    *(int *)(p + 0xA10) = 0x3000;
    *(int *)(p + 0xA14) = 0x18A1D;
    *(int *)(p + 0xA18) = 0x3000;
    *(int *)(p + 0xA1C) = 0x18A23;
    *(int *)(p + 0xA20) = 0x3000;
    *(int *)(p + 0xA24) = 0x18A29;
    *(int *)(p + 0xA28) = 0x3000;
    *(int *)(p + 0xA2C) = 0x18A2F;
    *(int *)(p + 0xA30) = 0x2000;
    *(int *)(p + 0xA34) = 0x18A33;
    *(int *)(p + 0xA38) = 0x1000;
    *(int *)(p + 0xA3C) = 0x18A35;
    *(int *)(p + 0xA40) = 0x800;
    *(int *)(p + 0xA44) = 0x18A36;
    *(int *)(p + 0xA48) = 0x7000;
    *(int *)(p + 0xA4C) = 0x18A44;
    *(int *)(p + 0xA50) = 0x4800;
    *(int *)(p + 0xA54) = 0x18A36;
    *(int *)(p + 0xA58) = 0x7000;
    *(int *)(p + 0xA5C) = 0x18A4D;
    *(int *)(p + 0xA60) = 0x4800;
    *(int *)(p + 0xA64) = 0x18A56;
    *(int *)(p + 0xA68) = 0x2000;
    *(int *)(p + 0xADC) = 0x18A5A;
    *(int *)(p + 0xAE0) = 0x3000;
    *(int *)(p + 0xAE4) = 0x18A60;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
