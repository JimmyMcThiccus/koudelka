#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB34(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAB8(int a, short b, int c, int d, int e)
{
    return func_800DAB34(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DAB34);

#include "../shared/bimf_a85220b1.cpp"

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DAE34);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DAFD8);

#include "../shared/bimf_dd77db6b.cpp"

EXTERN_C int func_800DB244(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D8E64(p, 3);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            func_800D7D64(p, q);
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_a1b3cda8.cpp"

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DB36C);

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DB454);

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

INCLUDE_ASM("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", func_800DB724);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_1dc69df650/nonmatchings/w0_1dc69df650", D_800DAA00);
