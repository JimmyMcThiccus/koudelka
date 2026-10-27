// ~18 instructions differ: register choice for step and branch order of the clamp/add arms.
#include "effect/effect.h"

EXTERN_C short func_800E0D50(void *self)
{
    short step = FIELD_AT(self, short, 0x7A);
    if (FIELD_AT(self, short, 0x7C) == 0)
        return step;
    if (FIELD_AT(self, unsigned short, 0x14) + step < FIELD_AT(self, short, 0x7C)) {
        FIELD_AT(self, unsigned short, 0x14) += step;
    } else {
        step = FIELD_AT(self, short, 0x7C) - FIELD_AT(self, unsigned short, 0x14);
        FIELD_AT(self, int, 0x1C) = 1;
        FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(self, short, 0x7C);
    }
    return step;
}
