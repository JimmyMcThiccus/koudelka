// Shared by 3 BIM.AR modules: if bit 0 of *flags is set, randomly run func_800D8064 or start the 0x21 action, clear it.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_e32ca3a9(void *p, unsigned *flags)
{
    if (*flags & 1) {
        int r;
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        int v = rand() * 99;
        if (v != v / 2 * 2) {
            r = func_800D8064(p);
        } else {
            void *q = func_800D7A4C(p, 1, 0x21);
            if (!q)
                return 0;
            r = func_800D7AC4(p, q, 1, 0);
        }
        if (r) {
            *flags &= ~1;
            return 1;
        }
    }
    return 0;
}
