// Shared by 2 BIM.AR modules: bit 1 of *flags: one time in three, when func_800D84C8 allows it, virtual call 21 then slot 0.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_814d219a(BimV *p, unsigned *flags)
{
    if (*flags & 2) {
        int r = rand() % 3;
        if (func_800D84C8(p) && r == 1) {
            p->v21(3);
            void *s = (void *)func_800D7ECC(p, 0);
            if (func_800D7D64(p, s)) {
                *flags &= ~2;
                return 1;
            }
        }
    }
    return 0;
}
