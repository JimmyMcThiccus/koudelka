// func_800C9ED8 draft: 390 positional / ~53 aligned instructions differ (sdiff.py). Same size -8 bytes. Differs: (1) loop-invariant motion also hoists D_80010300 (retail hoists only &D_800A4534, 2, D_80010178), so retail fp=b / s7=&D_800A4534 / s6=D_80010178 become fp=&D_800A4534 / s7 / s6 and b is spilled to 0x64(sp); (2) at the xA==5 test retail reuses v1 and copies it to s3 (addu s3,v1,zero) for the xA==2 test and the constant-2 args, we reload lhu s3; (3) tbl advance is (tbl+x118*64)-0x30 into v0 then s4 in retail, ours updates s4 in place. Everything else (vbase vcall, jump table, inline stream ctor, event ctors, switch on x10) lines up.
#include "movie/movie.h"
struct Unk800C9ED8X { virtual void v1(s32); };
struct Unk800C9ED8E : Unk800C3F68EV { u16 x4, x6, x8, xA; Unk800C9ED8X* xC; u32 x10; };
struct Unk800C9ED8VE { s16 delta; s16 index; void (*pfn)(void*, Unk800C9ED8X*); };
struct Unk800C9ED8VB { Unk800C9ED8VE* vptr; };
struct Unk800C9ED8R { s32 x0; u32 x4; char pad[0x40 - 8]; };
struct Unk800C9ED8T { char pad[0x10]; Unk800C9ED8R x10[1]; };
struct Unk800C9ED8 { char p0[0x100]; Unk800C9ED8VB* x100; const void* x104; s16 x108; char p1[0x10C - 0x10A]; Unk800C9ED8X* x10C; Unk800B9640* x110; s32 x114; s16 x118; char p2[0x17C - 0x11A]; s16 x17C; };
EXTERN_C void* D_800B4ED8[];
EXTERN_C s16 D_800CBAEC[];
EXTERN_C Unk800C9ED8E* func_8001EB60(void*, s32);
EXTERN_C void func_8006BDE0(void*);
EXTERN_C void func_8006BD34(void*);
EXTERN_C void func_800230E8(void*, void*);
EXTERN_C void func_8001BBBC(void*);
EXTERN_C void func_8001B910(void*);
EXTERN_C void func_80035DE0(void*);
EXTERN_C void func_800CA894(Unk800CA894* p);
inline Unk800B9640* Unk800C9ED8_stream() {
  Unk800B9640* d = (Unk800B9640*)operator new(0x54);
  StreamStat* v = &d->x4C; d->x4 = v; v->x0 = 0x10; v->x2 = 1; v->x4 = -1;
  d->x0 = D_80012154; d->x8 = D_8001201C; d->x0 = D_80012034; d->xC = d->x10;
  func_800198E0(d->x10, 4, 0);
  d->x8 = D_80012294; d->x0 = D_80012224; d->x8 = D_800B6F34; d->x28 = 0; d->x2C = 0; d->x0 = D_800B6F4C; d->x3C = 0; d->x40 = 0; d->x44 = 0;
  return d;
}
inline Unk800CA59CT* EV2(s16 k, void* a, s32 b) { Unk800CA59CT* t = func_8001CA10(0x14); *(void* volatile*)&t->x0 = D_80010178; *(void* volatile*)&t->x0 = D_80010300; t->x4 = 0; t->x8 = 2; t->xA = k; t->x10 = b; t->xC = (s32)a; t->x0 = D_800102D0; return t; }
inline void Unk800C9ED8_set118(Unk800C9ED8* p, s32 v) { p->x118 = v; }
//@func
EXTERN_C void func_800C9ED8(Unk800C9ED8* p) {
  Unk800C9ED8T* tbl = 0;
  Unk800C9ED8R rec;
  p->x110 = 0;
  Unk800BE8B0C* a = ctorC((Unk800BE8B0C*)operator new(0x18), (s32)p, 5, 0, 0);
  Unk800BE8B0C* b = ctorC((Unk800BE8B0C*)operator new(0x18), (s32)p, 6, 10, 0);
  if (p->x118) func_8001EFE4(p, Unk800BF918_ev(7, 0, p->x118));
  while (p->x108) {
    Unk800C9ED8E* e = func_8001EB60(p, 1);
    if (e->xA == 4 && e->x10 == 0) {
      Unk800C9ED8X* o = e->xC;
      Unk800C9ED8VE* ent = &(p ? p->x100 : 0)->vptr[3];
      Unk800C9ED8VB* vb = p ? p->x100 : 0;
      ent->pfn((char*)vb + ent->delta, o);
      if (o) o->v1(3);
    }
    if (e && e->xA == 6) {
      switch (e->x10) {
      case 0:
        func_8006BDE0(D_800B4ED8[0]);
        func_800230E8(D_800A4534.x44 + 0x154, p);
        break;
      case 1: case 2:
        func_8001BBBC(D_800A4534.x44);
        func_800BD928();
        if (p->x10C) p->x10C->v1(3);
        operator delete(b);
        p->x110 = 0;
        p->x10C = 0;
        func_8006BD34(D_800B4ED8[0]);
        if (p->x17C) {
          func_800232A0(D_800A4534.x44 + 0x154, p);
          func_8001EFE4((void*)p->x114, EV2(0x13, 0, 0));
        } else func_800CA928(p);
        break;
      case 10: case 11:
        func_8001EFE4(p, EV2(2, 0, 10));
        func_80035EB4(b);
        break;
      }
    } else if (e->xA == 7) {
      Unk800C9ED8_set118(p, e->x10);
      if (p->x118 == 0x17) {
        func_8001EFE4((void*)p->x114, EV2(0x13, 0, 0));
        continue;
      }
      while ((tbl = (Unk800C9ED8T*)func_800382A4(D_800AC86C, D_800CBAEC[p->x118 - 1], (s32)a)) == 0);
    } else {
      u32 k = e->xA;
      if (k == 5) {
        if (e->x10 == 0) {
          func_8001EFE4(p, EV2(2, 0, 10));
          tbl = (Unk800C9ED8T*)((Unk800C9ED8R*)tbl + p->x118); tbl = (Unk800C9ED8T*)((char*)tbl - 0x30);
          rec = *(Unk800C9ED8R*)tbl;
        }
      } else if (k == 2) {
        if (p->x17C == 0) func_800CA894((Unk800CA894*)p);
        switch (e->x10) {
        case 10:
          if (p->x110 == 0) { func_800BD8E8(); p->x110 = Unk800C9ED8_stream(); }
          if (func_800B92B8((Unk800B93D8T*)p->x110, rec.x0, rec.x4 / 23400 - 10) == 0) func_80035DE0(b);
          else {
            p->x10C = (Unk800C9ED8X*)func_800BDBAC((Unk800BDBAC*)operator new(0x5C), p->x110, 4, p, 2, 0, 2, 6);
            func_8001B910(D_800A4534.x44);
            func_800BDDC8(p->x10C, 0x30, 0xC0);
          }
          break;
        case 0:
          operator delete(a);
          break;
        }
      }
    }
    if (e) e->v2();
  }
  while (func_8001ED2C(p, 0x78, 1));
}
