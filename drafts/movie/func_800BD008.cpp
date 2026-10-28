// DRAFT: 26 differing instructions. Remaining: (1) in the clip-rect inline (cases 4/5) the R(P) ctor's this for the intersection result r (sp+0x40) stays in a register (t1) so its w=0/h=0 stores go through t1 instead of sp+0x44/0x46; this also shifts o into a0 instead of the retail v1 copy (retail else-branch copies via v1). Cause: r sits at offset 0 of operator&'s inline frame (retail evidently has it at a nonzero offset with the same overall frame layout). (2) case 0 copy loop: giv base a0 = s-4 instead of s+0x1C (loop strength reduction picks a different giv). Everything else matches.
#include "movie/movie.h"
struct Unk800BD008P { s16 x, y; Unk800BD008P(s16 ax, s16 ay) { x = ax; y = ay; } };
struct Unk800BD008R {
  s16 x, y, w, h;
  Unk800BD008R() {}
  Unk800BD008R(s16 ax, s16 ay, s16 aw, s16 ah) { x = ax; y = ay; w = aw; h = ah; }
  Unk800BD008R(Unk800BD008P p) { *(Unk800BD008P*)this = p; w = 0; h = 0; }
};
inline Unk800BD008R operator+(const Unk800BD008R& a, const Unk800BD008R& b) { return Unk800BD008R(a.x + b.x, a.y + b.y, a.w, a.h); }
inline Unk800BD008R operator&(const Unk800BD008R& a, const Unk800BD008R& c) {
  Unk800BD008R r(Unk800BD008P(c.x < a.x ? a.x : c.x, c.y < a.y ? a.y : c.y));
  s32 ar = a.x + a.w, cr = c.x + c.w;
  r.w = (ar < cr ? ar : cr) - r.x;
  s32 ab = a.y + a.h, cb = c.y + c.h;
  r.h = (ab < cb ? ab : cb) - r.y;
  if (r.w < 0 || r.h < 0) return Unk800BD008R(0, 0, 0, 0);
  return r;
}
EXTERN_C Unk800BD008P D_800B4CF4[];
EXTERN_C Unk800BD008R D_800AC730[];
struct Unk800BD008O { char p0[0x20]; Unk800BD008R x20; char p1[0x30 - 0x28]; s32 x30; };
struct Unk800BD008E { s16 delta; s16 index; void* pfn; };
struct Unk800BD008V { Unk800BD008E* vt; };
struct Unk800BD008 { char p0[0x14]; Unk800BD008R x14[2]; s32 x24[3]; s32 x30, x34; char* x38[2]; char* x40; s32 x44; char p1[0x4C - 0x48]; s32 x4C; s16 x50, x52; Unk800BD008V* x54; };
inline Unk800BD008R Unk800BD008_clip() {
  char* g = (char*)D_800A4578[0];
  Unk800BD008E* vt = *(Unk800BD008E**)(g + 0x2C);
  Unk800BD008O* o = ((Unk800BD008O* (*)(void*))vt[12].pfn)(g + vt[12].delta);
  if (o->x30) {
    return (o->x20 + Unk800BD008R(D_800B4CF4[D_800B4CF0[0] ^ 1])) & D_800AC730[D_800B4CF0[0] ^ 1];
  }
  return o->x20;
}
EXTERN_C s32 D_800B6AA4[];
EXTERN_C void StCdInterrupt();
EXTERN_C s32 LoadImage(void*, void*);
//@func
EXTERN_C void func_800BD008(void* vp) {
  Unk800BD008* p = (Unk800BD008*)vp;
  if (p->x4C == 5 && D_800B6AA4[0]) { StCdInterrupt(); D_800B6AA4[0] = 0; }
  Unk800BD008R r; r.x = 0; r.y = 0; r.w = 0; r.h = 0;
  s32 cur = p->x30;
  s32 pos = p->x34;
  char* buf = p->x38[p->x44];
  p->x34 = pos + 16;
  p->x44 ^= 1;
  if (p->x34 < p->x50) {
    s32 n = p->x52;
    DecDCTout(p->x38[p->x44], (p->x4C == 1 || p->x4C == 5) ? n * 12 : n * 8);
  } else {
    if (p->x24[cur] == 2) p->x24[cur] = 0;
    p->x30 = cur ^ 1;
    if (p->x24[p->x30] == 1) func_800BCEA0(p);
    else {
      DecDCToutCallback(0);
      Unk800BD008V* o = p->x54;
      if (o) ((void (*)(void*))o->vt[1].pfn)((char*)o + o->vt[1].delta);
    }
  }
  switch (p->x4C) {
  case 0: {
    u32* s = (u32*)buf;
    u32* dst = (u32*)p->x40 + (u32)pos / 2;
    s32 i = 0;
    while (1) {
      if (!(i < p->x52)) break;
      i++;
      u32 a = s[0], b = s[1], c = s[2], d = s[3]; s += 8;
      dst[0] = a; dst[1] = b; dst[2] = c; dst[3] = d;
      a = s[-4]; b = s[-3]; c = s[-2]; d = s[-1];
      dst[4] = a; dst[5] = b; dst[6] = c; dst[7] = d;
      dst += (u32)p->x50 / 2;
    }
    return;
  }
  case 1: {
    u32* src = (u32*)buf;
    u32* dst = (u32*)p->x40 + pos;
    s32 i = 0;
    while (1) {
      if (!(i < p->x52)) break;
      for (s32 j = 0; j < 16; j++) *dst++ = *src++;
      i++;
      s32 k = p->x50 - 16; dst += k;
    }
    return;
  }
  case 2: r = p->x14[0]; break;
  case 3: r = p->x14[cur]; break;
  case 4: r = Unk800BD008_clip(); break;
  case 5:
    r = Unk800BD008_clip();
    r.w = 24;
    r.x += (u32)(pos * 3) / 2;
    LoadImage(&r, buf);
    LoadImage(&r, buf);
    p->x38[p->x44 ^ 1] = p->x38[p->x44] + p->x52 * 48;
    return;
  }
  r.w = 16;
  r.x += pos;
  p->x38[p->x44 ^ 1] = p->x38[p->x44] + p->x52 * 32;
}
