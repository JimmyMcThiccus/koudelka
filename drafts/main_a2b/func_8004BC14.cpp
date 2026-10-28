/* func_8004BC14: near miss. 83 differing: logic matches (cull cross product, min/max z, OT insert) but register allocation differs: retail keeps p in $t2 and the min/max in $a2/$a0. Same shape as func_80049D2C. Needs S_A2B_OtB from a2b.h. */
EXTERN_C S_A2B_OtB *D_800B4D00_p asm("D_800B4D00");
//// func_8004BC14
EXTERN_C void func_8004BC14(void *p)
{
    short *v2 = AT(p, short *, 0x14);
    short *v1 = AT(p, short *, 0x10);
    short *v0 = AT(p, short *, 0xC);
    int t3 = *(int *)v2, t1 = *(int *)v1, t0 = *(int *)v0;
    int z0, z1, z2, mn, mx;
    char *prim;
    if ((v1[0] - v0[0]) * ((t3 >> 16) - (t1 >> 16)) - ((t1 >> 16) - (t0 >> 16)) * ((short)t3 - v1[0]) <= 0)
        return;
    z0 = v0[2]; z1 = v1[2]; z2 = v2[2];
    if (z0 < z1) {
        if (z0 < z2) { mn = z0; mx = z1; if (mx < z2) mx = z2; }
        else { mn = z2; mx = z1; }
    } else {
        if (z1 < z2) { mn = z1; mx = z0; if (mx < z2) mx = z2; }
        else { mn = z2; mx = z0; }
    }
    if (mn <= 0)
        return;
    mx >>= 2;
    prim = (char *)p + (D_800B4CF0 * 28 + 0x18);
    AT(prim, int, 8) = t0;
    AT(prim, int, 0x10) = t1;
    AT(prim, int, 0x18) = t3;
    {
        int c0 = AT(p, int, 0x50), c1 = AT(p, int, 0x54), c2 = AT(p, int, 0x58);
        AT(prim, int, 4) = c0;
        AT(prim, int, 0xC) = c1;
        AT(prim, int, 0x14) = c2;
    }
    D_800B4D00_p->add((S_A2B_PTag *)prim, mx);
}
