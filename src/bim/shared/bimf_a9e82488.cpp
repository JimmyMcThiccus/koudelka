// Shared by 2 BIM.AR modules: destructor of a monster class with a virtual base (module vtable 800DA890 and nearby).
#include "common.h"
#include "bim/shared.h"

EXTERN_C const BimVTable10 D_800DA890;
EXTERN_C char D_800DA8E0[], D_800DA8F8[], D_800DA908[], D_800DA9A0[], D_800DA9C0[], D_800DA9D8[];

EXTERN_C void bimf_a9e82488(BimDtor *self, int in_chrg)
{
    self->vt8C = D_800DA9C0;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9A0;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA908;
    self->vt4A8 = D_800DA8F8;
    self->vt980 = D_800DA8E0;
    self->vt0 = D_800DA9D8;
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA890;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA890;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA890.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA890.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}
