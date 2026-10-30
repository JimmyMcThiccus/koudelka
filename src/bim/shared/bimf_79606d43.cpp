// Shared by 2 BIM.AR modules: on bit 1 of *flags play the 7818 effect and start move (f9C8 % 3 + 1), or the 0x421
// action if there is none; failing that, the 0x121 action on bit 0. The handled bit is cleared.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_79606d43(BimCnt *p, unsigned *flags)
{
    if (!(*flags & 2))
        return 0;
    func_800D7818(p, 400, 300, 300, 0, 0, 0, 0, 0);
    func_800D8E64(p, -1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    void *s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
    if (!s) {
        s = func_800D7A4C(p, 1, 0x421);
        if (s) {
            if (!func_800D7D64(p, s))
                return 0;
            *flags &= ~2;
            return 1;
        }
    } else if (func_800D7A78(p, s) & 0x10) {
        if (func_800D7D64(p, s)) {
            *flags &= ~2;
            return 1;
        }
    }
    if (!(*flags & 1))
        return 0;
    s = func_800D7A4C(p, 1, 0x121);
    if (!s)
        return 0;
    if (!func_800D7BB4(p, (int)s, 0, 0))
        return 0;
    *flags &= ~1;
    return 1;
}
