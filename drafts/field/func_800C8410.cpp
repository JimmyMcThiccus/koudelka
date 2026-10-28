// func_800C8410: 9 differing: scheduling/register choice around the two Unk_Pt(0x60,4) temporaries in the i<4 loop. Untried: the c1..c7 local-constants trick that matched func_800C7230.
#include "field/field.h"

struct Unk_800C8410_e50 { char pad0[0x50]; };
struct Unk_800C8410_e1C { char pad0[0x1C]; };
struct Unk_800C8410 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; int unk68; int unk6C; Unk_800C8410_e50 unk70[8]; Unk_800C8410_e1C unk2F0[8]; Unk_800C8410_e1C unk3D0[8]; int unk4B0; int unk4B4; int unk4B8; int unk4BC; char unk4C0[0x50]; char unk510[0x1C]; char unk52C[0x1C]; char unk548[0x1C]; char unk564[4]; char pad568[0xA4]; Unk_VbObj vobj; };
EXTERN_C void* func_80054B98(void*);
EXTERN_C void* func_800CCD24(void*, int);
EXTERN_C char D_800B7D54[];
EXTERN_C char D_800B7D68[];
EXTERN_C char D_800B7D78[];
EXTERN_C char D_800B7D90[];
EXTERN_C char D_800B7DA4[];
EXTERN_C char D_800B7DB8[];
EXTERN_C char D_800B7DC8[];
EXTERN_C char D_800B7DDC[];
EXTERN_C char D_800B7DF0[];
EXTERN_C char D_800B7E04[];
EXTERN_C Unk_800C8410* func_800C8410(Unk_800C8410*, int);

EXTERN_C Unk_800C8410* func_800C8410(Unk_800C8410* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_800630BC(self, 0, 3);
    self->vb->vptr = (Unk_VTbl10*)&D_800B7E1C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B7E1C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B7E1C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x60C));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B7E1C).e[6].delta + adj;
    }
    self->vt54 = D_800B7E8C;
    self->vt58 = D_800B7E6C;
    self->vt18 = D_800B7EBC;
    self->unk68 = 0;
    self->unk6C = 0;
    {
        Unk_800C8410_e50* q = self->unk70;
        int n = 7;
        for (; n != -1; n--) {
            func_80054B98(q);
            q++;
        }
    }
    {
        Unk_800C8410_e1C* q = self->unk2F0;
        int n = 7;
        for (; n != -1; n--) {
            func_80053928(q);
            q++;
        }
    }
    {
        Unk_800C8410_e1C* q = self->unk3D0;
        int n = 7;
        for (; n != -1; n--) {
            func_80053928(q);
            q++;
        }
    }
    self->unk4B8 = 0;
    self->unk4BC = 0;
    func_80054AF0(self->unk4C0, 1);
    func_80053928(self->unk510);
    func_800538CC(self->unk52C, D_800B7D54, 8);
    func_800538CC(self->unk548, D_800B7D68, 6);
    func_800CCD24(self->unk564, 1);
    func_800C88D8((Unk_800C88D8*)self);
    self->unk4B0 = 0;
    self->unk4B4 = 0;
    func_80055020(self->unk4C0, Unk_Pt(8, 0xC));
    func_80054EB4(self->unk4C0, 0x130, 0x10);
    func_80054E18(self->unk4C0, self->unk510);
    for (unsigned i = 0; i < 4; i++) {
        func_80054EB4(&self->unk70[i], 0x64, 0x16);
        func_80053F48(&self->unk70[i], Unk_Pt(0xD2, 0x86 + i * 0x18));
        func_8005408C(&self->unk2F0[i], 2);
        func_80053F48(&self->unk2F0[i], Unk_Pt(0x60, 4));
        func_80054E18(&self->unk70[i], &self->unk2F0[i]);
        func_80054EB4(&self->unk70[i + 4], 0x68, 0x16);
        func_80053F48(&self->unk70[i + 4], Unk_Pt(0xD0, 0x1E + i * 0x18));
        func_8005408C(&self->unk2F0[i + 4], 2);
        func_80053F48(&self->unk2F0[i + 4], Unk_Pt(0x60, 4));
        func_80054E18(&self->unk70[i + 4], &self->unk2F0[i + 4]);
    }
    func_80053BCC(&self->unk3D0[0], (int)D_800B7D78, 0xA);
    func_80053BCC(&self->unk3D0[1], (int)D_800B7D90, 9);
    func_80053BCC(&self->unk3D0[2], (int)D_800B7DA4, 9);
    func_80053BCC(&self->unk3D0[3], (int)D_800B7DB8, 7);
    func_80053BCC(&self->unk3D0[4], (int)D_800B7DC8, 8);
    func_80053BCC(&self->unk3D0[5], (int)D_800B7DDC, 8);
    func_80053BCC(&self->unk3D0[6], (int)D_800B7DF0, 8);
    func_80053BCC(&self->unk3D0[7], (int)D_800B7E04, 9);
    func_80054EB4(self, 0x54, 0x21);
    func_80053F48(self->unk548, Unk_Pt(9, 2));
    func_80053F48(self->unk52C, Unk_Pt(9, 0xF));
    func_80054E18(self, self->unk548);
    func_80054E18(self, self->unk52C);
    return self;
}
