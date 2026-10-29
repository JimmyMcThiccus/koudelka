#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C(operator new(0xAF8), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", func_800DAB3C);

#include "../shared/bimf_8a9e0866.cpp"

INCLUDE_ASM("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", bimf_9813409c);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", bimf_6d10f24e);

#include "../shared/bimf_dd77db6b.cpp"

#include "../shared/bimf_5663c35c.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_f955403b.cpp"

EXTERN_C int bimf_5663c35c_c(void *p, unsigned *flags) asm("bimf_5663c35c");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_f955403b_c(void *p, unsigned *flags) asm("bimf_f955403b");

EXTERN_C int func_800DB3B4(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (bimf_5663c35c_c(p, flags)) {
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
        if (bimf_f955403b_c(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

INCLUDE_ASM("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", bimf_e310b46d);

INCLUDE_ASM("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", bimf_06b4d1a5);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_b4962b94.cpp"

#include "../shared/bimf_5bce61f8.cpp"

INCLUDE_RODATA("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_62110b0180/nonmatchings/w0_62110b0180", D_800DAA00);
