// func_800B8210: NOT MATCHING. 8 instructions differ: scheduling only (where `addiu a0,0x38` and the base u/v split land among the stack stores).
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A. Each needs the agentA.cpp prelude.
// func_800B9480: 9 instructions differ: register allocation only (retail loads n->f10 into a1 and copies to s1; node in s0)
//@ func_800B8210
EXTERN_C void func_800B8210(T_B8210x *p, UVB *a, UVB *b) {
    UVH base = p->uv9C;
    UVH uv[4];
    uv[0].b = *b;
    uv[1].b.u = b->u;
    uv[1].b.v = a->v;
    uv[2].b.u = a->u;
    uv[2].b.v = b->v;
    uv[3].b = *a;
    UVO *o;
    int i;
    for (i = 0, o = p->e38; i < 4; i++, o++) put_uv(o, base, uv[i]);
}
