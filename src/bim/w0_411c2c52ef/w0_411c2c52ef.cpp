#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C(operator new(0xAF8), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", func_800DAB3C);

#include "../shared/bimf_8a9e0866.cpp"

INCLUDE_ASM("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", func_800DAE38);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", func_800DB040);

#include "../shared/bimf_af99c5b3.cpp"

EXTERN_C int func_800DB22C(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0x190, 0x12C, 0x12C, 0, 0, 0, 0, 0);
        int id = func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        if (id == 4)
            return 0;
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            func_800D7D64(p, q);
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

EXTERN_C int func_800D8E64_c(void *p, unsigned *flags) asm("func_800D8E64");
EXTERN_C int func_800D7A20_c(void *p, unsigned *flags) asm("func_800D7A20");
EXTERN_C int func_800D7A4C_c(void *p, unsigned *flags) asm("func_800D7A4C");
EXTERN_C int func_800D7AC4_c(void *p, unsigned *flags) asm("func_800D7AC4");

EXTERN_C int func_800DB318(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x21);
        if (q)
            func_800D7AC4(p, q, 1, 0);
        *flags &= ~1;
        return 1;
    }
    return 0;
}


EXTERN_C int func_800DB22C_c(void *p, unsigned *flags) asm("func_800DB22C");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int bimf_af99c5b3_3_c(void *p, unsigned *flags) asm("bimf_af99c5b3_3");
EXTERN_C int func_800DB318_c(void *p, unsigned *flags) asm("func_800DB318");

EXTERN_C int func_800DB3B8(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (func_800DB22C_c(p, flags)) {
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
        if (func_800DB318_c(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}

INCLUDE_ASM("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", func_800DB4E0);

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_6
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", func_800DB630);

INCLUDE_RODATA("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_411c2c52ef/nonmatchings/w0_411c2c52ef", D_800DAA00);
