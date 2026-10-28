#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_80029BBC.h"

EXTERN_C int func_80029BBC(S_80029BBC *p)
{
    return ((((p->r << 5) + (p->g >> 3)) << 5) + (p->b >> 3)) << 5 | (p->a >> 3);
}

EXTERN_C int func_80029BF4(S_80029BF4 *p)
{
    return p->unk7;
}

EXTERN_C int func_80029C00(S_80029BF4 *p)
{
    return p->unk6;
}

EXTERN_C int func_80029C0C(S_80029BF4 *p)
{
    return p->unk5;
}

EXTERN_C S_8001A294 *func_80029C18(S_8001A294 *p, S_8001A294 *q)
{
    p->vtbl = D_80011384;
    p->unk4 = q->unk4;
    return p;
}

EXTERN_C void func_80029C34(void *p, int a)
{
    func_800198AC(p, a);
}

EXTERN_C S_W *func_80029C54(S_W *p, int in_chrg, short a)
{
    if (in_chrg) {
        p->unk0 = (int)((char *)p + 0x30);
        new ((char *)p + 0x30) S_VB30;
    }
    ((S_VB50 *)p->unk0)->vt = (VEnt *)D_8001147C.e;
    if (!in_chrg) {
        VTab50 tmp = D_8001147C;
        ((S_VB50 *)p->unk0)->vt = tmp.e;
        char *q = (char *)p->unk0 - 0x30;
        int adj = (char *)p - q;
        tmp.e[1].d = D_8001147C.e[1].d + adj;
        tmp.e[5].d = D_8001147C.e[5].d + adj;
        tmp.e[7].d = D_8001147C.e[7].d + adj;
        tmp.e[9].d = D_8001147C.e[9].d + adj;
    }
    p->vt = (VEnt *)D_80011394;
    p->unk14 = (int)D_800B4C98;
    p->unk18 = (int)D_800B4C80;
    p->unk20 = 1;
    p->unk24 = 1;
    p->unk28 = 1;
    p->unk4 = 0;
    p->unk8 = 0;
    p->x = 0;
    p->y = 0;
    p->w = 0;
    p->h = 0;
    *(short *)&p->unk1C = a;
    return p;
}

EXTERN_C void func_80029D74(S_W *p, int flags)
{
    p->vt = (VEnt *)D_80011394;
    ((S_VB50 *)p->unk0)->vt = (VEnt *)D_8001147C.e;
    if (!flags) {
        VTab50 tmp = D_8001147C;
        ((S_VB50 *)p->unk0)->vt = tmp.e;
        char *q = (char *)p->unk0 - 0x30;
        int adj = (char *)p - q;
        tmp.e[1].d = D_8001147C.e[1].d + adj;
        tmp.e[5].d = D_8001147C.e[5].d + adj;
        tmp.e[7].d = D_8001147C.e[7].d + adj;
        tmp.e[9].d = D_8001147C.e[9].d + adj;
    }
    vdel_80029D74(p->unk8);
    if (p->unk4) {
        S_W *o = p->unk4;
        p->unk4 = 0;
        func_8002B27C(o, p);
    }
    if (flags & 2)
        func_8001A610((void *)p->unk0, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void func_80029EB8()
{
}

EXTERN_C void func_80029EC0()
{
}

EXTERN_C S_Rgb func_80029EC8(S_80029EC8 *p)
{
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[13];
        return ((S_Rgb (*)(void *))e->f)((char *)o + e->d);
    }
    return p->unk10;
}

EXTERN_C S_Box2 func_80029F30(S_W *p)
{
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[14];
        return ((S_Box2 (*)(void *))e->f)((char *)o + e->d);
    }
    VEnt *e = &p->vt[10];
    return box_at_origin(((S_XY (*)(void *))e->f)((char *)p + e->d));
}

EXTERN_C int func_80029FC0(S_Node *p)
{
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[12];
        return ((int (*)(void *))e->f)((char *)o + e->d);
    }
    return 0;
}

EXTERN_C void func_8002A004(S_8002A004 *p)
{
    if (p->unk28 == 0)
        p->unk28 = 1;
}

EXTERN_C void func_8002A020(S_Node *p)
{
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[8];
        ((void (*)(void *))e->f)((char *)o + e->d);
    }
}

EXTERN_C bool func_8002A064(void *q, int x, int y)
{
    S_8002A064 *p = (S_8002A064 *)q;
    bool r = 0;
    if (x >= 0 && x < p->w && y >= 0)
        r = y < p->h;
    return r;
}

EXTERN_C void *func_8002A09C(void *p, int x, int y)
{
    return func_8002A064(p, x, y) ? p : 0;
}

EXTERN_C void *func_8002A0D0(void *p, S_Pt *pt)
{
    return func_8002A064(p, pt->x, pt->y) ? p : 0;
}

EXTERN_C void func_8002A110(S_8002A110 *p)
{
    p->unk28 = 0;
}

EXTERN_C void func_8002A118(S_Node *p)
{
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[1];
        ((void (*)(void *, int))e->f)((char *)o + e->d, 3);
        p->unk8 = 0;
    }
}

EXTERN_C void func_8002A168(S_Node *p)
{
    if (!p->unk24) {
        VObj *o = p->unk8;
        p->unk24 = 1;
        if (o) {
            VEnt *e = &o->vt[6];
            ((void (*)(void *))e->f)((char *)o + e->d);
        }
    }
}

EXTERN_C void func_8002A1BC(S_Node *p)
{
    if (p->unk24) {
        VObj *o = p->unk8;
        p->unk24 = 0;
        if (o) {
            VEnt *e = &o->vt[7];
            ((void (*)(void *))e->f)((char *)o + e->d);
        }
    }
}

EXTERN_C void func_8002A210(S_Node *p)
{
    VObj *o = p->unk8;
    p->unk20 = 1;
    if (o) {
        VEnt *e = &o->vt[4];
        ((void (*)(void *))e->f)((char *)o + e->d);
        if (p->unk4)
            func_8002A444(p->unk4);
    }
}

EXTERN_C void func_8002A274(S_Node *p)
{
    VObj *o = p->unk8;
    p->unk20 = 0;
    if (o) {
        VEnt *e = &o->vt[5];
        ((void (*)(void *))e->f)((char *)o + e->d);
        if (p->unk4)
            func_8002A444(p->unk4);
    }
}

EXTERN_C int func_8002A2D8(S_Node *p)
{
    return p->unk8 && p->unk20 && (!p->unk4 || func_8002A2D8(p->unk4));
}

EXTERN_C void func_8002A33C(S_Node *p)
{
    if (!p->unk14 && p->unk4)
        func_8002A33C(p->unk4);
}

EXTERN_C void func_8002A37C(S_Node *p, int a)
{
    VObj *o = p->unk8;
    p->unk14 = a;
    if (o) {
        VEnt *e = &o->vt[17];
        ((void (*)(void *, int))e->f)((char *)o + e->d, a);
    }
}

EXTERN_C void func_8002A3C0(S_Node *p)
{
    if (!p->unk18 && p->unk4)
        func_8002A3C0(p->unk4);
}

EXTERN_C void func_8002A400(S_Node *p, int a)
{
    VObj *o = p->unk8;
    p->unk18 = a;
    if (o) {
        VEnt *e = &o->vt[18];
        ((void (*)(void *, int))e->f)((char *)o + e->d, a);
    }
}

EXTERN_C void func_8002A444(S_Node *p)
{
    S_Node *q = p->unk4;
    p->unk28 = 0;
    if (q && q->unk28)
        func_8002A444(q);
}

EXTERN_C int func_8002A484(S_Node2C *p)
{
    VObj2C *o = p->unk4;
    if (o) {
        VEnt *e = &o->vt[25];
        return ((int (*)(void *))e->f)((char *)o + e->d);
    }
    return 0;
}

EXTERN_C void func_8002A4C8(S_W *p, int x, int y)
{
    if (p->x != x || p->y != y) {
        VObj *o = p->unk8;
        p->x = x;
        p->y = y;
        if (o) {
            VEnt *e = &o->vt[10];
            ((void (*)(void *))e->f)((char *)o + e->d);
            if (p->unk4 && p->unk4->unk28)
                func_8002A444((S_Node *)p->unk4);
        }
    }
}

EXTERN_C void func_8002A55C(S_W *p, int w, int h)
{
    if (p->w != w || p->h != h) {
        VObj *o = p->unk8;
        p->w = w;
        p->h = h;
        if (o) {
            VEnt *e = &o->vt[11];
            ((void (*)(void *))e->f)((char *)o + e->d);
            func_8002A444((S_Node *)p);
            if (p->unk4 && p->unk4->unk28)
                func_8002A444((S_Node *)p->unk4);
        }
    }
}

EXTERN_C void func_8002A5F8(VObj2C *p)
{
    VEnt *e = &p->vt[12];
    int r = ((int (*)(void *))e->f)((char *)p + e->d);
    if (r) {
        e = &p->vt[14];
        ((void (*)(void *, int))e->f)((char *)p + e->d, r);
    }
}

EXTERN_C void func_8002A65C(VObj2C *p, int a)
{
    VEnt *e = &p->vt[14];
    ((void (*)(void *, int))e->f)((char *)p + e->d, a);
}

EXTERN_C void func_8002A698(S_W *p, int a)
{
    if (p->unk20 && p->unk8) {
        VEnt *e = &p->vt[13];
        ((void (*)(void *))e->f)((char *)p + e->d);
        VObj *o = p->unk8;
        e = &o->vt[8];
        ((void (*)(void *, int))e->f)((char *)o + e->d, a);
    }
}

EXTERN_C void func_8002A728(S_W *p, S_8002A728 *ev)
{
    VEnt *e;
    switch (ev->type & 0xFF00) {
    case 0x200:
        e = &p->vt[23];
        ((void (*)(void *, S_8002A728 *))e->f)((char *)p + e->d, ev);
        break;
    case 0x800:
        e = &p->vt[24];
        ((void (*)(void *, S_8002A728 *))e->f)((char *)p + e->d, ev);
        break;
    default:
        e = &p->vt[22];
        ((void (*)(void *, S_8002A728 *))e->f)((char *)p + e->d, ev);
        break;
    }
}

EXTERN_C int func_8002A7B8(C_VD *p, int a)
{
    if (p->v4(a))
        return 1;
    S_W *q = p->parent;
    if (q) {
        VEnt *e = &q->vt[22];
        if (((int (*)(void *, int))e->f)((char *)q + e->d, a))
            return 1;
    }
    return 0;
}

EXTERN_C int func_8002A864(C_VD *p, int a)
{
    if (p->v6(a))
        return 1;
    S_W *q = p->parent;
    if (q) {
        VEnt *e = &q->vt[23];
        if (((int (*)(void *, int))e->f)((char *)q + e->d, a))
            return 1;
    }
    return 0;
}

EXTERN_C int func_8002A910(C_VD *p, int a)
{
    if (p->v8(a))
        return 1;
    S_W *q = p->parent;
    if (q) {
        VEnt *e = &q->vt[24];
        if (((int (*)(void *, int))e->f)((char *)q + e->d, a))
            return 1;
    }
    return 0;
}

EXTERN_C int func_8002A9BC(C_VD *p, int a)
{
    if (p->v4(a))
        return 1;
    int r = 0;
    if (p->unk4) {
        C_VB *b = p;
        if (b->unk4->v5(a))
            r = 1;
    }
    return r;
}

EXTERN_C int func_8002AA8C(C_VD *p, int a)
{
    if (p->v6(a))
        return 1;
    int r = 0;
    if (p->unk4) {
        C_VB *b = p;
        if (b->unk4->v7(a))
            r = 1;
    }
    return r;
}

EXTERN_C int func_8002AB5C(C_VD *p, int a)
{
    if (p->v8(a))
        return 1;
    int r = 0;
    if (p->unk4) {
        C_VB *b = p;
        if (b->unk4->v9(a))
            r = 1;
    }
    return r;
}

EXTERN_C void func_8002AC2C(S_8002AC2C *p)
{
    if (p->unk4)
        func_8002BBD4(p->unk4, p);
}

EXTERN_C S_XY func_8002AC60(S_W *p, S_XY pos)
{
    S_XY t = p->unk4 ? func_8002AC60(p->unk4, pos) : pos;
    return S_XY(t.x + p->x, t.y + p->y);
}

EXTERN_C void func_8002AD0C(void *p, S_8002AD0C *q)
{
    func_8002A064(p, q->unk0, q->unk2);
}

EXTERN_C void func_8002AD38(VObj2C *p, int x, int y, int w, int h)
{
    VEnt *e = &p->vt[8];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, x, y);
    e = &p->vt[9];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, w, h);
}

EXTERN_C void func_8002ADA8(VObj2C *p, short *r)
{
    VEnt *e = &p->vt[8];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, r[0], r[1]);
    e = &p->vt[9];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, r[2], r[3]);
}

EXTERN_C void func_8002AE14(VObj2C *p, S_Pt *pt)
{
    VEnt *e = &p->vt[9];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, pt->x, pt->y);
}

EXTERN_C void func_8002AE50(VObj2C *p, S_Pt *pt)
{
    VEnt *e = &p->vt[8];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, pt->x, pt->y);
}

EXTERN_C void func_8002AE8C(VObj2C *p, int a)
{
    if (a) {
        VEnt *e = &p->vt[4];
        ((void (*)(void *))e->f)((char *)p + e->d);
    } else {
        VEnt *e = &p->vt[5];
        ((void (*)(void *))e->f)((char *)p + e->d);
    }
}

EXTERN_C void func_8002AEE0(VObj2C *p, int a)
{
    if (a) {
        VEnt *e = &p->vt[2];
        ((void (*)(void *))e->f)((char *)p + e->d);
    } else {
        VEnt *e = &p->vt[3];
        ((void (*)(void *))e->f)((char *)p + e->d);
    }
}

EXTERN_C void *func_8002AF34(S_8002AF34 *p)
{
    return &p->unkC;
}

EXTERN_C S_Rgb func_8002AF3C(S_80025A64 *p)
{
    return p->unk10;
}

EXTERN_C S_Rgb func_8002AF5C(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C int func_8002AF7C(S_8002AF34 *p)
{
    return p->unk24;
}

EXTERN_C int func_8002AF88(S_8002AF34 *p)
{
    return p->unk20;
}

EXTERN_C int func_8002AF94(S_8002AF94 *p)
{
    int r = 0;
    if (p->unk8)
        r = p->unk28 != 0;
    return r;
}

EXTERN_C int func_8002AFB8(S_8002AF34 *p)
{
    return p->unk1C;
}

EXTERN_C void func_8002AFC4(S_8002AF34 *p, int v)
{
    p->unk1C = v;
}

EXTERN_C int func_8002AFCC(S_8002AF34 *p)
{
    return p->unk8;
}

EXTERN_C int func_8002AFD8(S_8002AF34 *p)
{
    return p->unk4;
}

EXTERN_C void func_8002AFE4(S_8002AF34 *p, int v)
{
    p->unk4 = v;
}

EXTERN_C void func_8002AFEC(S_8002AFEC *p, int flags)
{
    p->vt2C = D_8001151C;
    p->vb->vt = (VEnt *)D_800114CC.e;
    if (!flags) {
        VTab50 tmp = D_800114CC;
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - 0x50;
        int adj = (char *)p - q;
        tmp.e[1].d = D_800114CC.e[1].d + adj;
        tmp.e[5].d = D_800114CC.e[5].d + adj;
        tmp.e[7].d = D_800114CC.e[7].d + adj;
        tmp.e[9].d = D_800114CC.e[9].d + adj;
    }
    func_8002B36C((S_W *)p);
    func_80019920(p->unk30, 0);
    func_80029D74((S_W *)p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C Item *func_8002B108(S_W *p, int i)
{
    if (i < 0 || i >= coll_list(&p->coll)->count)
        return 0;
    return func_80019F64(coll_h(&p->coll), i);
}

EXTERN_C S_W *func_8002B174(S_W *p, S_W *c, int i)
{
    if (i < 0 || i >= coll_list(&p->coll)->count)
        i = coll_list(&p->coll)->count;
    if (func_80019C24(coll_list(&p->coll), c))
        return 0;
    func_80019A6C(coll_list(&p->coll), (int)c, i);
    c->unk4 = p;
    if (p->unk28)
        func_8002A444((S_Node *)p);
    if (p->unk8) {
        VEnt *e = &c->vt[26];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
    return c;
}

EXTERN_C void func_8002B27C(S_W *p, S_W *c)
{
    int found = 0;
    if (func_80019CFC((List *)coll_h(&p->coll), c) && c->unk4 == p)
        found = 1;
    if (found) {
        if (p->unk8) {
            VEnt *e = &c->vt[27];
            ((void (*)(void *))e->f)((char *)c + e->d);
        }
        c->unk4 = 0;
        del_vb(c);
        if (p->unk28)
            func_8002A444((S_Node *)p);
    }
}

EXTERN_C void func_8002B36C(S_W *p)
{
    S_W *c;
    coll_end(&p->coll);
    while ((c = (S_W *)p->coll.prev()) != 0) {
        if (p->unk8) {
            VEnt *e = &c->vt[27];
            ((void (*)(void *))e->f)((char *)c + e->d);
        }
        c->unk4 = 0;
        del_vb(c);
    }
    func_80019D40((S_80019D40 *)coll_list(&p->coll));
    if (p->unk28)
        func_8002A444((S_Node *)p);
}

EXTERN_C void func_8002B47C(S_W *p, int x, int y)
{
    VObj2C *c;
    func_8002A4C8(p, x, y);
    p->coll.reset();
    while ((c = p->coll.next()) != 0) {
        VEnt *e = &c->vt[1];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
}

EXTERN_C void func_8002B518(S_W *p, int x, int y)
{
    VObj2C *c;
    func_8002A55C(p, x, y);
    p->coll.reset();
    while ((c = p->coll.next()) != 0) {
        VEnt *e = &c->vt[1];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
}

EXTERN_C void func_8002B5B4(S_W *p)
{
    S_W *c;
    p->coll.reset();
    while ((c = (S_W *)p->coll.next()) != 0) {
        if (!W_active(c)) {
            VEnt *e = &c->vt[13];
            ((void (*)(void *))e->f)((char *)c + e->d);
        }
    }
    func_8002A004((S_8002A004 *)p);
}

EXTERN_C void func_8002B67C(S_W *p)
{
    if (p->unk20 && p->unk8) {
        VEnt *e = &p->vt[13];
        ((void (*)(void *))e->f)((char *)p + e->d);
        VObj *o = p->unk8;
        e = &o->vt[4];
        ((void (*)(void *))e->f)((char *)o + e->d);
    }
}

EXTERN_C void func_8002B6FC(S_W *p, int a)
{
    VObj2C *c;
    p->coll.toEnd();
    while ((c = p->coll.prev()) != 0) {
        VEnt *e = &c->vt[17];
        ((void (*)(void *, int))e->f)((char *)c + e->d, a);
    }
}

EXTERN_C int func_8002B7A4(S_W *p, int a)
{
    C_VD *c;
    p->coll.idx = 0;
loop:
    c = (C_VD *)p->coll.next();
    if (!c)
        return func_8002A9BC((C_VD *)p, a);
    if (c->v5(a))
        return 1;
    goto loop;
}

EXTERN_C int func_8002B854(S_W *p, int a)
{
    C_VD *c;
    p->coll.idx = 0;
loop:
    c = (C_VD *)p->coll.next();
    if (!c)
        return func_8002AA8C((C_VD *)p, a);
    if (c->v7(a))
        return 1;
    goto loop;
}

EXTERN_C int func_8002B904(S_W *p, int a)
{
    C_VD *c;
    p->coll.idx = 0;
loop:
    c = (C_VD *)p->coll.next();
    if (!c)
        return func_8002AB5C((C_VD *)p, a);
    if (c->v9(a))
        return 1;
    goto loop;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B9B4);

EXTERN_C void func_8002BA94(S_W *p)
{
    VObj2C *c;
    p->coll.reset();
    while ((c = p->coll.next()) != 0) {
        VEnt *e = &c->vt[26];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
    func_8002A110((S_8002A110 *)p);
}

EXTERN_C void func_8002BB34(S_W *p)
{
    VObj2C *c;
    p->coll.reset();
    while ((c = p->coll.next()) != 0) {
        VEnt *e = &c->vt[27];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
    func_8002A118((S_Node *)p);
}

EXTERN_C void func_8002BBD4(S_8002BBD4 *p, void *a)
{
    func_80019F0C(&p->unk30, a, 0);
}

EXTERN_C void func_8002BC08(S_W *p)
{
    VObj2C *c;
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[10];
        ((void (*)(void *, int, int))e->f)((char *)o + e->d, p->x, p->y);
    }
    p->coll.reset();
    while ((c = p->coll.next()) != 0) {
        VEnt *e = &c->vt[1];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
}

EXTERN_C S_Vec4z func_8002BCD0(S_Node *p)
{
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[15];
        return ((S_Vec4z (*)(void *))e->f)((char *)o + e->d);
    }
    return S_Vec4z();
}

EXTERN_C void func_8002BD34(S_W *p)
{
    VObj2C *c;
    p->coll.toEnd();
    while ((c = p->coll.prev()) != 0) {
        VEnt *e = &c->vt[18];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[19];
        ((void (*)(void *))e->f)((char *)o + e->d);
    }
}

EXTERN_C int func_8002BDFC(S_W *p)
{
    S_Rc8 box;
    box.x = 0;
    box.y = 0;
    box.w = 0;
    box.h = 0;
    VObj2C *c;
    p->coll.reset();
    while ((c = p->coll.next()) != 0) {
        VEnt *e = &c->vt[11];
        S_Rc8 r = ((S_Rc8 (*)(void *))e->f)((char *)c + e->d);
        box.unite(r);
    }
    if (box == S_Rc8(0, 0, 0, 0))
        return 0;
    S_XY off;
    S_XY tl = *(S_XY *)&box;
    off.x = -tl.x;
    off.y = -tl.y;
    p->coll.reset();
    while ((c = p->coll.next()) != 0) {
        VEnt *e = &c->vt[8];
        ((void (*)(void *, int, int))e->f)((char *)c + e->d, off.x, off.y);
    }
    VEnt *e = &p->vt[9];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, box.w, box.h);
    return 1;
}

EXTERN_C int func_8002C084(VObj2C *p)
{
    VEnt *e = &p->vt[10];
    S_Pt pt = ((S_Pt (*)(void *))e->f)((char *)p + e->d);
    e = &p->vt[9];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, pt.x, pt.y);
    return 1;
}

EXTERN_C void func_8002C0E4(VObj2C *p, S_Pt *pt)
{
    VEnt *e = &p->vt[9];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, pt->x, pt->y);
}

EXTERN_C void func_8002C120(VObj2C *p, S_Pt *pt)
{
    VEnt *e = &p->vt[8];
    ((void (*)(void *, int, int))e->f)((char *)p + e->d, pt->x, pt->y);
}

EXTERN_C int func_8002C15C(S_8002C15C *p)
{
    return count_of(&p->unk30);
}

EXTERN_C int func_8002C17C(S_8002C17C *p)
{
    return p->unk8;
}

EXTERN_C S_8002C188 *func_8002C188(S_8002C188 *p, int in_chrg)
{
    if (in_chrg) {
        p->vb = (S_VB50 *)((char *)p + 0x50);
        new ((char *)p + 0x50) S_VB30;
    }
    func_80029C54((S_W *)p, 0, 2);
    p->vb->vt = (VEnt *)D_800114CC.e;
    if (!in_chrg) {
        VTab50 tmp = D_800114CC;
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - 0x50;
        int adj = (char *)p - q;
        tmp.e[1].d = D_800114CC.e[1].d + adj;
        tmp.e[5].d = D_800114CC.e[5].d + adj;
        tmp.e[7].d = D_800114CC.e[7].d + adj;
        tmp.e[9].d = D_800114CC.e[9].d + adj;
    }
    p->vt2C = D_8001151C;
    S_8002C188m *m = (S_8002C188m *)((char *)p + 0x30);
    m->vbp = m->vbase;
    m->vb = m->vbase;
    func_800198E0(m->vbp, 0x10, 4);
    m->idx = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C2B8);

EXTERN_C void func_8002C498(S_W *p)
{
    if (!p->unk8) {
        S_8002C498 *o = (S_8002C498 *)operator new(0x1C);
        func_8002EEC4(o, p);
        o->vt = D_8001199C;
        o->unk14 = 0;
        func_8002EC90(o, D_800B4C88);
        p->unk8 = (VObj *)o;
    }
    func_8002BA94(p);
}

EXTERN_C void func_8002C514(S_W *p)
{
    S_W *q = p->unk4;
    if (q && !q->unk8) {
        VEnt *e = &q->vt[26];
        ((void (*)(void *))e->f)((char *)q + e->d);
    }
    if (!p->unk8) {
        VEnt *e = &p->vt[26];
        ((void (*)(void *))e->f)((char *)p + e->d);
    }
    VEnt *e = &p->vt[13];
    ((void (*)(void *))e->f)((char *)p + e->d);
    if (!p->unk20) {
        VObj *o = p->unk8;
        p->unk20 = 1;
        e = &o->vt[4];
        ((void (*)(void *))e->f)((char *)o + e->d);
    }
}

EXTERN_C void func_8002C5EC(S_W *p)
{
    VObj2C *c;
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[19];
        ((void (*)(void *))e->f)((char *)o + e->d);
    }
    p->coll.reset();
    while ((c = p->coll.next()) != 0) {
        VEnt *e = &c->vt[18];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
    if (p->unk8)
        func_8002F464(p->unk8);
}

EXTERN_C int func_8002C6C8(S_8002C6C8 *p)
{
    return p->unk8;
}

EXTERN_C void func_8002C6D4(S_8002C6D4 *p, int flags)
{
    p->vt2C = D_8001167C;
    p->vb->vt = (VEnt *)D_8001162C.e;
    if (!flags) {
        VTab50 tmp = D_8001162C;
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - 0x50; /* the full object holding the virtual base */
        int adj = (char *)p - q;
        tmp.e[1].d = D_8001162C.e[1].d + adj;
        tmp.e[5].d = D_8001162C.e[5].d + adj;
        tmp.e[7].d = D_8001162C.e[7].d + adj;
        tmp.e[9].d = D_8001162C.e[9].d + adj;
    }
    func_8002AFEC(p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void func_8002C7DC()
{
    VObj *c;
    D_800AC710_g.toEnd();
    while ((c = D_800AC710_g.prev()) != 0) {
        VEnt *e = &c->vt[2];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
    func_80019D40((S_80019D40 *)(List *)&D_800AC710);
    D_800B4CF0 ^= 1;
}

EXTERN_C void func_8002C8A4()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC710)->p, 0);
}

EXTERN_C void func_8002C8CC()
{
    S_8002C8CC *s = (S_8002C8CC *)&D_800AC710;
    s->q = s->data;
    s->p = s->data;
    func_800198E0(s->data, 16, 4);
    s->n = 0;
}
