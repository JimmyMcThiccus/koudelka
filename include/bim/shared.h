#ifndef BIM_SHARED_H
#define BIM_SHARED_H

/* Types and declarations for the shared BIM.AR module functions (src/bim/shared/). Guarded: a module includes
   many of them. Calls into the EXE and bim_base are declared here once so every shared file agrees. */
#include "shared/exe.h"
#include "bim/bim.h"

/* A monster object seen only through its vtable; vN is the Nth virtual (vtable entry N+1, 8 bytes each). */
struct BimV {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(int a);
    virtual void v19(int a); virtual void v20(int a); virtual int v21(int a);
};

/* Virtual-base vtable (10 entries of 8 bytes, as in battle.h) and the destructor object. */
struct BimVEntry { short delta; short index; void (*pfn)(void *); };
struct BimVTable10 { BimVEntry e[10]; };
struct BimVBase { BimVTable10 *vptr; };
struct BimDtor {
    void *vt0;
    char pad4[0x88];
    void *vt8C;
    char pad90[0x14C];
    BimVBase *vb1DC;
    void *vt1E0;
    void *vt1E4;
    char pad1E8[0x214];
    void *vt3FC;
    char pad400[0x9C];
    void *vt49C;
    char pad4A0[8];
    void *vt4A8;
    char pad4AC[0x4D4];
    void *vt980;
};
EXTERN_C char D_8001262C[], D_80017ADC[];
struct BimTbl { char pad[0x9FC]; int w[60]; };
EXTERN_C char *D_800B4D38[];
EXTERN_C void func_800D76C8(void *p, int a);

/* bim_base */
EXTERN_C int func_800D8E64(void *p, int a);
EXTERN_C int func_800D8E64_a(void *p) asm("func_800D8E64");
EXTERN_C int func_800D7D64(void *p, void *q);
EXTERN_C int func_800D8064(void *p);
struct BimCnt { char pad[0x9C8]; int f9C8; int f9CC; char pad9D0[0x118]; int fAE8; int fAEC; };
struct BimM9 { char pad[0x9F0]; int f9F0; int f9F4; int f9F8; int f9FC; };
EXTERN_C int func_800D8350(void *p, int a);
EXTERN_C int func_800D8634(void *p);
EXTERN_C int func_800D84C8(void *p);
EXTERN_C bool func_800D8350_b(void *p, int a) asm("func_800D8350");
EXTERN_C void func_800D7818(void *p, int a, int b, int c, int d, int e, int f, int g, int h);
EXTERN_C int func_800D7C7C_i(void *p, int a, int b) asm("func_800D7C7C");
EXTERN_C int func_800D7A78(void *p, void *q);
EXTERN_C void func_800D7A20(void *p, int a);
EXTERN_C void *func_800D7A4C(void *p, int a, int b);
EXTERN_C int func_800D7AC4(void *p, void *q, int a, int b);

#endif
