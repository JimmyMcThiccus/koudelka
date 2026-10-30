// Shared by 3 BIM.AR modules: selector: 7818 effect, then the f9C8/flag tests and the handler chain.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_f35df0eb_c(void *p, unsigned *flags) asm("bimf_f35df0eb");
EXTERN_C int bimf_6eb48601_c(void *p, unsigned *flags) asm("bimf_6eb48601");

EXTERN_C int bimf_227ce542(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 500, 300, 200, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 2) && (*flags & 2)) {
            func_800D8E64(p, 3);
            void *q = func_800D7A4C(p, 1, 0x421);
            if (q && func_800D7D64(p, q)) {
                *flags &= ~2;
                p->f9F0 = 0x10;
                return 1;
            }
        }
    }
    if (bimf_f35df0eb_c(p, flags))
        return 1;
    return bimf_6eb48601_c(p, flags);
}
