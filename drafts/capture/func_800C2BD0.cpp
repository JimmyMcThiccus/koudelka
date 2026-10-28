// 28 differ: structure right (src addr p+((i^1)*12+0xC) computed first, block copies of .b), but register allocation differs: retail address regs $a3/$a2 and scratches $t0,$t1(,$v0); ours puts addresses in $v0/$v1/$a0/$a1. Same issue in func_800C2B28 (mirror copy).
#include "common.h"
#include "capture/capture.h"
EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *p)
{
    int i = D_800B4CF0[0]; E12 *sa = &p->a[i ^ 1]; E12 *da = &p->a[i]; E16 *se = &p->e[i ^ 1]; E16 *de = &p->e[i]; da->b = sa->b; de->b = se->b;
}
