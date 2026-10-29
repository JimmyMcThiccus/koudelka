// Shared by 40 BIM.AR modules: if bit 0 of *flags is set, run a three-call sequence on the object and clear it.
#include "common.h"
#include "bim/shared.h"


EXTERN_C int bimf_a1b3cda8(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x21);
        if (q)
            func_800D7AC4(p, q, 1, 0);
        *flags &= ~1;
        return 1;
    }
    return 0;
}
