#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C S_Vobj *func_8001F1A8(S_Vobj *p)
{
    p->vtbl = D_800103F8;
    return p;
}

EXTERN_C unsigned short func_8001F1BC(S_8001F1BC *p, int v)
{
    unsigned short old = p->unk94;
    p->unk94 = v;
    return old;
}

EXTERN_C int func_8001F1CC(S_8001F1CC *p)
{
    return p->unk98;
}

EXTERN_C int func_8001F1D8(S_8001F1CC *p)
{
    return p->unk4;
}

EXTERN_C S_8001F1BC *func_8001F1E4()
{
    return D_800B4C18;
}

EXTERN_C int func_8001F1F0(S_8001F1CC *p)
{
    return p->unkF0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F1FC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F2C4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F360);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F3DC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F460);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F514);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F544);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F598);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F60C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F67C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F6E0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F788);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F85C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F930);

EXTERN_C S_8001F964_Derived *func_8001F964(S_8001F964 *p)
{
    return (S_8001F964_Derived *)p->unkC;
}

EXTERN_C int func_8001F980(S_8001F980 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F98C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001F9C0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FA6C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FA9C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FAD4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FB0C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FB4C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FB9C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FBF4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FC38);

EXTERN_C void func_8001FC78(S_8001FC78 *p, int a, int b)
{
    func_80020734(p->unk8, a, p, b);
}

EXTERN_C int func_8001FCA4(S_8001FCA4 *p)
{
    return p->unk8->unk4;
}

EXTERN_C void func_8001FCB8(S_8001FC78 *p)
{
    func_800208D4(p->unk8);
}

EXTERN_C void func_8001FCDC(S_8001FC78 *p)
{
    func_80020948(p->unk8);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FD00);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FD90);

EXTERN_C int func_8001FE20()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FE28);

EXTERN_C int func_8001FEB0()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FEB8);

EXTERN_C int func_8001FF40()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_8001FF48);

EXTERN_C int func_8001FFD0(S_8001FFD0 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4 *func_8001FFDC(S_Vobj4 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800104A8;
    return p;
}

EXTERN_C void func_80020000(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_80020020(S_8001FFD0 *p)
{
    return (p->unk12 >> 3) & 1;
}

EXTERN_C int func_80020034(S_8001FFD0 *p)
{
    return (p->unk12 >> 2) & 1;
}

EXTERN_C int func_80020048(S_8001FFD0 *p)
{
    return (p->unk12 >> 1) & 1;
}

EXTERN_C int func_8002005C(S_8001FFD0 *p)
{
    return p->unk12 & 0x1;
}

EXTERN_C void func_80020068(S_8001FFD0 *p, int v)
{
    p->unk12 = v;
}

EXTERN_C void func_80020070(S_8001FFD0 *p, int v)
{
    p->unk8 = v;
}

EXTERN_C void func_80020078(S_8001FFD0 *p, int v)
{
    p->unkC = v;
}

EXTERN_C void func_80020080(S_8001FFD0 *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_80020088(S_8001FFD0 *p)
{
    return p->unk12;
}

EXTERN_C int func_80020094(S_8001FFD0 *p)
{
    return p->unk8;
}

EXTERN_C int func_800200A0(S_8001FFD0 *p)
{
    return p->unkC;
}

EXTERN_C int func_800200AC(S_8001FFD0 *p)
{
    return p->unk10 & 0xFF00;
}

EXTERN_C int func_800200B8(S_8001FFD0 *p)
{
    return p->unk10;
}

EXTERN_C int func_800200C4(S_8001FFD0 *p)
{
    return p->unk4;
}

EXTERN_C void func_800200D0(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_800200F0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800103F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010408);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010420);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010438);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010450);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010460);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010470);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010480);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010498);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800104A8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800104F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010508);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010538);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010588);

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_800201DC);

EXTERN_C int func_800202B4()
{
    return 0;
}

EXTERN_C int func_800202BC()
{
    return 0;
}

EXTERN_C int func_800202C4()
{
    return 0;
}

EXTERN_C int func_800202CC()
{
    return 0;
}

EXTERN_C int func_800202D4()
{
    return 0;
}

EXTERN_C void func_800202DC()
{
    func_8001A610(&D_800AC6A8, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001F1A8", func_80020304);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800105B4);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800105DC);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800105F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_8001060C);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010624);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010654);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010684);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010694);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800106A4);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800106BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_800106EC);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010714);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010734);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_8001075C);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_80010774);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001F1A8", D_8001079C);
