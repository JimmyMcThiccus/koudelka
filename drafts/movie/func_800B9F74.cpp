// func_800B9F74: far off (~270 differ; logic is right). Retail stack: r0 0x10, r1 0x18, result 0x20, offset rect b 0x28 (built in regs, no temp copy), RECT(pt) 0x30, pt copy at 0x3C (2nd word of an 8-byte slot), clip rect c 0x48, max-point m 0x54 (2nd word again). Intersection: m = MAX(q.x, b.x) with q = &D_800AC730[buf^1]; w/h clamps are MIN(MIN(r1.w, x3C + x40) - x3C, x48) with the macro's double evaluation.
#include "movie/movie.h"
struct Unk800B9F74P { s16 x, y; };
struct Unk800B9F74R { Unk800B9F74P xy; s16 w, h;
  Unk800B9F74R() { xy.x = 0; xy.y = 0; w = 0; h = 0; }
  Unk800B9F74R(Unk800B9F74P p) { xy = p; w = 0; h = 0; } };
struct Unk800B9F74D { u32 tag; u32 code[5]; };
struct Unk800B9F74O { char pad[0x10]; u32 x10; u32* x14; char p2[0x20 - 0x18]; Unk800B9F74R x20; char p3[0x30 - 0x28]; s32 x30; };
struct Unk800B9F74 { char pad[8]; s16 x8; u16 xA; Unk800B9F74D xC[2]; s16 x3C, x3E, x40, x42; Unk800B9F74P x44; s16 x48, x4A; };
EXTERN_C Unk800B9F74P D_800B4CF4[];
EXTERN_C Unk800B9F74R D_800AC730[];
EXTERN_C void SetDrawMove(void*, Unk800B9F74R*, s32, s32);
inline Unk800B9F74R operator+(const Unk800B9F74R& r, const Unk800B9F74R& d) { Unk800B9F74R t; t.xy.x = r.xy.x + d.xy.x; t.xy.y = r.xy.y + d.xy.y; t.w = r.w; t.h = r.h; return t; }
inline Unk800B9F74R operator&(const Unk800B9F74R& a, const Unk800B9F74R& b) {
  Unk800B9F74P m; m.x = a.xy.x < b.xy.x ? b.xy.x : a.xy.x; m.y = a.xy.y < b.xy.y ? b.xy.y : a.xy.y;
  Unk800B9F74R c(m);
  s16 x2 = a.xy.x + a.w; if (b.xy.x + b.w < x2) x2 = b.xy.x + b.w; c.w = x2 - c.xy.x;
  s16 y2 = a.xy.y + a.h; if (b.xy.y + b.h < y2) y2 = b.xy.y + b.h; c.h = y2 - c.xy.y;
  if (c.w < 0 || c.h < 0) return Unk800B9F74R();
  return c;
}
#define MIN800B9F74(a, b) ((a) < (b) ? (a) : (b))
//@func
EXTERN_C s32 func_800B9F74(Unk800B9F74* p) {
  Unk800B9F74R r0, r1;
  if (p->x8 < 3 && p->x8 > 0) {
    Unk800B9F74O* o = (Unk800B9F74O*)D_800B4CFC[0];
    r1 = o->x30 ? D_800AC730[D_800B4CF0[0] ^ 1] & (o->x20 + Unk800B9F74R(D_800B4CF4[D_800B4CF0[0] ^ 1])) : o->x20;
    r1.xy.x += p->x3C; r1.xy.y += p->x3E;
    r0.xy = p->x44;
    r0.w = MIN800B9F74(MIN800B9F74(r1.w, p->x3C + p->x40) - p->x3C, p->x48);
    r0.h = MIN800B9F74(MIN800B9F74(r1.h, p->x3E + p->x42) - p->x3E, p->x4A);
    SetDrawMove(&p->xC[D_800B4CF0[0]], &r0, r1.xy.x, r1.xy.y);
    p->x8--;
  }
  Unk800C648C_add(p->xA, &p->xC[D_800B4CF0[0]].tag);
  return 1;
}
