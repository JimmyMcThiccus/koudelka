// Same shape as func_800D9C48 (16 differ).
#include "effect/effect.h"

EXTERN_C void func_800D9D08(void *self)
{
    SubNode *n;
    while ((n = FIELD_AT(self, SubNode *, 0x108)) != 0)
        FIELD_AT(self, SubNode *, 0x108) = static_cast<SubNode *>(func_8001A744(FIELD_AT(self, SubNode *, 0x108), n));
}
