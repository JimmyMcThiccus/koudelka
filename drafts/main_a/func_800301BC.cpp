// func_800301BC (and func_80031030): normal of a triangle (OuterProduct0, scale below 0x4000, VectorNormalS).
// Matches up to the max(|x|,|y|,|z|): retail keeps z in $v1 and builds the max into it with a two-level test
// tree; the ternary below allocates y/z the other way round (56 diffs).
struct S_LVec { long vx, vy, vz, pad; };
struct S_SVec { short vx, vy, vz, pad; };
EXTERN_C void OuterProduct0(S_LVec *v0, S_LVec *v1, S_LVec *v2);
EXTERN_C void VectorNormalS(S_LVec *v0, S_SVec *v1);
inline int abs_i(int x) { if (x < 0) x = -x; return x; }
union U_SVec { S_SVec s; S_Blk8 b; };
EXTERN_C S_Blk8 func_800301BC(void *pv)
{
    S_SVec *v = (S_SVec *)pv;
    S_LVec e1, e2, c;
    U_SVec n;
    int x, y, z, m, sh;
    n.s.vx = 0;
    n.s.vy = 0;
    n.s.vz = 0;
    n.s.pad = 0;
    e1.vx = v[1].vx - v[0].vx;
    e1.vy = v[1].vy - v[0].vy;
    e1.vz = v[1].vz - v[0].vz;
    e2.vx = v[2].vx - v[1].vx;
    e2.vy = v[2].vy - v[1].vy;
    e2.vz = v[2].vz - v[1].vz;
    OuterProduct0(&e1, &e2, &c);
    x = abs_i(c.vx);
    y = abs_i(c.vy);
    z = abs_i(c.vz);
    m = y < x ? (z < x ? x : (z < y ? y : z)) : (z < y ? y : (z < x ? x : z));
    sh = 0;
    while (m >= 0x4000) {
        m >>= 1;
        sh++;
    }
    if (sh) {
        c.vx >>= sh;
        c.vy >>= sh;
        c.vz >>= sh;
    }
    VectorNormalS(&c, &n.s);
    return n.b;
}
