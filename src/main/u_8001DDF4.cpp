#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8001DDF4.h"

EXTERN_C void func_8001DDF4(char *p, int flags)
{
    S_Obj4 *m;
    *(void ***)(p + 0x8C) = D_80010388;
    *(void ***)(p + 0xF8) = D_80010378;
    *(void ***)(p + 0x100) = D_800103A0;
    *(void ***)p = D_800103B8;
    func_8001D024(p + 0x100, 0);
    m = (S_Obj4 *)(p + 0xF8);
    m->vtbl = D_80010328;
    if (m->unk4)
        VCALL(m->unk4, 1, Fn_vi, 3);
    func_800198AC(m, 0);
    func_8001E508(p, flags);
}

EXTERN_C void func_8001DEB8(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800103E0;
    func_800198AC(p, a);
}

EXTERN_C void func_8001DEE0(S_Node *n, int flags)
{
    n->vtbl = D_800103D0;
    if (n->unk10 && n->unk8)
        VCALL(n->unk8, 1, Fn_vi, 3);
    func_8001A610(n, flags);
}

EXTERN_C void func_8001DF58(S_NodeList *l, int flags)
{
    S_Node *n = l->head;
    if (n)
        VCALL(n, 1, Fn_vi, 3);
    if (flags & 1)
        operator delete(l);
}

EXTERN_C int func_8001DFC0(S_NodeList *l)
{
    int r;
    S_Node *n;
    while (!(r = rand()))
        ;
    n = l->head;
    while (1) {
        if (!n)
            return r;
        if (r == n->unkC || r == 0) {
            r = rand();
            n = l->head;
        }
        n = n->next;
    }
}

EXTERN_C void func_8001E03C(S_NodeList *l, S_Node *n)
{
    if (l->head)
        func_8001A678(l->head, (int)n);
    else
        l->head = n;
}

EXTERN_C int func_8001E07C(S_NodeList *l, short id)
{
    S_Node *n = l->head;
    while (1) {
        if (!n)
            return 0;
        if (n->unkC == id) {
            l->head = (S_Node *)func_8001A744(l->head, n);
            if (((S_TargetI *)n->unk8)->f2(n->unk14 ? n->unk14 : n->unkC))
                VCALL(n, 1, Fn_vi, 3);
            else
                func_8001E03C(l, n);
            return 1;
        }
        n = n->next;
    }
}

EXTERN_C S_Node *func_8001E15C(S_NodeList *l, void *id)
{
    S_Node *n = l->head;
    if (!n)
        return 0;
    if (n->unk8 == id)
        return n;
    if (!n->next)
        return 0;
    return func_8001E248(n->next, id);
}

EXTERN_C void func_8001E1AC(S_NodeList *l, void *a, short b, int c, int d)
{
    func_8001E03C(l, (S_Node *)new S_Node3D0(a, b, c, d));
}

EXTERN_C S_8001E23C *func_8001E23C(S_8001E23C *p)
{
    p->unk0 = 0;
    return p;
}

EXTERN_C S_Node *func_8001E248(S_Node *n, void *id)
{
    if (n->unk8 == id)
        return n;
    if (!n->next)
        return 0;
    S_Node *r = func_8001E248(n->next, id);
    return r;
}

EXTERN_C void func_8001E288(S_Node *n)
{
    ((S_Target *)n->unk8)->f2(n->unk14 ? n->unk14 : n->unkC);
}

EXTERN_C void func_8001E2D8(S_8001E23C *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_8001E2E0(S_8001E23C *p)
{
    return p->unkC;
}

EXTERN_C int func_8001E2EC(S_8001E23C *p)
{
    return p->unk4;
}

EXTERN_C S_Node3D0 *func_8001E2F8(S_Node3D0 *p, void *a, short b, int c, int d)
{
    return new (p) S_Node3D0(a, b, c, d);
}

EXTERN_C S_Vobj *func_8001E330(S_Vobj *p)
{
    p->vtbl = D_800103E0;
    return p;
}

EXTERN_C int func_8001E344()
{
    return D_800B4C24++;
}

EXTERN_C void func_8001E360(S_Scn *s)
{
    List *l;
    D_800B4C18 = (S_8001F1BC *)s;
    s->unkF4 = 0;
    l = &D_800AC688;
    func_80019A6C(l, (int)s, l->count);
    func_80018EDC(s);
    func_800949B0(&((int *)s->unk88)[s->unk8 - 1]);
    ((S_SceneV *)s)->f2();
    if (s)
        VCALL(s, 1, Fn_vi, 3);
}

EXTERN_C S_Task *func_8001E40C(S_Task *p, void *a, short b, int c, int d)
{
    func_80018E5C((S_80018E5C *)p, c);
    new ((char *)p + 0x8C) S_Evt408(a);
    p->vtbl = D_80010420;
    p->unkA0 = 1;
    new ((char *)p + 0xA4) S_Vec1;
    func_8001F360((char *)p + 0xC4, p, 2);
    p->unk94 = b;
    if (!d)
        p->unkF0 = func_8001E344();
    else
        p->unkF0 = d;
    p->unkF4 = 3;
    return p;
}

EXTERN_C void func_8001E508(char *p, int flags)
{
    *(void ***)(p + 0x8C) = D_80010408;
    *(void ***)p = D_80010420;
    func_8001F3DC(p + 0xC4, 2);
    func_80019920(*(List **)(p + 0xA4), 0);
    func_8001A610(p + 0x8C, 0);
    func_80018E88(p, flags);
}

EXTERN_C void func_8001E57C(void *p)
{
    S_Task *s = (S_Task *)p;
    S_Evt *e;
    func_800186E8(&D_800A451C);
    e = (s ? (S_Evt *)((char *)s + 0x8C) : 0)->next;
    if (e && !(e->unk8 < s->unkA0)) {
        S_Task *prev = 0;
        S_Task *n = (S_Task *)D_800B4C1C;
        s->unkF4 = 1;
        while (1) {
            if (!n)
                break;
            if (!(n->unk94 > s->unk94 || (n->unk94 == s->unk94 && S_Evt_ge(n->cur, e))))
                break;
            prev = n;
            n = n->next;
        }
        if (prev) {
            s->next = 0;
            if (prev->next && s)
                func_8001A864(s, prev->next);
            prev->next = s;
        } else {
            s->next = n;
            D_800B4C1C = (S_8001F1BC *)s;
        }
    } else {
        void *t = D_800B4C20;
        s->unkF4 = 2;
        D_800B4C20 = s;
        s->next = (S_Task *)t;
    }
    func_80018788(&D_800A451C);
}

EXTERN_C void func_8001E6AC(void *s)
{
    if (s == D_800B4C1C || s == D_800B4C18)
        return;
    func_800186E8(&D_800A451C);
    if (D_800B4C1C && func_8001A6A8(D_800B4C1C, (int)s))
        D_800B4C1C = (S_8001F1BC *)func_8001A744(D_800B4C1C, s);
    else if (D_800B4C20)
        D_800B4C20 = func_8001A744(D_800B4C20, s);
    func_8001E57C(s);
    func_80018788(&D_800A451C);
}

EXTERN_C S_Scene *func_8001E758(S_Scene *s)
{
    if (s == (S_Scene *)D_800B4C18) {
        S_Scene *p, *n;
        func_800186E8(&D_800A451C);
        func_8001E57C(s);
        p = (S_Scene *)D_800B4C1C;
        n = p->next;
        D_800B4C18 = (S_8001F1BC *)p;
        p->unkF4 = 0;
        p->next = 0;
        D_800B4C1C = (S_8001F1BC *)n;
        func_80018788(&D_800A451C);
    }
    return (S_Scene *)D_800B4C18;
}

EXTERN_C void func_8001E7C8(S_Scene *s)
{
    if (s == (S_Scene *)D_800B4C18)
        func_80018FA8(s, ((void *(*)())func_8001E758)());
}

EXTERN_C int func_8001E804(char *obj, void *item)
{
    char *p = obj + 0xA4;
    Holder *h = p ? (Holder *)(obj + 0xAC) : 0;
    return func_80019CFC(h, item);
}

EXTERN_C void func_8001E840(S_8001E840 *p)
{
    p->unk98 = 0;
}

EXTERN_C int func_8001E848(char *cur, char *s)
{
    int r;
    Holder *h;
    List *l;
    func_800186E8(&D_800A451C);
    r = *(int *)(s + 0xF0);
    func_8001EFE4(cur, new (func_8001CA10(0x14)) S_Evt2D0(5, 0, 0));
    if (cur == (char *)D_800B4C18)
        func_8001E57C(cur);
    D_800B4C18 = (S_8001F1BC *)s;
    *(int *)(s + 0xF4) = 0;
    h = (Holder *)(cur + 0xA4);
    l = h;
    func_80019A6C(l, (int)s, l->count);
    l = &D_800AC688;
    func_80019A6C(l, (int)s, l->count);
    func_80018F0C(cur, s);
    func_80018788(&D_800A451C);
    if (cur == s) {
        func_800949B0(&((int *)((S_Scn *)cur)->unk88)[((S_Scn *)cur)->unk8 - 1]);
        ((S_SceneV *)cur)->f2();
        func_8001E9A8(cur);
    }
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E9A8);

EXTERN_C void func_8001EAAC(S_Scn *s)
{
    s->unkA0 = 5;
    func_8001EFE4((char *)s, new (func_8001CA10(0x14)) S_Evt2D0(5, 0, 0));
    func_8001E7C8((S_Scene *)s);
    ((S_SceneV *)func_8001C974(s ? (char *)s + 0x8C : 0))->f2();
}

EXTERN_C S_Evt *func_8001EB60(char *obj, int a)
{
    S_Evt *e;
    *(int *)(obj + 0xA0) = a;
    func_8001E7C8((S_Scene *)obj);
    while (1) {
        e = (S_Evt *)func_8001C974(obj ? obj + 0x8C : 0);
        if (e->unkA)
            return e;
        ((S_EvtV *)e)->f2();
        func_8001E7C8((S_Scene *)obj);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EBD8);

EXTERN_C S_Evt *func_8001EC98(S_Node *a, S_Evt *b, S_Evt *e)
{
    int m = 0;
    if (e->unkA == 3) {
        char *t = 0;
        if (e->unkC)
            t = (char *)e->unkC - 8;
        if (t == (char *)a->next)
            m = 1;
    }
    if (m) {
        if (b)
            b->next = e->next;
        e->next = 0;
        ((S_EvtV *)e)->f2();
        return b;
    }
    return e;
}

EXTERN_C S_Evt *func_8001ED2C(char *s, int a, int b)
{
    S_Evt *e;
    int m;
    *(int *)(s + 0xA0) = b;
    func_8001F544(s + 0xC4, a, b, 0, 0);
    while (1) {
        func_8001E7C8((S_Scene *)s);
        e = (S_Evt *)func_8001C974(s ? s + 0x8C : 0);
        if (e->unkA)
            break;
        ((S_EvtV *)e)->f2();
    }
    m = 0;
    if (e->unkA == 3) {
        char *t = 0;
        if (e->unkC)
            t = (char *)e->unkC - 8;
        if (t == s + 0xC4)
            m = 1;
    }
    {
        char *tm = s + 0xC4;
        if (m) {
            ((S_EvtV *)e)->f2();
            e = 0;
        } else if (!func_8001F598(tm)) {
            char *g = D_800B4C28;
            *(void **)(g + 4) = tm;
            func_8001A7B4(s ? s + 0x8C : 0, g);
        }
    }
    return e;
}

EXTERN_C int func_8001EE58(void *a, S_Node *b)
{
    if (func_8001EEC0(b, a)) {
        if (b)
            VCALL(b, 1, Fn_vi, 3);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EEC0);

EXTERN_C void func_8001EFE4(char *obj, void *e)
{
    func_8001C8D8(obj ? obj + 0x8C : 0, e);
    if ((obj ? (S_Evt *)(obj + 0x8C) : 0)->next == e)
        func_8001E6AC(obj);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001F048);

EXTERN_C void func_8001F074(char *p, int a)
{
    func_8001F094(p + 0xAC, a);
}

EXTERN_C void func_8001F094(void *p, int a)
{
    Holder *h = (Holder *)p;
    while (1) {
        int i = count_of(h);
        Item *it;
        if (!i)
            break;
        i--;
        it = func_80019F64(h, i);
        if (it)
            VCALL(it, 1, Fn_vi, 3);
        func_80019C68((List *)h, i);
    }
}

EXTERN_C void func_8001F134()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC688)->p, 0);
}

EXTERN_C void func_8001F15C()
{
    new ((void *)&D_800AC688) S_ScnAC688;
    func_8001F1A8(D_800B4C28);
}
