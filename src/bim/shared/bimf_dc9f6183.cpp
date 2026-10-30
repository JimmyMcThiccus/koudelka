// Shared by 2 BIM.AR modules: fill the monster's (id, value) table at +0x9FC and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_dc9f6183(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x18ABF;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x18AC2;
    *(int *)(p + 0xA08) = 0x5800;
    *(int *)(p + 0xA0C) = 0x18AC2;
    *(int *)(p + 0xA10) = 0x5800;
    *(int *)(p + 0xA14) = 0x18ACD;
    *(int *)(p + 0xA18) = 0x6800;
    *(int *)(p + 0xA1C) = 0x18ADA;
    *(int *)(p + 0xA20) = 0x6000;
    *(int *)(p + 0xA24) = 0x18AE6;
    *(int *)(p + 0xA28) = 0x6000;
    *(int *)(p + 0xA2C) = 0x18AF2;
    *(int *)(p + 0xA30) = 0x6000;
    *(int *)(p + 0xA34) = 0x18AFE;
    *(int *)(p + 0xA38) = 0x1000;
    *(int *)(p + 0xA3C) = 0x18B00;
    *(int *)(p + 0xA40) = 0x1800;
    *(int *)(p + 0xA44) = 0x18B03;
    *(int *)(p + 0xA48) = 0x6800;
    *(int *)(p + 0xA4C) = 0x18B10;
    *(int *)(p + 0xA50) = 0x6000;
    *(int *)(p + 0xA54) = 0x18B1C;
    *(int *)(p + 0xA58) = 0x6800;
    *(int *)(p + 0xADC) = 0x18B29;
    *(int *)(p + 0xAE0) = 0x6000;
    *(int *)(p + 0xAE4) = 0x18B35;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
