// func_800C6154: 125 differing, 504-528 vs 556 bytes. Control flow now matches retail (0x10 path first, 32D4 test, 8000/2000 chain, shared jal tails); open: (1) p lands in s2/q in s0 where retail has p=s0/q=s1, (2) the 24AC arg chain: retail keeps (t&0xFF)==0x3F with an explicit andi and duplicates the a0 setup per path, ours folds both, (3) retail recomputes p+0x2524 per call (we CSE it).
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"
struct Unk_800C6154_r { char pad0[0x1A]; unsigned char unk1A; unsigned char unk1B; char pad1C[0x6F]; unsigned char unk8B; };
struct Unk_800C6154_i { int unk0; int unk4; };
struct Unk_800C6154 { char pad0[0x1C]; Unk_800C6154_i unk1C; char pad24[0x18]; void* unk3C; char pad40[0x28]; signed char unk68[1]; char pad69[0x1C87]; unsigned short unk1CF0; char pad1CF2[6]; int unk1CF8; char pad1CFC[0x15D8]; int unk32D4; };
EXTERN_C void func_800D103C_a(void*, void*) asm("func_800D103C");
EXTERN_C void func_800D56BC_a(void*, int) asm("func_800D56BC");
EXTERN_C int func_800C6154(Unk_800C6154* p, Unk_FlagArg* q) {
    if (!func_8005618C(q) && p->unk1CF8) {
        unsigned f = q->unk18;
        if (p->unk32D4) {
            int i, j;
            if (f & 0x10) {
                Unk_800C6154_i* s = &p->unk1C;
                i = s->unk4;
                if (i < 1) {
                    return 1;
                }
                s->unk4 = func_80058270(p->unk3C, -1);
                j = i - 1;
            } else {
                if (!(f & 0x40)) {
                    return 1;
                }
                Unk_800C6154_i* s = &p->unk1C;
                i = s->unk4;
                j = i + 1;
                if ((int)p->unk1CF0 <= j) {
                    return 1;
                }
                s->unk4 = func_80058270(p->unk3C, 1);
            }
            func_800C66D4((Unk_800C66D4*)p, i, j);
            func_8005556C((void*)2, 1);
        } else {
            if (f & 0x8000) {
                p->unk32D4 = 1;
            } else if (f & 0x2000) {
                    Unk_800C6154_r* r = (Unk_800C6154_r*)func_80061188(D_800B4DD0[0], p->unk68[p->unk1C.unk4]);
                    func_800D103C_a((char*)p + 0x3070, r);
                    unsigned t = r->unk1B;
                    if (t - 0xC > 3 && !(((t - 1) & 0xFF) < 0xB || t == 0x3F || ((t - 0x44) & 0xFF) < 8)) {
                        func_80054094((char*)p + 0x24AC, 1);
                    } else {
                        func_80054094((char*)p + 0x24AC, 0);
                    }
                    if (r->unk8B >> 7 == 1) {
                        func_80054094((char*)p + 0x2358, 1);
                        func_80054094((char*)p + 0x2524, 1);
                    } else {
                        func_80054094((char*)p + 0x2358, r->unk1A != 0);
                        func_80054094((char*)p + 0x2524, 0);
                    }
                    func_800D56BC_a((char*)p + 0x2524, p->unk68[p->unk1C.unk4]);
                    func_800631D4((char*)p + 0x22E8);
            } else {
                func_80068F3C(p, q);
            }
        }
    }
    return 1;
}
