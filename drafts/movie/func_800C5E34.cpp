// func_800C5E34: 8 differ (same size). k4: D_800CBAD0 aliased as a small object (unsplit `la`, not hoisted, no giv) -> loop hoisting matches retail; Point layout via 8-byte block local + dead 8-byte local (24 bytes of locals, point at sp+0x1C). Remaining (same as B7190): retail has `addu a1,s0` before `addiu s2,s2,0x20` after the ctor call, and in the D_800CBAD0[i] store retail uses a0 for &D_800CBAD0 / v1 for the index / v0 for %hi(D_800B4C38) (ours v1/v0/a0). Both look like symptoms of the real (split, unhoisted) address pair rather than `la`.
#include "movie/movie.h"
typedef Unk800C5B80A Unk800C5E34F;
struct Unk800C5E34O { const void* vptr; s32 x4; s16 x8, xA; };
struct Unk800C5E34P { s16 x, y; };
struct Unk800C5E34S { const void* vptr; s32 x4; const void* vptr8; void* xC; Unk800C5E34P x10; s16 x14, x16; s32 x18; s16 x1C, x1E; };
struct Unk800C5E34E { s16 delta; s16 index; void (*pfn)(void*); };
struct Unk800C5E34B { char pad[0x10]; Unk800C5E34E* vt10; };
struct Unk800C5E34V { virtual void v1(); virtual void v2(); virtual void v3(); };
EXTERN_C char D_80010654[];
EXTERN_C void func_80021ACC(void*, char*);
inline void Unk800C5E34_w(Unk800C5E34O* o) { o->vptr = D_80010178; o->x4 = 0; }
inline void Unk800C5E34_m(Unk800C5E34O* o) { Unk800C5E34_w(o); o->vptr = D_800106EC; o->x8 = 0; o->xA = 0; }
inline void Unk800C5E34_n(Unk800C5E34O* o, char* p) { Unk800C5E34_m(o); o->vptr = D_80010654; func_80021ACC(o, p); }
EXTERN_C Unk800C6024V* D_800CBAD0_s[1] asm("D_800CBAD0");
//@func
EXTERN_C void func_800C5E34() {
  if (D_800CBACC[0] == 0) {
    Unk800C5E34F f;
    func_8005F238(&f);
    func_8005F298(&f, 0x1426A, 0x8800);
    char* p = (char*)func_8005F28C(&f);
    p += 0x10;
    for (u32 i = 0; i < 4; i++) {
      Unk800C5E34O* o = (Unk800C5E34O*)operator new(0x2C);
      Unk800C5E34_n(o, p);
      p += 0x20;
      Unk800C5E34B* b = (Unk800C5E34B*)D_800B4C38[0];
      D_800CBAD0_s[i] = (Unk800C6024V*)o;
      ((void (*)(void*, void*))b->vt10[1].pfn)((char*)b + b->vt10[1].delta, o);
    }
    Unk800C5E34S* t = (Unk800C5E34S*)operator new(0x20);
    struct { Unk800C5E34P a, b; } r; Unk800C5E34P u;
    void* own = (void*)D_800CBADC[0];
    t->vptr = D_80010178;
    t->x4 = 0;
    t->vptr8 = D_80010888;
    t->vptr = D_800108A0;
    t->xC = own;
    r.b.y = r.b.x = -1; t->x10 = r.b;
    t->x14 = 0; t->x16 = 0; t->x18 = 0; t->x1E = 0;
    func_80024BF0(t, p, 0x100, 0x100);
    D_800CBACC[0] = (void*)t;
    func_80025444(D_800B4C48, t, 0);
    ((Unk800C5E34V*)D_800CBACC[0])->v3();
    func_8005F3E0(&f);
    func_8005F248(&f, 2);
  }
}
