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

#endif /* GAME_A_H_U_8001986C_H */
