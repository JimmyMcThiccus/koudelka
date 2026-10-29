// Shared by 4 BIM.AR modules: if bit 0 of *flags is set, start the 0x21 action (unless one is running) and clear it.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_9905b8de(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        if (!func_800D8064(p)) {
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
