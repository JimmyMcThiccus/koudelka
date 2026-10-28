// func_800BE990: NOT MATCHING. 90 differ: right size (584 bytes); ours hoists three vtable constants into s5-s7, retail only two.
#include "common.h"
#include "battle/battle.h"
struct T_BE990 { int pad0; T_BDEDC_o *f4; T_BA5FC_o *arr[7]; short s24, s26; int f28; void *f2C; };
EXTERN_C void func_80024CA0(void *p, void *a, short b, short c);
//@ func_800BE990 a
EXTERN_C void func_800BE990(T_BE990 *p, unsigned char *d) {
    p->s26 = (signed char)d[1];
    p->s24 = (signed char)d[0];
    d += 4;
    for (int i = 0; i < p->s26; i++) {
        d += 0xC;
        T_BA5FC_o *o = (T_BA5FC_o *)operator new(0x20C);
        o->vtbl = D_80010178;
        o->f4 = 0;
        o->vtbl = D_800106EC;
        o->s8 = 0;
        o->sA = 0;
        o->vtbl = D_80010624;
        func_80021F48(o, (int)d);
        p->arr[i] = o;
        D_800B4C38[0]->v1(o);
        d += 0x200;
    }
    d += 8;
    unsigned short h0 = *(unsigned short *)d;
    d += 2;
    unsigned short h1 = *(unsigned short *)d;
    d += 2;
    T_BDEDC_o *q = (T_BDEDC_o *)operator new(0x20);
    *(VTable **)q = D_80010178;
    q->f4 = 0;
    q->vtbl8 = D_80010888;
    *(VTable **)q = D_800108A0;
    q->fC = p->arr[0];
    SVec2C t(-1, -1);
    q->f10 = t;
    q->s14 = 0;
    q->s16 = 0;
    q->f18 = 0;
    q->s1E = 0;
    p->f4 = q;
    func_80024CA0(q, d, h0 << 1, h1);
    func_80025444(D_800B4C48, p->f4, 3);
    func_8001ED2C(D_800B4C18[0], 1, 3);
    func_800766D8(p->f2C);
    void *r = func_800787B4();
    char *n = func_8001CA10(0x14);
    *(VTable **)n = D_80010178;
    *(VTable **)n = D_80010300;
    ((short *)n)[4] = 2;
    ((short *)n)[5] = 0xA;
    *(int *)(n + 0x10) = 4;
    *(int *)(n + 4) = 0;
    *(int *)(n + 0xC) = 0;
    *(VTable **)n = D_800102D0;
    func_8001EFE4(r, n);
}
