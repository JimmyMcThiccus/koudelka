#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80033ECC);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80033F30);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80033F9C);

EXTERN_C void func_80034028(S_800323C0 *p, S_800323C0_Node *n)
{
    if (p->unk8)
        n->unk4 = p->unk8;
    p->unk8 = n;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034044);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034184);

EXTERN_C int func_80034608(S_80034608 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034614);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034710);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003479C);

EXTERN_C void func_80034854(void *p, void *q)
{
    AT(p, int, 0) = AT(q, int, 0);
    func_80034EBC(p ? (char *)p + 4 : 0, (char *)q + 4);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003488C);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800348E4);

EXTERN_C S_80034924_B *func_80034924(S_80034924_A *p, S_80034924_B *q)
{
    int a = p->unk4, b = p->unk8, c = p->unkC, d = p->unk10;
    q->unkC = a;
    q->unk14 = b;
    q->unk1C = c;
    q->unk24 = d;
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003494C);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800349F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034AA0);

EXTERN_C S_Prim *func_80034AF4(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 9;
    p->code = 0x2C;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034B0C);

EXTERN_C void func_80034B84(S_A2_Flags *p, int on)
{
    unsigned char v = p->f;
    if (on) p->f = v | 2; else p->f = v & ~2;
}

EXTERN_C S_80034BA8 *func_80034BA8(S_80034BA8 *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C int func_80034BB4(S_80034BB4 *p)
{
    return (p->unk3 >> 1) & 1;
}

EXTERN_C void func_80034BC8(int *a, int *b)
{
    *a = *b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034BD4);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034EBC);

EXTERN_C void func_80034F24(S_80034F24 *p, int a)
{
    p->unk6 = (p->unk6 & 0xFF9F) | ((a & 3) << 5);
}

EXTERN_C int func_80034F40(S_80034F40 *p)
{
    return (p->unk6 >> 5) & 3;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034F54);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800351A4);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003525C);

EXTERN_C int func_800352D4()
{
    return 0;
}

EXTERN_C int func_800352DC(S_800352DC *p)
{
    return p->unk4;
}

EXTERN_C void func_800352E8(S_800352DC *p, int v)
{
    p->unk4 = v;
}

EXTERN_C S_Vobj *func_800352F0(S_Vobj *p)
{
    p->vtbl = D_80011FE4;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035304);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035384);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003546C);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003556C);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035678);

EXTERN_C void func_800356F4(void *p)
{
    func_80035384(p);
    ((void (*)(void *))func_80035B5C)(p ? (char *)p + 0x24 : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003572C);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800357E0);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003585C);

EXTERN_C int func_800358D4(S_800358D4 *p)
{
    return p->unk1C;
}

EXTERN_C void func_800358E0(void *p)
{
    func_8001AA68(p ? (char *)p + 8 : 0, 0);
}

EXTERN_C void func_80035910(void *p)
{
    func_8001AB50(p ? (char *)p + 8 : 0, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035940);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003598C);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035A28);

EXTERN_C void func_80035AB0(void *p, int a)
{
    AT(p, void **, 0) = D_80012154;
    if (a & 1)
        operator delete(p);
}

EXTERN_C void func_80035AE4()
{
}

EXTERN_C int func_80035AEC()
{
    return 0;
}

EXTERN_C void *func_80035AF4(void *p, int a, short c)
{
    if (a) {
        char *b = (char *)p + 8;
        AT(p, void *, 4) = b;
        AT(p, short, 8) = 16;
        AT(b, short, 2) = c;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_80012154;
    return p;
}

EXTERN_C void func_80035B28(void *p, int a)
{
    AT(p, void **, 0) = D_800121AC;
    if (a & 1)
        operator delete(p);
}

EXTERN_C void func_80035B5C()
{
}

EXTERN_C void *func_80035B64(void *p, int a, short c)
{
    if (a) {
        char *b = (char *)p + 8;
        AT(p, void *, 4) = b;
        AT(p, short, 8) = 16;
        AT(b, short, 2) = c;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_800121AC;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035B98);

EXTERN_C void func_80035BF0()
{
}

EXTERN_C void func_80035BF8()
{
    CdInit();
    func_80035CD8();
    func_800375E4();
}

EXTERN_C void func_80035C28()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035C30);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035CA8);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035CD8);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035CF8);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035D4C);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035DE0);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035E4C);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035EB4);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035F18);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035F80);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036000);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036090);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036110);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800361C8);

EXTERN_C void func_8003635C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036364);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036554);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036674);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800366F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036780);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036850);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036D8C);

EXTERN_C void *func_80036EB8(void *p, void *q)
{
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036EC0);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036F14);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036F54);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036FC0);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800370D0);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003714C);

EXTERN_C int func_80037258(S_80037258 *p)
{
    return p->unk28;
}

EXTERN_C void func_80037264()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC854)->p, 0);
}

EXTERN_C void func_8003728C()
{
    AT(&D_800AC854, void *, 0) = (char *)&D_800AC854 + 4;
    func_800198E0((char *)&D_800AC854 + 4, 4, 0);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_8001231C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_8001232C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_80012354);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_80012364);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_8001237C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_800123EC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_80012404);
