// Matches exactly once maspsx gets --expand-div (retail has ASPSX's div-by-zero/overflow
// break checks; tools/cc.py doesn't pass the flag). Land it when that's fixed.
#include "effect/effect.h"

EXTERN_C int rand(void);

EXTERN_C void func_800D7A4C(RandVal *self, short *base, short *phase)
{
    int r = 0;
    self->phase += self->step;
    if (self->range != 0)
        r = rand() / (0x8000 / self->range) - (self->range >> 1);
    if (self->range > 0x1000)
        self->range -= 0x1000;
    else if (self->range < -0x1000)
        self->range += 0x1000;
    *base = self->base;
    *phase = self->phase + r;
}
