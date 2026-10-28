// func_800CF408: MATCHES in try_compile (0 differing) but cannot land: its retail jump table (jtbl_800B7730, 5 entries) is followed by a 4-byte zero pad word (8-alignment of the next rodata object) which the compiler-generated table lacks, so battle.bin shrinks by 4 bytes. Needs a pad/align in the rodata layout (integrator).
// Prelude/types are in scratch_c/agents/b3/func_800CF408.cpp; body (landed form) below.
#include "common.h"
#include "battle/battle.h"
struct T_CF408_q { char pad[0x2A0]; char f2A0[0x170]; short s410; char pad412[0xAB]; signed char b4BD; char pad4BE[0x4C]; signed char b50A; char pad50B[0xB]; signed char b516; };
struct T_CF408_s { char pad[0x46D]; unsigned char b46D; };
struct T_CF408_x { char pad[0x2C]; T_CF408_s *f2C; };
struct T_CF408_m { int f0; int f4; int f8; T_CF408_x *fC; int f10; };
struct T_CF408_p { char pad[0xA0]; T_CF408_q *fA0; char pad_A4[0x870]; void *f914; };
EXTERN_C T_CF408_q *D_AFA64q[] __asm__("D_800AFA64");
EXTERN_C void func_80086028(void *p);
EXTERN_C void func_800C19BC_q(void *a, int b, void *c) __asm__("func_800C19BC");
EXTERN_C int func_800C0EB8_q(void *p) __asm__("func_800C0EB8");

//@ func_800CF408 best
EXTERN_C void func_800CF408(T_CF408_p *p, T_CF408_m *m) {
    switch (m->f10) {
    case 2:
        func_800C0EB8_q(p->fA0);
        break;
    case 1: {
        T_CF408_s *s = m->fC->f2C;
        func_800C19BC_q(p->fA0, 1, s);
        s->b46D &= 0xF7;
        break;
    }
    case 0: {
        void *g = p->f914;
        T_B9844 *o = (T_B9844 *)func_8001CA10(0x14);
        o->vtbl = D_80010178;
        o->f4 = 0;
        o->vtbl = D_80010300;
        o->s8 = 2;
        o->sA = 2;
        o->f10 = 0;
        o->fC = 0;
        o->vtbl = D_800102D0;
        func_8001EFE4(g, o);
        break;
    }
    case 3: {
        int flag = 0;
        p->f914 = 0;
        for (int i = 0; i < 3; i++) {
            T_CF408_q *q = D_AFA64q[i];
            if (q && q->b516) {
                char *e = q->f2A0;
                q->b516 = 0;
                func_8008299C(e, 0x29, 0, 0, 0, 0, 0);
                func_80086028(q);
                func_8008299C(e, 0x19, 0x15, 1, 0, 0, 0);
                func_8008299C(e, 0, 2, 0, 0, 0, 0);
                func_8008299C(e, 0x2A, 0, 0, 0, 0, 0);
                func_8008299C(e, 0x2A, 0, 0, 0, 0, 0);
                func_80082E14(e, 0);
                flag = 1;
            }
        }
        T_CF408_q *q = p->fA0;
        int c = !q->s410 && q->b50A;
        if (c) {
            func_8008299C(q->f2A0, 0x29, 0, 0, 0, 0, 0);
            T_CF408_q *r = p->fA0;
            if (r->b4BD == 1) func_8008299C(r->f2A0, 6, 1, 0, 0, 0, 0); else func_8008299C(r->f2A0, 0x32, 1, 0, 0, 0, 0);
            func_80086088(p->fA0, 0);
            func_8008299C(p->fA0->f2A0, 0x17, 1, 1, 0, 0, 0);
            func_8008299C(p->fA0->f2A0, 0x2A, 0, 0, 0, 0, 0);
            func_8008299C(p->fA0->f2A0, 0x2A, 0, 0, 0, 0, 0);
            func_80082E14(p->fA0->f2A0, 0);
            flag = 1;
        }
        if (!flag) func_800CDAE8(p, 0);
        break;
    }
    case 4:
        func_8007DEE8(((T_C0EB8_g *)D_800AF470[0])->f328, 0xB);
        break;
    }
}
