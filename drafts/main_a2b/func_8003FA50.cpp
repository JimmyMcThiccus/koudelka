/* func_8003FA50: near miss. 36 differing: retail keeps two separate call sites (args from different copies); GCC merges the tails. Uses include/game/a2b/a2b.h + a2/a2.h. */
EXTERN_C void func_8003FA50(void *p, void *a, int b, int c)
{
    short *t = AT(p, short *, 0x13C);
    if (t == 0) {
        AT(p, int, 0x13C) = func_80044F18(a, (short)b, (short)c, 0, 1);
    } else {
        int diff = 0;
        if (t[4] != (short)b || t[5] != (short)c)
            diff = 1;
        if (diff)
            AT(p, int, 0x13C) = func_80044F18(a, (short)b, (short)c, 0, 1);
    }
}
