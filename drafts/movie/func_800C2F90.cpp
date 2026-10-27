// func_800C2F90: 7 differing instructions: retail loads p->x50 before the D_800CBA94 store and computes the size
// as (n << 7) + 0x80 + (x50 << 7) in a different order. Same pattern as func_800C40B8.
struct B { s16 x0; s16 x2; s32 x4; };
struct A { s32 x0; B* x4; char p2[0x34 - 8]; s32 x34; char p3[0x44 - 0x38]; void* x44; char p4[0x50 - 0x48]; s32 x50; };
extern "C" s32 read(s32, void*, s32);
extern "C" s32 func_800C2F90(A* p, s32 n) { p->x4->x0 = 4; if (p->x34 == -1 || D_800CBA94[0] != 0) return 0; D_800CBA94[0] = p; read(p->x34, p->x44, (n * 128 + 128) + p->x50 * 128); p->x4->x4 = -1; p->x4->x0 = 1; return 1; }
