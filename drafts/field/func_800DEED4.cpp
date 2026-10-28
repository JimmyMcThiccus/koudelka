// func_800DEED4: 11 differing: tail of func_800DEED4 -- retail keeps the angle in a register separate from a1 (`bgez; a1=v0; a1=v0+0x1FF; a0=s0; a1>>=9`), the build does the /512 in place in v0. Header declares (void*, Unk_W3); this uses an int-arg alias.
#include "field/field.h"

struct Unk_800DEED4 { char pad0[0x328]; Unk_800DE59C* unk328; };
EXTERN_C int ratan2(int, int);
EXTERN_C void func_800DEE50(void*, int);

#define p ((Unk_800DEED4*)vp)
EXTERN_C void func_800DEED4_i(void* vp, int x, int z, int y) asm("func_800DEED4");
EXTERN_C void func_800DEED4_i(void* vp, int x, int z, int y) {
    Unk_W4 w = getW(p->unk328);
    int dy = y - w.c;
    int dx = x - w.a;
    if (dy == 0 && dx == 0) {
        return;
    }
    int a = ratan2(dx, dy) + 0x900;
    while (a < 0) {
        a += 0x1000;
    }
    int k = a / 512;
    func_800DEE50(p, k & 7);
}
#undef p
