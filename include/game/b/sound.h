#ifndef GAME_B_SOUND_H
#define GAME_B_SOUND_H

/* Sound driver (0x8008B4E8 onwards, next to the "Programmed by Hidenori Suzuki"
   string). That code was built with an older compiler (GCC 2.7.2, PsyQ 4.0/4.1);
   only functions that come out the same under PsyQ 4.4 are decompiled here. */

/* One sequence track. Command handlers take (driver, track, stream) and return
   the stream position after the command's operands. */
struct SeqTrack {
    unsigned short flags;  /* 0x00 */
    char pad02[0x1E];
    unsigned char *mark;   /* 0x20: stream position saved by a command */
    char pad24[0x1B];
    unsigned char unk3F;   /* 0x3F */
    int unk40;             /* 0x40 */
    int unk44;             /* 0x44 */
    int unk48;             /* 0x48 */
    unsigned short unk4C;  /* 0x4C */
    char pad4E[2];
    unsigned char unk50;   /* 0x50 */
    unsigned char octave;  /* 0x51: base note, in steps of 12 */
};

/* Driver state at 0x800B18FC. */
struct SoundState {
    unsigned short flags;  /* 0x000 */
    char pad002;
    unsigned char unk003;  /* 0x003 */
    int unk004;            /* 0x004 */
    char pad008[0x160];
    int unk168;            /* 0x168 */
    char pad16C[4];
    int unk170;            /* 0x170 */
    char pad174[0x10];
    int unk184;            /* 0x184 */
    int unk188;            /* 0x188 */
    char pad18C[0xCF];
    unsigned char unk25B;  /* 0x25B */
};

EXTERN_C SoundState D_800B18FC;

#endif /* GAME_B_SOUND_H */
