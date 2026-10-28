// func_800BFA58: 404 differing by raw count, but 28 bytes short, so most of that is offset shift. Aligned diff shows ~18 real hunks. Fixed vs the old draft: frame 0x38 (the 0x2000 path reuses r.a); vb(p) is precomputed as a h statement with s32 i = n +- k before the func_80019F64 call (puts a1 in the beqz delay slot); the shared tail is 'else goto other; func_80054CE4(p->x7C); return 1; other: <0x2000 block>' (tail now sits before the 0x2000 block); the 0x40 blocks take a per-block 'Unk800C10BCP* rb = &r.b' (s-reg pointer, matches retail). Still differs: p in s3 (retail s4) with s3/s4 swapped in the prologue; x74==1 block wants &r.b in s2 from its 2nd set on (first set direct); the pop ?: result goes via a0/v0 then into s0 in retail; the 0x40-then block copies cur into s2 (addu s2,s3); our x74==1 and x74==3 tails are identical and get cross-jumped (retail keeps both because the registers differ). Diff with scratch_c/k1/sd.py <file> func_800BFA58 -r.
#include "movie/movie.h"
struct Unk800BFA58I { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(Unk800C10BCP); };
struct Unk800BFA58Q { Unk800BFA58I** x0; s32 x4; };
struct Unk800BFA58T { Unk800BFA58Q* x0; s32 x4; void* x8; };
struct Unk800BFA58E { char pad[0x18]; u16 x18; };
struct Unk800BFA58 { char pad[0x1C]; Unk800BFA58T x1C; char p1[0x74 - 0x28]; s32 x74; s32 x78; char x7C[0x2564 - 0x7C]; void* x2564; char x2568[0x2588 - 0x2568]; s32 x2588; };
struct Unk800BFA58R { Unk800C10BCP a, b; };
EXTERN_C void func_80054CA0(void*);
EXTERN_C void func_80054F5C(void*);
EXTERN_C s32 func_8005409C(void*);
struct Unk800BFA58VE { s16 delta, index; void (*pfn)(); };
#define Unk800BFA58_v4(o, q) { Unk800BFA58VE* e_ = &(*(Unk800BFA58VE**)((char*)(o) + 0x18))[4]; ((void (*)(void*, Unk800C10BCP))e_->pfn)((char*)(o) + e_->delta, q); }
//@func
EXTERN_C s32 func_800BFA58(Unk800BFA58* p, Unk800BFA58E* ev) {
  Unk800BFA58R r;
  if (func_80054D78(func_800550BC(p)) == 0) return 1;
  D_800B4D90[0] = 1;
  func_8001FC78(ev, 0, 0);
  u16 k = ev->x18;
  if (p->x74 == 0) { func_8005549C(7, p, 0, -1); return 1; }
  if (k & 0x10) {
    Unk800BFA58T* t = &p->x1C;
    s32 n = t->x4;
    if (n <= 0) return 1;
    func_8008EF40(8);
    Unk800BFA58I* cur = (Unk800BFA58I*)func_800550BC(p);
    if (p->x74 == 1) {
      Unk800C10BC_set(&r.a, 5, 11); Unk800C10BC_set(&r.b, 0, 0); func_80054F30(cur, 6, (RECT*)&r.a, -12); cur->v2();
      Unk800BFA58I* nx = t->x4 > 0 ? p->x1C.x0->x0[--t->x4] : 0;
      Unk800C10BC_set(&r.a, 0x19, 0x38); Unk800BFA58_v4(nx, r.a);
      Unk800C10BC_set(&r.a, 0, 0); Unk800C10BC_set(&r.b, 0, 0); func_80054F30(nx, 6, (RECT*)&r.a, 12); nx->v2();
      func_80054CA0(nx);
      func_800C1AE0((Unk800C11A0*)p, func_800C4854((Unk800C4854*)nx) ? nx : 0);
      Unk800BFA58I* m; { void** h = &p->x1C ? &p->x1C.x8 : 0; s32 i = n + 1; m = (Unk800BFA58I*)func_80019F64(h ? *h : 0, i); }
      Unk800C10BC_set(&r.a, 0, 11); Unk800C10BC_set(&r.b, 0, 0); func_80054F30(m, 6, (RECT*)&r.a, 0); m->v2();
      { void** h = &p->x1C ? &p->x1C.x8 : 0; s32 i = n + 2; m = (Unk800BFA58I*)func_80019F64(h ? *h : 0, i); }
      Unk800C10BC_set(&r.a, 0, 0); Unk800C10BC_set(&r.b, 0, 0); func_80054F30(m, 6, (RECT*)&r.a, -12); func_80054F5C(m);
    } else {
      p->x74--;
      Unk800C10BC_set(&r.a, 5, 0); Unk800C10BC_set(&r.b, 0, 0); func_80054F30(cur, 6, (RECT*)&r.a, -12); cur->v2();
      Unk800BFA58I* nx = t->x4 > 0 ? p->x1C.x0->x0[--t->x4] : 0;
      func_80054CA0(nx);
      Unk800C10BC_set(&r.a, -5, 0); Unk800C10BC_set(&r.b, 0, 0); func_80054F30(nx, 6, (RECT*)&r.a, 12); nx->v2();
      func_800C1AE0((Unk800C11A0*)p, func_800C4854((Unk800C4854*)nx) ? nx : 0);
    }
  } else if (k & 0x40) {
    Unk800BFA58T* t = &p->x1C;
    s32 n = t->x4;
    if (!(n < (t ? t->x0 : 0)->x4 - 1)) return 1;
    func_8008EF40(8);
    Unk800BFA58I* cur; if (t->x4 < p->x1C.x0->x4) { cur = p->x1C.x0->x0[p->x1C.x4]; p->x1C.x4++; } else cur = 0;
    if (p->x74 == 3) {
      Unk800C10BCP* rb = &r.b;
      Unk800C10BC_set(&r.a, 5, -11); Unk800C10BC_set(rb, 0, 0); func_80054F30(cur, 6, (RECT*)&r.a, -12); cur->v2();
      Unk800BFA58I* pv = (Unk800BFA58I*)func_800550BC(p);
      Unk800C10BC_set(&r.a, 0x19, 0xA6); Unk800BFA58_v4(pv, r.a);
      Unk800C10BC_set(&r.a, 0, 0); Unk800C10BC_set(rb, 0, 0); func_80054F30(pv, 6, (RECT*)&r.a, 12); pv->v2();
      func_80054CA0(pv);
      func_800C1AE0((Unk800C11A0*)p, func_800C4854((Unk800C4854*)pv) ? pv : 0);
      Unk800BFA58I* m; { void** h = &p->x1C ? &p->x1C.x8 : 0; s32 i = n - 1; m = (Unk800BFA58I*)func_80019F64(h ? *h : 0, i); }
      Unk800C10BC_set(&r.a, 0, -11); Unk800C10BC_set(rb, 0, 0); func_80054F30(m, 6, (RECT*)&r.a, 0); m->v2();
      { void** h = &p->x1C ? &p->x1C.x8 : 0; s32 i = n - 2; m = (Unk800BFA58I*)func_80019F64(h ? *h : 0, i); }
      Unk800C10BC_set(&r.a, 0, 0); Unk800C10BC_set(rb, 0, 0); func_80054F30(m, 6, (RECT*)&r.a, -12); func_80054F5C(m);
    } else {
      p->x74++;
      Unk800C10BCP* rb = &r.b;
      Unk800C10BC_set(&r.a, 5, 0); Unk800C10BC_set(rb, 0, 0); func_80054F30(cur, 6, (RECT*)&r.a, -12); cur->v2();
      Unk800BFA58I* nx = (Unk800BFA58I*)func_800550BC(p);
      func_80054CA0(nx);
      Unk800C10BC_set(&r.a, -5, 0); Unk800C10BC_set(rb, 0, 0); func_80054F30(nx, 6, (RECT*)&r.a, 12); nx->v2();
      func_800C1AE0((Unk800C11A0*)p, func_800C4854((Unk800C4854*)nx) ? nx : 0);
    }
  } else goto other;
  func_80054CE4(p->x7C);
  return 1;
other:
    if (k & 0x2000) {
      if (func_8005409C(func_800550BC(p))) {
        p->x2564 = func_800550BC(p); p->x2588 = 0;
        func_8005457C(p->x2568, 0);
        Unk800C10BC_set(&r.a, 0xD9, p->x74 * 0x37 + 0x20);
        func_80053F48(p->x2568, r.a);
        func_800631D4(p->x2568);
      } else func_8008EF40(0xE);
    }
    return 1;
}
