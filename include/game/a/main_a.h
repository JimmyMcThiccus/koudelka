#ifndef GAME_A_MAIN_A_H
#define GAME_A_MAIN_A_H

/* Types, globals and functions used by the main_a part of game.cpp (0x800186B0-0x80054A2C).
   Most structs cover a run of nearby accessors; only the fields they touch are known. */

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

EXTERN_C void func_800198AC(void *p);
EXTERN_C void func_8001A610(void *p);
EXTERN_C void func_8001A678(void *p);
EXTERN_C void func_8001A6A8(void *p);
EXTERN_C void func_8001D024(void *p);
EXTERN_C void func_8001DEB8(void *p);
EXTERN_C void func_80020DB0(void *p);
EXTERN_C void func_80026138(void *p);
EXTERN_C void func_80028DC4(void *p);
EXTERN_C void func_8002D8AC(void *p);
EXTERN_C void func_8002DA94(void *p);
EXTERN_C void func_8002DC34(void *p);
EXTERN_C void func_8002DD34(void *p);
EXTERN_C void func_8002EE9C(void *p);
EXTERN_C void func_8002EEFC(void *p);
EXTERN_C void func_8003950C(void *p);
EXTERN_C void func_80039610(void *p);
EXTERN_C void func_80039710(void *p);
EXTERN_C void func_80039824(void *p);
EXTERN_C void func_8003BEC4(void *p);

/* A 4-byte value copied with lwl/lwr, so byte-aligned: an RGB+code colour, probably. */
typedef struct S_Rgb {
    unsigned char r, g, b, cd;
} S_Rgb;

/* unkC counts frames; it's volatile (it changes under interrupts). */
typedef struct S_800A4534 {
    char pad0[0xC];
    volatile unsigned int unkC;
} S_800A4534;

typedef struct S_80019D40 {
    int unk0;
    int unk4;
    char pad8[0x8];
    int unk10;
} S_80019D40;

typedef struct S_8001A294 {
    void **vtbl;
    int unk4;
    int unk8;
} S_8001A294;

typedef struct S_8001A6E8 {
    int unk0;
    struct S_8001A6E8 *unk4;
} S_8001A6E8;

typedef struct S_8001D6C8 {
    char pad0[0x14];
    unsigned int unk14;
    unsigned int unk18;
} S_8001D6C8;

/* unkC points at the second base of a class; the cast back adjusts by -8 with a null check. */
struct S_8001F964_Base0 {
    int unk0;
    int unk4;
};

struct S_8001F964_Base {
    int unk0;
};

struct S_8001F964_Derived : S_8001F964_Base0, S_8001F964_Base {
};

typedef struct S_8001F964 {
    char pad0[0xC];
    S_8001F964_Base *unkC;
} S_8001F964;

typedef struct S_80020B70 {
    char pad0[0x28];
    Holder unk28;
} S_80020B70;

typedef struct S_8002C15C {
    char pad0[0x30];
    Holder unk30;
} S_8002C15C;

typedef struct S_80021274 {
    int unk0[16];
    int unk40;
} S_80021274;

typedef struct S_80023A24 {
    char pad0[0x106];
    short unk106;
} S_80023A24;

typedef struct S_80025A64 {
    char pad0[0x8];
    S_Rgb unk8;
    S_Rgb unkC;
    S_Rgb unk10;
    S_Rgb unk14;
} S_80025A64;

typedef struct S_80025C88 {
    unsigned char unk0;
    unsigned char unk1;
    short unk2;
    short unk4;
} S_80025C88;

typedef struct S_80027FEC {
    char pad0[0x8];
    short unk8;
    short unkA;
} S_80027FEC;

typedef struct S_8002A004 {
    char pad0[0x28];
    int unk28;
} S_8002A004;

typedef struct S_8002E088 {
    char pad0[0x28];
    S_Rgb unk28;
} S_8002E088;

typedef struct S_8002EC00 {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} S_8002EC00;

typedef struct S_8002EC18 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} S_8002EC18;

typedef struct S_8002F8E0 {
    int unk0;
    void **vtbl;
} S_8002F8E0;

typedef struct S_800323C0_Node {
    int unk0;
    struct S_800323C0_Node *unk4;
} S_800323C0_Node;

typedef struct S_800323C0 {
    int unk0;
    int unk4;
    S_800323C0_Node *unk8;
} S_800323C0;

/* GPU primitive header: tag word, then r0 g0 b0 code. */
typedef struct S_Prim {
    unsigned int tag;
    unsigned char r0, g0, b0, code;
} S_Prim;

typedef struct S_80034F24 {
    char pad0[0x6];
    unsigned short unk6;
} S_80034F24;

typedef struct S_8003B2F0_V {
    int unk0;
    int unk4;
    int unk8;
} S_8003B2F0_V;

typedef struct S_8003B2F0 {
    char pad0[0x14];
    S_8003B2F0_V unk14;
} S_8003B2F0;

typedef struct S_Short {
    short v;
} S_Short;

typedef struct S_Int {
    int v;
} S_Int;

typedef struct S_8003ECE4 {
    char pad0[0x100];
    int unk100;
    int unk104;
} S_8003ECE4;

typedef struct S_80044690 {
    char pad0[0xF8];
    int unkF8;
    char padFC[0x24];
    unsigned char unk120;
    char pad121[0xFF];
    short unk220;
} S_80044690;

typedef struct S_1F80000C {
    int unk0;
    int unk4;
    int unk8;
} S_1F80000C;

typedef struct S_800493C8 {
    char pad0[0x8];
    unsigned int unk8;
} S_800493C8;

typedef struct S_8004AA24_A {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} S_8004AA24_A;

typedef struct S_8004AA24_B {
    char pad0[0xC];
    int unkC;
    char pad10[0x4];
    int unk14;
    char pad18[0x4];
    int unk1C;
} S_8004AA24_B;

typedef struct S_800537C0 {
    int unk0;
    int unk4;
    void **vtbl;
} S_800537C0;

typedef struct S_80053830 {
    int unk0;
    int unk4;
} S_80053830;

typedef struct S_8005402C {
    char pad0[0xC];
    short unkC;
    short unkE;
} S_8005402C;

EXTERN_C S_800A4534 D_800A4534;
EXTERN_C int D_800B4C24;
EXTERN_C int D_800B4C3C;
EXTERN_C int D_800B4C58;
EXTERN_C signed char D_800B4D08[];
EXTERN_C signed char D_800B4D3C[];
EXTERN_C S_1F80000C D_1F80000C[];
EXTERN_C void *D_80010118[];
EXTERN_C void *D_80010178[];
EXTERN_C void *D_80010328[];
EXTERN_C void *D_80011124[];
EXTERN_C void *D_80011384[];
EXTERN_C void *D_80011B5C[];
EXTERN_C void *D_80013B00[];
EXTERN_C void func_80019A6C(void *p, int a, int b);
EXTERN_C void func_8001F094(void *p);
EXTERN_C void func_8003C320(void *p, int a);
EXTERN_C void PadEnableCom(int a);
EXTERN_C void PadStopCom();
EXTERN_C void PadStartCom();

#endif
