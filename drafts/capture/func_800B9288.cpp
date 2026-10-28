// func_800B9288: 20 differ: retail computes the 3rd vcall arg as 0xF0 - rem with 0xF0 already in $a3 (the 4th arg) ('subu a2,a3,a2'); every form tried either materialises 0xF0 twice or (this one) emits 'addiu a2,a2,0xF0' after negating, shifting registers in the loop body. Loop structure/regs otherwise match.
#include "common.h"
#include "capture/capture.h"

// D_800A4534 (capture.cpp has a shorter Clock_800BD2E0 for it)
struct VObj2C_800B8CE8 {
    char pad[0x2C];
    VtblEntry *vt;
};
struct Clock_800A4534 {
    int f0, f4, f8;
    volatile unsigned int fC;
    char pad10[0x34];
    VObj2C_800B8CE8 *f44;
};
EXTERN_C Clock_800A4534 D_800A4534;

struct O_800B9288 {
    VtblEntry *vt;
    char pad4[0x58];
    unsigned int f5C;
};
struct S_800B9288 {
    char pad0[0x28];
    O_800B9288 *o[2][31];
    char pad120[0x228 - 0x120];
    unsigned int f228;
};

EXTERN_C void func_800B9288(S_800B9288 *p, int)
{
    int i;
    unsigned int t;
    O_800B9288 *o;
    VtblEntry *e;
    unsigned int n = p->f228;
    if (n == 0)
        return;
    if (D_800A4534.fC % 360 == 0)
        p->f228 = n - 1;
    t = (D_800A4534.fC - p->f228) >> 1;
    for (i = 0; i < 2; i++) {
        int j;
        for (j = 0; j < 31; j++) {
            o = p->o[i][j];
            e = &o->vt[8];
            ((void (*)(void *, int, int, int))e->pfn)((char *)o + e->delta, i * 160, -((int)(t - o->f5C) % 248) + 0xF0, 0xF0);
        }
    }
}
