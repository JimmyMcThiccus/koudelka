/* func_800435E8: near miss. 14 differing: retail loads p->1BC with lh (not lhu) before the <<9. Uses include/game/a2b/a2b.h + a2/a2.h. */
EXTERN_C void func_800435E8(void *p)
{
    AT(p, short, 0x1BC) = func_80044890((char *)p + 0x234, AT(AT(p, void *, 0x1B8), short, 0x2E));
    S_A2_Sv v = ((S_A2_At2C *)AT(p, void *, 0x1B8))->v;
    v.z = AT(p, short, 0x1BC) << 9;
    ((S_A2_At2C *)AT(p, void *, 0x1B8))->v = v;
    func_80039DD8(AT(p, void *, 0x1B8));
}
