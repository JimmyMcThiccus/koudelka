#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8001949C.h"

EXTERN_C int func_8001949C(S_8001949C *p)
{
    return p->unkC;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001949C", func_800194A8);

int main()
{
    func_8001B424();
    void *mem = operator new(0x3B4);
    void *p = func_8001B46C(mem, 1, S_Size(320, 240), 3, 0x1000);
    D_800A4578[0] = p;
    func_8001E360(p ? (char *)p + 0x50 : 0);
    ResetGraph(1);
    StopCallback();
    return 0;
}

EXTERN_C void *func_80019648(void *p)
{
    *(void ***)p = D_800100E0;
    int *o = D_800A4544;
    func_8001D150(o, new S_8001D684_((int)p, 0xC0, 0));
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001949C", func_800196C8);

EXTERN_C void func_80019820()
{
    func_8001D024(&D_800B4C00, 2);
}

EXTERN_C void func_80019848()
{
    func_80019648(&D_800B4C00);
}
