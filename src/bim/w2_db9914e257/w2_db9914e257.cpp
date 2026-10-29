#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DD17C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DD100(int a, short b, int c, int d, int e)
{
    return func_800DD17C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", func_800DD17C);

#include "../shared/bimf_81250a8a.cpp"

INCLUDE_ASM("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", bimf_ac9e0f11);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", bimf_1d1122f5);

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

EXTERN_C int func_800DD9EC(BimMon *p, unsigned *flags)
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

INCLUDE_ASM("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", bimf_9b3b5928);

INCLUDE_ASM("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", bimf_06b4d1a5);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a6f0c006.cpp"

INCLUDE_RODATA("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", D_800DCEF8);

INCLUDE_RODATA("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", D_800DCF48);

INCLUDE_RODATA("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", D_800DCF60);

INCLUDE_RODATA("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", D_800DCF70);

INCLUDE_RODATA("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", D_800DD008);

INCLUDE_RODATA("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", D_800DD028);

INCLUDE_RODATA("asm/bim/w2_db9914e257/nonmatchings/w2_db9914e257", D_800DD040);
