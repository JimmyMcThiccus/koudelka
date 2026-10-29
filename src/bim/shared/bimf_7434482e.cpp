// Shared by 84 BIM.AR modules: forwards to the shared base's func_800D8F50 with the third argument as a byte.
#include "common.h"

EXTERN_C void func_800D8F50(void *p, int a, unsigned char b);

EXTERN_C void bimf_7434482e(void *p, int a, int b)
{
    func_800D8F50(p, a, b);
}
