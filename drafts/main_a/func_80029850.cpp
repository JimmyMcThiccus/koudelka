// func_80029850 (u_80028428): colour * 7 / 10 clamped at 0, then func_8002972C. First two components match;
// retail clamps the third branch-free (slt/negu/and) while computing it during argument setup, GCC here
// emits a branch.
EXTERN_C S_8002972C *func_80029850(S_8002972C *p, S_8002972C *c)
{
    int t;
    int r = 0;
    t = c->unk5 * 7 / 10;
    if (t > 0)
        r = t;
    int g = 0;
    t = c->unk6 * 7 / 10;
    if (t > 0)
        g = t;
    t = c->unk7 * 7 / 10;
    func_8002972C(p, r, g, t > 0 ? t : 0, 1);
    return p;
}
