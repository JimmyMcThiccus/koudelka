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

#endif /* GAME_A_H_U_8001C2D0_H */
