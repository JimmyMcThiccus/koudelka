#ifndef GAME_A2B_A2B_H
#define GAME_A2B_A2B_H

/* Declarations for area main_a2b (u_8003C510). include/game/a2/ is read-only; new ones go here. */

struct S_A2B_B4ED8 { char pad[0x94]; int unk94; };
EXTERN_C S_A2B_B4ED8 *D_800B4ED8;
EXTERN_C int func_80048C30(void *a, void *b, void *c, int d, int e);
EXTERN_C void func_800601D8(void *, char *);
EXTERN_C int D_800B4D6C;
EXTERN_C char D_800B4D78[];
EXTERN_C void func_80028184();
EXTERN_C int D_800B4CF0;
struct S_A2B_Ent { int a, b, c, d; };
struct S_A2B_Buf { char pad[8]; short mode; };
#define E_(p, i) ((S_A2B_Ent *)((char *)(p) + (i) * 16 + 0xC))
struct S_A2B_Ch2 { signed char c[2]; S_A2B_Ch2() asm("func_800601C8"); S_A2B_Ch2(const S_A2B_Ch2 &) asm("func_80060200"); };
struct S_A2B_Str { char pad[0x10]; S_A2B_Ch2 *p; unsigned len; };
extern "C++" S_A2B_Ch2 f53AE4(S_A2B_Str *s, unsigned i) asm("func_80053AE4");
struct C_8005226C { C_8005226C(int a, void *b) asm("func_8005226C"); char pad[0x70]; };
EXTERN_C void func_8006BDE0(void *p);
EXTERN_C void func_8008EF40(int a);
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
EXTERN_C void func_8003FAEC(void *p, void *o, int a, int b);
EXTERN_C void func_8003E198(void *p, void *a, int b);
EXTERN_C void func_8003E124(void *p);
EXTERN_C void func_8004387C(void *p);
struct C_80052100 { C_80052100(int a, void *b, int c) asm("func_80052100"); char pad[0x70]; };
EXTERN_C void func_80052640(void *p, void *a);
struct S_A2B_Pt { short x, y; S_A2B_Pt(short a, short b) { x = a; y = b; } };
struct A2B_V53 : A2VPad<0x18> { virtual int s0(); virtual int s1(); virtual int s2(); virtual void s3(S_A2B_Pt); };
struct B_800538CC { B_800538CC(void *s, int n) asm("func_800538CC"); char pad[0x18]; void *vt; };
struct C_800545E0 : B_800538CC { int unk1C, unk20, unk24; C_800545E0(C_800545E0 *o) asm("func_800545E0"); };
extern "C++" void *f53BC0(void *p) asm("func_80053BC0");
EXTERN_C char *D_800A4578_p asm("D_800A4578");
struct S_A2B_988 { char pad[0x988]; };
EXTERN_C S_A2B_988 D_800AC8A0[];
struct C_80044BE4 : C_8001E40C { C_80044BE4() asm("func_80044BE4"); };
EXTERN_C void *D_80012794[];
EXTERN_C void *D_800127AC[];
extern "C++" void *f41CB8(void *p) asm("func_80041CB8");
EXTERN_C int func_80026014(int a);
EXTERN_C int func_800260A4(int a);
EXTERN_C int func_80094FD0(char *s);
struct S_A2B_X178 { int a, b, c, d; short s10, s12, s14; void init() { b = 0x1000; a = 0x1000; s14 = 0x2000; s10 = 0; s12 = 0; } };
struct S_A2B_V4 { int a, b, c, d; void init() { a = 0; b = 0; c = 0; d = 0; } };
struct C_8003D9FC : C_8001E40C {
    char pad11C[8]; S_A2B_V4 v124; int u134, u138, u13C; short u140, u142, u144; char name146[0x32];
    S_A2B_X178 x178; S_A2B_V4 v190; char u1A0;
    C_8003D9FC(int a, int b, char *s) asm("func_8003D9FC");
    C_8003D9FC(int a, int b, char *s, S_A2B_V4 *src) asm("func_8003DB1C");
};
extern "C++" void *f40294(void *p, int a) asm("func_80040294");
extern "C++" void *f4025C(void *p, int a, int b) asm("func_8004025C");
EXTERN_C int func_8003ED10(void *p, int b, int c, int d, int e);
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
EXTERN_C void func_80036D8C(void *p);
struct C_80054AF0 { C_80054AF0(int a) asm("func_80054AF0"); char pad[0x50]; };
EXTERN_C void func_80054EB4(void *p, int a, int b);
EXTERN_C void func_80054F30(void *p, int a, void *sv, int b);
EXTERN_C void func_80054E18(void *p, void *q);
EXTERN_C void func_80053CD8(void *p);
struct C_80054584b : C_80053928 { int u1c, u20, u24; C_80054584b(int a) asm("func_80054584"); };
EXTERN_C void func_800530B8(void *p, void *a);
EXTERN_C void func_8005388C(void *p, int a);
EXTERN_C void *D_800A4578_a[] asm("D_800A4578");
extern "C++" int f53874(void *p) asm("func_80053874");
extern "C++" int f53830(void *p) asm("func_80053830");
EXTERN_C void func_8002B174(void *a, void *b, int c);
EXTERN_C void ApplyRotMatrix(SVECTOR *v0, S_A2_V4 *v1);
extern "C++" void *f54584c(void *p, int a) asm("func_80054584");
extern "C++" void f53DDCb(void *a, void *b) asm("func_80053DDC");
extern "C++" void f53964(void *p, int a) asm("func_80053964");
extern "C++" void f538CC(void *p, int a, int b) asm("func_800538CC");
extern "C++" void f5457Cb(void *p, int a) asm("func_8005457C");
extern "C++" void f53FB0(void *p, int a, int b) asm("func_80053FB0");
extern "C++" void f53BCC(void *p, int a, int b) asm("func_80053BCC");
extern "C++" void f53CD8(void *p) asm("func_80053CD8");
#endif /* GAME_A2B_A2B_H */
