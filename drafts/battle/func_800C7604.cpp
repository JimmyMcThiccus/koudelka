// 9 differing: D_800AF470 load temp register (ours lui v1 + hoisted lui v0 for vtable; retail lui v0; lw a0; then lui v0 vtable) in each of 3 cases
#include "common.h"
#include "battle/battle.h"
struct T_C7604 { char pad[0x82C]; int f82C; int f830; };
inline void c7604_post(int code) {
    T_B9844 *o = (T_B9844 *)func_8001CA10(0x14);
    void *g = D_800AF470[0];
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_80010300;
    o->s8 = 2;
    o->sA = 2;
    o->f10 = code;
    o->fC = 0;
    o->vtbl = D_800102D0;
    func_8001EFE4(g, o);
}
//@ func_800C7604 best
EXTERN_C void func_800C7604(T_C7604 *p) {
    if (--p->f82C > 0) return;
    switch (p->f830) {
    case 0: c7604_post(0x202B); break;
    case 1: c7604_post(0x2027); break;
    case 2: c7604_post(0x2031); break;
    }
}
