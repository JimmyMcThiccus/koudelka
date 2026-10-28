// func_800C48D8: NOT MATCHING. 140 differ (same logic): retail p in s3 / cur s5 / oth s6 with g s1, &v1 s4, &m2 s0, &v2 s2; ours allocates p s2, cur s4, oth s5. Matrix/vector locals via func_8003A754/B168/AD78/B310/B2F0, add_prim loops.
#include "common.h"
#include "battle/battle.h"
struct T_C48D8_pb { int tag; int w4, w8, wC; };
struct T_C48D8_p { char pad[8]; short x; short y; int w[3]; };
struct T_C48D8 { char pad0[0xA]; unsigned short hA; char padC[0xC]; unsigned short h18; unsigned short h1A; T_C47D8_1C f1C[2]; unsigned int f34; char *f38; };
EXTERN_C int func_8005F1B4_0() __asm__("func_8005F1B4");
//@ func_800C48D8 a
EXTERN_C int func_800C48D8(T_C48D8 *p) {
    int cur = D_800B4CF0[0];
    int oth = cur ^ 1;
    if (func_8005F1B4_0()) {
        T_D4968_g *g = (T_D4968_g *)D_800B4ED8[0];
        T_MAT m1;
        func_8003A754(&m1, 0x1000);
        long v1[2];
        func_8003B168(v1, &as_b(g)->f48);
        func_8003AD78(&m1, v1);
        SetRotMatrix(&m1);
        T_MAT m2;
        func_8003A754(&m2, 0x1000);
        T_VEC v2;
        func_8003B310(&v2, &as_b(g)->f48);
        func_8003B2F0(&m2, &v2);
        SetTransMatrix(&m2);
        struct { unsigned short x; short y; } sxy;
        RotTransPers((SVec4 *)((char *)p + 0x10), (SVec2 *)&sxy, v1, v1 + 1);
        int bx = p->h18 + sxy.x;
        int by = p->h1A + sxy.y;
        for (unsigned i = 0; i < p->f34; i += 2) {
            ((short *)(p->f38 + (i + oth) * 16))[4] = bx - ((i >> 1) << 3);
            ((short *)(p->f38 + (i + oth) * 16))[5] = by;
            T_C48D8_pb *s = (T_C48D8_pb *)(p->f38 + (i + oth) * 16);
            T_C48D8_pb *d = (T_C48D8_pb *)(p->f38 + (i + cur) * 16);
            int a = s->w4, b = s->w8, c = s->wC;
            d->w4 = a; d->w8 = b; d->wC = c;
        }
    }
    for (unsigned i = 0; i < p->f34; i += 2) add_prim(p->hA, p->f38 + i * 16 + cur * 16);
    add_prim(p->hA, &p->f1C[cur]);
    return p->f34 / 2 + 1;
}
