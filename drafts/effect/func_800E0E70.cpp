// func_800E0E70: ~24-40 differ: retail puts the 2-byte mode temp at sp+0x10 and the colour copy temp at sp+0x18 (here swapped), and loads 0x78 with lh; logic and layout of the scratchpad block are right.
#include "effect/effect.h"

struct B2_800E0E70 {
    unsigned char a, b;
    B2_800E0E70(int x, int y) : a(x), b(y) {}
} __attribute__((aligned(2)));

struct C4_800E0E70 {
    unsigned char v[4];
};

struct F_800E0E70 {
    unsigned short lo : 5;
    unsigned short abr : 2;
    unsigned short hi : 9;
};

/* scratchpad parameter block */
struct SP_800E0E70 {
    B2_800E0E70 mode;
    F_800E0E70 flags;
    unsigned short tex;
    short pad6;
    int w8;
    int wC;
    void *p10;
    char pad14[0x30];
    C4_800E0E70 col;
    short s48, s4A, s4C, s4E, s50;
    unsigned char b52;
};

EXTERN_C SP_800E0E70 D_1F800000;

inline int mode_800E0E70(void *o)
{
    Poly *q = FIELD_AT(o, Poly *, 0xC);
    if (!q)
        return FIELD_AT(o, unsigned short, 0x10) & 0x3F;
    if (((int (*)(void *))q->vptr[3].pfn)((char *)q + q->vptr[3].delta))
        return (FIELD_AT(o, short, 0x10) << 1) & 0x7F;
    return FIELD_AT(o, short, 0x10) << 2;
}


EXTERN_C void func_800E0E70(void *self)
{
    void *o = FIELD_AT(self, void *, 0x28);
    int a = mode_800E0E70(o);
    F_800E0E70 f = FIELD_AT(FIELD_AT(self, void *, 0x28), F_800E0E70, 0x1C);
    f.abr = FIELD_AT(self, short, 0x78);
    D_1F800000.flags = f;
    D_1F800000.tex = FIELD_AT(FIELD_AT(FIELD_AT(self, void *, 0x28), void *, 0xC), unsigned short, 0x8);
    D_1F800000.w8 = FIELD_AT(self, int, 0x34);
    D_1F800000.wC = FIELD_AT(self, int, 0x38);
    D_1F800000.p10 = (char *)self + 0x3C;
    D_1F800000.col = C4_800E0E70(FIELD_AT(FIELD_AT(self, void *, 0x28), C4_800E0E70, 0x14));
    D_1F800000.s48 = FIELD_AT(self, short, 0x76);
    D_1F800000.s4A = FIELD_AT(self, short, 0x6C);
    D_1F800000.s4C = FIELD_AT(self, short, 0x74);
    D_1F800000.mode = B2_800E0E70(a, FIELD_AT(o, short, 0x12));
    D_1F800000.s50 = 0;
    D_1F800000.s4E = FIELD_AT(self, short, 0x70);
    D_1F800000.b52 = FIELD_AT(self, unsigned char, 0x86);
}
