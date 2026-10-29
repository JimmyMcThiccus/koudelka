// r4c: still 2. Also tried `r = &p->r` inside the call argument / assignment-in-argument / after the call, and copies of p/sz into locals.
// Pass 5 (permuter, ~130 variants: placement of `r = &p->r`, inverted if/else, inline call wrappers, local for sz.x,
// statement order): still 2. It's scheduler priority: s1 = &p->r feeds the call through a1, so it outranks the a0 move.
// Note func_80026420 is now landed with an S_Rect16 * second parameter; declare it that way here.
// func_80026558 (u_80025854; func_8002673C is the same split along y with 256): split a texture-tree node and
// allocate the child. 2 instructions differ: in the else branch retail schedules `addu $a0, $s0` (the call's first
// arg) before `addiu $s1, $s0, 0x8` (r = &p->r); every placement of `r = &p->r` tried gives the opposite order.
// Types: S_TNode/S_R16 in include/game/a/h_u_80025854.h.
EXTERN_C void *func_80026420(void *o, S_R16 *r, S_XYc sz);
EXTERN_C S_Pt16 func_80026558(S_TNode *p, S_XYc sz)
{
    S_R16 *r = &p->r2;
    VObj *c;
    *r = p->r;
    short m = r->x % 64;
    if (m && m + sz.x > 64) {
        int d = 64 - m;
        if (p->r.w - d < sz.x)
            return D_800B4C50_pt;
        p->r.w = d;
        p->r2.w -= d;
        p->r2.x += d;
        c = (VObj *)(p->c1 = (S_TNode *)func_80026420(p, r, sz));
    } else {
        p->r.w = sz.x;
        p->r2.w -= sz.x;
        p->r2.x += sz.x;
        r = &p->r;
        c = (VObj *)(p->c0 = (S_TNode *)func_80026420(p, r, sz));
    }
    if (c) {
        VEnt *e = &c->vt[2];
        return ((S_Pt16 (*)(void *, S_R16 *, S_XYc))e->f)((char *)c + e->d, r, sz);
    }
    p->r.w += p->r2.w;
    return D_800B4C50_pt;
}
