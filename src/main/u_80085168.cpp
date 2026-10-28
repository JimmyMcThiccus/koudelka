#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"
#include "game/b2/b2.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_80085168);

EXTERN_C void func_800852A0(void *self, int b)
{
    func_800852DC(self, b);
    func_80042838(self, b);
}

EXTERN_C void func_800852DC(void *self, int b)
{
    short v = FIELD_AT(self, short, 0x4E2);
    if (v == 0) {
        func_80085168(self, b);
    } else if (v == 1) {
        func_80084F58(self, b);
    } else if (v == 2) {
        func_80084D58(self, b);
    }
}

EXTERN_C void func_8008533C(void *self, int a, int b)
{
    if (func_80043700(self, (short)a, self, b == 0)) {
        int d = a + 0xF;
        char *p = (char *)func_8001CA10(0x14);
        FIELD_AT(p, void *, 0x0) = D_80010178;
        FIELD_AT(p, int, 0x4) = 0;
        FIELD_AT(p, void *, 0x0) = D_80010300;
        FIELD_AT(p, short, 0x8) = 2;
        FIELD_AT(p, short, 0xA) = 8;
        FIELD_AT(p, int, 0x10) = d;
        FIELD_AT(p, int, 0xC) = 0;
        FIELD_AT(p, void *, 0x0) = D_800102D0;
        func_8001EFE4(self, p);
    }
}

EXTERN_C void func_800853D8(void *self, int a, int c)
{
    if (a < 0) {
        func_800451A8(D_800B4D38_w, FIELD_AT(self, short, 0x4BE));
        FIELD_AT(self, int, 0x13C) = 0;
        FIELD_AT(self, short, 0x118) = -2;
    } else {
        func_80045120(D_800B4D38_w, FIELD_AT(self, short, 0x4BE), (short)a);
        if (c == 0) {
            FIELD_AT(self, int, 0x13C) = 0;
        }
    }
}

EXTERN_C void func_80085454(void *self, int b)
{
    func_8004377C(self, b);
}

EXTERN_C void func_80085478(void *self, int b)
{
    func_80043740(self, b);
}

EXTERN_C void func_8008549C(void *self, short b, short c, short d)
{
    func_800437A4(self, b);
    func_800437CC(self, c, d, 0);
}

struct V4_800854FC {
    int x, y, z, w;
    V4_800854FC(int a, int b, int c, int d) { x = a; y = b; z = c; w = d; }
};

EXTERN_C void func_800854FC(void *self, int b, int c, int d)
{
    void *p;
    V4_800854FC v(b, c, d, 0);
    p = FIELD_AT(self, void *, 0x1B8);
    FIELD_AT(p, V4_800854FC, 0x34) = v;
    func_80039DD8(p);
}

EXTERN_C void func_80085554(void *self, int b, int c)
{
    FIELD_AT(self, char, 0x4E0) = 1;
    func_800435AC(self, b, c);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_80085578);

EXTERN_C void func_80085614(void *self, short b, int c)
{
    void *p = FIELD_AT(self, void *, 0x1B8);
    if (p != 0) {
        func_8003D68C(FIELD_AT(p, void *, 0x68), c ? 2 : 1, self, b, 0);
        FIELD_AT(self, char, 0x4E1) = 1;
    }
}

EXTERN_C void func_80085670(void *self, short b, int c, int d)
{
    void *p = FIELD_AT(self, void *, 0x1B8);
    if (p != 0) {
        void *s = func_8003912C(p, b);
        if (s != 0) {
            void *o = func_8003CEB4(__builtin_new(0x30), s);
            func_8003D68C(o, d ? 1 : 2, self, c, 1);
            FIELD_AT(self, char, 0x4E1) = 1;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_80085710);

EXTERN_C void func_800857A0(void)
{
}

EXTERN_C void func_800857A8(int b)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x32C);
    if (p != 0) {
        func_800CDAC8(p, b);
    }
}

EXTERN_C void func_800857E4(int b)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x32C);
    if (p != 0) {
        func_800CDAE8(p, b);
    }
}

EXTERN_C void func_80085820(Derived_80085820 *self)
{
    func_800832F0((Base1_80085820 *)self);
    func_800CF2D0(FIELD_AT(D_800AF470.p, void *, 0x32C), FIELD_AT(self, signed char, 0x4BC) - 3);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_8008586C);

EXTERN_C void *func_80085A08(void *self, S8_80085A08 s, int d)
{
    if (FIELD_AT(self, signed char, 0x4C4) != 0) {
        return 0;
    }
    FIELD_AT(self, S8_80085A08, 0x4C6) = s;
    FIELD_AT(self, char, 0x4C5) = d;
    FIELD_AT(self, char, 0x4C4) = 1;
    return self;
}

EXTERN_C void func_80085A58(void *self)
{
    FIELD_AT(self, char, 0x4C4) = 0;
}

EXTERN_C int func_80085A60(void *self, Pair_80085A60 v)
{
    if (FIELD_AT(self, signed char, 0x4C4) == 0) {
        return 0;
    }
    FIELD_AT(self, short, 0x4C6) = v.a;
    FIELD_AT(self, short, 0x4CA) = v.b;
    return 1;
}

EXTERN_C void *func_80085A98(void *self)
{
    func_80074E28(self);
    FIELD_AT(self, short, 0xC) = 0;
    FIELD_AT(self, short, 0xE) = 0;
    FIELD_AT(self, void *, 0x8) = D_80017BA4;
    return self;
}

EXTERN_C void *func_80085AD4(void *self, int b, int c)
{
    func_80074E28(self);
    FIELD_AT(self, short, 0xC) = b;
    FIELD_AT(self, short, 0xE) = c;
    FIELD_AT(self, void *, 0x8) = D_80017BA4;
    return self;
}

EXTERN_C void *func_80085B28(void *self, S4_80085B28 *b)
{
    func_80074E28(self);
    FIELD_AT(self, S4_80085B28, 0xC) = *b;
    FIELD_AT(self, void *, 0x8) = D_80017BA4;
    return self;
}

EXTERN_C void func_80085B7C(void *self, int b)
{
    FIELD_AT(self, void *, 0x8) = D_80017BA4;
    func_80074E44(self, b);
}

EXTERN_C void *func_80085BA4(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_80017B94;
    return self;
}

EXTERN_C void func_80085BD8(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_80017B94;
    func_80074F78(self, b);
}

EXTERN_C void func_80085C00(void *self)
{
    if (FIELD_AT(self, signed char, 0x4AD)) {
        func_80085D7C((Derived_80085D7C *)self);
    } else if (FIELD_AT(self, signed char, 0x4AE)) {
        func_80085DC0(self);
    } else {
        func_80085C60(self, 0);
    }
}

EXTERN_C void func_80085C60(void *self, int b)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        if (FIELD_AT(self, short, 0x410) == 0) {
            if (b == 0) {
                func_8008299C(self ? (char *)self + 0x2A0 : 0, 1, 0x13, 0, 0, 0, 0);
                return;
            }
        } else if (FIELD_AT(self, short, 0x412) / FIELD_AT(self, short, 0x410) > 10) {
            func_8008299C(self ? (char *)self + 0x2A0 : 0, 1, 1, 0, 0, 0, 0);
            return;
        }
    } else if (FIELD_AT(self, short, 0x410) == 0 && b == 0) {
        func_8008299C(self ? (char *)self + 0x2A0 : 0, 1, 0x13, 0, 0, 0, 0);
        return;
    }
    func_8008299C(self ? (char *)self + 0x2A0 : 0, 1, 0, 0, 0, 0, 0);
}

EXTERN_C void func_80085D7C(Derived_80085D7C *self)
{
    func_8008299C((Base1_80085D7C *)self, 1, 0x11, 0, 0, 0, 0);
}

EXTERN_C void func_80085DC0(void *self)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        func_8008299C((Base1_80085DC0 *)(Derived_80085DC0 *)self, 1, 0x14, 0, 0, 0, 0);
    }
}

EXTERN_C void func_80085E14(void *self)
{
    if (FIELD_AT(self, signed char, 0x4AD)) {
        func_80085F90((Derived_80085F90 *)self);
    } else if (FIELD_AT(self, signed char, 0x4AE)) {
        func_80085FD4(self);
    } else {
        func_80085E74(self, 0);
    }
}

EXTERN_C void func_80085E74(void *self, int b)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        if (FIELD_AT(self, short, 0x410) == 0) {
            if (b == 0) {
                func_8008299C(self ? (char *)self + 0x2A0 : 0, 2, 0x13, 0, 0, 0, 0);
                return;
            }
        } else if (FIELD_AT(self, short, 0x412) / FIELD_AT(self, short, 0x410) > 10) {
            func_8008299C(self ? (char *)self + 0x2A0 : 0, 2, 1, 0, 0, 0, 0);
            return;
        }
    } else if (FIELD_AT(self, short, 0x410) == 0 && b == 0) {
        func_8008299C(self ? (char *)self + 0x2A0 : 0, 2, 0x13, 0, 0, 0, 0);
        return;
    }
    func_8008299C(self ? (char *)self + 0x2A0 : 0, 2, 0, 0, 0, 0, 0);
}

EXTERN_C void func_80085F90(Derived_80085F90 *self)
{
    func_8008299C((Base1_80085F90 *)self, 2, 0x11, 0, 0, 0, 0);
}

EXTERN_C void func_80085FD4(void *self)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        func_8008299C((Base1_80085FD4 *)(Derived_80085FD4 *)self, 2, 0x14, 0, 0, 0, 0);
    }
}

EXTERN_C void func_80086028(void *self)
{
    if (FIELD_AT(self, signed char, 0x4AD)) {
        func_800861A4((Derived_800861A4 *)self);
    } else if (FIELD_AT(self, signed char, 0x4AE)) {
        func_800861E8(self);
    } else {
        func_80086088(self, 0);
    }
}

EXTERN_C void func_80086088(void *self, int b)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        if (FIELD_AT(self, short, 0x410) == 0) {
            if (b == 0) {
                func_8008299C(self ? (char *)self + 0x2A0 : 0, 3, 0x13, 0, 0, 0, 0);
                return;
            }
        } else if (FIELD_AT(self, short, 0x412) / FIELD_AT(self, short, 0x410) > 10) {
            func_8008299C(self ? (char *)self + 0x2A0 : 0, 3, 1, 0, 0, 0, 0);
            return;
        }
    } else if (FIELD_AT(self, short, 0x410) == 0 && b == 0) {
        func_8008299C(self ? (char *)self + 0x2A0 : 0, 3, 0x13, 0, 0, 0, 0);
        return;
    }
    func_8008299C(self ? (char *)self + 0x2A0 : 0, 3, 0, 0, 0, 0, 0);
}

EXTERN_C void func_800861A4(Derived_800861A4 *self)
{
    func_8008299C((Base1_800861A4 *)self, 3, 0x11, 0, 0, 0, 0);
}

EXTERN_C void func_800861E8(void *self)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        func_8008299C((Base1_800861E8 *)(Derived_800861E8 *)self, 3, 0x14, 0, 0, 0, 0);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_8008623C);

EXTERN_C int func_80086288(void *self)
{
    return FIELD_AT(self, int, 0x540);
}

EXTERN_C void func_80086294(void *self, int b)
{
    FIELD_AT(self, int, 0x540) = b;
}

EXTERN_C short func_8008629C(void *self)
{
    return FIELD_AT(self, short, 0x53E);
}

EXTERN_C void func_800862A8(void *self, int b)
{
    FIELD_AT(self, short, 0x53E) = b;
}

EXTERN_C int func_800862B0(void *self, int b)
{
    return (b % 7) << 9;
}

EXTERN_C int func_800862E4(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C signed char func_80086300(void *self)
{
    return FIELD_AT(self, signed char, 0x4C5);
}

EXTERN_C void func_8008630C(void *self, int b)
{
    FIELD_AT(self, char, 0x4C5) = b;
}

EXTERN_C short func_80086314(void *self)
{
    return FIELD_AT(self, short, 0x4C8);
}

EXTERN_C short func_80086320(void *self)
{
    return FIELD_AT(self, short, 0x4CA);
}

EXTERN_C short func_8008632C(void *self)
{
    return FIELD_AT(self, short, 0x4C6);
}

EXTERN_C Pair_80086338 *func_80086338(Pair_80086338 *out, void *self)
{
    short a = FIELD_AT(self, short, 0x4C6);
    short b = FIELD_AT(self, short, 0x4CA);
    out->a = a;
    out->b = b;
    return out;
}

EXTERN_C void func_80086350(void *self, Pair_80086350 *out)
{
    short a = FIELD_AT(self, short, 0x4C6);
    short b = FIELD_AT(self, short, 0x4CA);
    Pair_80086350 tmp;
    tmp.a = a;
    tmp.b = b;
    *out = tmp;
}

EXTERN_C Quad_80086380 *func_80086380(Quad_80086380 *out, void *self)
{
    *out = FIELD_AT(self, Quad_80086380, 0x4C6);
    return out;
}

EXTERN_C int func_800863AC(void *self)
{
    return FIELD_AT(self, signed char, 0x4C4) != 0;
}

EXTERN_C signed char func_800863B8(void *self)
{
    return FIELD_AT(self, signed char, 0x4BD);
}

EXTERN_C signed char func_800863C4(void *self)
{
    return FIELD_AT(self, signed char, 0x4BC);
}

EXTERN_C void func_800863D0(void *self)
{
    FIELD_AT(self, Vec_800863D0, 0x190) = FIELD_AT(FIELD_AT(self, void *, 0x1B8), Vec_800863D0, 0x34);
}

EXTERN_C short func_80086400(void *self)
{
    return FIELD_AT(self, short, 0x4BE);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_8008640C);

EXTERN_C void func_80086454(void *self, int b)
{
    FIELD_AT(self, char, 0x4BC) = b;
}

EXTERN_C short func_8008645C(void *self)
{
    return FIELD_AT(self, short, 0x4E2);
}

EXTERN_C void func_80086468(void *self, int b, int c)
{
    FIELD_AT(self, short, 0x500) = b;
    FIELD_AT(self, short, 0x502) = 0;
    FIELD_AT(self, short, 0x504) = 0;
    FIELD_AT(self, char, 0x506) = c;
}

EXTERN_C short func_8008647C(Obj_8008647C *self, int i)
{
    return self->items[i];
}

EXTERN_C int func_80086490(void *self)
{
    return FIELD_AT(self, int, 0x4D8);
}

EXTERN_C int func_8008649C(void *self)
{
    return FIELD_AT(self, int, 0x4D4);
}

EXTERN_C void func_800864A8(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x4D4) = b;
    FIELD_AT(self, int, 0x4D8) = c;
}

EXTERN_C int func_800864B4(void *self)
{
    return FIELD_AT(self, int, 0x4D0);
}

EXTERN_C void func_800864C0(void *self)
{
    VObj<8> *p;
    while ((p = (VObj<8> *)func_800751AC(self)) != 0) {
        p->v00(3);
    }
}

EXTERN_C void func_80086518(void *self, short *b)
{
    FIELD_AT(self, short, 0xC) = (FIELD_AT(self, short, 0xC) + b[0]) / 2;
    FIELD_AT(self, short, 0xE) = (FIELD_AT(self, short, 0xE) + b[1]) / 2;
}

EXTERN_C void func_8008655C(short *p)
{
    int i;

    for (i = 5; i != 0; i--) {
        *p++ = 0;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_80086578);

EXTERN_C Vec_80086670 func_80086670(Vec_80086670 &a, void *b)
{
    Vec_80086670 t = a;
    func_80086578(&t, b);
    return t;
}

EXTERN_C int func_800866F0(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x8) & b;
}

EXTERN_C int func_800866FC(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x6) & b;
}

EXTERN_C int func_80086708(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x4) & b;
}

EXTERN_C int func_80086714(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x2) & b;
}

EXTERN_C int func_80086720(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x0) & b;
}

EXTERN_C void *func_8008672C(char *p)
{
    void *r = 0;
    if (p != 0) {
        r = p - 0x400;
    }
    return r;
}

EXTERN_C void *func_80086740(void *self)
{
    FIELD_AT(self, void *, 0x9C) = D_80017C00;
    func_8001AA28((char *)self + 4, 0x25);
    return self;
}

EXTERN_C void func_8008677C(void *self, int flags)
{
    FIELD_AT(self, void *, 0x9C) = D_80017C00;
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_800867B0(void *self, Snap_800867B0 *s)
{
    unsigned short a = s->unk0;
    unsigned short b = s->unk2;
    int c = s->unk4;
    int d = s->unk8;

    FIELD_AT(self, unsigned short, 0x4) = a;
    FIELD_AT(self, unsigned short, 0x7C) = b;
    FIELD_AT(self, int, 0x10) = c;
    FIELD_AT(self, int, 0x20) = d;
    FIELD_AT(self, Pair_800867B0, 0x24) = s->unkC;
    FIELD_AT(self, Vec_80086670, 0x44) = s->unk14;
    FIELD_AT(self, unsigned char, 0x6C) = s->unk1E;
}

EXTERN_C Snap_800867B0 *func_80086814(void *self, Snap_800867B0 *s)
{
    unsigned short a = FIELD_AT(self, unsigned short, 0x4);
    unsigned short b = FIELD_AT(self, unsigned short, 0x7C);
    int c = FIELD_AT(self, int, 0x10);
    int d = FIELD_AT(self, int, 0x20);

    s->unk0 = a;
    s->unk2 = b;
    s->unk4 = c;
    s->unk8 = d;
    s->unkC = FIELD_AT(self, Pair_800867B0, 0x24);
    s->unk14 = FIELD_AT(self, Vec_80086670, 0x44);
    s->unk1E = FIELD_AT(self, unsigned char, 0x6C);
    return s;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_8008687C);

EXTERN_C void func_8008691C(void *self)
{
    FIELD_AT(self, Vec_80086670, 0x62) = func_80086670(func_80086670(FIELD_AT(self, Vec_80086670, 0x44), (char *)self + 0x4E), (char *)self + 0x58);
}

EXTERN_C void func_80086990(void *self, int n, signed char *first, ...)
{
    signed char **pp;
    func_800898F0((char *)self + 0x2C);
    for (pp = &first; n != 0; n--) {
        if (*pp != 0) {
            func_80089DB8((signed char *)self + 0x2C, *pp);
        }
        pp++;
    }
    ((VObj<0x9C> *)self)->v01();
}

EXTERN_C void func_80086A20(char *self)
{
    func_8008687C(self, 0);
    func_8008691C(self);
    short m = FIELD_AT(self, unsigned char, 0x3D) * FIELD_AT(self, unsigned char, 0x3D);
    FIELD_AT(self, short, 0x12) = m;
    if (m < FIELD_AT(self, short, 0x10)) {
        FIELD_AT(self, short, 0x10) = m;
    }
    short n = FIELD_AT(self, unsigned char, 0x40) * FIELD_AT(self, unsigned char, 0x40) / 10;
    FIELD_AT(self, short, 0x22) = n;
    if (n < FIELD_AT(self, short, 0x20)) {
        FIELD_AT(self, short, 0x20) = n;
    }
    unsigned int x = FIELD_AT(self, unsigned char, 0x6D);
    int nw = x & ~FIELD_AT(self, unsigned char, 0x6C);
    FIELD_AT(self, unsigned char, 0x6D) = nw;
    if ((unsigned char)x != nw) {
        int diff = x ^ nw;
        if (diff & 0x80) {
            FIELD_AT(self, char, 0x78) = 0;
            ((VObj<0x9C> *)self)->v15(0);
        }
        if (diff & 0x40) {
            FIELD_AT(self, char, 0x79) = 0;
        }
        if (diff & 0x20) {
            FIELD_AT(self, char, 0x7A) = 0;
        }
        if (diff & 2) {
            func_80086B70(self, 1);
        }
        ((VObj<0x9C> *)self)->v17(0, (unsigned char)x, FIELD_AT(self, unsigned char, 0x6D));
    }
}

EXTERN_C void func_80086B70(void *self, int v)
{
    int n;
    if (v < -0x7FFF) {
        v = -0x7FFF;
    } else if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    if (FIELD_AT(self, unsigned short, 0x14) & 0x200) {
        v /= 2;
        if (!(-v < FIELD_AT(self, short, 0x10))) {
            v = -FIELD_AT(self, short, 0x10) + 1;
        }
    }
    if (FIELD_AT(self, unsigned char, 0x6D) & 1) {
        if (!(-v < FIELD_AT(self, short, 0x10))) {
            v = -FIELD_AT(self, short, 0x10) + 1;
        }
    }
    n = v;
    if (((H6_80086B70 *)self)->h[FIELD_AT(self, signed char, 0x76)] != -0x8000) {
        n = v + ((H6_80086B70 *)self)->h[FIELD_AT(self, signed char, 0x76)];
        if (n < -0x7FFF) {
            n = -0x7FFF;
        } else if (n > 0x7FFF) {
            n = 0x7FFF;
        }
    }
    ((H6_80086B70 *)self)->h[FIELD_AT(self, signed char, 0x76)] = n;
    if ((FIELD_AT(self, unsigned char, 0x6D) & 2) && v > 0) {
        v = 0;
    }
    v += FIELD_AT(self, short, 0x10);
    if (v < 0) {
        v = 0;
    } else if (v > FIELD_AT(self, short, 0x12)) {
        v = FIELD_AT(self, short, 0x12);
    }
    FIELD_AT(self, short, 0x10) = v;
}

EXTERN_C void func_80086CAC(void *self, int v)
{
    int n;
    if (v < -0x7FFF) {
        v = -0x7FFF;
    } else if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    if (FIELD_AT(self, unsigned short, 0x14) & 0x100) {
        if (FIELD_AT(self, short, 0x20) < -v) {
            v = -FIELD_AT(self, short, 0x20);
        }
    }
    n = v;
    if (((H16_80086CAC *)self)->h[FIELD_AT(self, signed char, 0x76)] != -0x8000) {
        n = v + ((H16_80086CAC *)self)->h[FIELD_AT(self, signed char, 0x76)];
        if (n < -0x7FFF) {
            n = -0x7FFF;
        } else if (n > 0x7FFF) {
            n = 0x7FFF;
        }
    }
    ((H16_80086CAC *)self)->h[FIELD_AT(self, signed char, 0x76)] = n;
    if ((FIELD_AT(self, unsigned char, 0x6D) & 2) && v > 0) {
        v = 0;
    }
    v += FIELD_AT(self, short, 0x20);
    if (v < 0) {
        v = 0;
    } else if (v > FIELD_AT(self, short, 0x22)) {
        v = FIELD_AT(self, short, 0x22);
    }
    FIELD_AT(self, short, 0x20) = v;
}

EXTERN_C void func_80086DB4(Obj_80086DB4 *self)
{
    int i;
    int j;
    int k;
    short v;

    self->unk82 = 0;
    v = -0x8000;
    for (i = 4; i >= 0; i--) {
        self->unk6[i] = v;
    }
    v = -0x8000;
    for (j = 4; j >= 0; j--) {
        self->unk16[j] = v;
    }
    for (k = 0; k < 5; k++) {
        self->unk70[k] = -0x80;
    }
}

EXTERN_C void func_80086E14(char *self)
{
    FIELD_AT(self, void *, 0) = (void *)func_80079F48(D_800AF470_w);
    func_800898F0(self + 0x34);
    func_8008655C((short *)(self + 0x58));
    func_80086DB4((Obj_80086DB4 *)self);
    self[0x6D] = 0;
    self[0x7B] = 0;
    self[0x7A] = 0;
    self[0x79] = 0;
    self[0x78] = 0;
}

EXTERN_C void func_80086E74(void *self)
{
    FIELD_AT(self, char, 0x6D) = 0;
    if (FIELD_AT(self, short, 0x10) == 0) {
        FIELD_AT(self, short, 0x10) = 1;
    }
    func_800898F0((char *)self + 0x34);
    func_8008655C((short *)((char *)self + 0x58));
    func_80086DB4((Obj_80086DB4 *)self);
    ((VObj<0x9C> *)self)->v01();
    FIELD_AT(self, char, 0x7B) = 0;
    FIELD_AT(self, char, 0x7A) = 0;
    FIELD_AT(self, char, 0x79) = 0;
    FIELD_AT(self, char, 0x78) = 0;
}

EXTERN_C int func_80086EF0(char *self)
{
    func_8008687C(self, FIELD_AT(self, unsigned char, 0x97) == 0);
    FIELD_AT(self, short, 0x80) = muldiv2_80086EF0(FIELD_AT(FIELD_AT(self, unsigned char *, 0x98), unsigned char, 1), 0x100, FIELD_AT(self, unsigned char, 0x3E));
    int r;
    if (FIELD_AT(self, unsigned short, 0x90) & 0x40) {
        r = 0;
        if (!(FIELD_AT(self, unsigned char, 0x6D) & 0x40)) {
            r = FIELD_AT(self, unsigned char, 0x96) <= FIELD_AT(self, short, 0x20);
        }
    } else {
        r = 1;
    }
    return r;
}

EXTERN_C int func_80086F94(char *self, void *b, int c)
{
    func_80086DB4((Obj_80086DB4 *)self);
    FIELD_AT(self, char, 0x76) = 0;
    FIELD_AT(self, char, 0x75) = c;
    FIELD_AT(self, unsigned char, 0x6D) &= 0xE2;
    func_8008687C(self, FIELD_AT(self, unsigned char, 0x97) == 0 || FIELD_AT(self, unsigned char, 0x97) == 3);
    func_8008691C(self);
    FIELD_AT(self, short, 0x80) = muldiv2_80086EF0(FIELD_AT(FIELD_AT(self, unsigned char *, 0x98), unsigned char, 0), 0x100, FIELD_AT(self, unsigned char, 0x3E));
    void *n = __builtin_new(0x14);
    void *r = func_8001FC38(n, (FIELD_AT(self, unsigned short, 0x90) & 0x80) ? 0x1002 : (FIELD_AT(self, unsigned short, 0x90) & 0x40) ? 0x1003 : 0x1004, func_8008672C(self), 0);
    char *p = (char *)func_8001CA10(0x14);
    FIELD_AT(p, void *, 0) = D_80010178;
    FIELD_AT(p, int, 4) = 0;
    FIELD_AT(p, void *, 0) = D_80010300;
    FIELD_AT(p, short, 8) = 2;
    FIELD_AT(p, short, 0xA) = 4;
    FIELD_AT(p, int, 0x10) = 0;
    FIELD_AT(p, void *, 0xC) = r;
    FIELD_AT(p, void *, 0) = D_800102D0;
    func_8001EFE4(b, p);
    return 1;
}

// (decls_b.h has void func_800870E4(void *self, int b); verified via scratch_c/ag_u_80082174/_proto_870E4.cpp)

EXTERN_C int func_800870E4(char *self, void *b, W20_80089658 *c, int d)
{
    func_80086DB4((Obj_80086DB4 *)self);
    FIELD_AT(self, char, 0x76) = 0;
    FIELD_AT(self, char, 0x75) = d;
    FIELD_AT(self, unsigned char, 0x6D) &= 0xE2;
    FIELD_AT(self, W20_80089658, 0x84) = *c;
    if (c == 0) {
        FIELD_AT(self, char *, 0x98) = 0;
    } else {
        FIELD_AT(self, char *, 0x98) = (char *)c + 0x14;
    }
    func_8008687C(self, FIELD_AT(self, unsigned char, 0x97) == 0 || FIELD_AT(self, unsigned char, 0x97) == 3);
    FIELD_AT(self, short, 0x80) = muldiv2_80086EF0(FIELD_AT(FIELD_AT(self, unsigned char *, 0x98), unsigned char, 0), 0x100, FIELD_AT(self, unsigned char, 0x3E));
    func_8008691C(self);
    void *n = __builtin_new(0x14);
    void *r = func_8001FC38(n, (FIELD_AT(self, unsigned short, 0x90) & 0x80) ? 0x1002 : (FIELD_AT(self, unsigned short, 0x90) & 0x40) ? 0x1003 : 0x1004, func_8008672C(self), 0);
    char *p = (char *)func_8001CA10(0x14);
    FIELD_AT(p, void *, 0) = D_80010178;
    FIELD_AT(p, int, 4) = 0;
    FIELD_AT(p, void *, 0) = D_80010300;
    FIELD_AT(p, short, 8) = 2;
    FIELD_AT(p, short, 0xA) = 4;
    FIELD_AT(p, int, 0x10) = 0;
    FIELD_AT(p, void *, 0xC) = r;
    FIELD_AT(p, void *, 0) = D_800102D0;
    func_8001EFE4(b, p);
    return 1;
}

EXTERN_C int func_80087284(void *self, void *b)
{
    int base = FIELD_AT(self, unsigned char, 0x7F) - 50;
    int v = FIELD_AT(b, unsigned char, 0x11);
    v -= base;
    if (v < 0) {
        v = 0;
    } else if (v > 100) {
        v = 100;
    }
    return v;
}

EXTERN_C int func_800872B8(char *self, char *b, int c)
{
    int k = FIELD_AT(b, unsigned char, 0x497);
    switch (k) {
    default:
        return 0;
    case 2:
        func_800898F0(self + 0x34);
        func_8008655C((short *)(self + 0x58));
        FIELD_AT(self, char, 0x82) = k;
        break;
    case 3:
        if (-FIELD_AT(self, unsigned char, 0x3E) < c) {
            return 1;
        }
        FIELD_AT(self, char, 0x82) = k;
        FIELD_AT(self, unsigned short, 0x58) |= 0x40;
        FIELD_AT(self, char, 0x7B) = -c / FIELD_AT(self, unsigned char, 0x3E);
        break;
    case 4:
        break;
    case 5:
        FIELD_AT(self, char, 0x82) = k;
        break;
    }
    return 1;
}

EXTERN_C void func_800873A8(void *self, void *b, int c)
{
    int sum;
    int t;
    if (func_800872B8((char *)self, (char *)b, c)) {
        return;
    }
    sum = 0;
    {
        signed char *p = (signed char *)b + 0x484;
        for (unsigned int i = 0; i < 8; i++) {
            sum += *p++;
        }
    }
    bool z = FIELD_AT(self, unsigned char, 5) == 0;
    if (FIELD_AT(b, unsigned char, 0x405) == 0) {
        t = !z;
    } else {
        t = z != 0;
    }
    if (t) {
        func_80089E14((signed char *)self + 0x34, (signed char *)b + 0x484);
        ((C70_800873A8 *)self)->v[FIELD_AT(self, signed char, 0x76)] = sum;
    } else {
        if (FIELD_AT(b, unsigned char, 0x497) == 6) {
            func_800898FC((unsigned char *)self + 0x24, (signed char *)b + 0x484);
            func_80089D80((unsigned char *)self + 0x24, 100);
        } else {
            func_80089DB8((signed char *)self + 0x34, (signed char *)b + 0x484);
        }
        ((C70_800873A8 *)self)->v[FIELD_AT(self, signed char, 0x76)] = -sum;
    }
    ((VObj<0x9C> *)self)->v01();
}

EXTERN_C void func_800874C4(void *self, void *b, int c)
{
    int sum;
    int t;
    if (func_800872B8((char *)self, (char *)b, c)) {
        return;
    }
    sum = 0;
    {
        signed char *p = (signed char *)b + 0x484;
        for (unsigned int i = 0; i < 8; i++) {
            sum += *p++;
        }
    }
    bool z = FIELD_AT(self, unsigned char, 5) == 0;
    if (FIELD_AT(b, unsigned char, 0x405) == 0) {
        t = !z;
    } else {
        t = z != 0;
    }
    if (t) {
        func_80089E14((signed char *)self + 0x34, (signed char *)b + 0x484);
        func_80089E14((signed char *)self + 0x34, (signed char *)b + 0x484);
        ((C70_800873A8 *)self)->v[FIELD_AT(self, signed char, 0x76)] = sum * 2;
    } else {
        if (FIELD_AT(b, unsigned char, 0x497) == 6) {
            func_800898FC((unsigned char *)self + 0x24, (signed char *)b + 0x484);
            func_800898FC((unsigned char *)self + 0x24, (signed char *)b + 0x484);
            func_80089D80((unsigned char *)self + 0x24, 100);
        } else {
            func_80089DB8((signed char *)self + 0x34, (signed char *)b + 0x484);
            func_80089DB8((signed char *)self + 0x34, (signed char *)b + 0x484);
        }
        ((C70_800873A8 *)self)->v[FIELD_AT(self, signed char, 0x76)] = -sum * 2;
    }
    ((VObj<0x9C> *)self)->v01();
}

EXTERN_C void func_80087620(void *self, void *b, int c)
{
    int sum;
    int t;
    if (func_800872B8((char *)self, (char *)b, c)) {
        return;
    }
    sum = 0;
    {
        signed char *p = (signed char *)b + 0x484;
        for (unsigned int i = 0; i < 8; i++) {
            sum += *p++;
        }
    }
    bool z = FIELD_AT(self, unsigned char, 5) == 0;
    if (FIELD_AT(b, unsigned char, 0x405) == 0) {
        t = !z;
    } else {
        t = z != 0;
    }
    if (t) {
        func_80089E14((signed char *)self + 0x34, func_80089F10((signed char *)b + 0x484, 2).b);
        ((C70_800873A8 *)self)->v[FIELD_AT(self, signed char, 0x76)] = sum / 2;
    } else {
        if (FIELD_AT(b, unsigned char, 0x497) == 6) {
            func_800898FC((unsigned char *)self + 0x24, func_80089F10((signed char *)b + 0x484, 2).b);
            func_80089D80((unsigned char *)self + 0x24, 100);
        } else {
            func_80089DB8((signed char *)self + 0x34, func_80089F10((signed char *)b + 0x484, 2).b);
        }
        ((C70_800873A8 *)self)->v[FIELD_AT(self, signed char, 0x76)] = -sum * 2;
    }
    ((VObj<0x9C> *)self)->v01();
}

EXTERN_C void func_80087764(void *self, void *b, int c)
{
    int sum;
    int t;
    if (func_800872B8((char *)self, (char *)b, c)) {
        return;
    }
    sum = 0;
    {
        signed char *p = (signed char *)b + 0x484;
        for (unsigned int i = 0; i < 8; i++) {
            sum += *p++;
        }
    }
    bool z = FIELD_AT(self, unsigned char, 5) == 0;
    if (FIELD_AT(b, unsigned char, 0x405) == 0) {
        t = !z;
    } else {
        t = z != 0;
    }
    if (t) {
        func_80089DB8((signed char *)self + 0x34, (signed char *)b + 0x484);
        ((C70_800873A8 *)self)->v[FIELD_AT(self, signed char, 0x76)] = -sum;
    } else {
        if (FIELD_AT(b, unsigned char, 0x497) == 6) {
            func_80089954((unsigned char *)self + 0x24, (signed char *)b + 0x484);
            func_80089D80((unsigned char *)self + 0x24, 100);
        } else {
            func_80089E14((signed char *)self + 0x34, (signed char *)b + 0x484);
        }
        ((C70_800873A8 *)self)->v[FIELD_AT(self, signed char, 0x76)] = sum;
    }
    ((VObj<0x9C> *)self)->v01();
}

EXTERN_C void func_80087880(void *self, int b)
{
    void *n = __builtin_new(0x14);
    void *r = func_8001FC38(n, 0x1001, func_8008672C((char *)self), 0);
    char *p = (char *)func_8001CA10(0x14);
    FIELD_AT(p, void *, 0) = D_80010178;
    FIELD_AT(p, int, 4) = 0;
    FIELD_AT(p, void *, 0) = D_80010300;
    FIELD_AT(p, short, 8) = 2;
    FIELD_AT(p, short, 0xA) = 4;
    FIELD_AT(p, int, 0x10) = 0;
    FIELD_AT(p, void *, 0xC) = r;
    FIELD_AT(p, void *, 0) = D_800102D0;
    func_8001EFE4((void *)b, p);
}

EXTERN_C void func_8008792C(void *self, char *b, int c)
{
    char *q = 0;
    if (b != 0) {
        q = b + 0x400;
    }
    FIELD_AT(self, short, 0x14) = FIELD_AT(q, short, 0x90);
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        func_800873A8(self, b, -c);
    } else {
        func_80086B70(self, -c);
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_800879CC(void *self, void *b, int c)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        func_800874C4(self, b, -c * 2);
    } else {
        func_80086B70(self, -c * 2);
    }
    func_800890F0(self, b, 1);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087A58(void *self, void *b, int c)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        func_80087620(self, b, -c / 2);
    } else {
        func_80086B70(self, -c / 2);
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087AF4(void *self, void *b, int c)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        func_80087764(self, b, c);
    } else {
        func_80086B70(self, c);
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087B78(void *self, char *b, int c)
{
    char *q = 0;
    if (b != 0) {
        q = b + 0x400;
    }
    FIELD_AT(self, short, 0x14) = FIELD_AT(q, short, 0x90);
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        func_800873A8(self, b, -c);
    } else {
        func_80086CAC(self, -c / 8);
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087C2C(void *self, void *b, int c, int d)
{
    char *q = 0;
    if (b != 0) {
        q = (char *)b + 0x400;
    }
    FIELD_AT(self, short, 0x14) = FIELD_AT(q, short, 0x90);
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        int m = d;
        if (m < c) {
            m = c;
        }
        func_800873A8(self, b, m);
    } else {
        if (c) {
            func_80086B70(self, c);
        }
        if (d) {
            func_80086CAC(self, d);
        }
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087CFC(void *self, void *b, int c)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        func_800874C4(self, b, -c * 2);
    } else {
        func_80086CAC(self, -c / 4);
    }
    func_800890F0(self, b, 1);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087D98(void *self, void *b, int c, int d)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        int m = d;
        if (m < c) {
            m = c;
        }
        func_800874C4(self, b, m * 2);
    } else {
        if (c) {
            func_80086B70(self, c * 2);
        }
        if (d) {
            func_80086CAC(self, d * 2);
        }
    }
    func_800890F0(self, b, 1);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087E50(void *self, void *b, int c)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        func_80087620(self, b, -c / 2);
    } else {
        func_80086CAC(self, -c / 16);
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087EF4(void *self, void *b, int c, int d)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        int m = d;
        if (m < c) {
            m = c;
        }
        func_80087620(self, b, m / 2);
    } else {
        if (c) {
            func_80086B70(self, c / 2);
        }
        if (d) {
            func_80086CAC(self, d / 2);
        }
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80087FC4(void *self, void *b, int c)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        func_80087764(self, b, c);
    } else {
        func_80086CAC(self, c / 8);
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_8008805C(void *self, void *b, int c, int d)
{
    func_80089178(self, (int)b);
    if (FIELD_AT(b, unsigned char, 0x497)) {
        int m = d;
        if (m < c) {
            m = c;
        }
        func_80087764(self, b, -m);
    } else {
        if (c) {
            func_80086B70(self, -c);
        }
        if (d) {
            func_80086CAC(self, -d);
        }
    }
    func_800890F0(self, b, 0);
    func_80087880(self, (int)b);
}

EXTERN_C void func_80088114(void *self, int b)
{
    func_80089178(self, b);
    ((VObj<0x9C> *)self)->v11(b);
    func_80087880(self, b);
}

EXTERN_C void func_8008816C(void *self, void *b, int c)
{
    func_80086DB4((Obj_80086DB4 *)self);
    FIELD_AT(self, W20_80089658, 0x84) = FIELD_AT(b, W20_80089658, 0x484);
    FIELD_AT(self, char, 0x75) = FIELD_AT(b, unsigned char, 0x475);
    func_8008687C((char *)self, FIELD_AT(self, unsigned char, 0x97) == 0 || FIELD_AT(self, unsigned char, 0x97) == 3);
    void *n = __builtin_new(0x14);
    void *r = func_8001FC38(n, (unsigned short)c, func_8008672C((char *)self), 0);
    char *p = (char *)func_8001CA10(0x14);
    FIELD_AT(p, void *, 0) = D_80010178;
    FIELD_AT(p, int, 4) = 0;
    FIELD_AT(p, void *, 0) = D_80010300;
    FIELD_AT(p, short, 8) = 2;
    FIELD_AT(p, short, 0xA) = 4;
    FIELD_AT(p, int, 0x10) = 0;
    FIELD_AT(p, void *, 0xC) = r;
    FIELD_AT(p, void *, 0) = D_800102D0;
    func_8001EFE4(b, p);
}

EXTERN_C void func_80088280(void *self, void *b)
{
    int i;
    FIELD_AT(self, unsigned char, 0x6D) |= 8;
    for (i = 0; i < FIELD_AT(b, signed char, 0x475); i++) {
        ((VObj<0x9C> *)self)->v11(b);
    }
    func_8008816C(self, b, 0x1006);
}

EXTERN_C void func_80088310(void *self, void *b)
{
    int i;
    FIELD_AT(self, unsigned char, 0x6D) |= 8;
    for (i = 0; i < FIELD_AT(b, signed char, 0x475); i++) {
        ((VObj<0x9C> *)self)->v11(b);
    }
    func_8008816C(self, b, 0x1007);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_800883A0);

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_80088794);

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_8008891C);

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_80088C8C);

EXTERN_C int func_80088DEC(char *self, char *b)
{
    Q_80088DEC *q = 0;
    if (b != 0) {
        q = (Q_80088DEC *)(b + 0x400);
    }
    FIELD_AT(self, unsigned char, 0x6D) |= 1;
    if (FIELD_AT(q, unsigned short, 0x14) & 0x100) {
        int save = FIELD_AT(self, signed char, 0x76);
        for (int i = 0; i < FIELD_AT(self, signed char, 0x75); i++) {
            func_80086CAC(self, -q->b[i]);
            FIELD_AT(self, char, 0x76)++;
        }
        FIELD_AT(self, char, 0x76) = save;
    }
    if (FIELD_AT(q, unsigned short, 0x14) & 0x200) {
        int save = FIELD_AT(self, signed char, 0x76);
        for (int i = 0; i < FIELD_AT(self, signed char, 0x75); i++) {
            func_80086B70(self, -q->a[i]);
            FIELD_AT(self, char, 0x76)++;
        }
        FIELD_AT(self, char, 0x76) = save;
        if (FIELD_AT(self, short, 0x10) <= 0) {
            FIELD_AT(self, short, 0x10) = 1;
        }
    }
    FIELD_AT(self, unsigned char, 0x6D) &= ~1;
    FIELD_AT(self, char, 0x76)++;
    FIELD_AT(q, short, 0x14) = 0;
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80085168", func_80088F34);

INCLUDE_RODATA("asm/main/nonmatchings/u_80085168", D_80017CB4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80085168", D_80017CCC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80085168", D_80017D1C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80085168", D_80017D2C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80085168", D_80017D4C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80085168", D_80017D64);

INCLUDE_RODATA("asm/main/nonmatchings/u_80085168", D_80017DFC);
