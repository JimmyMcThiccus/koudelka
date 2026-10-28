// func_8002FEC8 (u_8002ED44): triangle twin of the landed func_80030C70 (same NEAR64/VX macros, in h_u_8002ED44.h).
// Same instructions, but retail strength-reduces almost every output address to its own pointer (only o3[1]/o0[2]
// stay base+i), while GCC here keeps C70's pattern ([0] reduced, the rest base+i): 412 vs 444 bytes, 107 diffs.
// Statement order, chain order, int/bool flag, index type and local-pointer forms all give the same result.
EXTERN_C bool func_8002FEC8(S_Base14 *pa, S_Base14 *pb, S_Base14 *pc, S_Base14 *pd, S_Base14 *pe)
{
    bool ok = 1;
    int i;
    for (i = 0; i < 3; i++) {
        int n = 0;
        if (NEAR64(VX(pa, 0), VX(pa, 1)) && NEAR64(VX(pa, 1), VX(pa, 2)) && NEAR64(VX(pa, 2), VX(pa, 0)))
            n = 1;
        ok &= n;
        VX(pb, 0) = VX(pa, 0);
        VX(pc, 1) = VX(pa, 1);
        VX(pd, 2) = VX(pa, 2);
        VX(pb, 1) = VX(pc, 0) = VX(pe, 2) = (VX(pa, 0) + VX(pa, 1)) >> 1;
        VX(pc, 2) = VX(pd, 1) = VX(pe, 0) = (VX(pa, 1) + VX(pa, 2)) >> 1;
        VX(pb, 2) = VX(pd, 0) = VX(pe, 1) = (VX(pa, 2) + VX(pa, 0)) >> 1;
    }
    return !ok;
}
EXTERN_C bool func_8002FEC8(S_Base14 *pa, S_Base14 *pb, S_Base14 *pc, S_Base14 *pd, S_Base14 *pe)
{
    bool ok = 1;
