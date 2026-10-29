// Shared by 2 BIM.AR modules: bit 1 of *flags: take the slot func_800D8634 names, or the 0x421 action, and clear it.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_050d93e7(void *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        int r = func_800D8634(p);
        if (r != -1) {
            void *s = (void *)func_800D7ECC(p, r);
            if (!s) {
                s = func_800D7A4C(p, 1, 0x421);
                if (!s)
                    return 0;
            } else if (!(func_800D7A78(p, s) & 0x10))
                return 0;
            func_800D7D64(p, s);
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}
