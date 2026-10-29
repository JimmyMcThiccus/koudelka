// func_800BDEDC: 4 differing instructions: the SVec2C(-1,-1) temp lands at sp+0x218 (BLK temp 8-aligned after buf[0x204]); retail has it at sp+0x214
#include "common.h"
#include "shared/exe.h"
#include "battle/battle.h"
//@ func_800BDEDC base
EXTERN_C void func_800BDEDC(T_BDEDC *p, void *a, int b, int c) {
    char buf[0x204];
    T_BA5FC_o *o = (T_BA5FC_o *)operator new(0x20C);
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_800106EC;
    o->s8 = 0;
    o->sA = 0;
    o->vtbl = D_80010624;
    func_80021F48(o, (int)buf);
    T_BDEDC_o *q = (T_BDEDC_o *)operator new(0x20);
    *(VTable **)q = D_80010178;
    q->f4 = 0;
    q->vtbl8 = D_80010888;
    *(VTable **)q = D_800108A0;
    q->fC = o;
    SVec2C t(-1, -1);
    q->f10 = t;
    q->s14 = 0;
    q->s16 = 0;
    q->f18 = 0;
    q->s1E = 0;
    func_80024BF0(q, a, b, c);
    p->fC = q;
    func_80025444(D_800B4C48, q, 0);
    p->sA = p->fC->s1C;
    p->fC->v3();
    delete (T_Obj0 *)o;
}
