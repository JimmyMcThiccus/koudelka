#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", func_800DAB3C);

#include "../shared/bimf_a85220b1.cpp"

#include "../shared/bimf_dc9f6183.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", bimf_b4ba168f);

INCLUDE_ASM("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", bimf_8b808450);

#include "../shared/bimf_72fa68c8.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_0d32b1e3.cpp"

EXTERN_C int bimf_72fa68c8_c(void *p, unsigned *flags) asm("bimf_72fa68c8");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_0d32b1e3_c(void *p, unsigned *flags) asm("bimf_0d32b1e3");

EXTERN_C int func_800DB4DC(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_72fa68c8_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 2:
        if (bimf_af99c5b3_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 4:
        if (bimf_af99c5b3_1_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3_2_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_0d32b1e3_c(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

#include "../shared/bimf_05e090a7.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", bimf_da437c5e);

INCLUDE_RODATA("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_dacb669c9e/nonmatchings/w0_dacb669c9e", D_800DAA00);
