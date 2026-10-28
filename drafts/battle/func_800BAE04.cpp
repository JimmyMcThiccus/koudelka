// func_800BAE04: NOT MATCHING. 15 instructions differ: register allocation only (retail 0xB0 in s4, b in s5; t.h loaded into v1) + one sched swap.
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A. Each needs the agentA.cpp prelude.
// func_800B9480: 9 instructions differ: register allocation only (retail loads n->f10 into a1 and copies to s1; node in s0)
//@ func_800BAE04
EXTERN_C int func_800BAE04(T_BAE04 *p) {
    for (int i = 0; i < 35; i++) p->f18[i] = -1;
    func_800BB118((T_BB118 *)p, p->f18);
    T_BAE04_o8 *o8 = p->f8;
    T_UVU t;
    int u;
    if (!o8->fC) u = o8->s10 & 0x3F;
    else if (o8->fC->v3()) u = (o8->s10 << 1) & 0x7F;
    else u = o8->s10 << 2;
    t.set(u, o8->s12);
    D_1F800000[0].s2 = p->f8->h1C;
    D_1F800000[0].s4 = p->f8->fC->h8;
    D_1F800000[0].uv = t.h;
    unsigned short a = D_1F800000[0].s2;
    unsigned short b = D_1F800000[0].s4;
    T_BB190 *o;
    for (int i = 0; i < 35; i++) {
        o = func_800BB190((T_BB190 *)operator new(0xA0));
        p->f10->v5(o);
        ((unsigned char *)&o->m34.code)[2] = 0xB0;
        ((unsigned char *)&o->m34.code)[1] = 0xB0;
        ((unsigned char *)&o->m34.code)[0] = 0xB0;
        ((short *)&o->m34.uv[0])[1] = b;
        ((short *)&o->m34.uv[1])[1] = a;
        ((short *)&o->m34.uv[2])[1] = 1;
        ((unsigned char *)&o->m34.code)[3] |= 2;
        func_800BAFEC(p, (T_BAFEC *)o, i);
        o->f9C = i;
        if (p->f18[i] != -1) o->f98 = 1; else o->f98 = 0;
        ((T_V6 *)&o->vtbl8)->v6();
    }
    return 1;
}
