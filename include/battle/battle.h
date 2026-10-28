#ifndef BATTLE_BATTLE_H
#define BATTLE_BATTLE_H

/* Struct names are the address of the first function seen using them. Field
   names are offsets until their meaning is known. */

struct SVec2 {
    short x, y;
};
struct SVec4 {
    short x, y, z, w;
};

struct S_800BA418_448 {
    char pad[0x28];
};
/* Copied whole (func_800BA4A8, func_800BA4E4). */
struct S_800BA418_60 {
    int f0;
    int f4;
    int f8;
    char padC[0x54];
};
struct S_800BA6B4;
struct S_800BA418_3E8 {
    int f0;
    S_800BA6B4 *f4;
    int f8;
    int fC;
};
struct S_800BA418_3FC {
    int f0;
    S_800BA418_3FC *f4;
    signed char b8;
    char pad9[3];
    int fC;
};
struct S_800BA418_41C {
    char pad0[8];
    unsigned char b8;
    unsigned char b9;
    char padA[2];
    char fC[4];
};
struct S_800BA418 {
    char pad0[0x100];
    char b100;
    signed char b101;
    char pad102[2];
    S_800BA418_60 f104;
    S_800BA418_60 f164;
    char pad1C4[0x20];
    SVec4 f1E4;
    SVec4 f1EC;
    char pad1F4[0x84];
    int f278;
    char pad27C[0x10];
    short s28C;
    char pad28E[0x14C];
    short s3DA;
    char pad3DC[0xC];
    S_800BA418_3E8 f3E8;
    char f3F8[4];
    struct S_800BA418_3FC *f3FC;
    char pad400[0x1C];
    struct S_800BA418_41C *f41C;
    char pad420[4];
    char f424[0x24];
    S_800BA418_448 f448[1];
};

struct S_800BA6B4 {
    int pad0;
    int f4;
    signed char b8;
    char pad9;
    short sA;
    int fC;
    int f10;
    int f14;
};

struct S_800BC0E8 {
    int pad0;
    int f4;
    int f8;
    int fC;
};

struct S_800BE068 {
    int pad0;
    int f4;
    signed char b8;
    char pad9;
    unsigned short sA;
    int fC;
};

struct S_800CEA50 {
    char pad0[0xC];
    int fC;
    int f10;
    int f14;
};

struct S_800CFCB0 {
    char pad0[0x8C];
    int f8C;
    int f90;
    char pad94[0xC];
    int fA0;
};

/* Circular list head: next/prev point at itself when empty. */
struct S_800D00B8 {
    S_800D00B8 *next;
    S_800D00B8 *prev;
    int pad8;
    int fC;
    int f10;
    int f14;
};

struct S_800CFF68 {
    short s0;
    short s2;
    int f4;
};

/* GCC 2.x virtual base: the derived object holds a pointer to its List. */
struct List {
    int pad;
    int count;
};
struct Holder : virtual List {
};
inline int count_of(List *l) { return l->count; }

/* Opaque: vtables are only ever stored, never read, from C. */
struct VTable;

/* Polymorphic object as seen by the destructor/constructor bodies. */
struct T_VObj {
    VTable *vtbl;
    int f4;
    int f8;
    int fC;
};

struct T_CEE04 { char pad[0x7FC]; int f7FC[1]; };
struct T_D0054 { char pad[0x12C]; int f12C; };
struct T_D4E68 { char pad[0x2280]; int f2280; };
struct T_BFCB8 { char pad[0x52C]; int f52C; };
struct T_C1340 {
    char pad[0x2A0];
    char f2A0[0x170];
    short s410;
    char pad412[0x6E];
    short s480;
    char pad482[0x2C];
    char b4AE;
    char pad4AF[0xE];
    signed char b4BD;
    char pad4BE[0x12];
    int f4D0;
    char pad4D4[0x38];
    short s50C;
    char pad50E[0x2E];
    short s53C;
};
struct T_CE044_10 { int f0; void *p4; unsigned short h8; char padA[0xE]; };
struct T_CE044 { int pad0; int pad4; int f8; int fC; T_CE044_10 f10[1]; };
struct T_CFD98 { char pad[0x14]; int f14[1][5]; };
struct T_D5740 { char pad[0x20]; int f20; char pad24[0x48]; signed char b6C[1]; };
struct T_BC420 { char pad[0x4C0]; Holder h4C0; };
struct T_BB118 { char pad[0x14]; int *f14; int f18[35]; };
struct T_B9268 { char pad[0x4D0]; void *f4D0; char pad4D4[0x80]; T_BB118 *f554; T_BB118 *f558; };
struct T_BC270 { int pad0; void *f4; };
struct T_CFF44 { SVec2 f0; int f4; };
struct T_CFFB4 { SVec2 f0; int f4; short s8; };
struct T_C1A44 { int pad[3]; VTable *vtblC; };
struct T_C3D04 { char pad[0x516]; char b516; };
struct T_D4094 { char pad[0x52]; SVec4 f52; };
struct T_C9E58 { char pad[0x848]; int f848; int f84C[1]; };

/* vtables in BATTLE's .rodata and the EXE's */
EXTERN_C VTable D_800B6F6C[], D_800B6F84[], D_800B7054[], D_800B706C[], D_800B713C[], D_800B7154[],
    D_800B71B4[];
EXTERN_C VTable D_80010178[], D_80017904[];

/* EXE functions */
EXTERN_C void func_8001A610(void *p, int flags);
EXTERN_C void func_8001D024(void *p, int flags);
EXTERN_C void func_8005F120(void *p, int flags);
EXTERN_C void func_8005F440(void *p, int id);
EXTERN_C void func_80074E44(void *p, int flags);
EXTERN_C void func_80074F78(void *p, int flags);
EXTERN_C void func_800766D8(void *p);
EXTERN_C void *func_800787B4();

/* BATTLE functions */
EXTERN_C signed char func_800BA6D0(struct S_800BA6B4 *p);
EXTERN_C int func_800B9654(void *p);
EXTERN_C void func_800BB118(T_BB118 *p, int *t);
EXTERN_C void func_800BBC04(T_BB118 *p, int *t);
EXTERN_C void func_800BC0C0(T_VObj *p, int flags);
EXTERN_C void func_800C0694(void *p, int a);
EXTERN_C int func_800C1360(T_C1340 *p);
EXTERN_C int func_800C757C(void *p, int a);
struct T_CC110;
EXTERN_C int func_800CC110(T_CC110 *p);
EXTERN_C T_CE044_10 *func_800CE00C(T_CE044 *p);
EXTERN_C T_CE044_10 *func_800CE044(T_CE044 *p);
EXTERN_C T_CE044_10 *func_800CE090(T_CE044 *p);

EXTERN_C int D_800D5D78[];
EXTERN_C int D_800D5D7C;

struct T_VObj8 { VTable *vtbl; int f4; signed char b8; char pad9; short sA; int fC; };
struct T_D0404 { char pad[0x54]; int f54; int f58[3]; int f64; int f68; int f6C; int f70; };
struct T_CBA50 { char pad[0x908]; T_D0404 *f908; void *f90C; };
struct T_CF080 { char pad[0x808]; int f808[1]; };
struct T_CFE8C { SVec2 f0[0x23]; int f8C; int f90; };
struct T_D4718 { int pad[4]; int f10; char pad14[0x40]; SVec4 f54; };
struct T_C4748 { char pad[0x18]; short s18; short s1A; };
EXTERN_C VTable D_800B6F5C[], D_800B7374[];
EXTERN_C void func_8007F5B8(void *p, int a, int b);
EXTERN_C void func_800D0BCC(void *p);
EXTERN_C void func_800D0590(void *p);
EXTERN_C void func_800D0598(void *p);
EXTERN_C void func_800D0C88(void *p);
EXTERN_C void func_80076848(void *p, int a, int b, int c);
EXTERN_C void func_80042430(void *p, void *q, int a, int b);
EXTERN_C void func_80019D40(List *l);
EXTERN_C void func_80074F58(void *p);
EXTERN_C void func_8005F1D8(void *p);
struct T_C59B8 { int pad0; char f4[4]; };
struct T_C59B8_q { char pad[0x4A0]; char f4A0[4]; };
struct T_C5B18 { char pad[0xA4]; char fA4[4]; };
struct T_C5B18_q { char pad[0x4C4]; signed char b4C4; signed char b4C5; };
struct T_CDA94 { char pad[0x814]; int f814; };
struct T_CE00C_10 { char pad[0x18]; };
struct T_CE00C { int pad0; int pad4; int f8; int fC; T_CE00C_10 f10[1]; };
struct T_CEB5C { char pad[0x90C]; void *f90C; };
struct T_CFD2C { char pad[0x2C8]; char b2C8[1][5]; };
struct T_CFEBC_18 { int f[6]; };
struct T_CFEBC { char pad[0x3E8]; T_CFEBC_18 f3E8; };
struct T_D0338 { int pad0; int pad4; VTable *vtbl8; int fC; };
struct T_BA700 { VTable *vtbl; int f4; int f8; int fC; int f10; };
EXTERN_C VTable D_800B7778[];
EXTERN_C void func_8007505C(void *a, void *b);
EXTERN_C void func_800C51D0(void *a, void *b);
EXTERN_C void func_800766F8(void *p, int a, int b, int c, int d);
EXTERN_C void func_800C7764(void *p, int a, int b, int c, int d);
EXTERN_C T_D0338 *func_80074E28(T_D0338 *p);
EXTERN_C T_VObj *func_800BC094(T_VObj *p, int a, int b);

struct T_BC074 { char pad[0xB8]; int fB8; };
struct T_CDA8C { char pad[0x818]; int f818; };
struct T_CFCBC { char pad[0x848]; int f848; char pad84C[0xE8]; int f934; char pad938[0x18]; int f950; };
struct T_D1758 { char pad[0x5750]; int f5750; };
struct T_BE0F8 { int f0; int f4; };
struct T_CEBC4 { char pad[0x90C]; void *f90C; int f910; };
struct T_D2284 { char pad[0x2284]; char f2284[4]; };
struct T_VEC { int x, y, z, w; };
struct T_D2F54 { char pad[0x50]; char f50[0xFC]; int f14C; int f150; int f154; };
struct T_D596C { char pad[0x20]; int f20; };
struct T_4DD0 { char pad[0x1F6]; short s1F6; };
/* Incomplete arrays: retail splits these addresses itself (see docs/PARALLEL.md, Globals in overlays). */
EXTERN_C T_4DD0 *D_800B4DD0[];
EXTERN_C void func_80019A6C(List *l, int a, int n);
EXTERN_C void *func_800751AC(void *p);
EXTERN_C void func_8007669C(void *p, int a, int b);
EXTERN_C void func_8005783C(int a);
EXTERN_C void func_80068EE8(void *p);
EXTERN_C void func_8005457C(void *p, int a);
EXTERN_C void func_80054FE0(void *p);
EXTERN_C void func_80082E14(void *p, int a);
EXTERN_C void func_800566E4(void *p);
EXTERN_C void func_80055330(int a);
EXTERN_C void func_8005549C(int a, void *p, int b, int c);
EXTERN_C void func_80055624(void *p, int a);
EXTERN_C void func_8006323C(void *p);

struct T_BBC7C { VTable *vtbl; int f4; int f8; int fC; int f10; int f14; };
struct T_C59EC { int pad0; char f4[4]; };
struct T_Grids { char pad[0x2C8]; signed char b2C8[7][5]; char pad2EB[0x95]; char b380[7][5]; char b3A3[7][5]; };
struct T_C5AD0 { char pad[0xA0]; void *fA0; char fA4[4]; };
EXTERN_C VTable D_800B706C[], D_800B7154[];
EXTERN_C void *func_80085B28(void *p, int a);
EXTERN_C void func_80075004(void *a, void *b);
EXTERN_C T_VObj *func_800BC094(T_VObj *p, int a, int b);
EXTERN_C void *func_800C1A6C(void *p);
EXTERN_C int func_800C5A30(void *p, void *q);
EXTERN_C void func_800CADDC(void *p, int a);

struct T_CE9B8_x { char pad[0x410]; short s410; char pad412[0xE]; short s420; };
struct T_CE9B8 { int f0; T_CE9B8_x *p4; unsigned short h8; };
struct T_C5180 { char pad[0xC]; char fC[0x1C]; char f28[4]; };
/* List node; GCC 2.x puts the vptr after the first fields, at 8. Slot 1 is the virtual destructor.
   func_800751AC pops one off a list. */
struct T_Obj8 {
    T_Obj8 *next;
    T_Obj8 *prev;
    virtual ~T_Obj8();
};
struct T_C5124 : T_Obj8 { char padC[0x1C]; char f28[4]; };
struct T_CCD70 { char pad[0xA0]; T_C5B18_q *fA0; char padA4[0x224]; signed char b2C8[7][5]; };
struct T_Obj0 {
    virtual ~T_Obj0();
};
/* The popped node is a base at 0x4A0 of the object. */
inline T_Obj0 *func_800C1B48_pop(void *p) { char *r = (char *)func_800751AC(p); return r ? (T_Obj0 *)(r - 0x4A0) : 0; }
struct T_D401C_V { void **items; int count; };
struct T_D401C_M : virtual T_D401C_V {};
struct T_D401C_A { int a, b; };
struct T_D401C_D : T_D401C_A, T_D401C_M {};
struct T_D401C { char pad[0x30]; T_D401C_D *f30; };
struct T_C5474 { S_800D00B8 *f0; S_800D00B8 *f4; char pad8[0x124]; int f12C; };
EXTERN_C void exit(int code);
EXTERN_C void func_800B9A30(S_800BA418 *p, void *a, void *b, void *c);
EXTERN_C void func_800BA248(S_800BA418 *p);
EXTERN_C int func_800BA024(S_800BA418 *p);
EXTERN_C void func_800BA2F4(S_800BA418 *p);
EXTERN_C void func_800D044C(T_D0404 *p);
EXTERN_C T_D0404 *func_800D0404(T_D0404 *p);
EXTERN_C void func_800D0440(T_D0404 *p, int a, int b);
EXTERN_C void func_800C8D9C(void *p, int a, int *b, int *c);
EXTERN_C void func_800D4518(void *p);
EXTERN_C S_800D00B8 *func_800752B8(void *p, S_800D00B8 *x);
EXTERN_C void func_80054C34(void *p, int a);
EXTERN_C void func_80053964(void *p, int a);
EXTERN_C void func_800537DC(void *p, int a);
EXTERN_C int func_80053830(void *p);
EXTERN_C void func_800C78EC(void *p, int a);

struct T_BFB18 { char pad[0x1B8]; void *f1B8; };
struct T_BFB18_t { int f[4]; };
struct T_D00C8 { char pad[0x130]; S_800D00B8 nodes[10]; };
struct T_V0 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void *a);
};
struct T_BBCE8 { char pad[0x10]; T_V0 *f10; void *f14; };
struct T_BC3B4_item { char pad[0x1B8]; void *f1B8; };
struct T_BC3B4_A { int a, b; };
struct T_BC3B4_M : virtual List {};
struct T_BC3B4_X : T_BC3B4_A, T_BC3B4_M {};
struct T_BC3B4 { char pad[0x4C0]; T_BC3B4_X x4C0; char pad4D4[0xC]; T_BC3B4_item *f4E0; };
struct T_D0130_e { int f[4]; };
struct T_D0130 { char pad[0x10]; T_D0130_e e[16]; };
EXTERN_C void *func_8003912C(void *p, int a);
EXTERN_C void func_8003A150(T_BFB18_t *t, void *x, int a);
EXTERN_C void func_800C3FF4(void *p, int a, T_BFB18_t *t, int b, int c);
struct T_C5E1C;
EXTERN_C struct T_C1340 *func_800C5E1C(T_C5E1C *p, int a, int b);
EXTERN_C T_V0 *func_8003BEF8(void *p);
EXTERN_C void *func_800BBD60(void *p);
EXTERN_C T_BC3B4_item *func_80019F64(List *l, int i);
EXTERN_C void func_8008299C(void *p, int a, int b, int c, int d, int e, int f);
EXTERN_C void func_80085FD4(void *p);
inline void node_init(S_800D00B8 *l, int a, int b) { l->prev = l; l->next = l; l->fC = 1; l->f10 = a; l->f14 = b; }
EXTERN_C void *memset(void *p, int c, unsigned n);

struct T_CC1B0 { char pad[0x3D8]; T_CE044 f3D8; };
struct T_BF968 { char pad[0xF8]; int fF8; char padFC[0x24]; unsigned char b120; char pad121[0xFF]; short s220; char pad222[0x29E]; T_Obj0 *f4C0; char pad4C4[0x20]; signed char b4E4; };
struct T_D10D4 { char pad[0x54FC]; char f54FC[0x78]; char f5574[0x168]; char f56DC[4]; };
struct T_CA75C { char pad[0x2C8]; signed char b2C8[7][5]; char pad2EB[0x579]; int f864[36]; };
EXTERN_C void func_80054094(void *p, int a);
EXTERN_C void func_80068E60(void *p);
EXTERN_C int func_800B9758(void *p);
EXTERN_C int func_800B9844(void *p);
struct T_D0390_A { char pad[0xB8]; };
struct T_D0390_B { int pad[2]; T_CE9B8_x *items[3]; };
struct T_D0390_D : T_D0390_A, T_D0390_B {};
struct T_D0390_G { char pad[0x328]; T_D0390_D *f328; };
/* SVec2 built in place as an argument */
struct SVec2C { short x, y; SVec2C(short a, short b) { x = a; y = b; } };
struct T_D24E8_B {
    int pad[6];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(SVec2C v);
};
struct T_D24E8 : T_D24E8_B { char pad1C[0x40]; int f5C; };

struct T_C5E1C { char pad0[0x14]; T_C1340 *f14[7][5]; void *fA0; char fA4[0x334]; T_CE044 f3D8; };
EXTERN_C void func_80085A58(void *p);
EXTERN_C void func_800CDF64(T_CE044 *p, int i);
EXTERN_C int func_800CE110(T_CE044 *p, int key);
inline bool node_used(S_800D00B8 *l) { return l->fC == 1; }
inline bool in_grid(int a, int b) { if (a < 0 || b < 0 || a >= 5 || b >= 7) return false; return true; }

struct T_BE390 { char pad[0x26C]; int f26C; char pad270[8]; int f278; };
struct T_D0C90 { char pad[0x68]; int f68; };
struct T_CA710 { char pad[0x864]; int f864; char pad868[0xEC]; unsigned char b954; };
struct T_AF470 { char pad[0x384]; T_B9268 *f384; };
EXTERN_C T_BE390 *D_800B4ED8[];
EXTERN_C int D_800D5D80[];
EXTERN_C T_AF470 *D_800AF470[];
EXTERN_C void func_8006B850(void *p);
EXTERN_C void func_8006B740(void *p, int a);
EXTERN_C void func_8006B7D8(void *p, int a);
EXTERN_C void func_8006B814(void *p, int a);
EXTERN_C void func_80062280(void *p, int a);
EXTERN_C void func_8006323C(void *p);
EXTERN_C int func_800B9268(T_B9268 *p, int *t);

EXTERN_C VTable D_800B7538[];
struct T_C46F0 { VTable *vtbl; char pad4[0x34]; void *f38; };
EXTERN_C int D_800B4CF0[];
struct T_D47D0_e { short x, y; char pad[0x10]; };
struct T_D47D0_B {
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(int a, int b);
};
struct T_D47D0 : T_D47D0_B { char pad4[0x30]; T_D47D0_e e[2]; };

EXTERN_C short D_800B4DA6[];
EXTERN_C void func_80063714(void *p, int n);
EXTERN_C void func_800D1458(void *p);
struct T_D1148 { char pad[0x1C]; Holder h1C; };
EXTERN_C char D_800AFA74[];
EXTERN_C void func_80081820(void *p, int a, int b, int c, void *d, int e);
struct T_CF274 { char pad[0x2C4]; int f2C4; char pad2C8[0x66C]; int f934; };
struct T_CF95C_g { char pad[0x268]; int f268; int f26C; char pad270[8]; int f278; char pad27C[0x3C]; T_VEC v2B8; };
struct T_CF95C { char pad[0x3C6]; short s3C6; short s3C8; char pad3CA[0x572]; T_VEC v93C; int f94C; };
EXTERN_C void func_8006B690(void *p, int a);
EXTERN_C void func_800CF9CC(T_CF95C *p, int a, int b);
inline void set_g2(T_CF95C_g *g, T_VEC *v) { g->v2B8.x = v->x; g->v2B8.y = v->y; g->v2B8.z = v->z; g->f268 = 1; }
EXTERN_C void *D_800A4578[];
EXTERN_C void func_8002B27C(void *a, void *b);
EXTERN_C int func_80054E90(void *p);
EXTERN_C void func_80069958(void *p);
EXTERN_C void func_80056874(void *p);
EXTERN_C void func_8008EF40(int a);
struct T_D3CD4 { char pad[0x68]; char f68[0x2CC]; char f334[0x5C]; void *f390; };
struct T_D4748_e { short x, y; char pad[0x10]; };
struct T_D4748 { char pad[0x10]; int f10; char pad14[0x20]; T_D4748_e e[2]; };
struct T_D4748b { char pad[0x10]; int f10; char pad14[0x48]; short s5C; short s5E; };
EXTERN_C char D_800B7A98[], D_800B7AAC[], D_800B7ABC[];
EXTERN_C void func_80053BCC(void *p, char *s, int n);
struct T_D2A2C { char pad[0x60]; char f60[0x1C]; int f7C; };
EXTERN_C void *D_800B4C18[];
EXTERN_C void *func_800758F8(void *p, int a, void *b, void *c);
EXTERN_C void func_8001E848(void *a, void *b);
struct T_CEA80 { char pad[0x90C]; void *f90C; int f910; };

EXTERN_C VTable D_800B7768[];
struct T_D019C_e : T_Obj8 { char padC[0xC]; };
struct T_D019C { char pad[0xC]; VTable *vtblC; char pad10[0x120]; T_D019C_e nodes[10]; };
struct T_D1950_b { int pad[6]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); };
struct T_D1950_e : T_D1950_b { char pad1C[0x13C]; };
struct T_D1950 { char pad[0xD8]; T_D1950_e e[1]; };
struct T_4DD0b { char pad[0x1FB]; signed char b1FB; };
struct T_AFA58 { char pad[0x1B8]; int f1B8; char pad1BC[0x58]; short s214; };
EXTERN_C T_AFA58 *D_800AFA58[];
EXTERN_C void *D_800B4D40[];
EXTERN_C char D_800D5DAC[];
EXTERN_C void func_8007A400(void *p, int a);
EXTERN_C void func_80051E50(void *p);
EXTERN_C void func_800518A8(void *p, int a, void *b, int c);
struct T_CEC70 { char pad[0x7D8]; int f7D8; };
EXTERN_C char D_800B77D8[], D_800B7800[];
EXTERN_C void *func_800C5020(void *p, char *s, int n);
struct T_D0CC0 { char pad[0x68]; int f68; };
EXTERN_C int func_8005618C(void *q);
EXTERN_C T_BE0F8 *func_800BE09C(T_BE0F8 *t);
EXTERN_C T_BE0F8 *func_800BE108(T_BE0F8 *t, void *q);
EXTERN_C void func_800631D4(void *p);
EXTERN_C void func_80063340(void *p, void *q);
struct T_D19F0_q { char pad[0x18]; unsigned short h18; };
struct T_D19F0 { char pad[0x68]; char f68[4]; };
EXTERN_C int func_8008A2A0(void *p);
struct T_CF840_r { char pad[0x410]; short s410; };
struct T_CF840 { char pad[0xA0]; void *fA0; char padA4[0x738]; short s7DC; char pad7DE[0x52]; int f830; };
struct T_CF840_g { char pad[0x348]; int f348; };
EXTERN_C VTable D_800B7AFC[], D_800B7ACC[];
struct T_D2F94 { char pad[0x18]; VTable *vt18; char pad1C[0x34]; char f50[8]; VTable *vt58; char f5C[4]; char f60[0x20]; char f80[0x1C]; char f9C[0x1C]; char fB8[0x1C]; char fD4[0x28]; char fFC[0x28]; char f124[4]; };

struct T_D0230_n { int pad0, pad4; VTable *vtbl8; int fC; int pad10[2]; };
struct T_D0230 { char pad[0xC]; VTable *vtblC; char pad10[0x11C]; int f12C; T_D0230_n nodes[10]; };
struct T_D0BCC_o { int pad[6]; virtual ~T_D0BCC_o(); };
struct T_D0BCC { char pad[0x54]; T_D0BCC_o *f54; void *f58[3]; void *f64; };
EXTERN_C void func_800D119C(T_D0BCC_o *p);
EXTERN_C void *D_800A4578[];
EXTERN_C void func_8002B27C(void *a, void *b);
EXTERN_C void func_80054F30(void *p, int a, SVec4 *v, int b);
EXTERN_C void func_80054F5C(void *p);
struct T_D168C_b { int pad[6]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct T_D168C_e : T_D168C_b { char pad1C[0x13C]; };
struct T_D168C { char pad[0xD8]; T_D168C_e e[1]; };
struct T_4DD0c { char pad[0x1FB]; signed char b1FB; };
struct SVec4C { short x, y, z, w; SVec4C(short a, short b, short c, short d) { x = a; y = b; z = c; w = d; } };
EXTERN_C void func_8001FC78(void *p, int a, int b);
EXTERN_C int func_80058404(void *p, int a);
struct T_A4578 { char pad[0x1A4]; short s1A4; };
EXTERN_C T_BE0F8 *func_800BE0F8(T_BE0F8 *p, T_BE0F8 *q);
EXTERN_C void func_800D1148(T_D1148 *p);
struct T_D1A90 { char pad[0x20]; int f20; char pad24[0x18]; void *f3C; };
EXTERN_C void *func_800550BC(void *p);
EXTERN_C int func_8005409C(void *p);
EXTERN_C void func_80061F80(void *p, int a);
EXTERN_C void func_80068F3C(void *p, void *q);
EXTERN_C void func_8008EF40(int a);
struct T_D2598_b { int pad[6]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct T_D2598 : T_D2598_b { int f1C; int f20; char pad24[0x38]; int f5C; char pad60[0x221C]; int f227C; };
EXTERN_C void func_800824C8(void *p, int a);
EXTERN_C void func_800825FC(void *p, int a);
EXTERN_C void func_80085E74(void *p, int a);
struct T_CF764_q { char pad[0xA0]; char *fA0; };
struct T_CF764 { char pad[0x2A0]; char f2A0[4]; char f2A4[0x219]; char b4BD; char pad4BE[0x92]; unsigned char *f550; };
EXTERN_C void func_8005556C(int a, int b);
EXTERN_C void *D_800B4D5C[];
EXTERN_C int func_8008A54C(void *p, int a);
EXTERN_C int func_80068A5C(void *p);
EXTERN_C void func_800553D8(int a);
struct T_D1C50 { char pad[0x87C]; char f87C[0x2288]; char f2B04[0x2A70]; char f5574[4]; };
EXTERN_C void func_8005C088(void *p, int a, int b);
EXTERN_C void func_8005388C(void *p, int a);
EXTERN_C void func_8002DA94(int a, Holder *h);
struct T_D41D4 { char pad[8]; int f8; char padC[0x10]; unsigned short h1C; char pad1E[0x12]; Holder *f30; char pad34[4]; char f38[0xC]; int f44; char pad48[0xA]; SVec4 s52; };

EXTERN_C int func_80063744(void *p, int a);

struct T_D1B68_b { int pad[6]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct T_D1B68 : T_D1B68_b { char pad1C[0x5738]; int f5754; };
struct T_D2C50_s { char pad[0x400]; char f400[0x10]; short s410; short s412; char pad414[0xC]; short s420; short s422; };
struct T_D2C50_B { int pad[2]; T_D2C50_s *items[3]; };
struct T_D2C50_D : T_D0390_A, T_D2C50_B {};
struct T_D2C50_G { char pad[0x328]; T_D2C50_D *f328; };
struct T_D2C50 { char pad[0x7C]; int f7C; char pad80[0x54]; char fD4[0x50]; char f124[0x28]; void *f14C; void *f150; };
EXTERN_C void func_8008687C(void *p, int a);
EXTERN_C int func_800549C4(void *p, int a);
EXTERN_C void func_80064884(void *p, int a, int b);
EXTERN_C void func_800648E8(void *p, int a);
EXTERN_C void func_80054708(void *p, int a);
EXTERN_C void func_80054CE4(void *p);

struct T_VEntry { short delta; short index; void (*pfn)(void *); };
struct T_VTable10 { T_VEntry e[10]; };
struct T_VBase { T_VTable10 *vptr; };
EXTERN_C const T_VTable10 D_800B79A4, D_800B7C1C, D_800B7DEC;
EXTERN_C VTable D_800B7A14[], D_800B79F4[], D_800B7A44[], D_800B7D64[], D_800B7C6C[], D_800B7E5C[], D_800B7E3C[], D_800B7E8C[];
EXTERN_C void func_80069264(void *p, int a);
EXTERN_C void func_8005BDA4(void *p, int a);
struct T_D2670 { char pad[0x18]; VTable *vt18; char pad1C[0x34]; T_VBase *vb50; VTable *vt54; VTable *vt58; };
struct T_D4290 { T_VBase *vb0; char pad4[0x28]; VTable *vt2C; char pad30[8]; char f38[8]; VTable *vt40; };
struct T_D51FC { char pad[0x18]; VTable *vt18; char pad1C[0x34]; T_VBase *vb50; VTable *vt54; VTable *vt58; char pad5C[0x2228]; char f2284[0x50]; char f22D4[0x1C]; char f22F0[4]; };

EXTERN_C int func_800392C8(void *p);
struct T_CF9CC_q { char pad[0x1B8]; void *f1B8; };
struct T_CF9CC { char pad[0xA0]; T_CF9CC_q *fA0; };
inline void mk_vec(T_VEC *u, int x, int y, int z) { u->x = x; u->y = y; u->z = z; u->w = 0; }
EXTERN_C int rand();
EXTERN_C void func_800C5D84(void *p, int a);
struct T_CF2D0_r { char pad[0x94C]; unsigned char b94C; unsigned char b94D; };
struct T_CF2D0_g { char pad[0x33C]; int f33C; char pad340[8]; int f348; int f34C[1]; };
struct T_CF2D0 { char pad[0x7DC]; short s7DC; };

EXTERN_C char D_800B7EDC[];
EXTERN_C int func_80053880(void *p);
EXTERN_C void *func_800550BC(void *p);
EXTERN_C int func_8005409C(void *p);
EXTERN_C void func_8008EF40(int a);
EXTERN_C void func_80063340(void *p, void *q);
EXTERN_C int func_8005618C(void *q);
struct T_D59AC_f { char pad[0x50]; char f50[4]; };
struct T_D59AC : T_D2598_b { int f1C; int f20; char pad24[0x18]; T_D59AC_f *f3C; char pad40[0x1C]; int f5C; char pad60[8]; int f68; };
struct T_4DD0f { char pad[0x1F4]; short s1F4; };
struct T_CFB08_q { char pad[0x1B8]; void *f1B8; char pad1BC[0x30A]; short h4C6; short pad4C8; short h4CA; };
struct T_CFB08 { char pad[0xA0]; T_CFB08_q *fA0; };
EXTERN_C int func_800392C8(void *p);
EXTERN_C void func_8006B690(void *p, int a);
EXTERN_C VTable D_800104A8[];
EXTERN_C void func_8005BC84(void *p, int a, int b, int c);
EXTERN_C void func_800537C0(void *p);
struct T_D3ED0_vb { VTable *vptr; int f4; };
struct T_D3ED0 { T_VBase *vb0; char pad4[0x28]; VTable *vt2C; char pad30[8]; char f38[8]; VTable *vt40; int f44; int f48; int f4C; char b50; char pad51; SVec4 s52; char pad5A[2]; T_D3ED0_vb v5C; };
EXTERN_C char D_800AE640[];
EXTERN_C int func_80060154(void *p, int a);
EXTERN_C int func_800600A4(void *p, int a);
EXTERN_C void SetDrawMode(void *p, int a, int b, int c, void *r);
struct T_D43B0_e { char pad[3]; char b3; char pad4[2]; char b6; char b7; short s8; short sA; short sC; short sE; short s10; short s12; };
struct T_D43B0 { VTable *vt; char pad4[0xC]; int f10; char f14[0xC]; char f20[0xC]; T_D43B0_e e[2]; SVec4 s54; short s5C; short s5E; };
EXTERN_C void func_8005F0E4(void *p);
EXTERN_C VTable D_800B7D84[];
typedef void (*F4518)(void *, int);

struct T_BA594 { VTable *vtbl; int f4; int f8; T_Obj0 *fC; };
EXTERN_C VTable D_800B7184[], D_800B716C[], D_800B719C[];
EXTERN_C void func_80019920(void *p, int a);
struct T_BC310 { VTable *vtbl; char pad4[0x88]; VTable *vtbl8C; char pad90[0x68]; VTable *vtblF8; char padFC[0x3C4]; void *f4C0; };
struct T_BAD6C { VTable *vtbl; int f4, f8, fC; T_V0 *f10; int *f14; int f18[35]; };
EXTERN_C VTable D_80010300[], D_800102D0[], D_80010338[];
EXTERN_C char D_800A454C[];
EXTERN_C char *func_8001CA10(int n);
EXTERN_C void func_8001EFE4(void *a, void *b);
EXTERN_C void func_8001D150(void *a, void *b);
EXTERN_C void func_800198E0(void *l, int a, int b);
struct T_B8474 { int pad0; int f4; T_Obj0 *f8; };
struct T_B9844 { VTable *vtbl; int f4; short s8; short sA; void *fC; int f10; };
struct T_BC180 { VTable *vtbl; int f4; void *f8; short sC; short sE; int f10; };
struct T_BC294 { VTable *vtbl; char pad4[0x88]; VTable *vtbl8C; char pad90[0x68]; VTable *vtblF8; char padFC[0x3C4]; void *f4C0; int f4C4; void *f4C8; char f4CC[0x14]; void *f4E0; };
struct T_BCA6C_V {
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
};
struct T_BCA6C_p { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char r1, g1, b1, p1; short x1, y1;
    unsigned char r2, g2, b2, p2; short x2, y2; unsigned char r3, g3, b3, p3; short x3, y3; };
struct T_BCA6C : T_BCA6C_V { int f4; short s8; char padA[0x1A]; T_BCA6C_p prims[2]; };
struct T_BDE5C { VTable *vtbl; int f4; int f8; T_Obj0 *fC; };
EXTERN_C void func_80024FEC(void *p, int a);
EXTERN_C VTable D_800B6F2C[], D_800B6F14[], D_800B6F44[];
EXTERN_C void func_80051514(void *p, int flags);
EXTERN_C void func_8001E508(void *p, int flags);
struct T_B99A4 { VTable *vtbl; char pad4[0x88]; VTable *vtbl8C; char pad90[0x68]; VTable *vtblF8; char padFC[0x2EC]; T_BA594 f3E8; T_BDE5C f3F8; T_VObj f408; };
EXTERN_C void func_800B99A4(T_B99A4 *p, int flags);
EXTERN_C void func_800BDE5C(T_BDE5C *p, int flags);
EXTERN_C void func_800BA594(T_BA594 *p, int flags);
struct T_BC644_item { char pad[0x1B8]; void *f1B8; short s1BC; };
struct T_BC514_o { char pad[0x34]; T_VEC f34; };
struct T_BC514_item { char pad[0x1B8]; T_BC514_o *f1B8; };
EXTERN_C void func_80039DD8(void *p);
struct T_B8F5C_m { int f0; T_Obj0 *f4; int f8, fC; void clear() { if (f4) { delete f4; f4 = 0; } } };
struct T_B8F5C { char pad[0x3D8]; short s3D8; short s3DA; char pad3DC[0xC]; T_B8F5C_m m3E8; T_B8F5C_m m3F8; };
EXTERN_C VTable D_800B6DF4[];
EXTERN_C char D_800A4544[];
struct T_B84FC { VTable *vtbl; int f4; int f8; };
EXTERN_C VTable D_80011E8C[], D_80011EF4[], D_80011D04[], D_80011D6C[], D_80011AAC[], D_80011B14[];
EXTERN_C VTable D_800B6E64[], D_800B6E0C[], D_800B6F9C[], D_800B7004[], D_800B7084[], D_800B70EC[], D_800B7204[], D_800B726C[], D_800B72BC[], D_800B7324[];
EXTERN_C void func_800198AC(void *p, int flags);
struct T_B8778 { VTable *vtbl; int f4; VTable *vtbl8; };
inline void dtor_B8778(T_B8778 *p, VTable *v8, VTable *v0, int flags) {
    p->vtbl8 = v8; p->vtbl = v0;
    p->vtbl8 = D_80011E8C; p->vtbl = D_80011EF4;
    p->vtbl8 = D_80011D04; p->vtbl = D_80011D6C;
    p->vtbl8 = D_80011AAC; p->vtbl = D_80011B14;
    func_800198AC(&p->vtbl8, 0);
    func_8001A610(p, flags);
}
EXTERN_C VTable D_800B6EE4[], D_800B6ECC[], D_800B6EFC[];
EXTERN_C void func_8008E504(void *p);
EXTERN_C void func_800B8F5C(T_B8F5C *p);
EXTERN_C void func_800BC310(T_BC310 *p, int flags);
struct T_B8924_g { char pad[0x248]; void *f248; };
struct T_B8924 { VTable *vtbl; char pad4[0x88]; VTable *vtbl8C; char pad90[0x68]; VTable *vtblF8; char padFC[0x3EC]; void *f4E8; char pad4EC[0x24]; void *f510; char pad514[0x1C]; void *f530; };
struct T_B9480_n { int f0; T_B9480_n *next; int f8, fC; int f10; };
struct T_B9480_A { char pad[0x50]; };
struct T_B9480_B { int f0; };
struct T_B9480_g : T_B9480_A, T_B9480_B {};
EXTERN_C void func_80039C88(T_B9480_B *p, int a);
struct T_B9480 { char pad[0x40C]; T_B9480_n *f40C; char pad410[0x100]; Holder h510; };
struct T_BA248_e { T_VEC a; T_VEC b; int pad[2]; };
struct T_BA248 { char pad[0x2B4]; T_BA248_e e[3]; T_VEC n[3]; };
EXTERN_C void VectorNormal(T_VEC *a, T_VEC *b);
struct T_BCB6C_c { char pad[5]; unsigned char r, g, b; };
struct T_BD0A4_dm { int tag; struct { int c[2]; } code; };
struct T_BD0A4_pg { int tag; struct { int w[8]; } body; };
struct T_BD0A4 { VTable *vtbl; int f4; short s8; short sA; T_BD0A4_dm dm[2]; T_BD0A4_pg pg[2]; };
struct T_BA5FC_o { VTable *vtbl; int f4; short s8; short sA; };
struct T_BA5FC_g { int pad[4]; virtual void v1(T_BA5FC_o *o); };
struct T_BA5FC { VTable *vtbl; int f4; char b8; char pad9; short sA; T_BA5FC_o *fC; };
EXTERN_C T_BA5FC_g *D_800B4C38[];
EXTERN_C VTable D_800106EC[], D_80010624[];
EXTERN_C void func_80021F48(void *p, int a);
struct T_B89D4_A { char pad[0x124]; };
struct T_B89D4_B { int f0; };
struct T_B89D4_g : T_B89D4_A, T_B89D4_B {};
EXTERN_C void func_800B9480(T_B9480 *p);
EXTERN_C void func_800B9530(struct T_B9530 *p);
EXTERN_C int func_800BC180(void *p);
struct T_V4C { int x, y, z, w; T_V4C() {} T_V4C(int a, int b, int c, int d) { x = a; y = b; z = c; w = d; } };
inline T_V4C pos2_BC440(T_VEC *v) { T_V4C r(v->x, v->y, v->z, v->w); return r; }
struct LV { void **data; int count; int c, d; };
struct AV : virtual LV { int b; };
struct MV : virtual LV {};
struct XV : AV, MV {};
inline int lv_count(LV *l) { return l->count; }
inline void *lv_back(LV *l) { return l->count ? l->data[l->count - 1] : 0; }
EXTERN_C void func_80019CFC(LV *l, void *item);
struct T_B9758 { char pad[0x530]; XV x530; };
inline LV *lv_of(MV *m) { return m; }
struct T_B9654_o {
    virtual ~T_B9654_o();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(int a);
};
struct T_B9654 { char pad[0x510]; XV x510; };
EXTERN_C VTable D_80011A44[];
inline void *operator new(unsigned int, void *p) { return p; }
inline void *operator new[](unsigned int, void *p) { return p; }
struct SV4z { short x, y, z, w; SV4z() { x = 0; y = 0; z = 0; w = 0; } };
struct UV4 { char a[4]; UV4() {} };
struct PFT4 { char pad[3]; char len; char pad4[3]; char code; char pad8[0x20]; PFT4() { len = 9; code = 0x2C; } };
struct M34 { int code; UV4 uv[4]; PFT4 prims[2]; M34() : code(0x2C808080) {} };
struct T_BB190_base { VTable *vtbl; int f4; VTable *vtbl8; SV4z fC; SV4z f14[4]; M34 m34; };
struct T_BB190 : T_BB190_base { int f98; int f9C; };
inline void ctor_BB190(T_BB190_base *p) {
    p->vtbl = D_80010178;
    p->f4 = 0;
    p->vtbl8 = D_80011A44;
    new (&p->fC) SV4z;
    p->vtbl8 = D_80011AAC;
    p->vtbl = D_80011B14;
    new (p->f14) SV4z[4];
    p->vtbl8 = D_80011D04;
    p->vtbl = D_80011D6C;
    new (&p->m34) M34;
    p->vtbl8 = D_80011E8C;
    p->vtbl = D_80011EF4;
}
struct S24 { int a, b, c, d, e; unsigned short h0, h1, h2, h3; unsigned char c0, c1, c2, c3; int f; };
struct E28 { int w0, w1, w2, w3, w4, w5, w6, w7; unsigned char b0, b1, b2, b3, b4, b5, b6, b7; };
inline void cp_S24(S24 *d, S24 *s) {
    d->a = s->a; d->b = s->b; d->c = s->c; d->d = s->d; d->e = s->e;
    d->h0 = s->h0; d->h1 = s->h1; d->h2 = s->h2; d->h3 = s->h3;
    d->c0 = s->c0; d->c1 = s->c1; d->c2 = s->c2; d->c3 = s->c3; d->f = s->f;
}
inline void cp_E28(E28 *d, E28 *s) {
    d->w0 = s->w0; d->w1 = s->w1; d->w2 = s->w2; d->w3 = s->w3; d->w4 = s->w4; d->w5 = s->w5; d->w6 = s->w6; d->w7 = s->w7;
    d->b0 = s->b0; d->b1 = s->b1; d->b2 = s->b2; d->b3 = s->b3; d->b4 = s->b4; d->b5 = s->b5; d->b6 = s->b6; d->b7 = s->b7;
}
struct T_BA2F4 { char pad[0x290]; S24 f290; E28 e2B4[3]; char pad32C[0xF8]; S24 f424; E28 f448[3]; };
EXTERN_C void func_8001A864(void *a, void *b);
struct T_V2 { virtual void v1(); virtual void v2(); };
struct T_B8FF4_m { int f0; T_B9480_n *head; int f8, fC; };
inline void link_B8FF4(T_B8FF4_m *m, T_V2 *o) { if (m->head && o) func_8001A864(o, m->head); m->head = (T_B9480_n *)o; }
struct T_B8FF4 { char pad[0x278]; T_B9480_g *f278; char pad27C[0x18C]; T_B8FF4_m m408; char pad418[0x138]; T_V2 *f550, *f554, *f558, *f55C; };
EXTERN_C T_BA700 *func_800BA700(T_BA700 *p, int a);
EXTERN_C T_BBC7C *func_800BBC7C(T_BBC7C *p);
EXTERN_C void func_80039BEC(T_B9480_B *p, int a);
EXTERN_C int func_800B9FC4(S_800BA418 *p, signed char a);
struct T_B9530_g { char pad[0x254]; void *f254; };
struct T_B9530 { char pad[0x278]; T_B9530_g *f278; char pad27C[0x26C]; XV x4E8; int f504; int f508; int f50C; XV x510; int f52C; XV x530; };
EXTERN_C void func_8002DC34(void *a, void *b, int c);
inline LV *lv_ofx(XV *x) { return x; }
struct SV4C { short x, y, z, w; SV4C(short a, short b, short c) { x = a; y = b; z = c; w = 0; } };
struct T_BAFEC { char pad[0x14]; SV4C v[4]; };
struct T_BC704 { VTable *vtbl; int f4; short s8; short sA; T_BD0A4_dm dm[2]; T_BCA6C_p prims[2]; int f6C; };
EXTERN_C VTable D_800111BC[], D_800B71B4[];
EXTERN_C void SetDrawMode(void *p, int dfe, int dtd, int tpage, void *tw);
EXTERN_C void func_80098DC0(void *p, int abe);
EXTERN_C void func_800BCCEC(T_BCA6C *p, SVec2 *v);
EXTERN_C void func_800BCDC0(T_BCA6C *p, T_BCB6C_c *a, T_BCB6C_c *b, T_BCB6C_c *c, T_BCB6C_c *d);
EXTERN_C void func_800BCFC4(void *p);
struct T_BBD60 : T_BB190_base { SV4z v[4]; int fB8; };
struct T_BDEDC_V { virtual void v1(); virtual void v2(); virtual void v3(); };
struct T_BDEDC_o : T_BDEDC_V { int f4; VTable *vtbl8; void *fC; SVec2C f10; short s14, s16; int f18; short s1C; short s1E; };
struct T_BDEDC { char pad[0xA]; short sA; T_BDEDC_o *fC; };
EXTERN_C VTable D_80010888[], D_800108A0[];
EXTERN_C char D_800B4C48[];
EXTERN_C void func_80024BF0(void *p, void *a, short b, short c);
EXTERN_C void func_80025444(void *p, void *a, int b);
EXTERN_C void func_8002972C(T_BCB6C_c *p, int a, int b, int c, int d);
EXTERN_C struct T_BC704 *func_800BC704(struct T_BC704 *p, SVec2 *v, T_BCB6C_c *a, T_BCB6C_c *b, T_BCB6C_c *c, T_BCB6C_c *d, short e, short f, int g);
struct T_B92E0 { char pad[0x278]; T_B9530_g *f278; char pad27C[0x26C]; XV x4E8; int f504; void *f508; void *f50C; };
struct T_BAE04_c { virtual void v1(); virtual void v2(); virtual int v3(); };
struct T_BAE04_cc : T_BAE04_c { int f4; unsigned short h8; };
struct T_BAE04_o8 { char pad[0xC]; T_BAE04_cc *fC; short s10; short s12; char pad14[8]; unsigned short h1C; };
struct T_BAE04 { VTable *vtbl; int f4; T_BAE04_o8 *f8; int fC; T_V0 *f10; int *f14; int f18[35]; };
struct T_V6 { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); };
union T_UVU { struct { unsigned char u, v; } b; unsigned short h; void set(int u, int v) { b.u = u; b.v = v; } };
struct T_1F800000 { unsigned short uv; unsigned short s2; unsigned short s4; };
EXTERN_C T_1F800000 D_1F800000[];
EXTERN_C void func_800BAFEC(void *p, T_BAFEC *q, int n);
EXTERN_C void func_800BBAD4(void *p, T_BAFEC *q, int n);
EXTERN_C T_BB190 *func_800BB190(T_BB190 *p);
EXTERN_C T_BB190 *func_800BD164(T_BB190 *p);
struct T_PTAG { unsigned addr : 24; unsigned len : 8; };
struct T_OT { char pad[0x10]; unsigned int len; unsigned int *tbl; };
EXTERN_C T_OT *D_800B4CFC[];
inline void add_prim(unsigned int z, void *prim) {
    T_OT *ot = D_800B4CFC[0];
    if (z && z < ot->len) {
        ((T_PTAG *)prim)->addr = ot->tbl[z];
        ot->tbl[z] = (unsigned int)prim & 0xFFFFFF;
    }
}
struct T_BC878 : T_BCA6C_V { int f4; short s8; unsigned short sA; T_BD0A4_dm dm[2]; T_BCA6C_p prims[2]; int f6C; };
struct UVB { unsigned char u, v; };
union UVH { UVB b; unsigned short h; UVH() {} };
struct T_B8210 { char pad[0x9C]; UVH uv9C; };
EXTERN_C void func_800B8210(T_B8210 *p, UVB *a, UVB *b);
inline void call_B8210(T_B8210 *p, const UVH &a, const UVH &b) { func_800B8210(p, (UVB *)&a, (UVB *)&b); }
struct T_B7FFC : T_BB190_base { short s98, s9A; UVB uv9C; };
struct T_BA024_V { char pad[0x2C]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(short *a, int *b); };
struct T_BA024_V2 : T_BA024_V { char pad30[0x20]; };
struct T_CV { unsigned char r, g, b, cd; };
struct T_BA024_B { char pad0[0x2C]; short s7C, s7E, s80; short s82; int f84, f88, f8C; char pad40[0x78]; T_CV fB8; int fBC; };
struct T_BA024_G : T_BA024_V2, T_BA024_B { char pad110[0xC]; int f11C; };
struct T_BA024 { char pad[0x278]; T_BA024_G *f278; char pad27C[0x14]; int f290, f294, f298; int pad29C; int f2A0; unsigned short h2A4, h2A6, h2A8; short pad2AA; unsigned char b2AC, b2AD, b2AE, b2AF; int f2B0; E28 e2B4[3]; T_VEC n32C[3]; };
EXTERN_C void func_80099C80(int a);
EXTERN_C void func_80065D20(T_BA024_B *g, int i, int x, int y, int z, int r, int gg, int b);
EXTERN_C void func_80065E10(T_BA024_B *g, int i);
struct T_A4534 { int f0, f4, f8; volatile int fC; };
EXTERN_C T_A4534 D_800A4534;
struct T_MSG : T_V2 { int f4; short s8; unsigned short hA; int fC; int f10; };
struct T_B8AA8_s { char pad[0xB8]; short sB8; };
struct T_B8AA8_o : T_Obj0 { int f4, f8, fC, f10; T_B8AA8_s *f14; };
struct T_V3 { virtual void v1(); virtual void v2(); virtual void v3(); };
struct T_B8AA8 { char pad[0x274]; int f274; T_BE390 *f278; char pad27C[0x190]; T_B9480_n *f40C; char pad410[0xF8]; T_BCA6C *f508, *f50C;
    char pad510[0x40]; T_B8AA8_o *f550, *f554, *f558, *f55C; int f560, f564; T_V3 *f568; int f56C; };
EXTERN_C T_MSG *func_8001ED2C(void *p, int a, int b);
EXTERN_C int func_800B8EFC(S_800BA418 *p);
EXTERN_C void func_800B8FF4(T_B8FF4 *p);
EXTERN_C void func_8007F6C4(void *p);
EXTERN_C void func_8007F820(void *p);
EXTERN_C void func_8007F538(void *p, int *a, int *b, int c);
EXTERN_C void func_8006B5D4(void *p);
EXTERN_C void func_8006BDE0(void *p);
EXTERN_C T_V3 *func_800663EC(void *p, int a, void *b, int c, int d, int e);
EXTERN_C void func_800665C8(void *p);
EXTERN_C void func_80036D8C(void *p);
EXTERN_C void func_800BCA6C(T_BCA6C *p, short y);
EXTERN_C void func_800BCAEC(T_BCA6C *p, short y);
EXTERN_C void func_800BCB6C(T_BCA6C *p, T_BCB6C_c *c);
EXTERN_C void func_800BCC2C(T_BCA6C *p, T_BCB6C_c *c);

EXTERN_C int func_80054D78(void *p);
EXTERN_C void func_80054EB4(void *p, int a, int b);
EXTERN_C void func_80054FC0(void *p);
EXTERN_C void func_80054CA0(void *p);
struct T_D3D50_o { char pad[0x2C]; T_VEntry *vt2C; };
struct T_D3D50 { char pad[0x64]; unsigned f64; char pad68[0x2CC]; char f334[0x5C]; T_D3D50_o *f390; };
EXTERN_C void func_80068770(void *p, int a);
EXTERN_C void func_800557C8(void *p, int a, int b);
EXTERN_C void func_8006897C(void *p, int a, int b);
struct T_D20E0 { char pad[0x18]; VTable *vt18; char pad1C[0x34]; T_VBase *vb50; VTable *vt54; VTable *vt58; char pad5C[0x2220]; int f227C; T_D3ED0_vb v2280; };

struct T_D5074_x { char pad[0x1A]; char b1A; };
struct T_D5074_s { char pad[0x550]; T_D5074_x *f550; int f554; int f558; int f55C; };
struct T_D5074_B { int pad[2]; T_D5074_s *items[3]; };
struct T_D5074_D : T_D0390_A, T_D5074_B {};
struct T_D5074_G { char pad[0x328]; T_D5074_D *f328; };
struct T_D5074 : T_D2598_b { int f1C; int f20; char pad24[0x38]; int f5C; char pad60[0x221C]; int f227C; int f2280; };
EXTERN_C T_D5074_x *func_80061164(void *p, int a);
EXTERN_C void func_8008B150(void *s, void *x, int a, int b, int c);

struct T_D4E7C_x { char pad[0x1B]; unsigned char b1B; char pad1C[0x70]; unsigned char b8C; };
struct T_D4E7C_s { char pad[0x550]; T_D4E7C_x *f550; };
struct T_D4E7C_B { int pad[2]; T_D4E7C_s *items[3]; };
struct T_D4E7C_D : T_D0390_A, T_D4E7C_B {};
struct T_D4E7C_G { char pad[0x328]; T_D4E7C_D *f328; };
struct T_D4E7C_a { char d[0x6C]; };
struct T_D4E7C : T_D24E8_B { char pad1C[0x40]; int f5C; char pad60[0x3C]; T_D4E7C_a a9C[1]; };
struct T_D4E7C_c { char pad[0x1CF0]; unsigned short h1CF0; char pad1CF2[0x592]; char f2284[0x50]; char f22D4[0x1C]; char f22F0[4]; };
EXTERN_C void func_800540A8(void *p);
EXTERN_C int func_80068660(int *a, int *b, void *c);
EXTERN_C void func_80053CD8(void *p);

EXTERN_C const T_VTable10 D_800B7B6C;
EXTERN_C VTable D_800B7B3C[], D_800B7BBC[], D_800B7BDC[];
EXTERN_C void func_80056364(void *p, int in_chrg, int a, int b);
EXTERN_C void func_800694BC(void *p, int a, int b, int c);
EXTERN_C void func_80054AF0(void *p, int a);
EXTERN_C void func_800557C8(void *p, int a, int b);
EXTERN_C void func_80055020(void *p, SVec2C v);
EXTERN_C void func_80054EB4(void *p, int a, int b);
struct T_D3044_vb { VTable *vptr; int f4; };
struct T_D3044 { char pad[0x18]; VTable *vt18; char pad1C[0x34]; T_VBase *vb50; VTable *vt54; VTable *vt58; char pad5C[8]; int f64;
    char f68[0x2C4]; int f32C, f330; char f334[0x50]; int f384, f388, f38C, f390; T_D3044_vb v394; };
struct T_SPRT { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
struct T_D4518 { char pad[0x2C]; T_SPRT s[2]; };
struct T_D2D60_A : T_D1950_b { char pad1C[0x20]; void *f3C; char pad40[0x10]; };
struct T_D2D60_B { char pad[0x2C]; int f7C; char pad80[0x54]; char fD4[0x28]; char fFC[0x28]; char f124[0x28]; void *f14C, *f150, *f154; };
struct T_D2D60 : T_D2D60_A, T_D2D60_B {};
EXTERN_C void *func_800646FC(void *p, int a, SVec2 *v, int n);
EXTERN_C void func_8005800C(void *a, void *b);
EXTERN_C void *func_800D3ED0(void *p, int a, int b);
inline void sv2(SVec2 *v, short x, short y) { v->x = x; v->y = y; }
struct T_SPRTB { unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; };
struct T_SPRT2 { int tag; union { T_SPRTB b; struct { int w[4]; } body; }; };
struct T_D4968_A { char pad[0x50]; };
struct T_D4968_B { char pad[0x48]; SVec4 f48; };
struct T_D4968_g : T_D4968_A, T_D4968_B {};
inline T_D4968_B *as_b(T_D4968_g *g) { return g; }
struct T_D4968 { VTable *vt; int f4; short s8; unsigned short sA; int fC; int f10; T_BD0A4_dm dm[2]; T_SPRT2 s[2]; SVec4 f54; short h5C, h5E; };
struct T_MAT { short m[3][3]; short pad; int t[3]; };
EXTERN_C void func_8003A754(T_MAT *m, int a);
EXTERN_C void func_8003B168(void *a, SVec4 *b);
EXTERN_C void func_8003AD78(T_MAT *m, void *a);
EXTERN_C void SetRotMatrix(T_MAT *m);
EXTERN_C void func_8003B310(T_VEC *a, SVec4 *b);
EXTERN_C void func_8003B2F0(T_MAT *m, T_VEC *v);
EXTERN_C void SetTransMatrix(T_MAT *m);
EXTERN_C int RotTransPers(SVec4 *v, SVec2 *sxy, long *p, long *flag);
struct T_D5760_v { char pad[0x9C]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual int v10(int a); };
struct T_PK { unsigned short h __attribute__((packed)); };
inline int call_v10(T_D5760_v *o, int a) { return o->v10(a); }
struct T_D5760_s { char pad[0x400]; T_D5760_v v400[1]; char pad4A0[0xD8]; T_PK f578[1]; };
struct T_D5760_e1C { char pad[0x1C]; };
struct T_D5760_e28 { char pad[0x28]; };
struct T_D5760 { char pad[0x20]; int f20; char pad24[0x38]; int f5C; char pad60[0xC]; signed char b6C[15]; char pad7B;
    T_D5760_e1C e7C[15]; T_D5760_e28 e220[15]; T_D5760_e28 e478[15]; };
struct T_AEBD4 { char pad[0x1F]; unsigned char b1F; char pad20[0x6C]; };
EXTERN_C T_AEBD4 D_800AEBD4[];
EXTERN_C void func_80053F48(void *p, SVec2C v);
EXTERN_C int func_800549D8(void *p);
EXTERN_C int func_800D0390();
struct T_D1458_b { int pad[6]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(SVec2C v); };
struct T_D1458_e : T_D1458_b { char pad1C[0x13C]; };
struct T_D1458 { char pad[0x1C]; XV x1C; char pad38[0xA0]; T_D1458_e e[1]; };
struct T_D1458b { char pad[0x56F8]; XV x56F8; };
struct T_4DD0g { char pad[0x1FB]; signed char b1FB; };
EXTERN_C void func_800550FC(void *p, int n);
struct T_E1Cv { int pad[6]; virtual ~T_E1Cv(); };
struct T_E28v : T_E1Cv { char pad1C[0xC]; };
struct T_D321C { char pad[0x18]; VTable *vt18; char pad1C[0x34]; T_VBase *vb50; VTable *vt54; VTable *vt58; char pad5C[0xC];
    char f68[0x2C4]; T_E28v *f32C, *f330; char f334[0x50]; T_E1Cv *f384, *f388; T_E28v *f38C; };
EXTERN_C void func_80069B2C(void *p, int a);
EXTERN_C void func_8005652C(void *p, int a);
EXTERN_C const T_VTable10 D_800B7F1C, D_80014E0C;
EXTERN_C VTable D_800B7F8C[], D_800B7F6C[], D_800B7FBC[], D_80014E7C[], D_80014E5C[], D_80014EAC[];
inline void destroy28(T_E28v *a, int n) { if (a) { T_E28v *e = a + n; if (a != e) { T_E28v *b = a; do { --e; e->~T_E28v(); } while (b != e); } } }
inline void destroy1C(T_E1Cv *a, int n) { if (a) { T_E1Cv *e = a + n; if (a != e) { T_E1Cv *b = a; do { --e; e->~T_E1Cv(); } while (b != e); } } }
struct T_D5AE4 { char pad[0x18]; VTable *vt18; char pad1C[0x34]; T_VBase *vb50; VTable *vt54; VTable *vt58; char pad5C[0x20];
    T_E1Cv e7C[15]; T_E28v e220[15]; T_E28v e478[15]; };
struct T_D4BFC { char pad[0x18]; VTable *vt18; char pad1C[0x34]; T_VBase *vb50; VTable *vt54; VTable *vt58; char pad5C[0x2220];
    int f227C; int f2280; char f2284[0x50]; char f22D4[0x1C]; char f22F0[0x28]; T_D3044_vb v2318; };
EXTERN_C void func_80068770(void *p, int in_chrg);
EXTERN_C void func_8006897C(void *p, int a, int b);
EXTERN_C void func_80053928(void *p);
EXTERN_C void func_80054584(void *p, int a);
EXTERN_C void func_8005408C(void *p, int a);
EXTERN_C void func_80054E18(void *p, void *q);
inline void f30c(void *p, int a, const SVec4C &v, int b) { func_80054F30(p, a, (SVec4 *)&v, b); }
EXTERN_C char D_800B7A84[], D_800B7A8C[], D_800B7A94[];
EXTERN_C void func_800537C0(void *p);
EXTERN_C void func_800538CC(void *p, char *s, int n);
struct T_D2778 { char pad[0x18]; VTable *vt18; char pad1C[0x34]; char f50[8]; VTable *vt58; int f5C; char f60[0x1C]; int f7C;
    char f80[0x1C]; char f9C[0x1C]; char fB8[0x1C]; char fD4[0x28]; char fFC[0x28]; char f124[0x28]; void *f14C, *f150, *f154; };
typedef void *(*F_EFF)(void *a, short b, void *c, const T_V4C &v, int e);
EXTERN_C F_EFF D_800DA870[], D_800DBB90[], D_800DCEB0[];
EXTERN_C char D_800B772C[];
EXTERN_C void func_8007B1FC(void *a, void *b, int c);
struct T_CEE18_s { char pad[0x214]; short s214; char pad216[0x2A6]; char b4BC; };
EXTERN_C void func_800DA400(T_CEE18_s *s, void *q, int a);
struct T_CEE18 { char pad[0x7D8]; void *f7D8; char pad7DC[2]; short s7DE[7]; SVec2 xy7EC[7]; char *f808[3]; };

EXTERN_C T_C1340 *D_800AFA64[];
EXTERN_C int func_800C13CC(void *p);
EXTERN_C int func_800C07F8(void *p, int a);
struct T_CAD5C_q { char pad[0x514]; short s514; };
struct T_CAD5C { char pad[0xA0]; T_CAD5C_q *fA0; char padA4[0x85C]; int f900; };
struct T_C5D84 { char pad[0x4C6]; short s4C6; short pad4C8; short s4CA; };
/* battle.h declares func_800C5D84 as void(void *, int); retail returns the removed object. */
EXTERN_C T_C5D84 *func_800C5D84_r(T_C5E1C *p, int a) __asm__("func_800C5D84");
struct T_C8EE4 { char pad[0x2C8]; signed char b2C8[1][5]; };
typedef int (*F_C8D9C)(void *p, int a, int *b, int *c);
struct T_C65C8 { char pad[0xA0]; char *fA0; T_C5474 fA4; };
typedef void (*F_C51D0)(void *a, void *b, int c);
EXTERN_C char *func_800C5474(T_C5474 *p);
EXTERN_C void func_800D94F4(void *p);
EXTERN_C void func_800D05C4(T_D0404 *p);
struct T_CCB98 { SVec2 f0; int pad4; int pad8; int fC; int f10; int f14; };
EXTERN_C char D_800B75F0[], D_800B7620[];
EXTERN_C void func_80078C38(void *p, char *fmt, int a, int b, int c, int d, int e, int f, int g, int h, int i);
struct T_C757C { char pad[0x2C4]; int f2C4; };
struct T_C9284 { char pad[0x410]; short s410; char pad412[0xAB]; signed char b4BD; char pad4BE[7]; signed char b4C5; short s4C6; short s4C8; short s4CA; char pad4CC[0x47E]; unsigned char b94A; };
struct T_L2EC {
    SVec2 f0[0x23]; int f8C; int f90;
    void reset() { f8C = 0; f90 = 0; }
    void push(SVec2C v) { f0[f8C++] = *(SVec2 *)&v; }
};
EXTERN_C void func_800C7F30(T_Grids *p, char v);
EXTERN_C int func_800B928C(T_B9268 *p, int *t);
struct T_C9A4C {
    char pad[0x14]; T_C9284 *f14[7][5]; T_C9284 *fA0; char padA4[0x224]; signed char b2C8[7][5]; char pad2EB;
    T_L2EC l2EC; signed char b380[7][5]; signed char b3A3[7][5]; char pad3C6[0x47E]; int f844; int f848; void *f84C[1];
};
EXTERN_C void func_800CA9D0(T_C9A4C *p, int a, int b);
struct SVec2I { short x, y; SVec2I(int a, int b) { x = a; y = b; } };
EXTERN_C void func_800C800C(void *p, SVec2I v, int a, int b, int c);
EXTERN_C void func_800C7D88(T_Grids *p);
EXTERN_C bool func_800C8A54(T_C9A4C *p, int x1, int y1, int x, int y);
EXTERN_C void func_800CE4E4(T_L2EC *l, SVec2C v, int a);
/* func_800CE4B4 is defined returning int in battle.cpp; the caller's codegen needs a bool return. */
EXTERN_C bool func_800CE4B4_b(T_L2EC *p) __asm__("func_800CE4B4");
inline bool l2ec_next(T_L2EC *l) { if (!func_800CE4B4_b(l)) return false; return true; }
inline void add_cell(T_C9A4C *p, int x, int y) {
    if (in_grid(x, y) && !p->b2C8[y][x]) { p->b380[y][x] = 1; p->f84C[p->f848++] = p->f14[y][x]; }
}
struct T_CB8EC_k { int f0; T_CB8EC_k(int v) { f0 = v; } };
EXTERN_C T_BE0F8 *func_800BE0F8(T_BE0F8 *p, T_BE0F8 *q);
inline T_BE0F8 *put(T_BE0F8 *t, const T_CB8EC_k &k) { return func_800BE0F8(t, (T_BE0F8 *)&k); }
struct T_CB8EC { char pad[0x3D0]; int f3D0; };
struct T_CDD0C_v {
    short x, y;
    T_CDD0C_v() { x = 0; y = 0; }
    T_CDD0C_v(short a, short b) { x = a; y = b; }
    bool operator!=(const T_CDD0C_v &o) const { return x != o.x || y != o.y; }
};
/* The empty destructor matters: temporaries then get EH cleanups, which reserves the 16-byte outgoing-arg area even in leaf functions. */
struct T_CDD0C_e {
    T_CDD0C_v f0; int f4; short s8; char padA[0xE];
    T_CDD0C_e() { f0 = T_CDD0C_v(); f4 = 0; s8 = 0; }
    T_CDD0C_e(const T_CDD0C_v &v) { f0 = v; f4 = 0; s8 = 0; }
    T_CDD0C_e(const T_CDD0C_v &v, int a) { f0 = v; f4 = a; s8 = 0; }
    ~T_CDD0C_e() {}
};
struct T_CDD0C { int f0; int f4; int f8; int fC; T_CDD0C_e f10[41]; T_CDD0C_e f3E8; };
struct T_CDD0C2 {
    int f0; int f4; int f8; int fC; T_CDD0C_e f10[41]; T_CDD0C_e f3E8;
    T_CDD0C2() __asm__("func_800CDD0C");
};
EXTERN_C int func_800C7DD0(void *p, int h, int a, int b);
EXTERN_C void func_800C8EE4(T_C8EE4 *p, int a);
EXTERN_C void func_800C7B5C(void *p, int a, void *b, int x, int y);
EXTERN_C void *func_80085AD4(void *p, short x, short y);
/* battle.h declares func_800C78EC as void; retail returns the count. */
EXTERN_C int func_800C78EC_i(T_C9A4C *p, int a) __asm__("func_800C78EC");
inline void place(T_C9A4C *p, int a, int b, int c) { p->b2C8[b][a] = 0; func_800C7764(p, a, b, 1, c); }
struct T_C6050_c { char pad[0x400]; char f400[0x80]; unsigned short h480; char pad482[0x2B]; char b4AD; char b4AE; char pad4AF; int f4B0; int f4B4; short s4B8; };
struct T_C6050_n { T_C6050_n *next; T_C6050_n *prev; int pad8; int fC; };
struct T_C6050 { char pad[0xA4]; T_C5474 fA4; char pad1D4[0x65C]; int f830; };
EXTERN_C void func_80086E14(void *p);
EXTERN_C void func_800D8FF8(void *p);
EXTERN_C void func_800C6194(T_C6050 *p);
inline void c6050_reset(T_C6050 *p, T_C6050_c *c) {
    func_80086E14(c->f400);
    c->f4B0 = 3; c->s4B8 = 0; c->f4B4 = 0; c->b4AD = 0; c->b4AE = 0;
    func_800D8FF8(c->f400);
    ((F_C51D0)func_800C51D0)(&p->fA4, c, c->h480);
}
struct T_CA7D4 { char pad[0xA0]; T_C9284 *fA0; char padA4[0x850]; int f8F4[24]; unsigned char b954; unsigned char b955; };
EXTERN_C void func_800CA918(void *p, int a);
inline bool moved(T_C9284 *q, int x, int y) { return x != q->s4C6 || y != q->s4CA; }
EXTERN_C void func_800C8BA4(T_C9A4C *p, int x1, int y1, int x, int y);
/* battle.h declares func_800C7764 with void *p; the cast copy changes register allocation. */
EXTERN_C void func_800C7764_t(T_C9A4C *p, int x, int y, int d, int max) __asm__("func_800C7764");
struct T_CC7DC_q { char pad[0x4D8]; int f4D8; };
struct T_CC7DC_e {
    T_CDD0C_v f0; void *f4; unsigned short h8; short sA; int fC; int f10; int f14;
    bool at(const T_CDD0C_v &v) { return f0.x == v.x && f0.y == v.y; }
};
struct T_CC7DC { char pad[0x14]; T_C9284 *f14[7][5]; T_CC7DC_q *fA0; char padA4[0x2DC]; signed char b380[7][5]; char pad3A3[0x35]; T_CE044 f3D8; };
inline T_CC7DC_e *cc7dc_first(T_CC7DC *p) { return (T_CC7DC_e *)func_800CE044(&p->f3D8); }
inline T_CC7DC_e *cc7dc_next(T_CC7DC *p) { return (T_CC7DC_e *)func_800CE090(&p->f3D8); }
EXTERN_C void func_800CA7D4(T_CA7D4 *p, int a, int x, int y, int e);
struct T_C9FFC_in { char pad[0x1A]; unsigned short h1A; };
struct T_C9FFC { char pad[0xA0]; T_C9284 *fA0; char padA4[0x322]; T_CDD0C_v s3C6; char pad3CA[2]; int f3CC; int f3D0; };
EXTERN_C void func_800CF95C(T_CF95C *p);
EXTERN_C int func_800CA1B4(T_C9FFC *p, T_CDD0C_v *pos, int dir, int a, int b);
inline int c9ffc_move(T_C9FFC *p, int dir, int arg) {
    int d = (dir - p->f3CC + 8) % 8 / 2;
    if (func_800CA1B4(p, &p->s3C6, d, arg, 0) < 0) { func_8008EF40(14); return 0; }
    func_800CA7D4((T_CA7D4 *)p, 1, p->s3C6.x, p->s3C6.y, 1);
    func_8008EF40(8);
    func_800CF9CC((T_CF95C *)p, p->s3C6.x, p->s3C6.y);
    return 1;
}
inline int c9ffc_dir(T_C9FFC *p, int b, int arg) {
    int dir;
    if (b & 0x10) dir = 0;
    else if (b & 0x20) dir = 2;
    else if (b & 0x40) dir = 4;
    else if (b & 0x80) dir = 6;
    else return 0;
    return c9ffc_move(p, dir, arg);
}
struct T_CE154_k {
    T_CDD0C_v pos; int f4;
    T_CE154_k() {}
    T_CE154_k(T_CDD0C_v v) : pos(v) { f4 = 0; }
    T_CE154_k(int a) { f4 = a; }
};
EXTERN_C int func_800CE854(T_CE154_k *k, T_CDD0C_e *a, T_CDD0C_e *b);

/* battle.h declares these with other signatures; retail returns the first arg (BE09C, BE108)
   and C1A6C takes a second arg. Landing: change battle.h to the declarations below. */
EXTERN_C T_BE0F8 *func_800BE09C(T_BE0F8 *p);
EXTERN_C T_BE0F8 *func_800BE108(T_BE0F8 *p, void *q);
EXTERN_C void *func_800C1A6C_2(void *p, int team) __asm__("func_800C1A6C");
EXTERN_C void *func_800C5020(void *p, char *s, int n);
struct T_C0694;
EXTERN_C int func_800C0694_t(struct T_C0694 *p, int a) __asm__("func_800C0694");
struct T_BE208 { int v[6]; };
EXTERN_C T_BE208 *func_80062118(void *p);
EXTERN_C void func_80062120(void *p, void *src);
EXTERN_C void func_800BE29C(int *p, int a);
EXTERN_C void func_800BE2EC(int *p, int a);
struct T_BE108 { char pad[0x18]; unsigned short h18; };
struct T_C19BC { char pad[0x1B8]; void *f1B8; char pad1BC[0x2D4]; unsigned short h490; char pad492[0x2A]; signed char b4BC; char pad4BD[0x13]; T_C19BC *f4D0; char pad4D4[0x38]; short s50C; char b50E; };
struct T_C18B4_328 { char pad[0xB8]; char fB8[0x5C]; void *f114; };
struct T_BF414_b { char pad[8]; T_AFA58 *f8[3]; };
struct T_BF414_x { T_AFA58 *e[6]; };
struct T_C1924_e { unsigned char a, b, c, d; };
struct T_C19BC_g { char pad[0x328]; T_C18B4_328 *f328; void *f32C; char pad330[0x80]; T_C1924_e e3B0[32]; };
EXTERN_C void func_800C18B4(T_C19BC *p, int x);
struct T_C435C { int pad0, pad4; int f8; char padC[0x24]; Holder *f30; char pad34[0x10]; char f44[8]; int f4C; int f50; };
struct T_C4510;
EXTERN_C T_C4510 *func_800C4510(T_C4510 *p, SVec4 *pos, int a, int flags);
struct T_C5A30_q { char pad[0x4A0]; char f4A0[4]; char pad4A4[0x20]; signed char b4C4; char pad4C5; short s4C6; short s4C8; short s4CA; };
EXTERN_C char *func_80075448(void *a, void *b);
EXTERN_C void func_80085A60(void *q, SVec2C v);
struct T_It {
    S_800D00B8 *head;
    S_800D00B8 *cur;
    bool empty() { return head == 0; }
    bool last2() { if (empty()) return false; return head->prev == cur; }
    bool is_last() { if (head == 0) return false; return head->prev == cur; }
    void next() { if (!empty()) { if (!last2()) cur = cur->next; } }
};
struct T_C55C4_e { short s0; char b2; signed char b3; };
struct T_C55C4_o { char pad[0x4BC]; signed char b4BC; };
inline int team_of(void *o) { return ((T_C55C4_o *)o)->b4BC; }
struct T_C55C4 : T_It { char pad8[0x108]; T_C55C4_e e110[7]; };
EXTERN_C VTable D_800B7384[];
struct T_BE6B8 { VTable *vtbl; T_Obj0 *f4; T_Obj0 *f8[7]; short s24; short s26; };
struct T_C1158_v { char pad[0x2C]; SVec4 v2C; T_VEC f34; };
EXTERN_C int SquareRoot0(int a);
EXTERN_C int func_80026014(int a);
EXTERN_C int func_800260A4(int a);
struct T_C1158 { char pad[0x1B8]; T_C1158_v *f1B8; char pad1BC[0xE4]; char f2A0[0x230]; T_C1158 *f4D0; };
EXTERN_C int ratan2(int y, int x);
struct T_C47D8_10 { short s[6]; };
struct T_C47D8_1C { int a, b, c; };
struct T_C47D8 { VTable *vtbl; int f4; short s8; short sA; int fC; SVec4 f10; SVec2 f18; T_C47D8_1C f1C[2]; int f34; int f38; };
EXTERN_C VTable D_800111BC[], D_80014BD0[];
struct T_C1E44 { char pad[0x400]; char f400[0x112]; char b512; char b513; };
EXTERN_C int func_80089024(void *p);
EXTERN_C int func_8008906C(void *p);
EXTERN_C int func_800890B4(void *p);
struct T_C5020 { char pad[8]; VTable *vtbl8; char fC[0x1C]; char f28[4]; };
EXTERN_C VTable D_800B75A0[];
EXTERN_C void func_800537C0(void *p);
EXTERN_C void func_800538CC(void *p, char *s, int a);
EXTERN_C void func_80054AF0(void *p, int a);
EXTERN_C void func_80053FB0(void *p, int a, int b);
EXTERN_C void func_80054E18(void *p, void *q);
EXTERN_C void func_80055020(void *p, SVec2C v);
EXTERN_C void func_80054EB4(void *p, int a, int b);
EXTERN_C void func_80054FC0(void *p);
struct T_C5880_e { char pad[0x18]; };
struct T_C5880 { VTable *vtbl; char f4[0xA0]; T_D019C fA4; char pad2C4[0x124]; T_C5880_e a3E8[41]; char pad7C0[0x148]; void *f908; };
EXTERN_C VTable D_800B7748[];
inline void reset_nodes(T_D0054 *p) { S_800D00B8 *l; while ((l = (S_800D00B8 *)func_800751AC(p)) != 0) { l->prev = l; l->next = l; l->fC = 0; } p->f12C = 0; }
EXTERN_C void func_800C1BA8(void *p);
EXTERN_C void func_800D0074(T_D0054 *p);
EXTERN_C void func_800D0588(void *p);
EXTERN_C void func_800C1A44(T_C1A44 *p, int flags);
struct T_BEE50 { char pad[0x10]; unsigned char b10, b11, b12, b13; char pad14[0x10]; unsigned char b24; };
struct T_BEE50_r { unsigned char x, y; short al[0]; };
struct T_BF76C { char pad[0x2A0]; char f2A0[0x160]; char f400[0x80]; unsigned short h480; char pad482[0x32]; int f4B4; unsigned short h4B8; };
EXTERN_C void func_800D8F98(void *p);
EXTERN_C void func_800CAAF8(void *g, void *p, SVec2 *v);
struct T_BF5FC;
EXTERN_C void func_800BF414(T_BF5FC *p);
EXTERN_C int func_800BF5FC(T_BF5FC *p);
struct T_C0694_B {
    char pad[0x9C];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(int a);
};
struct T_C0694 { char pad[0x2A0]; char f2A0[0x160]; char f400[0xAD]; char b4AD; char pad4AE[0xF]; signed char b4BD; char pad4BE[0x12];
    int f4D0; int f4D4; int f4D8; char pad4DC[0x30]; short s50C; char pad50E[0x2E]; short s53C; short s53E; char pad540[0x38]; unsigned char b578[1];
    int bits(int i) { unsigned char *q = &b578[i * 2]; return (unsigned)(q[1] << 8 | q[0]) >> 10; } };
struct T_C0694_e { unsigned char lo, hi; };
inline int e_bits(T_C0694_e *e) { return (unsigned)(e->hi << 8 | e->lo) >> 10; }
EXTERN_C int func_800C9D6C(void *g, void *p, int a, int b, int c, int n);
EXTERN_C void func_80085F90(void *p);
EXTERN_C int func_800BFCB8(T_BFCB8 *p, int *q);
EXTERN_C void func_800BFC18(T_BFCB8 *p);
struct T_C5B4C_q { char pad[0x4BD]; signed char b4BD; char pad4BE[6]; signed char b4C4; };
EXTERN_C void func_80085A08(void *q, SVec4 v, int b);
EXTERN_C void func_800849D0(void *q, T_VEC v, int a, int b);
EXTERN_C void func_800CDED8_b(T_CE044 *l, SVec2 *v, void *q) __asm__("func_800CDED8");
inline void d0230_init(T_D0230 *p) { func_80074F58(p); p->vtblC = D_800B7768; T_D0230_n *e = p->nodes; for (int i = 9; i != -1; i--) { func_80074E28((T_D0338 *)e); e->vtbl8 = D_800B7778; e->fC = 0; e++; } p->f12C = 0; memset(p->pad10, 0xFF, 0x100); memset(p->pad10 + 0x100, 0xFF, 0x1C); }
inline void cfe8c_init(T_CFE8C *p) { SVec2 *q = p->f0; for (int i = 0x22; i != -1; i--) { q->x = 0; q->y = 0; q++; } p->f8C = 0; p->f90 = 0; }
struct T_C56A8 { VTable *vtbl; char f4[0x10]; int f14[7][5]; int fA0; T_D0230 fA4; int f2C4; char pad2C8[0x24]; T_CFE8C f2EC;
    char pad380[0x46]; short s3C6; short s3C8; char pad3CA[2]; int f3CC; int f3D0; int f3D4; char f3D8[0x400]; int f7D8; char pad7DC[0x38];
    int f814; int f818; int f81C; char pad820[0xE0]; int f900; int f904; int f908; char pad90C[0x28]; int f934; int f938; T_VEC v93C; char pad94C[8]; char b954; char b955; };
EXTERN_C void func_800756F8(void *p);
EXTERN_C void func_800C1A10_b(void *p) __asm__("func_800C1A10");
struct T_BE7A4_v { virtual void v1(); virtual void v2(); virtual int v3(); };
struct T_BE7A4_o { char pad[0xC]; T_BE7A4_v *fC; short s10; short s12; char pad14[8]; unsigned short h1C; };
struct T_BE7A4_c { char a, b; short al[0]; T_BE7A4_c(int x, int y) { a = x; b = y; } };
struct T_BE7A4_8 { char pad[8]; unsigned short h8; };
struct T_BE7A4_e { short x, y, z; };
struct T_BE7A4 { int pad0; T_BE7A4_o *f4; T_BE7A4_8 *f8[8]; int f28; int pad2C; T_BE7A4_e e30[1]; };
EXTERN_C unsigned short func_800BE928_b(T_BE7A4 *p, unsigned short id) __asm__("func_800BE928");
struct T_BEBE0;
EXTERN_C T_BEBE0 *func_800BEBE0(T_BEBE0 *p, int a, int b, unsigned short c, T_BFB18_t *t, unsigned short d, short *e, short *f, T_BE7A4_c *g, unsigned short h, unsigned short i);
struct T_C4510_pb { unsigned char r, g, b, code; short x, y; int w; };
struct T_C4510_p { int tag; T_C4510_pb b; };
struct T_C4510_q { int tag; int a, b, c; };
struct T_C4510 { VTable *vtbl; int f4; short s8; short sA; int fC; SVec4 f10; SVec2 f18; T_C47D8_1C f1C[2]; unsigned int f34; T_C4510_p *f38; };
EXTERN_C T_BCB6C_c D_800B4CB0[];
EXTERN_C void func_800C4EC4(T_C4510 *p);
EXTERN_C void func_800C4B70(T_C4510 *p, int a, int flags);
typedef void (*F_5F0E4)(void *p, int a);
EXTERN_C T_VEC func_800BF3B4(T_VEC *a, T_VEC *b);
struct T_BF1D0_g { char pad[0x2C8]; T_VEC v2C8; };
EXTERN_C T_VEC func_800BF1D0(void *self, T_VEC *b);
struct T_BEBE0 { VTable *vtbl; int f4; int f8; short sC; short sE; short s10; short s12; T_V0 *f14; void *f18; int f1C; int f20;
    signed char b24; signed char b25; signed char b26; char pad27; T_VEC v28; };
EXTERN_C void func_800BEE50(T_BEBE0 *p, T_BEE50_r *a, T_BEE50_r *b);
EXTERN_C void *func_800B7FFC(void *n, int a, int b, T_BE7A4_c *c, T_BEE50_r *d, T_BEE50_r *e, int f, int g);
struct T_BE484_c { signed char a; unsigned char b; T_BE484_c() {} T_BE484_c(int x, int y) { T_BE484_c *t = this; a = x; t->b = y; } };
struct T_BE484_e { short s; T_BE484_c c1; T_BE484_c c2; T_BE484_e() {} };
inline void be484_set(T_BE484_e *e, T_BE484_c &t, T_BE484_c *tp) { e->s = 0; t.a = 0; tp->b = 0; e->c1 = t; t.a = 0x7F; tp->b = 0xFF; e->c2 = t; }
struct T_BE484 { VTable *vtbl; T_Obj0 *f4; T_Obj0 *f8[7]; short s24; short s26; int f28; void *f2C; T_BE484_e e30[7]; };
struct T_BEE50_rd { unsigned char x, y; short al[0]; T_BEE50_rd() {} T_BEE50_rd(const T_BEE50_rd &o) { *(T_BEE50_r *)this = *(const T_BEE50_r *)&o; } };
struct T_BEF98_14 { virtual ~T_BEF98_14(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(void *a); };
struct T_BEF98_18 { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(T_BEE50_r *a, T_BEE50_r *b); };
struct T_BEF98_18d { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(T_BEE50_rd a, T_BEE50_rd b); };
struct T_C4EC4_s { char pad[3]; unsigned char len; unsigned char r, g, b, code; short x, y; unsigned char u, v; unsigned short clut; };
EXTERN_C T_BCB6C_c D_800B4C88[];
EXTERN_C void *func_800A0D2C(unsigned int n);
struct T_BF5FC_n { char pad[0xC]; short sC; short sE; };
struct T_BF5FC { char pad[0x2A0]; char f2A0[0x21C]; signed char b4BC; signed char b4BD; char pad4BE[2]; void *f4C0; char pad4C4[0x20]; signed char b4E4; };
EXTERN_C void *func_800D7048(void *n, int team, void *a, void *b, void *c, void *d, void *e, void *f);
EXTERN_C void func_80043460(void *p, SVec2C v, int a, int b);
EXTERN_C void func_80043540(void *p, SVec2C v, int a);
struct T_BE7A4;
EXTERN_C VTable D_800B73A4[];
struct T_BEDE8 { VTable *vtbl; int pad[4]; T_Obj0 *f14; };
inline int grid_at(T_CFD98 *p, SVec2 v) { return p->f14[v.y][v.x]; }
EXTERN_C void func_800C1BE4(T_C19BC *p, T_C19BC *q);
EXTERN_C void func_800C19BC(T_C19BC *a, int unused, T_C19BC *b);
EXTERN_C void func_800CBB84_b(void *p) __asm__("func_800CBB84");
struct T_C3E34_r { char pad[0x24]; T_BE0F8 e[11]; int pad7C; };
struct T_C3E34 { char pad[0x4BD]; signed char b4BD; char pad4BE[0x7E]; short s53C; short s53E; int f540; char pad544[4]; unsigned short h548; char pad54A[0x12]; T_C3E34_r r[1]; };
inline T_BE0F8 *row_at(T_C3E34_r *r, int j) { return &r->e[j]; }
struct T_C3DAC { char pad[0x14]; T_C3E34_r r; };
struct T_EBD4 { char pad[0x44]; T_BE0F8 e[9]; };
EXTERN_C T_C3E34 *func_800C9E58_b(void *p, int a) __asm__("func_800C9E58");
EXTERN_C T_C3DAC *func_80061188(void *p, int a);
EXTERN_C void func_800C3D2C(T_C3E34 *p, int i, int k, int *o1, int *o2);
EXTERN_C void func_800C3E34(T_C3E34 *p, int i, int j, int *o1, int *o2);
EXTERN_C void func_800C3F14(T_C3E34 *p, int *o1, int *o2);
struct T_C4784_e { char pad[8]; short x, y; char padC[4]; };
struct T_C4784 : T_D47D0_B { char pad4[0x34]; T_C4784_e *f38; };

inline void C3E34_get(T_C3E34_r *r, int j, int *o1, int *o2) {
    *o1 = r->e[j].f0;
    int v = r->e[j].f4;
    *o2 = v;
    if (!v) {
        *o1 = r->e[0].f0;
        *o2 = r->e[0].f4;
    }
}
struct T_C1A6C_n { T_C1A6C_n *next; T_C1A6C_n *prev; };
struct T_C1A6C_o { char pad[0x4BC]; signed char b4BC; };
/* List iterator: head at 0, current at 4; nodes sit at 0x4A0 inside their objects. */
struct T_C1A6C {
    T_C1A6C_n *head;
    T_C1A6C_n *cur;
    bool empty() { return head == 0; }
    bool last2() { if (empty()) return false; return head->prev == cur; }
    bool is_last() { if (head == 0) return false; return head->prev == cur; }
    void next() { if (!empty()) { if (!last2()) cur = cur->next; } }
    T_C1A6C_o *get() { return cur ? (T_C1A6C_o *)((char *)cur - 0x4A0) : 0; }
};

typedef int (*F_CMP3)(void *, void *, void *);
EXTERN_C int func_800C9284(T_C9A4C *p, int a, T_C9284 *q, int c);
EXTERN_C int func_800C9584(T_C9A4C *p, int a, T_C9284 *q, int c);
EXTERN_C int func_800C9794(T_C9A4C *p, T_C9284 *q, int b, int c);
EXTERN_C int func_800C98F0(T_C9A4C *p, T_C9284 *q, int b, int c);
EXTERN_C int func_800C9A4C(T_C9A4C *p, int a, int b, int c);
EXTERN_C int func_800C9B04(T_C9A4C *p, T_C9284 *q, int b, int c);
EXTERN_C int func_800C9674(T_C9A4C *p, T_C9284 *q1, T_C9284 *q2, int c);
EXTERN_C int func_800C9BFC(T_C9A4C *p, T_C9284 *q, int b, int c);
typedef int (*F_GRID5)(T_C9A4C *, int, int, int, int);
EXTERN_C int func_800CE910(SVec2 *a, SVec2 *b, SVec2 *c);
EXTERN_C int func_800C8F78(T_C9A4C *p, int a, int b, int c, int d);
EXTERN_C int func_800C9374(T_C9A4C *p, int a, int b, int c, int d);
EXTERN_C int func_800CE9B8(void *self, T_CE9B8 *a, T_CE9B8 *b);
EXTERN_C int func_800CEA00(void *self, T_CE9B8 *a, T_CE9B8 *b);
EXTERN_C int func_800CEA48();
EXTERN_C int func_800CEA50(void *self, S_800CEA50 *a, S_800CEA50 *b);
EXTERN_C int func_800CEA60(void *self, S_800CEA50 *a, S_800CEA50 *b);
EXTERN_C int func_800CEA70(void *self, S_800CEA50 *a, S_800CEA50 *b);

EXTERN_C T_CE044_10 *func_800CE064(T_CE044 *p);
EXTERN_C T_CE044_10 *func_800CE0D4(T_CE044 *p);
EXTERN_C int D_800D5DA4[];

struct T_CC110 { char pad[0xA0]; T_C9284 *fA0; char padA4[0x334]; char f3D8[0x3E8]; T_CDD0C_e e7C0; };
EXTERN_C void ce154_1(void *p) __asm__("func_800CE154");

struct T_B98C8_s { int f0; int f4; int f8; int fC; };
struct T_B98C8 { VTable *vtbl; char pad4[0x88]; VTable *vtbl8C; char pad90[0x68]; VTable *vtblF8; char padFC[4]; char b100; char b101; char pad102[0x172]; int f274; T_BE390 *f278; char pad27C[0x15C]; short s3D8; short s3DA; char pad3DC[0xC]; T_B98C8_s f3E8; T_B98C8_s f3F8; T_B98C8_s f408; };
EXTERN_C void *func_8001E40C(void *p, int a, int b, int c, int d);
EXTERN_C void func_800514C8(void *p);
EXTERN_C T_VObj8 *func_800BA564(T_VObj8 *p, char a, short b);
EXTERN_C T_VObj8 *func_800BDE2C(T_VObj8 *p);

EXTERN_C S_800D00B8 *f752B8_1(void *p) __asm__("func_800752B8");
EXTERN_C int func_800C54D8(void *vp, void *vk);

EXTERN_C T_B98C8 *func_800B98C8(T_B98C8 *p, int x);

struct T_BC294_l { void *f0; int f4; void *f8; };
EXTERN_C T_BC294 *func_800BC294(T_BC294 *p, int x);

struct T_D43B0n_s { unsigned addr:24; unsigned len:8; unsigned char r, g, b, code; short x, y; unsigned char u, v; unsigned short clut; short w, h; };
struct T_D43B0n { VTable *vtbl; char pad4[0xC]; int f10; char dm[2][0xC]; T_D43B0n_s s[2]; SVec4 s54; short h5C, h5E; };
EXTERN_C void *f4518_2(void *p, int a) __asm__("func_800D4518");
EXTERN_C void *func_800D43B0(void *vp, int a1);

struct T_C0EB8_e { int a, b; };
struct T_C0EB8_t { char pad[0x814]; int f814; T_C0EB8_e *f818; };
struct T_C0EB8_g { char pad[0x328]; char *f328; T_C0EB8_t *f32C; };
struct T_C0EB8_4D38 { char pad[0xF8]; int f[1]; };
struct T_C0EB8 {
    char pad0[0x144]; short s144; char pad146[0x15A]; char f2A0[0x170]; char pad410[0x9D]; char b4AD; char b4AE; char pad4AF[0xD];
    signed char b4BC; signed char b4BD; char pad4BE[8]; short s4C6; short pad4C8; short s4CA; char pad4CC[0x19]; signed char b4E5; signed char b4E6; char pad4E7; int f4E8; int f4EC; char pad4F0[0x1C]; short s50C;
};
struct T_C0EB8_v { int x, y, z, w; T_C0EB8_v() { x = 0; y = 0; z = 0; w = 0; } };
EXTERN_C T_C0EB8_4D38 *D_800B4D38[];
EXTERN_C T_C0EB8_g *D_800AF470g[] __asm__("D_800AF470");
EXTERN_C void f7FF58(void *a, int b, int c, int d) __asm__("func_8007FF58");
EXTERN_C void func_80086088(void *p, int a);
EXTERN_C void func_800C1254(T_C1340 *p);
EXTERN_C int func_800C0EB8(T_C0EB8 *p);

EXTERN_C void func_800BE7A4(T_BE7A4 *p, int id, void *x, unsigned short d, int e, unsigned short f);

EXTERN_C void func_800C3DAC(void *p, int a, int j, int *o1, int *o2);

struct T_2C { char d[0x2C]; };
EXTERN_C char D_800D5DAC[];
struct T_CED08 { char pad[0x7DC]; short s7DC; char pad7DE[0x156]; int f934; };
struct T_4DD0d { char pad[0x1FB]; signed char b1FB; };
EXTERN_C int func_800CED08(T_CED08 *p);

struct T_CFEF4_e { char pad[0x18]; ~T_CFEF4_e() {} };
struct T_CFEF4b { char pad[0x10]; T_CFEF4_e e[41]; };
EXTERN_C void func_800CFEF4(T_CFEF4b *p, int flags);

EXTERN_C void func_80068B14(void *p);
EXTERN_C int func_8008A5C8(void *a, void *b, void *c);
struct T_D2254_x { char pad[0x1B]; unsigned char b1B; char pad1C[0x6F]; unsigned char b8B; };
struct T_D2254_a { char d[0x6C]; };
struct T_D2254_b { char d[0x28]; };
struct T_D2254 { char pad[0x68]; signed char b68[0x34]; T_D2254_a a9C[1]; };
struct T_D2254b { char pad[0x1548]; T_D2254_b b1548[1]; };
struct T_D2254_y { char pad[0x1B]; char b1B; char pad1C[0x6F]; unsigned char b8B; };
struct T_D2254c { char pad[0x1CF0]; unsigned short h1CF0; };
struct T_D2254_B { int pad[2]; void *items[3]; };
struct T_D2254_D : T_D0390_A, T_D2254_B {};
struct T_D2254_G { char pad[0x328]; T_D2254_D *f328; };
EXTERN_C void func_800D2254(T_D2254 *p);

EXTERN_C char D_800B7964[];
struct T_D23C0_x { char pad[0x1B]; unsigned char b1B; };
struct T_VE3 { short delta; short index; void (*pfn)(void *, void *, void *, int); };
struct T_D23C0_b4 { char pad[0x9C]; T_VE3 *vt; };
struct T_D23C0_i { char pad[0x400]; T_D23C0_b4 b400; };
struct T_D23C0_B { int pad[2]; T_D23C0_i *items[3]; };
struct T_D23C0_D : T_D0390_A, T_D23C0_B {};
struct T_D23C0_G { char pad[0x328]; T_D23C0_D *f328; };
struct T_D23C0 { char pad[0x20]; int f20; };
struct T_4DD0e { char pad[0x1F4]; short s1F4; };
inline int kindOf(T_D23C0_x *x) { return x->b1B; }
struct VB23 { int pad[0x27]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(void *, void *, int); };
struct T_D23C0_j { char pad[0x400]; VB23 b400; };
EXTERN_C int func_800D23C0(T_D23C0 *p);

struct S4m { SVec2C a, b; S4m(short x, short y, short z, short w) : a(x, y), b(z, w) {} };
inline void fm(void *p, int a, const S4m &v, int b) { func_80054F30(p, a, (SVec4 *)&v, b); }
EXTERN_C T_D2778 *func_800D2778(T_D2778 *p);

EXTERN_C void func_800D2D60(T_D2D60 *p);

struct S4 { short x, y, z, w; };
EXTERN_C T_D4BFC *func_800D4BFC(T_D4BFC *self, int in_chrg, int a);

#endif /* BATTLE_BATTLE_H */
