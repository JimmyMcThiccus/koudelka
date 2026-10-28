// func_8001BE20 (u_8001986C): list-filter callback: unlink and kill a finished node. Down to 4 instructions:
// dead() as `int r = 0; if (unkA == 1) r = unk10 == 0;` and a copy `m = n` give retail's shape, but retail
// returns n through the copy ($a1) and uses $a2 for the rest; this has the roles swapped (return via $a2).
struct S_BE20_N {
    virtual void f0();
    virtual void kill();
};
struct S_BE20 : S_BE20_N {
    int dead() { int r = 0; if (unkA == 1) r = unk10 == 0; return r; }
    S_BE20 *next;
    short unk8;
    unsigned short unkA;
    int unkC;
    int unk10;
};
EXTERN_C S_BE20 *func_8001BE20(void *self, S_BE20 *prev, S_BE20 *n)
{
    S_BE20 *m = n;
    if (!n->dead())
        return n;
    if (prev)
        prev->next = m->next;
    m->next = 0;
    m->kill();
    return prev;
}
