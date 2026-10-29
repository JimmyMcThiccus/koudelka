#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_131b36e3_c(void *p, unsigned *flags) asm("bimf_131b36e3");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");
EXTERN_C int bimf_b4962b94_c(void *p, unsigned *flags) asm("bimf_b4962b94");
EXTERN_C int bimf_dd77db6b_c(void *p, unsigned *flags) asm("bimf_dd77db6b");
EXTERN_C int bimf_e310b46d_c(void *p, unsigned *flags) asm("bimf_e310b46d");

EXTERN_C int bimf_29503d9b(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 0x3E8, 0, 0, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    {
        char *vt = *(char **)p;
        if (((int (*)(void *, int))*(void **)(vt + 0xB4))((char *)p + *(short *)(vt + 0xB0), (int)flags))
            return 1;
    }
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_131b36e3_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_a1b3cda8_c(p, flags))
                return 1;
        }
    }
    if (bimf_b4962b94_c(p, flags))
        return 1;
    if (bimf_dd77db6b_c(p, flags))
        return 1;
    return bimf_e310b46d_c(p, flags);
}
