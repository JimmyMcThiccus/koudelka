#include "common.h"
#define EXE_H_IN_u_800372C0
#include "shared/exe.h"
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

EXTERN_C void *func_800372E0(void *p, int vb)
{
    if (vb) {
        char *b = (char *)p + 0x3C;
        AT(p, void *, 4) = b;
        AT(p, short, 0x3C) = 16;
        AT(b, short, 2) = 1;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_80012154;
    AT(p, void **, 8) = D_8001201C;
    AT(p, void **, 0) = D_80012034;
    AT(p, void *, 0xC) = (char *)p + 0x10;
    ((int (*)(void *, int, int))func_800198E0)((char *)p + 0x10, 4, 0);
    AT(p, void **, 8) = D_80012294;
    AT(p, void **, 0) = D_80012224;
    AT(p, int, 0x28) = 0;
    AT(p, int, 0x2C) = 0;
    return p;
}

EXTERN_C int func_80037380()
{
    return D_800B4D0C;
}

EXTERN_C int func_8003738C(void *p, int a)
{
    return (a & 0x1D) != 0;
}
