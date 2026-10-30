// Shared by 2 BIM.AR modules: run the bimf_db5f4bc4 handler; always handled.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_db5f4bc4(void *p, unsigned *flags);

EXTERN_C int bimf_227b9b39(void *p, unsigned *flags)
{
    bimf_db5f4bc4(p, flags);
    return 1;
}
