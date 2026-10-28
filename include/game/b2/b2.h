#ifndef GAME_B2_B2_H
#define GAME_B2_B2_H

/* main_b2 declarations (src/main/u_80068770 ... u_80089024). Small globals that a header
   in include/game/b/ declares with a padded struct are aliased here as plain words, so the
   per-unit $gp list decides between $gp and the assembler's lui macro. */

EXTERN_C const char D_80016248[];

EXTERN_C void *D_800B4DD0_w asm("D_800B4DD0");

EXTERN_C void *D_800AF470_w asm("D_800AF470");

#endif /* GAME_B2_B2_H */
