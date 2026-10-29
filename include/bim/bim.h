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
    unsigned char b7E;
    char pad7F[0x1];
    unsigned short s80;
    char pad82[0x38E];
    short s410;
    char pad412[0xAA];
    signed char b4BC;
    char pad4BD[0x9];
    short s4C6;
    char pad4C8[0x2];
    short s4CA;
    char pad4CC[0x18];
    char b4E4;
    char b4E5;
    char b4E6;
    char pad4E7[0x1];
    int f4E8;
    int f4EC;
    char pad4F0[0x498];
    int f988;
    char pad98C[0x18];
    int f9A4;
    char pad9A8[0x20];
    int f9C8;
    int f9CC;
    int f9D0;
    int f9D4;
    int f9D8;
    int f9DC;
    int f9E0;
    int f9E4;
    int f9E8;
    int f9EC;
    int f9F0;
    unsigned int f9F4;
};

struct BimVec4 { int x, y, z, w; };

EXTERN_C BimBattle *D_800AF470[];

struct BimPos { short x, y; };
EXTERN_C BimMon *D_800AFA58[];
/* func_800D83D4 as called with only the object in $a0 */
EXTERN_C int func_800D83D4_a(void *) asm("func_800D83D4");
EXTERN_C int func_800CC220(void *p);
EXTERN_C void func_800CC3DC(void *p, BimPos pos, int a, int b);
EXTERN_C int func_800C02C8(void *p, int a, int b, int c);
EXTERN_C unsigned short func_800D8FF8(BimMon *p);
EXTERN_C void func_800CC110(void *p);
EXTERN_C void func_800CC298(void *p, int a, unsigned short b);
EXTERN_C int func_800D8A50();
EXTERN_C int func_800C8D9C(void *p, int a, int *b, int *c);
EXTERN_C void func_800D7C7C(void *p, int a, int b);
EXTERN_C void func_800D8AE4();
EXTERN_C void func_800CFC50(void *p);
EXTERN_C void func_800CDA8C(void *p);
EXTERN_C void func_800CDA94(void *p, int a);

#endif
