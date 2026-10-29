#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C(operator new(0xAF8), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", func_800DAB3C);

#include "../shared/bimf_8a9e0866.cpp"

INCLUDE_ASM("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", func_800DAE40);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", func_800DB028);

INCLUDE_ASM("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", func_800DB1A0);

#include "../shared/bimf_131b36e3.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

EXTERN_C int func_800DB368(void *p, unsigned *flags)
{
    if (*flags & 1) {
        int ret;
        if (!func_800D8064(p)) {
            func_800D7A20(p, 0);
            void *q = func_800D7A4C(p, 1, 0x21);
            if (!q)
                return 0;
            func_800D7AC4(p, q, 1, 0);
            ret = 1;
        } else
            ret = 1;
        *flags &= ~1;
        return ret;
    }
    return 0;
}

EXTERN_C int bimf_131b36e3_c(void *p, unsigned *flags) asm("bimf_131b36e3");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int func_800DB368_c(void *p, unsigned *flags) asm("func_800DB368");

EXTERN_C int func_800DB404(BimMon *p, unsigned *flags)
{
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
        if (func_800DB368_c(p, flags)) {
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

EXTERN_C BimMon *func_800D8464();
EXTERN_C int bimf_af99c5b3_3_c(void *p, int a) asm("bimf_af99c5b3_3");

EXTERN_C int bimf_06b4d1a5(BimMon *p, int a)
{
    BimMon *o = func_800D8464();
    if (o && o != p) {
        if (rand() & 1) {
            if (!p->f9E4)
                return 0;
            if (!bimf_af99c5b3_3_c(p, a)) {
                if (p)
                    return 0;
                else
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    if (p->f9E8 && (rand() & 7) == 7)
        p->f9EC = 1;
    return 0;
}

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", func_800DB634);

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_RODATA("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_2966c8e7b8/nonmatchings/w0_2966c8e7b8", D_800DAA00);
