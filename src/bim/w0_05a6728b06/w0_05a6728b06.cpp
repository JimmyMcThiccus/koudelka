#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAAFC(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA80(int a, short b, int c, int d, int e)
{
    return func_800DAAFC(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", func_800DAAFC);

#include "../shared/bimf_77c7ba37.cpp"

EXTERN_C void func_800DADF8(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x19F02;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x19F02;
    *(int *)(p + 0xA08) = 0x1800;
    *(int *)(p + 0xA0C) = 0x19F02;
    *(int *)(p + 0xA10) = 0x1800;
    *(int *)(p + 0xA14) = 0x19F05;
    *(int *)(p + 0xA18) = 0x6800;
    *(int *)(p + 0xA1C) = 0x19F12;
    *(int *)(p + 0xA20) = 0x6000;
    *(int *)(p + 0xA24) = 0x19F12;
    *(int *)(p + 0xA28) = 0x6000;
    *(int *)(p + 0xA2C) = 0x19F1E;
    *(int *)(p + 0xA30) = 0x6000;
    *(int *)(p + 0xA34) = 0x19F2A;
    *(int *)(p + 0xA38) = 0x1000;
    *(int *)(p + 0xA3C) = 0x19F2C;
    *(int *)(p + 0xA40) = 0x1000;
    *(int *)(p + 0xA44) = 0x19F2E;
    *(int *)(p + 0xA48) = 0x6000;
    *(int *)(p + 0xA4C) = 0x19F3A;
    *(int *)(p + 0xA50) = 0x6800;
    *(int *)(p + 0xA54) = 0x19F2E;
    *(int *)(p + 0xA58) = 0x6000;
    *(int *)(p + 0xADC) = 0x19F47;
    *(int *)(p + 0xAE0) = 0x8000;
    *(int *)(p + 0xAE4) = 0x19F57;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", func_800DAF90);

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

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_92c79aea.cpp"

#include "../shared/bimf_db5f4bc4.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_6
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_7
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_8
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", func_800DB0EC);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_05a6728b06/nonmatchings/w0_05a6728b06", D_800DA9C0);
