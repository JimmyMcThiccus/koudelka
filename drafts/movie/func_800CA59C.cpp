// func_800CA59C: built drops the middle vptr store (D_80010300) of the inlined constructor chain; retail keeps
// all three vptr stores. Probably needs the real class hierarchy (EXE vtables at 0x80010178/0x80010300/0x800102D0).
struct T { void* x0; s32 x4; s16 x8, xA; s32 xC, x10; };
struct A { char pad[0x108]; s16 x108; };
extern "C" char D_80010178[], D_80010300[], D_800102D0[];
extern "C" T* func_8001CA10(s32);
extern "C" void func_8001EFE4(void*, T*);
inline void c1(T* t) { t->x0 = D_80010178; }
inline void c2(T* t) { c1(t); t->x0 = D_80010300; t->x8 = 2; t->xA = 2; t->x4 = 0; }
inline void c3(T* t) { c2(t); t->x10 = 0; t->xC = 0; t->x0 = D_800102D0; }
extern "C" void func_800CA59C(A* p) { p->x108 = 0; T* t = func_8001CA10(0x14); c3(t); func_8001EFE4(p, t); }
