// Shared by 72 BIM.AR modules: three virtual calls (slots 18, 20, 19) with the same argument.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_014cace9(BimV *p, int a)
{
    p->v18(a);
    p->v20(a);
    p->v19(a);
}
