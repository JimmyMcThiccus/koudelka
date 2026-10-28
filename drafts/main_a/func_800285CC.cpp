// func_800285CC (u_80028428): dtor: vt = D_8001126C, then the base dtor func_80028FD8 inline. Retail loads
// &D_800112F4 first (into $v1) and stores it to +0xC after the vt store; GCC here keeps source order. Probably a
// real class dtor with a second vptr at +0xC.
EXTERN_C void func_800285CC(S_80028FD8 *p, int a)
{
    p->vt = D_8001126C;
    p->vtC = D_800112F4;
    p->vt = D_80011304;
    func_8001A610(p, a);
}
