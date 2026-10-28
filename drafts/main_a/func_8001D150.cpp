// func_8001D150: insert a node into a list sorted by the short at +0xC, under the lock. Retail keeps %hi(D_800A451C)
// in $s4 across the calls and has separate tail stores; this version is 232 bytes vs 268 (61 instructions).
struct S_Node16 {
    void **vt;
    S_Node16 *next;
    int unk8;
    short key;
};
static inline S_Lnk *ins_8001D150(S_Lnk *p, S_Lnk *a)
{
    if (p->next && a)
        func_8001A864(a, p->next);
    p->next = a;
    return a;
}
extern "C" void func_8001D150(void *v, void *b)
{
    S_Lnk *list = (S_Lnk *)v;
    S_Node16 *node = (S_Node16 *)b;
    S_Node16 *prev, *c;
    func_800186E8(&D_800A451C);
    prev = 0;
    short key = node->key;
    for (c = (S_Node16 *)list->next; c; prev = c, c = c->next) {
        if (key < c->key) {
            if (prev)
                break;
            ins_8001D150((S_Lnk *)node, list->next);
            list->next = (S_Lnk *)node;
            goto out;
        }
    }
    if (prev)
        ins_8001D150((S_Lnk *)prev, (S_Lnk *)node);
    else
        list->next = (S_Lnk *)node;
out:
    func_80018788(&D_800A451C);
}
