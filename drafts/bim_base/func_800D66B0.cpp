// func_800D66B0: 10 differing instructions. Same code but i/ptr are in swapped callee-saved registers (retail i=$s0, ptr=$s1).
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
EXTERN_C BimGrp *func_800D66B0(BimGrp *g, BimGrpDesc *d) {
    int i = 0;
    void *cur = d->data;
    BimGrp *q;
    if (d->s8 > 0) {
        q = g;
        do {
            void *o = operator new(0x28);
            void *r = func_800D69B4(o, cur, &cur);
            i++;
            q->e[0] = r;
            q = (BimGrp *)((char *)q + 4);
        } while (i < d->s8);
    }
    g->f18 = 0;
    return g;
}
