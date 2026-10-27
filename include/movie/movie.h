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
struct Game { s32 x0, x4; GameUnk8* x8; char pad[0x1D2 - 0xC]; u8 x1D2; };
EXTERN_C Game* D_800A4578[];

/* libgpu primitives */
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

struct Unk800BA50CR { s16 a, b, c, d; };
struct Unk800BA50C { char pad[0x30]; Unk800BA50CR x30; };

struct Unk800C5B30 { char pad[0x58]; s32 x58; };
EXTERN_C void func_80054FE0(void*);

struct Unk800C3E10 { char pad[0x50]; s32 x50; void* x54; };
EXTERN_C void func_80025CE0(void*, void*, s32);

EXTERN_C void func_8001FC78(s32, s32, s32);

struct Unk800BDF84T { s32 x0, x4, x8; volatile u32 xC; };
EXTERN_C Unk800BDF84T D_800A4534;

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

EXTERN_C void func_8001A610(void*);

EXTERN_C void func_80054C34(void*);

EXTERN_C void func_8005F120(void*);

EXTERN_C void StFreeRing(void*);

struct Unk800CA86C { char pad[0x10C]; void* x10C; };
EXTERN_C void func_800BDDC8(void*, s32, s32);

struct Unk800BA40CR { s16 a, b, c, d; };
struct Unk800BA40C { char pad[8]; s16 x8; char pad2[0x3C-0xA]; Unk800BA40CR x3C; Unk800BA40CR x44; };

struct Unk800BA438R { s16 a, b, c, d; };
struct Unk800BA438 { char pad[8]; s16 x8; char pad2[0x3C-0xA]; Unk800BA438R x3C; Unk800BA438R x44; };

struct Unk800BCE4CR { s32 a, b; };
struct Unk800BCE4C { char pad[0x14]; Unk800BCE4CR x14[3]; char p2[0x30-0x2C]; s32 x30; char p3[0x4C-0x34]; s32 x4C; };

EXTERN_C void func_8001AB50(void*, s32);

struct Unk800C3D5C { char pad[0x34]; s32 x34, x38; };
struct Unk800BF898 { char pad[0x78]; Unk800C3D5C* x78; };
EXTERN_C int func_800C3D5C(Unk800C3D5C*, s32);

struct DIRENTRY { char name[20]; s32 attr; s32 size; DIRENTRY* next; s32 head; char system[4]; };
EXTERN_C char D_800CBAAC[];
EXTERN_C void func_800C40D0(void*);
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

struct Unk800C1690B { char pad[0x1BC]; s32 x1BC, x1C0; char p2[0x204-0x1C4]; s32 x204, x208; };
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
EXTERN_C void func_800648E8(void*);

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

struct Unk800B97E4R { s16 a, b, c, d; };
struct Unk800B97E4B { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); };
struct Unk800B97E4 { s32 x0, x4; Unk800B97E4B* x8; char pad[0x30 - 0xC]; Unk800B97E4R x30; };

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
EXTERN_C void func_800B93D8(void*, s32, s32, s32);

#endif /* MOVIE_H */
