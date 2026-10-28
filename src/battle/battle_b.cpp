#include "common.h"
#include "battle/battle.h"

EXTERN_C int func_800C1E44(T_C1E44 *p, int *out) {
    int r = func_80089024(p ? p->f400 : 0);
    *out = r;
    if (r != (int)0x80000000) {
        if (r < 0) p->b512 = 1;
        int r2 = func_8008906C(p ? p->f400 : 0);
        if (r2 != (int)0x80000000 && r2 < 0) p->b513 = 1;
        func_800890B4(p ? p->f400 : 0);
        return 0;
    }
    int r2 = func_8008906C(p ? p->f400 : 0);
    *out = r2;
    if (r2 != (int)0x80000000) {
        if (r2 < 0) p->b513 = 1;
        func_800890B4(p ? p->f400 : 0);
        return 1;
    }
    int r3 = func_800890B4(p ? p->f400 : 0);
    *out = r3;
    return r3 != (int)0x80000000 ? 2 : 0;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C1F5C);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C220C);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C2538);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C2814);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C2B70);

EXTERN_C int func_800C2ECC(S2ECC *self, S2ECC *other) {
    if (self->s4E2 != 2 || !other) return 0;
    if (other == self) self->b50A = 0;
    G2ECC *g = D_AF470_2ECC[0];
    int a = (self->b4BC << 4) | 3;
    int b = other->b4BC;
    int c = (self->s502 + 1 == self->s500) << 7;
    int d = self->b506 != 0;
    for (int i = 0x1F; i > 0; i--) g->t[i] = g->t[i - 1];
    g->t[0].b[0] = a; g->t[0].b[1] = b; g->t[0].b[2] = c; g->t[0].b[3] = d;
    self->a4F6[self->s502] = 0;
    if (!self->s410) { self->b4AD = 0; self->b4AE = 0; }
    if (self->s502 + 1 == self->s500) func_80085C00(self);
    if (self->b516) {
        func_8008299C(base_of(self), 0x18, 0x15, 0, 0, 0, 0);
        func_8008299C(base_of(self), 0, 2, 0, 0, 0, 0);
    }
    if (other->s50C != 1) func_80082C68(base_of(self), 0x21, D_AF470_2ECC[0], 0x2035, 2);
    else func_80082D44(base_of(self), 0x22, base_of(other), 0, 0);
    func_80082E14(base_of(self), 0);
    if (self->s504) self->h508++;
    self->s502++;
    return 0;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C30F0);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C3374);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C35F8);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C38FC);

EXTERN_C int func_800C3CF4() { return 1; }

EXTERN_C int func_800C3CFC() { return 1; }

EXTERN_C int func_800C3D04(T_C3D04 *p, int a, int b, int c) { if (~c & b & 2) { p->b516 = 1; return 0; } return 0; }

EXTERN_C void func_800C3D2C(T_C3E34 *p, int i, int k, int *o1, int *o2) {
    int n = p->h548;
    if (n > 2) n = 2;
    int a = T_tab[i].e[n * 3 + k].f0;
    int b = T_tab[i].e[n * 3 + k].f4;
    *o1 = a;
    *o2 = b;
    if (!b) {
        int c = T_tab[i].e[n * 3].f0;
        int d = T_tab[i].e[n * 3].f4;
        *o1 = c;
        *o2 = d;
    }
}

EXTERN_C void func_800C3DAC(void *p, int a, int j, int *o1, int *o2) {
    T_C3DAC *q = func_80061188(D_800B4DD0[0], a);
    int off = j * 8;
    char *r = (char *)q + 0x14;
    int v;
    *o1 = *(int *)(r + off + 0x24);
    *o2 = v = *(int *)(r + off + 0x28);
    if (!v) { *o1 = q->r.e[0].f0; *o2 = q->r.e[0].f4; }
}

EXTERN_C void func_800C3E34(T_C3E34 *p, int i, int j, int *o1, int *o2) {
    C3E34_get(&p->r[i], j, o1, o2);
}

EXTERN_C void func_800C3E84(T_C3E34 *p, int *o1, int *o2) {
    if (p->s53C == 3) {
        func_800C3F14(p, o1, o2);
    } else {
        T_C3E34 *q = func_800C9E58_b(((T_C19BC_g *)D_800AF470[0])->f32C, 0);
        int eq = p->b4BD == q->b4BD;
        func_800C3D2C(p, p->s53E, eq, o1, o2);
    }
}

EXTERN_C void func_800C3F14(T_C3E34 *p, int *o1, int *o2) {
    T_C3E34 *q = func_800C9E58_b(((T_C19BC_g *)D_800AF470[0])->f32C, 0);
    func_800C3DAC(p, p->f540, p->b4BD == q->b4BD, o1, o2);
}

EXTERN_C void func_800C3F84(T_C3E34 *p, int *o1, int *o2) {
    T_C3E34 *q = func_800C9E58_b(((T_C19BC_g *)D_800AF470[0])->f32C, 0);
    int eq = p->b4BD == q->b4BD;
    func_800C3E34(p, p->s53E, eq, o1, o2);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C3FF4);

EXTERN_C int func_800C41AC(T_41AC *p) {
    if (!f_53830(p)) {
        void *s0 = func_800621F8(D_800B4DD0[0]);
        if (s0) { func_800C5020(operator new(0x78), (char *)s0, 0x3C); func_80062214(D_800B4DD0[0]); }
        delete p;
        return 0;
    }
    short t = D_800A4534.fC - p->h54;
    if (t > 0x3C) {
        ((T_41AC_B *)p)->m3();
    } else {
        short s0 = t < 12 ? t * 2 : t / 2 + 0x12;
        T_41AC_X *x = p->f30;
        T_41AC_Y *y = x;
        T_41AC_Z *z = y ? y->f0 : 0;
        T_41AC_W *w = z->f4 ? z->f0->f0 : 0;
        w->m11(0, p->s56 - (short)s0);
        p->s56 = s0;
    }
    return 1;
}

EXTERN_C void func_800C435C(T_C435C *p, int x) {
    if (p->f8) {
        func_8005C088(p, x, 1);
        List *l = p->f30;
        func_80019A6C(l, (int)func_800C4510((T_C4510 *)operator new(0x3C), (SVec4 *)p->f44, p->f4C, p->f50), count_of(l));
        func_8002DA94(x, p->f30);
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C43F0);

EXTERN_C T_C4510 *func_800C4510(T_C4510 *p, SVec4 *pos, int a, int flags) {
    ((F_5F0E4)func_8005F0E4)(p, 2);
    p->vtbl = D_800B7538;
    p->f10 = *pos;
    p->f18.x = 0;
    p->f18.y = 0;
    p->f34 = 1;
    SetDrawMode(&p->f1C[0], 0, 0, (unsigned short)func_80060154(D_800AE640, 0x40), 0);
    SetDrawMode(&p->f1C[1], 0, 0, (unsigned short)func_80060154(D_800AE640, 0x40), 0);
    if (a == (int)0x80000000) func_800C4EC4(p);
    else func_800C4B70(p, a, flags & 0xFFFB);
    if (flags & 4) {
        T_BCB6C_c *c = D_800B4CB0;
        for (unsigned int i = 0; i < p->f34; i += 2) {
            int k = i + D_800B4CF0[0];
            p->f38[k].b.r = c->r;
            p->f38[k].b.g = c->g;
            p->f38[k].b.b = c->b;
        }
    }
    int cur = D_800B4CF0[0];
    int oth = cur ^ 1;
    for (unsigned int i = 0; i < p->f34; i += 2) {
        T_C4510_q *src = (T_C4510_q *)&p->f38[i + cur];
        int a = src->a, b = src->b, c = src->c;
        T_C4510_q *dst = (T_C4510_q *)&p->f38[i + oth];
        dst->a = a;
        dst->b = b;
        dst->c = c;
    }
    func_8005F1D8(p);
    return p;
}

EXTERN_C void func_800C46F0(T_C46F0 *p, int flags) { p->vtbl = D_800B7538; if (p->f38) delete[] (char *)p->f38; p->f38 = 0; func_8005F120(p, flags); }

EXTERN_C void func_800C4748(T_C4748 *p, int a, int b) { p->s18 += a; p->s1A += b; func_8005F1D8(p); }

EXTERN_C void func_800C477C() {}

EXTERN_C void func_800C4784(T_C4784 *p, int a, int b) {
    int i = D_800B4CF0[0];
    p->v11(a - p->f38[i].x, b - p->f38[i].y);
}

EXTERN_C T_C47D8 *func_800C47D8(T_C47D8 *p) {
    T_C47D8 *q = (T_C47D8 *)operator new(0x3C);
    q->vtbl = D_80010178;
    int t4 = p->f4;
    q->vtbl = D_800111BC;
    q->f4 = t4;
    q->s8 = p->s8;
    short tA = p->sA;
    q->vtbl = D_80014BD0;
    q->sA = tA;
    int tC = p->fC;
    q->vtbl = D_800B7538;
    q->fC = tC;
    q->f10 = p->f10;
    q->f18 = p->f18;
    T_C47D8_1C *d = q->f1C;
    int n = 1;
    T_C47D8_1C *src = p->f1C;
    do {
        *d = *src;
        d++;
        n--;
        src++;
    } while (n != -1);
    q->f34 = p->f34;
    q->f38 = p->f38;
    return q;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C48D8);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C4B70);

EXTERN_C void func_800C4EC4(T_C4510 *p) {
    T_BCB6C_c *c = D_800B4C88;
    p->f34 = 8;
    p->f38 = (T_C4510_p *)func_800A0D2C(0x80);
    for (unsigned int i = 0; i < p->f34; i++) {
        ((T_C4EC4_s *)p->f38)[i].len = 3;
        ((T_C4EC4_s *)p->f38)[i].code = 0x74;
    }
    int tp = func_800600A4(D_800AE640, 0x40);
    for (unsigned int i = 0; i < p->f34; i += 2) {
        int h = i >> 1;
        int k = i + D_800B4CF0[0];
        ((T_C4EC4_s *)p->f38)[k].r = c->r;
        ((T_C4EC4_s *)p->f38)[k].g = c->g;
        ((T_C4EC4_s *)p->f38)[k].b = c->b;
        ((T_C4EC4_s *)p->f38)[k].x = -(h * 8);
        ((T_C4EC4_s *)p->f38)[k].y = 0;
        int u = 0x98 - h * 8;
        ((T_C4EC4_s *)p->f38)[k].u = u;
        ((T_C4EC4_s *)p->f38)[k].v = 0;
        ((T_C4EC4_s *)p->f38)[k].clut = tp;
    }
}

EXTERN_C void func_800C5018() {}

EXTERN_C void *func_800C5020(void *pv, char *str, int n) {
    T_C5020 *p = (T_C5020 *)pv;
    func_800537C0(p);
    p->vtbl8 = D_800B75A0;
    func_800538CC(p->fC, str, 0);
    func_80054AF0(p->f28, 1);
    func_8005388C(p, n);
    func_80053FB0(p->fC, 1, 0x130);
    func_80054E18(p->f28, p->fC);
    func_80055020(p->f28, SVec2C(0xC, 0xA));
    func_80054EB4(p->f28, 0x130, 0x10);
    SVec4 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    v.w = 3;
    func_80054F30(p->f28, 5, &v, 0);
    func_80054FC0(p->f28);
    return p;
}

EXTERN_C int func_800C5124(T_C5124 *p) { if (func_80053830(p)) return 1; func_80054FE0(p->f28); delete p; return 0; }

EXTERN_C void func_800C5180(T_C5180 *p, int a) { func_80054C34(p->f28, 2); func_80053964(p->fC, 2); func_800537DC(p, a); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C51D0);

EXTERN_C char *func_800C5474(T_C5474 *p) {
    S_800D00B8 *x = p->f0;
    if (!x) return 0;
    p->f4 = x;
    if (x->f10 <= p->f12C) {
        int r = x->f14;
        S_800D00B8 *n = func_800752B8(p, x);
        n->prev = n;
        n->next = n;
        n->fC = 0;
        return (char *)r;
    }
    return 0;
}

EXTERN_C int func_800C54D8(void *vp, void *vk) {
    T_It *it = (T_It *)vp;
    int key = (int)vk;
    if (it->empty()) return 0;
    goto start;
found:
    { S_800D00B8 *n = f752B8_1(it); n->prev = n; n->next = n; n->fC = 0; return key; }
start:
    it->cur = it->head;
    while (1) {
        if (key == it->cur->f14) goto found;
        if (it->is_last()) return 0;
        it->next();
    }
}

EXTERN_C void func_800C55C4(T_C55C4 *p) {
    memset(p->e110, 0xFF, 0x1C);
    p->cur = p->head;
    int i = 0;
    for (;;) {
        S_800D00B8 *n = p->cur;
        int t = team_of((void *)n->f14);
        p->e110[i].b3 = t;
        int v = n->f10;
        p->e110[i].s0 = v;
        if (p->is_last()) break;
        i++;
        p->next();
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C56A8);

EXTERN_C void func_800C5880(T_C5880 *p, int flags) {
    p->vtbl = D_800B7748;
    func_800C1BA8(p->f4);
    reset_nodes((T_D0054 *)&p->fA4);
    func_800D0588(p->f908);
    operator delete(p->f908);
    T_C5880_e *a = p->a3E8;
    if (a) {
        T_C5880_e *e = a + 41;
        if (a != e) {
            T_C5880_e *s = a;
            do { --e; } while (s != e);
        }
    }
    T_D019C *m = &p->fA4;
    m->vtblC = D_800B7768;
    func_800D0074((T_D0054 *)m);
    T_D019C_e *b = m->nodes;
    if (b) {
        T_D019C_e *e = b + 10;
        if (b != e) {
            T_D019C_e *s = b;
            do { (--e)->~T_D019C_e(); } while (s != e);
        }
    }
    func_80074F78(m, 2);
    func_800C1A44((T_C1A44 *)p->f4, 2);
    if (flags & 1) operator delete(p);
}

EXTERN_C void func_800C59B8(T_C59B8 *p, T_C59B8_q *q) { func_8007505C(p->f4, q ? q->f4A0 : 0); }

EXTERN_C int func_800C59EC(T_C59EC *p) { int r; void *v = func_800C1A6C(p->f4); if (v) r = func_800C5A30(p, v); else r = 0; return r; }

EXTERN_C int func_800C5A30(void *pv, void *qv) {
    T_C5E1C *p = (T_C5E1C *)pv;
    T_C5A30_q *q = (T_C5A30_q *)qv;
    if (!q) return 0;
    if (q->b4C4) {
        p->f14[q->s4CA][q->s4C6] = 0;
        func_80085A58(q);
    }
    if (p->fA0 == q) p->fA0 = 0;
    func_800C54D8(p->fA4, q);
    char *r = func_80075448((char *)p + 4, q->f4A0);
    return r ? (int)(r - 0x4A0) : 0;
}

EXTERN_C void func_800C5AD0(T_C5AD0 *p, T_C5B18_q *q) { if (q && q->b4C4) { if (p->fA0 == q) p->fA0 = 0; func_800C54D8(p->fA4, q); } }

EXTERN_C void func_800C5B18(T_C5B18 *p, T_C5B18_q *q) { if (q && q->b4C4) func_800C51D0(p->fA4, q); }

EXTERN_C int func_800C5B4C(T_C5E1C *p, int team, int x, int y, int a, int b) {
    if (p->f14[y][x]) return 0;
    T_C5B4C_q *q = (T_C5B4C_q *)func_800C1A6C_2((char *)p + 4, team);
    if (!q) return 0;
    if (!q->b4C4) {
        p->f14[y][x] = (T_C1340 *)q;
        SVec4 pos;
        SVec4 *pp = &pos;
        pos.x = x;
        pp->y = a;
        pp->z = y;
        pp->w = 0;
        func_80085A08(q, pos, b);
        T_VEC v;
        int f = q->b4BD == 1;
        v.x = (x - 2) * 0x960;
        v.z = (3 - y) * 0x960;
        v.y = 0;
        v.w = 0;
        func_800849D0(q, v, f << 11, 1);
        pos.x = x;
        pp->y = y;
        func_800CDED8_b(&p->f3D8, (SVec2 *)pp, q);
        return 1;
    }
    return 0;
}

EXTERN_C int func_800C5CC4(T_C5E1C *p, int a, int x, int y) {
    if (p->f14[y][x]) return 0;
    T_C5A30_q *q = (T_C5A30_q *)func_800C1A6C_2((char *)p + 4, a);
    if (!q) return 0;
    p->f14[q->s4CA][q->s4C6] = 0;
    p->f14[y][x] = (T_C1340 *)q;
    func_80085A60(q, SVec2C(x, y));
    return 1;
}

EXTERN_C T_C5D84 *func_800C5D84_r(T_C5E1C *p, int a) {
    T_C5D84 *q = (T_C5D84 *)func_800C1A6C((char *)p + 4);
    if (!q) return 0;
    p->f14[q->s4CA][q->s4C6] = 0;
    func_80085A58(q);
    func_800C54D8(p->fA4, q);
    int k = func_800CE110(&p->f3D8, (int)q);
    if (k >= 0) func_800CDF64(&p->f3D8, k);
    return q;
}

EXTERN_C T_C1340 *func_800C5E1C(T_C5E1C *p, int a, int b) { T_C1340 *q = p->f14[b][a]; p->f14[b][a] = 0; if (q) { func_80085A58(q); func_800C54D8(p->fA4, q); int k = func_800CE110(&p->f3D8, (int)q); if (k >= 0) func_800CDF64(&p->f3D8, k); } return q; }

EXTERN_C void func_800C5EA0(T_C5E1C *p) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) func_800C5E1C(p, j, i); }

EXTERN_C int func_800C5F08(T_C5E1C *p, int a, int b) { if (!in_grid(a, b)) return -1; T_C1340 *q = p->f14[b][a]; if (!q) return 0; if (q->b4BD == 1) return 1; return 2; }

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C5F84);

EXTERN_C void func_800C6050(T_C6050 *p) {
    T_C5474 *l = &p->fA4;
    T_C6050_n *n;
    while ((n = (T_C6050_n *)func_800751AC(l)) != 0) { n->prev = n; n->next = n; n->fC = 0; }
    l->f12C = 0;
    for (int i = 0; i < 3; i++) { T_C6050_c *c = (T_C6050_c *)D_800AFA64[i]; if (c) c6050_reset(p, c); }
    for (int i = 0; i < 3; i++) { T_C6050_c *c = (T_C6050_c *)D_800AFA58[i]; if (c) c6050_reset(p, c); }
    p->f830 = 1;
    func_800C6194(p);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C6194);

EXTERN_C int func_800C65C8(T_C65C8 *p, int a) {
    if (p->fA0) ((F_C51D0)func_800C51D0)(&p->fA4, p->fA0, a);
    p->fA0 = 0;
    if (!p->fA4.f0) return 0;
    T_C5474 *l = &p->fA4;
    while (!(p->fA0 = func_800C5474(l))) l->f12C++;
    func_800D94F4(p->fA0 ? p->fA0 + 0x400 : 0);
    return 1;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C666C);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C68D8);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C6DF4);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C7158);

EXTERN_C int func_800C7528() {
    int n = 0;
    for (int i = 0; i < 3; i++) {
        T_C1340 *p = D_800AFA64[i];
        if (p && p->s410) n++;
    }
    return n == 0;
}

EXTERN_C int func_800C757C(void *pp, int a) {
    T_C757C *p = (T_C757C *)pp;
    if (p->f2C4 >= 0) {
        if (a) { void *d = D_800AF470[0]; p->f2C4++; func_80078C38(d, D_800B75F0, p->f2C4, 0, 0, 0, 0, 0, 0, 0, 0); }
        else { void *d = D_800AF470[0]; p->f2C4--; func_80078C38(d, D_800B7620, p->f2C4, 0, 0, 0, 0, 0, 0, 0, 0); }
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C7604);

EXTERN_C void func_800C7764_t(T_C9A4C *p, int x, int y, int d, int max) {
    if (max < d) return;
    if (x - 1 >= 0 && (p->b2C8[y][x - 1] == -1 || d < p->b2C8[y][x - 1])) { p->b2C8[y][x - 1] = d; func_800C7764_t(p, x - 1, y, d + 1, max); }
    if (x + 1 < 5 && (p->b2C8[y][x + 1] == -1 || d < p->b2C8[y][x + 1])) { p->b2C8[y][x + 1] = d; func_800C7764_t(p, x + 1, y, d + 1, max); }
    if (y - 1 >= 0 && (p->b2C8[y - 1][x] == -1 || d < p->b2C8[y - 1][x])) { p->b2C8[y - 1][x] = d; func_800C7764_t(p, x, y - 1, d + 1, max); }
    if (y + 1 < 7 && (p->b2C8[y + 1][x] == -1 || d < p->b2C8[y + 1][x])) { p->b2C8[y + 1][x] = d; func_800C7764_t(p, x, y + 1, d + 1, max); }
}

EXTERN_C int func_800C78EC_i(T_C9A4C *p, int a) {
    T_C9284 &q = *p->fA0;
    if (!&q) return 0;
    func_800C7D88((T_Grids *)p);
    int h = q.s4C8;
    func_800C7DD0(p, h, 0, 0);
    int n = 0;
    place(p, q.s4C6, q.s4CA, q.b4C5);
    func_800C8EE4((T_C8EE4 *)p, q.b4BD);
    if (a) func_800C7DD0(p, h, 1, 0);
    else n = -func_800C7DD0(p, h, 1, 1);
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 5; x++)
            if (p->b2C8[y][x] > 0) n++;
    return n;
}

EXTERN_C void func_800C7A28(T_C9A4C *p, void *l, int x, int y) {
    T_C9284 *q = p->fA0;
    if (!q) return;
    func_800C7D88((T_Grids *)p);
    func_800C7DD0(p, q->s4C8, 0, 0);
    place(p, q->s4C6, q->s4CA, q->b4C5);
    func_800C8EE4((T_C8EE4 *)p, q->b4BD);
    if (p->b2C8[y][x] >= 0 && !p->f14[y][x]) {
        p->f844 = 0x7FFFFFFF;
        func_800C7B5C((P7B5C *)p, 0, l, x, y);
        func_80075004(l, func_80085AD4(operator new(0x10), x, y));
    }
}

EXTERN_C bool func_800C7B5C(P7B5C *p, int a, void *l, int x, int y) {
    int c = p->b2C8[y][x];
    if (c == 0) {
        if (a < p->f844) {
            p->f844 = a;
            T_Obj8 *n;
            while ((n = (T_Obj8 *)func_800751AC(l)) != 0) delete n;
            return true;
        }
        return false;
    }
    if (c < 0) return false;
    void *last = 0;
    for (int i = 0; i < 4; i++) {
        x += D_800D5D84[i];
        y += D_800D5D94[i];
        if (!valid7b5c(x, y)) continue;
        int v = p->b2C8[y][x];
        if (v < 0 || !(v < c)) continue;
        int d = func_800C9EF4(p, p->f834, p->f838, p->f83C, p->f840, x * 100, y * 100);
        if (!func_800C7B5C_b(p, a + SquareRoot0(d), l, x, y)) continue;
        last = func_80085AD4(operator new(16), x, y);
        func_80075004(l, last);
    }
    return last != 0;
}

EXTERN_C void func_800C7D88(T_Grids *p) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) p->b2C8[i][j] = -1; }

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C7DD0);

EXTERN_C void func_800C7F30(T_Grids *p, char v) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) p->b380[i][j] = v; }

EXTERN_C void func_800C7F74(T_Grids *p, char v) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) p->b3A3[i][j] = v; }

EXTERN_C void func_800C7FB8(T_Grids *p) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) p->b3A3[i][j] |= p->b380[i][j]; }

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B75F0);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B7620);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C800C);

EXTERN_C bool func_800C8A54(T_C9A4C *p, int x1, int y1, int x, int y) {
    func_800C8BA4(p, x1, y1, x, y);
    p->b3A3[y1][x1] = 0;
    p->b3A3[y][x] = 0;
    for (int yy = 0; yy < 7; yy++) {
        for (int xx = 0; xx < 5; xx++) {
            T_C9284 *c = p->f14[yy][xx];
            int m = p->b3A3[yy][xx];
            if (c && m) {
                if (c->b4BD == 1) { if (c->s410 && (m & 4)) return 1; }
                else switch (c->b94A) {
                case 1: if (m & 2) return 1; break;
                case 2: if (m & 1) return 1; break;
                case 0: break;
                }
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C8BA4);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C8D9C);

EXTERN_C void func_800C8EE4(T_C8EE4 *p, int a) {
    int lo, hi;
    if (((F_C8D9C)func_800C8D9C)(p, a == 1 ? 2 : 1, &hi, &lo) < 0) return;
    for (int y = lo; y <= hi; y++) {
        for (int x = 0; x < 5; x++) p->b2C8[y][x] = -3;
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C8F78);

EXTERN_C int func_800C9284(T_C9A4C *p, int a, T_C9284 *q, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 2);
    func_800C7F30((T_Grids *)p, 0);
    if (c != 12 && !q->s410) return 0;
    add_cell(p, q->s4C6, q->s4CA);
    return p->f848;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800C9374);

EXTERN_C int func_800C9584(T_C9A4C *p, int a, T_C9284 *q, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 4);
    func_800C7F30((T_Grids *)p, 0);
    if (c != 12 && !q->s410) return 0;
    add_cell(p, q->s4C6, q->s4CA);
    return p->f848;
}

EXTERN_C int func_800C9674(T_C9A4C *p, T_C9284 *q1, T_C9284 *q2, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 9);
    func_800C7F30((T_Grids *)p, 0);
    if (c != 12 && !q2->s410) return 0;
    int x1 = q1->s4C6, y1 = q1->s4CA;
    int x = q2->s4C6, y = q2->s4CA;
    if (in_grid(x, y) && !p->b2C8[y][x]) {
        if (!func_800C8A54(p, x1, y1, x, y)) { p->b380[y][x] = 1; p->f84C[p->f848++] = p->f14[y][x]; }
    }
    return p->f848;
}

EXTERN_C int func_800C9794(T_C9A4C *p, T_C9284 *q, int b, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 5);
    func_800C7F30((T_Grids *)p, 0);
    int d = 1;
    int x = q->s4C6, y = q->s4CA;
    if (q->b4BD == 1) d = -1;
    add_cell(p, x + (d << 1), y + d);
    add_cell(p, x + d, y + d);
    return p->f848;
}

EXTERN_C int func_800C98F0(T_C9A4C *p, T_C9284 *q, int b, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 6);
    func_800C7F30((T_Grids *)p, 0);
    int d = 1;
    int x = q->s4C6, y = q->s4CA;
    if (q->b4BD == 1) d = -1;
    add_cell(p, x - d * 2, y + d);
    add_cell(p, x - d, y + d);
    return p->f848;
}

EXTERN_C int func_800C9A4C(T_C9A4C *p, int a, int b, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 7);
    func_800C7F30((T_Grids *)p, 0);
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 5; x++) {
            if (!p->b2C8[y][x]) { p->b380[y][x] = 1; p->f84C[p->f848++] = p->f14[y][x]; }
        }
    }
    return p->f848;
}

EXTERN_C int func_800C9B04(T_C9A4C *p, T_C9284 *q, int b, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 8);
    func_800C7F30((T_Grids *)p, 0);
    int d = 1;
    int x = q->s4C6, y = q->s4CA;
    if (q->b4BD == 1) d = -1;
    for (int i = -1; i < 2; i++) add_cell(p, x + i * d, y + d);
    return p->f848;
}

EXTERN_C int func_800C9BFC(T_C9A4C *p, T_C9284 *q, int b, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 11);
    func_800C7F30((T_Grids *)p, 0);
    int d = 1;
    int x = q->s4C6, y = q->s4CA;
    if (q->b4BD == 1) d = -1;
    for (int i = -1; i < 2; i++) { int cx = x + i * d; add_cell(p, cx, y + d); add_cell(p, cx, y + (d << 1)); }
    return p->f848;
}

EXTERN_C int func_800C9D6C(void *pp, void *aa, int b, int c, int mode, int x) {
    int r = 0;
    switch (mode) {
    case 1: r = func_800C8F78((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 2: r = ((F_GRID5)func_800C9284)((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 3: r = func_800C9374((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 4: r = ((F_GRID5)func_800C9584)((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 5: r = ((F_GRID5)func_800C9794)((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 6: r = ((F_GRID5)func_800C98F0)((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 7: r = ((F_GRID5)func_800C9A4C)((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 8: r = ((F_GRID5)func_800C9B04)((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 9: r = ((F_GRID5)func_800C9674)((T_C9A4C *)pp, (int)aa, b, c, x); break;
    case 11: r = ((F_GRID5)func_800C9BFC)((T_C9A4C *)pp, (int)aa, b, c, x); break;
    }
    return r;
}

EXTERN_C int func_800C9E58(T_C9E58 *p, int i) { if (i < p->f848) return p->f84C[i]; return 0; }

EXTERN_C int func_800C9E84(T_C9E58 *p, int a) { if (!a) return 0; for (int i = 0; i < 6; i++) if (func_800C9E58(p, i) == a) return 1; return 0; }

EXTERN_C int func_800C9EF4(void *self, int x0, int y0, int x1, int y1, int px, int py) {
    int dx = x1 - x0, dy = y1 - y0;
    int l = dx * dx + dy * dy;
    x0 -= px; y0 -= py;
    if (l == 0) return 0;
    int t = -(x0 * dx + y0 * dy);
    int ex = x0 + t * dx / l;
    int ey = y0 + t * dy / l;
    return ex * ex + ey * ey;
}

EXTERN_C int func_800C9FFC(T_C9FFC *p, T_C9FFC_in *in, int arg) {
    int b = ~in->h1A;
    if (b & 0x4000) { func_800CF95C((T_CF95C *)p); return 2; }
    if (b & 0x2000) {
        if (p->f3D0 == 2) {
            T_CDD0C_v t;
            t = T_CDD0C_v(p->fA0->s4C6, p->fA0->s4CA);
            if (t != p->s3C6) goto call;
            return 3;
        }
    call:
        func_800CF95C((T_CF95C *)p);
        return 3;
    }
    return c9ffc_dir(p, b, arg);
}
inline int c9ffc_move1(T_C9FFC *p, int dir, int arg) {
    int d = (dir - p->f3CC + 8) % 8;
    if (func_800CA1B4(p, &p->s3C6, d / 2, arg, 0) < 0) { func_8008EF40(14); return 0; }
    func_800CA7D4((T_CA7D4 *)p, 1, p->s3C6.x, p->s3C6.y, 1);
    func_8008EF40(8);
    func_800CF9CC((T_CF95C *)p, p->s3C6.x, p->s3C6.y);
    return 1;
}
inline int c9ffc_dir1(T_C9FFC *p, int b, int arg) {
    int dir;
    if (b & 0x10) dir = 0;
    else if (b & 0x20) dir = 2;
    else if (b & 0x40) dir = 4;
    else if (b & 0x80) dir = 6;
    else return 0;
    return c9ffc_move1(p, dir, arg);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CA1B4);

EXTERN_C void func_800CA710(T_CA710 *p, int a) { if (!a) p->f864 = -1; T_B9268 *x = D_800AF470[0]->f384; if (p->b954 & 1) func_800B9268(x, &p->f864); }

EXTERN_C int func_800CA75C(T_CA75C *p) { int n = 0; for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) if (p->b2C8[i][j] >= 0) p->f864[n++] = i * 5 + j; p->f864[n] = -1; return n; }

EXTERN_C void func_800CA7D4(T_CA7D4 *p, int a, int x, int y, int e) {
    int n = 0;
    p->b955++;
    if (a) {
        T_C9284 *q = p->fA0;
        if (in_grid(x, y)) p->f8F4[n++] = x + y * 5;
        if (e && q) {
            if (moved(q, x, y)) p->f8F4[n++] = q->s4C6 + q->s4CA * 5;
            func_800CA918(p, 1);
        }
    } else func_800CA918(p, 0);
    p->f8F4[n] = -1;
    T_B9268 *g = D_800AF470[0]->f384;
    if (p->b954 & 2) func_800B928C(g, p->f8F4);
    p->b955--;
}

EXTERN_C void func_800CA918(void *pp, int a) {
    T_C5AD0 *p = (T_C5AD0 *)pp;
    T_C5B18_q *q = (T_C5B18_q *)p->fA0;
    T_C5B18_q *r = q;
    if (q && ((signed char *)q)[0x4BD] != 2) {
        if (a) { T_CA918_cc c; c.r = 0x40; c.g = 0x40; c.b = 0x40; func_8003FB88x(q, 1, c); }
        else func_8003FB88x(r, 0, T_CA918_cc());
    }
}

EXTERN_C void func_800CA9D0(T_C9A4C *p, int a, int b) {
    T_C9284 *q = p->fA0;
    if (!q) return;
    SVec2I c(q->s4C6, q->s4CA);
    int k = q->b4BD;
    func_800C800C(p, c, a, b, k);
    func_800C7D88((T_Grids *)p);
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 5; x++) {
            if (p->b380[y][x] && p->f14[y][x]) {
                if (a != 12) { if (p->f14[y][x]->s410) p->b2C8[y][x] = 0; }
                else if (!p->f14[y][x]->s410) p->b2C8[y][x] = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CAAF8);

EXTERN_C int func_800CACD8(T_CAD5C *p) {
    T_CAD5C_q &q = *p->fA0;
    int r = func_800C07F8(&q, 0);
    if (r < 0) return 0;
    p->f900 = q.s514 + 1;
    func_800CADDC(p, 0);
    if (r) p->f900++;
    return 1;
}

EXTERN_C int func_800CAD5C(T_CAD5C *p) {
    T_CAD5C_q &q = *p->fA0;
    int r = func_800C13CC(&q);
    if (r < 0) return 0;
    p->f900 = q.s514 + 1;
    func_800CADDC(p, 0);
    if (r) p->f900++;
    return 1;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CADDC);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CB174);

EXTERN_C void func_800CB8EC(T_CB8EC *p, int a) {
    T_BE0F8 t;
    func_800BE09C(&t);
    switch (p->f3D0) {
    case 2: put(put(&t, T_CB8EC_k(0)), T_CB8EC_k(a != 0)); break;
    case 4: put(put(&t, T_CB8EC_k(0)), T_CB8EC_k(a != 0)); break;
    case 7: put(put(&t, T_CB8EC_k(0)), T_CB8EC_k(a != 0)); break;
    case 8: put(put(&t, T_CB8EC_k(0)), T_CB8EC_k(a != 0)); break;
    }
}

EXTERN_C void func_800CB9F0(T_CBA50 *p) { if (!p->f908) p->f908 = func_800D0404((T_D0404 *)operator new(0x74)); func_800D0440(p->f908, 0xFF, 0); func_800D044C(p->f908); }

EXTERN_C void func_800CBA50(T_CBA50 *p) { if (p->f908) func_800D0BCC(p->f908); }

EXTERN_C void func_800CBA80(T_CBA50 *p, int a, int b, int c) {
    if (p->f908) {
        func_800D0440(p->f908, 0xFF, 0);
        int m = 0;
        if (!(b & 1)) m = 1;
        if (!(b & 2)) m |= 4;
        if (c & 1) m |= 1;
        if (c & 2) m |= 2;
        if (c & 4) m |= 4;
        func_800D0440(p->f908, m, 1);
        func_800D05C4(p->f908);
    }
}

EXTERN_C void func_800CBB24(T_CBA50 *p) { if (p->f908) func_800D0590(p->f908); }

EXTERN_C void func_800CBB54(T_CBA50 *p) { if (p->f908) func_800D0598(p->f908); }

EXTERN_C void func_800CBB84(T_CBA50 *p) { if (p->f908) func_800D0C88(p->f908); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CBBB4);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CC110);

EXTERN_C void *func_800CC1B0(T_CC1B0 *p) { for (T_CE044_10 *e = func_800CE044(&p->f3D8); e; e = func_800CE090(&p->f3D8)) if ((e->h8 & 1) && (e->h8 & 0x20)) return e->p4; return 0; }

EXTERN_C T_CE044_10 *func_800CC220(T_CC1B0 *p, void *a) { for (T_CE044_10 *e = func_800CE044(&p->f3D8); e; e = func_800CE090(&p->f3D8)) if ((e->h8 & 1) && e->p4 == a) return e; return 0; }

EXTERN_C T_CE044_10 *func_800CC298(T_CC1B0 *p, unsigned mode, unsigned short mask) {
    T_CE044_10 *e = 0;
    switch (mode) {
    case 0: e = func_800CE00C(&p->f3D8); break;
    case 1: e = func_800CE044(&p->f3D8); D_800D5DA4[0] = 1; break;
    case 2: e = func_800CE064(&p->f3D8); D_800D5DA4[0] = -1; break;
    case 3: e = func_800CE090(&p->f3D8); D_800D5DA4[0] = 1; break;
    case 4: e = func_800CE0D4(&p->f3D8); D_800D5DA4[0] = -1; break;
    }
    while ((e->h8 & mask) != mask) {
        T_CE044 *l = &p->f3D8;
        if (D_800D5DA4[0] > 0) { e = func_800CE090(&p->f3D8); if (e) continue; func_800CE064(&p->f3D8); return 0; }
        e = func_800CE0D4(&p->f3D8); if (e) continue; func_800CE044(&p->f3D8); return 0;
    }
    return e;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CC3DC);

EXTERN_C void func_800CC7DC(T_CC7DC *p, T_CDD0C_v pos, int flag) {
    int k = p->fA0->f4D8;
    if (k < 5) return;
    if (k >= 9 && k != 11) return;
    T_CC7DC_e *e;
    for (e = cc7dc_first(p); e; e = cc7dc_next(p))
        if ((e->h8 & 2) && e->at(pos)) break;
    if (!e) return;
    if (e->h8 & 0x500) return;
    e->fC = 0; e->f10 = 0; e->f14 = 0;
    for (T_CC7DC_e *f = cc7dc_first(p); f; f = cc7dc_next(p)) {
        if (f->f4 && p->b380[f->f0.y][f->f0.x]) {
            T_C9284 *q = p->f14[f->f0.y][f->f0.x];
            if (q) {
                e->h8 |= flag; e->fC++;
                if (q->b4BD == 1) e->f10++; else e->f14++;
            }
        }
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CC98C);

EXTERN_C void func_800CCB98(T_C5E1C *p, int dx, int dy, T_CCB98 *s) {
    int x = s->f0.x, y = s->f0.y;
    if (!in_grid(x + dx, y + dy)) return;
    T_C1340 *q = p->f14[y + dy][x + dx];
    if (q) { s->fC++; if (q->b4BD == 1) s->f10++; else s->f14++; }
}

EXTERN_C void func_800CCC4C(T_C9A4C *p, SVec2C v, int a) {
    func_800C78EC(p, p->fA0->b4C5 != 0);
    p->l2EC.reset();
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 5; x++)
            if (p->b2C8[y][x] >= 0) p->l2EC.push(SVec2C(x, y));
    T_L2EC *l = &p->l2EC;
    func_800CE4E4(l, v, a);
    l->f90 = 0;
    while (l2ec_next(&p->l2EC)) ;
}

EXTERN_C int func_800CCD70(T_CCD70 *p, SVec2 v) { func_800C78EC(p, p->fA0->b4C5 != 0); return p->b2C8[v.y][v.x] >= 0; }

EXTERN_C int func_800CCDCC(T_C9A4C *p, SVec2I *out, T_CCDCC_in *in, int a3, int s5, int flag) {
    if ((in->h8 & 2) && !flag) {
        if (f_CCD70(p, in_c(in))) { *out = *(SVec2I *)&in->xy; return 1; }
        return 0;
    }
    f_CCC4C(p, in_c(in), flag ^ 1);
    if (l_cnt(&p->l2EC)) {
        T_L2EC *l = &p->l2EC;
        T_C9284 *cur = p->fA0;
        l->f90 = 0;
        do {
            *out = l_cur(l);
            T_C9284 *cell = p->f14[out->y][out->x];
            if (cell == cur) return 0;
            if (!cell) {
                int k = cur->b4BD; f_800C(p, *out, a3, s5, k);
                if (p->b380[in->xy.y][in->xy.x]) return 1;
            }
        } while (l2ec_next(&p->l2EC));
    }
    return 0;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CCFC0);

EXTERN_C void func_800CD250(T_C9A4C *p, SVec2C v, int a, int b) {
    func_800C78EC(p, b != 0);
    p->l2EC.reset();
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 5; x++)
            if (p->b2C8[y][x] >= 0) p->l2EC.push(SVec2C(x, y));
    T_L2EC *l = &p->l2EC;
    if (l->f8C) func_800CE4E4(l, v, a);
}

EXTERN_C void func_800CD354(T_C9A4C *p, void *l, int x, int y, int e) {
    T_C9284 *q = p->fA0;
    if (!q) return;
    func_800C7D88((T_Grids *)p);
    func_800C7DD0(p, q->s4C8, 0, 0);
    place(p, q->s4C6, q->s4CA, e);
    func_800C8EE4((T_C8EE4 *)p, q->b4BD);
    if (p->b2C8[y][x] >= 0 && !p->f14[y][x]) {
        p->f844 = 0x7FFFFFFF;
        func_800C7B5C((P7B5C *)p, 0, l, x, y);
        func_80075004(l, func_80085AD4(operator new(0x10), x, y));
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CD488);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CD790);

EXTERN_C void func_800CDA8C(T_CDA8C *p, int v) { p->f818 = v; }

EXTERN_C void func_800CDA94(T_CDA94 *p, int bit, int on) { int m = 1 << bit; if (on) p->f814 |= m; else p->f814 &= ~m; }

EXTERN_C void func_800CDAC8(void *p) { func_800C757C(p, 1); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CDAE8);

T_CDD0C2::T_CDD0C2() {
    f4 = 0; f8 = 0; fC = 0;
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 5; x++) { f10[fC] = T_CDD0C_e(T_CDD0C_v(x, y)); fC++; }
}

EXTERN_C void func_800CDE4C(T_CDD0C *p, T_CDD0C_v *v) {
    int i = p->fC;
    if (i < 41) { p->fC = i + 1; p->f10[i] = T_CDD0C_e(*v); }
}

EXTERN_C void func_800CDED8(T_CDD0C *p, T_CDD0C_v *v, int a) {
    int i = p->fC;
    if (i < 41) { p->fC = i + 1; p->f10[i] = T_CDD0C_e(*v, a); }
}

EXTERN_C void func_800CDF64(T_CE044 *p, int i) {
    if (i >= 0 && p->fC) {
        for (; i < p->fC - 1; i++) p->f10[i] = p->f10[i + 1];
        p->fC--;
    }
}

EXTERN_C T_CE044_10 *func_800CE00C(T_CE044 *p) { return p->fC ? &p->f10[p->f8] : 0; }

EXTERN_C T_CE044_10 *func_800CE044(T_CE044 *p) { p->f8 = 0; return func_800CE00C(p); }

EXTERN_C T_CE044_10 *func_800CE064(T_CE044 *p) { p->f8 = p->fC - 1; return func_800CE00C(p); }

EXTERN_C T_CE044_10 *func_800CE090(T_CE044 *p) { T_CE044_10 *r; if (p->f8 < p->fC - 1) { p->f8++; r = func_800CE00C(p); } else r = 0; return r; }

EXTERN_C T_CE044_10 *func_800CE0D4(T_CE044 *p) { T_CE044_10 *r; if (p->f8 > 0) { p->f8--; r = func_800CE00C(p); } else r = 0; return r; }

EXTERN_C int func_800CE110(T_CE044 *p, int key) { for (int i = 0; i < p->fC; i++) if (((int *)&p->f10[i])[1] == key) return i; return -1; }

EXTERN_C void func_800CE154(T_CDD0C *p, int key) {
    if (p->fC < 2) return;
    T_CE154_k k;
    k = !key ? T_CE154_k(p->f3E8.f0) : T_CE154_k(key);
    for (int i = 0; i < p->fC - 1; i++) {
        for (int j = i + 1; j < p->fC; j++) {
            if (func_800CE854(&k, &p->f10[i], &p->f10[j]) > 0) {
                T_CDD0C_e t = p->f10[i];
                p->f10[i] = p->f10[j];
                p->f10[j] = t;
            }
        }
    }
}

EXTERN_C void func_800CE320(T_CDD0C *p, int to, int from) {
    T_CDD0C_e t;
    t = p->f10[from];
    int i = from;
    if (to < i) { for (; to < i; i--) p->f10[i] = p->f10[i - 1]; }
    else { for (; i < to; i++) p->f10[i] = p->f10[i + 1]; }
    p->f10[to] = t;
}

EXTERN_C int func_800CE4B4(T_CFE8C *p) { int old = p->f90; p->f90 = old + 1; if (old + 1 >= p->f8C) { p->f90 = old; return 0; } return 1; }

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CE4E4);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CE7A4);

EXTERN_C int func_800CE854(T_CE154_k *p, T_CDD0C_e *a, T_CDD0C_e *b) {
    switch (*(int *)((char *)p + 4)) {
    case 0: return ((F_CMP3)func_800CE910)(p, a, b);
    case 1: return ((F_CMP3)func_800CE9B8)(p, a, b);
    case 2: return ((F_CMP3)func_800CEA00)(p, a, b);
    case 3: return ((F_CMP3)func_800CEA48)(p, a, b);
    case 4: return ((F_CMP3)func_800CEA50)(p, a, b);
    case 5: return ((F_CMP3)func_800CEA60)(p, a, b);
    case 6: return ((F_CMP3)func_800CEA70)(p, a, b);
    }
    return 0;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CE910);

EXTERN_C int func_800CE9B8(void *self, T_CE9B8 *a, T_CE9B8 *b) { if (!(a->h8 & 1) || !(b->h8 & 1)) return 0; return a->p4->s410 - b->p4->s410; }

EXTERN_C int func_800CEA00(void *self, T_CE9B8 *a, T_CE9B8 *b) { if (!(a->h8 & 1) || !(b->h8 & 1)) return 0; return a->p4->s420 - b->p4->s420; }

EXTERN_C int func_800CEA48() { return 0; }

EXTERN_C int func_800CEA50(void *self, S_800CEA50 *a, S_800CEA50 *b) { return a->fC - b->fC; }

EXTERN_C int func_800CEA60(void *self, S_800CEA50 *a, S_800CEA50 *b) { return a->f10 - b->f10; }

EXTERN_C int func_800CEA70(void *self, S_800CEA50 *a, S_800CEA50 *b) { return a->f14 - b->f14; }

EXTERN_C void func_800CEA80(T_CEA80 *p, int a, int b, int c) { p->f910 = a; void *x = func_800758F8(operator new(0x1C8), 1, D_800B4C18[0], p); void *d = D_800B4C18[0]; p->f90C = x; func_8001E848(d, x); func_8007669C(p->f90C, b, c); }

EXTERN_C void func_800CEB04(T_CEA80 *p) { void *x = func_800758F8(operator new(0x1C8), 1, D_800B4C18[0], p); void *d = D_800B4C18[0]; p->f90C = x; func_8001E848(d, x); }

EXTERN_C void func_800CEB5C(T_CEB5C *p, int a, int b, int c) { if (p->f90C) func_800766F8(p->f90C, a, b, c, 1); }

EXTERN_C void func_800CEB94(T_CBA50 *p, int a, int b) { if (p->f90C) func_80076848(p->f90C, a, b, 1); }

EXTERN_C void func_800CEBC4(T_CEBC4 *p, int a, int b, int c) { if (p->f90C) { p->f910 = a; func_8007669C(p->f90C, b, c); } }

EXTERN_C void func_800CEC00(T_CEBC4 *p) { func_800766D8(p->f90C); }

EXTERN_C void func_800CEC24(T_CEBC4 *p) { if (p->f910 == 0) { func_800CEC00(p); func_800CADDC(p, 4); } }

EXTERN_C void func_800CEC68() {}

EXTERN_C void func_800CEC70(T_CEC70 *p) { for (int i = 0; i < 3; i++) { T_AFA58 *r = D_800AFA58[i]; if (r) r->s214 = 1; } func_8007A400(D_800AF470[0], 1); func_80051E50(D_800B4D40[0]); func_800518A8(D_800B4D40[0], p->f7D8, D_800D5DAC, 0); }

EXTERN_C int func_800CED08(T_CED08 *p) { char *b = D_800D5DAC; int o = 0x97F0; b += o; *(T_2C *)&p->s7DC = *(T_2C *)b; p->f934 = p->s7DC + ((T_4DD0d *)D_800B4DD0[0])->b1FB; return p->s7DC; }

EXTERN_C int func_800CEE04(T_CEE04 *p, int i) { return p->f7FC[i]; }

EXTERN_C void func_800CEE18(T_CEE18 *p, char *q, int x, int i) {
    T_CEE18_s *s = 0;
    char *qq = q;
    p->f808[i] = qq + 0x48C;
    int vx = (p->xy7EC[i].x - 2) * 2400;
    int vz = -((p->xy7EC[i].y - 3) * 2400);
    int k = i + 3;
    switch (i) {
    case 0: s = (T_CEE18_s *)D_800DA870[0](p->f7D8, k, D_800B772C, T_V4C(vx, 0, vz, 0), 0); break;
    case 1: s = (T_CEE18_s *)D_800DBB90[0](p->f7D8, k, D_800B772C, T_V4C(vx, 0, vz, 0), 0); break;
    case 2: s = (T_CEE18_s *)D_800DCEB0[0](p->f7D8, k, D_800B772C, T_V4C(vx, 0, vz, 0), 0); break;
    }
    T_D0390_D *d = ((T_D0390_G *)D_800AF470[0])->f328;
    func_8007B1FC(d ? (char *)d + 0xB8 : 0, s, 2);
    s->b4BC = i + 3;
    func_800DA400(s, qq, p->s7DE[i]);
    void *g = D_800B4C18[0];
    s->s214 = 0;
    func_8001E848(g, s);
}

EXTERN_C void func_800CEFE8(T_CEFE8 *p, char *q0, int x, int i0) { register char *q asm("$8") = q0; register int i asm("$6") = i0; i0 = 0; if (q) { char *w = q + 0x48C; p->f808[i] = w; } register T_AFA58 *r asm("$5") = (T_AFA58 *)D_800AFA58[i]; register T_CEFE8_g *g asm("$3") = (T_CEFE8_g *)D_800AF470[0]; r->s214 = 0; if (q) { if (!r->f1B8) func_800CF080_1(g->f32C); else func_8007C070(g->f328 ? g->f328 + 0xB8 : 0, i + 3); } }

EXTERN_C void func_800CF080(T_CF080 *p, void *q, int i) { func_80042430(q, q, p->f808[i], 1); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CF0B0);

EXTERN_C void func_800CF274(T_CF274 *p) { if (p->f934 > 0) { if (--p->f934 == 0) { p->f2C4 = 0; func_80081820(D_800AFA74, 0x3C, 0x2067, 2, D_800AF470[0], 0); } } }

EXTERN_C void func_800CF2D0(T_CF2D0 *p, int a) {
    p->s7DC--;
    T_CF2D0_r *r = (T_CF2D0_r *)D_800AFA58[a];
    T_CF2D0_g *g = (T_CF2D0_g *)D_800AF470[0];
    int n = r->b94D - r->b94C + 1;
    if (r->b94C) {
        g->f34C[g->f348] = (rand() & 0x7FFF) % n + r->b94C;
        T_CF2D0_g *h = (T_CF2D0_g *)D_800AF470[0];
        g->f348++;
        if (!h->f33C && (rand() & 0x7FFF) < 0x4CCC) g->f348--;
    }
    func_800C5D84(p, a + 3);
    func_800C5A30(p, r);
}

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B772C);

INCLUDE_ASM("asm/battle/nonmatchings/battle_b", func_800CF408);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B7748);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B7768);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B7778);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B7788);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B778C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B77AC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B77CC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B77D8);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B7800);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_b", D_800B783C);
