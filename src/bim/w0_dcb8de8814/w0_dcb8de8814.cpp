#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB14(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA98(int a, short b, int c, int d, int e)
{
    return func_800DAB14(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DAB14);

#include "../shared/bimf_a9e82488.cpp"

EXTERN_C void func_800DAE18(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x1A0B5;
    *(int *)(p + 0xA00) = 0x3000;
    *(int *)(p + 0xA04) = 0x1A0BB;
    *(int *)(p + 0xA08) = 0x7000;
    *(int *)(p + 0xA0C) = 0x1A0A7;
    *(int *)(p + 0xA10) = 0x7000;
    *(int *)(p + 0xA14) = 0x1A0C9;
    *(int *)(p + 0xA18) = 0x7000;
    *(int *)(p + 0xA1C) = 0x1A0D7;
    *(int *)(p + 0xA20) = 0x8000;
    *(int *)(p + 0xA24) = 0x1A0E7;
    *(int *)(p + 0xA28) = 0x8800;
    *(int *)(p + 0xA2C) = 0x1A0F8;
    *(int *)(p + 0xA30) = 0x4000;
    *(int *)(p + 0xA34) = 0x1A100;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x1A101;
    *(int *)(p + 0xA40) = 0x1000;
    *(int *)(p + 0xA44) = 0x1A103;
    *(int *)(p + 0xA48) = 0x9000;
    *(int *)(p + 0xA4C) = 0x1A135;
    *(int *)(p + 0xA50) = 0x5800;
    *(int *)(p + 0xA54) = 0x1A115;
    *(int *)(p + 0xA58) = 0x7000;
    *(int *)(p + 0xA5C) = 0x1A123;
    *(int *)(p + 0xA60) = 0x7000;
    *(int *)(p + 0xA64) = 0x1A103;
    *(int *)(p + 0xA68) = 0x9000;
    *(int *)(p + 0xA6C) = 0x1A140;
    *(int *)(p + 0xA70) = 0x9800;
    *(int *)(p + 0xA74) = 0x1A103;
    *(int *)(p + 0xA78) = 0x9000;
    *(int *)(p + 0xA7C) = 0x1A131;
    *(int *)(p + 0xA80) = 0x1000;
    *(int *)(p + 0xA84) = 0x1A133;
    *(int *)(p + 0xA88) = 0x1000;
    *(int *)(p + 0xADC) = 0x1A153;
    *(int *)(p + 0xAE0) = 0xD000;
    *(int *)(p + 0xAE4) = 0x1A16D;
    *(int *)(p + 0xAE8) = 0x800;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

EXTERN_C int func_800DAFD4(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 0x10);
        func_80082670(p + 0x2A4, 0x11, 0x11);
        break;
    case 5:
        func_80082670(p + 0x2A4, 0x10, 0x10);
        func_80082670(p + 0x2A4, 0x11, 0x11);
        break;
    case 2:
    case 3:
    case 4:
    case 6:
        func_80082670(p + 0x2A4, 0x10, 0x7);
        func_80082670(p + 0x2A4, 0x11, 0x8);
        break;
    }
    return r;
}

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DB148);

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DB2B4);

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DB3B8);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_0d32b1e3.cpp"

EXTERN_C int func_800DB3B8(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_0d32b1e3(void *p, unsigned *flags);

EXTERN_C int func_800DB52C(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (func_800DB3B8(p, flags)) {
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

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DB654);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA890);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA8F8);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA9A0);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA9C0);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA9D8);
