/* func_80035384: near miss. 12 differing in the best variant: retail loads the vbase pointer through p (`lw v1,0xC(s1)`) while testing s0 = p+0xC for null; ours loads through s0. Typed parameter and inline `first()` helper tried. Uses include/game/a2/a2.h. */
struct S_A2_VH0C : A2VObj0 { char pad[8]; Holder h; };
EXTERN_C void func_80035384(void *vp)
{
    S_A2_VH0C *p = (S_A2_VH0C *)vp;
    unsigned short *q = p ? AT(p, unsigned short *, 4) : 0;
    *q |= 0x11;
    func_8001D324(D_800A4544, func_8001D25C(D_800A4544, (int)(p ? (char *)p + 8 : 0)));
    Holder *h = &p->h;
    while (1) {
        List *l = h;
        A2VObj0 *x = l->count ? AT(l, A2VObj0 **, 0)[0] : 0;
        if (!x) break;
        x->v01(0);
        func_80019C68((List *)h, 0);
    }
}
