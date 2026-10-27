// func_800BD330: logic matches. Retail gives each path its own `j end` with the
// return value set in the delay slot (120 bytes); GCC here merges the two
// `return 0` tails and shares the increment path (112 bytes). Tried inline
// atLast()/rewind() helpers and reordered branches without success.
#include "field/field.h"

EXTERN_C int func_800BD330(Unk_800BD3E0* p) {
    if (p->unk18 == p->unkA - 1) {
        if (p->unk20 != 1) {
            func_800BD3FC(p);
            return 0;
        }
        p->unk18 = 0;
        p->unk14 = p->unk10;
        return 0;
    }
    p->unk18 += 1;
    p->unk14++;
    return 1;
}
