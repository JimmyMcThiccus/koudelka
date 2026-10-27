#include "common.h"
#include "shared/vbase.h"

#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"

EXTERN_C void func_80053964(void *self);

EXTERN_C void func_80054A2C(void *self)
{
    func_80053964(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80054A4C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80054AF0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80054B98);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80054C34);

EXTERN_C void func_80054CA0(void *self)
{
    VObj<0x2C> *v = FIELD_AT(self, VObj<0x2C> *, 0x3C);
    if (v != 0) {
        v->v27();
    }
}

EXTERN_C void func_80058830(void *self, void *b);

EXTERN_C void func_80054CE4(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_80058830(p, (char *)self + 0x1C);
    }
}

EXTERN_C void func_800581E0(void *self);

EXTERN_C void func_80054D18(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_800581E0(p);
    }
}

EXTERN_C void func_80057F20(void *self, unsigned short b);

EXTERN_C void func_80054D48(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_80057F20(p, b);
    }
}

EXTERN_C int func_80053880(void *self);

EXTERN_C int func_80054D78(void *self)
{
    char *p = FIELD_AT(self, char *, 0x3C);
    if (p == 0) {
        return 1;
    }
    return func_80053880(p + 0x50);
}

EXTERN_C void func_8005800C(void *self);

EXTERN_C void func_80054DA8(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_8005800C(p);
    }
}

EXTERN_C void func_80019D40(List *l);

EXTERN_C void func_80054DD8(void *self)
{
    char *h = (char *)self + 0x1C;
    func_80019D40(h ? FIELD_AT(h, List *, 0x0) : 0);
}

EXTERN_C int func_80054E0C(void *self)
{
    return FIELD_AT(self, unsigned short, 0x44) != 0;
}

EXTERN_C void func_80019A6C(List *l, int b, int c);

EXTERN_C void func_80054E18(void *self, int b)
{
    char *h = (char *)self + 0x1C;
    List *l = h ? FIELD_AT(h, List *, 0x0) : 0;
    func_80019A6C(l, b, l->count);
}

EXTERN_C void func_80054E54(void *self, int b)
{
    char *h = (char *)self + 0x1C;
    char *g = h ? (char *)self + 0x24 : 0;
    func_80019F64(g ? FIELD_AT(g, List *, 0x0) : 0, b);
}

EXTERN_C int func_80054E90(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    int r = 0;
    if (p != 0) {
        r = FIELD_AT(p, int, 0x20) != 0;
    }
    return r;
}

EXTERN_C int func_80054048(void *self);

EXTERN_C void func_80054EB4(void *self, int b, int c)
{
    if (func_80054048(self) == 0) {
        VObj<0x2C> *v = FIELD_AT(self, VObj<0x2C> *, 0x3C);
        FIELD_AT(self, short, 0x40) = b;
        FIELD_AT(self, short, 0x42) = c;
        if (v != 0) {
            v->v08(b, c);
        }
    }
}

EXTERN_C void *func_80054F28(void *self)
{
    return (char *)self + 0x40;
}

struct SV_80054F30 {
    short x, y, z, w;
};

struct Obj_80054F30 {
    char pad[0x44];
    short a;
    SV_80054F30 v;
    short d;
};

EXTERN_C void func_80054F30(Obj_80054F30 *self, int a, SV_80054F30 *v, int d)
{
    self->a = a;
    self->v = *v;
    self->d = d;
}

EXTERN_C void func_8005854C(void *self, int a, void *v, int d);

EXTERN_C void func_80054F5C(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_8005854C(p, FIELD_AT(self, unsigned short, 0x44), (char *)self + 0x46, FIELD_AT(self, short, 0x4E));
        FIELD_AT(self, VObj<0x2C> *, 0x3C)->v04();
    }
}

EXTERN_C void func_800550FC(void *self, int b);

EXTERN_C void func_80054FC0(void *self)
{
    func_800550FC(self, 0);
}

struct Heap_800A4578 {
    void *p;
    int pad[2];
};
EXTERN_C Heap_800A4578 D_800A4578;
EXTERN_C void func_8002B27C(void *heap, void *p);

EXTERN_C void func_80054FE0(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_8002B27C(D_800A4578.p, p);
        FIELD_AT(self, void *, 0x3C) = 0;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80055020);

EXTERN_C void func_800550BC(void *self)
{
    char *h = (char *)self + 0x1C;
    char *g = h ? (char *)self + 0x24 : 0;
    int n = FIELD_AT(h, int, 0x4);
    func_80019F64(g ? FIELD_AT(g, List *, 0x0) : 0, n);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800550FC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80055330);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800553D8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005549C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005556C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80055624);

EXTERN_C void *D_800B4D84;
EXTERN_C int func_8001A6E8(void *self);

EXTERN_C int func_800557A0(void)
{
    return func_8001A6E8((char *)D_800B4D84 + 0x8C) >= 2;
}

EXTERN_C void func_80053BCC(void *self, void *b, int c);

struct Rec_800557C8 {
    signed char k;
    char pad[3];
    char data[0x14];
};

struct Pair_800557C8 {
    Rec_800557C8 a;
    Rec_800557C8 b;
};

EXTERN_C void func_800557C8(void *self, int b, int c)
{
    int off = c * 48;
    char *t;
    Rec_800557C8 *r;
    if (b != 0) {
        t = (char *)D_800B4D84 + 0x40F8;
    } else {
        t = (char *)D_800B4D84 + 0x4338;
    }
    if (FIELD_AT(D_800B4D84, int, 0x44E8) != 0) {
        char *u = t + 0x18;
        r = (Rec_800557C8 *)(u + off);
    } else {
        r = (Rec_800557C8 *)(t + off);
    }
    func_80053BCC(self, r->data, r->k);
}

EXTERN_C int func_80055838(int value)
{
    int old = FIELD_AT(D_800B4D84, int, 0x44E8);
    FIELD_AT(D_800B4D84, int, 0x44E8) = value;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005584C);

EXTERN_C char D_80013BA0[];
EXTERN_C char D_80013BB8[];
EXTERN_C void func_8001E508(void *self, int flags);

EXTERN_C void func_800558DC(void *self, int flags)
{
    FIELD_AT(self, void *, 0x8C) = D_80013BA0;
    FIELD_AT(self, void *, 0x0) = D_80013BB8;
    FIELD_AT(self, int, 0x44EC) = 0;
    D_800B4D84 = 0;
    func_8001E508(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005591C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80055A9C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80055D78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80055F0C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80055F98);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800560E4);

EXTERN_C int D_800B4D98;

EXTERN_C int func_8005618C(void)
{
    return D_800B4D98 == 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80056198);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80056364);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005652C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800566E4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80056874);

EXTERN_C void func_80056B3C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80056B44);

EXTERN_C void func_8001FC78(void *p, int b, int c);

EXTERN_C int func_80056BA8(VObj<0x18> *self, void *b)
{
    func_8001FC78(b, 0, 0);
    if (FIELD_AT(b, unsigned short, 0x18) & 0x4000) {
        self->v02();
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80056C18);

EXTERN_C void func_80056D60(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_80057F20(p, b ? 0x80 : 0x40);
    }
}

EXTERN_C int func_80056D9C(void)
{
    return 0;
}

struct Str_800AE620 {
    void *p0;
    int n4;
    void *p8;
    int buf[0x20];
};
EXTERN_C Str_800AE620 D_800AE620;
EXTERN_C void func_80019920(void *a, int b);

EXTERN_C void func_80056DA4(void)
{
    func_80019920(D_800AE620.p0, 0);
}

EXTERN_C void func_80056DCC(void)
{
    D_800AE620.p8 = D_800AE620.buf;
    D_800AE620.p0 = D_800AE620.buf;
    func_800198E0(D_800AE620.buf, 0x20, 0);
    D_800AE620.n4 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80056E0C);

EXTERN_C void func_8005717C(void *self);

EXTERN_C void func_80056F9C(void *self)
{
    FIELD_AT(self, int, 0xA0) = 0;
    func_8005717C(self);
}

EXTERN_C void func_80056FBC(void *self)
{
    FIELD_AT(self, int, 0xA0) = 1;
    func_8005717C(self);
}

EXTERN_C void func_8005388C(void *self, int b);

EXTERN_C void func_80056FE0(void *self)
{
    func_8005388C(self ? (char *)self + 0x50 : 0, FIELD_AT(self, int, 0x9C));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80057010);

EXTERN_C void func_8002A210(void *self);
EXTERN_C void func_80056FE0(void *self);

EXTERN_C void func_80057150(void *self)
{
    func_8002A210(self);
    func_80056FE0(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005717C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80057214);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80057368);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80057558);

EXTERN_C void *func_8002EEC4(void *self, void *b);
EXTERN_C void func_8002BA94(void *self);

EXTERN_C void func_800576A8(void *self)
{
    if (FIELD_AT(self, void *, 0x8) == 0) {
        FIELD_AT(self, void *, 0x8) = func_8002EEC4(operator new(0x14), self);
    }
    func_8002BA94(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800576F8);

EXTERN_C short D_800B4DA8;
EXTERN_C short D_800B4DAA;

EXTERN_C void func_8005783C(short v)
{
    if (v >= 3) {
        D_800B4DA8 = v;
    } else {
        D_800B4DA8 = 8;
    }
    D_800B4DAA = D_800B4DA8 - 2;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80057878);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80057C7C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80057F20);

EXTERN_C void func_80059B5C(void *p);

EXTERN_C void func_80057FEC(void *self)
{
    func_80059B5C((char *)self + 0x5C);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005800C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800580B0);

EXTERN_C void func_80059C54(void *self, int b, int c);
EXTERN_C int func_80059D94(void *self, int b);
EXTERN_C void func_8005CCB0(void *self, int b);

EXTERN_C void func_8005816C(void *self, int b)
{
    char *p = (char *)self + 0x5C;
    func_80059C54(p, FIELD_AT(self, int, 0x138), 0);
    FIELD_AT(self, int, 0x138) = b;
    func_80059C54(p, b, 1);
    func_8005CCB0(FIELD_AT(self, void *, 0x108), func_80059D94(p, FIELD_AT(self, int, 0x138)));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800581E0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058270);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058404);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058488);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005854C);

EXTERN_C int func_80058B98(void *self);
EXTERN_C int func_80058C5C(void *self);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058654);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058728);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058830);

EXTERN_C void func_80059EF8(void *self, int b);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058910);

EXTERN_C void func_80058F08(VObj<0x2C> *self, int b);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058A80);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058B98);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058C5C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058D98);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80058F68);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059300);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800593A0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800594A8);

EXTERN_C void func_80027FEC(void *self, void *b);

struct V_80059584 {
    int a, b, c, d;
};

struct Obj_80059584 {
    char pad[0xC];
    V_80059584 v[2];
};

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800595F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800596A4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059790);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059800);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059888);

EXTERN_C int func_8005992C(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C void func_8001A610(void *self, int flags);

EXTERN_C void func_80059938(void *self, int flags)
{
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059958);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059A84);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059B5C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059C54);

EXTERN_C void func_80059D8C(void *self, int b)
{
    FIELD_AT(self, int, 0x38) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059D94);

EXTERN_C int func_80059E90(VObj<0x2C> *self)
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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80059F0C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005A020);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005A120);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005A31C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005A518);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005A62C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005A784);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005A934);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005ABE0);

struct C4_8005AF70 {
    char v[4];
};

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005AFF0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005B0F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005B2F0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005B378);


struct Pair_8005B424 {
    short a;
    short b;
};

struct Ent_8005B424 {
    int pad[2];
    short a;
    short b;
    int pad2;
};

struct Obj_8005B424 {
    char pad[0x14];
    Ent_8005B424 *ents;
};

EXTERN_C Pair_8005B424 *func_8005B424(Pair_8005B424 *out, Obj_8005B424 *self)
{
    int i = D_800B4CF0.value;
    short a = self->ents[i].a;
    short b = self->ents[i].b;
    out->a = a;
    out->b = b;
    return out;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005B450);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005B4D8);

struct VEnt_8005B560 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

struct Ent_8005B560 {
    int pad[2];
    short a;
    short b;
    int pad2;
};

struct Obj_8005B560 {
    VEnt_8005B560 *vt;
    char pad[0x10];
    Ent_8005B560 *ents;
};

EXTERN_C void func_8005B560(Obj_8005B560 *self, int b, int c)
{
    VEnt_8005B560 *vt = self->vt;
    int i = D_800B4CF0.value;
    vt[11].pfn((char *)self + vt[11].delta, b - self->ents[i].a, c - self->ents[i].b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005B5B4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005B66C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005B7A8);

EXTERN_C void func_8005BC7C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005BC84);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005BDA4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005BF04);

EXTERN_C void func_8005BF48(void)
{
}

EXTERN_C void *func_8005C26C(void *self, void *b, int c);
EXTERN_C void func_8002A110(void *self);

EXTERN_C void func_8005BF50(void *self)
{
    if (FIELD_AT(self, void *, 0x8) == 0) {
        FIELD_AT(self, void *, 0x8) = func_8005C26C(operator new(0x34), self, FIELD_AT(self, int, 0x34));
    }
    func_8002A110(self);
}

EXTERN_C void func_8005C1E8(void *self);

EXTERN_C void func_8005BFA4(void *self)
{
    func_8005C1E8(self);
}

EXTERN_C void func_8005C088(void *self, int b, int c);

EXTERN_C void func_8005BFC4(void *self, int b)
{
    func_8005C088(self, b, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005BFE4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C088);

EXTERN_C void func_8005C1E8(void *self)
{
    int r = ((VObj<0x2C> *)self)->v11();
    if (r != 0) {
        func_8005C088(self, r, 1);
    }
}

struct V_8005C238 {
    char pad[0x2C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

EXTERN_C void func_8005C238(V_8005C238 *self)
{
    self->v14();
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C26C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C2B8);

struct V_8005C344 {
    char pad[0x2C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

EXTERN_C void func_8005C344(void *self)
{
    FIELD_AT(self, V_8005C344 *, 0x30)->v14();
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C380);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C3C4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C570);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C608);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C6E8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C77C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C7EC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C8B4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C910);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005C968);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005CA4C);

EXTERN_C void func_8005F120(void *self, int flags);

EXTERN_C void func_8005CB68(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005CB88);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005CCB0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005CD5C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005CE1C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005CEB4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005CF78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005D080);

EXTERN_C void func_8005F1D8(void *self);

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

struct VEnt_8005D334 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

EXTERN_C void func_8005D334(void *self, int b, int c)
{
    VEnt_8005D334 *vt = FIELD_AT(self, VEnt_8005D334 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

EXTERN_C void *func_8005D754(void *self, void *b);

EXTERN_C void *func_8005D384(void *self)
{
    return func_8005D754(operator new(0x88), self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005D3B8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005D624);

EXTERN_C void func_8005D734(void *self, int b)
{
    func_8005D228(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005D754);

EXTERN_C void func_8005F120(void *self, int flags);

EXTERN_C void func_8005D8A4(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005D8C4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005D9D4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005DB68);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005DC44);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005DD4C);

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

EXTERN_C void func_8005F1D8(void *self);

struct Entry_8005DF10 {
    char pad[0x30];
    unsigned short x;
    unsigned short y;
};

EXTERN_C void func_8005DF10(void *self, int dx, int dy)
{
    Entry_8005DF10 *e = (Entry_8005DF10 *)((char *)self + D_800B4CF0.value * 16);
    e->x += dx;
    e->y += dy;
    func_8005F1D8(self);
}

struct Entry_8005DF54 {
    char pad[0x2C];
    unsigned char rgb[3];
};

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

struct VEnt_8005DF98 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

EXTERN_C void func_8005DF98(void *self, int b, int c)
{
    VEnt_8005DF98 *vt = FIELD_AT(self, VEnt_8005DF98 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005DFE8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005E0E0);

EXTERN_C void func_8005E244(void)
{
}

EXTERN_C void func_8005F120(void *self, int flags);

EXTERN_C void func_8005E24C(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005E26C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005E404);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005E4CC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005E924);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005EA9C);

EXTERN_C void *func_8005EF58(void *self, void *b);

EXTERN_C void *func_8005EAFC(void *self)
{
    return func_8005EF58(operator new(0x114), self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005EB30);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005EDF4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005EF58);

EXTERN_C void func_8005F120(void *self, int flags);

EXTERN_C void func_8005F090(void *self, int flags)
{
    func_8005F120(self, flags);
}

struct Snd_800AE640 {
    int pad[4];
};
EXTERN_C Snd_800AE640 D_800AE640;
EXTERN_C void func_8005FC78(Snd_800AE640 *self, int b, int c);

EXTERN_C void func_8005F0B0(void)
{
    func_8005FC78(&D_800AE640, 0x1434E, 0x10800);
}

EXTERN_C char D_80010178[];
EXTERN_C char D_800111BC[];
EXTERN_C char D_80014BD0[];

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

EXTERN_C void func_8005FB04(Snd_800AE640 *self, int b);

EXTERN_C void func_8005F1EC(void)
{
    func_8005FB04(&D_800AE640, 2);
}

EXTERN_C void func_8005F8EC(Snd_800AE640 *self);

EXTERN_C void func_8005F214(void)
{
    func_8005F8EC(&D_800AE640);
}

EXTERN_C void *func_8005F238(void *self)
{
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x0) = 0;
    return self;
}

EXTERN_C void func_8005F3E0(void *self);
EXTERN_C void __builtin_delete(void *p);

// GCC 2.x deleting destructor: bit 0 of the second argument frees the object.
EXTERN_C void func_8005F248(void *self, int flags)
{
    func_8005F3E0(self);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

EXTERN_C int func_8005F28C(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005F298);

EXTERN_C void func_80036D8C(void *p);

EXTERN_C void func_8005F3E0(void *self)
{
    VObj0 *p = FIELD_AT(self, VObj0 *, 0x4);
    if (p != 0) {
        p->v02();
        func_80036D8C(FIELD_AT(self, void *, 0x4));
        FIELD_AT(self, int, 0x4) = 0;
        FIELD_AT(self, int, 0x0) = 0;
    }
}

EXTERN_C int D_800B4DC8;
EXTERN_C int D_800B4DCC;
EXTERN_C void func_8005F47C(int a, int b);

EXTERN_C void func_8005F440(int a, int b)
{
    if (D_800B4DC8 == 0) {
        D_800B4DC8 = a;
        D_800B4DCC = b;
    }
    func_8005F47C(a, b);
}

EXTERN_C int D_800B4DC4;

EXTERN_C int func_8005F470(void)
{
    return D_800B4DC4 != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005F47C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005F50C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005F5F4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005F698);

struct Arr_8005F704 {
    int pad[2];
    unsigned int count;
    int *items;
};

EXTERN_C void func_8005F704(Arr_8005F704 *self, unsigned int i, int v)
{
    if (i < self->count) {
        self->items[i] = v;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005F730);

EXTERN_C signed char D_800AE66C[0x100];
EXTERN_C signed char D_800AE76C[0x100];

EXTERN_C int func_8005F834(signed char *p)
{
    signed char *t = D_800AE76C;
    if ((p[0] & 0xF0) == 0x60) {
        t = D_800AE66C;
    }
    return t[(p[1] & 0xF) * 16 + (p[0] & 0xF)];
}

EXTERN_C unsigned int func_80053BB4(void *self);
EXTERN_C void *func_80053AE4(void *out, void *self, int i);
EXTERN_C int func_8005F834(signed char *p);

struct Ev_8005F87C {
    signed char v[8];
};

EXTERN_C int func_8005F87C(void *self)
{
    int sum = 0;
    unsigned int i;
    Ev_8005F87C e;

    for (i = 0; i < func_80053BB4(self); i++) {
        func_80053AE4(&e, self, i);
        sum += func_8005F834(e.v);
    }
    return sum;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005F8EC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005FB04);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8005FC78);

EXTERN_C unsigned short func_800600A4(void *self, int b)
{
    char *h;
    if (b < 6 || b == 11) {
        h = self ? (char *)self + 0x8 : 0;
        return FIELD_AT(func_80019F64(h ? FIELD_AT(h, List *, 0x0) : 0, 0), unsigned short, 0x8);
    }
    h = self ? (char *)self + 0x8 : 0;
    return FIELD_AT(func_80019F64(h ? FIELD_AT(h, List *, 0x0) : 0, 1), unsigned short, 0x8);
}

EXTERN_C unsigned short func_80060118(void *self, int b)
{
    char *h = self ? (char *)self + 0x8 : 0;
    return FIELD_AT(func_80019F64(h ? FIELD_AT(h, List *, 0x0) : 0, b), unsigned short, 0x8);
}

EXTERN_C unsigned short func_80060154(void *self, int b)
{
    if (b < 0x40) {
        return FIELD_AT(FIELD_AT(self, void *, 0x24), unsigned short, 0x1C);
    }
    return FIELD_AT(FIELD_AT(self, void *, 0x20), unsigned short, 0x1C);
}

struct Pair_80060188 {
    short a;
    short b;
};

EXTERN_C Pair_80060188 *func_80060188(Pair_80060188 *out, void *self, unsigned int i)
{
    if (i < 10) {
        *out = FIELD_AT(self, Pair_80060188 *, 0x28)[i];
    } else {
        out->a = 0;
        out->b = 0;
    }
    return out;
}

EXTERN_C void *func_800601C8(void *self)
{
    FIELD_AT(self, char, 0x1) = 0;
    FIELD_AT(self, char, 0x0) = 0;
    return self;
}

EXTERN_C void func_80060218(void *self, void *src);

EXTERN_C void *func_800601D8(void *self, void *src)
{
    func_80060218(self, src);
    return self;
}

EXTERN_C void *func_80060200(void *self, void *src)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(src, char, 0x0);
    FIELD_AT(self, char, 0x1) = FIELD_AT(src, char, 0x1);
    return self;
}

EXTERN_C void func_80060218(void *self, void *src)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(src, char, 0x0);
    FIELD_AT(self, char, 0x1) = FIELD_AT(src, char, 0x1);
}

EXTERN_C int func_80060230(signed char *a, signed char *b)
{
    return a[0] == b[0] && a[1] == b[1];
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013940);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013A38);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013A88);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013AA8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013B00);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013B20);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013B48);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013B70);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013BA0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013BB8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013BD0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013C00);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013C50);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013C70);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013CB0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013D00);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013E10);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013E30);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013F40);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013F90);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80013FB0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800140C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014110);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014130);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014180);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014278);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800142B8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014308);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014400);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014450);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014548);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800145B0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014658);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014750);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800147A0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014808);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014858);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014950);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800149B8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014A08);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014B00);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014B68);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014BD0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014C38);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80060260);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80060378);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80060588);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800609D0);

EXTERN_C int func_80060D9C(void *self);

EXTERN_C int func_80060D6C(void *self)
{
    return func_80060D9C(self) == FIELD_AT(self, int, 0x220);
}

struct Obj_80060D9C {
    char pad[0x124];
    signed char a[0x80];
    signed char b[0x7C];
};

EXTERN_C int func_80060D9C(void *self)
{
    int sum = 0;
    unsigned int i;
    signed char *p = ((Obj_80060D9C *)self)->a;
    signed char *q;

    for (i = 0; i < 0x80; i++) {
        sum += p[i];
    }
    q = ((Obj_80060D9C *)self)->b;
    for (i = 0; i < 0x7C; i++) {
        sum += q[i];
    }
    return sum;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80060DF0);

EXTERN_C int func_80061030(void *self, unsigned int i)
{
    return (((unsigned int *)((char *)self + 0x124))[i >> 5] & (1 << (i & 0x1F))) != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80061058);

struct Obj_800610E4 {
    char pad[0x120];
    short *out;
    char pad2[0xB0];
    short vals[1];
};

EXTERN_C void func_800610E4(Obj_800610E4 *self, int i, int j)
{
    self->out[i] = (j == 16) ? 0 : self->vals[j];
}

struct Obj_80061114 {
    char pad[0x1D4];
    short vals[1];
};

EXTERN_C void func_80061114(Obj_80061114 *self, int i, int j)
{
    short t = self->vals[i];
    self->vals[i] = self->vals[j];
    self->vals[j] = t;
}

EXTERN_C void func_8008CC20(int b);

EXTERN_C void func_80061138(void *self)
{
    func_8008CC20(FIELD_AT(self, signed char, 0x1F8) != 1);
}

struct Ent_80061164 {
    char pad[0x94];
};

EXTERN_C Ent_80061164 D_800AE984[];

EXTERN_C Ent_80061164 *func_80061164(void *self, int i)
{
    return &D_800AE984[i];
}

struct Ent_80061188 {
    char pad[0x94];
};

struct Obj_80061188 {
    int pad[2];
    Ent_80061188 cur;
    int sel;
    char pad2[0x184];
    Ent_80061188 e[1];
};

EXTERN_C void *func_80061188(Obj_80061188 *self, int i)
{
    if (i < 0 || (self->sel >= 0 && i == self->sel)) {
        return &self->cur;
    }
    return &self->e[i];
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800611D0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800614BC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800615B4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80061758);

struct Ent_800619F4 {
    char pad[0x94];
};

struct Obj_800619F4 {
    char pad[0x23C];
    Ent_800619F4 e[0x30];
};

EXTERN_C int func_800619F4(Obj_800619F4 *self)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (self->e[i].pad[0] == 0) {
            break;
        }
    }
    return i;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80061A20);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80061AAC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80061BF0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80061CC4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80061E9C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80061F80);

struct Ent_800620D8 {
    char pad[0x18];
    unsigned char used;
    char pad2[0x7B];
};

EXTERN_C Ent_800620D8 *func_800620D8(void *self, unsigned int i)
{
    if (i < 8 && *((unsigned char *)self + i * 0x94 + 0x1DFC) != 0) {
        return (Ent_800620D8 *)((char *)self + (i * 0x94 + 0x1DE4));
    }
    return 0;
}

EXTERN_C void *func_80062118(void *self)
{
    return (char *)self + 0x1A4;
}

struct Blk_80062120 {
    int v[6];
};

EXTERN_C void func_80062120(void *self, Blk_80062120 *src)
{
    FIELD_AT(self, Blk_80062120, 0x1A4) = *src;
}

EXTERN_C void *func_80062158(void *self)
{
    return self;
}

struct Clock_800A4534 {
    int pad[3];
    volatile unsigned int ticks;
};

EXTERN_C Clock_800A4534 D_800A4534;

EXTERN_C void func_80062160(unsigned int *out)
{
    *out = D_800A4534.ticks / 60;
}

EXTERN_C void func_80062160(unsigned int *out);

EXTERN_C void func_80062188(void *self)
{
    int v = FIELD_AT(self, int, 0x1C4) + (D_800A4534.ticks / 60 - FIELD_AT(self, int, 0x0));
    FIELD_AT(self, int, 0x1C4) = v;
    if (v > 360000) {
        FIELD_AT(self, int, 0x1C4) = 360000;
    }
    func_80062160((unsigned int *)self);
}

EXTERN_C void *func_800621F8(void *self)
{
    void *r = 0;
    if (FIELD_AT(self, signed char, 0xA0) != 0) {
        r = (char *)self + 0xA0;
    }
    return r;
}

struct Obj_80062214 {
    char pad[0xA0];
    char a[0x80];
};

EXTERN_C void func_80062214(Obj_80062214 *self)
{
    unsigned int i;

    for (i = 0; i < 0x80; i++) {
        self->a[i] = 0;
    }
}

EXTERN_C int func_80062238(void *self, unsigned int bit)
{
    return ((((signed char *)self + 0x1F9)[bit >> 3] >> (bit & 7)) ^ 1) & 1;
}

EXTERN_C void func_80062258(void *self, unsigned int i)
{
    ((unsigned char *)self + 0x1F9)[i >> 3] &= ~(1 << (i & 7));
}

EXTERN_C int func_80062280(void *self, int b)
{
    int old = FIELD_AT(self, int, 0x4);
    FIELD_AT(self, int, 0x4) = b;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006228C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006237C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800624A4);

struct Ent_800AE86C : VObj<0x18> {
};

EXTERN_C Ent_800AE86C D_800AE86C[10];

EXTERN_C void func_8006255C(void)
{
    if (D_800AE86C != 0) {
        Ent_800AE86C *p = D_800AE86C + 10;
        while (p != D_800AE86C) {
            p--;
            p->v00(2);
        }
    }
}

EXTERN_C void func_80053928(void *self);

EXTERN_C void func_800625C0(void)
{
    Ent_800AE86C *p = D_800AE86C;
    int i = 9;
    do {
        func_80053928(p);
        p++;
    } while (--i != -1);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062610);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062764);

struct Entry_800627E8 {
    int w[40];
};

EXTERN_C Entry_800627E8 *D_800B4E30;

EXTERN_C void func_800627E8(Entry_800627E8 *out, int i)
{
    *out = D_800B4E30[i - 1];
}

EXTERN_C void *func_80062834(void *self)
{
    return self;
}

EXTERN_C int D_800B4E34;

EXTERN_C int func_8006283C(void)
{
    return D_800B4E34;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062848);

EXTERN_C int func_80062978(void *self)
{
    int old = FIELD_AT(self, int, 0x6C) != 0;
    FIELD_AT(self, int, 0x6C) = 0;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062988);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062A90);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062C3C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062D60);

EXTERN_C void func_800566E4(void *self);
EXTERN_C void func_80056874(void *self);

EXTERN_C void func_80062E70(void *self)
{
    func_800566E4(self);
    func_80056874(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062E9C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80062FA4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800630BC);

EXTERN_C void func_8008EF40(int b);

EXTERN_C void func_800631D4(void *self)
{
    func_8008EF40(0xC);
    func_800566E4(self);
    if (FIELD_AT(self, int, 0x64) < 0) {
        char *h = (char *)self + 0x1C;
        FIELD_AT(self, int, 0x64) = (h ? FIELD_AT(h, List *, 0x0) : 0)->count;
    }
    func_800550FC(self, FIELD_AT(self, int, 0x64));
}

EXTERN_C void func_80054FE0(void *self);
EXTERN_C void func_8008EF40(int b);

EXTERN_C void func_8006323C(void *self)
{
    func_80054FE0(self);
    func_80056874(self);
    func_8008EF40(0xD);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063270);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063340);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063584);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800635FC);

EXTERN_C void func_800588EC(void *self, unsigned int b);

EXTERN_C void func_80063714(void *self, unsigned int b)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    FIELD_AT(self, unsigned int, 0x64) = b;
    if (p != 0) {
        func_800588EC(p, b);
    }
}

EXTERN_C int func_80058270(void *self, int b);

EXTERN_C int func_80063744(void *self, int b)
{
    switch (b) {
    case 1:
        FIELD_AT(self, int, 0x20) = func_80058270(FIELD_AT(self, void *, 0x3C), -1);
        return 1;
    case 2:
        FIELD_AT(self, int, 0x20) = func_80058270(FIELD_AT(self, void *, 0x3C), 1);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800637A0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800638A8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800639F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063B14);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063BE4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063CA4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063D64);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063E18);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063F3C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80063FFC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800640D0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80064188);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80064290);

struct Entry_800643DC {
    char pad[0x30];
    unsigned short x;
    unsigned short y;
};

EXTERN_C void func_800643DC(void *self, int dx, int dy)
{
    Entry_800643DC *e = (Entry_800643DC *)((char *)self + D_800B4CF0.value * 16);
    e->x += dx;
    e->y += dy;
    func_8005F1D8(self);
}

EXTERN_C void func_80064420(void)
{
}

struct VEnt_80064428 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

EXTERN_C void func_80064428(void *self, int b, int c)
{
    VEnt_80064428 *vt = FIELD_AT(self, VEnt_80064428 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80064478);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80064570);

EXTERN_C void func_800646D4(void)
{
}

EXTERN_C void func_8005F120(void *self, int flags);

EXTERN_C void func_800646DC(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800646FC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80064884);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800648E8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80064B3C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80064C78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80064E0C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065458);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065870);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800658E0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065A00);

EXTERN_C char D_80015384[];
EXTERN_C void func_80039A88(void *self);

EXTERN_C void func_80065AA0(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80015384;
    func_80039A88(self);
}

EXTERN_C void func_80065AC8(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065AD0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065B5C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065C64);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065D20);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065E10);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80065EE0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066054);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066128);

EXTERN_C void func_80066054(void *self, int b, int c);

EXTERN_C void *func_800661F4(void *self, int b)
{
    func_80066054(self, b, 0);
    return self;
}

struct Vec_80066220 {
    int x, y, z, w;
};

EXTERN_C Vec_80066220 *func_80066220(Vec_80066220 *out, Vec_80066220 *a, Vec_80066220 *b)
{
    int x = a->x + b->x;
    int y = a->y + b->y;
    int z = a->z + b->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

struct Vec_80066260 {
    int x, y, z, w;
};

EXTERN_C Vec_80066260 *func_80066260(Vec_80066260 *out, Vec_80066260 *a)
{
    int x = -a->x;
    int y = -a->y;
    int z = -a->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

struct Vec_80066294 {
    int x, y, z, w;
};

EXTERN_C Vec_80066294 *func_80066294(Vec_80066294 *out, Vec_80066294 *a, Vec_80066294 *b)
{
    int x = a->x - b->x;
    int y = a->y - b->y;
    int z = a->z - b->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

struct SVec_800662D4 {
    short x, y, z, w;
};

EXTERN_C SVec_800662D4 *func_800662D4(SVec_800662D4 *out, SVec_800662D4 *a)
{
    short x = -a->x;
    short y = -a->y;
    short z = -a->z;
    short w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

EXTERN_C void func_80066128(void *self, int b);

EXTERN_C void *func_80066308(void *self, int b)
{
    func_80066128(self, b);
    return self;
}

EXTERN_C void *func_80066330(void *self, int b, int c)
{
    func_80066054(self, b, c);
    return self;
}

EXTERN_C void *func_80066358(void *self)
{
    return (char *)self + 0xB8;
}

struct Word_80066360 {
    char b[4];
};

EXTERN_C void func_80066360(void *self, Word_80066360 *src)
{
    FIELD_AT(self, Word_80066360, 0xB8) = *src;
    FIELD_AT(self, int, 0xBC) = 1;
}

EXTERN_C void *func_80066380(void *self)
{
    return (char *)self + 0x68;
}

struct Quad_80066388 {
    int w[4];
};

EXTERN_C void func_80066388(void *self, Quad_80066388 *src)
{
    Quad_80066388 q = *src;
    FIELD_AT(self, Quad_80066388, 0x68) = q;
}

EXTERN_C void *func_800663D4(void *self)
{
    return (char *)self + 0x48;
}

EXTERN_C void *func_800663DC(void *self)
{
    return (char *)self + 0x98;
}

EXTERN_C void *func_800663E4(void *self)
{
    return (char *)self + 0x78;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800663EC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800664F8);

EXTERN_C int func_800665BC(void *self)
{
    return FIELD_AT(self, int, 0x28);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800665C8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014CAC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014CFC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014D1C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014D5C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014DAC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014DCC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014E0C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014E5C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014E7C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014EAC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014EEC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80014FFC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_8001504C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_8001506C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800150BC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800151B4);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_8001521C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_8001526C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015364);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015384);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800153C4);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800153FC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015414);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066690);

EXTERN_C void func_80066C7C(void *self);

EXTERN_C void func_80066798(void *self)
{
    if (FIELD_AT(self, int, 0x60) == 0) {
        func_80066C7C(self);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800667C8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006692C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066A54);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066AF0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066BC0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066C7C);

EXTERN_C void func_80066D14(void *self)
{
    FIELD_AT(self, int, 0x60) = 1;
}

EXTERN_C int func_80066D20(void *self)
{
    return FIELD_AT(self, int, 0x48);
}

EXTERN_C char D_800154B4[];

EXTERN_C void *func_80066D2C(void *self, int b)
{
    FIELD_AT(self, void *, 0x0) = D_800154B4;
    FIELD_AT(self, int, 0x4) = b;
    return self;
}

EXTERN_C void func_80066D44(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_800154B4;
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_80066D78(void *self)
{
    func_80066C7C(FIELD_AT(self, void *, 0x4));
}

EXTERN_C void func_80066D9C(void)
{
}

EXTERN_C char D_800154D4[];

EXTERN_C void *func_80066DA4(void *self, int b, int c, int d, int e)
{
    FIELD_AT(self, void *, 0x0) = D_800154D4;
    FIELD_AT(self, int, 0x4) = b;
    FIELD_AT(self, int, 0xC) = c;
    FIELD_AT(self, int, 0x8) = d;
    if (d == 0) {
        FIELD_AT(self, int, 0x8) = FIELD_AT(self, int, 0x4);
    }
    FIELD_AT(self, int, 0x10) = e;
    return self;
}

EXTERN_C void func_8001D024(void *self);

EXTERN_C void func_80066DDC(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_800154D4;
    func_8001D024(self);
}

struct Mgr_800A4544 {
    int pad[4];
};
EXTERN_C Mgr_800A4544 D_800A4544;
EXTERN_C char D_80010338[];
EXTERN_C void func_8001D150(void *self, void *b);

EXTERN_C int func_80066E04(void *self)
{
    Mgr_800A4544 *m = &D_800A4544;
    void *o;
    func_8001D150(m, (o = operator new(0x14),
                                FIELD_AT(o, void * volatile, 0x0) = D_80010178,
                                FIELD_AT(o, int, 0x4) = 0,
                                FIELD_AT(o, void * volatile, 0x0) = D_80010338,
                                FIELD_AT(o, void *, 0x8) = self,
                                FIELD_AT(o, short, 0xC) = 0x80,
                                FIELD_AT(o, int, 0x10) = 1,
                                o));
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066E7C);

EXTERN_C short func_8008C928(int b);

EXTERN_C int func_80066F8C(void)
{
    return func_8008C928(0) == 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800154B4);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800154D4);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800154EC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80066FB0);

EXTERN_C char D_800154EC[];

EXTERN_C void func_8006707C(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_800154EC;
    func_8001D024(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800670A4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80067134);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80067450);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800674C8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006753C);

EXTERN_C void func_80054094(void *self, int b);
EXTERN_C void func_80067B1C(void *self, int b, void *c, void *d, int e);

EXTERN_C void func_80067ABC(void *self, void *b)
{
    func_80054094((char *)self + 0x64, FIELD_AT(b, unsigned char, 0x18) != 1);
    func_80067B1C(self, FIELD_AT(b, unsigned short, 0xC), (char *)b + 0x80, (char *)b + 0xE, FIELD_AT(b, unsigned char, 0x8A) & 0xF);
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015570);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015580);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015594);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800155AC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800155BC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800155CC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800155D8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800155E4);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800155F0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800155FC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015608);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015614);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015620);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_8001562C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015640);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015654);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015668);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015678);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80067B1C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800680A0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006821C);

EXTERN_C int func_800682A0(VObj<0x18> *self, void *b)
{
    func_8001FC78(b, 0, 0);
    if (FIELD_AT(b, unsigned short, 0x18) & 0x20) {
        self->v02();
    }
    return 1;
}

EXTERN_C int func_80068310(VObj<0x18> *self, void *b)
{
    func_8001FC78(b, 0, 0);
    if (FIELD_AT(b, unsigned short, 0x18) & 0x20) {
        self->v02();
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80068380);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800156B0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015700);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015720);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015750);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015790);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800157E0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015800);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015830);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80068660);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80068770);

EXTERN_C void func_8006897C(void *self, int b, int c)
{
    if (FIELD_AT(self, unsigned short, 0x1D00) != (unsigned short)b) {
        char *h;
        FIELD_AT(self, short, 0x1D00) = b;
        h = (char *)self + 0x1C;
        func_80019D40(h ? FIELD_AT(h, List *, 0x0) : 0);
        FIELD_AT(h, int, 0x4) = 0;
    }
    FIELD_AT(self, int, 0x1CFC) = c;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800689E0);

EXTERN_C int func_80068A50(void *self)
{
    return FIELD_AT(self, int, 0x1D04);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80068A5C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80068B14);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80068E60);

EXTERN_C void func_8006323C(void *self);
EXTERN_C void func_80053CD8(void *self);

struct E28_80068EE8 {
    char pad[0x28];
};

struct Obj_80068EE8 {
    char pad[0x1548];
    E28_80068EE8 e[0x31];
};

EXTERN_C void func_80068EE8(Obj_80068EE8 *self)
{
    unsigned int i;
    func_8006323C(self);
    for (i = 0; i < 0x31; i++) {
        func_80053CD8(&self->e[i]);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80068F3C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800690C8);

struct E6C_800691EC {
    char pad[0x6C];
};

struct E28_800691EC {
    char pad[0x28];
};

struct Obj_800691EC {
    char pad[0x9C];
    E6C_800691EC a[0x31];
    E28_800691EC b[0x31];
};

EXTERN_C void func_800691EC(Obj_800691EC *self, int i, int c)
{
    func_80054094(&self->a[i], c);
    func_80054094(&self->b[i], c);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80069264);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800694BC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800697A4);

EXTERN_C void func_80054FC0(void *self);

EXTERN_C void func_80069914(VObj<0x18> *self)
{
    self->v04();
    func_80054FC0(self);
}

EXTERN_C void func_80054FE0(void *self);

EXTERN_C void func_80069958(void *self)
{
    func_80054FE0(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80069978);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80069B2C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80069D1C);

EXTERN_C void func_800A0D0C(void *p);

EXTERN_C void func_80069E60(void *self, int flags)
{
    if (FIELD_AT(self, void *, 0x14) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x14));
    }
    FIELD_AT(self, void *, 0x14) = 0;
    if (FIELD_AT(self, void *, 0x1C) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x1C));
    }
    FIELD_AT(self, void *, 0x1C) = 0;
    if (flags & 1) {
        __builtin_delete(self);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80069ECC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80069F74);

EXTERN_C int func_8006A040(void *self)
{
    return FIELD_AT(self, int, 0x1C);
}

struct Word_8006A04C {
    char b[4];
};

// A field copy returned by value; the FIELD cast form calls memcpy instead.
struct Obj_8006A04C {
    char pad[0x20];
    Word_8006A04C w;
};

EXTERN_C Word_8006A04C func_8006A04C(Obj_8006A04C *self)
{
    return self->w;
}

EXTERN_C int func_8006A06C(void *self)
{
    return FIELD_AT(self, int, 0x14);
}

EXTERN_C int func_8006A078(void *self)
{
    return FIELD_AT(self, int, 0x18);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006A084);

EXTERN_C char D_800159C4[];

EXTERN_C void func_8006A194(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_800159C4;
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006A1BC);

EXTERN_C void func_8006A3C0(VObj0 *self, void *b)
{
    char *p;
    if (FIELD_AT(self, short, 0x8) == 1) {
        self->v08();
    }
    p = (char *)self + D_800B4CF0.value * 16;
    FIELD_AT(p, short, 0x2C) = FIELD_AT(b, short, 0x8);
    FIELD_AT(p, short, 0x2E) = FIELD_AT(b, short, 0xA);
    FIELD_AT(self, short, 0x8) = 2;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006A440);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006A4E4);

EXTERN_C void func_8006A588(VObj0 *self, void *b)
{
    char *p;
    if (FIELD_AT(self, short, 0x8) == 1) {
        self->v08();
    }
    p = (char *)self + D_800B4CF0.value * 16;
    FIELD_AT(p, short, 0x30) = FIELD_AT(b, short, 0xC);
    FIELD_AT(p, short, 0x32) = FIELD_AT(b, short, 0xE);
    FIELD_AT(self, short, 0x8) = 2;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006A608);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006A6D4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006A784);

EXTERN_C void func_8006A80C(void *self)
{
    FIELD_AT(self, int, 0x48) = 1;
}

EXTERN_C void func_8006A818(void *self)
{
    FIELD_AT(self, int, 0x48) = 0;
}

EXTERN_C int func_8006A820(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006A82C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006AB18);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006AD40);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015914);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015964);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015984);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800159C4);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015A14);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015B34);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015B84);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015B9C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015BB4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006AE68);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006AF94);

EXTERN_C void func_8006B024(void *self, int b)
{
    FIELD_AT(self, int, 0x260) = b;
    if (b < -30000) {
        FIELD_AT(self, int, 0x260) = -30000;
    }
    if (FIELD_AT(self, int, 0x260) > -5000) {
        FIELD_AT(self, int, 0x260) = -5000;
    }
}

EXTERN_C void func_8006B058(void *self, int b)
{
    int v = FIELD_AT(self, int, 0x28C);
    v += b;
    if (v > 800) {
        v = 800;
    }
    if (v < 450) {
        v = 450;
    }
    FIELD_AT(self, int, 0x28C) = v;
}

EXTERN_C void func_8006B08C(void *self, int b)
{
    int v = FIELD_AT(self, int, 0x28C);
    v -= b;
    if (v > 800) {
        v = 800;
    }
    if (v < 450) {
        v = 450;
    }
    FIELD_AT(self, int, 0x28C) = v;
}

EXTERN_C void func_8006B3D0(void *self, void *b);

EXTERN_C void func_8006B0C0(void *self, int b)
{
    int v = FIELD_AT(self, int, 0x260);
    v += b;
    if (v < -18000) {
        v = -18000;
    }
    if (v > -10000) {
        v = -10000;
    }
    FIELD_AT(self, int, 0x260) = v;
    func_8006B3D0(self, (char *)self + 0x2A0);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B120(void *self, int b)
{
    int v = FIELD_AT(self, int, 0x260);
    v -= b;
    if (v < -18000) {
        v = -18000;
    }
    if (v > -10000) {
        v = -10000;
    }
    FIELD_AT(self, int, 0x260) = v;
    func_8006B3D0(self, (char *)self + 0x2A0);
    FIELD_AT(self, int, 0x26C) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006B180);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006B1C8);

EXTERN_C void func_8006B058(void *self, int b);
EXTERN_C void func_8006B180(void *self, int b);
EXTERN_C void func_8006B0C0(void *self, int b);

EXTERN_C void func_8006B210(void *self)
{
    func_8006B058(self, 14);
    func_8006B180(self, 12);
    func_8006B0C0(self, 1000);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B258(void *self, int b)
{
    func_8006B058(self, 0xE);
    func_8006B180(self, 0xC);
    func_8006B0C0(self, (short)b);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B08C(void *self, int b);
EXTERN_C void func_8006B1C8(void *self, int b);
EXTERN_C void func_8006B120(void *self, int b);

EXTERN_C void func_8006B2B0(void *self)
{
    func_8006B08C(self, 14);
    func_8006B1C8(self, 12);
    func_8006B120(self, 1000);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B2F8(void *self, int b)
{
    func_8006B08C(self, 0xE);
    func_8006B1C8(self, 0xC);
    func_8006B120(self, (short)b);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B3D0(void *self, void *b);

EXTERN_C void func_8006B350(void *self, int b)
{
    FIELD_AT(self, short, 0x2A2) += b;
    func_8006B3D0(self, (char *)self + 0x2A0);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B390(void *self, int b)
{
    FIELD_AT(self, short, 0x2A2) -= b;
    func_8006B3D0(self, (char *)self + 0x2A0);
    FIELD_AT(self, int, 0x26C) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006B3D0);

EXTERN_C void func_8006BB04(void *self);
EXTERN_C void *func_8006D344(void *self, void *b, int c, int d, int e);
EXTERN_C int func_8006D8EC(void *self);

EXTERN_C int func_8006B540(void *self)
{
    void *o;
    func_8008EF40(0x13);
    func_8006BB04(self);
    o = func_8006D344(operator new(0x74), self ? (char *)self + 0x124 : 0, 0xC9, 0, 0xC8);
    FIELD_AT(self, void *, 0x224) = o;
    func_8006D8EC(o);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", SsGetMute);

EXTERN_C int func_8006B5CC(void)
{
    return 1;
}

EXTERN_C void func_8006DA60(void *self);

EXTERN_C void func_8006B5D4(void *self)
{
    void *p = FIELD_AT(self, void *, 0x224);
    if (p != 0) {
        func_8006DA60(p);
    }
    FIELD_AT(self, int, 0x278) = 5;
    FIELD_AT(self, int, 0x26C) = 0;
}

EXTERN_C void *func_8006C95C(void *self, void *b, int c);
EXTERN_C int func_8006CA80(void *self);

EXTERN_C void func_8006B618(void *self, int b)
{
    if (FIELD_AT(self, int, 0x274) == 0) {
        void *o;
        FIELD_AT(self, int, 0x278) = 6;
        FIELD_AT(self, int, 0x26C) = 0;
        o = func_8006C95C(operator new(0x20), self ? (char *)self + 0x124 : 0, b);
        FIELD_AT(self, void *, 0x270) = o;
        func_8006CA80(o);
        FIELD_AT(self, int, 0x274) = 1;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006B690);

EXTERN_C void func_8006B740(void *self, int b)
{
    if (FIELD_AT(self, int, 0x274) == 0) {
        void *o;
        FIELD_AT(self, int, 0x278) = 4;
        FIELD_AT(self, int, 0x26C) = 0;
        o = func_8006C95C(operator new(0x20), self ? (char *)self + 0x124 : 0, b);
        FIELD_AT(self, void *, 0x270) = o;
        func_8006CA80(o);
        FIELD_AT(self, int, 0x274) = 1;
    }
}

EXTERN_C void func_8006B7B8(void *self)
{
    if (FIELD_AT(self, int, 0x274) != 0) {
        FIELD_AT(self, int, 0x270) = 0;
        FIELD_AT(self, int, 0x274) = 0;
    }
}

EXTERN_C void func_8006B618(void *self, int b);

EXTERN_C void func_8006B7D8(void *self, int b)
{
    switch (b) {
    case 0:
        func_8006B618(self, 0xC9);
        break;
    case 1:
        func_8006B618(self, 0xCA);
        break;
    }
}

EXTERN_C void func_8006B690(void *self, int b);

EXTERN_C void func_8006B814(void *self, int b)
{
    switch (b) {
    case 0:
        func_8006B690(self, 0xCB);
        break;
    case 1:
        func_8006B690(self, 0xCC);
        break;
    }
}

EXTERN_C void func_800BE09C(void *a);
EXTERN_C void func_800BE18C(void *a, void *b);

struct Tmp_8006B850 {
    int a, b;
};

EXTERN_C void func_8006B850(void *self)
{
    Tmp_8006B850 t;
    func_800BE09C(&t);
    func_800BE18C(&t, (char *)self + 0x2A0);
}

EXTERN_C void func_8006B884(void *self)
{
    FIELD_AT(self, int, 0x260) = -20000;
    FIELD_AT(self, int, 0x28C) = 500;
    FIELD_AT(self, char, 0x298) = 10;
    FIELD_AT(self, char, 0x299) = 10;
    FIELD_AT(self, char, 0x29A) = 10;
    FIELD_AT(self, int, 0x258) = 0;
    FIELD_AT(self, int, 0x25C) = 0;
    FIELD_AT(self, int, 0x27C) = 0;
    FIELD_AT(self, int, 0x280) = 0;
    FIELD_AT(self, int, 0x284) = 0;
    FIELD_AT(self, short, 0x290) = 0;
    FIELD_AT(self, short, 0x292) = 0;
    FIELD_AT(self, short, 0x294) = 0;
    FIELD_AT(self, int, 0x29C) = 0;
    FIELD_AT(self, short, 0x2A0) = 0xF6E;
    FIELD_AT(self, short, 0x2A2) = 0;
    FIELD_AT(self, short, 0x2A4) = 0;
    FIELD_AT(self, int, 0x2A8) = 0;
    FIELD_AT(self, int, 0x2AC) = 0;
    FIELD_AT(self, int, 0x2B0) = 0;
}

struct Blk_8006B8E8;
EXTERN_C void func_8006C3C8(void *self, int b, Blk_8006B8E8 *c);

struct Blk_8006B8E8 {
    int v[4];
};

EXTERN_C void func_8006B8E8(void *self, int b, Blk_8006B8E8 *c)
{
    FIELD_AT(self, Blk_8006B8E8, 0x2C8) = *c;
    func_8006C3C8(self, b, c);
}

EXTERN_C void func_8006C4EC(void *self, int b);

struct V_8006B928 {
    int v[4];
};

EXTERN_C V_8006B928 func_8003B310(void);

EXTERN_C void func_8006B928(void *self, int b)
{
    FIELD_AT(self, V_8006B928, 0x2C8) = func_8003B310();
    func_8006C4EC(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006B988);

EXTERN_C void func_8006BC98(void *self);
EXTERN_C void *func_800A0D2C(int size);
EXTERN_C void func_80025CE0(void *p, int b, int c);

EXTERN_C int func_8006BA1C(void *self)
{
    void *p;

    func_8006BC98(self);
    p = func_800A0D2C(FIELD_AT(self, int, 0x238));
    FIELD_AT(self, void *, 0x24C) = p;
    func_80025CE0(p, FIELD_AT(self, int, 0x234), FIELD_AT(self, int, 0x238));
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006BA64);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006BB04);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006BC98);

EXTERN_C void func_8008D4C0(void *p);

EXTERN_C int func_8006BCF4(void *self)
{
    void *p = FIELD_AT(self, void *, 0x244);
    if (p != 0) {
        func_8008D4C0(p);
        FIELD_AT(self, void *, 0x244) = 0;
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006BD34);

EXTERN_C void func_8002DC34(void *self, int b, int c);

EXTERN_C int func_8006BDE0(void *self)
{
    if (FIELD_AT(self, int, 0x2E0) != 0) {
        func_8002DC34((void *)((VObj<0x2C> *)D_800A4578.p)->v11(), FIELD_AT(self, int, 0x250), 0);
        FIELD_AT(self, int, 0x2E0) = 0;
    }
    return 1;
}

EXTERN_C void *func_80066FB0(void *self, void *b, int c, int d, int e);
EXTERN_C void func_800670A4(void *self);

EXTERN_C int func_8006BE4C(void *self)
{
    func_800670A4(func_80066FB0(operator new(0x18), self ? (char *)self + 0x124 : 0, 0x6F, 0, 0));
    return 1;
}

struct Blk_8006BEA0 {
    int v[4];
};

EXTERN_C Blk_8006BEA0 *func_8006BEA0(Blk_8006BEA0 *out, void *self)
{
    *out = FIELD_AT(self, Blk_8006BEA0, 0x2C8);
    return out;
}

EXTERN_C int func_8006BECC(void)
{
    return 1;
}

EXTERN_C int func_8006BED4(void)
{
    return 1;
}

EXTERN_C int func_8006BEDC(void *self)
{
    return FIELD_AT(self, int, 0x22C);
}

EXTERN_C void func_8006BEE8(void *self)
{
    FIELD_AT(self, int, 0x22C) = 0;
}

EXTERN_C void func_8006BEF0(void *self)
{
    FIELD_AT(self, int, 0x22C) = 1;
}

EXTERN_C void func_8006BEFC(void *self)
{
    FIELD_AT(self, int, 0x94) = 1;
}

EXTERN_C void func_8006BF08(void *self)
{
    FIELD_AT(self, int, 0x2C0) = 0;
    FIELD_AT(self, int, 0x2BC) = 0;
    FIELD_AT(self, int, 0x2B8) = 0;
}

EXTERN_C void *func_8006BF18(void *self)
{
    return (char *)self + 0x2B8;
}

EXTERN_C void func_8006BF20(void *self, int *v)
{
    FIELD_AT(self, int, 0x2B8) = v[0];
    FIELD_AT(self, int, 0x2BC) = v[1];
    FIELD_AT(self, int, 0x2C0) = v[2];
}

EXTERN_C void func_8006BF44(void *self)
{
    FIELD_AT(self, int, 0x268) = 0;
}

EXTERN_C void func_8006BF4C(void *self)
{
    FIELD_AT(self, int, 0x268) = 1;
}

EXTERN_C int func_8006BF58(void *self)
{
    return FIELD_AT(self, int, 0x278);
}

EXTERN_C void func_8006BF64(void *self, int b)
{
    FIELD_AT(self, int, 0x278) = b;
    FIELD_AT(self, int, 0x26C) = 0;
}

EXTERN_C void func_8006BF70(void *self, int b)
{
    FIELD_AT(self, int, 0x254) = b;
}

EXTERN_C int func_8006BF78(void *self)
{
    return FIELD_AT(self, int, 0x254);
}

EXTERN_C void *func_8006BF84(void *self)
{
    return (char *)self + 0x7C;
}

EXTERN_C void *func_8006BF8C(void *self)
{
    return (char *)self + 0x84;
}

EXTERN_C int D_800B4ED8;

EXTERN_C int func_8006BF94(void)
{
    return D_800B4ED8;
}

EXTERN_C void *func_8006BFA0(void *self)
{
    return (char *)self + 0x2A0;
}

EXTERN_C int func_8006BFA8(void *self)
{
    return FIELD_AT(self, int, 0x260);
}

EXTERN_C void func_8006BFB4(void *self, int b)
{
    FIELD_AT(self, int, 0x28C) = FIELD_AT(b, int, 0x0);
}

EXTERN_C int func_8006BFC0(void *self)
{
    return FIELD_AT(self, int, 0x28C);
}

EXTERN_C int D_800B4ED4;

EXTERN_C void func_8006BFCC(void *self)
{
    FIELD_AT(self, int, 0x28C) = D_800B4ED4;
}

EXTERN_C int D_800B4ED0;

EXTERN_C int func_8006BFD8(void)
{
    return D_800B4ED0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006BFE4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006C204);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006C29C);

EXTERN_C void func_8002BD34(void *self);
EXTERN_C void func_8003944C(void *self, void *b);

struct Data_800B4D1C {
    int pad[4];
};

EXTERN_C Data_800B4D1C D_800B4D1C;

EXTERN_C void func_8006C310(void *self)
{
    func_8002BD34(self);
    ((VObj0 *)((char *)self + 0x50))->v01();
    if (FIELD_AT(self, void *, 0x78) != 0) {
        func_8003944C(FIELD_AT(self, void *, 0x78), &D_800B4D1C);
    }
}

EXTERN_C void func_8002B518(void *self, int b, int c);

EXTERN_C void func_8006C36C(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x114) += (b - FIELD_AT(self, short, 0x10)) / 2;
    FIELD_AT(self, int, 0x118) += (c - FIELD_AT(self, short, 0x12)) / 2;
    func_8002B518(self, b, c);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006C3C8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006C4EC);

struct Vec_8006C61C {
    int x, y, z, w;
};

EXTERN_C Vec_8006C61C *func_8006C61C(Vec_8006C61C *out, Vec_8006C61C *a)
{
    int x = -a->x;
    int y = -a->y;
    int z = -a->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

EXTERN_C int func_8006C650(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006C65C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006C77C);

EXTERN_C char D_80015DBC[];
EXTERN_C void func_8002EC90(void *self, void *b);
EXTERN_C void func_8002EC40(void *self, void *b);

struct Data_800B4C78 {
    int pad[4];
};

struct Data_800B4C98 {
    int pad[4];
};

EXTERN_C Data_800B4C78 D_800B4C78;
EXTERN_C Data_800B4C98 D_800B4C98;

EXTERN_C void *func_8006C8D8(void *self, void *b, int c)
{
    func_8002EEC4(self, b);
    FIELD_AT(self, void *, 0x0) = D_80015DBC;
    FIELD_AT(self, int, 0x14) = c;
    func_8002EC90(self, &D_800B4C78);
    func_8002EC40(self, &D_800B4C98);
    return self;
}

EXTERN_C void func_8002EEFC(void *self);

EXTERN_C void func_8006C93C(void *self)
{
    func_8002EEFC(self);
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015C0C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015C5C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015C9C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015DBC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015E5C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006C95C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006C9F8);

EXTERN_C int func_8006CA80(void *self)
{
    Mgr_800A4544 *m = &D_800A4544;
    void *o;
    func_8001D150(m, (o = operator new(0x14),
                                FIELD_AT(o, void * volatile, 0x0) = D_80010178,
                                FIELD_AT(o, int, 0x4) = 0,
                                FIELD_AT(o, void * volatile, 0x0) = D_80010338,
                                FIELD_AT(o, void *, 0x8) = self,
                                FIELD_AT(o, short, 0xC) = 0x80,
                                FIELD_AT(o, int, 0x10) = 1,
                                o));
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006CAF8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006CBCC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006CD98);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006CF84);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006D290);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006D344);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006D768);

EXTERN_C int func_8006D8EC(void *self)
{
    Mgr_800A4544 *m = &D_800A4544;
    void *o;
    func_8001D150(m, (o = operator new(0x14),
                                FIELD_AT(o, void * volatile, 0x0) = D_80010178,
                                FIELD_AT(o, int, 0x4) = 0,
                                FIELD_AT(o, void * volatile, 0x0) = D_80010338,
                                FIELD_AT(o, void *, 0x8) = self,
                                FIELD_AT(o, short, 0xC) = 0x80,
                                FIELD_AT(o, int, 0x10) = 1,
                                o));
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006D964);

EXTERN_C void func_8006DA60(void *self)
{
    FIELD_AT(self, int, 0x60) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006DA6C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006DF68);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006E234);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006E73C);

EXTERN_C char D_80015EB8[];

EXTERN_C void func_8006E8BC(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80015EB8;
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006E8E4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006EACC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006EBB0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006EC70);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006EDD8);

EXTERN_C void func_8006EE8C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006EE94);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006EF84);

EXTERN_C int func_8006F040(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C char D_80015FD0[];
struct Sub_8006FDD8 {
    int a, b, c, d;
};
struct Obj_8006FDD8 {
    int a;
    int b;
    int c;
    Sub_8006FDD8 sub;
    int d;
};
EXTERN_C Obj_8006FDD8 *func_8006FDD8(Obj_8006FDD8 *self);
struct Flag_800AF408 {
    int v;
    int pad[2];
};
EXTERN_C Flag_800AF408 D_800AF408;
struct Flag_800AF40C {
    int v;
    int pad[2];
};
EXTERN_C Flag_800AF40C D_800AF40C;

EXTERN_C void *func_8006F04C(void *self)
{
    FIELD_AT(self, void *, 0xA4) = D_80015FD0;
    func_8006FDD8((Obj_8006FDD8 *)((char *)self + 0x4));
    func_8006FDD8((Obj_8006FDD8 *)((char *)self + 0x34));
    func_8006FDD8((Obj_8006FDD8 *)((char *)self + 0x64));
    FIELD_AT(self, int, 0x0) = 0;
    D_800AF410.state = 0;
    D_800AF40C.v = 0;
    D_800AF408.v = 0;
    return self;
}

EXTERN_C void func_8006F0B0(void *self, int flags)
{
    FIELD_AT(self, void *, 0xA4) = D_80015FD0;
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_8006F0E4(void *self, int b)
{
    FIELD_AT(self, int, 0x0) = b;
}

EXTERN_C void func_8006F0EC(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
}

EXTERN_C void func_8006F0F4(void *self, int b, int c, int d, int e)
{
    FIELD_AT(self, int, 0x94) = b;
    FIELD_AT(self, int, 0x98) = c;
    FIELD_AT(self, int, 0x9C) = d;
    FIELD_AT(self, int, 0xA0) = e;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006F10C);

struct VEnt_8006F154 {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

EXTERN_C void func_8006F154(void *self)
{
    VEnt_8006F154 *vt = FIELD_AT(self, VEnt_8006F154 *, 0xA4);
    D_800AF410.state = 2;
    vt[2].pfn((char *)self + vt[2].delta, FIELD_AT(self, int, 0x98));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006F194);

struct VEnt_8006F268 {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

EXTERN_C void func_8006F268(void *self)
{
    VEnt_8006F268 *vt = FIELD_AT(self, VEnt_8006F268 *, 0xA4);
    D_800AF410.state = 6;
    vt[2].pfn((char *)self + vt[2].delta, FIELD_AT(self, int, 0xA0));
}

EXTERN_C void func_8006F194(void *self);

EXTERN_C void func_8006F2A8(void *self)
{
    D_800AF410.state = 3;
    if (D_800AF408.v != 0) {
        D_800AF408.v = 0;
        func_8006F194(self);
    }
}

EXTERN_C void func_8006F10C(void *self);

EXTERN_C void func_8006F2E8(void *self)
{
    D_800AF410.state = 0;
    if (D_800AF40C.v != 0) {
        D_800AF40C.v = 0;
        func_8006F10C(self);
    }
}

struct Obj_8006F31C {
    int pad0;
    int b;
    char pad8[0x9C];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int b);
};

EXTERN_C void func_8006F31C(Obj_8006F31C *self)
{
    int *mode = &D_800AF410.state;
    *mode = 5;
    self->f3(self->b);
}

struct VEnt_8006F35C {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

EXTERN_C void func_8006F35C(void *self)
{
    if (D_800AF40C.v != 0) {
        D_800AF40C.v = 0;
        func_8006F10C(self);
    } else if (D_800AF408.v != 0) {
        D_800AF408.v = 0;
        func_8006F194(self);
    } else {
        VEnt_8006F35C *vt = FIELD_AT(self, VEnt_8006F35C *, 0xA4);
        int a = FIELD_AT(self, int, 0x4);
        D_800AF410.state = 0;
        vt[5].pfn((char *)self + vt[5].delta, a);
    }
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015EA0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015EB8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006F3DC);

EXTERN_C int func_8006F52C(void *self, int *a, int *b)
{
    int r;

    if (D_800AF410.state == 0) {
        return 0;
    }
    r = FIELD_AT(self, int, 0x24);
    if (r <= 0) {
        r = -1;
    }
    *a = r;
    *b = FIELD_AT(self, int, 0x28);
    return 1;
}

EXTERN_C int func_8006F570(void *self, int *a, int *b)
{
    int r;

    if (D_800AF410.state == 0) {
        return 0;
    }
    r = FIELD_AT(self, int, 0x2C);
    if (r <= 0) {
        r = -1;
    }
    *a = r;
    *b = FIELD_AT(self, int, 0x30);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006F5B4);

EXTERN_C int func_8006F630(void)
{
    switch (D_800AF410.state) {
    case 0:
    case 5:
        D_800AF410.state = 0;
        return 1;
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006F67C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006F8B4);

EXTERN_C void func_8006F268(void *self);

EXTERN_C int func_8006FA84(void *self)
{
    if (D_800AF410.state == 5) {
        func_8006F268(self);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006FAC0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006FCC0);

EXTERN_C Obj_8006FDD8 *func_8006FDD8(Obj_8006FDD8 *self)
{
    Sub_8006FDD8 *s;
    self->a = 0;
    self->b = -1;
    self->c = -1;
    s = &self->sub;
    s->a = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
    self->d = -1;
    return self;
}

EXTERN_C void func_8006FE08(void *self, int b, int c, int d)
{
    FIELD_AT(self, int, 0x20) = c;
    FIELD_AT(self, int, 0x24) = d;
}

EXTERN_C void func_8006FE14(void *self, int b, int c, int d, int e, int f)
{
    FIELD_AT(self, int, 0x20) = c;
    FIELD_AT(self, int, 0x24) = d;
    FIELD_AT(self, int, 0x28) = e;
    FIELD_AT(self, int, 0x2C) = f;
}

EXTERN_C int func_8006FE30(void *self, int b, int c, int d)
{
    return FIELD_AT(self, int, 0x20) == c && FIELD_AT(self, int, 0x24) == d;
}

EXTERN_C void func_8006FE58(void *self, int b)
{
    FIELD_AT(self, int, 0x0) = b;
}

EXTERN_C void func_8006FE60(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x0) = b;
    FIELD_AT(self, int, 0x8) = c;
}

struct Four_8006FE6C {
    int v[4];
};

struct Obj_8006FE6C {
    int a;
    int pad;
    int b;
    Four_8006FE6C s;
    int h;
};

EXTERN_C void func_8006FE6C(Obj_8006FE6C *self, int a, int b, Four_8006FE6C s, int h)
{
    self->a = a;
    self->b = b;
    self->s = s;
    self->h = h;
}

struct Four_8006FEA4 {
    int v[4];
};

struct Obj_8006FEA4 {
    int a;
    int b;
    int c;
    Four_8006FEA4 s;
    int h;
};

EXTERN_C void func_8006FEA4(Obj_8006FEA4 *self, int a, int b, int c, Four_8006FEA4 s, int h)
{
    self->a = a;
    self->b = b;
    self->c = c;
    self->s = s;
    self->h = h;
}

EXTERN_C int func_8006FEDC(void)
{
    return D_800AF410.state;
}

EXTERN_C char D_80016280[];
EXTERN_C char D_80016298[];
EXTERN_C void *func_8007778C(void *self);
EXTERN_C void *func_800756F8(void *self);

struct Obj_8006FEEC {
    char pad[0x44];
    short items[0x10];
};

EXTERN_C void *func_8006FEEC(void *p)
{
    Obj_8006FEEC *self = (Obj_8006FEEC *)p;
    int i;
    short v;
    func_8007778C(self);
    func_800756F8((char *)self + 0x40);
    FIELD_AT(self, void *, 0x40) = D_80016280;
    FIELD_AT(self, void *, 0x8) = D_80016298;
    v = -1;
    for (i = 0xF; i >= 0; i--) {
        self->items[i] = v;
    }
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8006FF50);

EXTERN_C int func_80077854(void *self, int b, int c);
EXTERN_C void func_80077210(void *self, void *b);
EXTERN_C void func_800766D8(void *self);

EXTERN_C void func_8006FFDC(void *self, int b)
{
    if (func_80077854(self, b, 0x100) != 0 && FIELD_AT(self, void *, 0x68) != 0) {
        func_80077210(FIELD_AT(self, void *, 0x68), self);
    }
    func_800766D8(FIELD_AT(self, void *, 0x64));
}

EXTERN_C void func_80070030(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80070038);

EXTERN_C int func_8007027C(void)
{
    return 0;
}

EXTERN_C int func_80070284(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0xC);
}

EXTERN_C int func_80070298(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0x10);
}

EXTERN_C int func_800702AC(void)
{
    return FIELD_AT(FIELD_AT(D_800AF470.p, void *, 0x328), int, 0x14C);
}

EXTERN_C int func_800702CC(void)
{
    return FIELD_AT(FIELD_AT(D_800AF470.p, void *, 0x328), int, 0x150);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800702EC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80070384);

struct V_80070440 {
    int a, b, c, d;
};

EXTERN_C int func_80070440(void)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    char *h = p ? (char *)p + 0xB8 : 0;
    V_80070440 t = FIELD_AT(FIELD_AT(FIELD_AT(h, void *, 0x8), void *, 0x1B8), V_80070440, 0x34);
    return t.a;
}

struct V_8007049C {
    int a, b, c, d;
};

EXTERN_C int func_8007049C(void)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    char *h = p ? (char *)p + 0xB8 : 0;
    V_8007049C t = FIELD_AT(FIELD_AT(FIELD_AT(h, void *, 0x8), void *, 0x1B8), V_8007049C, 0x34);
    return t.b;
}

struct V_800704F8 {
    int a, b, c, d;
};

EXTERN_C int func_800704F8(void)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    char *h = p ? (char *)p + 0xB8 : 0;
    V_800704F8 t = FIELD_AT(FIELD_AT(FIELD_AT(h, void *, 0x8), void *, 0x1B8), V_800704F8, 0x34);
    return t.c;
}

EXTERN_C int func_80070554(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0x30);
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80015FD0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80070568);

EXTERN_C void func_8007AD14(void *self, int b, int c, int d, int e, int f, int g);

EXTERN_C int func_80070DA0(int a, int b, int c, int d, int e, int f, int g)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_8007AD14(p ? (char *)p + 0xA8 : 0, b, c, d, e, f, g);
    return 0;
}

EXTERN_C int func_8007ADCC(void *self);

EXTERN_C int func_80070DF8(void)
{
    char *p = FIELD_AT(D_800AF470.p, char *, 0x328);
    char *q = 0;
    if (p != 0) {
        q = p + 0xA8;
    }
    func_8007ADCC(q);
    return 0;
}

EXTERN_C void func_8007D744(void *self);

EXTERN_C int func_80070E34(void)
{
    func_8007D744(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C void func_8006F3DC(void *self, int b, int c, int d, int e, int f);

EXTERN_C int func_80070E60(void *self, int b, int c, int d, int e, int f)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_8006F3DC(p, b, c, d, e, f);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80070E98);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80070F30);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80070FC8);

EXTERN_C void func_800DE3B8(void *self, int b, int c, int d, int e, int f, int g);

EXTERN_C int func_80071080(void *self, int b, int c, int d, int e, int f, int g)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_800DE3B8(p, b, c, d, e, f, g);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800710C0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80071148);

EXTERN_C void func_8007D6D0(void *self);

EXTERN_C int func_800711D0(void)
{
    func_8007D6D0(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C void func_8007FB30(void *self, int b);

EXTERN_C int func_800711FC(void *self, int b)
{
    func_8007FB30(D_800AF470.p, b);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80071224);

EXTERN_C int func_80071250(void)
{
    return 0;
}

EXTERN_C void func_8008022C(void *self);

EXTERN_C int func_80071258(void)
{
    func_8008022C((char *)D_800AF470.p + 0x4A0);
    return 0;
}

EXTERN_C void func_800802E0(void *self, int b);

EXTERN_C int func_80071280(void *self, int b)
{
    func_800802E0((char *)D_800AF470.p + 0x4A0, b);
    return 0;
}

EXTERN_C int func_8007FE4C(void *self, int b, int c);

EXTERN_C int func_800712A8(void *self, int b, int c)
{
    return func_8007FE4C((char *)D_800AF470.p + 0x498, b, c);
}

EXTERN_C void func_8007FF58(void *self, int b, int c, int d);

EXTERN_C void func_800712D0(void *self, int b, int c, int d)
{
    func_8007FF58((char *)D_800AF470.p + 0x498, b, c, d);
}

EXTERN_C int func_80080110(void *self, int b);

EXTERN_C void func_800712F8(void *self, int b)
{
    func_80080110((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_80080130(void *self, int b);

EXTERN_C int func_80071320(void *self, int b)
{
    return func_80080130((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_80080180(void *self, int b);

EXTERN_C int func_80071348(void *self, int b)
{
    return func_80080180((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_800801D0(void *self, int b, int c);

EXTERN_C int func_80071370(void *self, int b, int c)
{
    return func_800801D0((char *)D_800AF470.p + 0x498, b, c);
}

EXTERN_C void func_800DF758(void *self, int b, int c, int d);

EXTERN_C int func_80071398(void *self, int b, int c, int d)
{
    func_800DF758((char *)D_800AF470.p + 0x4B0, b, c, d);
    return 0;
}

EXTERN_C int func_800713C0(void *self, int b, int c, int d, int e)
{
    func_800DF758((char *)D_800AF470.p + 0x4B0, b, c, e);
    return 0;
}

EXTERN_C void func_800DF938(void *self);

EXTERN_C int func_800713EC(void)
{
    func_800DF938((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C void func_800DF9A8(void *self);

EXTERN_C int func_80071414(void)
{
    func_800DF9A8((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C void func_800DFB10(void *p);

EXTERN_C int func_8007143C(void)
{
    func_800DFB10((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C void func_8007E214(void *self);

EXTERN_C int func_80071464(void)
{
    func_8007E214(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C void func_8007E30C(void *self);

EXTERN_C int func_80071490(void)
{
    func_8007E30C(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

struct V_800714BC {
    int a, b, c, d;
};

EXTERN_C void func_800DED18(void *self, V_800714BC v);

EXTERN_C int func_800714BC(int a, int b, int c, int d)
{
    V_800714BC t;
    V_800714BC *p = &t;
    p->a = b;
    p->b = c;
    p->c = d;
    p->d = 0;
    func_800DED18(D_800AF470.p, t);
    return 0;
}

EXTERN_C void func_800DED9C(void *self);

EXTERN_C int func_80071510(void)
{
    func_800DED9C(D_800AF470.p);
    return 0;
}

EXTERN_C void func_800DEDD4(void *self);

EXTERN_C int func_80071538(void)
{
    func_800DEDD4(D_800AF470.p);
    return 0;
}

EXTERN_C void func_800DEE50(void *self);

EXTERN_C int func_80071560(void)
{
    func_800DEE50(D_800AF470.p);
    return 0;
}

EXTERN_C void func_800DEED4(void *self);

EXTERN_C int func_80071588(void)
{
    func_800DEED4(D_800AF470.p);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800715B0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007164C);

EXTERN_C void *func_8006FEEC(void *self);
EXTERN_C void func_8006FF50(void *self, int b, int c, void *d);

EXTERN_C void func_80071820(void *self, int b, int c)
{
    void *o = func_8006FEEC(operator new(0x6C));
    FIELD_AT(self, void *, 0x54) = o;
    func_8006FF50(o, b, c, self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80071880);

EXTERN_C void func_80076EF8(void *self, int b);

EXTERN_C void func_80071904(void)
{
    func_80076EF8(&D_800AF414, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007192C);

EXTERN_C void *func_80076EA8(void *self);


EXTERN_C void func_80071A40(void)
{
    func_80076EA8(&D_800AF414);
    D_800AF414.a = 0;
    D_800AF414.b = 0;
}

EXTERN_C void func_80071A74(void *self, int b)
{
    func_80076EF8(self, b);
}

EXTERN_C void *func_80071A94(void *self)
{
    func_80076EA8(self);
    FIELD_AT(self, int, 0x54) = 0;
    FIELD_AT(self, int, 0x58) = 0;
    return self;
}

EXTERN_C void *func_800751AC(void *self);

EXTERN_C void *func_80071AC4(void *self)
{
    return func_800751AC(self);
}

EXTERN_C void func_8007505C(void *self, void *node);

EXTERN_C void func_80071AE4(void *self, void *node)
{
    func_8007505C(self, node);
}

EXTERN_C void func_80074F78(void *self, int b);

EXTERN_C void func_80071B04(void *self, int b)
{
    func_80074F78(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80071B24);

EXTERN_C void *func_80074E28(void *self);
EXTERN_C char D_80016270[];

struct Obj_80071BDC {
    char pad[0x1C];
    int list[4];
};

EXTERN_C Obj_80071BDC *func_80071BDC(Obj_80071BDC *self)
{
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016270;
    int *l = self->list;
    l[0] = 0;
    l[1] = 0;
    l[2] = 0;
    l[3] = 0;
    return self;
}


EXTERN_C void func_80074E44(void *self, int flags);

EXTERN_C void func_80071C24(void *self, int b)
{
    func_80074E44(self, b);
}

EXTERN_C void func_800777E8(void *self, int b);

EXTERN_C void func_80071C44(void *self, int b)
{
    FIELD_AT(self, void *, 0x40) = D_80016280;
    FIELD_AT(self, void *, 0x8) = D_80016298;
    func_800777E8(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80071C78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80071D90);

EXTERN_C void *func_8003912C(void *self, int b);
EXTERN_C void func_80039BEC(void *self, int b);

EXTERN_C void func_80071E90(void *self)
{
    if (FIELD_AT(self, int, 0x298) != 0 && FIELD_AT(self, void *, 0x1B8) != 0) {
        void *r = func_8003912C(FIELD_AT(self, void *, 0x1B8), FIELD_AT(FIELD_AT(self, void *, 0x550), unsigned char, 0x8A) == 8 ? 0x12 : 0xD);
        if (r != 0) {
            func_80039BEC(r, FIELD_AT(self, int, 0x298));
        }
    }
}

EXTERN_C void func_80039C88(void *self, int b);

EXTERN_C void func_80071F08(void *self)
{
    if (FIELD_AT(self, int, 0x298) != 0) {
        int k = FIELD_AT(FIELD_AT(self, void *, 0x550), unsigned char, 0x8A) == 8 ? 0x12 : 0xD;
        func_80039C88(func_8003912C(FIELD_AT(self, void *, 0x1B8), k), FIELD_AT(self, int, 0x298));
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80071F6C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80072130);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800722EC);

EXTERN_C void func_80072508(void)
{
}

EXTERN_C void func_80072B84(void *self, int b);

EXTERN_C void func_80072510(void *self)
{
    func_80072B84(self, FIELD_AT(self, short, 0x140));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80072534);

EXTERN_C void func_80074564(void *self);
EXTERN_C void func_80073960(void *self);

EXTERN_C int func_800725F4(void *self)
{
    if (FIELD_AT(self, short, 0x220) == 0) {
        func_80074564(self);
    } else {
        func_80073960(self);
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80072634);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800727DC);

EXTERN_C int func_800728C0(void)
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800728C8);

EXTERN_C void func_800232A0(void *self, void *b);

struct Tgt_80072970 {
    char pad[0x1A4];
    short a;
    short b;
    char pad2[0xB0];
    short c;
};

struct View_80072970 {
    char pad[0x44];
    Tgt_80072970 *p;
};

EXTERN_C void func_80072970(void *self)
{
    View_80072970 *g = (View_80072970 *)&D_800A4534;
    int v = FIELD_AT(self, short, 0x5D0);
    FIELD_AT(self, short, 0x5CC) = 0;
    FIELD_AT(self, short, 0x142) = 0;
    g->p->c = v;
    g->p->a = FIELD_AT(self, short, 0x5D4);
    g->p->b = FIELD_AT(self, short, 0x5D8);
    func_800232A0((char *)g->p + 0x154, self);
    FIELD_AT(self, short, 0x140) = 0;
    FIELD_AT(self, short, 0x5DC) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800729E8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80072B84);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80072CFC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80072E70);

EXTERN_C void func_80073960(void *self)
{
    FIELD_AT(self, short, 0x5C8) = 0;
    FIELD_AT(self, short, 0x140) = 0;
    FIELD_AT(self, short, 0x5DC) = 0;
    FIELD_AT(self, int, 0xF8) = 0;
    FIELD_AT(self, unsigned char, 0x120)++;
}

EXTERN_C void func_80073980(void *self)
{
    FIELD_AT(self, short, 0x5C8) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007398C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80073C04);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016270);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016280);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016298);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800162B0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016300);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016310);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800163A8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800163C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800163E0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016410);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80074468);

EXTERN_C void func_80044590(void *self);
EXTERN_C void func_80073960(void *self);

EXTERN_C void func_80074564(void *self)
{
    if (FIELD_AT(self, short, 0x220) == 2) {
        func_80044590(self);
    }
    FIELD_AT(self, short, 0x220) = 0;
    func_80073960(self);
}

EXTERN_C void func_800745A8(void *self, int b)
{
    FIELD_AT(self, short, 0x5CE) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800745B0);

struct Vec_8007460C {
    int x, y, z, w;
};

EXTERN_C Vec_8007460C *func_8007460C(Vec_8007460C *out, Vec_8007460C *a, Vec_8007460C *b)
{
    int x = a->x + b->x;
    int y = a->y + b->y;
    int z = a->z + b->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *p);

EXTERN_C void func_8007464C(void *self)
{
    void *o = func_8001CA10(0x14);
    FIELD_AT(o, void * volatile, 0x0) = D_80010178;
    FIELD_AT(o, int, 0x4) = 0;
    FIELD_AT(o, void * volatile, 0x0) = D_80010300;
    FIELD_AT(o, short, 0x8) = 2;
    FIELD_AT(o, short, 0xA) = 0xC;
    FIELD_AT(o, int, 0xC) = 0;
    FIELD_AT(o, int, 0x10) = 0x65;
    FIELD_AT(o, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, o);
}

EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *p);

EXTERN_C void func_800746C4(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 0xC;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 100;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007473C(void *self, int b)
{
    FIELD_AT(self, short, 0x5CA) = b;
}

struct D_80074744 : VPad<0x1DC>, virtual VObj0 {
};

struct A_80074744 {
    int x;
};

struct B_80074744 : A_80074744 {
    int y;
};

EXTERN_C int func_80074744(D_80074744 *self, int b)
{
    int c = b;
    if (c != 0) {
        self->v02(c);
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007479C);

EXTERN_C void func_800749A8(void)
{
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800164C8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016518);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016528);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800165C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800165E0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800165F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800749B0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80074AB4);

struct Vec_80074C50 {
    int x, y, z, w;
};

EXTERN_C Vec_80074C50 *func_80074C50(Vec_80074C50 *out, Vec_80074C50 *a, Vec_80074C50 *b)
{
    int x = a->x + b->x;
    int y = a->y + b->y;
    int z = a->z + b->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80074C90);

EXTERN_C char D_800166A8[];

EXTERN_C void *func_80074E28(void *self)
{
    FIELD_AT(self, void *, 0x8) = D_800166A8;
    FIELD_AT(self, void *, 0x4) = self;
    FIELD_AT(self, void *, 0x0) = self;
    return self;
}

// GCC 2.x deleting destructor: bit 0 of flags frees the object.
EXTERN_C void func_80074E44(void *self, int flags)
{
    FIELD_AT(self, void *, 0x8) = D_800166A8;
    if (flags & 1) {
        operator delete(self);
    }
}

struct Node_80074E78 {
    Node_80074E78 *next;
    Node_80074E78 *prev;
};

EXTERN_C void func_80074E78(Node_80074E78 *a, Node_80074E78 *b)
{
    Node_80074E78 *t;
    a->prev->next = b;
    b->prev->next = a;
    t = a->prev;
    a->prev = b->prev;
    b->prev = t;
}

struct Node_80074EA4 {
    Node_80074EA4 *next;
    Node_80074EA4 *prev;
};

EXTERN_C Node_80074EA4 *func_80074EA4(Node_80074EA4 *head)
{
    Node_80074EA4 *n = head->next;
    if (n == head) {
        return 0;
    }
    head->prev->next = n;
    head->next->prev = head->prev;
    head->prev = head;
    head->next = head;
    return n;
}

struct Node_80074EE8 {
    Node_80074EE8 *next;
};

EXTERN_C int func_80074EE8(Node_80074EE8 *a)
{
    int n = 1;
    Node_80074EE8 *p;
    for (p = a; p->next != a; p = p->next) {
        n++;
    }
    return n;
}

EXTERN_C void func_80074E78(Node_80074E78 *a, Node_80074E78 *b);

EXTERN_C void func_80074F1C(void *self, Node_80074E78 *b)
{
    func_80074E78(FIELD_AT(self, Node_80074E78 *, 0x0), b);
}

EXTERN_C int func_80074F40(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_80074F4C(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

EXTERN_C char D_800166B8[];

EXTERN_C void *func_80074F58(void *self)
{
    FIELD_AT(self, void *, 0xC) = D_800166B8;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x8) = 0;
    return self;
}

EXTERN_C void func_80074F78(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_800166B8;
    if (b & 1) {
        operator delete(self);
    }
}

struct Node_80074FAC {
    Node_80074FAC *next;
    Node_80074FAC *prev;
};

struct List_80074FAC {
    Node_80074FAC *head;
    Node_80074FAC *cur;
};

EXTERN_C int func_80074FAC(List_80074FAC *self, Node_80074FAC *n)
{
    Node_80074FAC *p;
    if (self->head == 0) {
        return 0;
    }
    p = self->head;
    do {
        if (p == n) {
            self->cur = p;
            return 1;
        }
        if (p == self->head->prev) {
            break;
        }
        p = p->next;
    } while (1);
    return 0;
}

EXTERN_C int func_80074EE8(Node_80074EE8 *a);

struct List_80075004 {
    Node_80074E78 *head;
    Node_80074E78 *cur;
    int count;
};

EXTERN_C void func_80075004(List_80075004 *self, Node_80074E78 *n)
{
    self->count += func_80074EE8((Node_80074EE8 *)n);
    if (self->head != 0) {
        func_80074E78(n, self->head);
    }
    self->head = n;
    self->cur = n;
}

EXTERN_C void func_8007505C(void *self, void *node)
{
    FIELD_AT(self, int, 0x8) += func_80074EE8((Node_80074EE8 *)node);
    if (FIELD_AT(self, void *, 0x0) == 0) {
        FIELD_AT(self, void *, 0x0) = node;
    } else {
        func_80074E78(FIELD_AT(self, Node_80074E78 *, 0x0), (Node_80074E78 *)node);
    }
    FIELD_AT(self, void *, 0x4) = node;
}

EXTERN_C void func_800750B8(void *self, void *node)
{
    if (FIELD_AT(self, void *, 0x0) == 0) {
        func_8007505C(self, node);
    } else {
        FIELD_AT(self, int, 0x8) += func_80074EE8((Node_80074EE8 *)node);
        func_80074E78(FIELD_AT(self, Node_80074E78 *, 0x4)->next, (Node_80074E78 *)node);
        FIELD_AT(self, void *, 0x4) = node;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80075128);

EXTERN_C Node_80074EA4 *func_80074EA4(Node_80074EA4 *head);

EXTERN_C void *func_800751AC(void *self)
{
    Node_80074EA4 *n = FIELD_AT(self, Node_80074EA4 *, 0x0);
    Node_80074EA4 *r;
    if (n == 0) {
        return 0;
    }
    r = func_80074EA4(n);
    FIELD_AT(self, Node_80074EA4 *, 0x0) = r;
    if (FIELD_AT(self, Node_80074EA4 *, 0x4) == n) {
        FIELD_AT(self, Node_80074EA4 *, 0x4) = r;
    }
    if (--FIELD_AT(self, int, 0x8) == 0) {
        FIELD_AT(self, void *, 0x4) = 0;
        FIELD_AT(self, void *, 0x0) = 0;
    }
    return n;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80075220);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800752B8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80075358);

EXTERN_C void *func_800752B8(void *self);

struct Node_800753F8 {
    Node_800753F8 *next;
    Node_800753F8 *prev;
};

EXTERN_C void *func_800753F8(void *self)
{
    Node_800753F8 *h = FIELD_AT(self, Node_800753F8 *, 0x0);
    Node_800753F8 *c = FIELD_AT(self, Node_800753F8 *, 0x4);
    if (h == c) {
        return 0;
    }
    if (h != 0) {
        FIELD_AT(self, Node_800753F8 *, 0x4) = c->prev;
    }
    return func_800752B8(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80075448);

EXTERN_C int func_800755AC(void *self)
{
    void *p = FIELD_AT(self, void *, 0x0);
    if (p == 0) {
        return 0;
    }
    return FIELD_AT(p, int, 0x4);
}

EXTERN_C int func_800755C8(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

EXTERN_C int func_800755D4(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800755E0(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C void func_800755EC(void *self)
{
    void *p = FIELD_AT(self, void *, 0x0);
    if (p != 0) {
        void *c = FIELD_AT(self, void *, 0x4);
        if (p != c) {
            FIELD_AT(self, void *, 0x4) = FIELD_AT(c, void *, 0x4);
        }
    }
}

struct Node_80075620 {
    Node_80075620 *next;
    Node_80075620 *prev;
};

struct List_80075620 {
    Node_80075620 *head;
    Node_80075620 *cur;
    bool IsEmpty() { return head == 0; }
    bool IsLast() { return IsEmpty() ? false : head->prev == cur; }
};

EXTERN_C void func_80075620(List_80075620 *self)
{
    if (!self->IsEmpty()) {
        if (!self->IsLast()) {
            self->cur = self->cur->next;
        }
    }
}

EXTERN_C void func_80075674(void *self)
{
    void *p = FIELD_AT(self, void *, 0x0);
    if (p != 0) {
        FIELD_AT(self, void *, 0x4) = FIELD_AT(p, void *, 0x4);
    }
}

EXTERN_C void func_80075698(void *self)
{
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
}

EXTERN_C int func_800756A4(void *self)
{
    void *p = FIELD_AT(self, void *, 0x0);
    if (p == 0) {
        return 0;
    }
    return FIELD_AT(p, int, 0x4) == FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800756D4(void *self)
{
    return FIELD_AT(self, int, 0x0) == FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800756EC(void *self)
{
    return FIELD_AT(self, int, 0x0) == 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800166A8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800166B8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_800166C8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_800166F0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016708);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016740);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016758);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800167C8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800167E0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800167F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800756F8);

EXTERN_C char D_800167F8[];

EXTERN_C void *func_8007570C(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800167F8;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, int, 0x18) = 0;
    FIELD_AT(self, int, 0x1C) = 0;
    FIELD_AT(self, int, 0x20) = 1;
    return self;
}

struct Obj_80075744 {
    void *vtable;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

EXTERN_C Obj_80075744 *func_80075744(Obj_80075744 *self, int b, int c, int d, int e)
{
    self->vtable = D_80010178;
    self->unk4 = 0;
    self->vtable = D_800167F8;
    self->unk8 = b;
    self->unkC = c;
    self->unk10 = 0;
    self->unk14 = d;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = e;
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80075788);

EXTERN_C void func_8007589C(void *self);

EXTERN_C void func_80075828(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_800167F8;
    if (FIELD_AT(self, int, 0x10) != 0 && FIELD_AT(self, void *, 0xC) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0xC));
    }
    func_8007589C(self);
    func_8001A610(self, flags);
}

EXTERN_C void func_80075894(void *self, int b)
{
    FIELD_AT(self, int, 0x18) = b;
}

EXTERN_C void func_8007589C(void *self)
{
    char *p = FIELD_AT(self, char *, 0x18);
    if (p != 0) {
        ((VObj0 *)(p + 0x8))->v00(3);
        FIELD_AT(self, int, 0x18) = 0;
        FIELD_AT(self, int, 0x1C) = 0;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800758F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80075A40);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80075B4C);

EXTERN_C void func_80075DD8(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 5;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 6;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_80075E50(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 5;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 4;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80075EC8);

EXTERN_C void func_80075EC8(void *self, int b);

EXTERN_C void func_80075FB4(void *self)
{
    func_80075EC8(self, 1);
}

EXTERN_C void func_8003546C(void *a, void *b);
EXTERN_C void func_8003714C(void *a);

EXTERN_C void func_80075FD4(void *self)
{
    FIELD_AT(self, int, 0x13C) = 3;
    if (FIELD_AT(self, int, 0x1BC) == 0) {
        func_8003546C(self ? (char *)self + 0xF8 : 0, self ? (char *)self + 0x134 : 0);
    }
    func_8003714C(self ? (char *)self + 0xF8 : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80076038);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80076370);

EXTERN_C int func_8007669C(void *self, int b, int c)
{
    if (FIELD_AT(self, int, 0x13C) != 0) {
        return 0;
    }
    FIELD_AT(self, int, 0x140) = b;
    FIELD_AT(self, int, 0x144) = c;
    func_80075EC8(self, 0);
    return 1;
}

EXTERN_C void func_80076370(void *self);

EXTERN_C void func_800766D8(void *self)
{
    func_80076370(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800766F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80076848);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007698C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80076AEC);

EXTERN_C int func_80076BE8(void *self)
{
    return FIELD_AT(self, int, 0x144);
}

EXTERN_C int func_80076BF4(void *self, int b)
{
    unsigned v = FIELD_AT(self, unsigned, 0x20) + b;
    FIELD_AT(self, unsigned, 0x20) = v;
    if (FIELD_AT(self, unsigned, 0x1C) < v) {
        FIELD_AT(self, unsigned, 0x20) = FIELD_AT(self, unsigned, 0x1C);
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80076C1C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80076CD0);

EXTERN_C char D_80016878[];

EXTERN_C void func_80076D70(void *self, int flags)
{
    void *p;
    FIELD_AT(self, void *, 0x8) = D_80016878;
    p = FIELD_AT(self, void *, 0x10);
    if (p != 0) {
        operator delete(p);
    }
    func_80074E44(self, flags);
}

EXTERN_C char D_80016868[];
EXTERN_C void *func_80074F58(void *self);

EXTERN_C void *func_80076DC4(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_80016868;
    return self;
}

EXTERN_C void func_80076E60(void *self);

static inline int empty_80076DF8(void *self)
{
    return FIELD_AT(self, int, 0x0) == 0;
}

EXTERN_C void func_80076DF8(void *self, int flags)
{
    FIELD_AT(self, void *, 0xC) = D_80016868;
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
    while (!empty_80076DF8(self)) {
        func_80076E60(self);
    }
    func_80074F78(self, flags);
}

EXTERN_C void *func_800752B8(void *self);

EXTERN_C void func_80076E60(void *self)
{
    VObj<0x8> *p = (VObj<0x8> *)func_800752B8(self);
    if (p != 0) {
        p->v00(3);
    }
}

EXTERN_C void *func_800785DC(void *self);
EXTERN_C void *func_80076DC4(void *self);

EXTERN_C void *func_80076EA8(void *self)
{
    func_800785DC(self);
    func_800785DC((char *)self + 0x10);
    func_800785DC((char *)self + 0x24);
    func_80076DC4((char *)self + 0x34);
    FIELD_AT(self, int, 0x20) = 0;
    FIELD_AT(self, int, 0x44) = 0;
    FIELD_AT(self, int, 0x48) = 0;
    FIELD_AT(self, int, 0x4C) = 0;
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80076EF8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80076FD8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800770B4);

EXTERN_C int func_800771D4(void *self)
{
    return FIELD_AT(self, int, 0x20) != 0 || FIELD_AT(self, int, 0x24) != 0 || FIELD_AT(self, int, 0x10) != 0;
}

EXTERN_C void func_80077210(void *self, void *b)
{
    FIELD_AT(b, int, 0x1C) = 2;
    func_8007505C(self, b);
}

EXTERN_C int func_80075448(void *self, void *b);

EXTERN_C int func_80077234(void *self, void *b)
{
    return func_80075448(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80077254);

EXTERN_C void func_80078564(void *self);

EXTERN_C void *func_80077334(void *self, void *b)
{
    void *p = (void *)func_80075448((char *)self + 0x10, b);
    if (p == 0) {
        p = (void *)func_80075448((char *)self + 0x24, b);
    }
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 2;
        func_80078564(p);
        func_8007505C(self, p);
    }
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800773B0);

EXTERN_C void *func_800773B0(void *self);

EXTERN_C void func_80077444(void *self)
{
    void *p = func_800773B0(self);
    if (p != 0) {
        func_80077234(self, p);
    }
}

EXTERN_C void *func_800774D0(void *self, int b);
EXTERN_C void *func_80077478(void *self);

EXTERN_C void *func_80077478(void *self)
{
    void *p;
    if (FIELD_AT(self, void *, 0x20) != 0) {
        func_800774D0(self, 0);
    }
    p = func_800751AC((char *)self + 0x10);
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 4;
        FIELD_AT(self, void *, 0x20) = p;
    }
    return p;
}

EXTERN_C void *func_800774D0(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x20);
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 3;
        func_8007505C((char *)self + 0x10, p);
        FIELD_AT(self, void *, 0x20) = 0;
        if (b != 0) {
            func_80077478(self);
        }
    }
    return p;
}

EXTERN_C void *func_80077538(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x20);
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 5;
        func_8007505C((char *)self + 0x24, p);
        FIELD_AT(self, void *, 0x20) = 0;
        if (b != 0) {
            func_80077478(self);
        }
    }
    return p;
}

EXTERN_C void *func_800775A0(void *self, void *b)
{
    void *p = (void *)func_80075448((char *)self + 0x24, b);
    void *r = p;
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 3;
        func_8007505C((char *)self + 0x10, p);
    }
    return r;
}

EXTERN_C void *func_800775F0(void *self)
{
    void *p = func_800751AC((char *)self + 0x24);
    void *r = p;
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 3;
        func_8007505C((char *)self + 0x10, p);
    }
    return r;
}

EXTERN_C void func_80077640(void *self)
{
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
}

EXTERN_C void *func_800751AC(void *self);

EXTERN_C void *func_8007764C(void *self)
{
    return func_800751AC(self);
}

EXTERN_C void func_8007505C(void *self, void *node);

EXTERN_C void func_8007766C(void *self, void *node)
{
    func_8007505C(self, node);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007768C);

EXTERN_C int func_800776D8(void *self)
{
    int old = FIELD_AT(self, int, 0x10);
    FIELD_AT(self, int, 0x10) = 0;
    return old;
}

EXTERN_C int func_800776E4(void *self)
{
    return FIELD_AT(self, int, 0x10);
}

EXTERN_C int func_800776F0(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C void *func_800776FC(void *self, int b, int c)
{
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016878;
    FIELD_AT(self, int, 0xC) = b;
    FIELD_AT(self, int, 0x10) = c;
    return self;
}

EXTERN_C void *func_80077750(void *self)
{
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016878;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, int, 0x10) = 0;
    return self;
}

EXTERN_C char D_80016BD0[];

EXTERN_C void *func_8007778C(void *self)
{
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016BD0;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, int, 0x14) = 0;
    FIELD_AT(self, int, 0x18) = 0;
    FIELD_AT(self, int, 0x1C) = 0;
    FIELD_AT(self, int, 0x20) = 0;
    FIELD_AT(self, int, 0x24) = 0;
    FIELD_AT(self, int, 0x28) = 0;
    FIELD_AT(self, int, 0x2C) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, int, 0x3C) = 0;
    return self;
}

EXTERN_C void func_800A0D0C(void *p);

EXTERN_C void func_800777E8(void *self, int b)
{
    void *p;
    FIELD_AT(self, void *, 0x8) = D_80016BD0;
    p = FIELD_AT(self, void *, 0xC);
    if (p != 0) {
        func_800A0D0C(p);
    }
    p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        operator delete(p);
    }
    func_80074E44(self, b);
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016820);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016830);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016868);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016878);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80077854);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80077A44);

EXTERN_C int func_80077BF8(void *self, unsigned char *p)
{
    int v = *p++;
    v += *p++ << 8;
    v += *p << 16;
    return v + (p[1] << 24);
}

EXTERN_C int func_80077C2C(void *self, unsigned char *p)
{
    return p[0] | (p[1] << 8);
}

EXTERN_C void func_80077C40(void *self, unsigned char *p, int n, unsigned v)
{
    int i;
    for (i = 0; i < n; i++) {
        *p++ = v;
        v >>= 8;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80077C68);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80077EA8);

EXTERN_C void func_80078520(void *self, void *p)
{
    void *old = FIELD_AT(self, void *, 0x3C);
    if (old != 0) {
        __builtin_delete(old);
    }
    FIELD_AT(self, void *, 0x3C) = p;
}

EXTERN_C void func_80078564(void *self)
{
    if (FIELD_AT(self, void *, 0x3C) != 0) {
        operator delete(FIELD_AT(self, void *, 0x3C));
        FIELD_AT(self, void *, 0x3C) = 0;
    }
}

EXTERN_C int func_800785A0(void)
{
    return 0;
}

EXTERN_C int func_80077C68(void *self);
EXTERN_C int func_80077EA8(void *self);

EXTERN_C int func_800785A8(void *self)
{
    if (func_80077C68(self) < 0) {
        return -1;
    }
    return func_80077EA8(self);
}

EXTERN_C char D_80016BC0[];

EXTERN_C void *func_800785DC(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_80016BC0;
    return self;
}

EXTERN_C void func_800786A0(void *self);
EXTERN_C void func_80074F78(void *self, int b);

EXTERN_C void func_80078610(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_80016BC0;
    func_800786A0(self);
    func_80074F78(self, b);
}

EXTERN_C void func_80078658(void *self)
{
    VObj<0x8> *p = (VObj<0x8> *)func_800752B8(self);
    if (p != 0) {
        p->v00(3);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800786A0);

EXTERN_C void func_800786EC(void)
{
}

EXTERN_C void func_800786F4(void)
{
}

EXTERN_C void func_800786FC(void *self)
{
    FIELD_AT(self, int, 0x1C) = 5;
}

EXTERN_C void func_80078708(void *self)
{
    FIELD_AT(self, int, 0x1C) = 4;
}

EXTERN_C void func_80078714(void *self)
{
    FIELD_AT(self, int, 0x1C) = 3;
}

EXTERN_C void func_80078720(void *self)
{
    FIELD_AT(self, int, 0x1C) = 2;
}

EXTERN_C int func_8007872C(void *self)
{
    return FIELD_AT(self, int, 0x1C) == 1;
}

EXTERN_C void func_80078740(void *self)
{
    FIELD_AT(self, int, 0x1C) = 1;
}

EXTERN_C void func_8007874C(void *self)
{
    FIELD_AT(self, int *, 0x14) = FIELD_AT(self, int *, 0x28) + FIELD_AT(self, int, 0x2C);
    FIELD_AT(self, int, 0x10) = FIELD_AT(self, int, 0x20);
}

EXTERN_C int func_8007876C(void *self, int i)
{
    return FIELD_AT(self, int *, 0x14)[i];
}

EXTERN_C int func_80078784(void *self)
{
    return *FIELD_AT(self, int *, 0x14)++;
}

EXTERN_C void func_8007879C(void *self, int value)
{
    *--FIELD_AT(self, int *, 0x14) = value;
}

EXTERN_C void *func_800787B4(void)
{
    return D_800AF470.p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800787C4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80078A30);

EXTERN_C int func_80078C38(void)
{
    return 0;
}

EXTERN_C void func_80078C40(void)
{
}

EXTERN_C void func_80078C48(void)
{
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016BC0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80016BD0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80078C50);

EXTERN_C void func_800CB174(void *self, int b, int c);

EXTERN_C int func_8007908C(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x32C);
    if (p != 0) {
        func_800CB174(p, b, 1);
    }
    return 1;
}

EXTERN_C void func_800CB8EC(void *p);
EXTERN_C void func_8001FC78(void *p, int b, int c);

EXTERN_C int func_800790BC(void *self, void *b)
{
    void *p = FIELD_AT(self, void *, 0x32C);
    if (p != 0) {
        func_800CB8EC(p);
    }
    func_8001FC78(b, 0, 0);
    return 1;
}

struct D_80079104 : VPad<0xF8>, virtual VObj0 {
};

EXTERN_C int func_80079104(D_80079104 *self, int b)
{
    int c = b;
    if (c != 0) {
        return self->v02(c);
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80079168);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800792C8);

EXTERN_C void func_8007A1F4(void *self, int b);

EXTERN_C void func_800797FC(void *self)
{
    func_8007A1F4(self, 0);
}

EXTERN_C void func_8007981C(void)
{
}

EXTERN_C void func_8007B538(void *p, int b, int c, int d, int e, int f);

struct Base0_80079824 {
    char pad[0xB8];
};

struct Base1_80079824 {
    int unk0;
};

struct Derived_80079824 : Base0_80079824, Base1_80079824 {
};

EXTERN_C void func_80079824(void *self)
{
    func_8007B538((Base1_80079824 *)FIELD_AT(self, Derived_80079824 *, 0x328), 1, 1, 0, 0, 0);
}

EXTERN_C void func_8007E5B0(void *self);

EXTERN_C void func_80079868(void *self)
{
    char *p;
    func_8007E5B0(FIELD_AT(self, void *, 0x328));
    p = FIELD_AT(self, char *, 0x328);
    func_8007B538(p ? p + 0xB8 : 0, 1, 1, 0, 0, 0);
}

EXTERN_C void func_8007EDAC(void *self, int b, int c);

EXTERN_C void func_800798C0(void)
{
    func_8007EDAC(D_800AF470.p, 0x10000, 1);
}

EXTERN_C void func_800798EC(void *self, int b)
{
    FIELD_AT(self, int, 0x338) = b;
    func_8007A1F4(self, 5);
}

EXTERN_C void func_80079910(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80079918);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80079ABC);

EXTERN_C void func_8007A1F4(void *self, int b);

EXTERN_C void func_80079C18(void *self)
{
    func_8007A1F4(self, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80079C38);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80079D64);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80079E8C);

EXTERN_C int func_80079F48(void *self)
{
    void *p = FIELD_AT(self, void *, 0x32C);
    if (p != 0) {
        return FIELD_AT(p, int, 0x1D0);
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80079F6C);

EXTERN_C void func_80079F6C(void *self, int b);

EXTERN_C void func_8007A13C(void *self)
{
    VObj<0x18> *p = FIELD_AT(self, VObj<0x18> *, 0x358);
    if (p != 0) {
        p->v00(3);
        FIELD_AT(self, void *, 0x358) = 0;
    }
    func_80079F6C(self, 1);
}

EXTERN_C void func_8007A198(void *self)
{
    VObj<0x18> *p = FIELD_AT(self, VObj<0x18> *, 0x35C);
    if (p != 0) {
        p->v00(3);
        FIELD_AT(self, void *, 0x35C) = 0;
    }
    func_80079F6C(self, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007A1F4);

EXTERN_C void func_8007A3CC(void *self)
{
    FIELD_AT(self, int, 0x370) = -1;
    FIELD_AT(self, int, 0x39C)++;
    func_8007A1F4(self, FIELD_AT(self, int, 0x368));
}

EXTERN_C void func_8007A400(void *self, int b)
{
    FIELD_AT(self, int, 0x364) = 2;
    FIELD_AT(self, int, 0x36C) = b;
}

EXTERN_C void func_8007A410(void *self)
{
    func_8007A1F4(self, FIELD_AT(self, int, 0x3AC));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007A434);

EXTERN_C char D_80017370[];

EXTERN_C void *func_8007A960(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_80017370;
    return self;
}

EXTERN_C void func_8007AF04(void *self);

EXTERN_C void func_8007A994(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_80017370;
    func_8007AF04(self);
    func_80074F78(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007A9DC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007AA9C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007AB78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007AC38);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007AD14);

EXTERN_C void *func_8007A9DC(void *self);

EXTERN_C int func_8007ADCC(void *self)
{
    VObj<8> *p = (VObj<8> *)func_8007A9DC(self);
    if (p == 0) {
        return 0;
    }
    func_80075448(self, p);
    p->v00(3);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007AE34);

EXTERN_C void func_8007AF04(void *self)
{
    VObj<8> *p;
    while ((p = (VObj<8> *)func_800751AC(self)) != 0) {
        p->v00(3);
    }
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_80017010);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_80017030);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_80017048);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_8001705C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017068);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017070);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_80017078);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_80017090);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_800170A8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", jtbl_800170C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800170F0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017140);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017160);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017178);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017190);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800171B0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800171C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800171D0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800171E0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017210);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017260);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017280);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017298);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800172B0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800172E8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800172F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007AF5C);

struct Set_8007AFD0 {
    int unk0;
    int count;
    int items[3];
};

EXTERN_C void func_8007AFD0(Set_8007AFD0 *self, int item)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (self->items[i] == 0) {
            self->items[i] = item;
            self->count++;
            return;
        }
    }
}

struct Set_8007B014 {
    int unk0;
    int count;
    int items[3];
};

EXTERN_C int func_8007B014(Set_8007B014 *self, int item)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (self->items[i] == item) {
            self->items[i] = 0;
            self->count--;
            return item;
        }
    }
    return 0;
}

struct Obj_8007B058 {
    int pad;
    int count;
    void *items[1];
};

EXTERN_C void *func_8007B058(Obj_8007B058 *self, int i)
{
    void *p = self->items[i];
    if (p != 0) {
        self->items[i] = 0;
        self->count--;
    }
    return p;
}

EXTERN_C void func_800BFABC(void *self, void *b);

EXTERN_C void func_8007B08C(void *self)
{
    void *p = FIELD_AT(self, void *, 0x8);
    if (p != 0) {
        func_800BFABC(FIELD_AT(D_800AF470.p, void *, 0x380), p);
    }
}

EXTERN_C void func_80019D40(List *l);

EXTERN_C void func_8007B0C8(void *self)
{
    char *h = FIELD_AT(D_800AF470.p, char *, 0x380) + 0x610;
    func_80019D40(h ? FIELD_AT(h, List *, 0x0) : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007B108);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007B1FC);

EXTERN_C void func_8007B2B0(void *self)
{
    FIELD_AT(self, int, 0x14) = 0;
    D_800AFA64[0] = 0;
    D_800AFA64[1] = 0;
    D_800AFA64[2] = 0;
    FIELD_AT(self, int, 0x18) = 0;
    D_800AFA58[0] = 0;
    D_800AFA58[1] = 0;
    D_800AFA58[2] = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007B2E4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007B36C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007B404);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007B538);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007B5F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007B738);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007BB48);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007BC3C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007BCF0);

EXTERN_C void func_8007BDAC(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007BDB4);

struct Global_800B4C18 {
    void *p;
    int pad[2];
};
EXTERN_C Global_800B4C18 D_800B4C18;
EXTERN_C void *func_800758F8(void *self, int b, void *c, void *d);
EXTERN_C void func_8001E848(void *self, void *b);

EXTERN_C void func_8007BE44(void *self)
{
    void *o = operator new(0x1C8);
    char *h = (char *)D_800A4578.p;
    void *r = func_800758F8(o, 1, h ? h + 0x50 : 0, self);
    void *g = D_800B4C18.p;
    FIELD_AT(self, void *, 0x40) = r;
    func_8001E848(g, r);
}

EXTERN_C void func_800766F8(void *self, int b, int c, int d, int e);

EXTERN_C void func_8007BEA8(void *self, int b, int c, int d, int e)
{
    if (FIELD_AT(self, void *, 0x40) != 0) {
        func_800766F8(FIELD_AT(self, void *, 0x40), b, c, d, e);
    }
}

EXTERN_C void func_80076848(void *self, int b);

EXTERN_C void func_8007BEE8(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x40);
    if (p != 0) {
        func_80076848(p, b);
    }
}

EXTERN_C void func_8007698C(void *self, int b, int c, int d);

EXTERN_C void func_8007BF18(void *self, int b, int c)
{
    void *p = FIELD_AT(self, void *, 0x40);
    if (p != 0) {
        func_8007698C(p, b, c, 0);
    }
}

EXTERN_C int func_8007669C(void *self, int b, int c);

EXTERN_C void func_8007BF48(void *self, int b, int c, int d)
{
    if (FIELD_AT(self, void *, 0x40) != 0) {
        FIELD_AT(self, int, 0x30) = b;
        func_8007669C(FIELD_AT(self, void *, 0x40), c, d);
    }
}

EXTERN_C void func_800766D8(void *self);

EXTERN_C void func_8007BF84(void *self)
{
    func_800766D8(FIELD_AT(self, void *, 0x40));
}

EXTERN_C void func_80042430(void *a, void *b, int c, int d);
EXTERN_C void func_8007C070(void *self, int b);

struct Obj_8007BFA8 {
    int pad[2];
    void *items[3];
};

EXTERN_C void func_8007BFA8(Obj_8007BFA8 *self, int b, int c, int d)
{
    void *it = self->items[d];
    if (FIELD_AT(it, int, 0x1B8) == 0) {
        func_80042430(it, it, b, 1);
    } else {
        func_8007C070(self, d);
    }
}

EXTERN_C void func_800CF080(void *a, void *b, int c);

EXTERN_C void func_8007C008(void *self, int b)
{
    void *it = (void *)D_800AFA58[b];
    if (FIELD_AT(it, int, 0x1B8) == 0) {
        func_800CF080(FIELD_AT(D_800AF470.p, void *, 0x32C), it, b);
    } else {
        func_8007C070(self, b + 3);
    }
}

EXTERN_C void func_8007C0A8(void *self, int b);
EXTERN_C void func_8007C3C8(void *self, int b);

EXTERN_C void func_8007C070(void *self, int b)
{
    if (b < 3) {
        func_8007C0A8(self, b);
    } else {
        func_8007C3C8(self, b - 3);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007C0A8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007C3C8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007C55C);

EXTERN_C char D_800172E8[];
EXTERN_C char D_800172B0[];
EXTERN_C char D_800172F8[];
EXTERN_C void func_8007A994(void *self, int b);
EXTERN_C void func_8006F0B0(void *self, int flags);

EXTERN_C void func_8007C640(void *self, int flags)
{
    FIELD_AT(self, void *, 0xB4) = D_800172E8;
    FIELD_AT(self, void *, 0xB8) = D_800172B0;
    FIELD_AT(self, void *, 0xA4) = D_800172F8;
    func_8007A994((char *)self + 0xA8, 0);
    func_8006F0B0(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007C6A8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007C7B0);

EXTERN_C void func_8007DEE8(void *self, int b);

EXTERN_C void func_8007C9A4(void *self)
{
    func_8007DEE8(self, 3);
}

EXTERN_C void func_8007DEE8(void *self, int b);

EXTERN_C void func_8007C9C4(void *self)
{
    func_8007DEE8(self, 2);
}

struct Global_800B4D40 {
    void *p;
    int pad[2];
};
EXTERN_C Global_800B4D40 D_800B4D40;
EXTERN_C void func_8007A400(void *self, int b);
EXTERN_C void func_800518A8(void *a, int b, int c, int d);

EXTERN_C void func_8007C9E4(void *self, int b, int c)
{
    func_8007A400(D_800AF470.p, 0);
    func_800518A8(D_800B4D40.p, FIELD_AT(self, int, 0x10C), b, c);
}

EXTERN_C void func_800CEE18(void *a);
EXTERN_C void func_800CEFE8(void *a);

EXTERN_C void func_8007CA44(void *self)
{
    char *p = self ? (char *)self + 0xB8 : 0;
    if (FIELD_AT(p, int, 0x2C) == 0) {
        func_800CEE18(FIELD_AT(D_800AF470.p, void *, 0x32C));
    } else {
        func_800CEFE8(FIELD_AT(D_800AF470.p, void *, 0x32C));
    }
}

EXTERN_C int func_8007CAA8(void *self, int b)
{
    int old = FIELD_AT(self, int, 0x11C);
    FIELD_AT(self, int, 0x11C) = b;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007CAB4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007CB64);

EXTERN_C void func_8007B0C8(void *p);
EXTERN_C void func_8007BB48(void *p, int b, int c);

struct Base0_8007CC14 {
    char pad[0xB8];
};

struct Base1_8007CC14 {
    int unk0;
};

struct Derived_8007CC14 : Base0_8007CC14, Base1_8007CC14 {
};

EXTERN_C void func_8007CC14(Derived_8007CC14 *self)
{
    func_8007B0C8((Base1_8007CC14 *)self);
    func_8007BB48((Base1_8007CC14 *)self, 1, 1);
}

EXTERN_C int func_8007CAA8(void *self, int b);

EXTERN_C void func_8007CC60(void *self, int b, int c, int d)
{
    func_8007CAA8(self, 2);
    if (c <= 0) {
        c = -1;
    }
    FIELD_AT(self, int, 0x168) = c;
    FIELD_AT(self, int, 0x16C) = d;
}

EXTERN_C void func_8007CC60(void *self, int b, int c, int d);

EXTERN_C void func_8007CCB4(void *self)
{
    func_8007CC60(self, 0, FIELD_AT(self, int, 0x198), FIELD_AT(self, int, 0x19C));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007CCDC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007CE64);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007D024);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007D24C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007D498);

struct Blk_8007D6D0 {
    int v[4];
};
EXTERN_C void func_8006FAC0(void *self, void *a, void *b, void *c, void *d, void *e, void *f, Blk_8007D6D0 g, int h);

EXTERN_C void func_8007D6D0(void *self)
{
    func_8006FAC0(self, (char *)self + 0x168, (char *)self + 0x16C, (char *)self + 0x170, (char *)self + 0x174,
                  (char *)self + 0x178, (char *)self + 0x17C, FIELD_AT(self, Blk_8007D6D0, 0x154), FIELD_AT(self, int, 0x164));
    FIELD_AT(self, int, 0x1AC) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007D744);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007D824);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007D994);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007DB04);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007DC00);

EXTERN_C void func_80084B78(void *self, int b);

EXTERN_C void func_8007DDCC(char *p)
{
    char *q = 0;
    if (p != 0) {
        q = p + 0xB8;
    }
    func_80084B78(FIELD_AT(q, void *, 0x8), 1);
}

EXTERN_C void func_8007FE1C(void *self, int b);
EXTERN_C void func_800DE97C(void *self, int b);
EXTERN_C void func_8007DE74(void *self, int b);

EXTERN_C void func_8007DDFC(void *self, int b)
{
    func_8007FE1C(D_800AF470.p, 0);
    switch (FIELD_AT(self, int, 0x11C)) {
    case 1:
        func_800DE97C(self, b);
        break;
    case 2:
        func_8007DE74(self, b);
        break;
    case 3:
        break;
    }
}

EXTERN_C void func_80084674(void *self);

struct Base0_8007DE74 {
    char pad[0xB8];
};

struct Base1_8007DE74 {
    int unk0;
    int unk4;
    void *unk8;
    void *unkC;
    void *unk10;
};

struct Derived_8007DE74 : Base0_8007DE74, Base1_8007DE74 {
};

EXTERN_C void func_8007DE74(void *self, int b)
{
    Derived_8007DE74 *d = (Derived_8007DE74 *)self;
    func_80084674(((Base1_8007DE74 *)d)->unk8);
    func_80084674(((Base1_8007DE74 *)d)->unkC);
    func_80084674(((Base1_8007DE74 *)d)->unk10);
    func_8007DEE8(self, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007DEE8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007E214);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007E30C);

EXTERN_C void func_8007E414(void *self)
{
    void *g = D_800AF470.p;
    FIELD_AT(g, int, 0x3A4) = 0;
    switch (FIELD_AT(self, int, 0x11C)) {
    case 1:
        func_8007EDAC(g, 0, 0xF);
        break;
    case 2:
        func_8007DEE8(self, 0xA);
        break;
    case 3:
        break;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007E47C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007E5B0);

struct Slot_8007E658 {
    void *p;
    int pad;
};

struct Obj_8007E658 {
    char pad[0x1C4];
    Slot_8007E658 slots[4];
};

EXTERN_C int func_8007E658(Obj_8007E658 *self)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (self->slots[i].p == 0) {
            break;
        }
    }
    return i;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007E684);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007E8C0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007EAC8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007EDAC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007EF90);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007F0A8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007F138);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007F434);

EXTERN_C void func_8007D994(void *p);

EXTERN_C void func_8007F4F4(void *self)
{
    if (FIELD_AT(self, int, 0x378) == 1 && FIELD_AT(self, int, 0x370) == 1) {
        func_8007D994(FIELD_AT(self, void *, 0x328));
    }
}

EXTERN_C int func_8006F52C(void *self, int *a, int *b);

EXTERN_C int func_8007F538(void *self, int *a, int *b)
{
    return func_8006F52C(FIELD_AT(self, void *, 0x328), a, b);
}

EXTERN_C int func_8006F5B4(void *self, int *a, int *b, int *c);

EXTERN_C int func_8007F55C(void *self, int *a, int *b, int *c)
{
    return func_8006F5B4(FIELD_AT(self, void *, 0x328), a, b, c);
}

EXTERN_C int func_8006F570(void *self, int *a, int *b);

EXTERN_C int func_8007F580(void *self, int *a, int *b)
{
    return func_8006F570(FIELD_AT(self, void *, 0x328), a, b);
}

EXTERN_C int func_8007F5A4(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x240);
}

EXTERN_C void func_8007F5B8(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1000;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F62C(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1001;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007DDCC(char *p);

EXTERN_C void func_8007F6A0(void *self)
{
    func_8007DDCC(FIELD_AT(self, char *, 0x328));
}

EXTERN_C void func_8007F6C4(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1002;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F738(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1002;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F7AC(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1002;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F820(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1003;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F894(void)
{
}

EXTERN_C void func_8007A1F4(void *self, int b);

EXTERN_C void func_8007F89C(void *self)
{
    func_8007A1F4(self, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007F8BC);

EXTERN_C void func_8007F940(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x2008;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007F9B4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007FA58);

struct Base0_8007FB30 {
    char pad[0xB8];
};

struct Base1_8007FB30 {
    int unk0;
    int unk4;
    void *unk8;
};

struct Derived_8007FB30 : Base0_8007FB30, Base1_8007FB30 {
};

EXTERN_C void func_8007FB30(void *self, int b)
{
    Base1_8007FB30 *p = FIELD_AT(self, Derived_8007FB30 *, 0x328);
    void *q = p->unk8;
    if (q != 0) {
        FIELD_AT(q, short, 0x5CA) = (b + 4) % 8;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007FB78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007FC90);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007FD60);

EXTERN_C void func_8007FE1C(void *self, int b)
{
    FIELD_AT(self, int, 0x548) = b;
}

EXTERN_C void func_8007FE24(void *self, int b, int c, int d)
{
    FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x198) = c;
    FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x19C) = d;
}

EXTERN_C void func_8007FE3C(void *self, int b)
{
    FIELD_AT(self, int, 0x564) = b;
    FIELD_AT(self, int, 0x560) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007FE4C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8007FF58);

EXTERN_C int func_8007FE4C(void *self, int b, int c);

EXTERN_C int func_80080110(void *self, int b)
{
    return func_8007FE4C(self, b, 1);
}

EXTERN_C int func_80080130(void *self, int b)
{
    int r = func_8007FE4C(self, b, 1);
    func_8007FF58(self, b, 1, 1);
    return r;
}

EXTERN_C int func_80080180(void *self, int b)
{
    int r = func_8007FE4C(self, b, 1);
    func_8007FF58(self, b, 1, 0);
    return r;
}

EXTERN_C int func_800801D0(void *self, int b, int c)
{
    int r = func_8007FE4C(self, b, 1);
    func_8007FF58(self, b, 1, c);
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008022C);

EXTERN_C void func_8001A744(void *self, void *p);

EXTERN_C void func_800802E0(void *self, int b)
{
    VObj0 *p = FIELD_AT(self, VObj0 *, 0x4);
    for (;;) {
        if (p == 0) {
            return;
        }
        if (FIELD_AT(p, int, 0xC) == b) {
            break;
        }
        p = FIELD_AT(p, VObj0 *, 0x4);
    }
    func_8001A744(self, p);
    FIELD_AT(p, void *, 0x4) = 0;
    p->v00(3);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80080350);

EXTERN_C char D_800171B0[];

EXTERN_C void *func_800803E8(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171B0;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, int, 0x14) = 0;
    FIELD_AT(self, int, 0x3C) = 0;
    return self;
}

EXTERN_C void func_800DF6F0(void *self);

EXTERN_C void func_80080418(void *self, int flags)
{
    func_800DF6F0(self);
    func_8001A610(self, 2);
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C char D_80017190[];
EXTERN_C void *func_800756F8(void *self);

struct Obj_80080468 {
    void *vtable;
    int unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38;
    int pad[5];
    int unk50, unk54;
};

EXTERN_C Obj_80080468 *func_80080468(Obj_80080468 *self)
{
    func_800756F8(self);
    self->vtable = D_80017190;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk2C = -1;
    self->unk30 = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    return self;
}

EXTERN_C void func_80080828(void *self);

EXTERN_C void func_800804D8(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80017190;
    func_80080828(self);
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C int func_80080528(void)
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80080530);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80080614);

EXTERN_C void func_800806EC(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800806F4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80080828);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800808AC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80080990);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80080A2C);

EXTERN_C void func_800808AC(void *self);
EXTERN_C int func_8008D1F4(int a, int b);
EXTERN_C void func_800806F4(void *self);

EXTERN_C void func_80080AE8(void *self, int b)
{
    if (FIELD_AT(self, int, 0x38) != 0) {
        FIELD_AT(self, int, 0x18) = b;
        FIELD_AT(self, int, 0x14) = 1;
    } else {
        func_800808AC(self);
        FIELD_AT(self, int, 0x4) = b;
        FIELD_AT(self, int, 0x8) = func_8008D1F4(b, 0);
        FIELD_AT(self, int, 0x10) = 0;
        FIELD_AT(self, int, 0xC) = 1;
    }
    func_800806F4(self);
}

EXTERN_C void func_8008ECB4(int a);
EXTERN_C void func_8007EF90(void *self);

EXTERN_C void func_80080B60(void *self, int b)
{
    if (FIELD_AT(self, int, 0x38) != 0) {
        FIELD_AT(self, int, 0x24) = 1;
        FIELD_AT(self, int, 0x28) = b;
    } else {
        void *g;
        FIELD_AT(self, int, 0x1C) = b;
        func_8008ECB4(b);
        g = D_800AF470.p;
        FIELD_AT(self, int, 0x20) = 1;
        func_8007EF90(g);
    }
    func_800806F4(self);
}

EXTERN_C void func_80080BC4(void *self, int b)
{
    if (FIELD_AT(self, int, 0x38) != 0 || FIELD_AT(self, int, 0x10) == 0 || FIELD_AT(self, int, 0x20) == 0) {
        FIELD_AT(self, int, 0x2C) = b;
    } else {
        func_8008EF40((FIELD_AT(FIELD_AT(self, void *, 0x1C), unsigned short, 0x14) << 16) + b);
        FIELD_AT(self, int, 0x2C) = -1;
    }
}

EXTERN_C void func_800852DC(void *self, int b);

EXTERN_C void func_80080C40(void *self, void *b, int c)
{
    func_800852DC(b, c);
}

EXTERN_C void func_8008316C(void *self);

EXTERN_C void func_80080C64(void *self, char *b)
{
    char *q = 0;
    if (b != 0) {
        q = b + 0x2A0;
    }
    func_8008316C(q);
}

EXTERN_C void func_800DFB10(void *p);

EXTERN_C void func_80080C90(void *self)
{
    func_800DFB10((char *)self + 0x4B0);
}

EXTERN_C int func_80080CB0(void *self)
{
    return FIELD_AT(self, int, 0x568);
}

EXTERN_C int func_80080CBC(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_80080CC8(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C int func_80080CE4(void *self)
{
    return FIELD_AT(self, int, 0x328);
}

EXTERN_C void func_80080CF0(void *self, int b)
{
    func_8007DEE8(FIELD_AT(self, void *, 0x328), b);
}

EXTERN_C int func_80080D14(void *self, int i)
{
    return D_800AFA64[i];
}

EXTERN_C int func_80080D30(void *self, int i)
{
    return D_800AFA58[i];
}

struct Arr_80080D4C {
    char pad[0x8];
    int items[1];
};

EXTERN_C int func_80080D4C(void *self, int i)
{
    char *p = FIELD_AT(self, char *, 0x328);
    Arr_80080D4C *q = 0;
    if (p != 0) {
        q = (Arr_80080D4C *)(p + 0xB8);
    }
    return q->items[i];
}

// The 0x328 member points at a class whose second base sits at +0xB8; the
// upcast's null check is what retail compiles.
struct Base0_80080D74 {
    char pad[0xB8];
};

struct Base1_80080D74 {
    int unk0;
    int unk4;
    int unk8;
};

struct Derived_80080D74 : Base0_80080D74, Base1_80080D74 {
};

EXTERN_C int func_80080D74(void *self)
{
    Base1_80080D74 *b = FIELD_AT(self, Derived_80080D74 *, 0x328);
    return b->unk8;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80080D94);

EXTERN_C int func_80080E28(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x150);
}

EXTERN_C int func_80080E3C(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x14C);
}

EXTERN_C void func_80080828(void *self);

EXTERN_C void func_80080E50(void *self)
{
    func_80080828(self);
}

EXTERN_C int func_80080E70(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C int func_80080E7C(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C void *func_80080E88(void *self, int b, int c)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171B0;
    FIELD_AT(self, int, 0x8) = b;
    FIELD_AT(self, int, 0xC) = c;
    return self;
}

EXTERN_C void *func_80080EB4(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171B0;
    return self;
}

EXTERN_C void func_8001A610(void *self, int flags);

EXTERN_C void func_80080ED8(void *self, int flags)
{
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80080EF8);

EXTERN_C char D_800171C0[];

EXTERN_C void *func_80080F88(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171C0;
    return self;
}

EXTERN_C int func_80080FAC(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C int func_80080FB8(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C void *func_80080FC4(void *self, int b, int c)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171C0;
    FIELD_AT(self, int, 0x8) = b;
    FIELD_AT(self, int, 0xC) = c;
    return self;
}

EXTERN_C void *func_80080FF0(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171C0;
    return self;
}

EXTERN_C void func_8001A610(void *self, int flags);

EXTERN_C void func_80081014(void *self, int flags)
{
    func_8001A610(self, flags);
}

EXTERN_C void func_80081034(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x0) = b;
    FIELD_AT(self, int, 0x4) = c;
}

EXTERN_C void *func_80081040(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x0) = b;
    FIELD_AT(self, int, 0x4) = c;
    return self;
}

EXTERN_C void *func_80081050(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    return self;
}

EXTERN_C int func_80081060(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_8008106C(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C char D_800171D0[];

EXTERN_C void *func_80081088(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171D0;
    FIELD_AT(self, int, 0x8) = -1;
    FIELD_AT(self, int, 0xC) = 0;
    return self;
}

struct Cmd_800810B8 {
    unsigned char a, b, c, d;
};

struct Obj_800810B8 {
    char pad[0x3B0];
    Cmd_800810B8 q[0x20];
};

EXTERN_C void func_800810B8(Obj_800810B8 *self, void *o, int c, int d)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 7;
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = 0xFF;
    self->q[0].c = c;
    self->q[0].d = d;
}

struct Cmd_80081114 {
    unsigned char a, b, c, d;
};

struct Obj_80081114 {
    char pad[0x3B0];
    Cmd_80081114 q[0x20];
};

EXTERN_C void func_80081114(Obj_80081114 *self, void *o, void *t, int d, int e)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 6;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    int i;
    if (e) {
        d |= 0x80;
    }
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = d;
    self->q[0].d = 0xFF;
}

struct Cmd_80081190 {
    unsigned char a, b, c, d;
};

struct Obj_80081190 {
    char pad[0x3B0];
    Cmd_80081190 q[0x20];
};

EXTERN_C void func_80081190(Obj_80081190 *self, void *o, void *t, int d)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 5;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    int f = (d != 0) << 7;
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = f;
    self->q[0].d = 0xFF;
}

struct Cmd_80081204 {
    unsigned char a, b, c, d;
};

struct Obj_80081204 {
    char pad[0x3B0];
    Cmd_80081204 q[0x20];
};

EXTERN_C void func_80081204(Obj_80081204 *self, void *o, int c)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 4;
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = 0xFF;
    self->q[0].c = c;
    self->q[0].d = 0xFF;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80081260);

struct Cmd_800812E4 {
    unsigned char a, b, c, d;
};

struct Obj_800812E4 {
    char pad[0x3B0];
    Cmd_800812E4 q[0x20];
};

EXTERN_C void func_800812E4(Obj_800812E4 *self, void *o, void *t)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 1;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = 0xFF;
    self->q[0].d = 0xFF;
}

struct Cmd_80081350 {
    unsigned char a, b, c, d;
};

struct Obj_80081350 {
    char pad[0x3B0];
    Cmd_80081350 q[0x20];
};

EXTERN_C void func_80081350(Obj_80081350 *self, void *o, void *t, int d)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 1;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = d;
    self->q[0].d = 0xFF;
}

struct Cmd_800813BC {
    unsigned char a, b, c, d;
};

struct Obj_800813BC {
    char pad[0x3B0];
    Cmd_800813BC q[0x20];
};

EXTERN_C void func_800813BC(Obj_800813BC *self, int a, int b, int c, int d)
{
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = a;
    self->q[0].b = b;
    self->q[0].c = c;
    self->q[0].d = d;
}

EXTERN_C void *memset(void *dst, int c, unsigned int n);

EXTERN_C void func_8008140C(void *self)
{
    memset((char *)self + 0x3B0, 0xFF, 0x80);
}

EXTERN_C int func_80081434(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_80081440(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C int func_8008145C(void *self)
{
    return FIELD_AT(self, int, 0x384);
}

EXTERN_C int func_80081468(void *self)
{
    return FIELD_AT(self, int, 0x380);
}

EXTERN_C void func_80081474(void *self)
{
    VObj0 *p = FIELD_AT(self, VObj0 *, 0x32C);
    if (p != 0) {
        p->v02(3);
        FIELD_AT(self, void *, 0x32C) = 0;
    }
}

EXTERN_C int func_800814C4(void *self)
{
    return FIELD_AT(self, int, 0x32C);
}

EXTERN_C int func_800814D0(void *self)
{
    return FIELD_AT(self, int, 0x370);
}

EXTERN_C int func_800814DC(void *self)
{
    return FIELD_AT(self, int, 0x378);
}

EXTERN_C void func_800814E8(void)
{
}

EXTERN_C int func_800814F0(void *self)
{
    return FIELD_AT(self, int, 0x150);
}

EXTERN_C int func_800814FC(void *self)
{
    return FIELD_AT(self, int, 0x14C);
}

EXTERN_C int func_80081508(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_80081514(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C int func_80081530(void *self)
{
    return FIELD_AT(self, int, 0x2C);
}

EXTERN_C int func_8008153C(void *self, int i)
{
    return D_800AFA58[i];
}

EXTERN_C int *func_80081558(void)
{
    return D_800AFA58;
}

EXTERN_C int func_80081564(void *self)
{
    return FIELD_AT(self, int, 0x18);
}

EXTERN_C int func_80081570(void *self, int i)
{
    return D_800AFA64[i];
}

EXTERN_C int *func_8008158C(void)
{
    return D_800AFA64;
}

EXTERN_C int func_80081598(void *self)
{
    return FIELD_AT(self, int, 0x14);
}

EXTERN_C int func_800815A4(void *self)
{
    return FIELD_AT(self, int, 0x14) + FIELD_AT(self, int, 0x18);
}

struct Obj_800815B4 {
    char pad[0x8];
    int items[1];
};

EXTERN_C int func_800815B4(Obj_800815B4 *self, int i)
{
    return self->items[i];
}

EXTERN_C int func_800815C8(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C int func_800815D4(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800815E0(void *self, int b)
{
    return (b + 0x7FF) / 0x800;
}

EXTERN_C char D_80017360[];

EXTERN_C void func_800815F8(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80017360;
    func_8001A610(self, flags);
}

struct Obj_80081620 {
    void *vtable;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

EXTERN_C Obj_80081620 *func_80081620(Obj_80081620 *self, int b, int c, int d, int e)
{
    self->vtable = D_80010178;
    self->unk4 = 0;
    self->vtable = D_80017360;
    self->unk8 = b;
    self->unkC = c;
    self->unk10 = d;
    self->unk14 = e;
    return self;
}

EXTERN_C void *func_80081658(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_80017360;
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, int, 0x14) = 0;
    return self;
}

EXTERN_C char D_80017380[];

EXTERN_C void func_8008168C(void *self, int b)
{
    FIELD_AT(self, void *, 0x8) = D_80017380;
    func_80074E44(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800816B4);

EXTERN_C char D_800173C0[];

EXTERN_C void *func_80081748(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_800173C0;
    FIELD_AT(self, int, 0x10) = 0;
    return self;
}

EXTERN_C void func_800817C8(void *self);

EXTERN_C void func_80081780(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_800173C0;
    func_800817C8(self);
    func_80074F78(self, b);
}

EXTERN_C void func_800817C8(void *self)
{
    VObj<8> *p;
    while ((p = (VObj<8> *)func_800751AC(self)) != 0) {
        p->v00(3);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80081820);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80081970);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80081A74);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80081BA4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80081CB8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80081DCC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80081ED0);

EXTERN_C char D_80017390[];
EXTERN_C char D_800173A8[];
struct Global_800AFA88 {
    int v;
    int pad[2];
};
EXTERN_C Global_800AFA88 D_800AFA88;
EXTERN_C void *func_8001E40C(void *self, int b, int c, int d, int e);

struct Obj_80081FF8 {
    void *vtable;
    char pad[0x88];
    void *vt8C;
};

EXTERN_C Obj_80081FF8 *func_80081FF8(Obj_80081FF8 *self, int b, int c)
{
    func_8001E40C(self, b, 2, 0x400, 0);
    self->vt8C = D_80017390;
    self->vtable = D_800173A8;
    D_800AFA88.v = c;
    return self;
}

EXTERN_C void func_80082058(void *self, int flags)
{
    FIELD_AT(self, void *, 0x8C) = D_80017390;
    FIELD_AT(self, void *, 0x0) = D_800173A8;
    func_800817C8(&D_800AFA74);
    func_8001E508(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800820B4);

EXTERN_C void *func_80081748(void *self);

EXTERN_C void func_80082150(void)
{
    func_80081748(&D_800AFA74);
}

EXTERN_C void func_80081DCC(void *self, int b);

EXTERN_C void func_80082174(int b)
{
    func_80081DCC(&D_800AFA74, b);
}

EXTERN_C void func_80081CB8(void *self, int b);

EXTERN_C void func_8008219C(int b)
{
    func_80081CB8(&D_800AFA74, b);
}

EXTERN_C void func_80081BA4(void *self, int b);

EXTERN_C void func_800821C4(int b)
{
    func_80081BA4(&D_800AFA74, b);
}

EXTERN_C void func_80081A74(void *self, int b);

EXTERN_C void func_800821EC(int b)
{
    func_80081A74(&D_800AFA74, b);
}

EXTERN_C void func_80082214(void)
{
    func_800817C8(&D_800AFA74);
}

EXTERN_C void func_80081970(void *self, int b);

EXTERN_C void func_80082238(int b)
{
    func_80081970(&D_800AFA74, b);
}

EXTERN_C void func_80081820(Global_800AFA74 *p, int a, int b, int c, int d, int e);

EXTERN_C void func_80082260(int a, int b, unsigned short c, int d, int e)
{
    func_80081820(&D_800AFA74, a, b, c, d, e);
}

EXTERN_C void *func_800822A4(void)
{
    return D_800AFA70.p;
}

EXTERN_C void func_800817C8(void *self);

EXTERN_C void func_800822B4(void *self)
{
    func_800817C8(self);
}

EXTERN_C int func_800822D4(void *self)
{
    return FIELD_AT(self, int, 0x10);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800822E0);

EXTERN_C int func_80082374(void *self)
{
    return FIELD_AT(self, int, 0x10);
}

EXTERN_C int func_80082380(void *self)
{
    return FIELD_AT(self, int, 0x1C);
}

EXTERN_C int func_8008238C(void *self)
{
    return FIELD_AT(self, int, 0x18);
}

EXTERN_C int func_80082398(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800823A4);


EXTERN_C void func_80082450(void *self, int b)
{
    func_80074E44(self, b);
}

struct Obj_80082470 {
    short items[0x1A];
    int unk34;
    int unk38;
};

EXTERN_C Obj_80082470 *func_80082470(Obj_80082470 *self)
{
    int i;
    short v = -1;

    self->unk34 = 0;
    self->unk38 = 0;
    for (i = 0x19; i >= 0; i--) {
        self->items[i] = v;
    }
    return self;
}

EXTERN_C void func_800824C8(void *self);

EXTERN_C void *func_800824A0(void *self)
{
    func_800824C8(self);
    return self;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017360);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017370);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017380);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017390);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800173A8);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800173C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800173D0);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800173E0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800824C8);

EXTERN_C unsigned short D_800173E0[][10][16];

EXTERN_C void func_800825FC(short *self, int b)
{
    int i;
    FIELD_AT(self, int, 0x38) = b;
    int r = b % 16;
    int q = b / 16;
    if (FIELD_AT(self, int, 0x34) == 1) {
        for (i = 0; i < 16; i++) {
            *self++ = D_800173E0[q][r][i];
        }
    }
}

struct Obj_80082670 {
    short items[0x1A];
    int mode;  /* 0x34 */
};

EXTERN_C void func_80082670(Obj_80082670 *self, int i, int value)
{
    if (self->mode == 2) {
        self->items[i] = value;
    }
}

EXTERN_C char D_80017758[];

EXTERN_C void *func_80082690(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_80017758;
    FIELD_AT(self, char, 0x9) = 0;
    FIELD_AT(self, short, 0xA) = -1;
    return self;
}

struct Obj_800826C0 {
    void *vtable;
    int unk4;
    char unk8;
    char unk9;
    short unkA;
    int unkC, unk10, unk14, unk18, unk1C, unk20;
};

EXTERN_C Obj_800826C0 *func_800826C0(Obj_800826C0 *self, int b, int c, int d, int e, int f, int g)
{
    self->vtable = D_80010178;
    self->unk4 = 0;
    self->vtable = D_80017758;
    self->unk9 = 0;
    self->unkA = -1;
    self->unk8 = b;
    self->unkC = c;
    self->unk10 = d;
    self->unk14 = e;
    self->unk18 = f;
    self->unk1C = g;
    return self;
}

struct Obj_80082714 {
    void *vtable;
    int unk4;
    char unk8;
    char unk9;
    short unkA;
    int unkC, unk10, unk14, unk18, unk1C, unk20;
};

EXTERN_C Obj_80082714 *func_80082714(Obj_80082714 *self, int b, int c, int d, int e, int f, int g)
{
    self->vtable = D_80010178;
    self->unk4 = 0;
    self->vtable = D_80017758;
    self->unk9 = 0;
    self->unkA = -1;
    self->unk8 = b;
    self->unk20 = c;
    self->unkC = d;
    self->unk10 = e;
    self->unk14 = f;
    self->unk18 = g;
    return self;
}

EXTERN_C char D_80017748[];

EXTERN_C void *func_80082768(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_80017748;
    FIELD_AT(self, short, 0x8) = 0x5555;
    FIELD_AT(self, char, 0xA) = 0;
    return self;
}

EXTERN_C void *func_80082798(void *self, int b, int c)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_80017748;
    FIELD_AT(self, short, 0x8) = b;
    FIELD_AT(self, char, 0xA) = c;
    return self;
}

EXTERN_C void func_800827C4(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80017748;
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800827EC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800828E4);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017690);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017748);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017758);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008299C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80082C68);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80082D44);

EXTERN_C void func_80083310(void *self);

EXTERN_C void func_80082E14(void *self, int b)
{
    if (b != 0 || FIELD_AT(self, signed char, 0x8D) == 0) {
        if (FIELD_AT(self, int, 0x80) != 0) {
            FIELD_AT(self, char, 0x8B) = 1;
        } else {
            FIELD_AT(self, char, 0x8B) = 0;
            func_80083310(self);
        }
    }
}

EXTERN_C void func_80082E60(VObj<0x15C> *self)
{
    if (FIELD_AT(self, int, 0x80) != 0) {
        FIELD_AT(self, char, 0x8C) = 1;
    } else {
        FIELD_AT(self, char, 0x8C) = 0;
        self->v17();
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80082EB0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80082F5C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008316C);

EXTERN_C void func_80083F40(void *self, int b);
EXTERN_C void func_80083310(void *self);

EXTERN_C void func_80083268(void *self)
{
    if (FIELD_AT(self, short, 0x44) >= 0) {
        func_80083F40(self, FIELD_AT(self, short, 0x44));
        FIELD_AT(self, short, 0x44) = -2;
    }
    func_80083310(self);
}

EXTERN_C void func_80083310(void *self);

EXTERN_C void func_800832B0(void *self)
{
    FIELD_AT(self, char, 0x8E) = 0;
    func_80083310(self);
}

EXTERN_C void func_80083310(void *self);

EXTERN_C void func_800832D0(void *self)
{
    FIELD_AT(self, char, 0x99) = 0;
    func_80083310(self);
}

EXTERN_C void func_80083310(void *self);

EXTERN_C void func_800832F0(void *self)
{
    func_80083310(self);
}

EXTERN_C int func_800833F8(void *self);

EXTERN_C void func_80083310(void *self)
{
    if (FIELD_AT(self, signed char, 0x8E) == 0 && FIELD_AT(self, signed char, 0x99) == 0) {
        while (func_800833F8(self) == 0) {
        }
    }
}

EXTERN_C void func_80083360(void *self)
{
    FIELD_AT(self, short, 0x90)++;
    if (FIELD_AT(self, short, 0x92) != 0) {
        FIELD_AT(self, short, 0x92)--;
        FIELD_AT(self, short, 0x90)--;
        func_80083310(self);
    }
}

EXTERN_C void func_800833AC(void *self)
{
    FIELD_AT(self, short, 0x90)++;
    if (FIELD_AT(self, short, 0x92) != 0) {
        FIELD_AT(self, short, 0x92)--;
        FIELD_AT(self, short, 0x90)--;
        func_80083310(self);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800833F8);

struct Obj_80083EB4 {
    char pad[0x9A];
    short items[0x20];
};

EXTERN_C void func_80083EB4(Obj_80083EB4 *self)
{
    int i;
    short v = -2;

    for (i = 0x1F; i >= 0; i--) {
        self->items[i] = v;
    }
}

struct Obj_80083ED8 {
    char pad[0x9A];
    short ids[0x20];
};

EXTERN_C int func_80083ED8(Obj_80083ED8 *self, int b)
{
    int i;
    for (i = 0; i < 0x20; i++) {
        if (self->ids[i] == b) {
            return i;
        }
    }
    for (i = 0; i < 0x20; i++) {
        if (self->ids[i] == -2) {
            self->ids[i] = b;
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80083F40);

EXTERN_C int func_80084044(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_80084050(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C int func_8008406C(void *self)
{
    return FIELD_AT(self, signed char, 0xA) != 0;
}

EXTERN_C short func_80084078(void *self)
{
    return FIELD_AT(self, short, 0x8);
}

EXTERN_C short func_80084084(void *self)
{
    return FIELD_AT(self, short, 0xA);
}

struct Obj_80084090 {
    char pad[0xC];
    int items[1];
};

EXTERN_C int func_80084090(Obj_80084090 *self, int i)
{
    return self->items[i];
}

EXTERN_C int func_800840A4(void *self)
{
    return FIELD_AT(self, int, 0x20);
}

EXTERN_C unsigned char func_800840B0(void *self)
{
    return FIELD_AT(self, unsigned char, 0x8);
}

EXTERN_C void func_800840BC(void *self, int b)
{
    FIELD_AT(self, short, 0xA) = b;
}

EXTERN_C int func_800840C4(void *self)
{
    return FIELD_AT(self, signed char, 0x9) != 0;
}

EXTERN_C void func_800840D0(void *self, int b)
{
    FIELD_AT(self, char, 0x9) = b;
}

EXTERN_C void func_8001A610(void *self, int flags);

EXTERN_C void func_800840D8(void *self, int flags)
{
    func_8001A610(self, flags);
}

struct Obj_800840F8 {
    short items[1];
};

EXTERN_C int func_800840F8(Obj_800840F8 *self, int i)
{
    if (i >= 0) {
        i = self->items[i];
    }
    return i;
}

EXTERN_C int func_80084118(void *self)
{
    return FIELD_AT(self, int, 0x38);
}

EXTERN_C int func_80084124(void *self)
{
    return FIELD_AT(self, int, 0x34);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80084130);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80084454);

EXTERN_C void func_80084674(void *self)
{
    FIELD_AT(self, int, 0x4B0) = 3;
    FIELD_AT(self, short, 0x4F2) = 0x4C;
    FIELD_AT(self, char, 0x4C4) = 0;
    FIELD_AT(self, char, 0x4AD) = 0;
    FIELD_AT(self, char, 0x4AE) = 0;
    FIELD_AT(self, char, 0x4BA) = 0;
    FIELD_AT(self, char, 0x4BB) = 0;
    FIELD_AT(self, char, 0x4E0) = 0;
    FIELD_AT(self, char, 0x4E1) = 0;
    FIELD_AT(self, short, 0x4B8) = 0;
    FIELD_AT(self, int, 0x4B4) = 0;
    FIELD_AT(self, short, 0x52A) = 0;
    FIELD_AT(self, char, 0x4F0) = 0;
    FIELD_AT(self, char, 0x4E4) = 0;
    FIELD_AT(self, char, 0x4E5) = 0;
    FIELD_AT(self, char, 0x4E6) = 0;
    FIELD_AT(self, char, 0x516) = 0;
    FIELD_AT(self, char, 0x50E) = 0;
    FIELD_AT(self, char, 0x512) = 0;
    FIELD_AT(self, char, 0x513) = 0;
    FIELD_AT(self, short, 0x500) = 0;
    FIELD_AT(self, short, 0x502) = 0;
    FIELD_AT(self, short, 0x504) = 0;
    FIELD_AT(self, char, 0x506) = 0;
    FIELD_AT(self, short, 0x508) = 0;
    FIELD_AT(self, char, 0x4F1) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800846EC);

EXTERN_C void func_800846EC(void *self, int b);

EXTERN_C void func_8008478C(void *self)
{
    signed char a = FIELD_AT(self, signed char, 0x4BA);
    if (a != FIELD_AT(self, signed char, 0x4BB)) {
        func_800846EC(self, a != 0);
    }
}

EXTERN_C void func_8003D68C(void *a, int b, void *c, int d, int e);

EXTERN_C void func_800847C0(void *self, int b, int c)
{
    if (c != 0 && b != 0) {
        func_8003D68C(FIELD_AT(FIELD_AT(self, void *, 0x1B8), void *, 0x68), 1, self, 0xF, 0);
        FIELD_AT(self, char, 0x4E1) = 0;
    }
    FIELD_AT(self, char, 0x4BA) = b;
    func_800846EC(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80084824);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800849D0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80084AD8);

EXTERN_C void func_8008299C(void *p, int b, int c, int d, int e, int f, int g);
EXTERN_C void func_80082E14(void *self, int b);

EXTERN_C void func_80084B78(void *self, int b)
{
    if (FIELD_AT(self, short, 0x52A) == 2) {
        func_8008299C(self ? (char *)self + 0x2A0 : 0, 0x1C, 0, 0, 0, 0, 0);
        if (b != 0) {
            func_80082E14(self ? (char *)self + 0x2A0 : 0, 0);
        }
    }
    FIELD_AT(self, short, 0x52A) = 0;
}

EXTERN_C void func_80084BF8(void *self)
{
    if (FIELD_AT(self, short, 0x52A) == 2) {
        ((VObj<0x15C> *)((char *)self + 0x2A0))->v07(0, 0);
    }
    FIELD_AT(self, short, 0x52A) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80084C50);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017910);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017914);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017964);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017974);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017994);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_800179AC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017A44);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017ADC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017B94);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017BA4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80084D58);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80084F58);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80085168);

EXTERN_C void func_80042838(void *self, int b);

EXTERN_C void func_800852A0(void *self, int b)
{
    func_800852DC(self, b);
    func_80042838(self, b);
}

EXTERN_C void func_80085168(void *self, int b);
EXTERN_C void func_80084F58(void *self, int b);
EXTERN_C void func_80084D58(void *self, int b);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008533C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800853D8);

EXTERN_C void func_8004377C(void *self, short b);

EXTERN_C void func_80085454(void *self, int b)
{
    func_8004377C(self, b);
}

EXTERN_C void func_80043740(void *self, short b);

EXTERN_C void func_80085478(void *self, int b)
{
    func_80043740(self, b);
}

EXTERN_C void func_800437A4(void *self, int b);
EXTERN_C void func_800437CC(void *self, int b, int c, int d);

EXTERN_C void func_8008549C(void *self, short b, short c, short d)
{
    func_800437A4(self, b);
    func_800437CC(self, c, d, 0);
}

EXTERN_C void func_80039DD8(void *p);

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

EXTERN_C void func_800435AC(void *self);

EXTERN_C void func_80085554(void *self)
{
    FIELD_AT(self, char, 0x4E0) = 1;
    func_800435AC(self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80085578);

EXTERN_C void func_80085614(void *self, short b, int c)
{
    void *p = FIELD_AT(self, void *, 0x1B8);
    if (p != 0) {
        func_8003D68C(FIELD_AT(p, void *, 0x68), c ? 2 : 1, self, b, 0);
        FIELD_AT(self, char, 0x4E1) = 1;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80085670);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80085710);

EXTERN_C void func_800857A0(void)
{
}

EXTERN_C void func_800CDAC8(void *self, int b);

EXTERN_C void func_800857A8(int b)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x32C);
    if (p != 0) {
        func_800CDAC8(p, b);
    }
}

EXTERN_C void func_800CDAE8(void *self, int b);

EXTERN_C void func_800857E4(int b)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x32C);
    if (p != 0) {
        func_800CDAE8(p, b);
    }
}

EXTERN_C void func_800832F0(void *self);
EXTERN_C void func_800CF2D0(void *p, int b);

struct Base0_80085820 {
    char pad[0x2A0];
};

struct Base1_80085820 {
    int unk0;
};

struct Derived_80085820 : Base0_80085820, Base1_80085820 {
};

EXTERN_C void func_80085820(Derived_80085820 *self)
{
    func_800832F0((Base1_80085820 *)self);
    func_800CF2D0(FIELD_AT(D_800AF470.p, void *, 0x32C), FIELD_AT(self, signed char, 0x4BC) - 3);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008586C);

struct S8_80085A08 {
    char v[8];
};

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

struct Pair_80085A60 {
    short a;
    short b;
};

EXTERN_C int func_80085A60(void *self, Pair_80085A60 v)
{
    if (FIELD_AT(self, signed char, 0x4C4) == 0) {
        return 0;
    }
    FIELD_AT(self, short, 0x4C6) = v.a;
    FIELD_AT(self, short, 0x4CA) = v.b;
    return 1;
}

EXTERN_C char D_80017BA4[];

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

struct S4_80085B28 {
    char v[4];
};

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

EXTERN_C char D_80017B94[];

EXTERN_C void *func_80085BA4(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_80017B94;
    return self;
}

EXTERN_C void func_80074F78(void *self, int b);

EXTERN_C void func_80085BD8(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_80017B94;
    func_80074F78(self, b);
}

struct Derived_80085D7C;
EXTERN_C void func_80085D7C(Derived_80085D7C *self);
EXTERN_C void func_80085DC0(void *self);
EXTERN_C void func_80085C60(void *self, int b);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80085C60);

EXTERN_C void func_8008299C(void *p, int b, int c, int d, int e, int f, int g);

struct Base0_80085D7C {
    char pad[0x2A0];
};

struct Base1_80085D7C {
    int unk0;
};

struct Derived_80085D7C : Base0_80085D7C, Base1_80085D7C {
};

EXTERN_C void func_80085D7C(Derived_80085D7C *self)
{
    func_8008299C((Base1_80085D7C *)self, 1, 0x11, 0, 0, 0, 0);
}

struct Base0_80085DC0 {
    char pad[0x2A0];
};

struct Base1_80085DC0 {
    int unk0;
};

struct Derived_80085DC0 : Base0_80085DC0, Base1_80085DC0 {
};

EXTERN_C void func_80085DC0(void *self)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        func_8008299C((Base1_80085DC0 *)(Derived_80085DC0 *)self, 1, 0x14, 0, 0, 0, 0);
    }
}

struct Derived_80085F90;
EXTERN_C void func_80085F90(Derived_80085F90 *self);
EXTERN_C void func_80085FD4(void *self);
EXTERN_C void func_80085E74(void *self, int b);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80085E74);

struct Base0_80085F90 {
    char pad[0x2A0];
};

struct Base1_80085F90 {
    int unk0;
};

struct Derived_80085F90 : Base0_80085F90, Base1_80085F90 {
};

EXTERN_C void func_80085F90(Derived_80085F90 *self)
{
    func_8008299C((Base1_80085F90 *)self, 2, 0x11, 0, 0, 0, 0);
}

struct Base0_80085FD4 {
    char pad[0x2A0];
};

struct Base1_80085FD4 {
    int unk0;
};

struct Derived_80085FD4 : Base0_80085FD4, Base1_80085FD4 {
};

EXTERN_C void func_80085FD4(void *self)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        func_8008299C((Base1_80085FD4 *)(Derived_80085FD4 *)self, 2, 0x14, 0, 0, 0, 0);
    }
}

struct Derived_800861A4;
EXTERN_C void func_800861A4(Derived_800861A4 *self);
EXTERN_C void func_800861E8(void *self);
EXTERN_C void func_80086088(void *self, int b);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086088);

struct Base0_800861A4 {
    char pad[0x2A0];
};

struct Base1_800861A4 {
    int unk0;
};

struct Derived_800861A4 : Base0_800861A4, Base1_800861A4 {
};

EXTERN_C void func_800861A4(Derived_800861A4 *self)
{
    func_8008299C((Base1_800861A4 *)self, 3, 0x11, 0, 0, 0, 0);
}

struct Base0_800861E8 {
    char pad[0x2A0];
};

struct Base1_800861E8 {
    int unk0;
};

struct Derived_800861E8 : Base0_800861E8, Base1_800861E8 {
};

EXTERN_C void func_800861E8(void *self)
{
    if (FIELD_AT(self, signed char, 0x4BD) == 1) {
        func_8008299C((Base1_800861E8 *)(Derived_800861E8 *)self, 3, 0x14, 0, 0, 0, 0);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008623C);

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

struct Pair_80086338 {
    short a;
    short b;
};

EXTERN_C Pair_80086338 *func_80086338(Pair_80086338 *out, void *self)
{
    short a = FIELD_AT(self, short, 0x4C6);
    short b = FIELD_AT(self, short, 0x4CA);
    out->a = a;
    out->b = b;
    return out;
}

struct Pair_80086350 {
    short a;
    short b;
};

EXTERN_C void func_80086350(void *self, Pair_80086350 *out)
{
    short a = FIELD_AT(self, short, 0x4C6);
    short b = FIELD_AT(self, short, 0x4CA);
    Pair_80086350 tmp;
    tmp.a = a;
    tmp.b = b;
    *out = tmp;
}

struct Quad_80086380 {
    short a;
    short b;
    short c;
    short d;
};

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

struct Vec_800863D0 {
    int v[4];
};

EXTERN_C void func_800863D0(void *self)
{
    FIELD_AT(self, Vec_800863D0, 0x190) = FIELD_AT(FIELD_AT(self, void *, 0x1B8), Vec_800863D0, 0x34);
}

EXTERN_C short func_80086400(void *self)
{
    return FIELD_AT(self, short, 0x4BE);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008640C);

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

struct Obj_8008647C {
    char pad[0x4F6];
    short items[1];
};

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800864C0);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086578);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086670);

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

EXTERN_C char D_80017C00[];
EXTERN_C void func_8001AA28(void *self, int b);

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

struct Vec_80086670 {
    short v[5];
};
struct Pair_800867B0 {
    int a;
    int b;
};
struct Snap_800867B0 {
    unsigned short unk0;
    unsigned short unk2;
    int unk4;
    int unk8;
    Pair_800867B0 unkC;
    Vec_80086670 unk14;
    unsigned char unk1E;
};

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008687C);

EXTERN_C Vec_80086670 func_80086670(Vec_80086670 &a, void *b);

EXTERN_C void func_8008691C(void *self)
{
    FIELD_AT(self, Vec_80086670, 0x62) = func_80086670(func_80086670(FIELD_AT(self, Vec_80086670, 0x44), (char *)self + 0x4E), (char *)self + 0x58);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086990);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086A20);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086B70);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086CAC);

struct Obj_80086DB4 {
    char pad0[0x6];
    short unk6[5];
    char pad10[0x6];
    short unk16[5];
    char pad20[0x50];
    signed char unk70[5];
    char pad75[0xD];
    char unk82;
};

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086E14);

EXTERN_C void func_800898F0(void *self);
EXTERN_C void func_8008655C(short *p);
struct Obj_80086DB4;
EXTERN_C void func_80086DB4(Obj_80086DB4 *self);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086EF0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80086F94);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800870E4);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800872B8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800873A8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800874C4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087620);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087764);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087880);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008792C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800879CC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087A58);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087AF4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087B78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087C2C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087CFC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087D98);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087E50);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087EF4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80087FC4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008805C);

EXTERN_C void func_80089178(void *self, int b);
EXTERN_C void func_80087880(void *self, int b);

EXTERN_C void func_80088114(void *self, int b)
{
    func_80089178(self, b);
    ((VObj<0x9C> *)self)->v11(b);
    func_80087880(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008816C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80088280);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80088310);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800883A0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80088794);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008891C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80088C8C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80088DEC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017C00);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80088F34);

struct Hist_80089024 {
    short v[4];
};

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

struct Hist_8008906C {
    short v[4];
};

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

struct Bytes4_800890B4 {
    char c[4];
};

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800890F0);

EXTERN_C void *func_8008672C(char *p);
EXTERN_C void func_800D9218(void *self, int b);

EXTERN_C void func_80089178(void *self, int b)
{
    if (FIELD_AT(func_8008672C((char *)self), short, 0x4E2) == 2) {
        func_800D9218(self, b);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800891C0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800893EC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800894AC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80089658);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008972C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80089804);

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

union Col_800899AC {
    unsigned char c[8];
    int w[2];
};
EXTERN_C unsigned char *func_800898FC(unsigned char *a, signed char *b);

EXTERN_C Col_800899AC *func_800899AC(Col_800899AC *out, Col_800899AC *a, signed char *b)
{
    Col_800899AC t = *a;
    func_800898FC((unsigned char *)&t, b);
    *out = t;
    return out;
}

EXTERN_C unsigned char *func_80089954(unsigned char *a, signed char *b);

EXTERN_C Col_800899AC *func_800899FC(Col_800899AC *out, Col_800899AC *a, signed char *b)
{
    Col_800899AC t = *a;
    func_80089954((unsigned char *)&t, b);
    *out = t;
    return out;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80089A4C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80089AC0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80089B44);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80089BF4);

EXTERN_C int rand(void);

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

EXTERN_C signed char *func_80089DB8(signed char *a, signed char *b);

EXTERN_C Col_800899AC *func_80089E70(Col_800899AC *out, Col_800899AC *a, signed char *b)
{
    Col_800899AC t = *a;
    func_80089DB8((signed char *)&t, b);
    *out = t;
    return out;
}

EXTERN_C signed char *func_80089E14(signed char *a, signed char *b);

EXTERN_C Col_800899AC *func_80089EC0(Col_800899AC *out, Col_800899AC *a, signed char *b)
{
    Col_800899AC t = *a;
    func_80089E14((signed char *)&t, b);
    *out = t;
    return out;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80089F10);

EXTERN_C void func_80023F50(void *self, int b);

struct Base0_80089F84 {
    char pad[0x58];
};

struct Base1_80089F84 {
    int unk0;
};

struct Derived_80089F84 : Base0_80089F84, Base1_80089F84 {
};

EXTERN_C void func_80089F84(void *self)
{
    func_80023F50((Base1_80089F84 *)FIELD_AT(self, Derived_80089F84 *, 0x4), 0);
    operator delete(self);
}

EXTERN_C void func_80089FC8(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80089FD0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008A188);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008A2A0);

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008A5C8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008A770);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008A858);

EXTERN_C void func_800870E4(void *self, int b);

EXTERN_C void func_8008A93C(void *self, int b, int c)
{
    char *q = 0;
    FIELD_AT(self, int, 0x544) = c;
    if (self != 0) {
        q = (char *)self + 0x400;
    }
    func_800870E4(q, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008A96C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008AC28);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017CB4);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017CCC);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017D1C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017D2C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017D4C);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017D64);

INCLUDE_RODATA("asm/main/nonmatchings/main_b", D_80017DFC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008ACC4);

EXTERN_C int func_8008AE38(void *self, void *b)
{
    if (!(FIELD_AT(self, unsigned char, 0x46D) & 2)) {
        FIELD_AT(self, int, 0x54C) += FIELD_AT(b, unsigned short, 0x546);
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008AE68);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008AFE4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008B084);

EXTERN_C int func_8008B130(void *self, int b)
{
    return b * b * 100;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008B150);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008B258);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008B30C);

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

EXTERN_C int func_8008B444(int n);

EXTERN_C char *func_8008B4B4(char *self, char *b)
{
    short d = func_8008B444(b - self);
    return (char *)(d + (int)self);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008B4E8);

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

struct Hdr_8008B5B4 {
    int w[9];
};
struct Pair16_8008B5B4 {
    unsigned short a;
    unsigned short b;
};
struct Pair32_8008B5B4 {
    int a;
    int b;
};
struct Packed_8008B5B4 {
    Hdr_8008B5B4 hdr;
    Pair16_8008B5B4 e[9];
};
struct Unpacked_8008B5B4 {
    Hdr_8008B5B4 hdr;
    Pair32_8008B5B4 e[9];
};

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

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008B6B0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008B888);

EXTERN_C void func_8008B96C(void)
{
    char **pp = &FIELD_AT(&D_800B18FC, char *, 0x1CC);
    int i;

    for (i = 0; i < 0x18; i++, pp++) {
        if (*pp != 0) {
            FIELD_AT(*pp, unsigned short, 0x6) |= 0x1F5;
        }
    }
    D_800B18FC.flags &= ~0x80;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008B9C0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BA68);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BAC4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BB20);

EXTERN_C void func_8008BBB0(char *p, int n)
{
    SoundState *s;

    n &= 0x7FFFFFFC;
    if ((int)p & 3) {
        n -= 4;
        p = (char *)(((int)p + 3) & ~3);
    }
    s = &D_800B18FC;
    FIELD_AT(s, char *, 0x8) = p;
    FIELD_AT(s, char *, 0xC) = p + n;
    FIELD_AT(s, int, 0x10) = n;
    FIELD_AT(p, unsigned short, 0x0) = 0x8000;
    FIELD_AT(p, short, 0x2) = 0;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, char *, 0x8) = p + 0x10;
    FIELD_AT(p, int, 0xC) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BC0C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BD04);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BE08);

struct Blk_8008BE08 {
    int unk0;
    int unk4;
    char *end;
    Blk_8008BE08 *next;
};

EXTERN_C int func_8008BE50(void)
{
    Blk_8008BE08 *b = FIELD_AT(&D_800B18FC, Blk_8008BE08 *, 0x8);
    int max = 0;
    int d;

    while (b->next != 0) {
        d = (char *)b->next - b->end;
        if (max < d) {
            max = d;
        }
        b = b->next;
    }
    d = FIELD_AT(&D_800B18FC, char *, 0xC) - b->end;
    if (max < d) {
        max = d;
    }
    return max & ~3;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BECC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BF78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008BFEC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C060);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C168);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C27C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C3AC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C414);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C448);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C4B8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C4F0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C52C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C6B0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C6F8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C724);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C748);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C76C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C790);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C7B4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C928);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C970);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008C9A8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008CA50);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008CB84);

struct SndVoice_800B1A60 { unsigned char unk0; char pad[0x1B]; };
struct GlobalPtr_800B1A60 { SndVoice_800B1A60 *p; int pad[2]; };
EXTERN_C GlobalPtr_800B1A60 D_800B1A60;

EXTERN_C void func_8008CBE4(void)
{
    SndVoice_800B1A60 *e = D_800B1A60.p;
    int i;

    for (i = 0; i < 8; i++, e++) {
        e->unk0 = 0;
    }
    D_800B18FC.unk168 = 0;
    D_800B18FC.unk25B = 0;
    D_800B18FC.flags &= ~2;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008CC20);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008CC88);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008CD1C);

EXTERN_C void func_8008CD88(int a, int b)
{
    D_800B18FC.unk184 = a;
    D_800B18FC.unk188 = b;
    D_800B18FC.unk170 |= 0x300;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008CDA8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008CE18);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008CFD4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D038);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D08C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D114);

EXTERN_C void *func_8008D1E4(void)
{
    return D_800B1B48.p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D1F4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D450);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D4C0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D5A8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D5E8);

struct SndNode_800B1A58 { int unk0; unsigned short unk4; char pad6[6]; int unkC; char pad10[0x10]; SndNode_800B1A58 *next; };
struct GlobalPtr_800B1A58 { SndNode_800B1A58 *p; int pad[2]; };
EXTERN_C GlobalPtr_800B1A58 D_800B1A58;

EXTERN_C SndNode_800B1A58 *func_8008D6AC(int id)
{
    SndNode_800B1A58 *p;

    for (p = D_800B1A58.p; p != 0; p = p->next) {
        if (p->unkC == id) {
            break;
        }
    }
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D6E8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D808);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D84C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D8F4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D950);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008D97C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008DA00);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008DACC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008DBEC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008DC78);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008DCE4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008DD50);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008DEE4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E024);

EXTERN_C void func_8008E060(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E068);

EXTERN_C void *func_8008E0B0(void *self)
{
    return (char *)self + 0x58;
}

EXTERN_C void func_8008E0B8(void *self, unsigned char **out)
{
    unsigned char *p = FIELD_AT(self, unsigned char *, 0x1C);

    out[0] = p;
    while (*p++ != 0) {
    }
    out[1] = p;
    while (*p++ != 0) {
    }
    out[2] = p;
    while (*p++ != 0) {
    }
    out[3] = p;
}

EXTERN_C void func_8008E104(void)
{
}

EXTERN_C unsigned char func_8008E10C(void *self)
{
    return FIELD_AT(self, unsigned char, 0x2E);
}

EXTERN_C void func_8008E118(void *self, int b)
{
    FIELD_AT(self, char, 0x2D) = b;
}

EXTERN_C void func_8008E120(void *self, int b)
{
    FIELD_AT(self, int, 0xAC) = b;
}

EXTERN_C void func_8008E128(void *self, int b, int c)
{
    FIELD_AT(self, int, 0xB0) = b;
    FIELD_AT(self, char, 0x2F) = c;
}

struct Time_8008E134 {
    char pad0[2];
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
    unsigned char unk6;
    unsigned char unk7;
    char pad8[4];
    unsigned short ticks;
};

EXTERN_C void func_8008E134(unsigned int n, Time_8008E134 *t)
{
    unsigned int s = n / 240;
    unsigned int m = s / 60;

    t->unk7 = 0;
    t->ticks = n % 240;
    t->unk6 = (n % 240) >> 3;
    t->seconds = s % 60;
    t->hours = m / 60;
    t->minutes = m % 60;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E1B4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E210);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E2A0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E308);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E360);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E504);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E590);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E678);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E698);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E70C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E75C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008E994);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008EA9C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008EB40);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008ECB4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008ED44);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008EDE0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008EE24);

EXTERN_C unsigned char func_8008EECC(int a)
{
    SoundState *s = &D_800B18FC;
    int max = FIELD_AT(FIELD_AT(s, char *, 0x154), unsigned char, 0x2A);

    if (a != 0) {
        if (max < a) {
            a = max;
        }
        if (a < 4) {
            a = 4;
        }
        FIELD_AT(s, unsigned char, 0x252) = a;
    }
    return FIELD_AT(&D_800B18FC, unsigned char, 0x252);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008EF18);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008EF40);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008EF64);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008F0CC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008F1DC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008F4B0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008F618);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FA34);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FAB4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FB80);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FC38);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FD04);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FD44);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FD94);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FDE4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FEAC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8008FFF0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009031C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80090550);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80090724);

struct Ent_80090A88 {
    char pad[3];
    unsigned char unk3;
    char pad4[4];
};

EXTERN_C Ent_80090A88 *func_80090A88(Ent_80090A88 *e, int x)
{
    do {
        e++;
    } while (e->unk3 < x);
    return e;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80090AAC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80090CF4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800912DC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091334);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800916A0);

EXTERN_C unsigned char *func_800916F4(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44;
    return p;
}

EXTERN_C unsigned char *func_80091708(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = t->unk48;
    return p;
}

EXTERN_C unsigned char *func_80091720(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = (signed char)*p + t->unk44;
    return p + 1;
}

EXTERN_C unsigned char *func_80091740(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = (signed char)*p + t->unk48;
    return p + 1;
}

EXTERN_C unsigned char *func_80091760(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = *p;
    return p + 1;
}

EXTERN_C unsigned char *func_80091778(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = p[0] + (p[1] << 8);
    return p + 2;
}

EXTERN_C unsigned char *func_80091798(void *drv, SeqTrack *t, unsigned char *p)
{
    int v = p[0];
    v += p[1] << 8;
    v += p[2] << 16;
    t->unk40 = t->unk44 = v;
    return p + 3;
}

EXTERN_C unsigned char *func_800917C4(void *drv, SeqTrack *t, unsigned char *p)
{
    int v = *p;
    t->flags = (t->flags | 0x400) & ~0x300;
    t->unk40 = v;
    return p + 1;
}

EXTERN_C unsigned char *func_800917E4(void *drv, SeqTrack *t, unsigned char *p)
{
    int v = *p;
    t->flags |= 0x100;
    t->unk40 = v;
    return p + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091800);

EXTERN_C unsigned char *func_80091878(void *drv, SeqTrack *t, unsigned char *p)
{
    t->mark = p;
    t->unk44 = 0;
    t->unk48 = 0;
    t->unk3F = t->octave;
    return p;
}

EXTERN_C unsigned char *func_80091894(void *drv, SeqTrack *t, unsigned char *p)
{
    t->octave = *p * 12;
    return p + 1;
}

EXTERN_C unsigned char *func_800918B4(void *drv, SeqTrack *t, unsigned char *p)
{
    t->octave = (t->octave + (signed char)*p * 12) & 0x7F;
    return p + 1;
}

EXTERN_C unsigned char *func_800918E0(void *drv, SeqTrack *t, unsigned char *p)
{
    t->octave += 12;
    return p;
}

EXTERN_C unsigned char *func_800918F8(void *drv, SeqTrack *t, unsigned char *p)
{
    t->octave -= 12;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091910);

struct Loop_80091910 {
    unsigned char count;
    unsigned char unk1;
    unsigned char octave;
    unsigned char octave2;
    unsigned char *start;
    unsigned char *end;
};

EXTERN_C unsigned char *func_80091958(void *drv, SeqTrack *t, unsigned char *p)
{
    Loop_80091910 *e = &((Loop_80091910 *)((char *)t + 0x90))[FIELD_AT(t, unsigned char, 0xE)];

    if (--e->count != 0xFF) {
        e->end = p;
        e->octave2 = t->octave;
        p = e->start;
        t->octave = e->octave;
    } else {
        FIELD_AT(t, unsigned char, 0xE)--;
    }
    return p;
}

EXTERN_C unsigned char *func_800919C4(void *drv, SeqTrack *t, unsigned char *p)
{
    Loop_80091910 *e = &((Loop_80091910 *)((char *)t + 0x90))[FIELD_AT(t, unsigned char, 0xE)];

    if (e->count == 0) {
        p = e->end;
        t->octave = e->octave2;
        FIELD_AT(t, unsigned char, 0xE)--;
    }
    return p;
}

EXTERN_C unsigned char *func_80091A10(void *t, void *drv, unsigned char *p)
{
    int v = *p;

    FIELD_AT(t, int, 0x34) = v << 16;
    FIELD_AT(t, int, 0x44) = (v * 13981 >> 14) * FIELD_AT(t, short, 0x72);
    return p + 1;
}

EXTERN_C unsigned char *func_80091A5C(void *t, void *drv, unsigned char *p)
{
    int v = FIELD_AT(t, int, 0x34) + (*p << 16);

    FIELD_AT(t, int, 0x34) = v;
    FIELD_AT(t, int, 0x44) = ((v >> 16) * 55924 >> 16) * FIELD_AT(t, short, 0x72);
    return p + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091AB4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091B38);

EXTERN_C unsigned char *func_80091B68(void *drv, SeqTrack *t, unsigned char *p)
{
    FIELD_AT(drv, short, 0x5A) = p[0] - 1;
    FIELD_AT(drv, short, 0x5C) = p[1] - 1;
    return p + 2;
}

EXTERN_C unsigned char *func_80091B90(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk4C = *p + (t->unk4C & 0xFF00);
    return p + 1;
}

EXTERN_C unsigned char *func_80091BAC(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk4C = (unsigned char)t->unk4C + (*p << 8);
    return p + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091BC8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091C94);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091D70);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091ED0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80091FB4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009200C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092054);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009209C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800920E4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009212C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092178);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800921C8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092210);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092258);

EXTERN_C unsigned char *func_800922A0(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk50 = *p;
    return p + 1;
}

EXTERN_C unsigned char *func_800922B4(void *drv, SeqTrack *t, unsigned char *p)
{
    t->flags |= 0x800;
    return p;
}

EXTERN_C unsigned char *func_800922CC(void *drv, SeqTrack *t, unsigned char *p)
{
    t->flags &= ~0x800;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800922E4);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009231C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092354);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800923A8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092408);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092440);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092478);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800924D0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092508);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092540);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092584);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800925D0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009261C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092668);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800926B8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092754);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800927C8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092910);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092A98);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092ACC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092B00);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092B3C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092B98);

EXTERN_C unsigned char *func_80092BFC(void *drv, SeqTrack *t, unsigned char *p)
{
    int dur = p[0] + (p[1] << 8);
    int target = p[2];
    int d = (target << 22) - FIELD_AT(t, int, 0x64);

    if (dur != 0 && d != 0) {
        int q = d / dur;
        FIELD_AT(t, unsigned char, 0x85) = target;
        FIELD_AT(t, short, 0x8A) = dur;
        FIELD_AT(t, unsigned short, 0x2) = (FIELD_AT(t, unsigned short, 0x2) | 8) & ~0x100;
        FIELD_AT(t, int, 0x78) = q;
    }
    return p + 3;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092C54);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092CC8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092DE8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092F54);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092F88);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80092FBC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093018);

EXTERN_C unsigned char *func_80093088(void *drv, SeqTrack *t, unsigned char *p)
{
    unsigned short dur = p[0] + (p[1] << 8);
    int target = p[2];
    int d = (target << 16) - FIELD_AT(t, int, 0x60);

    if (dur != 0 && d != 0) {
        int q = d / dur;
        FIELD_AT(t, unsigned char, 0x86) = target;
        FIELD_AT(t, short, 0x8C) = dur;
        FIELD_AT(t, unsigned short, 0x2) |= 0x10;
        FIELD_AT(t, int, 0x7C) = q;
    }
    return p + 3;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800930E0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093154);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009327C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800933E8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009341C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093450);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093524);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093610);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800936A0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800936D8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093710);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093788);

struct Node_80093800 {
    unsigned short flags;
    char pad2[6];
    int unk8;
    char padC[8];
    short unk14;
    char pad16[2];
    short unk18;
    short unk1A;
    short unk1C;
    short unk1E;
    Node_80093800 *next;
};

EXTERN_C void func_80093800(void *drv, Node_80093800 *n)
{
    n->unk8 = 0;
    n->flags &= ~0x60;
    n->unk14 = 1;
    n->unk18 = n->unk1A;
    n->unk1C = n->unk1E;
    if (!(n->flags & 1)) {
        n->flags |= 1;
        n->next = FIELD_AT(drv, Node_80093800 *, 0xA8);
        FIELD_AT(drv, Node_80093800 *, 0xA8) = n;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093858);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800938B4);

EXTERN_C int func_80093928(void *self, int b, int c)
{
    return c + 3;
}

EXTERN_C int func_80093930(void *self, int b, int c)
{
    return c + 2;
}

EXTERN_C unsigned char *func_80093938(void *self, int b, unsigned char *p)
{
    FIELD_AT(self, int, 0x50) = (p[0] * 864000 + p[1] * 14400 + p[2] * 240 + p[3] * 8) << 8;
    return p + 5;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800939A8);

struct Voice_80091FB4 {
    char pad0[0x8];
    unsigned char unk8;
    char pad9[0x23];
    short unk2C;
    short unk2E;
    char pad30[0x20];
    short unk50;
    short unk52;
    char pad54[0x20];
    short unk74;
    short unk76;
    char pad78[0x3E];
    unsigned char unkB6;
    char padB7[3];
    unsigned short flags;
    char padBC[0x1C];
    unsigned char unkD8;
    unsigned char unkD9;
    unsigned char unkDA;
    unsigned char unkDB;
    unsigned char unkDC;
    unsigned char unkDD;
    unsigned char unkDE;
    unsigned char unkDF;
    char padE0[4];
};

EXTERN_C void func_800939F4(void *t, int a, int b)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);

    while (n--) {
        v->unkB6 &= ~a;
        v->flags |= b;
        v++;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093A40);

EXTERN_C void func_80093A80(void *drv, int bits)
{
    char *t = FIELD_AT(drv, char *, 0xC);
    int i = FIELD_AT(drv, unsigned char, 0x2A);

    do {
        if (FIELD_AT(t, short, 0x0) < 0) {
            int n = FIELD_AT(t, unsigned char, 0x8);
            char *v = FIELD_AT(t, char *, 0x24);
            while (n--) {
                FIELD_AT(v, unsigned char, 0xB) |= bits;
                v += 0xE4;
            }
        }
        t += 0x160;
    } while (--i);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093AEC);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093B3C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093BB8);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093C9C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093CE8);

struct Slot_80093D8C {
    short idx;
    char pad2[2];
    short prio;
};

EXTERN_C void func_80093D8C(Slot_80093D8C *s)
{
    int i = s->idx;
    Slot_80093D8C **slot = &(&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC))[i];

    if ((unsigned int)i < 0x18) {
        Slot_80093D8C *cur = *slot;
        if (cur != s && (cur == 0 || cur->prio <= s->prio)) {
            *slot = s;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093DE8);

EXTERN_C void func_80093E80(Slot_80093D8C *s)
{
    int i = s->idx;
    Slot_80093D8C **slot = &(&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC))[i];

    if ((unsigned int)i < 0x18 && *slot == s) {
        SoundState *d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC) - 0x1CC);
        *slot = 0;
        FIELD_AT(d, int, 0x234) |= 1 << i;
        FIELD_AT(d, int, 0x22C) &= ~(1 << i);
    }
}

EXTERN_C void func_80093EE0(Slot_80093D8C *s)
{
    int i = s->idx;
    Slot_80093D8C **slot = &(&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC))[i];

    if ((unsigned int)i < 0x18 && *slot == s) {
        SoundState *d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC) - 0x1CC);
        *slot = 0;
        FIELD_AT(d, int, 0x230) |= 1 << i;
        FIELD_AT(d, int, 0x22C) &= ~(1 << i);
    }
}

EXTERN_C void func_80093F40(Slot_80093D8C *s)
{
    int i = s->idx;

    if ((unsigned int)i < 0x18) {
        SoundState *d = &D_800B18FC;
        if ((&FIELD_AT(d, Slot_80093D8C *, 0x1CC))[i] == s) {
            int m = 1 << i;
            FIELD_AT(d, int, 0x234) |= m;
            FIELD_AT(d, int, 0x22C) &= ~m;
        }
    }
}

EXTERN_C void func_80093F98(Slot_80093D8C *s)
{
    int i = s->idx;

    if ((unsigned int)i < 0x18) {
        SoundState *d = &D_800B18FC;
        if ((&FIELD_AT(d, Slot_80093D8C *, 0x1CC))[i] == s) {
            FIELD_AT(d, int, 0x230) |= 1 << i;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80093FE0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_8009422C);

struct Bytes_800AFFA4 {
    unsigned char v[0xF8];
};
EXTERN_C Bytes_800AFFA4 D_800AFFA4;
struct Shorts_800B009C {
    short v[0x100];
};
EXTERN_C Shorts_800B009C D_800B009C;

EXTERN_C int func_800942E0(unsigned int a)
{
    unsigned int i = (a & 0x7FFF) >> 8;
    int b = D_800AFFA4.v[i];
    int k = (a & 0xFF) + ((b & 0xF) << 8);

    return D_800B009C.v[k] >> (6 - (b >> 4));
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80094330);

EXTERN_C int func_800944E8(unsigned short *flags)
{
    *flags &= ~1;
    return 0;
}

struct Lfo_80094500 {
    unsigned short flags;
    char pad2[6];
    int value;
    int step;
    int depth;
    unsigned short count;
    unsigned short period;
};

EXTERN_C int func_80094500(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        int v = 0;
        l->count = l->period;
        if (l->value == 0) {
            v = l->depth;
        }
        l->value = v;
    }
    return l->value;
}

EXTERN_C int func_80094548(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        int v = l->depth;
        l->count = l->period;
        if (l->flags & 0x40) {
            v = -v;
        }
        l->value = v;
        l->flags ^= 0x40;
    }
    return l->value;
}

EXTERN_C int func_8009459C(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        int v = l->depth;
        l->count = l->period;
        if (l->flags & 0x40) {
            v = -v;
        }
        l->step = v;
        l->flags ^= 0x40;
    }
    return l->value += l->step;
}

EXTERN_C int func_800945FC(Lfo_80094500 *l)
{
    int n = l->count;

    if (--n == 0) {
        unsigned short f = l->flags;
        int v;
        n = l->period;
        if (f & 0x20) {
            n <<= 1;
        }
        v = l->depth;
        l->step = v;
        if (f & 0x40) {
            l->step = -v;
        }
        l->flags = (f | 0x20) ^ 0x40;
    }
    l->count = n;
    return l->value += l->step;
}

struct Timer_80094664 {
    char pad0[0x8];
    int value;
    char padC[0x4];
    int step;
    unsigned short count;
    unsigned short period;
};

EXTERN_C int func_80094664(Timer_80094664 *t)
{
    if (--t->count == 0) {
        t->value = 0;
        t->count = t->period;
    } else {
        t->value += t->step;
    }
    return t->value;
}

struct Rng_800946B0 {
    char pad[0x254];
    int seed;
};

EXTERN_C int func_800946B0(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        Rng_800946B0 *s = (Rng_800946B0 *)&D_800B18FC;
        int r;
        l->count = l->period;
        r = s->seed;
        r ^= r << 17;
        r ^= r >> 15;
        s->seed = r;
        l->value = (l->depth >> 15) * (r & 0x7FFF);
    }
    return l->value;
}

EXTERN_C int func_8009471C(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        Rng_800946B0 *s = (Rng_800946B0 *)&D_800B18FC;
        int r;
        l->count = l->period;
        r = s->seed;
        r ^= r << 17;
        r ^= r >> 15;
        s->seed = r;
        l->value = (l->depth >> 14) * (r & 0x7FFF) - l->depth;
    }
    return l->value;
}

EXTERN_C int func_8009478C(void)
{
    SoundState *s = &D_800B18FC;
    int v = FIELD_AT(s, int, 0x254);
    v ^= v << 17;
    v ^= v >> 15;
    FIELD_AT(s, int, 0x254) = v;
    return v & 0x7FFF;
}

EXTERN_C int func_800947B8(void)
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800947C0);

EXTERN_C unsigned int func_80094800(unsigned int *p)
{
    unsigned int n = (p[2] + 3) >> 2;
    unsigned int s = 0;

    do {
        s += *p++;
    } while (--n != 0);
    return s;
}

EXTERN_C void func_8009482C(int a, int b)
{
    D_800B18FC.unk003 = a;
    D_800B18FC.unk004 = b;
    D_800B18FC.flags |= 8;
}

EXTERN_C void func_8009484C(int a, int b)
{
    D_800B18FC.unk003 = a;
    D_800B18FC.unk004 = b;
    D_800B18FC.flags |= 8;
}

EXTERN_C void func_80094888(void);

EXTERN_C void func_8009486C(void *self)
{
    void *p = D_800B1A68.p;
    FIELD_AT(self, void *, 0x10) = (void *)func_80094888;
    FIELD_AT(self, void *, 0x14) = p;
}

EXTERN_C void func_80094888(void)
{
}

struct Short_800B1B54 { unsigned short v; char pad[0xA]; };
struct Byte_800B1B56 { unsigned char v; char pad[0xB]; };
EXTERN_C Short_800B1B54 D_800B1B54;
EXTERN_C Byte_800B1B56 D_800B1B56;

EXTERN_C void func_80094890(void *p)
{
    if (p != 0) {
        D_800B1B54.v = FIELD_AT(p, unsigned short, 0x14);
    } else {
        D_800B1B54.v = 0;
    }
    D_800B1B56.v = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_800948B4);

EXTERN_C void func_80094908(void)
{
}
