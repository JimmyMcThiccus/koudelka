/* func_8004AA44: near miss. 26 differing: min/max loop register allocation (retail: mn=a3 mx=a2 n=t0, s=a1). Uses include/game/a2b/a2b.h + a2/a2.h. */
EXTERN_C int func_8004AA44(char *p)
{
    short *s = (short *)(p + 8);
    int mn = 0x7FFF, mx = -0x8000, n;
    for (n = 3; n; n--) {
        int v = *s;
        s += 4;
        if (v < mn) mn = v;
        if (mx < v) mx = v;
    }
    if (mx - mn >= 0x400)
        return 1;
    s = (short *)(p + 10);
    mn = 0x7FFF; mx = -0x8000;
    for (n = 3; n; n--) {
        int v = *s;
        s += 4;
        if (v < mn) mn = v;
        if (mx < v) mx = v;
    }
    return !(mx - mn < 0x200);
}
