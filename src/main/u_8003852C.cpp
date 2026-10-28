#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

EXTERN_C void *func_8003852C(void *p, int vb)
{
    if (vb) {
        char *b = (char *)p + 0x3C;
        AT(p, void *, 4) = b;
        AT(p, short, 0x3C) = 16;
        AT(b, short, 2) = 0;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_80012154;
    AT(p, void **, 8) = D_8001201C;
    AT(p, void **, 0) = D_80012034;
    AT(p, void *, 0xC) = (char *)p + 0x10;
    ((int (*)(void *, int, int))func_800198E0)((char *)p + 0x10, 4, 0);
    AT(p, void **, 8) = D_80012294;
    AT(p, void **, 0) = D_80012224;
    AT(p, void **, 8) = D_80012364;
    AT(p, int, 0x28) = 0;
    AT(p, int, 0x2C) = 0;
    AT(p, void **, 0) = D_8001237C;
    AT(p, char, 0x37) = 0;
    return p;
}

EXTERN_C int func_800385E4(S_800385E4 *p)
{
    return p->unk10;
}

EXTERN_C void func_800385F0(void *p, int flags)
{
    AT(p, void **, 8) = D_800123EC;
    AT(p, void **, 0) = D_80012404;
    func_8001D024((char *)p + 8, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void *func_80038654(void *p, int a, int b)
{
    char *m;
    func_8002EA70(p, a);
    m = (char *)p + 0x10;
    AT(p, void **, 0) = D_80012484;
    AT(m, void *, 8) = (char *)p + 0x1C;
    AT(p, void *, 0x10) = (char *)p + 0x1C;
    func_800198E0(AT(m, void *, 8), b, 0);
    AT(m, int, 4) = 0;
    return p;
}

EXTERN_C void func_800386B8(void *p, int flags)
{
    Holder *h = (Holder *)((char *)p + 0x10);
    List *l;
    AT(p, void **, 0) = D_80012484;
    l = h;
    if (l->count) {
        void *o = func_8002EB68(p);
        if (o)
            ((void (*)(void *, Holder *, int))func_8002DD34)(o, h, 1);
        func_80019D40((List *)h);
    }
    func_80019920(AT(p, List *, 0x10), 0);
    func_8002EE9C(p, flags);
}

EXTERN_C void func_80038764(void *p, int a)
{
    Holder *h = (Holder *)((char *)p + 0x10);
    List *l = h;
    if (l->count) {
        ((void (*)(int, Holder *, int))func_8002DD34)(a, h, 1);
        func_80019D40((List *)h);
    }
}

EXTERN_C void func_800387D0(A2VObj0 *p)
{
    int r = p->v11();
    if (r)
        p->v07(r);
}

EXTERN_C void func_80038834(A2VObj0 *p)
{
    int r = p->v11();
    if (r)
        p->v07(r);
}

EXTERN_C void func_80038898(A2VObj0 *p)
{
    int r = p->v11();
    if (r)
        p->v08(r);
}

EXTERN_C void func_800388FC(A2VObj0 *p, int a)
{
    p->v08(a);
}

EXTERN_C void func_80038938(void *p)
{
    S_A2_VE *e;
    func_8002EADC(p);
    e = VENT(p, 0xA0);
    e->pfn((char *)p + e->delta);
}

EXTERN_C void func_80038978(void *p)
{
    S_A2_VE *e;
    func_8002EAE8(p);
    e = VENT(p, 0xA0);
    e->pfn((char *)p + e->delta);
}

EXTERN_C int func_800389B8()
{
    return 1;
}

EXTERN_C int func_800389C0()
{
    return 1;
}

EXTERN_C int func_800389C8()
{
    return 1;
}

EXTERN_C int func_800389D0()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800389D8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038B0C);

EXTERN_C int func_80038C20(void *p)
{
    int r;
    if (AT(p, int, 4) == 0) {
        func_80038E2C(AT(p, void *, 8));
        r = 1;
    } else {
        AT(p, int, 4)--;
        r = 0;
    }
    return r;
}

EXTERN_C void *func_80038C64(void *p, int a, int b)
{
    char *g;
    void *t;
    AT(p, void **, 0) = D_80010160;
    AT(p, int, 4) = b;
    g = (char *)&D_800AC57C;
    t = g ? g + 0xF8 : 0;
    ((int (*)(void *, void *))func_8001D150)(t, new S_A2_X1(p));
    AT(p, void **, 0) = D_8001265C;
    AT(p, int, 8) = a;
    return p;
}

EXTERN_C void func_80038D14(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038D34);

EXTERN_C void func_80038E2C()
{
}

C_80038E34::C_80038E34(short a)
{
    AT(this, void **, 0) = D_80012674;
    unk4C = -1;
    unk4E = -1;
    unk52 = 1;
    unk68 = 0;
    unk50 = a;
    unk58 = -1;
}

C_80038E98::C_80038E98()
{
    AT(this, void **, 0) = D_80012674;
    unk4C = -1;
    unk4E = -1;
    unk52 = 1;
    unk68 = 0;
    unk5C = 0;
    unk58 = -1;
}

EXTERN_C int func_80038EF0(S_80038EF0 *p)
{
    return p->unk24;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038EFC);

EXTERN_C void *func_80038FB8(void *p, short a)
{
    void *r;
    if (AT(p, short, 0x4C) == a)
        return p;
    if (!AT(p, S_A2_Iter *, 0x28))
        return 0;
    AT(p, S_A2_Iter *, 0x28)->i = 0;
    do {
        void *c = a2_next(AT(p, S_A2_Iter *, 0x28));
        if (!c)
            return 0;
        r = (void *)func_8003906C(c, a, AT(p, short, 0x4C));
    } while (!r);
    return r;
}

EXTERN_C int func_8003906C(void *p, short a, short b)
{
    void *r;
    if (!(b < AT(p, short, 0x4C)))
        return 0;
    if (AT(p, short, 0x4C) == a)
        return (int)p;
    if (!AT(p, S_A2_Iter *, 0x28))
        return 0;
    AT(p, S_A2_Iter *, 0x28)->i = 0;
    do {
        void *c = a2_next(AT(p, S_A2_Iter *, 0x28));
        if (!c)
            return 0;
        r = func_80038FB8(c, a);
    } while (!r);
    return (int)r;
}

EXTERN_C void *func_8003912C(void *p, short a)
{
    void *r;
    if (AT(p, short, 0x50) == a)
        return p;
    if (!AT(p, S_A2_Iter *, 0x28))
        return 0;
    AT(p, S_A2_Iter *, 0x28)->i = 0;
    do {
        void *c = a2_next(AT(p, S_A2_Iter *, 0x28));
        if (!c)
            return 0;
        r = func_8003912C(c, a);
    } while (!r);
    return r;
}

EXTERN_C void func_800391DC(S_800391DC *p, int a, int b)
{
    p->unk64 = b;
    p->unk48->unk14 = a;
}

EXTERN_C void func_800391EC(A2VObj0 *p)
{
    if (AT(p, short, 0x50) == 99)
        return;
    if (AT(p, void *, 0x68))
        func_8003D00C(AT(p, void *, 0x68));
    if (AT(p, short, 0x52)) {
        p->v01();
        p->v02((char *)p + 4);
        if (AT(p, void *, 0x48))
            func_8003CB50(AT(p, void *, 0x48));
        if (AT(p, void *, 0x28))
            func_8003944C(AT(p, void *, 0x28), &D_800B4D1C);
    }
    if (AT(p, void *, 0x68))
        func_8003CF24(AT(p, void *, 0x68));
}

EXTERN_C int func_800392C8(S_800392C8 *p)
{
    return p->unk24;
}

EXTERN_C void func_800392D4(void *p)
{
    func_8003C320(p, 1);
}

EXTERN_C void func_800392F4(void *p)
{
    func_8003C3E4(p, AT(p, int, 0x58));
    if (AT(p, S_A2_Iter *, 0x28)) {
        AT(p, S_A2_Iter *, 0x28)->i = 0;
        while (1) {
            void *c = a2_next(AT(p, S_A2_Iter *, 0x28));
            if (!c)
                break;
            func_800392F4(c);
        }
    }
}

EXTERN_C void func_80039388(void *p, short a, short b, short c)
{
    AT(p, short, 0x52) = a;
    AT(p, int, 0x54) = b + c;
    if (AT(p, S_A2_Iter *, 0x28)) {
        AT(p, S_A2_Iter *, 0x28)->i = 0;
        while (1) {
            void *ch = a2_next(AT(p, S_A2_Iter *, 0x28));
            if (!ch)
                break;
            func_80039388(ch, a, AT(p, short, 0x54), c);
        }
    }
}

EXTERN_C void func_80039444(S_80039444 *p, int v)
{
    p->unk50 = v;
}

EXTERN_C void func_8003944C(void *h, void *o)
{
    int s = func_80019A18(h ? AT(h, List *, 0) : 0, 1);
    int i;
    for (i = 0; i < AT(h, List *, 0)->count; i++)
        ((A2VObj0 *)o)->v00(AT(AT(h, List *, 0), void **, 0)[i]);
    func_80019A18(h ? AT(h, List *, 0) : 0, s);
}

extern "C++" void *func_8003950C_(S_A2_Iter *it, A2VObj0 *o) asm("func_8003950C");
void *func_8003950C_(S_A2_Iter *it, A2VObj0 *o)
{
    void *r = 0;
    int s = func_80019A18(it ? (List *)it->arr : 0, 1);
    it->i = 0;
    while (it->i < it->arr->n) {
        if (o->v00(it->arr->items[it->i])) {
            r = it->arr->items[it->i];
            break;
        }
        it->i++;
    }
    func_80019A18(it ? (List *)it->arr : 0, s);
    return r;
}

extern "C++" void *func_80039610_(S_A2_Iter *it, A2VObj0 *o) asm("func_80039610");
void *func_80039610_(S_A2_Iter *it, A2VObj0 *o)
{
    void *r = 0;
    int s = func_80019A18(it ? (List *)it->arr : 0, 1);
    while (it->i < it->arr->n) {
        if (o->v00(it->arr->items[it->i])) {
            r = it->arr->items[it->i];
            break;
        }
        it->i++;
    }
    func_80019A18(it ? (List *)it->arr : 0, s);
    return r;
}

extern "C++" void *func_80039710_(S_A2_Iter *it, A2VObj0 *o) asm("func_80039710");
void *func_80039710_(S_A2_Iter *it, A2VObj0 *o)
{
    void *r;
    int s;
    if (!it->arr->n)
        return 0;
    r = 0;
    s = func_80019A18(it ? (List *)it->arr : 0, 1);
    for (it->i = it->arr->n - 1; it->i; it->i--) {
        if (o->v00(it->arr->items[it->i])) {
            r = it->arr->items[it->i];
            break;
        }
    }
    func_80019A18(it ? (List *)it->arr : 0, s);
    return r;
}

extern "C++" void *func_80039824_(S_A2_Iter *it, A2VObj0 *o) asm("func_80039824");
void *func_80039824_(S_A2_Iter *it, A2VObj0 *o)
{
    void *r;
    int s;
    if (it->i <= 0)
        return 0;
    r = 0;
    s = func_80019A18(it ? (List *)it->arr : 0, 1);
    while (--it->i) {
        if (o->v00(it->arr->items[it->i])) {
            r = it->arr->items[it->i];
            break;
        }
    }
    func_80019A18(it ? (List *)it->arr : 0, s);
    return r;
}

EXTERN_C void *func_80039928(S_A2_Stack *p)
{
    if (p->n <= 0)
        return 0;
    p->n--;
    return p->arr->items[p->n];
}

EXTERN_C void *func_80039960(S_A2_Iter *p)
{
    void *r;
    S_A2_Arr *a = p->arr;
    int i = p->i;
    if (i < a->n) {
        r = a->items[i];
        p->i = i + 1;
    } else
        r = 0;
    return r;
}

EXTERN_C int func_800399A4(S_800399A4 *p)
{
    return p->unk4;
}

EXTERN_C void func_800399B0(S_800399B0 *p)
{
    p->unk4 = p->unk0->unk4;
}

EXTERN_C void func_800399C4(S_800399A4 *p)
{
    p->unk4 = 0;
}

EXTERN_C void func_800399CC(S_800399A4 *p, int v)
{
    p->unk4 = v;
}

EXTERN_C void *func_800399D4(void *p, int vb, int a, int b)
{
    if (vb) {
        AT(p, void *, 0) = (char *)p + 8;
        func_800198E0((char *)p + 8, a, b);
    }
    AT(p, int, 4) = 0;
    return p;
}

C_80039A14_def::C_80039A14_def() : vt(D_800126F4), m4(0x1000), unk24(0), unk28(0)
{
    func_8001AA28(&s2C, 6);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039A88);

static inline void *a2_hctor(void *p, int a, int b)
{
    void *v = (char *)p + 0xC;
    AT(p, void *, 8) = v;
    AT(p, void *, 0) = v;
    func_800198E0(AT(p, void *, 8), a, b);
    AT(p, int, 4) = 0;
    return p;
}

EXTERN_C void func_80039BEC(void *p, void *item)
{
    List *l;
    if (!AT(p, void *, 0x28)) {
        char *h = (char *)a2_hctor(operator new(0x20), 0x20, 0);
        AT(p, void *, 0x28) = h;
        if (!h) { l = 0; goto call; }
    }
    l = AT(AT(p, char *, 0x28), List *, 0);
call:
    func_80019A6C(l, (int)item, l->count);
    AT(item, void *, 0x24) = p;
}

EXTERN_C int func_80039C88(void *p, void *q)
{
    char *h = AT(p, char *, 0x28);
    if (h) {
        char *h8 = h + 8;
        if (func_80019CFC(h8 ? AT(h8, void *, 0) : 0, (int)q)) {
            AT(q, int, 0x24) = 0;
            char *g = AT(p, char *, 0x28);
            List *l = g ? AT(g, List *, 0) : 0;
            if (!l->count) {
                if (g) {
                    func_80019920(AT(g, List *, 0), 0);
                    delete g;
                }
                AT(p, int, 0x28) = 0;
            }
            return 1;
        }
    }
    return 0;
}

EXTERN_C int func_80039D38(void *p, A2VObj0 *q)
{
    if (func_80039C88(p, q)) {
        if (q)
            q->v00(3);
        return 1;
    }
    return 0;
}

EXTERN_C void func_80039D94(void *p)
{
    void *q = AT(p, void *, 0x24);
    if (q) {
        S_A2_VE *e = VENT(q, 0x18);
        e->pfn((char *)q + e->delta);
    }
}

EXTERN_C void func_80039DD8(void *p)
{
    int i;
    if (AT(p, int, 0x44))
        return;
    AT(p, int, 0x44) = 1;
    if (!AT(p, void *, 0x28))
        return;
    for (i = 0;; i++) {
        char *h = AT(p, char *, 0x28);
        List *l = h ? AT(h, List *, 0) : 0;
        char *h2;
        if (!(i < l->count))
            break;
        h2 = h ? h + 8 : 0;
        func_80039DD8(func_80019F64(h2 ? AT(h2, List *, 0) : 0, i));
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039E80);

EXTERN_C void func_80039F80(void *p, int a, S_A2_Sv *d)
{
    AT(p, S_A2_V4, 0x34) = func_8003B450(a, (char *)p + 0x34);
    if (d) {
        S_A2_Sv *s = (S_A2_Sv *)((char *)p + 0x2C);
        short x = s->x + d->x;
        short y = s->y + d->y;
        short z = s->z + d->z;
        s->x = x;
        s->y = y;
        s->z = z;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A010);

EXTERN_C S_A2_V4 *func_8003A150(S_A2_V4 *r, char *m, S_A2_V4 *v)
{
    MATRIX *mx = (MATRIX *)(m + 4);
    long flag;
    SetRotMatrix(mx);
    SetTransMatrix(mx);
    S_A2_V4z t;
    S_A2_SvI sv = v ? S_A2_SvI(v->a, v->b, v->c) : S_A2_SvI();
    RotTrans(&sv, (S_A2_V4 *)&t, &flag);
    *r = *(S_A2_V4 *)&t;
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A214);

EXTERN_C void *func_8003A318(S_A2_Stack *p)
{
    if (p->n <= 0)
        return 0;
    p->n--;
    return p->arr->items[p->n];
}

EXTERN_C void *func_8003A350(S_A2_Iter *p)
{
    void *r;
    S_A2_Arr *a = p->arr;
    int i = p->i;
    if (i < a->n) {
        r = a->items[i];
        p->i = i + 1;
    } else
        r = 0;
    return r;
}

EXTERN_C void func_8003A394(void *p, int a)
{
    func_80039824(p, a);
}

EXTERN_C void func_8003A3B4(void *p, int a)
{
    func_80039710(p, a);
}

EXTERN_C void func_8003A3D4(void *p, int a)
{
    func_80039610(p, a);
}

EXTERN_C void func_8003A3F4(void *p, int a)
{
    func_8003950C(p, a);
}

EXTERN_C void *func_8003A414(void *h)
{
    S_A2_Arr *a = h ? AT(h, S_A2_Arr *, 0) : 0;
    if (a->n == 0)
        return 0;
    return a->items[a->n - 1];
}

EXTERN_C void *func_8003A454(void *h)
{
    S_A2_Arr *a = h ? AT(h, S_A2_Arr *, 0) : 0;
    if (a->n == 0)
        return 0;
    return a->items[0];
}

EXTERN_C void func_8003A490(void *p, int a)
{
    func_80019C68(p ? AT(p, void *, 0) : 0, a);
}

EXTERN_C void func_8003A4C0(void *p, int a)
{
    func_80019CFC(p ? AT(p, void *, 0) : 0, a);
}

EXTERN_C void *func_8003A4F0(void *p, int vb, int a, int b)
{
    if (vb) {
        void *v = (char *)p + 0xC;
        AT(p, void *, 8) = v;
        AT(p, void *, 0) = v;
        func_800198E0(AT(p, void *, 8), a, b);
    }
    AT(p, int, 4) = 0;
    return p;
}

EXTERN_C void *func_8003A538(void *p, int vb, int a, int b)
{
    if (vb) {
        AT(p, void *, 0) = (char *)p + 4;
        func_800198E0((char *)p + 4, a, b);
    }
    return p;
}

EXTERN_C void *func_8003A574(void *p, int a, int b)
{
    char *g;
    void *t;
    AT(p, void **, 0) = D_80010160;
    AT(p, int, 4) = b;
    g = (char *)&D_800AC57C;
    t = g ? g + 0xF8 : 0;
    ((int (*)(void *, void *))func_8001D150)(t, new S_A2_X1(p));
    AT(p, void **, 0) = D_800126DC;
    AT(p, int, 8) = a;
    return p;
}

EXTERN_C Item *func_8003A624(void *p, int a)
{
    return func_80019F64(p ? AT(p, List *, 0) : 0, a);
}

EXTERN_C void func_8003A654(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C void func_8003A674(S_A2_At34 *p, S_A2_V4 *v)
{
    p->v = *v;
    func_80039DD8(p);
}

EXTERN_C void func_8003A6B4(S_A2_At2C *p, S_A2_Sv *v)
{
    p->v = *v;
    func_80039DD8(p);
}

EXTERN_C void *func_8003A6F4(S_8003A6F4 *p)
{
    return &p->unk34;
}

EXTERN_C void *func_8003A6FC(S_8003A6F4 *p)
{
    return &p->unk2C;
}

EXTERN_C int func_8003A704(void *p, int a)
{
    void **q = AT(p, void **, 0x28);
    if (q)
        return func_80019C24(*q, a);
    return 0;
}

EXTERN_C int func_8003A738(S_8003A6F4 *p)
{
    return p->unk24;
}

EXTERN_C void func_8003A744(S_8003A6F4 *p)
{
    p->unk24 = 0;
}

EXTERN_C void func_8003A74C(S_8003A6F4 *p, int v)
{
    p->unk24 = v;
}

EXTERN_C void *func_8003A754(void *p, short a)
{
    int i;
    func_8001AA28(p, 8);
    for (i = 2; i >= 0; i--)
        AT(p, short, i * 8) = a;
    return p;
}

EXTERN_C void *func_8003A7A4(void *p, int a)
{
    func_8001A8F0(p, a, 8);
    return p;
}

EXTERN_C void *func_8003A7D0(void *p, int a)
{
    func_8001A8F0(p, a, 8);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A7FC);

extern "C++" S_A2_Sv0 f3abec(MATRIX *m) asm("func_8003ABEC");
S_A2_Sv0 f3abec(MATRIX *m)
{
    S_A2_Sv0 r;
    int a;
    short *s = (short *)m;
    a = ratan2(-s[6], SquareRoot0(s[0] * s[0] + s[3] * s[3]));
    r.y = a;
    if ((unsigned short)(a - 0x3FB) < 0xB) {
        if (s[0] < 0) {
            r.x = ratan2(s[1], s[2]) - 0x800;
            r.z = -0x800;
        } else {
            r.x = ratan2(s[1], s[2]);
            r.z = 0;
        }
    } else if ((unsigned short)(a + 0x405) < 0xB) {
        if (s[0] < 0) {
            r.x = -ratan2(s[1], -s[2]) - 0x800;
            r.z = -0x800;
        } else {
            r.x = -ratan2(s[1], -s[2]);
            r.z = 0;
        }
    } else {
        r.x = ratan2(s[7], s[8]);
        r.z = ratan2(s[3], s[0]);
    }
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003AD78);

extern "C++" S_A2_Sv0 f3b168(MATRIX *m) asm("func_8003B168");
S_A2_Sv0 f3b168(MATRIX *m)
{
    S_A2_Sv0 r;
    int a;
    short *s = (short *)m;
    a = ratan2(s[2], SquareRoot0(s[0] * s[0] + s[1] * s[1]));
    r.y = a;
    if ((unsigned short)(a - 0x3FB) < 0xB) {
        if (s[0] < 0) {
            r.x = ratan2(s[3], -s[6]) - 0x800;
            r.z = -0x800;
        } else {
            r.x = ratan2(s[3], -s[6]);
            r.z = 0;
        }
    } else if ((unsigned short)(a + 0x405) < 0xB) {
        if (s[0] < 0) {
            r.x = -ratan2(s[3], s[6]) - 0x800;
            r.z = -0x800;
        } else {
            r.x = -ratan2(s[3], s[6]);
            r.z = 0;
        }
    } else {
        r.x = ratan2(-s[5], s[8]);
        r.z = ratan2(-s[1], s[0]);
    }
    return r;
}

EXTERN_C S_8003B2F0 *func_8003B2F0(S_8003B2F0 *p, S_8003B2F0_V *v)
{
    int a = v->unk0, b = v->unk4, c = v->unk8;
    p->unk14.unk0 = a;
    p->unk14.unk4 = b;
    p->unk14.unk8 = c;
    return p;
}

EXTERN_C S_A2_V4 func_8003B310(void *s) return r
{
    int a = AT(s, int, 0x14), b = AT(s, int, 0x18), c = AT(s, int, 0x1C);
    r.d = 0;
    r.a = a;
    r.b = b;
    r.c = c;
}

EXTERN_C MATRIX *func_8003B334(MATRIX *p, MATRIX *q)
{
    MulMatrix(p, q);
    return p;
}

EXTERN_C MATRIX *func_8003B35C(MATRIX *r, MATRIX *a, MATRIX *b)
{
    MATRIX t;
    MATRIX *tp;
    func_8003A7A4(&t, (int)a);
    tp = &t;
    MulMatrix0(a, b, tp);
    func_8003A7A4(r, (int)tp);
    return r;
}

EXTERN_C MATRIX *func_8003B3C0(MATRIX *p, MATRIX *q)
{
    CompMatrix(p, q, p);
    return p;
}

EXTERN_C MATRIX *func_8003B3EC(MATRIX *r, MATRIX *a, MATRIX *b)
{
    MATRIX t;
    MATRIX *tp;
    func_8003A7A4(&t, (int)a);
    tp = &t;
    CompMatrix(a, b, tp);
    func_8003A7A4(r, (int)tp);
    return r;
}

extern "C++" S_A2_V4z f3b450(int a, void *b) asm("func_8003B450");
S_A2_V4z f3b450(int a, void *b)
{
    MATRIX *m = (MATRIX *)a;
    int *v = (int *)b;
    S_A2_V4z t;
    t.a = m->t[0] + ((m->m[0][0] * v[0] + m->m[0][1] * v[1] + m->m[0][2] * v[2] + 0x800) >> 12);
    t.b = m->t[1] + ((m->m[1][0] * v[0] + m->m[1][1] * v[1] + m->m[1][2] * v[2] + 0x800) >> 12);
    t.c = m->t[2] + ((m->m[2][0] * v[0] + m->m[2][1] * v[1] + m->m[2][2] * v[2] + 0x800) >> 12);
    return t;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B598);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B68C);

EXTERN_C MATRIX *func_8003B780(MATRIX *r, int a, MATRIX *b)
{
    MATRIX t;
    MATRIX *m;
    int i;
    func_8003A7D0(&t, a);
    m = &t;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++)
            t.m[i][j] += b->m[i][j];
        m->t[i] += b->t[i];
    }
    func_8003A7A4(r, (int)&t);
    return r;
}

EXTERN_C MATRIX *func_8003B834(MATRIX *a, MATRIX *b)
{
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++)
            a->m[i][j] += b->m[i][j];
        a->t[i] += b->t[i];
    }
    return a;
}

EXTERN_C MATRIX *func_8003B8AC(MATRIX *r, int a, MATRIX *b)
{
    MATRIX t;
    MATRIX *m;
    int i;
    func_8003A7D0(&t, a);
    m = &t;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++)
            t.m[i][j] -= b->m[i][j];
        m->t[i] -= b->t[i];
    }
    func_8003A7A4(r, (int)&t);
    return r;
}

EXTERN_C MATRIX *func_8003B960(MATRIX *a, MATRIX *b)
{
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++)
            a->m[i][j] -= b->m[i][j];
        a->t[i] -= b->t[i];
    }
    return a;
}

EXTERN_C MATRIX *func_8003B9D8(MATRIX *r, int a, int s)
{
    MATRIX t;
    MATRIX *m;
    int i;
    func_8003A7D0(&t, a);
    m = &t;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++)
            t.m[i][j] >>= s;
        m->t[i] >>= s;
    }
    func_8003A7A4(r, (int)&t);
    return r;
}

EXTERN_C MATRIX *func_8003BA78(MATRIX *m, int s)
{
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++)
            m->m[i][j] >>= s;
        m->t[i] >>= s;
    }
    return m;
}

EXTERN_C MATRIX *func_8003BAD8(MATRIX *r, int a, int s)
{
    MATRIX t;
    MATRIX *m;
    int i;
    func_8003A7D0(&t, a);
    m = &t;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++)
            t.m[i][j] <<= s;
        m->t[i] <<= s;
    }
    func_8003A7A4(r, (int)&t);
    return r;
}

EXTERN_C MATRIX *func_8003BB78(MATRIX *m, int s)
{
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++)
            m->m[i][j] <<= s;
        m->t[i] <<= s;
    }
    return m;
}

EXTERN_C short *func_8003BBD8(short *p)
{
    short a = p[1];
    short b = p[3];
    p[3] = a; p[1] = b;
    a = p[2];
    b = p[6];
    p[6] = a; p[2] = b;
    a = p[5];
    b = p[7];
    p[7] = a; p[5] = b;
    return p;
}

EXTERN_C void *func_8003BC10(void *p, int a)
{
    MATRIX m;
    func_8003A7D0(&m, a);
    func_8003A7A4(p, (int)func_8003BBD8((short *)&m));
    return p;
}

EXTERN_C S_A2_Sv func_8003BC50(short *m, int i) return r
{
    short a, b, c;
    m += i * 3;
    a = m[0]; b = m[1]; c = m[2];
    r.pad = 0; r.x = a; r.y = b; r.z = c;
}

EXTERN_C S_A2_Sv func_8003BC84(short *m, int i) return r
{
    short a, b, c;
    m += i;
    a = m[0]; b = m[3]; c = m[6];
    r.pad = 0; r.x = a; r.y = b; r.z = c;
}

EXTERN_C void func_8003BCB0(short *m, int i, short *v)
{
    m += i * 3;
    m[0] = v[0]; m[1] = v[1]; m[2] = v[2];
}

EXTERN_C void func_8003BCE0(MATRIX *m, int i, SVECTOR *v)
{
    m->m[0][i] = v->vx;
    m->m[1][i] = v->vy;
    m->m[2][i] = v->vz;
}

extern "C++" S_A2_S8 a2_be68(S_A2_S8 *a, S_A2_S8 *b) asm("func_8003BE68");
#define S8(p, i) ((S_A2_S8 *)((short *)(p) + (i)))
EXTERN_C S_A2_Sv4c func_8003BD08(short *a, short *b)
{
    S_A2_S8 x = a2_be68(S8(a, 0), S8(b, 0));
    S_A2_S8 y = a2_be68(S8(a, 1), S8(b, 1));
    S_A2_S8 z = a2_be68(S8(a, 2), S8(b, 2));
    S_A2_S8 w = *S8(a, 3);
    return S_A2_Sv4c(x, y, z, w);
}

extern "C++" S_A2_I8 a2_be84(S_A2_I8 *a, S_A2_I8 *b) asm("func_8003BE84");
#define I8(p, i) ((S_A2_I8 *)((int *)(p) + (i)))
EXTERN_C S_A2_Iv4c func_8003BDB8(int *a, int *b)
{
    S_A2_I8 x = a2_be84(I8(a, 0), I8(b, 0));
    S_A2_I8 y = a2_be84(I8(a, 1), I8(b, 1));
    S_A2_I8 z = a2_be84(I8(a, 2), I8(b, 2));
    S_A2_I8 w = *I8(a, 3);
    return S_A2_Iv4c(x, y, z, w);
}

EXTERN_C S_Short func_8003BE68(S_Short *a, S_Short *b)
{
    S_Short r;
    int t = a->v;
    t += b->v;
    r.v = t;
    return r;
}

EXTERN_C S_Int func_8003BE84(S_Int *a, S_Int *b)
{
    S_Int r;
    r.v = a->v + b->v;
    return r;
}

EXTERN_C S_8003BEA0 *func_8003BEA0(S_8003BEA0 *p, int i)
{
    return &p[i];
}

EXTERN_C void *func_8003BEB4(void *p)
{
    return p;
}

EXTERN_C void *func_8003BEBC(void *p)
{
    return p;
}

EXTERN_C void func_8003BEC4(void *p, int a)
{
    S_A2_VEnt *e = (S_A2_VEnt *)(AT(a, char *, 0) + 0x20);
    e->pfn((char *)a + e->delta, a);
}

C_8003BEF8::C_8003BEF8()
{
    AT(this, void **, 0) = D_80012724;
    unk48 = 0;
}

EXTERN_C void func_8003BF30(void *p, int a)
{
    AT(p, void **, 0) = D_80012724;
    if (AT(p, void *, 0x48)) {
        void *o = operator new(0xC);
        char *t = 0;
        void *v48 = AT(p, void *, 0x48);
        AT(o, void **, 0) = D_80010160;
        AT(o, int, 4) = 0;
        char *g = (char *)&D_800AC57C;
        if (g) t = g + 0xF8;
        func_8001D150(t, new S_A2_X1(o));
        AT(o, void **, 0) = D_80010148;
        AT(o, void *, 8) = v48;
    }
    func_80039A88(p, a);
}

EXTERN_C void func_8003C01C(void *p)
{
    int i;
    S_A2_N14 *v = AT(p, S_A2_N14 *, 0x48);
    while (v) {
        S_A2_N14 *w = v;
        w->f14 = 0;
        v = w->next;
    }
    if (!AT(p, void *, 0x28))
        return;
    for (i = 0;; i++) {
        char *h = AT(p, char *, 0x28);
        List *l = h ? AT(h, List *, 0) : 0;
        char *h2;
        if (!(i < l->count))
            break;
        h2 = h ? h + 8 : 0;
        func_8003C01C(func_80019F64(h2 ? AT(h2, List *, 0) : 0, i));
    }
}


EXTERN_C void func_8003C0D0(void *p, int a)
{
    S_A2_VD *first = AT(p, S_A2_VD *, 0x48);
    S_A2_VD *n;
    if (!first) return;
    if (a) {
        void *o = operator new(0xC);
        char *t = 0;
        void *v48 = AT(p, void *, 0x48);
        AT(o, void **, 0) = D_80010160;
        AT(o, int, 4) = 0;
        char *g = (char *)&D_800AC57C;
        if (g) t = g + 0xF8;
        func_8001D150(t, new S_A2_X1(o));
        AT(o, void **, 0) = D_80010148;
        AT(o, void *, 8) = v48;
    } else {
        n = first;
        while (n) {
            S_A2_VD *next = AT(n, S_A2_VD *, 4);
            func_8003C764(n, 0);
            AT(n, int, 4) = 0;
            delete n;
            n = next;
        }
        AT(p, int, 0x48) = 0;
    }
}

EXTERN_C void func_8003C1E4(A2VObj0 *p)
{
    p->v01();
    p->v02((char *)p + 4);
    if (AT(p, void *, 0x48))
        func_8003CB50(AT(p, void *, 0x48));
    if (AT(p, void *, 0x28))
        func_8003944C(AT(p, void *, 0x28), &D_800B4D1C);
}

EXTERN_C int func_8003C270(void *p, void *a)
{
    if (AT(p, void *, 0x48))
        return func_8003C908(AT(p, void *, 0x48), a);
    AT(p, void *, 0x48) = func_8003C5A8(operator new(0x1C), a ? (char *)a + 8 : 0, 0, 0);
    return 1;
}

EXTERN_C void func_8003C2E4(void *p, void *q)
{
    if (AT(p, void *, 0x48))
        AT(p, void *, 0x48) = func_8003CA10(AT(p, void *, 0x48), q);
}

EXTERN_C void func_8003C320(void *p, int a)
{
    void *q;
    int i;
    for (q = AT(p, void *, 0x48); q; q = AT(q, void *, 4))
        func_8003CC78(q, a);
    if (AT(p, void *, 0x28)) {
        i = AT(AT(p, List **, 0x28)[0], int, 4);
        for (i--; i >= 0; i--) {
            char *h = AT(p, char *, 0x28);
            char *h2 = h ? h + 8 : 0;
            func_8003C320(func_80019F64(h2 ? AT(h2, List *, 0) : 0, i), a);
        }
    }
}

EXTERN_C void func_8003C3E4(void *p, int a)
{
    void *q;
    for (q = AT(p, void *, 0x48); q; q = AT(q, void *, 4))
        func_8003CC78(q, a);
}

EXTERN_C void func_8003C434(void *p, void *a, int b, int c)
{
    void *o = func_8003C5A8(operator new(0x1C), a, b, c);
    if (b) {
        AT(o, void *, 4) = AT(p, void *, 0x48);
        AT(p, void *, 0x48) = o;
    } else if (AT(p, void *, 0x48))
        func_8001A678(AT(p, void *, 0x48), (int)o);
    else
        AT(p, void *, 0x48) = o;
}

EXTERN_C void func_8003C4CC(void *p, int a)
{
    func_8003BEC4(p, a);
}

EXTERN_C void func_8003C4EC()
{
    func_8003C510(&D_800B4D1C);
}
