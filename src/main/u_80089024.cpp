#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

EXTERN_C int func_80089024(void *self)
{
    int r = FIELD_AT(self, short, 0x6);
    FIELD_AT(self, Hist_80089024, 0x6) = FIELD_AT(self, Hist_80089024, 0x8);
    FIELD_AT(self, short, 0xE) = -0x8000;
    if ((unsigned short)r == 0x8000) {
        r = 0x80000000;
    }
    return r;
}

EXTERN_C int func_8008906C(void *self)
{
    int r = FIELD_AT(self, short, 0x16);
    FIELD_AT(self, Hist_8008906C, 0x16) = FIELD_AT(self, Hist_8008906C, 0x18);
    FIELD_AT(self, short, 0x1E) = -0x8000;
    if ((unsigned short)r == 0x8000) {
        r = 0x80000000;
    }
    return r;
}

EXTERN_C int func_800890B4(void *self)
{
    int v = FIELD_AT(self, signed char, 0x70);
    FIELD_AT(self, Bytes4_800890B4, 0x70) = FIELD_AT(self, Bytes4_800890B4, 0x71);
    FIELD_AT(self, signed char, 0x74) = 0x80;
    if ((unsigned char)v == 0x80) {
        v = 0x80000000;
    }
    return v;
}

EXTERN_C void func_800890F0(void *self, void *b, int c)
{
    if (FIELD_AT(func_8008672C((char *)self), short, 0x4E2) == 2) {
        func_800D96F8(self, b, c);
    } else {
        if (FIELD_AT(self, short, 0x20) < 0) {
            FIELD_AT(self, short, 0x20) = 0;
        }
        if (FIELD_AT(self, short, 0x10) <= 0) {
            FIELD_AT(self, short, 0x10) = 1;
        }
    }
}

EXTERN_C void func_80089178(void *self, int b)
{
    if (FIELD_AT(func_8008672C((char *)self), short, 0x4E2) == 2) {
        func_800D9218(self, b);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_800891C0);

EXTERN_C void func_800893EC(void *self, unsigned short *s, unsigned short *ins, int pos)
{
    int end;
    int n;
    int i;
    for (end = pos; s[end]; end++) {
    }
    for (n = 0; ins[n]; n++) {
    }
    for (i = end; i >= pos; i--) {
        s[i + n] = s[i];
    }
    for (i = 0; i < n; i++) {
        s[i + pos] = *ins++;
    }
}

EXTERN_C void func_800894AC(char *self, char *b, int c, R_800894AC *d)
{
    short t;
    func_80089804(self, b, c, 1, 99);
    *(S6C_800894AC *)(self ? self + 0x14 : 0) = *(S6C_800894AC *)(b ? b + 0x20 : 0);
    t = 1;
    if (func_800891C0(self ? self + 0x80 : 0, b + 0x8C, FIELD_AT(self, unsigned char, 0x18) != 4 ? (void *)(self + 0xC) : (void *)&t)) {
        FIELD_AT(self, char, 0xE) = rand() & rand() & rand() & rand() & 0xF0;
        for (; d->a != 0 || d->b != 0; d++) {
            if ((d->a & FIELD_AT(self, unsigned short, 0xC)) == d->a && (d->b & FIELD_AT(self, unsigned char, 0xE)) == d->b) {
                break;
            }
        }
        func_800893EC(self, (unsigned short *)(self + 0x1C), d->s, 1);
    }
    FIELD_AT(self, char, 0x1B) = FIELD_AT(b, char, 0);
}

EXTERN_C void func_80089658(char *self, char *b)
{
    FIELD_AT(self, W20_80089658, 0) = FIELD_AT(b, W20_80089658, 0);
    func_8008B5B4((Unpacked_8008B5B4 *)(self ? self + 0x14 : 0), (Packed_8008B5B4 *)(b + 0x14));
    *(C20_80089658 *)(self ? self + 0x80 : 0) = *(C20_80089658 *)(b ? b + 0x5C : 0);
}

EXTERN_C char *func_8008972C(char *self, char *b)
{
    FIELD_AT(b, W20_80089658, 0) = FIELD_AT(self, W20_80089658, 0);
    func_8008B630((Unpacked_8008B5B4 *)(self ? self + 0x14 : 0), (Packed_8008B5B4 *)(b + 0x14));
    *(C20_80089658 *)(b ? b + 0x5C : 0) = *(C20_80089658 *)(self ? self + 0x80 : 0);
    return b;
}

EXTERN_C void func_80089804(char *out, char *src, int idx, int lo, int hi)
{
    if (idx >= lo && hi >= idx) {
        func_80089AC0((unsigned char *)out, (unsigned char *)(src + 4), (unsigned char *)(src + 0xC), idx, lo, hi);
    } else {
        func_80089B44((signed char *)out, (signed char *)(src + 4), (signed char *)(src + 0xC));
    }
    FIELD_AT(out, short, 0x8) = FIELD_AT(src, short, 0x18);
    FIELD_AT(out, short, 0xA) = FIELD_AT(src, short, 0x1A);
    FIELD_AT(out, short, 0xC) = FIELD_AT(src, short, 0x2);
    FIELD_AT(out, char, 0xE) = FIELD_AT(src, char, 0x14);
    FIELD_AT(out, char, 0xF) = FIELD_AT(src, char, 0x15);
    FIELD_AT(out, char, 0x10) = FIELD_AT(src, char, 0x16);
    FIELD_AT(out, char, 0x11) = FIELD_AT(src + idx, char, 0x1C);
    FIELD_AT(out, char, 0x12) = FIELD_AT(src, char, 0x1F);
    FIELD_AT(out, char, 0x13) = FIELD_AT(src, char, 0x1);
}

EXTERN_C void func_800898F0(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
}

EXTERN_C unsigned char *func_800898FC(unsigned char *a, signed char *b)
{
    unsigned char *p = a;
    int n = 9;

    while (--n) {
        int v = *p + *b++;
        if (v <= 0) {
            v = 1;
        } else if (v >= 0x100) {
            v = 0xFF;
        }
        *p++ = v;
    }
    return a;
}

EXTERN_C unsigned char *func_80089954(unsigned char *a, signed char *b)
{
    unsigned char *p = a;
    int n = 9;

    while (--n) {
        int v = *p - *b++;
        if (v <= 0) {
            v = 1;
        } else if (v >= 0x100) {
            v = 0xFF;
        }
        *p++ = v;
    }
    return a;
}

EXTERN_C Col_800899AC *func_800899AC(Col_800899AC *out, Col_800899AC *a, signed char *b)
{
    Col_800899AC t = *a;
    func_800898FC((unsigned char *)&t, b);
    *out = t;
    return out;
}

EXTERN_C Col_800899AC *func_800899FC(Col_800899AC *out, Col_800899AC *a, signed char *b)
{
    Col_800899AC t = *a;
    func_80089954((unsigned char *)&t, b);
    *out = t;
    return out;
}

EXTERN_C Bytes8_80089A4C func_80089A4C(unsigned char *src, int d)
{
    Bytes8_80089A4C r;
    unsigned char *dst = r.b;
    for (unsigned int i = 0; i < 8; i++)
        *dst++ = *src++ / d;
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_80089AC0);

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_80089B44);

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_80089BF4);

EXTERN_C int func_80089D28(void *self)
{
    int cur = FIELD_AT(self, unsigned char, 0x7);
    int prev = 0;
    int r;

    do {
        int t = cur;
        cur += prev;
        prev = t;
        r = rand() & 0xFF;
    } while (cur < r);
    return 0xFF - r;
}

EXTERN_C void func_80089D80(unsigned char *p, int n)
{
    unsigned int i;

    n--;
    for (i = 0; i < 8; i++, p++) {
        if (*p > n) {
            *p = n;
        }
    }
}

EXTERN_C signed char *func_80089DB8(signed char *a, signed char *b)
{
    signed char *p = a;
    int n = 9;

    while (--n) {
        int v = *p + *b++;
        if (v < -0x80) {
            v = -0x80;
        } else if (v >= 0x80) {
            v = 0x7F;
        }
        *p++ = v;
    }
    return a;
}

EXTERN_C signed char *func_80089E14(signed char *a, signed char *b)
{
    signed char *p = a;
    int n = 9;

    while (--n) {
        int v = *p - *b++;
        if (v < -0x80) {
            v = -0x80;
        } else if (v >= 0x80) {
            v = 0x7F;
        }
        *p++ = v;
    }
    return a;
}

EXTERN_C Col_800899AC *func_80089E70(Col_800899AC *out, Col_800899AC *a, signed char *b)
{
    Col_800899AC t = *a;
    func_80089DB8((signed char *)&t, b);
    *out = t;
    return out;
}

EXTERN_C Col_800899AC *func_80089EC0(Col_800899AC *out, Col_800899AC *a, signed char *b)
{
    Col_800899AC t = *a;
    func_80089E14((signed char *)&t, b);
    *out = t;
    return out;
}

EXTERN_C SBytes8_80089F10 func_80089F10(signed char *src, int d)
{
    SBytes8_80089F10 r;
    signed char *dst = r.b;
    for (unsigned int i = 0; i < 8; i++)
        *dst++ = *src++ / d;
    return r;
}

EXTERN_C void func_80089F84(void *self)
{
    func_80023F50((Base1_80089F84 *)FIELD_AT(self, Derived_80089F84 *, 0x4), 0);
    operator delete(self);
}

EXTERN_C void func_80089FC8(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_80089FD0);

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_8008A188);

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_8008A2A0);

EXTERN_C int func_8008A54C(void *self, int b)
{
    char *p = FIELD_AT(self, char *, 0x550);

    if (p != 0) {
        switch (FIELD_AT(p, unsigned char, 0x1B)) {
        case 0x31: case 0x32:
        case 0x4F: case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56:
            return FIELD_AT(p, unsigned char, 0x8C) >= b;
        }
        if (FIELD_AT(FIELD_AT(self, char *, 0x550), unsigned char, 0x8C) == 0) {
            return 1;
        }
        return FIELD_AT(FIELD_AT(self, char *, 0x550), unsigned char, 0x8C) >= b;
    }
    return 0;
}

#define K8C_8008A5C8 FIELD_AT(FIELD_AT(self, char *, 0x550), unsigned char, 0x8C)
static inline int chk_8008A5C8(char *b, char *c)
{
    if (FIELD_AT(c, unsigned char, 0x13) != 5) {
        return 1;
    }
    return (FIELD_AT(b, unsigned char, 0x46D) & FIELD_AT(c, unsigned char, 0x10)) != 0;
}
EXTERN_C int func_8008A5C8(char *self, char *b, char *c)
{
    char *p;
    if (FIELD_AT(b, unsigned char, 0x405) == 0 && (p = FIELD_AT(b, char *, 0x550)) != 0) {
        switch (FIELD_AT(c, unsigned char, 0x1B)) {
        case 15:
            switch (FIELD_AT(p, unsigned char, 0x1B)) {
            case 0x31: case 0x32:
                if (K8C_8008A5C8 != 0) return 0;
                break;
            default:
                return 0;
            }
            break;
        case 12:
            switch (FIELD_AT(p, unsigned char, 0x1B)) {
            case 0x4F: case 0x50:
                if (K8C_8008A5C8 >= 6) return 0;
                break;
            case 0x51:
                if (K8C_8008A5C8 >= 10) return 0;
                break;
            default:
                return 0;
            }
            break;
        case 13:
            switch (FIELD_AT(p, unsigned char, 0x1B)) {
            case 0x52:
                if (K8C_8008A5C8 >= 6) return 0;
                break;
            case 0x54:
                if (K8C_8008A5C8 >= 12) return 0;
                break;
            default:
                return 0;
            }
            break;
        case 14:
            switch (FIELD_AT(p, unsigned char, 0x1B)) {
            case 0x53: case 0x55:
                if (K8C_8008A5C8 >= 2) return 0;
                break;
            case 0x56:
                if (K8C_8008A5C8 >= 6) return 0;
                break;
            default:
                return 0;
            }
            break;
        }
    }
    return chk_8008A5C8(b, c);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_8008A770);

EXTERN_C void func_8008A858(char *self, int b, int c)
{
    FIELD_AT(self, unsigned short, 0x548) = ((T_8008A858 *)self)->e[FIELD_AT(FIELD_AT(self, unsigned char *, 0x498), unsigned char, 7) - 1].hi();
    FIELD_AT(self, short, 0x420) -= FIELD_AT(self, unsigned char, 0x496) << FIELD_AT(self, unsigned short, 0x548);
    func_8008B4E8(&((T_8008A858 *)self)->e[FIELD_AT(FIELD_AT(self, unsigned char *, 0x498), unsigned char, 7) - 1],
                  FIELD_AT(self, unsigned char, 0x497) ? FIELD_AT(self, unsigned char, 0x496) * 10 : FIELD_AT(self, unsigned char, 0x496) * 5);
    FIELD_AT(self, char, 0x496) = 0;
    if (FIELD_AT(self, short, 0x420) < 0) {
        FIELD_AT(self, short, 0x420) = 0;
    }
    func_80086F94(self ? self + 0x400 : 0, (void *)b, c);
}

EXTERN_C void func_8008A93C(void *self, int b, int c, int d)
{
    char *q = 0;
    FIELD_AT(self, int, 0x544) = c;
    if (self != 0) {
        q = (char *)self + 0x400;
    }
    func_800870E4(q, (void *)b, (W20_80089658 *)c, d);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_8008A96C);

EXTERN_C int func_8008AC28(char *self, void *b, int c)
{
    char *a = FIELD_AT(self, char *, 0x550);
    int sum = FIELD_AT(a, unsigned char, 0x8C) + FIELD_AT(FIELD_AT(b, char *, 0x544), unsigned char, 0x8C);
    if (sum <= c) {
        FIELD_AT(a, char, 0x8C) = sum;
        FIELD_AT(FIELD_AT(b, char *, 0x544), char, 0x8C) = 1;
    } else {
        FIELD_AT(a, char, 0x8C) = c;
        FIELD_AT(FIELD_AT(b, char *, 0x544), char, 0x8C) = sum - c + 1;
    }
    FIELD_AT(self, unsigned char, 0x46D) |= 1;
    func_80087C2C(self ? self + 0x400 : 0, b, 0, 0);
    FIELD_AT(self, unsigned char, 0x46D) &= ~1;
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_8008ACC4);

EXTERN_C int func_8008AE38(void *self, void *b)
{
    if (!(FIELD_AT(self, unsigned char, 0x46D) & 2)) {
        FIELD_AT(self, int, 0x54C) += FIELD_AT(b, unsigned short, 0x546);
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_8008AE68);

EXTERN_C void func_8008AFE4(D_8008B084 *self, S_8008B084 *b)
{
    short *d;
    short *s;
    func_800867B0(self ? (char *)self + 0x400 : 0, (Snap_800867B0 *)b);
    unsigned char x = b->a;
    short y = b->b;
    int z = b->c;
    self->a = x;
    self->b = y;
    self->c = z;
    d = self->d;
    s = b->d;
    for (int i = 12; i != 0; i--) {
        *d++ = *s++;
    }
    d = self->e;
    s = b->e;
    for (int i = 16; i != 0; i--) {
        *d++ = *s++;
    }
}

EXTERN_C S_8008B084 *func_8008B084(D_8008B084 *self, S_8008B084 *b)
{
    func_80086814(self ? (char *)self + 0x400 : 0, (Snap_800867B0 *)b);
    unsigned char x = self->a;
    short y = self->b;
    int z = self->c;
    b->a = x;
    b->b = y;
    b->c = z;
    {
        int i;
        for (i = 0; i < 12; i++) {
            b->d[i] = self->d[i];
        }
    }
    {
        int i;
        for (i = 0; i < 16; i++) {
            b->e[i] = self->e[i];
        }
    }
    return b;
}

EXTERN_C int func_8008B130(void *self, int b)
{
    return b * b * 100;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_8008B150);

EXTERN_C void *func_8008B258(void *self, int b, int c)
{
    FIELD_AT(self, void *, 0) = D_80017CB4;
    FIELD_AT(self, int, 4) = b;
    char *o1 = (char *)__builtin_new(0xC);
    FIELD_AT(o1, int, 8) = c;
    FIELD_AT(o1, void *, 0) = D_80010118;
    FIELD_AT(o1, void *, 4) = self;
    Mgr_800A4544 *m = &D_800A4544;
    char *o2 = (char *)__builtin_new(0x14);
    FIELD_AT(o2, void *, 0) = D_80010178;
    FIELD_AT(o2, int, 4) = 0;
    FIELD_AT(o2, void *, 0) = D_80010338;
    FIELD_AT(o2, short, 0xC) = 0x80;
    FIELD_AT(o2, void *, 8) = o1;
    FIELD_AT(o2, int, 0x10) = 1;
    func_8001D150(m, o2);
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80089024", func_8008B30C);

EXTERN_C int func_8008B444(int n)
{
    int mask;
    int r;

    if (n < 2) {
        return 0;
    }
    mask = 0x80000000;
    while (!(n & mask)) {
        mask >>= 1;
    }
    mask = ~(mask << 1);
    do {
        r = rand() & mask;
    } while (r >= n);
    return r;
}

EXTERN_C char *func_8008B4B4(char *self, char *b)
{
    short d = func_8008B444(b - self);
    return (char *)(d + (int)self);
}

EXTERN_C int func_8008B4E8(U16_8008B4E8 *p, int b)
{
    int lo = (p->v & 0x3FF) + b;
    if (lo >= 1000) {
        p->v = lo + (p->v & 0xFC00) + 0x18;
        if (p->hi() >= 3) {
            p->v = 0xBE7;
        } else {
            return 1;
        }
    } else {
        p->v = (p->v & 0xFC00) + lo;
    }
    return 0;
}

EXTERN_C int func_8008B574(unsigned char *p)
{
    return ((p[1] << 8) | p[0]) & 0x3FF;
}

EXTERN_C int func_8008B58C(unsigned char *p)
{
    return ((p[1] << 8) | p[0]) >> 10;
}

EXTERN_C void *func_8008B5A4(void *self)
{
    FIELD_AT(self, char, 0x0) = 0;
    FIELD_AT(self, char, 0x1) = 0;
    return self;
}

EXTERN_C void func_8008B5B4(Unpacked_8008B5B4 *d, Packed_8008B5B4 *s)
{
    int i;

    d->hdr = s->hdr;
    for (i = 0; i < 9; i++) {
        d->e[i].a = s->e[i].a + 0x7547;
        d->e[i].b = s->e[i].b << 11;
    }
}

EXTERN_C Packed_8008B5B4 *func_8008B630(Unpacked_8008B5B4 *s, Packed_8008B5B4 *d)
{
    int i;

    d->hdr = s->hdr;
    for (i = 0; i < 9; i++) {
        d->e[i].a = s->e[i].a - 0x7547;
        d->e[i].b = (unsigned int)s->e[i].b >> 11;
    }
    return d;
}
