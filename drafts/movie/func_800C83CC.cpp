// 3 differ (ctor form): only the tail differs: retail schedules 'v0 = this' between the final lw/sw (temp v1); ours uses v0 as the temp and sets v0 after. Real ctor needed for the prologue order: //@sym __11Unk800C83CCPviPvi = 0x800C83CC; caller func_800C7F60 would need changing.
#include "movie/movie.h"
struct Unk800C83CCP { u8 a0, a1, a2, len; u8 r0, g0, b0, code; char rest[0x28 - 8]; };
struct Unk800C83CC { void* x0; char pad[0xC]; Unk800C83CCP x10[2]; u8 x60, x61; Unk800C83CC(void* a, s32 q, void* r, s32 n); };
struct Unk800C83CCW { u32 w[4]; };
struct Unk800C83CCW1 { u32 w; };
EXTERN_C char D_800B4C88[];
EXTERN_C void func_8005F0E4(void*, s32);
EXTERN_C void func_8005F148(void*, void*);
EXTERN_C void func_800C8B24(Unk800C8B24* p, Unk800C8B24B* q);
EXTERN_C void func_800C8894(Unk800C8894* p, Unk800C8894B* q);
EXTERN_C void func_800C899C(void*, void*);
//@func
//@func
Unk800C83CC::Unk800C83CC(void* a, s32 q, void* r, s32 n) {
  Unk800C83CC* p = this;
  func_8005F0E4(p, n);
  p->x0 = D_800B8614;
  p->x60 = 0; p->x61 = 0;
  p->x10[0].len = 9; p->x10[0].code = 0x2C;
  p->x10[1].len = 9; p->x10[1].code = 0x2C;
  func_8005F148(p, a);
  func_800C8B24((Unk800C8B24*)p, (Unk800C8B24B*)D_800B4C88);
  func_800C8894((Unk800C8894*)p, (Unk800C8894B*)q);
  func_800C899C(p, r);
  {
    s32 i = D_800B4CF0[0];
    u32* d = (u32*)&p->x10[i ^ 1];
    u32* s = (u32*)&p->x10[i];
    u32* dp = d; u32* sp = s;
    u32 k = 0;
  loop: if (k < 8) { u32 w0 = sp[1], w1 = sp[2], w2 = sp[3], w3 = sp[4]; dp[1] = w0; dp[2] = w1; dp[3] = w2; dp[4] = w3; sp += 4; dp += 4; k += 4; goto loop; }
    d[9] = s[9];
  }
}
