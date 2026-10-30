#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB3C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC0(int a, short b, int c, int d, int e)
{
    return func_800DAB3C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_600ddbde1a/nonmatchings/w0_600ddbde1a", func_800DAB3C);

#include "../shared/bimf_a85220b1.cpp"

EXTERN_C void func_800DAE38(char *p, int slot)
{
    int *q = (int *)p;
    int s = (short)slot;
    char **b = D_800B4D38;
    *(int *)(p + 0x9FC) = 0x195E2;
    *(int *)(p + 0xA00) = 0x1800;
    *(int *)(p + 0xA04) = 0x195E5;
    *(int *)(p + 0xA08) = 0x3800;
    *(int *)(p + 0xA0C) = 0x195E5;
    *(int *)(p + 0xA10) = 0x3800;
    *(int *)(p + 0xA14) = 0x195EC;
    *(int *)(p + 0xA18) = 0x6000;
    *(int *)(p + 0xA1C) = 0x195F8;
    *(int *)(p + 0xA20) = 0x5800;
    *(int *)(p + 0xA24) = 0x19603;
    *(int *)(p + 0xA28) = 0x6800;
    *(int *)(p + 0xA2C) = 0x19610;
    *(int *)(p + 0xA30) = 0x4800;
    *(int *)(p + 0xA34) = 0x19619;
    *(int *)(p + 0xA38) = 0x800;
    *(int *)(p + 0xA3C) = 0x1961A;
    *(int *)(p + 0xA40) = 0x2000;
    *(int *)(p + 0xA44) = 0x1961E;
    *(int *)(p + 0xA48) = 0x3800;
    *(int *)(p + 0xA4C) = 0x19625;
    *(int *)(p + 0xA50) = 0x6000;
    *(int *)(p + 0xADC) = 0x19631;
    *(int *)(p + 0xAE0) = 0x8800;
    *(int *)(p + 0xAE4) = 0x19642;
    *(int *)(p + 0xAE8) = 0x1000;
    int *v = q + 639;
    int **t = (int **)(*b + 0xF8);
    t[s] = v;
}

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_131b36e3_c(void *p, unsigned *flags) asm("bimf_131b36e3");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");
EXTERN_C int bimf_b4962b94_c(void *p, unsigned *flags) asm("bimf_b4962b94");
EXTERN_C int bimf_dd77db6b_c(void *p, unsigned *flags) asm("bimf_dd77db6b");
EXTERN_C int bimf_e310b46d_c(void *p, unsigned *flags) asm("bimf_e310b46d");

EXTERN_C int bimf_29503d9b(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 1000, 0, 0, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_131b36e3_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_a1b3cda8_c(p, flags))
                return 1;
        }
    }
    if (bimf_b4962b94_c(p, flags))
        return 1;
    if (bimf_dd77db6b_c(p, flags)) {
        if (p || flags)
            return 1;
        else
            return 1;
    }
    return bimf_e310b46d_c(p, flags);
}

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
