// func_800300C8 (and func_80030EE0, the 4-vertex version): xz bounding box of a triangle. Logic right, branch
// layout off: retail computes the first min into a temp ($v0) then copies it to the min register, with a bnez
// layout for x and a beqz/j layout for z. if/else gives the beqz/j layout for both (33 diffs).
struct S_BV { short x, y, z, pad; };
struct S_BBox { short x, z, w, d; };
EXTERN_C void *func_800300C8(void *pv, void *po)
{
    S_BV *v = (S_BV *)pv;
    S_BBox *out = (S_BBox *)po;
    short mn, mx;
    if (v[0].x < v[1].x) {
        mn = v[0].x;
        mx = v[1].x;
    } else {
        mn = v[1].x;
        mx = v[0].x;
    }
    if (v[2].x < mn)
        mn = v[2].x;
    out->x = mn;
    if (mx < v[2].x)
        mx = v[2].x;
    out->w = mx - mn;
    if (v[0].z < v[1].z) {
        mn = v[0].z;
        mx = v[1].z;
    } else {
        mn = v[1].z;
        mx = v[0].z;
    }
    if (v[2].z < mn)
        mn = v[2].z;
    out->z = mn;
    if (mx < v[2].z)
        mx = v[2].z;
    out->d = mx - mn;
    return out;
}
