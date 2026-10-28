// func_800B94BC (dtor of C_800B9470): 9 differ: scheduling only; retail materialises &D_800112F4 into $v1 before &D_800B6E9C. Store order and values match. Tried temporaries, struct fields, store reordering, real C++ dtor chain (B0 out-of-line / B1 inline / member with dtor): always materialised in store order.
#include "common.h"
#include "capture/capture.h"

EXTERN_C char D_800B6E9C[];
EXTERN_C char D_800112F4[];
EXTERN_C char D_80011304[];
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800B94BC(char *p, int in_chrg)
{
    *(char **)p = D_800B6E9C;
    *(char **)(p + 0xC) = D_800112F4;
    *(char **)p = D_80011304;
    func_8001A610(p, in_chrg);
}
