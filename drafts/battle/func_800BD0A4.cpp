// func_800BD0A4: NOT MATCHING. 42 instructions differ: same ops/addressing, but retail i/j in a1/v1 and block-move temps t1,t2,v1,t0 interleaved with address calc (built is 4 bytes longer, trailing nop)
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A. Each needs the agentA.cpp prelude.
// func_800B9480: 9 instructions differ: register allocation only (retail loads n->f10 into a1 and copies to s1; node in s0)
//@ func_800BD0A4
EXTERN_C void func_800BD0A4(T_BD0A4 *p) {
    int i = D_800B4CF0[0];
    int j = i ^ 1;
    T_BD0A4_dm *sd = &p->dm[j];
    T_BD0A4_dm *dd = &p->dm[i];
    T_BD0A4_pg *sp = &p->pg[j];
    T_BD0A4_pg *dp = &p->pg[i];
    dd->code = sd->code;
    dp->body = sp->body;
}
