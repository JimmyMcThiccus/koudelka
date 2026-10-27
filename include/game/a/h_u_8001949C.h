#ifndef GAME_A_H_U_8001949C_H
#define GAME_A_H_U_8001949C_H

/* Declarations for src/main/u_8001949C.cpp only. */

EXTERN_C void *D_80010338[];
struct S_8001D684_ {
    void **vt;
    int unk4;
    int unk8;
    short unkC;
    int unk10;
    S_8001D684_(int a, short b, int c)
    {
        vt = D_80010178;
        unk4 = 0;
        vt = D_80010338;
        unk8 = a;
        unkC = b;
        unk10 = c;
    }
};
struct S_Size {
    short w;
    short h;
    S_Size(short a, short b) : w(a), h(b) {}
};
EXTERN_C void *D_800100E0[];
EXTERN_C void *D_80010338[];
EXTERN_C int D_800A4544[];
EXTERN_C void *D_800A4578[];
EXTERN_C void func_8001D150(void *self, void *b);
EXTERN_C void func_8001B424();
EXTERN_C void *func_8001B46C(void *p, int a, const S_Size &sz, int b, int c);
EXTERN_C void func_8001E360(void *p);
EXTERN_C void ResetGraph(int mode);
EXTERN_C void StopCallback();

struct S_App {
    char pad0[0x44];
    char *unk44;
};
struct S_VDel {
    virtual ~S_VDel();
};
struct S_Own {
    void **vt;
    S_VDel *ptr;
};
struct S_Arr5 {
    int *data;
    int count;
    int cap;
    int grow;
    int unk10;
};
struct S_Holder24 {
    S_Arr5 *vb;
    int unk4;
    S_Arr5 *unk8;
};
struct S_80019158 {
    void **vt;
    int unk4;
    int unk8;
    int unkC;
    S_Own m10;
    S_Own m18;
    int unk20;
    S_Holder24 h;
    S_Arr5 list;
    int unk44;
};
EXTERN_C void *D_800100D0[];
EXTERN_C void *D_80010328[];
/* This file reaches D_800B4C18 and D_800B4C34 with lui (no $gp): explicit sections keep them off $gp. */
EXTERN_C void *D_800B4C34 __attribute__((section(".data")));
EXTERN_C S_8001F1BC *D_800B4C18_lui asm("D_800B4C18") __attribute__((section(".data")));
EXTERN_C int D_800A457C[];
EXTERN_C void func_8001DF58(void *p, int a);
EXTERN_C void func_8008B6B0(void *p, int a, int b);
EXTERN_C void func_8001E848(void *self, void *p);
EXTERN_C void *func_80044BE4(void *p);
EXTERN_C void *func_80051C3C(void *p, void *g);
EXTERN_C void *func_8007E684(void *p, int a, void *g);
EXTERN_C char *func_8006A82C(void *p, int a, void *g);
EXTERN_C void *func_8005584C(void *p, void *g);
static inline void own_dtor_800194A8(S_Own *m)
{
    m->vt = D_80010328;
    delete m->ptr;
    func_800198AC(m, 2);
}
#define GAME_800196C8 (((S_App *)&D_800A4534)->unk44 ? ((S_App *)&D_800A4534)->unk44 + 0x50 : 0)

#endif /* GAME_A_H_U_8001949C_H */
