// func_800B9480: 9 differing instructions: register allocation only (retail loads n->f10 into a1 and copies to s1, node in s0; ours has o in s0, node in s1)
#include "common.h"
#include "battle/battle.h"
//@ func_800B9480
EXTERN_C void func_800B9480(T_B9480 *p) {
    for (T_B9480_n *n = p->f40C; n; n = n->next) {
        int o = n->f10;
        if (o) {
            func_80039C88((T_B9480_g *)D_800B4ED8[0], o);
            List *l = &p->h510;
            func_80019A6C(l, o, l->count);
            n->f10 = 0;
        }
    }
}
