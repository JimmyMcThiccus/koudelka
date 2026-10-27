// func_8002D1E0: blocked by the small-extern $gp issue (main_b-r2-gp-finding): retail reads D_800B4CF0 twice
// with the assembler macro (`lui $v1; lw $v1, %lo($v1)`). `int D_800B4CF0` gives $gp; the 12-byte struct
// below makes GCC split the address and CSE it into $s0.
struct S_800B4CF0 { int value; int pad[2]; };
EXTERN_C S_800B4CF0 D_800B4CF0;
struct DISPENV { char b[0x14]; };
struct DRAWENV { char b[0x5C]; };
EXTERN_C DISPENV D_800AC7F8[];
EXTERN_C DRAWENV D_800AC740[];
EXTERN_C void PutDispEnv(DISPENV *env);
EXTERN_C void PutDrawEnv(DRAWENV *env);

EXTERN_C void func_8002D1E0()
{
    PutDispEnv(&D_800AC7F8[D_800B4CF0.value]);
    PutDrawEnv(&D_800AC740[D_800B4CF0.value]);
}
