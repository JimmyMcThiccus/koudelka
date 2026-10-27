#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C void func_8002DED8(void *p, int a)
{
    func_8002DD34(p, a);
}

EXTERN_C void func_8002DEF8(void *p, int a, int b)
{
    func_8002DC34(p, a, b);
}

EXTERN_C void func_8002DF18(void *p, int a)
{
    func_8002DA94(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002DF38);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002DF9C);

EXTERN_C void func_8002E000(void *p, int a)
{
    func_8002D8AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E020);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E054);

EXTERN_C S_Rgb func_8002E088(S_8002E088 *p)
{
    return p->unk28;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E0A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E2AC);

EXTERN_C void *func_8002E4B8(S_8002E4B8 *p)
{
    return &p->unk20;
}

EXTERN_C void func_8002E4C0(S_8002E4B8 *p)
{
    p->unk2C = 1;
}

EXTERN_C void func_8002E4CC(S_8002E4B8 *p)
{
    p->unk2C = 0;
}

EXTERN_C void func_8002E4D4(S_8002E4B8 *p, int v)
{
    p->unk1C = v;
}

EXTERN_C int func_8002E4DC(S_8002E4B8 *p)
{
    return p->unk1C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E4E8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E564);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E5B0);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E5D0);

EXTERN_C int func_8002E5F0()
{
    return D_800AC809[0] != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E600);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E69C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E714);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E7A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E814);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E898);

EXTERN_C int func_8002E908(S_8002E908 *p)
{
    return p->unk10;
}

EXTERN_C int func_8002E914(S_8002E908 *p)
{
    return p->unk10;
}

EXTERN_C int func_8002E920(S_8002E908 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E92C);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002E9D0);

EXTERN_C int func_8002EA0C(S_8002E908 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002EA18);

EXTERN_C void func_8002EA50(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002EA70);

EXTERN_C void func_8002EAAC()
{
}

EXTERN_C void func_8002EAB4()
{
}

EXTERN_C void func_8002EABC()
{
}

EXTERN_C void func_8002EAC4()
{
}

EXTERN_C void func_8002EACC()
{
}

EXTERN_C void func_8002EAD4()
{
}

EXTERN_C void func_8002EADC(S_8002E908 *p, int a, int b)
{
    p->unk8 = a;
    p->unkA = b;
}

EXTERN_C void func_8002EAE8(S_8002E908 *p, int a, int b)
{
    p->unkC = a;
    p->unkE = b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002EAF4);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002EB68);

EXTERN_C S_8002EBF0 *func_8002EBF0(S_8002EBF0 *p)
{
    p->unk0 = 0;
    p->unk2 = 0;
    return p;
}

EXTERN_C S_8002EC00 *func_8002EC00(S_8002EC00 *p)
{
    p->unk0 = 0;
    p->unk2 = 0;
    p->unk4 = 0;
    p->unk6 = 0;
    return p;
}

EXTERN_C S_8002EC18 *func_8002EC18(S_8002EC18 *p)
{
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    return p;
}

EXTERN_C void func_8002EC30()
{
}

EXTERN_C int func_8002EC38()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002EC40);

INCLUDE_ASM("asm/main/nonmatchings/u_8002DED8", func_8002EC90);

EXTERN_C void func_8002ECE0()
{
}

EXTERN_C void func_8002ECE8()
{
}

EXTERN_C void func_8002ECF0()
{
    func_80019920((List *)&D_800AC820, 2);
}

EXTERN_C void func_8002ED18()
{
    func_800198E0(&D_800AC820, 0x10, 0);
}
