#ifndef BIM_H
#define BIM_H

/* BIM.AR shared base: the monster class framework. Types here are provisional; BATTLE's equivalents
   (include/battle/battle.h) are per-function shapes, so these are kept local. */

struct BimBattle {
    char pad[0x32C];
    struct BimField *f32C;
};

struct BimField {
    char pad[0x950];
    int f950;
};

/* The monster object. */
struct BimMon {
    char pad0[0x3E];
    unsigned char b3E;
    char pad3F[0x3E];
    unsigned char b7D;
    char pad7E[2];
    unsigned short s80;
    char pad82[0x43A];
    signed char b4BC;
    char pad4BD[0x27];
    char b4E4;
    char b4E5;
    char b4E6;
    char pad4E7;
    int f4E8;
    int f4EC;
    char pad4F0[0x4B4];
    int f9A4;
    char pad9A8[0x24];
    int f9CC;
    char pad9D0[0xC];
    int f9DC;
    int f9E0;
    int f9E4;
};

struct BimVec4 { int x, y, z, w; };

EXTERN_C BimBattle *D_800AF470[];

EXTERN_C int func_800C8D9C(void *p, int a, int *b, int *c);
EXTERN_C void func_800D7C7C(void *p, int a, int b);
EXTERN_C void func_800D8AE4();
EXTERN_C void func_800CFC50(void *p);
EXTERN_C void func_800CDA8C(void *p);
EXTERN_C void func_800CDA94(void *p, int a);

#endif
