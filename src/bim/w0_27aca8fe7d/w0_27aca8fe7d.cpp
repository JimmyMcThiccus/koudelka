#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB0C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA90(int a, short b, int c, int d, int e)
{
    return func_800DAB0C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", func_800DAB0C);

#include "../shared/bimf_a9e82488.cpp"

INCLUDE_ASM("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", func_800DAE0C);

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", func_800DAFF4);

#include "../shared/bimf_cba85eee.cpp"

#include "../shared/bimf_af99c5b3.cpp"

EXTERN_C int func_800DB204(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x21);
        if (!q)
            return 0;
        if (func_800D8064(p)) {
            *flags &= ~1;
            return 1;
        }
    }
    return 0;
}

EXTERN_C int bimf_cba85eee(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int func_800DB204(void *p, unsigned *flags);

EXTERN_C int func_800DB2A0(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_cba85eee(p, flags)) {
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
        if (func_800DB204(p, flags)) {
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

INCLUDE_ASM("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", func_800DB3C8);

INCLUDE_ASM("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", func_800DB5F0);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA890);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA8F8);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA9A0);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA9C0);

INCLUDE_RODATA("asm/bim/w0_27aca8fe7d/nonmatchings/w0_27aca8fe7d", D_800DA9D8);
