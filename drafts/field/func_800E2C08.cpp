// func_800E2C08: 4 bytes short: retail keeps the loaded value in v0 (lw v0,0x14C(v0); addu s3,v0,zero; sll v0,v0,24).
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"

struct Unk_hcG { char pad0[0x78]; int unk78; char pad7C[0xC]; void* unk88; char pad8C[0x6C]; char unkF8[4]; char pad_FC[0x18]; char unk114[0x1C]; char unk130[0x28]; int unk158; int unk15C; char pad160[0x2D9C]; signed char unk2EFC; };
struct Unk_hcG_o { char pad0[0x14C]; int unk14C; };
struct Unk_hcG_ow { char pad0[0x328]; Unk_hcG_o* unk328; };
EXTERN_C signed char D_800EA7A4[];
EXTERN_C char D_800B9F38[];
EXTERN_C void* func_800E3B68(void*, int, int, int, int, void*);

EXTERN_C void func_800E2C08(Unk_hcG* p) {
    int found = 0;
    int v = ((Unk_hcG_ow*)func_800787B4())->unk328->unk14C;
    p->unk2EFC = 0;
    signed char c = v;
    while (p->unk2EFC < 10) {
        signed char k = p->unk2EFC;
        if (D_800EA7A4[k] == c) {
            func_800E31B8((Unk_800E31B8*)p);
            found = 1;
        }
        p->unk2EFC++;
        if (found) break;
    }
    if (found) {
        p->unk2EFC--;
    } else {
        p->unk2EFC = v + 0x10;
    }
    func_80062188(D_800B4DD0[0]);
    found = 0;
    func_80053CD8(p->unk114);
    func_80053CD8(p->unk130);
    func_80053CD8(p->unkF8);
    func_80054FC0((char*)p + 0x8C);
    for (unsigned int i = 0; i < 8; i++) {
        func_8005556C(2, 1);
    }
    if (!p->unk88) {
        p->unk88 = func_800E3B68(operator new(0x68), 1, p->unk78, 1, 0, D_800B9F38);
    }
    p->unk158 = 1;
    p->unk15C = 0;
    func_8005549C(0xA, p, 0, -1);
    func_800553D8(0);
}
