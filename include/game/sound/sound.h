#ifndef GAME_SOUND_SOUND_H
#define GAME_SOUND_SOUND_H

/* Sound driver (src/main/sound.cpp, 0x8008B6B0-0x80094910; PsyQ 4.1 / GCC 2.7.2).
   Driver state is D_800B18FC (game/b/sound.h); its fields are reached with
   FIELD_AT(&D_800B18FC, type, offset). */

struct Loop_80091910 {
    unsigned char count;
    unsigned char unk1;
    unsigned char octave;
    unsigned char octave2;
    unsigned char *start;
    unsigned char *end;
};

struct Voice_80091FB4 {
    char pad0[0x8];
    unsigned char unk8;
    char pad9[0x23];
    short unk2C;
    short unk2E;
    char pad30[0x20];
    short unk50;
    short unk52;
    char pad54[0x20];
    short unk74;
    short unk76;
    char pad78[0x3E];
    unsigned char unkB6;
    char padB7[3];
    unsigned short flags;
    char padBC[0x1C];
    unsigned char unkD8;
    unsigned char unkD9;
    unsigned char unkDA;
    unsigned char unkDB;
    unsigned char unkDC;
    unsigned char unkDD;
    unsigned char unkDE;
    unsigned char unkDF;
    char padE0[4];
};

struct Node_80093800 {
    unsigned short flags;
    char pad2[6];
    int unk8;
    char padC[8];
    short unk14;
    char pad16[2];
    short unk18;
    short unk1A;
    short unk1C;
    short unk1E;
    Node_80093800 *next;
};

EXTERN_C void func_80094990();
EXTERN_C void func_800949A0();
EXTERN_C void func_8008C7B4(int a, int b, int c, int d, int e);
EXTERN_C void func_8008CA50(void);
EXTERN_C char *func_8008C970(void);
EXTERN_C void func_8008CBE4(void);
EXTERN_C void func_8009484C(int a, int b);

#endif /* GAME_SOUND_SOUND_H */
