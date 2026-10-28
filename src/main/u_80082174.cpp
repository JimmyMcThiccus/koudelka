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
    func_80081970(&D_800AFA74, (void *)b);
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
