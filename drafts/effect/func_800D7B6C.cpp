// Matches exactly once maspsx gets --expand-div (retail has ASPSX's div-by-zero/overflow
// break checks; tools/cc.py doesn't pass the flag). Land it when that's fixed.
#include "effect/effect.h"

EXTERN_C int rand(void);

EXTERN_C int func_800D7B6C(RandVal *self)
{
    if (self->spread == 0)
        return self->base;
    return self->base + rand() / (0x8000 / self->spread) - (self->spread >> 1);
}
