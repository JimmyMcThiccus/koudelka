// Shared by 2 BIM.AR modules: bit 0 of *flags: run func_800D8064 or the 0x21 action depending on func_800D8350, clear it.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_22b1759c(void *p, unsigned *flags)
{
    if (*flags & 1) {
        int ret;
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        if (!func_800D8350_b(p, 2)) {
            if (!func_800D8064(p))
                return 0;
            ret = 1;
        } else {
            void *q = func_800D7A4C(p, 1, 0x21);
            if (!q)
                return 0;
            func_800D7AC4(p, q, 1, 0);
            ret = 1;
        }
        *flags &= ~1;
        return ret;
    }
    return 0;
}
