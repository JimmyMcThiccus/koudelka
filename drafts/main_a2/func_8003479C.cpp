/* func_8003479C: near miss. 3 instructions: branch sense of the 5th (stack) argument null check. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C int func_8003479C(char *a, char *b, char *c, char *d, char *e)
{
    if (func_80034B0C((S_Rgb *)a, (S_Rgb *)b, (S_Rgb *)c, (S_Rgb *)d, (S_Rgb *)e))
        return func_80034BD4(a ? a + 4 : 0, b ? b + 4 : 0, c ? c + 4 : 0, d ? d + 4 : 0, !e ? 0 : e + 4);
    return 0;
}
