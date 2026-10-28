/* func_80038D34: near miss. 38 differing: retail materialises `c ? c->14 : 0` into a register (the +0x14 word of the object at +0x48 looks like a virtual-base pointer, so this is a derived->virtual-base conversion); ours folds the test into the branch. Uses include/game/a2/a2.h. */
struct S_A2_VD { virtual ~S_A2_VD(); };
struct S_A2_48 { char pad[0x14]; S_A2_VD *f14; };
EXTERN_C void func_80038D34(void *p, int a)
{
    S_A2_VD *v;
    AT(p, void **, 0) = D_80012674;
    v = AT(p, S_A2_VD *, 0x68);
    if (v) { delete v; AT(p, int, 0x68) = 0; }
    S_A2_48 *c = AT(p, S_A2_48 *, 0x48);
    if (c ? c->f14 : 0) {
        if (!AT(p, short, 0x64)) {
            c = AT(p, S_A2_48 *, 0x48);
            S_A2_VD *w = c ? c->f14 : 0;
            if (w) delete w;
        }
        AT(p, S_A2_48 *, 0x48)->f14 = 0;
    }
    func_8003C0D0(p, 0);
    func_8003BF30(p, a);
}
