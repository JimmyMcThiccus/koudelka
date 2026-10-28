/* func_80039A88: near miss. 43 differing: first half (up to the `new` of the 0xC message object) matches. Retail stores the object through a copy (`addu v0,s0,zero; sw vt,0(v0); sw zero,4(v0)`) and computes s3 = holder+8 before those stores; ours stores through s0. Uses include/game/a2/a2.h. */
EXTERN_C void func_80039A88(void *p, int a)
{
    AT(p, void **, 0) = D_800126F4;
    if (AT(p, void *, 0x24))
        func_80039C88(AT(p, void *, 0x24), p);
    if (AT(p, void *, 0x28)) {
        int i = AT(AT(AT(p, char *, 0x28), List *, 0), int, 4);
        while (i) {
            char *h = AT(p, char *, 0x28);
            char *b = h ? h + 8 : 0;
            i--;
            AT(func_80019F64(b ? AT(b, List *, 0) : 0, i), int, 0x24) = 0;
        }
        void *o = operator new(0xC);
        char *s3 = 0;
        char *h2 = AT(p, char *, 0x28);
        if (h2) s3 = h2 + 8;
        AT(o, void **, 0) = D_80010160;
        AT(o, int, 4) = 0;
        char *t = 0;
        char *g = (char *)&D_800AC57C;
        if (g) t = g + 0xF8;
        func_8001D150(t, new S_A2_X1(o));
        AT(o, void **, 0) = D_800126DC;
        AT(o, void *, 8) = s3;
    }
    func_800198AC(p, a);
}
