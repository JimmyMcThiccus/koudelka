// NEAR (18 differ): CSE reuses the first -1 pseudo for the second compare (bne skips the call block via cse-skip-blocks), so -1 lives in a callee-saved reg; retail rematerialises -1 in $v0. NOTE: scratch_c/near/effect/func_800DA514.cpp holds func_800D7524 code by mistake; this is the real draft.
#include "common.h"
#include "effect/effect.h"

EXTERN_C int func_800DA514(SlotSet *self, int obj, int slot)
{
    if (slot == -1)
        slot = func_800DA584(self);
    if (slot == -1)
        return -1;
    if (slot < self->first)
        self->first = slot;
    self->slots[slot] = obj;
    return slot;
}
