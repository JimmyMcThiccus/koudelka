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

struct Unk800C3E10 { char pad[0x50]; s32 x50; void* x54; };



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







struct Unk800CA86C { char pad[0x10C]; void* x10C; };
EXTERN_C void func_800BDDC8(void*, s32, s32);

struct Unk800BA40C { char pad[8]; s16 x8; char pad2[0x3C-0xA]; RECT x3C; RECT x44; };
EXTERN_C void func_800BA40C(Unk800BA40C*, RECT*);

struct Unk800BA438 { char pad[8]; s16 x8; char pad2[0x3C-0xA]; RECT x3C; RECT x44; };

struct Unk800BCE4CR { s32 a, b; };
struct Unk800BCE4C { char pad[0x14]; Unk800BCE4CR x14[3]; char p2[0x30-0x2C]; s32 x30; char p3[0x4C-0x34]; s32 x4C; };


struct Unk800C3D5C { char pad[0x34]; s32 x34, x38; };
struct Unk800BF898 { char pad[0x78]; Unk800C3D5C* x78; };
EXTERN_C int func_800C3D5C(Unk800C3D5C*, s32);

struct DIRENTRY { char name[20]; s32 attr; s32 size; DIRENTRY* next; s32 head; char system[4]; };
EXTERN_C char D_800CBAAC[];
EXTERN_C void func_800C40D0(void*, void*);

struct Unk800B988C { char pad[0x2C];
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual s32 v14(s32); };

struct Unk800B9848B { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
struct Unk800B9848 { s32 x0, x4; Unk800B9848B* x8; };

struct Unk800B977C { void* x0; };
EXTERN_C char D_800B6FBC[];

struct Unk800C3D1C { char pad[0x2C]; char* x2C; };


struct Unk800C9058 { char pad[0x20]; s32 x20; };

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
EXTERN_C void DecDCTReset(s32);
/* x0 and x8 are the virtual-base pointers of two bases sharing the list at xC
   (see func_800BD83C); the ctor sets them without the in_chrg protocol. */
struct L800BD988 { char d[0x14]; };
struct Unk800BD988 { void* x0; s32 x4; void* x8; L800BD988 xC; s32 x20, x24; Unk800BD988(); };

struct Unk800B95DCB { virtual void v1(); virtual void v2(void*, s32); };
struct Unk800B95DC { s32 x0, x4; char x8[0x20]; };

struct Unk800C55F8 { char pad[0x6C]; s32 x6C; char x70[4]; };

struct Unk800BE368 { char pad[0x68]; s32 x68; };
EXTERN_C char D_800B4C48[];

struct Unk800C2DA8B { s32 x0, x4; };
struct Unk800C2DA8 { s32 x0; Unk800C2DA8B* x4; char p2[0x58-8]; u32 x58; u8* x5C; };

struct Unk800C2D58B { s32 x0, x4; };
struct Unk800C2D58 { s32 x0; Unk800C2D58B* x4; char p2[0x58-8]; u32 x58; u8* x5C; };

struct Unk800C5A14 { char pad[0x50]; s32 x50, x54; void* x58; };

struct Unk800C6298R { u8 r, g, b, pad; u16 x, y; char p2[12]; };
struct Unk800C6298 { char pad[0x2C]; Unk800C6298R x2C[1]; };

struct Unk800C62E4R { u8 r, g, b, pad; u16 x, y; char p2[12]; };
struct Unk800C62E4 { char pad[0x2C]; Unk800C62E4R x2C[1]; };
struct Unk800C62E4B { char pad[5]; u8 x5, x6, x7; };

struct Unk800C8B24R { char pad[0x14]; u8 x14, x15, x16; char p2[40-0x17]; };
struct Unk800C8B24 { Unk800C8B24R x0[1]; };
struct Unk800C8B24B { char pad[5]; u8 x5, x6, x7; };

EXTERN_C void func_800C5E34();

struct Unk800B8AB4 { s32 x0, x4; void* x8; char p[0x30-0xC]; char x30[4]; };
EXTERN_C void* func_800B9B14(void*, Unk800B8AB4*, void*);

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

struct Unk800B97E4B { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); };
struct Unk800B97E4 { s32 x0, x4; Unk800B97E4B* x8; char pad[0x30 - 0xC]; RECT x30; };

struct Unk800BA534 { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(s32); virtual void v9(); virtual void v10(); virtual void v11(); virtual s32 v12(); };

struct Unk800BEED4B { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800BEED4 { char pad[0x64]; void* x64; Unk800BEED4B* x68; };

struct Unk800C2CE4B { s32 x0, x4; };
struct Unk800C2CE4 { s32 x0; Unk800C2CE4B* x4; char pad[0x34 - 8]; s32 x34; };

struct Unk800B8F74B { s32 x0, x4; };
struct Unk800B8F74 { s32 x0; Unk800B8F74B* x4; char p2[0x40 - 8]; char* x40; };

struct Unk800BDE40B { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800BDE40 { char pad[0x44]; Unk800BDE40B* x44; s32 x48; };
EXTERN_C void func_800BDADC(void*, s32);

struct Unk800C98EC { char pad[0x28]; SPRT x28[4]; };
struct Unk800C98ECB { char pad[5]; u8 x5, x6, x7; };

struct Unk800BE584V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(s32, s32); };
struct Unk800BE584 : Unk800BE584V { char pad[0x5A - 4]; s16 x5A, x5C; };

struct Unk800B9704 { void* x0; s32 x4; void* x8; };
EXTERN_C char D_800B6F34[], D_800B6F4C[], D_80012294[], D_80012224[];

struct Unk800BDDC8 { char pad[0x20]; s16 x20; char p2[0x44 - 0x22]; void* x44; char p3[0x50 - 0x48]; void* x50; };
EXTERN_C s32 func_800B93D8(void*, s32, s32, s32);

struct Unk800C9874 { char pad[0x28]; SPRT x28[4]; };

struct Unk800CA7ECC { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800CA7EC { char pad[0x110]; Unk800CA7ECC* x110; };
struct Unk800CA7ECB { char pad[0x1A]; u8 x1A; };

struct Unk800B8EB8B { u16 x0; s16 x2; s32 x4; };
struct Unk800B8EB8 { s32 x0; Unk800B8EB8B* x4; char pad[0x40 - 8]; void* x40; void* x44; };

struct Unk800B8FE0 { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(s32); };
struct Unk800B8FE0B : Unk800B8FE0 { char pad[0x35 - 4]; u8 x35; };

struct Unk800C3D90 { char pad[0x40]; char* x40; };

struct Unk800C908C { char pad[0x20]; s32 x20; };

struct Unk800B9C64E { void* x0; };
struct Unk800B9C64L { Unk800B9C64E* x0; s32 x4; };
struct Unk800B9C64H { Unk800B9C64L* x0; };
EXTERN_C void func_800BA438(Unk800BA438*, RECT*);
EXTERN_C void func_800BA50C(Unk800BA50C*, RECT*);

EXTERN_C s32 D_800CBA9C[], D_800CBAA0[], D_800CBAA4[], D_800CBAA8[];

struct Unk800C2DF4B { s32 x0, x4; };
struct Unk800C2DF4 { s32 x0; Unk800C2DF4B* x4; char p2[0x58 - 8]; u32 x58; char* x5C; };

struct Unk800C2E7CB { s32 x0, x4; };
struct Unk800C2E7C { s32 x0; Unk800C2E7CB* x4; char p2[0x58 - 8]; u32 x58; char* x5C; };

struct Unk800C4184R { s16 v[16]; };
struct Unk800C4184 { char pad[0x4C]; Unk800C4184R* x4C; };

struct Unk800BE5F8V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); };
struct Unk800BE5F8 : Unk800BE5F8V { char pad[0x5E - 4]; s16 x5E, x60, x62; };
struct Unk800BE5F8T { s32 a, b; };

struct Unk800C2F04B { s16 x0; s16 x2; s32 x4; };
struct Unk800C2F04 { s32 x0; Unk800C2F04B* x4; char p2[0x34 - 8]; s32 x34; char p3[0x44 - 0x38]; void* x44; };
EXTERN_C s32 func_800C40B8(void*);

struct Unk800C3024B { s16 x0; s16 x2; s32 x4; };
struct Unk800C3024 { s32 x0; Unk800C3024B* x4; char p2[0x34 - 8]; s32 x34; char p3[0x44 - 0x38]; void* x44; };

struct Unk800C4D5C { char pad[0x3C]; void* x3C; char p2[0x50 - 0x40]; s32 x50; char p3[0x80 - 0x54]; s8 x80, x81; };

struct Unk800C8340E { s32 x0, x4; };
struct Unk800C8340L { Unk800C8340E* x0; };
struct Unk800C8340 { s32 x0, x4, x8; char p2[0x1C - 0xC]; u16 x1C; char p3[0x30 - 0x1E]; Unk800C8340L* x30; };
EXTERN_C void* func_800C96C0(void*, s32);

struct Unk800CA894C { char pad[0x18]; virtual void v1(s32); };
struct Unk800CA894 { char pad[0x11C]; Unk800CA894C* x11C[23]; Unk800CA894C* x178; };

struct Unk800BE4B4T { void* x0; s32 x4; void* x8; s16 xC; s32 x10; };
struct Unk800BE4B4 { char pad[0x50]; char x50[8]; s16 x58; char p2[0x64 - 0x5A]; s16 x64; char p3[0x6C - 0x66]; s16 x6C, x6E; };
EXTERN_C char D_80010178[], D_80010338[], D_800A4544[];

struct Unk800BDEACT { void* x0; s32 x4; void* x8; s16 xC; s32 x10; };
struct Unk800BDEAC { char pad[0x3C]; s16 x3C; };

struct Unk800C8A90 { char pad[0x10]; POLY_FT4 x10[2]; };

struct Unk800C910C { char pad[0x20]; s32 x20; char p2[0x3C - 0x24]; void* x3C; };
struct Unk800C910CB { char pad[0x18]; u16 x18; };

struct Unk800CA59CT { void* x0; s32 x4; s16 x8, xA; s32 xC, x10; };
struct Unk800CA59C { char pad[0x108]; s16 x108; };
EXTERN_C char D_80010178[], D_80010300[], D_800102D0[];
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

struct Unk800C6B94 { char pad[0x68]; s32 x68; char p2[0x4C4 - 0x6C]; char x4C4[4]; };

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
struct StreamHdr { s32 x0, x4; u32 x8; };
struct StreamV { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800B93D8T : StreamV { StreamStat* x4; char p0[0x24 - 8]; s32 x24; u32 x28; char p1[0x30 - 0x2C]; s32 x30; u8 x34, x35, x36, x37; s16 x38, x3A; void* x3C; StreamHdr* x40; void* x44; u32 x48; };
EXTERN_C Unk800B93D8T* D_800B4D0C[];

struct Unk800BD83CL { void** x0; s32 x4; };
struct Unk800BD83CH { Unk800BD83CL* x0; };
struct Unk800BD83CS { Unk800BD83CL* x0; s32 x4; Unk800BD83CH x8; char p[0x20 - 0xC]; s32 x20, x24; };
EXTERN_C void func_800BD008(void*);

struct Unk800C7F60 { s32 x0, x4, x8; char xC[4]; char p2[0x1C - 0x10]; u16 x1C; char p3[0x30 - 0x1E]; Unk800C8340L* x30; char p4[4]; char x38[4]; };

struct Unk800C7740T { u16 x0, x2; s16 x4, x6; };
struct Unk800C7740O { char pad[0x2C]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); };
struct Unk800C7740E { char d[80]; };
struct Unk800C7740 { char pad[0x74]; Unk800C7740E x74[13]; char p2[0x4B4 - 0x74 - 13 * 80]; Unk800C7740O* x4B4; Unk800C7740O* x4B8; s32 x4BC, x4C0; };

EXTERN_C void func_800C22E8();
EXTERN_C void func_800C2360();
EXTERN_C void func_800C23D8();
EXTERN_C void func_800C2450();

struct Unk800C6024V { virtual void v1(s32); };
EXTERN_C void* D_800CBACC[];
EXTERN_C Unk800C6024V* D_800CBAD0[];
EXTERN_C void* D_800B4C38[];

struct Unk800C95ECV { virtual void v1(s32); };
EXTERN_C void* D_800CBAE0[];
EXTERN_C Unk800C95ECV* D_800CBAE8[];


struct Unk800C5A60WH { u16 w, h; };
struct Unk800C5A60 { char pad[0x3C]; void* x3C; char p2[0x50 - 0x40]; s32 x50, x54; void* x58; };

struct Unk800C5074V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(Unk800BE5F8T*); };
struct Unk800C5074L { s32 x0, x4; };
struct Unk800C5074H { Unk800C5074L* x0; };
struct Unk800C5074C { Unk800C5074L* x0; s32 x4; Unk800C5074H x8; };
struct Unk800C5074 { s32 x0, x4, x8; char pad[0x30 - 0xC]; Unk800C5074C* x30; };

struct Unk800C8594Q { s16 x0, y0, x1, y1, x2, y2, x3, y3; };
struct Unk800C8594 { char pad[0x10]; POLY_FT4 x10[2]; };

struct Unk800C10BCP { s16 x, y; };
inline void Unk800C10BC_set(Unk800C10BCP* t, s16 x, s16 y) { t->x = x; t->y = y; }
struct Unk800C10BC { char pad[0x240]; char x240[0x1C]; char x25C[4]; };

struct Unk800C5510 { char pad[0x20]; s32 x20; char p2[0x68 - 0x24]; Unk800BF898* x68; Unk800C7740O* x6C; char x70[0xC0 - 0x70]; char xC0[4]; };
EXTERN_C char D_800B7F64[];

struct Unk800B9060M { u8 a, b; };
struct Unk800B9060 { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(Unk800B9060M*); };
struct Unk800B9060B : Unk800B9060 { char pad[0x24 - 4]; s32 x24; char p2[0x30 - 0x28]; s32 x30; s8 x34, x35, x36; u8 x37; char p3[0x48 - 0x38]; s32 x48; };

struct Unk800B9B48L { s32 x0, x4; };
struct Unk800B9B48N { s32 x0; void* x4; };
struct Unk800B9B48Q { char pad[0x64]; void* x64; };
struct Unk800B9B48W { char pad[0x1C]; u16 x1C; };
struct Unk800B9B48V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(Unk800B9B48Q*); };
struct Unk800B9B48 : Unk800B9B48V { Unk800B9B48W* x4; RECT x8; Unk800B9B48L* x10; char p2[0x30 - 0x14]; RECT x30; };

struct Unk800BE1CCS { char pad[0x64]; void* x64; };
struct Unk800BE1CC { void* x0; void* x4; char p1[0xC - 8]; void* xC; char p2[0x50 - 0x10]; void* x50; char p3[0x5A - 0x54]; s16 x5A, x5C; char p4[0x68 - 0x5E]; s32 x68; s16 x6C; s16 x6E; s16 x70; };
EXTERN_C char D_80010348[], D_800112F4[], D_800B76EC[], D_800B7704[];

EXTERN_C void func_800BCEA0(void*);

struct Unk800BE3B4T { void* x0; s32 x4; void* x8; s16 xC; s32 x10; };
struct Unk800BE3B4V { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); };
struct Unk800BE3B4 : Unk800BE3B4V { char pad[0x50 - 4]; char x50[8]; s16 x58; char p1[0x5E - 0x5A]; s16 x5E, x60, x62, x64; char p3[0x6C - 0x66]; s16 x6C, x6E; };

struct Unk800C8894UV { u8 u, v; };
struct Unk800C8894C { virtual void v1(); virtual void v2(); virtual s32 v3(); };
struct Unk800C8894CC : Unk800C8894C { u16 x4; u16 x6; u16 x8; };
struct Unk800C8894B { char pad[0xC]; Unk800C8894CC* xC; s16 x10, x12; char p2[0x1C - 0x14]; u16 x1C; };
struct Unk800C8894 { char pad[0x10]; POLY_FT4 x10[2]; u16 x60; };
inline void Unk800C8894_set(Unk800C8894UV* t, s32 u, s32 v) { t->u = u; t->v = v; }

struct Unk800C01C4OB { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C01C4O : Unk800C01C4OB { char p2[0x254 - 0x1C]; };
struct Unk800C01C4 { char pad[0x1C]; void* x1C; char p1[0x74 - 0x20]; s32 x74; char p2[0x18C - 0x78]; s32 x18C; char p3[0x278 - 0x190]; Unk800C01C4O x278[15]; };
struct Unk800C01C4B { char pad[0x18]; u16 x18; };
EXTERN_C s32 D_800B4D90[];

struct Unk800C3F68X { virtual void v1(s32); };
struct Unk800C3F68EV { virtual void v1(); virtual void v2(); };
struct Unk800C3F68E : Unk800C3F68EV { u16 x4, x6, x8, xA; Unk800C3F68X* xC; };
struct Unk800C3F68 { char pad[0x30]; s32 x30; };
EXTERN_C void* D_800B4C18[];

struct Unk800B92B8T { void* x0; s32 x4; void* x8; s16 xC; s32 x10; };

struct Unk800B9208V { virtual void v1(s32); };
struct Unk800B9208L { s32 x0, x4; };
struct Unk800B9208G { Unk800B9208L* x0; };
struct Unk800B9208S { virtual void v1(); virtual void v2(); virtual void v3(); };
EXTERN_C Unk800B9208G D_800AC854[];

struct Unk800C40B8 { char pad[0x50]; s32 x50; s32 x54; s32 x58; };

/* func_800BA498 */
struct Unk800BA498E { s16 delta; s16 index; void (*pfn)(); };
struct Unk800BA498 { void* x0; char pad[0x30 - 4]; RECT x30; };
EXTERN_C void func_800BA5A4();
EXTERN_C void func_800BA534(Unk800BA534*);

/* func_800B9640 */
EXTERN_C char D_80012154[], D_8001201C[], D_80012034[];
/* stream object ctor (in_chrg form): StreamStat is the virtual base at 0x4C, x4 its pointer */
struct Unk800B9640 { void* x0; StreamStat* x4; void* x8; void* xC; char x10[0x28 - 0x10]; s32 x28, x2C; char p2[0x3C - 0x30]; s32 x3C, x40, x44; char p3[0x4C - 0x48]; StreamStat x4C; };
// func_800198E0 (list ctor) really returns its this: the call must be a call_value (result unused) for the
// trailing stores to go through $v0, hence the cast below; declaring it `void* func_800198E0(void*, s32, s32)` in movie.h would also work.

/* func_800B9B14 */
/* GCC 2.x vtable entry: call pfn with this + delta */
struct Unk800B9B14E { s16 delta; s16 index; void (*pfn)(); };
EXTERN_C void func_800B9CF8(void*);
EXTERN_C void func_800B9B48(Unk800B9B48*, Unk800B9B48Q*);
EXTERN_C Unk800B9C34* func_800B9C34(Unk800B9C34*);
EXTERN_C Unk800B9C48* func_800B9C48(Unk800B9C48*);
EXTERN_C void func_800B9C64(char*, RECT*);
EXTERN_C void func_800BA534(Unk800BA534*);
// the EXE functions above are declared `()` only to take their address in the vtable; if another landed function
// declares one with parameters, drop it here. func_800BA498 (base ctor) returns this, as movie.h already says.

/* func_800C2F90 */
struct Unk800C2F90B { s16 x0; s16 x2; s32 x4; };
struct Unk800C2F90 { s32 x0; Unk800C2F90B* x4; char p2[0x34 - 8]; s32 x34; char p3[0x44 - 0x38]; void* x44; char p4[0x50 - 0x48]; s32 x50; };
// storing D_800CBA94 through a local pointer makes the MEM non-"in struct", so GCC lets the p->x loads move above it

/* func_800B98D4 */
struct Unk800B98D4E { s16 delta; s16 index; void (*pfn)(); };
struct Unk800B98D4T { Unk800B98D4E e[10]; };
struct Unk800B98D4V { const void* vptr; s32 x4; };
struct Unk800B98D4 { Unk800B98D4V* x0; char pad[0x2C - 4]; const void* x2C; RECT x30; Unk800B98D4V x38; };
EXTERN_C const Unk800B98D4T D_800B6FF4;
EXTERN_C char D_800B7044[], D_800104A8[];

/* func_800B9E78 */
struct Unk800B9E78E { s32 d[6]; };
/* same object as Unk800B9D18 (its ctor); this is its clone: new T(*this) with the copy ctor inlined */
struct Unk800B9E78 { void* x0; s32 x4; s16 x8, xA; Unk800B9E78E xC[2]; RECT x3C; RECT x44; };

/* func_800BDC88 */
struct Unk800BDC88O { virtual void v1(s32); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(s32); };
struct Unk800BDC88M { void* x0; void* x4; };
struct Unk800BDC88 { void* x0; void* x4; void* x8; char p[0x30 - 0xC]; Unk800BDC88M x30; char p2[0x44 - 0x38]; Unk800BDC88O* x44; Unk800BDC88O* x48; char p3[4]; void* x50; };
EXTERN_C char D_800B76B4[], D_800B767C[], D_800B7664[], D_800B76C4[], D_800B76D4[], D_800101C0[], D_800101B0[];

/* func_800C3E38 */
struct Unk800C3E38O { virtual void v1(s32); virtual void v2(s32); };
struct Unk800C3E38L { Unk800C3E38O** x0; s32 x4; };
struct Unk800C3E38H { Unk800C3E38L* x0; };
struct Unk800C3E38 { s32 x0; StreamStat* x4; char p[0xC - 8]; Unk800C3E38H xC; char p2[0x2C - 0x10]; Unk800C3E38O* x2C; s32 x30; };

/* func_800C8114 */
struct Unk800C8114E { s16 delta; s16 index; void (*pfn)(); };
struct Unk800C8114T { Unk800C8114E e[10]; };
/* virtual base (List-like) at 0x38: inline ctor D_80010178, x4 = 0, D_800104A8 */
struct Unk800C8114V { const void* vptr; s32 x4; };
struct Unk800C8114 { Unk800C8114V* x0; char pad[0x2C - 4]; const void* x2C; char p2[0x38 - 0x30]; Unk800C8114V x38; };
EXTERN_C const Unk800C8114T D_800B85C4;
EXTERN_C char D_800B84CC[], D_800104A8[];
EXTERN_C void func_800C9364();

/* func_800BE8B0 */
struct Unk800BE8B0C { void* x0; s32 x4, x8, xC, x10; u8 x14; };
struct Unk800BE8B0D { void* x0; StreamStat* x4; void* x8; void* xC; char x10[0x28 - 0x10]; s32 x28, x2C; char p[0x3C - 0x30]; StreamStat x3C; };
struct Unk800BE8B0 { char x0[0x64]; void* x64; Unk800BE8B0D* x68; Unk800BE8B0C* x6C; char p[0x74 - 0x70]; s32 x74; char p2[0x88 - 0x78]; s32 x88; };
EXTERN_C void* D_800127FC[];
inline Unk800BE8B0C* ctorC(Unk800BE8B0C* c, s32 a, s32 b, s32 cc, s32 d) { c->x0 = D_800127FC; c->x4 = a; c->x14 = 0; c->x8 = b; c->xC = cc; c->x10 = d; return c; }

/* func_800C5278 */
struct Unk800C5278E { s16 delta; s16 index; void (*pfn)(void*); };
struct Unk800C5278T { Unk800C5278E e[10]; };
struct Unk800C5278VB { const Unk800C5278T* vptr; };
struct Unk800C5278 { Unk800C5278VB* x0; char pad[0x2C - 4]; const void* x2C; };
EXTERN_C const Unk800C5278T D_800B7E1C;
EXTERN_C const char D_800B7E6C[];

/* func_800C595C */
struct Unk800C595CR { Unk800C10BCP xy; s16 w, h; };
struct Unk800C595C { char pad[0x18]; void* x18; char p2[0x50 - 0x1C]; s32 x50, x54, x58; };
EXTERN_C char D_800B8094[];

/* func_800C6388 */
struct Unk800C6388A { s32 d[3]; };
struct Unk800C6388B { s32 d[5]; };
struct Unk800C6388 { void* x0; s32 x4; u16 x8, xA; s32 xC; Unk800C6388A x10[2]; Unk800C6388B x28[2]; };
EXTERN_C char D_80014BD0[], D_800B80D4[];

/* func_800C7C3C */
struct Unk800C7C3CE { s16 delta, index; void* pfn; };
struct Unk800C7C3CT { Unk800C7C3CE e[10]; };
struct Unk800C7C3CB { const void* vptr; };
struct Unk800C7C3C { Unk800C7C3CB* x0; char pad[0x2C - 4]; const void* x2C; char p2[0x58 - 0x30]; const void* x58; s32 x5C; };
EXTERN_C const Unk800C7C3CT D_800B82F4;
EXTERN_C const char D_800B8344[], D_80013E30[];

/* func_800C800C */
struct Unk800C800CE { s16 delta, index; void* pfn; };
struct Unk800C800CT { Unk800C800CE e[10]; };
struct Unk800C800CB { const void* vptr; };
struct Unk800C800C { Unk800C800CB* x0; char pad[0x2C - 4]; const void* x2C; };
EXTERN_C const Unk800C800CT D_800B8384;
EXTERN_C const char D_800B83D4[];

/* func_800C8C28 */
struct Unk800C8C28 { void* x0; s32 x4; u16 x8, xA; s32 xC; POLY_FT4 x10[2]; u16 x60; };
EXTERN_C char D_80014BD0[], D_800B8614[];

/* func_800C11A0 */
struct Unk800C11A0 { char pad[0x68]; s32 x68; char p1[0x78 - 0x6C]; void* x78; char x7C[0xE8 - 0x7C]; char xE8[0x18C - 0xE8]; s32 x18C, x190; };
EXTERN_C void func_800C1AE0(Unk800C11A0*, void*);
EXTERN_C void* func_800C2624(void*, s32, s32, s32, s32, const char*);

/* func_800B9A0C */
struct Unk800B9A0CE { s16 delta; s16 index; void (*pfn)(); };
struct Unk800B9A0CV { const void* vptr; s32 x4; };
struct Unk800B9A0C { Unk800B9A0CV* x0; char pad[0x2C - 4]; const void* x2C; };
EXTERN_C char D_800B7044[];

/* func_800BBF7C */
struct Unk800BBF7CE { s16 delta; s16 index; void (*pfn)(); };
struct Unk800BBF7CT { Unk800BBF7CE e[10]; };
struct Unk800BBF7CV { const void* vptr; s32 x4; };
struct Unk800BBF7CS { Unk800BBF7CV* x0; const void* x4; };
struct Unk800BBF7C { const void* x0; char p0[0x8C - 4]; const void* x8C; char p1[0xF8 - 0x90]; const void* xF8; char p2[0x100 - 0xFC]; Unk800BBF7CS x100; };
EXTERN_C const Unk800BBF7CT D_800B7564, D_80010538;
EXTERN_C char D_800B75CC[], D_800B75B4[], D_800B7534[], D_800B75E4[], D_80010508[];
inline void Unk800BBF7C_dtor(Unk800BBF7CS* s) {
  s->x4 = D_80010508;
  s->x0->vptr = &D_80010538;
  Unk800BBF7CT vt = D_80010538;
  s->x0->vptr = &vt;
  char* full; s32 adj;
  vt.e[1].delta = D_80010538.e[1].delta + (adj = (char*)s - (full = (char*)s->x0 - 8));
  vt.e[6].delta = D_80010538.e[6].delta + adj;
}

/* func_800C5380 */
struct Unk800C5380E { s16 delta; s16 index; void (*pfn)(); };
struct Unk800C5380T { Unk800C5380E e[10]; };
struct Unk800C5380V { const void* vptr; s32 x4; };
struct Unk800C5380 { char pad[0x18]; const void* x18; char p1[0x50 - 0x1C]; Unk800C5380V* x50; const void* x54; const void* x58; char p2[0x68 - 0x5C]; s32 x68, x6C; char x70[0xC0 - 0x70]; char xC0[0xDC - 0xC0]; Unk800C5380V xDC; };
EXTERN_C const Unk800C5380T D_800B7FB4;
EXTERN_C char D_800B8024[], D_800B8004[], D_800B8054[], D_800104A8[];

/* func_800C648C */
/* libgpu P_TAG: addPrim(ot, p) is done with these bitfields */
struct Unk800C648CS { u32 tag; s32 w1, w2, w3, w4; };
struct Unk800C648CD { u32 tag; s32 code[2]; };
struct Unk800C648C { char pad[0xA]; u16 xA; s32 xC; Unk800C648CD x10[2]; Unk800C648CS x28[2]; };
struct Unk800C648CT { unsigned addr : 24; unsigned len : 8; };
struct Unk800C648CO { char pad[0x10]; u32 x10; u32* x14; };
EXTERN_C Unk800C648CO* D_800B4CFC[];
inline void Unk800C648C_add(u32 z, u32* prim) {
  Unk800C648CO* o = D_800B4CFC[0];
  if (z && z < o->x10) { ((Unk800C648CT*)prim)->addr = ((Unk800C648CT*)&o->x14[z])->addr; o->x14[z] = (u32)prim & 0xFFFFFF; }
}

/* func_800BE9D4 */
struct Unk800BE9D4C { void* x0; s32 x4, x8, xC, x10; u8 x14; };
struct Unk800BE9D4D { void* x0; StreamStat* x4; void* x8; void* xC; char x10[0x28 - 0x10]; s32 x28, x2C; char p[0x3C - 0x30]; StreamStat x3C; };
struct Unk800BE9D4 { char x0[0x64]; void* x64; Unk800BE9D4D* x68; Unk800BE9D4C* x6C; char p[0x74 - 0x70]; s32 x74; char p2[0x7C - 0x78]; s32 x7C, x80; char p3[0x88 - 0x84]; s32 x88; };
EXTERN_C void* D_800127FC[];
inline Unk800BE9D4C* Unk800BE9D4_ctorC(Unk800BE9D4C* c, s32 a, s32 b, s32 cc, s32 d) { c->x0 = D_800127FC; c->x4 = a; c->x14 = 0; c->x8 = b; c->xC = cc; c->x10 = d; return c; }

/* func_800BF918 */
struct Unk800BF918X { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual ~Unk800BF918X(); };
struct Unk800BF918 { char pad[0x6C]; s32 x6C; void* x70; s32 x74; Unk800BF918X* x78; char x7C[0x1F0 - 0x7C]; char x1F0[0x278 - 0x1F0]; Unk800C01C4O x278[15]; };
inline Unk800CA59CT* Unk800BF918_ev(s16 k, void* a, s32 b) { Unk800CA59CT* t = func_8001CA10(0x14); Unk800CA59C_ctor1(t); *(void* volatile*)&t->x0 = D_80010300; t->x8 = 2; t->xA = k; t->x4 = 0; t->x10 = b; t->xC = (s32)a; t->x0 = D_800102D0; return t; }

/* func_800C5148 */
struct Unk800C5148 { s32 x0, x4, x8; Unk800C10BCP xC; char p1[0x1C - 0x10]; u16 x1C; char p2[0x30 - 0x1E]; Unk800C8340L* x30; s32 x34; u32 x38; s32 x3C; };
EXTERN_C void* func_800C60E8(void*, s32, Unk800C10BCP*, s32);

/* func_800BEB0C */
struct Unk800BEB0C { char x0[0x64]; void* x64; Unk800BE8B0D* x68; Unk800BE8B0C* x6C; s32 x70, x74; char p2[0x7C - 0x78]; s32 x7C, x80; char p3[0x88 - 0x84]; s32 x88; };

/* func_800C0DA4 */
struct Unk800C0DA4 { char pad[0x74]; s32 x74; char p2[0x1F0 - 0x78]; char x1F0[4]; };
EXTERN_C const char D_800B7810[], D_800B7814[], D_800B7854[], D_800B792C[];
EXTERN_C void func_800C10BC(Unk800C10BC* p, void* a, s32 b, void* c, s32 d);

/* func_800C4860 */
struct Unk800C4860 { char pad[0x1C]; void* x1C; char p1[0x50 - 0x20]; s32 x50; char p2[0x78 - 0x54]; s32 x78; char p3[0x200 - 0x7C]; char x200[4]; };

/* func_800C8D18 */
struct Unk800C8D18Q { u32 w[4]; };
struct Unk800C8D18P { u32 tag; Unk800C8D18Q q[2]; u32 x24; };
struct Unk800C8D18 { char pad[0xA]; u16 xA; char p2[0x10 - 0xC]; Unk800C8D18P x10[2]; };
inline void Unk800C8D18_addz(void* pr, u32 z) { Unk800C648CO* ot = D_800B4CFC[0]; if (z != 0 && z < ot->x10) { u32 a = ot->x14[z]; *(u32*)pr = (*(u32*)pr & 0xFF000000) | (a & 0xFFFFFF); ot->x14[z] = (u32)pr & 0xFFFFFF; } }

/* func_800C4F10 */
struct Unk800C4F10E { s16 delta; s16 index; void (*pfn)(); };
struct Unk800C4F10V { const void* vptr; s32 x4; };
struct Unk800C4F10 { Unk800C4F10V* x0; char pad[0x2C - 4]; const Unk800C4F10E* x2C; char p2[0x38 - 0x30]; s32 x38, x3C; Unk800C4F10V x40; };
EXTERN_C char D_800104A8[];
EXTERN_C void* func_800C4F10(Unk800C4F10* self, s32 in_chrg, s32 b, s32 c, u16 a);

/* func_800C1AE0 */
struct Unk800C1AE0S { char d[0x20]; };
EXTERN_C char D_800B7B24[], D_800B7B28[], D_800B7B34[];

/* func_800C2624 */
struct Unk800C2624 { void* x0; StreamStat* x4; void* x8; void* xC; char x10[0x24 - 0x10]; void* x24; StreamStat* x28; s32 x2C, x30, x34; char* x38; s32 x3C, x40; char* x44; s32 x48, x4C, x50, x54; u32 x58; s32 x5C; StreamStat x60; };
EXTERN_C char D_80012154[], D_8001201C[], D_80012034[], D_800121AC[], D_80012074[], D_8001208C[], D_800120B4[], D_800B7CFC[], D_800B7CD4[], D_800B7D14[];
EXTERN_C s32 D_800CBA98[];
EXTERN_C void func_800C24E0();
EXTERN_C int func_800C24C8(int);
EXTERN_C void func_800C3D90(Unk800C3D90*, char*);
EXTERN_C void func_800C407C(Unk800C407C*);

/* func_800C46B8 */
struct Unk800C46B8 { char pad[0x54]; char x54[9]; char x5D[25]; s32 x78; };
EXTERN_C void* memcpy(void*, const void*, u32);

/* func_800C9AB4 */
struct Unk800C9AB4 { char pad[0xA]; u16 xA; s32 xC; Unk800C648CD x10[2]; Unk800C648CS x28[4]; };

/* func_800B8B14 */
EXTERN_C const Unk800B98D4T D_800B6DF4;
EXTERN_C char D_800B6E44[];

/* func_800BCCAC */
struct Unk800BCCAC { char pad[4]; void* x4[2]; s32 xC[2]; char p1[0x24 - 0x14]; s32 x24[2]; s32 x2C; char p2[0x40 - 0x30]; void* x40; char p3[0x48 - 0x44]; s32 x48; s32 x4C; s16 x50, x52; char p4[0x58 - 0x54]; char x58[4]; };
EXTERN_C s32 DecDCTinSync(s32);
EXTERN_C s32 DecDCTvlc2(void*, void*, void*);
EXTERN_C s32 func_800CBA80(void*);

/* func_800C38F0 */
struct Unk800C38F0 { char pad[0x30]; s32 x30, x34, x38, x3C; };
EXTERN_C s32 func_800C3F68(Unk800C3F68* p);

/* func_800C49BC */
struct Unk800C49BCR { s8 x0; char pad[0x5F]; };
struct Unk800C49BCQ { char p0[0xA0]; s32 xA0; char p1[0xD7 - 0xA4]; u8 xD7; char p2[0xDF - 0xD8]; u8 xDF; s32 xE0; u8 xE4, xE5; s8 xE6[3]; u8 xE9; char p3[0x19A0 - 0xEA]; Unk800C49BCR x19A0[3]; };
struct Unk800C49BCA { char d[0x1C]; };
struct Unk800C49BCB { char d[0x28]; };
struct Unk800C49BC { char p0[0x1C]; void* x1C; char p1[0x50 - 0x20]; s32 x50; char p2[0x5A - 0x54]; s8 x5A, x5B; char p3[0x78 - 0x5C]; s32 x78, x7C; s8 x80; u8 x81; s8 x82; char p4;
  Unk800C49BCA x84[3]; Unk800C49BCB xD8[3]; Unk800C49BCB x150, x178, x1A0; Unk800C49BCA x1C8, x1E4, x200, x21C, x238; };
EXTERN_C char D_800B7D54[], D_800B4D6C[];

/* func_800C5798 */
EXTERN_C const Unk800C5380T D_80014E0C;
EXTERN_C const char D_80014E7C[], D_80014E5C[], D_80014EAC[];
inline void Unk800C5798_base_dtor(Unk800C5380* self) {
  self->x54 = D_80014E7C;
  self->x58 = D_80014E5C;
  self->x18 = D_80014EAC;
  self->x50->vptr = &D_80014E0C;
  {
    Unk800C5380T vt = D_80014E0C;
    self->x50->vptr = &vt;
    char* full;
    int adj;
    vt.e[1].delta = D_80014E0C.e[1].delta + (adj = (char*)self - (full = (char*)self->x50 - 0x68));
    vt.e[6].delta = D_80014E0C.e[6].delta + adj;
  }
  func_8005652C(self, 0);
}

/* func_800CA610 */
struct Unk800CA610E { s16 delta; s16 index; void (*pfn)(); };
struct Unk800CA610O { const Unk800CA610E* vptr; };
struct Unk800CA610 { const void* x0; char p0[0x8C - 4]; const void* x8C; char p1[0xF8 - 0x90]; const void* xF8; char p2[0x100 - 0xFC]; Unk800BBF7CS x100; char p3[0x10C - 0x108]; Unk800CA610O* x10C; };
EXTERN_C const Unk800BBF7CT D_800B89CC;
EXTERN_C const char D_800B8A34[], D_800B8A1C[], D_800B899C[], D_800B8A4C[];

/* func_800B8CF0 */
EXTERN_C const Unk800B98D4T D_800B6DF4;
EXTERN_C char D_800B6E44[];
inline void Unk800B8CF0_base_dtor(Unk800B98D4* self, int in_chrg) {
  self->x2C = D_800B7044;
  self->x0->vptr = &D_800B6FF4;
  if (!in_chrg) {
    Unk800B98D4T vt = D_800B6FF4;
    self->x0->vptr = &vt;
    char* full; int adj;
    vt.e[1].delta = D_800B6FF4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x38));
    vt.e[5].delta = D_800B6FF4.e[5].delta + adj;
    vt.e[7].delta = D_800B6FF4.e[7].delta + adj;
    vt.e[9].delta = D_800B6FF4.e[9].delta + adj;
  }
  func_80029D74(self, 0);
}

/* func_800BCEA0 */
struct Unk800BCEA0 { char p0[4]; void* x4[8]; s32 x24[3]; s32 x30, x34; char* x38[2]; char* x40; s32 x44; char p1[0x4C - 0x48]; s32 x4C; char p2[0x52 - 0x50]; s16 x52; };
EXTERN_C void DecDCTin(void*, s32);
EXTERN_C void DecDCTout(void*, s32);
EXTERN_C void func_800BD83C();

/* func_800BDBAC */
/* ctor of the object func_800BDC88 destroys (Unk800BDC88): bases at 0 (vptrs 0/4/8) and 0x30 */
struct Unk800BDBACM { void* x0; void* x4; void* x8; s16 xC, xE, x10, x12; };
struct Unk800BDBAC { void* x0; void* x4; void* x8; char p[0x30 - 0xC]; Unk800BDBACM x30; void* x44; s32 x48, x4C, x50, x54, x58; };
EXTERN_C const char D_800B7654[];
EXTERN_C char D_800100F8[], D_80010198[];
inline void Unk800BDBAC_A(Unk800BDBAC* p) { p->x0 = D_80010348; p->x4 = (void*)D_800B7654; p->x8 = D_800B6FBC; p->x30.x0 = D_800100F8; p->x30.x4 = D_80010198; }
inline void Unk800BDBAC_B(Unk800BDBACM* m, void* c, s32 h, s32 x, s32 y, s32 w) { m->x4 = D_800101C0; m->x0 = D_800101B0; m->x8 = c; m->xC = x; m->xE = y; m->x10 = w; m->x12 = h; }

/* func_800C29C0 */
struct Unk800C29C0 { void* x0; char p0[8 - 4]; void* x8; char p1[0x24 - 0xC]; void* x24; char p2[0x40 - 0x28]; void* x40; void* x44; };
EXTERN_C char D_800B7CFC[], D_800B7CD4[], D_800B7D14[], D_80012074[], D_8001208C[], D_800120B4[];
EXTERN_C s32 D_800CBA98[];

/* func_800C4DE8 */
struct Unk800C4DE8E { s16 delta; s16 index; void (*pfn)(void*, s32); };
struct Unk800C4DE8A { char pad[0x18]; Unk800C4DE8E* vptr; char p2[0x28 - 0x1C]; };
struct Unk800C4DE8B { char pad[0x18]; Unk800C4DE8E* vptr; };
struct Unk800C4DE8 { char pad[0x84]; Unk800C4DE8B x84[3]; Unk800C4DE8A xD8[3]; char x150[0x28]; char x178[0x28]; char x1A0[0x28]; char x1C8[0x1C]; char x1E4[0x1C]; char x200[0x1C]; char x21C[0x1C]; char x238[0x1C]; };

/* func_800C5640 */
struct Unk800C5640V { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C5640 : Unk800C5640V { char p2[0x68 - 0x1C]; Unk800BF898* x68; Unk800C7740O* x6C; char x70[0xC0 - 0x70]; char xC0[4]; };
EXTERN_C void func_800BF898(Unk800BF898*, s32);
EXTERN_C char D_800B7F8C[];

/* func_800C6C38 */
struct Unk800C6C38EV { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C6C38E : Unk800C6C38EV { char p2[0x50 - 0x1C]; };
struct Unk800C6C38 { char pad[0x6C]; void* x6C; char p1[0x74 - 0x70]; Unk800C6C38E x74[13]; char p2[0x4B4 - 0x74 - 13 * 0x50]; s32 x4B4; char p3[0x4C4 - 0x4B8]; char x4C4[0x568 - 0x4C4]; char x568[0x610 - 0x568]; s32 x610; };
EXTERN_C void func_800C908C(Unk800C908C*);
inline void Unk800C6C38_ctor2(Unk800CA59CT* t) { Unk800CA59C_ctor1(t); *(void* volatile*)&t->x0 = D_80010300; t->x8 = 2; t->xA = 7; t->x4 = 0; }

/* func_800C7AC0 */
struct Unk800C7AC0E { s16 delta, index; void (*pfn)(void*, s32, s32); };
struct Unk800C7AC0V { const void* vptr; s32 x4; };
struct Unk800C7AC0 { Unk800C7AC0V* x0; char pad[0x2C - 4]; const Unk800C7AC0E* x2C; char p2[0x58 - 0x30]; const void* x58; void* x5C; Unk800C7AC0V x60; };
EXTERN_C Unk800C8114* func_800C8114(Unk800C8114*, s32, u16);

/* func_800C8228 */
EXTERN_C void func_800C95EC();

/* func_800C99B0 */
struct Unk800C99B0A { s32 d[3]; };
struct Unk800C99B0B { s32 d[5]; };
struct Unk800C99B0 { void* x0; s32 x4; u16 x8, xA; s32 xC; Unk800C99B0A x10[2]; Unk800C99B0B x28[4]; };
EXTERN_C char D_800B8794[];

/* func_800C30DC */
struct Unk800C30DC { s32 x0; StreamStat* x4; char p[0x34 - 8]; s32 x34; s32 x38, x3C; };
EXTERN_C s32 func_800C3674(void*);

/* func_800C3228 */
struct Unk800C3228V { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C3228 : Unk800C3228V { StreamStat* x4; char p[0x34 - 8]; s32 x34; char p2[0x44 - 0x38]; u8* x44; };
struct Unk800C3228N { char c[26]; };
EXTERN_C s32 func_800C2AF0(Unk800C3228*, void*, s32);
EXTERN_C s32 func_800C3674(void*);

/* func_800C8E64 */
struct Unk800C8E64 { char pad[0x18]; const void* x18; char p1[0x50 - 0x1C]; Unk800C5380V* x50; const void* x54; const void* x58; char p2[0x68 - 0x5C]; char x68[0x84 - 0x68]; char x84[0xA0 - 0x84]; Unk800C5380V xA0; };
EXTERN_C const Unk800C5380T D_800B86B4;
EXTERN_C const char D_800B8724[], D_800B8704[], D_800B8754[];
EXTERN_C char D_800B867C[], D_800B8698[];

/* func_800C5B80 */
struct Unk800C5B80A { char d[8]; };
struct Unk800C5B80O { char d[0xA0]; };
struct Unk800C5B80N { char c[13]; };
struct Unk800C5B80S { u8 x0, x1, x2, x3, x4, x5, x6, x7; char p0[0xC - 8]; u16 xC; u8 xE; char p1[0x1E - 0xF]; Unk800C5B80N x1E; char p2[0x8C - 0x2B]; u8 x8C; char p3[0x98 - 0x8D]; };
struct Unk800C5B80R { char pad[8]; void* x8; };
struct Unk800C5B80Q { char pad[0x328]; char* x328; };
struct Unk800C5B80X { char pad[0x1A]; u8 x1A; };
struct Unk800C5B80 { void* x0; void* x4; };
EXTERN_C s32 D_800CBAC8[];
EXTERN_C const Unk800C5B80N D_800B80C4;

/* func_800C7290 */
struct Unk800C7290VE { s16 delta, index; void (*pfn)(); };
struct Unk800C7290V { char pad[0x18]; const Unk800C7290VE* x18; };
struct Unk800C7290EV { char pad[0x18]; virtual void v1(); virtual void v2(); };
struct Unk800C7290E : Unk800C7290EV { char p2[0x50 - 0x1C]; };
struct Unk800C7290S { char d[0x1C]; };
struct Unk800C7290 : Unk800C7290V { char p0[0x20 - 0x1C]; s32 x20; char p1[0x74 - 0x24]; Unk800C7290E x74[8]; Unk800C7290S x2F4[8];
  Unk800C7290S x3D4, x3F0, x40C, x428, x444, x460, x47C, x498; Unk800C7740O* x4B4; s32 x4B8, x4BC; char p4[0x568 - 0x4C0]; char x568[0x610 - 0x568]; Unk800C7740O* x610; };
struct Unk800C7290G { char pad[0x1D4]; u16 x1D4[16]; char p2[0x1F8 - 0x1F4]; s8 x1F8; };
EXTERN_C void* func_800C7D60(void*, s32, Unk800C10BCP, s32, u16);

/* func_800C96C0 */
struct Unk800C96C0D { u32 tag; u32 code[2]; };
struct Unk800C96C0B { s32 w[4]; };
struct Unk800C96C0W { u32 tag; Unk800C96C0B b; };
struct Unk800C96C0 { void* x0; char p[0x10 - 4]; Unk800C96C0D x10[2]; SPRT x28[4]; };
struct Unk800C96C0T { char pad[0x1C]; u16 x1C; };
struct Unk800C96C0C { char pad[8]; u16 x8; };
EXTERN_C char D_800B8794[], D_800B4C88[];
EXTERN_C void func_800C98EC(Unk800C98EC*, Unk800C98ECB*);

/* func_800BDFA8 */
struct Unk800BDFA8A { s32 x0; };
struct Unk800BDFA8B { s32 x0; };
struct Unk800BDFA8 : Unk800BDFA8A, Unk800BDFA8B { char p0[0x20 - 8]; u16 x20, x22; char p1[0x44 - 0x24]; Unk800B93D8T* x44; Unk800BCCAC* x48; void* x4C; void* x50; s32 x54, x58; };
EXTERN_C Unk800BCCAC* func_800BC714(void*, void*, u16, u16, s32, Unk800BDFA8B*, void*);

/* func_800C3484 */
struct Unk800C3484V { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C3484 : Unk800C3484V { StreamStat* x4; char p0[0x34 - 8]; s32 x34; };
struct Unk800C3484N { char d[26]; };

/* func_800C91A0 */
/* same base (Unk800C5380 layout up to 0x68, base dtor Unk800C5798_base_dtor); members at 0x68 and 0x84 */
EXTERN_C const Unk800C5380T D_800B86B4;

/* func_800C9CDC */
/* ctor of the func_800CA610 object (Unk800CA610 layout); virtual base at 0x180 */
struct Unk800C9CDC { const void* x0; char p0[0x8C - 4]; const void* x8C; char p1[0xF8 - 0x90]; const void* xF8; char p2[0x100 - 0xFC]; Unk800BBF7CS x100; s16 x108; char p3[0x114 - 0x10A]; s32 x114; s16 x118; char p4[0x17C - 0x11A]; s16 x17C; char p5[0x180 - 0x17E]; Unk800BBF7CV x180; };
EXTERN_C void func_800CA928(void*);

/* func_800CA928 */
struct Unk800CA928P { s16 x, y; Unk800CA928P() {} Unk800CA928P(s16 a, s16 b) { x = a; y = b; } };
struct Unk800CA928O { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(Unk800CA928P); };
struct Unk800CA928 { char pad[0x11C]; void* x11C[23]; Unk800CA928O* x178; };
EXTERN_C char D_800B882C[], D_800B883C[], D_800B884C[], D_800B885C[], D_800B886C[], D_800B887C[], D_800B888C[], D_800B889C[], D_800B88AC[], D_800B88BC[], D_800B88CC[], D_800B88DC[], D_800B88EC[], D_800B88FC[], D_800B890C[], D_800B891C[], D_800B892C[], D_800B893C[], D_800B894C[], D_800B895C[], D_800B896C[], D_800B897C[], D_800B898C[];

/* func_800BF51C */
struct Unk800BF51COB { char pad[0x18]; virtual ~Unk800BF51COB(); };
struct Unk800BF51CO : Unk800BF51COB { char p2[0x254 - 0x1C]; ~Unk800BF51CO(); };
struct Unk800BF51CD { virtual ~Unk800BF51CD(); };
struct Unk800BF51CM { char pad[0x18]; const void* x18; char p1[0x50 - 0x1C]; Unk800C5380V* x50; const void* x54; const void* x58; char p2[0x6C - 0x5C]; };
struct Unk800BF51C { char pad[0x18]; const void* x18; char p1[0x50 - 0x1C]; Unk800C5380V* x50; const void* x54; const void* x58; char p2[0x7C - 0x5C];
  char x7C[0xCC - 0x7C]; char xCC[0xE8 - 0xCC]; char xE8[0x104 - 0xE8]; char x104[0x120 - 0x104]; char x120[0x13C - 0x120]; char x13C[0x164 - 0x13C];
  char x164[0x194 - 0x164]; char x194[0x1F0 - 0x194]; char x1F0[0x240 - 0x1F0]; char x240[0x25C - 0x240]; char x25C[0x278 - 0x25C];
  Unk800BF51CO x278[15]; s32 x2564; Unk800BF51CM x2568; s32 x25D4; char x25D8[0x26BC - 0x25D8]; Unk800BF51CM x26BC; char x2728[0x27A0 - 0x2728]; char x27A0[0x2818 - 0x27A0]; Unk800BF51CD* x2818; };
EXTERN_C const Unk800C5380T D_800B7BF4, D_80014D5C;
EXTERN_C const char D_800B7BC4[], D_800B7C44[], D_800B7C64[], D_80013BD0[], D_80014DAC[], D_80014DCC[];
inline void Unk800BF51C_mdtor(Unk800BF51CM* m, s32 in_chrg, const char* a, const char* b, const char* c, const Unk800C5380T* d, s32 off) {
  m->x54 = a; m->x58 = b; m->x18 = c; m->x50->vptr = d;
  if (!in_chrg) {
    Unk800C5380T vt = *d;
    m->x50->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = d->e[1].delta + (adj = (char*)m - (full = (char*)m->x50 - off));
    vt.e[6].delta = d->e[6].delta + adj;
  }
  func_8005652C(m, 0);
  if (in_chrg & 2) func_8001A610(m->x50, 0);
}
inline void Unk800BF51C_mdtor1(Unk800BF51CM* m, s32 in_chrg) {
  m->x54 = D_80013BD0; m->x58 = D_80014DAC; m->x18 = D_80014DCC; m->x50->vptr = &D_80014D5C;
  if (!in_chrg) { m->x50->vptr = 0; }
  func_8005652C(m, 0);
  if (in_chrg & 2) func_8001A610(m->x50, 0);
}
inline void Unk800BF51C_mdtor2(Unk800BF51CM* m, s32 in_chrg) {
  m->x54 = D_80014E7C; m->x58 = D_80014E5C; m->x18 = D_80014EAC; m->x50->vptr = &D_80014E0C;
  if (!in_chrg) { m->x50->vptr = 0; }
  func_8005652C(m, 0);
  if (in_chrg & 2) func_8001A610(m->x50, 0);
}

/* func_800C9364 */
struct Unk800C9364R { Unk800C10BCP a, b; };
struct Unk800C9364A { void* x0; s32 x4; s16 x8, xA; };
struct Unk800C9364B { void* x0; s32 x4; void* x8; void* xC; Unk800C10BCP x10; s16 x14, x16; s32 x18; s16 x1C, x1E; };
struct Unk800C9364G { char pad[0x10]; virtual void v1(void*); };
struct Unk800C9364V { virtual void v1(); virtual void v2(); virtual void v3(); };
EXTERN_C char D_800106EC[], D_80010624[], D_80010888[], D_800108A0[];
inline void* Unk800C9364_newA(char* buf) {
  Unk800C9364A* o = (Unk800C9364A*)operator new(0x20C);
  *(void* volatile*)&o->x0 = D_80010178; *(void* volatile*)&o->x0 = D_800106EC; o->x4 = 0; o->x8 = 0; o->xA = 0; o->x0 = D_80010624;
  func_80021F48(o, buf); return o;
}
inline void* Unk800C9364_newB(Unk800C95ECV** g, char* buf, s32 w, s32 h, Unk800C10BCP* pp) {
  Unk800C9364B* o = (Unk800C9364B*)operator new(0x20);
  void* own = *g;
  *(void* volatile*)&o->x0 = D_80010178; o->x4 = 0; o->x8 = D_80010888; o->x0 = D_800108A0; o->xC = own;
  pp->x = -1; pp->y = -1; o->x10 = *pp; o->x14 = 0; o->x16 = 0; o->x18 = 0; o->x1E = 0;
  func_80024BF0(o, buf, w, h); return o;
}

/* func_800C3674 */
struct Unk800C3674 { char p0[0x30]; s32 x30; char p1[0x38 - 0x34]; s32 x38, x3C; };
EXTERN_C s32 func_800C38F0(Unk800C38F0*);
#define Unk800C3674_POLL { Unk800C3F68E* e = func_8001ED2C(D_800B4C18[0], 2, 1); if (e) { if (e->xA == 4 && e->xC) e->xC->v1(3); e->v2(); } }

/* func_800C77F0 */
struct Unk800C77F0E { s16 delta; s16 index; void (*pfn)(void*, s32); };
struct Unk800C77F0A { char pad[0x18]; Unk800C77F0E* vptr; };
struct Unk800C77F0B { char pad[0x18]; Unk800C77F0E* vptr; char p2[0x50 - 0x1C]; };
struct Unk800C77F0 { char pad[0x18]; const void* x18; char p1[0x50 - 0x1C]; Unk800C5380V* x50; const void* x54; const void* x58; char p2[0x74 - 0x5C]; Unk800C77F0B x74[8]; Unk800C77F0A x2F4[8]; Unk800C77F0A x3D4[8]; char p3[0x4C4 - 0x4B4]; char x4C4[0x514 - 0x4C4]; char x514[0x1C]; char x530[0x1C]; char x54C[0x1C]; char x568[4]; };
EXTERN_C const Unk800C5380T D_800B8214;
EXTERN_C const char D_800B8284[], D_800B8264[], D_800B82B4[];
EXTERN_C void func_800C91A0(Unk800C5380*, int);

/* func_800C1BF8 */
struct Unk800C1BF8N8 { s16 d[4]; };
struct Unk800C1BF8N12 { s16 d[6]; };
struct Unk800C1BF8N14 { s16 d[7]; };
struct Unk800C1BF8N16 { s16 d[8]; };
struct Unk800C1BF8G { char pad[0x1C4]; s32 x1C4; };
EXTERN_C const Unk800C1BF8N12 D_800B7B40, D_800B7B80, D_800B7B90;
EXTERN_C const Unk800C1BF8N14 D_800B7B50, D_800B7BB4;
EXTERN_C const Unk800C1BF8N8 D_800B7B60[];
EXTERN_C const Unk800C1BF8N16 D_800B7B6C, D_800B7BA0;

/* func_800C6D80 */
struct Unk800C6D80EV { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); };
struct Unk800C6D80E : Unk800C6D80EV { char p2[0x50 - 0x1C]; };
struct Unk800C6D80S { char d[0x1C]; };
struct Unk800C6D80T { char d[0x20]; };
struct Unk800C6D80 { char p0[0x20]; s32 x20; char p1[0x3C - 0x24]; void* x3C; char p2[0x68 - 0x40]; s32 x68; char p3[0x74 - 0x6C]; Unk800C6D80E x74[8]; Unk800C6D80S x2F4[8];
  char p4[0x4B4 - 0x3D4]; Unk800C7740O* x4B4; Unk800C7740O* x4B8; s32 x4BC, x4C0; char p5[0x568 - 0x4C4]; char x568[4]; };
struct Unk800C6D80C { char pad[0x1C]; u16 x1C; };
struct Unk800C6D80G { char pad[0x120]; Unk800C6D80C* x120; char p2[0x1F8 - 0x124]; s8 x1F8; };
EXTERN_C void func_800C7740(Unk800C7740*);
EXTERN_C s32 func_800C910C(Unk800C910C*, Unk800C910CB*);

/* func_800C02D8 */
struct Unk800C02D8C { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual s32 v7(s32); };
struct Unk800C02D8V { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(s32); };
struct Unk800C02D8 : Unk800C02D8V { void* x1C; char p1[0x74 - 0x20]; s32 x74; Unk800C02D8C* x78; char p2[0x18C - 0x7C]; s32 x18C, x190; char p3[0x1F0 - 0x194]; char x1F0[0x278 - 0x1F0]; Unk800C01C4O x278[15]; char p4[0x2564 - 0x278 - 15 * 0x254]; char* x2564; };
EXTERN_C const char D_800B77B8[], D_800B7888[], D_800B78B8[];
EXTERN_C s32 func_800C39D4(void*);
inline s32 Unk800C02D8_open(Unk800C02D8* p) { s32 r; if ((r = func_800C2AF0((Unk800C3228*)p->x78, func_800C4994(p->x2564), 1)) != 0) return r; return (func_800C2F04((Unk800C2F04*)p->x78) == 0) << 1; }

/* func_800C2848 */
struct Unk800C2848 { void* x0; StreamStat* x4; void* x8; void* xC; char x10[0x24 - 0x10]; void* x24; StreamStat* x28; s32 x2C, x30, x34, x38, x3C; void* x40; void* x44; s32 x48, x4C, x50, x54, x58, x5C; StreamStat x60; };

/* func_800C21B8 */
struct Unk800C21B8B { char pad[0x9C]; virtual void v1(); virtual void v2(); };
struct Unk800C21B8A { char pad[0x400]; };
struct Unk800C21B8C : Unk800C21B8A, Unk800C21B8B { };
struct Unk800C21B8L { char pad[8]; Unk800C21B8C* x8[3]; };
struct Unk800C21B8D { char p[0x410]; s16 x410, x412; char p1[0xC]; s16 x420, x422; u8 x424[8]; };
struct Unk800C21B8G { char pad[0x328]; char* x328; };

/* func_800BEC54 */
struct Unk800BEC54V { virtual void v1(); virtual void v2(); virtual void v3(); virtual s32 v4(); };
struct Unk800BEC54 { char p0[0x64]; void* x64; Unk800BEC54V* x68; void* x6C; void* x70; s32 x74; char p1[0x7C - 0x78]; s32 x7C, x80; char p2[0x88 - 0x84]; s32 x88; };
struct Unk800BEC54S { const void* v0; const void* v4; s32 x8; s16 xC, xE, x10, x12; };
struct Unk800BEC54O { const void* x0; s32 x4; Unk800BEC54S x8; s32 x1C, x20, x24; };
EXTERN_C char D_80011FE4[], D_800100F8[], D_80010198[], D_800101C0[], D_800101B0[], D_80012104[], D_800120F4[], D_8001211C[];
#define Unk800BEC54_VS(x) (*(const void* volatile*)&(x))

/* func_800C3B88 */
struct Unk800C3B88 { char pad[0x38]; s32 x38; };
struct Unk800C3B88S5 { char c[5]; };
struct Unk800C3B88S13 { char c[13]; };
EXTERN_C char D_800B7CBC[], D_800B7CC0[];

/* func_800C0EA4 */
struct Unk800C0EA4V { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C0EA4O { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C0EA4 : Unk800C0EA4V { char p1[0x6C - 0x1C]; s32 x6C; char p2[0x78 - 0x70]; Unk800C0EA4O* x78; char x7C[0xE8 - 0x7C]; char xE8[0x18C - 0xE8]; s32 x18C; char p3[0x1F0 - 0x190]; char x1F0[0x25D8 - 0x1F0]; char x25D8[0x25F8 - 0x25D8]; s32 x25F8; char p4[0x2718 - 0x25FC]; s32 x2718; };
EXTERN_C void func_800C16C8(Unk800C0EA4*);
EXTERN_C void func_800C02D8(Unk800C02D8*);
EXTERN_C void func_800C1278(Unk800C0EA4*);
EXTERN_C void func_800C06BC(Unk800C0EA4*);
EXTERN_C void func_800C10BC(Unk800C10BC* p, void* a, s32 b, void* c, s32 d);
EXTERN_C const char D_800B7810[];
EXTERN_C char D_800B7A40[];

/* func_800C16C8 */
struct Unk800C16C8C { s32 d[0x14]; };
struct Unk800C16C8R { char p0[3]; u8 x3; char p1[0x18 - 4]; Unk800C16C8C x18; char p2[0x94 - 0x18 - 0x50]; };
struct Unk800C16C8G { char pad[0x202]; s8 x202, x203; char p2[0x23C - 0x204]; Unk800C16C8R x23C[1]; };
EXTERN_C void func_800C1690(void* p, s32* a, s32* b, s32* c, s32* d);
EXTERN_C void func_800C1BF8();
EXTERN_C void func_800C21B8();
EXTERN_C char D_800AC86C[];

/* func_800C7D60 */
struct Unk800C7D60R { s16 x, y, w, h; };
struct Unk800C7D60 { Unk800C8114V* x0; char pad[0xC - 4]; Unk800C7D60R xC; char p1[0x2C - 0x14]; const void* x2C; char p2[0x38 - 0x30]; s16 x38, x3A; Unk800C8114V x3C; };

/* func_800BC714 */
struct Unk800BC714P { s16 x, y; };
struct Unk800BC714R { Unk800BC714P pos; Unk800BC714P size; Unk800BC714R(Unk800BC714P p, Unk800BC714P s) : pos(p), size(s) {} };
struct Unk800BC714V { virtual void f1(); virtual void f2(); virtual void f3(); virtual Unk800BC714P f4(Unk800BC714P size); };
struct Unk800BC714 { const void* x0; void* x4[2]; s32 xC[2]; Unk800BC714R x14[2]; s32 x24[2]; s32 x2C, x30, x34; char* x38; char* x3C; char* x40; s32 x44, x48, x4C; Unk800BC714P x50; Unk800BDFA8B* x54; char x58[4]; };
EXTERN_C char D_800B7644[];
EXTERN_C Unk800BC714V* D_800B4C54[];
EXTERN_C void DecDCTvlcBuild(void*);

/* func_800BC12C */
struct Unk800BC12CO { virtual void f1(); virtual void f2(); virtual void f3(); };
struct Unk800BC12CP { char pad[0x1A]; u16 x1A; };
struct Unk800BC12C { char pad[0x10A]; s16 x10A, x10C; char p1[0x130 - 0x10E]; s16 x130, x132, x134; char p2[0x13C - 0x136]; u16 x13C; char p3[0x148 - 0x13E]; Unk800BC12CO* x148; };
inline void Unk800BC12C_ev(Unk800BC12C* p) { Unk800CA59CT* t = func_8001CA10(0x14); Unk800CA59C_ctor3(t); func_8001EFE4(p, t); }

/* func_800C06BC */
struct Unk800C06BCL { s32 x0; s32 x4; };
struct Unk800C06BCA { Unk800C06BCL* x0; s32 x4; };
struct Unk800C06BCB { void* x0; };
struct Unk800C06BCX : Unk800C06BCA, Unk800C06BCB { };
struct Unk800C06BCO { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(Unk800C10BCP); };
struct Unk800C06BC { char p0[0x1C]; Unk800C06BCX x1C; char p1[0x74 - 0x28]; s32 x74; Unk800C02D8C* x78; char x7C[0x18C - 0x7C]; s32 x18C, x190; char x194[0x1F0 - 0x194]; char x1F0[0x278 - 0x1F0]; Unk800C01C4O x278[15]; };
EXTERN_C const char D_800B78D8[], D_800B7968[];
EXTERN_C void func_800C5A14(Unk800C5A14* p, s32 v);
EXTERN_C void func_800C5A60(Unk800C5A60* p);
EXTERN_C int func_800C38C0(void* p, void* q);
EXTERN_C char* func_800C4994(char* p);
EXTERN_C s32 func_800C2F90(Unk800C2F90* p, s32 n);
EXTERN_C int func_800C3D08(Unk800C3D08* p);
EXTERN_C s32 func_800C2D4C(Unk800C2D4C* p);
EXTERN_C void func_800C49BC(Unk800C49BC* p, Unk800C49BCQ* q, s32 flag);
EXTERN_C s32 func_800C2F04(Unk800C2F04* p);
EXTERN_C s32 func_800C3B88(Unk800C3B88* p);
EXTERN_C void func_800C4860(Unk800C4860* p, s32 mode);
EXTERN_C void func_800C5B30(Unk800C5B30* p);
EXTERN_C s32 func_800C4854(Unk800C4854* p);
inline void* Unk800C06BC_list(Unk800C06BC* p) { Unk800C06BCX* x = &p->x1C; Unk800C06BCB* b = x; return b ? b->x0 : 0; }
inline void Unk800C06BC_rect(Unk800C9364R* r, s16 x, s16 y, s16 w, s16 h) { Unk800C10BC_set(&r->a, x, y); Unk800C10BC_set(&r->b, w, h); }
struct Unk800C06BCE { s16 d; s16 i; void (*f)(void*, Unk800C10BCP); };
struct Unk800C06BCOV { char pad[0x18]; Unk800C06BCE* vt; };
inline void Unk800C06BC_add(Unk800C06BCL* l, void* e) { func_80019A6C(l, e, l->x4); }

/* func_800C39D4 */
struct Unk800C39D4 { char pad[0x30]; s32 x30, x34, x38, x3C; };

/* func_800C8674 */

/* func_800B9DB4 */
struct Unk800B9DB4M { s32 v[6]; };
struct Unk800B9DB4 { char pad[0xC]; Unk800B9DB4M xC[2]; RECT x3C; RECT x44; };
inline Unk800B9DB4* base(Unk800B9DB4* self, Unk800B9DB4* out) { func_80027FEC(self, out); Unk800B9DB4M* d = out->xC; s32 i = 1; Unk800B9DB4M* s = self->xC; do { *d = *s; d++; s++; i--; } while (i != -1); return out; }

/* func_800C2AF0 */
struct Unk800C2AF0B { s16 x0; s16 x2; s32 x4; };
struct Unk800C2AF0 { s32 x0; Unk800C2AF0B* x4; char p2[0x34 - 8]; s32 x34; };
struct Unk800C2AF0S { char d[26]; };

/* func_800C83CC */
struct Unk800C83CCP { u8 a0, a1, a2, len; u8 r0, g0, b0, code; char rest[0x28 - 8]; };
struct Unk800C83CC { void* x0; char pad[0xC]; Unk800C83CCP x10[2]; u8 x60, x61; Unk800C83CC(void* a, s32 q, void* r, s32 n); };
EXTERN_C void func_800C8B24(Unk800C8B24* p, Unk800C8B24B* q);
EXTERN_C void func_800C8894(Unk800C8894* p, Unk800C8894B* q);
EXTERN_C void func_800C899C(void*, void*);

/* func_800C4370 */
struct Unk800C4370 { char p0[0x18]; const void* x18; char p1[0x50 - 0x1C]; s32 x50; char p3[0x78 - 0x54]; s32 x78, x7C; s8 x80; u8 x81; s8 x82; char p4;
  Unk800C49BCA x84[3]; Unk800C49BCB xD8[3]; Unk800C49BCB x150, x178, x1A0; Unk800C49BCA x1C8, x1E4, x200, x21C, x238; };
EXTERN_C char D_800B7DEC[], D_800B7D60[], D_800B7D64[];

/* func_800C899C */
struct Unk800C899CQ { s16 x, y; };
struct Unk800C899C { char pad[0x10]; POLY_FT4 x10[2]; u8 x60, x61; };
inline void Unk800C899C_fix(Unk800C899C* p, s32 i, s32 u, s32 v) {
  u -= p->x10[i].x0;
  v -= p->x10[i].y0;
  p->x10[i].u1 = p->x10[i].x1 + u;
  p->x10[i].v1 = p->x10[i].v0;
  p->x10[i].u2 = p->x10[i].u0;
  p->x10[i].v2 = p->x10[i].y2 + v;
  p->x10[i].u3 = p->x10[i].x3 + u;
  p->x10[i].v3 = p->x10[i].y3 + v;
}

/* func_800BC554 */
struct Unk800BC554 { const void* x0; char p0[0x8C - 4]; const void* x8C; char p1[0xF8 - 0x90]; const void* xF8; char p2[0x100 - 0xFC]; Unk800BBF7CS x100; s16 x108; char p3[0x150 - 0x10A]; Unk800BBF7CV x150; };
inline Unk800BC554* Unk800BC554_fin(Unk800BC554* t) { t->x8C = D_800B75CC; t->xF8 = D_800B75B4; t->x100.x4 = D_800B7534; t->x0 = D_800B75E4; t->x108 = 1; return t; }

/* func_800B914C */

/* func_800C60E8 */
struct Unk800C60E8DM { u32 tag; u32 code[2]; };
struct Unk800C60E8W { char pad[8]; u16 x8; };
struct Unk800C60E8G { char pad[0x1C]; u16 x1C; };
struct Unk800C60E8S { u32 tag; u32 w1, w2, w3, w4; };
struct Unk800C60E8 { void* x0; char pad[0x10 - 4]; Unk800C60E8DM x10[2]; SPRT x28[2]; };
struct Unk800C60E8Q { char pad[0x28]; SPRT s; };
EXTERN_C Unk800C60E8W* D_800CBADC[];
EXTERN_C void func_800C62E4(Unk800C62E4* p, Unk800C62E4B* q);

/* func_800C1278 */
struct Unk800C1278 { char pad[0x78]; void* x78; char x7C[0xE8 - 0x7C]; char xE8[0x18C - 0xE8]; s32 x18C, x190; char p1[0x1F0 - 0x194]; char x1F0[0x26BC - 0x1F0]; char x26BC[0x2718 - 0x26BC]; s32 x2718; };
EXTERN_C char D_800B7778[], D_800B77A0[], D_800B7AA0[], D_800B7AD4[];
EXTERN_C s32 func_800C3D50(Unk800C3D50*);

/* func_800BEDD0 */
struct Unk800BEDD0V0 { s32 x0, x4; };
struct Unk800BEDD0V1 { virtual void v1(s32); };
struct Unk800BEDD0V : Unk800BEDD0V0, Unk800BEDD0V1 {};
struct Unk800BEDD0R { s32 x0, x4; s32* x8; s32* xC; };
struct Unk800BEDD0W { s32 x0, x4; };
struct Unk800BEDD0M { s32 x0; Unk800BEDD0W* x4; char pad[0x2C - 8]; char* x2C; };
struct Unk800BEDD0 { char pad[0x64]; void* x64; Unk800BEDD0M* x68; char p2[0x70 - 0x6C]; Unk800BEDD0V* x70; char p3[0x78 - 0x74]; void* x78; };

EXTERN_C void func_800BEED4(Unk800BEED4*);

/* func_800BEF3C */
struct Unk800BEF3CV { const void* vptr; s32 x4; };
struct Unk800BEF3CE { char d[0x254]; };
struct Unk800BEF3CO { const void* x0; const void* x4; void* x8; s16 xC, xE, x10, x12; };
struct Unk800BEF3C { char p0[0x18 - 0x0]; const void* x18; char p1[0x50 - 0x1C]; Unk800BEF3CV* x50; const void* x54; const void* x58; char p2[0x68 - 0x5C]; s32 x68; s32 x6C; s32 x70; s32 x74; s32 x78; char x7C[0x50]; char xCC[0x1C]; char xE8[0x1C]; char x104[0x1C]; char x120[0x1C]; char x13C[0x28]; char x164[0x28]; s32 x18C; s32 x190; char x194[0x5C]; char x1F0[0x50]; char x240[0x1C]; char x25C[0x1C]; Unk800BEF3CE x278[15]; s32 x2564; char x2568[0x60]; s32 x25C8; char p3[0x25D8 - 0x25CC]; char x25D8[0x5C]; s32 x2634; s32 x2638; char p4[0x26BC - 0x263C]; char x26BC[0x6C]; char x2728[0x5C]; s32 x2784; char p5[0x27A0 - 0x2788]; char x27A0[0x5C]; s32 x27FC; char p6[0x2818 - 0x2800]; void* x2818; Unk800BEF3CV x281C; };
EXTERN_C char D_800B776C[], D_800B77B0[];
EXTERN_C void* D_800B4D60[];

/* func_800BCB14 */
// slot 5 returns a value: calling it as call_value is what gives retail's register choice (vt a2, pfn v0)
struct Unk800BCB14E { s16 delta; s16 index; s32 (*pfn)(void*, Unk800C10BCP); };
struct Unk800BCB14O { Unk800BCB14E* vt; };
inline Unk800C10BCP Unk800BCB14_pos(Unk800C595CR* q) { Unk800C595CR r = *q; return r.xy; }

/* func_800C6624 */
/* ctor of the func_800C77F0 object; virtual base at 0x614 */
struct Unk800C6624S { char d[0x1C]; };
struct Unk800C6624E { char d[0x50]; };
struct Unk800C6624 { char p0[0x18]; const void* x18; char p1[0x50 - 0x1C]; Unk800C5380V* x50; const void* x54; const void* x58; char p2[0x68 - 0x5C]; s32 x68; s32 x6C; char p3[0x74 - 0x70];
  Unk800C6624E x74[8]; Unk800C6624S x2F4[8]; Unk800C6624S x3D4[8]; Unk800C7740O* x4B4; s32 x4B8, x4BC, x4C0; char x4C4[0x514 - 0x4C4]; char x514[0x1C]; char x530[0x1C]; char x54C[0x1C];
  char x568[0x610 - 0x568]; s32 x610; Unk800C5380V x614; };
EXTERN_C const char D_800B813C[], D_800B8150[], D_800B8160[], D_800B8170[], D_800B8188[], D_800B819C[], D_800B81B0[], D_800B81C0[], D_800B81D4[], D_800B81E8[], D_800B81FC[];
EXTERN_C Unk800C8E64* func_800C8E64(Unk800C8E64*, s32);

/* func_800B9F74 */
struct Unk800B9F74P { s16 x, y; Unk800B9F74P() {} Unk800B9F74P(s16 x_, s16 y_) { x = x_; y = y_; } };
struct Unk800B9F74R { Unk800B9F74P xy; s16 w, h;
  Unk800B9F74R() { xy.x = 0; xy.y = 0; w = 0; h = 0; }
  Unk800B9F74R(Unk800B9F74P p) { xy = p; w = 0; h = 0; }
  Unk800B9F74R(Unk800B9F74P p, int) { xy = p; }
  Unk800B9F74R(int) {}
  Unk800B9F74R(s16 x, s16 y, s16 w_, s16 h_) { xy.x = x; xy.y = y; w = w_; h = h_; }
  Unk800B9F74R operator&(const Unk800B9F74R& a) const { const Unk800B9F74R& b = *this;
  Unk800B9F74R c(Unk800B9F74P(a.xy.x < b.xy.x ? b.xy.x : a.xy.x, a.xy.y < b.xy.y ? b.xy.y : a.xy.y), 0); c.w = 0; c.h = 0;
  s32 x2 = a.xy.x + a.w; if (b.xy.x + b.w < x2) x2 = b.xy.x + b.w; c.w = x2 - c.xy.x;
  s32 y2 = a.xy.y + a.h; if (b.xy.y + b.h < y2) y2 = b.xy.y + b.h; c.h = y2 - c.xy.y;
  if (c.w < 0 || c.h < 0) return Unk800B9F74R();
  return c;
}
};
struct Unk800B9F74D { u32 tag; u32 code[5]; };
struct Unk800B9F74O { char pad[0x10]; u32 x10; u32* x14; char p2[0x20 - 0x18]; Unk800B9F74R x20; char p3[0x30 - 0x28]; s32 x30; };
struct Unk800B9F74 { char pad[8]; s16 x8; u16 xA; Unk800B9F74D xC[2]; s16 x3C, x3E, x40, x42; Unk800B9F74P x44; s16 x48, x4A; };
EXTERN_C Unk800B9F74P D_800B4CF4[];
EXTERN_C Unk800B9F74R D_800AC730[];
inline Unk800B9F74R operator+(const Unk800B9F74R& r, const Unk800B9F74R& d) { return Unk800B9F74R(r.xy.x + d.xy.x, r.xy.y + d.xy.y, r.w, r.h); }

#define MINI800B9F74(a, b) ((a) >= (b) ? (b) : (a))
#define MINO800B9F74(a, b) ((a) < (b) ? (a) : (b))

/* func_800BD008 */
struct Unk800BD008P { s16 x, y; Unk800BD008P(s16 ax, s16 ay) { x = ax; y = ay; } };
struct Unk800BD008R {
  s16 x, y, w, h;
  Unk800BD008R() {}
  Unk800BD008R(s16 ax, s16 ay, s16 aw, s16 ah) { x = ax; y = ay; w = aw; h = ah; }
  Unk800BD008R(Unk800BD008P p) { *(Unk800BD008P*)this = p; w = 0; h = 0; }
};
inline Unk800BD008R Unk800BD008R_make2(s16 x, s16 y) { return Unk800BD008R(Unk800BD008P(x, y)); }
inline Unk800BD008R operator+(const Unk800BD008R& a, const Unk800BD008R& b) { return Unk800BD008R(a.x + b.x, a.y + b.y, a.w, a.h); }
inline Unk800BD008R operator&(const Unk800BD008R& a, const Unk800BD008R& c) {
  Unk800BD008R r = Unk800BD008R_make2(c.x < a.x ? a.x : c.x, c.y < a.y ? a.y : c.y);
  s32 ar = a.x + a.w, cr = c.x + c.w;
  r.w = (ar < cr ? ar : cr) - r.x;
  s32 ab = a.y + a.h, cb = c.y + c.h;
  r.h = (ab < cb ? ab : cb) - r.y;
  if (r.w < 0 || r.h < 0) return Unk800BD008R(0, 0, 0, 0);
  return r;
}
struct Unk800BD008O { char p0[0x20]; Unk800BD008R x20; char p1[0x30 - 0x28]; s32 x30; };
struct Unk800BD008E { s16 delta; s16 index; void* pfn; };
struct Unk800BD008V { Unk800BD008E* vt; };
struct Unk800BD008 { char p0[0x14]; Unk800BD008R x14[2]; s32 x24[3]; s32 x30, x34; char* x38[2]; char* x40; s32 x44; char p1[0x4C - 0x48]; s32 x4C; s16 x50, x52; Unk800BD008V* x54; };
inline Unk800BD008R Unk800BD008_clip() {
  char* g = (char*)D_800A4578[0];
  Unk800BD008E* vt = *(Unk800BD008E**)(g + 0x2C);
  Unk800BD008O* o = ((Unk800BD008O* (*)(void*))vt[12].pfn)(g + vt[12].delta);
  Unk800BD008O* q = o;
  if (o->x30) {
    return (o->x20 + Unk800BD008R(((Unk800BD008P*)D_800B4CF4)[D_800B4CF0[0] ^ 1])) & ((Unk800BD008R*)D_800AC730)[D_800B4CF0[0] ^ 1];
  }
  return q->x20;
}
EXTERN_C s32 D_800B6AA4[];

/* func_800BFA58 */
struct Unk800BFA58I { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(Unk800C10BCP); };
struct Unk800BFA58Q { Unk800BFA58I** x0; s32 x4; };
struct Unk800BFA58T { Unk800BFA58Q* x0; s32 x4; void* x8; };
struct Unk800BFA58E { char pad[0x18]; u16 x18; };
struct Unk800BFA58 { char pad[0x1C]; Unk800BFA58T x1C; char p1[0x74 - 0x28]; s32 x74; s32 x78; char x7C[0x2564 - 0x7C]; void* x2564; char x2568[0x2588 - 0x2568]; s32 x2588; };
struct Unk800BFA58R { Unk800C10BCP a, b; };
struct Unk800BFA58VE { s16 delta, index; void (*pfn)(); };
#define Unk800BFA58_v4(o, q) { Unk800BFA58VE* e_ = &(*(Unk800BFA58VE**)((char*)(o) + 0x18))[4]; ((void (*)(void*, Unk800C10BCP))e_->pfn)((char*)(o) + e_->delta, q); }

/* EXE functions that movie calls with another prototype than include/shared/exe.h. */
// func_8009C9C0 (PsyQ, not yet named) returns int to main_a2; movie was matched reading an unsigned char.
EXTERN_C u8 func_8009C9C0_c(void) asm("func_8009C9C0");
// Takes its point by value as S_A2_Pt (main_a2b); movie passes the same two shorts as Unk800C10BCP.
EXTERN_C void func_80053F48_m(void*, Unk800C10BCP) asm("func_80053F48");
// Takes its point by value as SV2C_80055020 (main_b); movie passes Unk800C10BCP.
EXTERN_C void func_80055020_m(void*, Unk800C10BCP) asm("func_80055020");
// Takes its point by value as Unk_Pt; movie passes Unk800C10BCP.
EXTERN_C void func_80063270_m(void*, Unk800C10BCP) asm("func_80063270");
// Returns S_Rgb by value; movie passes the hidden return slot itself.
EXTERN_C void func_80054054_m(Unk800C7740T*, void*) asm("func_80054054");
// Defined returning int; movie uses the result as an object pointer.
EXTERN_C Unk800B9208V* func_80019C68_m(Unk800B9208L*, s32) asm("func_80019C68");
// Takes one argument; movie passes up to three.
EXTERN_C void func_8005F1D8_v(void*, ...) asm("func_8005F1D8");
// Defined void (void); movie passes four arguments and uses $v0.
EXTERN_C s32 func_800468D0_m(void*, void*, void*, void*) asm("func_800468D0");
// Takes no arguments; movie passes one.
EXTERN_C s32 func_8006283C_m(Unk800C5B80O*) asm("func_8006283C");
// Takes no arguments; movie passes one.
EXTERN_C void func_800279A8_1(void*) asm("func_800279A8");
// Takes two arguments; movie passes one and leaves $a1 as it is.
EXTERN_C void func_800386B8_1(void*) asm("func_800386B8");
// Takes two arguments; movie passes one and leaves $a1 as it is.
EXTERN_C void func_80063340_1(void*) asm("func_80063340");
// Takes two arguments; movie passes one and leaves $a1 as it is.
EXTERN_C void func_80054C34_1(void*) asm("func_80054C34");
// Takes two arguments; movie passes one and leaves $a1 as it is.
EXTERN_C void func_8005F120_1(void*) asm("func_8005F120");

#endif /* MOVIE_H */
