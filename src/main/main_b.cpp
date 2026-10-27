#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

EXTERN_C void func_80054A2C(void *self, int b)
{
    func_80053964(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80054A4C);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80054AF0);

INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80054B98);

EXTERN_C void func_80054C34(void *self, int b)
{
    char *h;
    FIELD_AT(self, void *, 0x18) = D_80013B70;
    func_80054FE0(self);
    h = (char *)self + 0x1C;
    func_80019D40(h ? FIELD_AT(h, List *, 0x0) : 0);
    func_80019920(FIELD_AT(self, void *, 0x1C), 0);
    func_80053964(self, b);
}

EXTERN_C void func_80054CA0(void *self)
{
    VObj<0x2C> *v = FIELD_AT(self, VObj<0x2C> *, 0x3C);
    if (v != 0) {
        v->v27();
    }
}

EXTERN_C void func_80054CE4(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_80058830(p, (char *)self + 0x1C);
    }
}

EXTERN_C void func_80054D18(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_800581E0(p);
    }
}

EXTERN_C void func_80054D48(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_80057F20(p, b);
    }
}

EXTERN_C int func_80054D78(void *self)
{
    char *p = FIELD_AT(self, char *, 0x3C);
    if (p == 0) {
        return 1;
    }
    return func_80053880(p + 0x50);
}

EXTERN_C void func_80054DA8(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_8005800C(p);
    }
}

EXTERN_C void func_80054DD8(void *self)
{
    char *h = (char *)self + 0x1C;
    func_80019D40(h ? FIELD_AT(h, List *, 0x0) : 0);
}

EXTERN_C int func_80054E0C(void *self)
{
    return FIELD_AT(self, unsigned short, 0x44) != 0;
}

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

EXTERN_C void func_80054F30(Obj_80054F30 *self, int a, SV_80054F30 *v, int d)
{
    self->a = a;
    self->v = *v;
    self->d = d;
}

EXTERN_C void func_80054F5C(void *self)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        func_8005854C(p, FIELD_AT(self, unsigned short, 0x44), (char *)self + 0x46, FIELD_AT(self, short, 0x4E));
        FIELD_AT(self, VObj<0x2C> *, 0x3C)->v04();
    }
}

EXTERN_C void func_80054FC0(void *self)
{
    func_800550FC(self, 0);
}

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

EXTERN_C int func_800557A0(void)
{
    return func_8001A6E8((char *)D_800B4D84 + 0x8C) >= 2;
}

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
