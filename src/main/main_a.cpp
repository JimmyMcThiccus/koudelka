#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C S_800186B0 *func_800186B0(S_800186B0 *s)
{
    s->p = s->data;
    func_800198E0(s->data, 2, 0);
    return s;
}

EXTERN_C void func_800186E8(Holder *h)
{
    if (++D_800B4BFC == 1) {
        func_80094990();
        for (int i = 0; i < count_of(h); i++)
            func_80019F64(h, i)->run();
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018788);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018840);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800188D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018970);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018A20);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018A58);

EXTERN_C void func_80018A88()
{
    func_800186E8(&D_800A451C);
}

EXTERN_C void func_80018AAC()
{
    func_80018788(&D_800A451C);
}

EXTERN_C void func_80018AD0()
{
    func_80018840(&D_800A451C);
}

EXTERN_C void func_80018AF4()
{
    func_800188D4(&D_800A451C);
}

EXTERN_C void func_80018B18()
{
    func_80018970(&D_800A451C);
}

EXTERN_C void func_80018B3C()
{
    func_80019920((List *)((S_800186B0 *)&D_800A451C)->p, 0);
}

EXTERN_C void func_80018B64()
{
    func_800186B0((S_800186B0 *)&D_800A451C);
}
