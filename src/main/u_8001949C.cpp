#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C int func_8001949C(S_8001949C *p)
{
    return p->unkC;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001949C", func_800194A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001949C", main);

INCLUDE_ASM("asm/main/nonmatchings/u_8001949C", func_80019648);

INCLUDE_ASM("asm/main/nonmatchings/u_8001949C", func_800196C8);

EXTERN_C void func_80019820()
{
    func_8001D024(&D_800B4C00, 2);
}

EXTERN_C void func_80019848()
{
    func_80019648(&D_800B4C00);
}
