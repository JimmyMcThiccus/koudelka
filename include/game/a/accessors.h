#ifndef GAME_A_ACCESSORS_H
#define GAME_A_ACCESSORS_H

/* Objects behind the small accessor functions in 0x800186B0-0x80054A2C. Each struct
   covers a run of nearby accessors; only the fields they touch are known. */

typedef struct S_8001914C {
    char pad0[0x4];
    int unk4;
} S_8001914C;

typedef struct S_8001949C {
    char pad0[0xC];
    int unkC;
} S_8001949C;

typedef struct S_80019A18 {
    char pad0[0x10];
    int unk10;
} S_80019A18;

typedef struct S_80019FB4 {
    char pad0[0x4];
    int unk4;
    int unk8;
} S_80019FB4;

typedef struct S_8001A114 {
    char pad0[0x4];
    int unk4;
    int unk8;
} S_8001A114;

typedef struct S_8001A8B8 {
    char pad0[0x4];
    int unk4;
} S_8001A8B8;

typedef struct S_8001B30C {
    char pad0[0x4];
    int unk4;
} S_8001B30C;

typedef struct S_8001C658 {
    char pad0[0x4];
    int unk4;
} S_8001C658;

typedef struct S_8001CD10 {
    char pad0[0x4];
    int unk4;
    unsigned short unk8;
    unsigned short unkA;
    int unkC;
    int unk10;
} S_8001CD10;

typedef struct S_8001CFF8 {
    char pad0[0x4];
    int unk4;
} S_8001CFF8;

typedef struct S_8001D62C {
    char pad0[0x4];
    int unk4;
    int unk8;
    short unkC;
    char padE[0x2];
    int unk10;
} S_8001D62C;

typedef struct S_8001E23C {
    int unk0;
    int unk4;
    char pad8[0x4];
    short unkC;
    char padE[0x2];
    int unk10;
} S_8001E23C;

typedef struct S_8001E840 {
    char pad0[0x98];
    int unk98;
} S_8001E840;

typedef struct S_8001F1CC {
    char pad0[0x4];
    int unk4;
    char pad8[0x90];
    int unk98;
    char pad9C[0x54];
    int unkF0;
} S_8001F1CC;

typedef struct S_8001F980 {
    char pad0[0x4];
    int unk4;
} S_8001F980;

typedef struct S_8001FFD0 {
    char pad0[0x4];
    int unk4;
    int unk8;
    int unkC;
    unsigned short unk10;
    unsigned short unk12;
} S_8001FFD0;

typedef struct S_80020510 {
    char pad0[0x18];
    unsigned short unk18;
    unsigned short unk1A;
} S_80020510;

typedef struct S_80020B90 {
    char pad0[0x4];
    int unk4;
    char pad8[0x42];
    short unk4A;
    char pad4C[0x4];
    short unk50;
    short unk52;
    int unk54;
} S_80020B90;

typedef struct S_80020D24 {
    char pad0[0x4];
    int unk4;
    char pad8[0xC];
    int unk14;
} S_80020D24;

typedef struct S_80022A04 {
    char pad0[0x4];
    int unk4;
    unsigned short unk8;
    char padA[0x6];
    int unk10;
} S_80022A04;

typedef struct S_80022F64 {
    char pad0[0x4];
    int unk4;
} S_80022F64;

typedef struct S_800239AC {
    char pad0[0x9C];
    int unk9C;
    char padA0[0x64];
    short unk104;
    short unk106;
    int unk108;
} S_800239AC;

typedef struct S_80024634 {
    char pad0[0x25];
    unsigned char unk25;
    unsigned char unk26;
} S_80024634;

typedef struct S_80024858 {
    char pad0[0x10];
    int unk10;
    char pad14[0x4];
    int unk18;
} S_80024858;

typedef struct S_80025874 {
    char pad0[0x24];
    int unk24;
} S_80025874;

typedef struct S_800259F8 {
    char pad0[0x4];
    int unk4;
    char pad8[0x4];
    int unkC;
    int unk10;
    char pad14[0x8];
    unsigned short unk1C;
} S_800259F8;

typedef struct S_80025C5C {
    int unk0;
} S_80025C5C;

typedef struct S_80027D90 {
    char pad0[0xC];
    int unkC;
    char pad10[0x4];
    int unk14;
} S_80027D90;

typedef struct S_80028184 {
    char pad0[0x4];
    int unk4;
    short unk8;
    short unkA;
} S_80028184;

typedef struct S_80028448 {
    char pad0[0x4];
    int unk4;
} S_80028448;

typedef struct S_80028FC0 {
    char pad0[0x4];
    int unk4;
} S_80028FC0;

typedef struct S_80029BF4 {
    char pad0[0x5];
    unsigned char unk5;
    unsigned char unk6;
    unsigned char unk7;
} S_80029BF4;

typedef struct S_8002A110 {
    char pad0[0x28];
    int unk28;
} S_8002A110;

typedef struct S_8002AF34 {
    char pad0[0x4];
    int unk4;
    int unk8;
    int unkC;
    char pad10[0xC];
    unsigned short unk1C;
    char pad1E[0x2];
    int unk20;
    int unk24;
} S_8002AF34;

typedef struct S_8002C17C {
    char pad0[0x8];
    int unk8;
} S_8002C17C;

typedef struct S_8002C6C8 {
    char pad0[0x8];
    int unk8;
} S_8002C6C8;

typedef struct S_8002C90C {
    char pad0[0x4];
    int unk4;
} S_8002C90C;

typedef struct S_8002E4B8 {
    char pad0[0x1C];
    int unk1C;
    int unk20;
    char pad24[0x8];
    int unk2C;
} S_8002E4B8;

typedef struct S_8002E908 {
    char pad0[0x4];
    int unk4;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    int unk10;
} S_8002E908;

typedef struct S_8002ED90 {
    char pad0[0x8];
    int unk8;
} S_8002ED90;

typedef struct S_8002EF64 {
    char pad0[0x10];
    int unk10;
} S_8002EF64;

typedef struct S_8002F32C {
    char pad0[0x4];
    int unk4;
} S_8002F32C;

typedef struct S_8002F4CC {
    char pad0[0xC];
    int unkC;
    char pad10[0x4];
    int unk14;
} S_8002F4CC;

typedef struct S_8002F818 {
    char pad0[0x4];
    int unk4;
} S_8002F818;

typedef struct S_8002FD98 {
    char pad0[0x4];
    int unk4;
} S_8002FD98;

typedef struct S_80030528 {
    char pad0[0x4];
    int unk4;
} S_80030528;

typedef struct S_80030B4C {
    char pad0[0x4];
    int unk4;
} S_80030B4C;

typedef struct S_80032920 {
    char pad0[0x4];
    int unk4;
} S_80032920;

typedef struct S_80034608 {
    char pad0[0x4];
    int unk4;
} S_80034608;

typedef struct S_80034BA8 {
    int unk0;
} S_80034BA8;

typedef struct S_800352DC {
    char pad0[0x4];
    int unk4;
} S_800352DC;

typedef struct S_800358D4 {
    char pad0[0x1C];
    int unk1C;
} S_800358D4;

typedef struct S_80037258 {
    char pad0[0x28];
    int unk28;
    int unk2C;
} S_80037258;

typedef struct S_800385E4 {
    char pad0[0x10];
    int unk10;
} S_800385E4;

typedef struct S_80038EF0 {
    char pad0[0x24];
    int unk24;
} S_80038EF0;

typedef struct S_800392C8 {
    char pad0[0x24];
    int unk24;
} S_800392C8;

typedef struct S_80039444 {
    char pad0[0x50];
    short unk50;
} S_80039444;

typedef struct S_800399A4 {
    char pad0[0x4];
    int unk4;
} S_800399A4;

typedef struct S_8003A6F4 {
    char pad0[0x24];
    int unk24;
    char pad28[0x4];
    int unk2C;
    char pad30[0x4];
    int unk34;
} S_8003A6F4;

typedef struct S_8003CE88 {
    char pad0[0x4];
    int unk4;
    int unk8;
    char padC[0x8];
    int unk14;
} S_8003CE88;

typedef struct S_8003D37C {
    char pad0[0xE];
    unsigned char unkE;
} S_8003D37C;

typedef struct S_8003D9F0 {
    char pad0[0xC];
    short unkC;
} S_8003D9F0;

typedef struct S_8003EBC4 {
    char pad0[0x1B8];
    int unk1B8;
} S_8003EBC4;

typedef struct S_8003FDDC {
    char pad0[0x138];
    int unk138;
    char pad13C[0x8];
    short unk144;
    unsigned char unk146;
} S_8003FDDC;

typedef struct S_800406A0 {
    char pad0[0x8];
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    char pad18[0x4];
    unsigned short unk1C;
    char pad1E[0xE];
    short unk2C;
} S_800406A0;

typedef struct S_80041CCC {
    int unk0;
} S_80041CCC;

typedef struct S_8004467C {
    char pad0[0x214];
    short unk214;
} S_8004467C;

typedef struct S_80045D18 {
    char pad0[0x30];
    int unk30;
} S_80045D18;

typedef struct S_800493BC {
    char pad0[0xB];
    signed char unkB;
} S_800493BC;

typedef struct S_80049B2C {
    char pad0[0x44];
    int unk44;
} S_80049B2C;

typedef struct S_80049FA0 {
    char pad0[0x44];
    int unk44;
} S_80049FA0;

typedef struct S_8004A404 {
    char pad0[0x68];
    int unk68;
} S_8004A404;

typedef struct S_8004AF3C {
    char pad0[0x68];
    int unk68;
} S_8004AF3C;

typedef struct S_8004B3F0 {
    char pad0[0x68];
    int unk68;
} S_8004B3F0;

typedef struct S_8004BA18 {
    char pad0[0x5C];
    int unk5C;
} S_8004BA18;

typedef struct S_8004BEB8 {
    char pad0[0x58];
    int unk58;
} S_8004BEB8;

typedef struct S_8004C474 {
    char pad0[0x78];
    int unk78;
} S_8004C474;

typedef struct S_8004CA00 {
    char pad0[0x78];
    int unk78;
} S_8004CA00;

typedef struct S_8004D244 {
    char pad0[0x50];
    int unk50;
} S_8004D244;

typedef struct S_8004D780 {
    char pad0[0x50];
    int unk50;
} S_8004D780;

typedef struct S_8004DC8C {
    char pad0[0x80];
    int unk80;
} S_8004DC8C;

typedef struct S_8004E298 {
    char pad0[0x80];
    int unk80;
} S_8004E298;

typedef struct S_8004E81C {
    char pad0[0x80];
    int unk80;
} S_8004E81C;

typedef struct S_8004EF1C {
    char pad0[0x74];
    int unk74;
} S_8004EF1C;

typedef struct S_8004F49C {
    char pad0[0x68];
    int unk68;
} S_8004F49C;

typedef struct S_8004FB4C {
    char pad0[0x98];
    int unk98;
} S_8004FB4C;

typedef struct S_800501EC {
    char pad0[0x98];
    int unk98;
} S_800501EC;

typedef struct S_80050838 {
    int unk0;
} S_80050838;

typedef struct S_80051ECC {
    char pad0[0x11A];
    short unk11A;
} S_80051ECC;

typedef struct S_80053794 {
    int unk0;
    int unk4;
} S_80053794;

typedef struct S_80053BB4 {
    char pad0[0x10];
    int unk10;
    int unk14;
} S_80053BB4;

typedef struct S_80054048 {
    int unk0;
    int unk4;
    int unk8;
} S_80054048;

typedef struct S_8005457C {
    char pad0[0x8];
    int unk8;
} S_8005457C;

typedef struct S_800549D8 {
    char pad0[0x1C];
    int unk1C;
    int unk20;
    int unk24;
} S_800549D8;

EXTERN_C int D_800B4C18;
EXTERN_C short D_800B4C70;
EXTERN_C int D_800B4D0C;
EXTERN_C int D_800B4D5C;
EXTERN_C int D_800B4D60;

typedef struct S_8003ECFC {
    char pad0[0x100];
    int unk100;
    int unk104;
} S_8003ECFC;

typedef struct S_80034BB4 {
    char pad0[0x3];
    unsigned char unk3;
} S_80034BB4;

typedef struct S_80034F40 {
    char pad0[0x6];
    unsigned short unk6;
} S_80034F40;

typedef struct S_8001F1BC {
    char pad0[0x94];
    unsigned short unk94;
} S_8001F1BC;

/* Something whose unk4 is read through a pointer. */
typedef struct S_Link4 {
    int unk0;
    int unk4;
} S_Link4;

typedef struct S_800399B0 {
    S_Link4 *unk0;
    int unk4;
} S_800399B0;

typedef struct S_800549B0 {
    char pad0[0x1C];
    int unk1C;
} S_800549B0;

typedef struct S_800372C0 {
    int unk0;
    S_Link4 *unk4;
    char pad8[0x24];
    int unk2C;
} S_800372C0;

typedef struct S_800391DC_14 {
    char pad0[0x14];
    int unk14;
} S_800391DC_14;

typedef struct S_800391DC {
    char pad0[0x48];
    S_800391DC_14 *unk48;
    char pad4C[0x18];
    short unk64;
} S_800391DC;

typedef struct S_8001FCA4 {
    int unk0;
    int unk4;
    S_Link4 *unk8;
} S_8001FCA4;

typedef struct S_80040294 {
    char pad0[0x28];
    int unk28;
} S_80040294;

typedef struct S_8004580C {
    char pad0[0xF8];
    int unkF8[1];
} S_8004580C;

typedef struct S_8003BEA0 {
    short unk0;
    short unk2;
    short unk4;
} S_8003BEA0;

typedef struct S_80025CC8 {
    unsigned char unk0;
    unsigned char unk1;
} S_80025CC8;

typedef struct S_8002EBF0 {
    short unk0;
    short unk2;
} S_8002EBF0;

typedef struct S_80041CB8 {
    int unk0;
    int unk4;
} S_80041CB8;

/* An object whose first word is its vtable. */
typedef struct S_Vobj {
    void **vtbl;
} S_Vobj;

/* 8-byte entries in the scratchpad. */
typedef struct S_1F800010 {
    int unk0;
    int unk4;
} S_1F800010;

EXTERN_C short D_800B4C50;
EXTERN_C short D_800B4C52;
EXTERN_C int D_800B4D00;
EXTERN_C int D_800B4D2C;
EXTERN_C int D_800B4D30;
EXTERN_C unsigned char D_800AC809[];
EXTERN_C S_1F800010 D_1F800010[];
EXTERN_C void *D_80010198[];
EXTERN_C void *D_800101E8[];
EXTERN_C void *D_80010348[];
EXTERN_C void *D_800103E0[];
EXTERN_C void *D_800103F8[];
EXTERN_C void *D_80011FE4[];

#endif
