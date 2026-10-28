// func_800D2D60: NOT MATCHING. 4 instructions differ: s1/s2 swapped (retail s1 = &v[1], s2 = constant 4). Prelude types T_D2D60*, sv2 are in agentA2.cpp.
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A (batch 2). Each needs the agentA2.cpp prelude.
// func_800D4518: 122 instructions differ (built 8 bytes longer): same logic and case order; register allocation differs
// (retail keeps %hi(D_800B4CF0) in a2 and p in a3, so the index reload can be hoisted above the sh). Note: retail takes
// a second arg (a1 = switch value) but battle.h declares func_800D4518(void *p); func_800D401C calls it with one arg.
// Needs: struct T_SPRT { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
//        struct T_D4518 { char pad[0x2C]; T_SPRT s[2]; };
//@ func_800D2D60
EXTERN_C void func_800D2D60(T_D2D60 *p)
{
    T_D2C50_D *d = ((T_D2C50_G *)func_800787B4())->f328; int i = p->f7C;
    T_D2C50_B *b = d; T_D2C50_s *s = b->items[i];
    func_8008687C(s ? s->f400 : 0, 0);
    func_80054708(p->fFC, s->s412);
    func_80054708(p->fD4, s->s410);
    func_80054708(p->f124, s->s410);
    func_80054FC0(p);
    if (!p->f14C) {
        SVec2 v[2];
        void *m = operator new(0x58);
        sv2(&v[0], 0x56, 0xC);
        sv2(&v[1], 0x4C, 4);
        void *o = func_800646FC(m, 1, v, 2);
        void *g = p->f3C;
        p->f14C = o;
        func_8005800C(g, o);
        func_80064884(p->f14C, s->s412, 0);
        func_800648E8(p->f14C, s->s410);
        m = operator new(0x58);
        sv2(&v[0], 0xB8, 0xC);
        sv2(&v[1], 0x21, 4);
        o = func_800646FC(m, 1, v, 2);
        g = p->f3C;
        p->f150 = o;
        func_8005800C(g, o);
        func_80064884(p->f150, s->s422, 0);
        func_800648E8(p->f150, s->s420);
        o = func_800D3ED0(operator new(0x64), 1, 2);
        g = p->f3C;
        p->f154 = o;
        func_8005800C(g, o);
    }
    p->v5();
    func_8005388C((T_D2D60_B *)p, p->f7C + 0xC);
}
