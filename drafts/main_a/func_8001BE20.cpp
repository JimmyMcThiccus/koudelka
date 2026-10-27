// func_8001BE20: list-filter callback: unlink and kill a finished node. Same size; retail tests the
// inlined dead() result with beqz (no xori) and returns n through a copy in $a1 (11 instructions differ).
struct S_8001BE20_N {
    virtual void f0();
    virtual void kill();
};
struct S_8001BE20 : S_8001BE20_N {
    bool dead() { return unkA == 1 && unk10 == 0; }
    S_8001BE20 *next;
    short unk8;
    unsigned short unkA;
    int unkC;
    int unk10;
};

extern "C" S_8001BE20 *func_8001BE20(void *self, S_8001BE20 *prev, S_8001BE20 *n)
{
    if (!n->dead())
        return n;
    if (prev)
        prev->next = n->next;
    n->next = 0;
    n->kill();
    return prev;
}
