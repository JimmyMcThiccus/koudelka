// NEAR (6 differ): (1) entry: retail copies arg->$s1 in the beqz delay slot and sets p=src+0x18 earlier; (2) after new(0x28) retail sets a0/a2 before 'n=p; p=src+0x1C'. Fixed vs the older near copy: image-loop order (p updates after the vcall). func_800DE3BC needs (IdNode*, int, int, short, int) - the unit has (IdNode*, short, int, short).
#include "common.h"
#include "effect/effect.h"

/* Same layout as the unit's C_800E0384, extended to its full 0x8C bytes (fields seen
   in the copy constructor func_800E0468): merge into that class when landing. */
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
    int w28;
    int w2C, w30, w34, w38;
    RV_800E0384 rv;
    int w4C, w50, w54, w58;
    char m5C[0x10];
    int w6C, w70;
    short s74, s76, s78, s7A, s7C, s7E;
    short s80, s82, s84;
    unsigned char c86, c87, c88;
    C_800E0384(short aid);
};

/* end of C_800E0384 */

EXTERN_C char D_800106EC[];
EXTERN_C char D_80010624[];
EXTERN_C char D_80010888[];
EXTERN_C char D_800108A0[];
EXTERN_C char D_800B4C48[];
EXTERN_C Poly *D_800B4C38[];
EXTERN_C void func_80021F48(void *, void *);
EXTERN_C void func_80024CA0(void *self, void *buf, int w, int h);
EXTERN_C void func_80025444(void *a, void *b, int c);
EXTERN_C IdNode *func_800DE3BC(IdNode *self, int count, int unused, short c, int unused2);
EXTERN_C void func_800DE780(void *self, int i, Color c);
EXTERN_C void *func_800E0188(void *self, int n);
EXTERN_C void *func_800E1B24(void *self);
EXTERN_C void func_800E1AE4(void *self, Link *link);
EXTERN_C char *func_800DF974(void *self, char *p, IdNode *n);
EXTERN_C char *func_800DFEBC(void *self, char *p, IdNode *n);

struct Col_800DF4EC {
    unsigned char r, g, b, a;
    Col_800DF4EC() {}
};

struct Pal_800DF4EC {
    char *vptr;
    int next;
    short a, b;
};

struct Pair_800DF4EC {
    short a, b;
    Pair_800DF4EC(short aa, short ab) : a(aa), b(ab) {}
};

struct Wrap_800DF4EC {
    int pad;
    Pair_800DF4EC p;
    int pad2;
    Wrap_800DF4EC() : p(-1, -1) {}
};

struct Img_800DF4EC {
    char *vptr;
    int next;
    char *vptr8;
    Pal_800DF4EC *pal;
    Pair_800DF4EC xy;
    short w, h;
    int w18;
    short s1C, s1E;
};

struct Rec12_800DF4EC {
    short a, b, c, e, f, d;
};

struct Obj_800DF4EC {
    Link *imgs;
    Link *nodes;
    IdNode *pal;
    int pad;
    short count;
    short s12, s14, s16;
    Rec12_800DF4EC recs[8];
};

EXTERN_C char *func_800DF4EC(Obj_800DF4EC *self, char *src, int arg)
{
    char *p;
    int i;
    self->s12 = *(short *)(src + 0x12);
    self->s14 = (signed char)src[0xE];
    self->s16 = (signed char)src[0x6];
    p = src + 0x18;
    if (((signed char *)src)[0xF]) {
        short *n;
        IdNode *m = (IdNode *)operator new(0x28);
        n = (short *)p;
        p = src + 0x1C;
        self->pal = func_800DE3BC(m, *(short *)(src + 0x18) + 1, 0, *(short *)(src + 0x18) - 1, arg);
        for (i = 0; i <= *n; i++) {
            ((void (*)(void *, int, Col_800DF4EC))func_800DE780)(self->pal, i, *(Col_800DF4EC *)p);
            p += 4;
        }
    }
    i = 0;
    while (1) {
        Pal_800DF4EC *o;
        Img_800DF4EC *m;
        short *dim;
        if (!(i < *(short *)(src + 0x4)))
            break;
        p += 4;
        o = (Pal_800DF4EC *)operator new(0x20C);
        o->vptr = (char *)D_80010178;
        o->next = 0;
        o->vptr = D_800106EC;
        o->a = 0;
        o->b = 0;
        o->vptr = D_80010624;
        func_80021F48(o, p);
        {
            Poly *q = D_800B4C38[0];
            VtEntry *vt = FIELD_AT(q, VtEntry *, 0x10);
            vt[1].pfn((char *)q + vt[1].delta, (int)o);
        }
        p += 0x200;
        dim = (short *)p;
        p += 4;
        m = (Img_800DF4EC *)operator new(0x20);
        m->vptr = (char *)D_80010178;
        m->next = 0;
        m->vptr8 = D_80010888;
        m->vptr = D_800108A0;
        m->pal = o;
        m->xy = Wrap_800DF4EC().p;
        m->w = 0;
        m->h = 0;
        m->w18 = 0;
        m->s1E = 0;
        func_80024CA0(m, p, dim[0], dim[1]);
        func_80025444(D_800B4C48, m, 3);
        if (!self->imgs)
            self->imgs = (Link *)m;
        else
            func_8001A678(self->imgs, (Link *)m);
        p += (unsigned)(dim[0] * (dim[1] << 1)) >> 1;
        i++;
    }
    self->count = *(unsigned short *)(src + 0xC);
    i = 0;
    while (1) {
        C_800E0384 *e;
        if (!(i < self->count))
            break;
        e = new C_800E0384(i);
        self->recs[i] = *(Rec12_800DF4EC *)p;
        e->w28 = (int)func_800E0188(self, self->recs[i].d);
        p += 12;
        if (self->nodes)
            func_8001A678(self->nodes, (Link *)e);
        else
            self->nodes = (Link *)e;
        i++;
    }
    i = 0;
    while (1) {
        short *h;
        IdNode *n;
        int j;
        if (!(i < self->count))
            break;
        h = (short *)p;
        n = func_800D67F4((IdNode *)self->nodes, ((signed char *)p)[0]);
        p += 4;
        for (j = 0; j < h[1]; j++)
            p = func_800DF974(self, p, n);
        i++;
    }
    i = 0;
    while (1) {
        short *h;
        IdNode *n;
        int j;
        if (!(i < self->count))
            break;
        h = (short *)p;
        n = func_800D67F4((IdNode *)self->nodes, ((signed char *)p)[0]);
        p += 4;
        for (j = 0; j < h[1]; j++)
            p = func_800DFEBC(self, p, n);
        i++;
    }
    {
        Link *q = self->nodes;
        while (q) {
            void *t = func_800E1B24(q);
            if (t) {
                Link *nx = FIELD_AT(q, Link *, 0x4);
                self->nodes = func_8001A744(self->nodes, q);
                func_800E1AE4(t, q);
                q = nx;
            } else {
                q = FIELD_AT(q, Link *, 0x4);
            }
        }
    }
    return p;
}
