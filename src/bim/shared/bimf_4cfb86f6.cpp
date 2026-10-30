// Shared by 2 BIM.AR modules: dispatch on the monster's pending command (f9F0) to its handler; clear it after.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_bf95a37b(void *p, unsigned *flags);
EXTERN_C int bimf_af99c5b3(void *p, unsigned *flags);
EXTERN_C int bimf_0d32b1e3(void *p, unsigned *flags);

EXTERN_C int bimf_4cfb86f6(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (bimf_bf95a37b(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
        break;
    case 8:
        if (bimf_af99c5b3(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~1;
            return 1;
        }
        break;
    case 16:
        if (bimf_0d32b1e3(p, flags)) {
            p->f9F0 = 0;
            return 1;
        }
        break;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}
