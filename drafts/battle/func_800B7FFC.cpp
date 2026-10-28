// func_800B7FFC: NOT MATCHING. 27 instructions differ: the two UV argument copies for func_800B8210 land at sp+0x18/0x1A (retail sp+0x10, reusing
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A. Each needs the agentA.cpp prelude.
// func_800B9480: 9 instructions differ: register allocation only (retail loads n->f10 into a1 and copies to s1; node in s0)
//@ func_800B7FFC
EXTERN_C T_B7FFC *func_800B7FFC(T_B7FFC *p, short a, short b, UVB *c, UVH *d, UVH *e, unsigned short f, unsigned short g) {
    ctor_BB190(p);
    p->vtbl8 = D_800B6E64;
    p->vtbl = D_800B6E0C;
    p->uv9C = *c;
    p->s98 = a * 10;
    p->s9A = b * 10;
    *(SV4C *)&p->fC = SV4C(0, 1, 0);
    p->m34.code = 0x2E808080;
    call_B8210((T_B8210 *)p, UVH(*d), UVH(*e));
    p->m34.prims[0].code = 0x2C;
    p->m34.prims[1].code = 0x2C;
    *(short *)((char *)p + 0x3E) = f;
    *(short *)((char *)p + 0x3A) = g;
    p->m34.prims[0].len = 9;
    p->m34.prims[1].len = 9;
    return p;
}
