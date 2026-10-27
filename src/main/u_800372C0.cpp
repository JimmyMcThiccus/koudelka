#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

EXTERN_C int func_800372C0(S_800372C0 *p)
{
    return p->unk2C + p->unk4->unk4;
}

EXTERN_C int func_800372D4(S_80037258 *p)
{
    return p->unk2C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800372E0);

EXTERN_C int func_80037380()
{
    return D_800B4D0C;
}

EXTERN_C int func_8003738C(void *p, int a)
{
    return (a & 0x1D) != 0;
}

EXTERN_C void func_80037398(void *p, int flags)
{
    AT(p, void **, 8) = D_80012294;
    AT(p, void **, 0) = D_80012224;
    func_80035304(p, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void func_800373F8(void *p)
{
    func_8009CAE0(0);
    *AT(p, unsigned short *, 4) |= 1;
    AT(p, char, 0x37) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037440);

EXTERN_C void func_800374F4(void *p)
{
    if (!AT(p, signed char, 0x37))
        func_800361C8(p);
}

EXTERN_C void func_80037524(void *p, unsigned char a)
{
    if (!AT(p, signed char, 0x37))
        func_80036364(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037554);

EXTERN_C void func_80037584(void *p, unsigned char a)
{
    if (!AT(p, signed char, 0x37))
        func_80036554(p, a);
}

EXTERN_C int func_800375B4(void *p)
{
    if (AT(p, signed char, 0x37))
        return 0;
    return func_80036850(p);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800375E4);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037688);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800376D0);

EXTERN_C void func_80037834(void *p)
{
    A2VObj0 *q = AT(p, A2VObj0 *, 0x14);
    if (q) {
        q->v04(3);
        AT(p, void *, 0x14) = 0;
    }
    if (AT(p, void *, 0x1C)) {
        func_800A0D0C(AT(p, void *, 0x1C));
        AT(p, void *, 0x1C) = 0;
    }
    func_800376D0(p);
}

EXTERN_C int func_800378A8(void *p)
{
    int r;
    switch (AT(p, int, 0xC)) {
    case 2:
        r = 3;
        break;
    case 15:
        r = 0x10;
        break;
    default:
        if (strncmp(AT(p, char *, 0x1C), D_80012354, 14))
            r = 4;
        else if (AT(p, signed char *, 0x1C)[14] == AT(p, int, 0x10) + '0' || !AT(p, int, 0x10))
            r = 0x11;
        else
            r = 1;
        break;
    }
    return AT(p, int, 0xC) = r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037934);

EXTERN_C int func_800379D0(void *p)
{
    int r;
    switch (AT(p, int, 0xC)) {
    case 2:
        r = D_8001232C[AT(p, int, 0x10)].b;
        break;
    case 15:
        r = 0x800;
        break;
    default:
        r = 0x1000;
        break;
    }
    return r;
}

EXTERN_C char *func_80037A20(A2VObj0 *p, int n)
{
    char *r;
    unsigned int end;
    int off;
    if (!AT(p, char *, 0x1C))
        return 0;
    end = AT(p, int, 0x20) + n;
    if ((unsigned int)p->v05() < end)
        return 0;
    off = AT(p, int, 0x20);
    r = AT(p, char *, 0x1C) + off;
    AT(p, int, 0x20) = off + n;
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037AAC);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800382A4);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_8003831C);

EXTERN_C void func_800384C4()
{
    char *o = (char *)&D_800AC86C;
    AT(o, void **, 8) = D_800123EC;
    AT(o, void **, 0) = D_80012404;
    func_8001D024(o + 8, 0);
}

EXTERN_C void func_80038508()
{
    func_80037688(&D_800AC86C);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012484);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001252C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001257C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012594);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001260C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001262C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001265C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012674);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800126DC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800126F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012714);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012724);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001276C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001277C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012794);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800127AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800127D4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800127E4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800127FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012814);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012864);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001287C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001289C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800128CC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012944);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001295C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012974);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001298C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001299C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800129AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800129C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800129FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012A18);
