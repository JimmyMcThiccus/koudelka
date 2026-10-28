/* func_800532EC: near miss. 4 instructions: loop counter/pointer init order. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C void *func_800532EC(void *p, void *q)
{
    S_A2_V4 *s, *d;
    int i;
    func_80027FEC(p, q);
    d = (S_A2_V4 *)((char *)q + 0xC);
    i = 2;
    s = (S_A2_V4 *)((char *)p + 0xC);
    while (i--)
        *d++ = *s++;
    return q;
}
