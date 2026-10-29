// 2 differing: sw fA0 / sw f2C4 order swapped (source order F,M gives 4 diffs: memset a2 hoist differs)
#include "common.h"
#include "shared/exe.h"
#include "battle/battle.h"
//@ func_800C56A8 best
EXTERN_C T_C56A8 *func_800C56A8(T_C56A8 *p, int a) {
    func_800756F8(p);
    p->vtbl = D_800B7748;
    func_800C1A10_b(p->f4);
    d0230_init(&p->fA4);
    cfe8c_init(&p->f2EC);
    p->s3C6 = 0;
    p->s3C8 = 0;
    func_800CDD0C_b(p->f3D8);
    T_VEC *v = &p->v93C;
    p->v93C.x = 0;
    v->y = 0;
    v->z = 0;
    v->w = 0;
    p->f7D8 = a;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) p->f14[i][j] = 0;
    }
    p->b954 = 3;
    p->b955 = 0;
    T_AF470 *g = D_800AF470[0];
    p->f2C4 = -1;
    p->fA0 = 0;
    p->f3CC = 0;
    p->f3D0 = 0;
    p->f908 = 0;
    p->f934 = 0;
    p->f938 = 0;
    p->f814 = 0;
    p->f818 = 0;
    p->f81C = 0;
    p->f3D4 = 0;
    p->f900 = 0;
    p->f904 = -1;
    memset((char*)g + 0x3B0, 0xFF, 0x80);
    return p;
}
