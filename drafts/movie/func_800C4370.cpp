// func_800C4370: 8 differ: retail schedules y=4 (s7) after &t/s5 in the loop pre-header (here first), and loads the 0x6E/0x8E x-consts into v0 inside the loop (here v1). Writing y as a giv (i*13+4) fixes the order but swaps p/y between fp and s7.
#include "movie/movie.h"
struct Unk800C4370 { char p0[0x18]; const void* x18; char p1[0x50 - 0x1C]; s32 x50; char p3[0x78 - 0x54]; s32 x78, x7C; s8 x80; u8 x81; s8 x82; char p4;
  Unk800C49BCA x84[3]; Unk800C49BCB xD8[3]; Unk800C49BCB x150, x178, x1A0; Unk800C49BCA x1C8, x1E4, x200, x21C, x238; };
EXTERN_C char D_800B7DEC[], D_800B7D60[], D_800B7D64[];
EXTERN_C void func_80053928(void*);
EXTERN_C void func_8005464C(void*);
EXTERN_C void func_80054584(void*, s32);
EXTERN_C void func_8005408C(void*, s32);
//@keep D_800B7D60
//@keep D_800B7D64
//@func
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
  u32 i; s32 y;
  for (i = 0, y = 4; i < 3; i++, y += 13) {
    func_80053BCC(&p->x84[i], D_800B7D64, 2);
    Unk800C10BC_set(&t, 0x6E, y); func_80053F48(&p->x84[i], t);
    func_8005408C(&p->xD8[i], 2);
    Unk800C10BC_set(&t, 0x8E, y); func_80053F48(&p->xD8[i], t);
  }
  return p;
}
