// func_800B8AA8: NOT MATCHING. 125 instructions differ: logic and layout match, but loop-invariant motion hoists &D_800A4534 into a saved reg
// Round-2 scratch prelude below; many of its types are now in battle.h.
// Near misses from agent A. Each needs the agentA.cpp prelude.
// func_800B9480: 9 instructions differ: register allocation only (retail loads n->f10 into a1 and copies to s1; node in s0)
//@ func_800B8AA8
EXTERN_C void func_800B8AA8(T_B8AA8 *p) {
    short f = 0;
    int dir = 1;
    while (p->f274) {
        T_MSG *m = func_8001ED2C(p, 1, 1);
        if (p->f55C && p->f508) {
            short y = p->f55C->f14->sB8;
            func_800BCA6C(p->f508, y);
            func_800BCAEC(p->f50C, y);
            if (dir) f += 0x32; else f -= 0x32;
            if ((short)(f >> 8) > 80) { dir = 0; f = 0x5000; }
            if (f < 0) { dir = 1; f = 0; }
            short h = f >> 8;
            short q = h >> 2;
            T_BCB6C_c c1, c2;
            func_8002972C(&c1, q, q, q + 20, 1);
            func_8002972C(&c2, 0, q, h, 1);
            func_800BCB6C(p->f508, &c1);
            func_800BCC2C(p->f508, &c2);
            func_800198AC(&c2, 2);
            func_800198AC(&c1, 2);
        }
        if ((unsigned)(D_800A4534.fC - p->f564) > 6) {
            p->f564 = D_800A4534.fC;
            if (++p->f560 == 4) p->f560 = 0;
        }
        if (p->f56C && p->f568) {
            p->f568->v3();
            func_800665C8(p->f568);
            p->f56C = 0;
        }
        if (!m) continue;
        if (m->hA == 2) {
            switch (m->f10) {
            case 11: {
                int x, z;
                func_8007F538(func_800787B4(), &x, &z, 0);
                T_V3 *o = func_800663EC(operator new(0x6C), 1, p, 4, x, z);
                p->f568 = o;
                func_800665C8(o);
                break;
            }
            case 9: {
                func_800B8F5C((T_B8F5C *)p);
                func_800B8EFC((S_800BA418 *)p);
                func_80036D8C(p->f568);
                p->f568 = 0;
                func_800B8FF4((T_B8FF4 *)p);
                T_BE390 *g = p->f278;
                g->f278 = 3;
                g->f26C = 0;
                func_8007F6C4(func_800787B4());
                break;
            }
            case 10:
                func_8006B5D4(p->f278);
                func_8007F820(func_800787B4());
                func_8006BDE0(D_800B4ED8[0]);
                break;
            case 0:
                p->f550->f4 = 0;
                p->f554->f4 = 0;
                p->f558->f4 = 0;
                p->f55C->f4 = 0;
                delete p->f550;
                delete p->f554;
                delete p->f558;
                delete p->f55C;
                p->f550 = 0;
                p->f554 = 0;
                p->f558 = 0;
                p->f55C = 0;
                p->f40C = 0;
                p->f274 = 0;
                break;
            }
        }
        m->v2();
    }
}
