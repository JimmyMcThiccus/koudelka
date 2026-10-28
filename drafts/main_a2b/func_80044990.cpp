/* func_80044990: near miss. 23 differing: angle normalisation; retail stores `a` inside each loop arm and uses `~x+1` for the abs. Needs the a2b.h declarations plus this prelude. */
EXTERN_C void func_80044990(void *p, int a, int b, int c, int d, int e)
{
    int *q = (int *)p;
    int x, diff;
    q[5] = d;
    q[6] = e;
    if (a < 0) { while (a < 0) a += 0x1000; q[0] = a; } else { while (a > 0x1000) a -= 0x1000; q[0] = a; } x = a;
    q[2] = b;
    diff = b - x;
    q[3] = c;
    { int t = diff; if (t < 0) t = ~t + 1; if (t > 0x800) { if (diff > 0) diff -= 0x1000; else diff += 0x1000; } }
    q[1] = diff;
    q[4] = func_80041C18(q + 7);
}
