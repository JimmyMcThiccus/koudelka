// func_800E2D20: ~30 differ, register choice only: retail's 16-byte copies use $t1-$t4 (here $a3,$t0-$t2) and $s1/$s2 swap; structure and stack layout match.
#include "effect/effect.h"

EXTERN_C Vec4 func_800E3E04(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800E3DC4(Vec4 *a, Vec4 *b);
EXTERN_C short func_800E31B0(void *self, void *arg);

struct SV_800E2D20 {
    short x, y, z, w;
};

inline void tosv_800E2D20(SV_800E2D20 *d, Vec4 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
    d->w = s->w;
}

EXTERN_C short func_800E2D20(void *self, void *arg)
{
    VtEntry *vt;
    short r;
    if (++FIELD_AT(self, short, 0x6C) >= FIELD_AT(self, short, 0x6A))
        return 1;
    vt = FIELD_AT(self, VtEntry *, 0x0);
    Vec4 a = ((Vec4 (*)(void *))vt[3].pfn)((char *)self + vt[3].delta);
    vt = FIELD_AT(self, VtEntry *, 0x0);
    Vec4 b = ((Vec4 (*)(void *))vt[4].pfn)((char *)self + vt[4].delta);
    Vec4 pos;
    pos = func_800E3E04(&func_800E3E04(&FIELD_AT(self, Vec4, 0x38), &a), &b);
    {
        Vec4 next;
        next = func_800E3E04(&pos, &func_800E3DC4(&pos, &FIELD_AT(self, Vec4, 0x28)));
        FIELD_AT(self, Vec4, 0x38) = next;
    }
    FIELD_AT(self, Vec4, 0x28) = pos;
    vt = FIELD_AT(self, VtEntry *, 0x0);
    ((Vec4 (*)(void *, Vec4 *))vt[5].pfn)((char *)self + vt[5].delta, &a);
    tosv_800E2D20(&FIELD_AT(FIELD_AT(self, void *, 0xC), SV_800E2D20, 0xA0), &FIELD_AT(self, Vec4, 0x28));
    r = func_800E31B0(self, arg);
    if (r == 2)
        return FIELD_AT(self, signed char, 0x6E) ? 3 : 2;
    return r;
}
