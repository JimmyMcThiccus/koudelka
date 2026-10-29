// Shared by 13 BIM.AR modules: the three virtual calls of bimf_014cace9 (slots 18, 20, 19), then "handled".
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_1a38796b(BimV *p, int a)
{
    p->v18(a);
    p->v20(a);
    p->v19(a);
    return 1;
}
