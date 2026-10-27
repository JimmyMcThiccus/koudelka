#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8002DED8.h"

EXTERN_C void func_8002DED8(void *p, int a)
{
    func_8002DD34(p, a);
}

EXTERN_C void func_8002DEF8(void *p, int a, int b)
{
    func_8002DC34(p, a, b);
}

EXTERN_C void func_8002DF18(void *p, void *it)
{
    func_8002DA94(p, it);
}

EXTERN_C S_Lnk64 *func_8002DF38(S_8002DF38 *p, S_Lnk64 *q)
{
    S_Lnk64 *o = p->unk64;
    if (o) {
        if (q->next)
            func_8001A864(o, q->next);
        q->next = o;
    }
    p->unk64 = q;
    return q;
}

EXTERN_C S_Lnk64 *func_8002DF9C(S_8002DF38 *p, S_Lnk64 *q)
{
    S_Lnk64 *o = p->unk64;
    if (o) {
        if (q->next)
            func_8001A864(o, q->next);
        q->next = o;
    }
    p->unk64 = q;
    return q;
}

EXTERN_C void func_8002E000(void *p, void *it, int v)
{
    func_8002D8AC(p, it, v);
}

EXTERN_C int func_8002E020(S_8002E020 *p, int a)
{
    int r = 0;
    if (p->unk64)
        r = ((int (*)(void *, int))func_8001A6A8)(p->unk64, a) != 0;
    return r;
}

EXTERN_C int func_8002E054(S_8002E020 *p, int a)
{
    int r = 0;
    if (p->unk64)
        r = ((int (*)(void *, int))func_8001A6A8)(p->unk64, a) != 0;
    return r;
}

EXTERN_C S_Rgb func_8002E088(S_8002E088 *p)
{
    return p->unk28;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E0A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E2AC);

EXTERN_C void *func_8002E4B8(S_8002E4B8 *p)
{
    return &p->unk20;
}

EXTERN_C void func_8002E4C0(S_8002E4B8 *p)
{
    p->unk2C = 1;
}

EXTERN_C void func_8002E4CC(S_8002E4B8 *p)
{
    p->unk2C = 0;
}

EXTERN_C void func_8002E4D4(S_8002E4B8 *p, int v)
{
    p->unk1C = v;
}

EXTERN_C int func_8002E4DC(S_8002E4B8 *p)
{
    return p->unk1C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E4E8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E564);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E5B0);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E5D0);

EXTERN_C int func_8002E5F0()
{
    return D_800AC809[0] != 0;
}

EXTERN_C S_Lnk64 *func_8002E600(S_NodeVec *p)
{
    S_Lnk64 *first = p->first();
    S_Lnk64 *last = first;
    int i = 1;
    while (1) {
        S_Lnk64 *n;
        if (!(i < p->count))
            break;
        n = (S_Lnk64 *)func_80019F64((List *)p, i);
        last->next = n;
        last = n;
        i++;
    }
    last->next = 0;
    return first;
}

EXTERN_C S_IntVec *func_8002E69C(S_IntVec *p, S_Lnk64 *n, int unlink)
{
    S_Lnk64 *c;
    if (unlink) {
        while (1) {
            c = n;
            if (!c)
                break;
            func_80019A6C(p, (int)c, p->count);
            n = c->next;
            c->next = 0;
        }
    } else {
        c = n;
        while (1) {
            if (!c)
                break;
            func_80019A6C(p, (int)c, p->count);
            c = c->next;
        }
    }
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E714);

EXTERN_C void func_8002E7A8(S_8002E7A8 *p, int flags)
{
    p->vt = D_800117BC;
    if (p->unk8)
        func_800A0D0C(p->unk8);
    if (p->unkC)
        func_800A0D0C(p->unkC);
    func_8001A610(p, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E814);

EXTERN_C int func_8002E898(S_8002E898 *p, P_TAG *prim, unsigned int i)
{
    if (i && i < p->count) {
        prim->addr = p->tab[i];
        p->tab[i] = (unsigned long)prim & 0x00ffffff;
        return 1;
    }
    return 0;
}

EXTERN_C int func_8002E908(S_8002E908 *p)
{
    return p->unk10;
}

EXTERN_C int func_8002E914(S_8002E908 *p)
{
    return p->unk10;
}

EXTERN_C int func_8002E920(S_8002E908 *p)
{
    return p->unk4;
}

EXTERN_C void func_8002E92C(S_VObj *o, short x, short y)
{
    short w = ((short (*)(void *))o->vt[12].pfn)((char *)o + o->vt[12].delta);
    short h = ((short (*)(void *))o->vt[11].pfn)((char *)o + o->vt[11].delta);
    S_Rect r(x, y);
    r.w = w;
    r.h = h;
    ((void (*)(void *, S_Rect *))o->vt[10].pfn)((char *)o + o->vt[10].delta, &r);
}

EXTERN_C void func_8002E9D0(S_VObj *o, S_Pt2 pt)
{
    ((void (*)(void *, int, int))o->vt[8].pfn)((char *)o + o->vt[8].delta, pt.x, pt.y);
}

EXTERN_C int func_8002EA0C(S_8002E908 *p)
{
    return p->unk4;
}

EXTERN_C S_8002EA18 *func_8002EA18(S_8002EA18 *p, int a)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_800111BC;
    p->unk8 = 0;
    p->unkA = a;
    p->vt = D_800117D4;
    return p;
}

EXTERN_C void func_8002EA50(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C S_8002EA70 *func_8002EA70(S_8002EA70 *p, S_8002EA70_Src *src)
{
    p->vt = D_8001183C;
    p->src = src;
    p->blk = src->blk;
    return p;
}

EXTERN_C void func_8002EAAC()
{
}

EXTERN_C void func_8002EAB4()
{
}

EXTERN_C void func_8002EABC()
{
}

EXTERN_C void func_8002EAC4()
{
}

EXTERN_C void func_8002EACC()
{
}

EXTERN_C void func_8002EAD4()
{
}

EXTERN_C void func_8002EADC(S_8002E908 *p, int a, int b)
{
    p->unk8 = a;
    p->unkA = b;
}

EXTERN_C void func_8002EAE8(S_8002E908 *p, int a, int b)
{
    p->unkC = a;
    p->unkE = b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002EAF4);

EXTERN_C int func_8002EB68(S_8002EB68 *p)
{
    S_IntVec *v = (S_IntVec *)&D_800AC820;
    int t = v->count ? v->data[v->count - 1] : 0;
    S_8002EB68_O *o;
    if (t)
        return t;
    o = p->unk4->unk4;
    if (o)
        return ((int (*)(void *))o->vt[12].pfn)((char *)o + o->vt[12].delta);
    return 0;
}

EXTERN_C S_8002EBF0 *func_8002EBF0(S_8002EBF0 *p)
{
    p->unk0 = 0;
    p->unk2 = 0;
    return p;
}

EXTERN_C S_8002EC00 *func_8002EC00(S_8002EC00 *p)
{
    p->unk0 = 0;
    p->unk2 = 0;
    p->unk4 = 0;
    p->unk6 = 0;
    return p;
}

EXTERN_C S_8002EC18 *func_8002EC18(S_8002EC18 *p)
{
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    return p;
}

EXTERN_C void func_8002EC30()
{
}

EXTERN_C int func_8002EC38()
{
    return 0;
}

EXTERN_C void func_8002EC40(S_8002EC40 *p)
{
    if (func_8002A2D8(p->unk4))
        VCALL0(p, 4);
}

EXTERN_C void func_8002EC90(S_8002EC40 *p)
{
    if (func_8002A2D8(p->unk4))
        VCALL0(p, 4);
}

EXTERN_C void func_8002ECE0()
{
}

EXTERN_C void func_8002ECE8()
{
}

EXTERN_C void func_8002ECF0()
{
    func_80019920((List *)&D_800AC820, 2);
}

EXTERN_C void func_8002ED18()
{
    func_800198E0(&D_800AC820, 0x10, 0);
}
