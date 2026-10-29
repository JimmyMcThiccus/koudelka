#include "common.h"
#define EXE_H_IN_u_8003148C
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8002ED44.h"

INCLUDE_ASM("asm/main/nonmatchings/u_8003148C", func_8003148C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003148C", func_800318A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003148C", func_80031CE4);

EXTERN_C int *func_8003212C(S_8003212C_P *p, S_8003212C_Q *q, int *out)
{
    func_80030AA8(p, q, out);
    p->c34 = q->c2C;
    return &q->unk30;
}

EXTERN_C void func_80032174()
{
    D_800AC834.a = (int)D_80011E74;
    func_8001D324(D_800A4544, func_8001D25C(D_800A4544, &D_800AC834));
    func_8001D024(&D_800AC834, 2);
}

EXTERN_C void func_800321D8()
{
    char *s;
    D_800AC834.a = (int)D_80011E74;
    s = D_800A4544;
    D_800AC834.c = 0;
    D_800AC834.b = 0;
    D_800AC834.d = 0;
    func_8001D150(s, new S_Timer14(&D_800AC834, 0x40, 0));
}
