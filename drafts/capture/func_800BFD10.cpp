// func_800BFD10: 28 differ: retail evaluates &D_800A454C into $s0 before the operator new call (as if `this` of a member call); every form tried rematerialises it after. Same issue in func_800BD534.
#include "common.h"
#include "capture/capture.h"

EXTERN_C char D_80010178[];
EXTERN_C char D_80010338[];
EXTERN_C char D_800A454C[];
EXTERN_C void func_8001D150(void *, void *);
struct T_80010338 {
    void *vt;
    int f4;
    void *owner;
    short fC;
    int f10;
    T_80010338(void *p)
    {
        vt = D_80010178;
        f4 = 0;
        vt = D_80010338;
        fC = 0x80;
        owner = p;
        f10 = 1;
    }
};
EXTERN_C void func_800BFD10(void *p)
{
    func_8001D150(D_800A454C, new T_80010338(p));
}
