/* func_8004637C: near miss. 76 differing: loop/delay-slot layout; the same shape serves func_800464E4 and func_80046658 (those two add a func_80036D8C call after the last vcall). Needs the a2b.h declarations plus this prelude. */
EXTERN_C void *func_80048D64(void *p, int a, int b, int c, int d, int e);
EXTERN_C void func_80036D8C(void *p);
EXTERN_C int func_8004637C(void *p, int a, int b, int c)
{
    void *o = func_80048D64(p, a, b, c, 0, 0);
    AT(p, void *, 4) = o;
    { void *t = AT(o, void *, 4); AT(p, int, 8) = AT(p, int, 0xC) = AT(o, int, 0x2C) + AT(t, int, 4); }
    while (AT(AT(p, int *, 8), int, 0) != 0x32313130) {
        void *q = AT(p, void *, 4);
        ((A2VObj0 *)q)->v02();
        func_80036D8C(AT(p, void *, 4));
        o = func_80048D64(p, a, b, c, 0, 0);
        AT(p, void *, 4) = o;
        { void *t = AT(o, void *, 4); AT(p, int, 8) = AT(p, int, 0xC) = AT(o, int, 0x2C) + AT(t, int, 4); }
    }
    AT(p, int, 0) = func_80046998(p, p);
    if (AT(p, int, 0)) {
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        func_80036D8C(AT(p, void *, 4));
        return 1;
    }
    ((A2VObj0 *)AT(p, void *, 4))->v02();
    return 0;
}
