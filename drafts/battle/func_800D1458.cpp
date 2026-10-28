// func_800D1458: NOT MATCHING. 33 instructions differ, same size: s-register swaps (found/x in loops 1-2; loop-3 pointers) and the zero SVec4 temp:
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A (batch 2). Each needs the agentA2.cpp prelude.
// func_800D4518: 122 instructions differ (built 8 bytes longer): same logic and case order; register allocation differs
// (retail keeps %hi(D_800B4CF0) in a2 and p in a3, so the index reload can be hoisted above the sh). Note: retail takes
// a second arg (a1 = switch value) but battle.h declares func_800D4518(void *p); func_800D401C calls it with one arg.
// Needs: struct T_SPRT { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
//        struct T_D4518 { char pad[0x2C]; T_SPRT s[2]; };
//@ func_800D1458
#define Q ((T_D1458 *)q)
struct T_S4 { short x, y, z, w; T_S4(short a, short b, short c, short d) : x(a), y(b) { z = c; w = d; } };
inline void f30_D1458(void *p, const T_S4 &v) { func_80054F30(p, 5, (SVec4 *)&v, 8); }
EXTERN_C void func_800D1458(void *q)
{
    f30_D1458(q, T_S4(0, 0, 0, 0));
    int found = 1;
    int i = 0;
    XV *x = &((T_D1458b *)q)->x56F8;
    while (found) {
        if (func_8005409C(func_80019F64((List *)lv_of(x), i))) {
            found = 0;
            x->b = i;
        }
        i++;
    }
    found = 1;
    i = 0;
    x = &Q->x1C;
    while (found) {
        if (func_8005409C(func_80019F64((List *)lv_of(x), i))) {
            found = 0;
            x->b = i;
        }
        i++;
    }
    func_800550FC(q, lv_count(&Q->x1C));
    for (unsigned j = 0; j < ((T_4DD0g *)D_800B4DD0[0])->b1FB; j++) {
        func_800D2A2C(&Q->e[j], j);
        short xx = j == (unsigned)D_800B4D5C[0] ? 0x54 : 0x5E;
        int y = ((T_4DD0g *)D_800B4DD0[0])->b1FB - 3;
        Q->e[j].v4(SVec2C(xx, (j - y) * 0x13 + 0xA7));
        f30_D1458(&Q->e[j], T_S4(0, 0, 0, 0));
        Q->e[j].v2();
    }
}
#undef Q
