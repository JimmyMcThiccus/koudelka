// func_800D731C: 6 differing instructions (same size 204). Only the order of the trailing stores (2BC / 268 / 2C0) and a reload differs.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
struct BimV0 { int x, y, z, w; BimV0() { x = 0; y = 0; z = 0; w = 0; } };
EXTERN_C int func_800D731C(BimCtl *p) {
    BimG2 *g = (BimG2 *)D_800B4ED8[0];
    BimV0 a;
    BimV0 b = *(BimV0 *)g->v2C8;
    a = b;
    func_8003A150(&b, (char *)p->f4, 0);
    b.y += p->f1C;
    g->f2B8 = b.x;
    g->f2BC = b.y;
    g->f2C0 = b.z;
    g->f268 = 1;
    return 0;
}
