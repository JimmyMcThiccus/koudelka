// func_8002FAF8: 1 instruction off: retail `addu $v0, $t0, $t2` (i + &D_800B4D08), this gives the operands
// swapped. Indexing D_800B4D08 directly fixes the addu but then the hoisted `la D_800B4D08` lands after
// the pointer setup instead of before it.
EXTERN_C int func_8002FAF8(S_Tri *t, int x, int z)
{
    signed char *nx;
    int i;
    S_Tri_V *b, *v;
    int p, q;
    if (t->n <= 0)
        return 0;
    i = 0;
    nx = D_800B4D08;
    b = t->v;
    v = b;
    for (; i < 3; b++, i++) {
        S_Tri_V *a = &v[nx[i]];
        p = (a->x - b->x) * (z - b->z);
        q = (a->z - b->z) * (x - b->x);
        if (q < p)
            return 0;
    }
    return 1;
}
