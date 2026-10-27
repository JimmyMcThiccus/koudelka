// func_8002EE40: matches except the store to D_800B4CFC: retail uses the assembler macro without $gp
// (`lui $at; sw $s0, %lo($at)`); `int` gives $gp, arrays/structs/incomplete types give GCC's own lui $v0 split.
EXTERN_C void func_8002EE40(int a)
{
    S_IntVec *v = (S_IntVec *)&D_800AC820;
    func_80019A6C(v, a, v->count);
    D_800B4CFC[0] = a;
}
