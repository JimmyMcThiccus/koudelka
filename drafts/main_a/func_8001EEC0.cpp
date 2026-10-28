// func_8001EEC0 (u_8001DDF4; func_8001E9A8 has the same loop): the item loop over the iterator member at
// +0xA4. Modelling it as `struct S_ItA : virtual S_LB { int idx; ... }` (vbase pointer at +0xA4, idx at +0xA8)
// gets retail's `lw a0,0xA4(s0)` / `lw v0,4(s1)` split in the loop test; the body still differs (retail
// re-reads idx through 0xA8($s0) and stores it there). Plain-struct version below (55 diffs).
extern "C" int func_8001EEC0(void *p, void *unused)
{
    S_Task *s = (S_Task *)p;
    char *g;
    Holder *h;
    Item *it;
    func_800186E8(&D_800A451C);
    g = (char *)&D_800AC688;
    h = g ? (Holder *)(g + 8) : 0;
    func_80019CFC(h, s);
    if (s->unk98)
        func_8001E804(s->unk98, s);
    S_Iter *i = &s->iter;
    i->idx = 0;
    while ((it = i->next()) != 0)
        func_8001E840(it);
    if (func_8001A6A8(D_800B4C1C, (int)s))
        D_800B4C1C = (S_8001F1BC *)func_8001A744(D_800B4C1C, s);
    else
        D_800B4C20 = func_8001A744(D_800B4C20, s);
    func_80018788(&D_800A451C);
    return 1;
}
