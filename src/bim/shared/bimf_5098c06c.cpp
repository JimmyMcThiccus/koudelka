// Shared by 2 BIM.AR modules: if bit 0 of *flags is set, start the 0x21 action (if there is one) and clear it.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_5098c06c(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x21);
        if (q)
            func_800D7AC4(p, q, 0, 0);
        *flags &= ~1;
        return 1;
    }
    return 0;
}
