// func_800B9208: 29 differing, built 4 bytes longer; list-head null-check pattern on D_800AC854 not reproduced yet.
struct V { virtual void v1(s32); };
struct L { s32 x0, x4; };
struct G { L* x0; };
struct S { virtual void v1(); virtual void v2(); virtual void v3(); };
extern "C" S* D_800B4D0C_S[];
extern "C" G D_800AC854;
extern "C" u8 func_80035C30(s32);
extern "C" V* func_80019C68(L*, s32);
extern "C" void func_800B9208(void* a, u8 b) { S* s = (S*)D_800B4D0C[0]; if (s != a) return; s->v3(); if (func_80035C30(b)) return; G* g = &D_800AC854; if ((g ? g->x0 : 0)->x4) func_80019C68(g ? g->x0 : 0, 0)->v1(0); }
