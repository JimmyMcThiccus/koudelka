#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAAF4(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA78(int a, short b, int c, int d, int e)
{
    return func_800DAAF4(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", func_800DAAF4);

#include "../shared/bimf_77c7ba37.cpp"

INCLUDE_ASM("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", func_800DADEC);

INCLUDE_ASM("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", func_800DAF84);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_26a6dc91ab/nonmatchings/w0_26a6dc91ab", func_800DB0E4);

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
