#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", func_800DAB3C);

#include "../shared/bimf_a85220b1.cpp"

INCLUDE_ASM("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", func_800DAE38);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", bimf_29503d9b);

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

EXTERN_C int bimf_131b36e3(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_1(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_2(void *p, unsigned *flags);
EXTERN_C int bimf_a1b3cda8(void *p, unsigned *flags);

EXTERN_C int func_800DB3B8(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (!bimf_131b36e3(p, flags))
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

INCLUDE_ASM("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", bimf_e310b46d);

INCLUDE_ASM("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", bimf_06b4d1a5);

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

INCLUDE_RODATA("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", D_800DAA00);
