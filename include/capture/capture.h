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
    int pad;
    int *buf;
    int value;
    int mask;
    int wr;
    int rd;
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

#endif
