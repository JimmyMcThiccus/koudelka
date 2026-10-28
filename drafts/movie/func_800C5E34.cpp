// func_800C5E34: 118 differ. Same two problems as drafts/gameend/func_800B7190.cpp (same loader shape): retail frame has 24 bytes of locals (here 16) and its loop has more RTL at loop time: retail hoists only the 3 vtable pairs (s5/s4/s3) and does NOT strength-reduce D_800CBAD0[i] (sll+addu with lui/addiu inside the loop); here &D_800CBAD0 is hoisted and reduced to a pointer giv (s2), adding s6.
#include "movie/movie.h"
struct Unk800C5E34F { char* data; void* h; };
struct Unk800C5E34O { const void* vptr; s32 x4; s16 x8, xA; };
struct Unk800C5E34P { s16 x, y; };
struct Unk800C5E34S { const void* vptr; s32 x4; const void* vptr8; void* xC; Unk800C5E34P x10; s16 x14, x16; s32 x18; s16 x1C, x1E; };
struct Unk800C5E34E { s16 delta; s16 index; void (*pfn)(void*); };
struct Unk800C5E34B { char pad[0x10]; Unk800C5E34E* vt10; };
struct Unk800C5E34V { virtual void v1(); virtual void v2(); virtual void v3(); };
EXTERN_C char D_800106EC[], D_80010654[], D_80010888[], D_800108A0[];
EXTERN_C void* D_800CBADC[];
EXTERN_C void* func_8005F238(Unk800C5E34F*);
EXTERN_C void func_8005F298(Unk800C5E34F*, s32, s32);
EXTERN_C char* func_8005F28C(Unk800C5E34F*);
EXTERN_C void func_8005F3E0(Unk800C5E34F*);
EXTERN_C void func_8005F248(Unk800C5E34F*, s32);
EXTERN_C void func_80021ACC(void*, char*);
EXTERN_C void func_80024BF0(void*, char*, s32, s32);
EXTERN_C void func_80025444(void*, void*, s32);
inline void Unk800C5E34_w(Unk800C5E34O* o) { o->vptr = D_80010178; o->x4 = 0; }
inline void Unk800C5E34_m(Unk800C5E34O* o) { Unk800C5E34_w(o); o->vptr = D_800106EC; o->x8 = 0; o->xA = 0; }
inline void Unk800C5E34_n(Unk800C5E34O* o, char* p) { Unk800C5E34_m(o); o->vptr = D_80010654; func_80021ACC(o, p); }
//@func
EXTERN_C void func_800C5E34() {
  if (D_800CBACC[0] == 0) {
    Unk800C5E34F f;
    func_8005F238(&f);
    func_8005F298(&f, 0x1426A, 0x8800);
    char* p = func_8005F28C(&f);
    p += 0x10;
    for (u32 i = 0; i < 4; i++) {
      Unk800C5E34O* o = (Unk800C5E34O*)operator new(0x2C);
      Unk800C5E34_n(o, p);
      p += 0x20;
      D_800CBAD0[i] = (Unk800C6024V*)o;
      Unk800C5E34B* b = (Unk800C5E34B*)D_800B4C38[0];
      b->vt10[1].pfn((char*)b + b->vt10[1].delta);
    }
    Unk800C5E34S* t = (Unk800C5E34S*)operator new(0x20);
    t->vptr8 = D_80010888;
    t->vptr = D_80010178;
    t->x4 = 0;
    t->vptr = D_800108A0;
    t->xC = D_800CBADC[0];
    struct { Unk800C5E34P a, b; } r;
    r.b.x = -1;
    r.b.y = -1;
    t->x10 = r.b;
    t->x14 = 0; t->x16 = 0; t->x18 = 0; t->x1E = 0;
    func_80024BF0(t, p, 0x100, 0x100);
    D_800CBACC[0] = t;
    func_80025444(D_800B4C48, t, 0);
    ((Unk800C5E34V*)D_800CBACC[0])->v3();
    func_8005F3E0(&f);
    func_8005F248(&f, 2);
  }
}
