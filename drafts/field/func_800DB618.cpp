// func_800DB618: 8 differing: addu operand order in the struct-copy loop and order of lw D_800B4DD0 vs the last copied word. Header declares one argument; asm alias.
#include "field/field.h"

struct Unk_E148w { int w[37]; };
struct Unk_800DB618_e { char pad0[0x18]; unsigned char unk18; char pad19[0x72]; unsigned char unk8B; unsigned char unk8C; char pad8D[7]; };
struct Unk_800DB618 { char pad0[0x1C]; Unk_800BFB64_list unk1C; char pad20[0x4C]; Unk_S6C_DB5A4* unk6C; Unk_E148w* unk70; };
EXTERN_C void func_800DB618_i(Unk_800DB618*, Unk_E148w*) asm("func_800DB618");
EXTERN_C void func_80061BF0(void*, void*);
EXTERN_C void func_80054584(void*, int);
EXTERN_C char D_800B97A8[];

EXTERN_C void func_800DB618_i(Unk_800DB618* p, Unk_E148w* a) {
    unsigned n = first(&p->unk1C)->unk4 - 1;
    Unk_E148w* q = &p->unk70[n];
    *q = *a;
    func_80061BF0(D_800B4DD0[0], &p->unk70[n]);
    func_80053BCC(&p->unk6C->unk1C[n], (int)&p->unk70[n] + 0x1C, 0);
    func_800540A8(&p->unk6C->unk1C[n]);
    if (((Unk_800DB618_e*)&p->unk70[n])->unk18 == 4 && (((Unk_800DB618_e*)&p->unk70[n])->unk8B >> 7) != 1) {
        char s[0x20];
        char t[0x28];
        func_800538CC(s, D_800B97A8, 3);
        func_80053DDC(&p->unk6C->unk1C[n], s);
        func_80053964(s, 2);
        func_80054584(t, ((Unk_800DB618_e*)&p->unk70[n])->unk8C);
        func_80053DDC(&p->unk6C->unk1C[n], t);
        func_80053964(t, 2);
    }
    func_80054094(&p->unk6C->unk1C[n], 0);
    func_80054E18(p, &p->unk6C->unk1C[n]);
}
