#ifndef GAME_A_H_U_80028428_H
#define GAME_A_H_U_80028428_H

/* Declarations for src/main/u_80028428.cpp only. */

EXTERN_C void *D_800112F4[];
EXTERN_C void *D_80011304[];
EXTERN_C void *D_8001126C[];
struct S_80028FD8 { void **vt; int unk4; int unk8; void **vtC; };
/* Retail reaches D_800B4CF0 (double-buffer index) without $gp in this file: an explicit section keeps it off $gp. */
EXTERN_C int D_800B4CF0 __attribute__((section(".data")));
struct S_80028F10e { short unk38; short unk3A; char pad[0x10]; };
struct S_80028F10 { char pad0[8]; short unk8; char padA[0x2E]; S_80028F10e e[2]; };
struct S_XYs { short x, y; };
EXTERN_C S_XYs D_800B4C64;
EXTERN_C void *func_8002860C(void *p, void *q, int a, int b, void *c);

struct S_Sprt { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
struct S_DrMode { int tag; int code[2]; };
struct S_Spr2 { void **vt; int unk4; short unk8; short unkA; void **vtC; S_DrMode dm[2]; S_Sprt sp[2]; char pad48[8]; };
EXTERN_C void *D_800117D4[];
inline void spr2_copy(S_Spr2 *p, S_Spr2 *q)
{
    p->vt = D_80010178;
    p->unk4 = q->unk4;
    p->vt = D_800111BC;
    p->unk8 = q->unk8;
    p->unkA = q->unkA;
    p->vt = D_800117D4;
    p->vtC = D_800112F4;
    p->vt = D_80011304;
    {
        S_DrMode *d = p->dm;
        int n = 1;
        S_DrMode *s = q->dm;
        for (; n != -1; n--)
            *d = *s, d++, s++;
    }
    {
        S_Sprt *d = p->sp;
        int n = 1;
        S_Sprt *s = q->sp;
        for (; n != -1; n--)
            *d = *s, d++, s++;
    }
}

EXTERN_C void SetDrawMode(void *p, int dfe, int dtd, int tpage, void *tw);
struct S_Spr2v { void *volatile vt; int unk4; short unk8; short unkA; void **vtC; S_DrMode dm[2]; S_Sprt sp[2]; char pad48[8]; };
EXTERN_C void func_80028C80(S_Spr2 *p, void *r);
EXTERN_C void func_80028DC4(void *p, int a);
EXTERN_C void func_80028D10(S_Spr2 *p, void *c);
EXTERN_C void func_80028A24(S_Spr2 *p);

EXTERN_C char D_800B4C78[];
EXTERN_C char D_800B4C80[];
EXTERN_C char D_800B4C88[];
EXTERN_C char D_800B4C90[];
EXTERN_C char D_800B4C98[];
EXTERN_C char D_800B4CA0[];
EXTERN_C char D_800B4CA8[];
EXTERN_C char D_800B4CB0[];
EXTERN_C char D_800B4CB8[];
EXTERN_C char D_800B4CC0[];
EXTERN_C char D_800B4CC8[];
EXTERN_C char D_800B4CD0[];
EXTERN_C char D_800B4CD8[];
EXTERN_C char D_800B4CE0[];
inline int max0(int x) { return x > 0 ? x : 0; }

#endif /* GAME_A_H_U_80028428_H */
