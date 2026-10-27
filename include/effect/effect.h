#ifndef EFFECT_EFFECT_H
#define EFFECT_EFFECT_H

#include "common.h"

/* Member at a byte offset, for objects whose layout isn't recovered yet:
   FIELD_AT(self, short, 0x10) is the short at self+0x10. */
#ifndef FIELD_AT
#define FIELD_AT(p, type, off) (*(type *)((char *)(p) + (off)))
#endif

/* The code is C++ (GCC 2.8). Classes are written as plain structs with an explicit
   vptr, so this file never emits vtables: the retail ones are the D_800D5xxx/D_800D6xxx
   tables at the start of the overlay. Constructors return this; destructors take
   (this, flags) and free when flags & 1. */

/* EXE dynamic array: func_800198E0 init, func_80019920 clear, func_80019A6C insert,
   func_80019C68 remove, func_80019F64 get. Looks shared with the EXE (see the
   List/Holder pair in tests/compiler/func_800186E8.cpp). */
struct List {
    int pad0;
    int count;
    int pad8;
    int padC;
};

/* GCC 2 virtual-base pointer (_vb$List) of a subobject that inherits virtually from
   List. Converting it to List * null-checks the subobject. */
struct ListRef {
    List *list;
};

inline List *list_of(ListRef *r) { return r ? r->list : 0; }

EXTERN_C void func_800198E0(List *l, int elem_size, int arg);
EXTERN_C void func_80019920(List *l, int arg);
EXTERN_C void func_80019A6C(List *l, void *item, int index);
EXTERN_C void func_80019C68(List *l, int index);
EXTERN_C void *func_80019F64(List *l, int index);

/* Node with an id in a singly linked chain; base class from the EXE (vtable D_80010178). */
struct IdNode {
    int *vptr;
    IdNode *next;
    short id;
};

/* Base of a family of small polymorphic objects (vtable D_800D5F20). The virtuals
   mostly answer yes/no questions about the owner. */
struct Cond {
    void *owner;
    short id;
    int *vptr;
};

/* Cond holding a list of 16-byte entries (vtable D_800D5DC0). */
struct CondEntry {
    int a, b, c, d;
};

struct CondList : Cond {
    ListRef ref;
    List list;
};

/* Cond with a short threshold (vtable D_800D5EC8). */
struct CondMin : Cond {
    short min;
};

/* Randomised value (vtable D_800D6038 at 0xC). */
struct RandVal {
    short base;
    short step;
    short range;
    short phase;
    short spread;
    int *vptr;
};

/* Keyed value family (base vtable D_800D6188). Load functions read a record and
   return the pointer just past it. */
struct Key {
    short id;
    short s2;
    int w4;
    int *vptr;
};

struct Vec4 {
    int x, y, z, w;
    Vec4() {}
    Vec4(int ax, int ay, int az, int aw) : x(ax), y(ay), z(az), w(aw) {}
};

/* Key with a vector (vtable D_800D6160, derived D_800D6048/D_800D6070). */
struct KeyVec : Key {
    Vec4 v;
};

/* KeyVec subclasses D_800D6048 and D_800D6070 add a word. */
struct KeyVec2 : KeyVec {
    int extra;
};

/* Key with one extra word (vtables D_800D6098, D_800D60C0, D_800D60E8, D_800D6110, D_800D6138). */
struct KeyInt : Key {
    int value;
};

EXTERN_C int D_80010178[];
EXTERN_C int D_800D5DB0[];
EXTERN_C int D_800D5DC0[];
EXTERN_C int D_800D5E18[];
EXTERN_C int D_800D5E70[];
EXTERN_C int D_800D5EC8[];
EXTERN_C int D_800D5F20[];
EXTERN_C int D_800D5F78[];
EXTERN_C int D_800D5FD0[];
EXTERN_C int D_800D6038[];
EXTERN_C int D_800D6048[];
EXTERN_C int D_800D6070[];
EXTERN_C int D_800D6098[];
EXTERN_C int D_800D60C0[];
EXTERN_C int D_800D60E8[];
EXTERN_C int D_800D6110[];
EXTERN_C int D_800D6138[];
EXTERN_C int D_800D6160[];
EXTERN_C int D_800D6188[];

#endif /* EFFECT_EFFECT_H */
