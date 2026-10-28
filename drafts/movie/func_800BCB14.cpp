// func_800BCB14 (dtor of Unk800BC714): 59 differ, sched1 order only in the two virtual calls (cases 3/2, slot 5 of D_800B4C54[0], arg = self->x14[i].pos copied via an 8-byte temp): retail order is hi,lo,addu a0,sll,lw pfn (vt stays in a2, copy temps a3/t0); GCC gives hi,pfn,addu,lo,sll (vt in v1, temps a2/a3). The real-virtual form `((Unk800BCB14V*)D_800B4C54[0])->f5(Unk800C10BCP(Unk800C595CR(self->x14[i]).xy))` gives the identical 59; `->f5(self->x14[i].pos)` gives 67.
#include "movie/movie.h"
struct Unk800BCB14E { s16 delta; s16 index; void (*pfn)(void*, Unk800C10BCP); };
struct Unk800BCB14O { Unk800BCB14E* vt; };
EXTERN_C char D_800B7644[];
inline Unk800C10BCP Unk800BCB14_pos(Unk800C595CR* q) { Unk800C595CR r = *q; return r.xy; }
//@keep D_800B7644
//@func
EXTERN_C void func_800BCB14(Unk800BC714* self, s32 f) {
  void* q;
  self->x0 = D_800B7644;
  if (self->x4[0]) func_800A0D0C(self->x4[0]);
  if (self->x4[1]) func_800A0D0C(self->x4[1]);
  switch (self->x4C) {
  case 0: case 1:
    q = self->x38;
    goto free;
  case 3: { Unk800BCB14O* o = (Unk800BCB14O*)D_800B4C54[0]; Unk800BCB14E* e = o->vt; void* t = (char*)o + e[5].delta; e[5].pfn(t, Unk800BCB14_pos((Unk800C595CR*)&self->x14[1])); }
  case 2: { Unk800BCB14O* o = (Unk800BCB14O*)D_800B4C54[0]; Unk800BCB14E* e = o->vt; void* t = (char*)o + e[5].delta; e[5].pfn(t, Unk800BCB14_pos((Unk800C595CR*)&self->x14[0])); }
  case 4: case 5:
    q = self->x40;
  free:
    if (q) func_800A0D0C(q);
  }
  func_800198AC((Unk800BE5F8T*)self, f);
}
