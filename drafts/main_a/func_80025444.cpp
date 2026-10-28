// func_80025444 (u_80020B70): ~145 differing. Globals solved (asm-label aliases with section(".data") for D_800B4C50/52,
// D_800B4C54 as in h_u_80020B70.h; note the asm label must come before __attribute__ in this cc1). What remains is
// the same width pattern as func_80024D40: retail keeps (w << 16) in $s0 and derives sra 16/17/18 per branch.
// Prelude used:
extern "C" short D_800B4C50_x asm("D_800B4C50") __attribute__((section(".data")));
extern "C" short D_800B4C52_x asm("D_800B4C52") __attribute__((section(".data")));
struct S_VramQ {
    char pad0[0x4];
    S_VramV2 *unk4;
};
inline short S_half(S_AnimV *o, short w) { return o ? (o->f3() ? w >> 1 : w >> 2) : w; }
inline int S_ptne(S_Pt4 *a)
{
    int r = 0;
    if (a->x != D_800B4C50_x || a->y != D_800B4C52_x)
        r = 1;
    return r;
}
extern "C" int func_80025444(S_VramQ *q, S_TexImg *p, int abr)
{
    S_Pt4 pos;
    pos.x = 0;
    pos.y = 0;
    if (p->getSize().x + p->getSize().y <= 64) {
        if (!q->unk4)
            return 0;
        pos = q->unk4->f4(S_Pt4c(S_half(p->unkC, p->size.x), p->size.y));
        if (S_ptne(&pos)) {
            ((S_AnimV *)p)->f2(pos, abr);
            return 1;
        }
    }
    {
        pos = ((S_VramV2 *)D_800B4C54)->f4(S_Pt4c(S_half(p->unkC, p->size.x), p->size.y));
        if (!S_ptne(&pos))
            return 0;
        ((S_AnimV *)p)->f2(pos, abr);
        return 1;
    }
}
