// Shared by 6 BIM.AR modules: destructor of a monster class with a virtual base (module vtables 800DCEF8 and nearby).
#include "common.h"
#include "bim/shared.h"

EXTERN_C const BimVTable10 D_800DCEF8;
EXTERN_C char D_800DCF48[], D_800DCF60[], D_800DCF70[], D_800DD008[], D_800DD028[], D_800DD040[];

EXTERN_C void bimf_81250a8a(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DD028;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DD008;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DCF70;
    self->vt4A8 = D_800DCF60;
    self->vt980 = D_800DCF48;
    self->vt0 = D_800DD040;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DCEF8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DCEF8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DCEF8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DCEF8.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}
