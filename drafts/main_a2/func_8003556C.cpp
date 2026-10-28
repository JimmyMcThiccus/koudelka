/* func_8003556C: near miss. 60 differing and 12 bytes too big (retail 268). Retail does the first `count ? items[0] : 0` once before the loop, jumps into a shared selection block at the loop bottom (`bnez s0` back-edge), and reuses s1 = &p->h for the later conversions. Both a `for (s = first(); s; s = first())` and a `while ((s = first()))` form are off (292 / 224 bytes). Uses include/game/a2/a2.h. */
struct S_A2_VH0C : A2VObj0 { char pad[8]; Holder h; };
static inline A2VObj0 *a2_first(Holder *h) { List *l = h; return l->count ? AT(l, A2VObj0 **, 0)[0] : 0; }
extern "C++" int f3556C(S_A2_VH0C *p) asm("func_8003556C");
int f3556C(S_A2_VH0C *p)
{
    A2VObj0 *s;
    for (s = a2_first(&p->h); s; s = a2_first(&p->h)) {
        if (!p->v06(AT(s, int, 4)))
            return 0;
        s->v00(p ? (char *)p + 8 : 0);
        func_80019CFC((List *)&p->h, (int)s);
    }
    return 1;
}
