// func_800C1924: 6 differing instructions: t0/t1 swapped between p and (flag!=0)<<7
#include "common.h"
#include "battle/battle.h"
//@ func_800C1924
EXTERN_C int func_800C1924(T_C19BC *p, int flag) {
    T_C19BC_g *g = (T_C19BC_g *)D_800AF470[0];
    int a = (p->b4BC << 4) | 5;
    bool f = flag != 0;
    int b = p->f4D0 ? p->f4D0->b4BC : 0xFF;
    int c = f << 7;
    for (int i = 0x1F; i > 0; i--) g->e3B0[i] = g->e3B0[i - 1];
    g->e3B0[0].a = a;
    g->e3B0[0].b = b;
    g->e3B0[0].c = c;
    g->e3B0[0].d = 0xFF;
    func_800C18B4(p, flag);
    return 1;
}
