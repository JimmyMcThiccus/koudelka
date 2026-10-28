// func_800DFEBC:
// MATCHES (0 differing) but can't land yet: its jump table's retail address lies in 0x800D61B0-0x800D6528, where
// tables are 8-aligned absolutely; effect.cpp's rodata starts at 0x800D5DAC (4 mod 8) and GCC aligns compiled
// tables to 8 within the unit, so the table lands 4 bytes off. Needs EFFECT split at the original file boundary.
// matches; jump table jtbl_800D6528 (9 words, no trailing pad) is in the blocked 0x800D61B0-0x800D6528 range
#include "common.h"
#include "effect/effect.h"

EXTERN_C IdArray *func_800DDF58(IdArray *self, short id, short count, short def);
EXTERN_C IdArray *func_800DE180(IdArray *self, short id, short count, short def);
EXTERN_C void func_800DE0E4(void *self, int i, Color c);
EXTERN_C void func_800DE364(void *self, int i, SVec4 v);
EXTERN_C char *func_800D7A14(RandVal *self, char *src);
EXTERN_C void *func_800E01B0(short kind, short b, void *owner);

struct Col_800DFEBC {
    unsigned char x, y, z, w;
    Col_800DFEBC() {}
};

struct SV_800DFEBC {
    short x, y, z, w;
    SV_800DFEBC() {}
};

struct ColRec_800DFEBC {
    int idx;
    Col_800DFEBC c;
};

struct SvRec_800DFEBC {
    int idx;
    SV_800DFEBC v;
};

inline void rv_init_800DFEBC(RandVal *r)
{
    r->vptr = D_800D6038;
    r->base = 0;
    r->step = 0;
    r->range = 0;
    r->phase = 0;
}

/* RandVal seen as a real polymorphic class (g++ 2.8 puts the vptr after the members, at 0xC):
   its synthesized operator= copies the object and restores the old vptr through a stack temp,
   which is the retail sequence. f() is never defined, so no vtable is emitted. */
struct RVP_800DFEBC {
    short base, step, range, phase, spread;
    virtual void f();
};

inline void rv_set_800DFEBC(void *obj, RandVal *s)
{
    FIELD_AT(obj, RVP_800DFEBC, 0x3C) = *(RVP_800DFEBC *)s;
}

EXTERN_C char *func_800DFEBC(void *self, char *src, void *obj)
{
    RandVal rv;
    char *next = 0;
    rv_init_800DFEBC(&rv);
    switch ((short)(FIELD_AT(src, short, 0x0) - 100)) {
    case 0: {
        int i;
        char *h = src;
        IdArray *a = func_800DDF58((IdArray *)operator new(0x14), FIELD_AT(obj, short, 0x8),
                                   FIELD_AT(h, short, 0x4), FIELD_AT(h, short, 0x6));
        ColRec_800DFEBC *p = (ColRec_800DFEBC *)(h + 8);
        for (i = 0; i < FIELD_AT(h, short, 0x4); i++) {
            ((void (*)(void *, int, Col_800DFEBC))func_800DE0E4)(a, i, p->c);
            p++;
        }
        FIELD_AT(obj, IdArray *, 0x34) = a;
        next = (char *)p;
        break;
    }
    case 2: {
        int i;
        char *h = src;
        IdArray *a = func_800DE180((IdArray *)operator new(0x14), FIELD_AT(obj, short, 0x8),
                                   FIELD_AT(h, short, 0x4), FIELD_AT(h, short, 0x6));
        SvRec_800DFEBC *p = (SvRec_800DFEBC *)(h + 8);
        for (i = 0; i < FIELD_AT(h, short, 0x4); i++) {
            ((void (*)(void *, int, SV_800DFEBC))func_800DE364)(a, i, p->v);
            p++;
        }
        FIELD_AT(obj, IdArray *, 0x38) = a;
        next = (char *)p;
        break;
    }
    case 4: {
        func_800D7A14(&rv, src);
        next = src + 0xC;
        rv_set_800DFEBC(obj, &rv);
        break;
    }
    case 5:
        FIELD_AT(obj, short, 0x76) = FIELD_AT(src, short, 0x4);
        next = src + 8;
        break;
    case 6: {
        IdNode *n = 0;
        short id = FIELD_AT(src, short, 0x4);
        if (id - 1 >= 0)
            n = func_800D67F4(FIELD_AT(self, IdNode *, 0x4), id - 1);
        {
            char *rec = (char *)self + FIELD_AT(obj, short, 0x8) * 12;
            FIELD_AT(obj, void *, 0x54) = func_800E01B0(FIELD_AT(rec, short, 0x1C), FIELD_AT(rec, short, 0x18), n);
        }
        next = src + 8;
        break;
    }
    case 7:
        next = func_800E40E4((char *)obj + 0x5C, src);
        break;
    case 8:
        next = func_800E4110((char *)obj + 0x5C, src);
        break;
    }
    return next;
}
