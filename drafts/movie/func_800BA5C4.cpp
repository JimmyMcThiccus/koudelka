// DRAFT (k2): 33 differing instructions, same size as retail (6576). Registers and stack slots match retail.
// Remaining (all scheduling): (1) loop pre-header: the hoisted &r/&c/D_800A4534 setup order (retail &r.h,&r,...,&c last; mine &c
// second, &r last); (2) case 0 of the xA==6 switch: retail sets started=1 after loading a0; (3) two sprites (case -1, case 10,
// X=Y=0) pass &r as addiu a1,sp,0x48 instead of lw 0x78; (4) case 98: retail stores xA after x8 in event 2 and after the
// constants in event 1. Init order ctor1,x4,300,x8,xA fixes (4) but puts the D_80010178 pseudo below nobj in priority
// (s6/s7 swap); (5) case 101: lui v1/v0 swap for the D_800AF470 load.
#include "movie/movie.h"
struct Unk800BA5C4V { virtual void v1(s32); };
struct Unk800BA5C4W { char pad[0x18]; virtual void v1(s32); virtual void v2(); };
struct Unk800BA5C4B { virtual void v1(); virtual void v2(); virtual void v3(void*); };
struct Unk800BA5C4MV { virtual void v1(); virtual void v2(); };
struct Unk800BA5C4M : Unk800BA5C4MV { u16 x4, x6, x8, xA; Unk800BA5C4V* xC; s32 x10; };
struct Unk800BA5C4FX { char pad[0xE]; s8 xE; };
struct Unk800BA5C4FV { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800BA5C4F : Unk800BA5C4FV { char p[0x2C - 4]; Unk800BA5C4FX* x2C; };
struct Unk800BA5C4H { char pad[0x14]; u16 x14; };
struct Unk800BA5C4L { char d[0x28]; };
struct Unk800BA5C4P { s16 x, y; void set(s16 a, s16 b) { x = a; y = b; } };
struct Unk800BA5C4R { Unk800BA5C4P a, b; void set(s16 x, s16 y, s16 w, s16 h) { a.set(x, y); b.set(w, h); } };
struct Unk800BA5C4 {
  char p0[0x100]; Unk800BA5C4B* x100; char p1[0x108 - 0x104];
  s16 x108, x10A, x10C, x10E;
  Unk800BA5C4V* x110; Unk800BA5C4V* x114; Unk800BA5C4V* x118; Unk800BA5C4V* x11C;
  Unk800BA5C4V* x120; Unk800BA5C4V* x124; Unk800BA5C4V* x128; Unk800BA5C4V* x12C;
  s16 x130, x132, x134; char p2[2]; Unk800BA5C4H* x138; u16 x13C; char p3[2]; void* x140;
  Unk800BA5C4V* x144; Unk800B9640* x148;
};
EXTERN_C Unk800BA5C4F* func_80048D64(void*, s32, s32, void*, s32, s32);
EXTERN_C Unk800BA5C4H* func_80049250(void*, void*, void*);
EXTERN_C void func_8008CE18(s32, s32, s32, s32);
EXTERN_C void func_800230E8(void*, void*);
EXTERN_C Unk800BA5C4M* func_8001EB60(void*, s32);
EXTERN_C void* func_800BEDD0(void*);
EXTERN_C void func_800BEED4(Unk800BEED4*);
EXTERN_C void func_800BE9D4(Unk800BE9D4*);
EXTERN_C void func_800BEC54(Unk800BEC54*);
EXTERN_C void func_800BE888(void*, int);
EXTERN_C Unk800BE1CC* func_800BE1CC(Unk800BE1CC*, s32, s32, s32, s32);
EXTERN_C void* func_800BE880(void*);
EXTERN_C void func_800BEB0C(Unk800BEB0C*, s32, s32, s32);
EXTERN_C void func_800BE3B4(Unk800BE3B4*, s16, s16);
EXTERN_C s16 func_800BE54C(Unk800BE54C*, s16);
EXTERN_C void func_800BE4B4(Unk800BE4B4*, s16, s16);
EXTERN_C s16 func_800BE568(Unk800BE568*, s16);
EXTERN_C void func_800BE368(Unk800BE368*);
EXTERN_C void func_800BE584(Unk800BE584*, s16);
EXTERN_C void func_800BE5F8(Unk800BE5F8*, s16, s16, s16);
EXTERN_C void func_800BD8E8();
EXTERN_C void func_800BD928();
EXTERN_C s32 func_800B92B8(Unk800B93D8T*, s32, s32);
EXTERN_C void func_80035DE0(void*);
EXTERN_C Unk800BDBAC* func_800BDBAC(Unk800BDBAC*, void*, s32, void*, s32, s32, s32, s32);
EXTERN_C void func_8001B910(void*);
EXTERN_C void func_8001BBBC(void*);
EXTERN_C Unk800BA5C4W* func_800C6624(void*, s32, void*);
EXTERN_C Unk800BA5C4W* func_800BEF3C(void*, s32, void*);
EXTERN_C Unk800C5B70* func_800C5B70(Unk800C5B70*, s32, s32);
EXTERN_C void func_800C5B80(Unk800C5B80*);
EXTERN_C void func_8008ED44(void*);
EXTERN_C void func_8008D4C0(void*);
EXTERN_C char* D_800B4ED8[];
EXTERN_C void* D_800AF470[];
inline Unk800B9640* Unk800BA5C4_stream(Unk800B9640* p) {
  StreamStat* v = &p->x4C; p->x4 = v; v->x0 = 0x10; v->x2 = 1; v->x4 = -1;
  p->x0 = D_80012154; p->x8 = D_8001201C; p->x0 = D_80012034; p->xC = p->x10;
  func_800198E0(p->x10, 4, 0);
  p->x8 = D_80012294; p->x0 = D_80012224; p->x8 = D_800B6F34; p->x28 = 0; p->x2C = 0; p->x0 = D_800B6F4C; p->x3C = 0; p->x40 = 0; p->x44 = 0;
  return p;
}
#define BA5C4_LOADER(id, sz) { s3 = (Unk800BEB0C*)func_800BE880(operator new(0x8C)); func_800BEB0C(s3, id, sz, (s32)p); if (!s3->x88) func_800BEC54((Unk800BEC54*)s3); }
#define BA5C4_SPRITE(dst, X, Y, W, H) { Unk800BE1CC* o = (Unk800BE1CC*)operator new(0x74); r.set(X, Y, W, H); func_8002972C(&c, 0, 0, 0, 1); dst = (Unk800BA5C4V*)func_800BE1CC(o, (s32)&r.a, (s32)nobj, 1, (s32)&c); func_800198AC(&c, 2); }
#define BA5C4_54C(o, a) ((s32 (*)(Unk800BE54C*, s16))func_800BE54C)(o, a)
#define BA5C4_568(o, a) ((s32 (*)(Unk800BE568*, s16))func_800BE568)(o, a)
// event init split from its allocation (alloc, then the call's first argument, then the stores, as retail orders them).
// init2 (case 98) stores x8 through a named local `two` so the loop pass does not merge it with the hoisted invariant 2.
inline void Unk800BA5C4_init(Unk800CA59CT* t, s16 k, void* a, s32 b) { Unk800CA59C_ctor1(t); *(void* volatile*)&t->x0 = D_80010300; t->x4 = 0; t->x8 = 2; t->xA = k; t->x10 = b; t->xC = (s32)a; t->x0 = D_800102D0; }
inline void Unk800BA5C4_init2(Unk800CA59CT* t, s16 k, void* a, s32 b) { s16 two = 2; t->xA = k; Unk800CA59C_ctor1(t); t->x4 = 0; *(void* volatile*)&t->x0 = D_80010300; t->x8 = two; t->x10 = b; t->xC = (s32)a; t->x0 = D_800102D0; }
inline s32 Unk800BA5C4_msg(Unk800BA5C4M* m) { return m->x10; }
//@func
EXTERN_C void func_800BA5C4(Unk800BA5C4* p) {
  void* nobj = 0;
  Unk800BEB0C* s3 = 0;
  s16 started = 0; // s16 (not u16): its test becomes a paradoxical-subreg copy, and the slot gets 8-byte alignment (0x58..0x5F)
  Unk800BA5C4W* o60 = 0;
  Unk800C5B70* o64;
  Unk800BA5C4W* o68 = 0;
  Unk800BA5C4L l;
  Unk800BA5C4R r;
  Unk800BE5F8T c;
  p->x10A = 6; p->x10C = 2; p->x130 = 0; p->x134 = 0; p->x148 = 0;
  p->x110 = 0; p->x114 = 0; p->x144 = 0; p->x120 = 0; p->x124 = 0; p->x128 = 0; p->x12C = 0;
  Unk800BE8B0C* o6c = ctorC((Unk800BE8B0C*)operator new(0x18), (s32)p, 6, 10, 0);
  func_80048D54(&l);
  Unk800BA5C4F* f = func_80048D64(&l, 0x708, 0x1000, p, 0, 0);
  Unk800BA5C4FX* x = f->x2C;
  p->x10E = 1;
  if (x->xE != '1') p->x10E = 0;
  f->v3();
  func_80036D8C(f);
  f = func_80048D64(&l, 0xC37C, 0x12800, p, 0, 0);
  p->x138 = func_80049250(&l, f->x2C, &p->x140);
  f->v3();
  func_8008CE18(4, 0x28, 0, 0);
  if (p->x138) p->x13C = p->x138->x14;
  func_80036D8C(f);
  p->x118 = 0; p->x11C = 0;
  func_800230E8(D_800A4534.x44 + 0x154, p);
  while (p->x108) {
    s16 done = 0; // signed narrow: retail tests a copy of it (addu v0, s0)
    Unk800BA5C4M* m;
    if (p->x10C == 0) m = func_8001EB60(p, 1);
    else m = (Unk800BA5C4M*)func_8001ED2C(p, p->x10C, 1);
    if (m && m->xA == 5) {
      switch (Unk800BA5C4_msg(m)) {
      case 0:
        func_800BEED4((Unk800BEED4*)s3);
        goto reload;
      case 2:
        if (s3->x88) func_800BEC54((Unk800BEC54*)s3);
        break;
      case 1:
        if (s3) {
          nobj = func_800BEDD0(s3);
          if (nobj) func_800BE888(s3, 3);
          else {
          reload:
            func_800BE9D4((Unk800BE9D4*)s3); if (!s3->x88) func_800BEC54((Unk800BEC54*)s3);
          }
        }
        break;
      }
    }
    if (m && m->xA == 6) {
      switch (m->x10) {
      case 0: started = 1; func_800230E8(D_800A4534.x44 + 0x154, p); break;
      case 1: case 2: if (!started) func_800230E8(D_800A4534.x44 + 0x154, p); p->x10A++; break;
      case 10: case 11: func_80035EB4(o6c); break;
      }
    }
    if (m && m->xA == 4 && m->x10 == 0) {
      Unk800BA5C4V* o = m->xC;
      (p ? p->x100 : 0)->v3(o);
      if (o) o->v1(3);
      done = 1;
    }
    if (m && m->xA == 7) {
      switch (Unk800BA5C4_msg(m)) {
      case 0: p->x10A = 0x15; break;
      case 1: p->x10A = 0x18; p->x134 = 0; p->x130 = 0x62; break;
      case 2: operator delete(o64); p->x10A = 0x65; break;
      case 3: if (o68) o68->v1(3); o68 = 0; p->x10A = 0x15; break;
      }
      if (o60) { o60->v1(3); o60 = 0; }
    }
    if (!done || p->x10A == 4 || p->x10A == 9999) {
      switch (p->x10A) {
      case -1:
        p->x10C = 2;
        if (nobj) {
          p->x10A++;
          BA5C4_SPRITE(p->x118, 0, 0, 0xA0, 0xF0);
          nobj = 0;
          BA5C4_LOADER(0xC368, 0xA000);
        }
        break;
      case 0:
        p->x10C = 2;
        if (nobj) {
          p->x10A++;
          BA5C4_SPRITE(p->x11C, 0xA0, 0, 0xA0, 0xF0);
          nobj = 0;
        }
        break;
      case 1:
        func_800BE3B4((Unk800BE3B4*)p->x118, p->x132 = 2, 0x80);
        func_800BE3B4((Unk800BE3B4*)p->x11C, p->x132, 0x80);
        p->x10C = 2;
        p->x10A++;
        break;
      case 2: {
        s32 a = BA5C4_54C((Unk800BE54C*)p->x118, p->x132);
        s32 b = BA5C4_54C((Unk800BE54C*)p->x11C, p->x132);
        if (a && b) p->x10A++;
        break;
      }
      case 3:
        p->x10C = 0xB4;
        p->x10A++;
        break;
      case 4:
        func_800BE4B4((Unk800BE4B4*)p->x118, p->x132, 0);
        func_800BE4B4((Unk800BE4B4*)p->x11C, p->x132, 0);
        p->x10C = 2;
        p->x10A++;
        break;
      case 5: {
        s32 a = BA5C4_568((Unk800BE568*)p->x118, 0);
        s32 b = BA5C4_568((Unk800BE568*)p->x11C, 0);
        if (a && b) {
          func_800BE368((Unk800BE368*)p->x118);
          func_800BE368((Unk800BE368*)p->x11C);
          if (p->x130) { p->x10A = p->x130; p->x130 = 0; }
          else p->x10A++;
        }
        break;
      }
      case 6:
        func_800232A0(D_800A4534.x44 + 0x154, p);
        started = 0;
        if (p->x118 || p->x11C) {
          if (p->x118) p->x118->v1(3);
          if (p->x11C) p->x11C->v1(3);
          p->x118 = 0; p->x11C = 0;
        }
        p->x10C = 0;
        if (!p->x148) {
          func_800BD8E8();
          p->x148 = Unk800BA5C4_stream((Unk800B9640*)operator new(0x54));
        }
        if (!func_800B92B8((Unk800B93D8T*)p->x148, 0x1A16F, 0x585)) { func_80035DE0(o6c); break; }
        p->x144 = (Unk800BA5C4V*)func_800BDBAC((Unk800BDBAC*)operator new(0x5C), p->x148, 4, p, 2, 0, 2, 6);
        func_8001B910(D_800A4534.x44);
        func_800BDDC8(p->x144, 0x30, 0xC0);
        p->x10A++;
        break;
      case 7:
        if (p->x130) { p->x10A = p->x130; p->x130 = 0; }
        break;
      case 8:
        func_8001BBBC(D_800A4534.x44);
        func_800BD928();
        p->x10C = 5;
        if (p->x144) p->x144->v1(3);
        p->x144 = 0; p->x148 = 0;
        p->x10A++;
        break;
      case 9:
        if (p->x118 || p->x11C) {
          if (p->x118) p->x118->v1(3);
          if (p->x11C) p->x11C->v1(3);
          p->x118 = 0; p->x11C = 0;
        }
        BA5C4_LOADER(0xC3A1, 0xA000);
        p->x10A++;
        break;
      case 10:
        if (nobj) {
          BA5C4_SPRITE(p->x110, 0, 0, 0xA0, 0xF0);
          nobj = 0;
          p->x10A++;
        }
        break;
      case 11:
        BA5C4_LOADER(0xC3B5, 0xA000);
        p->x10A++;
        break;
      case 12:
        if (nobj) {
          BA5C4_SPRITE(p->x114, 0xA0, 0, 0xA0, 0xF0);
          nobj = 0;
          if (p->x130) { p->x10A = p->x130; p->x130 = 0; }
          else p->x10A++;
        }
        break;
      case 13:
        BA5C4_LOADER(0xC3C9, 0x1800);
        p->x10A++;
        break;
      case 14:
        if (nobj) {
          BA5C4_SPRITE(p->x120, 0x66, 0xB2, 0x80, 0x20);
          func_800BE584((Unk800BE584*)p->x120, 0);
          nobj = 0;
          p->x10A++;
        }
        break;
      case 15:
        BA5C4_LOADER(0xC3CC, 0x1000);
        p->x10A++;
        break;
      case 16:
        if (nobj) {
          BA5C4_SPRITE(p->x124, 0x30, 0x9C, 0x60, 0x10);
          func_800BE584((Unk800BE584*)p->x124, 0);
          nobj = 0;
          p->x10A++;
        }
        break;
      case 17:
        BA5C4_LOADER(0xC3CE, 0x1000);
        p->x10A++;
        break;
      case 18:
        if (nobj) {
          BA5C4_SPRITE(p->x128, 0xBA, 0x9C, 0x60, 0x10);
          func_800BE584((Unk800BE584*)p->x128, 0);
          nobj = 0;
          p->x10A++;
        }
        break;
      case 19:
        BA5C4_LOADER(0xC3D0, 0x1000);
        p->x10A++;
        break;
      case 20:
        if (nobj) {
          BA5C4_SPRITE(p->x12C, 0x80, 0xB8, 0x60, 0x10);
          func_800BE584((Unk800BE584*)p->x12C, 0);
          nobj = 0;
          p->x10A++;
        }
        break;
      case 21:
        func_800BE3B4((Unk800BE3B4*)p->x110, p->x132 = 2, 0x80);
        func_800BE3B4((Unk800BE3B4*)p->x114, p->x132, 0x80);
        p->x10C = 2;
        func_800BE584((Unk800BE584*)p->x124, 0);
        func_800BE584((Unk800BE584*)p->x128, 0);
        func_800BE584((Unk800BE584*)p->x12C, 0);
        p->x10A++;
        break;
      case 22: {
        s32 a = BA5C4_54C((Unk800BE54C*)p->x110, p->x132);
        s32 b = BA5C4_54C((Unk800BE54C*)p->x114, p->x132);
        if (a && b) {
          func_800BE584((Unk800BE584*)p->x120, 1);
          func_800BE5F8((Unk800BE5F8*)p->x120, 0x7F, 0x7F, 0x7F);
          p->x10A++;
        }
        break;
      }
      case 23:
        p->x10C = 0x258;
        p->x134 = 0;
        p->x10A++;
        break;
      case 24:
        func_800BE4B4((Unk800BE4B4*)p->x110, p->x132 = 2, p->x134);
        func_800BE4B4((Unk800BE4B4*)p->x114, p->x132, p->x134);
        func_800BE4B4((Unk800BE4B4*)p->x120, p->x132, p->x134);
        func_800BE4B4((Unk800BE4B4*)p->x124, p->x132, p->x134);
        func_800BE4B4((Unk800BE4B4*)p->x128, p->x132, p->x134);
        func_800BE4B4((Unk800BE4B4*)p->x12C, p->x132, p->x134);
        p->x10C = 2;
        p->x10A++;
        break;
      case 25: {
        s32 a = BA5C4_568((Unk800BE568*)p->x110, 0);
        s32 b = BA5C4_568((Unk800BE568*)p->x114, 0);
        func_800BE568((Unk800BE568*)p->x120, 0);
        func_800BE568((Unk800BE568*)p->x124, 0);
        func_800BE568((Unk800BE568*)p->x128, 0);
        func_800BE568((Unk800BE568*)p->x12C, 0);
        if (a && b) {
          if (p->x130 == 0x60 || p->x130 == 0x5E) { p->x10A = p->x130; p->x130 = 0; }
          else p->x10A++;
        }
        break;
      }
      case 26:
        p->x10C = 0x3C;
        func_800BE368((Unk800BE368*)p->x110);
        func_800BE368((Unk800BE368*)p->x114);
        func_800BE368((Unk800BE368*)p->x120);
        func_800BE368((Unk800BE368*)p->x124);
        func_800BE368((Unk800BE368*)p->x128);
        func_800BE368((Unk800BE368*)p->x12C);
        p->x10A = 9999;
        break;
      case 27:
        func_800BE584((Unk800BE584*)p->x120, 0);
        func_800BE5F8((Unk800BE5F8*)p->x124, 0x80, 0x80, 0x80);
        func_800BE584((Unk800BE584*)p->x124, 1);
        func_800BE5F8((Unk800BE5F8*)p->x128, 0x3C, 0x3C, 0x3C);
        func_800BE584((Unk800BE584*)p->x128, 1);
        func_800BE5F8((Unk800BE5F8*)p->x12C, 0x3C, 0x3C, 0x3C);
        func_800BE584((Unk800BE584*)p->x12C, 1);
        break;
      case 28:
        func_800BE584((Unk800BE584*)p->x120, 0);
        func_800BE5F8((Unk800BE5F8*)p->x124, 0x3C, 0x3C, 0x3C);
        func_800BE584((Unk800BE584*)p->x124, 1);
        func_800BE5F8((Unk800BE5F8*)p->x128, 0x80, 0x80, 0x80);
        func_800BE584((Unk800BE584*)p->x128, 1);
        func_800BE5F8((Unk800BE5F8*)p->x12C, 0x3C, 0x3C, 0x3C);
        func_800BE584((Unk800BE584*)p->x12C, 1);
        break;
      case 29:
        func_800BE5F8((Unk800BE5F8*)p->x12C, 0x80, 0x80, 0x80);
        func_800BE584((Unk800BE584*)p->x12C, 1);
        func_800BE5F8((Unk800BE5F8*)p->x124, 0x3C, 0x3C, 0x3C);
        func_800BE584((Unk800BE584*)p->x124, 1);
        func_800BE5F8((Unk800BE5F8*)p->x128, 0x3C, 0x3C, 0x3C);
        func_800BE584((Unk800BE584*)p->x128, 1);
        break;
      case 94:
        o68 = func_800C6624(operator new(0x61C), 1, p);
        o68->v2();
        p->x10A = 100;
        break;
      case 96:
        o60 = func_800BEF3C(operator new(0x2824), 1, p);
        o60->v2();
        p->x10A++;
        break;
      case 98: {
        func_8001ED2C(p, 0x3C, 1);
        Unk800CA59CT* t = func_8001CA10(0x14);
        void* q = D_800AF470[0];
        Unk800BA5C4_init2(t, 0x11, 0, 1);
        func_8001EFE4(q, t);
        char* o = D_800B4ED8[0];
        p->x10A = 100;
        char* d = o ? o + 0x124 : 0;
        t = func_8001CA10(0x14);
        Unk800BA5C4_init2(t, 2, p, 7);
        func_8001EFE4(d, t);
        func_800232A0(D_800A4534.x44 + 0x154, p);
        break;
      }
      case 99: {
        o64 = func_800C5B70((Unk800C5B70*)operator new(8), (s32)p, 2);
        func_800C5B80((Unk800C5B80*)o64);
        char* o = D_800B4ED8[0];
        p->x10A = 100;
        char* d = o ? o + 0x124 : 0;
        Unk800CA59CT* t = func_8001CA10(0x14);
        Unk800BA5C4_init(t, 2, p, 7);
        func_8001EFE4(d, t);
        break;
      }
      case 101: {
        Unk800CA59CT* t = func_8001CA10(0x14);
        void* q = D_800AF470[0];
        Unk800BA5C4_init(t, 0x11, 0, 0);
        func_8001EFE4(q, t);
        p->x10A = 100;
        func_800232A0(D_800A4534.x44 + 0x154, p);
        break;
      }
      case 97: case 100:
        break;
      default:
        if (p->x110) p->x110->v1(3);
        if (p->x114) p->x114->v1(3);
        if (p->x120) p->x120->v1(3);
        if (p->x124) p->x124->v1(3);
        if (p->x128) p->x128->v1(3);
        if (p->x12C) p->x12C->v1(3);
        p->x110 = 0; p->x114 = 0; p->x120 = 0; p->x124 = 0; p->x128 = 0; p->x12C = 0;
        p->x10C = 2;
        if (p->x130) { p->x10A = p->x130; p->x130 = 0; }
        else p->x10A = 6;
        break;
      }
    }
    if (m) m->v2();
  }
  if (p->x118) p->x118->v1(3);
  if (p->x11C) p->x11C->v1(3);
  if (p->x110) p->x110->v1(3);
  if (p->x114) p->x114->v1(3);
  if (p->x120) p->x120->v1(3);
  if (p->x124) p->x124->v1(3);
  if (p->x128) p->x128->v1(3);
  if (p->x12C) p->x12C->v1(3);
  operator delete(o6c);
  if (p->x138) {
    func_8008ED44(p->x138);
    func_8008D4C0(p->x140);
    if (p->x138) func_800A0D0C(p->x138);
  }
  func_800232A0(D_800A4578[0]->x154, p);
  func_80048D2C(&l, 2);
}
