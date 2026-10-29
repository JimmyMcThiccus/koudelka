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


/* Node with an id in a singly linked chain; base class from the EXE (vtable D_80010178). */
struct IdNode {
    int *vptr;
    IdNode *next;
    short id;
};

/* IdNode owning an array of count elements (Color for vtable D_800D6408, SVec4 for
   D_800D63F8); out-of-range indices read element def. */
struct IdArray : IdNode {
    void *data;
    short def;
    short count;
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

/* Unaligned 4-byte and 8-byte records (copied with lwl/lwr). */
struct Color {
    unsigned char r, g, b, a;
};

struct SVec4 {
    short x, y, z, w;
};

/* Doubly linked node embedded at 0x18 of SubNode. */
struct Link {
    Link *prev;
    Link *next;
};


struct SubNodeHead {
    int pad[6];
};

struct SubNode : SubNodeHead, Link {
};

/* Object with eight word slots at 0x110 (0x800DAxxx code). */
struct SlotSet {
    char pad0[0x110];
    int slots[8];
    char pad130[0xC];
    int first;
    int cur;
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

/* GCC 2 vtable entry: this adjustment and function. Entry 0 is unused; entry 1 is the
   destructor, called with flags 3 by delete. */
struct VtEntry {
    short delta;
    short index;
    void (*pfn)(void *self, int arg);
};

struct Poly {
    VtEntry *vptr;
};

/* EXE heap and memory helpers */

/* EFFECT functions called from code above their definition */
EXTERN_C IdNode *func_800D67F4(IdNode *self, short id);
EXTERN_C void func_800DE108(void *self, int i, Color *c);
EXTERN_C void func_800DE38C(void *self, int i, SVec4 *v);
EXTERN_C void func_800DE7A4(void *self, int i, Color *c);
EXTERN_C char *func_800E40E4(void *self, char *src);
EXTERN_C void *func_800E3EB4(void *self);
EXTERN_C int func_800DA584(SlotSet *self);
EXTERN_C void func_800DBE88(void *self, int flags);
EXTERN_C void func_800E28D8(IdNode *self, int flags);
EXTERN_C char *func_800DBEBC(void *self, char *src);
EXTERN_C char *func_800E4110(void *self, char *src);
EXTERN_C void func_800D67CC(IdNode *self, int flags);


/* vtables (retail rodata), then words in EFFECT .data */
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
EXTERN_C int D_800D62B0[];
EXTERN_C int D_800D62E0[];
EXTERN_C int D_800D6310[];
EXTERN_C int D_800D6340[];
EXTERN_C int D_800D6370[];
EXTERN_C int D_800D63F8[];
EXTERN_C int D_800D6408[];
EXTERN_C int D_800D6614[];
EXTERN_C int D_800D6644[];
EXTERN_C int D_800D6674[];
EXTERN_C int D_800D6704[];
EXTERN_C int D_800D672C[];
EXTERN_C int D_800D6754[];
EXTERN_C int D_800D677C[];
EXTERN_C int D_800D67A4[];
EXTERN_C int D_800E583C[];
EXTERN_C int D_800E5840[];
EXTERN_C int D_800E5844[];

EXTERN_C void *D_800E5848[];

/* EXE globals */
EXTERN_C void *D_800B4ED8[];

inline void idnode_init(IdNode *self, short id)
{
    self->vptr = D_80010178;
    self->next = 0;
    self->vptr = D_800D5DB0;
    self->id = id;
}

inline void key_init(Key *self, short id)
{
    self->vptr = D_800D6188;
    self->id = id;
    self->s2 = 0;
    self->w4 = 0;
}

inline void vec4_zero(Vec4 *v)
{
    v->x = 0;
    v->y = 0;
    v->z = 0;
    v->w = 0;
}

inline void keyvec_init(KeyVec *self, short id)
{
    key_init(self, id);
    self->vptr = D_800D6160;
    vec4_zero(&self->v);
}

/* Element i of the Color array at 0x1C, or the default element if i is out of range */
inline Color *color_at(void *self, int i)
{
    if (i >= FIELD_AT(self, short, 0xE))
        return &FIELD_AT(self, Color *, 0x1C)[FIELD_AT(self, short, 0x20)];
    return &FIELD_AT(self, Color *, 0x1C)[i];
}

inline void key_copy(Key *self, Key *other)
{
    self->s2 = other->s2;
    self->w4 = other->w4;
}

/* Shared by effect.cpp and effect_b.cpp (the two original files). */

/* Scratchpad parameter block at 0x1F800000 (filled before building an effect object) */
struct Params_800E2704 {
    char pad0[8];
    int a;
    int b;
    RandVal *rv;
    Vec4 v14;
    Vec4 v24;
    Vec4 v34;
    unsigned char b44, b45, b46, b47;
    short s48;
    short s4A;
    short s4C;
    short s4E;
    short s50;
    unsigned char b52;
};

EXTERN_C Params_800E2704 D_1F800000;

struct C_800D6C94;
EXTERN_C C_800D6C94 *func_800D6C94(C_800D6C94 *self);

/* EXE functions that effect calls with another prototype than include/shared/exe.h. */
// Defined with an explicit return slot (r, m, v); effect returns the Vec4 by value and passes the matrix as an int.
EXTERN_C Vec4 func_8003A150_v(int h, int n) asm("func_8003A150");
// Takes two arguments; effect passes one and leaves $a1 as it is.
EXTERN_C void func_8001D024_1(void *self) asm("func_8001D024");

// Effect passes nodes that convert to their base Link (and back), adjusting the pointer; exe.h takes void *.
EXTERN_C Link *func_8001A744_l(Link *a, Link *b) asm("func_8001A744");
EXTERN_C void func_8001A678_l(Link *a, Link *b) asm("func_8001A678");

#endif /* EFFECT_EFFECT_H */
