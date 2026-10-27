// func_800B94BC: 9 differ: destructor; scheduling of the three vtable stores (retail materialises 0x800112F4 first).
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
