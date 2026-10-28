// func_800C60E8: 47 differing (8 bytes short: nop placement): everything matches except the SPRT base pointer q gets $a2 instead of $a0, because sched1 hoists the call's `a0 = p` above the clut store at the if/else join; that shifts a few insns. Note: D_800CBACC must be read through a local pointer (it is really a scalar).
#include "movie/movie.h"
struct Unk800C60E8DM { u32 tag; u32 code[2]; };
struct Unk800C60E8W { char pad[8]; u16 x8; };
struct Unk800C60E8G { char pad[0x1C]; u16 x1C; };
struct Unk800C60E8S { u32 tag; u32 w1, w2, w3, w4; };
struct Unk800C60E8 { void* x0; char pad[0x10 - 4]; Unk800C60E8DM x10[2]; SPRT x28[2]; };
struct Unk800C60E8Q { char pad[0x28]; SPRT s; };
EXTERN_C Unk800C60E8W* D_800CBADC[];
#define p ((Unk800C60E8*)vp_)
//@func
EXTERN_C void* func_800C60E8(void* vp_, s32 idx, Unk800C10BCP* pos, s32 tp) {
  func_8005F0E4(p, tp);
  ((u8*)&p->x28[0])[3] = 4; p->x28[0].code = 0x64;
  ((u8*)&p->x28[1])[3] = 4; p->x28[1].code = 0x64;
  p->x0 = D_800B80D4;
  void** g = D_800CBACC;
  SetDrawMode(&p->x10[0], 0, 0, ((Unk800C60E8G*)*g)->x1C, 0);
  SetDrawMode(&p->x10[1], 0, 0, ((Unk800C60E8G*)*g)->x1C, 0);
  s32 i = D_800B4CF0[0];
  Unk800C60E8Q* q = (Unk800C60E8Q*)((char*)p + i * 20);
  q->s.x0 = pos->x; q->s.y0 = pos->y;
  Unk800C60E8W* w;
  if ((u32)idx < 16) { q->s.h = 0x28; q->s.w = 0x1E; q->s.u0 = idx * 32; q->s.v0 = 0; w = (Unk800C60E8W*)D_800CBAD0[idx]; }
  else { q->s.h = 0x10; q->s.w = 0x80; q->s.v0 = (idx & 0xF) * 16 + 0x40; q->s.u0 = 0; w = D_800CBADC[0]; }
  u16 c = w->x8; q->s.clut = c;
  func_800C62E4((Unk800C62E4*)p, (Unk800C62E4B*)D_800B4C88);
  Unk800C60E8S* a = (Unk800C60E8S*)&p->x28[i]; Unk800C60E8S* d = (Unk800C60E8S*)&p->x28[i ^ 1];
  u32 w1 = a->w1, w2 = a->w2, w3 = a->w3, w4 = a->w4; d->w1 = w1; d->w2 = w2; d->w3 = w3; d->w4 = w4;
  return p;
}
#undef p

