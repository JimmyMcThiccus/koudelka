// func_800BEF98: 8 differing instructions: scheduling of the two 2-byte temp copies for f18->v10(&a,&b) relative to the vptr load
#include "common.h"
#include "battle/battle.h"
struct T_BEE50_rn { unsigned short h; T_BEE50_rn(const T_BEE50_rn &o) { h = o.h; } T_BEE50_rn(unsigned short v) { h = v; } };
struct T_BEF98_18n { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(T_BEE50_rn a, T_BEE50_rn b); };
//@ func_800BEF98
EXTERN_C int func_800BEF98(T_BEBE0 *p) {
    if (p->b26 == 0) {
    T_BEE50_r ra, rb;
    func_800BEE50(p, &ra, &rb);
    T_BEF98_18 *o18 = (T_BEF98_18 *)p->f18;
    T_BEE50_r a2 = ra;
    T_BEE50_r b2 = rb;
    o18->v10(&a2, &b2);
    T_A4534 *c = &D_800A4534;
    int t = ((c->fC & ~1) - p->f1C) >> 1;
    if (t >= (unsigned short)p->sE) {
        p->b26 = 1;
        ((T_BEF98_14 *)p->f14)->v6(p->f18);
        T_B84FC *o = (T_B84FC *)operator new(0xC);
        int f18 = (int)p->f18;
        o->vtbl = D_800B6DF4;
        o->f4 = 1;
        o->f8 = f18;
        T_BC180 *q = (T_BC180 *)operator new(0x14);
        q->vtbl = D_80010178;
        q->f4 = 0;
        q->vtbl = D_80010338;
        q->f8 = o;
        q->sC = 0x80;
        q->f10 = 1;
        func_8001D150((char *)c + 0x10, q);
        int n = D_800D5D78[0];
        T_BEF98_14 *f14 = (T_BEF98_14 *)p->f14;
        D_800D5D78[0] = n + 1;
        delete f14;
        p->f14 = 0;
    } else {
    if (t == p->f20) return 0;
    if (++p->b24 >= 8) {
        p->b24 = 0;
        p->b25 = !p->b25;
        int off = p->b25 << 6;
        T_V4C v(p->v28.x + off, p->v28.y + off, p->v28.z + off, 0);
        T_C1158_v *fv = (T_C1158_v *)p->f14;
        fv->f34 = *(T_VEC *)&v;
        func_80039DD8(fv);
    }
    p->f20 = t;
    }
    } else if (D_800D5D78[0] == 0) return 1;
    return 0;
}
