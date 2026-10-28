#ifndef GAME_A_H_U_8001C2D0_H
#define GAME_A_H_U_8001C2D0_H

/* Declarations for src/main/u_8001C2D0.cpp only. */

EXTERN_C void func_800186E8(Holder *h);
struct S_VDel {
    virtual ~S_VDel();
};
struct S_8001CDEC {
    void **vt;
    int unk4;
    short unk8;
    short unkA;
    int unkC;
    int unk10;
};
struct S_8001D684 {
    void **vt;
    int unk4;
    int unk8;
    short unkC;
    int unk10;
};
EXTERN_C void *D_800B4C14;
EXTERN_C void *D_80010338[];
EXTERN_C void *D_800102A0[];
EXTERN_C void *D_800102C0[];
EXTERN_C void *D_800102D0[];
struct S_Node {
    void **vt;
    S_Node *next;
    int key;
};
EXTERN_C S_Node *func_8001D25C(void *p, int key);
EXTERN_C void func_8001D324(void *p, S_Node *q);
EXTERN_C void *func_8001C718(void *p);
EXTERN_C void func_8001C7D4(void *p, void *q);
EXTERN_C void func_8001CA58(void *p, int size);

EXTERN_C bool func_8001D6C8(S_8001D6C8 *p);
EXTERN_C void func_8001D6E0(S_8001D6C8 *p, int a);
EXTERN_C S_Node *func_8001D0E4(S_Node *p, int key);
EXTERN_C void *func_8001A744(void *self, void *p);
EXTERN_C void func_8001D150(void *self, void *b);
struct S_8001D5C0_V {
    virtual void f0();
    virtual int f1();
};
struct S_8001D5C0 {
    int unk0;
    int unk4;
    S_8001D5C0_V *unk8;
};
struct S_8001C5DC {
    int unk0;
    int unk4;
    int unk8;
};

struct S_Lnk {
    void **vt;
    S_Lnk *next;
};
struct S_8001C8D8 {
    void **vt;
    S_8001C8D8 *next;
    unsigned short key;
};
struct S_Elem14 {
    char pad[0x14];
};
struct S_Pool14 : S_VDel {
    S_Pool14 *next;
    unsigned int bits;
    S_Elem14 e[32];
};
struct S_8001D04C {
    void **vt;
    int unk4;
    S_VDel *unk8;
    int unkC;
    int unk10;
};
struct S_8001D684b {
    void **vt;
    int unk4;
    int unk8;
    short unkC;
    int unk10;
    S_8001D684b(int a, short b, int c)
    {
        vt = D_80010178;
        unk4 = 0;
        vt = D_80010338;
        unk8 = a;
        unkC = b;
        unk10 = c;
    }
};
EXTERN_C void *D_800101F8[];
EXTERN_C int D_800A4544[];
EXTERN_C S_Lnk *func_8001A864(S_Lnk *p, S_Lnk *a);
EXTERN_C S_Lnk *func_8001CF68(S_Lnk *head, S_Lnk *n);
static inline S_Pool14 *newpool_8001C718()
{
    S_Vobj4 *np = (S_Vobj4 *)operator new(0x28C);
    np->vtbl = D_80010178;
    np->unk4 = 0;
    np->vtbl = D_800102C0;
    np->unk8 = 0;
    D_800B4C14 = func_8001CF68((S_Lnk *)D_800B4C14, (S_Lnk *)np);
    return (S_Pool14 *)np;
}

struct S_Own2 {
    void **vt;
    S_VDel *ptr;
};
struct S_8001D3A8_V {
    virtual void f0();
    virtual int f1();
};
struct S_8001D3A8_N : S_VDel {
    S_8001D3A8_N *next;
    S_8001D3A8_V *unk8;
};
struct S_8001D3A8 {
    int unk0;
    S_8001D3A8_N *next;
};
EXTERN_C void *D_80010388[];
EXTERN_C void *D_80010378[];
EXTERN_C void *D_800103A0[];
EXTERN_C void *D_800103B8[];
EXTERN_C void func_8001E508(void *p, int a);

struct S_8001D8A4 {
    char pad0[0xFC];
    S_8001D3A8_N *list;
    int pad100;
    S_8001D3A8_N *cur;
    S_8001D3A8_N *nxt;
};

#endif /* GAME_A_H_U_8001C2D0_H */
