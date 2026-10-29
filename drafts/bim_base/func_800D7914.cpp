// func_800D7914: 31 differing instructions (same size 268). Loop/found-block layout differs: retail branches to an out-of-line 'f988 = i+1' block; the call tail loads pos halves without the stack reload.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
struct BimE2 { char pad[2]; unsigned char a, b; char pad4[0x7C]; };
EXTERN_C int func_800D7914(BimMon *p, unsigned n) {
    if (n >= 9) {
        int r = rand();
        int i = 0;
        int d = p->f990;
        char *q = (char *)p;
        int m = r % d;
        for (; i < 8; i++, q += 2)
            if (m < *(short *)(q + 0x994)) break;
        if (i < 8) p->f988 = i + 1;
        else p->f988 = 1;
    } else {
        p->f988 = n;
    }
    if (p->f988 == 0) return 0;
    BimE2 *e = (BimE2 *)((char *)p + p->f988 * 0x80 + 0x4DC);
    BimPos pos;
    pos.y = p->s4CA; pos.x = p->s4C6;
    func_800CC3DC(D_800AF470[0]->f32C, pos, e->a, e->b);
    return p->f988;
}
