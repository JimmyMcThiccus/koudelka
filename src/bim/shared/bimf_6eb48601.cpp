// Shared by 14 BIM.AR modules: clear bit 1 (else bit 0) of *flags, returning whether either was set.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_6eb48601(void *p, unsigned *flags)
{
    unsigned f = *flags;
    if (f & 2) {
        *flags = f & ~2;
        return 1;
    }
    if (f & 1) {
        *flags = f & ~1;
        return 1;
    }
    return 0;
}
