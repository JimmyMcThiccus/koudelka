#ifndef GAME_A2_A2_H
#define GAME_A2_A2_H

/* Declarations for area main_a2 (u_80032264 ... u_8003C510). */

EXTERN_C void func_80035CD8();
#define AT(p, type, off) (*(type *)((char *)(p) + (off)))
EXTERN_C void func_8003488C(void *p);
EXTERN_C void func_800348E4(void *p);
EXTERN_C void func_8001AA68(void *p, int a);
EXTERN_C void func_8001AB50(void *p, int a);
EXTERN_C void CdInit();
EXTERN_C void func_800375E4();
EXTERN_C void func_800361C8(void *p);
EXTERN_C void func_80036364(void *p, unsigned char a);
EXTERN_C void func_80036554(void *p, unsigned char a);
EXTERN_C int func_80036850(void *p);
EXTERN_C void func_80019CFC(void *p, int a);
EXTERN_C void func_8004A98C(void *p);
EXTERN_C void func_8004A9E4(void *p);
EXTERN_C void func_8001A744(void *p, int a);
EXTERN_C void func_80054708(void *p, int a);
EXTERN_C int func_80019C24(void *p, int a);
EXTERN_C void func_8001E508(void *p, int a);
EXTERN_C void func_80034EBC(void *p, void *q);
EXTERN_C void func_8004AE24(void *p, void *q);
EXTERN_C void func_80055624(void *p, int a);
EXTERN_C void *D_80012154[];
EXTERN_C void *D_800121AC[];
struct S_A2_PtrArr { void **items; };
struct S_A2_Stack { S_A2_PtrArr *arr; int n; };
struct S_A2_V4 { int a, b, c, d; };
struct S_A2_Sv { short x, y, z, pad; };
struct S_A2_800AC844 { int unk0; int unk4; void *unk8; };
EXTERN_C S_A2_800AC844 D_800AC844;
struct S_A2_Node4 { int unk0; void *unk4; };
struct S_A2_Flags { char pad[3]; unsigned char f; };
struct S_A2_VEnt { short delta; short index; void (*pfn)(void *, int); };
struct S_A2_FE34 { char pad[0x34]; S_A2_V4 v; };
struct S_A2_FE34o { char pad[0x1B8]; S_A2_FE34 *q; };
struct C_80039A14 { C_80039A14() asm("func_80039A14"); char pad[0x48]; };
struct C_8003BEF8 : C_80039A14 { int unk48; C_8003BEF8() asm("func_8003BEF8"); };
EXTERN_C void *D_80012724[];
EXTERN_C void *D_8001277C[];
EXTERN_C void func_80053C6C(void *p, void *q);
EXTERN_C void *D_80012974[];
EXTERN_C void *D_8001295C[];
EXTERN_C void *D_800137C0[];
EXTERN_C void *D_800137D8[];
EXTERN_C void *D_80012BC8[];
EXTERN_C void func_80035384(void *p);
EXTERN_C void func_80035B5C();
#endif /* GAME_A2_A2_H */
