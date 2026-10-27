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

struct Blk_8008BE08 {
    int unk0;
    int unk4;
    char *end;
    Blk_8008BE08 *next;
};

struct Time_8008E134 {
    char pad0[2];
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
    unsigned char unk6;
    unsigned char unk7;
    char pad8[4];
    unsigned short ticks;
};

/* A byte inside D_800B18FC (offset 0x1A3) that retail reaches as its own symbol: reading it as
   a D_800B18FC field lets the scheduler move the load above stores through pointers. */
struct Byte_800B1A9F {
    unsigned char v;
    char pad[11];
};

EXTERN_C Byte_800B1A9F D_800B1A9F;

struct Slot_80093D8C {
    short idx;
    char pad2[2];
    short prio;
};

struct Req_8008EF64 {
    int id;
    unsigned short unk14;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    char pad1A[2];
    unsigned char *data;
};

struct Ent_8008F618 {
    unsigned char flags;
    unsigned char unk1;
    unsigned short song;
    short rnd;
    unsigned short time;
    unsigned char vol;
    char pad9;
};

EXTERN_C void func_80094990();
EXTERN_C void func_800949A0();
EXTERN_C void func_8008C7B4(int a, int b, int c, int d, int e);
EXTERN_C void func_8008CA50(void);
EXTERN_C char *func_8008C970(void);
EXTERN_C void func_8008CBE4(void);
EXTERN_C void func_8009484C(int a, int b);
EXTERN_C void *func_8008BC0C(int size);
EXTERN_C char *func_8008C4F0(int id);
EXTERN_C void func_8008DACC(void *self, int a, int b);
EXTERN_C void func_8008EF64(int a, int b, int c);
EXTERN_C void func_8008F0CC(int a, int b, int c, int d);
EXTERN_C void func_80093710(void *t, int k);
EXTERN_C void func_80093788(void *t, int k);
EXTERN_C void func_800939A8(void *t, int a, int b);
EXTERN_C void func_800939F4(void *t, int a, int b);
EXTERN_C void func_80093A40(void *t, int bits);
EXTERN_C unsigned int func_80094800(unsigned int *p);
EXTERN_C long EnableEvent(unsigned long event);
EXTERN_C long DisableEvent(unsigned long event);
EXTERN_C void func_8008BA68(void);
EXTERN_C void func_8008BAC4(void);
EXTERN_C void func_8008E134(unsigned int n, Time_8008E134 *t);
EXTERN_C void func_80093DE8(void *n);
EXTERN_C void SpuSetKey(long on_off, unsigned long voice_bit);
EXTERN_C long SpuSetNoiseClock(long n_clock);
EXTERN_C void func_8008E1B4(void *t);
EXTERN_C void func_8009482C(int a, int b);
EXTERN_C void func_80093E80(Slot_80093D8C *s);
EXTERN_C void func_80093EE0(Slot_80093D8C *s);
EXTERN_C void *func_8008E360(int a);
EXTERN_C void func_8008E590(void *p, int a, int b);
EXTERN_C void func_8008CE18(int a, int b, int c, int d);
EXTERN_C void func_8008BE08(char *p);
EXTERN_C void func_8008CFD4(void);
EXTERN_C void func_8008D038(int v, short *out, int side);
EXTERN_C void func_80093A80(void *drv, int bits);
EXTERN_C void func_800A0800(int a, int b);
struct Song_8008EB40;
EXTERN_C Song_8008EB40 *func_8008EB40(int n);
EXTERN_C void func_8008D808(void *n);
EXTERN_C int func_800947B8(void *a);
EXTERN_C void SpuSetVoiceRRAttr(int voice, unsigned short rr, long mode);
EXTERN_C void func_8008F4B0(Req_8008EF64 *r);
EXTERN_C int func_8008F1DC(Req_8008EF64 *r, int vol, int pan);
EXTERN_C void *func_8008F618(int id, Ent_8008F618 *e, int vol, int pan);

#endif /* GAME_SOUND_SOUND_H */
