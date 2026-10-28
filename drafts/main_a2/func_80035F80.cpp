/* func_80035F80: near miss. 4 instructions: prologue saves s1 before s0 (param copy order). Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C void func_80035F80(int a, int b)
{
    func_800188D4(&D_800A451C);
    if (D_800B4D0C)
        ((A2VObj0 *)D_800B4D0C)->v09((unsigned char)a, b);
    else
        func_8009CAE0(0);
    func_80018970(&D_800A451C);
}
