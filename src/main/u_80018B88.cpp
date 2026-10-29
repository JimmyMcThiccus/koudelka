#include "common.h"
#define EXE_H_IN_u_80018B88
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_80018B88.h"

EXTERN_C void func_80018B88()
{
    S_Block *b = &D_800EA8A0;
    D_800B4EE8 = b;
    D_800EA8A0.next = 0;
    b->size = (D_800B4C08 - 0x7FF80000 - (int)b) & ~7;
    D_800B4EEC = (char *)b + b->size;
    func_8001ACB4();
}

EXTERN_C void func_80018BE4(S_Block *b)
{
    S_Block *n = (S_Block *)((char *)b + b->size);
    if (n == b->next) {
        b->size += n->size;
        b->next = b->next->next;
    }
}

EXTERN_C void func_80018C1C(void *p)
{
    S_Block *prev = (S_Block *)&D_800B4EE8;
    S_Block *b = (S_Block *)p - 1;
    S_Block *c = D_800B4EE8;
    if (c) {
        do {
            if (b < c) {
                link_80018C1C(b, c);
                link_80018C1C(prev, b);
                return;
            }
            prev = c;
            c = prev->next;
        } while (c);
    }
    b->next = 0;
    link_80018C1C(prev, b);
}

EXTERN_C void *func_80018C90(unsigned int size)
{
  S_Block *best = 0;
  S_Block *prev;
  S_Block *c;
  size = ((size + 7) >> 3) + 1;
  size = size << 3;
  prev = D_800B4EE8;
  for (c = prev->next; c; prev = c, c = c->next)
  {
    if ((c->size >= size) && ((!best) || (c->size < best->size)))
    {
      best = c;
      if (size == c->size)
      {
        prev->next = c->next;
        return c + 1;
      }
    }
  }

  if (!best)
  {
    best = D_800B4EE8;
    if (size > best->size)
    {
      return 0;
    }
    if (best->size == size)
    {
      D_800B4EE8 = best->next;
      return best + 1;
    }
    if (!best)
    {
      return 0;
    }
  }
  best->size -= size;
  best = (S_Block *) (((char *) best) + best->size);
  best->size = size;
  c = best;
  return c + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018D80);

EXTERN_C int func_80018DF4(int *p)
{
    return p ? p[-1] - 8 : 0;
}

EXTERN_C unsigned int func_80018E10(int *count)
{
    S_Block *c = D_800B4EE8;
    int n = 0;
    unsigned int max = n;
    while (c) {
        n++;
        if (max < c->size)
            max = c->size;
        c = c->next;
    }
    if (count)
        *count = n;
    return max;
}

EXTERN_C S_80018E5C *func_80018E5C(S_80018E5C *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800100C0;
    p->unk88 = 0;
    p->unk8 = a;
    return p;
}

EXTERN_C void func_80018E88(S_80018E5C *p, int flags)
{
    p->vtbl = D_800100C0;
    if (p->unk88)
        func_800A0D0C((void *)p->unk88);
    func_8001A610(p, flags);
}

EXTERN_C void func_80018EDC(S_80018E5C *p)
{
    p->unk88 = (int)func_800A0D2C(p->unk8 * 4);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018F0C);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018FA8);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_800190A0);

EXTERN_C int func_8001914C(S_8001914C *p)
{
    return p->unk4;
}

EXTERN_C S_800A4534 *func_80019158(S_800A4534 *v)
{
    S_80019158 *p = (S_80019158 *)v;
    S_Holder24 *h = &p->h;
    p->vt = D_800100D0;
    p->m10.vt = D_80010328;
    p->m18.vt = D_80010328;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->m10.ptr = 0;
    p->m18.ptr = 0;
    p->unk20 = 0;
    h->unk8 = &p->list;
    p->h.vb = &p->list;
    func_800198E0(h->unk8, 16, 0);
    h->unk4 = 0;
    p->unk44 = 0;
    S_Array *l = h ? h->vb : 0;
    func_80019A6C(l, (int)p, l->count);
    return v;
}

EXTERN_C void func_800191FC()
{
    D_800A4534.unkC++;
}

EXTERN_C void func_8001921C(S_8001921C *p)
{
    delete p->unk8;
    p->unk8 = p->unk4;
    p->unk4 = 0;
}

EXTERN_C S_Link *func_80019274(S_Link *p, S_Link *a)
{
    if (p->next)
        func_8001A678(a, (int)p->next);
    p->next = a;
    return a;
}

EXTERN_C void func_800192C0()
{
    S_80019158 *p = (S_80019158 *)&D_800A4534;
    p->vt = D_800100D0;
    if (&p->h == D_800B4C34)
        D_800B4C34 = 0;
    func_80019920((List *)p->h.vb, 0);
    func_8001DF58(&p->unk20, 2);
    own_dtor_80019158(&p->m18);
    own_dtor_80019158(&p->m10);
}

EXTERN_C S_80019158 *func_800193AC(S_80019158 *p, S_80019158 *q)
{
    p->vt = D_800100D0;
    p->unk4 = q->unk4;
    p->unk8 = q->unk8;
    p->unkC = q->unkC;
    p->m10.vt = D_80010328;
    p->m10.ptr = q->m10.ptr;
    p->m18.vt = D_80010328;
    p->m18.ptr = q->m18.ptr;
    p->unk20 = q->unk20;
    S_Holder24 *h = &p->h;
    h->unk8 = &p->list;
    p->h.vb = &p->list;
    S_Holder24 *qh = &q->h;
    *h->unk8 = *(qh ? qh->vb : 0);
    h->unk4 = qh->unk4;
    p->unk44 = q->unk44;
    return p;
}

EXTERN_C void func_80019478()
{
    func_80019158(&D_800A4534);
}
