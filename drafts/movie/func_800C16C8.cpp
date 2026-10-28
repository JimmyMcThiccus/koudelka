// blocked by jtbl alignment; also 1 differ: addu $s0 operand order in the dest-pointer add (retail s1+s0)
#include "movie/movie.h"
struct Unk800C16C8C { s32 d[0x14]; };
struct Unk800C16C8R { char p0[3]; u8 x3; char p1[0x18 - 4]; Unk800C16C8C x18; char p2[0x94 - 0x18 - 0x50]; };
struct Unk800C16C8G { char pad[0x202]; s8 x202, x203; char p2[0x23C - 0x204]; Unk800C16C8R x23C[1]; };
struct Unk800C16C8O { char d[0xA0]; };
EXTERN_C void func_800C1690(void* p, s32* a, s32* b, s32* c, s32* d);
EXTERN_C void func_80062610(Unk800C16C8O*);
EXTERN_C void func_80062764(Unk800C16C8O*, s32);
EXTERN_C s32 func_800619F4(void*);
EXTERN_C void func_800627E8(Unk800C16C8O*, s32);
EXTERN_C char* func_80062834(Unk800C16C8O*);
EXTERN_C void func_800C1BF8(void*);
EXTERN_C void func_800C21B8(void*);
EXTERN_C s32 func_800382A4(void*, s32, s32);
EXTERN_C char D_800AC86C[];
//@func
EXTERN_C void func_800C16C8(void* p) {
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
  Unk800C16C8O o;
  func_80062610(&o);
  s32 i;
  i = func_800619F4(D_800B4DD0[0]) - 1;
  if (i >= 0) do {
    func_800627E8(&o, ((u8*)D_800B4DD0[0])[i * 0x94 + 0x23F]);
    Unk800C16C8C* d = (Unk800C16C8C*)(i * 0x94 + (char*)D_800B4DD0[0] + 0x254);
    *d = *(Unk800C16C8C*)(func_80062834(&o) + 0x3C);
  } while (--i >= 0);
  func_800C1BF8(p);
  func_800C21B8(p);
  while (func_800382A4(D_800AC86C, ((Unk800C16C8G*)D_800B4DD0[0])->x202, 0));
  func_80062764(&o, 2);
}
