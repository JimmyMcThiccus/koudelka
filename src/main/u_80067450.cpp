#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80067450", func_80067450);

INCLUDE_ASM("asm/main/nonmatchings/u_80067450", func_800674C8);

INCLUDE_ASM("asm/main/nonmatchings/u_80067450", func_8006753C);

EXTERN_C void func_80067ABC(void *self, void *b)
{
    func_80054094((char *)self + 0x64, FIELD_AT(b, unsigned char, 0x18) != 1);
    func_80067B1C(self, FIELD_AT(b, unsigned short, 0xC), (char *)b + 0x80, (char *)b + 0xE, FIELD_AT(b, unsigned char, 0x8A) & 0xF);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80067450", func_80067B1C);

EXTERN_C void func_800680A0(void *self)
{
    int a = func_8005409C((char *)self + 0x64);
    int b = func_8005409C((char *)self + 0xB4);
    int c = func_8005409C((char *)self + 0x104);
    if (a || b || c) {
        func_800566E4(self);
        SV2C_80055020 pos(0x18, 0x4D);
        if (a) {
            func_80055020((char *)self + 0x64, pos);
            func_80054FC0((char *)self + 0x64);
            pos.y += FIELD_AT(func_80054F28((char *)self + 0x64), short, 0x2) + 2;
        }
        if (b) {
            func_80055020((char *)self + 0xB4, pos);
            func_80054FC0((char *)self + 0xB4);
            pos.y += FIELD_AT(func_80054F28((char *)self + 0xB4), short, 0x2) + 2;
        }
        if (c) {
            func_80055020((char *)self + 0x104, pos);
            func_80054FC0((char *)self + 0x104);
        }
        func_8008EF40(0xC);
    }
}

EXTERN_C void func_8006821C(void *self)
{
    char *p = (char *)self + 0x64;
    if (func_8005409C(p)) {
        func_80054FE0(p);
    }
    p = (char *)self + 0xB4;
    if (func_8005409C(p)) {
        func_80054FE0(p);
    }
    p = (char *)self + 0x104;
    if (func_8005409C(p)) {
        func_80054FE0(p);
    }
    func_80056874(self);
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80067450", func_80068380);

INCLUDE_ASM("asm/main/nonmatchings/u_80067450", func_80068660);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015904);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015914);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015964);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015984);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_800159C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015A14);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015B34);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015B84);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015B9C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80067450", D_80015BB4);
