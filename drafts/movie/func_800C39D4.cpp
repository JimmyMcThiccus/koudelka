// 13 differ: only r/k swap registers (retail r=s2,k=s3); global-alloc priorities r 10 refs/70 insns vs k 7/32 are nearly tied
#include "movie/movie.h"
struct Unk800C39D4 { char pad[0x30]; s32 x30, x34, x38, x3C; };
EXTERN_C s32 _card_info(s32);
EXTERN_C s32 _card_clear(s32);
EXTERN_C s32 _card_load(s32);
EXTERN_C s32 func_800C3F68(Unk800C3F68* p);
//@func
EXTERN_C s32 func_800C39D4(Unk800C39D4* p) {
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
  while (!_card_load(p->x38 + p->x3C)) {
    Unk800C3F68E* e = func_8001ED2C(D_800B4C18[0], 2, 1);
    if (e) { if (e->xA == 4 && e->xC) e->xC->v1(3); e->v2(); }
    if (k < 0) goto fail;
    k--;
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
