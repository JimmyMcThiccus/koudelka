#ifndef CAPTURE_CAPTURE_H
#define CAPTURE_CAPTURE_H

// Layouts are partial: only the fields the decompiled code touches are named.

// GCC 2.x vtable entry
struct VtblEntry {
    short delta;
    short index;
    void *pfn;
};

struct VObject {
    VtblEntry *vt;
};

struct ObjSlot {
    int pad;
    VObject *obj;
};

EXTERN_C void func_800198E0(void *, int, int);

struct IntPair {
    int a, b;
};

// 8 bytes, 2-aligned (copied with lwl/lwr)
struct ShortQuad {
    short v[4];
};

struct S_800B9E74 {
    char pad[0x3C];
    int slot[16];
};

struct S_800BF0FC {
    char pad[0x4E4];
    IntPair p0;
    IntPair p1;
};

struct S_800BFC9C {
    char pad[0x5D0];
    IntPair tag;
};

struct E_800C1CD0 {
    char data[0x28];
};

struct S_800C1CD0 {
    char pad[0x538];
    E_800C1CD0 e[1];
};

struct E_800B93D8 {
    char pad[0x2];
    short h;
    char pad2[0x10];
};

struct S_800B93D8 {
    char pad[0x30];
    E_800B93D8 e[1];
};

struct S_800B9414 {
    char pad[0x50];
    ShortQuad q;
};

struct S_800C1D00 {
    char pad[0x1DC];
    ShortQuad q0;
    ShortQuad q1;
};

struct S_800BCDA4 {
    char pad[0x118];
    void *list1[4];
    void *list0[4];
    short n1;
    short n0;
};

struct S_800BD5D0 {
    char pad[0x30];
    int list[4];
    short n;
};

struct S_800BF6E8 {
    char pad[0xA];
    short n;
    char pad2[0x8];
    int *ptr;
    int i;
};

struct Block60 {
    int w[24];
};

struct S_800C1D58 {
    char pad[0xFC];
    Block60 b0;
    Block60 b1;
};

// ring buffer of words
struct S_800BA17C {
    char *base;
    int *buf;
    int value;
    int mask;
    int wr;
    int rd;
    int last;
    S_800BA17C(int size, int bits, char *mem);
};

struct ShortPair {
    short a, b;
};

struct S_800BF62C {
    char pad[0xA];
    short n;
    char pad2[0x4];
    ShortPair *list;
    char pad3[0x8];
    int count;
};

struct S_800BDC70 {
    char pad[0x48];
    int list[4];
    short n;
};

struct Rgb {
    unsigned char r, g, b, cd;
};

struct Int2 {
    int v[2];
};

struct Body12 {
    union {
        Rgb c;
        int w;
    } col;
    short x, y;
    short pad, s;
};

struct E12 {
    int hdr;
    Int2 b;
};

struct E16 {
    int hdr;
    Body12 b;
};

// double-buffered: D_800B4CF0 selects the current entry
struct S_800C2D5C {
    char pad[8];
    short state;
    short pad2;
    E12 a[2];
    E16 e[2];
};

struct N_800C08FC {
    int pad;
    N_800C08FC *next;
    short id;
    char pad2[0xE];
    int val;
};

struct N_800C0CB0 {
    int pad;
    N_800C0CB0 *next;
    short id;
};

struct N_800C089C {
    int pad;
    N_800C089C *next;
    signed char id;
    char pad2[3];
    int val;
};

struct Short12 {
    short v[12];
};

struct S_800BD604 {
    char pad[0x28C4];
    Short12 v;
};

struct Rec8 {
    unsigned char a, b, c, d;
    short e, f;
};

struct S_800C1F6C {
    char pad[0x14];
    short n;
    char pad2[2];
    Rec8 *list;
};

struct S_800C2370_src {
    int pad;
    ShortQuad q[4];
};

struct S_800C2370_dst {
    char pad[0xC];
    ShortQuad q[4];
};

struct N_800BE6D8 {
    int pad;
    N_800BE6D8 *next;
    VObject obj;
};

struct N_800BE8E0 {
    int pad;
    N_800BE8E0 *next;
    char pad2[4];
    char data[1];
};

// Constructors are real C++ constructors (mangled names in config/symbols/capture.txt): GCC returns `this` from them,
// which a plain function can't reproduce. Base classes that are inlined show up as extra vtable stores.
struct C_800BF560 {
    void *vt;
    int f4;
    short f8, fA;
    signed char fC;
    int *f10, *f14;
    int f18, f1C;
    signed char f20;
    int f24;
    C_800BF560(short a, short n, char c);
};

EXTERN_C char D_800B6DF4[];

struct B_800B86F0 {
    void *vt;
    int f4, f8, fC;
    B_800B86F0()
    {
        vt = D_800B6DF4;
        f8 = 0;
        fC = 0;
    }
};
struct C_800BA258 : B_800B86F0 {
    S_800BA17C ring;
    C_800BA258(int size, int bits, char *mem);
};

// small vector with inline storage; same layout as S_800186B0 in the EXE
struct Vec_800BF80C {
    void *p;
    int n;
    void *data;
    int buf[1];
    void init()
    {
        data = buf;
        p = buf;
        func_800198E0(data, 0x10, 0);
        n = 0;
    }
};

struct C_800BFE58 {
    void *vt;
    char pad[0x88];
    void *vt2;
    C_800BFE58(int a);
};

struct C_800BFC28 : C_800BFE58 {
    C_800BFC28(int a);
};

struct C_800BF80C : C_800BFC28 {
    char pad2[0x5E0 - 0x90];
    Vec_800BF80C v;
    char pad3[0x600 - 0x5E0 - 0x10];
    int f600;
    C_800BF80C(int a);
};

#endif
