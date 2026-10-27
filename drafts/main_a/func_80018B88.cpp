// func_80018B88: heap init. Retail reaches D_800EA8A0 (heap start, past the EXE) with assembler macros:
// `la $a0` (lui/addiu $a0) and `sw $zero, D_800EA8A0` (lui $at). Declared 8 bytes it gets $gp here
// (tools/maspsx_extern.py registers the .extern); declared bigger/incomplete GCC splits with $v0; an absolute
// constant folds to lui/ori. Same logic otherwise. func_800192C0 has the same problem with D_800B4C34.
struct S_Block { S_Block *next; unsigned int size; };
struct S_800EA8A0;
extern "C" S_Block *D_800B4EE8;
extern "C" char *D_800B4EEC;
extern "C" S_800EA8A0 D_800EA8A0;
extern "C" int D_800B4C08[];
extern "C" void func_8001ACB4();

extern "C" void func_80018B88()
{
    S_Block *b = (S_Block *)&D_800EA8A0;
    D_800B4EE8 = b;
    ((S_Block *)&D_800EA8A0)->next = 0;
    b->size = (D_800B4C08[0] - 0x7FF80000 - (int)b) & ~7;
    D_800B4EEC = (char *)b + b->size;
    func_8001ACB4();
}
