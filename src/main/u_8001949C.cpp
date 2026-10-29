#include "common.h"
#define EXE_H_IN_u_8001949C
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8001949C.h"

EXTERN_C int func_8001949C(S_8001949C *p)
{
    return p->unkC;
}

EXTERN_C void func_800194A8(S_80019158 *p, int flags)
{
    p->vt = D_800100D0;
    if (&p->h == D_800B4C34)
        D_800B4C34 = 0;
    func_80019920((List *)p->h.vb, 0);
    func_8001DF58(&p->unk20, 2);
    own_dtor_800194A8(&p->m18);
    own_dtor_800194A8(&p->m10);
    if (flags & 1)
        operator delete(p);
}

int main()
{
    func_8001B424();
    void *mem = operator new(0x3B4);
    void *p = func_8001B46C_s(mem, 1, S_Size(320, 240), 3, 0x1000);
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

EXTERN_C int func_800196C8()
{
    void *o;
    char *r;
    func_8008B6B0(D_800A457C, 0x8000, 0);
    o = D_800B4C18_lui;
    func_8001E848(o, func_80044BE4(operator new(0x330)));
    o = D_800B4C18_lui;
    func_8001E848(o, func_80051C3C(operator new(0x12C), GAME_800196C8));
    o = D_800B4C18_lui;
    func_8001E848(o, func_8007E684(operator new(0x574), 1, GAME_800196C8));
    o = D_800B4C18_lui;
    r = func_8006A82C(operator new(0x2F0), 1, GAME_800196C8);
    func_8001E848(o, r ? r + 0x124 : 0);
    o = D_800B4C18_lui;
    func_8001E848(o, func_8005584C(operator new(0x679C), GAME_800196C8));
    return 1;
}

EXTERN_C void func_80019820()
{
    func_8001D024(&D_800B4C00, 2);
}

EXTERN_C void func_80019848()
{
    func_80019648(&D_800B4C00);
}
