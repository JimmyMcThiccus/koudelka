// func_800D2458: 16 differing: statement/load scheduling of the quad edit (tried 18 orderings).
#include "field/field.h"

#define Q p->unk10[i]

EXTERN_C void func_800D2458(Unk_800D2214* p, int w, int h) {
    int i = D_800B4CF0[0];
    int y = Q.y0;
    int u = Q.u0;
    int x = Q.x0;
    Q.x1 = x + w;
    Q.y2 = y + h;
    int v = Q.v0;
    Q.u1 = u + w;
    Q.v2 = v + h;
    Q.x3 = Q.x1;
    Q.u3 = Q.u1;
    Q.y3 = Q.y2;
    Q.v3 = Q.v2;
    Q.y1 = y;
    Q.x2 = x;
    Q.u2 = u;
    Q.v1 = v;
    func_8005F1D8(p);
}
