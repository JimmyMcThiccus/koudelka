#ifndef GAME_B2_B2_H
#define GAME_B2_B2_H

/* main_b2 declarations (src/main/u_80068770 ... u_80089024). Small globals that a header
   in include/game/b/ declares with a padded struct are aliased here as plain words, so the
   per-unit $gp list decides between $gp and the assembler's lui macro. */

EXTERN_C const char D_80016248[];

EXTERN_C void *D_800B4DD0_w asm("D_800B4DD0");

EXTERN_C void *D_800AF470_w asm("D_800AF470");

EXTERN_C int D_800B4CF0_w asm("D_800B4CF0");

struct B16_C {
    int w[4];
    B16_C(int x, int y, int z)
    {
        w[0] = x;
        w[1] = y;
        w[2] = z;
        w[3] = 0;
    }
};

EXTERN_C void func_8007D24C_c(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_C s, int a12) asm("func_8007D24C");

EXTERN_C void func_8007CAB4_c(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_C s, int a12) asm("func_8007CAB4");

EXTERN_C void func_8007D498_c(void *self, int a1, int a2, int a3, int a4, int a5, int a6, B16_C s, int a12) asm("func_8007D498");

EXTERN_C void func_800DE59C_c(void *self, int a1, int a2, int a3, int a4, int a5, int a6, B16_C s, int a12) asm("func_800DE59C");

#endif /* GAME_B2_B2_H */
