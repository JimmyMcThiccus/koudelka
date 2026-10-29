// Shared by 2 BIM.AR modules: bit 1 of *flags: kick off a 0x2BC/0x12C effect, then start a move if one is available.
// The redundant `p || flags` test only keeps the two `return 0` exits as separate blocks.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_81cee1ab(void *p, unsigned *flags)
{
    if (!(*flags & 2))
        return 0;
    func_800D7818(p, 0x2BC, 0x12C, 0, 0, 0, 0, 0, 0);
    func_800D8E64(p, -1);
    int a = func_800D8AE4_a(p);
    void *s = (void *)func_800D7ECC(p, a);
    if (!s)
        return 0;
    if (!(func_800D7A78(p, s) & 0x10)) {
        if (p || flags)
            return 0;
        else
            return 0;
    }
    func_800D7D64(p, s);
    *flags &= ~2;
    return 1;
}
