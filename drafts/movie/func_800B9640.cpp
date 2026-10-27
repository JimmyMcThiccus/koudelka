// func_800B9640: 20 differing: retail copies this into $v0 before the call and does the trailing vptr/zero stores through $v0; also v1=&x4C is computed before li 0x10.
struct VB { s16 x0, x2; s32 x4; };
struct A { void* x0; VB* x4; void* x8; void* xC; char x10[0x28 - 0x10]; s32 x28, x2C; char p2[0x3C - 0x30]; s32 x3C, x40, x44; char p3[0x4C - 0x48]; VB x4C; };
extern "C" char D_80012154[], D_8001201C[], D_80012034[], D_80012294[], D_80012224[], D_800B6F34[], D_800B6F4C[];
extern "C" void func_800198E0(void*, s32, s32);
inline A* Unk800B9640_base(A* t) { t->x0 = D_80012154; t->x8 = D_8001201C; t->x0 = D_80012034; t->xC = t->x10; func_800198E0(t->x10, 4, 0); return t; }
extern "C" A* func_800B9640(A* p, s32 f) { if (f) { VB* v = &p->x4C; v->x0 = 0x10; p->x4 = v; v->x2 = 1; v->x4 = -1; } p->x0 = D_80012154; p->x8 = D_8001201C; p->x0 = D_80012034; p->xC = p->x10; func_800198E0(p->x10, 4, 0); A* r = p; r->x8 = D_80012294; r->x0 = D_80012224; r->x8 = D_800B6F34; r->x28 = 0; r->x2C = 0; r->x0 = D_800B6F4C; r->x3C = 0; r->x40 = 0; r->x44 = 0; return r; }
