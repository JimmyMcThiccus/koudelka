#include "common.h"
#include "capture/capture.h"

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B758C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B76E4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7728);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B77D8);

EXTERN_C int D_800B1A5C[];
EXTERN_C void func_800B7B28(unsigned char *p)
{
    if (D_800B1A5C[0]) {
        if (!(*(unsigned short *)p & 0x400)) {
            int c = p[0x49];
            if (c != p[0x48]) {
                c++;
                if (c >= 4)
                    c = 0;
                p[0x49] = c;
            }
        }
        *(unsigned short *)p &= ~0x400;
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7B90);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7C34);

EXTERN_C int D_800B1A5C[];
EXTERN_C void func_800B7DFC(short *p)
{
    *p = 0;
    D_800B1A5C[0] = 0;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7E0C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7E6C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7F10);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8048);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B815C);

EXTERN_C char *func_800B8280(char *p, int v)
{
    char *a = *(char **)(p + 0x124);
    *(int *)(a + 0x1C) = v;
    a[0x6A1] = 3;
    a = *(char **)(p + 0x128);
    *(int *)(a + 0x1C) = v;
    a[0x6A1] = 3;
    return *(char **)(p + 0x124);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B82AC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8360);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8434);

EXTERN_C void func_800B8488(char *p, short a, char b)
{
    *(short *)(p + 0) = a;
    p[2] = b;
    *(short *)(p + 4) = 0x400;
    *(short *)(p + 6) = 0;
    *(short *)(p + 0xC) = 0;
    *(short *)(p + 0xE) = 0;
    *(short *)(p + 0x16) = 0;
    p[0x24] = 1;
    p[0x25] = 3;
    p[0x26] = 3;
    p[0x27] = 0;
    p[0x28] = 0xF;
    p[0x29] = 0x7F;
    p[0x2A] = 6;
    p[0x2B] = 0xF;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B84E0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B85B8);

EXTERN_C void func_800B85EC(VObject *p)
{
    if (((int *)p)[3] == ((int *)p)[1]) {
        VtblEntry *e = &p->vt[7];
        ((void (*)(void *))e->pfn)((char *)p + e->delta);
        ((int *)p)[3] = 0;
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8640);

EXTERN_C void func_800B86E8() {}

EXTERN_C char D_800B6DF4[];
EXTERN_C void **func_800B86F0(void **p)
{
    p[0] = D_800B6DF4;
    p[2] = 0;
    p[3] = 0;
    return p;
}

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6DF0);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6DF4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B870C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8BDC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8CE8);

EXTERN_C void func_8001AA68(void *, int);
EXTERN_C void func_800B8EB4(char *p)
{
    func_8001AA68(p ? p + 4 : 0, 0);
    *(short *)(p + 0x10) = 1;
}

EXTERN_C void func_8001AB50(void *, int);
EXTERN_C void func_800B8EF0(char *p) { func_8001AB50(p ? p + 4 : 0, 0); }

EXTERN_C void func_800B8F20(char *p) { *(int *)(p + 0x21C) = 1; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8F2C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9020);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B90C0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9288);

EXTERN_C int D_800B4CF0[];
EXTERN_C int func_800B93D8(S_800B93D8 *p) { return p->e[D_800B4CF0[0]].h; }

EXTERN_C int func_800B9400(char *p) { return *(int *)(p + 0x58); }

EXTERN_C void func_800B940C(char *p, int v) { *(int *)(p + 0x58) = v; }

EXTERN_C void func_800B9414(S_800B9414 *p, ShortQuad v) { p->q = v; }

EXTERN_C ShortQuad func_800B9444(S_800B9414 *p) { return p->q; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9470);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B94BC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B94FC);

EXTERN_C void func_8008CD1C(int, int);
EXTERN_C void func_80036110(void *, int);
EXTERN_C void func_800B95C0(void *p, int a)
{
    func_8008CD1C(0, 0);
    func_80036110(p, a);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9604);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B96F8);

EXTERN_C void func_80036674(void *);
EXTERN_C void func_800B998C(VObject *p, unsigned char *in)
{
    if ((in[0] & 0x10) || ((in[0] & 1) && (in[1] & 0x40))) {
        VtblEntry *e = &p->vt[8];
        ((void (*)(void *, int))e->pfn)((char *)p + e->delta, in[0]);
        func_80036674(p);
    } else
        ((char *)p)[0x35] = 2;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9A0C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9AA0);

EXTERN_C int func_800B9C60() { return -1; }

EXTERN_C int func_800B9C68() { return 0; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9C70);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9CF4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B9E10);

EXTERN_C int func_800B9E74(S_800B9E74 *p, int v, int i)
{
    int old = p->slot[i & 0xF];
    p->slot[i & 0xF] = v;
    return old;
}

EXTERN_C void func_800B9E8C(S_800B9E74 *p, int i) { p->slot[i & 0xF] = 0; }

EXTERN_C char *func_800B9EA0(char *p) { return p + 0x7C; }

EXTERN_C char D_800B6F04[];
EXTERN_C char D_800B6F1C[];
EXTERN_C char D_80012294[];
EXTERN_C char D_80012224[];
EXTERN_C void func_80035304(void *, int);
EXTERN_C void func_800B9EA8(char *p, int in_chrg)
{
    *(char **)(p + 8) = D_800B6F04;
    *(char **)p = D_800B6F1C;
    *(char **)(p + 8) = D_80012294;
    *(char **)p = D_80012224;
    func_80035304(p, 0);
    if (in_chrg & 1)
        operator delete(p);
}

EXTERN_C void *func_800A0D2C(int);
S_800BA17C::S_800BA17C(int size, int bits, char *mem)
{
    int n;
    if (!mem)
        base = (char *)func_800A0D2C(size);
    else
        base = mem;
    n = 1 << bits;
    value = (int)base;
    buf = (int *)func_800A0D2C(n * 4);
    mask = n - 1;
    rd = 0;
    wr = 0;
    buf[0] = 0;
    last = mask;
    buf[last] = (int)(base + size);
}

EXTERN_C void func_800A0D0C(void *);
EXTERN_C void func_800B9FCC(void *self, int in_chrg)
{
    void **p = (void **)self;
    if (p[0])
        func_800A0D0C(p[0]);
    if (p[1])
        func_800A0D0C(p[1]);
    if (in_chrg & 1)
        operator delete(p);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA038);

EXTERN_C void func_800BA0E8(S_800BA17C *p)
{
    p->wr = (p->wr + 1) & p->mask;
    p->buf[p->wr] = p->value;
}

EXTERN_C void func_800BA0E8(S_800BA17C *);
EXTERN_C void func_800BA114(S_800BA17C *p)
{
    int v = p->buf[p->wr];
    if (v)
        p->value = v;
    p->buf[p->wr] = 0;
    func_800BA0E8(p);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA168);

EXTERN_C int func_800BA17C(S_800BA17C *p)
{
    int r = 0;
    if (p->rd != p->wr) {
        r = p->buf[p->rd];
        p->rd++;
        p->rd &= p->mask;
    }
    return r;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA1BC);

EXTERN_C char D_800B6DF4[];
EXTERN_C char D_800B6F8C[];
C_800BA258::C_800BA258(int size, int bits, char *mem) : ring(size, bits, mem)
{
    vt = D_800B6F8C;
}

EXTERN_C char D_800B6F8C[];
EXTERN_C void func_800B9FCC(void *, int);
EXTERN_C void func_800BA2A4(char *p, int in_chrg)
{
    *(char **)p = D_800B6F8C;
    func_800B9FCC(p + 0x10, 0);
    if (in_chrg & 1)
        operator delete(p);
}

EXTERN_C void func_800BA2FC(int *p) { p[8] = (p[8] + 1) & p[7]; }

EXTERN_C void func_800BA114(S_800BA17C *);
EXTERN_C void func_800BA314(char *p) { func_800BA114(p ? (S_800BA17C *)(p + 0x10) : 0); }

EXTERN_C void func_800BA0E8(S_800BA17C *);
EXTERN_C void func_800BA344(char *p) { func_800BA0E8(p ? (S_800BA17C *)(p + 0x10) : 0); }

EXTERN_C void func_800BA038(void *, int);
EXTERN_C void func_800BA168(void *, int);
EXTERN_C void func_800BA374(char *p, int n)
{
    if (*(int *)(p + 0xC) == 0)
        func_800BA038(p ? p + 0x10 : 0, *(int *)(p + 4) * n);
    func_800BA168(p ? p + 0x10 : 0, n);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA3E4);

EXTERN_C char D_800B714C[];
EXTERN_C char D_800B7134[];
EXTERN_C char D_800B7164[];
EXTERN_C void func_80051514(void *, int);
EXTERN_C void func_8001E508(void *, int);
EXTERN_C void func_800BA4AC(char *p, int in_chrg)
{
    *(char **)(p + 0x8C) = D_800B714C;
    *(char **)(p + 0xF8) = D_800B7134;
    *(char **)p = D_800B7164;
    func_80051514(p + 0xF8, 0);
    func_8001E508(p, in_chrg);
}

EXTERN_C void func_800BDFE0(void *);
EXTERN_C void func_800BA514(char *p) { func_800BDFE0(*(void **)(p + 0x168)); }

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6E54);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6E6C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6E7C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6E9C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6F04);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6F1C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B6F8C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BA538);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BB03C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BB0D0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BB6E8);

EXTERN_C char D_800B7194[];
EXTERN_C char D_800B717C[];
EXTERN_C char D_800B71AC[];
EXTERN_C void func_80051514(void *, int);
EXTERN_C void func_8001E508(void *, int);
EXTERN_C void func_800BB758(char *p, int in_chrg)
{
    *(char **)(p + 0x8C) = D_800B7194;
    *(char **)(p + 0xF8) = D_800B717C;
    *(char **)p = D_800B71AC;
    func_80051514(p + 0xF8, 0);
    func_8001E508(p, in_chrg);
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C void func_800BB7C0(char *p)
{
    char *o;
    *(short *)(p + 0x104) = 0;
    o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 0xA;
    *(void **)(o + 0xC) = 0;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BB838);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BBBA4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BC3B0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BC650);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BCCC0);

EXTERN_C int func_800BCD60() { return 1; }

EXTERN_C char *D_800A4578[];
EXTERN_C void func_800230E8(void *, void *);
EXTERN_C void func_800BCD68(void *p) { func_800230E8(D_800A4578[0] + 0x154, p); }

EXTERN_C void func_800BCD94(char *p) { *(int *)(*(char **)(p + 0x114) + 0x1020) = 1; }

EXTERN_C void func_800BCDA4(S_800BCDA4 *p, void *v)
{
    if (v) {
        p->list0[p->n0] = v;
        p->n0++;
    }
}

EXTERN_C void func_800BCDD8(S_800BCDA4 *p, void *v)
{
    if (v) {
        p->list1[p->n1] = v;
        p->n1++;
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BCE0C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BCF18);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD0A8);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD13C);

EXTERN_C void func_8001AA68(void *, int);
EXTERN_C void func_800BD268(char *p)
{
    func_8001AA68(p ? p + 4 : 0, 0);
    *(short *)(p + 0x10) = 1;
}

EXTERN_C void func_8001AB50(void *, int);
EXTERN_C void func_800BD2A4(char *p) { func_8001AB50(p ? p + 4 : 0, 0); }

EXTERN_C void func_800BD2D4(char *p) { *(int *)(p + 0x2C) = 1; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD2E0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD534);

EXTERN_C int func_800BD5D0(S_800BD5D0 *p, int v)
{
    if (p->n < 4) {
        p->list[p->n++] = v;
        return 0;
    }
    return 1;
}

EXTERN_C void func_800BD604(S_800BD604 *p, Short12 *v) { p->v = *v; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD66C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BD800);

EXTERN_C void func_800BDC64(char *p) { *(int *)(p + 0x1020) = 1; }

EXTERN_C int func_800BDC70(S_800BDC70 *p, int *src, short n)
{
    int i;
    for (i = 0; i < n; i++)
        p->list[p->n++] = *src++;
    return 1;
}

EXTERN_C int func_800BDCB8(S_800BD5D0 *p, int *src, short n)
{
    int i;
    for (i = 0; i < n; i++)
        p->list[p->n++] = *src++;
    return 1;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BDD00);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BDD90);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BDE18);

EXTERN_C void func_800B77D8(void *);
EXTERN_C void func_800BDE78(char *p)
{
    *(int *)(p + 0x140) = 0;
    *(int *)(p + 0x144) = 0;
    func_800B77D8(p);
}

EXTERN_C void func_800BDE9C() {}

EXTERN_C void func_800BDEA4(char *p) { *(int *)(p + 0x144) = *(int *)(p + 0x140); }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BDEB0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BDF38);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BDFE0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BE034);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BE128);

EXTERN_C void func_800BE1C4(char *p)
{
    *(int *)(p + 0x484) = -((*(short *)(p + 0x278) - 320) / 2);
    *(int *)(p + 0x488) = -((*(short *)(p + 0x27A) - 240) / 2);
}

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7134);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B714C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7164);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B717C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7194);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B71AC);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B71C4);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B71F4);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7244);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B725C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7274);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B728C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B729C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B72BC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BE204);

EXTERN_C void func_800BE5E4(char *p) { *(int *)(p + 0x610) = 0; }

EXTERN_C void func_800BE5EC(char *p) { *(int *)(p + 0x610) = 1; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BE5F8);

EXTERN_C void func_800C0030(void *, void *, int);
EXTERN_C int func_800BE6D8(char *p)
{
    char *a = *(char **)(p + 0x4DC);
    N_800BE6D8 *e;
    func_800C0030(p, a + 0xC, *(short *)(a + 4));
    e = *(N_800BE6D8 **)(p + 0x490);
    while (1) {
        VObject *o = &e->obj;
        if (!e)
            break;
        VtblEntry *v = &o->vt[6];
        ((void (*)(void *))v->pfn)((char *)o + v->delta);
        e = e->next;
    }
    return 1;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BE748);

EXTERN_C int func_8001A6E8(void *);
EXTERN_C void func_8002DD34(void *, void *, int);
EXTERN_C void func_800BE8E0(char *p)
{
    N_800BE8E0 *e = (N_800BE8E0 *)(p + 0x448);
    int n = func_8001A6E8(e->next);
    while (1) {
        e = e->next;
        if (n == 0)
            break;
        n--;
        func_8002DD34(*(void **)(*(char **)(p + 0x270) + 0x254), e->data, 0);
    }
    *(int *)(p + 0x614) = 1;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BE954);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BEAC0);

EXTERN_C void func_800BEBB0(char *p)
{
    ObjSlot *q = (ObjSlot *)(p + 0x48C);
    if (q->obj) {
        // delete q->obj (virtual destructor, slot 1)
        VtblEntry *e = &q->obj->vt[1];
        ((void (*)(void *, int))e->pfn)((char *)q->obj + e->delta, 3);
        q->obj = 0;
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BEC00);

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF720(char *p, char v);
EXTERN_C void func_800BED34(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    if (e && e[0xC] == 0)
        func_800BF720((char *)e, 1);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BED7C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BEE24);

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF750(signed char *p);
EXTERN_C void func_800BEEC8(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    if (e && e[0xC] == 1)
        func_800BF750(e);
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF73C(char *p);
EXTERN_C void func_800BEF10(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    int ok = 0;
    if (e && e[0x20] == 1)
        ok = e[0xC] != 0;
    if (ok)
        func_800BF73C((char *)e);
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF7A8(char *p, int v);
EXTERN_C void func_800BEF6C(void *p, short id, int v)
{
    signed char *e = func_800C0CB0(p, id);
    if (e)
        func_800BF7A8((char *)e, v);
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C int func_800BEFA8(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    if (e)
        return e[0xC];
    return 0xFF;
}

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C int func_800BEFE0(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    if (e)
        return e[0x20];
    return 0xFF;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C void func_800BF018(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 4;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
}

EXTERN_C void func_800BF08C() {}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BF094);

EXTERN_C int func_800BF0FC(S_800BF0FC *p, IntPair *out) { *out = p->p0; return 1; }

EXTERN_C int func_800BF114(S_800BF0FC *p, IntPair *out) { *out = p->p1; return 1; }

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF12C(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 1;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF1A4(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 0xB;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF21C(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 0xD;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BF294);

EXTERN_C void **func_800BFCB0(void **p, void *a, int b, void *c, int d);
EXTERN_C void func_800BFD10(void *);
EXTERN_C int func_800BF324(void *p)
{
    func_800BFD10(func_800BFCB0((void **)operator new(0x14), p, 0xCA, 0, 200));
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF374(void *p)
{
    char *o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 0xC;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C int func_800BF3EC(char *p, int a, int b)
{
    char *o;
    *(int *)(p + 0x618) = a;
    *(int *)(p + 0x61C) = b;
    o = func_8001CA10(0x14);
    *(char **)o = D_80010178;
    *(int *)(o + 4) = 0;
    *(char **)o = D_80010300;
    *(short *)(o + 8) = 2;
    *(short *)(o + 0xA) = 2;
    *(int *)(o + 0x10) = 6;
    *(void **)(o + 0xC) = p;
    *(char **)o = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C void *func_80066FB0(void *, void *, int, int, int);
EXTERN_C void func_800670A4(void *);
EXTERN_C int func_800BF46C(char *p)
{
    func_800670A4(func_80066FB0(operator new(0x18), p, 0x6C, *(int *)(p + 0x620), 100));
    return 1;
}

EXTERN_C void *func_80066FB0(void *, void *, int, int, int);
EXTERN_C void func_800670A4(void *);
EXTERN_C void func_800BF4BC(char *p)
{
    func_800670A4(func_80066FB0(operator new(0x18), p, 0x6E, *(int *)(p + 0x620), 100));
}

EXTERN_C int D_800C3210[];
EXTERN_C int func_800BF508() { return D_800C3210[0]; }

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7364[];
EXTERN_C char *func_800BF518(char *p)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800B7364;
    *(short *)(p + 8) = 0;
    *(short *)(p + 0xA) = 0;
    p[0xC] = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1C) = 0;
    p[0x20] = 1;
    return p;
}

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7364[];
EXTERN_C void *func_800A0D2C(int);
C_800BF560::C_800BF560(short a, short n, char c)
{
    vt = D_80010178;
    f4 = 0;
    vt = D_800B7364;
    fA = n;
    f8 = a;
    fC = c;
    f14 = f10 = (int *)func_800A0D2C(n * 4);
    f18 = 0;
    f1C = 0;
    f24 = 0;
    f20 = 1;
}

EXTERN_C char D_800B7364[];
EXTERN_C void func_800A0D0C(void *);
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800BF5D8(char *p, int in_chrg)
{
    *(char **)p = D_800B7364;
    if (*(void **)(p + 0x10))
        func_800A0D0C(*(void **)(p + 0x10));
    func_8001A610(p, in_chrg);
}

EXTERN_C void func_800BF62C(S_800BF62C *p, short a, short b)
{
    if (p->count < p->n) {
        ShortPair *e = &p->list[p->count];
        e->a = a;
        e->b = b;
        p->count++;
    }
}

EXTERN_C void func_800BF73C(char *p);
EXTERN_C int func_800BF670(C_800BF560 *p)
{
    if (p->f18 == p->fA - 1) {
        if (p->f20 != 1)
            func_800BF73C((char *)p);
        else {
            p->f18 = 0;
            p->f14 = p->f10;
        }
        return 0;
    }
    p->f18++;
    p->f14++;
    return 1;
}

EXTERN_C void func_800BF6E8(S_800BF6E8 *p)
{
    int last = p->n - 1;
    while (1) {
        if (p->i == last)
            return;
        p->i++;
        p->ptr++;
    }
}

EXTERN_C void func_800BF720(char *p, char v)
{
    char old = p[0xC];
    p[0xC] = v;
    *(int *)(p + 0x18) = 0;
    p[0x20] = old;
    *(int *)(p + 0x14) = *(int *)(p + 0x10);
}

EXTERN_C void func_800BF73C(char *p)
{
    char v = p[0x20];
    p[0x20] = 1;
    p[0xC] = v;
}

EXTERN_C void func_800BF750(signed char *p)
{
    if (p[0x20] == 1 && p[0xC] == 1)
        p[0xC] = 2;
}

EXTERN_C void func_800BF77C(signed char *p)
{
    if (p[0x20] == 1 && p[0xC] == 2)
        p[0xC] = 1;
}

EXTERN_C void func_800BF7A8(char *p, int v)
{
    p[0xC] = v;
    p[0x20] = 1;
}

EXTERN_C int func_800BF7B8(char *p) { return *(int *)(p + 0x14); }

EXTERN_C void func_800BF7C4(char *p)
{
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x14) = *(int *)(p + 0x10);
}

EXTERN_C int func_800BF7D4(signed char *p) { return p[0x20]; }

EXTERN_C void func_800BF7E0(char *p, char v) { p[0x20] = v; }

EXTERN_C int func_800BF7E8(signed char *p) { return p[0xC]; }

EXTERN_C int func_800BF7F4(short *p) { return p[5]; }

EXTERN_C int func_800BF800(short *p) { return p[4]; }

EXTERN_C char D_800B7374[];
EXTERN_C char D_800B738C[];
C_800BF80C::C_800BF80C(int a) : C_800BFC28(a)
{
    vt2 = D_800B7374;
    vt = D_800B738C;
    v.init();
    f600 = 0;
}

EXTERN_C char D_800B7374[];
EXTERN_C char D_800B738C[];
EXTERN_C void func_80019920(void *, int);
EXTERN_C void func_800BFC68(char *p, int in_chrg);
EXTERN_C void func_800BF87C(char *p, int in_chrg)
{
    *(char **)(p + 0x8C) = D_800B7374;
    *(char **)p = D_800B738C;
    func_80019920(*(void **)(p + 0x5E0), 0);
    func_800BFC68(p, in_chrg);
}

EXTERN_C void func_80019A6C(void *, int, int);
EXTERN_C void func_800BF8D8(char *p, int a)
{
    int **c = (int **)(p + 0x5E0);
    int *vb = c ? *c : 0;
    func_80019A6C(vb, a, vb[1]);
}

EXTERN_C void *func_80019F64(void *);
EXTERN_C void *func_800BF914(char *p)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    void *r = func_80019F64(b ? *b : 0);
    *(void **)(p + 0x600) = r;
    if (!r)
        return 0;
    return r;
}

EXTERN_C int func_800BF96C(char *p)
{
    int **a = (int **)(p + 0x5E0);
    int *vb = a ? *a : 0;
    return vb[1];
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BF98C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BFA5C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BFAE8);

EXTERN_C void *func_80019F64(void *);
EXTERN_C int func_800BFB78(char *p, int unused, short *out)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    char *r = (char *)func_80019F64(b ? *b : 0);
    *(char **)(p + 0x600) = r;
    if (!r) {
        *out = -1;
        return 0;
    }
    *out = *(short *)(r + 0x1BC);
    return 1;
}

EXTERN_C void func_80019D40(void *);
EXTERN_C void func_800BFBEC(char *p)
{
    int **a = (int **)(p + 0x5E0);
    func_80019D40(a ? *a : 0);
}

EXTERN_C char *func_800BFC20(char *p) { return p + 0x5E0; }

EXTERN_C char D_800B73A4[];
EXTERN_C char D_800B73BC[];
C_800BFC28::C_800BFC28(int a) : C_800BFE58(a)
{
    vt2 = D_800B73A4;
    vt = D_800B73BC;
}

EXTERN_C char D_800B73A4[];
EXTERN_C char D_800B73BC[];
EXTERN_C void func_800BFF8C(void *, int);
EXTERN_C void func_800BFC68(char *p, int in_chrg)
{
    *(char **)(p + 0x8C) = D_800B73A4;
    *(char **)p = D_800B73BC;
    func_800BFF8C(p, in_chrg);
}

EXTERN_C IntPair *func_800BFC9C(S_800BFC9C *p)
{
    p->tag.a = 0xE0000000;
    p->tag.b = 0;
    return &p->tag;
}

EXTERN_C char D_800B73D4[];
EXTERN_C void **func_800BFCB0(void **p, void *a, int b, void *c, int d)
{
    p[0] = D_800B73D4;
    p[1] = a;
    p[3] = (void *)b;
    p[2] = c;
    if (!p[2])
        p[2] = p[1];
    p[4] = (void *)d;
    return p;
}

EXTERN_C char D_800B73D4[];
EXTERN_C void func_8001D024(void *, int);
EXTERN_C void func_800BFCE8(void **p, int in_chrg)
{
    p[0] = D_800B73D4;
    func_8001D024(p, in_chrg);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BFD10);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BFD84);

EXTERN_C void func_800BE954(void *);
EXTERN_C void func_800BFE10(void **p) { func_800BE954(p[1]); }

EXTERN_C void func_800BEAC0(void *);
EXTERN_C void func_800BFE34(void **p) { func_800BEAC0(p[1]); }

INCLUDE_ASM("asm/capture/nonmatchings/capture", __10C_800BFE58i);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800BFF8C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0030);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0194);

EXTERN_C void exit(int);
EXTERN_C signed char func_800C21B0(char *p);
EXTERN_C int func_800C0820(char *p, signed char key)
{
    N_800C0820 *e = *(N_800C0820 **)(p + 0x42C);
    while (1) {
        if (!((signed char *)p)[0xF9])
            break;
        if (key == func_800C21B0((char *)e))
            goto found;
        e = e->next;
    }
    exit(1);
found:
    return e->val;
}

EXTERN_C void exit(int);
EXTERN_C int func_800C089C(char *p, signed char key)
{
    N_800C089C *e = *(N_800C089C **)(p + 0x43C);
    signed char n = p[0xF8];
    while (1) {
        if (n == 0)
            break;
        if (key == e->id)
            goto found;
        n--;
        e = e->next;
    }
    exit(1);
found:
    return e->val;
}

EXTERN_C void exit(int);
EXTERN_C int func_800C08FC(char *p, signed char key)
{
    N_800C08FC *e = *(N_800C08FC **)(p + 0x40C);
    short n = *(short *)(p + 0x3D0);
    while (1) {
        if (n == 0)
            break;
        if (key == e->id)
            goto found;
        n--;
        e = e->next;
    }
    exit(1);
found:
    return e->val;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0958);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0A28);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0B7C);

EXTERN_C int func_8001A6E8(void *);
EXTERN_C signed char *func_800C0CB0(void *p, int id)
{
    N_800C0CB0 *e = *(N_800C0CB0 **)((char *)p + 0x3E4);
    short n = func_8001A6E8(e);
    while (1) {
        if (n == 0)
            break;
        if (id == e->id)
            break;
        n--;
        e = e->next;
    }
    return (signed char *)e;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0D14);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C0F38);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C12B4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C15F4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C1814);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C18C0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C1BA4);

EXTERN_C char *func_800C1CC8(char *p) { return p + 0x514; }

EXTERN_C E_800C1CD0 *func_800C1CD0(S_800C1CD0 *p, int i) { return &p->e[i]; }

EXTERN_C int func_800C1CE8(char *p) { return *(int *)(p + 0x104); }

EXTERN_C int func_800C1CF4(char *p, int v) { *(int *)(p + 0x104) = v; return 1; }

EXTERN_C ShortQuad func_800C1D00(S_800C1D00 *p) { return p->q1; }

EXTERN_C ShortQuad func_800C1D2C(S_800C1D00 *p) { return p->q0; }

EXTERN_C void func_800C1D58(S_800C1D58 *p, Block60 *b) { p->b1 = *b; }

EXTERN_C void func_800C1D94(S_800C1D58 *p, Block60 *b) { p->b0 = *b; }

EXTERN_C char *func_800C1DD0(char *p) { return p + 0xFC; }

EXTERN_C char *func_800C1DD8(char *p) { return p + 0x15C; }

EXTERN_C int func_800C1DE0(char *p) { return *(short *)(p + 0x284); }

EXTERN_C int func_800C1DEC(char *p) { return *(short *)(p + 0x3D2); }

EXTERN_C void func_800C1DF8(char *p, char v) { p[0xF9] = v; }

EXTERN_C void func_800C1E00(char *p, char v) { p[0xF8] = v; }

EXTERN_C char *func_800C1E08(char *p) { return p + 0x448; }

EXTERN_C char *func_800C1E10(char *p) { return p + 0x48C; }

EXTERN_C int func_800C1E18(char *p) { return *(int *)(p + 0x270); }

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7434[];
EXTERN_C char *func_800C1E24(char *p)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800B7434;
    *(signed char *)(p + 0x10) = -0x11;
    *(signed char *)(p + 0x11) = -0x11;
    *(short *)(p + 0x12) = -0x1011;
    *(short *)(p + 0x14) = -0x1011;
    *(int *)(p + 0x8) = 0xEFEFEFEF;
    *(int *)(p + 0xC) = 0xEFEFEFEF;
    *(int *)(p + 0x1C) = 0xEF;
    *(int *)(p + 0x18) = 0;
    return p;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C1E7C);

EXTERN_C char D_800B7434[];
EXTERN_C void func_800A0D0C(void *);
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C1F18(char *p, int in_chrg)
{
    *(char **)p = D_800B7434;
    if (*(void **)(p + 0x18))
        func_800A0D0C(*(void **)(p + 0x18));
    func_8001A610(p, in_chrg);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C1F6C);

EXTERN_C int func_800C1FDC(short *p) { return p[9] != 0; }

EXTERN_C int func_800C1FE8(int *p) { return p[6]; }

EXTERN_C int func_800C1FF4(int *p) { return p[7]; }

EXTERN_C void func_800C2000(int *p, int v) { p[7] = v; }

EXTERN_C int func_800C2008(short *p) { return p[10]; }

EXTERN_C int func_800C2014(signed char *p) { return p[0x11]; }

EXTERN_C int func_800C2020(signed char *p) { return p[0x10]; }

EXTERN_C int func_800C202C(int *p) { return p[3]; }

EXTERN_C int func_800C2038(int *p) { return p[2]; }

EXTERN_C char D_80010178[];
EXTERN_C char D_800B7444[];
EXTERN_C char *func_800C2044(char *p, char a, short b)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800B7444;
    p[8] = a;
    *(short *)(p + 0xA) = b;
    *(int *)(p + 0xC) = 0;
    return p;
}

EXTERN_C char D_800B7444[];
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C2074(char *p, int in_chrg)
{
    VObject *o;
    *(char **)p = D_800B7444;
    o = *(VObject **)(p + 0xC);
    if (o) {
        // delete o (virtual destructor, slot 1)
        VtblEntry *e = &o->vt[1];
        ((void (*)(void *, int))e->pfn)((char *)o + e->delta, 3);
    }
    func_8001A610(p, in_chrg);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C20DC);

EXTERN_C short func_800C2194(char *p)
{
    int r;
    if (*(int *)(p + 0xC) == 0)
        r = 0;
    else
        r = *(short *)(p + 0xA);
    return r;
}

EXTERN_C signed char func_800C21B0(char *p)
{
    int r;
    if (*(int *)(p + 0xC) == 0)
        r = 0;
    else
        r = *(signed char *)(p + 0x8);
    return r;
}

EXTERN_C int func_800C21CC(int *p) { return p[3]; }

EXTERN_C void func_800C21D8(char *p, char v) { p[8] = v; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C21E0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C22CC);

EXTERN_C S_800C2370_src *func_800C2370(S_800C2370_dst *d, S_800C2370_src *s, int *out)
{
    int i = 0;
    *out = 0;
    d->q[0] = s->q[0];
loop:
    if (i < 3) {
        (&d->q[0])[i + 1] = (&s->q[0])[i + 1];
        i++;
        goto loop;
    }
    return s;
}

EXTERN_C int func_800C23DC() { return 0; }

EXTERN_C void func_800C23E4(int *p, int v) { p[0x11] = v; }

EXTERN_C int func_800C23EC(int *p) { return p[0x11]; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C23F8);

EXTERN_C char D_800B751C[];
EXTERN_C void func_80019920(void *, int);
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C2480(char *p, int in_chrg)
{
    *(char **)p = D_800B751C;
    func_80019920(*(void **)(p + 0xC), 0);
    func_8001A610(p, in_chrg);
}

EXTERN_C void func_80019A6C(void *, int, int);
EXTERN_C void func_800C24D0(char *p, N_800C24D0 *n)
{
    if (*(int *)(p + 0x34)) {
        while (1) {
            if (!n)
                break;
            int *vb = (p + 0xC) ? *(int **)(p + 0xC) : 0;
            func_80019A6C(vb, (int)n, vb[1]);
            n = n->next;
        }
        *(int *)(p + 0x34) = 0;
        *(int *)(p + 0x38) = 0;
    }
}

EXTERN_C int func_800C254C(int *p) { return p[0xE]; }

EXTERN_C char *func_800C2558(char *p) { return p + 0xC; }

EXTERN_C int func_800C2560(short *p) { return p[0x16]; }

EXTERN_C void func_800C256C(short *p, short v) { p[0x16] = v; }

EXTERN_C int func_800C2574(int *p) { return p[0xC]; }

EXTERN_C void func_800C2580(int *p) { p[0xC]--; }

EXTERN_C void func_800C2594(int *p, int v) { p[0xC] = v; }

EXTERN_C int func_800C259C(short *p) { return p[4]; }

EXTERN_C void func_800C25A8(short *p, short v) { p[4] = v; }

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C25B0);

EXTERN_C char D_80010178[];
EXTERN_C char D_800111BC[];
EXTERN_C char D_800B752C[];
EXTERN_C char *func_800C2744(char *p)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800111BC;
    *(short *)(p + 8) = 0;
    *(short *)(p + 0xA) = 0;
    *(char **)p = D_800B752C;
    return p;
}

EXTERN_C char D_800B752C[];
EXTERN_C void func_8001A610(void *, int);
EXTERN_C void func_800C277C(void **p, int in_chrg)
{
    p[0] = D_800B752C;
    func_8001A610(p, in_chrg);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C27A4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2850);

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2A38(S_800C2D5C *p, short x, short y)
{
    if (p->state == 1)
        func_800C2BD0(p);
    int i = D_800B4CF0[0];
    p->e[i].b.x = x;
    p->e[i].b.y = y;
    p->state = 2;
}

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2AA8(S_800C2D5C *p, short dx, short dy)
{
    if (p->state == 1)
        func_800C2BD0(p);
    int i = D_800B4CF0[0];
    p->e[i].b.x += dx;
    p->e[i].b.y += dy;
    p->state = 2;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2B28);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2BD0);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2C4C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2CD4);

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2D5C(S_800C2D5C *p, unsigned char *out)
{
    out[0] = p->e[D_800B4CF0[0]].b.col.c.r;
    out[1] = p->e[D_800B4CF0[0]].b.col.c.g;
    out[2] = p->e[D_800B4CF0[0]].b.col.c.b;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2DB4);

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2E60(S_800C2D5C *p, unsigned char a, unsigned char b)
{
    if (p->state == 1)
        func_800C2BD0(p);
    p->e[D_800B4CF0[0]].b.p8 = a;
    p->e[D_800B4CF0[0]].b.p9 = b;
    p->state = 2;
}

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *);
EXTERN_C void func_800C2EE0(S_800C2D5C *p, char *q)
{
    if (p->state == 1)
        func_800C2BD0(p);
    p->e[D_800B4CF0[0]].b.s = *(short *)(q + 8);
    p->state = 2;
}

EXTERN_C void func_800C2F40(int *p) { p[0x12] = 1; }

EXTERN_C void func_800C2F4C(int *p) { p[0x12] = 0; }

EXTERN_C short D_800C3214[];
EXTERN_C void func_800C2F54() { D_800C3214[0] = 0; }

EXTERN_C int func_800C2F60(int *p) { return p[1]; }

EXTERN_C char D_80010178[];
EXTERN_C char D_800B757C[];
EXTERN_C char *func_800C2F6C(char *p)
{
    *(char **)p = D_80010178;
    *(int *)(p + 4) = 0;
    *(char **)p = D_800B757C;
    p[8] = 0;
    *(short *)(p + 0xA) = 0;
    *(int *)(p + 0xC) = 0;
    return p;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C2F9C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800C301C);

EXTERN_C int func_800C31A8(int *p) { return p[3]; }

EXTERN_C void func_800C31B4(char *p, char v) { p[8] = v; }

EXTERN_C void func_800C31BC(short *p, short v) { p[5] = v; }

EXTERN_C int func_800C31C4(signed char *p) { return p[8]; }

EXTERN_C int func_800C31D0(unsigned short *p) { return p[5]; }

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7334);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B734C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7364);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7374);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B738C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B73A4);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B73BC);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B73D4);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7404);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B741C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7434);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7444);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B7454);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B74BC);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B751C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B752C);

INCLUDE_RODATA("asm/capture/nonmatchings/capture", D_800B757C);
