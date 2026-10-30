// Shared by 3 BIM.AR modules: bit 1 of *flags: 7818 effect, then three phases (8E64 1 / 2 / 3) trying the 0x421
// action or move (f9C8 [+ rand()]) % 3 + 1, recording the phase in fAE8; phase 1 also tries 0x121 on bit 0.
// The goto to the final 'return 0' keeps retail's 'beqz s0, <return 0>; j <D64>' (a plain 'return 0' inverts it).
#include "common.h"
#include "bim/shared.h"

EXTERN_C void func_800D81FC_t(void *p, int a) asm("func_800D81FC");

EXTERN_C int bimf_51caf7a0(BimCnt *p, unsigned *flags)
{
    void *s;
    if (!(*flags & 2))
        return 0;
    func_800D7818(p, 200, 600, 200, 0, 0, 0, 0, 0);
    func_800D8E64(p, 1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    s = func_800D7A4C(p, 1, 0x421);
    if (s && p->fAE8 != 1) {
        if (func_800D7D64(p, s)) {
            *flags &= ~2;
            p->fAE8 = 1;
            return 1;
        }
        if (*flags & 1) {
            if (func_800D7AC4(p, s, 0, 0)) {
                *(int *)((char *)p + 0x9F0) = 1;
                *flags &= ~1;
                return 1;
            }
        }
        s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
        if (s) {
            if (func_800D7A78(p, s) & 0x10) {
                if (func_800D7D64(p, s)) {
                    *flags &= ~2;
                    p->fAE8 = 1;
                    return 1;
                }
            }
        }
    }
    int k = rand() % 6;
    if (k != 2) {
        func_800D8E64(p, 2);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        s = func_800D7A4C(p, 1, 0x421);
        if (s) {
            func_800D81FC_t(p, 3);
            if (func_800D7D64(p, s)) {
                *flags &= ~2;
                p->fAE8 = 2;
                return 1;
            }
        }
        s = (void *)func_800D7ECC(p, (p->f9C8 + rand()) % 3 + 1);
        if (s) {
            if (!(func_800D7A78(p, s) & 0x10))
                goto three;
            func_800D81FC_t(p, 3);
            if (func_800D7D64(p, s)) {
                *flags &= ~2;
                p->fAE8 = 2;
                return 1;
            }
        }
    }
three:
    func_800D8E64(p, 3);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    s = (void *)func_800D7ECC(p, (p->f9C8 + rand()) % 3 + 1);
    if (!s) {
        int r = rand();
        if (r != r / 2 * 2)
            s = func_800D7A4C(p, 1, 0x421);
        else
            s = func_800D7A4C(p, 2, 0x421);
        if (!s)
            goto fail;
    } else if (!(func_800D7A78(p, s) & 0x10))
        return 0;
    if (!func_800D7D64(p, s))
        return 0;
    *flags &= ~2;
    p->fAE8 = 3;
    return 1;
fail:
    return 0;
}
