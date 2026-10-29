#include "common.h"
#define EXE_H_IN_u_8002C90C
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8002C90C.h"

EXTERN_C int func_8002C90C(S_8002C90C *p)
{
    return p->unk4;
}

EXTERN_C S_8002C918 *func_8002C918(S_8002C918 *p)
{
    p->vt = D_80010178;
    p->a = 0;
    p->vt = D_8001178C;
    return p;
}

EXTERN_C void func_8002C93C(int a)
{
    List *l = &D_800AC710;
    func_80019A6C(l, a, 0);
}

EXTERN_C void func_8002C974(int a)
{
    List *l = &D_800AC710;
    func_80019A6C(l, a, l->count);
}

EXTERN_C void func_8002C9B4(void *p, int a)
{
    func_8001A610(p, a);
}

S_8002C9D4::S_8002C9D4(const S_8002C9D4 &src)
{
    func_8002E714(this, src.unk10);
    vt = D_800117A4;
    unk18 = src.unk18;
    blk20 = src.blk20;
    unk28 = 0;
    unk2A = 0;
    unk1C = src.unk1C;
    unk2C = 0;
    unk30 = src.unk30;
    unk64 = 0;
}

S_8002C9D4::S_8002C9D4(const S_8002C9D4 &src, S_Rect8 *rect)
{
    func_8002E714(this, src.unk10);
    vt = D_800117A4;
    unk18 = src.unk18;
    *(short *)&blk20.b[0] = 0;
    *(short *)&blk20.b[2] = 0;
    *(short *)&blk20.b[4] = 0;
    *(short *)&blk20.b[6] = 0;
    unk28 = 0;
    unk2A = 0;
    func_8002D24C(this, rect);
    S_Pt2 pos;
    S_Rect8 r;
    r = *rect;
    pos = r.pos;
    func_8002D780(this, pos);
    unk1C = src.unk1C;
    unk2C = 0;
    unk30 = src.unk30;
    unk64 = 0;
}

EXTERN_C void func_8002CB44(S_Drawable *p, int flags)
{
    p->vt = D_800117A4;
    if (p->unk64)
        new S_DeleteObj(p->unk64);
    char *g = (char *)&D_800AC710;
    Holder *h = g ? (Holder *)(g + 8) : 0;
    func_80019CFC(h, p);
    func_8002E7A8(p, flags);
}

EXTERN_C void func_8002CC60(S_Drawable *p)
{
    if (p->unk64)
        new S_DeleteObj(p->unk64);
    p->unk64 = 0;
    new S_DeleteObj(p);
}

EXTERN_C void func_8002CDC0(S_RectXYWH *r)
{
    SetDefDrawEnv(&D_800AC740[0], r->x, r->y, r->w, r->h);
    SetDefDispEnv(&D_800AC7F8[1], r->x, r->y, r->w, r->h);
    *(S_Rect2c *)&D_800AC730[0] = S_Rect2c(r->x, r->y, r->w, r->h);
    *(S_Pt2c *)&D_800B4CF4[0] = S_Pt2c(r->x, r->y);
    if (r->h <= 240) {
        SetDefDrawEnv(&D_800AC740[1], r->x + r->w, r->y, r->w, r->h);
        SetDefDispEnv(&D_800AC7F8[0], r->x + r->w, r->y, r->w, r->h);
        *(S_Rect2c *)&D_800AC730[1] = S_Rect2c(r->x + r->w, r->y, r->w, r->h);
        *(S_Pt2c *)&D_800B4CF4[1] = S_Pt2c(r->x + r->w, r->y);
    } else {
        SetDefDrawEnv(&D_800AC740[1], r->x, r->y, r->w, r->h);
        SetDefDispEnv(&D_800AC7F8[0], r->x, r->y, r->w, r->h);
        *(S_Rect2c *)&D_800AC730[1] = S_Rect2c(r->x, r->y, r->w, r->h);
        *(S_Pt2c *)&D_800B4CF4[1] = S_Pt2c(r->x, r->y);
    }
    D_800AC740[1].b[0x16] = 1;
    D_800AC740[0].b[0x16] = 1;
}

EXTERN_C void func_8002D020(S_Pt2 *p0, S_Pt2 *p1, S_Pt2 *ds, S_Pt2 *dp)
{
    SetDefDrawEnv(&D_800AC740[0], p0->x, p0->y, ds->x, ds->y);
    SetDefDispEnv(&D_800AC7F8[1], p0->x, p0->y, dp->x, dp->y);
    *(S_Rect2c *)&D_800AC730[0] = S_Rect2c(p0->x, p0->y, ds->x, ds->y);
    *(S_Pt2 *)&D_800B4CF4[0] = *p0;
    SetDefDrawEnv(&D_800AC740[1], p1->x, p1->y, ds->x, ds->y);
    SetDefDispEnv(&D_800AC7F8[0], p1->x, p1->y, dp->x, dp->y);
    *(S_Rect2c *)&D_800AC730[1] = S_Rect2c(p1->x, p1->y, ds->x, ds->y);
    *(S_Pt2 *)&D_800B4CF4[1] = *p1;
    D_800AC740[1].b[0x16] = 1;
    D_800AC740[0].b[0x16] = 1;
    D_800AC7F8[1].b[0x11] = 1;
    D_800AC7F8[0].b[0x11] = 1;
}

EXTERN_C void func_8002D1E0()
{
    PutDispEnv(&D_800AC7F8[D_800B4CF0]);
    PutDrawEnv(&D_800AC740[D_800B4CF0]);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002C90C", func_8002D24C);

EXTERN_C void func_8002D780(void *vp, S_Pt2 pos)
{
    S_D780 *p = (S_D780 *)vp;
    S_Pt2s ofs;
    if (p->parent) {
        S_Pt2s t = p->parent->pos;
        ofs.set(pos.x + t.x, pos.y + t.y);
    } else {
        ofs = *(S_Pt2s *)&pos;
    }
    S_Pt2s *pp = &p->pos;
    *pp = ofs;
    if (p->unk30) {
        short x, y;
        x = pp->x + D_800B4CF4[0].a;
        y = pp->y + D_800B4CF4[0].b;
        ofs.x = x;
        ofs.y = y;
        SetDrawOffset(p->d4C, &ofs);
        x = pp->x + D_800B4CF4[1].a;
        y = pp->y + D_800B4CF4[1].b;
        ofs.x = x;
        ofs.y = y;
        SetDrawOffset(p->d58, &ofs);
    } else {
        SetDrawOffset(p->d4C, pp);
        SetDrawOffset(p->d58, pp);
    }
}

EXTERN_C int func_8002D8AC(void *p, void *it, int v)
{
    void *o;
    if (!DRW(p)->unk64)
        return 0;
    for (((S_Iter *)it)->it = 0; (o = ((S_Iter *)it)->next()) != 0;)
        if (((int (*)(void *, void *))func_8001A6A8)(DRW(p)->unk64, o) != v)
            return v;
    return 0;
}

EXTERN_C void func_8002D94C(S_8002D94C *p)
{
    p->add(&p->mode[D_800B4CF0].tag, p->count - 1);
    p->add(&p->mode2[D_800B4CF0].tag, p->count - 1);
    D_800B4CFC = p;
    for (S_Node8 *n = p->list; n; n = n->next)
        ((void (*)(void *))n->vt[3].pfn)((char *)n + n->vt[3].delta);
}

EXTERN_C void *func_8002DA94(void *p, void *it)
{
    S_Lnk64 *o;
    ((S_Iter *)it)->it = 0;
    while ((o = (S_Lnk64 *)((S_Iter *)it)->next()) != 0) {
        S_Lnk64 *h = (S_Lnk64 *)DRW(p)->unk64;
        if (h) {
            if (o->next)
                func_8001A864(h, o->next);
            o->next = h;
        }
        DRW(p)->unk64 = o;
    }
    return it;
}

EXTERN_C void func_8002DB50(void *p, int del)
{
    if (DRW(p)->unk64) {
        if (del)
            new S_DeleteObj(DRW(p)->unk64);
        DRW(p)->unk64 = 0;
    }
}

EXTERN_C int func_8002DC34(void *p, int a, int del)
{
    if (DRW(p)->unk64 && ((int (*)(void *, int))func_8001A6A8)(DRW(p)->unk64, a)) {
        DRW(p)->unk64 = func_8001A744(DRW(p)->unk64, (void *)a);
        if (del)
            new S_DeleteObj((void *)a);
        return a;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002C90C", func_8002DD34);

EXTERN_C void func_8002DE7C()
{
    int i, j;
    S_Sh4 *p = D_800AC730;
    S_Sh2 *q;
    for (i = 1; i != -1; i--) {
        p->a = 0; p->b = 0; p->c = 0; p->d = 0; p++;
    }
    q = D_800B4CF4;
    for (j = 1; j != -1; j--) {
        q->a = 0; q->b = 0; q++;
    }
}
