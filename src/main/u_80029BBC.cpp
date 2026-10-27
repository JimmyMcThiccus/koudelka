#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_80029BBC);

EXTERN_C int func_80029BF4(S_80029BF4 *p)
{
    return p->unk7;
}

EXTERN_C int func_80029C00(S_80029BF4 *p)
{
    return p->unk6;
}

EXTERN_C int func_80029C0C(S_80029BF4 *p)
{
    return p->unk5;
}

EXTERN_C S_8001A294 *func_80029C18(S_8001A294 *p, S_8001A294 *q)
{
    p->vtbl = D_80011384;
    p->unk4 = q->unk4;
    return p;
}

EXTERN_C void func_80029C34(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_80029C54);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_80029D74);

EXTERN_C void func_80029EB8()
{
}

EXTERN_C void func_80029EC0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_80029EC8);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_80029F30);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_80029FC0);

EXTERN_C void func_8002A004(S_8002A004 *p)
{
    if (p->unk28 == 0)
        p->unk28 = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A020);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A064);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A09C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A0D0);

EXTERN_C void func_8002A110(S_8002A110 *p)
{
    p->unk28 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A118);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A168);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A1BC);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A210);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A274);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A2D8);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A33C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A37C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A3C0);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A400);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A444);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A484);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A4C8);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A55C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A5F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A65C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A698);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A728);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A7B8);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A864);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A910);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002A9BC);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AA8C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AB5C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AC2C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AC60);

EXTERN_C void func_8002AD0C(void *p, S_8002AD0C *q)
{
    func_8002A064(p, q->unk0, q->unk2);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AD38);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002ADA8);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AE14);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AE50);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AE8C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AEE0);

EXTERN_C void *func_8002AF34(S_8002AF34 *p)
{
    return &p->unkC;
}

EXTERN_C S_Rgb func_8002AF3C(S_80025A64 *p)
{
    return p->unk10;
}

EXTERN_C S_Rgb func_8002AF5C(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C int func_8002AF7C(S_8002AF34 *p)
{
    return p->unk24;
}

EXTERN_C int func_8002AF88(S_8002AF34 *p)
{
    return p->unk20;
}

EXTERN_C int func_8002AF94(S_8002AF94 *p)
{
    int r = 0;
    if (p->unk8)
        r = p->unk28 != 0;
    return r;
}

EXTERN_C int func_8002AFB8(S_8002AF34 *p)
{
    return p->unk1C;
}

EXTERN_C void func_8002AFC4(S_8002AF34 *p, int v)
{
    p->unk1C = v;
}

EXTERN_C int func_8002AFCC(S_8002AF34 *p)
{
    return p->unk8;
}

EXTERN_C int func_8002AFD8(S_8002AF34 *p)
{
    return p->unk4;
}

EXTERN_C void func_8002AFE4(S_8002AF34 *p, int v)
{
    p->unk4 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002AFEC);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B108);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B174);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B27C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B36C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B47C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B518);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B5B4);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B67C);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B6FC);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B7A4);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B854);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B904);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002B9B4);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002BA94);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002BB34);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002BBD4);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002BC08);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002BCD0);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002BD34);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002BDFC);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C084);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C0E4);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C120);

EXTERN_C int func_8002C15C(S_8002C15C *p)
{
    return count_of(&p->unk30);
}

EXTERN_C int func_8002C17C(S_8002C17C *p)
{
    return p->unk8;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C188);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C2B8);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C498);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C514);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C5EC);

EXTERN_C int func_8002C6C8(S_8002C6C8 *p)
{
    return p->unk8;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C6D4);

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C7DC);

EXTERN_C void func_8002C8A4()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC710)->p, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80029BBC", func_8002C8CC);
