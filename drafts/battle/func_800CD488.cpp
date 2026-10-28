// WIP (not a near miss): structure/branches/loops match retail; only register allocation differs (q/k/out/l pseudos), 764 vs 776 bytes
#include "common.h"
#include "battle/battle.h"
struct T_CD488_c { short x, y; T_CD488_c() { x = 0; y = 0; } };

//@ func_800CD488 best
EXTERN_C int func_800CD488(T_C9A4C *p, SVec2I *out, int a, int b) {
    SVec2C pos(p->fA0->s4C6, p->fA0->s4CA);
    T_C9284 *q = p->fA0;
    int d = a < 0 ? -a : a;
    int old = q->b4C5;
    q->b4C5 = d < old ? d : old;
    func_800C78EC(p, 0);
    q->b4C5 = old;
    if (a < 0) {
        int y = 6;
        if (pos.y < y) do {
            for (int x = 0; x < 5; x++) p->b2C8[y][x] = -1;
            y--;
        } while (pos.y < y);
    } else {
        int y = 0;
        if (y < pos.y) do {
            for (int x = 0; x < 5; x++) p->b2C8[y][x] = -1;
            y++;
        } while (y < pos.y);
    }
    if (!b) { for (int x = 0; x < 5; x++) p->b2C8[pos.y][x] = -1; }
    p->l2EC.reset();
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 5; x++)
            if (p->b2C8[y][x] >= 0) p->l2EC.push(SVec2C(x, y));
    if (l_cnt(&p->l2EC)) {
        T_CD488_c c;
        c.x = pos.x;
        c.y = a < 0 ? 7 : -1;
        func_800CE4E4(&p->l2EC, *(SVec2C *)&c, 0);
        T_L2EC *l = &p->l2EC;
        l->f90 = 0;
        do { *out = l_cur(l); if (!p->f14[out->y][out->x]) return 1; } while (l2ec_next(l));
    }
    return 0;
}

