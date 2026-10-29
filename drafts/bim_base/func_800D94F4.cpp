// func_800D94F4: 11 differing instructions (508 bytes, same size). Retail keeps m=b3D*b3E*dt in $v1 with the byte b83 in $v0 and stores b83 before the sra 8; ours swaps v0/v1 and defers the sb into the jal delay slot.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
EXTERN_C int func_80079F48(void *);
EXTERN_C int func_800D94F4(BimChar *p) {
    int now = func_80079F48(D_800AF470[0]);
    int dt = now - p->f0;
    p->f0 = now;
    unsigned char old = p->b6D;
    if (p->b7B) {
        int t = p->b7B - dt;
        if (t <= 0) { p->b7B = 0; p->h58 &= ~0x40; }
        else p->b7B = t;
    }
    if (p->b78) {
        int t = p->b78 - dt;
        if (t <= 0) { p->b78 = 0; p->v15(0); p->b6D &= 0x7F; }
        else p->b78 = t;
    }
    if (p->b79) {
        int t = p->b79 - dt;
        if (t <= 0) { p->b79 = 0; p->b6D &= 0xBF; }
        else p->b79 = t;
    }
    if (p->b7A) {
        int t = p->b7A - dt;
        if (t <= 0) { p->b7A = 0; p->b6D &= 0xDF; }
        else p->b7A = t;
        int m = p->b3D * p->b3E * dt;
        int v = m / 4 + p->b83;
        p->b76 = 0;
        p->b83 = v;
        int n = -(v >> 8);
        func_80086B70(p, n);
        if (p->s10 <= 0) p->s10 = 1;
        BimSub2 *o = (BimSub2 *)((char *)func_8008672C((char *)p) + 0x2A0);
        o->v15(n, 0);
        ((short *)p)[p->b76 + 3] = (short)0x8000;
    }
    if (p->b6D != old) p->v17(0, old, p->b6D);
    return 1;
}
