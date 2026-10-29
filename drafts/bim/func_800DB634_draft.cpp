#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800DB634(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0x320, 0xC8, 0, 0, 0, 0, 0, 0);
        int id = func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        if (id != 1 && id != 2)
            return 0;
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            func_800D7D64(p, q);
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}
