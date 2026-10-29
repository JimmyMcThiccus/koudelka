// r4c: still 2 (lw D_800A4534.fC lands in v1, retail a0). Tried: 400 store orders, locals for the value/&D_800A4534, plain D_800D5D7C, no register hint; permuter 11k iterations: no change.
// func_800B881C: NOT MATCHING. 2 instructions differ: the final lw of D_800A4534.fC lands in v1 (ours) instead of a0 (retail); everything else matches. Uses register-v0 'r' trick for trailing stores.
// Harness format (scratch_c/battle-batch.py): prelude + //@ section. Needs landed func_800BC294 and T_BC294 from battle.h.
#include "common.h"
#include "shared/exe.h"
#include "battle/battle.h"
struct T_B881C_l { void *f0; int f4; void *f8; };
struct T_B881C { VTable *vtbl; char pad4[0x88]; VTable *vtbl8C; char pad90[0x68]; VTable *vtblF8; char padFC[0x3E8]; int f4E4; T_B881C_l f4E8; char pad4F4[0x14]; int f508; int f50C; T_B881C_l f510; char pad51C[0x14]; T_B881C_l f530; char pad53C[0x14]; int f550; int f554; int f558; int f55C; int f560; int f564; int f568; int f56C; };
EXTERN_C int f198E0_v(void *l, int a, int b) __asm__("func_800198E0");
EXTERN_C int D_800D5D7C_a[] __asm__("D_800D5D7C");
//@ func_800B881C b
EXTERN_C T_B881C *func_800B881C(T_B881C *p, int x) {
    func_800BC294((T_BC294 *)p, x);
    p->vtbl8C = D_800B6EE4;
    p->vtblF8 = D_800B6ECC;
    p->vtbl = D_800B6EFC;
    T_B881C_l *l = &p->f4E8;
    l->f8 = (char *)p + 0x4F4;
    p->f4E8.f0 = (char *)p + 0x4F4;
    f198E0_v(l->f8, 0x10, 0);
    l->f4 = 0;
    T_B881C_l *m = &p->f510;
    m->f8 = (char *)p + 0x51C;
    p->f510.f0 = (char *)p + 0x51C;
    f198E0_v(m->f8, 0x10, 0);
    m->f4 = 0;
    T_B881C_l *n = &p->f530;
    n->f8 = (char *)p + 0x53C;
    p->f530.f0 = (char *)p + 0x53C;
    f198E0_v(n->f8, 0x10, 0);
    n->f4 = 0;
    register T_B881C *r asm("$2") = p;
    r->f4E4 = -1;
    r->f550 = 0; r->f554 = 0; r->f558 = 0; r->f55C = 0;
    r->f508 = 0; r->f50C = 0;
    r->f568 = 0; r->f56C = 0; r->f560 = 0;
    r->f564 = D_800A4534.fC;
    D_800D5D7C_a[0] = (int)r;
    return r;
}
