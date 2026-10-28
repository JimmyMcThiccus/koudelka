/* func_80036090: near miss. s-register assignment for a/b/&D_800A451C differs. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C void func_80036090(int a, int b)
{
    func_800188D4(&D_800A451C);
    func_8009CAC0(0);
    if (D_800B4D0C)
        ((A2VObj0 *)D_800B4D0C)->v11((unsigned char)a, b);
    func_80018970(&D_800A451C);
}
