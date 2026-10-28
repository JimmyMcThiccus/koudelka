/* func_8004BC14: near miss. Ghidra-guided (word loads + short casts) version, 51-73 differing depending on the colour-copy form (this is the 51 one minus the colour temps: remove the c0..c2 block to get it): logic matches; retail keeps p in $t2, the vertex pointers in $a2/$a3/$t4. Same shape as func_80049D2C (prim of 5 words, extra `p->0x18 & 0x2000000` cull bypass). Needs S_A2B_OtB from a2b.h. */
EXTERN_C S_A2B_OtB *D_800B4D00_p asm("D_800B4D00");
//// func_8004BC14
EXTERN_C void func_8004BC14(void *p)
{
    unsigned *p14 = AT(p, unsigned *, 0x14);
    unsigned *p10 = AT(p, unsigned *, 0x10);
    unsigned *p6 = AT(p, unsigned *, 0xC);
    unsigned uVar9 = *p14;
    unsigned uVar8 = *p10;
    int y1 = (int)uVar8 >> 16;
    unsigned uVar7 = *p6;
    int z0, z1, z2, mn, mx;
    unsigned *prim;
    if (0 < ((int)(short)*p10 - (int)(short)*p6) * (((int)uVar9 >> 16) - y1) -
                (y1 - ((int)uVar7 >> 16)) * ((int)(short)uVar9 - (int)(short)*p10)) {
        z0 = (short)p6[1]; z1 = (short)p10[1]; z2 = (short)p14[1];
        if (z0 < z1) {
            if (z0 < z2) { mn = z0; mx = z1; if (mx < z2) mx = z2; }
            else { mn = z2; mx = z1; }
        } else {
            if (z1 < z2) { mn = z1; mx = z0; if (mx < z2) mx = z2; }
            else { mn = z2; mx = z0; }
        }
        if (0 < mn) {
            prim = (unsigned *)((char *)p + (D_800B4CF0 * 28 + 0x18));
            prim[2] = uVar7;
            prim[4] = uVar8;
            prim[6] = uVar9;
            {
                unsigned c0 = AT(p, unsigned, 0x50), c1 = AT(p, unsigned, 0x54), c2 = AT(p, unsigned, 0x58);
                prim[1] = c0;
                prim[3] = c1;
                prim[5] = c2;
            }
            D_800B4D00_p->add((S_A2B_PTag *)prim, mx >> 2);
        }
    }
}
