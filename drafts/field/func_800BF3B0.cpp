// func_800BF3B0: 29 differing: retail keeps the source pointer a1 as its own IV and the dest in a3; the build copies a1 to a3 first. 8-byte element copy loop.
#include "field/field.h"

struct Unk_E8_F3B0 { unsigned char a, b, c, d; unsigned short e, f; };
struct Unk_800BF3B0 { char pad0[0x14]; short unk14; char pad16[2]; Unk_E8_F3B0* unk18; };

#define p ((Unk_800BF3B0*)vp)
EXTERN_C void func_800BF3B0(void* vp, Unk_E8_F3B0* s) {
    Unk_E8_F3B0* d = p->unk18;
    short n = p->unk14;
    while (n != 0) {
        d->a = s->a;
        d->b = s->b;
        d->c = s->c;
        d->d = s->d;
        d->e = s->e;
        d->f = s->f;
        d++;
        s++;
        n--;
    }
}
#undef p
