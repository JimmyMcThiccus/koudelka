#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C S_Vobj *func_8001C2D0(S_Vobj *p)
{
    p->vtbl = D_800101E8;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C2E4);

EXTERN_C void func_8001C36C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C38C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C580);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C5DC);

EXTERN_C int func_8001C658(S_8001C658 *p)
{
    return p->unk4 != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C664);

EXTERN_C void func_8001C6A0(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_8001C6C0(S_8001C658 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4 *func_8001C6CC(S_Vobj4 *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800102B0;
    p->unk8 = 0;
    p->unkC = a;
    return p;
}

EXTERN_C void func_8001C6F8(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C718);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C7D4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C89C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C8D8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C974);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C9D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CA10);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CA58);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CAA4);

EXTERN_C void func_8001CAE0(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CB00);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CB7C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CC00);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CC84);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CCC8);

EXTERN_C int func_8001CD10(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CD1C(S_8001CD10 *p)
{
    return p->unk4 != 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800100C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800100D0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800100E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800100F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010108);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010118);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010130);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010148);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010160);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010178);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010198);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101D8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101E8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010210);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010260);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010278);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010288);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800102A0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800102B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800102C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800102D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CD28);

EXTERN_C int func_8001CD6C(S_8001CD10 *p)
{
    return p->unk4;
}

EXTERN_C void func_8001CD78(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_8001CD98(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDA4(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDB0(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDBC(S_8001CD10 *p)
{
    return p->unk8;
}

EXTERN_C int func_8001CDC8(S_8001CD10 *p)
{
    return p->unkA;
}

EXTERN_C int func_8001CDD4(S_8001CD10 *p)
{
    return p->unk10;
}

EXTERN_C int func_8001CDE0(S_8001CD10 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CDEC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CE24);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CE5C);

EXTERN_C S_Vobj4 *func_8001CE94(S_Vobj4 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_80010300;
    return p;
}

EXTERN_C void func_8001CEB8(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CED8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CF68);

EXTERN_C int func_8001CFF8(S_8001CFF8 *p)
{
    return p->unk4;
}

EXTERN_C void func_8001D004(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C void func_8001D024(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80010348;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D04C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D0E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D150);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D25C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D2C0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D324);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D3A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D490);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D4C0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D540);

EXTERN_C S_8001A294 *func_8001D5A8(S_8001A294 *p)
{
    p->vtbl = D_80010328;
    p->unk4 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D5C0);

EXTERN_C int func_8001D62C(S_8001D62C *p)
{
    return p->unk10;
}

EXTERN_C void func_8001D638(S_8001D62C *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_8001D640(S_8001D62C *p)
{
    return p->unkC;
}

EXTERN_C int func_8001D64C(S_8001D62C *p)
{
    return p->unk8;
}

EXTERN_C void func_8001D658(void *p, int a)
{
    func_8001A6A8(p, a);
}

EXTERN_C int func_8001D678(S_8001D62C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D684);

EXTERN_C S_Vobj *func_8001D6B4(S_Vobj *p)
{
    p->vtbl = D_80010348;
    return p;
}

EXTERN_C int func_8001D6C8(S_8001D6C8 *p)
{
    return D_800A4534.unkC < p->unk14;
}

EXTERN_C void func_8001D6E0(S_8001D6C8 *p, int a)
{
    unsigned int t = D_800A4534.unkC;
    p->unk18 = t;
    p->unk14 = t + a;
}

EXTERN_C void func_8001D700(S_8001D6C8 *p, int a)
{
    unsigned int t = D_800A4534.unkC;
    p->unk14 = t;
    p->unk18 = t + a;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010300);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010328);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010338);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010348);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D720);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D76C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D7B0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D8A4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D9F4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001DB04);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001DBB8);

EXTERN_C void func_8001DDD0()
{
    func_8001D7B0(&D_800AC57C);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010378);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010388);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800103A0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800103B8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800103D0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800103E0);
