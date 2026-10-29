// func_8006BFE4 (vbase ctor): 4 differing instructions. Retail adds the e1 and e5 deltas before storing either (addu,addu,sh,sh); we emit addu,sh,..,addu,sh.
#include "common.h"
struct S_8006BFE4m { void *vb; int idx; void *vbp; char vbase[0x14]; };
struct S_8006BFE4 { S_VBB *vb; char pad4[0x28]; void **vt2C; S_8006BFE4m m; void **vt50; char pad54[0xBC]; int f110; int f114; int f118; int f11C; int f120; };
EXTERN_C const VTabB50 D_800114CC;
EXTERN_C void *D_8001151C[];
EXTERN_C void *func_80065A00(void *);
EXTERN_C void *func_80029C54(void *p, int in_chrg, unsigned short a);
EXTERN_C void *func_8006BFE4_d(S_8006BFE4 *self, int in_chrg, int a, int b) asm("func_8006BFE4");
//HDR_END
EXTERN_C void *func_8006BFE4_d(S_8006BFE4 *self, int in_chrg, int a, int b)
{
    if (in_chrg) {
        self->vb = (S_VBB *)((char *)self + 0x124);
        S_VBobjB *v = (S_VBobjB *)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80029C54(self, 0, 2);
    self->vb->vt = (VEntB *)D_800114CC.e;
    VTabB50 vt = D_800114CC;
    self->vb->vt = vt.e;
    char *full;
    int adj;
    vt.e[1].d = D_800114CC.e[1].d + (adj = (char *)self - (full = (char *)self->vb - 0x50));
    vt.e[5].d = D_800114CC.e[5].d + adj;
    vt.e[7].d = D_800114CC.e[7].d + adj;
    vt.e[9].d = D_800114CC.e[9].d + adj;
    self->vt2C = D_8001151C;
    S_8006BFE4m *m = &self->m;
    m->vbp = m->vbase;
    m->vb = m->vbase;
    func_800198E0(m->vbp, 0x10, 4);
    m->idx = 0;
    func_80065A00((char *)self + 0x50);
    self->vb->vt = (VEntB *)D_80015C0C.e;
    if (!in_chrg) {
        VTabB50 vt2 = D_80015C0C;
        self->vb->vt = vt2.e;
        char *full2;
        int adj2;
        vt2.e[1].d = D_80015C0C.e[1].d + (adj2 = (char *)self - (full2 = (char *)self->vb - 0x124));
        vt2.e[5].d = D_80015C0C.e[5].d + adj2;
        vt2.e[7].d = D_80015C0C.e[7].d + adj2;
        vt2.e[9].d = D_80015C0C.e[9].d + adj2;
    }
    char *r = (char *)self;
    FIELD_AT(r, void **, 0x50) = D_80015C5C;
    FIELD_AT(r, void **, 0x2C) = D_80015C9C;
    FIELD_AT(r, int, 0x110) = a;
    {
        struct Q4_8006BFE4 { int a, b, c, d; } *q = (Q4_8006BFE4 *)(r + 0x114);
        q->a = 0; q->b = 0; q->c = b; q->d = 0;
    }
    return r;
}
