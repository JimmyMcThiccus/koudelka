// ~16 differ: GCC keeps -1 in a callee-saved register (one extra saved reg); retail
// rematerialises -1 into $v0 before each compare.
#include "effect/effect.h"

EXTERN_C int func_800DA514(SlotSet *self, int value, int slot)
{
    if (slot == -1)
        slot = func_800DA584(self);
    if (slot == -1)
        return -1;
    if (slot < self->first)
        self->first = slot;
    self->slots[slot] = value;
    return slot;
}
