// func_800B85B8: returns 1 (v0) and the increment reuses that register: retail `li v0,1; addu v1,v1,v0`. C gives `addiu v0,v0,1` and a separate `li v0,1`.
#include "common.h"
#include "capture/capture.h"

EXTERN_C void func_80035B98(void *);
EXTERN_C int func_800B85B8(int *p)
{
    int r = 1;
    func_80035B98(p);
    p[3] += r;
    return r;
}
