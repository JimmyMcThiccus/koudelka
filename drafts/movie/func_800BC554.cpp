// func_800BC554: 15 differing, only the tail: retail copies this to $v0 at the if-join and does the 4 vptr stores + x108 through $v0 (temps in $v1); here sched1 leaves the return copy at the end (temps in $v0). Same trick works in landed func_800B98D4, unclear why not here.
#include "movie/movie.h"
struct Unk800BC554 { const void* x0; char p0[0x8C - 4]; const void* x8C; char p1[0xF8 - 0x90]; const void* xF8; char p2[0x100 - 0xFC]; Unk800BBF7CS x100; s16 x108; char p3[0x150 - 0x10A]; Unk800BBF7CV x150; };
EXTERN_C void func_8001E40C(void*, s32, s32, s32, s32);
EXTERN_C void func_800514C8(void*);
inline Unk800BC554* Unk800BC554_fin(Unk800BC554* t) { t->x8C = D_800B75CC; t->xF8 = D_800B75B4; t->x100.x4 = D_800B7534; t->x0 = D_800B75E4; t->x108 = 1; return t; }
//@func
EXTERN_C Unk800BC554* func_800BC554(Unk800BC554* self, s32 in_chrg, s32 a) {
  if (in_chrg) { Unk800BBF7CV* v = &self->x150; self->x100.x0 = v; self->x150.vptr = D_80010178; v->x4 = 0; self->x150.vptr = D_800104A8; }
  func_8001E40C(self, a, 2, 0x500, 0);
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

