// func_800D82E0: 49 differing: cnt/str swapped (retail cnt=s1, str=s2).
#include "field/field.h"

struct Unk_800D82E0 { char pad0[0x18]; void* vtbl18; char pad1C[0x34]; char unk50[0x1C]; Unk_800D7B6C_a* unk6C; Unk_800D7B6C_a* unk70; Unk_800D7B6C_b* unk74; Unk_800D7B6C_b* unk78; };
EXTERN_C char D_800B9174[];
EXTERN_C Unk_800D7F10_o* func_800D82E0_i(Unk_800D82E0* self, void* str, unsigned n, int w) asm("func_800D82E0");

EXTERN_C Unk_800D7F10_o* func_800D82E0_i(Unk_800D82E0* self, void* str, unsigned n, int w) {
    unsigned cnt = (n - 1 >> 2) + 1;
    func_80054AF0(self, n * 3 + cnt + 1);
    self->vtbl18 = D_800B917C;
    func_800538CC(self->unk50, func_80053BC0(str), 0);
    func_80054EB4(self, 0x130, 0x58);
    int ct = cnt;
    self->unk6C = new Unk_800D7B6C_a[cnt];
    self->unk70 = new Unk_800D7B6C_a[n];
    self->unk74 = new Unk_800D7B6C_b[n];
    self->unk78 = new Unk_800D7B6C_b[n];
    func_80053F48(self->unk50, Unk_Pt(8, 0));
    func_80054E18(self, self->unk50);
    unsigned i;
    for (i = 0; i < ct; i++) {
        func_80053BCC(&self->unk6C[i], (int)D_800B9174, 2);
        func_80053F48(&self->unk6C[i], Unk_Pt(w + 8 + 0x120 / ct * i, 12));
        func_80054E18(self, &self->unk6C[i]);
    }
    unsigned j;
    for (j = 0; j < n; j += 4) {
        int base = 0x120 / ct * (j >> 2) + 8;
        int y = 0x17;
        for (unsigned k = 0; k < 4; k++) {
            unsigned idx = k + j;
            if (idx >= n) break;
            func_80053F48(&self->unk70[idx], Unk_Pt(base, y));
            func_80054E18(self, &self->unk70[idx]);
            func_8005408C(&self->unk74[idx], 2);
            func_80053F48(&self->unk74[idx], Unk_Pt(base + w + 0xC, y));
            func_80054E18(self, &self->unk74[idx]);
            func_8005408C(&self->unk78[idx], 2);
            func_80053F48(&self->unk78[idx], Unk_Pt(base + w + 0x2C, y));
            y += 0xD;
            func_80054E18(self, &self->unk78[idx]);
        }
    }
    return (Unk_800D7F10_o*)self;
}
