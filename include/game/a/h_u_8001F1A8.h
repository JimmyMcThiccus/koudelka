#ifndef GAME_A_H_U_8001F1A8_H
#define GAME_A_H_U_8001F1A8_H

/* Declarations for src/main/u_8001F1A8.cpp only. */

EXTERN_C int func_80019C24(List *l, void *item);
EXTERN_C int func_80019CFC(List *l, void *item);
EXTERN_C void *func_8001A744(void *list, void *item);
EXTERN_C void *D_800B4C30;
EXTERN_C void *D_800B4C34;
EXTERN_C void *D_800100F8[];
EXTERN_C void *D_80010470[];
EXTERN_C void *D_80010480[];
EXTERN_C void *D_800104F8[];
EXTERN_C void func_800186E8(Holder *h);
EXTERN_C int VSyncCallback(void (*f)());
EXTERN_C void func_8001F9C0();
struct S_8001F930 {
    void **vtbl;
    void **vtbl2;
    int unk8;
    int unkC;
};
struct S_8001FC38 {
    void **vtbl;
    int unk4;
    int unk8;
    int unkC;
    short unk10;
    short unk12;
};
struct S_8001FB9C {
    List *list;
};

struct S_Timer {
    void **vtbl;
    S_Timer *next;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    unsigned int unk1C;
    int unk20;
    int unk24;
    int unk28;
};
struct S_List {
    void **data;
    int count;
};
struct S_TimerIter {
    S_List *list;
    int idx;
    Item *next()
    {
        if (idx < list->count)
        {
            Item *r = (Item *)list->data[idx];
            idx++;
            return r;
        }
        return 0;
    }
};
EXTERN_C S_Timer *func_8001A864(S_Timer *a, S_Timer *b);
EXTERN_C void func_80018AF4();
EXTERN_C void func_80018B18();
EXTERN_C void func_8001F514(void *item);

EXTERN_C void *D_800102D0[];
EXTERN_C void *D_800105DC[];
EXTERN_C void *D_80010588[];
struct VtblEntry {
    short delta;
    short index;
    void *pfn;
};
#define VCALL(o, slot, T, args...) \
    ((T)((VtblEntry *)(*(void ***)(o)))[slot].pfn)((char *)(o) + ((VtblEntry *)(*(void ***)(o)))[slot].delta , ## args)
struct S_TimerBase8 {
    void **vtbl;
    void **vtbl2;
    void *unk8;
    unsigned short unkC;
};
struct S_8001F788 {
    void **vtbl;
    int unk4;
    unsigned short unk8;
    short unkA;
    void *unkC;
    int unk10;
};
inline void *operator new(unsigned int, void *p) { return p; }
struct S_Obj178 {
    void **vtbl;
    int unk4;
    S_Obj178() { vtbl = D_80010178; unk4 = 0; }
};
struct S_Evt300 : S_Obj178 {
    unsigned short unk8;
    short unkA;
    void *unkC;
    int unk10;
    S_Evt300(unsigned short a, short b, void *c, int d) { vtbl = D_80010300; unk8 = a; unkA = b; unk10 = d; unkC = c; }
};
struct S_Evt2D0 : S_Evt300 {
    S_Evt2D0(unsigned short a, void *c) : S_Evt300(a, 3, c, 0) { vtbl = D_800102D0; }
};
struct S_C178 {
    void **vtbl;
    void *unk4;
    S_C178(const S_C178 &s) { vtbl = D_80010178; unk4 = s.unk4; }
};
struct S_C4F8 : S_C178 {
    int unk8;
    int unkC;
    S_C4F8(const S_C4F8 &s) : S_C178(s) { vtbl = D_800104F8; unk8 = s.unk8; unkC = s.unkC; }
};
struct S_C5DC : S_C4F8 {
    unsigned short unk10;
    unsigned short unk12;
    S_C5DC(const S_C5DC &s) : S_C4F8(s), unk10(s.unk10), unk12(s.unk12) { vtbl = D_800105DC; }
};
struct S_C588 : S_C5DC {
    int unk14;
    unsigned short unk18;
    unsigned short unk1A;
    S_C588(const S_C588 &s) : S_C5DC(s), unk14(s.unk14) { vtbl = D_80010588; unk18 = s.unk18; unk1A = s.unk1A; }
};
struct S_80020304 {
    void **vtbl;
    void *unk4;
    int unk8;
    int unkC;
    unsigned short unk10;
    unsigned short unk12;
    int unk14;
    unsigned short unk18;
    unsigned short unk1A;
};
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *p, void *o);
EXTERN_C S_8001FC38 *func_8001FC38(S_8001FC38 *p, int a, int b, int c);

EXTERN_C void func_8001F788(S_TimerBase8 *b, S_TimerBase8 *x);

struct S_Ev {
    char pad0[0x10];
    unsigned short unk10;
};
struct S_Handler {
    void **vtbl;
    S_Handler *unk4;
};
typedef int (*HandlerFn)(void *, void *);

EXTERN_C void *D_80010438[];
EXTERN_C void *D_80010450[];
EXTERN_C void *D_80010460[];
struct S_BF8 {
    void **vtbl;
    S_BF8() { vtbl = D_800100F8; }
};
struct S_B198 {
    void **vtbl2;
    S_B198() { vtbl2 = D_80010198; }
};
struct S_TF930 : S_BF8, S_B198 {
    int unk8;
    int unkC;
    S_TF930(int a, int b) { vtbl2 = D_80010480; vtbl = D_80010470; unk8 = a; unkC = b; }
};
struct S_TimerObj : S_Obj178, S_TF930 {
    int unk18;
    int unk1C;
    S_TimerObj(int a, int b) : S_TF930(a, b) { ((void ***)this)[3] = D_80010438; ((void ***)this)[2] = D_80010450; ((void ***)this)[0] = D_80010460; unk1C = 0; }
};

struct S_8001FBF4 {
    void *unk0;
    int unk4;
    void *unk8;
    int data[0x10];
    S_8001FBF4() { unk8 = data; unk0 = unk8; func_800198E0(unk8, 0x10, 0); unk4 = 0; }
};

#endif /* GAME_A_H_U_8001F1A8_H */
