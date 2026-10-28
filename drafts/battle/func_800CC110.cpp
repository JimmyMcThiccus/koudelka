// func_800CC110: NOT MATCHING. 20 instructions differ: register allocation only (retail halfwords in a2/a3 and block-move temps t0..t3; ours a1/a2 and a3,t0..). Structure matches (T_CDD0C_e(v,(int)o) assigned to p->e7C0).
#include "common.h"
#include "battle/battle.h"
//@ func_800CC110 a
EXTERN_C int func_800CC110(T_CC110 *p) {
    T_CDD0C_e t(T_CDD0C_v(p->fA0->s4C6, p->fA0->s4CA), (int)p->fA0);
    p->e7C0 = t;
    ce154_1((T_CE044 *)p->f3D8);
    func_800CE044((T_CE044 *)p->f3D8);
    return 1;
}
//@ func_800CC110 b
EXTERN_C int func_800CC110(T_CC110 *p) {
    T_C9284 *o = p->fA0;
    short a = o->s4C6, b = o->s4CA;
    T_CDD0C_v v(a, b);
    T_CDD0C_e t(v, (int)o);
    p->e7C0 = t;
    ce154_1((T_CE044 *)p->f3D8);
    func_800CE044((T_CE044 *)p->f3D8);
    return 1;
}
//@ func_800CC110 c
EXTERN_C int func_800CC110(T_CC110 *p) {
    T_C9284 *o = p->fA0;
    T_CDD0C_v v(o->s4C6, o->s4CA);
    T_CDD0C_e t(v, (int)o);
    T_CE044 *l = (T_CE044 *)p->f3D8;
    p->e7C0 = t;
    ce154_1(l);
    func_800CE044(l);
    return 1;
}
