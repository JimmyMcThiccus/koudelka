/* func_800468D8: near miss. 2 differing: prologue order (lw of the 5th stack arg before saving $s0). Needs the a2b.h declarations plus this prelude. */
EXTERN_C int func_800468D8(void *a, int b, int c, void *d, int e)
{
    int r = func_80036FC0(e, b, c, d);
    if (!r) { if (d) func_80035DE0(d); return 1; }
    if (d) ((A2VObj0 *)d)->v00(0);
    return 0;
}
