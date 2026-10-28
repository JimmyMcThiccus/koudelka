struct S_PC_Ot { char pad0[0x10]; unsigned int count; unsigned int *tab; };
extern struct S_PC_Ot *D_800B4D00_pp asm("D_800B4D00");
extern int D_800B4CF0;
void func_8004BC14(char *p)
{
    unsigned *p14 = *(unsigned **)(p + 0x14);
    unsigned *p10 = *(unsigned **)(p + 0x10);
    unsigned *p6 = *(unsigned **)(p + 0xC);
    unsigned uVar9 = *p14;
    unsigned uVar8 = *p10;
    int y1 = (int)uVar8 >> 16;
    unsigned uVar7 = *p6;
    int z0, z1, z2, mn, mx;
    unsigned *prim;
    unsigned z;
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
            struct S_PC_Ot *t;
            prim = (unsigned *)(p + (D_800B4CF0 * 28 + 0x18));
            prim[2] = uVar7;
            prim[4] = uVar8;
            prim[6] = uVar9;
            prim[1] = *(unsigned *)(p + 0x50);
            prim[3] = *(unsigned *)(p + 0x54);
            prim[5] = *(unsigned *)(p + 0x58);
            t = D_800B4D00_pp;
            z = mx >> 2;
            if (z != 0 && z < t->count) {
                *prim = (*prim & 0xff000000) | (t->tab[z] & 0xffffff);
                t->tab[z] = (unsigned)prim & 0xffffff;
            }
        }
    }
}
