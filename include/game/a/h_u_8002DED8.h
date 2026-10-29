#ifndef GAME_A_H_U_8002DED8_H
#define GAME_A_H_U_8002DED8_H

/* Declarations for src/main/u_8002DED8.cpp only. */

struct VtE { short delta; short index; void *pfn; };
struct S_VObj { VtE *vt; };
#define VCALL0(o, k) ((void (*)(void *))(o)->vt[k].pfn)((char *)(o) + (o)->vt[k].delta)
struct S_8002E020 { char pad[0x64]; void *unk64; };
struct S_8002EA18 { void **vt; int unk4; short unk8; short unkA; };
EXTERN_C void *D_800117D4[];
EXTERN_C void *D_8001183C[];
struct S_Pt2 { short x, y; };
struct S_Blk8 { unsigned char b[8]; };
struct S_8002EA70_Src { char pad[0xC]; S_Blk8 blk; };
struct S_8002EA70 { void **vt; S_8002EA70_Src *src; S_Blk8 blk; };
struct S_8002E564 { int *p; int n; int *q; int buf[5]; };
EXTERN_C int func_8002A2D8(void *p);
struct S_8002EC40 { VtE *vt; void *unk4; };

struct S_Lnk64 { int a; S_Lnk64 *next; };
struct S_8002DF38 { char pad[0x64]; S_Lnk64 *unk64; };
EXTERN_C void *D_800117BC[];
struct S_8002E7A8 { void **vt; int a; void *unk8; void *unkC; };
struct P_TAG { unsigned addr : 24; unsigned len : 8; };
struct S_8002E898 { char pad[0x10]; unsigned int count; unsigned long *tab; };

struct S_IntVec { int *data; int count; };
struct S_NodeVec { S_Lnk64 **data; int count; S_Lnk64 *first() { return count ? data[0] : 0; } };
struct S_8002EB68_O { char pad[0x2C]; VtE *vt; };
struct S_8002EB68_M { int a; S_8002EB68_O *unk4; };
struct S_8002EB68 { int a; S_8002EB68_M *unk4; };
struct S_Rect { short x, y, w, h; S_Rect(short ax, short ay) { x = ax; y = ay; } };

EXTERN_C void *D_800117A4[];
struct S_8002E4E8 {
    void **vt;
    char pad4[0x14];
    int unk18;
    int unk1C;
    short unk20[6];
    int unk2C;
    int unk30;
    char pad34[0x30];
    void *unk64;
    S_8002E4E8(int a, int n, int b);
};

// Retail reaches D_800B4CF0 and D_800B4CFC from this file with the assembler macro (lui), not $gp.
EXTERN_C int D_800B4CF0 __attribute__((section(".data")));
EXTERN_C int D_800B4CFC __attribute__((section(".data")));
struct S_OT {
    void **vt;
    S_VObj *unk4;
    unsigned long *buf[2];
    int count;
    unsigned long *tab;
};

struct S_Arr5 {
    int *p;
    int n;
    int *q;
    int buf[5];
    void *operator new(unsigned int n) { return __builtin_new(n); }
    S_Arr5() { q = buf; p = q; func_800198E0(q, 5, 0); n = 0; }
};

struct S_Pt2h { short x, y; };
EXTERN_C S_Pt2h D_800B4CF8;
EXTERN_C S_Pt2h D_800B4CF4;

#endif /* GAME_A_H_U_8002DED8_H */
