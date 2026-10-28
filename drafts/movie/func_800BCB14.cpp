// func_800BCB14 (ALSO blocked by jtbl alignment): 59 differ, register allocation only in the two case 3/2 virtual calls: retail keeps the vptr in a2 (pfn loaded late, after the arg halves), copy temps a3/t0; stack layout and order otherwise right.
#include "movie/movie.h"
struct Unk800BCB14E { s16 delta; s16 index; void (*pfn)(void*, Unk800C10BCP); };
struct Unk800BCB14O { Unk800BCB14E* vt; };
struct Unk800BCB14P { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(Unk800C10BCP); };
struct Unk800BCB14 { const void* x0; void* x4; void* x8; char p0[0x14 - 0xC]; Unk800C595CR x14; Unk800C595CR x1C; char p1[0x38 - 0x24]; void* x38; char p2[0x40 - 0x3C]; void* x40; char p3[0x4C - 0x44]; u32 x4C; };
EXTERN_C Unk800BCB14O* D_800B4C54[];
EXTERN_C char D_800B7644[];
inline Unk800C10BCP Unk800BCB14_xy(Unk800C595CR* q) { Unk800C595CR r = *q; return r.xy; }
EXTERN_C void func_800BCB14(Unk800BCB14* p, s32 f) {
  void* q;
  p->x0 = D_800B7644;
  if (p->x4) func_800A0D0C(p->x4);
  if (p->x8) func_800A0D0C(p->x8);
  switch (p->x4C) {
  case 0: case 1:
    q = p->x38;
    goto free;
  case 3: { Unk800BCB14O* o = D_800B4C54[0]; Unk800BCB14E* e = o->vt; void* t = (char*)o + e[5].delta; e[5].pfn(t, Unk800BCB14_xy(&p->x1C)); }
  case 2: { Unk800BCB14O* o = D_800B4C54[0]; Unk800BCB14E* e = o->vt; void* t = (char*)o + e[5].delta; e[5].pfn(t, Unk800BCB14_xy(&p->x14)); }

  case 4: case 5:
    q = p->x40;
  free:
    if (q) func_800A0D0C(q);
  }
  func_800198AC((Unk800BE5F8T*)p, f);
}
