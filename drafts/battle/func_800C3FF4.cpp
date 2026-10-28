// func_800C3FF4: NOT MATCHING. 26 differ (4 bytes short): virtual-base ctor, D3ED0 recipe (explicit in_chrg vtable copy). Retail sets a1=self in the jal delay slot after lw a0,0x44(g) and keeps an unfilled load-delay nop after lw 0x88(sp); ours hoists addu a1,s0 early, so the 4th lhu lands in a2 instead of a1.
#include "common.h"
#include "battle/battle.h"
struct T_C3FF4 { T_VBase *vb0; char pad4[0x28]; VTable *vt2C; char pad30[8]; char f38[8]; VTable *vt40; short h44, h46, h48, h4A; int f4C; int f50; short h54, h56; T_D3ED0_vb v58; };
struct T_C3FF4_p { int x, y, z, w; };
EXTERN_C const T_VTable10 D_800B73D0;
EXTERN_C VTable D_800B7518[], D_800B7420[];
EXTERN_C void f5BC84_c(void *p, int a, int b, int c) __asm__("func_8005BC84");
EXTERN_C void f2B174_c(void *a, void *b, int c) __asm__("func_8002B174");
EXTERN_C void f2AC2C_c(void *p) __asm__("func_8002AC2C");
EXTERN_C void f2A210_c(void *p) __asm__("func_8002A210");
EXTERN_C void f5388C_c(void *p, int a) __asm__("func_8005388C");
//@ func_800C3FF4 a
EXTERN_C T_C3FF4 *func_800C3FF4(T_C3FF4 *self, int in_chrg, T_C3FF4_p *pos, int a3, int a4)
{
    if (in_chrg) {
        self->vb0 = (T_VBase *)&self->v58;
        T_D3ED0_vb *v = (T_D3ED0_vb *)self->vb0;
        v->vptr = D_80010178;
        v->f4 = 0;
        v->vptr = D_800104A8;
    }
    f5BC84_c(self, 0, 2, 1);
    func_800537C0(self->f38);
    self->vb0->vptr = (T_VTable10 *)&D_800B73D0;
    T_VTable10 vt;
    if (!in_chrg) {
        vt = D_800B73D0;
        self->vb0->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B73D0.e[1].delta + (adj = (char *)self - (full = (char *)self->vb0 - 0x58));
        vt.e[5].delta = D_800B73D0.e[5].delta + adj;
        vt.e[7].delta = D_800B73D0.e[7].delta + adj;
        vt.e[9].delta = D_800B73D0.e[9].delta + adj;
    }
    self->vt40 = D_800B7518;
    self->vt2C = D_800B7420;
    short *q = &self->h44;
    unsigned short px = pos->x, py = pos->y, pz = pos->z, pw = pos->w;
    self->h44 = px; q[1] = py; q[2] = pz; q[3] = pw;
    self->f4C = a3;
    self->f50 = a4;
    char *g = (char *)&D_800A4534;
    int tm = D_800A4534.fC;
    self->h56 = 0;
    self->h54 = tm;
    void *g44 = *(void * volatile *)(g + 0x44);
    f2B174_c(g44, self, -1);
    f2AC2C_c(self);
    f2A210_c(self);
    f5388C_c(self ? self->f38 : 0, 0x1A);
    return self;
}
