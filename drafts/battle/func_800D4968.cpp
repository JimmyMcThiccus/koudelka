// func_800D4968: NOT MATCHING. ~150 differ, same size class: logic matches; s-register assignment differs (retail p in s4) and the 16-byte
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A (batch 2). Each needs the agentA2.cpp prelude.
// func_800D4518: 122 instructions differ (built 8 bytes longer): same logic and case order; register allocation differs
// (retail keeps %hi(D_800B4CF0) in a2 and p in a3, so the index reload can be hoisted above the sh). Note: retail takes
// a second arg (a1 = switch value) but battle.h declares func_800D4518(void *p); func_800D401C calls it with one arg.
// Needs: struct T_SPRT { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
//        struct T_D4518 { char pad[0x2C]; T_SPRT s[2]; };
//@ func_800D4968
EXTERN_C int func_800D4968(T_D4968 *p)
{
    if (p->f10) {
        T_MAT m1;
        long pf[2];
        T_MAT m2;
        T_VEC v;
        SVec2 sxy;
        T_D4968_g *g = (T_D4968_g *)D_800B4ED8[0];
        func_8003A754(&m1, 0x1000);
        func_8003B168(pf, &as_b(g)->f48);
        func_8003AD78(&m1, pf);
        SetRotMatrix(&m1);
        func_8003A754(&m2, 0x1000);
        func_8003B310(&v, &as_b(g)->f48);
        func_8003B2F0(&m2, &v);
        SetTransMatrix(&m2);
        RotTransPers(&p->f54, &sxy, &pf[0], &pf[1]);
        int j = D_800B4CF0[0] ^ 1;
        p->s[j].b.x0 = p->h5C + sxy.x;
        p->s[j].b.y0 = p->h5E + sxy.y - 16;
    }
    int i = D_800B4CF0[0];
    T_SPRT2 *e = &p->s[i ^ 1];
    T_SPRT2 *d = &p->s[i];
    d->body = e->body;
    add_prim(p->sA, &p->s[i]);
    add_prim(p->sA, &p->dm[D_800B4CF0[0]]);
    return 2;
}
