// func_80068770 (virtual-base ctor): 41 differing instructions. Structure and stack layout match (vtable copy at sp+0x10, SV2C temp at sp+0x60);
// retail keeps self in $s5 and loads pt.y back from the stack (lhu a1,0x62(sp)) before sll/ori; we keep y in a register and self lands in $s3.
// exe.h declares it void(void*,int); defined here via an asm alias returning void*.
#include "common.h"
EXTERN_C void func_80053F48_v(void *self, SV2C_80055020 v) asm("func_80053F48");
struct S_80068770 { char pad0[0x18]; void **vt18; char pad1C[0x34]; S_VBB *vb; void **vt54; void **vt58; };
EXTERN_C const VTabB50 D_80015790;
EXTERN_C void *D_80015800[];
EXTERN_C void *D_800157E0[];
EXTERN_C void *D_80015830[];
//HDR_END
EXTERN_C void *func_80068770_def(S_80068770 *self, int in_chrg) asm("func_80068770");
EXTERN_C void *func_80068770_def(S_80068770 *self, int in_chrg)
{
    VTabB50 vt;
    if (in_chrg) {
        self->vb = (S_VBB *)((char *)self + 0x227C);
        S_VBobjB *v = (S_VBobjB *)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_800630BC(self, 0, 0x31);
    self->vb->vt = (VEntB *)D_80015790.e;
    if (!in_chrg) {
        vt = D_80015790;
        self->vb->vt = vt.e;
        char *full;
        int adj;
        vt.e[1].d = D_80015790.e[1].d + (adj = (char *)self - (full = (char *)self->vb - 0x227C));
        vt.e[6].d = D_80015790.e[6].d + adj;
    }
    self->vt54 = D_80015800;
    self->vt58 = D_800157E0;
    self->vt18 = D_80015830;
    char *p = (char *)self + 0x9C;
    int i = 0x30;
    do {
        func_80062D60(p, 1);
        i--;
        p += 0x6C;
    } while (i != -1);
    p = (char *)self + 0x1548;
    i = 0x30;
    do {
        func_8005464C(p);
        i--;
        p += 0x28;
    } while (i != -1);
    FIELD_AT(self, short, 0x1CF0) = 0;
    FIELD_AT(self, int, 0x1CF4) = 0;
    FIELD_AT(self, int, 0x1CF8) = 1;
    FIELD_AT(self, int, 0x1CFC) = 1;
    FIELD_AT(self, short, 0x1D00) = 0;
    FIELD_AT(self, int, 0x1D04) = 0;
    func_8006753C((char *)self + 0x1D08, 1);
    int off = 0x1548;
    char *q = (char *)self;
    unsigned short y = 3;
    for (unsigned int k = 0; k < 0x31; k++) {
        char *e = (char *)self + off;
        func_8005408C(e, 2);
        off += 0x28;
        func_80053F48_v(e, SV2C_80055020(0xD6, y));
        FIELD_AT(self, char, 0x68 + k) = 0;
        FIELD_AT(q, int, 0xF8) = 2;
        q += 0x6C;
        y += 0xD;
    }
    return self;
}
