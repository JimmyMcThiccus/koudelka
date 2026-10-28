#ifndef GAME_A_H_U_8001986C_H
#define GAME_A_H_U_8001986C_H

/* Declarations for src/main/u_8001986C.cpp only. */

struct S_8001A014 { void **vt; int a; int b; };
EXTERN_C void *D_80010108[];

struct S_Array { int *data; int count; int cap; int grow; int unk10; };
struct S_Link { int unk0; S_Link *next; };
struct S_HeapE { unsigned short next; unsigned short size; };
struct S_Heap { int unk0; int unk4; S_HeapE e[1]; };
struct S_ArrayIt { int unk0; S_Array *arr; int idx; };
EXTERN_C void *D_800100F8[];
EXTERN_C void *D_800101C0[];
EXTERN_C void *D_800101B0[];
EXTERN_C void *D_800101D8[];
EXTERN_C int D_800A4578[];
EXTERN_C void *func_800A0D2C(int size);
EXTERN_C void func_800A0D0C(void *p);
EXTERN_C int func_80019B2C(void *p, int v, int start);
EXTERN_C void func_80019D5C(void *p, int i, int v, int n);
EXTERN_C void func_8001B910(int a);
EXTERN_C void func_8001BBBC(int a);
EXTERN_C void func_8001C9D0();
EXTERN_C void func_8009DDC0(int a);
EXTERN_C void ResetGraph(int mode);
EXTERN_C void InitGeom();
EXTERN_C void InitCARD(int a);
EXTERN_C void StartCARD();
struct S_8001AC38 { void **vt; void **vt4; int unk8; short unkC; short unkE; short unk10; short unk12; };
struct S_8001ACDC { void **vt; int unk4; short unk8; short unkA; short unkC; short unkE; };

EXTERN_C void *func_8001A970(void *dst, void *src, int n);
EXTERN_C void func_80019974(S_Array *a, int n);

struct S_VDel {
    virtual ~S_VDel();
};
struct S_8001A2D0_N : S_VDel {
    S_8001A2D0_N *next;
};
struct S_8001A2D0 {
    int unk0;
    int unk4;
    S_8001A2D0_N *unk8;
};
struct S_8001A138_V {
    virtual void run(void *p);
};
struct S_8001A138 {
    int unk0;
    S_8001A138_V *unk4;
    int unk8;
};
EXTERN_C void *D_80010338[];
EXTERN_C int D_800A4544[];
EXTERN_C void func_8001D150(void *self, void *b);
struct S_8001D684 {
    void **vt;
    int unk4;
    int unk8;
    short unkC;
    int unk10;
    S_8001D684(int a, short b, int c)
    {
        vt = D_80010178;
        unk4 = 0;
        vt = D_80010338;
        unk8 = a;
        unkC = b;
        unk10 = c;
    }
};

struct S_8001A3BC {
    void **vt;
    int unk4;
    int unk8;
};
struct S_8001A610 {
    void **vt;
    S_VDel *unk4;
};
struct S_8001A7B4_P {
    virtual S_Link *test(S_Link *r, S_Link *cur);
};
EXTERN_C void *D_80010160[];
EXTERN_C void *D_80010130[];
EXTERN_C void *D_80010148[];
EXTERN_C S_Link *func_8001A708(S_Link *p, S_Link *a);

struct S_8001AA68 {
    void **vt;
    void **vt4;
    void *unk8;
    short unkC;
    short unkE;
    unsigned short unk10;
    unsigned short unk12;
};
struct S_8001AA68_N {
    void **vt;
    int unk4;
    short unk8;
    short unkA;
    void *unkC;
    int unk10;
};
EXTERN_C void *D_80010300[];
EXTERN_C void *D_800102D0[];
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *p, void *q);
EXTERN_C void func_80018C1C(void *p);
EXTERN_C void func_8001AD18(S_Heap *h, S_HeapE *b);
EXTERN_C void func_8001AD68(S_Heap *h);
EXTERN_C void func_8001ADE0(S_Heap *h, S_HeapE *p);
EXTERN_C S_Link *func_8001A864(S_Link *p, S_Link *a);
EXTERN_C S_Link *func_8001A744(S_Link *head, S_Link *n);
static inline void link_8001ADE0(S_Heap *h, S_HeapE *a, S_HeapE *b)
{
    a->next = b - h->e;
    func_8001AD18(h, a);
}

struct S_8001B394 {
    char pad0[0x14C];
    int unk14C;
    void *unk150;
};
struct S_800EA8A0;
EXTERN_C S_800EA8A0 D_800EA8A0[];
EXTERN_C void *func_80018C90(unsigned int size);
EXTERN_C void *func_8001AF8C(S_Heap *h, unsigned int size);
EXTERN_C void *func_80018D80(unsigned int size);
EXTERN_C void *func_80027E30(unsigned int size);
EXTERN_C void func_80027FB0(void *p);
EXTERN_C int func_80018DF4(int *p);
EXTERN_C void func_8002D1E0();
EXTERN_C int DrawSync(int mode);
EXTERN_C int ResetRCnt(int spec);
static inline bool above_8001B1C8(S_Heap *h, void *p)
{
    return (char *)h->e < (char *)p;
}

/* This file reads D_800B4C3C with lui (no $gp); main_a.h declares it plainly, so it is reached here by asm name. */
EXTERN_C int D_800B4C3C_lui asm("D_800B4C3C") __attribute__((section(".data")));
EXTERN_C void DrawSyncCallback(void (*f)());

struct S_Pt4_986C { short x, y; };
struct S_Pt4c_986C {
    short x, y;
    S_Pt4c_986C(short a, short b) { x = a; y = b; }
    S_Pt4_986C &pt() { return *(S_Pt4_986C *)this; }
};
struct S_Rect_986C { S_Pt4_986C pos; S_Pt4_986C size; };
struct S_RectPS_986C {
    S_Pt4_986C pos;
    S_Pt4_986C size;
    S_RectPS_986C(S_Pt4_986C p, S_Pt4_986C s) : pos(p), size(s) {}
    S_RectPS_986C(S_Pt4_986C s) { pos.x = 0; pos.y = 0; size = s; }
};
struct S_VramV_986C {
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual S_Pt4_986C f4(S_Pt4c_986C sz);
    virtual int f5(S_Pt4_986C pos);
};
EXTERN_C S_VramV_986C *D_800B4C54 __attribute__((section(".data")));
EXTERN_C S_Pt4_986C D_800B4CF4 __attribute__((section(".data")));
EXTERN_C S_Pt4_986C D_800B4CF8 __attribute__((section(".data")));
EXTERN_C int D_800B4CF0 __attribute__((section(".data")));
EXTERN_C void *D_800101F8[];
struct S_800101F8 {
    void **vt;
    int unk4;
    S_800101F8(int a) { vt = D_800101F8; unk4 = a; }
};
struct S_14_986C { char pad[0x14]; void *unk14; };
struct S_WinV_986C {
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void *v12();
};
struct VEnt_986C { short d; short i; void *f; };
struct S_8001BBBC {
    int unk0;
    int unk4;
    S_14_986C *unk8;
    S_Rect_986C rect;
    char pad14[0x18];
    VEnt_986C *vt;
    void *v12() { VEnt_986C *e = &vt[12]; return ((void *(*)(void *))e->f)((char *)this + e->d); }
    S_Rect_986C getRect() { return rect; }
};
#define WV(p) ((S_WinV_986C *)((char *)(p) + 0x2C))
EXTERN_C void func_8002CDC0(S_RectPS_986C *r);
EXTERN_C void func_8002D24C(void *p, void *r);
EXTERN_C void *func_8002900C(void *p, int a, int b, int c, int d, int e);
inline S_Pt4_986C org0_986C() { return D_800B4CF4; }
inline S_Pt4_986C org1_986C() { return D_800B4CF8; }
EXTERN_C void func_8002D020(S_Pt4_986C *a, S_Pt4_986C *b, S_Pt4_986C *c, S_Pt4_986C *d);

inline void *operator new(unsigned int, void *p) { return p; }
struct VTab50_986C { VEnt_986C e[10]; };
EXTERN_C const VTab50_986C D_80010210;
EXTERN_C void *D_80010498[];
EXTERN_C void *D_80010260[];
EXTERN_C void *D_80010288[];
EXTERN_C void *D_80010278[];
EXTERN_C void *D_8001167C[];
EXTERN_C void *D_800104A8[];
EXTERN_C int D_800B4C38 __attribute__((section(".data")));
EXTERN_C char D_800B4C90[];
EXTERN_C char D_800B4C80[];
EXTERN_C char D_800A4554[];
struct S_VB_986C {
    VEnt_986C *vt;
    int unk4;
    S_VB_986C() { vt = (VEnt_986C *)D_80010178; unk4 = 0; vt = (VEnt_986C *)D_800104A8; }
};
struct S_Size_986C {
    short w, h;
    S_Size_986C(short a, short b) : w(a), h(b) {}
};
struct S_GameV_986C {
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(int x, int y);
};
struct S_8001B46C {
    S_VB_986C *vb;
    char pad4[0x28];
    VEnt_986C *vt2C;
    char pad30[0x20];
    void **vt50;
    char pad54[0x88];
    void **vtDC;
    char padE0[0x68];
    void **vt148;
    int unk14C;
    char pad150[0x4];
    char unk154[0x9C];
    char unk1F0[0x90];
    char unk280[0x9C];
    char unk31C[0x90];
    void v9(int x, int y) { VEnt_986C *e = &vt2C[9]; ((void (*)(void *, int, int))e->f)((char *)this + e->d, x, y); }
};
EXTERN_C void func_8002C2B8(void *p, int in_chrg);
EXTERN_C void func_8001E40C(void *p, int in_chrg, int a, int b, int c);
EXTERN_C void func_80022FB8(void *p, int a);
EXTERN_C void SsUtReverbOff();
EXTERN_C void PadInitDirect(void *a, void *b);
EXTERN_C void func_80035BF8();
struct S_Rect2_986C {
    short x, y, w, h;
    S_Rect2_986C(int aw, int ah) { w = aw; x = 0; y = 0; h = ah; }
    S_Rect2_986C(short ax, short ay, short aw, short ah) { x = ax; y = ay; w = aw; h = ah; }
};
struct S_8002900C_986C {
    char pad[0x3C];
    S_8002900C_986C(int a, int b, int c, int d, const S_Rect2_986C &r) asm("func_8002900C");
};
EXTERN_C void func_80026214(const S_Rect2_986C &r);
EXTERN_C void func_80021300(S_RectPS_986C *r, int a);
EXTERN_C void func_8002A400(void *p, void *q);
EXTERN_C void func_8002A37C(void *p, void *q);
EXTERN_C int func_8001E07C(void *p, int a);

struct S_BE20_N {
    virtual void f0();
    virtual void kill();
};
struct S_BE20 : S_BE20_N {
    int dead() { int r = 0; if (unkA == 1) r = unk10 == 0; return r; }
    S_BE20 *next;
    short unk8;
    unsigned short unkA;
    int unkC;
    int unk10;
};

#endif /* GAME_A_H_U_8001986C_H */
