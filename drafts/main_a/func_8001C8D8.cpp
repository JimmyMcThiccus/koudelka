// func_8001C8D8: sorted insert (by ushort key at +8) under the lock. Same size; retail loads c->next into $v1 and
// keeps a copy in $a0 for the advance (an inline helper's parameter copy?); here it loads straight into $a0 (5 instructions).
struct S_Lnk {
    void **vt;
    S_Lnk *next;
};
struct S_8001C8D8 {
    void **vt;
    S_8001C8D8 *next;
    unsigned short key;
};
extern "C" S_Lnk *func_8001A864(S_Lnk *p, S_Lnk *a);
static inline bool goes_8001C8D8(S_8001C8D8 *n, S_8001C8D8 *a)
{
    return a && !(a->key < n->key);
}
extern "C" void func_8001C8D8(S_8001C8D8 *c, S_8001C8D8 *n)
{
    func_800186E8(&D_800A451C);
    while (goes_8001C8D8(n, c->next))
        c = c->next;
    if (c->next && n)
        func_8001A864((S_Lnk *)n, (S_Lnk *)c->next);
    c->next = n;
    func_80018788(&D_800A451C);
}
