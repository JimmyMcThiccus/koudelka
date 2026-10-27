// func_80028F10 / func_80028F58 / func_80028B90 / func_80028C08 / func_80028C80 / func_80028D10 / func_80028AE8 /
// func_80028A24 / func_80028DC4 / func_800288D0 / func_80029414 / func_8002900C (u_80028428): blocked on how
// D_800B4CF0 (the 0/1 double-buffer index) is reached. In this unit retail uses the assembler-macro form
// `lui $vN; lw $vN, %lo(D_800B4CF0)($vN)` (no $gp, lui re-done at every access, never in a delay slot), i.e. GCC
// saw a small object but ASPSX did not use $gp. tools/maspsx_extern.py puts every small .extern on $gp, and a
// >8-byte declaration makes GCC split %hi/%lo itself (CSEd, schedulable). Needs a tools change (e.g. a per-unit
// list of small externs to keep off $gp). Body of func_80028F10 for reference:
EXTERN_C int func_80028F10(S_80028F10 *p)
{
    int i;
    if (p->unk8 == 1)
        i = D_800B4CF0.value ^ 1;
    else
        i = D_800B4CF0.value;
    return p->e[i].unk38;
}
