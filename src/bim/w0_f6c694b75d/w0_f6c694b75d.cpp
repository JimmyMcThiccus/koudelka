#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAAFC(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA80(int a, short b, int c, int d, int e)
{
    return func_800DAAFC(operator new(0xAF0), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DAAFC);

#include "../shared/bimf_3dafacd3.cpp"

EXTERN_C void func_800DADF4(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9F8) = 0x19977;
    *(int *)(p + 0x9FC) = 0x2800;
    *(int *)(p + 0xA00) = 0x1997C;
    *(int *)(p + 0xA04) = 0x7800;
    *(int *)(p + 0xA08) = 0x19969;
    *(int *)(p + 0xA0C) = 0x7000;
    *(int *)(p + 0xA10) = 0x1998B;
    *(int *)(p + 0xA14) = 0x6000;
    *(int *)(p + 0xA18) = 0x19997;
    *(int *)(p + 0xA1C) = 0x5000;
    *(int *)(p + 0xA20) = 0x199A1;
    *(int *)(p + 0xA24) = 0x5000;
    *(int *)(p + 0xA28) = 0x199AB;
    *(int *)(p + 0xA2C) = 0x3000;
    *(int *)(p + 0xA30) = 0x199B1;
    *(int *)(p + 0xA34) = 0x1800;
    *(int *)(p + 0xA38) = 0x199B4;
    *(int *)(p + 0xA3C) = 0x1000;
    *(int *)(p + 0xA40) = 0x199B6;
    *(int *)(p + 0xA44) = 0x5800;
    *(int *)(p + 0xA48) = 0x199C1;
    *(int *)(p + 0xA4C) = 0x4800;
    *(int *)(p + 0xA50) = 0x199CA;
    *(int *)(p + 0xA54) = 0x6000;
    *(int *)(p + 0xA58) = 0x199B6;
    *(int *)(p + 0xA5C) = 0x5800;
    *(int *)(p + 0xA60) = 0x199E0;
    *(int *)(p + 0xA64) = 0x5800;
    *(int *)(p + 0xA68) = 0x199D6;
    *(int *)(p + 0xA6C) = 0x1800;
    *(int *)(p + 0xA70) = 0x199D9;
    *(int *)(p + 0xA74) = 0x3800;
    *(int *)(p + 0xAD8) = 0x199EB;
    *(int *)(p + 0xADC) = 0x5800;
    *(int *)(p + 0xAE0) = 0x199F6;
    *(int *)(p + 0xAE4) = 0x1800;
    int *v = q + 638;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

EXTERN_C int func_800DAF88(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 2:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 3:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 4:
        func_80082670(p + 0x2A4, 0x10, 0xE);
        func_80082670(p + 0x2A4, 0x11, 0xF);
        break;
    }
    return r;
}

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB134);

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB1E8);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_0d32b1e3.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB398);

#include "../shared/bimf_05e090a7.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB4D4);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA9C0);
