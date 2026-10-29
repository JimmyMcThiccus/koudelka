// Shared by 21 BIM.AR modules: if bit 1 of *flags is set, start a move and clear the bit when it is available.
// The redundant `p || flags` test only keeps the two `return 0` exits as separate blocks (found with the permuter).
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_b4962b94(void *p, unsigned *flags)
{
    if (!(*flags & 2))
        return 0;
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
