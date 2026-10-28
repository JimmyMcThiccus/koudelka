// func_800C6624: 184 differing, but only the loop-setup block (retail 0x290-0x2C4) differs: retail computes tp = &t (sp+0x60) first, spills it to 0x70 and reloads it into t0; here sched puts the tp def after the giv inits and t0 is reused (one instruction shorter), so everything after is shifted by one instruction. Rest identical.
#include "movie/movie.h"
/* ctor of the func_800C77F0 object; virtual base at 0x614 */
struct Unk800C6624S { char d[0x1C]; };
struct Unk800C6624E { char d[0x50]; };
struct Unk800C6624 { char p0[0x18]; const void* x18; char p1[0x50 - 0x1C]; Unk800C5380V* x50; const void* x54; const void* x58; char p2[0x68 - 0x5C]; s32 x68; s32 x6C; char p3[0x74 - 0x70];
  Unk800C6624E x74[8]; Unk800C6624S x2F4[8]; Unk800C6624S x3D4[8]; Unk800C7740O* x4B4; s32 x4B8, x4BC, x4C0; char x4C4[0x514 - 0x4C4]; char x514[0x1C]; char x530[0x1C]; char x54C[0x1C];
  char x568[0x610 - 0x568]; s32 x610; Unk800C5380V x614; };
EXTERN_C const char D_800B813C[], D_800B8150[], D_800B8160[], D_800B8170[], D_800B8188[], D_800B819C[], D_800B81B0[], D_800B81C0[], D_800B81D4[], D_800B81E8[], D_800B81FC[];
EXTERN_C void func_80054B98(void*);
EXTERN_C void func_80053928(void*);
EXTERN_C void func_80053FB0(void*, s32, s32);
EXTERN_C void func_80055020(void*, Unk800C10BCP);
EXTERN_C void func_8005408C(void*, s32);
EXTERN_C Unk800C8E64* func_800C8E64(Unk800C8E64*, s32);
//@keep D_800B813C
//@keep D_800B8150
//@keep D_800B8160
//@keep D_800B8170
//@keep D_800B8188
//@keep D_800B819C
//@keep D_800B81B0
//@keep D_800B81C0
//@keep D_800B81D4
//@keep D_800B81E8
//@keep D_800B81FC
//@func
EXTERN_C Unk800C6624* func_800C6624(Unk800C6624* self, s32 in_chrg, s32 a) {
  Unk800C5380T vt;
  char* full; int adj;
  if (in_chrg) {
    self->x50 = &self->x614;
    Unk800C5380V* v = self->x50;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_800630BC(self, 0, 3);
  self->x50->vptr = &D_800B8214;
  if (!in_chrg) {
    vt = D_800B8214;
    self->x50->vptr = &vt;
    vt.e[1].delta = D_800B8214.e[1].delta + (adj = (char*)self - (full = (char*)self->x50 - 0x614));
    vt.e[6].delta = D_800B8214.e[6].delta + adj;
  }
  self->x54 = D_800B8284; self->x58 = D_800B8264; self->x18 = D_800B82B4;
  self->x68 = 0;
  { Unk800C6624E* q = self->x74; s32 n = 7; do { func_80054B98(q); q++; } while (--n != -1); }
  { Unk800C6624S* q = self->x2F4; s32 n = 7; do { func_80053928(q); q++; } while (--n != -1); }
  { Unk800C6624S* q = self->x3D4; s32 n = 7; do { func_80053928(q); q++; } while (--n != -1); }
  self->x4BC = 0;
  self->x4C0 = 0;
  func_80054AF0(self->x4C4, 1);
  func_80053928(self->x514);
  func_800538CC(self->x530, (void*)D_800B813C, 8);
  func_800538CC(self->x54C, (void*)D_800B8150, 6);
  func_800C8E64((Unk800C8E64*)self->x568, 1);
  if (D_800CBAC8[0] == 0) {
    Unk800C5B80A t;
    D_800CBAC8[0] = 1;
    func_8005F238(&t);
    func_8005F298(&t, 0x14349, 0x2000);
    func_80060588(D_800B4DD0[0], func_8005F28C(&t));
    func_8005F3E0(&t);
    func_8005F248(&t, 2);
  }
  self->x6C = a;
  self->x610 = 0;
  self->x4B4 = 0;
  self->x4B8 = 0;
  func_80053BCC(self, (void*)D_800B8160, 7);
  func_80053C6C(self->x514, self);
  func_8005457C(self->x514, 0);
  func_80053FB0(self->x514, 0, 0x130);
  func_80054E18(self->x4C4, self->x514);
  {
    u32 i = 0;
    Unk800C10BCP t;
    Unk800C10BCP* tp = &t;
    t.x = 8; tp->y = 0xC;
    func_80055020(self->x4C4, t);
    func_80054EB4(self->x4C4, 0x130, 0x10);
    while (1) {
      if (!(i < 4)) break;
      func_80054EB4(&self->x74[i], 0x64, 0x16);
      t.y = 0x86 + i * 0x18; t.x = 0xD2;
      func_80053F48(&self->x74[i], t);
      func_8005408C(&self->x2F4[i], 2);
      tp->y = 4; t.x = 0x60;
      func_80053F48(&self->x2F4[i], t);
      func_80054E18(&self->x74[i], &self->x2F4[i]);
      func_80054EB4(&self->x74[i + 4], 0x68, 0x16);
      t.y = 0x1E + i * 0x18; t.x = 0xD0;
      func_80053F48(&self->x74[i + 4], t);
      func_8005408C(&self->x2F4[i + 4], 2);
      t.x = 0x60; tp->y = 4;
      func_80053F48(&self->x2F4[i + 4], t);
      func_80054E18(&self->x74[i + 4], &self->x2F4[i + 4]);
      i++;
    }
  }
  {
    func_80053BCC(self->x3D4[0].d, (void*)D_800B8170, 10);
    func_80053BCC(self->x3D4[1].d, (void*)D_800B8188, 9);
    func_80053BCC(self->x3D4[2].d, (void*)D_800B819C, 9);
    func_80053BCC(self->x3D4[3].d, (void*)D_800B81B0, 7);
    func_80053BCC(self->x3D4[4].d, (void*)D_800B81C0, 8);
    func_80053BCC(self->x3D4[5].d, (void*)D_800B81D4, 8);
    func_80053BCC(self->x3D4[6].d, (void*)D_800B81E8, 8);
    func_80053BCC(self->x3D4[7].d, (void*)D_800B81FC, 9);
    func_80054EB4(self, 0x54, 0x21);
    Unk800C10BCP t;
    Unk800C10BCP* tp = &t;
    t.x = 9; tp->y = 2;
    func_80053F48(self->x54C, t);
    t.x = 9; tp->y = 0xF;
    func_80053F48(self->x530, t);
    func_80054E18(self, self->x54C);
    func_80054E18(self, self->x530);
  }
  return self;
}
