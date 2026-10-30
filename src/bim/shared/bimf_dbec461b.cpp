// Shared by 3 BIM.AR modules: selector: 7818 effect, then the f9C8/flag tests and the handler chain.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_0df9734b_c(void *p, unsigned *flags) asm("bimf_0df9734b");
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_eb1719f4_c(void *p, unsigned *flags) asm("bimf_eb1719f4");
EXTERN_C int bimf_22b1759c_c(void *p, unsigned *flags) asm("bimf_22b1759c");
EXTERN_C int bimf_05f10258_c(void *p, unsigned *flags) asm("bimf_05f10258");
EXTERN_C int bimf_db5f4bc4_c(void *p, unsigned *flags) asm("bimf_db5f4bc4");

EXTERN_C int bimf_dbec461b(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 600, 0, 400, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    if (bimf_0df9734b_c(p, flags))
        return 1;
    if (((BimV *)p)->v22((int)flags))
        return 1;
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_eb1719f4_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_22b1759c_c(p, flags))
                return 1;
        }
    }
    if (bimf_05f10258_c(p, flags)) {
        if (p || flags)
            return 1;
        else
            return 1;
    }
    return bimf_db5f4bc4_c(p, flags);
}
