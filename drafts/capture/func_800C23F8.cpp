// func_800C23F8: constructor; 9 instructions differ. Retail copies `this` to $v0 right after the
// func_800198E0 call and stores the trailing fields through $v0 (constants in $v1); this version
// keeps $s0 as the base and copies `this` at the end. Same pattern matched in C_800BF80C, which has an
// out-of-line base; here the bases are inline.
#include "common.h"
#include "capture/capture.h"

EXTERN_C char D_80010178[];
EXTERN_C char D_800B751C[];

struct B_80010178 {
    void *vt;
    int f4;
    B_80010178()
    {
        vt = D_80010178;
        f4 = 0;
    }
};

struct B_800B751C : B_80010178 {
    B_800B751C() { vt = D_800B751C; }
};

struct C_800C23F8 : B_800B751C {
    short f8;
    short pad;
    Vec_800BF80C v;
    int pad1C[4];
    short f2C;
    int f30, f34, f38;
    C_800C23F8();
};

C_800C23F8::C_800C23F8() : v(5)
{
    f8 = -1;
    f2C = -1;
    f30 = 0;
    f34 = 1;
    f38 = 1;
}
