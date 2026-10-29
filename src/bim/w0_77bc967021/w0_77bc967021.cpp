#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAAF4(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA78(int a, short b, int c, int d, int e)
{
    return func_800DAAF4(operator new(0xB00), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", func_800DAAF4);

EXTERN_C const BimVTable10 D_800DA878;
EXTERN_C char D_800DA8C8[], D_800DA8E0[], D_800DA8F0[], D_800DA988[], D_800DA9A8[], D_800DA9C0[];

EXTERN_C void func_800DACC0(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DA9A8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA988;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA8F0;
    self->vt4A8 = D_800DA8E0;
    self->vt980 = D_800DA8C8;
    self->vt0 = D_800DA9C0;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA878;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA878;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA878.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAF8));
        vt.e[6].delta = D_800DA878.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_ASM("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", func_800DAE04);

#include "../shared/bimf_014cace9.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", func_800DAFDC);

EXTERN_C int func_800DB1A0(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0x12C, 0x12C, 0x190, 0, 0, 0, 0, 0);
        func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q && func_800D7D64(p, q)) {
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", func_800DB264);

#include "../shared/bimf_92c79aea.cpp"

INCLUDE_ASM("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", func_800DB378);

INCLUDE_ASM("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", func_800DB480);

struct BimS52 { char pad[0x52]; short s52; };
struct BimA { char pad[0x1B8]; void *f1B8; char pad1BC[0x844]; int fA00; int fA04; };
EXTERN_C void func_800D8204(void *p, int a);

EXTERN_C void func_800DB620(BimA *p)
{
    if (p->fA00) {
        func_800D8204(p, 0xF);
        ((BimS52 *)func_8003912C(p->f1B8, 0xF))->s52 = 0;
    }
    if (p->fA04) {
        func_800D8204(p, 0x10);
        ((BimS52 *)func_8003912C(p->f1B8, 0x10))->s52 = 0;
    }
}

INCLUDE_RODATA("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_77bc967021/nonmatchings/w0_77bc967021", D_800DA9C0);
