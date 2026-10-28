// built 536 vs 544 bytes: same computation; retail makes two extra copies (s1 = cos, t0 = sin) used only by the final y3 term, and the poly base lives in v1; regalloc differs throughout
#include "movie/movie.h"
EXTERN_C s32 func_800260A4(s32);
EXTERN_C s32 func_80026014(s32);
//@func
EXTERN_C void func_800C8674(Unk800C8594* p, s32 a) {
  s32 i = D_800B4CF0[0];
  s32 c = func_800260A4(a);
  s32 s = func_80026014(a);
  s32 x, y;
  x = p->x10[i].x0; y = p->x10[i].y0;
  p->x10[i].x0 = (x * c - y * s + 0x800) / 4096; p->x10[i].y0 = (x * s + y * c + 0x800) / 4096;
  x = p->x10[i].x1; y = p->x10[i].y1;
  p->x10[i].x1 = (x * c - y * s + 0x800) / 4096; p->x10[i].y1 = (x * s + y * c + 0x800) / 4096;
  x = p->x10[i].x2; y = p->x10[i].y2;
  p->x10[i].x2 = (x * c - y * s + 0x800) / 4096; p->x10[i].y2 = (x * s + y * c + 0x800) / 4096;
  x = p->x10[i].x3; y = p->x10[i].y3;
  p->x10[i].x3 = (x * c - y * s + 0x800) / 4096; p->x10[i].y3 = (x * s + y * c + 0x800) / 4096;
  func_8005F1D8(p);
}
