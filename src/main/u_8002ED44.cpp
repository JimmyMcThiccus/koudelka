#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C void *func_8002ED44(void *p, int a, int b)
{
    func_800198E0(p, a, b);
    return p;
}

EXTERN_C void func_8002ED6C(S_8002ED6C *p)
{
    func_80019C68(p, p->unk4 - 1);
}

EXTERN_C void *func_8002ED90(S_8002ED90 *p)
{
    return &p->unk8;
}

EXTERN_C S_Rgb func_8002ED98(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C S_Rgb func_8002EDB8(S_80025A64 *p)
{
    return p->unk8;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002EDD8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002EE10);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002EE40);

EXTERN_C void func_8002EE7C(void *p, int a)
{
    func_8002EE9C(p, a);
}

EXTERN_C void func_8002EE9C(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800118DC;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002EEC4);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002EEFC);

EXTERN_C int func_8002EF64(S_8002EF64 *p)
{
    return p->unk10;
}

EXTERN_C S_8002EC18 *func_8002EF70(S_8002EC18 *p)
{
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002EF88);

EXTERN_C void func_8002F004(void *p, void *q)
{
    func_8002DB50(q, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F028);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F180);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F1BC);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F21C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F2A4);

EXTERN_C int func_8002F32C(S_8002F32C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F338);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F464);

EXTERN_C int func_8002F4C4()
{
    return 0;
}

EXTERN_C int func_8002F4CC(S_8002F4CC *p)
{
    return p->unk14;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F4D8);

EXTERN_C void func_8002F520(void *p, int a)
{
    func_8002EEFC(p, a);
}

EXTERN_C void *func_8002F540(S_8002F4CC *p)
{
    return &p->unkC;
}

EXTERN_C void func_8002F548()
{
}

EXTERN_C int func_8002F550()
{
    return -1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F558);

EXTERN_C int func_8002F580(unsigned int a)
{
    return (a >> 5) & 3;
}

EXTERN_C int func_8002F58C(int a, int b)
{
    return (a & 0xFF9F) | ((b & 3) << 5);
}

EXTERN_C int func_8002F5A0(int v)
{
    int old = D_800B4D00;
    D_800B4D00 = v;
    return old;
}

EXTERN_C void func_8002F5B0(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F5D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F614);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F7D4);

EXTERN_C int func_8002F818(S_8002F818 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F824);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F874);

EXTERN_C int func_8002F8D0()
{
    return 0;
}

EXTERN_C void func_8002F8D8()
{
}

EXTERN_C S_8002F8E0 *func_8002F8E0(S_8002F8E0 *p)
{
    p->vtbl = D_80011B5C;
    p->unk0 = 0;
    return p;
}

EXTERN_C int func_8002F8F8(int *p, int i)
{
    return p[i];
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F90C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F960);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002F998);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FA20);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FA50);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FAF8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FB8C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FC40);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FCF4);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FD5C);

EXTERN_C int func_8002FD98(S_8002FD98 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FDA4);

EXTERN_C int func_8002FE3C(void *p, int i)
{
    return D_800B4D08[i];
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FE54);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8002FEC8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030084);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800300C8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800301BC);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030358);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030384);

EXTERN_C int func_800303FC()
{
    return 0;
}

EXTERN_C void func_80030404()
{
}

EXTERN_C void func_8003040C()
{
}

EXTERN_C void func_80030414()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8003041C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800304B4);

EXTERN_C int func_80030520()
{
    return 0;
}

EXTERN_C int func_80030528(S_80030528 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030534);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030608);

EXTERN_C int *func_80030694(int *p)
{
    func_8001AA28(p, 6);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800306C0);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030714);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8003074C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800307D4);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030804);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800308B0);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030940);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800309F4);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030AA8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030B10);

EXTERN_C int func_80030B4C(S_80030B4C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030B58);

EXTERN_C int func_80030BF0(int a)
{
    return (a + 1) & 3;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030BFC);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030C70);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030E9C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80030EE0);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80031030);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800311CC);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800311F8);

EXTERN_C int func_80031278()
{
    return 0x28;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80031280);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800313BC);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800313E0);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8003148C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800318A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80031CE4);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_8003212C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_80032174);

INCLUDE_ASM("asm/main/nonmatchings/u_8002ED44", func_800321D8);
