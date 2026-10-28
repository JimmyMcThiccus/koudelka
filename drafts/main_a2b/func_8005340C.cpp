/* func_8005340C: near miss. 18 differing: retail loads D_800B4CFC into $t0 before the copy and keeps the prim address in $a3. Needs the a2b.h declarations plus this prelude. */
struct S_A2B_OtT { char pad[0x10]; unsigned n; unsigned *ot; };
EXTERN_C S_A2B_OtT *D_800B4CFC;
struct S_A2B_Tag { unsigned addr : 24; unsigned len : 8; };
EXTERN_C int func_8005340C(void *pv)
{
    S_A2B_Buf *p = (S_A2B_Buf *)pv;
    S_A2B_Ent *d, *s;
    unsigned z;
    S_A2B_OtT *t;
    S_A2B_Tag *pr;
    switch (p->mode) {
    case 1:
        d = E_(p, D_800B4CF0);
        s = E_(p, D_800B4CF0 ^ 1);
        *d = *s;
    case 2:
        p->mode--;
    }
    z = AT(p, unsigned short, 0xA);
    t = D_800B4CFC;
    pr = (S_A2B_Tag *)((char *)(D_800B4CF0 * 16 + (int)p) + 0xC);
    if (z && z < t->n) {
        pr->addr = ((S_A2B_Tag *)&t->ot[z])->addr;
        t->ot[z] = (unsigned)pr & 0xFFFFFF;
    }
    return 1;
}
