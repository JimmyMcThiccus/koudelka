// func_800B8640: ~20 differ: block order of the `xC != 0` virtual-call path vs the early `return 1`.
#include "common.h"
#include "capture/capture.h"

EXTERN_C int func_800B8640(VObject *p, int a, int b, int c)
{
    int *f = (int *)p;
    if (b)
        return f[2] == a && b == f[3];
    if (f[3]) {
        VtblEntry *e = &p->vt[2];
        ((void (*)(void *, int))e->pfn)((char *)p + e->delta, 0);
        f[3] = 0;
    }
    f[2] = a;
    f[1] = c;
    return 1;
}
