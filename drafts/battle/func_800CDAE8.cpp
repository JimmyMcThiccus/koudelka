// NEAR (7 differing): only instruction order/registers in the two object-creation blocks (g=D_800AF470[0] load placement; lui $v1 vs $v0). Loop and the rest match.
#include "common.h"
#include "battle/battle.h"
struct T_CDAE8_g2 { char pad[0x110]; void *f110; };
struct T_CDAE8_g { char pad[0x328]; T_CDAE8_g2 *f328; };
struct T_CDAE8 { char pad[0x2C4]; int f2C4; char pad2C8[0x670]; int f938; };
struct T_CDAE8_s { char pad[0x1B8]; int f1B8; char pad1BC[0x2E8]; unsigned f4A4_dummy_unused; };
struct T_CDAE8_s2 { char pad[0x1B8]; int f1B8; char pad1BC[0xE4]; char f2A0[4]; char f2A4[0x208]; unsigned f4AC; char pad4B0[0xD]; signed char b4BD; char pad4BE[0x92]; struct { char pad[0x8A]; unsigned char b8A; } *f550; };
EXTERN_C void func_800D68EC(void *p);
EXTERN_C void f_8299C(void *p, int a, int b, int c, int d, int e, int f) __asm__("func_8008299C");
EXTERN_C void func_80085E14(void *p);
//@ func_800CDAE8 best
EXTERN_C void func_800CDAE8(T_CDAE8 *p) {
    func_800C757C(p, 0);
    if (p->f2C4) return;
    if (p->f938) {
        T_B9844 *o = (T_B9844 *)func_8001CA10(0x14);
        void *g = D_800AF470[0];
        o->vtbl = D_80010178;
        o->f4 = 0;
        o->vtbl = D_80010300;
        o->s8 = 2;
        o->sA = 2;
        o->f10 = 0x206B;
        o->fC = 0;
        o->vtbl = D_800102D0;
        func_8001EFE4(g, o);
        p->f938 = 0;
    } else {
        func_800D68EC(((T_CDAE8_g *)D_800AF470[0])->f328->f110);
        T_B9844 *o = (T_B9844 *)func_8001CA10(0x14);
        o->vtbl = D_80010178;
        o->f4 = 0;
        o->vtbl = D_80010300;
        o->s8 = 2;
        o->sA = 2;
        o->f10 = 0x206D;
        o->fC = 0;
        void *g = D_800AF470[0];
        o->vtbl = D_800102D0;
        func_8001EFE4(g, o);
    }
    int i = 0;
    unsigned mask = 0xFFFF00;
    char one = 1;
    for (; i < 3; i++) {
        T_CDAE8_s2 *s = (T_CDAE8_s2 *)D_800AFA64[i];
        if (s && s->f1B8) {
            if (!(s->f4AC & mask)) f_8299C(s->f2A0, 0, 2, 0, 0, 0, 0);
            char *q = s->f2A4;
            int k = s->f550->b8A - 1;
            s->b4BD = one;
            func_800824C8(q, 1);
            func_800825FC(q, k);
            if (!(s->f4AC & mask)) func_80085E14(s);
            func_80082E14(s->f2A0, 0);
        }
    }
}





