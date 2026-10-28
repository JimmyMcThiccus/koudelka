// func_800D17A4: NOT MATCHING. ~90 instructions: the SVec2 passed by value to the slot-4 virtual goes through a stack temporary at sp+0x18 here; retail packs it straight from sp+0x10 and keeps two copies of &p->e[n] (s0/s1).
#include "common.h"
#include "battle/battle.h"
EXTERN_C void func_800BE274(void *p);

EXTERN_C void *D_800B4D88[];
struct T_D17A4_e : T_D24E8_B { char pad1C[0x13C]; };
struct T_D17A4 { char pad[0xD8]; T_D17A4_e e[1]; };
struct T_D17A4b { char pad[0x574C]; void *f574C; int f5750; };
struct T_4DD0g { char pad[0x1FB]; signed char b1FB; };
EXTERN_C void func_800D17A4(T_D17A4 *p) {
    func_80056874(p);
    func_80055330(0);
    SVec2 a;
    SVec2 *pa = &a;
    int k = ((T_4DD0g *)D_800B4DD0[0])->b1FB;
    a.x = 0x56;
    int n = (int)D_800B4D5C[0];
    pa->y = (n - (k - 3)) * 19 + 0xA7;
    T_D17A4_e *e = &p->e[n];
    e->v4(SVec2C(0x56, a.y));
    SVec4 b; b.x = 4; b.y = 0; b.z = 0; b.w = 0;
    func_80054F30(e, 3, &b, 0);
    e->v2();
    func_800BE09C((T_BE0F8 *)pa);
    func_800BE274(pa);
    for (unsigned i = 0; i < 4; i++) func_8005556C(2, 1);
    T_D17A4b *q = (T_D17A4b *)p;
    if (q->f5750) {
        q->f5750 = 0;
        func_800D119C((T_D0BCC_o *)p);
        func_80055330(0);
        for (unsigned i = 0; i < 4; i++) func_8005556C(2, 1);
        D_800B4D88[0] = p;
        func_800553D8(0);
    } else func_800D0BCC(q->f574C);
}
