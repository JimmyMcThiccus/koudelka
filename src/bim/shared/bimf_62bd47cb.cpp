// Shared by 3 BIM.AR modules: fill the monster's (id, value) table at +0x9F8 and register it as entry `slot` of D_800B4D38[0]'s table at +0xF8.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_62bd47cb(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x19F59;
    *(int *)(p + 0x9FC) = 0x1000;
    *(int *)(p + 0xA00) = 0x19FAB;
    *(int *)(p + 0xA04) = 0x4000;
    *(int *)(p + 0xA08) = 0x19FB3;
    *(int *)(p + 0xA0C) = 0x5800;
    *(int *)(p + 0xA10) = 0x19F5B;
    *(int *)(p + 0xA14) = 0x5000;
    *(int *)(p + 0xA18) = 0x19F65;
    *(int *)(p + 0xA1C) = 0x6000;
    *(int *)(p + 0xA20) = 0x19F71;
    *(int *)(p + 0xA24) = 0x6000;
    *(int *)(p + 0xA28) = 0x19F7D;
    *(int *)(p + 0xA2C) = 0x5000;
    *(int *)(p + 0xA30) = 0x19F87;
    *(int *)(p + 0xA34) = 0x800;
    *(int *)(p + 0xA38) = 0x19F88;
    *(int *)(p + 0xA3C) = 0x800;
    *(int *)(p + 0xA40) = 0x19F89;
    *(int *)(p + 0xA44) = 0x4800;
    *(int *)(p + 0xA48) = 0x19F92;
    *(int *)(p + 0xA4C) = 0x6000;
    *(int *)(p + 0xA50) = 0x19F9E;
    *(int *)(p + 0xA54) = 0x6800;
    *(int *)(p + 0xA58) = 0x19F89;
    *(int *)(p + 0xA5C) = 0x4800;
    *(int *)(p + 0xA60) = 0x19FAB;
    *(int *)(p + 0xA64) = 0x4000;
    *(int *)(p + 0xA68) = 0x19FB3;
    *(int *)(p + 0xA6C) = 0x5800;
    *(int *)(p + 0xAD8) = 0x19FBE;
    *(int *)(p + 0xADC) = 0x6000;
    *(int *)(p + 0xAE0) = 0x19FCA;
    *(int *)(p + 0xAE4) = 0x800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}
