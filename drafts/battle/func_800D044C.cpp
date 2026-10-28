// func_800D044C: NOT MATCHING. 21 instructions differ: retail loops 2/3 do not strength-reduce the item pointer (a1+2j recomputed, j in a0), ours does (a1+=2); loop-2 init order s0/s1 differs. Unused 'char unused[8]' reproduces the 0x28 frame.
#include "common.h"
#include "battle/battle.h"
struct T_D044C_e { unsigned char a, b; };
struct T_D044C_i { char pad[0x561]; T_D044C_e e[27]; };
struct T_D044C_B { int pad[2]; T_D044C_i *items[3]; };
struct T_D044C_D : T_D0390_A, T_D044C_B {};
struct T_D044C_G { char pad[0x328]; T_D044C_D *f328; };
struct T_D044C_o { char pad[0x948]; unsigned char b948; };
EXTERN_C void func_80062214(void *p);
//@ func_800D044C a
EXTERN_C void func_800D044C(unsigned char *d) {
    char unused[8];
    func_80062214(D_800B4DD0[0]);
    for (unsigned i = 0; i < 3; i++) {
        if (D_800AFA58[i] && ((T_D044C_o *)D_800AFA58[i])->b948) func_800D0C90((T_D0C90 *)d);
    }
    int off = 0;
    for (unsigned i = 0; i < 3; i++) {
        T_D044C_B *b = ((T_D044C_G *)func_800787B4())->f328;
        T_D044C_i *it = b->items[i];
        for (unsigned j = 0; j < 11; j++) { int t = it->e[j].a; d[j + off] = t >> 2; }
        for (unsigned j = 0; j < 15; j++) { int t = it->e[12 + j].a; d[j + i * 16 + 0x24] = t >> 2; }
        off += 12;
    }
    D_800B4DD0[0]->s1F6 = 0;
}
