// 27 differ: same issue as func_800C2BD0 (mirror copy i -> i^1, then func_80028184(p)); retail keeps p in $t1, the four element addresses in $a2/$a1 and the copy registers in $a3,$t0(,$v0); structure otherwise right.
#include "common.h"
#include "capture/capture.h"

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_80028184(void *);
EXTERN_C void func_800C2B28(S_800C2D5C *p)
{
    if (p->state) {
        int i = D_800B4CF0[0];
        E12 *sa = &p->a[i];
        E12 *da = &p->a[i ^ 1];
        da->b = sa->b;
        E16 *se = &p->e[i];
        E16 *de = &p->e[i ^ 1];
        de->b = se->b;
    }
    func_80028184(p);
}
