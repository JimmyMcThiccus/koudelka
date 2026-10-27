#ifndef MOVIE_H
#define MOVIE_H

#include "common.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

/* EXE globals. Declared as unsized arrays so they're reached with lui/%lo like
   retail (a sized small extern would get $gp, which the overlays never use). */
struct GameUnk8 { char pad[0x14]; void* x14; };
struct Game { s32 x0, x4; GameUnk8* x8; char pad[0x154 - 0xC]; char x154[0x1D2 - 0x154]; u8 x1D2; };
struct Sys { s32 x0, x4, x8; volatile u32 xC; char pad[0x44 - 0x10]; char* x44; };
EXTERN_C Sys D_800A4534;
EXTERN_C Game* D_800A4578[];

/* libgpu primitives */
struct RECT { s16 x, y, w, h; };
struct POLY_FT4 { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; };
struct SPRT { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; };

EXTERN_C s32 D_800B4CF0[]; /* current primitive buffer (0/1) */
EXTERN_C void* D_800CBA94[];
EXTERN_C void func_8005F1D8(void*, ...);

struct Unk800BBF74 { char pad[0x108]; s16 x108; };

struct Unk800B8B08 { s32 x0, x4, x8; };

struct Unk800B95C8 { char pad[0x28]; s32 x28; };

struct Unk800BDF78 { char pad[0x58]; s32 x58; };

struct Unk800C49B0 { char pad[0x82]; s8 x82; };

struct Unk800C5B70 { s32 x0, x4; };

EXTERN_C s32 D_800CBAE4[];

struct Unk800B9C34 { s16 x0, x2; };

struct Unk800B9C48 { s16 x0, x2, x4, x6; };

struct Unk800BA3E4 { char pad[8]; s16 x8; char pad2[0x3C-0xA]; s16 x3C, x3E; };

struct Unk800C3D08B { s16 x0; };
struct Unk800C3D08 { s32 x0; Unk800C3D08B* x4; };


struct Unk800B8E9C { char pad[0x40]; s32 x40; };

struct Unk800BE54C { char pad[0x64]; s16 x64; char pad2[0x6E-0x66]; s16 x6E; };

struct Unk800BCE7C { char pad[0x34]; s32 x34; char p2[0x40-0x38]; s32 x40; char p3[0x50-0x44]; s16 x50; };

struct Unk800BA50C { char pad[0x30]; RECT x30; };

struct Unk800C5B30 { char pad[0x58]; s32 x58; };
EXTERN_C void func_80054FE0(void*);

struct Unk800C3E10 { char pad[0x50]; s32 x50; void* x54; };
EXTERN_C void func_80025CE0(void*, void*, s32);

EXTERN_C void func_8001FC78(void*, s32, s32);


struct Unk800B98C8 { char pad[0x8]; s32 x8; };

struct Unk800C2D4C { char pad[0x5C]; s32 x5C; };

struct Unk800C30B0 { char pad[0x58]; s32 x58; };

struct Unk800C3D50 { char pad[0x38]; s32 x38; };

struct Unk800C4178 { char pad[0x54]; s32 x54; };

struct Unk800C420C { char pad[0x4C]; s32 x4C; };

struct Unk800C42B8 { char pad[0x48]; s32 x48; };

struct Unk800C4364 { char pad[0x44]; s32 x44; };

struct Unk800C4854 { char pad[0x78]; s32 x78; };

struct Unk800C49A4 { char pad[0x50]; s32 x50; };

struct Unk800B9CEC { s32 x0, x4; };

struct Unk800BA46C { s32 x0, x4; };

struct Unk800BA598 { s32 x0, x4; };

struct Unk800BA3F8 { char pad[8]; s16 x8; char pad2[0x40-0xA]; s16 x40, x42; };

struct Unk800BE568 { char pad[0x64]; s16 x64; char pad2[0x6E-0x66]; s16 x6E; };

EXTERN_C void func_8003546C(void*, void*);

EXTERN_C void func_800386B8(void*);

EXTERN_C void func_8001A610(void*, s32);

EXTERN_C void func_80054C34(void*);

EXTERN_C void func_8005F120(void*);

EXTERN_C void StFreeRing(void*);

struct Unk800CA86C { char pad[0x10C]; void* x10C; };
EXTERN_C void func_800BDDC8(void*, s32, s32);

struct Unk800BA40C { char pad[8]; s16 x8; char pad2[0x3C-0xA]; RECT x3C; RECT x44; };
EXTERN_C void func_800BA40C(Unk800BA40C*, RECT*);

struct Unk800BA438 { char pad[8]; s16 x8; char pad2[0x3C-0xA]; RECT x3C; RECT x44; };

struct Unk800BCE4CR { s32 a, b; };
struct Unk800BCE4C { char pad[0x14]; Unk800BCE4CR x14[3]; char p2[0x30-0x2C]; s32 x30; char p3[0x4C-0x34]; s32 x4C; };

EXTERN_C void func_8001AB50(void*, s32);

struct Unk800C3D5C { char pad[0x34]; s32 x34, x38; };
struct Unk800BF898 { char pad[0x78]; Unk800C3D5C* x78; };
EXTERN_C int func_800C3D5C(Unk800C3D5C*, s32);

struct DIRENTRY { char name[20]; s32 attr; s32 size; DIRENTRY* next; s32 head; char system[4]; };
EXTERN_C char D_800CBAAC[];
EXTERN_C void func_800C40D0(void*, void*);
EXTERN_C DIRENTRY* firstfile(char*, DIRENTRY*);

struct Unk800B988C { char pad[0x2C];
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual s32 v14(s32); };

struct Unk800B9848B { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
struct Unk800B9848 { s32 x0, x4; Unk800B9848B* x8; };

struct Unk800B977C { void* x0; };
EXTERN_C char D_800B6FBC[];

struct Unk800C3D1C { char pad[0x2C]; char* x2C; };


struct Unk800C9058 { char pad[0x20]; s32 x20; };
EXTERN_C void func_800550FC(void*, s32);

struct Unk800C1690C { char pad[0x18]; u16 x18; };
struct Unk800C1690B { char pad[0x120]; Unk800C1690C* x120; char p1[0x1BC - 0x124]; s32 x1BC, x1C0; char p2[0x204-0x1C4]; s32 x204, x208; };
EXTERN_C Unk800C1690B* D_800B4DD0[];

struct Unk800C407CH { s32 x0; char d[0x5C]; char e[0x20]; char rows[1][128]; };
struct Unk800C407C { char pad[0x44]; Unk800C407CH* x44; char* x48; char* x4C; s32 x50; char* x54; char* x58; char* x5C; };

struct Unk800C8A54R { char pad[0x1E]; u16 x1E; char p2[40-0x20]; };
struct Unk800C8A54 { Unk800C8A54R x0[1]; };
struct Unk800C8A54B { char pad[8]; u16 x8; };

struct Unk800B8F34B { s32 x0, x4; };
struct Unk800B8F34 { s32 x0; Unk800B8F34B* x4; char p2[0x40-8]; u8* x40; };

EXTERN_C void* D_800CBA90[];
EXTERN_C void* func_800BD988(void*);

struct Unk800B95DCB { virtual void v1(); virtual void v2(void*, s32); };
struct Unk800B95DC { s32 x0, x4; char x8[0x20]; };

struct Unk800C55F8 { char pad[0x6C]; s32 x6C; char x70[4]; };
EXTERN_C void func_8002B27C(void*, s32);
EXTERN_C void func_8006323C(void*);

struct Unk800BE368 { char pad[0x68]; s32 x68; };
EXTERN_C char D_800B4C48[];
EXTERN_C void func_8002DC34(void*, void*, s32);
EXTERN_C void func_80025714(void*, s32);

struct Unk800C2DA8B { s32 x0, x4; };
struct Unk800C2DA8 { s32 x0; Unk800C2DA8B* x4; char p2[0x58-8]; u32 x58; u8* x5C; };

struct Unk800C2D58B { s32 x0, x4; };
struct Unk800C2D58 { s32 x0; Unk800C2D58B* x4; char p2[0x58-8]; u32 x58; u8* x5C; };

struct Unk800C5A14 { char pad[0x50]; s32 x50, x54; void* x58; };
EXTERN_C void func_800648E8(void*, s32);

struct Unk800C6298R { u8 r, g, b, pad; u16 x, y; char p2[12]; };
struct Unk800C6298 { char pad[0x2C]; Unk800C6298R x2C[1]; };

struct Unk800C62E4R { u8 r, g, b, pad; u16 x, y; char p2[12]; };
struct Unk800C62E4 { char pad[0x2C]; Unk800C62E4R x2C[1]; };
struct Unk800C62E4B { char pad[5]; u8 x5, x6, x7; };

struct Unk800C8B24R { char pad[0x14]; u8 x14, x15, x16; char p2[40-0x17]; };
struct Unk800C8B24 { Unk800C8B24R x0[1]; };
struct Unk800C8B24B { char pad[5]; u8 x5, x6, x7; };

EXTERN_C void func_800279A8(void*);
EXTERN_C void func_800C5E34();
EXTERN_C void func_800566E4(void*);
EXTERN_C void func_80055330(s32);
EXTERN_C void func_8005549C(s32, void*, s32, s32);

struct Unk800B8AB4 { s32 x0, x4; void* x8; char p[0x30-0xC]; char x30[4]; };
EXTERN_C void* func_800B9B14(void*, Unk800B8AB4*, void*);
EXTERN_C void func_8002A110(void*);

struct Unk800B9790 { s32 x0, x4; void* x8; char p[0x30-0xC]; char x30[4]; };
EXTERN_C void* func_800BA498(void*, Unk800B9790*, void*);

struct Unk800C6330V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(s32, s32); };
struct Unk800C6330 : Unk800C6330V { char pad[0x28 - 4]; SPRT x28[2]; };

struct Unk800C9958V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(s32, s32); };
struct Unk800C9958 : Unk800C9958V { char pad[0x28 - 4]; SPRT x28[2]; };

struct Unk800C8BD0V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(s32, s32); };
struct Unk800C8BD0 : Unk800C8BD0V { char pad[0x10 - 4]; POLY_FT4 x10[2]; };

struct Unk800C8B74 { char pad[0x10]; POLY_FT4 x10[2]; };

struct Unk800BD928 { void* x0; };
EXTERN_C void DecDCToutCallback(void*);
EXTERN_C void func_80019920(void*, s32);

struct Unk800B97E4B { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); };
struct Unk800B97E4 { s32 x0, x4; Unk800B97E4B* x8; char pad[0x30 - 0xC]; RECT x30; };

struct Unk800BA534 { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(s32); virtual void v9(); virtual void v10(); virtual void v11(); virtual s32 v12(); };

struct Unk800BEED4B { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800BEED4 { char pad[0x64]; void* x64; Unk800BEED4B* x68; };
EXTERN_C void func_80036D8C(void*);
EXTERN_C void func_80048D2C(void*, s32);

struct Unk800C2CE4B { s32 x0, x4; };
struct Unk800C2CE4 { s32 x0; Unk800C2CE4B* x4; char pad[0x34 - 8]; s32 x34; };
EXTERN_C void func_800356F4(void*);
EXTERN_C int close(int);

struct Unk800B8F74B { s32 x0, x4; };
struct Unk800B8F74 { s32 x0; Unk800B8F74B* x4; char p2[0x40 - 8]; char* x40; };

struct Unk800BDE40B { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800BDE40 { char pad[0x44]; Unk800BDE40B* x44; s32 x48; };
EXTERN_C void func_800BDADC(void*, s32);
EXTERN_C void func_8001AA68(void*, s32);

struct Unk800C98EC { char pad[0x28]; SPRT x28[4]; };
struct Unk800C98ECB { char pad[5]; u8 x5, x6, x7; };

struct Unk800BE584V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(s32, s32); };
struct Unk800BE584 : Unk800BE584V { char pad[0x5A - 4]; s16 x5A, x5C; };

struct Unk800B9704 { void* x0; s32 x4; void* x8; };
EXTERN_C char D_800B6F34[], D_800B6F4C[], D_80012294[], D_80012224[];
EXTERN_C void func_80035304(void*, s32);

struct Unk800BDDC8 { char pad[0x20]; s16 x20; char p2[0x44 - 0x22]; void* x44; char p3[0x50 - 0x48]; void* x50; };
EXTERN_C void* func_800A0D2C(s32);
EXTERN_C s32 func_800B93D8(void*, s32, s32, s32);

struct Unk800C9874 { char pad[0x28]; SPRT x28[4]; };

struct Unk800CA7ECC { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800CA7EC { char pad[0x110]; Unk800CA7ECC* x110; };
struct Unk800CA7ECB { char pad[0x1A]; u8 x1A; };
EXTERN_C void func_800232A0(void*, void*);

struct Unk800B8EB8B { u16 x0; s16 x2; s32 x4; };
struct Unk800B8EB8 { s32 x0; Unk800B8EB8B* x4; char pad[0x40 - 8]; void* x40; void* x44; };
EXTERN_C s32 StGetNext(void*, void*);

struct Unk800B8FE0 { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(s32); };
struct Unk800B8FE0B : Unk800B8FE0 { char pad[0x35 - 4]; u8 x35; };
EXTERN_C void func_80036674(void*);

struct Unk800C3D90 { char pad[0x40]; char* x40; };
EXTERN_C s32 func_80094FD0(char*);
EXTERN_C void func_800A0D0C(void*);

struct Unk800C908C { char pad[0x20]; s32 x20; };
EXTERN_C void func_8002456C(void*);
EXTERN_C void func_80024524(void*);

struct Unk800B9C64E { void* x0; };
struct Unk800B9C64L { Unk800B9C64E* x0; s32 x4; };
struct Unk800B9C64H { Unk800B9C64L* x0; };
EXTERN_C void func_800BA438(Unk800BA438*, RECT*);
EXTERN_C void func_800BA50C(Unk800BA50C*, RECT*);

EXTERN_C s32 D_800CBA9C[], D_800CBAA0[], D_800CBAA4[], D_800CBAA8[];
EXTERN_C void func_80094990();
EXTERN_C void func_800949A0();
EXTERN_C s32 CloseEvent(s32);

struct Unk800C2DF4B { s32 x0, x4; };
struct Unk800C2DF4 { s32 x0; Unk800C2DF4B* x4; char p2[0x58 - 8]; u32 x58; char* x5C; };

struct Unk800C2E7CB { s32 x0, x4; };
struct Unk800C2E7C { s32 x0; Unk800C2E7CB* x4; char p2[0x58 - 8]; u32 x58; char* x5C; };

struct Unk800C4184R { s16 v[16]; };
struct Unk800C4184 { char pad[0x4C]; Unk800C4184R* x4C; };

struct Unk800BE5F8V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); };
struct Unk800BE5F8 : Unk800BE5F8V { char pad[0x5E - 4]; s16 x5E, x60, x62; };
struct Unk800BE5F8T { s32 a, b; };
EXTERN_C void func_8002972C(Unk800BE5F8T*, s32, s32, s32, s32);
EXTERN_C void func_80028D10(void*, Unk800BE5F8T*);
EXTERN_C void func_800198AC(Unk800BE5F8T*, s32);

struct Unk800C2F04B { s16 x0; s16 x2; s32 x4; };
struct Unk800C2F04 { s32 x0; Unk800C2F04B* x4; char p2[0x34 - 8]; s32 x34; char p3[0x44 - 0x38]; void* x44; };
EXTERN_C s32 func_800C40B8(void*);
EXTERN_C s32 read(s32, void*, s32);

struct Unk800C3024B { s16 x0; s16 x2; s32 x4; };
struct Unk800C3024 { s32 x0; Unk800C3024B* x4; char p2[0x34 - 8]; s32 x34; char p3[0x44 - 0x38]; void* x44; };
EXTERN_C s32 write(s32, void*, s32);

struct Unk800C4D5C { char pad[0x3C]; void* x3C; char p2[0x50 - 0x40]; s32 x50; char p3[0x80 - 0x54]; s8 x80, x81; };
EXTERN_C void func_80054FC0(void*);
EXTERN_C void* func_800C4F10(void*, s32, s32, s32, s32);
EXTERN_C void func_8005800C(void*, void*);

struct Unk800C8340E { s32 x0, x4; };
struct Unk800C8340L { Unk800C8340E* x0; };
struct Unk800C8340 { s32 x0, x4, x8; char p2[0x1C - 0xC]; u16 x1C; char p3[0x30 - 0x1E]; Unk800C8340L* x30; };
EXTERN_C void func_8005C088(void*, void*, s32);
EXTERN_C void* func_800C96C0(void*, s32);
EXTERN_C void func_80019A6C(Unk800C8340E*, void*, s32);
EXTERN_C void func_8002DA94(void*, void*);

struct Unk800CA894C { char pad[0x18]; virtual void v1(s32); };
struct Unk800CA894 { char pad[0x11C]; Unk800CA894C* x11C[23]; Unk800CA894C* x178; };

struct Unk800BE4B4T { void* x0; s32 x4; void* x8; s16 xC; s32 x10; };
struct Unk800BE4B4 { char pad[0x50]; char x50[8]; s16 x58; char p2[0x64 - 0x5A]; s16 x64; char p3[0x6C - 0x66]; s16 x6C, x6E; };
EXTERN_C char D_80010178[], D_80010338[], D_800A4544[];
EXTERN_C void func_8001D150(void*, void*);

struct Unk800BDEACT { void* x0; s32 x4; void* x8; s16 xC; s32 x10; };
struct Unk800BDEAC { char pad[0x3C]; s16 x3C; };

struct Unk800C8A90 { char pad[0x10]; POLY_FT4 x10[2]; };

struct Unk800C910C { char pad[0x20]; s32 x20; char p2[0x3C - 0x24]; void* x3C; };
struct Unk800C910CB { char pad[0x18]; u16 x18; };
EXTERN_C void func_80058270(void*, s32);
EXTERN_C s32 func_80058404(void*, s32);

struct Unk800CA59CT { void* x0; s32 x4; s16 x8, xA; s32 xC, x10; };
struct Unk800CA59C { char pad[0x108]; s16 x108; };
EXTERN_C char D_80010178[], D_80010300[], D_800102D0[];
EXTERN_C Unk800CA59CT* func_8001CA10(s32);
EXTERN_C void func_8001EFE4(void*, Unk800CA59CT*);
inline void Unk800CA59C_ctor1(Unk800CA59CT* t) { *(void* volatile*)&t->x0 = D_80010178; }
inline void Unk800CA59C_ctor2(Unk800CA59CT* t) { Unk800CA59C_ctor1(t); *(void* volatile*)&t->x0 = D_80010300; t->x8 = 2; t->xA = 2; t->x4 = 0; }
inline void Unk800CA59C_ctor3(Unk800CA59CT* t) { Unk800CA59C_ctor2(t); t->x10 = 0; t->xC = 0; t->x0 = D_800102D0; }

struct Unk800B9D18 { void* x0; s32 x4; s16 x8, xA; char pad[0x3C - 0xC]; RECT x3C; RECT x44; };
EXTERN_C char D_80010178[], D_800111BC[], D_800B71E4[];

struct Unk800C4218R { u8 b[64]; };
struct Unk800C4218 { char pad[0x48]; Unk800C4218R* x48; };

struct Unk800C42C4R { u8 b[128]; };
struct Unk800C42C4 { char pad[0x44]; Unk800C42C4R* x44; };

struct Unk800BE2C4V { virtual void v1(s32); };
struct Unk800BE2C4 { void* x0; char pad[0xC - 4]; void* xC; char p2[0x50 - 0x10]; void* x50; char p3[0x68 - 0x54]; Unk800BE2C4V* x68; };
EXTERN_C char D_800112F4[], D_800B76EC[], D_800B7704[], D_80011304[];
EXTERN_C void func_8001D024(void*, s32);

struct Unk800C6B94 { char pad[0x68]; s32 x68; char p2[0x4C4 - 0x6C]; char x4C4[4]; };
EXTERN_C void func_80054F30(void*, s32, RECT*, s32);
EXTERN_C void func_8005556C(s32, s32);

struct Unk800C40D0S5 { char c[5]; };
struct Unk800C40D0S12 { char c[12]; };
struct Unk800C40D0S8 { char c[8]; };
struct Unk800C40D0 { char pad[0x38]; s32 x38; char p2[0x40 - 0x3C]; Unk800C40D0S12* x40; };
EXTERN_C char D_800CBAAC[], D_800CBAB1[], D_800B7CAC[], D_800B7CB4[];

struct Unk800C71E8V { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C71E8 : Unk800C71E8V { char p2[0x4B8 - 0x1C]; s32 x4B8; };
struct Unk800C71E8B { char pad[0x18]; u16 x18; };

/* stream reader state; x4 points at its status block */
struct StreamStat { u16 x0; s16 x2; s32 x4; };
struct Unk800B93D8T { s32 x0; StreamStat* x4; char pad[0x30 - 8]; s32 x30; u8 x34, x35, x36, x37; char p3[0x3C - 0x38]; void* x3C; s32 x40, x44; };
EXTERN_C Unk800B93D8T* D_800B4D0C[];
EXTERN_C void StSetRing(void*, s32);
EXTERN_C void StSetStream(s32, s32, s32, void*, void*);
EXTERN_C void StClearRing();
EXTERN_C void func_8008CD1C(s32, s32);

struct Unk800BD83CL { void** x0; s32 x4; };
struct Unk800BD83CH { Unk800BD83CL* x0; };
struct Unk800BD83CS { Unk800BD83CL* x0; s32 x4; Unk800BD83CH x8; char p[0x20 - 0xC]; s32 x20, x24; };
EXTERN_C void func_80018AF4();
EXTERN_C void func_80018B18();
EXTERN_C void func_800BD008(void*);

struct Unk800C7F60 { s32 x0, x4, x8; char xC[4]; char p2[0x1C - 0x10]; u16 x1C; char p3[0x30 - 0x1E]; Unk800C8340L* x30; char p4[4]; char x38[4]; };
EXTERN_C void* func_800C83CC(void*, void*, s32, void*, s32);

struct Unk800C7740T { u16 x0, x2; s16 x4, x6; };
struct Unk800C7740O { char pad[0x2C]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); };
struct Unk800C7740E { char d[80]; };
struct Unk800C7740 { char pad[0x74]; Unk800C7740E x74[13]; char p2[0x4B4 - 0x74 - 13 * 80]; Unk800C7740O* x4B4; Unk800C7740O* x4B8; s32 x4BC, x4C0; };
EXTERN_C void func_80054054(Unk800C7740T*, void*);
EXTERN_C void func_80063BE4(Unk800C7740O*);
EXTERN_C void func_80063B14(Unk800C7740O*, Unk800C7740T*, s32);

EXTERN_C void _bu_init();
EXTERN_C s32 OpenEvent(u32, s32, s32, void (*)());
EXTERN_C void func_800C22E8();
EXTERN_C void func_800C2360();
EXTERN_C void func_800C23D8();
EXTERN_C void func_800C2450();

struct Unk800C6024V { virtual void v1(s32); };
EXTERN_C void* D_800CBACC[];
EXTERN_C Unk800C6024V* D_800CBAD0[];
EXTERN_C void* D_800B4C38[];
EXTERN_C void func_80024FEC(void*, s32);
EXTERN_C void func_8005F5F4(void*, void*, s32);
EXTERN_C void func_800215E8(void*, void*);

struct Unk800C95ECV { virtual void v1(s32); };
EXTERN_C void* D_800CBAE0[];
EXTERN_C Unk800C95ECV* D_800CBAE8[];

EXTERN_C void func_80019CFC(void*, s32);

struct Unk800C5A60WH { u16 w, h; };
struct Unk800C5A60 { char pad[0x3C]; void* x3C; char p2[0x50 - 0x40]; s32 x50, x54; void* x58; };
EXTERN_C Unk800C5A60WH* func_80054F28(void*);
EXTERN_C void* func_800646FC(void*, s32, RECT*, s32);
EXTERN_C void func_80064884(void*, s32, s32);

struct Unk800C5074V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(Unk800BE5F8T*); };
struct Unk800C5074L { s32 x0, x4; };
struct Unk800C5074H { Unk800C5074L* x0; };
struct Unk800C5074C { Unk800C5074L* x0; s32 x4; Unk800C5074H x8; };
struct Unk800C5074 { s32 x0, x4, x8; char pad[0x30 - 0xC]; Unk800C5074C* x30; };
EXTERN_C Unk800C5074V* func_80019F64(void*, s32);

struct Unk800C8594Q { s16 x0, y0, x1, y1, x2, y2, x3, y3; };
struct Unk800C8594 { char pad[0x10]; POLY_FT4 x10[2]; };

struct Unk800C10BCP { s16 x, y; };
inline void Unk800C10BC_set(Unk800C10BCP* t, s16 x, s16 y) { t->x = x; t->y = y; }
struct Unk800C10BC { char pad[0x240]; char x240[0x1C]; char x25C[4]; };
EXTERN_C void func_8005457C(void*, s32);
EXTERN_C void func_80053F48(void*, Unk800C10BCP);
EXTERN_C void func_80053CD8(void*);
EXTERN_C void func_80053BCC(void*, s32, s32);

#endif /* MOVIE_H */
