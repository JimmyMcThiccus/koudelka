// Shared by 5 BIM.AR modules: clear the object's flag at +0x9F0 if set; returns 0.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_92c79aea(BimMon *p)
{
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}
