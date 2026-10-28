#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"
#include "game/b2/b2.h"

EXTERN_C int func_8006CBCC(void *self, int id)
{
    switch (id) {
    case 0xC9: {
        int dt = D_800A4534.ticks - FIELD_AT(self, int, 0xC);
        FIELD_AT(self, int, 0xC) = D_800A4534.ticks;
        int rem = FIELD_AT(self, int, 0x14) - dt;
        int rate = 0x400 / FIELD_AT(self, int, 0x10);
        FIELD_AT(self, int, 0x14) = rem;
        if (rem <= 0) {
            dt += rem;
            void *p = FIELD_AT(self, void *, 0x4);
            func_8006B350(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
            return 0;
        }
        void *p = FIELD_AT(self, void *, 0x4);
        func_8006B350(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
        return 1;
    }
    case 0xCA: {
        int dt = D_800A4534.ticks - FIELD_AT(self, int, 0xC);
        FIELD_AT(self, int, 0xC) = D_800A4534.ticks;
        int rem = FIELD_AT(self, int, 0x14) - dt;
        int rate = 0x400 / FIELD_AT(self, int, 0x10);
        FIELD_AT(self, int, 0x14) = rem;
        if (rem <= 0) {
            dt += rem;
            void *p = FIELD_AT(self, void *, 0x4);
            func_8006B390(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
            return 0;
        }
        void *p = FIELD_AT(self, void *, 0x4);
        func_8006B390(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
        return 1;
    }
    }
    return 1;
}

EXTERN_C int func_8006CD98(void *self, int id)
{
    switch (id) {
    case 0xCB: {
        int dt = D_800A4534.ticks - FIELD_AT(self, int, 0xC);
        FIELD_AT(self, int, 0xC) = D_800A4534.ticks;
        int rem = FIELD_AT(self, int, 0x14) - dt;
        short rate = 0x5208 / FIELD_AT(self, int, 0x10);
        FIELD_AT(self, int, 0x14) = rem;
        if (rem <= 0) {
            dt += rem;
            void *p = FIELD_AT(self, void *, 0x4);
            func_8006B2F8(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
            return 0;
        }
        void *p = FIELD_AT(self, void *, 0x4);
        func_8006B2F8(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
        return 1;
    }
    case 0xCC: {
        int dt = D_800A4534.ticks - FIELD_AT(self, int, 0xC);
        FIELD_AT(self, int, 0xC) = D_800A4534.ticks;
        int rem = FIELD_AT(self, int, 0x14) - dt;
        short rate = 0x5208 / FIELD_AT(self, int, 0x10);
        FIELD_AT(self, int, 0x14) = rem;
        if (rem <= 0) {
            dt += rem;
            void *p = FIELD_AT(self, void *, 0x4);
            func_8006B258(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
            return 0;
        }
        void *p = FIELD_AT(self, void *, 0x4);
        func_8006B258(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
        return 1;
    }
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006CF84);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006D290);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006D344);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006D768);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006D964);

EXTERN_C void func_8006DA60(void *self)
{
    FIELD_AT(self, int, 0x60) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006DA6C);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006DF68);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006E234);

EXTERN_C void *func_8006E73C(Obj_8006E73C *self, int a, int b, int c, int e, short f, int g)
{
    char tmp[8];
    self->vt = D_80010178;
    self->f4 = 0;
    self->vt = D_800111BC;
    self->f8 = 0;
    self->fA = e;
    self->vt = D_80015EB8;
    self->f74 = g;
    SetDrawMode((char *)self + 0xC, 0, 0, 0, 0);
    SetDrawMode((char *)self + 0x18, 0, 0, 0, 0);
    FIELD_AT(self, unsigned char, 0x27) = 9;
    FIELD_AT(self, unsigned char, 0x2B) = 0x2C;
    FIELD_AT(self, unsigned char, 0x4F) = 9;
    FIELD_AT(self, unsigned char, 0x53) = 0x2C;
    if ((unsigned short)f < 4) {
        func_80098DC0((char *)self + 0x24, 1);
        func_80098DC0((char *)self + 0x4C, 1);
    } else {
        func_80098DC0((char *)self + 0x24, 0);
        func_80098DC0((char *)self + 0x4C, 0);
    }
    func_8006EACC(self, c, f);
    func_8006EBB0(self, a);
    func_8006EC70(self, b);
    func_8002972C(tmp, 0x80, 0x80, 0x80, 1);
    func_8006EDD8(self, tmp);
    func_8006EE94(self);
    func_800198AC(tmp, 2);
    return self;
}

EXTERN_C void func_8006E8BC(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80015EB8;
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006E8E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006EACC);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006EBB0);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006EC70);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006EDD8);

EXTERN_C void func_8006EE8C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006EE94);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006EF84);

EXTERN_C int func_8006F040(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006F10C);

EXTERN_C void func_8006F154(void *self)
{
    VEnt_8006F154 *vt = FIELD_AT(self, VEnt_8006F154 *, 0xA4);
    D_800AF410.state = 2;
    vt[2].pfn((char *)self + vt[2].delta, FIELD_AT(self, int, 0x98));
}

EXTERN_C void func_8006F194(void *self)
{
    D_800AF410.state = 4;
    FIELD_AT(self, B48_658, 0x64) = FIELD_AT(self, B48_658, 0x34);
    FIELD_AT(self, B48_658, 0x34) = FIELD_AT(self, B48_658, 0x4);
    ((VObj<0xA4> *)self)->v02(FIELD_AT(self, int, 0x4));
    ((VObj<0xA4> *)self)->v01(FIELD_AT(self, int, 0x9C));
}

EXTERN_C void func_8006F268(void *self)
{
    VEnt_8006F268 *vt = FIELD_AT(self, VEnt_8006F268 *, 0xA4);
    D_800AF410.state = 6;
    vt[2].pfn((char *)self + vt[2].delta, FIELD_AT(self, int, 0xA0));
}

EXTERN_C void func_8006F2A8(void *self)
{
    D_800AF410.state = 3;
    if (D_800AF408.v != 0) {
        D_800AF408.v = 0;
        func_8006F194(self);
    }
}

EXTERN_C void func_8006F2E8(void *self)
{
    D_800AF410.state = 0;
    if (D_800AF40C.v != 0) {
        D_800AF40C.v = 0;
        func_8006F10C(self);
    }
}

EXTERN_C void func_8006F31C(Obj_8006F31C *self)
{
    int *mode = &D_800AF410.state;
    *mode = 5;
    self->f3(self->b);
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006F3DC);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006F5B4);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006F67C);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006F8B4);

EXTERN_C int func_8006FA84(void *self)
{
    if (D_800AF410.state == 5) {
        func_8006F268(self);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006FAC0);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006FCC0);

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

EXTERN_C void func_8006FE6C(Obj_8006FE6C *self, int a, int b, Four_8006FE6C s, int h)
{
    self->a = a;
    self->b = b;
    self->s = s;
    self->h = h;
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_8006FF50);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_80070038);

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

EXTERN_C void func_800702EC(void)
{
    char *s = (char *)D_800AF470.p;
    char *v = FIELD_AT(s, char *, 0x328);
    short *q;
    v = v ? v + 0xB8 : 0;
    q = (short *)(FIELD_AT(FIELD_AT(v, char *, 0x8), char *, 0x1B8) + 0x2C);
    func_80080CC8(s, (short)SquareRoot0(q[0] * q[0] + q[1] * q[1] + q[2] * q[2]));
}

EXTERN_C int func_80070384(void)
{
    char *s = (char *)D_800AF470.p;
    char *v = FIELD_AT(s, char *, 0x328);
    short *q;
    v = v ? v + 0xB8 : 0;
    q = (short *)(FIELD_AT(FIELD_AT(v, char *, 0x8), char *, 0x1B8) + 0x2C);
    return 1 << (func_80080CC8(s, (short)SquareRoot0(q[0] * q[0] + q[1] * q[1] + q[2] * q[2])) % 8);
}

EXTERN_C int func_80070440(void)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    char *h = p ? (char *)p + 0xB8 : 0;
    V_80070440 t = FIELD_AT(FIELD_AT(FIELD_AT(h, void *, 0x8), void *, 0x1B8), V_80070440, 0x34);
    return t.a;
}

EXTERN_C int func_8007049C(void)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    char *h = p ? (char *)p + 0xB8 : 0;
    V_8007049C t = FIELD_AT(FIELD_AT(FIELD_AT(h, void *, 0x8), void *, 0x1B8), V_8007049C, 0x34);
    return t.b;
}

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

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_80015FD0);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_80070568);

EXTERN_C int func_80070DA0(int a, int b, int c, int d, int e, int f, int g)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_8007AD14(p ? (char *)p + 0xA8 : 0, b, c, d, e, f, g);
    return 0;
}

EXTERN_C int func_80070DF8(int a, int b)
{
    char *p = FIELD_AT(D_800AF470.p, char *, 0x328);
    char *q = 0;
    if (p != 0) {
        q = p + 0xA8;
    }
    func_8007ADCC(q, b);
    return 0;
}

EXTERN_C int func_80070E34(void)
{
    func_8007D744(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C int func_80070E60(void *self, int b, int c, int d, int e, int f)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_8006F3DC(p, b, c, d, e, f);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_80070E98);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_80070F30);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_80070FC8);

EXTERN_C int func_80071080(void *self, int b, int c, int d, int e, int f, int g)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_800DE3B8(p, b, c, d, e, f, g);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_800710C0);

INCLUDE_ASM("asm/main/nonmatchings/u_8006CBCC", func_80071148);

EXTERN_C int func_800711D0(void)
{
    func_8007D6D0(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C int func_800711FC(void *self, int b)
{
    func_8007FB30(D_800AF470.p, b);
    return 0;
}

EXTERN_C int func_80071224(void *self)
{
    func_80071398(self, (int)D_80016248, 0, 0x101);
    return 0;
}

EXTERN_C int func_80071250(void)
{
    return 0;
}

EXTERN_C int func_80071258(void)
{
    func_8008022C((char *)D_800AF470.p + 0x4A0);
    return 0;
}

EXTERN_C int func_80071280(void *self, int b)
{
    func_800802E0((char *)D_800AF470.p + 0x4A0, b);
    return 0;
}

EXTERN_C int func_800712A8(void *self, int b, int c)
{
    return func_8007FE4C((char *)D_800AF470.p + 0x498, b, c);
}

EXTERN_C void func_800712D0(void *self, int b, int c, int d)
{
    func_8007FF58((char *)D_800AF470.p + 0x498, b, c, d);
}

EXTERN_C void func_800712F8(void *self, int b)
{
    func_80080110((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_80071320(void *self, int b)
{
    return func_80080130((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_80071348(void *self, int b)
{
    return func_80080180((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_80071370(void *self, int b, int c)
{
    return func_800801D0((char *)D_800AF470.p + 0x498, b, c);
}

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

EXTERN_C int func_800713EC(void)
{
    func_800DF938((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C int func_80071414(void)
{
    func_800DF9A8((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C int func_8007143C(void)
{
    func_800DFB10((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C int func_80071464(void)
{
    func_8007E214(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C int func_80071490(void)
{
    func_8007E30C(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

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

EXTERN_C int func_80071510(void)
{
    func_800DED9C(D_800AF470.p);
    return 0;
}

EXTERN_C int func_80071538(void)
{
    func_800DEDD4(D_800AF470.p);
    return 0;
}

EXTERN_C int func_80071560(void)
{
    func_800DEE50(D_800AF470.p);
    return 0;
}

EXTERN_C int func_80071588(void)
{
    func_800DEED4(D_800AF470.p);
    return 0;
}

EXTERN_C void func_800715B0(void *self, int a, int b, int c)
{
    char buf[0x38];
    char *o = buf;
    int *v;
    func_80074E28(o);
    FIELD_AT(o, void *, 0x8) = D_80016270;
    v = (int *)(o + 0x1C);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    FIELD_AT(buf, int, 0xC) = a;
    FIELD_AT(buf, int, 0x10) = b;
    FIELD_AT(buf, int, 0x30) = c;
    func_8007164C(self, buf);
    func_80074E44(buf, 2);
}

EXTERN_C void func_8007164C(void *self, void *b)
{
    void *o;
    switch (FIELD_AT(b, int, 0xC) & 0xF0000) {
    case 0x10000:
        if (FIELD_AT(self, void *, 0x54) != 0) {
            o = copy_80071B24(__builtin_new(0x34), b);
            func_800770B4(&D_800AF414, FIELD_AT(self, int, 0x54), (int)o);
        }
        break;
    case 0:
        if (FIELD_AT(self, void *, 0x58) != 0) {
            o = copy_80071B24(__builtin_new(0x34), b);
            func_800770B4(&D_800AF414, FIELD_AT(self, int, 0x58), (int)o);
        }
        break;
    case 0x20000:
        break;
    }
}

EXTERN_C void func_80071820(void *self, int b, int c)
{
    void *o = func_8006FEEC(operator new(0x6C));
    FIELD_AT(self, void *, 0x54) = o;
    func_8006FF50(o, b, c, self);
}

EXTERN_C void func_80071880(void *self, void *b)
{
    if (FIELD_AT(self, void *, 0x58) != 0) {
        VObj<8> *o;
        func_80077234(&D_800AF414, FIELD_AT(self, void *, 0x58));
        o = FIELD_AT(self, VObj<8> *, 0x58);
        if (o != 0) {
            o->v00(3);
        }
    }
    FIELD_AT(self, void *, 0x58) = b;
    func_80077210(&D_800AF414, b);
}

EXTERN_C void func_80071904(void)
{
    func_80076EF8(&D_800AF414, 2);
}

EXTERN_C void *func_8007192C(void *d, void *s)
{
    sub_copy_8007192C((Sub_8007192C *)d, (Sub_8007192C *)s, D_80016BC0);
    sub_copy_8007192C((Sub_8007192C *)((char *)d + 0x10), (Sub_8007192C *)((char *)s + 0x10), D_80016BC0);
    FIELD_AT(d, int, 0x20) = FIELD_AT(s, int, 0x20);
    sub_copy_8007192C((Sub_8007192C *)((char *)d + 0x24), (Sub_8007192C *)((char *)s + 0x24), D_80016BC0);
    sub_copy_8007192C((Sub_8007192C *)((char *)d + 0x34), (Sub_8007192C *)((char *)s + 0x34), D_80016868);
    FIELD_AT(d, int, 0x44) = FIELD_AT(s, int, 0x44);
    FIELD_AT(d, int, 0x48) = FIELD_AT(s, int, 0x48);
    FIELD_AT(d, int, 0x4C) = FIELD_AT(s, int, 0x4C);
    FIELD_AT(d, int, 0x50) = FIELD_AT(s, int, 0x50);
    FIELD_AT(d, int, 0x54) = FIELD_AT(s, int, 0x54);
    FIELD_AT(d, int, 0x58) = FIELD_AT(s, int, 0x58);
    return d;
}

EXTERN_C void func_80071A40(void)
{
    func_80076EA8(&D_800AF414);
    D_800AF414.a = 0;
    D_800AF414.b = 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_80016248);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_80016270);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_80016280);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_80016298);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_800162B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_80016300);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_80016310);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_800163A8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_800163C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_800163E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006CBCC", D_80016410);
