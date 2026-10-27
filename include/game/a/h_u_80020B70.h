#ifndef GAME_A_H_U_80020B70_H
#define GAME_A_H_U_80020B70_H

/* Declarations for src/main/u_80020B70.cpp only. */

struct VtblEntry {
    short delta;
    short index;
    void *pfn;
};
#define VCALL(o, slot, T, args...) \
    ((T)((VtblEntry *)(*(void ***)(o)))[slot].pfn)((char *)(o) + ((VtblEntry *)(*(void ***)(o)))[slot].delta , ## args)
inline void *operator new(unsigned int, void *p) { return p; }
typedef void (*Fn_vi)(void *, int);
typedef int (*Fn_i)(void *);
typedef void (*Fn_v)(void *);
EXTERN_C void *func_800A0D2C(int size);
EXTERN_C void func_800A0D0C(void *p);
EXTERN_C int *func_8001AA28(int *p, int n);
EXTERN_C void *D_800B4C38;
EXTERN_C void *D_800105DC[];
EXTERN_C void *D_80010624[];
EXTERN_C void *D_80010654[];
EXTERN_C void *D_80010684[];
EXTERN_C void *D_800107F0[];
EXTERN_C void *D_80010800[];
EXTERN_C void *func_80021348(void *p, int a, int b);
EXTERN_C void *func_8002466C(void *p, int a, int b);
EXTERN_C int func_80023F50(void *p, int a);
EXTERN_C void *func_8001FC38(void *p, int a, int b, int c);
struct S_Obj178 {
    void **vtbl;
    int unk4;
    S_Obj178() { vtbl = D_80010178; unk4 = 0; }
};
struct S_Obj6EC : S_Obj178 {
    short unk8;
    short unkA;
    S_Obj6EC(short a) { vtbl = D_800106EC; unk8 = 0; unkA = a; }
};
struct S_Obj624 : S_Obj6EC {
    S_Obj624(short a) : S_Obj6EC(a) { vtbl = D_80010624; }
};
struct S_Obj654 : S_Obj6EC {
    S_Obj654(short a) : S_Obj6EC(a) { vtbl = D_80010654; }
};
struct S_Buf {
    void *data;
};
struct S_IdNode {
    void **vtbl;
    S_IdNode *next;
    unsigned short unk8;
    unsigned short unkA;
};
struct S_IdNode1E {
    void **vtbl;
    S_IdNode1E *next;
    char pad8[0x16];
    unsigned short unk1E;
};
struct S_Holder10 {
    char pad0[0x10];
    S_IdNode *unk10;
};
struct S_80024FA8 {
    char pad0[0x18];
    void *unk18;
};
struct S_80024524 {
    char pad0[0x26];
    unsigned char unk26;
};
struct S_80022974 {
    S_80022974(int a) { func_80021348(this, a, 0); unk10 = D_80010684; unk14 = 0; }
    char pad0[0x10];
    void **unk10;
    int unk14;
};
struct S_80020D44 {
    S_80020D44(unsigned short a, int b, unsigned short c, int d) { func_8001FC38(this, a, b, c); vtbl = D_800105DC; unk14 = d; }
    void **vtbl;
    char pad4[0x10];
    int unk14;
};
struct S_80024870 {
    S_80024870(int a) { func_8002466C(this, a, 0); unk1C = D_800107F0; vtbl = D_80010800; unk10 = 10; }
    void **vtbl;
    char pad4[0xC];
    int unk10;
    char pad14[0x8];
    void **unk1C;
};

EXTERN_C void func_800215E8(void *list, void *p);
EXTERN_C int PadInfoAct(int port, int term, int offs);
EXTERN_C void func_80021F48(void *p, int a);
EXTERN_C void func_80021ACC(void *p, int a);
EXTERN_C void *D_800106A4[];
EXTERN_C void *D_800106BC[];
EXTERN_C void *D_80010694[];
EXTERN_C void func_8002141C(void *p, int flags);
struct S_Buf2 {
    void *data;
    char pad4[0x8];
    void *unkC;
    void **unk10;
};
struct S_B6A4 {
    void **vtbl2;
    S_B6A4() { vtbl2 = D_800106A4; }
};
struct S_80022A1C : S_Obj6EC, S_B6A4 {
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    short unk20;
    short unk22;
    S_80022A1C(int a, int b) : S_Obj6EC(0) { vtbl = D_800106BC; unk10 = a; unk18 = b; unk20 = 0; unk22 = 0; }
};
struct S_800226A0 : S_Obj624 {
    S_800226A0(int a, short b) : S_Obj624(b) { func_80021F48(this, a); }
};
struct S_80022810 : S_Obj654 {
    S_80022810(int a, short b) : S_Obj654(b) { func_80021ACC(this, a); }
};
struct S_Pad {
    void **vtbl;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
};

EXTERN_C int GetTPage(int tp, int abr, int x, int y);
EXTERN_C int PadSetAct(int port, unsigned char *data, int len);
EXTERN_C int func_8001D25C(void *a, void *b);
EXTERN_C void func_8001D324(void *a, int b);
EXTERN_C char D_800A4544[];
EXTERN_C void *D_8001079C[];
EXTERN_C void *D_80010714[];
typedef int (*Fn_i)(void *);
struct S_Tex {
    char pad0[0xC];
    void *unkC;
    short unk10;
    short unk12;
    char pad14[0x8];
    unsigned short unk1C;
};
struct S_Ref {
    char pad0[0x4];
    int unk4;
    S_Buf *unk8;
};
struct S_Rect8 {
    short x, y, w, h;
};
struct S_Pt4 {
    short x, y;
};
struct S_Pt4c {
    short x, y;
    S_Pt4c(short a, short b) { x = a; y = b; }
};
struct S_80022AB4 {
    S_Rect8 r;
    S_Pt4 p;
    S_Pt4c sz;
    int unk10;
    int unk14;
    int unk18;
    S_80022AB4(S_Rect8 *a, S_Pt4 *b, int c, int d, int e) : r(*a), p(*b), sz(b->x - a->x, b->y - a->y), unk10(c), unk14(d), unk18(e) {}
};
struct S_Act {
    char pad0[0x4];
    int unk4;
    char pad8[0x4];
    unsigned char *unkC;
    char pad10[0x4];
    int unk14;
    int unk18;
};
struct S_IntVec {
    int *data;
    unsigned int count;
    void **vtbl;
};

EXTERN_C void *memset(void *p, int c, int n);
EXTERN_C void func_80024594(Holder *h);
EXTERN_C void *D_800105B4[];
EXTERN_C void func_800246C4(void *p, int flags);
EXTERN_C char D_800A4558[];
EXTERN_C int func_80019CFC(List *l, void *item);
struct S_80021ACC_D {
    short v[16];
};
struct S_80021ACC {
    char pad0[0xC];
    S_80021ACC_D m;
};
struct S_800244A4 {
    char pad0[0x4];
    int unk4[4];
    char unk14[0x10];
    char pad24[0x3];
    unsigned char unk27;
    Holder unk28;
};
struct S_800246EC {
    char pad0[0x4];
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

struct S_Clut {
    short v[256];
};
struct S_80021F48 {
    char pad0[0xC];
    S_Clut m;
};
struct S_AnimV {
    virtual void f1();
    virtual void f2(S_Pt4 pos, int a);
    virtual int f3();
};
struct S_AnimV2 {
    virtual void f1();
    virtual void f2(S_Pt4c pos, int a);
};
struct S_AnimNode {
    void **vtbl;
    S_AnimNode *next;
};
struct S_800210A4 {
    char pad0[0x10];
    S_AnimNode *unk10;
    S_AnimNode *unk14;
    int unk18;
    int unk1C;
    S_Pt4 unk20;
    int unk24;
};
struct S_80025268 {
    char pad0[0x10];
    short unk10;
    short unk12;
    char pad14[0x10];
    S_AnimNode *unk24;
    S_AnimNode *unk28;
    int unk2C;
    int unk30;
};
struct S_80024CA0 {
    char pad0[0xC];
    S_AnimV *unkC;
    S_Rect8 unk10;
    short *unk18;
    unsigned short unk1C;
    unsigned short unk1E;
};

EXTERN_C void func_8001D150(void *list, void *n);
EXTERN_C void *D_8001075C[];
EXTERN_C void *D_80010774[];
EXTERN_C void *D_80010338[];
EXTERN_C void *D_80010160[];
EXTERN_C void *D_800105F4[];
EXTERN_C void *D_8001060C[];
EXTERN_C void func_80023C40(char *p, int flags);
struct S_Evt338 : S_Obj178 {
    void *unk8;
    short unkC;
    int unk10;
    S_Evt338(void *a, short b, int c) { vtbl = D_80010338; unk8 = a; unkC = b; unk10 = c; }
};
struct S_Pal {
    void **vtbl;
    char pad4[0x8];
    unsigned short unkC[256];
};
struct S_80023B94 {
    void **vtbl;
    char pad4[0x20];
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    void *unk28;
    int data[5];
    unsigned char unk40;
    unsigned char unk41;
};
struct S_B160 {
    void **vtbl;
    int unk4;
    S_B160(int a)
    {
        char *g;
        vtbl = D_80010160;
        unk4 = a;
        char *l;
        g = (char *)&D_800AC57C;
        l = g ? g + 0xF8 : 0;
        func_8001D150(l, new S_Evt338(this, 0x80, 1));
    }
};
struct S_800225C0 : S_B160 {
    int unk8;
    S_800225C0(int a, int b) : S_B160(b) { vtbl = D_800105F4; unk8 = a; }
};
struct S_80022730 : S_B160 {
    int unk8;
    S_80022730(int a, int b) : S_B160(b) { vtbl = D_8001060C; unk8 = a; }
};

EXTERN_C void func_80025CE0(void *dst, void *src, int n);
EXTERN_C void *D_80010888[];
EXTERN_C void *D_80010840[];
EXTERN_C void *D_80010858[];
EXTERN_C void func_80024AF0(void *p, int flags);
EXTERN_C int func_800211F4(S_80021274 *p, int x);
struct S_Vec5 {
    void *unk0;
    int unk4;
    void *unk8;
    int data[5];
    S_Vec5(int n) { unk8 = data; unk0 = unk8; func_800198E0(unk8, n, 0); unk4 = 0; }
};
struct S_20C64 {
    void **vtbl;
    int unk4;
    S_Vec5 a;
    S_Vec5 b;
    short unk48;
    short unk4A;
    char pad4C[0x4];
    short unk50;
    short unk52;
};
struct S_SlotTbl {
    S_80021274 *arr;
    char pad4[0x4];
    short unk8;
    short unkA;
};
struct S_KeyV {
    virtual unsigned int hash();
    virtual int eq(void *v);
};
struct S_HNode {
    char pad0[0x4];
    S_HNode *next;
    void *unk8;
};
struct S_HTbl {
    S_HNode **data;
    unsigned int count;
};

EXTERN_C void func_80025714(void *list, void *p);
EXTERN_C void *D_800108A0[];
EXTERN_C void *D_80010118[];
EXTERN_C S_80021274 *func_80021144(S_80021274 *p);
EXTERN_C int func_80021294(S_80021274 *p, int x);
struct S_SlotRef {
    short a;
    short b;
    S_SlotRef() : a(0), b(0) {}
};
struct S_118 {
    void **vtbl;
    void *unk4;
    int unk8;
    S_118(void *a, int b) { vtbl = D_80010118; unk4 = a; unk8 = b; }
};
struct S_TexPool {
    S_80021274 *arr;
    S_Rect8 r;
    int unkC;
    void **unk10;
};

EXTERN_C int LoadImage(S_Rect8 *r, void *p);
EXTERN_C int func_80019C24(List *l, void *item);
struct S_VramV;
struct S_VramV {
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5(S_Pt4 pos);
};
EXTERN_C S_VramV *D_800B4C54[0];
struct S_TexImg {
    char pad0[0x4];
    S_VramV *unk4;
    char pad8[0x4];
    S_AnimV *unkC;
    S_Pt4 pos;
    S_Pt4 size;
    short *unk18;
    unsigned short unk1C;
    unsigned short unk1E;
    S_Pt4 getPos() { return pos; }
    S_Pt4 getSize() { return size; }
};
struct S_PadLv {
    char pad0[0x4];
    int unk4;
    char pad8[0x4];
    unsigned char *unkC;
    int unk10;
    int unk14;
    int unk18;
};

EXTERN_C void *func_8001A744(void *list, void *item);

EXTERN_C void *func_80023450(void *p);
EXTERN_C void func_8001EFE4(void *obj, void *e);
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void *D_80010300[];
EXTERN_C void *D_800102D0[];
EXTERN_C void func_8001A864(void *a, void *b);
struct S_Evt300b : S_Obj178 {
    unsigned short unk8;
    short unkA;
    void *unkC;
    int unk10;
    S_Evt300b(unsigned short a, short b, void *c, int d) { vtbl = D_80010300; unk8 = a; unkA = b; unk10 = d; unkC = c; }
};
struct S_Evt2D0b : S_Evt300b {
    S_Evt2D0b(unsigned short a, short b, void *c) : S_Evt300b(a, b, c, 0) { vtbl = D_800102D0; }
};
struct S_HNode734 : S_Obj178 {
    void *unk8;
    S_HNode734(void *k) { vtbl = D_80010734; unk8 = k; }
};

EXTERN_C int MoveImage(S_Rect8 *r, int x, int y);
EXTERN_C void DrawOTag(void *ot);
EXTERN_C int func_80098DA0(void *p);
struct S_Scroll {
    short x;
    short y;
    char pad4[0x4];
    unsigned short unk8;
    unsigned short unkA;
    char padC[0x4];
    int unk10;
    int unk14;
    int unk18;
};
struct S_21764 {
    char pad0[0x8];
    short unk8;
    short unkA;
    S_Scroll *unkC;
};
struct S_2510C {
    char pad0[0xC];
    S_AnimV *unkC;
    S_Pt4 pos;
    char pad14[0x8];
    unsigned short unk1C;
    char pad1E[0x6];
    S_AnimNode *unk24;
    S_AnimNode *unk28;
    int unk2C;
    int unk30;
};

EXTERN_C int func_80023CB8(void *p, int a, int b);
EXTERN_C void func_80020984(void *p, int a);
EXTERN_C void *D_80010588[];
inline void *S_first(List *l) { return l->count ? *(void **)*(void ***)l : 0; }
struct S_ItemV {
    virtual void f1();
    virtual int f2(int a);
    virtual int f3();
};
struct S_Grp {
    char pad0[0x25];
    unsigned char unk25;
    unsigned char unk26;
    signed char unk27;
    char unk28[0x18];
    unsigned char unk40;
};
struct S_C588n {
    void **vtbl;
    char pad4[0x10];
    int unk14;
    unsigned short unk18;
    unsigned short unk1A;
    S_C588n(void *a, unsigned short b)
    {
        func_8001FC38(this, 0x204, (int)a, 0);
        vtbl = D_800105DC;
        unk14 = 0;
        vtbl = D_80010588;
        unk18 = b;
        unk1A = 0;
    }
};

EXTERN_C int func_800209F4(void *p);
struct S_C588m {
    void **vtbl;
    char pad4[0x10];
    int unk14;
    unsigned short unk18;
    unsigned short unk1A;
    S_C588m(void *a, unsigned short b)
    {
        func_8001FC38(this, 0x205, (int)a, 0);
        vtbl = D_800105DC;
        unk14 = 0;
        vtbl = D_80010588;
        unk18 = ~b;
        unk1A = b;
    }
};

#endif /* GAME_A_H_U_80020B70_H */
