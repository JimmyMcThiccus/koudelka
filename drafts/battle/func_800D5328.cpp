// func_800D5328: NOT MATCHING. 174 differ (4 bytes long): virtual-base ctor, structure right (Ghidra-assisted). Ours hoists the 0x82 constant of the first SVec2C(0x82,y) into $fp (a 9th callee-saved reg); retail uses s0-s7 only and rematerialises li 0x82 in the loop.
#include "common.h"
#include "battle/battle.h"
struct T_D5328 { char pad0[0x18]; VTable *vt18; char pad1C[0x34]; T_VBase *vb50; VTable *vt54; VTable *vt58; char pad5C[0xC]; int f68; char b6C[16]; char pad7C[0x654]; T_D3ED0_vb v6D0; };
struct B16_D5328 { char b[16]; };
struct E1C_D5328 { char b[0x1C]; };
struct R8C_D5328 { char pad[0x1F]; unsigned char b1F; char pad20[0x6C]; };
EXTERN_C const T_VTable10 D_800B7F1C;
EXTERN_C VTable D_800B7F6C[], D_800B7F8C[], D_800B7FBC[];
EXTERN_C const char D_800B7ECC[];
EXTERN_C R8C_D5328 D_800AEBD4r[] __asm__("D_800AEBD4");
EXTERN_C char D_800AEBF4[];
EXTERN_C void f630BC_e(void *p, int a, int b) __asm__("func_800630BC");
EXTERN_C void f53928_e(void *p) __asm__("func_80053928");
EXTERN_C void f5464C_e(void *p) __asm__("func_8005464C");
EXTERN_C void f53BCC_e(void *p, void *q, int a) __asm__("func_80053BCC");
EXTERN_C void f540A8_e(void *p) __asm__("func_800540A8");
EXTERN_C void f53C6C_e(void *p, void *q) __asm__("func_80053C6C");
EXTERN_C void f53964_e(void *p, int a) __asm__("func_80053964");
EXTERN_C void f5408C_e(void *p, int a) __asm__("func_8005408C");
EXTERN_C void f53F48_e(void *p, SVec2C v) __asm__("func_80053F48");
EXTERN_C void f54708_e(void *p, int a) __asm__("func_80054708");
EXTERN_C void f63714_e(void *p, int a) __asm__("func_80063714");
EXTERN_C void *func_800D5328(T_D5328 *self, int in_chrg, int a);
//@ func_800D5328 a
EXTERN_C void *func_800D5328(T_D5328 *self, int in_chrg, int a)
{
    if (in_chrg) {
        self->vb50 = (T_VBase *)((char *)self + 0x6D0);
        T_D3ED0_vb *v = (T_D3ED0_vb *)self->vb50;
        v->vptr = D_80010178;
        v->f4 = 0;
        v->vptr = D_800104A8;
    }
    f630BC_e(self, 0, 0x2D);
    self->vb50->vptr = (T_VTable10 *)&D_800B7F1C;
    T_VTable10 vt;
    if (!in_chrg) {
        vt = D_800B7F1C;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B7F1C.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x6D0));
        vt.e[6].delta = D_800B7F1C.e[6].delta + adj;
    }
    self->vt54 = D_800B7F8C;
    self->vt58 = D_800B7F6C;
    self->vt18 = D_800B7FBC;
    self->f68 = a;
    {
        char *e = (char *)self + 0x7C;
        int i = 14;
        do { f53928_e(e); i--; e += 0x1C; } while (i != -1);
    }
    {
        char *e = (char *)self + 0x220;
        int i = 14;
        do { f5464C_e(e); i--; e += 0x28; } while (i != -1);
    }
    {
        char *e = (char *)self + 0x478;
        int i = 14;
        do { f5464C_e(e); i--; e += 0x28; } while (i != -1);
    }
    func_800557C8(self, 0, 6);
    for (unsigned i = 0; i < 15; i++) self->b6C[i] = 0;
    B16_D5328 tbl = *(const B16_D5328 *)D_800B7ECC;
    unsigned n = 0;
    int off = 0x7C;
    for (unsigned i = 0; i < 15; i++) {
        if (func_80062238(D_800B4DD0[0], i)) {
            char *s = (char *)self + n;
            n++;
            s[0x6C] = tbl.b[i];
            E1C_D5328 t;
            f53928_e(&t);
            f53BCC_e(&t, D_800AEBF4 + s[0x6C] * 0x8C + 8, 0);
            f540A8_e(&t);
            f53C6C_e((char *)self + off, &t);
            func_80054E18(self, (char *)self + off);
            off += 0x1C;
            f53964_e(&t, 2);
        }
    }
    {
        unsigned i = 0;
        int o1 = 0x478, o0 = 0x220;
        unsigned short y = 4;
        while (i < n) {
            char *a0 = (char *)self + o0;
            f5408C_e(a0, 2);
            o0 += 0x28;
            f53F48_e(a0, SVec2C(0x82, y));
            func_80054E18(self, a0);
            char *a1 = (char *)self + o1;
            o1 += 0x28;
            f54708_e(a1, D_800AEBD4r[(signed char)self->b6C[i]].b1F);
            i++;
            f5408C_e(a1, 2);
            f53F48_e(a1, SVec2C(0xA2, y));
            func_80054E18(self, a1);
            y += 13;
        }
    }
    f63714_e(self, n);
    func_80054EB4(self, 0xAA, n < 8 ? n * 13 + 8 : 0x70);
    SVec4 v4;
    v4.x = -2; v4.y = 0; v4.z = 2; v4.w = 0;
    func_80054F30(self, 5, &v4, 2);
    return self;
}
