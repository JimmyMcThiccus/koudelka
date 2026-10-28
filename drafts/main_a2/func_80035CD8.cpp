/* func_80035CD8: near miss. la of D_800B4D13 scheduled before the counter init. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C void func_80035CD8()
{
    int i;
    for (i = 3; i >= 0; i--) D_800B4D10[i] = 0;
}
