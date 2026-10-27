#ifndef BATTLE_BATTLE_H
#define BATTLE_BATTLE_H

/* BATTLE.BIN reaches every global with lui/%lo and never uses $gp, so it was
   probably built with -G0. Under the project's -G8, small externs would go
   through $gp; giving their declarations an explicit .data section keeps the
   lui access. No storage is defined. */
#define LUI_DATA __attribute__((section(".data")))

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
struct S_800BA418 {
    char pad0[0x100];
    char b100;
    char b101;
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
    char pad3DC[0x48];
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
struct T_C1340 { char pad[0x4D0]; int f4D0; };
struct T_CE044_10 { char pad[0x18]; };
struct T_CE044 { int pad0; int pad4; int f8; int fC; T_CE044_10 f10[1]; };
struct T_CFD98 { char pad[0x14]; int f14[1][5]; };
struct T_D5740 { char pad[0x20]; int f20; char pad24[0x48]; signed char b6C[1]; };
struct T_BC420 { char pad[0x4C0]; Holder h4C0; };
struct T_B9268 { char pad[0x4D0]; void *f4D0; char pad4D4[0x80]; void *f554; void *f558; };
struct T_BC270 { int pad0; void *f4; };
struct T_CEC00 { char pad[0x90C]; void *f90C; };
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
EXTERN_C int func_800B9654(void *p);
EXTERN_C int func_800BB118(void *p);
EXTERN_C int func_800BBC04(void *p);
EXTERN_C void func_800BC0C0(T_VObj *p, int flags);
EXTERN_C void func_800C0694(void *p, int a);
EXTERN_C int func_800C1360(void *p);
EXTERN_C int func_800C757C(void *p, int a);
EXTERN_C void func_800CC110(void *p);
EXTERN_C T_CE044_10 *func_800CE00C(T_CE044 *p);

EXTERN_C int D_800D5D78 LUI_DATA;
EXTERN_C int D_800D5D7C LUI_DATA;

struct T_VObj8 { VTable *vtbl; int f4; signed char b8; char pad9; short sA; int fC; };
struct T_CBA50 { char pad[0x908]; void *f908; void *f90C; };
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
struct T_C5B18_q { char pad[0x4C4]; signed char b4C4; };
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

#endif /* BATTLE_BATTLE_H */
