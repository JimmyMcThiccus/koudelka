#include "common.h"
#include "movie/movie.h"

EXTERN_C void func_800B8AB4(Unk800B8AB4* p) { if (p->x8 == 0) p->x8 = func_800B9B14(operator new(0x38), p, p->x30); func_8002A110(p); }

EXTERN_C s32 func_800B8B08(Unk800B8B08* p) { return p->x8; }

EXTERN_C Unk800B98D4* func_800B8B14(Unk800B98D4* self, s32 in_chrg, RECT* r, u16 a) {
  if (in_chrg) { Unk800B98D4V* v = &self->x38; self->x0 = v; self->x38.vptr = D_80010178; v->x4 = 0; self->x38.vptr = D_800104A8; }
  func_80029C54(self, 0, a);
  self->x0->vptr = &D_800B6FF4;
  Unk800B98D4T vt0 = D_800B6FF4;
  self->x0->vptr = &vt0;
  char* full0; s32 adj0;
  vt0.e[1].delta = ((Unk800B98D4T&)D_800B6FF4).e[1].delta + (adj0 = (char*)self - (full0 = (char*)self->x0 - 0x38));
  vt0.e[5].delta = ((Unk800B98D4T&)D_800B6FF4).e[5].delta + adj0;
  vt0.e[7].delta = ((Unk800B98D4T&)D_800B6FF4).e[7].delta + adj0;
  vt0.e[9].delta = ((Unk800B98D4T&)D_800B6FF4).e[9].delta + adj0;
  self->x2C = D_800B7044;
  self->x30 = *r;
  self->x0->vptr = &D_800B6DF4;
  if (!in_chrg) {
    Unk800B98D4T vt = D_800B6DF4;
    self->x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B6DF4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x38));
    vt.e[5].delta = D_800B6DF4.e[5].delta + adj;
    vt.e[7].delta = D_800B6DF4.e[7].delta + adj;
    vt.e[9].delta = D_800B6DF4.e[9].delta + adj;
  }
  self->x2C = D_800B6E44;
  return self;
}

EXTERN_C void func_800B8CF0(Unk800B98D4* self, int in_chrg) {
  self->x2C = D_800B6E44;
  self->x0->vptr = &D_800B6DF4;
  if (!in_chrg) {
    Unk800B98D4T vt = D_800B6DF4;
    self->x0->vptr = &vt;
    char* full; int adj;
    vt.e[1].delta = D_800B6DF4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x38));
    vt.e[5].delta = D_800B6DF4.e[5].delta + adj;
    vt.e[7].delta = D_800B6DF4.e[7].delta + adj;
    vt.e[9].delta = D_800B6DF4.e[9].delta + adj;
  }
  Unk800B8CF0_base_dtor(self, 0);
  if (in_chrg & 2) func_8001A610(self->x0, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C s32 func_800B8E9C(Unk800B8E9C* p) { s32 v = p->x40; if (v == 0) v = -1; return v; }

EXTERN_C s32 func_800B8EB8(Unk800B8EB8* p, void* v) { if (((p ? p->x4 : 0)->x0 >> 4) & 1) return 0; if (v == p->x40) return 1; if (StGetNext(&p->x44, &p->x40)) return 0; p->x4->x4 = 0; return 1; }

EXTERN_C s32 func_800B8F34(Unk800B8F34* p) { Unk800B8F34B* b = p->x4; s32 i = b->x4; s32 r; if (i >= 0) { r = p->x40[i]; b->x4 = i + 1; } else r = -1; return r; }

EXTERN_C s32 func_800B8F74(Unk800B8F74* p, void* dst, s32 n) { if (p->x4->x4 < 0) return 0; func_80025CE0(dst, p->x40 + p->x4->x4, n); p->x4->x4 += n; return n; }

EXTERN_C void func_800B8FE0(Unk800B8FE0B* p, u8* q) { if ((q[0] & 0x10) || ((q[0] & 1) && (q[1] & 0x40))) { p->v8(q[0]); func_80036674(p); } else p->x35 = 2; }

EXTERN_C s32 func_800B9060(Unk800B9060B* p) { switch (p->x35) { case 0: func_8003556C(p); return 0; case 9: { u8 loc[4]; Unk800B9060M m; if (p->x36 == 0) return 0; if (func_800366F8(p) == 0) return 0; CdIntToPos(p->x24, loc); CdControl(2, loc, 0); p->x30 = 0; p->x48 = 0; p->x34 = 0; p->x35 = 0; if (CdRead2(p->x37 | 0x120)) return 0; m.a = func_8009C9C0(); m.b = 0; p->v13(&m); return 0; } } return func_80036850(p); }

EXTERN_C void func_800B914C(Unk800B93D8T* p) {
  Unk800B93D8T** g = D_800B4D0C;
  Unk800B93D8T* s = *g;
  // comparing through a flag keeps cse from recording s == p (combine folds it back into the bne)
  s32 cur = s == p;
  if (!cur) return;
  if (p->x30 >= 0) { func_8008CD1C(0, 0); VSync(0); func_8009A470(); }
  p->x36 = 0;
  p->x35 = 0x15;
  *g = 0; // through the local pointer so the p->x3C load can move above it
  if (p->x3C) func_800A0D0C(p->x3C);
  s->x44 = 0; s->x40 = 0; s->x3C = 0;
  s->x4->x4 = -1;
  StreamStat* st = s ? s->x4 : 0;
  st->x0 |= 0x11;
}

EXTERN_C void func_800B9208(void* a, u8 b) { Unk800B9208S* s = (Unk800B9208S*)D_800B4D0C[0]; if (s != a) return; s->v3(); if (func_80035C30(b)) return; Unk800B9208G* g = D_800AC854; if ((g ? g->x0 : 0)->x4) func_80019C68(g ? g->x0 : 0, 0)->v1(0); }

EXTERN_C s32 func_800B92B8(Unk800B93D8T* p, s32 a, s32 b) { if (D_800B4D0C[0] || func_80035C30(func_8009C9C0())) return 0; p->x24 = a; p->x28 = b; p->x4->x0 = 0; p->x3A = 0x10; p->x30 = -1; p->x36 = 0; p->x35 = func_8009C9E0() != 9 ? 3 : 9; char* d = D_800A4544; if (func_8001D25C(d, p ? (char*)p + 8 : 0) == 0) { void* q = p ? (char*)p + 8 : 0; Unk800B92B8T* n = (Unk800B92B8T*)operator new(0x14); *(void* volatile*)&n->x0 = D_80010178; n->x0 = D_80010338; n->x4 = 0; n->x8 = q; n->xC = 0x80; n->x10 = 0; func_8001D150(d, n); } D_800B4D0C[0] = p; return 1; }

EXTERN_C s32 func_800B93D8(void* a, s32 n, s32 c, s32 d) { Unk800B93D8T* s = D_800B4D0C[0]; if (s == a) { s->x3C = func_800A0D2C(n << 11); StSetRing(s->x3C, n); StSetStream(d, 0, -1, 0, 0); StClearRing(); func_8008CD1C(0x4400, 0x18); s->x30 = 0; s->x37 = c; s->x36 = 1; return 1; } return 0; }

EXTERN_C void* func_800B9484(Unk800B93D8T* p) { void* r = p->x44; if (r || ((p ? p->x4 : 0)->x0 & 1)) { p->x44 = 0; } else if (StGetNext(&r, &p->x40)) { r = 0; if (func_8009C9C0() & 0x15) p->v3(); } else { StreamHdr* h = p->x40; if (h->x8 >= p->x28 || h->x8 <= p->x48) p->v3(); else if (h->x8 == p->x28 - 3) func_8008CD1C(0, 0x18); p->x48 = h->x8; p->x4->x4 = 0; } return r; }

EXTERN_C void func_800B95A8(void* p, void* q) { StFreeRing(q); }

EXTERN_C s32 func_800B95C8(Unk800B95C8* p) { return p->x28; }

EXTERN_C int func_800B95D4() { return 0x20; }

EXTERN_C void func_800B95DC(Unk800B95DC* p, char* q) { if (q) ((Unk800B95DCB*)(q - 8))->v2(p->x8, 0x20); }

EXTERN_C void func_800B9620(void* p, void* q) { func_8003546C(p, q); }

EXTERN_C Unk800B9640* func_800B9640(Unk800B9640* p, s32 f) {
  if (f) { StreamStat* v = &p->x4C; p->x4 = v; v->x0 = 0x10; v->x2 = 1; v->x4 = -1; }
  p->x0 = D_80012154; p->x8 = D_8001201C; p->x0 = D_80012034; p->xC = p->x10;
  ((void* (*)(void*, s32, s32))func_800198E0)(p->x10, 4, 0);
  p->x8 = D_80012294; p->x0 = D_80012224; p->x8 = D_800B6F34; p->x28 = 0; p->x2C = 0; p->x0 = D_800B6F4C; p->x3C = 0; p->x40 = 0; p->x44 = 0;
  return p;
}

EXTERN_C void func_800B9704(Unk800B9704* p, s32 f) { p->x8 = D_800B6F34; p->x0 = D_800B6F4C; p->x8 = D_80012294; p->x0 = D_80012224; func_80035304(p, 0); if (f & 1) operator delete(p); }

EXTERN_C Unk800B977C* func_800B977C(Unk800B977C* p) { p->x0 = D_800B6FBC; return p; }

EXTERN_C void func_800B9790(Unk800B9790* p) { if (p->x8 == 0) p->x8 = func_800BA498(operator new(0x38), p, p->x30); func_8002A110(p); }

EXTERN_C void func_800B97E4(Unk800B97E4* p, RECT* r) { p->x30 = *r; if (p->x8) p->x8->v21(); }

EXTERN_C void func_800B9848(Unk800B9848* p) { if (p->x8) p->x8->v8(); }

EXTERN_C s32 func_800B988C(Unk800B988C* p, s32 a) { return p->v14(a); }

EXTERN_C s32 func_800B98C8(Unk800B98C8* p) { return p->x8; }

EXTERN_C Unk800B98D4* func_800B98D4(Unk800B98D4* self, s32 in_chrg, RECT* r, u16 a) {
  if (in_chrg) {
    self->x0 = &self->x38;
    Unk800B98D4V* v = self->x0;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_80029C54(self, 0, a);
  self->x0->vptr = &D_800B6FF4;
  if (!in_chrg) {
    Unk800B98D4T vt = D_800B6FF4;
    self->x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B6FF4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x38));
    vt.e[5].delta = D_800B6FF4.e[5].delta + adj;
    vt.e[7].delta = D_800B6FF4.e[7].delta + adj;
    vt.e[9].delta = D_800B6FF4.e[9].delta + adj;
  }
  self->x2C = D_800B7044;
  self->x30 = *r;
  return self;
}

EXTERN_C void func_800B9A0C(Unk800B9A0C* self, s32 in_chrg) {
  self->x2C = D_800B7044;
  self->x0->vptr = &D_800B6FF4;
  if (!in_chrg) {
    Unk800B98D4T vt = D_800B6FF4;
    self->x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B6FF4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x38));
    vt.e[5].delta = D_800B6FF4.e[5].delta + adj;
    vt.e[7].delta = D_800B6FF4.e[7].delta + adj;
    vt.e[9].delta = D_800B6FF4.e[9].delta + adj;
  }
  func_80029D74(self, 0);
  if (in_chrg & 2) func_8001A610(self->x0, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C const Unk800B9B14E D_800B7134[];
EXTERN_C void* func_800B9B14(void* p, Unk800B8AB4* a, void* b) { func_800BA498(p, (Unk800B9790*)a, b); *(const void**)p = D_800B7134; return p; }

EXTERN_C void func_800B9B48(Unk800B9B48* p, Unk800B9B48Q* q) { Unk800B9B48L** h = &p->x10; if ((h ? *h : 0)->x4) p->v9(q); Unk800B9B48N* n = (Unk800B9B48N*)func_800B9D18((Unk800B9D18*)operator new(0x4C), &p->x8, &p->x30, p->x4->x1C); Unk800B9B48L* l = h ? *h : 0; func_80019A6C(l, n, l->x4); void* o = q->x64; if (o) { if (n->x4) func_8001A864(o, n->x4); n->x4 = o; } q->x64 = n; }

EXTERN_C Unk800B9C34* func_800B9C34(Unk800B9C34* p) { p->x0 = 3; p->x2 = 3; return p; }

EXTERN_C Unk800B9C48* func_800B9C48(Unk800B9C48* p) { p->x0 = 0; p->x2 = 0; p->x4 = 3; p->x6 = 3; return p; }

EXTERN_C void func_800B9C64(char* p, RECT* r) { char* d = p + 0x10; Unk800B9C64H* b = d ? (Unk800B9C64H*)(d + 8) : 0; Unk800B9C64L* l = b ? b->x0 : 0; Unk800BA438* e = l->x4 ? (Unk800BA438*)l->x0->x0 : 0; if (e) func_800BA438(e, r); func_800BA50C((Unk800BA50C*)p, r); }

EXTERN_C s32 func_800B9CEC(Unk800B9CEC* p) { return p->x4; }

EXTERN_C void func_800B9CF8(void* p) { func_800386B8(p); }

EXTERN_C Unk800B9D18* func_800B9D18(Unk800B9D18* p, RECT* r1, RECT* r2, u16 n) { *(void* volatile*)&p->x0 = D_80010178; *(void* volatile*)&p->x0 = D_800111BC; p->x4 = 0; p->x8 = 0; p->xA = n; p->x0 = D_800B71E4; p->x3C.x = 0; p->x3C.y = 0; p->x3C.w = 0; p->x3C.h = 0; p->x44.x = 0; p->x44.y = 0; p->x44.w = 0; p->x44.h = 0; p->x44 = *r2; func_800BA40C((Unk800BA40C*)p, r1); return p; }

EXTERN_C Unk800B9DB4* func_800B9DB4(Unk800B9DB4* p, Unk800B9DB4* q) {
  // r is set twice (dead 0 first) so cse makes it the canonical copy of q after the loop: it lands in $v0
  Unk800B9DB4* r = 0;
  base(p, q); r = q; r->x3C = p->x3C; r->x44 = p->x44; return r; }

EXTERN_C Unk800B9E78* func_800B9E78(Unk800B9E78* s) {
  Unk800B9E78* p = (Unk800B9E78*)operator new(0x4C);
  Unk800B9E78E* d = p->xC; s32 n = 1; Unk800B9E78E* q = s->xC;
  *(void* volatile*)&p->x0 = D_80010178;
  s32 t = s->x4; p->x0 = D_800111BC; p->x4 = t; p->x8 = s->x8; p->xA = s->xA;
  p->x0 = D_800B71E4;
  do { *d = *q; d++; q++; } while (--n != -1);
  p->x3C = s->x3C; p->x44 = s->x44;
  return p;
}

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9F74);

EXTERN_C void func_800BA3E4(Unk800BA3E4* p, s16 a, s16 b) { p->x3C = a; p->x3E = b; p->x8 = 2; }

EXTERN_C void func_800BA3F8(Unk800BA3F8* p, s16 a, s16 b) { p->x40 = a; p->x42 = b; p->x8 = 2; }

EXTERN_C void func_800BA40C(Unk800BA40C* p, RECT* r) { p->x3C = *r; p->x8 = 2; }

EXTERN_C void func_800BA438(Unk800BA438* p, RECT* r) { p->x44 = *r; p->x8 = 2; }

EXTERN_C void func_800BA464() {}

EXTERN_C s32 func_800BA46C(Unk800BA46C* p) { return p->x4; }

EXTERN_C void func_800BA478(void* p, s32 f) { func_8001A610(p, f); }

EXTERN_C const Unk800BA498E D_800B723C[];
EXTERN_C void* func_800BA498(void* vp, Unk800B9790* a, void* b) {
  Unk800BA498* p = (Unk800BA498*)vp;
  func_80038654(p, a, 5);
  p->x0 = (void*)D_800B723C;
  p->x30.x = 0; p->x30.y = 0; p->x30.w = 0; p->x30.h = 0;
  p->x30 = *(RECT*)b;
  return p;
}

EXTERN_C void func_800BA50C(Unk800BA50C* p, RECT* r) { p->x30 = *r; }

EXTERN_C void func_800BA534(Unk800BA534* p) { s32 r = p->v12(); if (r) p->v8(r); }

EXTERN_C s32 func_800BA598(Unk800BA598* p) { return p->x4; }

EXTERN_C void func_800BA5A4(void* p) { func_800386B8(p); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BA5C4);

EXTERN_C void func_800BBF74(Unk800BBF74* p) { p->x108 = 0; }

EXTERN_C void func_800BBF7C(Unk800BBF7C* self, s32 in_chrg) {
  self->x8C = D_800B75CC; self->xF8 = D_800B75B4; self->x100.x4 = D_800B7534; self->x0 = D_800B75E4;
  self->x100.x0->vptr = &D_800B7564;
  if (!in_chrg) {
    Unk800BBF7CT vt = D_800B7564;
    self->x100.x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B7564.e[1].delta + (adj = (char*)self - (full = (char*)self->x100.x0 - 0x150));
    vt.e[6].delta = D_800B7564.e[6].delta + adj;
  }
  Unk800BBF7C_dtor(&self->x100);
  func_80051514(&self->xF8, 0);
  func_8001E508(self, 0);
  if (in_chrg & 2) func_8001A610(self->x100.x0, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C s32 func_800BC12C(Unk800BC12C* p, Unk800BC12CP* pad) {
  s32 b = ~pad->x1A;
  switch (p->x10A) {
  case 1: case 2:
    break;
  case 3: case 4:
    if (b & 0x2000) { p->x10A = 4; p->x130 = 9; }
    break;
  case 5:
    if (b & 0x2000) p->x130 = 9;
    break;
  case 7:
    if (b & 0x2008) { p->x148->f3(); p->x10C = 2; }
    break;
  case 13: case 14:
    p->x132 = 0x14;
    break;
  case 24: {
    s32 k = b & 8; k |= 0xF001; if (k) { p->x10A = 0x1B; p->x10C = 0; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 4); }
    } break;
  case 27:
    if (b & 0x20) { p->x10A = 0x1C; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 4); }
    else if (b & 0x4000) { p->x10A = 0x15; Unk800BC12C_ev(p); func_8008EF40(0xD); }
    else if ((b & 0x2000) && p->x130 == 0) { p->x10A = 0x18; p->x134 = 0; p->x130 = 0x63; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 1); }
    else if (b & 0x40) { p->x10A = 0x1D; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 4); }
    break;
  case 28:
    if (b & 0x40) { p->x10A = 0x1D; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 4); }
    else if (b & 0x80) { p->x10A = 0x1B; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 4); }
    else if (b & 0x4000) { p->x10A = 0x15; Unk800BC12C_ev(p); func_8008EF40(0xD); }
    else if ((b & 0x2000) && p->x130 == 0) { p->x10A = 0x18; p->x130 = 0x60; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 2); }
    break;
  case 29:
    if (b & 0x80) { p->x10A = 0x1B; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 4); }
    else if (b & 0x20) { p->x10A = 0x1C; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 4); }
    else if (b & 0x4000) { p->x10A = 0x15; Unk800BC12C_ev(p); func_8008EF40(0xD); }
    else if (b & 0x2000) { p->x10A = 0x18; p->x130 = 0x5E; Unk800BC12C_ev(p); func_8008EF40(p->x13C << 16 | 3); }
    break;
  case 25:
    if ((b & 0x2000) && p->x130 == 0) p->x130 = 9;
    break;
  }
  return 1;
}

EXTERN_C int func_800BC54C() { return 1; }

EXTERN_C Unk800BC554* func_800BC554(Unk800BC554* self, s32 in_chrg, s32 a) {
  if (in_chrg) { Unk800BBF7CV* v = &self->x150; self->x100.x0 = v; self->x150.vptr = D_80010178; v->x4 = 0; self->x150.vptr = D_800104A8; }
  ((void* (*)(void*, s32, s32, s32, s32))func_8001E40C)(self, a, 2, 0x500, 0);
  func_800514C8(&self->xF8);
  Unk800BBF7CS* s = &self->x100;
  s->x0->vptr = &D_80010538;
  Unk800BBF7CT vt0 = D_80010538;
  s->x0->vptr = &vt0;
  char* full0; s32 adj0;
  vt0.e[1].delta = D_80010538.e[1].delta + (adj0 = (char*)s - (full0 = (char*)s->x0 - 8));
  vt0.e[6].delta = D_80010538.e[6].delta + adj0;
  s->x4 = D_80010508;
  self->x100.x0->vptr = &D_800B7564;
  if (!in_chrg) {
    Unk800BBF7CT vt = D_800B7564;
    self->x100.x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B7564.e[1].delta + (adj = (char*)self - (full = (char*)self->x100.x0 - 0x150));
    vt.e[6].delta = D_800B7564.e[6].delta + adj;
  }
  Unk800BC554_fin(self); return self;
}

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7530);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7534);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7564);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B75B4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B75CC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B75E4);

EXTERN_C Unk800BCCAC* func_800BC714(void* p, void* bs, u16 w, u16 h, s32 mode, Unk800BDFA8B* o, void* buf) {
#define self ((Unk800BC714*)p)
  self->x0 = D_800B7644;
  {
    Unk800BC714R* r = self->x14;
    s32 n = 1;
    do { r->pos.x = 0; r->pos.y = 0; r->size.x = 0; r->size.y = 0; r++; } while (--n != -1);
  }
  self->x50.x = 0; self->x50.y = 0;
  self->x54 = o; self->x50.x = w; self->x50.y = h; self->x4C = mode;
  DecDCTvlcBuild(self->x58);
  switch (mode) {
  case 0:
    if (buf == 0) self->x40 = (char*)func_800A0D2C((u32)(self->x50.x * self->x50.y) / 2 * 4); else self->x40 = (char*)buf;
    self->x38 = (char*)func_800A0D2C(self->x50.y * 64);
    self->x3C = self->x38 + self->x50.y * 32;
    break;
  case 1:
    if (buf == 0) self->x40 = (char*)func_800A0D2C(self->x50.x * self->x50.y * 4); else self->x40 = (char*)buf;
    self->x38 = (char*)func_800A0D2C(self->x50.y * 128);
    self->x3C = self->x38 + self->x50.y * 64;
    break;
  case 3: {
    Unk800BC714R r(D_800B4C54[0]->f4(self->x50), self->x50);
    self->x14[1] = r;
  }
  case 2:
    if (buf == 0) self->x40 = (char*)func_800A0D2C((u32)(self->x50.x * self->x50.y) / 2 * 4); else self->x40 = (char*)buf;
    {
    Unk800BC714R r(D_800B4C54[0]->f4(self->x50), self->x50);
    self->x14[0] = r;
    }
    self->x3C = (self->x38 = self->x40) + self->x50.y * 32;
    break;
  case 4:
    if (buf == 0) self->x40 = (char*)func_800A0D2C((u32)(self->x50.x * self->x50.y) / 2 * 4); else self->x40 = (char*)buf;
    self->x3C = (self->x38 = self->x40) + self->x50.y * 32;
    break;
  case 5:
    if (buf == 0) self->x40 = (char*)func_800A0D2C((u32)(self->x50.x * self->x50.y * 3) / 4 * 4); else self->x40 = (char*)buf;
    self->x3C = (self->x38 = self->x40) + self->x50.y * 48;
    break;
  }
  self->xC[0] = func_800CBA80(bs) + 0x20;
  self->x4[0] = func_800A0D2C(self->xC[0] * 4);
  self->xC[1] = self->xC[0];
  self->x4[1] = func_800A0D2C(self->xC[1] * 4);
  self->x44 = 0;
  self->x30 = 0;
  self->x2C = 1;
  self->x48 = DecDCTvlc2(bs, self->x4[0], self->x58);
  self->x24[0] = 1;
  self->x24[1] = 0;
  return (Unk800BCCAC*)self;
#undef self
}

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BCB14);

EXTERN_C s32 func_800BCCAC(Unk800BCCAC* p, void* bs) {
  if (p->x24[p->x2C] && DecDCTinSync(1)) return 0;
  p->x24[p->x2C] = 1;
  s32 n = func_800CBA80(bs) + 0x20;
  if (p->xC[p->x2C] < n) { if (p->x4[p->x2C]) func_800A0D0C(p->x4[p->x2C]); p->xC[p->x2C] = n; p->x4[p->x2C] = func_800A0D2C(n * 4); }
  p->x48 = DecDCTvlc2(bs, p->x4[p->x2C], p->x58);
  if (p->x4C == 0) p->x40 = func_800A0D2C((u32)(p->x50 * p->x52) / 2 * 4);
  if (p->x4C == 1) p->x40 = func_800A0D2C(p->x50 * p->x52 * 4);
  if (!p->x24[p->x2C ^ 1]) func_800BCEA0(p);
  p->x2C ^= 1;
  return 1;
}

EXTERN_C Unk800BCE4CR* func_800BCE4C(Unk800BCE4C* p) { return p->x4C == 3 ? &p->x14[p->x30] : p->x14; }

EXTERN_C s32 func_800BCE7C(Unk800BCE7C* p) { s32 r; if (p->x34 < p->x50) r = 0; else r = p->x40; return r; }

EXTERN_C void func_800BCEA0(void* vp) {
    Unk800BCEA0* p = (Unk800BCEA0*)vp;
    s32 n = p->x52 * 8;
    DecDCTReset(0);
    DecDCTin(p->x4[p->x30], (p->x4C == 1 || p->x4C == 5) ? 1 : 2);
    switch (p->x4C) {
    case 2: case 3: case 4:
        p->x38[p->x44] = p->x40;
        p->x38[p->x44 ^ 1] = p->x40 + p->x52 * 32;
        break;
    case 5:
        p->x38[p->x44] = p->x40;
        p->x38[p->x44 ^ 1] = p->x40 + p->x52 * 48;
        n = p->x52 * 12;
        break;
    }
    DecDCTout(p->x38[p->x44], n);
    p->x34 = 0;
    DecDCToutCallback((void*)func_800BD83C);
    p->x24[p->x30] = 2;
}

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BD008);

EXTERN_C void func_800BD83C() { func_80018AF4(); Unk800BD83CS* s = (Unk800BD83CS*)D_800CBA90[0]; if (s->x20) s->x24 = 1; else if ((s ? s->x0 : 0)->x4) { Unk800BD83CH* h = s ? &s->x8 : 0; Unk800BD83CL* l = h ? h->x0 : 0; func_800BD008(l->x4 ? *l->x0 : 0); } func_80018B18(); }

EXTERN_C void func_800BD8E8() { if (D_800CBA90[0] == 0) D_800CBA90[0] = new Unk800BD988; }

EXTERN_C void func_800BD928() { if (D_800CBA90[0]) { DecDCToutCallback(0); Unk800BD928* t = (Unk800BD928*)D_800CBA90[0]; if (t) { func_80019920(t->x0, 0); operator delete(t); } D_800CBA90[0] = 0; } }

Unk800BD988::Unk800BD988() { x0 = x8 = &xC; func_800198E0(x8, 4, 0); x4 = 0; x20 = 0; x24 = 0; DecDCTReset(0); }

EXTERN_C void func_800BD9DC(void* vs, void* item) { Unk800BD83CS* s = (Unk800BD83CS*)vs; s->x20 = 1; Unk800BD83CL* l = s ? s->x0 : 0; func_80019A6C(l, item, l->x4); if ((s ? s->x0 : 0)->x4 == 1) { Unk800BD83CH* h = s ? &s->x8 : 0; Unk800BD83CL* m = h ? h->x0 : 0; func_800BCEA0(m->x4 ? *m->x0 : 0); } s->x20 = 0; if (s->x24) { Unk800BD83CH* h2 = s ? &s->x8 : 0; Unk800BD83CL* m2 = h2 ? h2->x0 : 0; func_800BD008(m2->x4 ? *m2->x0 : 0); s->x24 = 0; } }

EXTERN_C void func_800BDADC(void* vs, s32 item) { Unk800BD83CS* s = (Unk800BD83CS*)vs; s->x20 = 1; Unk800BD83CH* h = s ? &s->x8 : 0; func_80019CFC(h ? h->x0 : 0, item); s->x20 = 0; if ((s ? s->x0 : 0)->x4 == 0) DecDCToutCallback(0); else if (s->x24) { Unk800BD83CH* h2 = s ? &s->x8 : 0; Unk800BD83CL* l = h2 ? h2->x0 : 0; func_800BD008(l->x4 ? *l->x0 : 0); s->x24 = 0; } }

EXTERN_C Unk800BDBAC* func_800BDBAC(Unk800BDBAC* p, void* a, s32 n, void* c, s32 h, s32 x, s32 y, s32 w) {
    Unk800BDBAC_A(p); Unk800BDBAC_B(&p->x30, c, h, x, y, w);
    p->x4 = D_800B76B4; p->x8 = D_800B767C; p->x30.x4 = D_800B7664; p->x30.x0 = D_800B76C4; p->x0 = D_800B76D4;
    p->x44 = a; p->x48 = 0; p->x4C = 0; p->x50 = 0; p->x54 = n - 1; p->x58 = 0;
    return p;
}

EXTERN_C void func_800BDC88(Unk800BDC88* p, s32 f) {
  p->x4 = D_800B76B4; p->x8 = D_800B767C; p->x30.x4 = D_800B7664; p->x30.x0 = D_800B76C4; p->x0 = D_800B76D4;
  if (func_8001D25C(D_800A4544, p)) func_8001D324(D_800A4544, func_8001D25C(D_800A4544, p));
  if (p->x48) p->x48->v1(3);
  if (p->x44) p->x44->v5(3);
  if (p->x50) func_800A0D0C(p->x50);
  Unk800BDC88M* t = &p->x30;
  t->x4 = D_800101C0; p->x30.x0 = D_800101B0;
  func_800198AC((Unk800BE5F8T*)t, 0);
  func_8001D024(p, f);
}

EXTERN_C void func_800BDDC8(void* vp, s32 a, s32 b) { Unk800BDDC8* p = (Unk800BDDC8*)vp; p->x20 = 0; p->x50 = func_800A0D2C(0x38400); func_800B93D8(p->x44, a, b, 1); func_8003546C(p->x44, p ? (char*)p + 8 : 0); }

EXTERN_C void func_800BDE40(Unk800BDE40* p) { p->x44->v3(); func_800BDADC(D_800CBA90[0], p->x48); func_8001AA68(p ? (char*)p + 0x30 : 0, 0); }

EXTERN_C void func_800BDEAC(Unk800BDEAC* p, char* q) { func_800B95DC(p ? (Unk800B95DC*)((char*)p + 8) : 0, q); char* d = D_800A4544; Unk800BDEACT* t = (Unk800BDEACT*)operator new(0x14); *(void* volatile*)&t->x0 = D_80010178; t->x0 = D_80010338; t->x4 = 0; t->x8 = p; t->xC = 0x80; t->x10 = 0; func_8001D150(d, t); func_8001AA68(p ? (char*)p + 0x30 : 0, 0); p->x3C = 1; }

EXTERN_C void func_800BDF48(char* p) { func_8001AB50(p ? p + 0x30 : 0, 0); }

EXTERN_C void func_800BDF78(Unk800BDF78* p) { p->x58 = 1; }

EXTERN_C void func_800BDF84(void* p, u32 n) { while (D_800A4534.xC < n) {} }

EXTERN_C s32 func_800BDFA8(Unk800BDFA8* p) {
    void* f;
    if (p->x48) {
        u32 t = D_800A4534.xC + p->x54;
        if (p->x50) { func_800A0D0C(p->x50); p->x50 = 0; }
        if (p->x4C) {
            if (func_800BCCAC(p->x48, p->x4C)) {
                func_800B95A8(p->x44, p->x4C);
                p->x4C = 0;
                func_800BDF84(p, t);
            } else {
                func_800BD83C();
                func_800BDF84(p, t);
            }
        } else {
            f = func_800B9484(p->x44);
            if (f == 0) goto tail;
            if (func_800BCCAC(p->x48, f)) {
                func_800B95A8(p->x44, f);
                func_800BDF84(p, t);
            } else {
                p->x4C = f;
                goto tail;
            }
        }
    } else {
        f = func_800B9484(p->x44);
        if (f == 0) goto tail;
        p->x48 = func_800BC714(operator new(0x11058), f, p->x20, p->x22, 5, (Unk800BDFA8B*)p, p->x50);
        p->x50 = 0;
        func_800B95A8(p->x44, f);
        func_800BD9DC(D_800CBA90[0], p->x48);
        func_800BDF84(p, D_800A4534.xC + 2);
    }
tail:
    Unk800B93D8T* s = p->x44;
    if ((s ? s->x4 : 0)->x0 & 1) {
        s->v3();
        func_800BDADC(D_800CBA90[0], (s32)p->x48);
        func_8001AA68(p ? (char*)p + 0x30 : 0, 0);
        return 1;
    }
    p->x58 = 0;
    return 0;
}

EXTERN_C Unk800BE1CC* func_800BE1CC(Unk800BE1CC* p, s32 a, s32 b, s32 c, s32 d) { func_8002860C(p, a, b, c, d); *(void* volatile*)&p->x50 = D_80010348; p->xC = D_800112F4; p->x50 = D_800B76EC; p->x0 = D_800B7704; p->x68 = b; p->x5A = func_80028F10(p); p->x5C = func_80028F58(p); func_800BE584((Unk800BE584*)p, 0); p->x70 = 0; func_80028A24(p); p->x6C = 0; Unk800BE1CCS* s = (Unk800BE1CCS*)D_800A4578[0]->x8->x14; void* o = s->x64; if (o) { if (p->x4) func_8001A864(o, p->x4); p->x4 = o; } s->x64 = p; return p; }

EXTERN_C void func_800BE2C4(Unk800BE2C4* p, s32 f) { p->xC = D_800112F4; p->x50 = D_800B76EC; p->x0 = D_800B7704; if (p->x68) p->x68->v1(3); func_8001D024(&p->x50, 0); p->xC = D_800112F4; p->x0 = D_80011304; func_8001A610(p, f); }

EXTERN_C void func_800BE368(Unk800BE368* p) { func_8002DC34(D_800A4578[0]->x8->x14, p, 0); func_80025714(D_800B4C48, p->x68); }

EXTERN_C void func_800BE3B4(Unk800BE3B4* p, s16 a, s16 b) { if (p->x6C == 0) { Unk800BE5F8T t; p->x5E = 0; p->x64 = a; p->x58 = b; p->x60 = 0; p->x62 = 0; p->x6C = 1; p->x6E = 0; func_8002972C(&t, p->x5E, p->x60, p->x62, 1); func_80028D10(p, &t); func_800198AC(&t, 2); p->v7(); func_800BE584((Unk800BE584*)p, 1); void* q = p ? p->x50 : 0; char* d = D_800A4544; Unk800BE3B4T* n = (Unk800BE3B4T*)operator new(0x14); *(void* volatile*)&n->x0 = D_80010178; n->x0 = D_80010338; n->x4 = 0; n->x8 = q; n->xC = 0x80; n->x10 = 0; func_8001D150(d, n); } }

EXTERN_C void func_800BE4B4(Unk800BE4B4* p, s16 a, s16 b) { if (p->x6C == 0) { p->x6C = 2; p->x6E = 0; p->x58 = b; p->x64 = a; void* q = p ? p->x50 : 0; char* d = D_800A4544; Unk800BE4B4T* t = (Unk800BE4B4T*)operator new(0x14); *(void* volatile*)&t->x0 = D_80010178; t->x0 = D_80010338; t->x4 = 0; t->x8 = q; t->xC = 0x80; t->x10 = 0; func_8001D150(d, t); } }

EXTERN_C s16 func_800BE54C(Unk800BE54C* p, s16 a) { if (a != 0) p->x64 = a; return p->x6E; }

EXTERN_C s16 func_800BE568(Unk800BE568* p, s16 a) { if (a != 0) p->x64 = a; return p->x6E; }

EXTERN_C void func_800BE584(Unk800BE584* p, s16 f) { if (!f) p->v9(0, 0); else p->v9(p->x5A, p->x5C); p->v7(); }

EXTERN_C void func_800BE5F8(Unk800BE5F8* p, s16 a, s16 b, s16 c) { Unk800BE5F8T t; p->x5E = a; p->x60 = b; p->x62 = c; func_8002972C(&t, a, b, c, 1); func_80028D10(p, &t); func_800198AC(&t, 2); p->v7(); }

EXTERN_C s32 func_800BE684(Unk800BE3B4* p) {
  s32 v;
  switch (p->x6C) {
  case 1: {
    Unk800BE5F8T t;
    func_8002972C(&t, p->x5E, p->x60, p->x62, 1);
    func_80028D10(p, &t);
    func_800198AC(&t, 2);
    p->v7();
    p->x5E += p->x64;
    p->x60 += p->x64;
    p->x62 += p->x64;
    if (p->x5E > p->x58) p->x6E = 1; else p->x6E = 0;
    v = p->x6E;
    break;
  }
  case 2: {
    Unk800BE5F8T t;
    s32 r;
    func_8002972C(&t, p->x5E, p->x60, p->x62, 1);
    func_80028D10(p, &t);
    func_800198AC(&t, 2);
    p->v7();
    r = 1;
    if (p->x5E - p->x64 > p->x58) { p->x5E -= p->x64; r = 0; } else p->x5E = p->x58;
    if (p->x60 - p->x64 > p->x58) { p->x60 -= p->x64; r = 0; } else p->x5E = p->x58;
    if (p->x62 - p->x64 > p->x58) { p->x62 -= p->x64; r = 0; } else p->x5E = p->x58;
    p->x6E = r;
    v = r;
    break;
  }
  default:
    return 0;
  }
  if (!v) return 0;
  p->x6C = 0;
  return 1;
}

EXTERN_C void* func_800BE880(void* p) { return p; }

EXTERN_C void func_800BE888(void* p, int f) { if (f & 1) operator delete(p); }

EXTERN_C void func_800BE8B0(Unk800BE8B0* p, char* name, s32 a) {
  p->x74 = a; strcpy(p->x0, name);
  p->x64 = func_80048D54(operator new(0x28));
  p->x6C = ctorC((Unk800BE8B0C*)operator new(0x18), p->x74, 5, 2, 0);
  Unk800BE8B0D* d = (Unk800BE8B0D*)operator new(0x44);
  StreamStat* v = &d->x3C; d->x4 = v; v->x0 = 0x10; v->x2 = 1; v->x4 = -1;
  d->x0 = D_80012154; d->x8 = D_8001201C; d->x0 = D_80012034; d->xC = d->x10;
  func_800198E0(d->x10, 4, 0);
  d->x8 = D_80012294; d->x0 = D_80012224; d->x28 = 0; d->x2C = 0;
  p->x68 = d;
  p->x88 = (s16)func_800468D0(p->x64, p, p->x6C, d);
}

EXTERN_C void func_800BE9D4(Unk800BE9D4* p) {
  p->x64 = func_80048D54(operator new(0x28));
  Unk800BE9D4D* d = (Unk800BE9D4D*)operator new(0x44);
  StreamStat* v = &d->x3C; d->x4 = v; v->x0 = 0x10; v->x2 = 1; v->x4 = -1;
  d->x0 = D_80012154; d->x8 = D_8001201C; d->x0 = D_80012034; d->xC = d->x10;
  func_800198E0(d->x10, 4, 0);
  d->x8 = D_80012294; d->x0 = D_80012224; d->x28 = 0; d->x2C = 0;
  p->x68 = d;
  if (!p->x6C) p->x6C = Unk800BE9D4_ctorC((Unk800BE9D4C*)operator new(0x18), p->x74, 5, 2, 0);
  p->x88 = (s16)func_800468D8(p->x64, p->x7C, p->x80, p->x6C, p->x68);
}

EXTERN_C void func_800BEB0C(Unk800BEB0C* p, s32 a, s32 b, s32 c) {
  p->x7C = a; p->x80 = b; p->x70 = 0; p->x74 = c;
  p->x64 = func_80048D54(operator new(0x28));
  p->x6C = ctorC((Unk800BE8B0C*)operator new(0x18), p->x74, 5, 2, 0);
  Unk800BE8B0D* d = (Unk800BE8B0D*)operator new(0x44);
  StreamStat* v = &d->x3C; d->x4 = v; v->x0 = 0x10; v->x2 = 1; v->x4 = -1;
  d->x0 = D_80012154; d->x8 = D_8001201C; d->x0 = D_80012034; d->xC = d->x10;
  func_800198E0(d->x10, 4, 0);
  d->x8 = D_80012294; d->x0 = D_80012224; d->x28 = 0; d->x2C = 0;
  p->x68 = d;
  p->x88 = (s16)func_800468D8(p->x64, a, b, p->x6C, d);
}

inline void Unk800BEC54_s(Unk800BEC54S* s, s32 a) { Unk800BEC54_VS(s->v4) = D_800101C0; Unk800BEC54_VS(s->v0) = D_800101B0; s->xC = 1; s->x10 = 5; s->x12 = 2; s->xE = 0; s->x8 = a; }
inline Unk800BEC54O* Unk800BEC54_o(Unk800BEC54O* o, s32 r, s32 a) { Unk800BEC54_VS(o->x0) = D_80011FE4; Unk800BEC54_VS(o->x8.v0) = D_800100F8; Unk800BEC54_VS(o->x8.v4) = D_80010198; Unk800BEC54_s(&o->x8, a); Unk800BEC54_VS(o->x8.v4) = D_80012104; Unk800BEC54_VS(o->x8.v0) = D_800120F4; Unk800BEC54_VS(o->x0) = D_8001211C; o->x1C = r; o->x20 = 0; o->x24 = 0; return o; }
EXTERN_C void func_800BEC54(Unk800BEC54* p) {
  if (p->x88 != 0) {
    func_80035EB4(p->x6C);
    s32 r = (s16)func_800468D8(p->x64, p->x7C, p->x80, p->x6C, p->x68);
    p->x88 = r;
    if (r != 0) return;
  }
  operator delete(p->x6C);
  p->x6C = 0;
  if (p->x70 == 0) {
    Unk800BEC54O* o = (Unk800BEC54O*)operator new(0x28);
    s32 r = p->x68->v4();
    p->x70 = Unk800BEC54_o(o, r, p->x74);
  }
  func_8003546C(p->x68, p->x70);
  func_8003714C(p->x68);
}

EXTERN_C void* func_800BEDD0(Unk800BEDD0* p) { Unk800BE5F8T t; Unk800BE5F8T* tp = &t; func_80050838(tp); if (p->x70) p->x70->v1(3); Unk800BEDD0R* r = func_80049398(p->x64); r->xC = (s32*)(p->x68->x2C + p->x68->x4->x4); r->x8 = r->xC; s32* h = r->xC; r->xC = h + 6; s32* q = h + 3; if (*r->x8 == -1) { p->x78 = func_80050874(tp, q, r, 0, 0); func_80025444(D_800B4C48, p->x78, 0); func_8001ED2C(D_800B4C18[0], 5, 3); } else p->x78 = 0; func_800BEED4((Unk800BEED4*)p); return p->x78; }

EXTERN_C void func_800BEED4(Unk800BEED4* p) { p->x68->v3(); func_80036D8C(p->x68); if (p->x64) func_80048D2C(p->x64, 3); }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7644);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7654);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7664);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B767C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B76B4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B76C4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B76D4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B76EC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7704);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BEF3C);

EXTERN_C void func_800BF51C(Unk800BF51C* self, s32 in_chrg) {
  self->x54 = D_800B7BC4; self->x58 = D_800B7C44; self->x18 = D_800B7C64;
  self->x50->vptr = &D_800B7BF4;
  if (!in_chrg) {
    Unk800C5380T vt = D_800B7BF4;
    self->x50->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B7BF4.e[1].delta + (adj = (char*)self - (full = (char*)self->x50 - 0x281C));
    vt.e[6].delta = D_800B7BF4.e[6].delta + adj;
  }
  delete self->x2818;
  self->x2818 = 0;
  func_80062A90(self->x27A0, 2);
  func_80062A90(self->x2728, 2);
  Unk800BF51C_mdtor(&self->x26BC, 2, D_80013BD0, D_80014DAC, D_80014DCC, &D_80014D5C, 0x6C);
  func_800C5798((Unk800C5380*)self->x25D8, 2);
  Unk800BF51C_mdtor(&self->x2568, 2, D_80014E7C, D_80014E5C, D_80014EAC, &D_80014E0C, 0x68);
  { Unk800BF51CO* p = self->x278; if (p) { Unk800BF51CO* e = p + 15; if (p != e) { Unk800BF51CO* b = p; do { e--; e->~Unk800BF51CO(); } while (b != e); } } }
  func_80053964(self->x25C, 2); func_80053964(self->x240, 2);
  ((void (*)(void*, s32))func_80054C34)(self->x1F0, 2); ((void (*)(void*, s32))func_80054C34)(self->x194, 2);
  func_80053964(self->x164, 2); func_80053964(self->x13C, 2); func_80053964(self->x120, 2);
  func_80053964(self->x104, 2); func_80053964(self->xE8, 2); func_80053964(self->xCC, 2);
  ((void (*)(void*, s32))func_80054C34)(self->x7C, 2);
  Unk800C5798_base_dtor((Unk800C5380*)self);
  if (in_chrg & 2) func_8001A610(self->x50, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C void func_800BF898(Unk800BF898* p, s32 v) { if (p->x78) func_800C3D5C(p->x78, v); }

EXTERN_C void func_800BF8C8(void* p) { func_800279A8(p); func_800C5E34(); func_800566E4(p); func_80055330(0); func_8005549C(6, p, 0, -1); }

EXTERN_C void func_800BF918(Unk800BF918* p) {
  delete p->x78; p->x78 = 0;
  func_80054FE0(p->x7C); func_80054FE0(p->x1F0);
  for (s32 i = 0; i < 15; i++) p->x278[i].v3();
  p->x74 = 0; func_8006323C(p);
  func_80062160(D_800B4DD0[0]);
  func_8001EFE4(p->x70, Unk800BF918_ev(7, p, p->x6C != 0));
  p->x6C = 0; func_800C6024(); func_8002798C();
}

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BFA58);

EXTERN_C s32 func_800C01C4(Unk800C01C4* p, Unk800C01C4B* q) { s32 hit; func_8001FC78(q, 0, 0); hit = 0; if (func_80054D78(func_800550BC(p)) && p->x18C == 3) hit = q->x18 == 0x4000; if (hit) { D_800B4D90[0] = 1; for (s32 i = 0; i < 15; i++) p->x278[i].v3(); void** h = &p->x1C; func_80019D40(h ? *h : 0); p->x74 = 0; p->x18C = 1; func_8005549C(7, p, 0, -1); } return 1; }

EXTERN_C void func_800C02D8(Unk800C02D8* p) {
    u32 i;
    s32 ok;
    func_800C10BC((Unk800C10BC*)p, (void*)D_800B77B8, 0x2B, (void*)D_800B7810, 0);
    func_80054FC0(p->x1F0);
    for (i = 0; i < 8; i++) func_8005556C(2, 1);
    if ((p->x190 = func_800C39D4(p->x78)) != 0) {
        p->x74 = 0;
        for (s32 j = 0; j < 15; j++) p->x278[j].v3();
        void** h = &p->x1C; func_80019D40(h ? *h : 0);
        if ((u32)(p->x190 - 3) < 2) {
            func_800C10BC((Unk800C10BC*)p, (void*)D_800B7814, 0x1E, (void*)D_800B7810, 0);
            func_80054CE4(p->x1F0);
            for (i = 0; i < 30; i++) func_8005556C(2, 1);
            p->x18C = 0;
        } else {
            if (p->x190 == 1) func_800C10BC((Unk800C10BC*)p, (void*)D_800B7854, 0x18, (void*)D_800B7810, 0);
            else func_800C10BC((Unk800C10BC*)p, (void*)D_800B7888, 0x16, (void*)D_800B7810, 0);
            func_80054CE4(p->x1F0);
            for (i = 0; i < 60; i++) func_8005556C(2, 1);
            p->x18C = 1;
            func_800553D8(0);
        }
        func_80054FE0(p->x1F0);
        func_8005549C(7, p, 0, -1);
        return;
    }
    s32 r = Unk800C02D8_open(p);
    ok = 0;
    if (r) ok = 1;
    else {
        while (p->x78->v7(0) == 0) func_8005556C(4, 1);
        p->x78->v3();
        if (func_800C39D4(p->x78)) ok = 1;
        else {
            func_800C10BC((Unk800C10BC*)p, (void*)D_800B78B8, 0xE, (void*)D_800B7810, 0);
            func_80054CE4(p->x1F0);
            func_8008EF40(0x14);
            for (i = 0; i < 60; i++) func_8005556C(2, 1);
            p->v7(3);
        }
    }
    if (ok) {
        p->x74 = 0;
        for (s32 j = 0; j < 15; j++) p->x278[j].v3();
        void** h = &p->x1C; func_80019D40(h ? *h : 0);
        p->x18C = 1;
        func_800C10BC((Unk800C10BC*)p, (void*)D_800B7888, 0x16, (void*)D_800B7810, 0);
        func_80054CE4(p->x1F0);
        for (i = 0; i < 60; i++) func_8005556C(2, 1);
        func_80054FE0(p->x1F0);
        func_8005549C(7, p, 0, -1);
        func_800553D8(0);
    }
}

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7778);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B77A0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B77B0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B77B8);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7810);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7814);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7854);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7888);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B78B8);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B78D8);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B792C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7968);

#define Unk800C06BC_VC4(o, a) { Unk800C06BCE* e = ((Unk800C06BCOV*)o)->vt; e[4].f((char*)o + e[4].d, a); }
#define Unk800C06BC_ADD(l) Unk800C06BC_add(l, (char*)p + i * 0x254 + 0x278)
EXTERN_C void func_800C06BC(Unk800C0EA4* vp) {
#define p ((Unk800C06BC*)vp)
  u32 k;
  for (s32 j = 0; j < 15; j++) p->x278[j].v3();
  { Unk800C06BCA* h = &p->x1C; func_80019D40(h ? h->x0 : 0); }
  func_800C10BC((Unk800C10BC*)p, (void*)D_800B78D8, 0x28, (void*)D_800B7810, 0);
  func_80054FC0(p->x1F0);
  func_800C5A14((Unk800C5A14*)p->x194, 0);
  func_800C5A60((Unk800C5A60*)p->x194);
  for (k = 0; k < 8; k++) func_8005556C(2, 1);
  s32 n = 0;
  p->x190 = func_800C39D4(p->x78);
  for (s32 i = 0; i < 15 && p->x190 == 0; i++) {
    func_800C5A14((Unk800C5A14*)p->x194, i + 1);
    func_8005556C(1, 1);
    if (!func_800C38C0(p->x78, func_800C4994((char*)&p->x278[i]))) { func_8008EF40(10); continue; }
    func_8008EF40(0x14);
    n++;
    func_800C2AF0((Unk800C3228*)p->x78, func_800C4994((char*)&p->x278[i]), 1);
    { Unk800C06BCA* h = &p->x1C; Unk800C06BCL* l = h ? h->x0 : 0; Unk800C06BC_ADD(l); }
    if (func_800C2F90((Unk800C2F90*)p->x78, 2) == 0) goto fail;
    while (p->x78->v7(0) == 0) func_8005556C(1, 1);
    if (!func_800C3D08((Unk800C3D08*)p->x78)) goto fail;
    if (((s8*)func_800C2D4C((Unk800C2D4C*)p->x78))[0xE4]) {
      func_800C49BC((Unk800C49BC*)&p->x278[i], (Unk800C49BCQ*)func_800C2D4C((Unk800C2D4C*)p->x78), 1);
    } else {
      p->x78->v3();
      func_800C2AF0((Unk800C3228*)p->x78, func_800C4994((char*)&p->x278[i]), 1);
      func_800C2F04((Unk800C2F04*)p->x78);
      while (p->x78->v7(0) == 0) func_8005556C(1, 1);
      func_800C49BC((Unk800C49BC*)&p->x278[i], (Unk800C49BCQ*)func_800C2D4C((Unk800C2D4C*)p->x78), 0);
    }
    goto next;
  fail:
    p->x190 = -1;
  next:
    p->x78->v3();
  }
  func_8008EF40(0x14);
  if ((p->x190 = func_800C39D4(p->x78)) == 0) {
    if (n == 0) p->x190 = 7;
    else {
      s32 r = func_800C3B88((Unk800C3B88*)p->x78) % 16;
      for (s32 i = 0; i < 15; i++) {
        if (!func_80019C24(&p->x1C ? ((Unk800C06BCA&)p->x1C).x0 : 0, &p->x278[i])) {
          if (r == 0) func_800C4860((Unk800C4860*)&p->x278[i], 1);
          else { func_800C4860((Unk800C4860*)&p->x278[i], 0); r--; }
          Unk800C06BCL* l = &p->x1C ? ((Unk800C06BCA&)p->x1C).x0 : 0;
          Unk800C06BC_ADD(l);
        }
      }
    }
  }
  func_800C5B30((Unk800C5B30*)p->x194);
  if (p->x190 != 0) {
    p->x74 = 0;
    switch (p->x190) {
    case 7: func_800C10BC((Unk800C10BC*)p, (void*)D_800B792C, 0x1C, (void*)D_800B7810, 0); break;
    case 1: func_800C10BC((Unk800C10BC*)p, (void*)D_800B7854, 0x18, (void*)D_800B7810, 0); break;
    case 3: func_800C10BC((Unk800C10BC*)p, (void*)D_800B7814, 0x1E, (void*)D_800B7810, 0); break;
    case -1: case 2: func_800C10BC((Unk800C10BC*)p, (void*)D_800B7968, 0x17, (void*)D_800B7810, 0); break;
    }
    func_80054CE4(p->x1F0);
    p->x18C = 1;
    for (k = 0; k < 60; k++) func_8005556C(2, 1);
    func_80054FE0(p->x1F0);
    func_8005549C(7, p, 0, -1);
  } else {
    p->x74 = 1;
    Unk800C9364R r;
    s32 j;
    for (j = 2; j > 0; j--) {
      Unk800C06BCO* o = (Unk800C06BCO*)func_80019F64(Unk800C06BC_list(p), j);
      Unk800C06BC_rect(&r, 0, 0, 0, 0);
      func_80054F30(o, 0, (RECT*)&r, 0);
      Unk800C10BCP* pa = &r.a; pa->x = 0x32; pa->y = j * 0x37 + 0x38;
      Unk800C06BC_VC4(o, r.a);
      o->v2();
      func_80054D48(o, 0x44);
    }
    Unk800C06BCX* x = &p->x1C;
    Unk800C06BCB* bb = x;
    Unk800C06BCO* o = (Unk800C06BCO*)func_80019F64(bb ? bb->x0 : 0, 0);
    Unk800C06BC_rect(&r, -2, -1, 4, 2);
    func_80054F30(o, 7, (RECT*)&r, 0x10);
    Unk800C10BC_set(&r.a, 0x19, 0x38);
    Unk800C06BC_VC4(o, r.a);
    o->v2();
    func_800C1AE0((Unk800C11A0*)p, func_800C4854((Unk800C4854*)o) ? o : 0);
    func_80054CE4(p->x7C);
    func_80054FE0(p->x1F0);
    x->x4 = 0;
    p->x18C = 3;
  }
  func_800553D8(0);
}

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B79C0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B79F8);

#undef p
#undef Unk800C06BC_VC4
#undef Unk800C06BC_ADD

EXTERN_C const char D_800B7810[], D_800B7814[], D_800B7854[], D_800B792C[], D_800B79C0[], D_800B79F8[];
EXTERN_C void func_800C10BC(Unk800C10BC* p, void* a, s32 b, void* c, s32 d);
EXTERN_C s32 func_80054E90(void*);
EXTERN_C void func_80054CE4(void*);
EXTERN_C void func_800C0DA4(Unk800C0DA4* p, s32 n) {
  switch (n) {
  case 7: p->x74 = 0; func_800C10BC((Unk800C10BC*)p, (void*)D_800B792C, 0x1C, (void*)D_800B7810, 0); break;
  case 4: func_800C10BC((Unk800C10BC*)p, (void*)D_800B79C0, 0x1B, (void*)D_800B7810, 0); break;
  case 1: p->x74 = 0; func_800C10BC((Unk800C10BC*)p, (void*)D_800B7854, 0x18, (void*)D_800B7810, 0); break;
  case 3: p->x74 = 0; func_800C10BC((Unk800C10BC*)p, (void*)D_800B7814, 0x1E, (void*)D_800B7810, 0); break;
  case -1: case 0: case 2: case 5: case 6:
  default: p->x74 = 0; func_800C10BC((Unk800C10BC*)p, (void*)D_800B79F8, 0xF, (void*)D_800B7810, 0); break;
  }
  void* o = p->x1F0;
  if (func_80054E90(o)) func_80054CE4(o); else func_80054FC0(o);
}

EXTERN_C void func_800C0E9C() {}

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7A40);

EXTERN_C s32 func_800C0EA4(Unk800C0EA4* p, s32 n) {
  s32 r = func_80063744(p, n);
  if (r == 0) switch (n) {
  case 3:
    func_80060588(D_800B4DD0[0], func_800C2D4C((Unk800C2D4C*)p->x78));
    func_800C16C8(p);
    p->x78->v3();
    func_80054FE0(p->x1F0);
    p->x6C = 1;
    func_800553D8(0);
    p->v3();
    break;
  case 4:
    p->x78->v3();
    func_800C10BC((Unk800C10BC*)p, (void*)D_800B7A40, 0x1D, (void*)D_800B7810, 0);
    func_80054CE4(p->x1F0);
    break;
  case 5:
    func_80055330(0);
    func_800C02D8((Unk800C02D8*)p);
    break;
  case 6:
    func_800C11A0((Unk800C11A0*)p);
    break;
  case 7:
    switch (p->x18C) {
    case 0:
      func_800C1278(p);
      break;
    case 1:
      func_80055330(0);
      func_800C1AE0((Unk800C11A0*)p, 0);
      func_80053CD8(p->xE8);
      func_80054CE4(p->x7C);
      p->x18C = 0;
      func_80054FE0(p->x1F0);
      func_800553D8(0);
      p->x2718 = -1;
      p->x25F8 = 0;
      func_800C5510((Unk800C5510*)p->x25D8);
      break;
    case 2:
      func_800C06BC(p);
      break;
    }
    break;
  }
  return r;
}

EXTERN_C void func_800C10BC(Unk800C10BC* p, void* a, s32 b, void* c, s32 d) { Unk800C10BCP t; func_8005457C(p->x240, 0); if (d == 0) { Unk800C10BC_set(&t, 4, 8); func_80053F48(p->x240, t); func_80053CD8(p->x25C); } else { Unk800C10BC_set(&t, 4, 2); func_80053F48(p->x240, t); func_80053BCC(p->x25C, c, d); } func_80053BCC(p->x240, a, b); }

EXTERN_C char D_800B7A90[]; /* D_800B7A90 */
EXTERN_C void func_800C11A0(Unk800C11A0* p) {
    u32 i;
    func_80062188(D_800B4DD0[0]);
    func_800C1AE0(p, 0);
    func_80053CD8(p->xE8);
    func_80054FC0(p->x7C);
    for (i = 0; i < 8; i++) func_8005556C(2, 1);
    if (p->x78 == 0) p->x78 = func_800C2624(operator new(0x68), 1, p->x68, 1, 0, D_800B7A90);
    p->x18C = 1;
    p->x190 = 0;
    func_8005549C(7, p, 0, -1);
    func_800553D8(0);
}

EXTERN_C void func_800C1278(Unk800C0EA4* p0) {
  Unk800C1278* p = (Unk800C1278*)p0;
  func_800C10BC((Unk800C10BC*)p, D_800B7AA0, 0x18, (void*)D_800B7810, 0);
  func_80054FC0(p->x1F0);
  for (u32 i = 0; i < 8; i++) func_8005556C(2, 1);
  s32 q; /* retry-loop busy code (4) */
  u32 b = (u32)func_800C3D50((Unk800C3D50*)p->x78) >> 4; s32 r = 0;
  u32 k; /* the parity term b + k is a giv; retail keeps it as a reduced induction variable */
  for (k = 1; ; k++) {
    if (!(k < 2)) break;
    if (r) goto done;
    if ((b + k) % 2 == 1) { func_80053BCC(p->xE8, D_800B7778, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0); }
    else { func_80053BCC(p->xE8, D_800B7AD4, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0x10); }
    func_80054CE4(p->x7C);
    s32 v = p->x190 = func_800C39D4(p->x78);
    switch (v) {
    case 0: case 3: if ((b + k) % 2 == 1) r += 1; else r += 2; break;
    case 4: {
      u32 j = 0; q = 4; /* function-scope q: keeps the retry loop's 4 out of the outer loop's hoisting */
      for (; j < 10; ) { j++; s32 w = func_800C3674(p->x78); p->x190 = w; if (w != q) break; }
    }
      if (p->x190 != 4) p->x190 = -1;
      r = -1; break;
    case -1: r = -1; break;
    }
    func_8005556C(2, 1);
  }
  if (r) goto done;
  for (k = 1; ; k++) {
    if (!(k < 2)) break;
    if (r) break;
    if ((b + k) % 2 == 1) { func_80053BCC(p->xE8, D_800B7778, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0); }
    else { func_80053BCC(p->xE8, D_800B7AD4, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0x10); }
    func_80054CE4(p->x7C);
    s32 v = p->x190 = func_800C3674(p->x78);
    switch (v) {
    case 0: case 3: if ((b + k) % 2 == 1) r += 1; else r += 2; break;
    case 4: {
      u32 j = 0; q = 4; /* function-scope q: keeps the retry loop's 4 out of the outer loop's hoisting */
      for (; j < 10; ) { j++; s32 w = func_800C3674(p->x78); p->x190 = w; if (w != q) break; }
    }
      if (p->x190 != 4) p->x190 = -1;
      r = -1; break;
    case -1: r = -1; break;
    }
  }
  func_8005556C(2, 1);
done:
  if (r <= 0) {
    if (r == 0) { func_800C3D5C((Unk800C3D5C*)p->x78, 0); func_80054CE4(p->x7C); }
    func_800C0DA4((Unk800C0DA4*)p, p->x190);
    for (u32 i = 0; i < 0x3C; i++) func_8005556C(2, 1);
    p->x18C = 1;
    func_800553D8(0);
  } else {
    if (r % 2 == 1) { func_80053BCC(p->xE8, D_800B7778, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0); }
    else { func_80053BCC(p->xE8, D_800B7AD4, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0x10); }
    func_80054CE4(p->x7C);
    p->x2718 = 2;
    func_80053BCC(p->x26BC, D_800B77A0, 6);
    p->x18C = 2;
  }
  func_80054FE0(p->x1F0);
  func_8005549C(7, p, 0, -1);
}

EXTERN_C void func_800C1690(void* p, s32* a, s32* b, s32* c, s32* d) { Unk800C1690B* g = D_800B4DD0[0]; g->x1BC = *a; g->x1C0 = *b; g->x204 = *c; g->x208 = *d; }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7A90);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7AA0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7AD4);

EXTERN_C void func_800C16C8(Unk800C0EA4* p) {
  switch (((Unk800C16C8G*)D_800B4DD0[0])->x203) {
  case 0: { s32 a = 0xD0E1, b = 0x35800, c = 0x159E4, d = 0x18000; func_800C1690(p, &a, &b, &c, &d); } break;
  case 1: { s32 a = 0xDAA1, b = 0x34000, c = 0x165FA, d = 0x1D000; func_800C1690(p, &a, &b, &c, &d); } break;
  case 2: { s32 a = 0xE60C, b = 0x31000, c = 0x157A9, d = 0x28800; func_800C1690(p, &a, &b, &c, &d); } break;
  case 3: { s32 a = 0xEC13, b = 0x2A800, c = 0x15B7F, d = 0x28800; func_800C1690(p, &a, &b, &c, &d); } break;
  case 4: { s32 a = 0xF768, b = 0x35000, c = 0x168D2, d = 0x14000; func_800C1690(p, &a, &b, &c, &d); } break;
  case 5: { s32 a = 0x10A67, b = 0x31000, c = 0x15838, d = 0x25800; func_800C1690(p, &a, &b, &c, &d); } break;
  case 6: { s32 a = 0x11395, b = 0x33000, c = 0x16247, d = 0x28000; func_800C1690(p, &a, &b, &c, &d); } break;
  case 7: { s32 a = 0x12160, b = 0x35000, c = 0x164C9, d = 0x1B800; func_800C1690(p, &a, &b, &c, &d); } break;
  case 8: { s32 a = 0x12910, b = 0x32000, c = 0x159A6, d = 0x1F000; func_800C1690(p, &a, &b, &c, &d); } break;
  case 9: { s32 a = 0x1027B, b = 0x36800, c = 0x15E77, d = 0x23000; func_800C1690(p, &a, &b, &c, &d); } break;
  }
  Unk800C5B80O o;
  func_80062610(&o);
  s32 i;
  i = func_800619F4(D_800B4DD0[0]) - 1;
  if (i >= 0) do {
    func_800627E8(&o, ((u8*)D_800B4DD0[0])[i * 0x94 + 0x23F]);
    Unk800C16C8C* d = (Unk800C16C8C*)((char*)(i * 0x94) + (s32)D_800B4DD0[0] + 0x254);
    *d = *(Unk800C16C8C*)((char*)func_80062834(&o) + 0x3C);
  } while (--i >= 0);
  ((void (*)(void*))func_800C1BF8)(p);
  ((void (*)(void*))func_800C21B8)(p);
  while (func_800382A4(D_800AC86C, ((Unk800C16C8G*)D_800B4DD0[0])->x202, 0));
  func_80062764(&o, 2);
}

EXTERN_C void func_800C1AE0(Unk800C11A0* p, void* a) {
    if (a) {
        Unk800C1AE0S buf;
        func_800538CC(&buf, D_800B7B24, 1);
        func_80053BCC(p->xE8 + 0x38, D_800B7B28, 4);
        func_80054708(p->xE8 + 0x7C, func_800C49B0((Unk800C49B0*)a));
        func_80053DDC(p->xE8 + 0x38, &buf);
        func_80053DDC(p->xE8 + 0x38, p->xE8 + 0x7C);
        func_80053BCC(p->xE8 + 0x1C, D_800B7B34, 4);
        func_80054708(p->xE8 + 0x54, func_800C4854((Unk800C4854*)a));
        func_80053DDC(p->xE8 + 0x1C, &buf);
        func_80053DDC(p->xE8 + 0x1C, p->xE8 + 0x54);
        func_80053964(&buf, 2);
    } else {
        func_80053CD8(p->xE8 + 0x38);
        func_80053CD8(p->xE8 + 0x1C);
    }
    func_80053CD8(p->xE8 + 0x7C);
    func_80053CD8(p->xE8 + 0x54);
}

#define LOAD(n) { func_800627E8(&o, n); void* q = func_80062834(&o); func_800894AC(&s, q, 0, func_8006283C(&o)); }
#define NAME(T, L) (*(T*)&s.x1E = L)
EXTERN_C void func_800C1BF8() {
  Unk800C5B80O o;
  Unk800C5B80S s;
  s32 a = func_800619F4(D_800B4DD0[0]);
  s32 b = func_800619F4(D_800B4DD0[0]);
  if (a % 10 + 1 == b / 10) {
    func_80062610(&o);
    s32 ok = 1;
    switch (((Unk800C1BF8G*)D_800B4DD0[0])->x1C4) {
    case 0x10AF: LOAD(0x39) s.xC = 0x80; NAME(Unk800C1BF8N12, D_800B7B40); break;
    case 0x215E: LOAD(0x33) s.xC = 0x80; NAME(Unk800C1BF8N14, D_800B7B50); break;
    case 0x320D: LOAD(3) NAME(Unk800C1BF8N8, D_800B7B60[0]); break;
    case 0x42BC: LOAD(0x40) NAME(Unk800C1BF8N16, D_800B7B6C); break;
    case 0x536B: LOAD(0x3F) NAME(Unk800C1BF8N12, D_800B7B80); break;
    case 0x8F02: LOAD(0x25) s.x0 = 0x28; s.x1 = 0xF6; s.x2 = 0; s.x3 = 0; s.x4 = 0xF6; s.x5 = 0xF6; s.x6 = 0xF6; s.x7 = 0xF6; s.xC = 0x2080; NAME(Unk800C1BF8N12, D_800B7B90); break;
    case 0x9D4F: LOAD(0x24) s.x8C = 3; s.x0 = 0x63; s.x1 = 0x63; s.x2 = 0x63; s.x3 = 0x63; s.x4 = 0xEC; s.x5 = 0xEC; s.x6 = 0xEC; s.x7 = 0xEC; s.xC = 0x80; NAME(Unk800C1BF8N16, D_800B7BA0); break;
    case 0x13A9E: LOAD(0x12) s.x8C = 0xFF; s.x0 = 0; s.x1 = 0; s.x2 = 0; s.x3 = 0; s.x4 = 0; s.x5 = 0x63; s.x6 = 0x63; s.x7 = 0; s.xC = 0x40; NAME(Unk800C1BF8N14, D_800B7BB4); break;
    default: ok = 0; break;
    }
    if (ok) { func_80061758(D_800B4DD0[0], &s); func_8008EF40(0x12); }
    func_80062764(&o, 2);
  }
}
#undef NAME
#undef LOAD

EXTERN_C void func_800C21B8() {
  if (*(s32*)((char*)D_800B4DD0[0] + 0x1C4) == 0x7309) {
    u32 i = 0;
    while (1) {
      if (!(i < 3)) break;
      char* g = ((Unk800C21B8G*)func_800787B4())->x328;
      Unk800C21B8L* l = (Unk800C21B8L*)(g ? g + 0xB8 : 0);
      Unk800C21B8D* d = (Unk800C21B8D*)l->x8[i];
      u8* best = &d->x424[0];
      u8* q = &d->x424[1];
      for (u32 k = 1; k < 8; k++, q++) if (*best < *q) best = q;
      *best += d->x424[7]; if (*best >= 100) *best = 99;
      d->x424[7] >>= 1;
      ((Unk800C21B8C*)d)->v2();
      d->x410 = d->x412;
      d->x420 = d->x422;
      i++;
    }
    func_8008EF40(0x13);
  }
}

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C22E8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2360);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C23D8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2450);

EXTERN_C int func_800C24C8(int x) { return (x + 0x1FFF) / 0x2000; }

EXTERN_C void func_800C24E0() { _bu_init(); func_80094990(); D_800CBA9C[0] = OpenEvent(0xF4000001, 4, 0x1000, func_800C22E8); D_800CBAA0[0] = OpenEvent(0xF4000001, 0x8000, 0x1000, func_800C2360); D_800CBAA4[0] = OpenEvent(0xF4000001, 0x100, 0x1000, func_800C23D8); D_800CBAA8[0] = OpenEvent(0xF4000001, 0x2000, 0x1000, func_800C2450); func_800949A0(); }

EXTERN_C void func_800C259C() { func_80094990(); CloseEvent(D_800CBA9C[0]); CloseEvent(D_800CBAA0[0]); CloseEvent(D_800CBAA4[0]); CloseEvent(D_800CBAA8[0]); func_800949A0(); D_800CBA9C[0] = -1; D_800CBAA0[0] = -1; D_800CBAA4[0] = -1; D_800CBAA8[0] = -1; }

EXTERN_C void* func_800C2624(void* vp, s32 in_chrg, s32 size, s32 a, s32 b, const char* name) {
#define p ((Unk800C2624*)vp)

  if (in_chrg) {
    p->x4 = p->x28 = &p->x60;
    StreamStat* v = p->x28;
    v->x0 = 0x10; v->x2 = 0; v->x4 = -1;
  }
  p->x0 = D_80012154; p->x8 = D_8001201C; p->x0 = D_80012034; p->xC = p->x10; func_800198E0(p->x10, 4, 0);
  p->x24 = D_800121AC; p->x8 = D_80012074; p->x24 = D_8001208C; p->x0 = D_800120B4;
  p->x8 = D_800B7CFC; p->x24 = D_800B7CD4; p->x0 = D_800B7D14;
  p->x30 = -1; p->x34 = -1; p->x38 = (char*)b; p->x3C = 0; p->x50 = a; p->x40 = 0;
  func_800C3D90((Unk800C3D90*)p, (char*)name);
  if (D_800CBA98[0] == 0) {
    func_800C24E0();
    EnableEvent(D_800CBA9C[0]); EnableEvent(D_800CBAA0[0]); EnableEvent(D_800CBAA4[0]); EnableEvent(D_800CBAA8[0]);
  }
  p->x58 = ((u32)size + 0x7F) / 128 * 128; s32* c = D_800CBA98; (*c)++;
  p->x44 = (char*)func_800A0D2C(func_800C40B8(p));
  p->x44[0] = 'S'; p->x44[1] = 'C'; p->x44[2] = p->x50 + 0x10;
  p->x44[3] = func_800C24C8(func_800C40B8(p));
  for (s32 i = 0; i < 0x1C; i++) p->x44[i + 0x44] = 0;
  p->x2C = 0; p->x48 = 0; p->x4C = 0; p->x54 = 0; p->x5C = 0;
  func_800C407C((Unk800C407C*)p);
  return p;
#undef p
}

EXTERN_C Unk800C2848* func_800C2848(Unk800C2848* p, s32 f, Unk800C2848* o) {
  if (f) {
    p->x4 = p->x28 = &p->x60;
    StreamStat* v = p->x28;
    v->x0 = 0x10; v->x2 = 0; v->x4 = -1;
  }
  p->x0 = D_80012154; p->x8 = D_8001201C; p->x0 = D_80012034; p->xC = p->x10;
  func_800198E0(p->x10, 4, 0);
  p->x24 = D_800121AC; p->x8 = D_80012074; p->x24 = D_8001208C; p->x0 = D_800120B4;
  p->x8 = D_800B7CFC; p->x24 = D_800B7CD4; p->x0 = D_800B7D14;
  p->x30 = -1; p->x34 = -1; p->x38 = o->x38; p->x3C = o->x3C; p->x50 = o->x50; p->x40 = 0;
  func_800C3D90((Unk800C3D90*)p, (char*)o->x40);
  void* b = func_800A0D2C(func_800C40B8(p)); p->x44 = b; void* s = o->x44;
  func_80025CE0(b, s, func_800C40B8(p));
  p->x2C = 0; p->x48 = 0; p->x4C = 0; p->x54 = 0; p->x5C = 0;
  func_800C407C((Unk800C407C*)p);
  return p;
}

EXTERN_C void func_800C29C0(Unk800C29C0* p, s32 f) {
    p->x8 = D_800B7CFC; p->x24 = D_800B7CD4; p->x0 = D_800B7D14;
    if (p->x44) func_800A0D0C(p->x44);
    func_800C2CE4((Unk800C2CE4*)p);
    if (p->x40) func_800A0D0C(p->x40);
    p->x40 = 0;
    s32* c = D_800CBA98;
    if (--*c == 0) {
        DisableEvent(D_800CBA9C[0]);
        DisableEvent(D_800CBAA0[0]);
        DisableEvent(D_800CBAA4[0]);
        DisableEvent(D_800CBAA8[0]);
        func_800C259C();
    }
    p->x8 = D_80012074; p->x24 = D_8001208C; p->x0 = D_800120B4;
    func_80035B28(&p->x24, 0);
    func_80035304(p, 0);
    if (f & 1) operator delete(p);
}

#define p ((Unk800C2AF0*)vp)
EXTERN_C s32 func_800C2AF0(Unk800C3228* vp, void* name, s32 mode) {
  p->x4->x0 = 4;
  if (p->x34 != -1 || D_800CBA94[0] != 0) return -1;
  func_800C40D0(p, name);
  Unk800C2AF0S path = *(Unk800C2AF0S*)D_800CBAAC;
  s32 fl = 0x8000;
  if (mode == 1) fl |= 2; else fl |= 1;
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

EXTERN_C void func_800C2CE4(Unk800C2CE4* p) { if (p->x34 != -1) { func_800356F4(p); close(p->x34); Unk800C2CE4B* b = p->x4; void* d = D_800CBA94[0]; p->x34 = -1; b->x4 = -1; if (d == p) D_800CBA94[0] = 0; } }

EXTERN_C s32 func_800C2D4C(Unk800C2D4C* p) { return p->x5C; }

EXTERN_C s32 func_800C2D58(Unk800C2D58* p) { Unk800C2D58B* b = p->x4; s32 i = b->x4; if (i >= 0 && i < p->x58) { s32 r = p->x5C[i]; b->x4 = i + 1; return r; } return -1; }

EXTERN_C void func_800C2DA8(Unk800C2DA8* p, u8 c) { Unk800C2DA8B* b = p->x4; s32 i = b->x4; if (i >= 0 && i < p->x58) { p->x5C[i] = c; b->x4 = i + 1; } }

EXTERN_C s32 func_800C2DF4(Unk800C2DF4* p, void* dst, s32 n) { s32 pos = p->x4->x4; if (pos < 0 || p->x58 < pos + n) return 0; func_80025CE0(dst, p->x5C + pos, n); p->x4->x4 += n; return n; }

EXTERN_C s32 func_800C2E7C(Unk800C2E7C* p, void* src, s32 n) { s32 pos = p->x4->x4; if (pos < 0 || p->x58 < pos + n) return 0; func_80025CE0(p->x5C + pos, src, n); p->x4->x4 += n; return n; }

EXTERN_C s32 func_800C2F04(Unk800C2F04* p) { p->x4->x0 = 4; if (p->x34 == -1 || D_800CBA94[0] != 0) return 0; D_800CBA94[0] = p; read(p->x34, p->x44, func_800C40B8(p)); p->x4->x4 = -1; p->x4->x0 = 1; return 1; }

EXTERN_C s32 func_800C2F90(Unk800C2F90* p, s32 n) { p->x4->x0 = 4; if (p->x34 == -1 || D_800CBA94[0] != 0) return 0; void** q = D_800CBA94; *q = p; read(p->x34, p->x44, p->x50 * 128 + 0x80 + n * 128); p->x4->x4 = -1; p->x4->x0 = 1; return 1; }

EXTERN_C s32 func_800C3024(Unk800C3024* p) { p->x4->x0 = 4; if (p->x34 == -1 || D_800CBA94[0] != 0) return 0; D_800CBA94[0] = p; write(p->x34, p->x44, func_800C40B8(p)); p->x4->x4 = -1; p->x4->x0 = 1; return 1; }

EXTERN_C s32 func_800C30B0(Unk800C30B0* p) { return p->x58; }

EXTERN_C int func_800C30BC(void* x) { return D_800CBA94[0] != x; }

EXTERN_C void* func_800C30D4(void* p, void* q) { return q; }

EXTERN_C s32 func_800C30DC(Unk800C30DC* p) {
  p->x4->x0 = 4;
  if (p->x34 != -1 || D_800CBA94[0]) return -1;
  s32 r = func_800C3674(p);
  if (r == 0 || r == 4) {
    u32 i;
    r = (_card_format(p->x38 + p->x3C) == 0) << 1;
    i = 0;
    while (r == 2 && i < 30) {
      Unk800C3F68E* e = func_8001ED2C(D_800B4C18[0], 2, 1);
      if (e) { if (e->xA == 4 && e->xC) e->xC->v1(3); e->v2(); }
      r = (_card_format(p->x38 + p->x3C) == 0) << 1;
      i++;
    }


    p->x4->x0 = r ? 2 : 0;
  }
  return r;
}

EXTERN_C s32 func_800C3228(Unk800C3228* p, void* q) {
  p->x4->x0 = 4;
  if (p->x34 != -1 || D_800CBA94[0]) return -1;
  s32 r = func_800C2AF0(p, q, 1);
  if (r == 0) { p->v3(); r = 6; p->x4->x0 = 2; }
  else if (r == 5) {
    func_800C40D0(p, q);
    Unk800C3228N n = *(Unk800C3228N*)D_800CBAAC;
    u32 i;
    s32 mode = (p->x44[3] << 16) | 0x200;
    p->x34 = open(n.c, mode);
    i = 0;
    while (p->x34 == -1 && i < 30) {
      Unk800C3F68E* e = func_8001ED2C(D_800B4C18[0], 2, 1);
      if (e) { if (e->xA == 4 && e->xC) e->xC->v1(3); e->v2(); }
      p->x34 = open(n.c, mode);
      i++;
    }
    if (p->x34 == -1) { p->x4->x0 = 2; r = func_800C3674(p) == 0 ? 7 : 2; }
    else { close(p->x34); r = 0; p->x34 = -1; p->x4->x0 = 0; }
  }
  return r;
}

EXTERN_C s32 func_800C3484(Unk800C3484* p, void* name) {
    s32 r;
    u32 i;
    s32 busy;
    Unk800C3484N n;
    p->x4->x0 = 4;
    if (p->x34 != -1 || D_800CBA94[0]) return -1;
    r = func_800C2AF0((Unk800C3228*)p, name, 1);
    if (r == 0) {
    p->v3();
    i = 0;
    func_800C40D0(p, name);
    n = *(Unk800C3484N*)D_800CBAAC;
    busy = (erase(n.d) == 0) << 1;
    while (busy && i < 30) {
        Unk800C3F68E* e = func_8001ED2C(D_800B4C18[0], 2, 1);
        if (e) { if (e->xA == 4 && e->xC) e->xC->v1(3); e->v2(); }
        busy = (erase(n.d) == 0) << 1;
        i++;
    }
    { StreamStat* st = p->x4; if (busy) st->x0 = 2; else st->x0 = 0; }
    }
    return r;
}

#define p ((Unk800C3674*)vp)
EXTERN_C s32 func_800C3674(void* vp) {
    s32 r = -1;
    s32 retry = 1;
    s32 i;
    s32 v;
    while (retry) {
        retry = 0;
        r = func_800C38F0((Unk800C38F0*)p);
        if (r == 0) {
            D_800CBA94[0] = p;
            for (i = 30; ; i--) {
                if (_card_load(p->x38 + p->x3C)) break;
                Unk800C3674_POLL
                if (i < 0) return -1;
            }
            switch (func_800C3F68((Unk800C3F68*)p)) { case 4: r = 0; break; case 0x2000: r = 4; break; default: retry = 1; break; }
            D_800CBA94[0] = 0;
        } else if (r == 3) {
            { void** d = D_800CBA94; *d = p; }
            _card_clear(p->x38 + p->x3C);
            if (func_800C3F68((Unk800C3F68*)p) != 4) retry = 1;
            else {
                D_800CBA94[0] = p;
                for (i = 30; ; i--) {
                    if (_card_load(p->x38 + p->x3C)) break;
                    Unk800C3674_POLL
                    if (i < 0) return -1;
                }
                switch (func_800C3F68((Unk800C3F68*)p)) { case 4: r = 3; break; case 0x2000: r = 4; break; default: retry = 1; break; }
            }
            D_800CBA94[0] = 0;
        }
    }
    return r;
}
#undef p

EXTERN_C int func_800C38C0(void* p, void* q) { DIRENTRY d; func_800C40D0(p, q); return firstfile(D_800CBAAC, &d) != 0; }

EXTERN_C s32 func_800C38F0(Unk800C38F0* p) {
  s32 r = -1;
  if (D_800CBA94[0] == 0) {
    if (p->x34 != -1) return -1;
    D_800CBA94[0] = p;
    s32 flag = 1;
    u32 i = 0;
    while (flag) {
      if (!(i < 3)) break;
      if (_card_info(p->x38 + p->x3C) == 1) {
        switch (func_800C3F68((Unk800C3F68*)p)) {
        case 0x2000: r = 3; flag = 0; break;
        case 4: r = 0; flag = 0; break;
        default: r = 1; break;
        }
      }
      i++;
    }
    D_800CBA94[0] = 0;
  }
  return r;
}

EXTERN_C s32 func_800C39D4(void* pv) {
  Unk800C39D4* p = (Unk800C39D4*)pv;
  s32 r;
  s32 k;
  if (D_800CBA94[0] != 0) goto fail;
  if (p->x34 != -1) return -1;
  r = -1;
  { void** q = D_800CBA94; *q = p; }
  _card_info(p->x38 + p->x3C);
  switch (func_800C3F68((Unk800C3F68*)p)) {
  case 4: break;
  case 0x2000:
    r = 3;
    { void** q = D_800CBA94; *q = p; }
    _card_clear(p->x38 + p->x3C);
    func_800C3F68((Unk800C3F68*)p);
    break;
  default:
    r = 1;
    goto end;
  }
  if (r != 3) r = 0;
  D_800CBA94[0] = p;
  k = 30;
loop:
  if (!_card_load(p->x38 + p->x3C)) {
    Unk800C3F68E* e = func_8001ED2C(D_800B4C18[0], 2, 1);
    if (e) { if (e->xA == 4 && e->xC) e->xC->v1(3); e->v2(); }
    if (k < 0) goto fail;
    k--;
    goto loop;
  }
  switch (func_800C3F68((Unk800C3F68*)p)) {
  case 4: r = r ? 3 : 0; break;
  case 0x2000: r = 4; break;
  default: r = -1; break;
  }
  goto end;
fail:
  return -1;
end:
  D_800CBA94[0] = 0;
  return r;

}

EXTERN_C s32 func_800C3B88(Unk800C3B88* p) {
  char name[7];
  DIRENTRY d;
  Unk800C3B88S13 cmp;
  char* src = p->x38 == 0 ? D_800B7CAC : D_800B7CB4;
  s32 n = 15, u = 0;
  *(Unk800C3B88S5*)name = *(Unk800C3B88S5*)src;
  name[6] = 0;
  cmp = *(Unk800C3B88S13*)D_800B7CC0;
  name[5] = D_800B7CBC[0];
  for (s32 r = firstfile(name, &d) != 0; r; r = nextfile(&d) != 0) {
    s32 match = 1;
    for (s32 k = 11; k >= 0; k--) { if (!match) break; if ((s8)d.name[k] != (s8)cmp.c[k]) match = 0; }
    if (!match) u += 1 + (d.size - 1) / 0x2000;
    n -= 1 + (d.size - 1) / 0x2000;
  }
  return n * 16 + u;
}

EXTERN_C int func_800C3D08(Unk800C3D08* p) { return p->x4->x0 == 0; }

EXTERN_C int func_800C3D1C(Unk800C3D1C* p, char* q) { if (q == 0) { p->x2C = 0; } else { if (p->x2C) return 0; p->x2C = q + 4; } return 1; }

EXTERN_C s32 func_800C3D50(Unk800C3D50* p) { return p->x38; }

EXTERN_C int func_800C3D5C(Unk800C3D5C* p, s32 v) { if (p->x38 == v || p->x34 != -1) return 0; p->x38 = v; return 1; }

EXTERN_C void func_800C3D90(Unk800C3D90* p, char* s) { s32 n = func_80094FD0(s); if (p->x40) func_800A0D0C(p->x40); p->x40 = (char*)func_800A0D2C(n + 1); func_80025CE0(p->x40, s, n); p->x40[n] = 0; }

EXTERN_C void func_800C3E10(Unk800C3E10* p, void* b) { func_80025CE0(p->x54, b, p->x50 * 128); }

EXTERN_C void func_800C3E38(Unk800C3E38* p, s32 m) {
  p->x30 = m;
  if (m == 4) { p->x4->x4 = 0; p->x4->x0 = 0; }
  else {
    p->x4->x4 = -1; p->x4->x0 = 1;
    Unk800C3E38H* h = &p->xC;
    Unk800C3E38L* l = h ? h->x0 : 0;
    Unk800C3E38O* o = l->x4 ? *l->x0 : 0;
    if (o && m != 4) {
      o->v2(0);
      Unk800C3E38H* h2 = &p->xC;
      func_80019C68((Unk800B9208L*)(h2 ? h2->x0 : 0), 0);
    }
  }
  Unk800C3E38O* q = p->x2C;
  if (q) {
    if (m == 4) q->v1(0); else q->v2(0);
    p->x2C = 0;
  }
}

EXTERN_C s32 func_800C3F68(Unk800C3F68* p) { u32 i = 0; while (p->x30 == -1 && i < 60) { Unk800C3F68E* e = func_8001ED2C(D_800B4C18[0], 2, 1); if (e) { if (e->xA == 4 && e->xC) e->xC->v1(3); e->v2(); } i++; } TestEvent(D_800CBA9C[0]); TestEvent(D_800CBAA0[0]); TestEvent(D_800CBAA4[0]); TestEvent(D_800CBAA8[0]); s32 r = p->x30; p->x30 = -1; return r; }

EXTERN_C void func_800C407C(Unk800C407C* p) { p->x48 = p->x44->d; p->x4C = p->x44->e; p->x54 = (char*)p->x44->rows; p->x5C = p->x54 + p->x50 * 128; }

EXTERN_C s32 func_800C40B8(void* vp) { Unk800C40B8* p = (Unk800C40B8*)vp; return p->x50 * 128 + 0x80 + p->x58; }

EXTERN_C void func_800C40D0(void* vp, void* vq) { Unk800C40D0* p = (Unk800C40D0*)vp; Unk800C40D0S8* q = (Unk800C40D0S8*)vq; *(Unk800C40D0S5*)D_800CBAAC = *(Unk800C40D0S5*)(p->x38 == 0 ? D_800B7CAC : D_800B7CB4); *(Unk800C40D0S12*)D_800CBAB1 = *p->x40; *(Unk800C40D0S8*)(D_800CBAB1 + 0xC) = *q; D_800CBAB1[0x14] = 0; }

EXTERN_C s32 func_800C4178(Unk800C4178* p) { return p->x54; }

EXTERN_C void func_800C4184(Unk800C4184* p, Unk800C4184R* r) { *p->x4C = *r; }

EXTERN_C s32 func_800C420C(Unk800C420C* p) { return p->x4C; }

EXTERN_C void func_800C4218(Unk800C4218* p, Unk800C4218R* r) { *p->x48 = *r; }

EXTERN_C s32 func_800C42B8(Unk800C42B8* p) { return p->x48; }

EXTERN_C void func_800C42C4(Unk800C42C4* p, Unk800C42C4R* r) { *p->x44 = *r; }

EXTERN_C s32 func_800C4364(Unk800C4364* p) { return p->x44; }

EXTERN_C Unk800C4370* func_800C4370(Unk800C4370* p) {
  func_80054AF0(p, 1);
  p->x18 = D_800B7DEC;
  p->x50 = 0; p->x78 = 0; p->x7C = 0; p->x80 = 0; p->x81 = 0;
  { Unk800C49BCA* e = p->x84; s32 n = 2; do { func_80053928(e); e++; } while (--n != -1); }
  { Unk800C49BCB* e = p->xD8; s32 n = 2; do { func_8005464C(e); e++; } while (--n != -1); }
  func_80054584(&p->x150, 0); func_80054584(&p->x178, 0); func_80054584(&p->x1A0, 0);
  func_800538CC(&p->x1C8, D_800B4D6C, 1); func_800538CC(&p->x1E4, D_800B4D6C, 1);
  func_800538CC(&p->x200, D_800B7D54, 4);
  func_800538CC(&p->x21C, D_800B7D60, 1); func_800538CC(&p->x238, D_800B7D60, 1);
  func_80054094(p, 0);
  func_80054EB4(p, 0xF6, 0x30);
  Unk800C10BCP t;
  func_8005408C(&p->x150, 2);
  Unk800C10BC_set(&t, 0xE6, 0x1C); func_80053F48(&p->x150, t);
  Unk800C10BC_set(&t, 0xD6, 0x1C); func_80053F48(&p->x1C8, t);
  Unk800C10BC_set(&t, 0xD2, 0x1C); func_80053F48(&p->x21C, t);
  func_8005408C(&p->x178, 2);
  Unk800C10BC_set(&t, 0xD2, 0x1C); func_80053F48(&p->x178, t);
  Unk800C10BC_set(&t, 0xC2, 0x1C); func_80053F48(&p->x1E4, t);
  Unk800C10BC_set(&t, 0xBE, 0x1C); func_80053F48(&p->x238, t);
  func_8005408C(&p->x1A0, 2);
  Unk800C10BC_set(&t, 0xBE, 0x1C); func_80053F48(&p->x1A0, t);
  u32 i;
  for (i = 0; i < 3; i++) {
    func_80053BCC(&p->x84[i], D_800B7D64, 2);
    Unk800C10BCP* tp = &t; tp->x = 0x6E; tp->y = i * 13 + 4; func_80053F48(&p->x84[i], t);
    func_8005408C(&p->xD8[i], 2);
    Unk800C10BCP* tq = &t; tq->x = 0x8E; tq->y = i * 13 + 4; func_80053F48(&p->xD8[i], t);
  }
  return p;
}

struct Unk800C46B8S9 { char c[9]; };
struct Unk800C46B8S25 { char c[25]; };
EXTERN_C char D_800B7D6C[], D_800B7D78[]; /* "KDL00000", Shift-JIS title */
EXTERN_C void func_800C46B8(Unk800C46B8* p, u32 n) {
  if (n - 1 < 15) {
    Unk800C46B8S9 name = *(Unk800C46B8S9*)D_800B7D6C;
    name.c[6] += n / 10; name.c[7] += n % 10;
    memcpy((char*)p + 0x54, &name, 9);
    Unk800C46B8S25 title = *(Unk800C46B8S25*)D_800B7D78;
    title.c[0x13] += n / 10; title.c[0x15] += n % 10;
    memcpy((char*)p + 0x5D, &title, 25);
    p->x78 = n;
  }
}

EXTERN_C s32 func_800C4854(Unk800C4854* p) { return p->x78; }

EXTERN_C char D_800B7DE4[]; /* D_800B7DE4 */
EXTERN_C char D_800B7D94[];
EXTERN_C char D_800B7DD0[];
EXTERN_C void func_800C4860(Unk800C4860* p, s32 mode) {
  Unk800C10BCP t;
  if (mode != 2) {
  void** h = &p->x1C; func_80019D40(h ? *h : 0);
  func_80054094(p, 1); func_80054E18(p, p->x200); func_8005457C(p->x200, 0);
  p->x50 = 1; p->x78 = 0;
  switch (mode) {
  case 0: func_80053BCC(p->x200, D_800B7D94, 0x1C); Unk800C10BC_set(&t, 0x20, 0x12); func_80053F48(p->x200, t); break;
  case 1: func_80053BCC(p->x200, D_800B7DD0, 9); Unk800C10BC_set(&t, 0x60, 0x12); func_80053F48(p->x200, t); break;
  default: func_80053BCC(p->x200, D_800B7DE4, 3); Unk800C10BC_set(&t, 0x78, 0x12); func_80053F48(p->x200, t); break;
  }
  }
}

EXTERN_C char* func_800C4994(char* p) { return p + 0x54; }

EXTERN_C char* func_800C499C(char* p) { return p + 0x5D; }

EXTERN_C s32 func_800C49A4(Unk800C49A4* p) { return p->x50; }

EXTERN_C s8 func_800C49B0(Unk800C49B0* p) { return p->x82; }

EXTERN_C void func_800C49BC(Unk800C49BC* p, Unk800C49BCQ* q, s32 flag) {
  if (p->x78 == 0) p->x78 = (p->x5A - '0') * 10 + (p->x5B - '0');
  if (flag) { p->x7C = q->xE0; p->x80 = q->xE4; p->x81 = q->xE5; p->x82 = q->xE9; }
  else { p->x7C = q->xA0; p->x80 = q->xD7; p->x81 = q->xDF; p->x82 = 0; }
  void** h = &p->x1C;
  func_80019D40(h ? *h : 0);
  func_80054094(p, 0);
  p->x50 = 0;
  func_8005457C(&p->x200, 0);
  func_80053BCC(&p->x200, D_800B7D54, 4);
  Unk800C10BCP t;
  Unk800C10BC_set(&t, 0x9C, 0x12);
  func_80053F48(&p->x200, t);
  s32 v = p->x7C;
  func_80054708(&p->x150, v % 60);
  v = v / 60;
  if (func_800549D8(&p->x150) >= 10) func_80053CD8(&p->x1C8); else func_80053BCC(&p->x1C8, D_800B4D6C, 1);
  func_80054708(&p->x178, v % 60);
  if (func_800549D8(&p->x178) >= 10) func_80053CD8(&p->x1E4); else func_80053BCC(&p->x1E4, D_800B4D6C, 1);
  func_80054708(&p->x1A0, v / 60);
  func_80054E18(p, &p->x200);
  func_80054E18(p, &p->x150);
  func_80054E18(p, &p->x1C8);
  func_80054E18(p, &p->x21C);
  func_80054E18(p, &p->x178);
  func_80054E18(p, &p->x1E4);
  func_80054E18(p, &p->x238);
  func_80054E18(p, &p->x1A0);
  u32 i;
  if (flag) {
    for (i = 0; i < p->x80; i++) {
            func_80054708(&p->xD8[i], (q->xE6 + i)[0]);
      func_80054E18(p, &p->xD8[i]);
      func_80054E18(p, &p->x84[i]);
    }
  } else {
    for (i = 0; i < p->x80; i++) {
      func_80054708(&p->xD8[i], q->x19A0[i].x0);
      func_80054E18(p, &p->xD8[i]);
      func_80054E18(p, &p->x84[i]);
    }
  }
}

EXTERN_C void func_800C4D5C(Unk800C4D5C* p) { s32 z = p->x3C == 0; func_80054FC0(p); if (z && p->x50 == 0) { void* m = operator new(0x48); s32 v = p->x81; func_8005800C(p->x3C, func_800C4F10((Unk800C4F10*)m, 1, p->x80, v < 16 ? v : 10, 2)); } }

EXTERN_C void func_800C4DE8(Unk800C4DE8* p, s32 f) {
    func_80053964(p->x238, 2);
    func_80053964(p->x21C, 2);
    func_80053964(p->x200, 2);
    func_80053964(p->x1E4, 2);
    func_80053964(p->x1C8, 2);
    func_80053964(p->x1A0, 2);
    func_80053964(p->x178, 2);
    func_80053964(p->x150, 2);
    /* member arrays with virtual dtors (vptr at 0x18, dtor in slot 1): g++'s vec-delete loop */
    if (p->xD8 != 0) { Unk800C4DE8A* t = p->xD8 + 3; while (p->xD8 != t) { t--; t->vptr[1].pfn((char*)t + t->vptr[1].delta, 2); } }
    if (p->x84 != 0) { Unk800C4DE8B* t = p->x84 + 3; while (p->x84 != t) { t--; t->vptr[1].pfn((char*)t + t->vptr[1].delta, 2); } }
    ((void (*)(void*, s32))func_80054C34)(p, f);
}

EXTERN_C void* func_800C4F10(Unk800C4F10* self, s32 in_chrg, s32 b, s32 c, u16 a) {
  Unk800C5278T vt;
  if (in_chrg) {
    self->x0 = &self->x40;
    Unk800C4F10V* v = self->x0;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_8005BC84(self, 0, a, 0x10);
  self->x0->vptr = &D_800B7E1C;
  if (!in_chrg) {
    vt = D_800B7E1C;
    self->x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B7E1C.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x40));
    vt.e[5].delta = D_800B7E1C.e[5].delta + adj;
    vt.e[7].delta = D_800B7E1C.e[7].delta + adj;
    vt.e[9].delta = D_800B7E1C.e[9].delta + adj;
  }
  self->x2C = (const Unk800C4F10E*)D_800B7E6C;
  self->x38 = b; self->x3C = c;
  {
  Unk800C10BCP t;
  Unk800C10BC_set(&t, 8, 4);
  const Unk800C4F10E* e = &self->x2C[8];
  ((void (*)(void*, s32, s32))e->pfn)((char*)self + e->delta, t.x, t.y);
  }
  return self;
}

EXTERN_C void func_800C5074(Unk800C5074* p, u8 c) { if (p->x8) { Unk800BE5F8T t; s32 i; func_8002972C(&t, c, c, c, 1); i = (p->x30 ? p->x30->x0 : 0)->x4 - 1; loop: if (i >= 0) { Unk800C5074H* h = p->x30 ? &p->x30->x8 : 0; func_80019F64(h ? h->x0 : 0, i)->v12(&t); i--; goto loop; } func_800198AC(&t, 2); } }

EXTERN_C void func_800C5148(Unk800C5148* p, void* q) {
  if (p->x8) {
    func_8005C088(p, q, 1);
    Unk800C10BCP pt = p->xC;
    for (u32 i = 0; i < p->x38; i++) {
      Unk800C8340E* e = p->x30 ? p->x30->x0 : 0;
      func_80019A6C(e, func_800C60E8(operator new(0x50), i, &pt, p->x1C), e->x4);
      pt.x += 0x20;
    }
    pt.x = p->xC.x + 0x90;
    Unk800C8340E* e = p->x30 ? p->x30->x0 : 0;
    func_80019A6C(e, func_800C60E8(operator new(0x50), p->x3C + 0x10, &pt, p->x1C), e->x4);
    func_8002DA94(q, p->x30);
  }
}

EXTERN_C void func_800C5278(Unk800C5278* self, s32 in_chrg)
{
    self->x2C = D_800B7E6C;
    self->x0->vptr = &D_800B7E1C;
    if (!in_chrg) {
        Unk800C5278T vt = D_800B7E1C;
        self->x0->vptr = &vt;
        char* full;
        s32 adj;
        vt.e[1].delta = D_800B7E1C.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x40));
        vt.e[5].delta = D_800B7E1C.e[5].delta + adj;
        vt.e[7].delta = D_800B7E1C.e[7].delta + adj;
        vt.e[9].delta = D_800B7E1C.e[9].delta + adj;
    }
    func_8005BDA4(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->x0, 0);
    if (in_chrg & 1)
        operator delete(self);
}

EXTERN_C Unk800C5380* func_800C5380(Unk800C5380* self, s32 in_chrg, s32 a) {
  Unk800C5380T vt;
  if (in_chrg) {
    self->x50 = &self->xDC;
    Unk800C5380V* v = self->x50;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_800630BC(self, 0, 2);
  self->x50->vptr = &D_800B7FB4;
  if (!in_chrg) {
    vt = D_800B7FB4;
    self->x50->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B7FB4.e[1].delta + (adj = (char*)self - (full = (char*)self->x50 - 0xDC));
    vt.e[6].delta = D_800B7FB4.e[6].delta + adj;
  }
  self->x54 = D_800B8024; self->x58 = D_800B8004; self->x18 = D_800B8054;
  func_80054AF0(self->x70, 1);
  func_800538CC(self->xC0, D_800B7F64, 0x12);
  self->x68 = a;
  func_80054EB4(self->x70, 0xF0, 0x15);

  Unk800C10BCP t;
  Unk800C10BC_set(&t, 0x28, 0x38);
  func_80053F48(self->x70, t);
  func_80054E18(self->x70, self->xC0);
  self->x6C = 0;
  return self;
}

EXTERN_C void func_800C5510(Unk800C5510* p) { Unk800C7740T t; Unk800C7740T* tp = &t; func_800BF898(p->x68, 0); func_80053BCC(p->xC0, D_800B7F64, 0x12); p->x20 = 0; func_80054FC0(p->x70); func_800631D4(p); p->x6C = func_800638A8(operator new(0x64), 1); func_8002B174(D_800A4578[0], p->x6C, -1); p->x6C->v28(); t.x0 = 0x11A; tp->x2 = 0x3C; func_80063B14(p->x6C, &t, 2); p->x6C->v4(); }

EXTERN_C void func_800C55F8(Unk800C55F8* p) { func_8002B27C(D_800A4578[0], p->x6C); p->x6C = 0; func_8006323C(p); func_80054FE0(p->x70); }

EXTERN_C s32 func_800C5640(Unk800C5640* p, Unk800C71E8B* b) {
    u16 k = b->x18;
    if (k & 0x80) {
        Unk800C7740T t; Unk800C7740T* tp = &t;
        func_800BF898(p->x68, 0);
        func_80053BCC(p->xC0, D_800B7F64, 0x12);
        func_80054CE4(p->x70);
        func_80063BE4(p->x6C);
        t.x0 = 0x11A; tp->x2 = 0x3C;
        func_80063B14(p->x6C, &t, 2);
        func_8008EF40(8);
    } else if (k & 0x20) {
        Unk800C7740T t; Unk800C7740T* tp = &t;
        func_800BF898(p->x68, 0x10);
        func_80053BCC(p->xC0, D_800B7F8C, 0x12);
        func_80054CE4(p->x70);
        func_80063BE4(p->x6C);
        t.x0 = 0x1C; tp->x2 = 0x3C;
        func_80063B14(p->x6C, &t, 1);
        func_8008EF40(8);
    } else if (k & 0x4000) {
        p->v3();
    } else {
        func_80063340(p);
    }
    return 1;
}

EXTERN_C int func_800C5770(void* p, void* a) { func_8001FC78(a, 0, 0); return 1; }

EXTERN_C void func_800C5798(Unk800C5380* self, int in_chrg) {
  self->x54 = D_800B8024;
  self->x58 = D_800B8004;
  self->x18 = D_800B8054;
  self->x50->vptr = &D_800B7FB4;
  if (!in_chrg) {
    Unk800C5380T vt = D_800B7FB4;
    self->x50->vptr = &vt;
    char* full;
    int adj;
    vt.e[1].delta = D_800B7FB4.e[1].delta + (adj = (char*)self - (full = (char*)self->x50 - 0xDC));
    vt.e[6].delta = D_800B7FB4.e[6].delta + adj;
  }
  func_80053964(self->xC0, 2);
  ((void (*)(void*, s32))func_80054C34)(self->x70, 2);
  Unk800C5798_base_dtor(self);
  if (in_chrg & 2) func_8001A610(self->x50, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C Unk800C595C* func_800C595C(Unk800C595C* p, s32 a, Unk800C595CR* r) { Unk800C10BCP u; func_80054AF0(p, 1); p->x18 = D_800B8094; p->x50 = a; p->x54 = 0; p->x58 = 0; func_80054EB4(p, r->w, r->h); Unk800C595CR t = *r; u = t.xy; func_80053F48(p, u); return p; }

EXTERN_C void func_800C5A14(Unk800C5A14* p, s32 v) { if (v >= 0 && v <= p->x50) { p->x54 = v; if (p->x58) func_800648E8(p->x58, v); } }

EXTERN_C void func_800C5A60(Unk800C5A60* p) { func_80054FC0(p); if (p->x58 == 0) { void* m = operator new(0x58); RECT r; RECT* rp = &r; s16 w = func_80054F28(p)->w - 0x10; s16 h = func_80054F28(p)->h - 8; r.x = 8; rp->y = 4; r.w = w; r.h = h; p->x58 = func_800646FC(m, 1, &r, 2); func_80064884(p->x58, p->x50, 0); func_800648E8(p->x58, p->x54); func_8005800C(p->x3C, p->x58); } }

EXTERN_C void func_800C5B30(Unk800C5B30* p) { p->x58 = 0; func_80054FE0(p); }

EXTERN_C void func_800C5B50(void* p) { func_80054C34(p); }

EXTERN_C Unk800C5B70* func_800C5B70(Unk800C5B70* p, s32 a, s32 b) { p->x4 = b; p->x0 = a; return p; }

EXTERN_C void func_800C5B80(Unk800C5B80* p) {
  Unk800C5B80A a;
  Unk800C5B80O o;
  Unk800C5B80S s;
  func_80055330(0);
  if (D_800CBAC8[0] == 0) {
    D_800CBAC8[0] = 1;
    func_8005F238(&a);
    func_8005F298(&a, 0x14349, 0x2000);
    func_80060588(D_800B4DD0[0], func_8005F28C(&a));
    func_8005F3E0(&a);
    func_8005F248(&a, 2);
  }
  func_80062610(&o);
  func_800627E8(&o, 0x19);
  {
    void* q = func_80062834(&o);
    func_800894AC(&s, q, 0, func_8006283C(&o));
  }
  s.x8C = 0x19;
  s.x0 = 6; s.x1 = 0; s.x2 = 4; s.x3 = 5; s.x4 = 0; s.x5 = 0; s.x6 = 0; s.x7 = 0;
  s.x1E = D_800B80C4;
  s.xC = 0x80; s.xE = 0;
  func_80061758(D_800B4DD0[0], &s);
  func_800627E8(&o, 0x4F);
  {
    void* q = func_80062834(&o);
    func_800894AC(&s, q, 0, func_8006283C(&o));
  }
  s.x8C = 5;
  s.x0 = 5; s.x1 = 0xFF; s.x2 = 6; s.x3 = 6; s.x4 = 0xFF; s.x5 = 0; s.x6 = 0; s.x7 = 0;
  func_80061758(D_800B4DD0[0], &s);
  {
    char* v = func_800787B4()->x328;
    Unk800C5B80R* r = v ? (Unk800C5B80R*)(v + 0xB8) : 0;
    void* w = r->x8;
    Unk800C5B80X* x = func_80061188(D_800B4DD0[0], 1);
    x->x1A = 1;
    func_8008B150(w, x, 0, 0, 0);
  }
  {
    void* w = p->x4;
    Unk800CA59CT* t = func_8001CA10(0x14);
    Unk800C6C38_ctor2(t); t->xC = (s32)p; t->x0 = D_800102D0; t->x10 = (s32)w;
    func_8001EFE4(p->x0, t);
  }
  func_800553D8(0);
  func_80062764(&o, 2);
}

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5E34);

EXTERN_C void func_800C6024() { if (D_800CBACC[0]) { func_80024FEC(D_800CBACC[0], 0); func_8005F5F4(operator new(0x14), D_800CBACC[0], 2); D_800CBACC[0] = 0; for (u32 i = 0; i < 4; i++) { func_800215E8(D_800B4C38[0], D_800CBAD0[i]); if (D_800CBAD0[i]) D_800CBAD0[i]->v1(3); D_800CBAD0[i] = 0; } } }

#define p ((Unk800C60E8*)vp_)
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
  if ((u32)idx < 16) { q->s.h = 0x28; q->s.w = 0x1E; q->s.u0 = idx * 32; q->s.v0 = 0; q->s.clut = ((Unk800C60E8W*)D_800CBAD0[idx])->x8; }
  else { q->s.h = 0x10; q->s.w = 0x80; q->s.v0 = (idx & 0xF) * 16 + 0x40; q->s.u0 = 0; q->s.clut = D_800CBADC[0]->x8; }
  // func_800C62E4 is called as value-returning (call_value): GCC then copies the return value p into $v0 right
  // after the call and the tail addresses use $v0. The clut store sits in both branches; cross-jumping merges them.
  ((s32 (*)(Unk800C62E4*, Unk800C62E4B*))func_800C62E4)((Unk800C62E4*)p, (Unk800C62E4B*)D_800B4C88);
  Unk800C60E8S* a = (Unk800C60E8S*)&p->x28[i]; Unk800C60E8S* d = (Unk800C60E8S*)&p->x28[i ^ 1];
  u32 w1 = a->w1, w2 = a->w2, w3 = a->w3, w4 = a->w4; d->w1 = w1; d->w2 = w2; d->w3 = w3; d->w4 = w4;
  return p;
}
#undef p

EXTERN_C void func_800C6298(Unk800C6298* p, s32 dx, s32 dy) { s32 i = D_800B4CF0[0]; p->x2C[i].x += dx; p->x2C[i].y += dy; func_8005F1D8(p, dx, dy); }

EXTERN_C void func_800C62E4(Unk800C62E4* p, Unk800C62E4B* q) { u8 r = q->x5, g = q->x6, b = q->x7; s32 i = D_800B4CF0[0]; p->x2C[i].r = r; p->x2C[i].g = g; p->x2C[i].b = b; func_8005F1D8(p); }

EXTERN_C void func_800C6330(Unk800C6330* p, s32 x, s32 y) { s32 i = D_800B4CF0[0]; p->v11(x - p->x28[i].x0, y - p->x28[i].y0); }

EXTERN_C Unk800C6388* func_800C6388(Unk800C6388* p) {
  Unk800C6388* n = (Unk800C6388*)operator new(0x50);
  *(void* volatile*)&n->x0 = D_80010178;
  n->x4 = p->x4; *(void* volatile*)&n->x0 = D_800111BC; n->x8 = p->x8; n->xA = p->xA;
  *(void* volatile*)&n->x0 = D_80014BD0; n->xC = p->xC;
  n->x0 = D_800B80D4;
  { Unk800C6388A* d = n->x10; s32 k = 1; Unk800C6388A* s = p->x10; do { *d = *s; d++; s++; } while (--k != -1); }
  { Unk800C6388B* d = n->x28; s32 k = 1; Unk800C6388B* s = p->x28; do { *d = *s; d++; s++; } while (--k != -1); }
  return n;
}

EXTERN_C s32 func_800C648C(Unk800C648C* p) {
  s32 i = D_800B4CF0[0];
  if (func_8005F1B4(p)) { Unk800C648CS* s = &p->x28[i ^ 1]; Unk800C648CS* d = &p->x28[i]; s32 a = s->w1, b = s->w2, c = s->w3, e = s->w4; d->w1 = a; d->w2 = b; d->w3 = c; d->w4 = e; }
  Unk800C648C_add(p->xA, &p->x28[i].tag);
  Unk800C648C_add(p->xA, &p->x10[i].tag);
  return 2;
}

EXTERN_C void func_800C65FC() {}

EXTERN_C void func_800C6604(void* p) { func_8005F120(p); }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B24);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B28);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B34);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B40);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B50);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B60);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B6C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B80);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7B90);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7BA0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7BB4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7BC4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7BF4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7C44);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7C64);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CAC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CB4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CBC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CC0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CD4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CFC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D14);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D54);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D60);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D64);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D6C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D78);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D94);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7DD0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7DE4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7DEC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7E1C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7E6C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7F64);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7F8C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7FB4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8004);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8024);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8054);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8094);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B80C4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B80D4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C6624);

EXTERN_C void func_800C6B94(Unk800C6B94* p) { RECT r; u32 i; p->x68 = 0; func_800566E4(p); func_80055330(0); RECT* rp = &r; r.x = 0; rp->y = 1; r.w = 0; r.h = 2; func_80054F30(p->x4C4, 7, &r, 0); func_80054FC0(p->x4C4); for (i = 0; i < 8; i++) func_8005556C(2, 1); func_8005549C(3, p, 0, -1); }

EXTERN_C void func_800C6C38(Unk800C6C38* p) {
    u32 i;
    func_800C908C((Unk800C908C*)p->x568);
    func_80054FE0(p);
    for (i = 0; i < 8; i++) p->x74[i].v3();
    if (p->x4B4) { func_8002B27C(D_800A4578[0], p->x4B4); p->x4B4 = 0; }
    if (p->x610) { func_8002B27C(D_800A4578[0], p->x610); p->x610 = 0; }
    func_80054FE0(p->x4C4);
    func_80054FE0(p);
    func_80056874(p);
    Unk800CA59CT* t = func_8001CA10(0x14);
    Unk800C6C38_ctor2(t); t->x10 = 3; t->xC = (s32)p; t->x0 = D_800102D0;
    func_8001EFE4(p->x6C, t);
    func_80061058(D_800B4DD0[0]);
}

EXTERN_C s32 func_800C6D80(Unk800C6D80* p, Unk800C71E8B* q) {
    u16 k;
    func_8001FC78(q, 0, 0);
    k = q->x18;
    if (k & 0xA0) {
        if (p->x4B8 == 0) {
            if (k & 0x80) p->x68 = (p->x68 + 2) % 3;
            else p->x68 = (p->x68 + 1) % 3;
            if (p->x68 == 0) {
                func_800C7740((Unk800C7740*)p);
            } else if (p->x68 == 1) {
                Unk800C7740T t; Unk800C7740T* tp = &t;
                func_80063BE4(p->x4B4);
                t.x0 = 8; tp->x2 = 0x3E;
                func_80063B14(p->x4B4, &t, 3);
            } else if (p->x68 == 2) {
                Unk800C7740T t; Unk800C7740T* tp = &t;
                func_80063BE4(p->x4B4);
                t.x0 = 0x6A; tp->x2 = 0x3E;
                func_80063B14(p->x4B4, &t, 3);
            }
            func_8008EF40(9);
        }
    } else {
        s32 m = p->x68;
        if (m == 2) {
            func_800C910C((Unk800C910C*)p->x568, (Unk800C910CB*)q);
        } else if (m == 1) {
            if (k & 0x10) {
                func_80058270(p->x3C, -1);
                p->x20 = func_80058404(p->x3C, -1);
                { void** d = (void**)D_800B4DD0; ((Unk800C6D80G*)d[0])->x1F8 = 0; }
                func_80061138(D_800B4DD0[0]);
            } else if (k & 0x40) {
                func_80058270(p->x3C, 1);
                p->x20 = func_80058404(p->x3C, 1);
                { void** d = (void**)D_800B4DD0; ((Unk800C6D80G*)d[0])->x1F8 = m; }
                func_80061138(D_800B4DD0[0]);
            }
        } else if (p->x4B8) {
            if (k & 0x10) {
                p->x4C0 = ((p->x4C0 + 3) & 3) + 4;
                func_800C7740((Unk800C7740*)p);
                func_8008EF40(8);
            } else if (k & 0x40) {
                p->x4C0 = ((p->x4C0 + 1) & 3) + 4;
                func_800C7740((Unk800C7740*)p);
                func_8008EF40(8);
            } else if (((Unk800C6D80G*)D_800B4DD0[0])->x120->x1C & k) {
                if (p->x4BC != p->x4C0) {
                    Unk800C6D80T t;
                    func_80061114(D_800B4DD0[0], p->x4BC + 8, p->x4C0 + 8);
                    func_800538CC(&t, func_80053BC0(&p->x2F4[p->x4BC]), 0);
                    func_80053C6C(&p->x2F4[p->x4BC], &p->x2F4[p->x4C0]);
                    func_80053C6C(&p->x2F4[p->x4C0], &t);
                    p->x74[p->x4BC].v5();
                    p->x74[p->x4C0].v5();
                    func_80053964(&t, 2);
                }
                func_8002B27C(D_800A4578[0], (s32)p->x4B8);
                p->x4B8 = 0;
                func_8008EF40(2);
            }
        } else {
            if (k & 0x10) {
                p->x4BC = ((p->x4BC + 3) & 3) + 4;
                func_800C7740((Unk800C7740*)p);
                func_8008EF40(8);
            } else if (k & 0x40) {
                p->x4BC = ((p->x4BC + 1) & 3) + 4;
                func_800C7740((Unk800C7740*)p);
                func_8008EF40(8);
            } else if (((Unk800C6D80G*)D_800B4DD0[0])->x120->x1C & k) {
                p->x4C0 = p->x4BC;
                p->x4B8 = func_800638A8(operator new(0x64), 1);
                func_8002B174(D_800A4578[0], p->x4B8, -1);
                func_800C7740((Unk800C7740*)p);
                func_8008EF40(0xC);
            }
        }
    }
    return 1;
}

EXTERN_C s32 func_800C71E8(Unk800C71E8* p, Unk800C71E8B* q) { u16 m = q->x18; func_8001FC78(q, 0, 0); if (D_800B4DD0[0]->x120->x18 & m) { if (p->x4B8) { func_8002B27C(D_800A4578[0], p->x4B8); p->x4B8 = 0; } else p->v3(); } return 1; }

EXTERN_C s32 func_800C7290(Unk800C7290* p, s32 msg) {
  if (msg == 3) {
    Unk800C10BCP t;
    void* m;
    p->x610 = (Unk800C7740O*)func_800C7AC0((Unk800C7AC0*)operator new(0x68), 1);
    func_8002B174(D_800A4578[0], p->x610, -1);
    p->x610->v28();
    p->x610->v4();
    u32 i;
    for (i = 0; i < 8; i++) {
      switch (((Unk800C7290G*)D_800B4DD0[0])->x1D4[i + 8]) {
      case 0x2000: func_80053C6C(&p->x2F4[i], &p->x3F0); break;
      case 0x8000: func_80053C6C(&p->x2F4[i], &p->x3D4); break;
      case 0x4000: func_80053C6C(&p->x2F4[i], &p->x40C); break;
      case 0x1000: func_80053C6C(&p->x2F4[i], &p->x428); break;
      case 0x100: func_80053C6C(&p->x2F4[i], &p->x444); break;
      case 0x200: func_80053C6C(&p->x2F4[i], &p->x460); break;
      case 0x400: func_80053C6C(&p->x2F4[i], &p->x47C); break;
      default: func_80053C6C(&p->x2F4[i], &p->x498); break;
      }
    }
    { u32 j; for (j = 0; j < 8; j++) p->x74[j].v2(); }
    Unk800C10BCP* tp = &t;
    m = operator new(0x44); t.x = 4; tp->y = 3; func_80054DA8(&p->x74[0], func_800C7D60(m, 1, t, 8, 2));
    m = operator new(0x44); t.x = 4; tp->y = 3; func_80054DA8(&p->x74[1], func_800C7D60(m, 1, t, 9, 2));
    m = operator new(0x44); t.x = 4; tp->y = 3; func_80054DA8(&p->x74[2], func_800C7D60(m, 1, t, 10, 2));
    m = operator new(0x44); t.x = 4; tp->y = 3; func_80054DA8(&p->x74[3], func_800C7D60(m, 1, t, 11, 2));
    m = operator new(0x44); t.x = 4; tp->y = 3; func_80054DA8(&p->x74[4], func_800C7D60(m, 1, t, 12, 2));
    m = operator new(0x44); t.x = 4; tp->y = 3; func_80054DA8(&p->x74[5], func_800C7D60(m, 1, t, 13, 2));
    m = operator new(0x44); t.x = 4; tp->y = 3; func_80054DA8(&p->x74[6], func_800C7D60(m, 1, t, 14, 2));
    m = operator new(0x44); t.x = 4; tp->y = 3; func_80054DA8(&p->x74[7], func_800C7D60(m, 1, t, 15, 2));
    p->x4BC = 7;
    p->x4B4 = func_800638A8(operator new(0x64), 1);
    func_8002B174(D_800A4578[0], p->x4B4, -1);
    func_800C7740((Unk800C7740*)p);
    func_8005457C(p, 1);
    t.x = 8; tp->y = 0x3F;
    { const Unk800C7290VE* e = &p->x18[4]; ((void (*)(void*, Unk800C10BCP))e->pfn)((char*)p + e->delta, t); }
    p->x20 = ((Unk800C7290G*)D_800B4DD0[0])->x1F8;
    func_800550FC(p, 2);
    func_800C9058((Unk800C9058*)p->x568);
    func_800553D8(0);
    return 1;
  }
  return 0;
}

EXTERN_C void func_800C7740(Unk800C7740* p) { Unk800C7740T t; s32 i = p->x4BC; Unk800C7740O* o = p->x4B4; s32 m = 2; if (p->x4B8) { i = p->x4C0; m = 1; o = p->x4B8; } func_80054054(&t, &p->x74[i]); t.x0 -= 4; t.x2 += 4; func_80063BE4(o); func_80063B14(o, &t, m); o->v4(); }

EXTERN_C void func_800C77F0(Unk800C77F0* self, int in_chrg) {
  self->x54 = D_800B8284; self->x58 = D_800B8264; self->x18 = D_800B82B4;
  self->x50->vptr = &D_800B8214;
  if (!in_chrg) {
    Unk800C5380T vt = D_800B8214;
    self->x50->vptr = &vt;
    char* full; int adj;
    vt.e[1].delta = D_800B8214.e[1].delta + (adj = (char*)self - (full = (char*)self->x50 - 0x614));
    vt.e[6].delta = D_800B8214.e[6].delta + adj;
  }
  func_800C91A0((Unk800C5380*)self->x568, 2);
  func_80053964(self->x54C, 2);
  func_80053964(self->x530, 2);
  func_80053964(self->x514, 2);
  ((void (*)(void*, s32))func_80054C34)(self->x4C4, 2);
  if (self->x3D4 != 0) { Unk800C77F0A* t = self->x3D4 + 8; while (self->x3D4 != t) { t--; t->vptr[1].pfn((char*)t + t->vptr[1].delta, 2); } }
  if (self->x2F4 != 0) { Unk800C77F0A* t = self->x2F4 + 8; while (self->x2F4 != t) { t--; t->vptr[1].pfn((char*)t + t->vptr[1].delta, 2); } }
  if (self->x74 != 0) { Unk800C77F0B* t = self->x74 + 8; while (self->x74 != t) { t--; t->vptr[1].pfn((char*)t + t->vptr[1].delta, 2); } }
  Unk800C5798_base_dtor((Unk800C5380*)self);
  if (in_chrg & 2) func_8001A610(self->x50, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C Unk800C7AC0* func_800C7AC0(Unk800C7AC0* self, s32 in_chrg) {
  if (in_chrg) {
    self->x0 = &self->x60;
    Unk800C7AC0V* v = self->x0;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_80057368(self, 0);
  self->x0->vptr = &D_800B82F4;
  if (!in_chrg) {
    Unk800C7C3CT vt = D_800B82F4;
    self->x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B82F4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x60));
    vt.e[5].delta = D_800B82F4.e[5].delta + adj;
    vt.e[7].delta = D_800B82F4.e[7].delta + adj;
    vt.e[9].delta = D_800B82F4.e[9].delta + adj;
  }
  self->x58 = D_800B8344;
  self->x2C = (const Unk800C7AC0E*)D_80013E30;
  self->x2C[8].pfn((char*)self + self->x2C[8].delta, 0, 0);
  self->x2C[9].pfn((char*)self + self->x2C[9].delta, 0x140, 0xF0);
  self->x5C = func_800C8114((Unk800C8114*)operator new(0x40), 1, 2);
  func_8002B174(self, self->x5C, -1);
  return self;
}

EXTERN_C void func_800C7C3C(Unk800C7C3C* self, int in_chrg) {
  self->x58 = D_800B8344;
  self->x2C = D_80013E30;
  self->x0->vptr = &D_800B82F4;
  if (!in_chrg) {
    Unk800C7C3CT vt = D_800B82F4;
    self->x0->vptr = &vt;
    char* full;
    int adj;
    vt.e[1].delta = D_800B82F4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x60));
    vt.e[5].delta = D_800B82F4.e[5].delta + adj;
    vt.e[7].delta = D_800B82F4.e[7].delta + adj;
    vt.e[9].delta = D_800B82F4.e[9].delta + adj;
  }
  func_8002B27C(self, self->x5C);
  self->x5C = 0;
  func_80057558(self, 0);
  if (in_chrg & 2) func_8001A610(self->x0, 0);
  if (in_chrg & 1) operator delete(self);
}

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8214);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8264);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8284);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B82B4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B82F4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8344);

EXTERN_C void* func_800C7D60(void* p, s32 in_chrg, Unk800C10BCP t, s32 kind, u16 a) {
#define self ((Unk800C7D60*)p)
  Unk800C800CT vt;
  if (in_chrg) {
    self->x0 = &self->x3C;
    Unk800C8114V* v = self->x0;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_8005BC84(self, 0, a, 0x10);
  self->x0->vptr = &D_800B8384;
  if (!in_chrg) {
    vt = D_800B8384;
    self->x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B8384.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x3C));
    vt.e[5].delta = D_800B8384.e[5].delta + adj;
    vt.e[7].delta = D_800B8384.e[7].delta + adj;
    vt.e[9].delta = D_800B8384.e[9].delta + adj;
  }
  self->x2C = D_800B83D4;
  self->x38 = 0;
  self->x3A = 0;
  Unk800C7D60R r;
s16 x = t.x, y = t.y; r.w = 0x20; r.h = 0x10; r.x = x; r.y = y;
  self->xC = r;
  switch (kind) {
  case 9: self->x38 = 0x20; break;
  case 10: self->x3A = 0x10; break;
  case 11: self->x38 = 0x20; self->x3A = 0x10; break;
  case 12: self->xC.w = 0x10; self->x3A = 0x20; break;
  case 13: self->xC.w = 0x10; self->x38 = 0x10; self->x3A = 0x20; break;
  case 14: self->xC.w = 0x10; self->x38 = 0x20; self->x3A = 0x20; break;
  case 15: self->xC.w = 0x10; self->x38 = 0x30; self->x3A = 0x20; break;
  }
  return self;
}
#undef self

EXTERN_C void func_800C7F60(Unk800C7F60* p, void* q) { if (p->x8) { func_8005C088(p, q, 1); Unk800C8340E* e = p->x30 ? p->x30->x0 : 0; func_80019A6C(e, new Unk800C83CC(p->xC, func_800C96B0(), p->x38, p->x1C), e->x4); func_8002DA94(q, p->x30); } }

EXTERN_C void func_800C800C(Unk800C800C* self, int in_chrg) {
  self->x2C = D_800B83D4;
  self->x0->vptr = &D_800B8384;
  if (!in_chrg) {
    Unk800C800CT vt = D_800B8384;
    self->x0->vptr = &vt;
    char* full;
    int adj;
    vt.e[1].delta = D_800B8384.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x3C));
    vt.e[5].delta = D_800B8384.e[5].delta + adj;
    vt.e[7].delta = D_800B8384.e[7].delta + adj;
    vt.e[9].delta = D_800B8384.e[9].delta + adj;
  }
  func_8005BDA4(self, 0);
  if (in_chrg & 2) func_8001A610(self->x0, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C Unk800C8114* func_800C8114(Unk800C8114* self, s32 in_chrg, u16 a) {
  if (in_chrg) {
    self->x0 = &self->x38;
    Unk800C8114V* v = self->x0;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_8005BC84(self, 0, a, 0x10);
  self->x0->vptr = &D_800B85C4;
  if (!in_chrg) {
    Unk800C8114T vt = D_800B85C4;
    self->x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B85C4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x38));
    vt.e[5].delta = D_800B85C4.e[5].delta + adj;
    vt.e[7].delta = D_800B85C4.e[7].delta + adj;
    vt.e[9].delta = D_800B85C4.e[9].delta + adj;
  }
  self->x2C = D_800B84CC;
  func_800C9364();
  return self;
}

EXTERN_C void func_800C8228(Unk800C8114* self, int in_chrg) {
  self->x2C = D_800B84CC;
  self->x0->vptr = &D_800B85C4;
  if (!in_chrg) {
    Unk800C8114T vt = D_800B85C4;
    self->x0->vptr = &vt;
    char* full;
    int adj;
    vt.e[1].delta = D_800B85C4.e[1].delta + (adj = (char*)self - (full = (char*)self->x0 - 0x38));
    vt.e[5].delta = D_800B85C4.e[5].delta + adj;
    vt.e[7].delta = D_800B85C4.e[7].delta + adj;
    vt.e[9].delta = D_800B85C4.e[9].delta + adj;
  }
  func_800C95EC();
  func_8005BDA4(self, 0);
  if (in_chrg & 2) func_8001A610(self->x0, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C void func_800C8338() {}

EXTERN_C void func_800C8340(Unk800C8340* p, void* q) { if (p->x8) { func_8005C088(p, q, 1); Unk800C8340E* e = p->x30 ? p->x30->x0 : 0; func_80019A6C(e, func_800C96C0(operator new(0x78), p->x1C), e->x4); func_8002DA94(q, p->x30); } }

Unk800C83CC::Unk800C83CC(void* a, s32 q, void* r, s32 n) {
  Unk800C83CC* p = this;
  ((void* (*)(void*, s32))func_8005F0E4)(p, n);
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

EXTERN_C void func_800C84FC(Unk800C8594* p, Unk800C8594Q d) { s32 i = D_800B4CF0[0]; p->x10[i].x0 = d.x0; p->x10[i].y0 = d.y0; p->x10[i].x1 = d.x1; p->x10[i].y1 = d.y1; p->x10[i].x2 = d.x2; p->x10[i].y2 = d.y2; p->x10[i].x3 = d.x3; p->x10[i].y3 = d.y3; func_8005F1D8(p); }

EXTERN_C void func_800C8594(Unk800C8594* p, Unk800C8594Q d) { s32 i = D_800B4CF0[0]; p->x10[i].x0 += d.x0; p->x10[i].y0 += d.y0; p->x10[i].x1 += d.x1; p->x10[i].y1 += d.y1; p->x10[i].x2 += d.x2; p->x10[i].y2 += d.y2; p->x10[i].x3 += d.x3; p->x10[i].y3 += d.y3; func_8005F1D8(p); }

EXTERN_C void func_800C8674(Unk800C8594* p, s32 a) {
  s32 i = D_800B4CF0[0];
  s32 c = func_800260A4(a); s32 c2 = c; /* retail keeps separate copies of cos/sin for the last term */
  s32 s = func_80026014(a); s32 s2 = s;
  s32 x, y;
  x = p->x10[i].x0; y = p->x10[i].y0;
  p->x10[i].x0 = (x * c - y * s + 0x800) / 4096; p->x10[i].y0 = (x * s + y * c + 0x800) / 4096;
  x = p->x10[i].x1; y = p->x10[i].y1;
  p->x10[i].x1 = (x * c - y * s + 0x800) / 4096; p->x10[i].y1 = (x * s + y * c + 0x800) / 4096;
  x = p->x10[i].x2; y = p->x10[i].y2;
  p->x10[i].x2 = (x * c - y * s + 0x800) / 4096; p->x10[i].y2 = (x * s + y * c + 0x800) / 4096;
  x = p->x10[i].x3; y = p->x10[i].y3;
  p->x10[i].x3 = (x * c - y * s + 0x800) / 4096; p->x10[i].y3 = (x * s2 + y * c2 + 0x800) / 4096;
  func_8005F1D8(p);
}

EXTERN_C void func_800C8894(Unk800C8894* p, Unk800C8894B* q) { if (q) { s32 c = D_800B4CF0[0]; Unk800C8894UV uv; s32 u; p->x10[c].tpage = q->x1C; if (q->xC == 0) u = q->x10 & 0x3F; else if (q->xC->v3()) u = (q->x10 << 1) & 0x7F; else u = q->x10 << 2; Unk800C8894_set(&uv, u, q->x12); p->x10[c].u0 = uv.u; p->x10[c].v0 = uv.v; p->x60 = *(u16*)&uv; p->x10[c].clut = q->xC->x8; func_8005F1D8(p); } }

EXTERN_C void func_800C899C(void* pv, void* qv) { Unk800C899C* p = (Unk800C899C*)pv; Unk800C899CQ* q = (Unk800C899CQ*)qv;
  s32 u = q->x + p->x60;
  s32 v = q->y + p->x61;
  s32 i = D_800B4CF0[0];
  p->x10[i].u0 = q->x + p->x60;
  p->x10[i].v0 = q->y + p->x61;
  Unk800C899C_fix(p, i, u, v);
  func_8005F1D8(p);
}

EXTERN_C void func_800C8A54(Unk800C8A54* p, Unk800C8A54B* q) { p->x0[D_800B4CF0[0]].x1E = q->x8; func_8005F1D8(p, q); }

EXTERN_C void func_800C8A90(Unk800C8A90* p, s32 dx, s32 dy) { s32 i = D_800B4CF0[0]; p->x10[i].x0 += dx; p->x10[i].y0 += dy; p->x10[i].x1 += dx; p->x10[i].y1 += dy; p->x10[i].x2 += dx; p->x10[i].y2 += dy; p->x10[i].x3 += dx; p->x10[i].y3 += dy; func_8005F1D8(p, dx, dy); }

EXTERN_C void func_800C8B24(Unk800C8B24* p, Unk800C8B24B* q) { s32 i = D_800B4CF0[0]; p->x0[i].x14 = q->x5; p->x0[i].x15 = q->x6; p->x0[i].x16 = q->x7; func_8005F1D8(p); }

EXTERN_C void func_800C8B74(Unk800C8B74* p, s32 w, s32 h) { s32 i = D_800B4CF0[0]; s32 x = p->x10[i].x0, y = p->x10[i].y0;
  p->x10[i].x1 = x + w; p->x10[i].y1 = y; p->x10[i].x2 = x; p->x10[i].y2 = y + h; p->x10[i].x3 = x + w; p->x10[i].y3 = y + h; func_8005F1D8(p); }

EXTERN_C void func_800C8BD0(Unk800C8BD0* p, s32 x, s32 y) { s32 i = D_800B4CF0[0]; p->v11(x - p->x10[i].x0, y - p->x10[i].y0); }

EXTERN_C Unk800C8C28* func_800C8C28(Unk800C8C28* p) {
  Unk800C8C28* n = (Unk800C8C28*)operator new(0x64);
  *(void* volatile*)&n->x0 = D_80010178;
  n->x4 = p->x4; *(void* volatile*)&n->x0 = D_800111BC; n->x8 = p->x8; n->xA = p->xA;
  *(void* volatile*)&n->x0 = D_80014BD0; n->xC = p->xC;
  n->x0 = D_800B8614;
  { POLY_FT4* d = n->x10; s32 k = 1; POLY_FT4* s = p->x10; do { *d = *s; d++; s++; } while (--k != -1); }
  n->x60 = p->x60;
  return n;
}

EXTERN_C s32 func_800C8D18(Unk800C8D18* p) {
  if (func_8005F1B4(p)) { s32 c = D_800B4CF0[0]; Unk800C8D18P* d = &p->x10[c]; Unk800C8D18P* s = &p->x10[c ^ 1]; u32* dw = (u32*)d; u32* sw = (u32*)s; u32 i = 0; loop: if (i < 8) { i += 4; u32 a = sw[1], b = sw[2], e = sw[3], f = sw[4]; sw += 4; dw[1] = a; dw[2] = b; dw[3] = e; dw[4] = f; dw += 4; goto loop; } d->x24 = s->x24; }
  Unk800C8D18_addz(&p->x10[D_800B4CF0[0]], p->xA); return 1; }

EXTERN_C void func_800C8E44(void* p) { func_8005F120(p); }

EXTERN_C Unk800C8E64* func_800C8E64(Unk800C8E64* self, s32 in_chrg) {
  Unk800C5380T vt;
  if (in_chrg) {
    self->x50 = &self->xA0;
    Unk800C5380V* v = self->x50;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_800630BC(self, 0, 2);
  self->x50->vptr = &D_800B86B4;
  if (!in_chrg) {
    vt = D_800B86B4;
    self->x50->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B86B4.e[1].delta + (adj = (char*)self - (full = (char*)self->x50 - 0xA0));
    vt.e[6].delta = D_800B86B4.e[6].delta + adj;
  }
  self->x54 = D_800B8724; self->x58 = D_800B8704; self->x18 = D_800B8754;
  func_800538CC(self->x68, D_800B867C, 0xC);
  func_800538CC(self->x84, D_800B8698, 0xD);
  func_80054EB4(self, 0x6E, 0x21);
  func_8005457C(self, 1);
  Unk800C10BCP t; Unk800C10BCP* tp = &t;
  t.x = 0x5F; tp->y = 0x3F; func_80063270(self, t);
  t.x = 9; tp->y = 2; func_80053F48(self->x68, t);
  t.x = 9; tp->y = 0xF; func_80053F48(self->x84, t);
  func_80054E18(self, self->x68);
  func_80054E18(self, self->x84);
  return self;
}

EXTERN_C void func_800C9058(Unk800C9058* p) { p->x20 = D_800A4578[0]->x1D2 != 0; func_800550FC(p, 2); }

EXTERN_C void func_800C908C(Unk800C908C* p) { if (p->x20 == 0) { func_8002456C(D_800A4534.x44 + 0x1AC); func_8002456C(D_800A4534.x44 + 0x2D8); } else { func_80024524(D_800A4534.x44 + 0x1AC); func_80024524(D_800A4534.x44 + 0x2D8); } func_80054FE0(p); }

EXTERN_C s32 func_800C910C(Unk800C910C* p, Unk800C910CB* q) { func_8001FC78(q, 0, 0); if (q->x18 & 0x10) { func_80058270(p->x3C, -1); p->x20 = func_80058404(p->x3C, -1); } else if (q->x18 & 0x40) { func_80058270(p->x3C, 1); p->x20 = func_80058404(p->x3C, 1); } return 1; }

EXTERN_C void func_800C91A0(Unk800C5380* self, int in_chrg) {
  self->x54 = D_800B8724; self->x58 = D_800B8704; self->x18 = D_800B8754;
  self->x50->vptr = &D_800B86B4;
  if (!in_chrg) {
    Unk800C5380T vt = D_800B86B4;
    self->x50->vptr = &vt;
    char* full; int adj;
    vt.e[1].delta = D_800B86B4.e[1].delta + (adj = (char*)self - (full = (char*)self->x50 - 0xA0));
    vt.e[6].delta = D_800B86B4.e[6].delta + adj;
  }
  func_80053964((char*)self + 0x84, 2);
  func_80053964((char*)self + 0x68, 2);
  Unk800C5798_base_dtor(self);
  if (in_chrg & 2) func_8001A610(self->x50, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C void func_800C9364() {
  if (D_800CBAE0[0] == 0) {
    Unk800C95ECV** g = D_800CBAE8;
    Unk800C5B80A t; Unk800C9364R r[2];
    func_8005F238(&t);
    func_8005F298(&t, 0x14326, 0x9800);
    char* buf = (char*)func_8005F28C(&t); buf += 0x10;
    ((Unk800C9364G*)D_800B4C38[0])->v1(*g = (Unk800C95ECV*)Unk800C9364_newA(buf));
    buf += 0x200;
    D_800CBAE0[0] = Unk800C9364_newB(g, buf, 0x80, 0x100, &r[0].b);
    func_80025444(D_800B4C48, D_800CBAE0[0], 0);
    ((Unk800C9364V*)D_800CBAE0[0])->v3();
    buf += 0x8000;
    D_800CBAE4[0] = (s32)Unk800C9364_newB(g, buf, 0x40, 0x40, &r[0].b);
    func_80025444(D_800B4C48, (void*)D_800CBAE4[0], 0);
    ((Unk800C9364V*)D_800CBAE4[0])->v3();
    func_8005F3E0(&t);
    func_8005F248(&t, 2);
  }
}

EXTERN_C void func_800C95EC() { if (D_800CBAE0[0]) { func_80024FEC(D_800CBAE0[0], 0); func_8005F5F4(operator new(0x14), D_800CBAE0[0], 2); D_800CBAE0[0] = 0; func_80024FEC((void*)D_800CBAE4[0], 0); func_8005F5F4(operator new(0x14), (void*)D_800CBAE4[0], 2); D_800CBAE4[0] = 0; func_800215E8(D_800B4C38[0], D_800CBAE8[0]); if (D_800CBAE8[0]) D_800CBAE8[0]->v1(3); D_800CBAE8[0] = 0; } }

EXTERN_C s32 func_800C96B0() { return D_800CBAE4[0]; }

EXTERN_C void* func_800C96C0(void* vp, s32 n) {
    Unk800C96C0* p = (Unk800C96C0*)vp;
    u32 i;
    s32 c;
    SPRT* t;
    s32 w0, w1, w2, w3;
    void** g;
    Unk800C96C0W *ws, *wd;
    func_8005F0E4(p, n);
    p->x0 = D_800B8794;
    g = D_800CBAE0; SetDrawMode(&p->x10[0], 0, 0, ((Unk800C96C0T*)g[0])->x1C, 0);
    SetDrawMode(&p->x10[1], 0, 0, ((Unk800C96C0T*)g[0])->x1C, 0);
    for (i = 0; i < 4; i++) { t = (SPRT*)((char*)p + i * 20 + 0x28); ((u8*)t)[3] = 4; t->code = 0x64; }
    c = D_800B4CF0[0];
    p->x28[c].x0 = -16; p->x28[c].y0 = 0x48; p->x28[c].u0 = 0; p->x28[c].v0 = 0;
    p->x28[c].h = 0x80; p->x28[c].w = 0x80;
    g = (void**)D_800CBAE8; p->x28[c].clut = ((Unk800C96C0C*)g[0])->x8;
    ws = (Unk800C96C0W*)&p->x28[c]; wd = (Unk800C96C0W*)&p->x28[c + 2]; w0 = ws->b.w[0]; w1 = ws->b.w[1]; w2 = ws->b.w[2]; w3 = ws->b.w[3]; wd->b.w[0] = w0; wd->b.w[1] = w1; wd->b.w[2] = w2; wd->b.w[3] = w3;
    p->x28[c + 2].x0 = 0x70; p->x28[c + 2].v0 = 0x80;
    func_800C98EC((Unk800C98EC*)p, (Unk800C98ECB*)D_800B4C88);
    for (i = 0; i < 4; i += 2) { ws = (Unk800C96C0W*)&p->x28[i + c]; wd = (Unk800C96C0W*)&p->x28[i + (c ^ 1)]; w0 = ws->b.w[0]; w1 = ws->b.w[1]; w2 = ws->b.w[2]; w3 = ws->b.w[3]; wd->b.w[0] = w0; wd->b.w[1] = w1; wd->b.w[2] = w2; wd->b.w[3] = w3; }
    return p;
}

EXTERN_C void func_800C9874(Unk800C9874* p, s32 dx, s32 dy) { s32 c = D_800B4CF0[0]; p->x28[c].x0 += dx; p->x28[c].y0 += dy; p->x28[c + 2].x0 += dx; p->x28[c + 2].y0 += dy; func_8005F1D8(p, dx, dy); }

EXTERN_C void func_800C98EC(Unk800C98EC* p, Unk800C98ECB* q) { s32 c = D_800B4CF0[0]; u32 i = 0; loop: if (i < 4) { p->x28[c + i].r0 = q->x5; p->x28[c + i].g0 = q->x6; p->x28[c + i].b0 = q->x7; i += 2; goto loop; } func_8005F1D8(p, q); }

EXTERN_C void func_800C9958(Unk800C9958* p, s32 x, s32 y) { s32 i = D_800B4CF0[0]; p->v11(x - p->x28[i].x0, y - p->x28[i].y0); }

EXTERN_C Unk800C99B0* func_800C99B0(Unk800C99B0* p) {
  Unk800C99B0* n = (Unk800C99B0*)operator new(0x78);
  *(void* volatile*)&n->x0 = D_80010178;
  n->x4 = p->x4; *(void* volatile*)&n->x0 = D_800111BC; n->x8 = p->x8; n->xA = p->xA;
  *(void* volatile*)&n->x0 = D_80014BD0; n->xC = p->xC;
  n->x0 = D_800B8794;
  { Unk800C99B0A* d = n->x10; s32 k = 1; Unk800C99B0A* s = p->x10; do { *d = *s; d++; s++; } while (--k != -1); }
  { Unk800C99B0B* d = n->x28; s32 k = 3; Unk800C99B0B* s = p->x28; do { *d = *s; d++; s++; } while (--k != -1); }
  return n;
}

EXTERN_C s32 func_800C9AB4(Unk800C9AB4* p) {
  s32 i = D_800B4CF0[0];
  if (func_8005F1B4(p)) { u32 j = 0; s32 k = i ^ 1; loop: if (j < 4) { Unk800C648CS* s = &p->x28[j + k]; Unk800C648CS* d = &p->x28[j + i]; j += 2; s32 a = s->w1, b = s->w2, c = s->w3, e = s->w4; d->w1 = a; d->w2 = b; d->w3 = c; d->w4 = e; goto loop; } }
  Unk800C648C_add(p->xA, &p->x28[i].tag);
  Unk800C648C_add(p->xA, &p->x28[i + 2].tag);
  Unk800C648C_add(p->xA, &p->x10[i].tag);
  return 3;
}

EXTERN_C void func_800C9CB4() {}

EXTERN_C void func_800C9CBC(void* p) { func_8005F120(p); }

EXTERN_C Unk800C9CDC* func_800C9CDC(Unk800C9CDC* self, s32 in_chrg, s32 a, s16 b) {
  if (in_chrg) {
    self->x100.x0 = &self->x180;
    Unk800BBF7CV* v = self->x100.x0;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_8001E40C(self, a, 2, 0x500, 0);
  func_800514C8(&self->xF8);
  Unk800BBF7CS* s = &self->x100;
  s->x0->vptr = &D_80010538;
  Unk800BBF7CT vt1 = D_80010538;
  s->x0->vptr = &vt1;
  char* full1; s32 adj1;
  vt1.e[1].delta = D_80010538.e[1].delta + (adj1 = (char*)s - (full1 = (char*)s->x0 - 8));
  vt1.e[6].delta = D_80010538.e[6].delta + adj1;
  s->x4 = D_80010508;
  self->x100.x0->vptr = &D_800B89CC;
  Unk800BBF7CT vt;
  char* full; s32 adj;
  if (!in_chrg) {
    vt = D_800B89CC;
    self->x100.x0->vptr = &vt;
    vt.e[1].delta = D_800B89CC.e[1].delta + (adj = (char*)self - (full = (char*)self->x100.x0 - 0x180));
    vt.e[6].delta = D_800B89CC.e[6].delta + adj;
  }
  self->x8C = D_800B8A34; self->xF8 = D_800B8A1C; self->x100.x4 = D_800B899C; self->x0 = D_800B8A4C;
  self->x108 = 1;
  self->x17C = 1;
  self->x114 = a;
  self->x118 = b;
  if (b == 0) { self->x17C = 0; func_800CA928(self); }
  self->x118 = b;
  return self;
}

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8380);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8384);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B83D4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B84CC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B85C4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8614);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B867C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8698);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B86B4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8704);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8724);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8754);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8794);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C9ED8);

EXTERN_C void func_800CA59C(Unk800CA59C* p) { p->x108 = 0; Unk800CA59CT* t = func_8001CA10(0x14); Unk800CA59C_ctor3(t); func_8001EFE4(p, t); }

EXTERN_C void func_800CA610(Unk800CA610* self, s32 in_chrg) {
  self->x8C = D_800B8A34; self->xF8 = D_800B8A1C; self->x100.x4 = D_800B899C; self->x0 = D_800B8A4C;
  self->x100.x0->vptr = &D_800B89CC;
  if (!in_chrg) {
    Unk800BBF7CT vt = D_800B89CC;
    self->x100.x0->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B89CC.e[1].delta + (adj = (char*)self - (full = (char*)self->x100.x0 - 0x180));
    vt.e[6].delta = D_800B89CC.e[6].delta + adj;
  }
  Unk800CA610O* o = self->x10C;
  if (o) { const Unk800CA610E* e = &o->vptr[1]; ((void (*)(void*, s32))e->pfn)((char*)o + e->delta, 3); }
  Unk800BBF7C_dtor(&self->x100);
  func_80051514(&self->xF8, 0);
  func_8001E508(self, 0);
  if (in_chrg & 2) func_8001A610(self->x100.x0, 0);
  if (in_chrg & 1) operator delete(self);
}

EXTERN_C s32 func_800CA7EC(Unk800CA7EC* p, Unk800CA7ECB* q) { if (~q->x1A & 8) { func_800232A0(D_800A4578[0]->x154, p); if (p->x110) p->x110->v3(); } return 1; }

EXTERN_C int func_800CA864() { return 1; }

EXTERN_C void func_800CA86C(Unk800CA86C* p) { func_800BDDC8(p->x10C, 0x30, 0xC0); }

EXTERN_C void func_800CA894(Unk800CA894* p) { if (p->x178) p->x178->v1(3); for (s32 i = 0; i < 23; i++) if (p->x11C[i]) p->x11C[i]->v1(3); }

EXTERN_C void func_800CA928(void* vp) {
#define p ((Unk800CA928*)vp)
  p->x178 = (Unk800CA928O*)((void* (*)(void*, s32, s32))func_800630BC)(operator new(0x70), 1, 0x17);
  p->x11C[0] = func_80062848(operator new(0x78), 1, D_800B882C, p, 1, 0);
  p->x11C[1] = func_80062848(operator new(0x78), 1, D_800B883C, p, 2, 0);
  p->x11C[2] = func_80062848(operator new(0x78), 1, D_800B884C, p, 3, 0);
  p->x11C[3] = func_80062848(operator new(0x78), 1, D_800B885C, p, 4, 0);
  p->x11C[4] = func_80062848(operator new(0x78), 1, D_800B886C, p, 5, 0);
  p->x11C[5] = func_80062848(operator new(0x78), 1, D_800B887C, p, 6, 0);
  p->x11C[6] = func_80062848(operator new(0x78), 1, D_800B888C, p, 7, 0);
  p->x11C[7] = func_80062848(operator new(0x78), 1, D_800B889C, p, 8, 0);
  p->x11C[8] = func_80062848(operator new(0x78), 1, D_800B88AC, p, 9, 0);
  p->x11C[9] = func_80062848(operator new(0x78), 1, D_800B88BC, p, 10, 0);
  p->x11C[10] = func_80062848(operator new(0x78), 1, D_800B88CC, p, 11, 0);
  p->x11C[11] = func_80062848(operator new(0x78), 1, D_800B88DC, p, 12, 0);
  p->x11C[12] = func_80062848(operator new(0x78), 1, D_800B88EC, p, 13, 0);
  p->x11C[13] = func_80062848(operator new(0x78), 1, D_800B88FC, p, 14, 0);
  p->x11C[14] = func_80062848(operator new(0x78), 1, D_800B890C, p, 15, 0);
  p->x11C[15] = func_80062848(operator new(0x78), 1, D_800B891C, p, 16, 0);
  p->x11C[16] = func_80062848(operator new(0x78), 1, D_800B892C, p, 17, 0);
  p->x11C[17] = func_80062848(operator new(0x78), 1, D_800B893C, p, 18, 0);
  p->x11C[18] = func_80062848(operator new(0x78), 1, D_800B894C, p, 19, 0);
  p->x11C[19] = func_80062848(operator new(0x78), 1, D_800B895C, p, 20, 0);
  p->x11C[20] = func_80062848(operator new(0x78), 1, D_800B896C, p, 21, 0);
  p->x11C[21] = func_80062848(operator new(0x78), 1, D_800B897C, p, 22, 0);
  p->x11C[22] = func_80062848(operator new(0x78), 1, D_800B898C, p, 23, 0);
  func_80054E18(p->x178, p->x11C[0]);
  func_80054E18(p->x178, p->x11C[1]);
  func_80054E18(p->x178, p->x11C[2]);
  func_80054E18(p->x178, p->x11C[3]);
  func_80054E18(p->x178, p->x11C[4]);
  func_80054E18(p->x178, p->x11C[5]);
  func_80054E18(p->x178, p->x11C[6]);
  func_80054E18(p->x178, p->x11C[7]);
  func_80054E18(p->x178, p->x11C[8]);
  func_80054E18(p->x178, p->x11C[9]);
  func_80054E18(p->x178, p->x11C[10]);
  func_80054E18(p->x178, p->x11C[11]);
  func_80054E18(p->x178, p->x11C[12]);
  func_80054E18(p->x178, p->x11C[13]);
  func_80054E18(p->x178, p->x11C[14]);
  func_80054E18(p->x178, p->x11C[15]);
  func_80054E18(p->x178, p->x11C[16]);
  func_80054E18(p->x178, p->x11C[17]);
  func_80054E18(p->x178, p->x11C[18]);
  func_80054E18(p->x178, p->x11C[19]);
  func_80054E18(p->x178, p->x11C[20]);
  func_80054E18(p->x178, p->x11C[21]);
  func_80054E18(p->x178, p->x11C[22]);
  p->x178->v4(Unk800CA928P(10, 0xE6));
  p->x178->v2();
#undef p
}

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTReset);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTGetEnv);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTPutEnv);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTin);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_188);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_1B4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTout);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTinSync);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_220);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCToutSync);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_268);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTinCallback);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCToutCallback);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_2C0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B882C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B883C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B884C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B885C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B886C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B887C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B888C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B889C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B88AC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B88BC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B88CC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B88DC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B88EC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B88FC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B890C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B891C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B892C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B893C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B894C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B895C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B896C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B897C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B898C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B899C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B89CC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8A1C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8A34);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8A4C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_394);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_3A0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_3B0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_440);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_4CC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_550);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_560);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_5E4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_5F4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_60C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTvlcSize2);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTvlc2);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTvlcBuild);

INCLUDE_ASM("asm/movie/nonmatchings/movie", BUILD_OBJ_AC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800CBA80);
