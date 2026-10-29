// Shared by 19 BIM.AR modules: if bit 1 of *flags is set, start the 0x421 action and clear the bit.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_131b36e3(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            func_800D7D64(p, q);
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}
