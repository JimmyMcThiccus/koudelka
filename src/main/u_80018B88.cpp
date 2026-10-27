#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018B88);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018BE4);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018C1C);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018C90);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018D80);

EXTERN_C int func_80018DF4(int *p)
{
    return p ? p[-1] - 8 : 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018E10);

EXTERN_C S_80018E5C *func_80018E5C(S_80018E5C *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800100C0;
    p->unk88 = 0;
    p->unk8 = a;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018E88);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018EDC);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018F0C);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80018FA8);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_800190A0);

EXTERN_C int func_8001914C(S_8001914C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80019158);

EXTERN_C void func_800191FC()
{
    D_800A4534.unkC++;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_8001921C);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_80019274);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_800192C0);

INCLUDE_ASM("asm/main/nonmatchings/u_80018B88", func_800193AC);

EXTERN_C void func_80019478()
{
    func_80019158(&D_800A4534);
}
