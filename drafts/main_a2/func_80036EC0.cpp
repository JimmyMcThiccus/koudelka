/* func_80036EC0: near miss. 5 instructions: registers v0/v1 swapped in the final compare. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C int func_80036EC0(void *p, int n)
{
    void *q = p ? AT(p, void *, 4) : 0;
    if (!(((AT(q, unsigned short, 0) >> 4) ^ 1) & 1))
        return 0;
    return AT(AT(p, void *, 4), unsigned int, 4) + n <= AT(p, unsigned int, 0x30);
}
