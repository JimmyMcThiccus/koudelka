// func_800CF0B0: NOT MATCHING. 14 instructions: the hoisted constants 0x21/0x201F/2 (fp/s7/s6) match, but retail compares `a < 2` with sltiu and evaluates the 6th stack argument of func_800C5B4C first.
#include "common.h"
#include "battle/battle.h"
EXTERN_C void func_800C59B8(T_C59B8 *p, T_C59B8_q *q);
typedef void (*F59B8)(void *, void *, int);
EXTERN_C void func_800C5B4C(void *p, int a, int b, int c, int d, int e, int f);
EXTERN_C void func_80082C68(void *p, int a, void *b, int c, int d);
struct T_CF0B0_s { char pad[0x2A0]; char f2A0[0x1DC]; unsigned char b47C; char pad47D[0x3F]; signed char b4BC; char pad4BD[0x8D]; unsigned char b54A; unsigned char b54B; };
EXTERN_C T_CF0B0_s *D_800AFA64[];
struct T_CF0B0_xy { short x, y; };
struct T_CF0B0 { char pad[0x7DC]; short s7DC; char pad7DE[0xE]; T_CF0B0_xy xy7EC[3]; char pad7F8[0x13C]; int f934; };
EXTERN_C int func_800CF0B0(T_CF0B0 *p, unsigned a) {
    int k1 = 0x21;
    void *g = D_800AF470[0];
    int k2 = 0x201F;
    int k3 = 2;
    if (a <= 1) {
        for (int i = 0; i < 3; i++) {
            T_CF0B0_s *s = D_800AFA64[i];
            if (s) {
                ((F59B8)func_800C59B8)(p, s, 1);
                func_800C5B4C(p, i, s->b54A, s->b54B, 0, 3, 1);
                func_80082C68(s->f2A0, k1, g, k2, k3);
                func_80082E14(s->f2A0, 0);
            }
        }
    }
    if (a == 0 || a == 2) {
        for (int i = 0; i < p->s7DC; i++) {
            T_CF0B0_s *s = (T_CF0B0_s *)D_800AFA58[i];
            if (s) {
                ((F59B8)func_800C59B8)(p, s, 2);
                func_800C5B4C(p, s->b4BC, p->xy7EC[i].x, p->xy7EC[i].y, 0, s->b47C, 1);
                func_80082C68(s->f2A0, k1, g, k2, k3);
                func_80082E14(s->f2A0, 0);
            }
        }
    }
    return p->f934;
}
