// func_8002E0A8 (and func_8002E2AC, same with D_800B4CF0 ^ 1): screen-rect clip. Body below (inline clip) gets the
// right stack slots but res's w/h zeroing goes through $t0 (=&res) instead of sp; the non-inline form (all in the
// function body) has the right code but GCC reuses the temp slots (frame 0x20 vs 0x38).
struct S_PtE { short x, y; S_PtE() { } S_PtE(short ax, short ay) { x = ax; y = ay; } };
inline short max_s(short a, short b) { return a < b ? b : a; }
inline int min_i(int a, int b) { return b < a ? b : a; }
struct S_RcE {
    S_PtE pos;
    short w, h;
    S_RcE() { }
    S_RcE(S_PtE p) : pos(p), w(0), h(0) { }
    S_RcE(short ax, short ay, short aw, short ah) { pos.x = ax; pos.y = ay; w = aw; h = ah; }
    S_RcE clip(const S_RcE &c) const
    {
        S_RcE res((S_PtE(c.pos.x < pos.x ? pos.x : c.pos.x, c.pos.y < pos.y ? pos.y : c.pos.y)));
        res.w = min_i(c.pos.x + c.w, pos.x + w) - res.pos.x;
        res.h = min_i(c.pos.y + c.h, pos.y + h) - res.pos.y;
        if (res.w < 0 || res.h < 0)
            return S_RcE(0, 0, 0, 0);
        return res;
    }
};
inline S_RcE operator+(const S_RcE &a, const S_RcE &b) { return S_RcE(a.pos.x + b.pos.x, a.pos.y + b.pos.y, a.w + b.w, a.h + b.h); }
EXTERN_C S_RcE D_800AC730[];
struct S_8002E0A8 { char pad[0x20]; S_RcE rect; char pad28[8]; int unk30; };
//// func_8002E0A8
EXTERN_C S_RcE func_8002E0A8(S_8002E0A8 *p)
{
    if (!p->unk30)
        return p->rect;
    return (p->rect + S_RcE(((S_PtE *)&D_800B4CF4)[D_800B4CF0])).clip(D_800AC730[D_800B4CF0]);
}
