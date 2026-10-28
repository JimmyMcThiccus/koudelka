// func_8002C7DC (u_80029BBC): reverse-iterate D_800AC710's items calling vslot 2, then func_80019D40, then
// D_800B4CF0 ^= 1. Retail keeps %hi(D_800AC710) in $s1 and reloads the List pointer as %lo(D_800AC710)($s1)
// while the index goes through $s0 = &D_800AC710; GCC here CSEs both into $s0 (16 bytes shorter).
EXTERN_C void func_8002C7DC()
{
    VObj *c;
    S_CollG *g = (S_CollG *)&D_800AC710;
    g->toEnd();
    while ((c = g->prev()) != 0) {
        VEnt *e = &c->vt[2];
        ((void (*)(void *))e->f)((char *)c + e->d);
    }
    func_80019D40((S_80019D40 *)(List *)&D_800AC710);
    D_800B4CF0 ^= 1;
}
