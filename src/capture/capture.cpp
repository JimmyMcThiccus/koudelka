#include "common.h"
#include "capture/capture.h"

struct E_800B758C {
    int a, b, c, d;
};
struct H_800B758C {
    int tag;
    char pad4[0x1C];
    E_800B758C e[0x7C];
};
EXTERN_C char *func_8008C060(int, int);
EXTERN_C void func_8009482C(int, void *);
EXTERN_C char *func_8008BC0C(int);
EXTERN_C void func_8008C724(char *, void *, int, void *);
EXTERN_C void func_800B758C(char *p, char *buf)
{
    int i, j;
    char *o;
    E_800B758C *q;
    char *e;
    H_800B758C *h;
    E_800B758C *e2;
    *(int *)(p + 0xB0) = 0;
    *(int *)(p + 0xAC) = 0;
    *(char **)(p + 0x44) = buf;
    p[0x48] = 0;
    p[0x49] = 0;
    for (i = 0; i < 4; i++) {
        e = p + 0x4C + i * 16;
        *(char **)(e + 8) = buf;
        e[0] = 0;
        e[1] = 0;
        *(int *)(e + 4) = -1;
        *(char **)(e + 0xC) = buf + 0x7E0;
        buf += 0xFC0;
    }
    o = func_8008C060(0x3F00, 8);
    if (o == 0)
        func_8009482C(0xC8, p);
    *(char **)(p + 0x10) = o;
    buf = func_8008BC0C(0xFC0);
    *(char **)(p + 0x124) = buf;
    *(char **)(p + 0x128) = buf + 0x7E0;
    for (i = 0; i < 2; i++) {
        h = ((H_800B758C **)(p + 0x124))[i];
        h->tag = 0x6D727473;
        e2 = h->e;
        q = e2;
        j = 0x7C;
        do {
            j--;
            q->a = 0x20C;
            q->b = 0;
            q->c = 0;
            q->d = 0;
            q++;
        } while (j);
        ((unsigned char *)&e2[0x68])[1] = 3;
    }
    for (i = 0; i < 4; i++)
        func_8008C724(*(char **)(p + 0x10) + i * 0xFC0, *(void **)(p + 0x124), 0x7E0, 0);
}

EXTERN_C void func_8008BE08(void *);
EXTERN_C void func_8008C3AC(void *);
EXTERN_C void func_800B76E4(char *p)
{
    func_8008BE08(*(void **)(p + 0x124));
    *(void **)(p + 0x124) = 0;
    *(void **)(p + 0x128) = 0;
    func_8008C3AC(*(void **)(p + 0x10));
    *(void **)(p + 0x10) = 0;
}

struct S_800B18FC {
    unsigned short flags;
    char pad2;
    unsigned char b3;
    char pad4[0x13C];
    int f140;
    char pad144[8];
    int f14C;
    char pad150[0x10];
    void *f160;
    char pad164[0x3F];
    unsigned char b1A3;
};
EXTERN_C S_800B18FC D_800B18FC;
EXTERN_C void func_8009484C(int, int);
EXTERN_C int func_800B7728(void)
{
    char *o = (char *)D_800B18FC.f160;
    unsigned int i;
    char *e;
    if (o == 0)
        return 0;
    if (*(int *)(o + 0x10) == 0)
        return 0;
    D_800B18FC.flags |= 0x30;
    (*(int *)(o + 0xAC))++;
    i = (unsigned char)o[0x48];
    if (i >= 4) {
        func_8009484C(0xC8, (int)o);
        i = 0;
    }
    e = o + 0x4C + i * 16;
    e[0] = 0;
    D_800B18FC.flags &= ~0x30;
    return *(int *)(e + 8);
}

EXTERN_C S_800B18FC D_800B18FC;
struct H_800B77D8 {
    int tag;
    char pad4[3];
    unsigned char b7;
    char pad8[0x10];
    int f18;
    int f1C;
};
struct E_800B77D8 {
    unsigned char b0;
    char pad1[3];
    int f4;
    H_800B77D8 *f8;
    H_800B77D8 *fC;
};
struct S_800B77D8 {
    unsigned short flags;
    char pad2[6];
    unsigned char b8, b9;
    char padA[6];
    int f10;
    char pad14[0x14];
    void *f28;
    void *f2C;
    char pad30[0xC];
    int f3C;
    char pad40[8];
    unsigned char f48, f49;
    unsigned short f4A;
    E_800B77D8 e[4];
    char pad8C[0x24];
    int fB0;
    int fB4;
    char padB8[0xC];
    short vC4;
    char padC6[0x2E];
    short vF4;
};
EXTERN_C void SpuSetIRQ(int);
EXTERN_C void SpuSetIRQAddr(unsigned long);
EXTERN_C void SpuSetKey(int, unsigned long);
EXTERN_C void func_8009484C(int, int);
EXTERN_C void func_800B7B28(unsigned char *);
EXTERN_C void func_800B7B90(char *);
EXTERN_C void func_800B7E6C(char *, unsigned char *);
EXTERN_C void func_800B815C(char *, char *);
EXTERN_C void func_800B77D8(void *)
{
    S_800B77D8 *o = (S_800B77D8 *)D_800B18FC.f160;
    unsigned char i;
    E_800B77D8 *e;
    int n;
    if (o == 0 || !(o->flags & 0x4000) || o->f10 == 0)
        return;
    D_800B18FC.flags |= 0x30;
    i = o->f48;
    if (i >= 4) {
        func_8009484C(0xC8, (int)o);
        i = 0;
    }
    e = &o->e[i];
    if (e->f8->tag != 0x6D727473)
        o->f4A |= 0x1003;
    if (e->fC->tag != 0x6D727473)
        o->f4A |= 0x1003;
    if (e->f8->f18 != e->fC->f18)
        o->f4A |= 0x103;
    if (e->f8->b7 != 0)
        o->f4A |= 0x403;
    if (e->fC->b7 != 1)
        o->f4A |= 0x803;
    o->fB0++;
    n = e->f8->f1C;
    if (n != o->fB4 + 1)
        o->f4A |= 0x200;
    o->fB4 = n;
    if (o->f4A & 2) {
        o->f4A &= ~2;
        D_800B18FC.flags &= ~0x30;
        return;
    }
    e->f4 = n;
    e->b0 = 1;
    i = o->f48 + 1;
    if (i >= 4)
        i = 0;
    if (o->f49 == i) {
        o->flags &= 0xDFFF;
        SpuSetIRQ(0);
        SpuSetIRQ(3);
        D_800B18FC.f140 = 0;
        SpuSetIRQAddr(0x1000);
        i = 0;
        o->f3C = 0;
        o->b8 = 0;
        o->b9 = 0;
        o->f48 = 0;
        o->f49 = 0;
        if (o->flags & 1)
            SpuSetKey(0, (1 << o->vC4) | (1 << o->vF4));
        else
            SpuSetKey(0, 1 << o->vC4);
    } else {
        o->f48 = i;
    }
    if (!(o->flags & 0x2000)) {
        if (i < o->f49)
            i += 4;
        if (i - o->f49 >= 3) {
            unsigned char *x;
            e = &o->e[o->f49];
            o->flags |= 0x2000;
            o->f28 = (void *)func_800B7B28;
            o->f2C = (void *)func_800B7B90;
            x = (unsigned char *)e->f8;
            func_800B7E6C((char *)o, x);
            func_800B815C((char *)o, (char *)x);
        }
    }
    D_800B18FC.flags &= ~0x30;
}

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

EXTERN_C int D_800B1A5C[];
EXTERN_C char *func_800B8280(char *p, int v);
EXTERN_C void func_800B815C(char *, char *);
EXTERN_C void func_800B7B90(char *p)
{
    if (D_800B1A5C[0]) {
        char *e = p + 0x4C + (unsigned char)p[0x49] * 16;
        int n = *(int *)(p + 0xA8) + 1;
        char *r;
        if (n == *(int *)(e + 4)) {
            *(unsigned short *)p &= ~0x400;
            r = *(char **)(e + 8);
            *(int *)r = 0;
        } else {
            *(unsigned short *)p |= 0x400;
            r = func_800B8280(p, n);
            *(unsigned short *)(p + 0x4A) |= 0x2000;
        }
        func_800B815C(p, r);
    }
}

EXTERN_C S_800B18FC D_800B18FC;
EXTERN_C void SpuSetIRQ(int);
EXTERN_C void func_8008BF78(void *, int);
EXTERN_C void func_800B8488(char *p, short a, char b);
EXTERN_C void func_80093D8C(void *);
EXTERN_C void func_8008C928(int);
EXTERN_C void func_8009484C(int, int);
EXTERN_C void func_8008CBE4(void);
EXTERN_C void func_800B7C34(char *p, int, int a2, int a3)
{
    int vol = a2;
    int full = 0x1000;
    SpuSetIRQ(0);
    SpuSetIRQ(3);
    D_800B18FC.f140 = 0;
    D_800B18FC.f14C = 0;
    func_8008BF78(p, 0x12C);
    *(unsigned short *)p = 0x201;
    vol = vol * 90 / 127;
    p[8] = 0;
    p[9] = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x1C) = 0;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x2C) = 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
    *(int *)(p + 0x40) = 0;
    *(int *)(p + 0xAC) = 0;
    *(int *)(p + 0xB0) = 0;
    p[0x90] = 0;
    p[0x92] = 0;
    *(int *)(p + 0xA8) = -1;
    *(short *)(p + 2) = full;
    *(short *)(p + 6) = a3;
    *(short *)(p + 4) = vol;
    func_800B8488(p + 0xC4, 0x14, 0);
    func_800B8488(p + 0xF4, 0x15, 0);
    vol <<= 7;
    if (D_800B18FC.b1A3 == 0) {
        vol = (vol * 0x5A00) >> 15;
        *(short *)(p + 0xCC) = vol;
        *(short *)(p + 0xCE) = vol;
        *(short *)(p + 0xFC) = vol;
        *(short *)(p + 0xFE) = vol;
    } else {
        *(short *)(p + 0xCC) = vol;
        *(short *)(p + 0xCE) = 0;
        *(short *)(p + 0xFC) = 0;
        *(short *)(p + 0xFE) = vol;
    }
    *(short *)(p + 0x108) = full;
    *(short *)(p + 0xD8) = full;
    D_800B18FC.f160 = p;
    func_80093D8C(p + 0xC4);
    func_80093D8C(p + 0xF4);
    *(short *)(p + 0x4A) = 0;
    *(int *)(p + 0xB4) = -1;
    func_8008C928(0x10);
    if (D_800B18FC.b3)
        func_8009484C(0xE2, (int)p);
    func_8008CBE4();
}

EXTERN_C int D_800B1A5C[];
EXTERN_C void func_800B7DFC(short *p)
{
    *p = 0;
    D_800B1A5C[0] = 0;
}

EXTERN_C S_800B18FC D_800B18FC;
EXTERN_C void func_800B82AC(char *);
EXTERN_C void func_800B7E0C(void *p, int)
{
    if (D_800B18FC.f160 != p)
        func_800B82AC((char *)D_800B18FC.f160);
    D_800B18FC.f160 = p;
    *(unsigned short *)p |= 0x4000;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7E6C);

EXTERN_C S_800B18FC D_800B18FC;
EXTERN_C void SpuSetIRQ(int);
EXTERN_C void SpuSetIRQAddr(unsigned long);
EXTERN_C void SpuSetKey(int, unsigned long);
EXTERN_C void SpuSetVoiceStartAddr(int, unsigned long);
EXTERN_C void SpuSetVoiceLoopStartAddr(int, unsigned long);
EXTERN_C int func_800B8048(void);
EXTERN_C void func_800B7F10(unsigned char *a)
{
    if (a[1] == 2) {
        char *o = (char *)D_800B18FC.f160;
        if (o == 0) {
            SpuSetIRQ(0);
            SpuSetIRQ(3);
            D_800B18FC.f140 = 0;
            SpuSetIRQAddr(0x1000);
        } else {
            void (*cb)(char *);
            *(unsigned short *)o &= 0xEFFF;
            cb = *(void (**)(char *))(o + 0x28);
            if (cb)
                cb(o);
            if (*(int *)(o + 0x3C) == 0) {
                D_800B18FC.f140 = (int)func_800B8048;
                SpuSetIRQAddr(*(int *)(o + 0x10) + 0x28);
                SpuSetIRQ(1);
                SpuSetVoiceStartAddr(*(short *)(o + 0xC4), *(int *)(o + 0xE0));
                SpuSetVoiceStartAddr(*(short *)(o + 0xF4), *(int *)(o + 0x110));
                SpuSetVoiceLoopStartAddr(*(short *)(o + 0xC4), *(int *)(o + 0xE4));
                SpuSetVoiceLoopStartAddr(*(short *)(o + 0xF4), *(int *)(o + 0x114));
                SpuSetKey(1, (1 << *(short *)(o + 0xC4)) | (1 << *(short *)(o + 0xF4)));
            } else {
                SpuSetIRQ(1);
            }
            (*(int *)(o + 0x3C))++;
        }
    }
}

EXTERN_C S_800B18FC D_800B18FC;
EXTERN_C void SpuSetIRQ(int);
EXTERN_C void SpuSetIRQAddr(unsigned long);
EXTERN_C unsigned long SpuGetIRQAddr(void);
EXTERN_C void SpuSetVoiceLoopStartAddr(int, unsigned long);
EXTERN_C int func_8009F2C0(void);
EXTERN_C int func_800B8048(void)
{
    char *o;
    void (*cb)(char *);
    int i;
    char *b;
    SpuSetIRQ(0);
    o = (char *)D_800B18FC.f160;
    if (o == 0) {
        SpuSetIRQ(0);
        SpuSetIRQ(3);
        D_800B18FC.f140 = 0;
        SpuSetIRQAddr(0x1000);
        return 0;
    }
    cb = *(void (**)(char *))(o + 0x2C);
    if (cb)
        cb(o);
    i = (unsigned char)o[9] + 1;
    if (i >= 4)
        i = 0;
    o[9] = i;
    b = *(char **)(o + 0x10) + i * *(int *)(o + 0x24);
    SpuSetIRQAddr((unsigned long)(b + 0x28));
    b += 0x20;
    *(char **)(o + 0xE4) = b;
    SpuSetVoiceLoopStartAddr(*(short *)(o + 0xC4), (unsigned long)b);
    b += *(int *)(o + 0x20);
    *(char **)(o + 0x114) = b;
    SpuSetVoiceLoopStartAddr(*(short *)(o + 0xF4), (unsigned long)b);
    (*(int *)(o + 0x40))++;
    o[0xA] = func_8009F2C0();
    *(unsigned long *)(o + 0xC) = SpuGetIRQAddr();
    return 0;
}

struct Q_800B815C { int a, b, c, d; };
struct B_800B815C { Q_800B815C q[2]; };
struct S_800B815C {
    unsigned short flags;
    char pad2[6];
    unsigned char idx;
    char pad9[7];
    char *buf;
    char *f14;
    char *f18;
    int size;
    char pad20[4];
    int stride;
    char pad28[0x10];
    int f38;
    char pad3C[0xC];
    unsigned char f48, f49;
    char pad4A[0x42];
    B_800B815C blk;
};
EXTERN_C void func_8008C724(char *, void *, int, void *);
EXTERN_C void func_800B7F10(unsigned char *);
EXTERN_C void func_800B82AC(char *);
EXTERN_C void func_800B815C(char *pc, char *sc)
{
    S_800B815C *p = (S_800B815C *)pc;
    B_800B815C *src = (B_800B815C *)sc;
    int i = p->idx;
    char *dst = p->buf + i * p->stride;
    i++;
    if (i >= 4)
        i = 0;
    p->idx = i;
    {
        Q_800B815C *s = src->q;
        Q_800B815C *d = p->blk.q;
        int j = 2;
        do {
            int a, b, c, e;
            a = s->a;
            b = s->b;
            c = s->c;
            e = s->d;
            d->a = a;
            d->b = b;
            d->c = c;
            d->d = e;
            s++;
            d++;
            j--;
        } while (j);
    }
    p->flags |= 0x1000;
    func_8008C724(dst, src, p->size, (void *)func_800B7F10);
    p->f38++;
    p->f14 = (char *)src;
    p->f18 = dst;
    if (p->flags & 0x800) {
        int a = p->f48;
        if (a < p->f49)
            a += 4;
        if (a == p->f49)
            func_800B82AC((char *)p);
    }
}

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

EXTERN_C int D_800B1A3C[];
EXTERN_C int D_800B1A5C[];
EXTERN_C void SpuSetIRQ(int);
EXTERN_C void SpuSetIRQAddr(unsigned long);
EXTERN_C void SpuSetKey(int, unsigned long);
EXTERN_C void func_80093E80(void *);
EXTERN_C void func_800B82AC(char *p)
{
    *(unsigned short *)p &= 0x9FFF;
    SpuSetIRQ(0);
    SpuSetIRQ(3);
    D_800B1A3C[0] = 0;
    SpuSetIRQAddr(0x1000);
    if (*(unsigned short *)p & 1) {
        SpuSetKey(0, (1 << *(short *)(p + 0xC4)) | (1 << *(short *)(p + 0xF4)));
        func_80093E80(p + 0xC4);
        func_80093E80(p + 0xF4);
    } else {
        SpuSetKey(0, 1 << *(short *)(p + 0xC4));
        func_80093E80(p + 0xC4);
    }
    D_800B1A5C[0] = 0;
}

EXTERN_C S_800B18FC D_800B18FC;
EXTERN_C void SpuSetIRQ(int);
EXTERN_C void SpuSetIRQAddr(unsigned long);
EXTERN_C void SpuSetKey(int, unsigned long);
EXTERN_C void func_80093E80(void *);
EXTERN_C void func_8008BAC4(void);
EXTERN_C void func_8008BA68(void);
EXTERN_C void func_8008C928(int);
EXTERN_C void func_800B8360(char *p)
{
    D_800B18FC.f160 = 0;
    *(unsigned short *)p &= 0xBFFF;
    func_8008BAC4();
    D_800B18FC.f140 = 0;
    SpuSetIRQ(0);
    SpuSetIRQ(3);
    SpuSetIRQAddr(0x1000);
    if (*(unsigned short *)p & 1) {
        SpuSetKey(0, (1 << *(short *)(p + 0xC4)) | (1 << *(short *)(p + 0xF4)));
        func_80093E80(p + 0xC4);
        func_80093E80(p + 0xF4);
    } else {
        SpuSetKey(0, 1 << *(short *)(p + 0xC4));
        func_80093E80(p + 0xC4);
    }
    func_8008BA68();
    func_8008C928(0x10);
}

struct Q_800B8434 { int a, b, c, d; };
EXTERN_C void func_800B8434(Q_800B8434 *d, Q_800B8434 *s)
{
    int j = 0x7E;
    do {
        int a, b, c, e;
        j--;
        a = s->a;
        b = s->b;
        c = s->c;
        e = s->d;
        d->a = a;
        d->b = b;
        d->c = c;
        d->d = e;
        s++;
        d++;
    } while (j);
}

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

struct S_800B84E0 {
    short voice;
    char pad2[6];
    short volL, volR;
    char padC[8];
    unsigned short pitch;
    char pad16[6];
    int start;
    int loop;
    unsigned char arMode, srMode, rrMode, ar, dr, sr, rr, sl;
};
EXTERN_C void SpuSetVoiceVolume(int, short, short);
EXTERN_C void SpuSetVoicePitch(int, unsigned short);
EXTERN_C void SpuSetVoiceStartAddr(int, unsigned long);
EXTERN_C void SpuSetVoiceLoopStartAddr(int, unsigned long);
EXTERN_C void SpuSetVoiceARAttr(int, unsigned short, long);
EXTERN_C void SpuSetVoiceDR(int, unsigned short);
EXTERN_C void SpuSetVoiceSL(int, unsigned short);
EXTERN_C void SpuSetVoiceSRAttr(int, unsigned short, long);
EXTERN_C void SpuSetVoiceRRAttr(int, unsigned short, long);
EXTERN_C void func_8009F700(int, int);
EXTERN_C void func_8009EBC0(int, int);
EXTERN_C void func_8009F0E0(int, int);
EXTERN_C void func_800B84E0(S_800B84E0 *p)
{
    int v = p->voice;
    int mask;
    SpuSetVoiceVolume(v, p->volL, p->volR);
    SpuSetVoicePitch(v, p->pitch);
    SpuSetVoiceStartAddr(v, p->start);
    SpuSetVoiceLoopStartAddr(v, p->loop);
    SpuSetVoiceARAttr(v, p->ar, p->arMode);
    SpuSetVoiceDR(v, p->dr);
    SpuSetVoiceSL(v, p->sl);
    SpuSetVoiceSRAttr(v, p->sr, p->srMode);
    SpuSetVoiceRRAttr(v, p->rr, p->rrMode);
    mask = 1 << v;
    func_8009F700(0, mask);
    func_8009EBC0(0, mask);
    func_8009F0E0(0, mask);
}
