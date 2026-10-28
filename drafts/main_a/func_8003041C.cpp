// func_8003041C: edge vectors e[i] = v[D_800B4D08[i]] - v[i]. Right instructions, wrong register/giv
// allocation (24 diffs): retail walks e ($a2) and v[i] ($a1) with D_800B4D08 hoisted first.
EXTERN_C void func_8003041C(S_Tri *t)
{
    int i;
    S_Tri_V *v;
    func_8002F90C((S_8002F90C *)t);
    v = t->v;
    for (i = 0; i < 3; i++) {
        S_Tri_V *a = &v[D_800B4D08[i]];
        S_Tri_V *b = &v[i];
        S_Tri_V *e = &t->e[i];
        e->x = a->x - b->x;
        e->y = a->y - b->y;
        e->z = a->z - b->z;
    }
}
