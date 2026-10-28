/* func_8003585C: near miss. 3 instructions: operand order of p->1C - p->20. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C int func_8003585C(A2VObj0 *p, unsigned int n)
{
    unsigned int end = AT(p, unsigned int, 0x1C);
    unsigned int avail = end - AT(p, unsigned int, 0x20);
    void *r;
    if (n >= avail)
        n = avail;
    r = (void *)p->v04(n);
    if (r) {
        CdGetSector(r, n >> 2);
        return 1;
    }
    return 0;
}
