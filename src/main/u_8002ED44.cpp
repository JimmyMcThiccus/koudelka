#include "common.h"
#define EXE_H_IN_u_8002ED44
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8002ED44.h"

EXTERN_C void *func_8002ED44(void *p, int a, int b)
{
    func_800198E0(p, a, b);
    return p;
}

EXTERN_C void func_8002ED6C(S_8002ED6C *p)
{
    func_80019C68(p, p->unk4 - 1);
}

EXTERN_C void *func_8002ED90(S_8002ED90 *p)
{
    return &p->unk8;
}

EXTERN_C S_Rgb func_8002ED98(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C S_Rgb func_8002EDB8(S_80025A64 *p)
{
    return p->unk8;
}

EXTERN_C int func_8002EDD8()
{
    S_IntVec *p = (S_IntVec *)&D_800AC820;
    return p->count ? p->data[p->count - 1] : 0;
}

EXTERN_C int func_8002EE10(S_IntVec *p)
{
    return p->count ? p->data[p->count - 1] : 0;
}

EXTERN_C void func_8002EE40(int a)
{
    S_IntVec *v = (S_IntVec *)&D_800AC820;
    func_80019A6C(v, a, v->count);
    D_800B4CFC = a;
}

EXTERN_C void func_8002EE7C(void *p, int a)
{
    func_8002EE9C(p, a);
}

EXTERN_C void func_8002EE9C(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800118DC;
    func_800198AC(p, a);
}

S_8002EEC4::S_8002EEC4(void *s)
{
    func_8002EA70(this, s);
    vt = D_800118FC;
    unk10 = 0;
}

EXTERN_C void func_8002EEFC(void *vp, int flags)
{
    S_8002F180 *p = (S_8002F180 *)vp;
    *(void ***)p = D_800118FC;
    if (p->unk10) {
        func_80019CFC((List *)&D_800AC820, p->unk10);
        func_8002CC60(p->unk10);
        p->unk10 = 0;
    }
    func_8002EE9C(p, flags);
}

EXTERN_C int func_8002EF64(S_8002EF64 *p)
{
    return p->unk10;
}

EXTERN_C S_8002EC18 *func_8002EF70(S_8002EC18 *p)
{
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    return p;
}

EXTERN_C void func_8002EF88(S_8002EF88 *p, S_8002EF88_O *o)
{
    func_8002DB50(o, 1);
    o->unk1C = func_8002A3C0_i(p->unk4);
    S_IntVec *v = (S_IntVec *)&D_800AC820;
    func_80019A6C(v, (int)o, v->count);
    D_800B4CFC = (int)o;
    func_8002B6FC(p->unk4, o);
    func_8002EAF4();
}

EXTERN_C void func_8002F004(void *p, void *q)
{
    func_8002DB50(q, 1);
}

EXTERN_C void func_8002F028(void *vp)
{
    S_8002F028 *p = (S_8002F028 *)vp;
    S_Pt2 pos;
    S_Rect8 r;
    if (!p->unk10) {
        p->unk10 = new S_Lay(p->unk4->prio(), 5, 1);
        func_8002D24C(p->unk10, &p->rect);
        r = p->rect;
        pos = r.pos;
        func_8002D780(p->unk10, pos);
    } else {
        func_8002DB50(p->unk10, 1);
    }
    ((void (*)(void *, void *))p->vt[8].pfn)((char *)p + p->vt[8].delta, p->unk10);
}

EXTERN_C void func_8002F180(S_8002F180 *p)
{
    if (p->unk10) {
        func_8002CC60(p->unk10);
        p->unk10 = 0;
    }
}

EXTERN_C void func_8002F1BC(S_8002F1BC *p)
{
    if (p->unk10) {
        func_8002D94C(p->unk10);
        add_710(p->unk10);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F21C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F2A4);

EXTERN_C int func_8002F32C(S_8002F32C *p)
{
    return p->unk4;
}

EXTERN_C void func_8002F338(S_8002F338 *p)
{
    S_Pt2 pos;
    S_Rect8 r;
    SetDispMask(1);
    func_8002F028(p);
    if (p->unk14)
        VCALL1(p->unk14, 1, 3);
    p->unk14 = new S_Lay(0, 5, 1);
    func_8002D24C(p->unk14, &p->rect);
    r = p->rect;
    pos = r.pos;
    func_8002D780(p->unk14, pos);
    p->unk14->unk1C = func_8002A3C0_i(p->unk4);
}

EXTERN_C void func_8002F464(S_8002F1BC *p)
{
    if (p->unk14) {
        func_8002D94C(p->unk14);
        add_710(p->unk14);
    }
}

EXTERN_C int func_8002F4C4()
{
    return 0;
}

EXTERN_C int func_8002F4CC(S_8002F4CC *p)
{
    return p->unk14;
}

S_8002F4D8::S_8002F4D8(void *s) : S_8002EEC4(s)
{
    vt = D_8001199C;
    unk14 = 0;
    func_8002EC90(this, D_800B4C88);
}

EXTERN_C void func_8002F520(void *p, int a)
{
    func_8002EEFC(p, a);
}

EXTERN_C void *func_8002F540(S_8002F4CC *p)
{
    return &p->unkC;
}

EXTERN_C void func_8002F548()
{
}

EXTERN_C int func_8002F550()
{
    return -1;
}

EXTERN_C S_8002F558 *func_8002F558(S_8002F558 *p)
{
    p->vt = D_80011A44;
    p->v.clear();
    return p;
}

EXTERN_C int func_8002F580(unsigned int a)
{
    return (a >> 5) & 3;
}

EXTERN_C int func_8002F58C(int a, int b)
{
    return (a & 0xFF9F) | ((b & 3) << 5);
}

EXTERN_C int func_8002F5A0(int v)
{
    int old = D_800B4D00;
    D_800B4D00 = v;
    return old;
}

EXTERN_C void func_8002F5B0(void *p, int a)
{
    func_800198AC(p, a);
}

EXTERN_C int func_8002F5D0(S_8002F5D0 *p)
{
    S_VObj *o = p->o;
    if (o)
        return VCALL0I(o, 5);
    return 0;
}

EXTERN_C int func_8002F614(S_F614 *p)
{
    S_F614_O *objs[4];
    int i;
    int n;
    char *r;
    S_F614_O *o;
    for (i = 0; i < 4; i++) {
        r = ((char *(*)(void *))p->vt[2].pfn)((char *)p + p->vt[2].delta);
        o = 0;
        if (r)
            o = (S_F614_O *)(r - 8);
        objs[i] = o;
    }
    n = 0;
    if (((int (*)(void *, S_F614_O **))p->vt[4].pfn)((char *)p + p->vt[4].delta, objs)) {
        for (i = 0; i < 4; i++) {
            VCALL0(objs[i], 6);
            objs[i]->blk = p->blk;
            VCALL0(objs[i], 3);
            n += VCALL0I(objs[i], 5);
        }
    } else {
        for (i = 0; i < 4; i++)
            VCALL0(objs[i], 3);
    }
    if (p->unk4)
        VCALL0(p->unk4, 6);
    return n;
}

EXTERN_C void func_8002F7D4(S_8002F5D0 *p)
{
    S_VObj *o = p->o;
    if (o)
        VCALL0(o, 6);
}

EXTERN_C int func_8002F818(S_8002F818 *p)
{
    return p->unk4;
}

EXTERN_C S_8002F824 *func_8002F824(S_8002F824 *p)
{
    p->vt = D_80010178;
    p->b.vt = D_80011A44;
    p->unk4 = 0;
    p->b.v.clear();
    p->b.vt = D_80011AAC;
    p->vt = D_80011B14;
    return p;
}

EXTERN_C void func_8002F874(S_8002F824 *p, int flags)
{
    p->b.vt = D_80011AAC;
    p->vt = D_80011B14;
    func_800198AC(&p->b, 0);
    func_8001A610(p, flags);
}

EXTERN_C int func_8002F8D0()
{
    return 0;
}

EXTERN_C void func_8002F8D8()
{
}

EXTERN_C S_8002F8E0 *func_8002F8E0(S_8002F8E0 *p)
{
    p->vtbl = D_80011B5C;
    p->unk0 = 0;
    return p;
}

EXTERN_C int func_8002F8F8(int *p, int i)
{
    return p[i];
}

EXTERN_C void func_8002F90C(S_8002F90C *p)
{
    p->c = func_800301BC(p ? (char *)p + 0x14 : 0);
}

EXTERN_C void func_8002F960(char *p)
{
    gte_ldv3c(p ? p + 0x14 : 0);
    gte_rtpt();
}

EXTERN_C bool func_8002F998(S_Obj14 *p, S_Obj14 **q)
{
    return func_8002FEC8(p, q[0], q[1], q[2], q[3]);
}

EXTERN_C void *func_8002FA20(char *p, void *out)
{
    return func_800300C8(p ? p + 0x14 : 0, out);
}

EXTERN_C int func_8002FA50(S_Plane *t, int x, int z)
{
    return t->ny == 0 ? (t->v[0].y + t->v[1].y + t->v[2].y) / 3
                      : t->v[0].y - ((x - t->v[0].x) * t->nx + (z - t->v[0].z) * t->nz) / t->ny;
}

EXTERN_C int func_8002FAF8(S_Tri *t, int x, int z)
{
    if (t->n <= 0)
        return 0;
    for (int i = 0; i < 3; i++) {
        int j = D_800B4D08[i];
        S_Tri_V *v = t->v;
        if (edge_side(v, j, &v[i], x, z))
            return 0;
    }
    return 1;
}

EXTERN_C int func_8002FB8C(S_Plane *t, short a)
{
    int s, c;
    if (t->ny > 0) {
        s = func_80026014(a);
        c = func_800260A4(a);
        return ratan2((t->nx * s - t->nz * c) / t->ny, 0x1000);
    }
    return 0x400;
}

EXTERN_C int func_8002FC40(S_Plane *t, short a)
{
    int s, c;
    if (t->ny > 0) {
        s = func_800260A4(a);
        c = func_80026014(a);
        return ratan2((t->nx * s - t->nz * c) / t->ny, 0x1000);
    }
    return 0x400;
}

EXTERN_C void *func_8002FCF4(S_8002F90C *p, S_8002FCF4_Q *q, int *out)
{
    *out = q->b1;
    p->c = q->c4;
    func_80030084(p ? (S_Blk8 *)((char *)p + 0x14) : 0, q->cC);
    return q + 1;
}

EXTERN_C void func_8002FD5C(S_8002FD5C *p)
{
    S_8002FD5C_O *o = p->o;
    if (o) {
        gte_ldv3m(o->sv);
        gte_rtpt();
    }
}

EXTERN_C int func_8002FD98(S_8002FD98 *p)
{
    return p->unk4;
}

EXTERN_C S_8002FDA4 *func_8002FDA4(S_8002FDA4 *p)
{
    int i;
    S_Vec4sA *q;
    p->vt = D_80010178;
    p->b.vt = D_80011A44;
    p->unk4 = 0;
    p->b.v.clear();
    p->b.vt = D_80011AAC;
    p->vt = D_80011B14;
    q = p->v;
    for (i = 2; i != -1; i--) {
        q->x = 0; q->y = 0; q->z = 0; q->w = 0; q++;
    }
    p->b.vt = D_80011B8C;
    p->vt = D_80011BF4;
    return p;
}

EXTERN_C int func_8002FE3C(void *p, int i)
{
    return D_800B4D08[i];
}

EXTERN_C void func_8002FE54(S_8002F824 *p, int flags)
{
    p->b.vt = D_80011B8C;
    p->vt = D_80011BF4;
    p->b.vt = D_80011AAC;
    p->vt = D_80011B14;
    func_800198AC(&p->b, 0);
    func_8001A610(p, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FEC8);

EXTERN_C void func_80030084(S_Blk8 *d, S_Blk8 *s)
{
    int i = 0;
    while (1) {
        if (!(i < 3))
            break;
        i++;
        *d = *s;
        d++;
        s++;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800300C8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800301BC);

EXTERN_C void func_80030358(void *p)
{
    gte_ldv3c(p);
    gte_rtpt();
}

EXTERN_C void func_80030384(S_Obj44 *p)
{
    if (p) {
        S_Obj44 *e = p + ((int *)p)[-2];
        while (p != e) {
            e--;
            VCALL1(e, 1, 2);
        }
        __builtin_vec_delete((char *)p - 8);
    }
}

EXTERN_C int func_800303FC()
{
    return 0;
}

EXTERN_C void func_80030404()
{
}

EXTERN_C void func_8003040C()
{
}

EXTERN_C void func_80030414()
{
}

EXTERN_C void func_8003041C(S_Tri *t)
{
    func_8002F90C((S_8002F90C *)t);
    S_Tri_V *e = t->e;
    S_Tri_V *v = t->v;
    for (int i = 0; i < 3; i++)
        edge_sub(&e[i], v, D_800B4D08[i], &v[i]);
}

EXTERN_C int func_800304B4(S_Tri *t, int x, int z)
{
    int i = 0;
    S_Tri_V *v, *e;
    int a, b;
    if (t->n <= 0)
        return 0;
    v = t->v;
    e = t->e;
    for (; i < 3; v++, i++, e++) {
        a = e->x * (z - v->z);
        b = e->z * (x - v->x);
        if (b < a)
            return 0;
    }
    return 1;
}

EXTERN_C int func_80030520()
{
    return 0;
}

EXTERN_C int func_80030528(S_80030528 *p)
{
    return p->unk4;
}

S_80030534::S_80030534()
{
    int i;
    S_Vec4sA *q;
    vt = D_80010178;
    b.vt = D_80011A44;
    unk4 = 0;
    b.v.clear();
    b.vt = D_80011AAC;
    vt = D_80011B14;
    q = v;
    for (i = 2; i != -1; i--) {
        q->x = 0; q->y = 0; q->z = 0; q->w = 0; q++;
    }
    b.vt = D_80011B8C;
    vt = D_80011BF4;
    func_80030694(m2C);
    b.vt = D_80011C44;
    vt = D_80011CAC;
}

EXTERN_C void func_80030608(S_8002F824 *p, int flags)
{
    p->b.vt = D_80011C44;
    p->vt = D_80011CAC;
    p->b.vt = D_80011B8C;
    p->vt = D_80011BF4;
    p->b.vt = D_80011AAC;
    p->vt = D_80011B14;
    func_800198AC(&p->b, 0);
    func_8001A610(p, flags);
}

EXTERN_C int *func_80030694(int *p)
{
    func_8001AA28(p, 6);
    return p;
}

EXTERN_C void func_800306C0(S_8002F90C *p)
{
    p->c = func_80031030(p ? (char *)p + 0x14 : 0);
}

EXTERN_C void func_80030714(char *p)
{
    gte_ldv3c(p ? p + 0x14 : 0);
    gte_rtpt();
}

EXTERN_C bool func_8003074C(S_Obj14 *p, S_Obj14 **q)
{
    return func_80030C70(p, q[0], q[1], q[2], q[3]);
}

EXTERN_C void func_800307D4(char *p)
{
    func_80030EE0(p ? p + 0x14 : 0);
}

EXTERN_C int func_80030804(S_Plane *t, int x, int z)
{
    if (t->ny)
        return t->v[0].y - ((x - t->v[0].x) * t->nx + (z - t->v[0].z) * t->nz) / t->ny;
    return (t->v[0].y + t->v[1].y + t->v[2].y + t->v[3].y) / 4;
}

EXTERN_C int func_800308B0(S_Tri *t, int x, int z)
{
    int i;
    S_Tri_V *v;
    if (t->n <= 0)
        return 0;
    i = 0;
    v = t->v;
    while (i < 4) {
        int j = i + 1;
        S_Tri_V *a = &v[j & 3];
        S_Tri_V *b = &v[i];
        int p = (a->x - b->x) * (z - b->z);
        int q = (a->z - b->z) * (x - b->x);
        if (q < p)
            return 0;
        i = j;
    }
    return 1;
}

EXTERN_C int func_80030940(S_Plane *t, short a)
{
    int s, c;
    if (t->ny > 0) {
        s = func_80026014(a);
        c = func_800260A4(a);
        return ratan2((t->nx * s - t->nz * c) / t->ny, 0x1000);
    }
    return 0x400;
}

EXTERN_C int func_800309F4(S_Plane *t, short a)
{
    int s, c;
    if (t->ny > 0) {
        s = func_800260A4(a);
        c = func_80026014(a);
        return ratan2((t->nx * s - t->nz * c) / t->ny, 0x1000);
    }
    return 0x400;
}

EXTERN_C void *func_80030AA8(void *vp, void *vq, int *out)
{
    S_8002F90C *p = (S_8002F90C *)vp;
    S_80030AA8_Q *q = (S_80030AA8_Q *)vq;
    *out = q->b1;
    p->c = q->c4;
    func_80030E9C(p ? (S_Blk8 *)((char *)p + 0x14) : 0, q->cC);
    return q + 1;
}

EXTERN_C void func_80030B10(S_8002FD5C *p)
{
    S_8002FD5C_O *o = p->o;
    if (o) {
        gte_ldv3m(o->sv);
        gte_rtpt();
    }
}

EXTERN_C int func_80030B4C(S_80030B4C *p)
{
    return p->unk4;
}

EXTERN_C S_8002FDA4 *func_80030B58(S_8002FDA4 *p)
{
    int i;
    S_Vec4sA *q;
    p->vt = D_80010178;
    p->b.vt = D_80011A44;
    p->unk4 = 0;
    p->b.v.clear();
    p->b.vt = D_80011AAC;
    p->vt = D_80011B14;
    q = p->v;
    for (i = 3; i != -1; i--) {
        q->x = 0; q->y = 0; q->z = 0; q->w = 0; q++;
    }
    p->b.vt = D_80011D04;
    p->vt = D_80011D6C;
    return p;
}

EXTERN_C int func_80030BF0(int a)
{
    return (a + 1) & 3;
}

EXTERN_C void func_80030BFC(S_8002F824 *p, int flags)
{
    p->b.vt = D_80011D04;
    p->vt = D_80011D6C;
    p->b.vt = D_80011AAC;
    p->vt = D_80011B14;
    func_800198AC(&p->b, 0);
    func_8001A610(p, flags);
}

EXTERN_C bool func_80030C70(S_Base14 *pa, S_Base14 *pb, S_Base14 *pc, S_Base14 *pd, S_Base14 *pe)
{
    bool ok = 1;
    int i;
    for (i = 0; i < 3; i++) {
        int n = 0;
        if (NEAR64(VX(pa, 0), VX(pa, 1)) && NEAR64(VX(pa, 1), VX(pa, 2)) && NEAR64(VX(pa, 2), VX(pa, 3)) && NEAR64(VX(pa, 3), VX(pa, 0)))
            n = 1;
        ok &= n;
        VX(pb, 0) = VX(pa, 0);
        VX(pc, 1) = VX(pa, 1);
        VX(pd, 2) = VX(pa, 2);
        VX(pe, 3) = VX(pa, 3);
        VX(pb, 1) = VX(pc, 0) = (VX(pa, 0) + VX(pa, 1)) >> 1;
        VX(pb, 2) = VX(pd, 0) = (VX(pa, 0) + VX(pa, 2)) >> 1;
        VX(pc, 3) = VX(pe, 1) = (VX(pa, 1) + VX(pa, 3)) >> 1;
        VX(pd, 3) = VX(pe, 2) = (VX(pa, 2) + VX(pa, 3)) >> 1;
        VX(pb, 3) = VX(pc, 2) = VX(pd, 1) = VX(pe, 0) = (VX(pa, 1) + VX(pa, 2)) >> 1;
    }
    return !ok;
}

EXTERN_C void func_80030E9C(S_Blk8 *d, S_Blk8 *s)
{
    int i = 0;
    while (1) {
        if (!(i < 4))
            break;
        i++;
        *d = *s;
        d++;
        s++;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030EE0);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80031030);

EXTERN_C void func_800311CC(void *p)
{
    gte_ldv3c(p);
    gte_rtpt();
}

EXTERN_C void func_800311F8(S_Obj68 *p)
{
    if (p) {
        S_Obj68 *e = p + ((int *)p)[-2];
        while (p != e) {
            e--;
            VCALL1(e, 1, 2);
        }
        __builtin_vec_delete((char *)p - 8);
    }
}

EXTERN_C int func_80031278()
{
    return 0x28;
}

EXTERN_C S_8002F558 *func_80031280()
{
    S_Pool834 *pool = (S_Pool834 *)&D_800AC834;
    S_80031280 *x = pool->free;
    if (x) {
        pool->free = x->next;
        x->next = 0;
    } else {
        int i, j;
        S_Vec4sA *q;
        POLY_F4 *pr;
        S_80031280 *n = (S_80031280 *)__builtin_new(0x68);
        n->vt = D_80010178;
        n->b.vt = D_80011A44;
        n->next = 0;
        n->b.v.clear();
        n->b.vt = D_80011AAC;
        n->vt = D_80011B14;
        q = n->v;
        for (i = 3; i != -1; i--) {
            q->x = 0; q->y = 0; q->z = 0; q->w = 0; q++;
        }
        n->b.vt = D_80011D04;
        n->vt = D_80011D6C;
        n->c34 = 0x28808080;
        pr = n->prim;
        for (j = 1; j != -1; j--) {
            pr->len = 5;
            pr->code = 0x28;
            pr++;
        }
        n->b.vt = D_80011DBC;
        n->vt = D_80011E24;
        x = n;
    }
    return x ? &x->b : 0;
}

EXTERN_C void func_800313BC(S_800313BC *p)
{
    if (D_800AC834.c)
        p->next = D_800AC834.c;
    D_800AC834.c = (int)p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800313E0);
