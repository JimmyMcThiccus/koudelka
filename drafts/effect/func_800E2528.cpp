// 15 instructions differ: virtual call returning Vec4 by value. Retail loads the object
// into $v0, adds the this-delta before loading the function and copies the return slot to
// $s0 in the jalr delay slot; both this explicit form and a real C++ virtual call schedule
// it differently.
#include "effect/effect.h"

EXTERN_C Vec4 func_800E2528(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x2C);
    VtEntry *vt = p->vptr;
    return ((Vec4 (*)(void *))vt[4].pfn)((char *)p + vt[4].delta);
}
