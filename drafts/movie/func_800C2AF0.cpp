// func_800C2AF0: 5 differing: only the open() flags select: retail has `addiu v0,1; bne; ori s3,0x8001 (delay); ori s3,0x8002`, here sched puts ori 0x8001 before the compare and reorg fills the delay slot with the join's `addiu a0,sp,0x10` instead.
#include "movie/movie.h"
struct Unk800C2AF0B { s16 x0; s16 x2; s32 x4; };
struct Unk800C2AF0 { s32 x0; Unk800C2AF0B* x4; char p2[0x34 - 8]; s32 x34; };
struct Unk800C2AF0S { char d[26]; };
//@func
#define p ((Unk800C2AF0*)vp)
EXTERN_C s32 func_800C2AF0(Unk800C3228* vp, void* name, s32 mode) {
  p->x4->x0 = 4;
  if (p->x34 != -1 || D_800CBA94[0] != 0) return -1;
  func_800C40D0(p, name);
  Unk800C2AF0S path = *(Unk800C2AF0S*)D_800CBAAC;
  s32 fl;
  if (mode == 1) fl = 0x8002; else fl = 0x8001;
  p->x34 = open((char*)&path, fl);
  for (u32 i = 0; p->x34 == -1 && i < 30; i++) {
    Unk800C3F68E* e = func_8001ED2C(D_800B4C18[0], 2, 1);
    if (e) { if (e->xA == 4 && e->xC) e->xC->v1(3); e->v2(); }
    p->x34 = open((char*)&path, fl);
  }
  s32 r;
  if (p->x34 == -1) { p->x4->x4 = -1; p->x4->x0 = 2; r = 5; } else { p->x4->x4 = 0; p->x4->x0 = 0; r = 0; }
  return r;
}
#undef p
