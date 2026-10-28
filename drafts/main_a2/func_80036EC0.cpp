/* func_80036EC0: near miss. 5 differing: v0/v1 allocation of the two loads and the compare (retail: base in v0 chained from the reloaded p->4, limit in v1). permuter base score 40, no progress in 25 min. Uses include/game/a2/a2.h. */
EXTERN_C int func_80036EC0(void *p, int n)
{
    void *q = p ? AT(p, void *, 4) : 0;
    if (!(((AT(q, unsigned short, 0) >> 4) ^ 1) & 1))
        return 0;
    return AT(AT(p, void *, 4), unsigned int, 4) + n <= AT(p, unsigned int, 0x30);
}
