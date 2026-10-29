// Shared by 3 BIM.AR modules: bit 1 of *flags: when func_800D84C8/func_800D8350 allow it, virtual call 21 must answer 2
// before slot 0's move is started.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_0df9734b(BimV *p, unsigned *flags)
{
    if (*flags & 2) {
        int ok = 0;
        if (func_800D84C8(p))
            ok = func_800D8350(p, 2) != 0;
        if (ok) {
            int r = p->v21(2);
            func_800D7A20(p, 5);
            func_800D7A20(p, 0);
            if (r == 2) {
                void *s = (void *)func_800D7ECC(p, 0);
                if (func_800D7D64(p, s)) {
                    *flags &= ~2;
                    return 1;
                }
            }
        }
    }
    return 0;
}
