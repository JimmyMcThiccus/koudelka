#ifndef GAME_A2B_A2B_H
#define GAME_A2B_A2B_H

/* Declarations for area main_a2b (u_8003C510). include/game/a2/ is read-only; new ones go here. */

struct S_A2B_B4ED8 { char pad[0x94]; int unk94; };
EXTERN_C S_A2B_B4ED8 *D_800B4ED8;
EXTERN_C int func_80048C30(void *a, void *b, void *c, int d, int e);
EXTERN_C void func_800601D8(void *, char *);
EXTERN_C int D_800B4D6C;
EXTERN_C char D_800B4D78[];
EXTERN_C void func_80028184();
EXTERN_C int D_800B4CF0;
struct S_A2B_Ent { int a, b, c, d; };
struct S_A2B_Buf { char pad[8]; short mode; };
#define E_(p, i) ((S_A2B_Ent *)((char *)(p) + (i) * 16 + 0xC))
#endif /* GAME_A2B_A2B_H */
