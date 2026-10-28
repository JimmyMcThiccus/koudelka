#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80056E0C);

EXTERN_C void func_80056F9C(void *self, int a, int b)
{
    FIELD_AT(self, int, 0xA0) = 0;
    func_8005717C(self, a, b);
}

EXTERN_C void func_80056FBC(void *self, int a, int b)
{
    FIELD_AT(self, int, 0xA0) = 1;
    func_8005717C(self, a, b);
}

EXTERN_C void func_80056FE0(void *self)
{
    func_8005388C(self ? (char *)self + 0x50 : 0, FIELD_AT(self, int, 0x9C));
}

EXTERN_C int func_80057010(void *self)
{
    int c;
    if (func_80053874(self ? (char *)self + 0x50 : 0) >= 5) {
        if (FIELD_AT(self, int, 0xA0) != 0) {
            c = (FIELD_AT(self, int, 0x9C) - func_80053874(self ? (char *)self + 0x50 : 0)) * 255 / FIELD_AT(self, int, 0x9C);
        } else {
            c = func_80053874(self ? (char *)self + 0x50 : 0) * 255 / FIELD_AT(self, int, 0x9C);
        }
        func_8005D9D4((char *)self + 0x5C, c);
    } else {
        func_8005D9D4((char *)self + 0x5C, (FIELD_AT(self, int, 0xA0) != 0) << 8);
    }
    if (func_80053830(self ? (char *)self + 0x50 : 0)) {
        return 1;
    }
    if (FIELD_AT(self, int, 0xA4) != 0) {
        func_8005549C(0, self, 0, -1);
    }
    if (FIELD_AT(self, int, 0xA8) != 0) {
        func_8002B27C(D_800A4578.p, self);
    }
    return 0;
}

EXTERN_C void func_80057150(void *self)
{
    func_8002A210(self);
    func_80056FE0(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005717C);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80057214);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80057368);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80057558);

EXTERN_C void func_800576A8(void *self)
{
    if (FIELD_AT(self, void *, 0x8) == 0) {
        FIELD_AT(self, void *, 0x8) = func_8002EEC4(operator new(0x14), self);
    }
    func_8002BA94(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_800576F8);

EXTERN_C void func_8005783C(short v)
{
    if (v >= 3) {
        D_800B4DA8 = v;
    } else {
        D_800B4DA8 = 8;
    }
    D_800B4DAA = D_800B4DA8 - 2;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80057878);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80057C7C);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80057F20);

EXTERN_C void func_80057FEC(void *self, int b)
{
    func_80059B5C((char *)self + 0x5C, b);
}

EXTERN_C void func_8005800C(void *self, void *b)
{
    char *h = (char *)self + 0x110;
    List *l = h ? *(List **)h : 0;
    func_80019A6C(l, (int)b, l->count);
    ((VObj<0x2C> *)self)->v29(b, -1);
    ((VObj<0x2C> *)b)->v27();
    ((VObj<0x2C> *)b)->v03();
}

EXTERN_C void func_800580B0(void *self, int b)
{
    VObj<0x2C> *o = FIELD_AT(self, VObj<0x2C> *, 0x108);
    if (o != 0) {
        if (b) {
            o->v03();
            func_8005BFA4((char *)self + 0x5C);
            func_8002A210((char *)self + 0x5C);
            func_80059C54((char *)self + 0x5C, FIELD_AT(self, int, 0x138), 1);
        } else {
            o->v04();
            func_80059C54((char *)self + 0x5C, FIELD_AT(self, int, 0x138), 0);
            FIELD_AT(self, int, 0x138) = 0;
            FIELD_AT(self, int, 0x134) = 0;
        }
    }
}

EXTERN_C void func_8005816C(void *self, int b)
{
    char *p = (char *)self + 0x5C;
    func_80059C54(p, FIELD_AT(self, int, 0x138), 0);
    FIELD_AT(self, int, 0x138) = b;
    func_80059C54(p, b, 1);
    func_8005CCB0(FIELD_AT(self, void *, 0x108), func_80059D94(p, FIELD_AT(self, int, 0x138)));
}

EXTERN_C void func_800581E0(void *self)
{
    func_8005BFA4((char *)self + 0xC8);
    func_80059A84((char *)self + 0x5C);
    if (FIELD_AT(self, void *, 0x108) == 0) {
        func_80059C54((char *)self + 0x5C, FIELD_AT(self, int, 0x138), 0);
    } else {
        func_80059C54((char *)self + 0x5C, FIELD_AT(self, int, 0x138), 1);
        FIELD_AT(self, VObj<0x2C> *, 0x108)->v28(0x40);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80058270);

EXTERN_C int func_80058404(void *self, int b)
{
    if (FIELD_AT(self, int, 0x140) == 0 && FIELD_AT(self, int, 0x150) > 0) {
        func_80058270(self, b);
        FIELD_AT(self, int, 0x154) = -b * D_800B4DA6;
        func_8005388C(self ? (char *)self + 0x50 : 0, -1);
        FIELD_AT(self, int, 0x140) = 3;
    }
    return FIELD_AT(self, int, 0x138);
}

EXTERN_C int func_80058488(void *self, int b)
{
    int v;
    int n;
    func_80059C54((char *)self + 0x5C, FIELD_AT(self, int, 0x138), 0);
    FIELD_AT(self, int, 0x134) = b > 0 ? D_800B4DA8 - 1 : 1;
    v = D_800B4DA8;
    n = FIELD_AT(self, int, 0x138) + b * (v - 2);
    FIELD_AT(self, int, 0x138) = n;
    if (n <= 0) {
        FIELD_AT(self, int, 0x134) = 0;
        FIELD_AT(self, int, 0x138) = 0;
    } else if ((unsigned int)n >= FIELD_AT(self, unsigned int, 0x130)) {
        FIELD_AT(self, int, 0x134) = v - 1;
        FIELD_AT(self, int, 0x138) = FIELD_AT(self, int, 0x130) - 1;
    } else {
        func_8008EF40(9);
    }
    func_80058A80(self);
    return FIELD_AT(self, int, 0x138);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005854C);

EXTERN_C int func_800585F4(void *self)
{
    int v = FIELD_AT(self, int, 0x140);
    if (v > 0) {
        if (v >= 3) {
            if (v == 3) {
                return func_80058B98(self);
            }
        } else {
            return func_80058C5C(self);
        }
    }
    FIELD_AT(self, int, 0x140) = 0;
    return 0;
}

EXTERN_C void func_80058654(void *self)
{
    if (FIELD_AT(self, int, 0x140) != 0) {
        int n;
        func_80055624((char *)self + 0x50, 0);
        n = func_80053874(self ? (char *)self + 0x50 : 0) - 1;
        if ((unsigned int)(FIELD_AT(self, int, 0x140) - 1) < 2) {
            int i;
            for (i = 0; i < n; i++) {
                func_80058C5C(self);
            }
            func_80053848(self ? (char *)self + 0x50 : 0);
            func_80058C5C(self);
            FIELD_AT(self, int, 0x140) = 0;
        } else {
            func_80053848(self ? (char *)self + 0x50 : 0);
            FIELD_AT(self, int, 0x140) = 0;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80058728);

EXTERN_C void func_80058830(void *self, void *b)
{
    char *s = (char *)self + 0x5C;
    func_8005BFA4(s);
    func_8005A020(s, 0, 0);
    func_80059E90((VObj<0x2C> *)s, (int)b);
    if (func_80059F00(s)) {
        ((VObj<0x2C> *)self)->v14();
    } else {
        func_80058A80(self);
    }
}

EXTERN_C void func_800588C8(void *self)
{
    func_80059EF8((char *)self + 0x5C, 1);
}

EXTERN_C void func_800588EC(void *self, unsigned int b)
{
    FIELD_AT(self, unsigned int, 0x130) = b;
    if (b - 1 < FIELD_AT(self, unsigned int, 0x138)) {
        FIELD_AT(self, unsigned int, 0x138) = b - 1;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80058910);

EXTERN_C void func_80058A04(void *self)
{
    if (FIELD_AT(self, void *, 0x108) != 0) {
        char *p = (char *)self + 0x5C;
        func_80059C54(p, FIELD_AT(self, int, 0x138), 1);
        func_8005CCB0(FIELD_AT(self, void *, 0x108), func_80059D94(p, FIELD_AT(self, int, 0x138)));
        if (FIELD_AT(self, void *, 0x10C) != 0) {
            func_80058F08(FIELD_AT(self, VObj<0x2C> *, 0x10C), FIELD_AT(self, int, 0x138));
        }
    }
}

EXTERN_C void func_80058A80(void *self)
{
    int s = 0;
    int i = 1;
    unsigned int old = FIELD_AT(self, unsigned int, 0x134);
    int n = FIELD_AT(self, int, 0x138);
    FIELD_AT(self, int, 0x150) = 0;
    FIELD_AT(self, int, 0x134) = 0;
    if (n > 0) {
        int a = D_800B4DAA;
        int b = D_800B4DA8;
        int m = n;
        do {
            if (FIELD_AT(self, int, 0x134) == a && !(FIELD_AT(self, unsigned int, 0x130) - (b - FIELD_AT(self, int, 0x134)) < (unsigned int)i)) {
                s += 13;
            } else {
                FIELD_AT(self, int, 0x134)++;
            }
            i++;
        } while (i <= m);
    }
    if (old < FIELD_AT(self, unsigned int, 0x134)) {
        s += (FIELD_AT(self, int, 0x134) - old) * 13;
        FIELD_AT(self, int, 0x134) = old;
    }
    func_8005A020((char *)self + 0x5C, 0, 0);
    if (s > 0) {
        func_8005BF04((char *)self + 0x5C, 0, -s);
    }
    ((VObj<0x2C> *)self)->v14();
}

EXTERN_C int func_80058B98(void *self)
{
    int ret = 1;
    if (D_800B4DA6 < FIELD_AT(self, int, 0x150)) {
        func_8005BF04((char *)self + 0x5C, 0, FIELD_AT(self, int, 0x154));
        FIELD_AT(self, int, 0x150) -= D_800B4DA6;
    } else {
        if (FIELD_AT(self, int, 0x150) > 0) {
            if (FIELD_AT(self, int, 0x154) > 0) {
                func_8005BF04((char *)self + 0x5C, 0, FIELD_AT(self, int, 0x150));
            } else {
                func_8005BF04((char *)self + 0x5C, 0, -FIELD_AT(self, int, 0x150));
            }
            FIELD_AT(self, int, 0x150) = 0;
        }
        FIELD_AT(self, int, 0x140) = 0;
        ret = 0;
    }
    ((VObj<0x2C> *)self)->v14();
    return ret;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80058C5C);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80058D98);

EXTERN_C void func_80058EE8(void *self, int lo, int hi)
{
    if (lo >= hi) {
        FIELD_AT(self, int, 0x38) = lo;
        FIELD_AT(self, int, 0x3C) = hi;
        FIELD_AT(self, int, 0x40) = hi;
    }
}

EXTERN_C void func_80058F08(VObj<0x2C> *self, int b)
{
    if (b >= FIELD_AT(self, int, 0x3C) && b <= FIELD_AT(self, int, 0x38)) {
        FIELD_AT(self, int, 0x40) = b;
        self->v14(b);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80058F68);

EXTERN_C void func_80059300(void *self)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        char *h = FIELD_AT(self, char *, 0x30);
        if ((h ? FIELD_AT(h, List *, 0x0) : 0)->count > 0) {
            char *v = h ? h + 8 : 0;
            func_80019F64(v ? *(void **)v : 0, 4)->v07(4, FIELD_AT(self, int, 0x40) * 2 + 8);
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_800593A0);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_800594A8);

EXTERN_C Obj_80059584 *func_80059584(Obj_80059584 *self, Obj_80059584 *out)
{
    V_80059584 *s;
    V_80059584 *d;
    int i;
    func_80027FEC(self, out);
    d = out->v;
    i = 1;
    s = self->v;
    do {
        *d = *s;
        d++;
        s++;
        i--;
    } while (i != -1);
    return out;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_800595F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_800596A4);

EXTERN_C void func_80059790(void *self)
{
    if (FIELD_AT(self, short, 8) != 0) {
        int i = D_800B4CF0_w;
        ((Q16o *)((char *)self + ((i ^ 1) << 4)))->q = ((Q16o *)((char *)self + (i << 4)))->q;
    }
    func_80028184(self);
}

EXTERN_C void func_80059800(void *self, int a, int b, int c, int d)
{
    if (FIELD_AT(self, short, 8) == 1) {
        int i = D_800B4CF0_w;
        ((Q16o *)((char *)self + (i << 4)))->q = ((Q16o *)((char *)self + ((i ^ 1) << 4)))->q;
    }
    short *p = (short *)((char *)self + (D_800B4CF0_w << 4));
    p[0xA] = a;
    p[0xB] = b;
    p[0xC] = c;
    p[0xD] = d;
    FIELD_AT(self, short, 8) = 2;
}

EXTERN_C void func_80059888(void *self, unsigned char *c)
{
    if (FIELD_AT(self, short, 8) == 1) {
        int i = D_800B4CF0_w;
        ((Q16o *)((char *)self + (i << 4)))->q = ((Q16o *)((char *)self + ((i ^ 1) << 4)))->q;
    }
    *((unsigned char *)self + (D_800B4CF0_w << 4) + 0x10) = c[5];
    *((unsigned char *)self + (D_800B4CF0_w << 4) + 0x11) = c[6];
    *((unsigned char *)self + (D_800B4CF0_w << 4) + 0x12) = c[7];
    FIELD_AT(self, short, 8) = 2;
}

EXTERN_C int func_8005992C(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C void func_80059938(void *self, int flags)
{
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80059958);
