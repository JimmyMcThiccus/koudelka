// Shared by 3 BIM.AR modules: if bit 0 of *flags is set, try the 0x21, 0x121 and 0x421 actions in turn, clear it.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_ad7de1b4(void *p, unsigned *flags)
{
    if (*flags & 1) {
        rand();
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x21);
        if (!(q && func_800D7BB4(p, (int)q, 0, 0))) {
            q = func_800D7A4C(p, 1, 0x121);
            if (!(q && func_800D7BB4(p, (int)q, 0, 0))) {
                q = func_800D7A4C(p, 1, 0x421);
                if (!q || !func_800D7AC4(p, q, 0, 0))
                    return 0;
            }
        }
        *flags &= ~1;
        return 1;
    }
    return 0;
}
