// func_800D8064: 23 differing instructions (retail 180 bytes, built 172). Structure and the lwl/lwr struct-temp copy match.
// Retail has p in $s0 / ctx in $s1 (ours swapped), compares via xori+bnez, loads the vptr straight from p+0x3FC and
// adds 0x2A0 after the delta load (no null check); our (BimSub2*)(p+0x2A0) cast loads the vptr via the adjusted pointer.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
EXTERN_C int func_800D8064(BimMon *p) {
    void *c = D_800AF470[0]->f32C;
    BimPosV v;
    if (func_800CD790(c, &v) == 1) {
        BimSub2 *o = (BimSub2 *)((char *)p + 0x2A0);
        o->v16(v);
        func_800C5CC4(c, p->b4BC, v.x, v.y);
        return 1;
    }
    return 0;
}
