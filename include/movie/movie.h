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

#endif /* MOVIE_H */
