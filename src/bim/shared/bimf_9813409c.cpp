// Shared by 2 BIM.AR modules: fill the monster's (id, value) table at +0xA00 and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_9813409c(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0xA00) = 0x18BFC;
    *(int *)(p + 0xA04) = 0x2000;
    *(int *)(p + 0xA08) = 0x18C00;
    *(int *)(p + 0xA0C) = 0x5800;
    *(int *)(p + 0xA10) = 0x18BF1;
    *(int *)(p + 0xA14) = 0x5800;
    *(int *)(p + 0xA18) = 0x18C0B;
    *(int *)(p + 0xA1C) = 0x6800;
    *(int *)(p + 0xA20) = 0x18C18;
    *(int *)(p + 0xA24) = 0x7000;
    *(int *)(p + 0xA28) = 0x18C26;
    *(int *)(p + 0xA2C) = 0x7000;
    *(int *)(p + 0xA30) = 0x18C34;
    *(int *)(p + 0xA34) = 0x4000;
    *(int *)(p + 0xA38) = 0x18C3C;
    *(int *)(p + 0xA3C) = 0x800;
    *(int *)(p + 0xA40) = 0x18C3D;
    *(int *)(p + 0xA44) = 0x1800;
    *(int *)(p + 0xA48) = 0x18C40;
    *(int *)(p + 0xA4C) = 0x6000;
    *(int *)(p + 0xA50) = 0x18C4C;
    *(int *)(p + 0xA54) = 0x6000;
    *(int *)(p + 0xA58) = 0x18C40;
    *(int *)(p + 0xA5C) = 0x6000;
    *(int *)(p + 0xA60) = 0x18C58;
    *(int *)(p + 0xA64) = 0x2000;
    *(int *)(p + 0xAE0) = 0x18C5C;
    *(int *)(p + 0xAE4) = 0x8000;
    *(int *)(p + 0xAE8) = 0x18C6C;
    *(int *)(p + 0xAEC) = 0x800;
    int *v = q + 640;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
