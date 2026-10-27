#ifndef GAME_B_GLOBALS_H
#define GAME_B_GLOBALS_H

/* Retail reaches these with lui/%lo, not $gp. Under -G8 a 4-byte extern would
   use $gp, so single words are declared as a struct padded past 8 bytes; only
   the first word is known. */
struct GlobalWord {
    void *p;
    int pad[2];
};

struct GameMode_800AF410 {
    int state;
    int pad[2];
};

EXTERN_C GameMode_800AF410 D_800AF410;

/* An index; entries it selects are 16 bytes apart. */
struct GlobalInt_800B4CF0 {
    int value;
    int pad[2];
};

EXTERN_C GlobalInt_800B4CF0 D_800B4CF0;

struct Obj_800AF414 {
    char pad[0x54];
    int a;
    int b;
};

EXTERN_C Obj_800AF414 D_800AF414;

EXTERN_C GlobalWord D_800AF470;
EXTERN_C GlobalWord D_800AFA70;
EXTERN_C GlobalWord D_800B1A68;
EXTERN_C GlobalWord D_800B1B48;

/* Object at 0x800AFA74; layout unknown. */
struct Global_800AFA74 {
    int pad[8];
};

EXTERN_C Global_800AFA74 D_800AFA74;

EXTERN_C int D_800AFA58[3];
EXTERN_C int D_800AFA64[3];

#endif /* GAME_B_GLOBALS_H */
