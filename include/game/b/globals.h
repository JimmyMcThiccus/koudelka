#ifndef GAME_B_GLOBALS_H
#define GAME_B_GLOBALS_H

/* Retail reaches these with lui/%lo, not $gp. Under -G8 a 4-byte extern would
   use $gp, so single words are declared as a struct padded past 8 bytes; only
   the first word is known. */
struct GlobalWord {
    void *p;
    int pad[2];
};

EXTERN_C GlobalWord D_800AF470;
EXTERN_C GlobalWord D_800AFA70;
EXTERN_C GlobalWord D_800B1A68;
EXTERN_C GlobalWord D_800B1B48;

EXTERN_C int D_800AFA58[3];
EXTERN_C int D_800AFA64[3];

#endif /* GAME_B_GLOBALS_H */
