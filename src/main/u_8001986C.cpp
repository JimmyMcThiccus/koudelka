#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C void func_8001986C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", printf);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019894);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", puts);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_800198A4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_800198AC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_800198E0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019920);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019974);

EXTERN_C int func_80019A18(S_80019A18 *p, int v)
{
    int old = p->unk10;
    p->unk10 = v;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019A24);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019A6C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019B2C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019BA0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019C24);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019C68);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019CFC);

EXTERN_C void func_80019D40(S_80019D40 *p)
{
    if (p->unk10 == 0)
        p->unk4 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019D5C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019F0C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019F64);

EXTERN_C int func_80019FB4(S_80019FB4 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019FC0);

EXTERN_C void func_8001A00C(S_80019FB4 *p, int v)
{
    p->unk8 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A014);

EXTERN_C void func_8001A030(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A050);

EXTERN_C int func_8001A080(S_8001A080 *p)
{
    return p->unk4 ? *p->unk0 : 0;
}

EXTERN_C void func_8001A0AC(void *p, int a)
{
    func_80019A6C(p, a, 0);
}

EXTERN_C void func_8001A0CC(S_8001A080 *p, int a)
{
    func_80019A6C(p, a, p->unk4);
}

EXTERN_C void func_8001A0F0(S_8001A080 *p, int a)
{
    func_80019A6C(p, a, p->unk4);
}

EXTERN_C int func_8001A114(S_8001A114 *p)
{
    return p->unk8;
}

EXTERN_C int func_8001A120(S_8001A114 *p)
{
    return p->unk4 == 0;
}

EXTERN_C int func_8001A12C(S_8001A114 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A138);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A1A0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A220);

EXTERN_C S_8001A294 *func_8001A294(S_8001A294 *p, int a, int b)
{
    p->vtbl = D_80010118;
    p->unk4 = a;
    p->unk8 = b;
    return p;
}

EXTERN_C void func_8001A2B0(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A2D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A354);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A3BC);

EXTERN_C void func_8001A46C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A48C);

EXTERN_C void func_8001A53C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A55C);

EXTERN_C void func_8001A5F0(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A610);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A678);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A6A8);

EXTERN_C int func_8001A6E8(S_8001A6E8 *p)
{
    int n = 0;
    while (p) {
        p = p->unk4;
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A708);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A744);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A7B4);

EXTERN_C void func_8001A844(void *p, int a)
{
    func_8001A678(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A864);

EXTERN_C int func_8001A8B8(S_8001A8B8 *p, int v)
{
    p->unk4 = v;
    return v;
}

EXTERN_C void func_8001A8C4(S_8001A8B8 *p)
{
    p->unk4 = 0;
}

EXTERN_C int func_8001A8CC(S_8001A8B8 *p)
{
    return p->unk4;
}

EXTERN_C S_8001A294 *func_8001A8D8(S_8001A294 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A8F0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001A970);

EXTERN_C int *func_8001AA28(int *p, int n)
{
    int *q = p;
    while (n--)
        *q++ = 0;
    return p;
}

EXTERN_C S_Vobj *func_8001AA54(S_Vobj *p)
{
    p->vtbl = D_80010198;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AA68);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AB50);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AC38);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AC80);

EXTERN_C void func_8001ACB4()
{
    D_800B4C04 = func_8001ACDC(operator new(0x4008));
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001ACDC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AD18);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AD68);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001ADE0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AEFC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AF8C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B0C0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B134);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B1C8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B26C);

EXTERN_C void func_8001B2D8(void *p)
{
    func_8001B0C0(D_800B4C04, p);
}

EXTERN_C int func_8001B300(char *a, char *b)
{
    return a + 8 < b;
}

EXTERN_C int func_8001B30C(S_8001B30C *p)
{
    return p->unk4;
}

EXTERN_C void func_8001B318(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B338);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B394);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B424);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B46C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B8C8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B910);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001BBBC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001BE20);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001BE9C);

EXTERN_C void func_8001C2AC()
{
    func_8001C2D0((S_Vobj *)&D_800B4C10);
}
