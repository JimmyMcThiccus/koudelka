// func_800C1278: 247 differing but structurally only: retail keeps a separate hoisted const 4 ($s2) for the retry loop, here loop.c merges it with the switch's 4 (combine_movables), which drops $fp and renumbers s2..s7 everywhere. Control flow, calls and the r%2 tests already match (sdiff.py shows ~20 small hunks).
#include "movie/movie.h"
struct Unk800C1278 { char pad[0x78]; void* x78; char x7C[0xE8 - 0x7C]; char xE8[0x18C - 0xE8]; s32 x18C, x190; char p1[0x1F0 - 0x194]; char x1F0[0x26BC - 0x1F0]; char x26BC[0x2718 - 0x26BC]; s32 x2718; };
EXTERN_C char D_800B7778[], D_800B77A0[], D_800B7AA0[], D_800B7AD4[];
EXTERN_C s32 func_800C39D4(void*);
EXTERN_C s32 func_800C3D50(Unk800C3D50*);
EXTERN_C void func_800C0DA4(void*, s32);
inline void Unk800C1278_retry(Unk800C1278* p) { for (u32 j = 0; j < 10; ) { j++; s32 w = func_800C3674(p->x78); p->x190 = w; if (w != 4) break; } }
//@keep D_800B7AA0
//@keep D_800B7AD4
//@func
EXTERN_C void func_800C1278(Unk800C1278* p) {
  func_800C10BC((Unk800C10BC*)p, D_800B7AA0, 0x18, (void*)D_800B7810, 0);
  func_80054FC0(p->x1F0);
  for (u32 i = 0; i < 8; i++) func_8005556C(2, 1);
  s32 r = 0;
  u32 b = (u32)func_800C3D50((Unk800C3D50*)p->x78) >> 4;
  u32 k, s;
  for (k = 1, s = b + k; ; k++, s++) {
    if (!(k < 2)) break;
    if (r) goto done;
    if (s % 2 == 1) { func_80053BCC(p->xE8, D_800B7778, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0); }
    else { func_80053BCC(p->xE8, D_800B7AD4, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0x10); }
    func_80054CE4(p->x7C);
    s32 v = p->x190 = func_800C39D4(p->x78);
    switch (v) {
    case 0: case 3: if (s % 2 == 1) r += 1; else r += 2; break;
    case 4: Unk800C1278_retry(p);
      if (p->x190 != 4) p->x190 = -1;
      r = -1; break;
    case -1: r = -1; break;
    }
    func_8005556C(2, 1);
  }
  if (r) goto done;
  for (k = 1, s = b + k; ; k++, s++) {
    if (!(k < 2)) break;
    if (r) break;
    if (s % 2 == 1) { func_80053BCC(p->xE8, D_800B7778, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0); }
    else { func_80053BCC(p->xE8, D_800B7AD4, 0x12); func_800C3D5C((Unk800C3D5C*)p->x78, 0x10); }
    func_80054CE4(p->x7C);
    s32 v = p->x190 = func_800C3674(p->x78);
    switch (v) {
    case 0: case 3: if (s % 2 == 1) r += 1; else r += 2; break;
    case 4: Unk800C1278_retry(p);
      if (p->x190 != 4) p->x190 = -1;
      r = -1; break;
    case -1: r = -1; break;
    }
  }
  func_8005556C(2, 1);
done:
  if (r <= 0) {
    if (r == 0) { func_800C3D5C((Unk800C3D5C*)p->x78, 0); func_80054CE4(p->x7C); }
    func_800C0DA4(p, p->x190);
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

