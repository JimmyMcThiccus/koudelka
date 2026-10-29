#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAB44(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAAC8(int a, short b, int c, int d, int e)
{
    return func_800DAB44(operator new(0xB00), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DAB44);

EXTERN_C const BimVTable10 D_800DA8B8;
EXTERN_C char D_800DA908[], D_800DA920[], D_800DA930[], D_800DA9C8[], D_800DA9E8[], D_800DAA00[];

EXTERN_C void func_800DAD0C(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DA9E8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9C8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA930;
    self->vt4A8 = D_800DA920;
    self->vt980 = D_800DA908;
    self->vt0 = D_800DAA00;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8B8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8B8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8B8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF8));
        vt.e[6].delta = D_800DA8B8.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DAE50);

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB018);

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB174);

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB448);

#include "../shared/bimf_af99c5b3.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_1
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_2
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_3
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB584);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA86C);

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB634);

#include "../shared/bimf_db5f4bc4.cpp"

#define bimf_af99c5b3 bimf_af99c5b3_4
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_5
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

#define bimf_af99c5b3 bimf_af99c5b3_6
#include "../shared/bimf_af99c5b3.cpp"
#undef bimf_af99c5b3

INCLUDE_ASM("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", func_800DB7BC);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA8B8);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA908);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA920);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA930);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA9C8);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DA9E8);

INCLUDE_RODATA("asm/bim/w0_bda43dfefe/nonmatchings/w0_bda43dfefe", D_800DAA00);
