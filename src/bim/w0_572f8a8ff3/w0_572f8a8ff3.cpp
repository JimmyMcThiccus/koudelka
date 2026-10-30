#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", func_800DAB3C);

#include "../shared/bimf_a85220b1.cpp"

#include "../shared/bimf_539de782.cpp"

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", bimf_85fa9335);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_cba85eee.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_4379dd60.cpp"

EXTERN_C int bimf_cba85eee_c(void *p, unsigned *flags) asm("bimf_cba85eee");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_af99c5b3_3_c(void *p, unsigned *flags) asm("bimf_af99c5b3_3");
EXTERN_C int bimf_4379dd60_c(void *p, unsigned *flags) asm("bimf_4379dd60");

EXTERN_C int func_800DB2E4(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_cba85eee_c(p, flags)) {
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
        if (bimf_4379dd60_c(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

#include "../shared/bimf_6eb48601.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_6
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", bimf_a4898870);

#define bimf_af99c5b3 bimf_af99c5b3_7
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_8
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_RODATA("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_572f8a8ff3/nonmatchings/w0_572f8a8ff3", D_800DAA00);
