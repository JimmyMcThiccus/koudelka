#ifndef GAME_A_H_U_8001DDF4_H
#define GAME_A_H_U_8001DDF4_H

/* Declarations for src/main/u_8001DDF4.cpp only. */

struct VtblEntry {
    short delta;
    short index;
    void *pfn;
};
#define VCALL(o, slot, T, args...) \
    ((T)((VtblEntry *)(*(void ***)(o)))[slot].pfn)((char *)(o) + ((VtblEntry *)(*(void ***)(o)))[slot].delta , ## args)
inline void *operator new(unsigned int, void *p) { return p; }
EXTERN_C void *D_800103D0[];
EXTERN_C void *D_80010408[];
EXTERN_C void *D_80010420[];
struct S_Obj178 {
    void **vtbl;
    void *unk4;
    S_Obj178() { vtbl = D_80010178; unk4 = 0; }
};
struct S_Node {
    void **vtbl;
    S_Node *next;
    void *unk8;
    short unkC;
    int unk10;
    int unk14;
};
struct S_Node3D0 : S_Obj178 {
    void *unk8;
    short unkC;
    int unk10;
    int unk14;
    S_Node3D0(void *a, short b, int c, int d) { vtbl = D_800103D0; unk8 = a; unkC = b; unk14 = c; unk10 = d; }
};
struct S_NodeList {
    S_Node *head;
};
struct S_Target {
    virtual void f1();
    virtual void f2(int);
};
typedef int (*Fn_ii)(void *, int);
typedef void (*Fn_vi)(void *, int);

struct S_TargetI {
    virtual void f1();
    virtual int f2(int);
};
struct S_EvtV {
    virtual void f1();
    virtual void f2();
};
struct S_Evt {
    void **vtbl;
    S_Evt *next;
    unsigned short unk8;
    unsigned short unkA;
    void *unkC;
};
struct S_Scene {
    char pad0[0x4];
    S_Scene *next;
    char pad8[0xEC];
    int unkF4;
};
struct S_ScnAC688 {
    void *unk0;
    int unk4;
    void *unk8;
    int data[4];
    S_ScnAC688() { unk8 = data; unk0 = unk8; func_800198E0(unk8, 4, 0); unk4 = 0; }
};
EXTERN_C void func_80018FA8(void *jb, void *v);
EXTERN_C void func_8001E57C(void *p);
EXTERN_C void *func_8001C974(void *p);
EXTERN_C void func_8001C8D8(void *p, void *e);
EXTERN_C void func_8001E6AC(void *p);
EXTERN_C int func_8001EEC0(void *a, void *b);
EXTERN_C void func_8001F3DC(void *p, int flags);
EXTERN_C void func_80018E88(void *p, int flags);
EXTERN_C char D_800B4C28[];
EXTERN_C S_Scene *func_8001E758(S_Scene *s);

EXTERN_C void func_80018EDC(void *p);
EXTERN_C void *D_800B4C20;
EXTERN_C void *D_80010388[];
EXTERN_C void *D_80010378[];
EXTERN_C void *D_800103A0[];
EXTERN_C void *D_800103B8[];
EXTERN_C void *D_80010300[];
EXTERN_C void *D_800102D0[];
struct S_SceneV {
    virtual void f1();
    virtual void f2();
};
struct S_Scn {
    void **vtbl;
    char pad4[0x4];
    int unk8;
    char padC[0x7C];
    char *unk88;
    char pad8C[0x14];
    int unkA0;
    char padA4[0x50];
    int unkF4;
};
struct S_Evt300 : S_Obj178 {
    unsigned short unk8;
    short unkA;
    void *unkC;
    int unk10;
    S_Evt300(unsigned short a, short b, void *c, int d) { vtbl = D_80010300; unk8 = a; unkA = b; unk10 = d; unkC = c; }
};
struct S_Evt2D0 : S_Evt300 {
    S_Evt2D0(unsigned short a, short b, void *c) : S_Evt300(a, b, c, 0) { vtbl = D_800102D0; }
};
struct S_Obj4 {
    void **vtbl;
    void *unk4;
};

EXTERN_C void *D_80010408[];
EXTERN_C void *D_80010420[];
EXTERN_C S_80018E5C *func_80018E5C(S_80018E5C *p, int a);
EXTERN_C int func_8001E344();
EXTERN_C void func_8001E840(S_8001E840 *p);
struct S_Evt408 : S_Evt300 {
    S_Evt408(void *c) : S_Evt300(2, 2, c, 0) { vtbl = D_80010408; }
};
struct S_Vec1 {
    void *unk0;
    int unk4;
    void *unk8;
    int data[1];
    S_Vec1() { unk8 = data; unk0 = unk8; func_800198E0(unk8, 1, 0); unk4 = 0; }
};
struct S_List {
    void **data;
    int count;
};
inline int S_Evt_ge(S_Evt *a, S_Evt *b) { return a->unk8 >= b->unk8; }
struct S_Iter {
    S_List *list;
    int idx;
    Item *next()
    {
        if (idx < list->count) {
            Item *r = (Item *)list->data[idx];
            idx++;
            return r;
        }
        return 0;
    }
};
struct S_Task {
    void **vtbl;
    S_Task *next;
    char pad8[0x88];
    S_Evt *cur;
    unsigned short unk94;
    char pad96[0x2];
    char *unk98;
    char pad9C[0x4];
    int unkA0;
    S_Iter iter;
    char padAC[0x44];
    int unkF0;
    int unkF4;
};

EXTERN_C S_Node *func_8001E248(S_Node *n, void *id);

EXTERN_C void func_8001F544(void *t, int delay, int a, int repeat, int b);
EXTERN_C int func_8001F598(void *t);
EXTERN_C int func_80018F0C(void *jb, void *v);
EXTERN_C void func_8001E9A8(void *p);

/* Real polymorphic classes, named after their retail vtables, for code that needs the compiler's own
   vptr handling (e.g. the vptr-preserving copy in `*e = C_80010300(...)`). Their virtual functions are
   declared, never defined, so no vtable is emitted; GCC's vtable and dtor symbols are equated to the
   retail ones below (no storage). */
struct C_800100F8 { virtual ~C_800100F8(); };
struct C_80010178 : C_800100F8 { void *unk4; C_80010178() { unk4 = 0; } ~C_80010178(); virtual void f2() = 0; };
struct C_80010300 : C_80010178 {
    unsigned short unk8;
    short unkA;
    void *unkC;
    int unk10;
    C_80010300(int d, void *c, unsigned short a) { unk8 = a; unkA = 2; unk10 = d; unkC = c; }
    void f2();
};
__asm__(".set _vt.10C_800100F8, D_800100F8\n"
        ".set _vt.10C_80010178, D_80010178\n"
        ".set _vt.10C_80010300, D_80010300\n"
        ".set _._10C_80010178, func_8001A610\n");
struct S_8001EBD8 { char pad[0x98]; void *unk98; };

inline S_Iter *iter_reset(S_Iter *i)
{
    i->idx = 0;
    return i;
}
EXTERN_C void func_800190A0(void *a, void *b);

#endif /* GAME_A_H_U_8001DDF4_H */
