#ifndef GAME_A_H_U_80029BBC_H
#define GAME_A_H_U_80029BBC_H

/* Declarations for src/main/u_80029BBC.cpp only. */

struct VEnt { short d; short i; void *f; };
struct VObj { VEnt *vt; };
struct VObj2C { char pad0[0x2C]; VEnt *vt; };
struct S_80029BBC { char pad0[4]; unsigned char r, g, b, a; };
struct S_8002A064 { char pad0[0x10]; short w; short h; };
struct S_Node { int unk0; S_Node *unk4; VObj *unk8; char padC[8]; int unk14; int unk18; char pad1C[4]; int unk20; int unk24; int unk28; };
struct S_Pt { short x, y; };
struct S_Vec4 { int a, b, c, d; };

struct S_8002BBD4 { char pad0[0x30]; Holder unk30; };
EXTERN_C void func_80019F0C(List *l, void *a, int b);
struct S_8002AC2C { int unk0; S_8002BBD4 *unk4; };
struct S_8002C8CC { void *p; int n; void *q; int data[1]; };
struct S_Node2C { char pad0[4]; VObj2C *unk4; };
struct S_80029EC8 { char pad0[8]; VObj *unk8; char padC[4]; S_Rgb unk10; };
struct S_Vec4z { int a, b, c, d; S_Vec4z() { a = 0; b = 0; c = 0; d = 0; } };

struct S_Arr { VObj2C **items; int count; };
struct S_Coll {
    S_Arr *vb;
    int idx;
    void reset() { idx = 0; }
    VObj2C *next() { return idx < vb->count ? vb->items[idx++] : 0; }
    void toEnd() { idx = vb->count; }
    VObj2C *prev() { return idx > 0 ? vb->items[--idx] : 0; }
};
struct S_8002A728 { char pad0[0x10]; unsigned short type; };
struct S_W {
    int unk0;
    S_W *unk4;
    VObj *unk8;
    short x, y, w, h;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    VEnt *vt;
    S_Coll coll;
};

EXTERN_C void func_8002A118(S_Node *p);
EXTERN_C void func_8002A4C8(S_W *p, int x, int y);
EXTERN_C void func_8002A55C(S_W *p, int x, int y);

struct C_VB0 {
    virtual int v1(int); virtual int v2(int); virtual int v3(int); virtual int v4(int);
    virtual int v5(int); virtual int v6(int); virtual int v7(int); virtual int v8(int);
    virtual int v9(int);
};
struct C_VB : C_VB0 {
    C_VB *unk4;
};
struct C_VD : virtual C_VB {
    S_W *parent;
};

struct S_CollG {
    S_Arr *vb;
    int idx;
    void toEnd() { idx = vb->count; }
    VObj *prev() { return idx > 0 ? (VObj *)vb->items[--idx] : 0; }
};
EXTERN_C void func_80019D40(S_80019D40 *p);
EXTERN_C int D_800B4CF0;
EXTERN_C void func_8002EEC4(void *p, void *q);
EXTERN_C void func_8002EC90(void *p, void *q);
EXTERN_C char D_800B4C88[];
EXTERN_C void *D_8001199C[];
struct S_8002C498 { void **vt; char pad4[0x10]; int unk14; char pad18[4]; };
inline bool W_active(S_W *c)
{
    bool r = 0;
    if (c->unk8)
        r = c->unk28 != 0;
    return r;
}

struct S_XY { short x, y; S_XY() {} S_XY(short x_, short y_) { x = x_; y = y_; } };
inline List *coll_list(S_Coll *c) { return c ? (List *)c->vb : 0; }
inline Holder *coll_h(S_Coll *c) { return c ? (Holder *)((char *)c + 8) : 0; }

EXTERN_C int func_80019CFC(List *l, void *item);
EXTERN_C int func_80019C24(List *l, void *item);
EXTERN_C void func_8002F464(void *p);
inline void coll_end(S_Coll *c) { c->idx = coll_list(c)->count; }
inline void del_vb(void *c)
{
    if (c) {
        VObj *b = *(VObj **)c;
        VEnt *e = &b->vt[1];
        ((void (*)(void *, int))e->f)((char *)b + e->d, 3);
    }
}

#endif /* GAME_A_H_U_80029BBC_H */
