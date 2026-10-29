// Shared by 14 BIM.AR modules: clear bit 1 (else bit 0) of *flags, returning whether either was set.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_db5f4bc4(void *p, unsigned *flags)
{
    unsigned f = *flags;
    int ret;
    if (f & 2) {
        *flags = f & ~2;
        return 1;
    }
    ret = f & 1;
    if (ret) {
        *flags = f & ~1;
        ret = 1;
    }
    return ret;
}
