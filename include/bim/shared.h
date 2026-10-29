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
    virtual void v19(int a); virtual void v20(int a);
};

/* bim_base */
EXTERN_C int func_800D8E64(void *p, int a);
EXTERN_C int func_800D7D64(void *p, void *q);
EXTERN_C unsigned short func_800D7A78(void *p, void *q);
EXTERN_C void func_800D7A20(void *p, int a);
EXTERN_C void *func_800D7A4C(void *p, int a, int b);
EXTERN_C void func_800D7AC4(void *p, void *q, int a, int b);

#endif
