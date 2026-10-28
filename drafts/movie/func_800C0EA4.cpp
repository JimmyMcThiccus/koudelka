// func_800C0EA4: matches in try_compile (0 differing), but its switch jump table jtbl_800B7A7C is at 4 mod 8 and GCC
// emits '.align 3' before jump tables, so .rodata shifts by 4 in the full build. Also convert its string literal to D_800B7A40.
#include "movie/movie.h"
struct Unk800C0EA4V { char pad[0x18]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C0EA4O { virtual void v1(); virtual void v2(); virtual void v3(); };
struct Unk800C0EA4 : Unk800C0EA4V { char p1[0x6C - 0x1C]; s32 x6C; char p2[0x78 - 0x70]; Unk800C0EA4O* x78; char x7C[0xE8 - 0x7C]; char xE8[0x18C - 0xE8]; s32 x18C; char p3[0x1F0 - 0x190]; char x1F0[0x25D8 - 0x1F0]; char x25D8[0x25F8 - 0x25D8]; s32 x25F8; char p4[0x2718 - 0x25FC]; s32 x2718; };
EXTERN_C s32 func_80063744(void*, s32);
EXTERN_C void func_80060588(void*, s32);
EXTERN_C void func_800C16C8(Unk800C0EA4*);
EXTERN_C void func_800C02D8(Unk800C0EA4*);
EXTERN_C void func_800C1278(Unk800C0EA4*);
EXTERN_C void func_800C06BC(Unk800C0EA4*);
EXTERN_C void func_800C10BC(Unk800C10BC* p, void* a, s32 b, void* c, s32 d);
EXTERN_C void func_80054CE4(void*);
EXTERN_C const char D_800B7810[];
//@note p has a vptr at 0x18 (Unk800C0EA4V); declares func_800C16C8/func_800C02D8/func_800C1278/func_800C06BC taking Unk800C0EA4* -- if those land with other param types, cast here instead
//@keep D_800B7810
//@func
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
    func_800C10BC((Unk800C10BC*)p, "MDEDMDODBEIE@BCDADBEDD@BHFAFCG@BBFEFEFNF@BBGEFMFOFFGEFDFNB", 0x1D, (void*)D_800B7810, 0);
    func_80054CE4(p->x1F0);
    break;
  case 5:
    func_80055330(0);
    func_800C02D8(p);
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
