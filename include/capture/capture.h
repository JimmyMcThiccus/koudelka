#ifndef CAPTURE_CAPTURE_H
#define CAPTURE_CAPTURE_H

// Layouts are partial: only the fields the decompiled code touches are named.

struct IntPair {
    int a, b;
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

#endif
