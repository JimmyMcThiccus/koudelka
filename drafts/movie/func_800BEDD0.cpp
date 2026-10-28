// func_800BEDD0: 33 differing (4 bytes short): retail keeps two extra register copies of the header pointer (a0=h for +0x18/+0xC, v0=h for the *h==-1 load); everything else incl. virtual call via base at +8 matches.
#include "movie/movie.h"
struct Unk800BEDD0V0 { s32 x0, x4; };
struct Unk800BEDD0V1 { virtual void v1(s32); };
struct Unk800BEDD0V : Unk800BEDD0V0, Unk800BEDD0V1 {};
struct Unk800BEDD0R { s32 x0, x4; s32* x8; s32* xC; };
struct Unk800BEDD0W { s32 x0, x4; };
struct Unk800BEDD0M { s32 x0; Unk800BEDD0W* x4; char pad[0x2C - 8]; char* x2C; };
struct Unk800BEDD0 { char pad[0x64]; void* x64; Unk800BEDD0M* x68; char p2[0x70 - 0x6C]; Unk800BEDD0V* x70; char p3[0x78 - 0x74]; void* x78; };
EXTERN_C void func_80050838(Unk800BE5F8T*);
EXTERN_C Unk800BEDD0R* func_80049398(void*);
EXTERN_C void* func_80050874(Unk800BE5F8T*, s32*, Unk800BEDD0R*, s32, s32);
EXTERN_C void func_80025444(void*, void*, s32);
EXTERN_C void func_800BEED4(void*);
//@func
EXTERN_C void* func_800BEDD0(Unk800BEDD0* p) { Unk800BE5F8T t; Unk800BE5F8T* tp = &t; func_80050838(tp); if (p->x70) p->x70->v1(3); Unk800BEDD0R* r = func_80049398(p->x64); r->xC = (s32*)(p->x68->x2C + p->x68->x4->x4); r->x8 = r->xC; s32* h = r->xC; r->xC = h + 6; if (*r->x8 == -1) { p->x78 = func_80050874(tp, h + 3, r, 0, 0); func_80025444(D_800B4C48, p->x78, 0); func_8001ED2C(D_800B4C18[0], 5, 3); } else p->x78 = 0; func_800BEED4(p); return p->x78; }
