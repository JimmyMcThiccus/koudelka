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

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80058B98);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80059790);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80059800);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80059888);

EXTERN_C int func_8005992C(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C void func_80059938(void *self, int flags)
{
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80059958);

EXTERN_C void func_80059A84(void *self)
{
    void *p;
    if (FIELD_AT(self, int, 0x5C) != 0 && FIELD_AT(self, void *, 0x30) != 0) {
        FIELD_AT(self, int, 0x5C) = 0;
        FIELD_AT(self, Iter_B *, 0x30)->i = 0;
        for (p = iter_next_B(FIELD_AT(self, Iter_B *, 0x30)); p != 0; p = iter_next_B(FIELD_AT(self, Iter_B *, 0x30))) {
            func_8005B378(p, 5);
        }
    }
}

EXTERN_C void func_80059B5C(void *self, int b)
{
    VObj0 *p;
    if (FIELD_AT(self, int, 0x8) != 0) {
        FIELD_AT(self, Iter_B *, 0x30)->i = 0;
        for (p = (VObj0 *)iter_next_B(FIELD_AT(self, Iter_B *, 0x30)); p != 0; p = (VObj0 *)iter_next_B(FIELD_AT(self, Iter_B *, 0x30))) {
            p->v11(b);
        }
    }
}

EXTERN_C void func_80059C54(void *self, int i, int flag)
{
    if (FIELD_AT(self, int, 0x8) != 0 && (unsigned int)i < (unsigned int)(FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count) {
        char *v = FIELD_AT(self, char *, 0x38) ? FIELD_AT(self, char *, 0x38) + 8 : 0;
        if (func_8005409C(func_80019F64(v ? *(void **)v : 0, i))) {
            VObj0 *o;
            v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
            o = func_80019F64(v ? *(void **)v : 0, i);
            if (flag) {
                func_8005B378(o, 3);
            } else if (FIELD_AT(self, int, 0x5C) == 0) {
                func_8005B378(o, 5);
            } else {
                func_8005B378(o, 1);
            }
        } else {
            VObj0 *o;
            v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
            o = func_80019F64(v ? *(void **)v : 0, i);
            func_8005B378(o, flag ? 4 : 2);
        }
    }
}

EXTERN_C void func_80059D8C(void *self, int b)
{
    FIELD_AT(self, int, 0x38) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_80059D94);

EXTERN_C int func_80059E90(VObj<0x2C> *self, int b)
{
    int r = self->v11();
    if (r != 0) {
        self->v16(r);
    }
    return 1;
}

EXTERN_C void func_80059EF8(void *self, int b)
{
    FIELD_AT(self, int, 0x60) = b;
}

EXTERN_C int func_80059F00(void *self)
{
    return FIELD_AT(self, int, 0x60);
}

EXTERN_C void func_80059F0C(void *self, int b)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        char t[8];
        VObj0 *p;
        unsigned char c = b;
        func_8002972C(t, c, c, c, 1);
        FIELD_AT(self, Iter_B *, 0x30)->i = 0;
        for (p = (VObj0 *)iter_next_B(FIELD_AT(self, Iter_B *, 0x30)); p != 0; p = (VObj0 *)iter_next_B(FIELD_AT(self, Iter_B *, 0x30))) {
            p->v11(t);
        }
        func_800198AC(t, 2);
    }
}

EXTERN_C void func_8005A020(void *self, int x, int y)
{
    int dx, dy, i;
    if (FIELD_AT(self, short, 0xC) == x && FIELD_AT(self, short, 0xE) == y) {
        return;
    }
    dx = x - FIELD_AT(self, short, 0xC);
    dy = y - FIELD_AT(self, short, 0xE);
    FIELD_AT(self, short, 0xC) = x;
    FIELD_AT(self, short, 0xE) = y;
    if (FIELD_AT(self, int, 0x8) != 0) {
        FIELD_AT(FIELD_AT(self, char *, 0x30), int, 0x4) = 0;
        for (i = (FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count - 1; i >= 0; i--) {
            char *h = FIELD_AT(self, char *, 0x30);
            char *v = h ? h + 8 : 0;
            func_80019F64(v ? *(void **)v : 0, i)->v10(dx, dy);
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005A120);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005A31C);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005A518);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005A62C);

EXTERN_C void func_8005A784(void *self, int b)
{
    if (FIELD_AT(self, int, 0x8) != 0 && (FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count == 5) {
        char t1[8];
        char t2[8];
        unsigned char k = b;
        char *v;
        VObj0 *o;
        func_8002972C(t1, k, k, k, 1);
        v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
        func_80019F64(v ? *(void **)v : 0, 0)->v11(t1);
        func_8002972C(t2, k * 2 - 1, k * 2 - 1, k * 2 - 1, 1);
        v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
        o = func_80019F64(v ? *(void **)v : 0, 1);
        func_800536F0(o, t2);
        o->v06();
        v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
        o = func_80019F64(v ? *(void **)v : 0, 3);
        func_80059888(o, (int)t2);
        o->v06();
        func_800198AC(t2, 2);
        func_800198AC(t1, 2);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005A934);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005ABE0);

EXTERN_C void func_8005AF70(VObj<0x2C> *self)
{
    void *p = FIELD_AT(self, void *, 0x4);
    if (p != 0) {
        C4_8005AF70 t = FIELD_AT(p, C4_8005AF70, 0x10);
        char *h = (char *)self + 0xC;
        char *g = h ? (char *)self + 0x10 : 0;
        FIELD_AT(g, C4_8005AF70, 0x0) = t;
    }
    self->v14();
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005AFF0);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005B0F8);

EXTERN_C void func_8005B2F0(void *self, int b)
{
    FIELD_AT(self, void *, 0x0) = D_80014548;
    if (FIELD_AT(self, void *, 0x1C) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x1C));
    }
    FIELD_AT(self, void *, 0x1C) = 0;
    if (FIELD_AT(self, void *, 0x14) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x14));
    }
    FIELD_AT(self, void *, 0x14) = 0;
    if (FIELD_AT(self, void *, 0x10) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x10));
    }
    FIELD_AT(self, void *, 0x10) = 0;
    func_8005F120(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005B378);

EXTERN_C Pair_8005B424 *func_8005B424(Pair_8005B424 *out, Obj_8005B424 *self)
{
    int i = D_800B4CF0.value;
    short a = self->ents[i].a;
    short b = self->ents[i].b;
    out->a = a;
    out->b = b;
    return out;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005B450);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005B4D8);

EXTERN_C void func_8005B560(Obj_8005B560 *self, int b, int c)
{
    VEnt_8005B560 *vt = self->vt;
    int i = D_800B4CF0.value;
    vt[11].pfn((char *)self + vt[11].delta, b - self->ents[i].a, c - self->ents[i].b);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005B5B4);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005B66C);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005B7A8);

EXTERN_C void func_8005BC7C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005BC84);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005BDA4);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005BF04);

EXTERN_C void func_8005BF48(void)
{
}

EXTERN_C void func_8005BF50(void *self)
{
    if (FIELD_AT(self, void *, 0x8) == 0) {
        FIELD_AT(self, void *, 0x8) = func_8005C26C(operator new(0x34), self, FIELD_AT(self, int, 0x34));
    }
    func_8002A110(self);
}

EXTERN_C void func_8005BFA4(void *self)
{
    func_8005C1E8(self);
}

EXTERN_C void func_8005BFC4(void *self, int b)
{
    func_8005C088(self, b, 1);
}

EXTERN_C void func_8005BFE4(void *self)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        if ((FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count > 0) {
            void *r = (void *)((VObj<0x2C> *)self)->v11();
            if (r != 0) {
                func_8002DD34(r, FIELD_AT(self, void *, 0x30), 0);
                func_8002DA94(r, FIELD_AT(self, void *, 0x30));
            }
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C088);

EXTERN_C void func_8005C1E8(void *self)
{
    int r = ((VObj<0x2C> *)self)->v11();
    if (r != 0) {
        func_8005C088(self, r, 1);
    }
}

EXTERN_C void func_8005C238(V_8005C238 *self)
{
    self->v14();
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C26C);

EXTERN_C void func_8005C2B8(void *self, int b)
{
    char *h;
    FIELD_AT(self, void *, 0x0) = D_800145B0;
    h = (char *)self + 0x10;
    if ((h ? FIELD_AT(h, List *, 0x0) : 0)->count > 0) {
        func_8005C088(FIELD_AT(self, void *, 0x30), func_8002EB68(self), 1);
    }
    FIELD_AT(FIELD_AT(self, void *, 0x30), void *, 0x30) = 0;
    FIELD_AT(self, void *, 0x30) = 0;
    func_800386B8(self, b);
}

EXTERN_C void func_8005C344(void *self)
{
    FIELD_AT(self, V_8005C344 *, 0x30)->v14();
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C380);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C3C4);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C570);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C608);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C6E8);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C77C);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C7EC);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C8B4);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C910);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005C968);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005CA4C);

EXTERN_C void func_8005CB68(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005CB88);

EXTERN_C void func_8005CCB0(void *self, int b)
{
    FIELD_AT(self, SV2_80055020, 0xC) = func_80054054();
    FIELD_AT(self, short, 0x10) = func_8005F87C((void *)b);
    if (func_80054074(b) == 1) {
        FIELD_AT(self, short, 0xC) -= 6;
    } else {
        FIELD_AT(self, short, 0xC) -= FIELD_AT(self, unsigned short, 0x10) + 6;
    }
    ((VObj<0x2C> *)self)->v14();
}

EXTERN_C void func_8005CD5C(void *self, unsigned char c)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        if ((FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count > 0) {
            char t[8];
            char *v;
            func_8002972C(t, c, c, c, 1);
            v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
            func_80019F64(v ? *(void **)v : 0, 0)->v11(t);
            func_800198AC(t, 2);
        }
    }
}

EXTERN_C void func_8005CE1C(void *self, int b)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        List *l;
        void *q;
        func_8005C088(self, b, 1);
        l = FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0;
        q = func_8005D080(__builtin_new(0x88), (char *)self + 0xC, FIELD_AT(self, short, 0x10) - 10, FIELD_AT(self, unsigned short, 0x1C));
        func_80019A6C(l, (int)q, l->count);
        func_8002DA94((void *)b, FIELD_AT(self, void *, 0x30));
    }
}

EXTERN_C void func_8005CEB4(void *self)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        char *h = FIELD_AT(self, char *, 0x30);
        if ((h ? *(List **)h : 0)->count > 0) {
            char *v = h ? h + 8 : 0;
            VObj0 *o = func_80019F64(v ? *(void **)v : 0, 0);
            o->v07(FIELD_AT(self, short, 0xC), FIELD_AT(self, short, 0xE));
            func_8005D228(o, FIELD_AT(self, short, 0x10) < 11 ? 2 : FIELD_AT(self, short, 0x10) - 10);
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005CF78);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005D080);

EXTERN_C void func_8005D228(void *self, int b)
{
    char *p = (char *)self + D_800B4CF0.value * 16;
    FIELD_AT(p, short, 0x74) = b;
    FIELD_AT(p, short, 0x50) = FIELD_AT(p, short, 0x70) + b;
    func_8005F1D8(self);
}

EXTERN_C void func_8005D264(void *self, int dx, int dy)
{
    char *p = (char *)self + D_800B4CF0.value * 16;
    FIELD_AT(p, short, 0x30) += dx;
    FIELD_AT(p, short, 0x32) += dy;
    FIELD_AT(p, short, 0x50) += dx;
    FIELD_AT(p, short, 0x52) += dy;
    FIELD_AT(p, short, 0x70) += dx;
    FIELD_AT(p, short, 0x72) += dy;
    func_8005F1D8(self);
}

EXTERN_C void func_8005D2D8(void *self, unsigned char *c)
{
    char *p = (char *)self + D_800B4CF0.value * 16;
    unsigned char r = c[5];
    unsigned char g = c[6];
    unsigned char b = c[7];
    FIELD_AT(p, unsigned char, 0x2C) = r;
    FIELD_AT(p, unsigned char, 0x2D) = g;
    FIELD_AT(p, unsigned char, 0x2E) = b;
    FIELD_AT(p, unsigned char, 0x4C) = r;
    FIELD_AT(p, unsigned char, 0x4D) = g;
    FIELD_AT(p, unsigned char, 0x4E) = b;
    FIELD_AT(p, unsigned char, 0x6C) = r;
    FIELD_AT(p, unsigned char, 0x6D) = g;
    FIELD_AT(p, unsigned char, 0x6E) = b;
    func_8005F1D8(self);
}

EXTERN_C void func_8005D334(void *self, int b, int c)
{
    VEnt_8005D334 *vt = FIELD_AT(self, VEnt_8005D334 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

EXTERN_C void *func_8005D384(void *self)
{
    return func_8005D754(operator new(0x88), self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005D3B8);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005D624);

EXTERN_C void func_8005D734(void *self, int b)
{
    func_8005D228(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005D754);

EXTERN_C void func_8005D8A4(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005D8C4);

EXTERN_C void func_8005D9D4(void *self, int b)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        char *h = FIELD_AT(self, char *, 0x30);
        if ((h ? *(List **)h : 0)->count == 1) {
            unsigned int c = b;
            if (c >= 0x100) {
                char *v = h ? h + 8 : 0;
                List *l = v ? *(List **)v : 0;
                VObj0 *o = l->count ? **(VObj0 ***)l : 0;
                o->v11(&D_800B4C98);
                v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
                l = v ? *(List **)v : 0;
                func_8005DEA4(l->count ? **(void ***)l : 0, 0);
            } else {
                char t[8];
                char *v;
                List *l;
                VObj0 *o;
                func_8002972C(t, c, c, c, 1);
                v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
                l = v ? *(List **)v : 0;
                o = l->count ? **(VObj0 ***)l : 0;
                o->v11(t);
                func_800198AC(t, 2);
            }
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005DB68);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005DC44);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005DD4C);

EXTERN_C void func_8005DEA4(void *self, int b)
{
    if (b != 0) {
        unsigned char *q = (unsigned char *)(D_800B4CF0.value * 16 + (int)self) + 0x28;
        q[7] = q[7] | 2;
    } else {
        unsigned char *q = (unsigned char *)(D_800B4CF0.value * 16 + (int)self) + 0x28;
        q[7] = q[7] & ~2;
    }
    func_8005F1D8(self);
}

EXTERN_C void func_8005DF10(void *self, int dx, int dy)
{
    Entry_8005DF10 *e = (Entry_8005DF10 *)((char *)self + D_800B4CF0.value * 16);
    e->x += dx;
    e->y += dy;
    func_8005F1D8(self);
}

EXTERN_C void func_8005DF54(void *self, unsigned char *src)
{
    unsigned char r = src[5];
    unsigned char g = src[6];
    unsigned char b = src[7];
    Entry_8005DF54 *e = (Entry_8005DF54 *)((char *)self + D_800B4CF0.value * 16);
    e->rgb[0] = r;
    e->rgb[1] = g;
    e->rgb[2] = b;
    func_8005F1D8(self);
}

EXTERN_C void func_8005DF98(void *self, int b, int c)
{
    VEnt_8005DF98 *vt = FIELD_AT(self, VEnt_8005DF98 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005DFE8);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005E0E0);

EXTERN_C void func_8005E244(void)
{
}

EXTERN_C void func_8005E24C(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005E26C);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005E404);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005E4CC);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005E924);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005EA9C);

EXTERN_C void *func_8005EAFC(void *self)
{
    return func_8005EF58(operator new(0x114), self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005EB30);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005EDF4);

INCLUDE_ASM("asm/main/nonmatchings/u_80056E0C", func_8005EF58);

EXTERN_C void func_8005F090(void *self, int flags)
{
    func_8005F120(self, flags);
}

EXTERN_C void func_8005F0B0(void)
{
    func_8005FC78(&D_800AE640, 0x1434E, 0x10800);
}

EXTERN_C void *func_8005F0E4(void *self, int b)
{
    FIELD_AT(self, void * volatile, 0x0) = D_80010178;
    FIELD_AT(self, void * volatile, 0x0) = D_800111BC;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, short, 0x8) = 0;
    FIELD_AT(self, short, 0xA) = b;
    FIELD_AT(self, void * volatile, 0x0) = D_80014BD0;
    FIELD_AT(self, int, 0xC) = 0;
    return self;
}

EXTERN_C void func_8005F120(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80014BD0;
    func_8001A610(self, flags);
}

EXTERN_C void func_8005F148(VObj0 *self, short *v)
{
    self->v07(v[0], v[1]);
    self->v08(v[2], v[3]);
}

EXTERN_C int func_8005F1B4(void *self)
{
    if (FIELD_AT(self, int, 0xC) != 0) {
        FIELD_AT(self, int, 0xC) = 0;
        return 1;
    }
    return 0;
}

EXTERN_C void func_8005F1D8(void *self)
{
    FIELD_AT(self, int, 0xC) = 1;
}

EXTERN_C void func_8005F1E4(void)
{
}

EXTERN_C void func_8005F1EC(void)
{
    func_8005FB04(&D_800AE640, 2);
}

EXTERN_C void func_8005F214(void)
{
    func_8005F8EC(&D_800AE640);
}
