#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_80020368.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020368);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_8002042C);

EXTERN_C void func_80020510(S_80020510 *p, int v)
{
    p->unk1A = v;
}

EXTERN_C void func_80020518(S_80020510 *p, int v)
{
    p->unk18 = v;
}

EXTERN_C int func_80020520(S_80020510 *p)
{
    return p->unk1A;
}

EXTERN_C int func_8002052C(S_80020510 *p)
{
    return p->unk18;
}

S_80020538::S_80020538(unsigned short a, short b, short c, int d, unsigned short e, int f)
{
    func_8001FC38(this, a, d, e);
    vt = D_800105DC;
    unk14 = f;
    vt = D_80010588;
    unk18 = b;
    unk1A = c;
}

EXTERN_C void func_800205B4(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C void func_800205D4(int a)
{
    S_VObj *o;
    G_6C4.it = 0;
    while ((o = G_6C4.next()) != 0) {
        ((void (*)(void *, int))func_80020948)(o, a);
        if (((S_80020734 *)o)->unk4 == (S_VObj *)a)
            func_80020734(o, 0, 0, 0);
    }
}

EXTERN_C void func_8002068C()
{
    S_VObj *o;
    G_6C4.it = 0;
    while ((o = G_6C4.next()) != 0)
        VCALL0(o, 2);
}

EXTERN_C void func_8002072C()
{
}

#define P ((S_80020734 *)vp)
EXTERN_C void func_80020734(void *vp, int a, void *b, int c)
{
    if ((S_VObj *)a != P->unk4) {
        if (P->unk4)
            VCALL0(P->unk4, 2);
        P->unk4 = (S_VObj *)a;
        P->unk48 = 0;
    }
    P->unk54 = c;
    if (b)
        P->unk4C = ((S_80020734_B *)b)->unkC;
}
#undef P

EXTERN_C S_800207C4_R *func_800207C4(S_800207C4 *p, S_VObj *o)
{
    S_800207C4_R *r = 0;
    if (p->unk4 && p->unk54 && D_800A4534.unkC - p->unk4C >= p->unk52 + p->unk50 * p->unk48) {
        r = ((S_800207C4_R *(*)(void *))o->vt[2].pfn)((char *)o + o->vt[2].delta);
        r->unk8 = p;
        r->unk14 = ++p->unk48;
    }
    return r;
}

EXTERN_C S_80020884_Out *func_80020884(S_80020884 *p, S_80020884_Out *out)
{
    if (p->unk4 && D_800A4534.unkC - p->unk4C >= p->unk4A)
        p->unk48 = 0;
    out->unk14 = p->unk48;
    return out;
}

EXTERN_C int func_800208D4(char *p, void *item)
{
    Holder *h = (Holder *)(p + 8);
    if (!func_80019C24(h, item)) {
        List *l = h;
        func_80019A6C(l, (int)item, l->count);
        return 1;
    }
    return 0;
}

EXTERN_C int func_80020948(char *p, void *item)
{
    S_80020948 *m = (S_80020948 *)(p + 8);
    Holder *h = m;
    return func_80019CFC(h, item) != 0;
}

EXTERN_C int func_80020984(S_80020984 *p, void *item)
{
    if (func_80019C24(&p->h, item))
        return 0;
    func_80019A6C((List *)&p->h, (int)item, 0);
    return 1;
}

EXTERN_C int func_800209F4(char *p, void *item)
{
    char *q = p + 0x28;
    Holder *h = q ? (Holder *)(q + 8) : 0;
    return func_80019CFC(h, item) != 0;
}

EXTERN_C int func_80020A30(S_80020A30 *p, int a)
{
    S_VObj *o = p->unk4;
    if (o && ((int (*)(void *, int))o->vt[3].pfn)((char *)o + o->vt[3].delta, a))
        return 1;
    p->iter.it = p->iter.l->count;
    while ((o = p->iter.prev()) != 0) {
        if (((int (*)(void *, int))o->vt[3].pfn)((char *)o + o->vt[3].delta, a))
            return 1;
    }
    return 0;
}

EXTERN_C void func_80020B08()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC6C4)->p, 0);
}

EXTERN_C void func_80020B30()
{
    S_Arr8 *s = (S_Arr8 *)&D_800AC6C4;
    s->q = s->buf;
    ((S_Arr8 *)&D_800AC6C4)->p = s->buf;
    func_800198E0(s->buf, 8, 0);
    s->n = 0;
}
