#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

EXTERN_C void func_80082174(int b)
{
    func_80081DCC(&D_800AFA74, b);
}

EXTERN_C void func_8008219C(int b)
{
    func_80081CB8(&D_800AFA74, b);
}

EXTERN_C void func_800821C4(int b)
{
    func_80081BA4(&D_800AFA74, b);
}

EXTERN_C void func_800821EC(int b)
{
    func_80081A74(&D_800AFA74, b);
}

EXTERN_C void func_80082214(void)
{
    func_800817C8(&D_800AFA74);
}

EXTERN_C void func_80082238(int b)
{
    func_80081970(&D_800AFA74, b);
}

EXTERN_C void func_80082260(int a, int b, unsigned short c, int d, int e)
{
    func_80081820(&D_800AFA74, a, b, c, d, e);
}

EXTERN_C void *func_800822A4(void)
{
    return D_800AFA70.p;
}

EXTERN_C void func_800822B4(void *self)
{
    func_800817C8(self);
}

EXTERN_C int func_800822D4(void *self)
{
    return FIELD_AT(self, int, 0x10);
}

EXTERN_C void func_800822E0(void *self)
{
    int d = FIELD_AT(self, int, 0x10);
    int c = FIELD_AT(self, int, 0x1C);
    unsigned short s = FIELD_AT(self, unsigned short, 0x14);
    char *p = (char *)func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = s;
    FIELD_AT(p, int, 0x10) = d;
    FIELD_AT(p, int, 0xC) = c;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(FIELD_AT(self, void *, 0x18), p);
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800823A4);

EXTERN_C void func_80082450(void *self, int b)
{
    func_80074E44(self, b);
}

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

EXTERN_C void *func_800824A0(void *self)
{
    func_800824C8(self);
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800824C8);

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

EXTERN_C void func_80082670(Obj_80082670 *self, int i, int value)
{
    if (self->mode == 2) {
        self->items[i] = value;
    }
}

EXTERN_C void *func_80082690(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_80017758;
    FIELD_AT(self, char, 0x9) = 0;
    FIELD_AT(self, short, 0xA) = -1;
    return self;
}

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

EXTERN_C void *func_800827EC(char *self)
{
    short v;
    FIELD_AT(self, void *, 0x15C) = D_80017690;
    func_80082470((Obj_80082470 *)(self + 4));
    func_80082690(self + 0x58);
    func_80082768(self + 0x7C);
    FIELD_AT(self, short, 0x40) = -2;
    FIELD_AT(self, short, 0x42) = -2;
    FIELD_AT(self, short, 0x44) = -2;
    v = -2;
    for (int i = 3; i >= 0; i--) {
        ((O_800827EC *)self)->d[i] = v;
    }
    ((O_800827EC *)self)->e = -2;
    short v2 = -2;
    for (int i = 1; i >= 0; i--) {
        ((O_800827EC *)self)->f[i] = v2;
    }
    FIELD_AT(self, short, 0x54) = -2;
    FIELD_AT(self, char, 0x56) = 0;
    FIELD_AT(self, char, 0x57) = 0;
    FIELD_AT(self, char, 0x8B) = 0;
    FIELD_AT(self, char, 0x8C) = 0;
    FIELD_AT(self, char, 0x8D) = 0;
    FIELD_AT(self, char, 0x8E) = 0;
    FIELD_AT(self, char, 0x99) = 0;
    FIELD_AT(self, short, 0x92) = 0;
    FIELD_AT(self, short, 0x90) = 0;
    FIELD_AT(self, short, 0x94) = 0;
    FIELD_AT(self, char, 0x98) = 0;
    for (int i = 0; i < 0x20; i++) {
        ((H_80082D44 *)self)->h[i][0] = -1;
        ((H_80082D44 *)self)->h[i][1] = -1;
    }
    func_80083EB4((Obj_80083EB4 *)self);
    return self;
}

EXTERN_C void func_800828E4(char *self, int flags)
{
    FIELD_AT(self, void *, 0x15C) = D_80017690;
    char *l = self + 0x58;
    while (1) {
        VObj0 *o = FIELD_AT(l, VObj0 *, 4);
        if (o == 0) break;
        func_8001A744(l, o);
        FIELD_AT(o, int, 4) = 0;
        o->v00(3);
    }
    func_800827C4(self + 0x7C, 2);
    func_8001A610(l, 2);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008299C);

EXTERN_C void func_80082C68(H_80082D44 *self, short b, int c, int d, unsigned short e)
{
    int i;
    for (i = 0x1F; i > 0; i--) {
        int j;
        for (j = 0; j < 2; j++) {
            self->h[i][j] = self->h[i - 1][j];
        }
    }
    self->h[0][0] = b;
    self->h[0][1] = c;
    func_8001A678((char *)self + 0x58, func_80082714((Obj_80082714 *)__builtin_new(0x24), b, c, d, e, 0, 0));
}

EXTERN_C void func_80082D44(H_80082D44 *self, short b, int c, int d, int e)
{
    int i;
    for (i = 0x1F; i > 0; i--) {
        int j;
        for (j = 0; j < 2; j++) {
            self->h[i][j] = self->h[i - 1][j];
        }
    }
    self->h[0][0] = b;
    self->h[0][1] = c;
    func_8001A678((char *)self + 0x58, func_80082714((Obj_80082714 *)__builtin_new(0x24), (short)b, c, d, e, 0, 0));
}

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

EXTERN_C void func_80082EB0(char *self, int b, int c)
{
    if (b >= 0) {
        FIELD_AT(self, short, 0x94)++;
        func_8001A678(self + 0x7C, func_80082798(__builtin_new(0xC), (short)b, c));
        if (func_8001A6E8(self + 0x7C) == 2) {
            ((VObj<0x15C> *)self)->v00(b, c);
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80082F5C);

EXTERN_C void func_8008316C(void *self)
{
    if (FIELD_AT(self, short, 0x54) >= 0) {
        func_80083F40(self, FIELD_AT(self, short, 0x54));
        FIELD_AT(self, short, 0x54) = -2;
    }
    if (FIELD_AT(self, short, 0x4E) >= 0) {
        func_80083F40(self, FIELD_AT(self, short, 0x4E));
        FIELD_AT(self, short, 0x4E) = -2;
    }
    if (FIELD_AT(self, short, 0x44) >= 0) {
        func_80083F40(self, FIELD_AT(self, short, 0x44));
        FIELD_AT(self, short, 0x44) = -2;
    }
    if (FIELD_AT(self, signed char, 0x56) && FIELD_AT(self, signed char, 0x57)) {
        int i;
        FIELD_AT(self, char, 0x56) = 0;
        FIELD_AT(self, char, 0x57) = 0;
        for (i = 0; i < 4; i++) {
            if (((A46_8008316C *)self)->e[i] >= 0) {
                func_80083F40(self, ((A46_8008316C *)self)->e[i]);
                ((A46_8008316C *)self)->e[i] = -2;
            }
        }
    }
    func_80083310(self);
}

EXTERN_C void func_80083268(void *self)
{
    if (FIELD_AT(self, short, 0x44) >= 0) {
        func_80083F40(self, FIELD_AT(self, short, 0x44));
        FIELD_AT(self, short, 0x44) = -2;
    }
    func_80083310(self);
}

EXTERN_C void func_800832B0(void *self)
{
    FIELD_AT(self, char, 0x8E) = 0;
    func_80083310(self);
}

EXTERN_C void func_800832D0(void *self)
{
    FIELD_AT(self, char, 0x99) = 0;
    func_80083310(self);
}

EXTERN_C void func_800832F0(void *self)
{
    func_80083310(self);
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800833F8);

EXTERN_C void func_80083EB4(Obj_80083EB4 *self)
{
    int i;
    short v = -2;

    for (i = 0x1F; i >= 0; i--) {
        self->items[i] = v;
    }
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80083F40);

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

EXTERN_C void func_800840D8(void *self, int flags)
{
    func_8001A610(self, flags);
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80084130);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80084454);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800846EC);

EXTERN_C void func_8008478C(void *self)
{
    signed char a = FIELD_AT(self, signed char, 0x4BA);
    if (a != FIELD_AT(self, signed char, 0x4BB)) {
        func_800846EC(self, a != 0);
    }
}

EXTERN_C void func_800847C0(void *self, int b, int c)
{
    if (c != 0 && b != 0) {
        func_8003D68C(FIELD_AT(FIELD_AT(self, void *, 0x1B8), void *, 0x68), 1, self, 0xF, 0);
        FIELD_AT(self, char, 0x4E1) = 0;
    }
    FIELD_AT(self, char, 0x4BA) = b;
    func_800846EC(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80084824);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800849D0);

EXTERN_C void func_80084AD8(void *self, int b)
{
    if (FIELD_AT(self, signed char, 0x517) == 0) {
        FIELD_AT(self, short, 0x52A) = 1;
    } else if (FIELD_AT(self, unsigned short, 0x52A) < 2) {
        func_8008299C(self ? (char *)self + 0x2A0 : 0, 0x1C, 1, 0, 0, 0, 0);
        if (b) {
            func_80082E14(self ? (char *)self + 0x2A0 : 0, 0);
        }
        FIELD_AT(self, short, 0x52A) = 2;
    }
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80084C50);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017910);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017914);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017964);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017974);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017994);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_800179AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017A44);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017ADC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017B94);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017BA4);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80084D58);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80084F58);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80085168);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800853D8);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80085578);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80085710);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008586C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80085C60);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80085E74);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80086088);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008623C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008640C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800864C0);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80086578);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008687C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80086A20);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80086B70);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80086E14);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80086F94);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800870E4);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800873A8);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800874C4);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80087620);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80087764);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008816C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800883A0);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80088794);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008891C);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80088C8C);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80088DEC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017C00);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80088F34);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800891C0);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_800894AC);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80089AC0);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80089B44);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80089BF4);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_80089FD0);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008A188);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008A2A0);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008A5C8);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008A770);

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
    func_80086F94(self ? self + 0x400 : 0, b, c);
}

EXTERN_C void func_8008A93C(void *self, int b, int c)
{
    char *q = 0;
    FIELD_AT(self, int, 0x544) = c;
    if (self != 0) {
        q = (char *)self + 0x400;
    }
    func_800870E4(q, b);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008A96C);

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

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017CB4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017CCC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017D1C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017D2C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017D4C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017D64);

INCLUDE_RODATA("asm/main/nonmatchings/u_80082174", D_80017DFC);

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008ACC4);

EXTERN_C int func_8008AE38(void *self, void *b)
{
    if (!(FIELD_AT(self, unsigned char, 0x46D) & 2)) {
        FIELD_AT(self, int, 0x54C) += FIELD_AT(b, unsigned short, 0x546);
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008AE68);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008B150);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80082174", func_8008B30C);

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
