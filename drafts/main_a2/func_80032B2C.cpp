/* func_80032B2C: near miss. 19 differing: structure and loop shape match; only the register assignment of the loop (ptr/min/max/count = a1/a3/a2/t0 in retail, a2/t0/a3/a1 here) differs. Same for func_8003494C (stride 8), func_80032BD8/func_800349F8 (bounding test). Uses include/game/a2/a2.h. */
static inline int a2_range(short *q)
{
    int mn = 0x7FFF, mx = -0x8000;
    for (int n = 4; n; n--) {
        int v = *q;
        q += 2;
        if (v < mn) mn = v;
        if (mx < v) mx = v;
    }
    return mx - mn;
}
EXTERN_C int func_80032B2C(void *p)
{
    if (a2_range((short *)((char *)p + 8)) >= 0x400) return 1;
    return !(a2_range((short *)((char *)p + 0xA)) < 0x200);
}
