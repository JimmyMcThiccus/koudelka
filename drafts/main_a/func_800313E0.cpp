// func_800313E0: retail tests func_8003074C's result with `xori $v0, 1; bnez` (and copies q to $v1 for
// the first three loads); with func_8003074C returning bool this gives a plain beqz. Types are in h_u_8002ED44.h
// (S_Obj34 : S_Obj14, S_Mid34, S_Base34 is in this draft's batch file).
EXTERN_C int func_800313E0(S_Obj34 *p, S_Obj34 **q)
{
    if (!func_8003074C(p, (S_Obj14 **)q))
        return 0;
    return func_80032A9C(p, q[0], q[1], q[2], q[3]);
}
