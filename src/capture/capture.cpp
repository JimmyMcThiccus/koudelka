#include "common.h"
#include "capture/capture.h"

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B758C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B76E4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7728);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B77D8);

EXTERN_C int D_800B1A5C[];
EXTERN_C void func_800B7B28(unsigned char *p)
{
    if (D_800B1A5C[0]) {
        if (!(*(unsigned short *)p & 0x400)) {
            int c = p[0x49];
            if (c != p[0x48]) {
                c++;
                if (c >= 4)
                    c = 0;
                p[0x49] = c;
            }
        }
        *(unsigned short *)p &= ~0x400;
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7B90);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7C34);

EXTERN_C int D_800B1A5C[];
EXTERN_C void func_800B7DFC(short *p)
{
    *p = 0;
    D_800B1A5C[0] = 0;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7E0C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7E6C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7F10);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8048);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B815C);

EXTERN_C char *func_800B8280(char *p, int v)
{
    char *a = *(char **)(p + 0x124);
    *(int *)(a + 0x1C) = v;
    a[0x6A1] = 3;
    a = *(char **)(p + 0x128);
    *(int *)(a + 0x1C) = v;
    a[0x6A1] = 3;
    return *(char **)(p + 0x124);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B82AC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8360);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8434);

EXTERN_C void func_800B8488(char *p, short a, char b)
{
    *(short *)(p + 0) = a;
    p[2] = b;
    *(short *)(p + 4) = 0x400;
    *(short *)(p + 6) = 0;
    *(short *)(p + 0xC) = 0;
    *(short *)(p + 0xE) = 0;
    *(short *)(p + 0x16) = 0;
    p[0x24] = 1;
    p[0x25] = 3;
    p[0x26] = 3;
    p[0x27] = 0;
    p[0x28] = 0xF;
    p[0x29] = 0x7F;
    p[0x2A] = 6;
    p[0x2B] = 0xF;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B84E0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B85B8);

EXTERN_C void func_800B85EC(VObject *p)
{
    if (((int *)p)[3] == ((int *)p)[1]) {
        VtblEntry *e = &p->vt[7];
        ((void (*)(void *))e->pfn)((char *)p + e->delta);
        ((int *)p)[3] = 0;
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8640);

EXTERN_C void func_800B86E8() {}

EXTERN_C char D_800B6DF4[];
EXTERN_C void **func_800B86F0(void **p)
{
    p[0] = D_800B6DF4;
    p[2] = 0;
    p[3] = 0;
    return p;
}

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6DF0);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6DF4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B870C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8BDC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8CE8);

EXTERN_C void func_8001AA68(void *, int);
EXTERN_C void func_800B8EB4(char *p)
{
    func_8001AA68(p ? p + 4 : 0, 0);
    *(short *)(p + 0x10) = 1;
}

EXTERN_C void func_8001AB50(void *, int);
EXTERN_C void func_800B8EF0(char *p) { func_8001AB50(p ? p + 4 : 0, 0); }

EXTERN_C void func_800B8F20(char *p) { *(int *)(p + 0x21C) = 1; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8F2C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9020);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B90C0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9288);

EXTERN_C int D_800B4CF0[];
EXTERN_C int func_800B93D8(S_800B93D8 *p) { return p->e[D_800B4CF0[0]].h; }

EXTERN_C int func_800B9400(char *p) { return *(int *)(p + 0x58); }

EXTERN_C void func_800B940C(char *p, int v) { *(int *)(p + 0x58) = v; }

EXTERN_C void func_800B9414(S_800B9414 *p, ShortQuad v) { p->q = v; }

EXTERN_C ShortQuad func_800B9444(S_800B9414 *p) { return p->q; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9470);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B94BC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B94FC);

EXTERN_C void func_8008CD1C(int, int);
EXTERN_C void func_80036110(void *, int);
EXTERN_C void func_800B95C0(void *p, int a)
{
    func_8008CD1C(0, 0);
    func_80036110(p, a);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9604);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B96F8);

EXTERN_C void func_80036674(void *);
EXTERN_C void func_800B998C(VObject *p, unsigned char *in)
{
    if ((in[0] & 0x10) || ((in[0] & 1) && (in[1] & 0x40))) {
        VtblEntry *e = &p->vt[8];
        ((void (*)(void *, int))e->pfn)((char *)p + e->delta, in[0]);
        func_80036674(p);
    } else
        ((char *)p)[0x35] = 2;
}

EXTERN_C char D_80035F80[];
EXTERN_C void func_8009CAE0(void *);
EXTERN_C void func_80036554(void *, int);
EXTERN_C void func_800B9A0C(VObject *p, unsigned char a, int b)
{
    signed char *s = (signed char *)p;
    if (a == 2) {
        if (s[0x34] == a) {
            if (s[0x35] == 10) {
                s[0x34] = 5;
                s[0x35] = 0;
                func_8009CAE0(D_80035F80);
            }
        } else
            func_80036554(p, 2);
    } else {
        VtblEntry *e = &p->vt[13];
        ((void (*)(void *, int))e->pfn)((char *)p + e->delta, b);
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9AA0);

EXTERN_C int func_800B9C60() { return -1; }

EXTERN_C int func_800B9C68() { return 0; }

EXTERN_C void func_800370D0(void *);
EXTERN_C void func_8001AA28(void *, int);
EXTERN_C void func_800B9C70(S_800B9E74 *p)
{
    int i;
    VObject *o;
    VtblEntry *e;
    func_800370D0(p);
    for (i = 0; i < 16; i++) {
        o = (VObject *)p->slot[i];
        if (o) {
            // o->~T() (virtual destructor, slot 1, no delete)
            e = &o->vt[1];
            ((void (*)(void *, int))e->pfn)((char *)o + e->delta, 0);
        }
    }
    func_8001AA28(p->slot, 16);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9CF4);

EXTERN_C char *D_800B4D0C;
EXTERN_C void func_8008CD1C(int, int);
EXTERN_C int func_800B9E10(char *a, char b)
{
    char *s = D_800B4D0C;
    if (s == a) {
        func_8008CD1C(0x4400, 0x18);
        *(int *)(s + 0x30) = 0;
        *(int *)(*(char **)(s + 4) + 4) = 0;
        s[0x36] = 1;
        s[0x37] = b;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800B9E74(S_800B9E74 *p, int v, int i)
{
    int old = p->slot[i & 0xF];
    p->slot[i & 0xF] = v;
    return old;
}

EXTERN_C void func_800B9E8C(S_800B9E74 *p, int i) { p->slot[i & 0xF] = 0; }

EXTERN_C char *func_800B9EA0(char *p) { return p + 0x7C; }

EXTERN_C char D_800B6F04[];
EXTERN_C char D_800B6F1C[];
EXTERN_C char D_80012294[];
EXTERN_C char D_80012224[];
EXTERN_C void func_80035304(void *, int);
EXTERN_C void func_800B9EA8(char *p, int in_chrg)
{
    *(char **)(p + 8) = D_800B6F04;
    *(char **)p = D_800B6F1C;
    *(char **)(p + 8) = D_80012294;
    *(char **)p = D_80012224;
    func_80035304(p, 0);
    if (in_chrg & 1)
        operator delete(p);
}

EXTERN_C void *func_800A0D2C(int);
S_800BA17C::S_800BA17C(int size, int bits, char *mem)
{
    int n;
    if (!mem)
        base = (char *)func_800A0D2C(size);
    else
        base = mem;
    n = 1 << bits;
    value = (int)base;
    buf = (int *)func_800A0D2C(n * 4);
    mask = n - 1;
    rd = 0;
    wr = 0;
    buf[0] = 0;
    last = mask;
    buf[last] = (int)(base + size);
}

EXTERN_C void func_800A0D0C(void *);
EXTERN_C void func_800B9FCC(void *self, int in_chrg)
{
    void **p = (void **)self;
    if (p[0])
        func_800A0D0C(p[0]);
    if (p[1])
        func_800A0D0C(p[1]);
    if (in_chrg & 1)
        operator delete(p);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA038);

EXTERN_C void func_800BA0E8(S_800BA17C *p)
{
    p->wr = (p->wr + 1) & p->mask;
    p->buf[p->wr] = p->value;
}

EXTERN_C void func_800BA0E8(S_800BA17C *);
EXTERN_C void func_800BA114(S_800BA17C *p)
{
    int v = p->buf[p->wr];
    if (v)
        p->value = v;
    p->buf[p->wr] = 0;
    func_800BA0E8(p);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA168);

EXTERN_C int func_800BA17C(S_800BA17C *p)
{
    int r = 0;
    if (p->rd != p->wr) {
        r = p->buf[p->rd];
        p->rd++;
        p->rd &= p->mask;
    }
    return r;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA1BC);

EXTERN_C char D_800B6DF4[];
EXTERN_C char D_800B6F8C[];
C_800BA258::C_800BA258(int size, int bits, char *mem) : ring(size, bits, mem)
{
    vt = D_800B6F8C;
}

EXTERN_C char D_800B6F8C[];
EXTERN_C void func_800B9FCC(void *, int);
EXTERN_C void func_800BA2A4(char *p, int in_chrg)
{
    *(char **)p = D_800B6F8C;
    func_800B9FCC(p + 0x10, 0);
    if (in_chrg & 1)
        operator delete(p);
}

EXTERN_C void func_800BA2FC(int *p) { p[8] = (p[8] + 1) & p[7]; }

EXTERN_C void func_800BA114(S_800BA17C *);
EXTERN_C void func_800BA314(char *p) { func_800BA114(p ? (S_800BA17C *)(p + 0x10) : 0); }

EXTERN_C void func_800BA0E8(S_800BA17C *);
EXTERN_C void func_800BA344(char *p) { func_800BA0E8(p ? (S_800BA17C *)(p + 0x10) : 0); }

EXTERN_C void func_800BA038(void *, int);
EXTERN_C void func_800BA168(void *, int);
EXTERN_C void func_800BA374(char *p, int n)
{
    if (*(int *)(p + 0xC) == 0)
        func_800BA038(p ? p + 0x10 : 0, *(int *)(p + 4) * n);
    func_800BA168(p ? p + 0x10 : 0, n);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA3E4);

EXTERN_C char D_800B714C[];
EXTERN_C char D_800B7134[];
EXTERN_C char D_800B7164[];
EXTERN_C void func_80051514(void *, int);
EXTERN_C void func_8001E508(void *, int);
EXTERN_C void func_800BA4AC(char *p, int in_chrg)
{
    *(char **)(p + 0x8C) = D_800B714C;
    *(char **)(p + 0xF8) = D_800B7134;
    *(char **)p = D_800B7164;
    func_80051514(p + 0xF8, 0);
    func_8001E508(p, in_chrg);
}

EXTERN_C void func_800BDFE0(char *);
EXTERN_C void func_800BA514(char *p) { func_800BDFE0(*(char **)(p + 0x168)); }

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6E54);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6E6C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6E7C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6E9C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6F04);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6F1C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6F8C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA538);

EXTERN_C void func_800BB03C(char *p)
{
    int i;
    VObj18 *o = *(VObj18 **)(p + 0x160);
    VtblEntry *e;
    if (o) {
        // delete o (virtual destructor, slot 1)
        e = &o->vt[1];
        ((void (*)(void *, int))e->pfn)((char *)o + e->delta, 3);
    }
    for (i = 0; i < 22; i++) {
        o = ((VObj18 **)(p + 0x108))[i];
        if (o) {
            e = &o->vt[1];
            ((void (*)(void *, int))e->pfn)((char *)o + e->delta, 3);
        }
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BB0D0);

EXTERN_C char D_800B7194[];
EXTERN_C char D_800B717C[];
EXTERN_C char D_800B71AC[];

// EXE base classes: func_8001E40C and func_800514C8 are their constructors
// (aliases, so the calls stay relocations against the EXE's func_ names)
__asm__(".set __10B_8001E40Ciiii, func_8001E40C\n"
        ".set __10B_800514C8, func_800514C8");
struct B_8001E40C {
    void *vt;
    char pad[0x88];
    void *vt8C;
    char pad2[0xF8 - 0x90];
    B_8001E40C(int a, int b, int c, int d);
};
struct B_800514C8 {
    void *vt;
    int f4;
    B_800514C8();
};
struct C_800BB6E8 : B_8001E40C, B_800514C8 {
    int f100;
    C_800BB6E8(int a);
};

C_800BB6E8::C_800BB6E8(int a) : B_8001E40C(a, 2, 0x1000, 0)
{
    vt8C = D_800B7194;
    B_800514C8::vt = D_800B717C;
    B_8001E40C::vt = D_800B71AC;
    f100 = a;
}

EXTERN_C char D_800B7194[];
EXTERN_C char D_800B717C[];
EXTERN_C char D_800B71AC[];
EXTERN_C void func_80051514(void *, int);
EXTERN_C void func_8001E508(void *, int);
EXTERN_C void func_800BB758(char *p, int in_chrg)
{
    *(char **)(p + 0x8C) = D_800B7194;
    *(char **)(p + 0xF8) = D_800B717C;
    *(char **)p = D_800B71AC;
    func_80051514(p + 0xF8, 0);
    func_8001E508(p, in_chrg);
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C void func_800BB7C0(char *p)
{
    char *o;
    *(short *)(p + 0x104) = 0;
    o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 0xA;
    *(void **)(o + 0xC) = 0;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BB838);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BBBA4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BC3B0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BC650);

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *D_800A4578[];
EXTERN_C void func_800232A0(void *, void *);
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BCCC0(char *p, unsigned char *in)
{
    char *o;
    if (~in[0x1A] & 8) {
        func_800232A0(D_800A4578[0] + 0x154, p);
        o = func_8001CA10(0x14);
        *(char **)o = D_80010178;
        *(int *)(o + 4) = 0;
        *(char **)o = D_80010300;
        *(short *)(o + 8) = 2;
        *(short *)(o + 0xA) = 2;
        *(int *)(o + 0x10) = 5001;
        *(void **)(o + 0xC) = 0;
        *(char **)o = D_800102D0;
        func_8001EFE4(*(void **)(p + 0x108), o);
    }
    return 1;
}

EXTERN_C int func_800BCD60() { return 1; }

EXTERN_C char *D_800A4578[];
EXTERN_C void func_800230E8(void *, void *);
EXTERN_C void func_800BCD68(void *p) { func_800230E8(D_800A4578[0] + 0x154, p); }

EXTERN_C void func_800BCD94(char *p) { *(int *)(*(char **)(p + 0x114) + 0x1020) = 1; }

EXTERN_C void func_800BCDA4(S_800BCDA4 *p, void *v)
{
    if (v) {
        p->list0[p->n0] = v;
        p->n0++;
    }
}

EXTERN_C void func_800BCDD8(S_800BCDA4 *p, void *v)
{
    if (v) {
        p->list1[p->n1] = v;
        p->n1++;
    }
}

EXTERN_C char D_80010348[];
EXTERN_C char D_800100F8[];
EXTERN_C char D_80010198[];
EXTERN_C char D_800101C0[];
EXTERN_C char D_800101B0[];
EXTERN_C char D_800B7274[];
EXTERN_C char D_800B728C[];
EXTERN_C char D_800B729C[];
EXTERN_C char D_800127FC[];

struct A_800BCE0C {
    void *vtA;
    A_800BCE0C() { vtA = D_80010348; }
};
struct B1_800BCE0C {
    void *vt1;
    B1_800BCE0C() { vt1 = D_800100F8; }
};
struct B2_800BCE0C {
    void *vt2;
    B2_800BCE0C() { vt2 = D_80010198; }
};
struct B_800BCE0C : B1_800BCE0C, B2_800BCE0C {
    int f8;
    short fC, fE, f10, f12;
    B_800BCE0C(int a, short b, short c, short d, short e)
    {
        vt2 = D_800101C0;
        vt1 = D_800101B0;
        f8 = a;
        fC = c;
        fE = d;
        f10 = e;
        f12 = b;
    }
};
struct T_800BCE0C {
    void *vt;
    int f4, f8, fC, f10;
    char f14;
    T_800BCE0C(int a)
    {
        vt = D_800127FC;
        f8 = 6;
        f4 = a;
        f14 = 0;
        fC = 10;
        f10 = 0;
    }
};
struct C_800BCE0C : A_800BCE0C, B_800BCE0C {
    int pad18[3];
    int f24;
    int f28, f2C;
    int pad30[5];
    int f44;
    char pad48[0x2914 - 0x48];
    T_800BCE0C *f2914;
    int f2918;
    int f291C, f2920;
    C_800BCE0C(int a, int b, int c);
};
struct S_800BCF18;
EXTERN_C void func_800BCF18(S_800BCF18 *);

C_800BCE0C::C_800BCE0C(int a, int b, int c) : B_800BCE0C(c, 2, 1, 2, 6)
{
    vt2 = D_800B7274;
    vt1 = D_800B728C;
    vtA = D_800B729C;
    f28 = 0;
    f2C = 0;
    f44 = c;
    f291C = a;
    f2920 = b;
    f24 = 0;
    f2914 = new T_800BCE0C(c);
    f2918 = 0;
    func_800BCF18((S_800BCF18 *)this);
}

EXTERN_C void func_80035EB4(void *);
EXTERN_C void func_80035DE0(void *);
EXTERN_C S_800B9E74 *func_800B94FC(void *, int, int);
EXTERN_C bool func_800B9CF4(S_800B9E74 *, int, int);
EXTERN_C int func_800B9E74(S_800B9E74 *p, int v, int i);

struct S_800BCF18 {
    char pad0[0x18];
    C_800BA258 *f18;
    C_800BA258 *f1C;
    C_800BDD00 *f20;
    S_800B9E74 *f24;
    char pad28[8];
    int f30, f34, f38, f3C;
    short f40;
    char pad42[6];
    int f48, f4C, f50, f54;
    short f58;
    char pad5A[0x1020 - 0x5A];
    int f1020;
    char pad1024[0x28F4 - 0x1024];
    int f28F4, f28F8, f28FC, f2900;
    int f2904, f2908, f290C, f2910;
    void *f2914;
    int f2918;
    int f291C;
    unsigned int f2920;
};

EXTERN_C void func_800BCF18(S_800BCF18 *p)
{
    if (p->f2918)
        func_80035EB4(p->f2914);
    if (!p->f24)
        p->f24 = func_800B94FC(operator new(0xA8), 1, 1);
    if (!func_800B9CF4(p->f24, p->f291C, p->f2920 / 0x800 * 4 / 5 - 0x28)) {
        p->f2918 = 1;
        func_80035DE0(p->f2914);
        return;
    }
    p->f2918 = 0;
    p->f18 = new C_800BA258(0x11000, 5, 0);
    p->f1C = new C_800BA258(0x5000, 5, 0);
    p->f20 = new C_800BDD00;
    func_800B9E74(p->f24, (int)p->f18, 1);
    func_800B9E74(p->f24, (int)p->f1C, 2);
    func_800B9E74(p->f24, (int)p->f20, 4);
    p->f58 = p->f40 = 0;
    p->f30 = p->f34 = p->f38 = p->f3C = 0;
    p->f48 = p->f4C = p->f50 = p->f54 = 0;
    p->f28F4 = p->f28F8 = p->f28FC = p->f2900 = 0;
    p->f2904 = p->f2908 = p->f290C = p->f2910 = 0;
    p->f1020 = 0;
}

EXTERN_C char D_80010348[];
EXTERN_C char D_800100F8[];
EXTERN_C char D_80010198[];
EXTERN_C char D_800101C0[];
EXTERN_C char D_800101B0[];
EXTERN_C char D_800B7274[];
EXTERN_C char D_800B728C[];
EXTERN_C char D_800B729C[];

struct A_800BD0A8 {
    void *vtA;
    A_800BD0A8() { vtA = D_80010348; }
};
struct B1_800BD0A8 {
    void *vt1;
    B1_800BD0A8() { vt1 = D_800100F8; }
};
struct B2_800BD0A8 {
    void *vt2;
    B2_800BD0A8() { vt2 = D_80010198; }
};
struct B_800BD0A8 : B1_800BD0A8, B2_800BD0A8 {
    int f8;
    short fC, fE, f10, f12;
    B_800BD0A8(int a, short b, short c, short d, short e)
    {
        vt2 = D_800101C0;
        vt1 = D_800101B0;
        f8 = a;
        fC = c;
        fE = d;
        f10 = e;
        f12 = b;
    }
};
struct C_800BD0A8 : A_800BD0A8, B_800BD0A8 {
    int pad[4];
    int f28, f2C;
    C_800BD0A8(int u, int a, short b, short c, short d, short e);
};

C_800BD0A8::C_800BD0A8(int u, int a, short b, short c, short d, short e) : B_800BD0A8(a, b, c, d, e)
{
    vt2 = D_800B7274;
    vt1 = D_800B728C;
    vtA = D_800B729C;
    f28 = 0;
    f2C = 0;
}

EXTERN_C char D_800101C0[];
EXTERN_C char D_800101B0[];
EXTERN_C char D_800B7274[];
EXTERN_C char D_800B728C[];
EXTERN_C char D_800B729C[];
EXTERN_C void func_800BA2A4(char *p, int in_chrg);
EXTERN_C void func_80036D8C(void *);
EXTERN_C void func_800BDD90(char *p, int in_chrg);
EXTERN_C void func_80039C88(void *, int);
EXTERN_C void func_800198AC(void *, int);
EXTERN_C void func_8001D024(void *, int);

// destructor of the class built by func_800BD0A8 / func_800BCE0C
EXTERN_C void func_800BD13C(char *p, int in_chrg)
{
    int i;
    *(char **)(p + 8) = D_800B7274;
    *(char **)(p + 4) = D_800B728C;
    *(char **)p = D_800B729C;
    operator delete(*(void **)(p + 0x2914));
    if (*(char **)(p + 0x18))
        func_800BA2A4(*(char **)(p + 0x18), 3);
    if (*(char **)(p + 0x1C))
        func_800BA2A4(*(char **)(p + 0x1C), 3);
    if (*(void **)(p + 0x24))
        func_80036D8C(*(void **)(p + 0x24));
    if (*(void **)(p + 0x20))
        func_800BDD90(*(char **)(p + 0x20), 3);
    for (i = 0; i < 4; i++) {
        if (((void **)(p + 0x2904))[i])
            func_80039C88(((void **)(p + 0x2904))[i], ((int *)(p + 0x28F4))[i]);
    }
    {
        char *b = p + 4;
        *(char **)(b + 4) = D_800101C0;
        *(char **)b = D_800101B0;
        func_800198AC(b, 0);
    }
    func_8001D024(p, in_chrg);
}

EXTERN_C void func_8001AA68(void *, int);
EXTERN_C void func_800BD268(char *p)
{
    func_8001AA68(p ? p + 4 : 0, 0);
    *(short *)(p + 0x10) = 1;
}

EXTERN_C void func_8001AB50(void *, int);
EXTERN_C void func_800BD2A4(char *p) { func_8001AB50(p ? p + 4 : 0, 0); }

EXTERN_C void func_800BD2D4(char *p) { *(int *)(p + 0x2C) = 1; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD2E0);

EXTERN_C char D_800A4544[];
EXTERN_C char D_80010178[];
EXTERN_C char D_80010338[];
EXTERN_C void func_8001D150(void *, void *);
EXTERN_C int func_800B9E10(char *a, char b);

struct T_800BD534 {
    void *vt;
    int f4;
    void *f8;
    short fC;
    int f10;
};

EXTERN_C int func_800BD534(char *p)
{
    char *l;
    T_800BD534 *o;
    if (*(char **)(p + 0x24)) {
        *(int *)(p + 0x5C) = 0;
        func_800B9E10(*(char **)(p + 0x24), 0);
        l = D_800A4544;
        o = (T_800BD534 *)operator new(0x14);
        o->vt = D_80010178;
        o->f4 = 0;
        o->vt = D_80010338;
        o->f8 = p;
        o->fC = 0x80;
        o->f10 = 1;
        func_8001D150(l, o);
        return 1;
    }
    return 0;
}

EXTERN_C int func_800BD5D0(S_800BD5D0 *p, int v)
{
    if (p->n < 4) {
        p->list[p->n++] = v;
        return 0;
    }
    return 1;
}

EXTERN_C void func_800BD604(S_800BD604 *p, Short12 *v) { p->v = *v; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD66C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD800);

EXTERN_C void func_800BDC64(char *p) { *(int *)(p + 0x1020) = 1; }

EXTERN_C int func_800BDC70(S_800BDC70 *p, int *src, short n)
{
    int i;
    for (i = 0; i < n; i++)
        p->list[p->n++] = *src++;
    return 1;
}

EXTERN_C int func_800BDCB8(S_800BD5D0 *p, int *src, short n)
{
    int i;
    for (i = 0; i < n; i++)
        p->list[p->n++] = *src++;
    return 1;
}

EXTERN_C char D_800B72BC[];
EXTERN_C void func_800B7C34(void *, int, int, int);
EXTERN_C void *func_800A0D2C(int);
EXTERN_C void func_800B758C(void *, void *);
EXTERN_C void func_800B7E0C(void *, int);
C_800BDD00::C_800BDD00()
{
    func_800B7C34(m, 0x1000, 0x60, 0x40);
    buf = func_800A0D2C(0x3F00);
    func_800B758C(m, buf);
    func_800B7E0C(m, 0);
    f140 = 0;
    f144 = 0;
}

EXTERN_C char D_800B72BC[];
EXTERN_C void func_800B8360(void *);
EXTERN_C void func_800B76E4(void *);
EXTERN_C void func_800B7DFC(short *p);
EXTERN_C void func_800A0D0C(void *);
EXTERN_C void func_800BDD90(char *p, int in_chrg)
{
    *(char **)p = D_800B72BC;
    func_800B8360(p + 0x10);
    func_800B76E4(p + 0x10);
    func_800B7DFC((short *)(p + 0x10));
    if (*(void **)(p + 0x13C))
        func_800A0D0C(*(void **)(p + 0x13C));
    if (in_chrg & 1)
        operator delete(p);
}

EXTERN_C int func_800B7728(void);
EXTERN_C int func_800BDE18(char *p, int n)
{
    int r = 0;
    if (n) {
        if (*(int *)(p + 0x144))
            r = *(int *)(p + 0x144);
        else
            r = *(int *)(p + 0x140) = func_800B7728();
        *(int *)(p + 0x144) = r + n;
    }
    return r;
}

EXTERN_C void func_800B77D8(void *);
EXTERN_C void func_800BDE78(char *p)
{
    *(int *)(p + 0x140) = 0;
    *(int *)(p + 0x144) = 0;
    func_800B77D8(p);
}

EXTERN_C void func_800BDE9C() {}

EXTERN_C void func_800BDEA4(char *p) { *(int *)(p + 0x144) = *(int *)(p + 0x140); }

EXTERN_C char D_800B7334[];
EXTERN_C char D_800B734C[];
EXTERN_C int D_800C3210[];
C_800BDEB0::C_800BDEB0(int a) : C_800BF80C(a)
{
    vt2 = D_800B7334;
    vt = D_800B734C;
    D_800C3210[0] = (int)this;
    f604 = 0;
    f608 = 0;
    f60C = 1;
    f610 = 0;
    f614 = 1;
    f624 = 0;
    f628 = 0;
    f62C = 0;
    f630 = 0;
    f620 = a;
    f634 = 0;
    f638 = 0;
}

EXTERN_C char D_800B7334[];
EXTERN_C char D_800B734C[];
EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C void func_800BF87C(char *p, int in_chrg);
EXTERN_C void func_800BDF38(char *p, int in_chrg)
{
    char *o;
    *(char **)(p + 0x8C) = D_800B7334;
    *(char **)p = D_800B734C;
    o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 9;
    *(int *)(o + 0x10) = 10001;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(*(void **)(p + 0x620), o);
    func_800BF87C(p, in_chrg);
}

EXTERN_C void **func_800BFCB0(void **p, void *a, int b, void *c, int d);
EXTERN_C void func_800BFD10(void *);
EXTERN_C void func_800BDFE0(char *p)
{
    *(short *)(p + 0x3D0) = 0;
    *(short *)(p + 0x3D2) = 0;
    func_800BFD10(func_800BFCB0((void **)operator new(0x14), p, 0xC9, 0, 200));
}

EXTERN_C int func_8001A6E8(void *);
EXTERN_C void func_800C2CD4(S_800C2D5C *p, unsigned char *c);

struct A_800BE034 {
    VObject **data;
    int n;
};
struct It_800BE034 {
    A_800BE034 *arr;
    int i;
    VObject *next()
    {
        VObject *x = 0;
        if (i < arr->n)
            x = arr->data[i++];
        return x;
    }
};
struct N_800BE034 {
    int pad;
    N_800BE034 *next;
    char pad2[4];
    It_800BE034 it;
    char pad3[0x30 - 0x14];
    short cnt;
};

EXTERN_C int func_800BE034(void *pv, Rgb *out)
{
    char *p = (char *)pv;
    N_800BE034 *l = (N_800BE034 *)(p + 0x448);
    N_800BE034 *e;
    int n = func_8001A6E8(l->next);
    if (!n)
        return 0;
    e = l->next;
    while (1) {
        It_800BE034 *it = &e->it;
        int c;
        if (!n)
            break;
        it->i = 0;
        c = e->cnt;
        while (1) {
            VObject *x;
            VtblEntry *v;
            if (!c)
                break;
            x = it->next();
            func_800C2CD4((S_800C2D5C *)x, (unsigned char *)out);
            v = &x->vt[7];
            ((void (*)(void *))v->pfn)((char *)x + v->delta);
            c--;
        }
        e = e->next;
        n--;
    }
    return 1;
}

EXTERN_C int func_8001A6E8(void *);
EXTERN_C void func_800C2D5C(S_800C2D5C *p, unsigned char *out);

struct A_800BE128 {
    S_800C2D5C **data;
    int n;
};
struct It_800BE128 {
    A_800BE128 *arr;
    int i;
    S_800C2D5C *next()
    {
        S_800C2D5C *x;
        if (i < arr->n)
            x = arr->data[i++];
        else
            x = 0;
        return x;
    }
};
struct N_800BE128 {
    int pad;
    N_800BE128 *next;
    char pad2[4];
    It_800BE128 it;
    char pad3[0x30 - 0x14];
    short cnt;
};

EXTERN_C int func_800BE128(char *p, unsigned char *out)
{
    N_800BE128 *l = (N_800BE128 *)(p + 0x448);
    N_800BE128 *e;
    It_800BE128 *it;
    if (!func_8001A6E8(l->next))
        return 0;
    e = l->next;
    it = &e->it;
    it->i = 0;
    int c = e->cnt;
    if (c) {
        func_800C2D5C(it->next(), out);
        c = 1;
    }
    return c;
}

EXTERN_C void func_800BE1C4(char *p)
{
    *(int *)(p + 0x484) = -((*(short *)(p + 0x278) - 320) / 2);
    *(int *)(p + 0x488) = -((*(short *)(p + 0x27A) - 240) / 2);
}

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7134);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B714C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7164);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B717C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7194);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B71AC);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B71C4);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B71F4);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7244);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B725C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7274);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B728C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B729C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B72BC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BE204);

EXTERN_C void func_800BE5E4(char *p) { *(int *)(p + 0x610) = 0; }

EXTERN_C void func_800BE5EC(char *p) { *(int *)(p + 0x610) = 1; }

EXTERN_C void func_800C0194(void *, void *, void *, void *, void *, void *);
EXTERN_C void func_800BE1C4(char *p);
EXTERN_C void func_800C1814(S_800C1814 *p);
EXTERN_C void func_800C15F4(void *);
EXTERN_C void func_800C1BA4(void *);
EXTERN_C void func_800C0F38(void *, void *);
EXTERN_C int func_800C0958(void *, void *);
EXTERN_C int func_8001A6E8(void *);
EXTERN_C void func_8002DA94(void *, void *);
EXTERN_C int func_800BE5F8(char *p)
{
    char *d = *(char **)(p + 0x4D4);
    N_800BE8E0 *e;
    int n;
    p[0xF8] = d[8];
    p[0xF9] = d[9];
    func_800C0194(p, d + 0xC, p + 0x428, p + 0x438, p + 0x3E0, p + 0x408);
    func_800BE1C4(p);
    func_800C1814((S_800C1814 *)p);
    func_800C15F4(p);
    func_800C1BA4(p);
    func_800C0F38(p, p + 0x448);
    func_800C0958(p, p + 0x448);
    e = (N_800BE8E0 *)(p + 0x448);
    n = func_8001A6E8(e->next);
    while (1) {
        e = e->next;
        if (n == 0)
            break;
        func_8002DA94(*(void **)(*(char **)(p + 0x270) + 0x254), e->data);
        n--;
    }
    *(int *)(p + 0x614) = 0;
    return 1;
}

EXTERN_C void func_800C0030(void *, void *, int);
EXTERN_C int func_800BE6D8(char *p)
{
    char *a = *(char **)(p + 0x4DC);
    N_800BE6D8 *e;
    func_800C0030(p, a + 0xC, *(short *)(a + 4));
    e = *(N_800BE6D8 **)(p + 0x490);
    while (1) {
        VObject *o = &e->obj;
        if (!e)
            break;
        VtblEntry *v = &o->vt[6];
        ((void (*)(void *))v->pfn)((char *)o + v->delta);
        e = e->next;
    }
    return 1;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BE748);

EXTERN_C int func_8001A6E8(void *);
EXTERN_C void func_8002DD34(void *, void *, int);
EXTERN_C void func_800BE8E0(char *p)
{
    N_800BE8E0 *e = (N_800BE8E0 *)(p + 0x448);
    int n = func_8001A6E8(e->next);
    while (1) {
        e = e->next;
        if (n == 0)
            break;
        n--;
        func_8002DD34(*(void **)(*(char **)(p + 0x270) + 0x254), e->data, 0);
    }
    *(int *)(p + 0x614) = 1;
}

EXTERN_C int func_8001A6E8(void *);
EXTERN_C void func_8002DC34(void *, void *, int);
EXTERN_C void func_80019CFC(void *, void *);
EXTERN_C void func_80019A6C(void *, int, int);

struct V_800BE954 {
    VObject **data;
    int n;
};
struct N_800BE954 {
    int pad;
    N_800BE954 *next;
    char pad2[4];
    char sub[0x30 - 0xC];
    int f30;
};

EXTERN_C int func_800BE954(void *pv, int n)
{
    N_800BE954 *l = (N_800BE954 *)((char *)pv + 0x448);
    int cnt = 0;
    int k = func_8001A6E8(l->next);
    char *q = (char *)pv + 0x5B0;
    N_800BE954 *e = l->next;
    while (1) {
        char *s = e->sub;
        if (!k)
            break;
        while (1) {
            V_800BE954 *v = s ? *(V_800BE954 **)s : 0;
            char *b;
            V_800BE954 *vv;
            VObject *x;
            if (!v->n)
                break;
            b = s ? s + 8 : 0;
            vv = b ? *(V_800BE954 **)b : 0;
            if (vv->n)
                x = vv->data[vv->n - 1];
            else
                x = 0;
            if (!x)
                continue;
            func_8002DC34(*(void **)(*(char **)((char *)pv + 0x270) + 0x254), x, 0);
            b = s ? s + 8 : 0;
            func_80019CFC(b ? *(V_800BE954 **)b : 0, x);
            {
                V_800BE954 *w = q ? *(V_800BE954 **)((char *)pv + 0x5B0) : 0;
                func_80019A6C(w, (int)x, w->n);
            }
            e->f30--;
            cnt++;
            if (cnt == n)
                return cnt;
        }
        e = e->next;
        k--;
    }
    return cnt;
}

EXTERN_C void func_80019CFC(void *, void *);

struct V_800BEAC0 {
    VObject **data;
    int n;
};

EXTERN_C int func_800BEAC0(void *pv, int n)
{
    int i = 0;
    char *q = (char *)pv + 0x5B0;
    while (1) {
        char *b;
        V_800BEAC0 *v;
        VObject *x;
        VtblEntry *e;
        if (!(i < n))
            break;
        b = q ? (char *)pv + 0x5B8 : 0;
        v = b ? *(V_800BEAC0 **)b : 0;
        if (v->n)
            x = v->data[v->n - 1];
        else
            x = 0;
        if (!x)
            break;
        b = q ? (char *)pv + 0x5B8 : 0;
        func_80019CFC(b ? *(V_800BEAC0 **)b : 0, x);
        e = &x->vt[1];
        ((void (*)(void *, int))e->pfn)((char *)x + e->delta, 3);
        i++;
    }
    return i;
}

EXTERN_C void func_800BEBB0(char *p)
{
    ObjSlot *q = (ObjSlot *)(p + 0x48C);
    if (q->obj) {
        // delete q->obj (virtual destructor, slot 1)
        VtblEntry *e = &q->obj->vt[1];
        ((void (*)(void *, int))e->pfn)((char *)q->obj + e->delta, 3);
        q->obj = 0;
    }
}

static inline void clear_800BEC00(ObjSlot *q)
{
    if (q->obj) {
        VtblEntry *e = &q->obj->vt[1];
        ((void (*)(void *, int))e->pfn)((char *)q->obj + e->delta, 3);
        q->obj = 0;
    }
}

EXTERN_C void func_800BEC00(void *pv)
{
    clear_800BEC00((ObjSlot *)((char *)pv + 0x3E0));
    clear_800BEC00((ObjSlot *)((char *)pv + 0x408));
    clear_800BEC00((ObjSlot *)((char *)pv + 0x428));
    clear_800BEC00((ObjSlot *)((char *)pv + 0x438));
    clear_800BEC00((ObjSlot *)((char *)pv + 0x448));
    *(short *)((char *)pv + 0x3D0) = 0;
    *(short *)((char *)pv + 0x3D2) = 0;
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF720(char *p, char v);
EXTERN_C void func_800BED34(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    if (e && e[0xC] == 0)
        func_800BF720((char *)e, 1);
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C ShortPair func_800C0B7C(void *, int);
EXTERN_C void func_800C0D14(void *, ShortPair);

struct S_800BED7C {
    char pad[0x10];
    int *base;
    int *ptr;
    int i;
};

EXTERN_C void func_800BED7C(void *p, short id)
{
    S_800BED7C *e = (S_800BED7C *)func_800C0CB0(p, id);
    ShortPair t;
    if (e) {
        e->ptr = e->base;
        e->i = 0;
        t = func_800C0B7C(p, id);
        if (t.b != 0x1000)
            func_800C0D14(p, ShortPair(t));
    }
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF6E8(S_800BF6E8 *p);
EXTERN_C ShortPair func_800C0B7C(void *, int);
EXTERN_C void func_800C0D14(void *, ShortPair);
EXTERN_C void func_800BEE24(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    ShortPair t;
    if (e) {
        func_800BF6E8((S_800BF6E8 *)e);
        t = func_800C0B7C(p, id);
        if (t.b != 0x1000)
            func_800C0D14(p, ShortPair(t));
    }
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF750(signed char *p);
EXTERN_C void func_800BEEC8(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    if (e && e[0xC] == 1)
        func_800BF750(e);
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF73C(char *p);
EXTERN_C void func_800BEF10(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    int ok = 0;
    if (e && e[0x20] == 1)
        ok = e[0xC] != 0;
    if (ok)
        func_800BF73C((char *)e);
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF7A8(char *p, int v);
EXTERN_C void func_800BEF6C(void *p, short id, int v)
{
    signed char *e = func_800C0CB0(p, id);
    if (e)
        func_800BF7A8((char *)e, v);
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C int func_800BEFA8(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    if (e)
        return e[0xC];
    return 0xFF;
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C int func_800BEFE0(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    if (e)
        return e[0x20];
    return 0xFF;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C void func_800BF018(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 4;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
}

EXTERN_C void func_800BF08C() {}

EXTERN_C void func_800BEC00(void *);
EXTERN_C int func_800BE5F8(char *p);
EXTERN_C int func_800BE034(void *, Rgb *);
EXTERN_C void func_800BEBB0(char *p);
EXTERN_C int func_800BE6D8(char *p);
EXTERN_C void func_80036D8C(void *);
EXTERN_C void func_800BF094(char *p)
{
    Rgb c;
    func_800BEC00(p);
    func_800BE5F8(p);
    c.r = 0x80;
    c.g = 0x80;
    c.b = 0x80;
    func_800BE034(p, &c);
    func_800BEBB0(p);
    func_800BE6D8(p);
    func_80036D8C(*(void **)(p + 0x624));
    *(void **)(p + 0x624) = 0;
}

EXTERN_C int func_800BF0FC(S_800BF0FC *p, IntPair *out) { *out = p->p0; return 1; }

EXTERN_C int func_800BF114(S_800BF0FC *p, IntPair *out) { *out = p->p1; return 1; }

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF12C(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 1;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF1A4(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 0xB;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF21C(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 0xD;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF294(void *p, void *owner, int n)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 9;
    *(int *)(o + 0x10) = n;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(owner, o);
    return 1;
}

EXTERN_C void **func_800BFCB0(void **p, void *a, int b, void *c, int d);
EXTERN_C void func_800BFD10(void *);
EXTERN_C int func_800BF324(void *p)
{
    func_800BFD10(func_800BFCB0((void **)operator new(0x14), p, 0xCA, 0, 200));
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF374(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 0xC;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF3EC(char *p, int a, int b)
{
    char *o;
    *(int *)(p + 0x618) = a;
    *(int *)(p + 0x61C) = b;
    o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 6;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C void *func_80066FB0(void *, void *, int, int, int);
EXTERN_C void func_800670A4(void *);
EXTERN_C int func_800BF46C(char *p)
{
    func_800670A4(func_80066FB0(operator new(0x18), p, 0x6C, *(int *)(p + 0x620), 100));
    return 1;
}

EXTERN_C void *func_80066FB0(void *, void *, int, int, int);
EXTERN_C void func_800670A4(void *);
EXTERN_C void func_800BF4BC(char *p)
{
    func_800670A4(func_80066FB0(operator new(0x18), p, 0x6E, *(int *)(p + 0x620), 100));
}

EXTERN_C int D_800C3210[];
EXTERN_C int func_800BF508() { return D_800C3210[0]; }

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7364[];
EXTERN_C char *func_800BF518(char *p)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800B7364;
    *(short *)(p + 8) = 0;
    *(short *)(p + 0xA) = 0;
    p[0xC] = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1C) = 0;
    p[0x20] = 1;
    return p;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7364[];
EXTERN_C void *func_800A0D2C(int);
C_800BF560::C_800BF560(short a, short n, char c)
{
    vt = D_80010178;
    f4 = 0;
    vt = D_800B7364;
    fA = n;
    f8 = a;
    fC = c;
    f14 = f10 = (int *)func_800A0D2C(n * 4);
    f18 = 0;
    f1C = 0;
    f24 = 0;
    f20 = 1;
}

EXTERN_C char D_800B7364[];
EXTERN_C void func_800A0D0C(void *);
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800BF5D8(char *p, int in_chrg)
{
    *(char **)p = D_800B7364;
    if (*(void **)(p + 0x10))
        func_800A0D0C(*(void **)(p + 0x10));
    func_8001A610(p, in_chrg);
}

EXTERN_C void func_800BF62C(S_800BF62C *p, short a, short b)
{
    if (p->count < p->n) {
        ShortPair *e = &p->list[p->count];
        e->a = a;
        e->b = b;
        p->count++;
    }
}

EXTERN_C void func_800BF73C(char *p);
EXTERN_C int func_800BF670(C_800BF560 *p)
{
    if (p->f18 == p->fA - 1) {
        if (p->f20 != 1)
            func_800BF73C((char *)p);
        else {
            p->f18 = 0;
            p->f14 = p->f10;
        }
        return 0;
    }
    p->f18++;
    p->f14++;
    return 1;
}

EXTERN_C void func_800BF6E8(S_800BF6E8 *p)
{
    int last = p->n - 1;
    while (1) {
        if (p->i == last)
            return;
        p->i++;
        p->ptr++;
    }
}

EXTERN_C void func_800BF720(char *p, char v)
{
    char old = p[0xC];
    p[0xC] = v;
    *(int *)(p + 0x18) = 0;
    p[0x20] = old;
    *(int *)(p + 0x14) = *(int *)(p + 0x10);
}

EXTERN_C void func_800BF73C(char *p)
{
    char v = p[0x20];
    p[0x20] = 1;
    p[0xC] = v;
}

EXTERN_C void func_800BF750(signed char *p)
{
    if (p[0x20] == 1 && p[0xC] == 1)
        p[0xC] = 2;
}

EXTERN_C void func_800BF77C(signed char *p)
{
    if (p[0x20] == 1 && p[0xC] == 2)
        p[0xC] = 1;
}

EXTERN_C void func_800BF7A8(char *p, int v)
{
    p[0xC] = v;
    p[0x20] = 1;
}

EXTERN_C int func_800BF7B8(char *p) { return *(int *)(p + 0x14); }

EXTERN_C void func_800BF7C4(char *p)
{
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x14) = *(int *)(p + 0x10);
}

EXTERN_C int func_800BF7D4(signed char *p) { return p[0x20]; }

EXTERN_C void func_800BF7E0(char *p, char v) { p[0x20] = v; }

EXTERN_C int func_800BF7E8(signed char *p) { return p[0xC]; }

EXTERN_C int func_800BF7F4(short *p) { return p[5]; }

EXTERN_C int func_800BF800(short *p) { return p[4]; }

EXTERN_C char D_800B7374[];
EXTERN_C char D_800B738C[];
C_800BF80C::C_800BF80C(int a) : C_800BFC28(a)
{
    vt2 = D_800B7374;
    vt = D_800B738C;
    v.init(0x10);
    f600 = 0;
}

EXTERN_C char D_800B7374[];
EXTERN_C char D_800B738C[];
EXTERN_C void func_80019920(void *, int);
EXTERN_C void func_800BFC68(char *p, int in_chrg);
EXTERN_C void func_800BF87C(char *p, int in_chrg)
{
    *(char **)(p + 0x8C) = D_800B7374;
    *(char **)p = D_800B738C;
    func_80019920(*(void **)(p + 0x5E0), 0);
    func_800BFC68(p, in_chrg);
}

EXTERN_C void func_80019A6C(void *, int, int);
EXTERN_C void func_800BF8D8(char *p, int a)
{
    int **c = (int **)(p + 0x5E0);
    int *vb = c ? *c : 0;
    func_80019A6C(vb, a, vb[1]);
}

EXTERN_C void *func_80019F64(void *, int);
EXTERN_C void *func_800BF914(char *p, int i)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    void *r = func_80019F64(b ? *b : 0, i);
    *(void **)(p + 0x600) = r;
    if (!r)
        return 0;
    return r;
}

EXTERN_C int func_800BF96C(char *p)
{
    int **a = (int **)(p + 0x5E0);
    int *vb = a ? *a : 0;
    return vb[1];
}

struct Int4_800BF98C {
    int x, y, z, w;
};
struct O_800BF98C {
    char pad[0x34];
    Int4_800BF98C v;
    Int4_800BF98C get()
    {
        Int4_800BF98C *q = &v;
        int x = q->x, y = q->y, z = q->z, w = q->w;
        Int4_800BF98C r;
        r.x = x;
        r.y = y;
        r.z = z;
        r.w = w;
        return r;
    }
};
EXTERN_C void *func_80019F64(void *, int);
EXTERN_C int func_800BF98C(char *p, int i, Int4_800BF98C *out)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    char *r = (char *)func_80019F64(b ? *b : 0, i);
    *(char **)(p + 0x600) = r;
    if (!r)
        return 0;
    *out = (*(O_800BF98C **)(r + 0x1B8))->get();
    return 1;
}

struct Int4_800BFA5C { int v[4]; };
EXTERN_C void *func_80019F64(void *, int);
EXTERN_C int func_800BFA5C(char *p, int i, Int4_800BFA5C *out)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    char *r = (char *)func_80019F64(b ? *b : 0, i);
    *(char **)(p + 0x600) = r;
    if (!r)
        return 0;
    *out = *(Int4_800BFA5C *)(*(char **)(r + 0x1B8) + 0x34);
    return 1;
}

struct Int4_800BFAE8 { int v[4]; };
EXTERN_C void *func_80019F64(void *, int);
EXTERN_C void func_80039DD8(void *);
EXTERN_C int func_800BFAE8(char *p, int i, Int4_800BFAE8 *in)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    char *r = (char *)func_80019F64(b ? *b : 0, i);
    *(char **)(p + 0x600) = r;
    if (!r)
        return 0;
    char *o = *(char **)(r + 0x1B8);
    *(Int4_800BFAE8 *)(o + 0x34) = *in;
    func_80039DD8(o);
    return 1;
}

EXTERN_C int func_800BFB78(char *p, int i, short *out)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    char *r = (char *)func_80019F64(b ? *b : 0, i);
    *(char **)(p + 0x600) = r;
    if (!r) {
        *out = -1;
        return 0;
    }
    *out = *(short *)(r + 0x1BC);
    return 1;
}

EXTERN_C void func_80019D40(void *);
EXTERN_C void func_800BFBEC(char *p)
{
    int **a = (int **)(p + 0x5E0);
    func_80019D40(a ? *a : 0);
}

EXTERN_C char *func_800BFC20(char *p) { return p + 0x5E0; }

EXTERN_C char D_800B73A4[];
EXTERN_C char D_800B73BC[];
C_800BFC28::C_800BFC28(int a) : C_800BFE58(a)
{
    vt2 = D_800B73A4;
    vt = D_800B73BC;
}

EXTERN_C char D_800B73A4[];
EXTERN_C char D_800B73BC[];
EXTERN_C void func_800BFF8C(void *, int);
EXTERN_C void func_800BFC68(char *p, int in_chrg)
{
    *(char **)(p + 0x8C) = D_800B73A4;
    *(char **)p = D_800B73BC;
    func_800BFF8C(p, in_chrg);
}

EXTERN_C IntPair *func_800BFC9C(S_800BFC9C *p)
{
    p->tag.a = 0xE0000000;
    p->tag.b = 0;
    return &p->tag;
}

EXTERN_C char D_800B73D4[];
EXTERN_C void **func_800BFCB0(void **p, void *a, int b, void *c, int d)
{
    p[0] = D_800B73D4;
    p[1] = a;
    p[3] = (void *)b;
    p[2] = c;
    if (!p[2])
        p[2] = p[1];
    p[4] = (void *)d;
    return p;
}

EXTERN_C char D_800B73D4[];
EXTERN_C void func_8001D024(void *, int);
EXTERN_C void func_800BFCE8(void **p, int in_chrg)
{
    p[0] = D_800B73D4;
    func_8001D024(p, in_chrg);
}

EXTERN_C char D_800A454C[];
EXTERN_C char D_80010178[];
EXTERN_C char D_80010338[];
EXTERN_C void func_8001D150(void *, void *);

struct T_800BFD10 {
    void *vt;
    int f4;
    void *f8;
    short fC;
    int f10;
};

EXTERN_C void func_800BFD10(void *p)
{
    char *l = D_800A454C;
    T_800BFD10 *o = (T_800BFD10 *)operator new(0x14);
    o->vt = D_80010178;
    o->f4 = 0;
    o->vt = D_80010338;
    o->f8 = p;
    o->fC = 0x80;
    o->f10 = 1;
    func_8001D150(l, o);
}

EXTERN_C int func_800BFE10(void **p, int a);
EXTERN_C int func_800BFE34(void **p, int a);
EXTERN_C int func_800BF324(void *p);
EXTERN_C int func_800BF374(void *p);
EXTERN_C int func_800BFD84(void **p)
{
    int t = (int)p[3];
    void *o;
    if (t == 200)
        return 1;
    o = p[1];
    switch (t) {
    case 201:
        if (func_800BFE10(p, 30))
            return 0;
        func_800BF324(o);
        return 1;
    case 202:
        if (func_800BFE34(p, 30))
            return 0;
        func_800BF374(o);
        return 1;
    }
    return 0;
}

EXTERN_C int func_800BE954(void *, int);
EXTERN_C int func_800BFE10(void **p, int a) { return func_800BE954(p[1], a); }

EXTERN_C int func_800BEAC0(void *, int);
EXTERN_C int func_800BFE34(void **p, int a) { return func_800BEAC0(p[1], a); }

INCLUDE_ASM("asm/capture/nonmatchings/capture", __10C_800BFE58i);

EXTERN_C char D_800B7404[];
EXTERN_C char D_800B741C[];
EXTERN_C void func_80019920(void *, int);
EXTERN_C void func_800C22CC(char *p, int in_chrg);
EXTERN_C void func_800C2480(char *p, int in_chrg);
EXTERN_C void func_800C2F9C(char *p, int in_chrg);
EXTERN_C void func_800C2074(char *p, int in_chrg);
EXTERN_C void func_800C1F18(char *p, int in_chrg);
EXTERN_C void func_800BF5D8(char *p, int in_chrg);
EXTERN_C void func_8001E508(void *, int);
EXTERN_C void func_800BFF8C(void *self, int in_chrg)
{
    char *p = (char *)self;
    *(char **)(p + 0x8C) = D_800B7404;
    *(char **)p = D_800B741C;
    func_80019920(*(void **)(p + 0x5B0), 0);
    func_800C22CC(p + 0x48C, 2);
    func_800C2480(p + 0x448, 2);
    func_800C2F9C(p + 0x438, 2);
    func_800C2074(p + 0x428, 2);
    func_800C1F18(p + 0x408, 2);
    func_800BF5D8(p + 0x3E0, 2);
    func_8001E508(p, in_chrg);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0030);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0194);

EXTERN_C void exit(int);
EXTERN_C signed char func_800C21B0(char *p);
EXTERN_C int func_800C0820(char *p, signed char key)
{
    N_800C0820 *e = *(N_800C0820 **)(p + 0x42C);
    while (1) {
        if (!((signed char *)p)[0xF9])
            break;
        if (key == func_800C21B0((char *)e))
            goto found;
        e = e->next;
    }
    exit(1);
found:
    return e->val;
}

EXTERN_C void exit(int);
EXTERN_C int func_800C089C(char *p, signed char key)
{
    N_800C089C *e = *(N_800C089C **)(p + 0x43C);
    signed char n = p[0xF8];
    while (1) {
        if (n == 0)
            break;
        if (key == e->id)
            goto found;
        n--;
        e = e->next;
    }
    exit(1);
found:
    return e->val;
}

EXTERN_C void exit(int);
EXTERN_C int func_800C08FC(char *p, signed char key)
{
    N_800C08FC *e = *(N_800C08FC **)(p + 0x40C);
    short n = *(short *)(p + 0x3D0);
    while (1) {
        if (n == 0)
            break;
        if (key == e->id)
            goto found;
        n--;
        e = e->next;
    }
    exit(1);
found:
    return e->val;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0958);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0A28);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0B7C);

EXTERN_C int func_8001A6E8(void *);
EXTERN_C signed char *func_800C0CB0(void *p, int id)
{
    N_800C0CB0 *e = *(N_800C0CB0 **)((char *)p + 0x3E4);
    short n = func_8001A6E8(e);
    while (1) {
        if (n == 0)
            break;
        if (id == e->id)
            break;
        n--;
        e = e->next;
    }
    return (signed char *)e;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0D14);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0F38);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C12B4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C15F4);

EXTERN_C void VectorNormal(Vec3 *, Vec3 *);
EXTERN_C void func_800C1814(S_800C1814 *p)
{
    int i;
    int n = p->n;
    Vec3 v;
    for (i = 0; i < n; i++) {
        v.x = p->e[i].b.x - p->e[i].a.x;
        v.y = p->e[i].b.y - p->e[i].a.y;
        v.z = p->e[i].b.z - p->e[i].a.z;
        VectorNormal(&v, &p->out[i]);
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C18C0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C1BA4);

EXTERN_C char *func_800C1CC8(char *p) { return p + 0x514; }

EXTERN_C E_800C1CD0 *func_800C1CD0(S_800C1CD0 *p, int i) { return &p->e[i]; }

EXTERN_C int func_800C1CE8(char *p) { return *(int *)(p + 0x104); }

EXTERN_C int func_800C1CF4(char *p, int v) { *(int *)(p + 0x104) = v; return 1; }

EXTERN_C ShortQuad func_800C1D00(S_800C1D00 *p) { return p->q1; }

EXTERN_C ShortQuad func_800C1D2C(S_800C1D00 *p) { return p->q0; }

EXTERN_C void func_800C1D58(S_800C1D58 *p, Block60 *b) { p->b1 = *b; }

EXTERN_C void func_800C1D94(S_800C1D58 *p, Block60 *b) { p->b0 = *b; }

EXTERN_C char *func_800C1DD0(char *p) { return p + 0xFC; }

EXTERN_C char *func_800C1DD8(char *p) { return p + 0x15C; }

EXTERN_C int func_800C1DE0(char *p) { return *(short *)(p + 0x284); }

EXTERN_C int func_800C1DEC(char *p) { return *(short *)(p + 0x3D2); }

EXTERN_C void func_800C1DF8(char *p, char v) { p[0xF9] = v; }

EXTERN_C void func_800C1E00(char *p, char v) { p[0xF8] = v; }

EXTERN_C char *func_800C1E08(char *p) { return p + 0x448; }

EXTERN_C char *func_800C1E10(char *p) { return p + 0x48C; }

EXTERN_C int func_800C1E18(char *p) { return *(int *)(p + 0x270); }

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7434[];
EXTERN_C char *func_800C1E24(char *p)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800B7434;
    *(signed char *)(p + 0x10) = -0x11;
    *(signed char *)(p + 0x11) = -0x11;
    *(short *)(p + 0x12) = -0x1011;
    *(short *)(p + 0x14) = -0x1011;
    *(int *)(p + 0x8) = 0xEFEFEFEF;
    *(int *)(p + 0xC) = 0xEFEFEFEF;
    *(int *)(p + 0x1C) = 0xEF;
    *(int *)(p + 0x18) = 0;
    return p;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7434[];
EXTERN_C void *func_800A0D2C(int);
C_800C1E7C::C_800C1E7C(Desc_800C1E7C *d)
{
    vt = D_80010178;
    f4 = 0;
    vt = D_800B7434;
    f8 = d->a;
    fC = d->b;
    f10 = d->c;
    f11 = d->d;
    f12 = d->e;
    n = d->n;
    f1C = 0;
    list = func_800A0D2C(n * 8);
}

EXTERN_C char D_800B7434[];
EXTERN_C void func_800A0D0C(void *);
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C1F18(char *p, int in_chrg)
{
    *(char **)p = D_800B7434;
    if (*(void **)(p + 0x18))
        func_800A0D0C(*(void **)(p + 0x18));
    func_8001A610(p, in_chrg);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C1F6C);

EXTERN_C int func_800C1FDC(short *p) { return p[9] != 0; }

EXTERN_C int func_800C1FE8(int *p) { return p[6]; }

EXTERN_C int func_800C1FF4(int *p) { return p[7]; }

EXTERN_C void func_800C2000(int *p, int v) { p[7] = v; }

EXTERN_C int func_800C2008(short *p) { return p[10]; }

EXTERN_C int func_800C2014(signed char *p) { return p[0x11]; }

EXTERN_C int func_800C2020(signed char *p) { return p[0x10]; }

EXTERN_C int func_800C202C(int *p) { return p[3]; }

EXTERN_C int func_800C2038(int *p) { return p[2]; }

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7444[];
EXTERN_C char *func_800C2044(char *p, char a, short b)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800B7444;
    p[8] = a;
    *(short *)(p + 0xA) = b;
    *(int *)(p + 0xC) = 0;
    return p;
}

EXTERN_C char D_800B7444[];
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C2074(char *p, int in_chrg)
{
    VObject *o;
    *(char **)p = D_800B7444;
    o = *(VObject **)(p + 0xC);
    if (o) {
        // delete o (virtual destructor, slot 1)
        VtblEntry *e = &o->vt[1];
        ((void (*)(void *, int))e->pfn)((char *)o + e->delta, 3);
    }
    func_8001A610(p, in_chrg);
}

EXTERN_C char D_80010178[];
EXTERN_C char D_800106EC[];
EXTERN_C char D_80010624[];
EXTERN_C void func_80021F48(void *, void *);
EXTERN_C VObj10 *D_800B4C38[];
EXTERN_C void func_800C20DC(char *p, void *a)
{
    char *o = (char *)operator new(0x20C);
    VObj10 *m;
    VtblEntry *e;
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_800106EC;
    *(short *)(o + 8) = 0;
    *(short *)(o + 0xA) = 0;
    *(char **)o = D_80010624;
    func_80021F48(o, a);
    m = D_800B4C38[0];
    *(char **)(p + 0xC) = o;
    e = &m->vt[1];
    ((void (*)(void *, void *))e->pfn)((char *)m + e->delta, o);
    *(short *)(p + 0xA) = *(short *)(*(char **)(p + 0xC) + 8);
}

EXTERN_C short func_800C2194(char *p)
{
    int r;
    if (*(int *)(p + 0xC) == 0)
        r = 0;
    else
        r = *(short *)(p + 0xA);
    return r;
}

EXTERN_C signed char func_800C21B0(char *p)
{
    int r;
    if (*(int *)(p + 0xC) == 0)
        r = 0;
    else
        r = *(signed char *)(p + 0x8);
    return r;
}

EXTERN_C int func_800C21CC(int *p) { return p[3]; }

EXTERN_C void func_800C21D8(char *p, char v) { p[8] = v; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C21E0);

EXTERN_C char D_800B7454[];
EXTERN_C char D_800B74BC[];
EXTERN_C char D_80011C44[];
EXTERN_C char D_80011CAC[];
EXTERN_C char D_80011B8C[];
EXTERN_C char D_80011BF4[];
EXTERN_C char D_80011AAC[];
EXTERN_C char D_80011B14[];
EXTERN_C void func_800198AC(void *, int);
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C22CC(char *p, int in_chrg)
{
    *(char **)(p + 8) = D_800B7454;
    *(char **)p = D_800B74BC;
    *(char **)(p + 8) = D_80011C44;
    *(char **)p = D_80011CAC;
    *(char **)(p + 8) = D_80011B8C;
    *(char **)p = D_80011BF4;
    *(char **)(p + 8) = D_80011AAC;
    *(char **)p = D_80011B14;
    func_800198AC(p + 8, 0);
    func_8001A610(p, in_chrg);
}

EXTERN_C S_800C2370_src *func_800C2370(S_800C2370_dst *d, S_800C2370_src *s, int *out)
{
    int i = 0;
    *out = 0;
    d->q[0] = s->q[0];
loop:
    if (i < 3) {
        (&d->q[0])[i + 1] = (&s->q[0])[i + 1];
        i++;
        goto loop;
    }
    return s;
}

EXTERN_C int func_800C23DC() { return 0; }

EXTERN_C void func_800C23E4(int *p, int v) { p[0x11] = v; }

EXTERN_C int func_800C23EC(int *p) { return p[0x11]; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C23F8);

EXTERN_C char D_800B751C[];
EXTERN_C void func_80019920(void *, int);
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C2480(char *p, int in_chrg)
{
    *(char **)p = D_800B751C;
    func_80019920(*(void **)(p + 0xC), 0);
    func_8001A610(p, in_chrg);
}

EXTERN_C void func_80019A6C(void *, int, int);
EXTERN_C void func_800C24D0(char *p, N_800C24D0 *n)
{
    if (*(int *)(p + 0x34)) {
        while (1) {
            if (!n)
                break;
            int *vb = (p + 0xC) ? *(int **)(p + 0xC) : 0;
            func_80019A6C(vb, (int)n, vb[1]);
            n = n->next;
        }
        *(int *)(p + 0x34) = 0;
        *(int *)(p + 0x38) = 0;
    }
}

EXTERN_C int func_800C254C(int *p) { return p[0xE]; }

EXTERN_C char *func_800C2558(char *p) { return p + 0xC; }

EXTERN_C int func_800C2560(short *p) { return p[0x16]; }

EXTERN_C void func_800C256C(short *p, short v) { p[0x16] = v; }

EXTERN_C int func_800C2574(int *p) { return p[0xC]; }

EXTERN_C void func_800C2580(int *p) { p[0xC]--; }

EXTERN_C void func_800C2594(int *p, int v) { p[0xC] = v; }

EXTERN_C int func_800C259C(short *p) { return p[4]; }

EXTERN_C void func_800C25A8(short *p, short v) { p[4] = v; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C25B0);

EXTERN_C char D_80010178[];
EXTERN_C char D_800111BC[];
EXTERN_C char D_800B752C[];
EXTERN_C char *func_800C2744(char *p)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800111BC;
    *(short *)(p + 8) = 0;
    *(short *)(p + 0xA) = 0;
    *(char **)p = D_800B752C;
    return p;
}

EXTERN_C char D_800B752C[];
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C277C(void **p, int in_chrg)
{
    p[0] = D_800B752C;
    func_8001A610(p, in_chrg);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C27A4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2850);

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2A38(S_800C2D5C *p, short x, short y)
{
    if (p->state == 1)
        func_800C2BD0(p);
    int i = D_800B4CF0[0];
    p->e[i].b.x = x;
    p->e[i].b.y = y;
    p->state = 2;
}

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2AA8(S_800C2D5C *p, short dx, short dy)
{
    if (p->state == 1)
        func_800C2BD0(p);
    int i = D_800B4CF0[0];
    p->e[i].b.x += dx;
    p->e[i].b.y += dy;
    p->state = 2;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2B28);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2BD0);

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2C4C(S_800C2D5C *p, unsigned char *c)
{
    if (p->state == 1)
        func_800C2BD0(p);
    p->e[D_800B4CF0[0]].b.col.c.r = c[5];
    p->e[D_800B4CF0[0]].b.col.c.g = c[6];
    p->e[D_800B4CF0[0]].b.col.c.b = c[7];
    p->state = 2;
}

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2CD4(S_800C2D5C *p, unsigned char *c)
{
    if (p->state == 1)
        func_800C2BD0(p);
    p->e[D_800B4CF0[0]].b.col.c.r = c[0];
    p->e[D_800B4CF0[0]].b.col.c.g = c[1];
    p->e[D_800B4CF0[0]].b.col.c.b = c[2];
    p->state = 2;
}

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2D5C(S_800C2D5C *p, unsigned char *out)
{
    out[0] = p->e[D_800B4CF0[0]].b.col.c.r;
    out[1] = p->e[D_800B4CF0[0]].b.col.c.g;
    out[2] = p->e[D_800B4CF0[0]].b.col.c.b;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2DB4);

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2E60(S_800C2D5C *p, unsigned char a, unsigned char b)
{
    if (p->state == 1)
        func_800C2BD0(p);
    p->e[D_800B4CF0[0]].b.p8 = a;
    p->e[D_800B4CF0[0]].b.p9 = b;
    p->state = 2;
}

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2EE0(S_800C2D5C *p, char *q)
{
    if (p->state == 1)
        func_800C2BD0(p);
    p->e[D_800B4CF0[0]].b.s = *(short *)(q + 8);
    p->state = 2;
}

EXTERN_C void func_800C2F40(int *p) { p[0x12] = 1; }

EXTERN_C void func_800C2F4C(int *p) { p[0x12] = 0; }

EXTERN_C short D_800C3214[];
EXTERN_C void func_800C2F54() { D_800C3214[0] = 0; }

EXTERN_C int func_800C2F60(int *p) { return p[1]; }

EXTERN_C char D_80010178[];
EXTERN_C char D_800B757C[];
EXTERN_C char *func_800C2F6C(char *p)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800B757C;
    p[8] = 0;
    *(short *)(p + 0xA) = 0;
    *(int *)(p + 0xC) = 0;
    return p;
}

EXTERN_C char D_800B757C[];
EXTERN_C void func_80024FEC(void *, int);
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C2F9C(char *p, int in_chrg)
{
    *(char **)p = D_800B757C;
    if (*(void **)(p + 0xC)) {
        func_80024FEC(*(void **)(p + 0xC), 0);
        VObject *o = *(VObject **)(p + 0xC);
        if (o) {
            // delete o (virtual destructor, slot 1)
            VtblEntry *e = &o->vt[1];
            ((void (*)(void *, int))e->pfn)((char *)o + e->delta, 3);
        }
    }
    func_8001A610(p, in_chrg);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C301C);

EXTERN_C int func_800C31A8(int *p) { return p[3]; }

EXTERN_C void func_800C31B4(char *p, char v) { p[8] = v; }

EXTERN_C void func_800C31BC(short *p, short v) { p[5] = v; }

EXTERN_C int func_800C31C4(signed char *p) { return p[8]; }

EXTERN_C int func_800C31D0(unsigned short *p) { return p[5]; }

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7334);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B734C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7364);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7374);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B738C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B73A4);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B73BC);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B73D4);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7404);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B741C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7434);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7444);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7454);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B74BC);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B751C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B752C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B757C);
