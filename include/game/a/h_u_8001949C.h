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

#endif /* GAME_A_H_U_8001949C_H */
