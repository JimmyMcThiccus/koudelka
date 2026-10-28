// func_800E6AC4: 10 differing: register numbering in the second loop (retail i=s1, 0xAC offset=s5, src=s4, 0x100 offset=s3).
#include "field/field.h"

struct Unk_E6AC4_s { char pad0[0xA0]; int unkA0; char pad[0x33]; unsigned char unkD7; char padD8[7]; signed char unkDF; int unkE0; unsigned char unkE4; signed char unkE5; signed char unkE6[1]; };
struct Unk_E6AC4_s2 { char pad0[0x19A0]; signed char unk19A0; };
struct Unk_E6AC4 { char pad0[0x1C]; Unk_800BFB64_list l1C; char pad20[0x30]; int unk50; char pad54[4]; signed char unk58; char pad59; signed char unk5A; signed char unk5B; char pad5C[0x44]; int unkA0; int unkA4; signed char unkA8; char padA9[0x53]; char unkFC[4]; char unk100[0x28 * 8]; };
EXTERN_C char D_800BA298[];
EXTERN_C void func_800E6AC4_i(Unk_E6AC4* self, Unk_E6AC4_s* src, int flag) asm("func_800E6AC4");

EXTERN_C void func_800E6AC4_i(Unk_E6AC4* self, Unk_E6AC4_s* src, int flag) {
    if (self->unkA0 == 0) {
        int t = (self->unk5A - 0x30) * 10 - 0x30;
        self->unkA0 = t + self->unk5B;
    }
    int a;
    if (flag) {
        self->unkA4 = src->unkE0;
        self->unkA8 = src->unkE4;
        a = src->unkE5;
    } else {
        self->unkA4 = src->unkA0;
        self->unkA8 = src->unkD7;
        a = src->unkDF;
    }
    func_800E675C((Unk_800E675C*)self, a);
    func_80019D40(first(&self->l1C));
    char* t = (char*)self + 0x228;
    func_80054094(self, 0);
    self->unk50 = 0;
    func_8005457C(t, 0);
    func_80053BCC(t, (int)D_800BA298, 4);
    func_80053F48(t, Unk_Pt(0x9C, 0x12));
    int s = self->unkA4;
    func_800E6F14((Unk_800E6F14*)self, s);
    func_80054708((char*)self + 0x178, s % 60);
    s = s / 60;
    if (func_800549D8((char*)self + 0x178) >= 10) {
        func_80053CD8((char*)self + 0x1F0);
    } else {
        func_80053BCC((char*)self + 0x1F0, (int)D_800B4D6C, 1);
    }
    func_80054708((char*)self + 0x1A0, s % 60);
    if (func_800549D8((char*)self + 0x1A0) >= 10) {
        func_80053CD8((char*)self + 0x20C);
    } else {
        func_80053BCC((char*)self + 0x20C, (int)D_800B4D6C, 1);
    }
    func_80054708((char*)self + 0x1C8, s / 60);
    func_80054E18(self, (char*)self + 0x228);
    func_80054E18(self, (char*)self + 0x178);
    func_80054E18(self, (char*)self + 0x1F0);
    func_80054E18(self, (char*)self + 0x244);
    func_80054E18(self, (char*)self + 0x1A0);
    func_80054E18(self, (char*)self + 0x20C);
    func_80054E18(self, (char*)self + 0x260);
    func_80054E18(self, (char*)self + 0x1C8);
    if (flag) {
        if (self->unkA8) {
        unsigned i = 0;
        do {
            char* q = self->unk100 + i * 0x28;
            func_80054708(q, i[(signed char*)src + 0xE6]);
            func_80054E18(self, q);
            func_80054E18(self, (char*)self + 0xAC + i * 0x1C);
            i++;
        } while (i < self->unkA8);
        }
    } else {
        if (self->unkA8) {
        unsigned i = 0;
        char* r = (char*)src;
        do {
            char* q = self->unk100 + i * 0x28;
            func_80054708(q, ((Unk_E6AC4_s2*)r)->unk19A0);
            r += 0x60;
            func_80054E18(self, q);
            func_80054E18(self, (char*)self + 0xAC + i * 0x1C);
            i++;
        } while (i < self->unkA8);
        }
    }
}
