#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAAF4(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA78(int a, short b, int c, int d, int e)
{
    return func_800DAAF4(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", func_800DAAF4);

#include "../shared/bimf_77c7ba37.cpp"

EXTERN_C void func_800DADEC(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x19AD8;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x19ADB;
    *(int *)(p + 0xA08) = 0x6800;
    *(int *)(p + 0xA0C) = 0x19ADB;
    *(int *)(p + 0xA10) = 0x6800;
    *(int *)(p + 0xA14) = 0x19AE8;
    *(int *)(p + 0xA18) = 0x4000;
    *(int *)(p + 0xA1C) = 0x19AF0;
    *(int *)(p + 0xA20) = 0x6000;
    *(int *)(p + 0xA24) = 0x19AFC;
    *(int *)(p + 0xA28) = 0x6800;
    *(int *)(p + 0xA2C) = 0x19B09;
    *(int *)(p + 0xA30) = 0x2800;
    *(int *)(p + 0xA34) = 0x19B0E;
    *(int *)(p + 0xA38) = 0x1000;
    *(int *)(p + 0xA3C) = 0x19B10;
    *(int *)(p + 0xA40) = 0x1800;
    *(int *)(p + 0xA44) = 0x19B13;
    *(int *)(p + 0xA48) = 0x5000;
    *(int *)(p + 0xA4C) = 0x19B1D;
    *(int *)(p + 0xA50) = 0x6800;
    *(int *)(p + 0xA54) = 0x19B38;
    *(int *)(p + 0xA58) = 0x1800;
    *(int *)(p + 0xA5C) = 0x19B2A;
    *(int *)(p + 0xA60) = 0x7000;
    *(int *)(p + 0xA64) = 0x19B13;
    *(int *)(p + 0xA68) = 0x5000;
    *(int *)(p + 0xA6C) = 0x19B3B;
    *(int *)(p + 0xA70) = 0x6800;
    *(int *)(p + 0xADC) = 0x19B48;
    *(int *)(p + 0xAE0) = 0xB000;
    *(int *)(p + 0xAE4) = 0x19B5E;
    *(int *)(p + 0xAE8) = 0x1000;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800DB398(void *p, unsigned *flags);
EXTERN_C int bimf_db5f4bc4_c(void *p, unsigned *flags) asm("bimf_db5f4bc4");

EXTERN_C int func_800DAFF8(BimV *p, unsigned *flags)
{
    func_800D7818(p, 0x12C, 0x64, 0x12C, 0x64, 0xC8, 0, 0, 0);
    if (p->v21((int)flags))
        return 1;
    if (func_800DB398(p, flags))
        return 1;
    bimf_db5f4bc4_c(p, flags);
    return 1;
}

INCLUDE_ASM("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", func_800DB098);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_0d32b1e3.cpp"

EXTERN_C int func_800DB098(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_0d32b1e3(void *p, unsigned *flags);

EXTERN_C int func_800DB270(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (func_800DB098(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_0d32b1e3(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

#include "../shared/bimf_db5f4bc4.cpp"

INCLUDE_ASM("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", func_800DB398);

INCLUDE_RODATA("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_bbd62bf3a1/nonmatchings/w0_bbd62bf3a1", D_800DA9C0);
