// 16 differ: retail keeps the loop unrotated (j back to the test) and skips the null check on
// the second argument; while/for(;;) forms rotate it and null-check both.
#include "effect/effect.h"

EXTERN_C void func_800D9C48(void *self)
{
    SubNode *n;
    while ((n = FIELD_AT(self, SubNode *, 0x104)) != 0)
        FIELD_AT(self, SubNode *, 0x104) = static_cast<SubNode *>(func_8001A744(FIELD_AT(self, SubNode *, 0x104), n));
}
