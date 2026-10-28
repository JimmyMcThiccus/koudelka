// func_800BC294: NOT MATCHING. 13 instructions differ: `addiu a1,0x10` scheduled right after the first call in retail; final f4E0 store goes through v0 (return value) in retail.
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A. Each needs the agentA.cpp prelude.
// func_800B9480: 9 instructions differ: register allocation only (retail loads n->f10 into a1 and copies to s1; node in s0)
//@ func_800BC294
EXTERN_C T_BC294d *func_800BC294(T_BC294d *p) {
    return new (p) T_BC294d;
}
