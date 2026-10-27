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
EXTERN_C void func_800CC110(void *p);
EXTERN_C T_CE044_10 *func_800CE00C(T_CE044 *p);
EXTERN_C T_CE044_10 *func_800CE044(T_CE044 *p);
EXTERN_C T_CE044_10 *func_800CE090(T_CE044 *p);

EXTERN_C int D_800D5D78;
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
EXTERN_C void func_800C54D8(void *p, void *q);

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
EXTERN_C void func_800BA024(S_800BA418 *p);
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
EXTERN_C void func_800B9758(void *p);
EXTERN_C void func_800B9844(void *p);
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
EXTERN_C void func_800A0D0C(void *p);
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
EXTERN_C void func_800C5020(void *p, char *s, int n);
struct T_D0CC0 { char pad[0x68]; int f68; };
EXTERN_C int func_8005618C(void *q);
EXTERN_C void func_800BE09C(T_BE0F8 *t);
EXTERN_C void func_800BE108(T_BE0F8 *t, void *q);
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
EXTERN_C void *func_800D43B0(void *p, int a);
EXTERN_C void func_8005388C(void *p, int a);
EXTERN_C void func_8002DA94(int a, Holder *h);
struct T_D41D4 { char pad[8]; int f8; char padC[0x10]; unsigned short h1C; char pad1E[0x12]; Holder *f30; char pad34[4]; char f38[0xC]; int f44; char pad48[0xA]; SVec4 s52; };

#endif /* BATTLE_BATTLE_H */
