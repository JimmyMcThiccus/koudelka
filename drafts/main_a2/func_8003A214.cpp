/* func_8003A214: near miss. 38 differing: retail keeps the `n ? items[n-1] : 0` null test after the `if (!n)` early branch (bnez/beqz on the same count reg); ours folds it. Delete via virtual dtor (slot 0, flag 3) is right. Uses include/game/a2/a2.h. */
struct S_A2_VD { virtual ~S_A2_VD(); };
EXTERN_C int func_8003A214(void *p)
{
    char *h = AT(p, char *, 8);
    if (!h) return 1;
    if (AT(p, int, 4)) {
        AT(p, int, 4)--;
        return 0;
    }
    S_A2_Arr *l = AT(h, S_A2_Arr *, 0);
    if (l->n == 0) {
        func_80019920((List *)l, 0);
        delete h;
        AT(p, int, 8) = 0;
        return 1;
    }
    delete (S_A2_VD *)(l->n ? l->items[l->n - 1] : 0);
    h = AT(p, char *, 8);
    S_A2_Arr *l2 = h ? AT(h, S_A2_Arr *, 0) : 0;
    func_80019C68(h ? AT(h, void *, 0) : 0, l2->n - 1);
    return 0;
}
