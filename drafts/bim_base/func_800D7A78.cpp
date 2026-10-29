// func_800D7A78: 2 differing instructions. Retail computes the first bit as (f & 2) != 0 via andi/sltu; every form tried (ushort/uchar/int r, !!, ternary) makes GCC emit srl 1; andi 1 instead.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
struct BimFlags { char pad[8]; unsigned short h8; };
EXTERN_C unsigned short func_800D7A78(void *, BimFlags *p) {
    unsigned short r = 0;
    if (p) {
        unsigned short f = p->h8;
        r = !!(f & 2);
        if (f & 0x20) r |= 2;
        if (f & 0x100) r |= 4;
        if (f & 0x400) r |= 0x10;
    }
    return r;
}
EXTERN_C BimMon *D_800AFA64[] asm("D_800AFA64");
EXTERN_C int func_800D8964() {
    int n = 0;
    for (int i = 0; i < 3; i++) {
        BimMon *p = D_800AFA64[i];
        if (p && p->s410) n++;
    }
    return n;
}
EXTERN_C int func_800D89B8() {
    int n = 0;
    for (int i = 0; i < 3; i++) {
        BimMon *p = D_800AFA58[i];
        if (p && p->s410) n++;
    }
    return n;
}
EXTERN_C void func_800D8204(char *p, int a) {
    func_8008299C(p ? p + 0x2A0 : 0, 0x2D, a, 0x14, 0, 0, 0);
    func_80082E14(p ? p + 0x2A0 : 0, 0);
}
EXTERN_C void func_800D8260(char *p, int a) {
    func_8008299C(p ? p + 0x2A0 : 0, 0x2E, a, 0x14, 0, 0, 0);
    func_80082E14(p ? p + 0x2A0 : 0, 0);
}
EXTERN_C int func_800D84C8(BimMon *p) {
    int d = p->s410;
    int r;
    if (d) r = p->s412 / d > 3;
    else r = 1;
    return r;
}
EXTERN_C BimMon *func_800D8464() {
    for (int i = 0; i < 3; i++) {
        BimMon *p = D_800AFA58[i];
        if (p && p->f9EC && p->s410) return p;
    }
    return 0;
}
EXTERN_C int func_800D8350(void *, int d) {
    if (d == 0) return 0;
    return rand() % d == d - 1;
}
