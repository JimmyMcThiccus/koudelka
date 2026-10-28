// WIP: structure and loops match retail; only register allocation differs (q shares s0 with l in retail), 760 vs 764 bytes
#include "common.h"
#include "battle/battle.h"
EXTERN_C int f_CD488(T_C9A4C *p, SVec2I *out, int a, int b) __asm__("func_800CD488");


//@ func_800CD790 best
EXTERN_C int func_800CD790(T_C9A4C *p, SVec2I *out) {
    T_C9284 *q = p->fA0;
    int k = q->b4BD;
    func_800C78EC(p, 0);
    if (k == 2) {
        for (int x = 4; x >= 0; x--) p->b2C8[6][x] = -1;
        for (int y = 5; y >= 0; y--)
            for (int x = 0; x < 5; x++) {
                T_C9284 *c = p->f14[y + 1][x];
                if (!c || c == q || c->b4BD != k) p->b2C8[y][x] = -1;
            }
    } else {
        for (int x = 4; x >= 0; x--) p->b2C8[0][x] = -1;
        for (int y = 1; y < 6; y++)
            for (int x = 0; x < 5; x++) {
                T_C9284 *c = p->f14[y - 1][x];
                if (!c || c == q || c->b4BD != k) p->b2C8[y][x] = -1;
            }
    }
    p->l2EC.reset();
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 5; x++)
            if (p->b2C8[y][x] >= 0) p->l2EC.push(SVec2C(x, y));
    if (l_cnt(&p->l2EC)) {
        T_L2EC *l = &p->l2EC;
        func_800CE4E4(l, SVec2C(q->s4C6, q->s4CA), 1);
        l->f90 = 0;
        do { *out = l_cur(l); if (!p->f14[out->y][out->x]) return 1; } while (l2ec_next(l));
    }
    if (k == 2) return f_CD488(p, out, -3, 0); else return f_CD488(p, out, 3, 0);
}

