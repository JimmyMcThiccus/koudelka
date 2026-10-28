// 6 differ: op==1 branches: retail keeps the p->f30[k-1] pointer in $v0 (lw v0,0x30(v0); beqz v0; lw a0,0x1B8(v0)), we allocate it to $a0. Everything else matches.
#include "common.h"
#include "capture/capture.h"

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *D_800B4ED8[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C void func_8003F8CC(void *, void *);
EXTERN_C int func_8003912C(int, int);
EXTERN_C void func_80039C88(void *, int);
EXTERN_C void func_80039BEC(int, int);
EXTERN_C void func_800392D4(int);
EXTERN_C void func_800392F4(int);
EXTERN_C void func_8003FC08(void *, int, int);
EXTERN_C void func_80039DD8(void *);

struct Pos_800BD800 {
    int x, y, z, w;
};
struct M_800BD800 {
    char pad[0x34];
    Pos_800BD800 pos;
};
struct O_800BD800 {
    char pad[0x1B4];
    M_800BD800 *m;
    int f1B8;
};
struct H_800BD800 {
    char pad[0x10];
    unsigned short n;
};
struct R_800BD800 {
    unsigned char b[500];
};
struct S_800BD800 {
    char pad0[0x24];
    char *f24;
    char pad28[8];
    O_800BD800 *f30[5];
    void *f44;
    O_800BD800 *f48[4];
    char pad58[0x28F4 - 0x58];
    int f28F4[4];
    int f2904[4];
};

EXTERN_C void func_800BD800(S_800BD800 *p, int in, short last)
{
    unsigned char *d;
    H_800BD800 *h;
    unsigned char *s;
    unsigned char *c;
    int op, b;
    int i;
    if (!in)
        return;
    d = (unsigned char *)in;
    h = (H_800BD800 *)(p->f24 + 0x7C);
    s = d;
    if (last) {
        for (i = 0; i < h->n; i++) {
            if (p->f30[i])
                func_8003F8CC(p->f30[i], s);
            s += 500;
        }
    }
    c = (unsigned char *)(h->n * 500 + (int)d);
    op = c[0];
    b = c[1];
    if (!op)
        return;
    if (op == 1) {
        int j = (b & 0x70) >> 4;
        int k = b & 0xF;
        int r;
        int a, x;
        if (!(b & 0x80)) {
            O_800BD800 *o = p->f30[k - 1];
            if (!o)
                return;
            x = o->f1B8;
            a = 0xD;
        } else {
            O_800BD800 *o = p->f30[k - 1];
            if (!o)
                return;
            x = o->f1B8;
            a = 0xE;
        }
        r = func_8003912C(x, a);
        if (p->f2904[j - 1])
            func_80039C88((void *)p->f2904[j - 1], p->f28F4[j - 1]);
        if (p->f48[j - 1])
            func_80039BEC(r, p->f48[j - 1]->f1B8);
        p->f2904[j - 1] = r;
        p->f28F4[j - 1] = p->f48[j - 1]->f1B8;
    } else if (op == 2) {
        int a = p->f30[(b & 0xF) - 1]->f1B8;
        int t = (b & 0x30) >> 4;
        a += 0x6C;
        if (t == 1)
            func_800392D4(a);
        else if (t == 2)
            func_800392F4(a);
    } else if (op == 3) {
        int m = 1;
        int k = b & 7;
        int n = (unsigned)b >> 4;
        int q;
        if (b & 8)
            m = 2;
        q = m * 15;
        func_8003FC08(p->f30[k - 1], 1, n * q);
    } else if (op == 4) {
        int x = p->f30[(b & 0xF) - 1]->f1B8;
        func_80039C88(D_800B4ED8[0] ? D_800B4ED8[0] + 0x50 : 0, x);
    } else if (op == 5) {
        int x = p->f30[(b & 0xF) - 1]->f1B8;
        func_80039BEC((int)(D_800B4ED8[0] ? D_800B4ED8[0] + 0x50 : 0), x);
    } else if (op == 6) {
        char *o = func_8001CA10(0x14);
        *(char **)o = D_80010178;
        *(int *)(o + 4) = 0;
        *(char **)o = D_80010300;
        *(short *)(o + 8) = 2;
        *(short *)(o + 0xA) = 6;
        *(int *)(o + 0x10) = 5;
        *(void **)(o + 0xC) = 0;
        *(char **)o = D_800102D0;
        func_8001EFE4(p->f44, o);
    } else if (op == 7) {
        int j = ((unsigned)b >> 4) - 1;
        Pos_800BD800 v = p->f30[j]->m->pos;
        M_800BD800 *m;
        v.y -= 200;
        m = p->f30[j]->m;
        m->pos = v;
        func_80039DD8(m);
    } else if (op == 8) {
        int j = ((unsigned)b >> 4) - 1;
        Pos_800BD800 v = p->f30[j]->m->pos;
        M_800BD800 *m;
        v.y += 200;
        m = p->f30[j]->m;
        m->pos = v;
        func_80039DD8(m);
    } else if (op == 9) {
        char *o = func_8001CA10(0x14);
        *(char **)o = D_80010178;
        *(int *)(o + 4) = 0;
        *(char **)o = D_80010300;
        *(short *)(o + 8) = 2;
        *(short *)(o + 0xA) = 6;
        *(int *)(o + 0x10) = 5000;
        *(void **)(o + 0xC) = 0;
        *(char **)o = D_800102D0;
        func_8001EFE4(p->f44, o);
    }
}
