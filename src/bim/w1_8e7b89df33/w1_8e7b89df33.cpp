#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DBE5C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DBDE0(int a, short b, int c, int d, int e)
{
    return func_800DBE5C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", func_800DBE5C);

#include "../shared/bimf_ff339051.cpp"

INCLUDE_ASM("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", bimf_2b913bf0);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", bimf_cb8fde67);

#include "../shared/bimf_0ae2aad9.cpp"

#include "../shared/bimf_5663c35c.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a1b3cda8.cpp"

EXTERN_C int bimf_5663c35c(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_1(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_2(void *p, unsigned *flags);
EXTERN_C int bimf_a1b3cda8(void *p, unsigned *flags);

EXTERN_C int func_800DC6D8(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (!bimf_5663c35c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 2:
        if (!bimf_af99c5b3(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 4:
        if (!bimf_af99c5b3_1(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 8:
        if (!bimf_af99c5b3_2(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~1;
        return 1;
    case 16:
        if (!bimf_a1b3cda8(p, flags))
            return 0;
        p->f9F0 = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", bimf_9b3b5928);

INCLUDE_ASM("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", bimf_06b4d1a5);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a6f0c006.cpp"

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBBD8);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBC40);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBC50);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBCE8);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBD08);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBD20);
