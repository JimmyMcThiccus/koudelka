// func_800C0DA4: matches in try_compile, but GCC aligns its switch jump table to 8 bytes and retail's
// jtbl_800B7A1C sits at 0x800B7A1C (4 mod 8), so .rodata shifts by 4 in the full build. Needs a build change
// (jump table alignment) before it can land.
#include "movie/movie.h"
struct Unk800C0DA4 { char pad[0x74]; s32 x74; char p2[0x1F0 - 0x78]; char x1F0[4]; };
EXTERN_C const char D_800B7810[], D_800B7814[], D_800B7854[], D_800B792C[];
EXTERN_C void func_800C10BC(Unk800C10BC* p, void* a, s32 b, void* c, s32 d);
EXTERN_C s32 func_80054E90(void*);
EXTERN_C void func_80054CE4(void*);
//@note the jump table is .align 3; the zero word before jtbl_800B7A1C in retail should be its alignment padding (no "" literal needed)
//@keep D_800B7810
//@keep D_800B7814
//@keep D_800B7854
//@keep D_800B792C
//@func
EXTERN_C void func_800C0DA4(Unk800C0DA4* p, s32 n) {
  switch (n) {
  case 7: p->x74 = 0; func_800C10BC((Unk800C10BC*)p, (void*)D_800B792C, 0x1C, (void*)D_800B7810, 0); break;
  case 4: func_800C10BC((Unk800C10BC*)p, "MDEDMDODBEIE@BCDADBEDD@BIFCG@BEGNFFFOFBGMFAFDGDGEFDFNB", 0x1B, (void*)D_800B7810, 0); break;
  case 1: p->x74 = 0; func_800C10BC((Unk800C10BC*)p, (void*)D_800B7854, 0x18, (void*)D_800B7810, 0); break;
  case 3: p->x74 = 0; func_800C10BC((Unk800C10BC*)p, (void*)D_800B7814, 0x1E, (void*)D_800B7810, 0); break;
  case -1: case 0: case 2: case 5: case 6:
  default: p->x74 = 0; func_800C10BC((Unk800C10BC*)p, "EENFAFBFLFEF@BDGOF@BLFOFAFDFNB", 0xF, (void*)D_800B7810, 0); break;
  }
  void* o = p->x1F0;
  if (func_80054E90(o)) func_80054CE4(o); else func_80054FC0(o);
}
