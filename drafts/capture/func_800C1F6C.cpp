// func_800C1F6C: register roles of source/destination pointers swapped vs retail (retail keeps src in a1, dst = p->list in a3).
#include "common.h"
#include "capture/capture.h"

EXTERN_C void func_800C1F6C(S_800C1F6C *p, Rec8 *s)
{
    short n = p->n;
    Rec8 *d = p->list;
    while (n) {
        d->a = s->a;
        d->b = s->b;
        d->c = s->c;
        d->d = s->d;
        d->e = s->e;
        d->f = s->f;
        n--;
        s++;
        d++;
    }
}
