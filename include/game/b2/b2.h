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

static inline char *nx_80080350(char *p) { return FIELD_AT(p, char *, 4); }

EXTERN_C char D_800173D0[];

EXTERN_C void func_8008022C_def(void *self, int a, int b) asm("func_8008022C");

EXTERN_C void *D_800B4D38_w asm("D_800B4D38");

EXTERN_C int func_800D9970_i(void *self, int b) asm("func_800D9970");

EXTERN_C int func_800883A0_i(void *self, int b) asm("func_800883A0");

EXTERN_C int func_80088794_i(void *self, int b) asm("func_80088794");

EXTERN_C int func_800D9CB0_i(void *self, int b) asm("func_800D9CB0");

EXTERN_C int func_8008891C_i(void *self, int b) asm("func_8008891C");

EXTERN_C int func_80088C8C_i(void *self, int b) asm("func_80088C8C");

EXTERN_C char D_80015E5C[];

EXTERN_C int D_800B4ED8_p asm("D_800B4ED8");

static inline char *IDX16(void *self) { return (char *)self + D_800B4CF0_w * 16; }

static inline char *IDX40(void *self) { return (char *)self + D_800B4CF0_w * 40; }

struct W3_B {
    int a, b, c;
};

EXTERN_C void func_80028184(void *self);

EXTERN_C void func_800DE760_c(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_C s, int b1, int b2, int b3) asm("func_800DE760");

EXTERN_C void func_8006EF84(void *self);

EXTERN_C int D_800B4D28_w asm("D_800B4D28");

EXTERN_C int D_800B4D30_w asm("D_800B4D30");

EXTERN_C void func_80071F08(void *self);

EXTERN_C char D_800127E4[];

struct Rgb_B {
    unsigned char v[4];
    Rgb_B() {}
};

EXTERN_C void func_8003D358_c(void *a, int b, Rgb_B c) asm("func_8003D358");

EXTERN_C void func_800435E8(void *self);

EXTERN_C short func_80073C04(void *self);

EXTERN_C void func_800DDFB0_c(void *self, int a, int b, int c, int d, int e, int f, int g, B16_B s, int h) asm("func_800DDFB0");

EXTERN_C void *func_800550BC_r(void *self) asm("func_800550BC");

EXTERN_C void func_80067ABC(void *self, void *b);

EXTERN_C void func_800680A0(void *self);

EXTERN_C int func_80058488(void *self, int b);

EXTERN_C void func_80063340(void *self, void *m);

static inline int xor_8006A6D4(int a, int b) { return a ^ b; }

#endif /* GAME_B2_B2_H */
