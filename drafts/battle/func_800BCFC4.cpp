// func_800BCFC4: NOT MATCHING. 43 instructions differ (same size): reg alloc / sched only. Retail keeps p in t2, i in v1, j in a0, ptrs in a2/a1,
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A. Each needs the agentA.cpp prelude.
// func_800B9480: 9 instructions differ: register allocation only (retail loads n->f10 into a1 and copies to s1; node in s0)
//@ func_800BCFC4
EXTERN_C void func_800BCFC4(T_BD0A4 *p) {
    if (p->s8) {
        int i = D_800B4CF0[0];
        T_BD0A4_dm *s = &p->dm[i];
        T_BD0A4_dm *d = &p->dm[i ^ 1];
        d->code = s->code;
        T_BD0A4_pg *s2 = &p->pg[i];
        T_BD0A4_pg *d2 = &p->pg[i ^ 1];
        d2->body = s2->body;
    }
    func_80028184(p);
}
