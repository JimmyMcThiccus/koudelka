// func_800D4BFC: NOT MATCHING. 2 instructions differ: in the two SVec4C(-2,0,2,0) temps, retail stores z as `sh s1,0x64(sp)`; built uses `sh s1,4(s0)`.
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A (batch 2). Each needs the agentA2.cpp prelude.
// func_800D4518: 122 instructions differ (built 8 bytes longer): same logic and case order; register allocation differs
// (retail keeps %hi(D_800B4CF0) in a2 and p in a3, so the index reload can be hoisted above the sh). Note: retail takes
// a second arg (a1 = switch value) but battle.h declares func_800D4518(void *p); func_800D401C calls it with one arg.
// Needs: struct T_SPRT { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
//        struct T_D4518 { char pad[0x2C]; T_SPRT s[2]; };
//@ func_800D4BFC
EXTERN_C T_D4BFC *func_800D4BFC(T_D4BFC *self, int in_chrg, int a)
{
    T_VTable10 vt;
    if (in_chrg) {
        T_D3044_vb *v = &self->v2318;
        self->vb50 = (T_VBase *)v;
        self->v2318.vptr = D_80010178;
        v->f4 = 0;
        self->v2318.vptr = D_800104A8;
    }
    func_80068770(self, 0);
    self->vb50->vptr = (T_VTable10 *)&D_800B7DEC;
    if (!in_chrg) {
        vt = D_800B7DEC;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B7DEC.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x2318));
        vt.e[6].delta = D_800B7DEC.e[6].delta + adj;
    }
    self->vt54 = D_800B7E5C;
    self->vt58 = D_800B7E3C;
    self->vt18 = D_800B7E8C;
    self->f227C = a;
    self->f2280 = 0xFFFF;
    func_80054AF0(self->f2284, 2);
    func_80053928(self->f22D4);
    func_80054584(self->f22F0, 0);
    func_800557C8(self, 0, 7);
    func_80054EB4(self, 0xE0, 0x70);
    f30c(self, 5, SVec4C(-2, 0, 2, 0), 2);
    func_8006897C(self, 1, 1);
    f30c(self->f2284, 5, SVec4C(-2, 0, 2, 0), 2);
    func_80054EB4(self->f2284, 0xE0, 0x14);
    func_80055020(self->f2284, SVec2C(8, 0x51));
    func_8005408C(self->f22F0, 2);
    func_80053F48(self->f22F0, SVec2C(0xD6, 3));
    func_80054E18(self->f2284, self->f22D4);
    func_80054E18(self->f2284, self->f22F0);
    return self;
}
