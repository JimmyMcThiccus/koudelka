#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", func_800DAB3C);

#include "../shared/bimf_a85220b1.cpp"

INCLUDE_ASM("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", func_800DAE34);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", func_800DB028);

INCLUDE_ASM("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", func_800DB104);

EXTERN_C int func_800DB5F4(void *p);

EXTERN_C int func_800DB260(void *p, unsigned *flags)
{
    if (*flags & 2)
        return func_800DB5F4(p) != 0;
    return 0;
}

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

EXTERN_C int func_800D7914_c(void *p, unsigned *flags) asm("func_800D7914");
EXTERN_C int func_800D7A20_c(void *p, unsigned *flags) asm("func_800D7A20");
EXTERN_C int func_800D7A4C_c(void *p, unsigned *flags) asm("func_800D7A4C");
EXTERN_C int func_800D7AC4_c(void *p, unsigned *flags) asm("func_800D7AC4");

EXTERN_C int func_800DB2B0(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7914((BimMon *)p, -1);
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


INCLUDE_ASM("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", func_800DB350);

INCLUDE_ASM("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", func_800DB468);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", func_800DB5F4);

INCLUDE_ASM("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", func_800DB7B4);

INCLUDE_RODATA("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_ab498dac03/nonmatchings/w0_ab498dac03", D_800DAA00);
