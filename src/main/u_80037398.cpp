#include "common.h"
#define EXE_H_IN_u_80037398
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

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
    CdReadyCallback(0);
    *AT(p, unsigned short *, 4) |= 1;
    AT(p, char, 0x37) = 1;
}

EXTERN_C void func_80037440(void *p, int flags)
{
    AT(p, void **, 8) = D_80012364;
    AT(p, void **, 0) = D_8001237C;
    char *b = p ? (char *)p + 8 : 0;
    char *g = D_800A4544;
    func_8001D324(g, func_8001D25C(g, (int)b));
    AT(p, void **, 8) = D_80012294;
    D_800B4D0C = 0;
    AT(p, void **, 0) = D_80012224;
    func_80035304(p, 0);
    if (flags & 1) delete (char *)p;
}

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

EXTERN_C void func_80037554(void *p, unsigned char a)
{
    if (!AT(p, signed char, 0x37)) f3635C_alt(p, a);
}

// func_80036554 takes three arguments; retail passes two here and leaves $a2 as it is.
EXTERN_C void func_80036554_2(void *p, unsigned char a) asm("func_80036554");

EXTERN_C void func_80037584(void *p, unsigned char a)
{
    if (!AT(p, signed char, 0x37))
        func_80036554_2(p, a);
}

EXTERN_C int func_800375B4(void *p)
{
    if (AT(p, signed char, 0x37))
        return 0;
    return func_80036850(p);
}

EXTERN_C void func_800375E4()
{
    char *g = D_800A4544;
    char *o = (char *)&D_800AC86C;
    if (!func_8001D25C(g, (int)(o ? o + 8 : 0))) {
        void *k = o ? o + 8 : 0;
        func_8001D150(g, new S_A2_X44764(k));
    }
}

EXTERN_C void *func_80037688(void *p)
{
    AT(p, void **, 0) = D_80011FE4;
    AT(p, void **, 8) = D_800123EC;
    AT(p, void **, 0) = D_80012404;
    AT(p, int, 0x10) = 0;
    AT(p, int, 0x14) = 0;
    AT(p, int, 0x18) = 0;
    AT(p, int, 0x1C) = 0;
    AT(p, int, 0x28) = 0;
    AT(p, int, 0x2C) = 1;
    return p;
}

static inline void *a2_ctor44(void *p)
{
    char *b = (char *)p + 0x3C;
    AT(p, void *, 4) = b;
    AT(p, short, 0x3C) = 16;
    AT(b, short, 2) = 0;
    AT(b, int, 4) = -1;
    AT(p, void **, 0) = D_80012154;
    AT(p, void **, 8) = D_8001201C;
    AT(p, void **, 0) = D_80012034;
    AT(p, void *, 0xC) = (char *)p + 0x10;
    ((int (*)(void *, int, int))func_800198E0)((char *)p + 0x10, 4, 0);
    AT(p, void **, 8) = D_80012294;
    AT(p, void **, 0) = D_80012224;
    AT(p, void **, 8) = D_80012364;
    AT(p, int, 0x28) = 0;
    AT(p, int, 0x2C) = 0;
    AT(p, void **, 0) = D_8001237C;
    AT(p, char, 0x37) = 0;
    return p;
}
extern "C++" int f376D0(void *p) asm("func_800376D0");
int f376D0(void *p)
{
    if (D_800B4D0C || AT(p, int, 0x14)) return 0;
    AT(p, int, 0x28) = AT(p, int, 0x28) + 1;
    func_800279A8();
    if (AT(p, void *, 0x1C)) __builtin_vec_delete(AT(p, void *, 0x1C));
    AT(p, void *, 0x1C) = __builtin_vec_new(0x1000);
    AT(p, int, 0x20) = 0;
    AT(p, int, 0xC) = 0;
    void *o = a2_ctor44(operator new(0x44));
    AT(p, void *, 0x14) = o;
    func_80035CF8();
    func_80035CD8();
    func_80036FC0(AT(p, void *, 0x14), 0x708, 0x1000);
    func_8003546C(AT(p, void *, 0x14), (int)p);
    func_8003714C(AT(p, void *, 0x14));
    return 1;
}

EXTERN_C void func_80037834(void *p)
{
    A2VObj0 *q = AT(p, A2VObj0 *, 0x14);
    if (q) {
        q->v04(3);
        AT(p, void *, 0x14) = 0;
    }
    if (AT(p, void *, 0x1C)) {
        __builtin_vec_delete(AT(p, void *, 0x1C));
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

EXTERN_C void func_80037934(void *p)
{
    int r = func_8009C9C0();
    if (r & 0x10)
        AT(p, int, 0xC) = 9;
    else if (r & 2) {
        if (AT(p, int, 0xC) == 15 && AT(p, int, 0x24))
            AT(p, int, 0xC) = 14;
        else
            AT(p, int, 0xC) = 4;
    } else {
        AT(p, int, 0xC) = 0xB;
        AT(p, int, 0x24) = 600;
        CdControl(6, 0, 0);
    }
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80037398", func_80037AAC);

EXTERN_C int func_800382A4(void *p, int a, int b)
{
    if (!AT(p, int, 0xC) && func_800376D0(p)) {
        AT(p, int, 0x10) = a;
        AT(p, int, 0x18) = b;
        return AT(p, int, 0x1C);
    }
    func_8001EAAC(D_800B4C18);
    return 0;
}

EXTERN_C void func_8003831C(void *p, int m)
{
    if (AT(p, void *, 0x14)) {
        if (!(m & 0x10)) {
            if (m & 2) AT(p, int, 0xC) = 0xA;
            else AT(p, int, 0xC) = 4;
        } else AT(p, int, 0xC) = 9;
        return;
    }
    switch (AT(p, int, 0xC)) {
    case 0:
        if (!AT(p, int, 0x2C) && !(m & 0x10)) return;
        func_80035CF8();
        func_800376D0(p);
        return;
    case 7:
        AT(p, int, 0xC) = 9;
    }
    void *o = a2_ctor44(operator new(0x44));
    AT(p, void *, 0x14) = o;
    func_80035CF8();
    func_80035CD8();
    func_80036FC0(AT(p, void *, 0x14), 0x708, 0x1000);
    func_8003546C(AT(p, void *, 0x14), (int)p);
    ((A2VObj0 *)AT(p, void *, 0x14))->v02();
}

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

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012484);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001252C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001257C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012594);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001260C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001262C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001265C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012674);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800126DC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800126F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012714);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012724);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001276C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001277C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012794);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800127AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800127D4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800127E4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800127FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012814);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012864);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001287C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001289C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800128CC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012944);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001295C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012974);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001298C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_8001299C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800129AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800129C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_800129FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80037398", D_80012A18);
