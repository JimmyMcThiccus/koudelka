// func_800BEDD0: 61 differing, built 20 bytes short: retail keeps &t in $s1, adjusts x70 by +8 before the virtual call, and copies the computed pointer through several registers (inlined helpers).
struct X { char pad[8]; virtual void v1(s32); };
struct R { s32 x0, x4; s32* x8; s32* xC; };
struct W { s32 x0, x4; };
struct M { s32 x0; W* x4; char pad[0x2C - 8]; char* x2C; };
struct A { char pad[0x64]; void* x64; M* x68; char p2[0x70 - 0x6C]; X* x70; char p3[0x78 - 0x74]; void* x78; };
extern "C" void func_80050838(Unk800BE5F8T*);
extern "C" R* func_80049398(void*);
extern "C" void* func_80050874(Unk800BE5F8T*, s32*, R*, s32, s32);
extern "C" void func_80025444(void*, void*, s32);
extern "C" void* D_800B4C18[];
extern "C" void func_8001ED2C(void*, s32, s32);
extern "C" void func_800BEED4(void*);
extern "C" void* func_800BEDD0(A* p) { Unk800BE5F8T t; func_80050838(&t); if (p->x70) p->x70->v1(3); R* r = func_80049398(p->x64); s32* ptr = (s32*)(p->x68->x2C + p->x68->x4->x4); r->xC = ptr; r->x8 = r->xC; r->xC = r->x8 + 6; if (*ptr == -1) { p->x78 = func_80050874(&t, ptr + 3, r, 0, 0); func_80025444(D_800B4C48, p->x78, 0); func_8001ED2C(D_800B4C18[0], 5, 3); } else p->x78 = 0; func_800BEED4(p); return p->x78; }
