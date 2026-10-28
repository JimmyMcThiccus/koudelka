/* func_8004A89C: near miss. 3 differing: only the polarity of the last null test (retail: `bnez e` with `e+4` in the delay slot, i.e. `pe = e + 4; if (e == 0) pe = 0;` as in Ghidra, but that form changes the rest). func_80034B0C takes the same five args. */
EXTERN_C int func_80034B0C(void *a, void *b, void *c, void *d, void *e);
EXTERN_C int func_8004A89C(void *a, void *b, void *c, void *d, void *e)
{
    int r;
    if (func_80034B0C(a, b, c, d, e)) r = func_8004AC04(a ? (char *)a + 4 : 0, b ? (char *)b + 4 : 0, c ? (char *)c + 4 : 0, d ? (char *)d + 4 : 0, e ? (char *)e + 4 : 0);
    else r = 0;
    return r;
}
