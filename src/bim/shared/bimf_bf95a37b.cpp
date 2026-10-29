// Shared by 2 BIM.AR modules: bit 1 of *flags: kick off a 0x1F4/0xC8/0x12C effect, start the 0x421 action, clear it when it took.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_bf95a37b(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0x1F4, 0xC8, 0x12C, 0, 0, 0, 0, 0);
        func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q && func_800D7D64(p, q)) {
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}
