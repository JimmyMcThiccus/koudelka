#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8001F1A8.h"

EXTERN_C S_Vobj *func_8001F1A8(S_Vobj *p)
{
    p->vtbl = D_800103F8;
    return p;
}

EXTERN_C unsigned short func_8001F1BC(S_8001F1BC *p, int v)
{
    unsigned short old = p->unk94;
    p->unk94 = v;
    return old;
}

EXTERN_C int func_8001F1CC(S_8001F1CC *p)
{
    return p->unk98;
}

EXTERN_C int func_8001F1D8(S_8001F1CC *p)
{
    return p->unk4;
}

EXTERN_C S_8001F1BC *func_8001F1E4()
{
    return D_800B4C18;
}

EXTERN_C int func_8001F1F0(S_8001F1CC *p)
{
    return p->unkF0;
}

EXTERN_C S_Timer *func_8001F1FC(S_Timer *a, S_Timer *b)
{
    S_Timer *head, *tail;
    if (a == 0 || b == 0)
        return a ? a : b;
    head = 0;
    tail = head;
    while (1) {
        if (!(a && b))
            break;
        if (a->unk1C <= b->unk1C) {
            if (tail) {
                tail->next = a;
                tail = a;
                a = tail->next;
            } else {
                head = a;
                a = head->next;
                tail = head;
            }
        } else {
            if (tail) {
                tail->next = b;
                tail = b;
                b = b->next;
            } else {
                head = b;
                b = head->next;
                tail = head;
            }
        }
    }
    if (a)
        tail->next = a;
    else
        tail->next = b;
    return head;
}

EXTERN_C void func_8001F2C4()
{
    S_Timer *t = (S_Timer *)D_800B4C30;
    D_800B4C30 = 0;
    while (t && !(D_800A4534.unkC < t->unk1C)) {
        S_Timer *n = t->next;
        void *cb = (char *)t + 0xC;
        t->next = 0;
        VCALL(cb, 1, void (*)(void *, int), 0);
        t = n;
    }
    D_800B4C30 = D_800B4C30 ? func_8001F1FC((S_Timer *)D_800B4C30, t) : t;
}

EXTERN_C S_TimerObj *func_8001F360(S_TimerObj *p, int a, int b)
{
    return new (p) S_TimerObj(a, b);
}

EXTERN_C void func_8001F3DC(S_Timer *p, int flags)
{
    S_8001F930 *b;
    ((void ***)p)[3] = D_80010438;
    ((void ***)p)[2] = D_80010450;
    p->vtbl = D_80010460;
    func_8001F514(p);
    b = (S_8001F930 *)((char *)p + 8);
    b->vtbl2 = D_80010480;
    b->vtbl = D_80010470;
    func_800198AC(b, 0);
    func_8001A610(p, flags);
}

EXTERN_C void func_8001F460(S_Timer *t)
{
    S_Timer *s = (S_Timer *)D_800B4C30;
    if (s) {
        if (s->unk1C < t->unk1C) {
            while (1) {
                S_Timer *n = s->next;
                int c = 0;
                if (n)
                    c = n->unk1C < t->unk1C;
                if (!c)
                    break;
                s = n;
            }
            t->next = 0;
            if (s->next && t)
                func_8001A864(t, s->next);
            s->next = t;
        } else {
            t->next = s;
            D_800B4C30 = t;
        }
    } else {
        t->next = 0;
        D_800B4C30 = t;
    }
}

EXTERN_C void func_8001F514(void *item)
{
    if (D_800B4C30)
        D_800B4C30 = func_8001A744(D_800B4C30, item);
}

EXTERN_C void func_8001F544(S_Timer *t, int delay, int a, int repeat, int b)
{
    t->unk1C = D_800A4534.unkC + delay;
    if (repeat)
        t->unk20 = delay;
    else
        t->unk20 = 0;
    t->unk24 = 0;
    t->unk14 = a;
    t->unk28 = b;
    func_8001F460(t);
}

EXTERN_C int func_8001F598(S_Timer *t)
{
    int r;
    t->unk24 = 0;
    if (t->unk1C) {
        ((void (*)())func_8001F514)();
        r = D_800A4534.unkC > t->unk1C ? 0 : t->unk1C - D_800A4534.unkC;
        t->unk1C = 0;
        return r;
    }
    return 0;
}

EXTERN_C int func_8001F60C(S_Timer *t)
{
    int r;
    if (!t->unk1C)
        return 0;
    ((void (*)())func_8001F514)();
    r = D_800A4534.unkC > t->unk1C ? 0 : t->unk1C - D_800A4534.unkC;
    t->unk24 = r;
    t->unk1C = 0;
    return r;
}

EXTERN_C int func_8001F67C(S_Timer *t)
{
    if (t->unk24) {
        int period = t->unk20;
        func_8001F544(t, t->unk24, t->unk14, 0, t->unk28);
        t->unk20 = period;
        return 1;
    }
    return 0;
}

EXTERN_C void func_8001F6E0(S_Timer *t, S_TimerBase8 *x)
{
    func_8001F788(t ? (S_TimerBase8 *)((char *)t + 8) : 0, x);
    t->unk1C = 0;
    if (t->unk28) {
        if (--t->unk28 == 0) {
            if (t)
                VCALL(t, 1, void (*)(void *, int), 3);
            return;
        }
    }
    if (t->unk20)
        func_8001F544(t, t->unk20, t->unk14, 1, t->unk28);
}

EXTERN_C void func_8001F788(S_TimerBase8 *b, S_TimerBase8 *x)
{
    if (b->unk8) {
        S_TimerBase8 *t = x ? x : b;
        unsigned short v = b->unkC;
        func_8001EFE4(b->unk8, new (func_8001CA10(0x14)) S_Evt2D0(v, t));
        if (x && b)
            VCALL(b, 1, void (*)(void *, int), 3);
    }
}

EXTERN_C void func_8001F85C(S_TimerBase8 *b, S_TimerBase8 *x)
{
    if (b->unk8) {
        S_TimerBase8 *t = x ? x : b;
        unsigned short v = b->unkC;
        func_8001EFE4(b->unk8, new (func_8001CA10(0x14)) S_Evt2D0(v, t));
        if (x && b)
            VCALL(b, 1, void (*)(void *, int), 3);
    }
}

EXTERN_C S_8001F930 *func_8001F930(S_8001F930 *p, int a, int b)
{
    p->vtbl = D_800100F8;
    p->vtbl2 = D_80010480;
    p->vtbl = D_80010470;
    p->unk8 = a;
    p->unkC = b;
    return p;
}

EXTERN_C S_8001F964_Derived *func_8001F964(S_8001F964 *p)
{
    return (S_8001F964_Derived *)p->unkC;
}

EXTERN_C int func_8001F980(S_8001F980 *p)
{
    return p->unk4;
}

EXTERN_C void func_8001F98C(S_8001F930 *p, int a)
{
    p->vtbl2 = D_80010480;
    p->vtbl = D_80010470;
    func_800198AC(p, a);
}

EXTERN_C void func_8001F9C0()
{
    Item *it;
    if (D_800B4C34) {
        func_80018AF4();
        ((S_TimerIterR *)D_800B4C34)->idx = 0;
        while ((it = ((S_TimerIterR *)D_800B4C34)->next()) != 0)
            it->run();
        func_80018B18();
    }
}

EXTERN_C int func_8001FA6C(Holder *h, void *item)
{
    return func_80019C24(h, item);
}

EXTERN_C int func_8001FA9C(char *p, void *item)
{
    Holder *h = p ? (Holder *)(p + 8) : 0;
    return func_80019CFC(h, item) != 0;
}

EXTERN_C void func_8001FAD4(Holder *h, void *item)
{
    List *l = h;
    func_80019A6C(l, (int)item, l->count);
}

EXTERN_C void func_8001FB0C()
{
    func_800186E8(&D_800A451C);
    D_800B4C34 = 0;
    VSyncCallback(0);
    func_80018788(&D_800A451C);
}

EXTERN_C void func_8001FB4C(void *p)
{
    func_800186E8(&D_800A451C);
    D_800B4C34 = p;
    VSyncCallback(func_8001F9C0);
    func_80018788(&D_800A451C);
}

EXTERN_C void func_8001FB9C(S_8001FB9C *p, int flags)
{
    if (p == D_800B4C34)
        D_800B4C34 = 0;
    func_80019920(p->list, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C S_8001FBF4 *func_8001FBF4(S_8001FBF4 *p)
{
    return new (p) S_8001FBF4;
}

EXTERN_C S_8001FC38 *func_8001FC38(S_8001FC38 *p, int a, int b, int c)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800104F8;
    p->unk8 = b;
    p->unkC = D_800A4534.unkC;
    p->unk10 = a;
    p->unk12 = c;
    return p;
}

EXTERN_C void func_8001FC78(S_8001FC78 *p, int a, int b)
{
    func_80020734(p->unk8, a, p, b);
}

EXTERN_C int func_8001FCA4(S_8001FCA4 *p)
{
    return p->unk8->unk4;
}

EXTERN_C int func_8001FCB8(S_8001FC78 *p, void *item)
{
    return func_800208D4((char *)p->unk8, item);
}

EXTERN_C int func_8001FCDC(S_8001FC78 *p, void *item)
{
    return func_80020948((char *)p->unk8, item);
}

EXTERN_C int func_8001FD00(S_Handler *o, S_Ev *e)
{
    switch (e->unk10 & 0xFF00) {
    case 0x200:
        return VCALL(o, 6, HandlerFn, e);
    case 0x800:
        return VCALL(o, 8, HandlerFn, e);
    default:
        return VCALL(o, 4, HandlerFn, e);
    }
}

EXTERN_C int func_8001FD90(S_Handler *o, S_Ev *e)
{
    switch (e->unk10 & 0xFF00) {
    case 0x200:
        return VCALL(o, 7, HandlerFn, e);
    case 0x800:
        return VCALL(o, 9, HandlerFn, e);
    default:
        return VCALL(o, 5, HandlerFn, e);
    }
}

EXTERN_C int func_8001FE20()
{
    return 0;
}

EXTERN_C int func_8001FE28(S_Handler *o, void *a)
{
    S_Handler *n;
    if (VCALL(o, 4, HandlerFn, a))
        return 1;
    n = o->unk4;
    int r;
    if (n)
        r = VCALL(n, 5, HandlerFn, a);
    else
        r = 0;
    return r;
}

EXTERN_C int func_8001FEB0()
{
    return 0;
}

EXTERN_C int func_8001FEB8(S_Handler *o, void *a)
{
    S_Handler *n;
    if (VCALL(o, 6, HandlerFn, a))
        return 1;
    n = o->unk4;
    int r;
    if (n)
        r = VCALL(n, 7, HandlerFn, a);
    else
        r = 0;
    return r;
}

EXTERN_C int func_8001FF40()
{
    return 0;
}

EXTERN_C int func_8001FF48(S_Handler *o, void *a)
{
    S_Handler *n;
    if (VCALL(o, 8, HandlerFn, a))
        return 1;
    n = o->unk4;
    int r;
    if (n)
        r = VCALL(n, 9, HandlerFn, a);
    else
        r = 0;
    return r;
}

EXTERN_C int func_8001FFD0(S_8001FFD0 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4 *func_8001FFDC(S_Vobj4 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800104A8;
    return p;
}

EXTERN_C void func_80020000(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_80020020(S_8001FFD0 *p)
{
    return (p->unk12 >> 3) & 1;
}

EXTERN_C int func_80020034(S_8001FFD0 *p)
{
    return (p->unk12 >> 2) & 1;
}

EXTERN_C int func_80020048(S_8001FFD0 *p)
{
    return (p->unk12 >> 1) & 1;
}

EXTERN_C int func_8002005C(S_8001FFD0 *p)
{
    return p->unk12 & 0x1;
}

EXTERN_C void func_80020068(S_8001FFD0 *p, int v)
{
    p->unk12 = v;
}

EXTERN_C void func_80020070(S_8001FFD0 *p, int v)
{
    p->unk8 = v;
}

EXTERN_C void func_80020078(S_8001FFD0 *p, int v)
{
    p->unkC = v;
}

EXTERN_C void func_80020080(S_8001FFD0 *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_80020088(S_8001FFD0 *p)
{
    return p->unk12;
}

EXTERN_C int func_80020094(S_8001FFD0 *p)
{
    return p->unk8;
}

EXTERN_C int func_800200A0(S_8001FFD0 *p)
{
    return p->unkC;
}

EXTERN_C int func_800200AC(S_8001FFD0 *p)
{
    return p->unk10 & 0xFF00;
}

EXTERN_C int func_800200B8(S_8001FFD0 *p)
{
    return p->unk10;
}

EXTERN_C int func_800200C4(S_8001FFD0 *p)
{
    return p->unk4;
}

EXTERN_C void func_800200D0(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C S_C588 *func_800200F0(S_C588 *s)
{
    S_C588 *o = new S_C588(*s);
    if (s->unk4)
        o->unk4 = VCALL(s->unk4, 2, void *(*)(void *));
    return o;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800103F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010408);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010420);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010438);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010450);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010460);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010470);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010480);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010498);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800104A8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800104F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010508);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010538);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010588);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_800201DC);

EXTERN_C int func_800202B4()
{
    return 0;
}

EXTERN_C int func_800202BC()
{
    return 0;
}

EXTERN_C int func_800202C4()
{
    return 0;
}

EXTERN_C int func_800202CC()
{
    return 0;
}

EXTERN_C int func_800202D4()
{
    return 0;
}

EXTERN_C void func_800202DC()
{
    func_8001A610(&D_800AC6A8, 2);
}

EXTERN_C void func_80020304()
{
    S_80020304 *p = (S_80020304 *)&D_800AC6A8;
    func_8001FC38((S_8001FC38 *)p, 0x203, 0, 0);
    p->vtbl = D_800105DC;
    p->unk14 = 0;
    p->vtbl = D_80010588;
    p->unk18 = 0;
    p->unk1A = 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800105B4);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800105DC);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800105F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_8001060C);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010624);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010654);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010684);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010694);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800106A4);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800106BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800106EC);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010714);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010734);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_8001075C);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010774);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_8001079C);
