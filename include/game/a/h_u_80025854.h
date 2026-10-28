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

/* D_800B4C50/D_800B4C52 (two shorts in main_a.h) read as one point; it must be a 2-aligned struct
   for GCC to copy it with lwl/lwr straight off $gp. */
struct S_Pt16 { short x, y; };
EXTERN_C S_Pt16 D_800B4C50_pt asm("D_800B4C50");

inline void setPos_80025BE0(S_Img *p, S_XYc v) { p->unk10 = v; }

struct S_R16 { short x, y, w, h; };
struct S_TNode {
    void **vt;
    S_TNode *parent;
    S_R16 r;
    S_TNode *c0;
    S_R16 r2;
    S_TNode *c1;
};
inline int max_int(int a, int b) { return a > b ? a : b; }
inline void rect_unite(S_R16 *a, S_R16 *b)
{
    S_XYc tl(a->x < b->x ? a->x : b->x, a->y < b->y ? a->y : b->y);
    a->w = max_int(a->x + a->w, b->x + b->w) - tl.x;
    a->h = max_int(a->y + a->h, b->y + b->h) - tl.y;
    *(S_XYc *)a = tl;
}
inline void tnode_collapse(S_TNode *p)
{
    if (p->parent)
        func_8002758C(p->parent, p);
    else
        rect_unite(&p->r, &p->r2);
}

struct S_Rc16 {
    short x, y, w, h;
};
inline int in_rect(S_Rc16 *r, S_XYc pt)
{
    return r->x <= pt.x && pt.x < r->x + r->w && r->y <= pt.y && pt.y < r->y + r->h;
}
struct S_80027754 { char pad0[8]; S_Rc16 r8; VObj *o10; S_Rc16 r14; VObj *o1C; };
inline int send_80027754(VObj *o, const S_XYc &pt)
{
    VEnt *e = &o->vt[5];
    return ((int (*)(void *, S_XYc))e->f)((char *)o + e->d, pt);
}

struct S_Rect16 { short x, y, w, h; };
struct S_80026420 { void **vt; void *unk4; };

#endif /* GAME_A_H_U_80025854_H */
