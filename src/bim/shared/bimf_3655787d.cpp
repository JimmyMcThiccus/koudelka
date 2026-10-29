// Shared by 3 BIM.AR modules: if bit 1 of *flags is set, start the 0x421 action; on success clear it and store the id.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_3655787d(BimCnt *p, unsigned *flags)
{
    if (*flags & 2) {
        int r = func_800D8E64(p, 1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q && func_800D7D64(p, q)) {
            *flags &= ~2;
            p->fAE8 = r;
            return 1;
        }
    }
    return 0;
}
