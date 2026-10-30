#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB34(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAB8(int a, short b, int c, int d, int e)
{
    return func_800DAB34(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", func_800DAB34);

#include "../shared/bimf_a85220b1.cpp"

#include "../shared/bimf_c9eb637c.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", bimf_127a353f);

#include "../shared/bimf_063a8822.cpp"

#include "../shared/bimf_5098c06c.cpp"

#include "../shared/bimf_a1b3cda8.cpp"

EXTERN_C int bimf_063a8822_c(void *p, unsigned *flags) asm("bimf_063a8822");
EXTERN_C int bimf_5098c06c_c(void *p, unsigned *flags) asm("bimf_5098c06c");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");

EXTERN_C int func_800DB31C(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (bimf_063a8822_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 2:
    case 4:
        p->f9F0 = 0;
        break;
    case 8:
        if (bimf_5098c06c_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_a1b3cda8_c(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}


INCLUDE_ASM("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", bimf_bf5e5e80);

EXTERN_C BimMon *func_800D8464();
EXTERN_C int bimf_af99c5b3_c(void *p, int a) asm("bimf_af99c5b3");

EXTERN_C int bimf_06b4d1a5(BimMon *p, int a)
{
    BimMon *o = func_800D8464();
    if (o && o != p) {
        if (rand() & 1) {
            if (!p->f9E4)
                return 0;
            if (!bimf_af99c5b3_c(p, a)) {
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

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_81cee1ab.cpp"

INCLUDE_RODATA("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_0a4e78060a/nonmatchings/w0_0a4e78060a", D_800DAA00);
