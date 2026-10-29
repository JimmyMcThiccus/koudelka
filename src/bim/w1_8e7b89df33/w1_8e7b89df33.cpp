#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DBE5C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DBDE0(int a, short b, int c, int d, int e)
{
    return func_800DBE5C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", func_800DBE5C);

#include "../shared/bimf_ff339051.cpp"

INCLUDE_ASM("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", bimf_2b913bf0);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_5663c35c_c(void *p, unsigned *flags) asm("bimf_5663c35c");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");
EXTERN_C int bimf_a6f0c006_c(void *p, unsigned *flags) asm("bimf_a6f0c006");
EXTERN_C int bimf_0ae2aad9_c(void *p, unsigned *flags) asm("bimf_0ae2aad9");
EXTERN_C int bimf_9b3b5928_c(void *p, unsigned *flags) asm("bimf_9b3b5928");

EXTERN_C int bimf_cb8fde67(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 700, 300, 0, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_5663c35c_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_a1b3cda8_c(p, flags))
                return 1;
        }
    }
    if (bimf_a6f0c006_c(p, flags))
        return 1;
    if (bimf_0ae2aad9_c(p, flags)) {
        if (p || flags)
            return 1;
        else
            return 1;
    }
    return bimf_9b3b5928_c(p, flags);
}

#include "../shared/bimf_0ae2aad9.cpp"

#include "../shared/bimf_5663c35c.cpp"

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_a1b3cda8.cpp"

EXTERN_C int bimf_5663c35c(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_1(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3_2(void *p, unsigned *flags);
EXTERN_C int bimf_a1b3cda8(void *p, unsigned *flags);

EXTERN_C int func_800DC6D8(BimMon *p, unsigned *flags)
{
    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
    switch (p->f9F0) {
    case 1:
        if (!bimf_5663c35c(p, flags))
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

INCLUDE_ASM("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", bimf_9b3b5928);

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

#include "../shared/bimf_a6f0c006.cpp"

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBBD8);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBC28);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBC40);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBC50);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBCE8);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBD08);

INCLUDE_RODATA("asm/bim/w1_8e7b89df33/nonmatchings/w1_8e7b89df33", D_800DBD20);
