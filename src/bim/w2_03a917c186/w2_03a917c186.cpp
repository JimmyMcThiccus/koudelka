#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DD184(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DD108(int a, short b, int c, int d, int e)
{
    return func_800DD184(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", func_800DD184);

#include "../shared/bimf_81250a8a.cpp"

INCLUDE_ASM("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", bimf_57069eeb);

#include "../shared/bimf_374ba601.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", bimf_dbec461b);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_eb1719f4.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_22b1759c.cpp"

EXTERN_C int bimf_eb1719f4_c(void *p, unsigned *flags) asm("bimf_eb1719f4");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_af99c5b3_3_c(void *p, unsigned *flags) asm("bimf_af99c5b3_3");
EXTERN_C int bimf_22b1759c_c(void *p, unsigned *flags) asm("bimf_22b1759c");

EXTERN_C int func_800DDABC(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_eb1719f4_c(p, flags)) {
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
        if (bimf_22b1759c_c(p, flags)) {
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

INCLUDE_ASM("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", bimf_06b4d1a5);

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", bimf_05f10258);

#include "../shared/bimf_0df9734b.cpp"

INCLUDE_RODATA("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", D_800DCEF8);

INCLUDE_RODATA("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", D_800DCF48);

INCLUDE_RODATA("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", D_800DCF60);

INCLUDE_RODATA("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", D_800DCF70);

INCLUDE_RODATA("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", D_800DD008);

INCLUDE_RODATA("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", D_800DD028);

INCLUDE_RODATA("asm/bim/w2_03a917c186/nonmatchings/w2_03a917c186", D_800DD040);
