// func_80020C64 (u_80020B70; func_80022FB8 inlines the same body): 5 differing instructions, all the
// constants 30/6 for unk4A/unk52/unk50: retail loads 30 into $v1 and 6 into $v0 before the last Vec store.
// Tried statement orders, chained assignment, an inline setter and locals. S_Vec5 is in h_u_80020B70.h.
extern "C" S_20C64 *func_80020C64(S_20C64 *p)
{
    List *l;
    p->vtbl = D_800105B4;
    p->unk4 = 0;
    new (&p->a) S_Vec5(8);
    new (&p->b) S_Vec5(4);
    p->unk4A = 30;
    p->unk52 = 30;
    p->unk50 = 6;
    p->unk48 = 0;
    l = &D_800AC6C4;
    func_80019A6C(l, (int)p, l->count);
    return p;
}
