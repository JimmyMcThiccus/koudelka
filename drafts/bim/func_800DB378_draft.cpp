#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800DB378(void *p, unsigned *flags)
{
    unsigned f;
    int ret;
    if (*flags & 2) {
        func_800D7818(p, 0x190, 0x12C, 0x12C, 0, 0, 0, 0, 0);
        func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q && func_800D7D64(p, q)) {
            *flags &= ~2;
            return 1;
        }
        f = *flags;
        if (f & 2) {
            *flags = f & ~2;
            return 1;
        }
    } else
        f = *flags;
    ret = f & 1;
    if (ret) {
        *flags = f & ~1;
        ret = 1;
    }
    return ret;
}
