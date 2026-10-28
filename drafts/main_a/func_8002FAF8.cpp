// func_8002FAF8: 2 diffs: retail computes the giv b (= &t->v[i]) as $a3 = t + 0x14 and copies it to $t1 for v;
// this computes v in $t1 and copies it to $a3 (same pattern as func_8003041C, which matched with edge_sub).
inline int edge_side(S_Tri_V *v, int j, S_Tri_V *b, int x, int z) { S_Tri_V *a = &v[j]; int p = (a->x - b->x) * (z - b->z); int q = (a->z - b->z) * (x - b->x); return q < p; }
EXTERN_C int func_8002FAF8(S_Tri *t, int x, int z)
{
    if (t->n <= 0)
        return 0;
    for (int i = 0; i < 3; i++) {
        S_Tri_V *v = t->v;
        if (edge_side(v, D_800B4D08[i], &v[i], x, z))
            return 0;
    }
    return 1;
}
