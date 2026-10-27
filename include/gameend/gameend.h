#ifndef GAMEEND_GAMEEND_H
#define GAMEEND_GAMEEND_H

#include "common.h"

/* GCC 2.x vtable entry (no thunks): call pfn with this + delta. */
struct VEntry {
    short delta;
    short index;
    void (*pfn)(void *);
};

/* The virtual base's vtable, copied to the stack when a constructor or
   destructor runs for a subobject (in_chrg == 0) so its deltas can be fixed. */
struct VTable10 {
    VEntry e[10];
};

/* List / Holder as in game.cpp's func_800186E8: converting a Holder to its
   virtual base reads the vbase pointer, with a null check. */
struct List {
    int pad;
    int count;
};

struct Holder : virtual List {
};

/* Item list returned by func_80019F64; the slot used here is the seventh. */
struct Item {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct Q {
    int f0;
    int f4;
};

struct H0 : virtual Q {
    int x;
};

/* Pointed to by GameEnd::f94: Q through H0's vbase pointer, List through Holder (+8). */
struct T94 : H0, Holder {
};

/* The virtual base at GameEnd+0x2C4. Its constructor is inlined: base vptr
   D_80010178, f4 = 0, then D_800104A8. Destructor func_8001A610. */
struct VBase {
    const void *vptr;
    int f4;
};

/* EXE base class at GameEnd+0x00: ctor func_80056364, dtor func_8005652C. */
struct BaseA {
    char pad0[0x18];
    const VEntry *vt18;
    char pad1C[0x50 - 0x1C];
    VBase *vb50;
    const VEntry *vt54;
    const VEntry *vt58;
    char pad5C[0x64 - 0x5C];
};

/* EXE base class at GameEnd+0x64: ctor func_8005BC84, dtor func_8005BDA4. */
struct BaseB {
    VBase *vb64;
    char pad4[0x4];
    int f6C;
    char padC[0x1C - 0xC];
    unsigned short f1C;
    char pad1E[0x2C - 0x1E];
    const VEntry *vt90;
    T94 *f94;
    char pad34[0x38 - 0x34];
};

/* EXE base class at GameEnd+0x9C: ctor func_800537C0, dtor func_800537DC. */
struct BaseC {
    char pad0[0x8];
    const VEntry *vtA4;
};

/* The overlay's one class. Its virtual functions are only reached through
   the vtables D_800B6DF4..D_800B6F9C; the constructor func_800B6FEC is called
   by the EXE at a fixed address. */
struct GameEnd : BaseA, BaseB, BaseC {
    char fA8[0x14]; /* 0x200 bytes are copied to fA8 from file 0x1531C */
    unsigned short fBC;
    char padBE[0x2A8 - 0xBE];
    int f2A8;
    void *f2AC;
    void *f2B0[3];
    void *f2BC;
    void *f2C0;
};

struct Ev {
    char pad0[0x18];
    unsigned short flags;
};

struct Color {
    char pad0[8];
};

struct Point {
    short x, y;
    Point(short a, short b) { x = a; y = b; }
};

struct Size {
    short w, h;
    Size(short a, short b) { w = a; h = b; }
};

struct Rect {
    Point p;
    Size s;
    Rect(short x, short y, short w, short h) : p(x, y), s(w, h) {}
};

EXTERN_C const VEntry D_800B6DF4[];
EXTERN_C const VEntry D_800B6E14[];
EXTERN_C const VEntry D_800B6E44[];
EXTERN_C const VEntry D_800B6F3C[];
EXTERN_C const VEntry D_800B6F5C[];
EXTERN_C const VTable10 D_800B6F9C;

#endif /* GAMEEND_GAMEEND_H */
