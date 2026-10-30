#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAAF4(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA78(int a, short b, int c, int d, int e)
{
    return func_800DAAF4(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", func_800DAAF4);

#include "../shared/bimf_77c7ba37.cpp"

EXTERN_C void func_800DADEC(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x19B68;
    *(int *)(p + 0xA00) = 0x2800;
    *(int *)(p + 0xA04) = 0x19B6D;
    *(int *)(p + 0xA08) = 0x7000;
    *(int *)(p + 0xA0C) = 0x19B61;
    *(int *)(p + 0xA10) = 0x3800;
    *(int *)(p + 0xA14) = 0x19B7B;
    *(int *)(p + 0xA18) = 0x8800;
    *(int *)(p + 0xA1C) = 0x19B8C;
    *(int *)(p + 0xA20) = 0x8800;
    *(int *)(p + 0xA24) = 0x19B9D;
    *(int *)(p + 0xA28) = 0x8800;
    *(int *)(p + 0xA2C) = 0x19BAE;
    *(int *)(p + 0xA30) = 0x7800;
    *(int *)(p + 0xA34) = 0x19BBD;
    *(int *)(p + 0xA38) = 0x1000;
    *(int *)(p + 0xA3C) = 0x19BBF;
    *(int *)(p + 0xA40) = 0x2800;
    *(int *)(p + 0xA44) = 0x19BC4;
    *(int *)(p + 0xA48) = 0xA800;
    *(int *)(p + 0xA4C) = 0x19C03;
    *(int *)(p + 0xA50) = 0x7000;
    *(int *)(p + 0xA54) = 0x19BE8;
    *(int *)(p + 0xA58) = 0x8800;
    *(int *)(p + 0xA5C) = 0x19BD9;
    *(int *)(p + 0xA60) = 0x7800;
    *(int *)(p + 0xA64) = 0x19BC4;
    *(int *)(p + 0xA68) = 0xA800;
    *(int *)(p + 0xA6C) = 0x19BF9;
    *(int *)(p + 0xA70) = 0x2800;
    *(int *)(p + 0xA74) = 0x19BFE;
    *(int *)(p + 0xA78) = 0x2800;
    *(int *)(p + 0xADC) = 0x19C11;
    *(int *)(p + 0xAE0) = 0x8000;
    *(int *)(p + 0xAE4) = 0x19C21;
    *(int *)(p + 0xAE8) = 0x1000;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

EXTERN_C int func_800DAF84(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 0xE);
        func_80082670(p + 0x2A4, 0x11, 0xF);
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
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    }
    return r;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800DB47C(void *p, unsigned *flags);
EXTERN_C int bimf_db5f4bc4_c(void *p, unsigned *flags) asm("bimf_db5f4bc4");

EXTERN_C int func_800DB0E4(BimV *p, unsigned *flags)
{
    func_800D7818(p, 0x12C, 0xC8, 0x12C, 0xC8, 0, 0, 0, 0);
    if (p->v21((int)flags))
        return 1;
    if (func_800DB47C(p, flags))
        return 1;
    bimf_db5f4bc4_c(p, flags);
    return 1;
}

INCLUDE_ASM("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", func_800DB180);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_1393ddd0.cpp"

EXTERN_C int func_800DB180(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_1393ddd0(void *p, unsigned *flags);

EXTERN_C int func_800DB354(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (func_800DB180(p, flags)) {
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
        if (bimf_1393ddd0(p, flags)) {
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

INCLUDE_ASM("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", func_800DB47C);

INCLUDE_RODATA("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", D_800DA9C0);
