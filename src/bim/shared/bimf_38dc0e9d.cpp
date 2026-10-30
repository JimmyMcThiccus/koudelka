// Shared by 2 BIM.AR modules: on bit 1 of *flags, play the 7818 effect and start the selected move if it is
// usable (7A78 bit 0x10) and the 8E64 result is 0 or 1; clear the bit when it starts.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_38dc0e9d(void *p, unsigned *flags)
{
    if (!(*flags & 2))
        return 0;
    func_800D7818(p, 0x2BC, 0x12C, 0, 0, 0, 0, 0, 0);
    int r = func_800D8E64(p, -1);
    void *s = (void *)func_800D7ECC(p, func_800D8AE4_a(p));
    if (s && (func_800D7A78(p, s) & 0x10) && r < 2 && r >= 0) {
        func_800D7D64(p, s);
        *flags &= ~2;
        return 1;
    }
    return 0;
}
