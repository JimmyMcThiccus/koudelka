// func_800D7048: 101 differing instructions; control flow and calls match, but p/q/i register assignment differs (retail p=$s1, q=$s0, i=$s2) and the {fC,f10,f14,f18}=0 stores use '$v0=p+0xC; sw 4/8/C($v0)' in retail.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
EXTERN_C BimCtl *func_800D7048(BimCtl *p, int sel, int a, int b, int c, int d, int e, int f) {
    int ids[6];
    int *q = ids;
    p->vtbl = D_800D5DC8;
    p->v[0] = 0; p->v[1] = 0; p->v[2] = 0; p->v[3] = 0;
    p->f4 = 0;
    ids[0] = a; ids[1] = b; ids[2] = c; ids[3] = d; ids[4] = e; ids[5] = f;
    p->s8 = 0;
    for (int i = 0; i < 6; i++) {
        if (*q) {
            if (i == sel) p->f4 = *q;
            else {
                BimXYZW t;
                p->s8++;
                func_8003A150(&t, (char *)*q, 0);
                p->v[0] += t.x;
                p->v[2] += t.z;
            }
        }
        q++;
    }
    BimXYZW t;
    func_8003A150(&t, (char *)func_8003912C((void *)p->f4, 5), 0);
    p->f1C = t.y - 200;
    BimHook *o = (BimHook *)operator new(0x14);
    o->vtbl = D_80010178;
    o->vtbl = D_80010338;
    o->f4 = 0;
    o->f8 = p;
    o->sC = 0x80;
    o->f10 = 0;
    func_8001D150(D_800A4544, o);
    BimGlobal *g = D_800B4ED8[0];
    p->f20 = g->f278;
    g->f278 = 6;
    g->f26C = 0;
    func_800D731C(p);
    return p;
}
