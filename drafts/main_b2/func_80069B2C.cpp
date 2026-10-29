// func_80069B2C (dtor with three inline array-destroy loops): ~120 differing instructions. Retail keeps the array begin in a temp copied to $s2 and the end pointer unfolded
// (addiu s0,s1,0x2BC; beq; addiu s0,s0,-0x1C), we fold the -0x1C into the base and use a 4th saved register. Same shape applies to func_80069264 (arrays of 0x28 and 0x6C).
#include "common.h"
struct S_B2_vb50 { char pad0[0x18]; void **vt18; char pad1C[0x34]; S_VBB *vb; void **vt54; void **vt58; };
EXTERN_C const VTabB50 D_80015914;
EXTERN_C void *D_80015964[];
EXTERN_C void *D_80015984[];
EXTERN_C void func_80069B2C_d(S_B2_vb50 *self, int in_chrg) asm("func_80069B2C");
//HDR_END
EXTERN_C void func_80069B2C_d(S_B2_vb50 *self, int in_chrg)
{
    self->vt54 = D_80013BD0;
    self->vt58 = D_80015964;
    self->vt18 = D_80015984;
    self->vb->vt = (VEntB *)D_80015914.e;
    if (!in_chrg) {
        VTabB50 vt = D_80015914;
        self->vb->vt = vt.e;
        char *full;
        int adj;
        vt.e[1].d = D_80015914.e[1].d + (adj = (char *)self - (full = (char *)self->vb - 0x2BC));
        vt.e[6].d = D_80015914.e[6].d + adj;
    }
    char *q;
    char *b = (char *)self + 0x284;
    if (b != 0) {
        char *p = (char *)self + 0x2BC;
        if (b != p) {
            p -= 0x1C;
            do {
                ((VObj<0x18> *)p)->v00(2);
                q = p;
                p -= 0x1C;
            } while (b != q);
        }
    }
    b = (char *)self + 0x1A4;
    if (b != 0) {
        char *p = (char *)self + 0x284;
        if (b != p) {
            p -= 0x1C;
            do {
                ((VObj<0x18> *)p)->v00(2);
                q = p;
                p -= 0x1C;
            } while (b != q);
        }
    }
    b = (char *)self + 0x64;
    if (b != 0) {
        char *p = (char *)self + 0x1A4;
        if (b != p) {
            p -= 0x28;
            do {
                ((VObj<0x18> *)p)->v00(2);
                q = p;
                p -= 0x28;
            } while (b != q);
        }
    }
    func_8005652C(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb, 0);
    if (in_chrg & 1)
        __builtin_delete(self);
}
