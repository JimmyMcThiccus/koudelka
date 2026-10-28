// 31 differ: dataflow right, scheduling/regalloc of the u/v adds and the x0/u0 loads differ
#include "movie/movie.h"
struct Unk800C899CQ { s16 x, y; };
struct Unk800C899C { char pad[0x10]; POLY_FT4 x10[2]; u8 x60, x61; };
inline void fixA(Unk800C899C* p, s32 i, s32 u, s32 v) {
  u -= p->x10[i].x0;
  p->x10[i].u2 = p->x10[i].u0;
  p->x10[i].u1 = p->x10[i].x1 + u;
  p->x10[i].u3 = p->x10[i].x3 + u;
  v -= p->x10[i].y0;
  p->x10[i].v2 = p->x10[i].y2 + v;
  p->x10[i].v1 = p->x10[i].v0;
  p->x10[i].v3 = p->x10[i].y3 + v;
}
inline void fixB(Unk800C899C* p, s32 i, s32 u, s32 v) {
  p->x10[i].u1 = p->x10[i].x1 - p->x10[i].x0 + u;
  p->x10[i].v1 = p->x10[i].v0;
  p->x10[i].u2 = p->x10[i].u0;
  p->x10[i].v2 = p->x10[i].y2 - p->x10[i].y0 + v;
  p->x10[i].u3 = p->x10[i].x3 - p->x10[i].x0 + u;
  p->x10[i].v3 = p->x10[i].y3 - p->x10[i].y0 + v;
}
//@func
EXTERN_C void func_800C899C(Unk800C899C* p, Unk800C899CQ* q) {
  s32 u = q->x + p->x60;
  s32 v = q->y + p->x61;
  s32 i = D_800B4CF0[0];
  p->x10[i].u0 = q->x + p->x60;
  p->x10[i].v0 = q->y + p->x61;
  fixA(p, i, u, v);
  func_8005F1D8(p);
}
