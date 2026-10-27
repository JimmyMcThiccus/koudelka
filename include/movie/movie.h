#ifndef MOVIE_H
#define MOVIE_H

#include "common.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

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

EXTERN_C s32 D_800CBA94[];

struct Unk800B8E9C { char pad[0x40]; s32 x40; };

struct Unk800BE54C { char pad[0x64]; s16 x64; char pad2[0x6E-0x66]; s16 x6E; };

struct Unk800BCE7C { char pad[0x34]; s32 x34; char p2[0x40-0x38]; s32 x40; char p3[0x50-0x44]; s16 x50; };

struct Unk800BA50CR { s16 a, b, c, d; };
struct Unk800BA50C { char pad[0x30]; Unk800BA50CR x30; };

struct Unk800C5B30 { char pad[0x58]; s32 x58; };
EXTERN_C void func_80054FE0(Unk800C5B30*);

struct Unk800C3E10 { char pad[0x50]; s32 x50, x54; };
EXTERN_C void func_80025CE0(s32, s32, s32);

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

EXTERN_C void func_8003546C(void*);

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


struct Unk800C9058B { char pad[0x1D2]; u8 x1D2; };
struct Unk800C9058 { char pad[0x20]; s32 x20; };
EXTERN_C Unk800C9058B* D_800A4578[];
EXTERN_C void func_800550FC(Unk800C9058*, s32);

struct Unk800C1690B { char pad[0x1BC]; s32 x1BC, x1C0; char p2[0x204-0x1C4]; s32 x204, x208; };
EXTERN_C Unk800C1690B* D_800B4DD0[];

struct Unk800C407CH { s32 x0; char d[0x5C]; char e[0x20]; char rows[1][128]; };
struct Unk800C407C { char pad[0x44]; Unk800C407CH* x44; char* x48; char* x4C; s32 x50; char* x54; char* x58; char* x5C; };

struct Unk800C8A54R { char pad[0x1E]; u16 x1E; char p2[40-0x20]; };
struct Unk800C8A54 { Unk800C8A54R x0[1]; };
struct Unk800C8A54B { char pad[8]; u16 x8; };
EXTERN_C s32 D_800B4CF0[];
EXTERN_C void func_8005F1D8(Unk800C8A54*, Unk800C8A54B*);

struct Unk800B8F34B { s32 x0, x4; };
struct Unk800B8F34 { s32 x0; Unk800B8F34B* x4; char p2[0x40-8]; u8* x40; };

EXTERN_C void* D_800CBA90[];
EXTERN_C void* func_800BD988(void*);

struct Unk800B95DCB { virtual void v1(); virtual void v2(void*, s32); };
struct Unk800B95DC { s32 x0, x4; char x8[0x20]; };

#endif /* MOVIE_H */
