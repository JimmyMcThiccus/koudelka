#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB34(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAB8(int a, short b, int c, int d, int e)
{
    return func_800DAB34(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", func_800DAB34);

#include "../shared/bimf_a85220b1.cpp"

#include "../shared/bimf_3e5937f3.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", bimf_227ce542);

#include "../shared/bimf_bafe7335.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_9905b8de.cpp"

EXTERN_C int bimf_bafe7335_c(void *p, unsigned *flags) asm("bimf_bafe7335");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_9905b8de_c(void *p, unsigned *flags) asm("bimf_9905b8de");

EXTERN_C int func_800DB328(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_bafe7335_c(p, flags)) {
            *flags &= ~2;
            p->f9F0 = 0;
            return 1;
        }
        break;
    case 2:
    case 4:
        p->f9F0 = 0;
        break;
    case 8:
        if (bimf_af99c5b3_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_9905b8de_c(p, flags)) {
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

EXTERN_C BimMon *func_800D8464();
EXTERN_C int bimf_af99c5b3_1_c(void *p, int a) asm("bimf_af99c5b3_1");

EXTERN_C int bimf_06b4d1a5(BimMon *p, int a)
{
    BimMon *o = func_800D8464();
    if (o && o != p) {
        if (rand() & 1) {
            if (!p->f9E4)
                return 0;
            if (!bimf_af99c5b3_1_c(p, a)) {
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

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", bimf_f35df0eb);

INCLUDE_RODATA("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_e43bb5c67a/nonmatchings/w0_e43bb5c67a", D_800DAA00);
