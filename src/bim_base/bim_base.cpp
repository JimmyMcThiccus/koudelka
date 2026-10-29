#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6198);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6328);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6584);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D66B0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6740);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D67EC);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D68EC);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D69B4);

EXTERN_C void func_800D6B98(BimCtl *p, int flags) {
    p->vtbl = D_800D5DB0;
    if (p->v[0]) delete[] (char *)p->v[0];
    if (p->v[1]) delete[] (char *)p->v[1];
    if (p->v[2]) delete[] (char *)p->v[2];
    func_8001D024(p, flags);
}

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6C1C);

EXTERN_C void func_800D6D08(BimCtl *p) {
    if (func_8001D25C(D_800A4544, (int)p)) {
        func_8001D324(D_800A4544, func_8001D25C(D_800A4544, (int)p));
        BimGlobal *g = D_800B4ED8[0];
        g->f278 = 1;
        g->f26C = 0;
    }
    p->f20 = 0;
    p->f24 = 0;
    *(short *)((char *)p + 6) = 0;
    p->v[3] = 0;
}

EXTERN_C int func_800D6D84(BimCtl *p) {
    if (p->f1C) return 1;
    BimXYZW a, b;
    func_8003A150(&a, (char *)p->f20, 0);
    func_8003A150(&b, (char *)p->f24, 0);
    func_800D6DF4(p, &a, &b);
    return 0;
}

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6DF4);

EXTERN_C BimVec4 *func_800D7008(BimVec4 *r, BimVec4 *a, BimVec4 *b) {
    int ax = a->x, bx = b->x, ay = a->y, by = b->y, az = a->z, bz = b->z, aw = a->w;
    r->x = ax - bx; r->y = ay - by; r->z = az - bz; r->w = aw; return r; }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7048);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D71F4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D731C);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D73E8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D76C8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7818);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7914);

EXTERN_C void func_800D7A20() { func_800CC110(D_800AF470[0]->f32C); }

EXTERN_C void func_800D7A4C(void *p, int a, unsigned short b) { func_800CC298(D_800AF470[0]->f32C, a, b); }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7A78);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7AC4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7BB4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7C7C);

EXTERN_C int func_800D7D64(BimMon *p, int a) {
    int r;
    if ((unsigned)(p->f988 - 1) < 8) { int t = p->f9A4; p->f9A4 = 1; r = func_800C02C8(p, a, p->f988 - 1, t); }
    else r = 0;
    return r;
}

EXTERN_C void func_800D7DB4(char *p, unsigned *q) {
    func_800D8FF8(p ? (BimMon *)(p + 0x400) : 0);
    *q &= ~3;
}

EXTERN_C int func_800D7DFC(void *self, BimCtl *o) {
    if (o) self = (void *)o->f4;
    int i = 0;
    if (!self) return -1;
    BimMon **q = D_800AFA64;
    while (i < 3) {
        BimMon *x = *q++;
        if (self == x) return i + 1;
        i++;
    }
    i = 0;
    q = D_800AFA58;
    while (i < 3) {
        BimMon *x = *q++;
        if (self == x) return i + 4;
        i++;
    }
    return -1;
}

EXTERN_C int func_800D7E8C(void *p, int a) { if (a == 0) return 0; return func_800CC220(D_800AF470[0]->f32C); }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7ECC);

EXTERN_C void func_800D7F3C(BimMon *p) {
    void *c = D_800AF470[0]->f32C;
    BimPos pos;
    short y = p->s4CA, x = p->s4C6;
    pos.y = y; pos.x = x;
    func_800CC3DC(c, pos, 5, 1);
}

EXTERN_C int func_800D7F90(void *p, int a, int b) { return func_8007FE4C((char *)D_800AF470[0] + 0x498, a, b); }

EXTERN_C void func_800D7FB8(void *p, int a, int b, int c) { func_8007FF58((char *)D_800AF470[0] + 0x498, a, b, c); }

EXTERN_C void func_800D7FE0() { func_800CFC50(D_800AF470[0]->f32C); }

EXTERN_C int func_800D800C() { return D_800AF470[0]->f32C->f950; }

EXTERN_C int func_800D802C() { int a, b; func_800C8D9C(D_800AF470[0]->f32C, 2, &a, &b); return b + 1; }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8064);

EXTERN_C void func_800D8118(void *p) { func_80085E74(p, 0); }

EXTERN_C void func_800D8138(char *p) { func_8008299C(p ? p + 0x2A0 : 0, 4, 2, 0, 0, 0, 0); }

EXTERN_C void func_800D817C(BimMon *p, char v) { p->b4E4 = v; }

EXTERN_C void func_800D8184(BimMon *p, int a, int b) { p->f4E8 = a; p->f4EC = b; }

EXTERN_C void func_800D8190() { func_800CDA8C(D_800AF470[0]->f32C); }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D81BC);

EXTERN_C void func_800D81FC(BimMon *p, int a) { p->f9A4 = a; }

EXTERN_C void func_800D8204(char *p, int a) {
    func_8008299C(p ? p + 0x2A0 : 0, 0x2D, a, 0x14, 0, 0, 0);
    func_80082E14(p ? p + 0x2A0 : 0, 0);
}

EXTERN_C void func_800D8260(char *p, int a) {
    func_8008299C(p ? p + 0x2A0 : 0, 0x2E, a, 0x14, 0, 0, 0);
    func_80082E14(p ? p + 0x2A0 : 0, 0);
}

EXTERN_C void func_800D82BC(BimMon *p) {
    p->f9C8 = 0; p->f9CC = 0; p->f9D0 = -1; p->f9D4 = 0; p->f9D8 = 0; p->f9DC = 0;
    p->f9E0 = 0; p->f9E4 = 0; p->f9E8 = 0; p->f9EC = 0; p->f9F0 = 0;
}

EXTERN_C void func_800D82F0() { func_800D8AE4(); }

EXTERN_C void func_800D8310(BimMon *p) {
    if (func_800D83D4_a(p)) p->f9C8++;
    p->f9CC = 0;
}

EXTERN_C int func_800D8350(void *, int d) {
    if (d == 0) return 0;
    return rand() % d == d - 1;
}

EXTERN_C int func_800D83BC(void *, int *p) { *p &= ~3; return 1; }

EXTERN_C int func_800D83D4(void *, int *p) { return *p == 0; }

EXTERN_C int func_800D83E0(BimMon *p) {
    if (!p->f9E8) return 0;
    int any = 0;
    for (int i = 0; i < 3; i++) {
        BimMon *q = D_800AFA58[i];
        if (q && q->f9EC && q->s410) any = 1;
    }
    if (!any) p->f9EC = 1;
    return 1;
}

EXTERN_C BimMon *func_800D8464() {
    for (int i = 0; i < 3; i++) {
        BimMon *p = D_800AFA58[i];
        if (p && p->f9EC && p->s410) return p;
    }
    return 0;
}

EXTERN_C int func_800D84C8(BimMon *p) {
    int d = p->s410;
    int r;
    if (d) r = p->s412 / d > 3;
    else r = 1;
    return r;
}

EXTERN_C int func_800D8524() {
    int r[3];
    int i = 0;
    int *q = r;
    BimMon **pp = D_800AFA58;
    for (; i < 3; i++) {
        BimMon *p = *pp;
        if (p && p->s410) *q = p->s412 / p->s410;
        else *q = 0;
        q++;
        pp++;
    }
    int idx;
    int r0 = r[0], r1 = r[1];
    if (r1 < r0) {
        if (r[2] < r0) idx = 0;
        else if (r[2] < r1) idx = 1;
        else idx = 2;
    } else if (r[2] < r1) idx = 1;
    else idx = (r[2] >= r0) ? 2 : 0;
    if (r[idx]) return idx | 4;
    return -1;
}

EXTERN_C int func_800D8634() {
    int r[3];
    int i = 0;
    int *q = r;
    BimMon **pp = D_800AFA64;
    for (; i < 3; i++) {
        BimMon *p = *pp;
        if (p && p->s410) *q = p->s412 / p->s410;
        else *q = 0;
        q++;
        pp++;
    }
    int idx;
    int r0 = r[0], r1 = r[1];
    if (r1 < r0) {
        if (r[2] < r0) idx = 0;
        else if (r[2] < r1) idx = 1;
        else idx = 2;
    } else if (r[2] < r1) idx = 1;
    else idx = (r[2] >= r0) ? 2 : 0;
    if (r[idx]) return idx + 1;
    return -1;
}

EXTERN_C int func_800D8744() {
    int r[3];
    int i = 0;
    int *q = r;
    BimMon **pp = D_800AFA58;
    for (; i < 3; i++) {
        BimMon *p = *pp;
        if (p && p->s410) *q = p->s412 / p->s410;
        else *q = 0;
        q++;
        pp++;
    }
    int idx;
    int r0 = r[0], r1 = r[1];
    if (r1 < r0) {
        if (r[2] < r0) idx = 0;
        else if (r[2] < r1) idx = 1;
        else idx = 2;
    } else if (r[2] < r1) idx = 1;
    else idx = (r[2] >= r0) ? 2 : 0;
    if (r[idx]) return idx | 4;
    return -1;
}

EXTERN_C int func_800D8854() {
    int r[3];
    int i = 0;
    int *q = r;
    BimMon **pp = D_800AFA64;
    for (; i < 3; i++) {
        BimMon *p = *pp;
        if (p && p->s410) *q = p->s412 / p->s410;
        else *q = 0;
        q++;
        pp++;
    }
    int idx;
    int r0 = r[0], r1 = r[1];
    if (r1 < r0) {
        if (r[2] < r0) idx = 0;
        else if (r[2] < r1) idx = 1;
        else idx = 2;
    } else if (r[2] < r1) idx = 1;
    else idx = (r[2] >= r0) ? 2 : 0;
    if (r[idx]) return idx + 1;
    return -1;
}

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

EXTERN_C void func_800D8A0C(void *p, int a) { func_800D7C7C(p, a, 0); }

EXTERN_C void func_800D8A2C(void *p, int a) { func_800D7C7C(p, -a, 0); }

EXTERN_C int func_800D8A50() {
    int m = 0;
    for (int i = 0; i < 3; i++) {
        BimMon *p = D_800AFA58[i];
        if (p && p->s410 && p->s4CA >= m) m = p->s4CA;
    }
    return m;
}

EXTERN_C int func_800D8AB8(BimMon *p) { return func_800D8A50() - p->s4CA; }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8AE4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8C0C);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8CC0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8D64);

EXTERN_C int func_800D8E38(BimMon *p, int n) {
    if ((unsigned)(n - 1) >= 8) return 0;
    return (p->f9F4 & (1 << (n - 1))) != 0;
}

EXTERN_C int func_800D8E64(BimMon *a, int b) {
    int r;
    if ((func_800D8E38(a, b) ^ 1) == 0) {
        r = func_800D7914(a, b);
        if (b == 0) r = func_800D7914(a, -1);
    } else r = func_800D7914(a, -1);
    func_80082670((char *)a + 0x2A4, 8, r + 9);
    func_80082670((char *)a + 0x2A4, 0x12, r + 9);
    return r;
}

EXTERN_C int func_800D8EF4(void *, int a) {
    for (int i = 0; i < 3; i++) {
        BimMon *p = D_800AFA58[i];
        if (!p && p->f9D4 == a) return 0;
    }
    return 0;
}

EXTERN_C int func_800D8F48() { return 1; }

EXTERN_C void func_800D8F50(BimMon *p) { p->f9CC++; }

EXTERN_C void func_800D8F64() {}

EXTERN_C int func_800D8F6C(BimMon *p) { return p->f9E4; }

EXTERN_C int func_800D8F78(BimMon *p) { return p->f9DC != 0; }

EXTERN_C int func_800D8F84(BimMon *p) { return p->f9E0; }

EXTERN_C void func_800D8F90() {}

EXTERN_C unsigned short func_800D8F98(BimMon *p) {
    func_8008687C(p, 0);
    int k = 0x100;
    return p->s80 = ((long long)(int)p->b7D * (long long)k) / p->b3E;
}

EXTERN_C unsigned short func_800D8FF8(BimMon *p) {
    func_8008687C(p, 0);
    return p->s80 = 0x100LL / p->b3E;
}

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9048);

EXTERN_C int func_800D9170(BimMon *p, unsigned char *q) {
    int t = p->b7E - 0x32;
    int v = q[0x11] - t;
    if (v < 0) v = 0;
    else if (v > 100) v = 100;
    return v;
}

EXTERN_C int func_800D91A4(char *p) {
    int x = func_80089D28(p + 0x3C) & 0xFF;
    int k = 0x10;
    int d = (unsigned char)p[0x3E];
    int v = ((long long)x * k + 0x200) / d;
    if (v > 0xFF) v = 0xFF;
    return v;
}

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9218);

EXTERN_C void func_800D94A8(char *p) {
    *(short *)(p + 0x10) = 0;
    p[0x6D] = 2;
    func_8008655C((short *)(p + 0x58));
    func_800898F0(p + 0x34);
    p[0x7B] = 0; p[0x7A] = 0; p[0x79] = 0; p[0x78] = 0;
}

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D94F4);

EXTERN_C void func_800D96F0() {}

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D96F8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D98E0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9970);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9CB0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9F88);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA0E8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA164);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA2E4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA400);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA5E0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA690);
