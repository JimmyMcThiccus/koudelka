#ifndef GAME_A_H_U_8002ED44_H
#define GAME_A_H_U_8002ED44_H

/* Declarations for src/main/u_8002ED44.cpp only. */

struct S_800AC834 { int a; int b; int c; int d; };
EXTERN_C S_800AC834 D_800AC834;
struct S_800313BC { int a; int next; };

struct S_IntVec { int *data; int count; };
struct S_Vec4s { short x, y, z, w; void clear() { x = 0; y = 0; z = 0; w = 0; } };
struct S_8002F558 { void **vt; S_Vec4s v; };
EXTERN_C void *D_80011A44[];
EXTERN_C void *func_800300C8(void *v, void *out);
EXTERN_C void func_80030EE0(void *p);
#define gte_ldv3c(r0) __asm__ volatile("lwc2 $0, 0(%0);lwc2 $1, 4(%0);lwc2 $2, 8(%0);lwc2 $3, 12(%0);lwc2 $4, 16(%0);lwc2 $5, 20(%0)" : : "r"(r0))
#define gte_ldv3m(v) __asm__ volatile("lwc2 $0, %0;lwc2 $1, %1;lwc2 $2, %2;lwc2 $3, %3;lwc2 $4, %4;lwc2 $5, %5" : : "m"((v)[0]), "m"((v)[1]), "m"((v)[2]), "m"((v)[3]), "m"((v)[4]), "m"((v)[5]))
#define gte_rtpt() __asm__ volatile("nop;nop;cop2 0x0280030")
struct S_8002FD5C_O { char pad[0x14]; int sv[6]; };
struct S_8002FD5C { int a; S_8002FD5C_O *o; };

struct VtE { short delta; short index; void *pfn; };
struct S_VObj { VtE *vt; };
#define VCALL0(o, k) ((void (*)(void *))(o)->vt[k].pfn)((char *)(o) + (o)->vt[k].delta)
#define VCALL0I(o, k) ((int (*)(void *))(o)->vt[k].pfn)((char *)(o) + (o)->vt[k].delta)
EXTERN_C void func_8002CC60(void *p);
struct S_8002F180 { char pad[0x10]; void *unk10; };
struct S_8002F5D0 { int a; S_VObj *o; };
struct S_Blk8 { unsigned char b[8]; };
struct S_Blk4 { unsigned char b[4]; };
EXTERN_C void *func_80030AA8(void *p, void *q, int *out);
struct S_8003212C_Q { char pad[0x2C]; S_Blk4 c2C; int unk30; };
struct S_8003212C_P { char pad[0x34]; S_Blk4 c34; };
struct S_8002F824 { void **vt; int unk4; S_8002F558 b; };
EXTERN_C void *D_80011AAC[];
EXTERN_C void *D_80011B14[];

EXTERN_C S_Blk8 func_800301BC(void *p);
EXTERN_C S_Blk8 func_80031030(void *p);
struct S_8002F90C { char pad[0xC]; S_Blk8 c; };
EXTERN_C void func_8002D94C(void *p);
struct S_8002F1BC { char pad[0x10]; void *unk10; void *unk14; };
inline void add_710(void *item) { List *l = &D_800AC710; func_80019A6C(l, (int)item, l->count); }
EXTERN_C int func_8001D25C(void *a, void *b);
EXTERN_C void func_8001D324(void *a, int b);
EXTERN_C void *D_80011E74[];
EXTERN_C char D_800A4544[];
EXTERN_C void *D_800118FC[];
EXTERN_C int func_80019CFC(void *l, void *item);
struct S_8002FCF4_Q { char a; signed char b1; char pad[2]; S_Blk8 c4; S_Blk8 cC[3]; };
struct S_80030AA8_Q { char a; signed char b1; char pad[2]; S_Blk8 c4; S_Blk8 cC[4]; };

EXTERN_C void *D_80011B8C[];
EXTERN_C void *D_80011BF4[];
EXTERN_C void *D_80011D04[];
EXTERN_C void *D_80011D6C[];
EXTERN_C void func_800A0D0C(void *p);
EXTERN_C void func_8002EADC(void *p);
EXTERN_C void func_8002EAE8(void *p);
EXTERN_C void func_8002D24C(void *p, void *rect);
struct S_Pt2 { short x, y; };
struct S_Rect8 { S_Pt2 pos; S_Pt2 size; };
EXTERN_C void func_8002D780(void *p, S_Pt2 pos);
struct S_8002F21C { char pad[8]; S_Rect8 rect; void *unk10; };
struct S_Obj44 { VtE *vt; char pad[0x40]; };
struct S_Obj68 { VtE *vt; char pad[0x64]; };
#define VCALL1(o, k, a) ((void (*)(void *, int))(o)->vt[k].pfn)((char *)(o) + (o)->vt[k].delta, a)
struct S_Tri_V { short x, y, z, pad; };
struct S_Tri { char pad[0xE]; short n; char pad10[4]; S_Tri_V v[3]; S_Tri_V e[3]; };

struct S_Pad14 { char pad[0x14]; };
struct S_Base14 { int x; };
struct S_Obj14 : S_Pad14, S_Base14 { };
EXTERN_C bool func_8002FEC8(S_Base14 *a, S_Base14 *b, S_Base14 *c, S_Base14 *d, S_Base14 *e);
EXTERN_C bool func_80030C70(S_Base14 *a, S_Base14 *b, S_Base14 *c, S_Base14 *d, S_Base14 *e);
EXTERN_C void *D_80011C44[];
EXTERN_C void *D_80011CAC[];
EXTERN_C void *D_80010338[];
EXTERN_C void func_8001D150(void *sched, void *timer);
struct S_Timer14 {
    void **vt;
    int unk4;
    void *unk8;
    short unkC;
    int unk10;
    S_Timer14(void *t, short d, int n) { vt = D_80010178; unk4 = 0; vt = D_80010338; unk8 = t; unkC = d; unk10 = n; }
};

struct S_Vec4sA { short x, y, z, w; };
struct S_8002FDA4 { void **vt; int unk4; S_8002F558 b; S_Vec4sA v[4]; };
struct S_Plane { char pad[0xC]; short nx, ny, nz, pad12; S_Tri_V v[4]; };
struct S_Mid34 { char pad[0x34 - 0x18]; };
struct S_Base34 { int x; };
struct S_Obj34 : S_Obj14, S_Mid34, S_Base34 { };
EXTERN_C int func_80032A9C(S_Base34 *a, S_Base34 *b, S_Base34 *c, S_Base34 *d, S_Base34 *e);

EXTERN_C int func_80026014(int a);
EXTERN_C int func_800260A4(int a);
EXTERN_C int ratan2(int y, int x);
struct S_Rect8s { short x, y, w, h; };

EXTERN_C void SetDispMask(int mask);
EXTERN_C void func_8002F028(void *p);
EXTERN_C int func_8002A3C0(void *p);
EXTERN_C void *func_8002E714(void *p, int n);
EXTERN_C void *D_800117A4[];
struct S_Lay {
    VtE *vt;
    char pad4[0x14];
    int unk18;
    int unk1C;
    short unk20[6];
    int unk2C;
    int unk30;
    char pad34[0x30];
    void *unk64;
    S_Lay(int a, int n, int b)
    {
        func_8002E714(this, n);
        *(void ***)&vt = D_800117A4;
        unk18 = a;
        unk1C = 0;
        unk20[0] = 0;
        unk20[1] = 0;
        unk20[2] = 0;
        unk20[3] = 0;
        unk20[4] = 0;
        unk20[5] = 0;
        unk2C = 0;
        unk30 = b;
        unk64 = 0;
    }
};
struct S_8002F338 { int a; void *unk4; S_Rect8 rect; int pad10; S_Lay *unk14; };

struct S_Obj2C { char pad[0x2C]; VtE *vt; };
struct S_Mid4 {
    int a;
    S_Obj2C *unk4;
    int prio() { S_Obj2C *o = unk4; return o ? ((int (*)(void *))o->vt[12].pfn)((char *)o + o->vt[12].delta) : 0; }
};
struct S_8002F028 { VtE *vt; S_Mid4 *unk4; S_Rect8 rect; S_Lay *unk10; };

EXTERN_C void *D_80011DBC[];
EXTERN_C void *D_80011E24[];
struct POLY_F4 { unsigned char tag[3]; unsigned char len; unsigned char r0, g0, b0, code; short xy[8]; };
struct S_80031280 { void **vt; S_80031280 *next; S_8002F558 b; S_Vec4sA v[4]; int c34; POLY_F4 prim[2]; };
struct S_Pool834 { int a; S_80031280 *free; int c; int d; };

EXTERN_C int *func_80030694(int *p);
struct S_80030534 {
    void **vt;
    int unk4;
    S_8002F558 b;
    S_Vec4sA v[3];
    int m2C[6];
    S_80030534();
};

#endif /* GAME_A_H_U_8002ED44_H */
