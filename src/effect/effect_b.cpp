#include "common.h"
#include "effect/effect.h"

EXTERN_C void *func_800E0188(void *self, int n)
{
    void *p = FIELD_AT(self, void *, 0x0);
    int i = 0;
    while (i < n) {
        i++;
        p = FIELD_AT(p, void *, 0x4);
    }
    return p;
}

EXTERN_C void *func_800E01B0(short kind, short b, void *owner)
{
    Cond *c = 0;
    switch (kind) {
    case -1: {
        CondMin *m = (CondMin *)operator new(0x10);
        m->vptr = D_800D5F20;
        m->owner = owner;
        m->id = kind;
        m->vptr = D_800D5EC8;
        m->min = b;
        c = m;
        break;
    }
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        c = (Cond *)operator new(0xC);
        c->vptr = D_800D5F20;
        c->owner = owner;
        c->id = kind;
        c->vptr = D_800D5E70;
        break;
    case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        c = (Cond *)operator new(0xC);
        c->vptr = D_800D5F20;
        c->owner = owner;
        c->id = kind;
        c->vptr = D_800D5E18;
        break;
    case 16: {
        CondList *l = (CondList *)operator new(0x24);
        l->vptr = D_800D5F20;
        l->owner = owner;
        l->id = kind;
        l->vptr = D_800D5DC0;
        l->ref.list = &l->list;
        func_800198E0(&l->list, 0x10, 0);
        c = l;
        break;
    }
    }
    return c;
}

EXTERN_C void *func_800E01B0(short a, short b, void *c);

EXTERN_C void *func_800E02F4(void *self, void *arg)
{
    int id = FIELD_AT(self, short, 0x4);
    VtEntry *vt = FIELD_AT(self, VtEntry *, 0x8);
    void *p = func_800E01B0(id, ((short (*)(void *))vt[9].pfn)((char *)self + vt[9].delta), arg);
    vt = FIELD_AT(p, VtEntry *, 0x8);
    vt[7].pfn((char *)p + vt[7].delta, (int)self);
    return p;
}

EXTERN_C void *func_800E037C(void *self)
{
    return self;
}

EXTERN_C int D_800D6604[];
EXTERN_C void *func_800E4058(void *self, void *other);

struct RV_800E0384 {
    short base, step, range, phase, spread;
    int *vptr;
    RV_800E0384()
    {
        vptr = D_800D6038;
        base = 0;
        step = 0;
        range = 0;
        phase = 0;
    }
};

struct A_800E0384 {
    int *vptr;
    int next;
    A_800E0384() { vptr = D_80010178; next = 0; }
};

struct B_800E0384 : A_800E0384 {
    short id;
    B_800E0384(short aid) { vptr = D_800D5DB0; id = aid; }
};

struct V_800E0384 : B_800E0384 {
    V_800E0384(short aid) : B_800E0384(aid) { vptr = D_800D6604; }
};

struct C_800E0384 : V_800E0384 {
    short sC, sE, s10, s12, s14;
    short pad16;
    int w18, w1C, w20, w24;
    int pad28;
    int w2C, w30, w34, w38;
    RV_800E0384 rv;
    int w4C, w50, w54, w58;
    char m5C[0x10];
    int w6C, w70;
    short s74, s76, s78, s7A, s7C, s7E;
    C_800E0384(short aid);
};

C_800E0384::C_800E0384(short aid) : V_800E0384(aid), w24(1)
{
    func_800E4058(m5C, 0);
    w2C = 0;
    w30 = 0;
    w34 = 0;
    w38 = 0;
    w4C = 0;
    w58 = 0;
    w50 = 0;
    w54 = 0;
    w6C = 0;
    s74 = 0;
    s76 = 0;
    w70 = 0;
    s78 = 0;
    s7A = 0;
    s7C = 0;
    s7E = 0;
    s10 = 0;
    sC = 0;
    sE = 0;
    s14 = 0;
    w18 = 0;
    w1C = 0;
    w20 = 0;
    s12 = 0;
}

EXTERN_C int D_800D6604[];
EXTERN_C void *func_800E4058(void *self, void *other);
EXTERN_C void *func_800E41B8(void *self, void *other);
EXTERN_C IdArray *func_800DDFC0(IdArray *self, IdArray *other);
EXTERN_C IdArray *func_800DE1E8(IdArray *self, IdArray *other);

/* Copy constructor of the C_800E0384 class (same layout; own type names so it can be
   pasted next to it). */
struct RV_800E0468 {
    short base, step, range, phase, spread;
    int *vptr;
    RV_800E0468()
    {
        vptr = D_800D6038;
        base = 0;
        step = 0;
        range = 0;
        phase = 0;
    }
};

struct A_800E0468 {
    int *vptr;
    int next;
    A_800E0468() { vptr = D_80010178; next = 0; }
};

struct B_800E0468 : A_800E0468 {
    short id;
    B_800E0468(short aid) { vptr = D_800D5DB0; id = aid; }
};

struct V_800E0468 : B_800E0468 {
    V_800E0468(short aid) : B_800E0468(aid) { vptr = D_800D6604; }
};

struct C_800E0468 : V_800E0468 {
    short sC, sE, s10, s12, s14;
    short pad16;
    int w18, w1C, w20, w24;
    int w28;
    void *p2C, *p30;
    IdArray *p34, *p38;
    RV_800E0468 rv;
    int w4C, w50, w54, w58;
    char m5C[0x10];
    int w6C, w70;
    short s74, s76, s78, s7A, s7C, s7E;
    short s80, s82, s84;
    unsigned char c86, c87, c88;
    C_800E0468(const C_800E0468 &o);
};

C_800E0468::C_800E0468(const C_800E0468 &o) : V_800E0468(o.id), w24(0)
{
    func_800E4058(m5C, 0);
    w28 = o.w28;
    p2C = 0;
    p30 = 0;
    p34 = func_800DDFC0((IdArray *)operator new(0x14), o.p34);
    p38 = func_800DE1E8((IdArray *)operator new(0x14), o.p38);
    rv = o.rv;
    w4C = 0;
    w50 = 0;
    w54 = 0;
    w58 = 0;
    w6C = o.w6C;
    s74 = o.s74;
    s76 = o.s76;
    w70 = o.w70;
    s78 = o.s78;
    s7A = o.s7A;
    s7C = o.s7C;
    s7E = o.s7E;
    func_800E41B8(m5C, (void *)o.m5C);
    c86 = o.c86;
    c87 = o.c87;
    c88 = o.c88;
    s10 = 0;
    sC = 0;
    sE = 0;
    s14 = 0;
    w18 = 0;
    w1C = 0;
    w20 = 0;
    s12 = 0;
    s80 = o.s80;
    s82 = o.s82;
    s84 = o.s84;
}

EXTERN_C int D_800D6604[];
EXTERN_C void func_800E40BC(void *self, int flags);

struct P8_800E0638 {
    int pad[2];
    VtEntry *vptr;
};

EXTERN_C void func_800E0638(IdNode *self, int flags)
{
    Poly *p;
    P8_800E0638 *q;
    self->vptr = D_800D6604;
    p = FIELD_AT(self, Poly *, 0x34);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x38);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x2C);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x30);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x4C);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    q = FIELD_AT(self, P8_800E0638 *, 0x50);
    if (q)
        q->vptr[1].pfn((char *)q + q->vptr[1].delta, 3);
    q = FIELD_AT(self, P8_800E0638 *, 0x54);
    if (q)
        q->vptr[1].pfn((char *)q + q->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x58);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    func_800E40BC((char *)self + 0x5C, 2);
    func_800D67CC(self, flags);
}

EXTERN_C int func_800E4130(void *self, short value);
EXTERN_C int func_800E4174(void *self, short value);
EXTERN_C void func_800E41FC(void *self);
EXTERN_C void func_800E424C(void *self);
EXTERN_C void func_800E0BD8(void *self);
EXTERN_C int func_800E0AEC(void *self);
EXTERN_C void func_800E0B60(void *self, int arg);
EXTERN_C void *func_800E0DAC(void *self, void *arg, void *p);
EXTERN_C void func_800E0E20(void *self, void *arg);

inline Vec4 pos_800E07E0(void *n)
{
    return FIELD_AT(n, Vec4, 0x28);
}

EXTERN_C void func_800E07E0(void *self, void *arg, void *owner)
{
    int ok = 0;
    if (FIELD_AT(self, short, 0x10) != 0) {
        ok = 1;
    } else {
        void *p = FIELD_AT(self, void *, 0x54);
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
        if (((int (*)(void *))vt[10].pfn)((char *)p + vt[10].delta))
            ok = 1;
    }
    if (ok) {
        void *n;
        if (func_800E4130((char *)self + 0x5C, FIELD_AT(self, short, 0x12)))
            func_800E41FC((char *)self + 0x5C);
        if (func_800E4174((char *)self + 0x5C, FIELD_AT(self, short, 0x12)))
            func_800E424C((char *)self + 0x5C);
        n = FIELD_AT(self, void *, 0x4C);
        Vec4 pos(0, 0, 0, 0);
        func_800E0BD8(self);
        while (n) {
            VtEntry *vt = FIELD_AT(n, VtEntry *, 0x0);
            switch ((short)((int (*)(void *, void *))vt[2].pfn)((char *)n + vt[2].delta, self)) {
            case 0:
                n = FIELD_AT(n, void *, 0x4);
                break;
            case 1:
                if (func_800E0AEC(self)) {
                    pos = pos_800E07E0(n);
                    func_800E0B60(self, (int)&pos);
                }
                n = func_800E0DAC(self, arg, n);
                break;
            case 2:
                if (func_800E0AEC(self)) {
                    pos = pos_800E07E0(n);
                    func_800E0B60(self, (int)&pos);
                }
                if (FIELD_AT(self, signed char, 0x87) == 0) {
                    func_800E0E20(self, arg);
                    n = 0;
                    FIELD_AT(self, int, 0x18) = 0;
                } else {
                    n = func_800E0DAC(self, arg, n);
                }
                goto tail;
            case 3:
                if (func_800E0AEC(self)) {
                    pos = pos_800E07E0(n);
                    func_800E0B60(self, (int)&pos);
                }
            tail:
                FIELD_AT(self, short, 0x10) = 2;
                if (FIELD_AT(self, unsigned char, 0x88) >> 7)
                    FIELD_AT(owner, char, 0x7C) = 1;
                break;
            }
        }
    }
    if (FIELD_AT(self, void *, 0x58))
        func_800E07E0(FIELD_AT(self, void *, 0x58), arg, owner);
    if (FIELD_AT(self, void *, 0x4))
        func_800E07E0(FIELD_AT(self, void *, 0x4), arg, owner);
}

EXTERN_C int func_800E0AEC(void *self)
{
    void *n;
    if (!FIELD_AT(self, void *, 0x58))
        return 0;
    for (n = FIELD_AT(self, void *, 0x58); n; n = FIELD_AT(n, void *, 0x4)) {
        Poly *p = FIELD_AT(n, Poly *, 0x54);
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
        if (((int (*)(void *))vt[10].pfn)((char *)p + vt[10].delta))
            return 1;
    }
    return 0;
}

EXTERN_C void func_800E0B60(void *self, int arg)
{
    void *n;
    if (!FIELD_AT(self, void *, 0x58))
        return;
    for (n = FIELD_AT(self, void *, 0x58); n; n = FIELD_AT(n, void *, 0x4)) {
        Poly *p = FIELD_AT(n, Poly *, 0x54);
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
        ((void (*)(void *, int))vt[5].pfn)((char *)p + vt[5].delta, arg);
    }
}

EXTERN_C void *func_800E1B24(void *self);

inline int is2_800E0BD8(void *self)
{
    return FIELD_AT(self, short, 0x10) == 2;
}

EXTERN_C void func_800E0BD8(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x54);
    VtEntry *vt;
    FIELD_AT(self, int, 0x18) = 0;
    vt = FIELD_AT(p, VtEntry *, 0x8);
    if (((int (*)(void *))vt[10].pfn)((char *)p + vt[10].delta))
        return;
    FIELD_AT(self, short, 0xC)++;
    FIELD_AT(self, short, 0x12)++;
    switch (FIELD_AT(self, short, 0x80)) {
    case 0:
        if (FIELD_AT(self, short, 0xC) > FIELD_AT(self, short, 0x82)) {
            FIELD_AT(self, int, 0x20) = 1;
            if ((FIELD_AT(self, short, 0xC) = FIELD_AT(self, short, 0x84)) != 0)
                return;
        }
        break;
    case 2:
        if (is2_800E0BD8(self)) {
            FIELD_AT(self, int, 0x20) = 1;
            return;
        }
        break;
    case 1:
    case 3:
    case 4: {
        void *q = func_800E1B24(self);
        if (FIELD_AT(q, int, 0x20) && !FIELD_AT(q, int, 0x4C))
            FIELD_AT(self, int, 0x20) = 1;
        break;
    }
    }
    if (FIELD_AT(self, short, 0xE) == 0)
        FIELD_AT(self, int, 0x18) = 1;
    if (++FIELD_AT(self, short, 0xE) >= FIELD_AT(self, short, 0x7E))
        FIELD_AT(self, short, 0xE) = 0;
}

EXTERN_C bool func_800E0D2C(void *self)
{
    int r = 0;
    if (FIELD_AT(self, int, 0x18) != 0)
        r = FIELD_AT(self, int, 0x1C) == 0;
    return r;
}

EXTERN_C short func_800E0D50(void *self)
{
    short step = FIELD_AT(self, short, 0x7A);
    short max = FIELD_AT(self, short, 0x7C);
    if (max == 0)
        return step;
    if (FIELD_AT(self, unsigned short, 0x14) + step >= max) {
        step = max - FIELD_AT(self, unsigned short, 0x14);
        FIELD_AT(self, unsigned short, 0x14) = max;
        FIELD_AT(self, int, 0x1C) = 1;
    } else {
        FIELD_AT(self, unsigned short, 0x14) += step;
    }
    return step;
}

EXTERN_C void func_800E343C(void *self, Poly *p);

EXTERN_C void *func_800E0DAC(void *self, void *arg, void *p)
{
    void *next;
    func_800E343C(p, (Poly *)arg);
    next = FIELD_AT(p, void *, 0x4);
    FIELD_AT(self, Link *, 0x4C) = func_8001A744(FIELD_AT(self, Link *, 0x4C), (Link *)p);
    if (p) {
        Poly *o = (Poly *)p;
        o->vptr[1].pfn((char *)o + o->vptr[1].delta, 3);
    }
    return next;
}

EXTERN_C void *func_800E0DAC(void *self, void *arg, void *p);

EXTERN_C void func_800E0E20(void *self, void *arg)
{
    void *p;
    for (p = FIELD_AT(self, void *, 0x4C); p; p = func_800E0DAC(self, arg, p))
        ;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect_b", func_800E0E70);

EXTERN_C void *func_800E3518(void *self);
EXTERN_C void *func_800E37F4(void *self);

EXTERN_C void func_800E0FDC(void *self, Poly *p)
{
    void *o;
    if (FIELD_AT(FIELD_AT(self, void *, 0x30), signed char, 0x40))
        o = func_800E37F4(operator new(0x70));
    else
        o = func_800E3518(operator new(0x70));
    ((void (*)(void *, int))p->vptr[5].pfn)((char *)p + p->vptr[5].delta, FIELD_AT(o, int, 0xC));
    if (FIELD_AT(self, Link *, 0x4C))
        func_8001A678(FIELD_AT(self, Link *, 0x4C), (Link *)o);
    else
        FIELD_AT(self, Link *, 0x4C) = (Link *)o;
}

struct ZVec_800E1090 : Vec4 {
    ZVec_800E1090() { x = 0; y = 0; z = 0; w = 0; }
};

struct Frame_800E1090 {
    ZVec_800E1090 a, b, c, d, e, f;
};

EXTERN_C void func_800E1604(void *self, void *arg);
EXTERN_C bool func_800E0D2C(void *self);
EXTERN_C void func_800E0E70(void *self);
EXTERN_C short func_800E0D50(void *self);
EXTERN_C void func_800D7F94(void *self);
EXTERN_C void func_800E0FDC(void *self, Poly *p);


inline Vec4 get_800E1090(void *o)
{
    VtEntry *vt = FIELD_AT(o, VtEntry *, 0x0);
    return ((Vec4 (*)(void *, int))vt[4].pfn)((char *)o + vt[4].delta, 0);
}

EXTERN_C void func_800E1090(void *self, void *arg)
{
    int i, n;
    if (FIELD_AT(self, void *, 0x58))
        func_800E1604(FIELD_AT(self, void *, 0x58), arg);
    if (!func_800E0D2C(self))
        return;
    func_800E0E70(self);
    n = func_800E0D50(self);
    for (i = 0; i < n; i++) {
        Frame_800E1090 fr;
        func_800D7F94(&fr);
        D_1F800000.v14 = get_800E1090(FIELD_AT(self, void *, 0x2C));
        D_1F800000.v34 = get_800E1090(FIELD_AT(self, void *, 0x30));
        (Vec4 &)fr.a = D_1F800000.v14;
        (Vec4 &)fr.b = D_1F800000.v34;
        {
            void *o = FIELD_AT(self, void *, 0x50);
            VtEntry *vt = FIELD_AT(o, VtEntry *, 0x8);
            D_1F800000.v24 = ((Vec4 (*)(void *, void *))vt[4].pfn)((char *)o + vt[4].delta, &fr);
        }
        func_800E0FDC(self, (Poly *)arg);
    }
}

/* Params_800E2704, ZVec_800E1090, Frame_800E1090: same definitions as in func_800E1090.cpp (paste once). */
EXTERN_C bool func_800E0D2C(void *self);
EXTERN_C void func_800E0E70(void *self);
EXTERN_C short func_800E0D50(void *self);
EXTERN_C void func_800D7F94(void *self);
EXTERN_C void func_800E0FDC(void *self, Poly *p);

inline Vec4 get_800E1304(void *o, int a)
{
    VtEntry *vt = FIELD_AT(o, VtEntry *, 0x0);
    return ((Vec4 (*)(void *, int))vt[4].pfn)((char *)o + vt[4].delta, a);
}

EXTERN_C void func_800E1304(void *self, void *arg)
{
    int m, n, j;
    void *p;
    VtEntry *vt;
    if (FIELD_AT(self, void *, 0x58))
        func_800E1304(FIELD_AT(self, void *, 0x58), arg);
    p = FIELD_AT(self, void *, 0x54);
    vt = FIELD_AT(p, VtEntry *, 0x8);
    m = ((int (*)(void *))vt[4].pfn)((char *)p + vt[4].delta);
    if (!m)
        return;
    func_800E0E70(self);
    n = func_800E0D50(self);
    for (j = 0; j < m; j++) {
        int k;
        int x;
        p = FIELD_AT(self, void *, 0x54);
        vt = FIELD_AT(p, VtEntry *, 0x8);
        x = ((int (*)(void *, int))vt[8].pfn)((char *)p + vt[8].delta, j);
        for (k = 0; k < n; k++) {
            Frame_800E1090 fr;
            func_800D7F94(&fr);
            D_1F800000.v14 = get_800E1304(FIELD_AT(self, void *, 0x2C), x);
            D_1F800000.v34 = get_800E1304(FIELD_AT(self, void *, 0x30), 0);
            (Vec4 &)fr.a = D_1F800000.v14;
            (Vec4 &)fr.b = D_1F800000.v34;
            {
                void *o = FIELD_AT(self, void *, 0x50);
                VtEntry *vt = FIELD_AT(o, VtEntry *, 0x8);
                D_1F800000.v24 = ((Vec4 (*)(void *, void *))vt[4].pfn)((char *)o + vt[4].delta, &fr);
            }
            func_800E0FDC(self, (Poly *)arg);
        }
    }
    p = FIELD_AT(self, void *, 0x54);
    vt = FIELD_AT(p, VtEntry *, 0x8);
    ((void (*)(void *))vt[6].pfn)((char *)p + vt[6].delta);
}

/* Params_800E2704, ZVec_800E1090, Frame_800E1090, get_800E1090: same definitions as in func_800E1090.cpp (paste once). */
EXTERN_C bool func_800E0D2C(void *self);
EXTERN_C void func_800E0E70(void *self);
EXTERN_C short func_800E0D50(void *self);
EXTERN_C void func_800D7F94(void *self);
EXTERN_C void func_800E0FDC(void *self, Poly *p);
EXTERN_C void *func_800E1B24(void *self);

inline Vec4 getp_800E1604(void *o, Vec4 *a)
{
    VtEntry *vt = FIELD_AT(o, VtEntry *, 0x0);
    return ((Vec4 (*)(void *, Vec4 *))vt[4].pfn)((char *)o + vt[4].delta, a);
}

EXTERN_C void func_800E1604(void *self, void *arg)
{
    int i, j, n;
    void *q;
    if (FIELD_AT(self, void *, 0x58))
        func_800E1604(FIELD_AT(self, void *, 0x58), arg);
    if (!func_800E0D2C(self))
        return;
    func_800E0E70(self);
    Frame_800E1090 fr;
    Vec4 pos(0, 0, 0, 0);
    Vec4 dir(0, 0, 0, 0);
    n = func_800E0D50(self);
    switch (FIELD_AT(FIELD_AT(self, void *, 0x2C), signed char, 0x40)) {
    case 0:
    case 7:
    case 8:
        for (i = 0; i < n; i++) {
            func_800D7F94(&fr);
            D_1F800000.v14 = get_800E1090(FIELD_AT(self, void *, 0x2C));
            D_1F800000.v34 = get_800E1090(FIELD_AT(self, void *, 0x30));
            (Vec4 &)fr.a = D_1F800000.v14;
            (Vec4 &)fr.b = D_1F800000.v34;
            {
                void *o = FIELD_AT(self, void *, 0x50);
                VtEntry *vt = FIELD_AT(o, VtEntry *, 0x8);
                D_1F800000.v24 = ((Vec4 (*)(void *, void *))vt[4].pfn)((char *)o + vt[4].delta, &fr);
            }
            func_800E0FDC(self, (Poly *)arg);
        }
        break;
    case 9:
        for (q = FIELD_AT(func_800E1B24(self), void *, 0x4C); q; q = FIELD_AT(q, void *, 0x4)) {
            pos = Vec4(FIELD_AT(q, Vec4, 0x28));
            dir = Vec4(FIELD_AT(q, Vec4, 0x38));
            for (j = 0; j < n; j++) {
                func_800D7F94(&fr);
                D_1F800000.v14 = getp_800E1604(FIELD_AT(self, void *, 0x2C), &pos);
                D_1F800000.v34 = getp_800E1604(FIELD_AT(self, void *, 0x30), &pos);
                (Vec4 &)fr.a = D_1F800000.v14;
                (Vec4 &)fr.b = D_1F800000.v34;
                (Vec4 &)fr.c = pos;
                (Vec4 &)fr.d = dir;
                {
                    void *o = FIELD_AT(self, void *, 0x50);
                    VtEntry *vt = FIELD_AT(o, VtEntry *, 0x8);
                    D_1F800000.v24 = ((Vec4 (*)(void *, void *))vt[4].pfn)((char *)o + vt[4].delta, &fr);
                }
                func_800E0FDC(self, (Poly *)arg);
            }
        }
        break;
    case 1:
        break;
    }
    if (FIELD_AT(self, void *, 0x4))
        func_800E1604(FIELD_AT(self, void *, 0x4), arg);
}

EXTERN_C void func_800E1AE4(void *self, Link *link)
{
    if (FIELD_AT(self, Link *, 0x58))
        func_8001A678(FIELD_AT(self, Link *, 0x58), link);
    else
        FIELD_AT(self, Link *, 0x58) = link;
}

EXTERN_C void *func_800E1B24(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x54);
    VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
    return ((void *(*)(void *))vt[2].pfn)((char *)p + vt[2].delta);
}

EXTERN_C void func_800E49D8(void *self, void *arg);
EXTERN_C void func_800E4B88(void *self, void *arg);
EXTERN_C int func_8003912C(void *p, int n);

EXTERN_C void func_800E1B60(void *self, void *arg)
{
    void *s;
    func_800E49D8(FIELD_AT(self, void *, 0x2C), arg);
    func_800E4B88(FIELD_AT(self, void *, 0x30), arg);
    s = FIELD_AT(self, void *, 0x50);
    switch (FIELD_AT(s, short, 0x0)) {
    case 0:
        FIELD_AT(s, int, 0x1C) = FIELD_AT(FIELD_AT(self, void *, 0x2C), int, 0x3C);
        break;
    case 1:
        FIELD_AT(FIELD_AT(self, void *, 0x50), int, 0xC) =
            func_8003912C(FIELD_AT(FIELD_AT(arg, void *, 0x4), void *, 0x1B8), 2);
        break;
    case 2:
        FIELD_AT(FIELD_AT(self, void *, 0x50), int, 0xC) =
            func_8003912C(FIELD_AT(FIELD_AT(arg, void *, 0x4), void *, 0x1B8), 5);
        break;
    }
    if (FIELD_AT(self, void *, 0x58))
        func_800E1B60(FIELD_AT(self, void *, 0x58), arg);
    if (FIELD_AT(self, void *, 0x4))
        func_800E1B60(FIELD_AT(self, void *, 0x4), arg);
}

/* RV_800E0468 .. C_800E0468: the class declarations already in the unit (paste once). */
EXTERN_C int D_800D6604[];

EXTERN_C void *func_800E4CAC(void *self, short id);
EXTERN_C void *func_800E5030(void *self, short id);
EXTERN_C void *func_800E5254(void *self, short id);
EXTERN_C void *func_800E5450(void *self, short id);
EXTERN_C void func_800E49D8(void *self, void *arg);
EXTERN_C void func_800E4B88(void *self, void *arg);
EXTERN_C int func_8003912C(void *p, int n);
EXTERN_C void *func_800E01B0(short kind, short b, void *owner);

EXTERN_C void *func_800E1C5C(void *src, int a, void *b)
{
    C_800E0468 *n = new C_800E0468(*(C_800E0468 *)src);
    void *p;
    VtEntry *vt;
    switch (FIELD_AT(((C_800E0468 *)src)->p2C, signed char, 0x41)) {
    case 0:
        n->p2C = func_800E4CAC(operator new(0x48), ((C_800E0468 *)src)->id);
        break;
    case 1:
        n->p2C = func_800E5030(operator new(0x48), ((C_800E0468 *)src)->id);
        break;
    case 2:
        n->p2C = func_800E5254(operator new(0x48), ((C_800E0468 *)src)->id);
        break;
    case 3:
        n->p2C = func_800E5450(operator new(0x48), ((C_800E0468 *)src)->id);
        break;
    }
    p = n->p2C;
    vt = FIELD_AT(p, VtEntry *, 0x0);
    vt[3].pfn((char *)p + vt[3].delta, (int)((C_800E0468 *)src)->p2C);
    func_800E49D8(n->p2C, b);
    switch (FIELD_AT(((C_800E0468 *)src)->p30, signed char, 0x41)) {
    case 0:
        n->p30 = func_800E4CAC(operator new(0x48), ((C_800E0468 *)src)->id);
        break;
    case 1:
        n->p30 = func_800E5030(operator new(0x48), ((C_800E0468 *)src)->id);
        break;
    case 2:
        n->p30 = func_800E5254(operator new(0x48), ((C_800E0468 *)src)->id);
        break;
    case 3:
        n->p30 = func_800E5450(operator new(0x48), ((C_800E0468 *)src)->id);
        break;
    }
    p = n->p30;
    vt = FIELD_AT(p, VtEntry *, 0x0);
    vt[3].pfn((char *)p + vt[3].delta, (int)((C_800E0468 *)src)->p30);
    func_800E4B88(n->p30, b);
    switch (FIELD_AT((void *)((C_800E0468 *)src)->w50, short, 0x0)) {
    case 0: {
        KeyVec2 *k = (KeyVec2 *)operator new(0x20);
        keyvec_init(k, 0);
        k->extra = FIELD_AT(((C_800E0468 *)src)->p2C, int, 0x3C);
        n->w50 = (int)k;
        break;
    }
    case 1: {
        KeyInt *k = (KeyInt *)operator new(0x10);
        key_init(k, 1);
        k->vptr = D_800D6138;
        k->value = 0;
        k->value = func_8003912C(FIELD_AT(FIELD_AT(b, void *, 0x4), void *, 0x1B8), 2);
        n->w50 = (int)k;
        break;
    }
    case 2: {
        KeyInt *k = (KeyInt *)operator new(0x10);
        key_init(k, 2);
        k->vptr = D_800D6110;
        k->value = 0;
        k->value = func_8003912C(FIELD_AT(FIELD_AT(b, void *, 0x4), void *, 0x1B8), 5);
        n->w50 = (int)k;
        break;
    }
    case 5: {
        Key *k = (Key *)operator new(0xC);
        key_init(k, 5);
        k->vptr = D_800D60E8;
        n->w50 = (int)k;
        break;
    }
    case 6: {
        Key *k = (Key *)operator new(0xC);
        key_init(k, 6);
        k->vptr = D_800D60C0;
        n->w50 = (int)k;
        break;
    }
    case 8: {
        Key *k = (Key *)operator new(0xC);
        key_init(k, 8);
        k->vptr = D_800D6098;
        n->w50 = (int)k;
        break;
    }
    case 10: {
        KeyVec2 *k = (KeyVec2 *)operator new(0x20);
        keyvec_init(k, 10);
        k->vptr = D_800D6070;
        n->w50 = (int)k;
        break;
    }
    case 11: {
        KeyVec2 *k = (KeyVec2 *)operator new(0x20);
        keyvec_init(k, 11);
        k->vptr = D_800D6048;
        n->w50 = (int)k;
        break;
    }
    }
    p = (void *)n->w50;
    vt = FIELD_AT(p, VtEntry *, 0x8);
    vt[3].pfn((char *)p + vt[3].delta, ((C_800E0468 *)src)->w50);
    {
        void *q = (void *)((C_800E0468 *)src)->w54;
        int id = FIELD_AT(q, short, 0x4);
        void *r;
        vt = FIELD_AT(q, VtEntry *, 0x8);
        r = func_800E01B0(id, ((short (*)(void *))vt[9].pfn)((char *)q + vt[9].delta), (void *)a);
        vt = FIELD_AT(r, VtEntry *, 0x8);
        vt[7].pfn((char *)r + vt[7].delta, (int)q);
        n->w54 = (int)r;
    }
    if (((C_800E0468 *)src)->w58)
        n->w58 = (int)func_800E1C5C((void *)((C_800E0468 *)src)->w58, (int)n, b);
    if (((C_800E0468 *)src)->next)
        func_8001A678((Link *)n, (Link *)func_800E1C5C((void *)((C_800E0468 *)src)->next, a, b));
    return n;
}

EXTERN_C void *func_800E1B24(void *self);

EXTERN_C bool func_800E21B8(void *self)
{
    Poly *p;
    VtEntry *vt;
    if (FIELD_AT(self, void *, 0x4) && !func_800E21B8(FIELD_AT(self, void *, 0x4)))
        return false;
    if (FIELD_AT(self, void *, 0x58) && !func_800E21B8(FIELD_AT(self, void *, 0x58)))
        return false;
    p = FIELD_AT(self, Poly *, 0x54);
    vt = FIELD_AT(p, VtEntry *, 0x8);
    if (((int (*)(void *))vt[10].pfn)((char *)p + vt[10].delta)) {
        void *q = func_800E1B24(self);
        if (!FIELD_AT(q, int, 0x20) || FIELD_AT(q, int, 0x4C))
            return false;
        p = FIELD_AT(self, Poly *, 0x54);
        vt = FIELD_AT(p, VtEntry *, 0x8);
        if (((int (*)(void *))vt[4].pfn)((char *)p + vt[4].delta) || FIELD_AT(self, int, 0x4C))
            return false;
        return true;
    }
    if (FIELD_AT(self, int, 0x20) && !FIELD_AT(self, int, 0x4C))
        return true;
    return false;
}

EXTERN_C void func_800E2F2C(void *p);

EXTERN_C void func_800E22E0(void *self)
{
    if (FIELD_AT(self, void *, 0x4C))
        func_800E2F2C(FIELD_AT(self, void *, 0x4C));
    if (FIELD_AT(self, void *, 0x58))
        func_800E22E0(FIELD_AT(self, void *, 0x58));
    if (FIELD_AT(self, void *, 0x4))
        func_800E22E0(FIELD_AT(self, void *, 0x4));
}

EXTERN_C char D_800B4C48[];
EXTERN_C void func_80025444(void *a, void *b, int c);

EXTERN_C void func_800E2348(void *self)
{
    Poly *p;
    func_80025444(D_800B4C48, FIELD_AT(self, void *, 0x28), FIELD_AT(self, short, 0x78));
    p = FIELD_AT(self, Poly *, 0x28);
    ((void (*)(void *))p->vptr[3].pfn)((char *)p + p->vptr[3].delta);
}

EXTERN_C void func_800E23A0(void *self, short arg)
{
    if (FIELD_AT(self, short, 0x10) == 0) {
        Poly *p = FIELD_AT(self, Poly *, 0x54);
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
        if (((int (*)(void *, short))vt[3].pfn)((char *)p + vt[3].delta, arg))
            FIELD_AT(self, short, 0x10) = 1;
    }
    if (FIELD_AT(self, void *, 0x58))
        func_800E23A0(FIELD_AT(self, void *, 0x58), arg);
    if (FIELD_AT(self, void *, 0x4))
        func_800E23A0(FIELD_AT(self, void *, 0x4), arg);
}

EXTERN_C int func_800E2440(void *self)
{
    return FIELD_AT(self, int, 0x38);
}

EXTERN_C int func_800E244C(void *self)
{
    return FIELD_AT(self, int, 0x34);
}

EXTERN_C int func_800E2458(void *self)
{
    return FIELD_AT(self, int, 0x4C);
}

EXTERN_C Link *func_800E2464(Link *a, Link *b)
{
    return func_8001A744(a, b);
}

EXTERN_C int func_800E2484(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect_b", func_800E2490);

INCLUDE_ASM("asm/effect/nonmatchings/effect_b", func_800E24DC);

INCLUDE_ASM("asm/effect/nonmatchings/effect_b", func_800E2528);

EXTERN_C int func_800E2574(void *self)
{
    return FIELD_AT(self, unsigned char, 0x88) >> 7;
}

EXTERN_C int func_800E2580(void *self)
{
    return FIELD_AT(self, int, 0x20);
}

EXTERN_C int func_800E258C(void *self)
{
    return FIELD_AT(self, short, 0x10) == 2;
}

EXTERN_C int func_800E25A0(void *self)
{
    return FIELD_AT(self, short, 0x10) != 0;
}

EXTERN_C void func_800E25AC(void *self, int value)
{
    FIELD_AT(self, int, 0x54) = value;
}

EXTERN_C void func_800E25B4(void *self, int value)
{
    FIELD_AT(self, int, 0x28) = value;
}

EXTERN_C void func_800E25BC(void *self, void *other)
{
    FIELD_AT(self, short, 0x78) = FIELD_AT(other, short, 0x2);
}

EXTERN_C void func_800E25C8(void *self, char *src)
{
    FIELD_AT(self, short, 0x80) = FIELD_AT(src, short, 0x2);
    FIELD_AT(self, short, 0x82) = FIELD_AT(src, short, 0x4);
    FIELD_AT(self, short, 0x84) = FIELD_AT(src, short, 0x6);
}

EXTERN_C void func_800E25EC(void *self, char *src)
{
    FIELD_AT(self, char, 0x86) = FIELD_AT(src, char, 0x4);
    FIELD_AT(self, char, 0x87) = FIELD_AT(src, char, 0x5);
    FIELD_AT(self, char, 0x88) = FIELD_AT(src, char, 0x6);
}

EXTERN_C void func_800E2610(void *self, char *src)
{
    FIELD_AT(self, short, 0x7A) = FIELD_AT(src, short, 0x4);
    FIELD_AT(self, short, 0x7C) = FIELD_AT(src, short, 0x6);
    FIELD_AT(self, short, 0x7E) = FIELD_AT(src, short, 0x8);
}

EXTERN_C void func_800E2634(void *self, short value)
{
    FIELD_AT(self, int, 0x70) = value;
}

EXTERN_C void func_800E2644(void *self, void *other)
{
    FIELD_AT(self, short, 0x76) = FIELD_AT(other, short, 0x4);
}

EXTERN_C void func_800E2650(void *self, short a, short b)
{
    FIELD_AT(self, int, 0x6C) = a;
    FIELD_AT(self, short, 0x74) = b;
}

EXTERN_C void func_800E2664(void *self, int value)
{
    FIELD_AT(self, int, 0x50) = value;
}

EXTERN_C void func_800E266C(void *self, Vec4 *v)
{
    int w = FIELD_AT(self, int, 0x48);
    int *pw = &w;
    FIELD_AT(self, Vec4, 0x3C) = *v;
    FIELD_AT(self, int, 0x48) = *pw;
}

EXTERN_C void func_800E26A4(void *self, int value)
{
    FIELD_AT(self, int, 0x30) = value;
}

EXTERN_C void func_800E26AC(void *self, int value)
{
    FIELD_AT(self, int, 0x2C) = value;
}

EXTERN_C void func_800E26B4(void *self, int value)
{
    FIELD_AT(self, int, 0x38) = value;
}

EXTERN_C void func_800E26BC(void *self, int value)
{
    FIELD_AT(self, int, 0x34) = value;
}

EXTERN_C char *func_800E26C4(void *self, char *src)
{
    return func_800E4110((char *)self + 0x5C, src);
}

EXTERN_C char *func_800E26E4(void *self, char *src)
{
    return func_800E40E4((char *)self + 0x5C, src);
}

EXTERN_C void *func_800E2944(void *self);

struct Pair_800E2704 {
    int v;
    int next;
    Pair_800E2704(int a) : v(a), next(0) {}
};

struct C_800E2704 : IdNode {
    int fC;
    Pair_800E2704 *p10;
    Pair_800E2704 *p14;
    RandVal rv;
    Vec4 v28, v38, v48;
    int f58;
    int f5C;
    int f60;
    int f64;
    short f68;
    short f6A;
    short f6C;
    char f6E;
};

inline void rv_init_800E2704(RandVal *r)
{
    r->vptr = D_800D6038;
    r->base = 0;
    r->step = 0;
    r->range = 0;
    r->phase = 0;
}

EXTERN_C void *func_800E2704(void *p, short id)
{
    C_800E2704 *self = (C_800E2704 *)p;
    idnode_init(self, id);
    self->vptr = D_800D6674;
    rv_init_800E2704(&self->rv);
    vec4_zero(&self->v28);
    vec4_zero(&self->v38);
    vec4_zero(&self->v48);
    self->p10 = new Pair_800E2704(D_1F800000.a);
    self->p14 = new Pair_800E2704(D_1F800000.b);
    {
        int *vp = self->rv.vptr;
        int **pvp = &vp;
        self->rv = *D_1F800000.rv;
        self->rv.vptr = *pvp;
    }
    self->v28 = D_1F800000.v14;
    self->v38 = D_1F800000.v24;
    self->v48 = D_1F800000.v34;
    self->f6A = D_1F800000.s48;
    self->f5C = D_1F800000.s4A;
    self->f68 = D_1F800000.s4C;
    self->f6E = D_1F800000.b52;
    self->f60 = D_1F800000.s4E;
    self->f64 = D_1F800000.s50;
    self->f6C = 0;
    self->f58 = 0;
    func_800E2944(self);
    return self;
}

EXTERN_C void func_800E28D8(IdNode *self, int flags)
{
    self->vptr = D_800D6674;
    if (FIELD_AT(self, void *, 0x10))
        operator delete(FIELD_AT(self, void *, 0x10));
    if (FIELD_AT(self, void *, 0x14))
        operator delete(FIELD_AT(self, void *, 0x14));
    func_800D67CC(self, flags);
}

/* NOTE for landing: the unit declares func_800E2944 as void; it returns self->fC (void *): change the declaration.
   Params_800E2704 here splits pad44 into bytes b44..b47 (update the unit's struct). */

struct Iter_800E2944 {
    IdArray *arr;
    int idx;
};

inline bool past_end_800E2944(IdArray *a, int i)
{
    return i >= a->count;
}

inline Color *col_at_800E2944(IdArray *a, int i)
{
    if (i >= a->count)
        return &((Color *)a->data)[a->def];
    return &((Color *)a->data)[i];
}

inline SVec4 *svec_at_800E2944(IdArray *a, int i)
{
    if (i >= a->count)
        return &((SVec4 *)a->data)[a->def];
    return &((SVec4 *)a->data)[i];
}

inline Color nextc_800E2944(Iter_800E2944 *it, int step)
{
    Color c;
    if (past_end_800E2944(it->arr, it->idx))
        it->idx = it->arr->def;
    c = *col_at_800E2944(it->arr, it->idx);
    it->idx += step;
    return c;
}

inline SVec4 nextv_800E2944(Iter_800E2944 *it, int step)
{
    SVec4 c;
    if (past_end_800E2944(it->arr, it->idx))
        it->idx = it->arr->def;
    c = *svec_at_800E2944(it->arr, it->idx);
    it->idx += step;
    return c;
}

EXTERN_C void func_800D7A4C(RandVal *self, short *base, short *phase);
EXTERN_C int rand(void);

struct UV_800E2944 {
    unsigned char u, v;
    UV_800E2944() {}
};

struct Desc_800E2944 {
    unsigned char b0, b1;
    char pad2[2];
    short s4, s6, s8;
    char pad[0x26];
    UV_800E2944 uv[4];
    Color col;
};

inline short rv_get_800E2944(RandVal *r)
{
    if (r->spread == 0)
        return r->base;
    return r->base + rand() / (0x8000 / r->spread) - (r->spread >> 1);
}

inline void sv_from_800E2944(SVec4 *d, Vec4 *s)
{
    short x = s->x, y = s->y, z = s->z, w = s->w;
    d->x = x;
    d->y = y;
    d->z = z;
    d->w = w;
}

EXTERN_C void *func_800E2944(void *self)
{
    Desc_800E2944 d;
    Color col = nextc_800E2944(FIELD_AT(self, Iter_800E2944 *, 0x10), 0);
    short base;
    void *o;
    VtEntry *vt;
    FIELD_AT(self, void *, 0xC) = func_800D6C94((C_800D6C94 *)operator new(0xA8));
    d.b0 = 0;
    d.b1 = 0;
    d.s4 = 0;
    d.s6 = 0;
    d.s8 = -1;
    d.col = col;
    d.uv[0].u = D_1F800000.b44 - 1;
    d.uv[0].v = D_1F800000.b46 - 1;
    d.uv[1].u = D_1F800000.b44 - 1;
    d.uv[1].v = 0;
    d.uv[2].u = 0;
    d.uv[2].v = D_1F800000.b46 - 1;
    d.uv[3].u = 0;
    d.uv[3].v = 0;
    o = FIELD_AT(self, void *, 0xC);
    vt = FIELD_AT(o, VtEntry *, 0x0);
    int zero = 0;
    ((void (*)(void *, Desc_800E2944 *, int *))vt[10].pfn)((char *)o + vt[10].delta, &d, &zero);
    sv_from_800E2944(&FIELD_AT(FIELD_AT(self, void *, 0xC), SVec4, 0xA0), &FIELD_AT(self, Vec4, 0x28));
    FIELD_AT(FIELD_AT(self, void *, 0xC), short, 0x98) = nextv_800E2944(FIELD_AT(self, Iter_800E2944 *, 0x14), 0).z;
    FIELD_AT(FIELD_AT(self, void *, 0xC), short, 0x9E) = rv_get_800E2944(&FIELD_AT(self, RandVal, 0x18));
    func_800D7A4C(&FIELD_AT(self, RandVal, 0x18), &base, &FIELD_AT(FIELD_AT(self, void *, 0xC), short, 0x9C));
    FIELD_AT(FIELD_AT(self, void *, 0xC), short, 0x9A) = nextv_800E2944(FIELD_AT(self, Iter_800E2944 *, 0x14), 0).w;
    return FIELD_AT(self, void *, 0xC);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect_b", func_800E2D20);

struct Iter_800E2F2C {
    IdArray *arr;
    int idx;
};

inline bool past_end_800E2F2C(IdArray *a, int i)
{
    return i >= a->count;
}

inline Color *col_at_800E2F2C(IdArray *a, int i)
{
    if (i >= a->count)
        return &((Color *)a->data)[a->def];
    return &((Color *)a->data)[i];
}

inline SVec4 *svec_at_800E2F2C(IdArray *a, int i)
{
    if (i >= a->count)
        return &((SVec4 *)a->data)[a->def];
    return &((SVec4 *)a->data)[i];
}

inline Color nextc_800E2F2C(Iter_800E2F2C *it, int step)
{
    Color c;
    if (past_end_800E2F2C(it->arr, it->idx))
        it->idx = it->arr->def;
    c = *col_at_800E2F2C(it->arr, it->idx);
    it->idx += step;
    return c;
}

inline SVec4 nextv_800E2F2C(Iter_800E2F2C *it, int step)
{
    SVec4 c;
    if (past_end_800E2F2C(it->arr, it->idx))
        it->idx = it->arr->def;
    c = *svec_at_800E2F2C(it->arr, it->idx);
    it->idx += step;
    return c;
}

EXTERN_C void func_800D7A4C(RandVal *self, short *base, short *phase);

EXTERN_C void func_800E2F2C(void *self)
{
    short base;
    FIELD_AT(FIELD_AT(self, void *, 0xC), Color, 0x34) = nextc_800E2F2C(FIELD_AT(self, Iter_800E2F2C *, 0x10), 1);
    FIELD_AT(FIELD_AT(self, void *, 0xC), short, 0x98) = nextv_800E2F2C(FIELD_AT(self, Iter_800E2F2C *, 0x14), 1).z;
    func_800D7A4C(&FIELD_AT(self, RandVal, 0x18), &base, &FIELD_AT(FIELD_AT(self, void *, 0xC), short, 0x9C));
    FIELD_AT(FIELD_AT(self, void *, 0xC), short, 0x9A) = nextv_800E2F2C(FIELD_AT(self, Iter_800E2F2C *, 0x14), 0).w;
    if (FIELD_AT(self, void *, 0x4))
        func_800E2F2C(FIELD_AT(self, void *, 0x4));
}

#define gte_ldIR123(r0, r1, r2) __asm__ volatile( \
    "mtc2 %0, $9\n\t" \
    "mtc2 %1, $10\n\t" \
    "mtc2 %2, $11" \
    : : "r"(r0), "r"(r1), "r"(r2))
#define gte_sqr0() __asm__ volatile("nop\n\tnop\n\t.word 0x4AA00428")
#define gte_stmac1(r0) __asm__ volatile("swc2 $25, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac2(r0) __asm__ volatile("swc2 $26, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac3(r0) __asm__ volatile("swc2 $27, 0(%0)" : : "r"(r0) : "memory")

EXTERN_C Vec4 func_800E3DC4(Vec4 *a, Vec4 *b);

EXTERN_C int func_800E31B0(void *self, void *owner)
{
    int dx, dy, dz, r;
    Vec4 d;
    Vec4 e;
    int sq[6];
    dx = FIELD_AT(self, Vec4, 0x38).x - FIELD_AT(self, Vec4, 0x28).x;
    dy = FIELD_AT(self, Vec4, 0x38).y - FIELD_AT(self, Vec4, 0x28).y;
    dz = FIELD_AT(self, Vec4, 0x38).z - FIELD_AT(self, Vec4, 0x28).z;
    gte_ldIR123(dx, dy, dz);
    gte_sqr0();
    gte_stmac1(&sq[0]);
    gte_stmac2(&sq[1]);
    gte_stmac3(&sq[2]);
    if (FIELD_AT(owner, unsigned char, 0x88) >> 7) {
        ((void (*)(Vec4 *, Vec4 *, Vec4 *))func_800E3DC4)(&e, &FIELD_AT(self, Vec4, 0x48), &FIELD_AT(self, Vec4, 0x28));
        d = e;
        gte_ldIR123(d.x, d.y, d.z);
        gte_sqr0();
        gte_stmac1(&sq[3]);
        gte_stmac2(&sq[4]);
        gte_stmac3(&sq[5]);
        if (sq[3] + sq[4] + sq[5] < sq[0] + sq[1] + sq[2])
            return 2;
    }
    if (dx == 0 && dy == 0 && dz == 0) {
        if (FIELD_AT(self, Vec4, 0x48).x == FIELD_AT(self, Vec4, 0x38).x &&
            FIELD_AT(self, Vec4, 0x48).y == FIELD_AT(self, Vec4, 0x38).y &&
            FIELD_AT(self, Vec4, 0x48).z == FIELD_AT(self, Vec4, 0x38).z)
            return 2;
        return 0;
    }
    {
        int ex = FIELD_AT(self, Vec4, 0x48).x - FIELD_AT(self, Vec4, 0x28).x;
        int ey = FIELD_AT(self, Vec4, 0x48).y - FIELD_AT(self, Vec4, 0x28).y;
        int ez = FIELD_AT(self, Vec4, 0x48).z - FIELD_AT(self, Vec4, 0x28).z;
        int xx = ex * dx;
        int dot = ey * dy + xx + ez * dz;
        int len = sq[0] + sq[1] + sq[2];
        r = (dot << 8) / (len << 4);
    }
    if ((unsigned)r <= 0x10) {
        int px, py, pz;
        r >>= 4;
        px = dx * r + FIELD_AT(self, Vec4, 0x28).x;
        py = dy * r + FIELD_AT(self, Vec4, 0x28).y;
        pz = dz * r + FIELD_AT(self, Vec4, 0x28).z;
        if (px == FIELD_AT(self, Vec4, 0x48).x &&
            py == FIELD_AT(self, Vec4, 0x48).y &&
            pz == FIELD_AT(self, Vec4, 0x48).z)
            return 2;
    }
    return 0;
}

EXTERN_C int D_800D63B8[];
EXTERN_C char D_80010338[];
EXTERN_C char D_800A4544[];
EXTERN_C void func_8001D150(void *, void *);

struct S_800E343C {
    void *vptr;
    int next;
    void *owner;
    short prio;
    int on;
};

inline void *init_800E343C(void *self, int a, int b)
{
    char *l;
    S_800E343C *o;
    FIELD_AT(self, int *, 0x0) = D_800D63B8;
    FIELD_AT(self, int, 0x4) = b;
    FIELD_AT(self, int, 0x8) = a;
    l = D_800A4544;
    o = (S_800E343C *)operator new(0x14);
    o->vptr = D_80010178;
    o->next = 0;
    o->vptr = D_80010338;
    o->owner = self;
    o->prio = 0x80;
    o->on = 1;
    func_8001D150(l, o);
    return self;
}

EXTERN_C void func_800E343C(void *self, Poly *p)
{
    ((void (*)(void *, int))p->vptr[6].pfn)((char *)p + p->vptr[6].delta, FIELD_AT(self, int, 0xC));
    init_800E343C(operator new(0xC), FIELD_AT(self, int, 0xC), 1);
    int n = D_800E5840[0];
    FIELD_AT(self, int, 0xC) = 0;
    D_800E5840[0] = n + 1;
}

EXTERN_C void *func_800E2704(void *self, short id);

EXTERN_C void *func_800E3518(void *self)
{
    func_800E2704(self, 0);
    FIELD_AT(self, int *, 0x0) = D_800D6644;
    return self;
}

EXTERN_C void func_800E3550(IdNode *self, int flags)
{
    self->vptr = D_800D6644;
    func_800E28D8(self, flags);
}

#define gte_ldIR123(r0, r1, r2) __asm__ volatile( \
    "mtc2 %0, $9\n\t" \
    "mtc2 %1, $10\n\t" \
    "mtc2 %2, $11" \
    : : "r"(r0), "r"(r1), "r"(r2))
#define gte_sqr0() __asm__ volatile("nop\n\tnop\n\t.word 0x4AA00428")
#define gte_stmac1(r0) __asm__ volatile("swc2 $25, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac2(r0) __asm__ volatile("swc2 $26, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac3(r0) __asm__ volatile("swc2 $27, 0(%0)" : : "r"(r0) : "memory")

EXTERN_C int SquareRoot0(int a);
EXTERN_C Vec4 func_800E3DC4(Vec4 *a, Vec4 *b);

EXTERN_C Vec4 func_800E3578(void *self)
{
    Vec4 d;
    int len;
    const Vec4 &t = func_800E3DC4(&FIELD_AT(self, Vec4, 0x38), &FIELD_AT(self, Vec4, 0x28));
    d = t;
    int sq[3];
    gte_ldIR123(d.x, d.y, d.z);
    gte_sqr0();
    d.x <<= 2;
    d.y <<= 2;
    d.z <<= 2;
    gte_stmac1(&sq[0]);
    gte_stmac2(&sq[1]);
    gte_stmac3(&sq[2]);
    len = SquareRoot0(sq[0] + sq[1] + sq[2]);
    if (!len)
        len = 1;
    len <<= 2;
    d.x = d.x * FIELD_AT(self, int, 0x60) / len >> 2;
    d.y = d.y * FIELD_AT(self, int, 0x60) / len >> 2;
    d.z = d.z * FIELD_AT(self, int, 0x60) / len >> 2;
    return d;
}

EXTERN_C Vec4 func_800E3770(void *self)
{
    int p = FIELD_AT(self, int, 0x5C);
    if (p == 0)
        return Vec4(0, 0, 0, 0);
    if (FIELD_AT(self, short, 0x6C) < FIELD_AT(self, short, 0x68))
        return Vec4(0, 0, 0, 0);
    return Vec4(0, p, 0, 0);
}

EXTERN_C Vec4 func_800E37C8(void *self)
{
    return FIELD_AT(self, Vec4, 0x38);
}

EXTERN_C void *func_800E37F4(void *self)
{
    func_800E2704(self, 0);
    FIELD_AT(self, int *, 0x0) = D_800D6614;
    return self;
}

EXTERN_C void func_800E382C(IdNode *self, int flags)
{
    self->vptr = D_800D6614;
    func_800E28D8(self, flags);
}

#define gte_ldIR123(r0, r1, r2) __asm__ volatile( \
    "mtc2 %0, $9\n\t" \
    "mtc2 %1, $10\n\t" \
    "mtc2 %2, $11" \
    : : "r"(r0), "r"(r1), "r"(r2))
#define gte_sqr0() __asm__ volatile("nop\n\tnop\n\t.word 0x4AA00428")
#define gte_stmac1(r0) __asm__ volatile("swc2 $25, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac2(r0) __asm__ volatile("swc2 $26, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac3(r0) __asm__ volatile("swc2 $27, 0(%0)" : : "r"(r0) : "memory")

EXTERN_C int SquareRoot0(int a);
EXTERN_C Vec4 func_800E3DC4(Vec4 *a, Vec4 *b);

EXTERN_C Vec4 func_800E3854(void *self)
{
    Vec4 d;
    int len;
    const Vec4 &t = func_800E3DC4(&FIELD_AT(self, Vec4, 0x48), &FIELD_AT(self, Vec4, 0x28));
    d = t;
    int sq[3];
    gte_ldIR123(d.x, d.y, d.z);
    gte_sqr0();
    d.x <<= 2;
    d.y <<= 2;
    d.z <<= 2;
    gte_stmac1(&sq[0]);
    gte_stmac2(&sq[1]);
    gte_stmac3(&sq[2]);
    len = SquareRoot0(sq[0] + sq[1] + sq[2]);
    if (!len)
        len = 1;
    len <<= 2;
    d.x = d.x * FIELD_AT(self, int, 0x60) / len >> 2;
    d.y = d.y * FIELD_AT(self, int, 0x60) / len >> 2;
    d.z = d.z * FIELD_AT(self, int, 0x60) / len >> 2;
    return d;
}

EXTERN_C Vec4 func_800E3A4C(void *self)
{
    int p = FIELD_AT(self, int, 0x5C);
    if (p == 0)
        return Vec4(0, 0, 0, 0);
    if (FIELD_AT(self, short, 0x6C) < FIELD_AT(self, short, 0x68))
        return Vec4(0, 0, 0, 0);
    return Vec4(0, p, 0, 0);
}

#define gte_ldIR123(r0, r1, r2) __asm__ volatile( \
    "mtc2 %0, $9\n\t" \
    "mtc2 %1, $10\n\t" \
    "mtc2 %2, $11" \
    : : "r"(r0), "r"(r1), "r"(r2))
#define gte_sqr0() __asm__ volatile("nop\n\tnop\n\t.word 0x4AA00428")
#define gte_stmac1(r0) __asm__ volatile("swc2 $25, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac2(r0) __asm__ volatile("swc2 $26, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac3(r0) __asm__ volatile("swc2 $27, 0(%0)" : : "r"(r0) : "memory")

EXTERN_C int SquareRoot0(int a);

EXTERN_C Vec4 func_800E3AA4(void *self, Vec4 *v)
{
    if (FIELD_AT(self, int, 0x58) || FIELD_AT(self, int, 0x5C))
        return FIELD_AT(self, Vec4, 0x38);
    {
        Vec4 d;
        Vec4 n;
        int sq[6];
        int len1, len2;
        d.x = FIELD_AT(self, Vec4, 0x38).x - FIELD_AT(self, Vec4, 0x28).x;
        d.y = FIELD_AT(self, Vec4, 0x38).y - FIELD_AT(self, Vec4, 0x28).y;
        d.z = FIELD_AT(self, Vec4, 0x38).z - FIELD_AT(self, Vec4, 0x28).z;
        gte_ldIR123(d.x, d.y, d.z);
        gte_sqr0();
        gte_stmac1(&sq[0]);
        gte_stmac2(&sq[1]);
        gte_stmac3(&sq[2]);
        gte_ldIR123(v->x, v->y, v->z);
        gte_sqr0();
        len1 = SquareRoot0(sq[0] + sq[1] + sq[2]);
        if (!len1)
            len1 = 1;
        gte_stmac1(&sq[3]);
        gte_stmac2(&sq[4]);
        gte_stmac3(&sq[5]);
        len2 = SquareRoot0(sq[3] + sq[4] + sq[5]);
        if (!len2)
            len2 = 1;
        if (((d.x * v->x + d.y * v->y + d.z * v->z) << 4) / ((len1 * len2) << 2) >= 4) {
            n.x = v->x * len1 / len2;
            n.y = v->y * len1 / len2;
            n.z = v->z * len1 / len2;
            FIELD_AT(self, Vec4, 0x38).x = FIELD_AT(self, Vec4, 0x28).x + n.x;
            FIELD_AT(self, Vec4, 0x38).y = FIELD_AT(self, Vec4, 0x28).y + n.y;
            FIELD_AT(self, Vec4, 0x38).z = FIELD_AT(self, Vec4, 0x28).z + n.z;
            FIELD_AT(self, int, 0x60) = 1;
        }
    }
    return FIELD_AT(self, Vec4, 0x38);
}

EXTERN_C Vec4 func_800E3DC4(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x - b->x, a->y - b->y, a->z - b->z, a->w);
}

EXTERN_C Vec4 func_800E3E04(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
}

EXTERN_C Vec4 func_800E3E44(void *self)
{
    return FIELD_AT(self, Vec4, 0x38);
}

EXTERN_C Vec4 func_800E3E70(void *self)
{
    return FIELD_AT(self, Vec4, 0x28);
}

EXTERN_C int func_800E3E9C(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800E3EA8(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C void *func_800E3EB4(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, short, 0x10) = 0;
    FIELD_AT(self, short, 0x12) = 0;
    return self;
}

inline void del_800E3ED4(Poly *o)
{
    if (o)
        o->vptr[1].pfn((char *)o + o->vptr[1].delta, 3);
}

EXTERN_C void func_800E3ED4(void *self, int flags)
{
    int t = FIELD_AT(self, int, 0xC);
    if (t == 0)
        del_800E3ED4(FIELD_AT(self, Poly *, 0x0));
    else if (t != 0x8000)
        goto done;
    del_800E3ED4(FIELD_AT(self, Poly *, 0x4));
    del_800E3ED4(FIELD_AT(self, Poly *, 0x8));
done:
    if (flags & 1)
        operator delete(self);
}

EXTERN_C void func_800E3FB8(void *self, void *other)
{
    FIELD_AT(self, int, 0x0) = FIELD_AT(other, int, 0x0);
    FIELD_AT(self, int, 0x4) = FIELD_AT(other, int, 0x4);
    FIELD_AT(self, int, 0x8) = FIELD_AT(other, int, 0x8);
    FIELD_AT(self, short, 0x10) = FIELD_AT(other, short, 0x10);
    FIELD_AT(self, short, 0x12) = FIELD_AT(other, short, 0x12);
    FIELD_AT(self, short, 0x14) = FIELD_AT(other, short, 0x14);
    FIELD_AT(self, short, 0x16) = FIELD_AT(other, short, 0x16);
    FIELD_AT(self, int, 0xC) = 0;
}

EXTERN_C void *func_800E4010(void *self)
{
    FIELD_AT(self, int, 0xC)++;
    return self;
}

EXTERN_C IdNode *func_800E4028(void *self, short id)
{
    return func_800D67F4(FIELD_AT(self, IdNode *, 0x4), id);
}

EXTERN_C void func_800E4050(void *self, int value)
{
    FIELD_AT(self, int, 0x0) = value;
}

EXTERN_C void *func_800E4058(void *self, void *other)
{
    FIELD_AT(self, char, 0x0) = 0;
    FIELD_AT(self, char, 0x1) = 0;
    FIELD_AT(self, char, 0x2) = 0;
    FIELD_AT(self, short, 0x4) = 0;
    FIELD_AT(self, short, 0x6) = 0;
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    if (other) {
        FIELD_AT(self, char, 0x0) = FIELD_AT(other, char, 0x0);
        FIELD_AT(self, char, 0x1) = FIELD_AT(other, char, 0x1);
        FIELD_AT(self, short, 0x4) = FIELD_AT(other, short, 0x4);
        FIELD_AT(self, char, 0x2) = FIELD_AT(other, char, 0x2);
        FIELD_AT(self, short, 0x6) = FIELD_AT(other, short, 0x6);
    }
    return self;
}

EXTERN_C void func_800E40BC(void *self, int flags)
{
    if (flags & 1)
        operator delete(self);
}

EXTERN_C char *func_800E40E4(void *self, char *src)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(src, char, 0x2);
    FIELD_AT(self, char, 0x1) = FIELD_AT(src, char, 0x6);
    FIELD_AT(self, short, 0x4) = FIELD_AT(src, short, 0x4);
    return src + 8;
}

EXTERN_C char *func_800E4110(void *self, char *src)
{
    FIELD_AT(self, char, 0x2) = FIELD_AT(src, char, 0x6);
    FIELD_AT(self, short, 0x6) = FIELD_AT(src, short, 0x4);
    return src + 8;
}

EXTERN_C int func_800E4130(void *self, short value)
{
    if (FIELD_AT(self, signed char, 0x0) == 0)
        return 0;
    if (FIELD_AT(self, int, 0x8) == 1)
        return 0;
    if (value >= FIELD_AT(self, short, 0x4)) {
        FIELD_AT(self, int, 0x8) = 1;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800E4174(void *self, short value)
{
    if (FIELD_AT(self, signed char, 0x2) == 0)
        return 0;
    if (FIELD_AT(self, int, 0xC) == 1)
        return 0;
    if (value >= FIELD_AT(self, short, 0x6)) {
        FIELD_AT(self, int, 0xC) = 1;
        return 1;
    }
    return 0;
}

EXTERN_C void *func_800E41B8(void *self, void *other)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(other, char, 0x0);
    FIELD_AT(self, char, 0x1) = FIELD_AT(other, char, 0x1);
    FIELD_AT(self, short, 0x4) = FIELD_AT(other, short, 0x4);
    FIELD_AT(self, char, 0x2) = FIELD_AT(other, char, 0x2);
    FIELD_AT(self, short, 0x6) = FIELD_AT(other, short, 0x6);
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    return self;
}

EXTERN_C void func_8008EF64(int arg, int a, int b);

EXTERN_C void func_800E41FC(void *self)
{
    void **p = (void **)D_800E5848[0];
    if (p && *p)
        func_8008EF64((FIELD_AT(*p, unsigned short, 0x14) << 16) + FIELD_AT(self, signed char, 0x1), 0x60, 0x40);
}

EXTERN_C void func_8008FAB4(int arg);

EXTERN_C void func_800E424C(void *self)
{
    void **p = (void **)D_800E5848[0];
    if (p && *p)
        func_8008FAB4((FIELD_AT(*p, unsigned short, 0x14) << 16) + FIELD_AT(self, signed char, 0x2));
}

EXTERN_C void *func_800E4298(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    D_800E5848[0] = self;
    return self;
}

EXTERN_C void func_800E43A0(void *self);

EXTERN_C void func_800E42B0(void *self, int flags)
{
    func_800E43A0(self);
    if (flags & 1)
        operator delete(self);
}

EXTERN_C void func_8008ECB4(void *p);

EXTERN_C char *func_800E42F4(void *self, char *data)
{
    FIELD_AT(self, void *, 0x0) = __builtin_vec_new(FIELD_AT(data, int, 0x8));
    func_80025CE0(FIELD_AT(self, void *, 0x0), data, FIELD_AT(data, int, 0x8));
    func_8008ECB4(FIELD_AT(self, void *, 0x0));
    return data + FIELD_AT(data, int, 0x8);
}

EXTERN_C void *func_8008D1F4(void *data, int arg);
EXTERN_C void func_8008C928(int arg);

EXTERN_C char *func_800E4354(void *self, char *data)
{
    FIELD_AT(self, void *, 0x4) = func_8008D1F4(data, 0);
    func_8008C928(0x10);
    return data + FIELD_AT(data, int, 0x8);
}

EXTERN_C void func_8008ED44(void *p);
EXTERN_C void func_8008D4C0(void *p);

EXTERN_C void func_800E43A0(void *self)
{
    if (FIELD_AT(self, void *, 0x0)) {
        func_8008ED44(FIELD_AT(self, void *, 0x0));
        if (FIELD_AT(self, void *, 0x0))
            __builtin_vec_delete(FIELD_AT(self, void *, 0x0));
        FIELD_AT(self, void *, 0x0) = 0;
    }
    if (FIELD_AT(self, void *, 0x4)) {
        func_8008D4C0(FIELD_AT(self, void *, 0x4));
        FIELD_AT(self, void *, 0x4) = 0;
    }
}

EXTERN_C int func_800E4410(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800E441C(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

EXTERN_C int func_800E4428(void *self)
{
    return FIELD_AT(self, signed char, 0x1);
}

EXTERN_C void *func_800E4434(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, short, 0x14) = -1;
    return self;
}

struct C_800E4458 : IdNode {
    Vec4 a, b, c;
    int f3C;
    char f40, f41, f42;
    short f44;
};

EXTERN_C void *func_800E4458(void *p, short id)
{
    C_800E4458 *self = (C_800E4458 *)p;
    idnode_init(self, id);
    self->vptr = D_800D67A4;
    vec4_zero(&self->a);
    vec4_zero(&self->b);
    vec4_zero(&self->c);
    self->f3C = 0;
    self->f40 = 0;
    self->f41 = 0;
    self->f42 = 0;
    self->f44 = 0x44C;
    return self;
}

EXTERN_C void func_800E44E0(IdNode *self, int flags)
{
    self->vptr = D_800D67A4;
    func_800D67CC(self, flags);
}

EXTERN_C char *func_800E4508(void *self, char *src)
{
    Vec4 *v;
    FIELD_AT(self, unsigned char, 0x40) = src[2];
    FIELD_AT(self, unsigned char, 0x41) = FIELD_AT(src, unsigned short, 0x2) >> 8;
    FIELD_AT(self, Vec4, 0xC) = FIELD_AT(src, Vec4, 0x4);
    v = &FIELD_AT(src, Vec4, 0x14);
    FIELD_AT(self, Vec4, 0x1C) = Vec4(*v);
    FIELD_AT(self, Vec4, 0x2C) = Vec4(0, 0, 0, 0);
    FIELD_AT(self, unsigned char, 0x42) = src[0x10];
    return src + 0x24;
}

EXTERN_C void func_800E45CC(void *self, void *other)
{
    FIELD_AT(self, short, 0x8) = FIELD_AT(other, short, 0x8);
    FIELD_AT(self, char, 0x40) = FIELD_AT(other, char, 0x40);
    FIELD_AT(self, char, 0x41) = FIELD_AT(other, char, 0x41);
    FIELD_AT(self, Vec4, 0xC) = FIELD_AT(other, Vec4, 0xC);
    FIELD_AT(self, Vec4, 0x1C) = FIELD_AT(other, Vec4, 0x1C);
    FIELD_AT(self, Vec4, 0x2C) = Vec4(0, 0, 0, 0);
    FIELD_AT(self, char, 0x42) = FIELD_AT(other, char, 0x42);
}

EXTERN_C Vec4 func_800E5798(Vec4 *a, Vec4 *b);

inline void add3_800E4674(Vec4 *a, const Vec4 &b)
{
    int x = a->x + b.x;
    int y = a->y + b.y;
    int z = a->z + b.z;
    a->x = x;
    a->y = y;
    a->z = z;
}

EXTERN_C Vec4 func_800E4674(void *self, Vec4 *off)
{
    Vec4 base;
    Vec4 t;
    if (off)
        base = *off;
    else
        vec4_zero(&base);
    vec4_zero(&t);
    if (FIELD_AT(self, void *, 0x3C))
        t = func_8003A150(FIELD_AT(self, int, 0x3C), (int)&t);
    add3_800E4674(&base, func_800E5798(&func_800E5798(&t, &FIELD_AT(self, Vec4, 0x2C)), &FIELD_AT(self, Vec4, 0xC)));
    return base;
}

EXTERN_C int SquareRoot0(int a);
EXTERN_C Vec4 func_800E5758(Vec4 *a, Vec4 *b);

EXTERN_C Vec4 func_800E47AC(void *self, Vec4 *v)
{
    Vec4 cam;
    Vec4 d;
    int len;
    if (!FIELD_AT(self, int, 0x28))
        return *v;
    cam = FIELD_AT(D_800B4ED8[0], Vec4, 0x2C8);
    d = func_800E5758(&cam, v);
    len = SquareRoot0(d.x * d.x + d.y * d.y + d.z * d.z);
    d.x = d.x * FIELD_AT(self, short, 0x44) / len + v->x;
    d.y = d.y * FIELD_AT(self, short, 0x44) / len + v->y;
    d.z = d.z * FIELD_AT(self, short, 0x44) / len + v->z;
    return d;
}

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D6604);

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D6614);

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D6644);

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D6674);

EXTERN_C int func_8003912C(void *p, int n);

EXTERN_C void func_800E49D8(void *self, void *argp)
{
    void **arg = (void **)argp;
    void *who = 0;
    switch (FIELD_AT(self, signed char, 0x40)) {
    case 1:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 2);
        who = arg[1];
        break;
    case 2:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 5);
        who = arg[1];
        break;
    case 3:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 6);
        who = arg[1];
        break;
    case 4:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 2);
        who = arg[0];
        break;
    case 5:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 5);
        who = arg[0];
        break;
    case 6:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 6);
        who = arg[0];
        break;
    case 10:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), FIELD_AT(self, signed char, 0x42));
        who = arg[1];
        break;
    case 11:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), FIELD_AT(self, signed char, 0x42));
        who = arg[0];
        break;
    case 12:
        FIELD_AT(self, Vec4, 0x2C) = *(Vec4 *)arg[3];
        break;
    }
    if (who && FIELD_AT(who, signed char, 0x4BC) >= 3) {
        switch (FIELD_AT(who, unsigned char, 0x94A)) {
        case 0:
            FIELD_AT(self, short, 0x44) = 0x2BC;
            break;
        case 1:
            FIELD_AT(self, short, 0x44) = 0x44C;
            break;
        case 2:
            FIELD_AT(self, short, 0x44) = 0x7D0;
            break;
        }
    }
}

EXTERN_C int func_8003912C(void *p, int n);

EXTERN_C void func_800E4B88(void *self, void *argp)
{
    void **arg = (void **)argp;
    switch (FIELD_AT(self, signed char, 0x40)) {
    case 2:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 2);
        break;
    case 3:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 5);
        break;
    case 4:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 6);
        break;
    case 5:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 2);
        break;
    case 6:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 5);
        break;
    case 7:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 6);
        break;
    case 10:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), FIELD_AT(self, signed char, 0x42));
        break;
    case 11:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), FIELD_AT(self, signed char, 0x42));
        break;
    case 12:
        FIELD_AT(self, Vec4, 0x2C) = *(Vec4 *)arg[4];
        break;
    }
}

EXTERN_C void *func_800E4458(void *self, short id);

EXTERN_C void *func_800E4CAC(void *self, short id)
{
    func_800E4458(self, id);
    FIELD_AT(self, int *, 0x0) = D_800D677C;
    return self;
}

EXTERN_C void func_800E4CE8(IdNode *self, int flags)
{
    self->vptr = D_800D677C;
    func_800E44E0(self, flags);
}

#define gte_SetRotMatrix(r0) __asm__ volatile( \
    "lw $12, 0(%0)\n\t" \
    "lw $13, 4(%0)\n\t" \
    "ctc2 $12, $0\n\t" \
    "ctc2 $13, $1\n\t" \
    "lw $12, 8(%0)\n\t" \
    "lw $13, 12(%0)\n\t" \
    "lw $14, 16(%0)\n\t" \
    "ctc2 $12, $2\n\t" \
    "ctc2 $13, $3\n\t" \
    "ctc2 $14, $4" \
    : : "r"(r0) : "$12", "$13", "$14")
#define gte_ldv0(r0) __asm__ volatile( \
    "lwc2 $0, 0(%0)\n\t" \
    "lwc2 $1, 4(%0)" \
    : : "r"(r0))
#define gte_rtv0() __asm__ volatile("nop\n\tnop\n\t.word 0x4A486012")
#define gte_stlvnl(r0) __asm__ volatile( \
    "swc2 $25, 0(%0)\n\t" \
    "swc2 $26, 4(%0)\n\t" \
    "swc2 $27, 8(%0)" \
    : : "r"(r0) : "memory")

struct Mat_800E4D10 {
    int m[8];
};

EXTERN_C int rand(void);
EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C Vec4 func_800E4674(void *self, Vec4 *off);
EXTERN_C Vec4 func_800E47AC(void *self, Vec4 *v);

inline void add3p_800E4D10(Vec4 *a, const Vec4 *b)
{
    int x = a->x + b->x;
    int y = a->y + b->y;
    int z = a->z + b->z;
    a->x = x;
    a->y = y;
    a->z = z;
}

EXTERN_C Vec4 func_800E4D10(void *self, Vec4 *arg)
{
    Vec4 r;
    SVec4 rot;
    Mat_800E4D10 m;
    SVec4 sv;
    vec4_zero(&r);
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    rot.w = 0;
    func_8003A754(&m, 0x1000);
    if (FIELD_AT(self, int, 0x1C)) {
        sv.x = rand() / (0x8000 / FIELD_AT(self, int, 0x1C));
        sv.y = rand() / (0x8000 / FIELD_AT(self, int, 0x1C));
        sv.z = rand() / (0x8000 / FIELD_AT(self, int, 0x1C));
        rot.x = rand() / 8;
        rot.z = rand() / 8;
        rot.y = rand() / 8;
        func_8003A7FC(&m, &rot);
        gte_SetRotMatrix(&m);
        gte_ldv0(&sv);
        gte_rtv0();
        gte_stlvnl(&r);
    }
    {
        const Vec4 &p = func_800E4674(self, arg);
        add3p_800E4D10(&r, &p);
    }
    r = func_800E47AC(self, &r);
    return r;
}

EXTERN_C void *func_800E5030(void *self, short id)
{
    func_800E4458(self, id);
    FIELD_AT(self, int *, 0x0) = D_800D6754;
    return self;
}

EXTERN_C void func_800E506C(IdNode *self, int flags)
{
    self->vptr = D_800D6754;
    func_800E44E0(self, flags);
}

#define gte_SetRotMatrix(r0) __asm__ volatile( \
    "lw $12, 0(%0)\n\t" \
    "lw $13, 4(%0)\n\t" \
    "ctc2 $12, $0\n\t" \
    "ctc2 $13, $1\n\t" \
    "lw $12, 8(%0)\n\t" \
    "lw $13, 12(%0)\n\t" \
    "lw $14, 16(%0)\n\t" \
    "ctc2 $12, $2\n\t" \
    "ctc2 $13, $3\n\t" \
    "ctc2 $14, $4" \
    : : "r"(r0) : "$12", "$13", "$14")
#define gte_ldv0(r0) __asm__ volatile( \
    "lwc2 $0, 0(%0)\n\t" \
    "lwc2 $1, 4(%0)" \
    : : "r"(r0))
#define gte_rtv0() __asm__ volatile("nop\n\tnop\n\t.word 0x4A486012")
#define gte_stlvnl(r0) __asm__ volatile( \
    "swc2 $25, 0(%0)\n\t" \
    "swc2 $26, 4(%0)\n\t" \
    "swc2 $27, 8(%0)" \
    : : "r"(r0) : "memory")

EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C int rand(void);
EXTERN_C Vec4 func_800E4674(void *self, Vec4 *off);
EXTERN_C Vec4 func_800E47AC(void *self, Vec4 *v);

struct Mat_800E5094 {
    int m[8];
};

inline void add3_800E5094(Vec4 *a, const Vec4 *b)
{
    int x = a->x + b->x;
    int y = a->y + b->y;
    int z = a->z + b->z;
    a->x = x;
    a->y = y;
    a->z = z;
}

EXTERN_C Vec4 func_800E5094(void *self, Vec4 *off)
{
    Vec4 v;
    vec4_zero(&v);
    SVec4 rot;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    rot.w = 0;
    Mat_800E5094 m;
    func_8003A754(&m, 0x1000);
    SVec4 dir;
    dir.x = FIELD_AT(self, short, 0x1C);
    dir.z = 0;
    dir.y = 0;
    rot.x = rand() / 8;
    rot.z = rand() / 8;
    rot.y = rand() / 8;
    func_8003A7FC(&m, &rot);
    gte_SetRotMatrix(&m);
    gte_ldv0(&dir);
    gte_rtv0();
    gte_stlvnl(&v);
    {
        const Vec4 &p = func_800E4674(self, off);
        add3_800E5094(&v, &p);
    }
    v = func_800E47AC(self, &v);
    return v;
}

EXTERN_C void *func_800E4458(void *self, short id);

EXTERN_C void *func_800E5254(void *self, short id)
{
    func_800E4458(self, id);
    FIELD_AT(self, int *, 0x0) = D_800D672C;
    return self;
}

EXTERN_C void func_800E5290(IdNode *self, int flags)
{
    self->vptr = D_800D672C;
    func_800E44E0(self, flags);
}

EXTERN_C int rand(void);
EXTERN_C Vec4 func_800E4674(void *self, Vec4 *off);
EXTERN_C Vec4 func_800E47AC(void *self, Vec4 *v);

inline void add3_800E52B8(Vec4 *a, const Vec4 *b)
{
    int x = a->x + b->x;
    int y = a->y + b->y;
    int z = a->z + b->z;
    a->x = x;
    a->y = y;
    a->z = z;
}

EXTERN_C Vec4 func_800E52B8(void *self, Vec4 *off)
{
    Vec4 v;
    int signs, a, b, c, t;
    vec4_zero(&v);
    signs = rand();
    a = rand() >> 3;
    b = rand() >> 3;
    c = rand() >> 3;
    t = FIELD_AT(self, int, 0x1C) * a >> 12;
    if (!(signs & 1))
        t = -t;
    v.x = t;
    signs >>= 1;
    t = FIELD_AT(self, int, 0x20) * b >> 12;
    if (!(signs & 1))
        t = -t;
    v.y = t;
    signs >>= 1;
    t = FIELD_AT(self, int, 0x24) * c >> 12;
    if (!(signs & 1))
        t = -t;
    v.z = t;
    {
        const Vec4 &p = func_800E4674(self, off);
        add3_800E52B8(&v, &p);
    }
    v = func_800E47AC(self, &v);
    return v;
}

EXTERN_C void *func_800E4458(void *self, short id);

EXTERN_C void *func_800E5450(void *self, short id)
{
    func_800E4458(self, id);
    FIELD_AT(self, int *, 0x0) = D_800D6704;
    return self;
}

EXTERN_C void func_800E548C(IdNode *self, int flags)
{
    self->vptr = D_800D6704;
    func_800E44E0(self, flags);
}

EXTERN_C int rand(void);
EXTERN_C Vec4 func_800E4674(void *self, Vec4 *off);
EXTERN_C Vec4 func_800E47AC(void *self, Vec4 *v);

inline void add3p_800E54B4(Vec4 *a, const Vec4 *b)
{
    int x = a->x + b->x;
    int y = a->y + b->y;
    int z = a->z + b->z;
    a->x = x;
    a->y = y;
    a->z = z;
}

EXTERN_C Vec4 func_800E54B4(void *self, Vec4 *arg)
{
    Vec4 r;
    int v;
    int z, y, x;
    int sz, sy, sx;
    vec4_zero(&r);
    v = rand();
    z = 0;
    y = 0;
    x = 0;
    sz = 1;
    sy = 1;
    sx = 1;
    if (v < 0x2AAB) {
        sy = (v & 1) ? 1 : -1;
        v >>= 1;
        sz = (v & 1) ? 1 : -1;
        x = (rand() & 1) ? 0x1000 : -0x1000;
        y = rand() >> 3;
        z = rand() >> 3;
    } else if (v < 0x5555) {
        sx = (v & 1) ? 1 : -1;
        v >>= 1;
        sy = 1;
        sz = (v & 1) ? 1 : -1;
        x = rand() >> 3;
        y = (rand() & 1) ? 0x1000 : -0x1000;
        z = rand() >> 3;
    } else if (v <= 0x8000) {
        sx = (v & 1) ? 1 : -1;
        v >>= 1;
        sy = (v & 1) ? 1 : -1;
        x = rand() >> 3;
        y = rand() >> 3;
        z = (rand() & 1) ? 0x1000 : -0x1000;
    }
    r.x = (FIELD_AT(self, int, 0x1C) * x >> 12) * sx;
    r.y = (FIELD_AT(self, int, 0x20) * y >> 12) * sy;
    r.z = (FIELD_AT(self, int, 0x24) * z >> 12) * sz;
    {
        const Vec4 &p = func_800E4674(self, arg);
        add3p_800E54B4(&r, &p);
    }
    r = func_800E47AC(self, &r);
    return r;
}

EXTERN_C Vec4 func_800E5758(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x - b->x, a->y - b->y, a->z - b->z, a->w);
}

EXTERN_C Vec4 func_800E5798(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
}

EXTERN_C int func_800E57D8(void *self)
{
    return FIELD_AT(self, int, 0x3C);
}

EXTERN_C int func_800E57E4(void *self)
{
    return FIELD_AT(self, signed char, 0x40) != 0;
}

EXTERN_C int func_800E57F0(void *self)
{
    return FIELD_AT(self, signed char, 0x41);
}

EXTERN_C int func_800E57FC(void *self)
{
    return FIELD_AT(self, signed char, 0x40);
}

EXTERN_C void func_800E5808(void *self, Vec4 v)
{
    FIELD_AT(self, Vec4, 0x2C) = v;
}

/* Retail has a zero word after func_800E4B88's jump table, before the vtables from D_800D6704.
   Kept in order like INCLUDE_RODATA. */
void __maspsx_include_asm_hack_rodata_pad_800D6700()
{
    __asm__(
        ".section .rodata # maspsx-keep\n"
        "\t.word 0 # maspsx-keep\n"
        ".text # maspsx-keep\n"
    );
}

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D6704);

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D672C);

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D6754);

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D677C);

INCLUDE_RODATA("asm/effect/nonmatchings/effect_b", D_800D67A4);

