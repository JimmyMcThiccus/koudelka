#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DBE54(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DBDD8(int a, short b, int c, int d, int e)
{
    return func_800DBE54(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", func_800DBE54);

#include "../shared/bimf_ff339051.cpp"

#include "../shared/bimf_62bd47cb.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", bimf_b1674f83);

#include "../shared/bimf_3655787d.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_1393ddd0.cpp"

EXTERN_C int bimf_3655787d_c(void *p, unsigned *flags) asm("bimf_3655787d");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_1393ddd0_c(void *p, unsigned *flags) asm("bimf_1393ddd0");

EXTERN_C int func_800DC590(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (!bimf_3655787d_c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 2:
    case 4:
        p->f9F0 = 0;
        return 0;
    case 8:
        if (!bimf_af99c5b3_c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~1;
        return 1;
    case 16:
        if (!bimf_1393ddd0_c(p, flags))
            return 0;
        p->f9F0 = 0;
        return 1;
    }
    return 0;
}


#include "../shared/bimf_6eb48601.cpp"

INCLUDE_ASM("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", bimf_51caf7a0);

#include "../shared/bimf_ad7de1b4.cpp"

INCLUDE_RODATA("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", D_800DBBD8);

INCLUDE_RODATA("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", D_800DBC40);

INCLUDE_RODATA("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", D_800DBC50);

INCLUDE_RODATA("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", D_800DBCE8);

INCLUDE_RODATA("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", D_800DBD08);

INCLUDE_RODATA("asm/bim/w1_fd11d6f236/nonmatchings/w1_fd11d6f236", D_800DBD20);
