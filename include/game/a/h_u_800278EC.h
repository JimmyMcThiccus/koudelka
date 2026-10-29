#ifndef GAME_A_H_U_800278EC_H
#define GAME_A_H_U_800278EC_H

/* Declarations for src/main/u_800278EC.cpp only. */

struct VEnt { short d; short i; void *f; };
struct VObj { VEnt *vt; };
EXTERN_C void *D_8001116C[];
EXTERN_C void *D_800111A4[];
EXTERN_C void *D_800111FC[];
EXTERN_C void *func_800284D4(void *p, void *q);
EXTERN_C char D_800B4C6C[];
EXTERN_C char D_800AC6E4[];
EXTERN_C int D_800B4C60;
/* Retail stores D_800EA8A4 with the assembler macro (lui $at), not $gp: an explicit section keeps it off $gp. */
EXTERN_C volatile int D_800EA8A4 __attribute__((section(".data")));
EXTERN_C char D_800EA8A8[];
EXTERN_C void func_80018C1C(void *p);
EXTERN_C void *D_800B4C5C;
struct S_80028330 { char pad0[0x10]; VEnt *vt; };
struct S_Ptr4C38;
EXTERN_C S_Ptr4C38 D_800B4C38;
struct S_80028064 { int unk0; VObj *unk4; };
struct S_80027DB0 { char pad0[0x14]; unsigned int unk14; unsigned int unk18; char *unk1C; };
struct S_800280A8 { VEnt *vt; S_800280A8 *next; };
struct S_800280F8 { int unk0; void *unk4; };
struct S_800280F8b { char pad0[0x64]; void *unk64; };
struct S_80027DFC { void **vt; void **vt4; };

EXTERN_C void *D_80011254[];
EXTERN_C void *D_800103D0[];
EXTERN_C void *D_80010338[];
EXTERN_C void *D_800106EC[];
EXTERN_C void *D_80010654[];
EXTERN_C char D_800112D4[];
EXTERN_C char D_800A4554[];
EXTERN_C char D_800A4544[];
EXTERN_C void func_8001E03C(void *l, void *n);
struct S_XYs { short x, y; };
EXTERN_C S_XYs D_800B4C64;
EXTERN_C S_XYs D_800B4C68;
struct S_Obj178c {
    void *volatile vt;
    int unk4;
    S_Obj178c() { vt = D_80010178; unk4 = 0; }
};
struct S_N3D0 : S_Obj178c {
    void *unk8;
    short unkC;
    int unk10;
    int unk14;
    S_N3D0(void *a) { vt = D_800103D0; unk8 = a; unkC = -0x8000; unk10 = 0; unk14 = 0; }
};
struct S_N338 : S_Obj178c {
    void *unk8;
    short unkC;
    int unk10;
    S_N338(void *a) { vt = D_80010338; unk8 = a; unkC = 0x80; unk10 = 0; }
};
struct S_800282AC { void **vt; };
struct C_800279C0 {
    void **vt;
    void **vt4;
    int unk8;
    int unkC;
    char pad10[0x10];
    C_800279C0();
};

EXTERN_C void func_8001B1C8(void *p);
EXTERN_C void *func_8001B134(unsigned int size);
EXTERN_C void _96_init();
EXTERN_C long LoadExec(char *file, unsigned long sp, unsigned long size);
EXTERN_C void start();
EXTERN_C long StopRCnt(unsigned long spec);
EXTERN_C int VSync(int mode);
EXTERN_C char D_80011154[];
EXTERN_C void *D_80012154[];
EXTERN_C void *D_8001201C[];
EXTERN_C void *D_80012034[];
EXTERN_C void *D_80012294[];
EXTERN_C void *D_80012224[];
struct S_80027A60_VB { short unk0; short unk2; int unk4; };
struct S_80027A60_O {
    void **vt;
    S_80027A60_VB *vb;
    void **vt8;
    int *p;
    int data[6];
    int unk28;
    int unk2C;
    char pad30[0xC];
    S_80027A60_VB vbase;
};
struct S_80027A60 {
    VEnt *vt;
    int unk4;
    int unk8;
    int state;
    VObj *unk10;
    int unk14;
    int unk18;
    char *unk1C;
};

#endif /* GAME_A_H_U_800278EC_H */
