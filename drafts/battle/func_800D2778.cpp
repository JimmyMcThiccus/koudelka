// func_800D2778: NOT MATCHING. 2 instructions differ: zero SVec4C temp, retail stores z/w as `sh zero,0x14/0x16(sp)`; built uses 4/6($s1).
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A (batch 2). Each needs the agentA2.cpp prelude.
// func_800D4518: 122 instructions differ (built 8 bytes longer): same logic and case order; register allocation differs
// (retail keeps %hi(D_800B4CF0) in a2 and p in a3, so the index reload can be hoisted above the sh). Note: retail takes
// a second arg (a1 = switch value) but battle.h declares func_800D4518(void *p); func_800D401C calls it with one arg.
// Needs: struct T_SPRT { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
//        struct T_D4518 { char pad[0x2C]; T_SPRT s[2]; };
//@ func_800D2778
EXTERN_C T_D2778 *func_800D2778(T_D2778 *p)
{
    func_80054AF0(p, 8);
    func_800537C0(p->f50);
    p->vt58 = D_800B7AFC;
    p->vt18 = D_800B7ACC;
    p->f5C = 4;
    func_80053928(p->f60);
    p->f7C = 1;
    func_800538CC(p->f80, D_800B7A84, 2);
    func_800538CC(p->f9C, D_800B7A8C, 2);
    func_800538CC(p->fB8, D_800B7A94, 1);
    func_80054584(p->fD4, 0);
    func_80054584(p->fFC, 0);
    func_80054584(p->f124, 0);
    p->f14C = 0;
    p->f150 = 0;
    p->f154 = 0;
    f30c(p, 0, SVec4C(0, 0, 0, 0), 0);
    func_80054EB4(p, 0xE0, 0x12);
    func_80053F48(p->f80, SVec2C(0x45, 0));
    func_80053F48(p->f9C, SVec2C(0xA6, 0));
    func_80053F48(p->fB8, SVec2C(0x76, 0));
    func_80053F48(p->f60, SVec2C(6, 0));
    func_8005408C(p->fD4, 2);
    func_80053F48(p->fD4, SVec2C(0x76, 0));
    func_80053F48(p->fFC, SVec2C(0x80, 0));
    func_8005408C(p->f124, 2);
    func_80053F48(p->f124, SVec2C(0xD8, 0));
    func_80054E18(p, p->f80);
    func_80054E18(p, p->f9C);
    func_80054E18(p, p->fB8);
    func_80054E18(p, p->f60);
    func_80054E18(p, p->fD4);
    func_80054E18(p, p->fFC);
    func_80054E18(p, p->f124);
    return p;
}
