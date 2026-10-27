#ifndef GAME_A_H_U_80025854_H
#define GAME_A_H_U_80025854_H

/* Declarations for src/main/u_80025854.cpp only. */

struct VEnt { short d; short i; void *f; };
struct VObj { VEnt *vt; };
struct S_XYc { short x, y; S_XYc() {} S_XYc(short x_, short y_) { x = x_; y = y_; } };
struct S_Cc { unsigned char r, g, b, a; S_Cc() {} };
struct S_4b { unsigned char a, b, c, d; };
struct S_8b { S_4b p, q; };
struct S_800261DC { int unk0; void *unk4; };
EXTERN_C void func_8002758C(void *p, void *q);
EXTERN_C void func_80027408(void *p, void *q);
struct S_80025A04 { char pad0[0xC]; VObj *unkC; };
struct S_80026138 { void **vt; void *unk4; };
EXTERN_C VObj *D_800B4C54;
EXTERN_C void *D_800110C4[];
struct S_80026274 {
    void **vt;
    int unk4;
    short unk8, unkA, unkC, unkE;
    int unk10;
    short unk14, unk16, unk18, unk1A;
    int unk1C;
};
EXTERN_C S_80026274 *func_80026274(S_80026274 *p, S_8b *r, int b);

EXTERN_C short D_800108C0[];
EXTERN_C void *D_80010888[];
EXTERN_C void *D_800108A0[];
EXTERN_C void func_80024BF0(void *p, int a, int b, int c);
struct S_UV { unsigned char u, v; S_UV(unsigned char u_, unsigned char v_) { u = u_; v = v_; } };
struct S_Tex { char pad0[0xC]; VObj *unkC; short unk10; short unk12; short unk14; short unk16; };
struct S_80026920 { char pad0[0x10]; VObj *unk10; char pad14[8]; VObj *unk1C; };
struct S_Del { VEnt *vt; int unk4; };
struct S_800262E4 { void **vt; char pad4[0xC]; S_Del *unk10; char pad14[8]; S_Del *unk1C; };
struct S_Img {
    void **vt;
    int unk4;
    void **unk8;
    int unkC;
    S_XYc unk10;
    S_XYc unk14;
    int unk18;
    short unk1C;
    short unk1E;
};
inline int vcall3(VObj *o)
{
    VEnt *e = &o->vt[3];
    return ((int (*)(void *))e->f)((char *)o + e->d);
}
inline void vdel(S_Del *o)
{
    if (o) {
        VEnt *e = &o->vt[1];
        ((void (*)(void *, int))e->f)((char *)o + e->d, 3);
    }
}
struct S_UV2 { unsigned char u, v; S_UV2(int u_, int v_) { u = u_; v = v_; } };

#endif /* GAME_A_H_U_80025854_H */
