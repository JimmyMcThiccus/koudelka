// func_800D2A98: NOT MATCHING. ~70 instructions: the bit-search loop keeps the mask in two registers (a1 current, v1 next) in retail. Note func_800D401C really takes (p, n): retail loads p->f5C into a1.
#include "common.h"
#include "battle/battle.h"
EXTERN_C char D_800B7A94[];
EXTERN_C void func_8008687C(void *p, int a);
struct T_D2A98_s { char pad[0x400]; char f400[0x12]; short s412; char pad414[0x44]; unsigned short h458; char pad45A[0x13]; unsigned char b46D; };
struct T_D2A98_B { int pad[2]; T_D2A98_s *items[3]; };
struct T_D2A98_D : T_D0390_A, T_D2A98_B {};
struct T_D2A98_G { char pad[0x328]; T_D2A98_D *f328; };
struct T_D2A98 { char pad[0x50]; char f50[0xC]; int f5C; char pad60[0x1C]; int f7C; char pad80[0x38]; char fB8[0x44]; char fFC[0x58]; T_D401C *f154; };
EXTERN_C void func_800D401C(T_D401C *p, int n);
EXTERN_C int func_800D2A98(T_D2A98 *p) {
    if (!func_80053830(p ? p->f50 : 0)) {
        int old = p->f5C;
        p->f5C = (old + 1) % 5;
        T_D2A98_D *d = ((T_D2A98_G *)func_800787B4())->f328; int k = p->f7C;
        T_D2A98_B *b = d;
        T_D2A98_s *s = b->items[k];
        int n = p->f5C;
        if (n < 3) {
            int m = 0x20 << n;
            while (!(s->b46D & m)) { n = p->f5C = n + 1; m <<= 1; if (n >= 3) break; }
        }
        if (p->f5C == 3 && !s->h458) p->f5C = 4;
        if (p->f5C != old) {
            func_800D401C(p->f154, p->f5C);
            if (p->f5C < 4) { func_80053CD8(p->fFC); func_80053CD8(p->fB8); }
            else { func_8008687C(s ? s->f400 : 0, 0); func_80054708(p->fFC, s->s412); func_80053BCC(p->fB8, D_800B7A94, 1); }
            func_80054CE4(p);
        }
        func_8005388C(p ? p->f50 : 0, 0x1E);
    }
    return 1;
}
