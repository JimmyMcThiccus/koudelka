// WIP, not a match: 139 differing. Retail loop is unrotated (test at top, k < r+1 recomputed) and strength-reduces y+k, y-k, x-k into running regs; ours is rotated with no giv reduction.
#include "common.h"
#include "battle/battle.h"
//@ func_800C8F78 v2
EXTERN_C int func_800C8F78(T_C9A4C *p, int a, T_C9284 *q, int c, int r) {
    p->f848 = 0;
    func_800CA9D0(p, c, 1);
    func_800C7F30((T_Grids *)p, 0);
    if (c != 12 && !q->s410) return 0;
    int x = q->s4C6, y = q->s4CA;
    add_cell(p, x, y);
    for (int k = 1; k < r + 1; k++) {
        add_cell(p, x, y + k);
        add_cell(p, x, y - k);
        add_cell(p, x + k, y);
        add_cell(p, x - k, y);
    }
    return p->f848;
}
