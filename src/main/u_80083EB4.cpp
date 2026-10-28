#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

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

struct I9A_80083F40 { char pad[0x9A]; short ids[32]; };
EXTERN_C int func_80083F40(void *self, int id)
{
    if (id >= 0) {
        for (int i = 0; i < 0x20; i++) {
            if (((I9A_80083F40 *)self)->ids[i] == id) {
                ((VObj<0x15C> *)self)->v01(id, 0);
                ((I9A_80083F40 *)self)->ids[i] = -2;
                return i;
            }
        }
    } else if (id == -1) {
        for (int i = 0; i < 0x20; i++) {
            if (((I9A_80083F40 *)self)->ids[i] != -2) {
                ((VObj<0x15C> *)self)->v01(((I9A_80083F40 *)self)->ids[i], 0);
                ((I9A_80083F40 *)self)->ids[i] = -2;
            }
        }
    }
    return id;
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80083EB4", func_80084130);

INCLUDE_ASM("asm/main/nonmatchings/u_80083EB4", func_80084454);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80083EB4", func_800846EC);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80083EB4", func_80084824);

INCLUDE_ASM("asm/main/nonmatchings/u_80083EB4", func_800849D0);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80083EB4", func_80084C50);

INCLUDE_ASM("asm/main/nonmatchings/u_80083EB4", func_80084D58);

INCLUDE_ASM("asm/main/nonmatchings/u_80083EB4", func_80084F58);

INCLUDE_RODATA("asm/main/nonmatchings/u_80083EB4", D_80017C00);
