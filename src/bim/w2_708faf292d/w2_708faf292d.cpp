#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DD17C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DD100(int a, short b, int c, int d, int e)
{
    return func_800DD17C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", func_800DD17C);

#include "../shared/bimf_81250a8a.cpp"

EXTERN_C void func_800DD480(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x19496;
    *(int *)(p + 0xA00) = 0x800;
    *(int *)(p + 0xA04) = 0x19497;
    *(int *)(p + 0xA08) = 0x2000;
    *(int *)(p + 0xA0C) = 0x19494;
    *(int *)(p + 0xA10) = 0x1000;
    *(int *)(p + 0xA14) = 0x1949B;
    *(int *)(p + 0xA18) = 0x3800;
    *(int *)(p + 0xA1C) = 0x194A2;
    *(int *)(p + 0xA20) = 0x5800;
    *(int *)(p + 0xA24) = 0x194AD;
    *(int *)(p + 0xA28) = 0x5800;
    *(int *)(p + 0xA2C) = 0x194B8;
    *(int *)(p + 0xA30) = 0x3000;
    *(int *)(p + 0xA34) = 0x194BE;
    *(int *)(p + 0xA38) = 0x1000;
    *(int *)(p + 0xA3C) = 0x194C0;
    *(int *)(p + 0xA40) = 0x1000;
    *(int *)(p + 0xA44) = 0x194C2;
    *(int *)(p + 0xA48) = 0x3800;
    *(int *)(p + 0xA4C) = 0x194C2;
    *(int *)(p + 0xA50) = 0x3800;
    *(int *)(p + 0xA54) = 0x194C2;
    *(int *)(p + 0xA58) = 0x3800;
    *(int *)(p + 0xA5C) = 0x194C2;
    *(int *)(p + 0xA60) = 0x3800;
    *(int *)(p + 0xA64) = 0x194C2;
    *(int *)(p + 0xA68) = 0x3800;
    *(int *)(p + 0xA6C) = 0x194C9;
    *(int *)(p + 0xA70) = 0x1000;
    *(int *)(p + 0xADC) = 0x194CB;
    *(int *)(p + 0xAE0) = 0x4000;
    *(int *)(p + 0xAE4) = 0x194D3;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", func_800DD668);

INCLUDE_ASM("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", func_800DD7F0);

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

EXTERN_C int func_800DD8C4(void *p, unsigned *flags)
{
    if (*flags & 1) {
        int ret;
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        if (!func_800D8064(p)) {
            void *q = func_800D7A4C(p, 1, 0x21);
            if (q)
                func_800D7AC4(p, q, 1, 0);
            ret = 1;
        } else
            ret = 1;
        *flags &= ~1;
        return ret;
    }
    return 0;
}

EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_af99c5b3_3_c(void *p, unsigned *flags) asm("bimf_af99c5b3_3");
EXTERN_C int func_800DD8C4_c(void *p, unsigned *flags) asm("func_800DD8C4");

EXTERN_C int func_800DD974(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_af99c5b3_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 2:
        if (bimf_af99c5b3_1_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 4:
        if (bimf_af99c5b3_2_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3_3_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (func_800DD8C4_c(p, flags)) {
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

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_6
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", func_800DDAFC);

INCLUDE_ASM("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", func_800DDC2C);

INCLUDE_RODATA("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", D_800DCEF8);

INCLUDE_RODATA("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", D_800DCF48);

INCLUDE_RODATA("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", D_800DCF60);

INCLUDE_RODATA("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", D_800DCF70);

INCLUDE_RODATA("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", D_800DD008);

INCLUDE_RODATA("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", D_800DD028);

INCLUDE_RODATA("asm/bim/w2_708faf292d/nonmatchings/w2_708faf292d", D_800DD040);
