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
    if (!(func_800D7A78(p, s) & 0x10))
        return 0;
    func_800D7D64(p, s);
    *flags &= ~2;
    return 1;
}
