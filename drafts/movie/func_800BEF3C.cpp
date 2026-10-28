// func_800BEF3C: 25 differ, all in one spot: the s1 = 0 init of the 15-element func_800C46B8 loop (goto loop, so no strength reduction, as retail) is scheduled up past the func_80062848/func_80053CD8 calls (retail keeps it after the 2nd func_80053CD8), and i++ lands before the address chain instead of after. Everything else matches. Declares func_800C4370 as void*(void*) (its own draft is not landed).
#include "movie/movie.h"
struct Unk800BEF3CTE { s16 delta; s16 index; void (*pfn)(); };
struct Unk800BEF3CT { Unk800BEF3CTE e[10]; };
struct Unk800BEF3CV { const void* vptr; s32 x4; };
struct Unk800BEF3CE { char d[0x254]; };
struct Unk800BEF3CO { const void* x0; const void* x4; void* x8; s16 xC, xE, x10, x12; };
struct Unk800BEF3C { char p0[0x18 - 0x0]; const void* x18; char p1[0x50 - 0x1C]; Unk800BEF3CV* x50; const void* x54; const void* x58; char p2[0x68 - 0x5C]; s32 x68; s32 x6C; s32 x70; s32 x74; s32 x78; char x7C[0x50]; char xCC[0x1C]; char xE8[0x1C]; char x104[0x1C]; char x120[0x1C]; char x13C[0x28]; char x164[0x28]; s32 x18C; s32 x190; char x194[0x5C]; char x1F0[0x50]; char x240[0x1C]; char x25C[0x1C]; Unk800BEF3CE x278[15]; s32 x2564; char x2568[0x60]; s32 x25C8; char p3[0x25D8 - 0x25CC]; char x25D8[0x5C]; s32 x2634; s32 x2638; char p4[0x26BC - 0x263C]; char x26BC[0x6C]; char x2728[0x5C]; s32 x2784; char p5[0x27A0 - 0x2788]; char x27A0[0x5C]; s32 x27FC; char p6[0x2818 - 0x2800]; void* x2818; Unk800BEF3CV x281C; };
EXTERN_C const Unk800BEF3CT D_800B7BF4;
EXTERN_C char D_800B7BC4[], D_800B7C44[], D_800B7C64[], D_800B776C[], D_800B7778[], D_800B77A0[], D_800B77B0[], D_800104A8[], D_800101C0[], D_800101B0[];
EXTERN_C void* D_800B4D60[];
EXTERN_C void func_80053928(void*);
EXTERN_C void func_80054584(void*, s32);
EXTERN_C void func_8005408C(void*, s32);
EXTERN_C void* func_800C4370(void*);
EXTERN_C void func_800C46B8(Unk800C46B8*, u32);
EXTERN_C Unk800C5380* func_800C5380(Unk800C5380*, s32, s32);
EXTERN_C Unk800C595C* func_800C595C(Unk800C595C*, s32, Unk800C595CR*);
EXTERN_C void func_80062C3C(void*, s32, void*, s32, s32);
EXTERN_C void* func_80062848(void*, s32, void*, void*, s32, s32);
inline Unk800BEF3CO* Unk800BEF3C_ctor(Unk800BEF3CO* o, void* q, s16 c, s16 e, s16 g, s16 h) { o->x0 = D_800100F8; o->x4 = D_800101C0; o->x0 = D_800101B0; o->xC = c; o->xE = e; o->x10 = g; o->x12 = h; o->x8 = q; return o; }
inline void Unk800BEF3C_b(Unk800BEF3CO* o) { o->x0 = D_800100F8; o->x4 = D_800101C0; o->x0 = D_800101B0; }
inline Unk800BEF3CO* Unk800BEF3C_ctor2(Unk800BEF3CO* o, void* q, s16 c, s16 e, s16 g, s16 h) { Unk800BEF3C_b(o); o->xC = c; o->xE = e; o->x10 = g; o->x12 = h; o->x8 = q; return o; }
//@keep D_800B776C
//@func
EXTERN_C Unk800BEF3C* func_800BEF3C(Unk800BEF3C* p, s32 in_chrg, s32 a) {
  Unk800BEF3CT vt;
  Unk800C595CR r;
  Unk800C10BCP t;
  if (in_chrg) {
    p->x50 = &p->x281C;
    Unk800BEF3CV* v = p->x50;
    v->vptr = D_80010178; v->x4 = 0; v->vptr = D_800104A8;
  }
  func_800630BC(p, 0, 0x10);
  p->x50->vptr = &D_800B7BF4;
  if (!in_chrg) {
    vt = D_800B7BF4;
    p->x50->vptr = &vt;
    char* full; s32 adj;
    vt.e[1].delta = D_800B7BF4.e[1].delta + (adj = (char*)p - (full = (char*)p->x50 - 0x281C));
    vt.e[6].delta = D_800B7BF4.e[6].delta + adj;
  }
  p->x54 = D_800B7BC4; p->x58 = D_800B7C44; p->x18 = D_800B7C64;
  p->x68 = 0x1AA0; p->x6C = 0; p->x74 = 0;
  func_80054AF0(p->x7C, 2);
  func_800538CC(p->xCC, D_800B776C, 4);
  func_800538CC(p->xE8, D_800B7778, 0x12);
  func_80053928(p->x104); func_80053928(p->x120);
  func_80054584(p->x13C, 1); func_80054584(p->x164, 1);
  p->x18C = 0; p->x190 = 0;
  Unk800C10BC_set(&r.xy, 0x58, 0x5C); r.w = 0x90; r.h = 0xC;
  func_800C595C((Unk800C595C*)p->x194, 0xF, &r);
  func_80054AF0(p->x1F0, 1);
  func_80053928(p->x240); func_80053928(p->x25C);
  { Unk800BEF3CE* e = p->x278; s32 n = 14; do { func_800C4370(e); e++; } while (--n != -1); }
  func_800630BC(p->x2568, 1, 3);
  func_800C5380((Unk800C5380*)p->x25D8, 1, (s32)p);
  func_80062C3C(p->x26BC, 1, D_800B77A0, 2, 0);
  func_80062848(p->x2728, 1, D_800B77B0, D_800B4D60[0], 5, 0);
  func_80062848(p->x27A0, 1, D_800B776C, D_800B4D60[0], 7, 0);
  func_80053CD8(p->x104); func_80053CD8(p->x120);
  p->x70 = a;
  u32 i = 0;
  loop: { Unk800BEF3CE* e = &p->x278[i]; i++; func_800C46B8((Unk800C46B8*)e, i); func_80054E18(p, e); } if (i < 15) goto loop;
  p->x78 = 0; p->x2564 = 0;
  Unk800C10BC_set(&t, 0x10, 0); func_80053F48(p->xCC, t);
  func_8005408C(p->xE8, 2);
  Unk800C10BC_set(&t, 0x12C, 0xE); func_80053F48(p->xE8, t);
  func_800C1AE0((Unk800C11A0*)p, 0);
  Unk800C10BC_set(&t, 0x60, 0); func_80053F48(p->x104, t);
  Unk800C10BC_set(&t, 0x8A, 0); func_80053F48(p->x13C, t);
  Unk800C10BC_set(&t, 0xB0, 0); func_80053F48(p->x120, t);
  Unk800C10BC_set(&t, 0xD2, 0); func_80053F48(p->x164, t);
  func_80054E18(p->x7C, p->xCC); func_80054E18(p->x7C, p->xE8); func_80054E18(p->x7C, p->x104);
  func_80054E18(p->x7C, p->x13C); func_80054E18(p->x7C, p->x120); func_80054E18(p->x7C, p->x164);
  func_80054EB4(p->x7C, 0x130, 0x1C);
  Unk800C10BC_set(&t, 8, 0x1A); func_80053F48(p->x7C, t);
  Unk800C10BC_set(&t, 4, 0x11); func_80053F48(p->x25C, t);
  func_80054E18(p->x1F0, p->x240); func_80054E18(p->x1F0, p->x25C);
  func_80054EB4(p->x1F0, 0x130, 0x22);
  Unk800C10BC_set(&t, 8, 0x70); func_80053F48(p->x1F0, t);
  p->x2784 = 2;
  func_80054E18(p->x2568, p->x2728); func_80054E18(p->x2568, p->x26BC);
  p->x27FC = 2;
  func_80054EB4(p->x25D8, 0x6E, 0x22);
  Unk800C10BC_set(&t, 0x69, 0x78); func_80053F48(p->x25D8, t);
  func_80054E18(p->x25D8, p->x27A0); func_80054E18(p->x25D8, p->x26BC);
  p->x2634 = -1; p->x2638 = 2; p->x25C8 = 2;
  func_80054EB4(p->x2568, 0x4F, 0x22);
  Unk800BEF3CO* o = (Unk800BEF3CO*)operator new(0x14);
  o->x0 = D_800100F8; o->x4 = D_800101C0; o->x0 = D_800101B0;
  o->xC = 3; o->xE = 4; o->x8 = D_800B4D60[0]; o->x10 = 7; o->x12 = 2;
  p->x2818 = o;
  return p;
}
