// func_800B9DB4: 23 differing: only p/q register swap (retail p=$s0, q=$s1); loop + v0 store copy match. q has 6 refs vs p 5 so global alloc gives q $s0.
#include "movie/movie.h"
EXTERN_C void func_80027FEC(void*, void*);
struct Unk800B9DB4M { s32 v[6]; };
struct Unk800B9DB4 { char pad[0xC]; Unk800B9DB4M xC[2]; RECT x3C; RECT x44; };
inline Unk800B9DB4* base(Unk800B9DB4* self, Unk800B9DB4* out) { func_80027FEC(self, out); Unk800B9DB4M* d = out->xC; s32 i = 1; Unk800B9DB4M* s = self->xC; do { *d = *s; d++; s++; i--; } while (i != -1); return out; }
//@func
EXTERN_C Unk800B9DB4* func_800B9DB4(Unk800B9DB4* p, Unk800B9DB4* q) { base(p, q); q->x3C = p->x3C; q->x44 = p->x44; return q; }
