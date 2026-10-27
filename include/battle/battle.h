#ifndef BATTLE_BATTLE_H
#define BATTLE_BATTLE_H

/* BATTLE.BIN reaches every global with lui/%lo and never uses $gp, so it was
   probably built with -G0. Under the project's -G8, small externs would go
   through $gp; giving their declarations an explicit .data section keeps the
   lui access. No storage is defined. */
#define LUI_DATA __attribute__((section(".data")))

/* Struct names are the address of the first function seen using them. Field
   names are offsets until their meaning is known. */

struct S_800BA418_448 {
    char pad[0x28];
};
struct S_800BA418 {
    char pad0[0x100];
    char b100;
    char b101;
    char pad102[2];
    char f104[0x8];
    int f10C;
    char pad110[0x54];
    char f164[0x114];
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

EXTERN_C int D_800D5D78 LUI_DATA;
EXTERN_C int D_800D5D7C LUI_DATA;

#endif /* BATTLE_BATTLE_H */
