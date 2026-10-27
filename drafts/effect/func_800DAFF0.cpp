// Retail reaches D_800A4534+0xC as lui/addiu then lw 0xC(reg); every form tried folds it into
// %lo(D_800A4534+0xC), so the code is one instruction short.
#include "effect/effect.h"

EXTERN_C char D_800A4534[];
EXTERN_C void func_800DB0FC(void *self);

EXTERN_C void func_800DAFF0(void *self)
{
    void *p;
    FIELD_AT(self, char, 0x164) = 1;
    FIELD_AT(self, int, 0x14C) = FIELD_AT(D_800A4534, int, 0xC) & ~1;
    p = D_800B4ED8[0];
    FIELD_AT(p, int, 0x278) = 4;
    FIELD_AT(p, int, 0x26C) = 0;
    if (FIELD_AT(self, void *, 0x130) == 0)
        func_800DB0FC(self);
}
