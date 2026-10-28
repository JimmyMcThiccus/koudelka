// func_80028A24 (u_80028428): 27 differ (same size) with register("$9") p; ~37 without. Mirror copy dm[i]->dm[i^1], sp[i]->sp[i^1] (same pattern as func_80028AE8, capture func_800C2B28/C2BD0): retail keeps p in $t1, i in $v1, j in $a0, element ptrs a2/a1 and block-move temps a3,t0 (+v1,a0 for the 16-byte copy).
struct B8 { int a, b; };
struct B16 { int a, b, c, d; };
struct DM2 { int tag; B8 c; };
struct SP2 { int tag; B16 c; };
struct S_Sp2 { char pad0[8]; short unk8; char padA[6]; DM2 dm[2]; SP2 sp[2]; };

EXTERN_C void func_80028184(void *p);
EXTERN_C void func_80028A24(S_Spr2 *q)
{
    S_Sp2 *p = (S_Sp2 *)q;
    if (p->unk8) {
        int i = D_800B4CF0;
        DM2 *s = &p->dm[i];
        DM2 *d = &p->dm[i ^ 1];
        d->c = s->c;
        SP2 *s2 = &p->sp[i];
        SP2 *d2 = &p->sp[i ^ 1];
        d2->c = s2->c;
    }
    func_80028184(p);
}
