// Shared by 5 BIM.AR modules: if bit 0 of *flags is set, start the 0x21 action and clear the bit when it took.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_1393ddd0(void *p, unsigned *flags)
{
    if (*flags & 1) {
        func_800D7914((BimMon *)p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x21);
        if (q && func_800D7C7C_i(p, -3, 0)) {
            *flags &= ~1;
            return 1;
        }
    }
    return 0;
}
