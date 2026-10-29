// Shared by 9 BIM.AR modules: clear bit 1 (else bit 0) of *flags; always handled.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_05e090a7(void *p, unsigned *flags)
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
    return 1;
}
