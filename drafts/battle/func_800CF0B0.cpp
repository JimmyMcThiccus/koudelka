// NEAR (5 differing): first f5B4C_7 call: retail loads the const arg 3 into $v1 before the a0..a3 setup; we put it in $t0 after the lbu. Everything else matches.
#include "common.h"
#include "battle/battle.h"
EXTERN_C void f59B8_3(void *p, void *q, int a) __asm__("func_800C59B8");
EXTERN_C void f5B4C_7(void *p, int a, int b, int c, int d, int e, int f) __asm__("func_800C5B4C");
EXTERN_C void f82C68_5(void *p, int a, void *b, int c, int d) __asm__("func_80082C68");
struct T_CF0B0_s { char pad[0x2A0]; char f2A0[0x1DC]; unsigned char b47C; char pad47D[0x3F]; signed char b4BC; char pad4BD[0x8D]; unsigned char b54A; unsigned char b54B; };
struct T_CF0B0_xy { short x, y; };
struct T_CF0B0 { char pad[0x7DC]; short s7DC; char pad7DE[0xE]; T_CF0B0_xy xy7EC[3]; char pad7F8[0x13C]; int f934; };
//@ func_800CF0B0 best
EXTERN_C int func_800CF0B0(T_CF0B0 *p, unsigned a) {
    int k1 = 0x21;
    void *g = D_800AF470[0];
    int k2 = 0x201F;
    char k3 = 2;
    if (a == 0 || a == 1) {
        for (int i = 0; i < 3; i++) {
            T_CF0B0_s *s = (T_CF0B0_s *)D_800AFA64[i];
            if (s) {
                f59B8_3(p, s, 1);
                int e = 3; int y = s->b54B; int x = s->b54A; f5B4C_7(p, i, x, y, 0, e, 1);
                f82C68_5(s->f2A0, k1, g, k2, k3);
                func_80082E14(s->f2A0, 0);
            }
        }
    }
    if (a == 0 || a == 2) {
        for (int i = 0; i < p->s7DC; i++) {
            T_CF0B0_s *s = (T_CF0B0_s *)D_800AFA58[i];
            if (s) {
                f59B8_3(p, s, 2);
                int x = p->xy7EC[i].x; int y = p->xy7EC[i].y; int e = s->b47C; int t = s->b4BC; f5B4C_7(p, t, x, y, 0, e, 1);
                f82C68_5(s->f2A0, k1, g, k2, k3);
                func_80082E14(s->f2A0, 0);
            }
        }
    }
    return p->f934;
}




