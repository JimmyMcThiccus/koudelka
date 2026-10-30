#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DD15C(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DD0E0(int a, short b, int c, int d, int e)
{
    return func_800DD15C(operator new(0xAF4), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", func_800DD15C);

EXTERN_C const BimVTable10 D_800DCED0;
EXTERN_C char D_800DCF20[], D_800DCF38[], D_800DCF48[], D_800DCFE0[], D_800DD000[], D_800DD018[];

EXTERN_C void func_800DD324(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DD000;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DCFE0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DCF48;
    self->vt4A8 = D_800DCF38;
    self->vt980 = D_800DCF20;
    self->vt0 = D_800DD018;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DCED0;
    if (!in_chrg) {
        BimVTable10 vt = D_800DCED0;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DCED0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DCED0.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

#include "../shared/bimf_41634af0.cpp"

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", func_800DD6DC);

INCLUDE_ASM("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", func_800DD8A4);

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#include "../shared/bimf_92c79aea.cpp"

INCLUDE_ASM("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", func_800DDAB0);

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", func_800DDBD0);

INCLUDE_ASM("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", func_800DDD20);

EXTERN_C int func_800DDEC8(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 0x10);
        func_80082670(p + 0x2A4, 0x11, 0x11);
        break;
    case 4:
        func_80082670(p + 0x2A4, 0x10, 0x12);
        func_80082670(p + 0x2A4, 0x11, 0x13);
        break;
    case 2:
    case 3:
    case 5:
    case 6:
        func_80082670(p + 0x2A4, 0x10, 0x7);
        func_80082670(p + 0x2A4, 0x11, 0x8);
        break;
    }
    return r;
}

INCLUDE_RODATA("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", D_800DCED0);

INCLUDE_RODATA("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", D_800DCF20);

INCLUDE_RODATA("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", D_800DCF38);

INCLUDE_RODATA("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", D_800DCF48);

INCLUDE_RODATA("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", D_800DCFE0);

INCLUDE_RODATA("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", D_800DD000);

INCLUDE_RODATA("asm/bim/w2_44ce6d80e4/nonmatchings/w2_44ce6d80e4", D_800DD018);
