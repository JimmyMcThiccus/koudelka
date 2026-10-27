// 13 instructions differ: retail spills the saved word at 0x48 to an 8-byte stack slot
// (dead store) before the 16-byte copy; plain int/struct/array/volatile locals don't.
#include "effect/effect.h"

EXTERN_C void func_800E266C(void *self, Vec4 *v)
{
    int w = FIELD_AT(self, int, 0x48);
    FIELD_AT(self, Vec4, 0x3C) = *v;
    FIELD_AT(self, int, 0x48) = w;
}
