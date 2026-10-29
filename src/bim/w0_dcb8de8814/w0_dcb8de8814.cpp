#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB14(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA98(int a, short b, int c, int d, int e)
{
    return func_800DAB14(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DAB14);

#include "../shared/bimf_a9e82488.cpp"

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DAE18);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA86C);

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DAFD4);

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DB148);

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DB2B4);

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DB3B8);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_0d32b1e3.cpp"

EXTERN_C int func_800DB3B8(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_0d32b1e3(void *p, unsigned *flags);

EXTERN_C int func_800DB52C(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (func_800DB3B8(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_0d32b1e3(p, flags)) {
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

INCLUDE_ASM("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", func_800DB654);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA890);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA8F8);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA9A0);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA9C0);

INCLUDE_RODATA("asm/bim/w0_dcb8de8814/nonmatchings/w0_dcb8de8814", D_800DA9D8);
