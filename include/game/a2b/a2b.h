#ifndef GAME_A2B_A2B_H
#define GAME_A2B_A2B_H

/* Declarations for area main_a2b (u_8003C510). include/game/a2/ is read-only; new ones go here. */

struct S_A2B_B4ED8 { char pad[0x94]; int unk94; };
EXTERN_C S_A2B_B4ED8 *D_800B4ED8;
EXTERN_C int func_80048C30(void *a, void *b, void *c, int d, int e);
EXTERN_C int D_800B4D6C;
EXTERN_C char D_800B4D78[];
EXTERN_C int D_800B4CF0;
struct S_A2B_Ent { int a, b, c, d; };
struct S_A2B_Buf { char pad[8]; short mode; };
#define E_(p, i) ((S_A2B_Ent *)((char *)(p) + (i) * 16 + 0xC))
struct S_A2B_Ch2 { signed char c[2]; S_A2B_Ch2() asm("func_800601C8"); S_A2B_Ch2(const S_A2B_Ch2 &) asm("func_80060200"); };
struct S_A2B_Str { char pad[0x10]; S_A2B_Ch2 *p; unsigned len; };
// Returns the class S_A2B_Ch2 by value; exe.h spells out the hidden return slot instead.
extern "C++" S_A2B_Ch2 f53AE4(S_A2B_Str *s, unsigned i) asm("func_80053AE4");
struct C_8005226C { C_8005226C(int a, void *b) asm("func_8005226C"); char pad[0x70]; };
EXTERN_C void *D_80012FC0[];
EXTERN_C void *D_80013038[];
EXTERN_C void *D_80013548[];
EXTERN_C void *D_800135C0[];
struct S_A2B_PolyG3 { unsigned char tag[3]; unsigned char len; unsigned char r0, g0, b0, code; char rest[0x14]; };
struct S_A2B_G3x2 { S_A2B_PolyG3 p[2]; };
struct S_A2B_B3 : C_800497FC {
    char pad10[8]; S_A2B_G3x2 m;
    S_A2B_B3() {
        S_A2B_PolyG3 *r; S_A2B_PolyG3 *q; int i;
        r = m.p; q = r; i = 2;
        while (i--) { q->len = 6; q->code = 0x30; q++; }
        r[0].len = 6; r[0].code = 0x30; r[1].code = 0x30; r[1].len = 6;
        vt = D_80012F50;
    }
};
struct S_A2B_Col3 { unsigned int c[3]; S_A2B_Col3() asm("func_800497A8"); };
struct C_8004BD84 : S_A2B_B3 { S_A2B_Col3 col; C_8004BD84() asm("func_8004BD84"); };
struct C_8004C254 : S_A2B_B3 { unsigned int rgb; C_8004C254() asm("func_8004C254"); };
struct S_A2B_PolyG4 { unsigned char tag[3]; unsigned char len; unsigned char r0, g0, b0, code; char rest[0x1C]; };
struct S_A2B_G4x2 { S_A2B_PolyG4 p[2]; };
struct S_A2B_B4 : C_8004CF20 {
    char pad10[0xC]; S_A2B_G4x2 m;
    S_A2B_B4() {
        S_A2B_PolyG4 *r; S_A2B_PolyG4 *q; int i;
        r = m.p; q = r; i = 2;
        while (i--) { q->len = 8; q->code = 0x38; q++; }
        r[0].len = 8; r[0].code = 0x38; r[1].code = 0x38; r[1].len = 8;
        vt = D_800134D8;
    }
};
struct S_A2B_Col4 { unsigned int c[4]; S_A2B_Col4() asm("func_8004CECC"); };
struct C_8004F368 : S_A2B_B4 { S_A2B_Col4 col; C_8004F368() asm("func_8004F368"); };
struct C_8004F924 : S_A2B_B4 { unsigned int rgb; C_8004F924() asm("func_8004F924"); };
struct C_8004EDFC : C_8004CF20 { char pad10[0xC]; S_A2B_G4x2 m; C_8004EDFC() asm("func_8004EDFC"); };
struct C_8004B8F8 : C_800497FC { char pad10[8]; S_A2B_G3x2 m; C_8004B8F8() asm("func_8004B8F8"); };
// prelude
EXTERN_C void *D_800B4D38;
EXTERN_C void func_80044C7C(void *p, void *a);
EXTERN_C void func_8003FAEC(void *p, void *o, short a, short b);
EXTERN_C void func_8004387C(void *p);
struct C_80052100 { C_80052100(int a, void *b, int c) asm("func_80052100"); char pad[0x70]; };
EXTERN_C void func_80052640(void *p, void *a);
struct S_A2B_Pt { short x, y; S_A2B_Pt(short a, short b) { x = a; y = b; } };
struct A2B_V53 : A2VPad<0x18> { virtual int s0(); virtual int s1(); virtual int s2(); virtual void s3(S_A2B_Pt); };
struct B_800538CC { B_800538CC(void *s, int n) asm("func_800538CC"); char pad[0x18]; void *vt; };
struct C_800545E0 : B_800538CC { int unk1C, unk20, unk24; C_800545E0(C_800545E0 *o) asm("func_800545E0"); };
// The definition returns int; this caller uses the result as a pointer.
extern "C++" void *f53BC0(void *p) asm("func_80053BC0");
EXTERN_C char *D_800A4578_p asm("D_800A4578");
struct S_A2B_988 { char pad[0x988]; };
EXTERN_C S_A2B_988 D_800AC8A0[];
struct C_80044BE4 : C_8001E40C { C_80044BE4() asm("func_80044BE4"); };
EXTERN_C void *D_80012794[];
EXTERN_C void *D_800127AC[];
extern "C++" void *f41CB8(void *p) asm("func_80041CB8");
struct S_A2B_X178 { int a, b, c, d; short s10, s12, s14; void init() { b = 0x1000; a = 0x1000; s14 = 0x2000; s10 = 0; s12 = 0; } };
struct S_A2B_V4 { int a, b, c, d; void init() { a = 0; b = 0; c = 0; d = 0; } };
struct C_8003D9FC : C_8001E40C {
    char pad11C[8]; S_A2B_V4 v124; int u134, u138, u13C; short u140, u142, u144; char name146[0x32];
    S_A2B_X178 x178; S_A2B_V4 v190; char u1A0;
    C_8003D9FC(int a, int b, char *s) asm("func_8003D9FC");
    C_8003D9FC(int a, int b, char *s, S_A2B_V4 *src) asm("func_8003DB1C");
};
// Defined in u_8003F7E8 with short arguments and a char * result; these callers pass ints.
extern "C++" void *f40294(void *p, int a) asm("func_80040294");
extern "C++" void *f4025C(void *p, int a, int b) asm("func_8004025C");
EXTERN_C int func_8003ED10(void *p, int b, int c, int d, int e);
// The defining unit types the argument as S_80053BB4, its callers as S_A2B_Str: the same object.
extern "C++" int f53BB4(S_A2B_Str *s) asm("func_80053BB4");
struct S_A2B_Q16 { int a, b, c, d; };
struct S_A2B_Q16o { char pad[0xC]; S_A2B_Q16 q; };
struct S_A2B_PTag { unsigned addr : 24; unsigned len : 8; };
struct S_A2B_OtB {
    char pad0[0x10];
    unsigned int count;
    unsigned long *tab;
    int add(S_A2B_PTag *prim, unsigned int i)
    {
        if (i && i < count) {
            prim->addr = tab[i];
            tab[i] = (unsigned long)prim & 0x00ffffff;
            return 1;
        }
        return 0;
    }
};
EXTERN_C S_A2B_OtB *D_800B4CFC;
#define PB_(s) ((unsigned char *)(s)->p)
struct S_A2B_StrC { char pad[0x10]; S_A2_Ch *p; unsigned len; };
EXTERN_C void *func_80048D64(void *p, int a, int b, int c, int d, int e);
struct C_80054AF0 { C_80054AF0(int a) asm("func_80054AF0"); char pad[0x50]; };
struct C_80054584b : C_80053928 { int u1c, u20, u24; C_80054584b(int a) asm("func_80054584"); };
EXTERN_C void func_800530B8(void *p, void *a);
EXTERN_C void *D_800A4578_a[] asm("D_800A4578");
// These callers hold the second argument (a pointer) as an int.
extern "C++" void f538CC(void *p, int a, int b) asm("func_800538CC");
extern "C++" void f53BCC(void *p, int a, int b) asm("func_80053BCC");
struct S_A2B_VEnt { short d; short i; void *f; };
struct S_A2B_VTab50 { S_A2B_VEnt e[10]; };
struct S_A2B_VBp { S_A2B_VEnt *vt; };
struct S_A2B_VObj { void *vptr; int unk4; };
EXTERN_C const S_A2B_VTab50 D_80013A38_t asm("D_80013A38");
EXTERN_C void *D_80013A88[];
EXTERN_C void *D_80013940[];
struct S_A2B_C68 { S_A2B_VBp *vb; char pad4[0x28]; void **vt2C; char pad30[0x8]; int i38; char pad3C[0x4]; void **vt40; int i44; char pad48[0xC]; int i54, i58, i5C, i60, i64; S_A2B_VObj vobj; };
struct S_A2B_CpB2C { void *vtbl; int unk4; short unk8, unkA; S_A2B_Q16 arr[2]; };
extern "C++" S_A2B_CpB2C *f53360(S_A2B_CpB2C *p) asm("func_80053360");
EXTERN_C void *func_80049250(void *a, void *b, void *c);
struct S_A2B_E2D0 : S_A2_X0 {
    unsigned short u8; short uA; void *uC; int u10;
    void init(int a, int b, void *c, int d) { vt = D_80010178; u4 = 0; vt = D_80010300; u8 = a; uA = b; u10 = d; uC = c; vt = D_800102D0; }
};
EXTERN_C S_A2_V4 func_8004463C(S_A2_V4 *a, S_A2_V4 *b);
EXTERN_C short D_800B4D34;
extern "C++" void *f1A744(void *p, void *a) asm("func_8001A744");
struct S_A2B_Del12 { void *vt; int kind; void *obj; S_A2B_Del12(int k, void *o) { vt = D_800127E4; kind = k; obj = o; } };
#endif /* GAME_A2B_A2B_H */
