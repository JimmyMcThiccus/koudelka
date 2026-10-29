#include "common.h"
#include "bim/shared.h"
EXTERN_C char D_80010178[], D_800104A8[];
EXTERN_C const BimVTable10 D_800DA8B8;
EXTERN_C char D_800DA908[], D_800DA920[], D_800DA930[], D_800DA9C8[], D_800DA9E8[], D_800DAA00[];
EXTERN_C void func_800D73E8(void *self, int a, int b, int c, int d, int e, int f);
EXTERN_C void bimf_ac9e0f11(void *self, int a);
EXTERN_C void func_800D8D64(void *self, int a, int b, int c, int d, int e, int f, int g, int h);

EXTERN_C BimDtor *func_800DAB3C(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{
    BimDtor *new_var;
    if (in_chrg) {
        BimVBase *vb = self->vb1DC = (BimVBase *)&self->vtAEC;
        vb->vptr = (BimVTable10 *)D_80010178;
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *)D_800104A8;
    }
    func_800D73E8(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&D_800DA8B8;
    if (!in_chrg) {
        BimVTable10 vt = D_800DA8B8;
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800DA8B8.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - 0xAEC));
        vt.e[6].delta = D_800DA8B8.e[6].delta + adj;
    }
    self->vt8C = D_800DA9E8;
    self->vt1E0 = D_8001262C;
    self->vt1E4 = D_800DA9C8;
    self->vt3FC = D_80017ADC;
    self->vt49C = D_800DA930;
    self->vt4A8 = D_800DA920;
    self->vt980 = D_800DA908;
    self->vt0 = D_800DAA00;
    bimf_ac9e0f11(self, b);
    func_800D8D64(self, 1, 0, 0, 0, 0, 0, 0, 0);
    self->f9DC = 0;
    (new_var = self)->f9D8 = 0;
    return new_var;
}
