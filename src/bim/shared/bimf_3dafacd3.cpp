// Shared by 2 BIM.AR modules: destructor of a monster class with a virtual base (module vtable 800DA878 and nearby).
#include "common.h"
#include "bim/shared.h"

EXTERN_C const BimVTable10 D_800DA878;
EXTERN_C char D_800DA8C8[], D_800DA8E0[], D_800DA8F0[], D_800DA988[], D_800DA9A8[], D_800DA9C0[];

EXTERN_C void bimf_3dafacd3(BimDtor *self, int in_chrg)
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
        vt.e[1].delta = D_800DA878.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAE8));
        vt.e[6].delta = D_800DA878.e[6].delta + adj;
    }
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}
