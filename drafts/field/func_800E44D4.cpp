// func_800E44D4: 4 differing. Retail computes (a<<7) into a2 in the beqz delay slot, loads fd/buf, then does `sw p, D_800EA7B0` AFTER the loads and before the `unk50<<7` shift; the build stores the global earlier. Sibling func_800E4448 (landed) takes the offset from func_800E5554.
#include "field/field.h"

struct Unk_800E44D4_s { short unk0; short pad2; int unk4; };
struct Unk_800E44D4 { char pad0[4]; Unk_800E44D4_s* unk4; char pad8[0x2C]; int unk34; char pad38[0xC]; int unk44; char pad48[8]; int unk50; };

EXTERN_C int func_800E44D4(Unk_800E44D4* p, int a) {
    p->unk4->unk0 = 4;
    if (p->unk34 == -1 || D_800EA7B0[0]) {
        return 0;
    }
    int off = (a << 7) + 0x80;
    int n = p->unk50 << 7;
    D_800EA7B0[0] = (int)p;
    read(p->unk34, (void*)p->unk44, n + off);
    p->unk4->unk4 = -1;
    p->unk4->unk0 = 1;
    return 1;
}
