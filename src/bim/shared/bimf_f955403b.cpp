// Shared by 2 BIM.AR modules: if bit 0 of *flags is set, run func_800D7C7C or else the 0x21 action, and clear it.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_f955403b(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7A20(p, 0);
        if (!func_800D7C7C_i(p, -3, 0)) {
            void *q = func_800D7A4C(p, 1, 0x21);
            if (!q)
                return 0;
            func_800D7AC4(p, q, 1, 0);
        }
        *flags &= ~1;
        return 1;
    }
    return 0;
}
