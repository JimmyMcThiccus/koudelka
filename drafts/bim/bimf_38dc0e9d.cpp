// Shared by 2 BIM.AR modules: bit 1 of *flags: kick off a 0x2BC/0x12C effect, then start a move when the id is 0 or 1.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_38dc0e9d(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0x2BC, 0x12C, 0, 0, 0, 0, 0, 0);
        func_800D8E64(p, -1);
        int id = func_800D8AE4_a(p);
        void *s = (void *)func_800D7ECC(p, id);
        if (s && (func_800D7A78(p, s) & 0x10) && id < 2 && id >= 0) {
            func_800D7D64(p, s);
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}
