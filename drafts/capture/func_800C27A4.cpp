// func_800C27A4: 11 differ: two element-copy loops counting 1..-1; pointer increment order differs.
#include "common.h"
#include "capture/capture.h"

EXTERN_C void func_80027FEC(void *, void *);
EXTERN_C S_800C2D5C *func_800C27A4(S_800C2D5C *s, S_800C2D5C *d)
{
    int n;
    E16 *se, *de;
    E12 *sa, *da;
    func_80027FEC(s, d);
    de = d->e;
    se = s->e;
    n = 2;
    while (n--)
        { *de = *se; de++; se++; }
    da = d->a;
    sa = s->a;
    n = 2;
    while (n--)
        { *da = *sa; da++; sa++; }
    return d;
}
