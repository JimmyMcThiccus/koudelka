// func_8007E684 (vbase ctor, ~42 differing): retail computes a0 = self+0x4B0 right after the vbase vtable block (before the vtable stores) and runs the final 16x4 int loop unreduced (addu v1,s1,zero; sw -1,0x10C(v1)); we sink the address to its use and strength-reduce the loop.
#include "common.h"
EXTERN_C void *func_800787C4_c(void *self, int in_chrg, void *a2, int b, int c) asm("func_800787C4");
EXTERN_C void *func_800803E8_c(void *self) asm("func_800803E8");
EXTERN_C void *func_80080468_c(void *self) asm("func_80080468");
EXTERN_C void func_800DA874(void);
EXTERN_C void func_800DBB94(void);
EXTERN_C void func_800DCEB4(void);
EXTERN_C void *D_800171C0_a[] asm("D_800171C0");
EXTERN_C void *D_800171D0_a[] asm("D_800171D0");
EXTERN_C void *D_80017360_a[] asm("D_80017360");
EXTERN_C void *func_8007E684_d(S_8008B30C *self, int in_chrg, void *a2) asm("func_8007E684");
struct T6_7E684 { void *vt; int n; int a, b, c, d; };
struct T4_7E684 { void *vt; int n; int c, d; };
EXTERN_C int D_800AF470_a[] asm("D_800AF470");
EXTERN_C int D_800AF474_a[] asm("D_800AF474");
//HDR_END
EXTERN_C void *func_8007E684_d(S_8008B30C *self, int in_chrg, void *a2)
{
    if (in_chrg) {
        FIELD_AT(self, void *, 0xF8) = (char *)self + 0x56C;
        S_VBobjB *vo = (S_VBobjB *)((char *)self + 0x56C);
        vo->vptr = D_80010178;
        vo->unk4 = 0;
        vo->vptr = D_800104A8;
    }
    func_800787C4_c(self, 0, a2, 2, 0x800);
    FIELD_AT(self, S_VBB *, 0xF8)->vt = (VEntB *)D_800170F0.e;
    if (!in_chrg) {
        VTabB50 vt = D_800170F0;
        FIELD_AT(self, S_VBB *, 0xF8)->vt = vt.e;
        char *full;
        int adj;
        vt.e[1].d = D_800170F0.e[1].d + (adj = (char *)self - (full = FIELD_AT(self, char *, 0xF8) - 0x56C));
        vt.e[6].d = D_800170F0.e[6].d + adj;
    }
    char *m4b0 = (char *)self + 0x4B0;
    FIELD_AT(self, void **, 0x8C) = D_80017160;
    FIELD_AT(self, void **, 0xFC) = D_800171E0;
    FIELD_AT(self, void **, 0x100) = D_80017140;
    FIELD_AT(self, void **, 0x0) = D_80017178;
    {
        T6_7E684 *q = (T6_7E684 *)((char *)self + 0x430);
        q->vt = D_80010178;
        q->n = 0;
        q->vt = D_80017360_a;
        q->a = 0; q->b = 0; q->c = 0; q->d = 0;
    }
    {
        Q4_8007C55C *q = (Q4_8007C55C *)((char *)self + 0x458);
        q->a = 0; q->b = 0; q->c = 0; q->d = 0;
    }
    FIELD_AT(self, int, 0x498) = 0;
    FIELD_AT(self, int, 0x49C) = 0;
    FIELD_AT(self, void * volatile, 0x4A0) = D_80010178;
    FIELD_AT(self, int, 0x4A4) = 0;
    FIELD_AT(self, void * volatile, 0x4A0) = D_800171C0_a;
    func_800803E8_c(m4b0);
    func_80080468_c((char *)self + 0x4F0);
    {
        T4_7E684 *q = (T4_7E684 *)((char *)self + 0x54C);
        q->vt = D_80010178;
        q->n = 0;
        q->vt = D_800171D0_a;
        q->c = -1;
        q->d = 0;
    }
    int g = D_800AF474_a[0];
    D_800AF470_a[0] = (int)self;
    FIELD_AT(self, void *, 0x104) = self;
    FIELD_AT(self, int, 0x214) = 0;
    FIELD_AT(self, int, 0x218) = 0;
    FIELD_AT(self, int, 0x21C) = 0;
    FIELD_AT(self, int, 0x20C) = -1;
    FIELD_AT(self, int, 0x210) = 0;
    FIELD_AT(self, int, 0x55C) = 0;
    if (g != 0) {
        func_800DA874();
        func_800DBB94();
        func_800DCEB4();
    }
    FIELD_AT(self, int, 0x560) = 0;
    FIELD_AT(self, int, 0x568) = 0;
    func_8007FE1C(self, 0);
    int i = 0;
    int *p = (int *)self;
    do {
        p[0x43] = -1;
        p[0x44] = -1;
        p[0x45] = -1;
        p[0x46] = -1;
        i++;
        p += 4;
    } while (i < 0x10);
    return self;
}
