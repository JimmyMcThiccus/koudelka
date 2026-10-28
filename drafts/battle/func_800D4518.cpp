// func_800D4518: NOT MATCHING. 122 instructions differ (built 8 bytes longer): same logic and case order; register allocation differs
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A (batch 2). Each needs the agentA2.cpp prelude.
// func_800D4518: 122 instructions differ (built 8 bytes longer): same logic and case order; register allocation differs
// (retail keeps %hi(D_800B4CF0) in a2 and p in a3, so the index reload can be hoisted above the sh). Note: retail takes
// a second arg (a1 = switch value) but battle.h declares func_800D4518(void *p); func_800D401C calls it with one arg.
// Needs: struct T_SPRT { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
//        struct T_D4518 { char pad[0x2C]; T_SPRT s[2]; };
//@ func_800D4518
EXTERN_C void func_800D4518(T_D4518 *p, int a)
{
    int i = D_800B4CF0[0];
    p->s[i].r0 = 0x90;
    p->s[i].w = 0x30;
    p->s[D_800B4CF0[0]].g0 = 0x28;
    switch (a) {
    case 1:
        p->s[D_800B4CF0[0]].u0 = 0;
        p->s[D_800B4CF0[0]].v0 = 0;
        break;
    case 2:
        p->s[D_800B4CF0[0]].u0 = 0x40;
        p->s[D_800B4CF0[0]].v0 = 0;
        break;
    case 3:
        p->s[D_800B4CF0[0]].r0 = 0x10;
        p->s[D_800B4CF0[0]].g0 = 0x80;
        p->s[D_800B4CF0[0]].u0 = 0;
        p->s[D_800B4CF0[0]].v0 = 8;
        break;
    case 0:
        p->s[D_800B4CF0[0]].u0 = 0x40;
        p->s[D_800B4CF0[0]].v0 = 8;
        break;
    default:
        i = D_800B4CF0[0];
        p->s[i].u0 = 0;
        p->s[i].w = 8;
        p->s[D_800B4CF0[0]].v0 = 0x20;
        break;
    }
    func_8005F1D8(p);
}
