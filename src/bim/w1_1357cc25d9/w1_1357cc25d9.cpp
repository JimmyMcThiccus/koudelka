#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DBE5C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DBDE0(int a, short b, int c, int d, int e)
{
    return func_800DBE5C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", func_800DBE5C);

#include "../shared/bimf_ff339051.cpp"

INCLUDE_ASM("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", bimf_b27548ae);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", bimf_2a027d19);

#include "../shared/bimf_dd77db6b.cpp"

#include "../shared/bimf_131b36e3.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a1b3cda8.cpp"

EXTERN_C int bimf_131b36e3_c(void *p, unsigned *flags) asm("bimf_131b36e3");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");

EXTERN_C int func_800DC6F8(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (bimf_131b36e3_c(p, flags)) {
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
        if (bimf_a1b3cda8_c(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

INCLUDE_ASM("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", bimf_e310b46d);

INCLUDE_ASM("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", bimf_06b4d1a5);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_b4962b94.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_RODATA("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", D_800DBBD8);

INCLUDE_RODATA("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", D_800DBC40);

INCLUDE_RODATA("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", D_800DBC50);

INCLUDE_RODATA("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", D_800DBCE8);

INCLUDE_RODATA("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", D_800DBD08);

INCLUDE_RODATA("asm/bim/w1_1357cc25d9/nonmatchings/w1_1357cc25d9", D_800DBD20);
