#include "common.h"
#include "battle/battle.h"

EXTERN_C void func_800CF764(T_CF764_q *pp) { T_CF764 *q = (T_CF764 *)pp->fA0; int n = q->f550[0x8A] - 1; q->b4BD = 1; func_800824C8(q->f2A4, 1); func_800825FC(q->f2A4, n); func_8008299C(q->f2A0, 0x29, 0, 0, 0, 0, 0); func_8008299C(q->f2A0, 0, 2, 0, 0, 0, 0); func_80085E74(q, 0); func_8008299C(q->f2A0, 0x2A, 0, 0, 0, 0, 0); func_80082E14(q->f2A0, 0); }

EXTERN_C int func_800CF840(T_CF840 *p) { if (func_8008A2A0(p->fA0)) { ((T_CF840_g *)D_800AF470[0])->f348 = 0; for (int i = 0; i < 3; i++) { T_CF840_r *r = (T_CF840_r *)D_800AFA58[i]; if (r && r->s410) { r->s410 = 0; p->s7DC--; } } p->f830 = 2; return 1; } return 0; }

EXTERN_C void func_800CF8E4(T_CF95C *p) { T_CF95C_g *g = (T_CF95C_g *)D_800B4ED8[0]; p->v93C = g->v2B8; p->f94C = g->f278; g->f278 = 6; g->f26C = 0; func_800CF9CC(p, p->s3C6, p->s3C8); func_8006B690(g, 0xCB); }

EXTERN_C void func_800CF95C(T_CF95C *p) { T_CF95C_g *g = (T_CF95C_g *)D_800B4ED8[0]; set_g2(g, &p->v93C); int t = p->f94C; p->v93C.x = 0; p->v93C.y = 0; p->v93C.z = 0; p->v93C.w = 0; g->f26C = 0; g->f278 = t; func_8006B690(g, 0xCC); }

EXTERN_C void func_800CF9CC(T_CF95C *pp, int a, int b) {
    T_CF9CC_q *q = ((T_CF9CC *)pp)->fA0;
    if (q) {
        T_VEC v; T_VEC *pv = &v; v.x = 0; pv->y = 0; pv->z = 0; pv->w = 0;
        v.y = -900;
        if (q->f1B8 && func_800392C8(q->f1B8)) { T_VEC t; func_8003A150((T_BFB18_t *)&t, func_8003912C(q->f1B8, 5), 0); v = t; }
        T_VEC u;
        mk_vec(&u, (short)a * 2400 - 4800, v.y - 200, (short)b * -2400 + 7200);
        set_g2((T_CF95C_g *)D_800B4ED8[0], &u);
    }
}

EXTERN_C void func_800CFB08(T_CFB08 *p, T_CFB08_q *q) {
    if (!q) q = p->fA0;
    T_VEC v; T_VEC *pv = &v; v.x = 0; pv->y = 0; pv->z = 0; pv->w = 0;
    if (q) {
        SVec2 pos;
        short x = q->h4C6, y = q->h4CA;
        v.y = -900;
        pos.x = x; pos.y = y;
        if (q->f1B8 && func_800392C8(q->f1B8)) { T_VEC t; func_8003A150((T_BFB18_t *)&t, func_8003912C(q->f1B8, 5), 0); v = t; }
        if (v.y == 0) v.y = -900;
        T_VEC u;
        mk_vec(&u, pos.x * 2400 - 4800, v.y - 200, pos.y * -2400 + 7200);
        T_CF95C_g *g = (T_CF95C_g *)D_800B4ED8[0];
        set_g2(g, &u);
        func_8006B690(g, 0xCC);
    }
}
inline T_D3ED0 *d3ed0_init(T_D3ED0 *x) {
    x->vt40 = D_800B7D64;
    x->vt2C = D_800B7C6C;
    x->f4C = 4;
    x->f44 = 0;
    x->f48 = 0;
    SVec4 *s = &x->s52; x->s52.x = 0; s->y = 0; s->z = 0; s->w = 0;
    x->b50 = 0;
    return x;
}

EXTERN_C int func_800CFC50(T_CFCBC *p, int v) { int a, b; p->f950 = 0; func_800C8D9C(p, 2, &a, &b); if (a < v) v = a; p->f950 = v; return v; }

EXTERN_C int func_800CFCB0(T_CFCBC *p) { return p->f950; }

EXTERN_C void func_800CFCBC(T_CFCBC *p, int v) { p->f934 = v; }

EXTERN_C int func_800CFCC4(T_CFD98 *p, SVec2 v) { return p->f14[v.y][v.x]; }

EXTERN_C int func_800CFCF0(T_CFCBC *p) { return p->f848; }

EXTERN_C int func_800CFCFC(void *p, int a, int b) { if (a < 0 || b < 0 || a >= 5 || b >= 7) return 0; return 1; }

EXTERN_C void func_800CFD2C(T_CFD2C *p, int a, int b, int c) { p->b2C8[b][a] = 0; func_800C7764(p, a, b, 1, c); }

EXTERN_C void func_800CFD64(void *p) { func_800CC110(p); }

EXTERN_C void func_800CFD84(S_800CFCB0 *p, int v) { p->fA0 = v; }

EXTERN_C int func_800CFD8C(S_800CFCB0 *p) { return p->fA0; }

EXTERN_C int func_800CFD98(T_CFD98 *p, int i, int j) { return p->f14[j][i]; }

EXTERN_C int func_800CFDB8(void *self, int v) { return (v & 7) << 9; }

EXTERN_C int func_800CFDC4(void *self, int v) { return ((v + 0x100) / 512) & 7; }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800CFDE0);

EXTERN_C int func_800CFE08(S_800CFCB0 *p) { p->f90 = 0; return p->f8C != 0; }

EXTERN_C int func_800CFE18(S_800CFCB0 *p) { return p->f8C; }

EXTERN_C void func_800CFE24(S_800CFCB0 *p) { p->f8C = 0; p->f90 = 0; }

EXTERN_C void func_800CFE30(T_CFE8C *p, SVec2 v) { p->f0[p->f8C++] = v; }

EXTERN_C void func_800CFE64(void *p, int flags) { if (flags & 1) operator delete(p); }

EXTERN_C T_CFE8C *func_800CFE8C(T_CFE8C *p) { SVec2 *q = p->f0; for (int i = 0x22; i != -1; i--) { q->x = 0; q->y = 0; q++; } p->f8C = 0; p->f90 = 0; return p; }

EXTERN_C void func_800CFEBC(T_CFEBC *p, T_CFEBC_18 *v) { p->f3E8 = *v; }

EXTERN_C void func_800CFEF4(T_CFEF4b *p, int flags) { T_CFEF4_e *b = p->e; T_CFEF4_e *e = b + 41; if (b) { if (b != e) { T_CFEF4_e *s = b; do { (--e)->~T_CFEF4_e(); } while (s != e); } } if (flags & 1) operator delete(p); }

EXTERN_C T_CFF44 *func_800CFF44(T_CFF44 *p, SVec2 v, int a) { p->f0 = v; p->f4 = a; return p; }

EXTERN_C S_800CFF68 *func_800CFF68(S_800CFF68 *p, int v) { p->s0 = 0; p->s2 = 0; p->f4 = v; return p; }

EXTERN_C S_800CFF68 *func_800CFF7C(S_800CFF68 *p) { p->s0 = 0; p->s2 = 0; return p; }

EXTERN_C void func_800CFF8C(void *p, int flags) { if (flags & 1) operator delete(p); }

EXTERN_C T_CFFB4 *func_800CFFB4(T_CFFB4 *p, SVec2 *v, int a) { p->f0.x = 0; p->f0.y = 0; p->f0 = *v; p->f4 = a; p->s8 = 0; return p; }

EXTERN_C T_CFFB4 *func_800CFFE0(T_CFFB4 *p, SVec2 *v) { p->f0.x = 0; p->f0.y = 0; p->f0 = *v; p->f4 = 0; p->s8 = 0; return p; }

EXTERN_C T_CFFB4 *func_800D000C(T_CFFB4 *p) { p->f0.x = 0; p->f0.y = 0; SVec2 t; t.x = 0; t.y = 0; p->f0 = t; p->f4 = 0; p->s8 = 0; return p; }

EXTERN_C int func_800D0048(T_CE044 *p) { return p->f8; }

EXTERN_C void func_800D0054(T_D0054 *p, int v) { p->f12C += v; }

EXTERN_C int func_800D0068(T_D0054 *p) { return p->f12C; }

EXTERN_C void func_800D0074(T_D0054 *p) { S_800D00B8 *l; while ((l = (S_800D00B8 *)func_800751AC(p)) != 0) { l->prev = l; l->next = l; l->fC = 0; } p->f12C = 0; }

EXTERN_C void func_800D00B8(void *self, S_800D00B8 *l) { l->prev = l; l->next = l; l->fC = 0; }

EXTERN_C S_800D00B8 *func_800D00C8(T_D00C8 *p, int a, int b) { for (int i = 0; i < 10; i++) { if (!node_used(&p->nodes[i])) { node_init(&p->nodes[i], a, b); return &p->nodes[i]; } } return 0; }

EXTERN_C void func_800D0130(T_D0130 *p) { int i = 15; do { p->e[i] = p->e[i - 1]; } while (--i > 0); memset(&p->e[0], 0xFF, 0x10); }

EXTERN_C void func_800D019C(T_D019C *p, int flags) { p->vtblC = D_800B7768; func_800D0074((T_D0054 *)p); T_D019C_e *b = p->nodes; if (b) { T_D019C_e *e = b + 10; if (b != e) { T_D019C_e *s = b; do { (--e)->~T_D019C_e(); } while (s != e); } } func_80074F78(p, flags); }

EXTERN_C T_D0230 *func_800D0230(T_D0230 *p) { func_80074F58(p); p->vtblC = D_800B7768; T_D0230_n *e = p->nodes; for (int i = 9; i != -1; i--) { func_80074E28((T_D0338 *)e); e->vtbl8 = D_800B7778; e->fC = 0; e++; } p->f12C = 0; memset(p->pad10, 0xFF, 0x100); memset(p->pad10 + 0x100, 0xFF, 0x1C); return p; }

EXTERN_C int func_800D02E8(S_800D00B8 *l) { return l->f14; }

EXTERN_C int func_800D02F4(S_800D00B8 *l) { return l->f10; }

EXTERN_C int func_800D0300(S_800D00B8 *l) { return l->fC; }

EXTERN_C void func_800D030C(S_800D00B8 *l) { l->prev = l; l->next = l; l->fC = 0; }

EXTERN_C void func_800D031C(S_800D00B8 *l, int a, int b) { l->prev = l; l->next = l; l->fC = 1; l->f10 = a; l->f14 = b; }

EXTERN_C T_D0338 *func_800D0338(T_D0338 *p) { func_80074E28(p); p->vtbl8 = D_800B7778; p->fC = 0; return p; }

EXTERN_C void func_800D0370(void *p, int flags) { func_80074E44(p, flags); }

EXTERN_C int func_800D0390() { int v = 1; for (unsigned i = 0; i < 3 && v > 0; i++) { T_D0390_B *b = ((T_D0390_G *)func_800787B4())->f328; v = b->items[i]->s410; } return v > 0; }

EXTERN_C T_D0404 *func_800D0404(T_D0404 *p) { p->f68 = 0; p->f6C = 0xFF; p->f70 = 0; p->f54 = 0; for (unsigned i = 0; i < 3; i++) p->f58[i] = 0; p->f64 = 0; return p; }

EXTERN_C void func_800D0440(T_D0404 *p, int a, int b) { p->f6C = a; p->f70 = b; }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D044C);

EXTERN_C void func_800D0588() {}

EXTERN_C void func_800D0590(void *self) {}

EXTERN_C void func_800D0598(void *self) { func_8005F440(func_800787B4(), 0x1262); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D05C4);

EXTERN_C void func_800D0BCC(void *q) { T_D0BCC *p = (T_D0BCC *)q; func_800D119C(p->f54); delete p->f54; p->f54 = 0; for (unsigned i = 0; i < 3; i++) { if (p->f58[i]) { func_8002B27C(p->f64, p->f58[i]); p->f58[i] = 0; } } func_8002B27C(D_800A4578[0], p->f64); p->f64 = 0; }

EXTERN_C void func_800D0C88(void *self) {}

EXTERN_C void func_800D0C90(T_D0C90 *p) { p->f68 = 1; func_80062280(D_800B4DD0[0], 1); }

EXTERN_C void func_800D0CC0(T_D0CC0 *p) { if (p->f68) func_800C5020(operator new(0x78), D_800B77D8, 0x3C); else func_800C5020(operator new(0x78), D_800B7800, 0x3C); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D0D1C);

EXTERN_C void func_800D10D4(T_D10D4 *p, int m, int a) { if (m & 1) func_80054094(p->f54FC, a); if (m & 2) func_80054094(p->f5574, a); if (m & 4) func_80054094(p->f56DC, a); }

EXTERN_C void func_800D1148(T_D1148 *p) { D_800B4DA6[0] = 6; func_80063714(p, count_of(&p->h1C)); func_800D1458(p); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D119C);

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D1458);

EXTERN_C void func_800D168C(T_D168C *p) { SVec4 v; SVec4 *q = &v; v.x = 0; q->y = 0; v.z = 0; v.w = 0; func_80054F30(p, 5, q, -8); func_80054F5C(p); for (unsigned i = 0; i < ((T_4DD0c *)D_800B4DD0[0])->b1FB; i++) p->e[i].v3(); }

EXTERN_C void func_800D1758(T_D1758 *p) { p->f5750 = 1; }

EXTERN_C void func_800D1764(void *p) { func_800566E4(p); func_80055330(0); func_8005549C(3, p, 0, -1); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D17A4);

EXTERN_C void func_800D1950(T_D1950 *p) { for (unsigned i = 0; i < ((T_4DD0b *)D_800B4DD0[0])->b1FB; i++) p->e[i].v5(); }

EXTERN_C int func_800D19F0(T_D19F0 *p, T_D19F0_q *q) { if (func_8005618C(q)) return 1; T_BE0F8 t; func_800BE09C(&t); T_BE0F8 k; k.f0 = 1; func_800BE108(func_800BE0F8(&t, &k), q); if (q->h18 & 0x1000) func_800631D4(p->f68); else if (!(q->h18 & 0xC00)) func_80063340(p, q); return 1; }

EXTERN_C int func_800D1A90(T_D1A90 *p, T_D19F0_q *q) { func_8001FC78(q, 0, 0); if (func_8005618C(q)) return 1; T_BE0F8 t; func_800BE09C(&t); T_BE0F8 k; k.f0 = 0; func_800BE108(func_800BE0F8(&t, &k), q); ((T_A4578 *)D_800A4578[0])->s1A4 = 3; if ((q->h18 & 0x10) && p->f3C) p->f20 = func_80058404(p->f3C, -1); else if ((q->h18 & 0x40) && p->f3C) p->f20 = func_80058404(p->f3C, 1); return 1; }

EXTERN_C int func_800D1B68(T_D1B68 *p, int a) {
    if (func_80063744(p, a)) return 1;
    switch (a) {
    case 3: func_800D1C50((T_D1C50 *)p); return 1;
    case 4: p->f5754 = 4; p->v3(); return 1;
    case 5: p->f5754 = 5; p->v3(); return 1;
    case 6: p->f5754 = 6; p->v3(); return 1;
    case 7: p->f5754 = 7; p->v3(); return 1;
    case 8: p->f5754 = 8; p->v3(); return 1;
    case 9: p->f5754 = 9; p->v3(); return 1;
    case 10: p->f5754 = 10; p->v3(); return 1;
    }
    return 0;
}

EXTERN_C void func_800D1C50(T_D1C50 *p) { for (unsigned i = 0; i < 4; i++) func_8005556C(2, 1); func_800D1148((T_D1148 *)p); int n = (int)D_800B4D5C[0]; T_D0390_G *g = (T_D0390_G *)func_800787B4(); T_D0390_B *b = g->f328; char *s = (char *)b->items[n]; if (func_8005409C(p->f5574)) func_80054094(p->f5574, func_8008A54C(s, 1) == 0); func_80054094(p->f2B04, (((unsigned char *)s)[0x46D] >> 6) & 1); func_80054094(p->f87C, func_80068A5C(p->f87C) != 0); func_800553D8(0); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D1D38);

EXTERN_C T_D20E0 *func_800D20E0(T_D20E0 *self, int in_chrg, int a)
{
    if (in_chrg) {
        self->vb50 = (T_VBase *)&self->v2280;
        T_D3ED0_vb *v = (T_D3ED0_vb *)self->vb50;
        v->vptr = D_80010178;
        v->f4 = 0;
        v->vptr = D_800104A8;
    }
    func_80068770(self, 0);
    self->vb50->vptr = (T_VTable10 *)&D_800B79A4;
    T_VTable10 vt;
    SVec4 v;
    if (!in_chrg) {
        vt = D_800B79A4;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B79A4.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x2280));
        vt.e[6].delta = D_800B79A4.e[6].delta + adj;
    }
    self->vt54 = D_800B7A14;
    self->vt58 = D_800B79F4;
    self->vt18 = D_800B7A44;
    self->f227C = a;
    func_800557C8(self, 0, 5);
    func_8006897C(self, 4, 0);
    func_80054EB4(self, 0xE0, 0x8A);
    v.x = -2; v.y = 0; v.z = 2; v.w = 0;
    func_80054F30(self, 5, &v, 2);
    return self;
}

EXTERN_C void func_800D2254(T_D2254 *p) {
    func_80068B14(p);
    int cnt = ((T_D2254c *)p)->h1CF0;
    
    for (int i = 0; i < cnt; i++) {
        T_D2254_x *x = (T_D2254_x *)func_80061188(D_800B4DD0[0], ((signed char *)p)[i + 0x68]);
        int ok = 0;
        unsigned char t = x->b1B;
        if ((unsigned char)(t - 12) < 4) {
            T_D2254_D *d = ((T_D2254_G *)func_800787B4())->f328; int n = (int)D_800B4D5C[0];
            T_D2254_B *b = d;
            void *s = b->items[n];
            if (!func_8008A5C8(s, s, x)) ok = 1;
        } else { 
            if (t == 6 || t == 0xB) {
            if (func_800D0390()) ok = 1;
        } else if (t == 0x87 || (x->b8B >> 7)) ok = 1; }
        if (ok) { func_80054094(&p->a9C[i], 1); func_80054094(&((T_D2254b *)p)->b1548[i], 1); }
    }
    func_80054CE4(p);
}

EXTERN_C int func_800D23C0(T_D23C0 *p) {
    int c = ((signed char *)p)[p->f20 + 0x68]; int k = kindOf((T_D23C0_x *)func_80061188(D_800B4DD0[0], c)); int r = (signed char)c;
    if ((unsigned)(k - 12) < 4) {
        T_D23C0_D *d = ((T_D23C0_G *)func_800787B4())->f328; int n = (int)D_800B4D5C[0];
        T_D23C0_B *b = d;
        T_D23C0_j *s = (T_D23C0_j *)b->items[n];
        T_D23C0_x *e = (T_D23C0_x *)func_80061188(D_800B4DD0[0], c);
        r = 0x10E7;
        ((VB23 *)((char *)s + 0x400))->v5(s, e, 1);
    } else {
        r = (r << 16) + 0x10E6;
        T_4DD0e *t = (T_4DD0e *)D_800B4DD0[0];
        if (t->s1F4 < 3 && (k == 6 || k == 0xB)) { t->s1F4++; func_800C5020(operator new(0x78), D_800B7964, 0x3C); }
    }
    return r;
}

EXTERN_C void func_800D24E8(T_D24E8 *p) { func_8005457C(p, 1); p->v4(SVec2C(8, 0xD7)); p->f5C = 1; func_80068E60(p); func_8005783C(10); }

EXTERN_C void func_800D255C(void *p) { func_8005783C(0); func_80068EE8(p); func_8005457C(p, 0); }

EXTERN_C int func_800D2598(T_D2598 *p, T_D19F0_q *q) { if (func_8005618C(q)) return 1; if (q->h18 & 0x2000) { if (func_8005409C(func_800550BC(p))) { func_80061F80(D_800B4DD0[0], ((signed char *)p)[p->f20 + 0x68]); p->f5C = 2; p->v3(); func_8005549C(p->f227C, p, 0, -1); } else func_8008EF40(0xE); } else func_80068F3C(p, q); return 1; }

EXTERN_C void func_800D2670(T_D2670 *self, int in_chrg)
{
    self->vt54 = D_800B7A14;
    self->vt58 = D_800B79F4;
    self->vt18 = D_800B7A44;
    self->vb50->vptr = (T_VTable10 *)&D_800B79A4;
    if (!in_chrg) {
        T_VTable10 vt = D_800B79A4;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B79A4.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x2280));
        vt.e[6].delta = D_800B79A4.e[6].delta + adj;
    }
    func_80069264(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb50, 0);
    if (in_chrg & 1)
        operator delete(self);
}

EXTERN_C T_D2778 *func_800D2778(T_D2778 *p)
{
    func_80054AF0(p, 8);
    func_800537C0(p->f50);
    p->vt58 = D_800B7AFC;
    p->vt18 = D_800B7ACC;
    p->f5C = 4;
    func_80053928(p->f60);
    p->f7C = 1;
    func_800538CC(p->f80, D_800B7A84, 2);
    func_800538CC(p->f9C, D_800B7A8C, 2);
    func_800538CC(p->fB8, D_800B7A94, 1);
    func_80054584(p->fD4, 0);
    func_80054584(p->fFC, 0);
    func_80054584(p->f124, 0);
    p->f14C = 0;
    p->f150 = 0;
    p->f154 = 0;
    fm(p, 0, S4m(0, 0, 0, 0), 0);
    func_80054EB4(p, 0xE0, 0x12);
    func_80053F48(p->f80, SVec2C(0x45, 0));
    func_80053F48(p->f9C, SVec2C(0xA6, 0));
    func_80053F48(p->fB8, SVec2C(0x76, 0));
    func_80053F48(p->f60, SVec2C(6, 0));
    func_8005408C(p->fD4, 2);
    func_80053F48(p->fD4, SVec2C(0x76, 0));
    func_80053F48(p->fFC, SVec2C(0x80, 0));
    func_8005408C(p->f124, 2);
    func_80053F48(p->f124, SVec2C(0xD8, 0));
    func_80054E18(p, p->f80);
    func_80054E18(p, p->f9C);
    func_80054E18(p, p->fB8);
    func_80054E18(p, p->f60);
    func_80054E18(p, p->fD4);
    func_80054E18(p, p->fFC);
    func_80054E18(p, p->f124);
    return p;
}

EXTERN_C void func_800D2A2C(T_D2A2C *p, int a) { p->f7C = a; switch (a) { case 0: func_80053BCC(p->f60, D_800B7A98, 8); break; case 1: func_80053BCC(p->f60, D_800B7AAC, 6); break; default: func_80053BCC(p->f60, D_800B7ABC, 5); break; } }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D2A98);

EXTERN_C void func_800D2C50(T_D2C50 *p) {
    if (p->f14C) {
        T_D2C50_D *d = ((T_D2C50_G *)func_800787B4())->f328; int i = p->f7C;
        T_D2C50_B *b = d; T_D2C50_s *s = b->items[i];
        func_8008687C(s ? s->f400 : 0, 0);
        if (func_800549C4(p->fD4, s->s410)) { func_80064884(p->f14C, s->s412, 0); func_800648E8(p->f14C, s->s410); func_80054708(p->fD4, s->s410); }
        if (func_800549C4(p->f124, s->s420)) { func_80064884(p->f150, s->s422, 0); func_800648E8(p->f150, s->s420); func_80054708(p->f124, s->s420); }
        func_80054CE4(p);
    }
}

EXTERN_C void func_800D2D60(T_D2D60 *p)
{
    T_D2C50_D *d = ((T_D2C50_G *)func_800787B4())->f328; int i = p->f7C;
    T_D2C50_B *b = d; T_D2C50_s *s = b->items[i];
    func_8008687C(s ? s->f400 : 0, 0);
    func_80054708(p->fFC, s->s412);
    func_80054708(p->fD4, s->s410);
    func_80054708(p->f124, s->s410);
    func_80054FC0(p);
    if (!p->f14C) {
        SVec2 v[2];
        void *m = operator new(0x58);
        { short y = 0xC; SVec2 *q = &v[0]; q->x = 0x56; q->y = y; }
        { short y = 4; SVec2 *q = &v[1]; q->x = 0x4C; q->y = y; }
        void *o = func_800646FC(m, 1, v, 2);
        void *g = p->f3C;
        p->f14C = o;
        func_8005800C(g, o);
        func_80064884(p->f14C, s->s412, 0);
        func_800648E8(p->f14C, s->s410);
        m = operator new(0x58);
        { short y = 0xC; SVec2 *q = &v[0]; q->x = 0xB8; q->y = y; }
        { short y = 4; SVec2 *q = &v[1]; q->x = 0x21; q->y = y; }
        o = func_800646FC(m, 1, v, 2);
        g = p->f3C;
        p->f150 = o;
        func_8005800C(g, o);
        func_80064884(p->f150, s->s422, 0);
        func_800648E8(p->f150, s->s420);
        o = func_800D3ED0(operator new(0x64), 1, 2);
        g = p->f3C;
        p->f154 = o;
        func_8005800C(g, o);
    }
    p->v5();
    func_8005388C((T_D2D60_B *)p, p->f7C + 0xC);
}

EXTERN_C void func_800D2F54(T_D2F54 *p) { func_80055624(p->f50, 0); p->f14C = 0; p->f150 = 0; p->f154 = 0; func_80054FE0(p); }

EXTERN_C void func_800D2F94(T_D2F94 *p, int flags) { p->vt58 = D_800B7AFC; p->vt18 = D_800B7ACC; func_80053964(p->f124, 2); func_80053964(p->fFC, 2); func_80053964(p->fD4, 2); func_80053964(p->fB8, 2); func_80053964(p->f9C, 2); func_80053964(p->f80, 2); func_80053964(p->f60, 2); func_800537DC(p->f50, 0); func_80054C34(p, flags); }

EXTERN_C T_D3044 *func_800D3044(T_D3044 *self, int in_chrg)
{
    if (in_chrg) {
        T_D3044_vb *v = &self->v394;
        self->vb50 = (T_VBase *)v;
        self->v394.vptr = D_80010178;
        v->f4 = 0;
        self->v394.vptr = D_800104A8;
    }
    func_80056364(self, 0, 0, 1);
    self->vb50->vptr = (T_VTable10 *)&D_800B7B6C;
    T_VTable10 vt;
    if (!in_chrg) {
        vt = D_800B7B6C;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B7B6C.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x394));
        vt.e[6].delta = D_800B7B6C.e[6].delta + adj;
    }
    self->vt54 = D_800B7B3C;
    self->vt58 = D_800B7BBC;
    self->vt18 = D_800B7BDC;
    self->f64 = 0;
    func_800694BC(self->f68, 1, 0x10, 0);
    func_80054AF0(self->f334, 4);
    func_800557C8(self, 0, 3);
    self->f32C = 0;
    self->f330 = 0;
    self->f384 = 0;
    self->f388 = 0;
    self->f38C = 0;
    self->f390 = 0;
    func_80055020(self->f68, SVec2C(0x41, 0x94));
    func_80054EB4(self->f68, 0xF8, 0x48);
    func_80055020(self->f334, SVec2C(0x41, 0x94));
    return self;
}

EXTERN_C void func_800D321C(T_D321C *self, int in_chrg)
{
    self->vt54 = D_800B7B3C;
    self->vt58 = D_800B7BBC;
    self->vt18 = D_800B7BDC;
    self->vb50->vptr = (T_VTable10 *)&D_800B7B6C;
    if (!in_chrg) {
        T_VTable10 vt = D_800B7B6C;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B7B6C.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x394));
        vt.e[6].delta = D_800B7B6C.e[6].delta + adj;
    }
    delete[] self->f32C;
    delete[] self->f330;
    delete[] self->f384;
    delete[] self->f388;
    delete[] self->f38C;
    func_80054C34(self->f334, 2);
    func_80069B2C(self->f68, 2);
    func_8005652C(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb50, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7884);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B78D4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B78F4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7924);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7964);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B79A4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B79F4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7A14);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7A44);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7A84);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7A8C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7A94);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7A98);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7AAC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7ABC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7ACC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7AFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D3574);

EXTERN_C void func_800D3CD4(T_D3CD4 *p) { if (p->f390) { func_8002B27C(D_800A4578[0], p->f390); p->f390 = 0; } if (func_80054E90(p->f334)) func_80054FE0(p->f334); func_80069958(p->f68); func_80056874(p); func_8008EF40(0xD); }

EXTERN_C int func_800D3D50(T_D3D50 *p, T_D19F0_q *q) {
    func_8001FC78(q, 0, 0);
    if ((int)p->f64 > 0) { if (p->f64 >= (unsigned)D_800A4534.fC) return 1; p->f64 = 0; }
    int ok = 0;
    if (q->h18 & 0x40) ok = func_80054D78(p->f334) != 0;
    if (ok) {
        char *s = p->f334;
        int n;
        if (func_80054E90(s)) {
            p->f64 = D_800A4534.fC + 20;
            SVec4 v; SVec4 *pv = &v; v.x = 0; pv->y = 8; v.z = 0; v.w = -8;
            func_80054F30(s, 9, &v, 0);
            func_80054F5C(s);
            n = 0xD;
        } else {
            p->f64 = D_800A4534.fC + 20;
            SVec4 v; SVec4 *pv = &v; v.x = 0; pv->y = -8; v.z = 0; v.w = 8;
            func_80054F30(s, 8, &v, 0);
            func_80054EB4(s, 0xF8, 0x48);
            func_80054FC0(s);
            func_80054CA0(s);
            T_D3D50_o *o = p->f390;
            o->vt2C[28].pfn((char *)o + o->vt2C[28].delta);
            n = 0xC;
        }
        func_8008EF40(n);
    }
    return 1;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D3ED0);

EXTERN_C void func_800D401C(T_D401C *p) { T_D401C_M *m = p->f30; T_D401C_V *v = m; func_800D4518(v->count ? v->items[0] : 0); }

EXTERN_C void func_800D407C(T_D407C *p, int a, int b) { int t1, t2; if (p) { t2 = (t1 = a >> 24); p->f44 = 1; p->b50 = t2; p->f48 = b; } else { t2 = (t1 = a >> 24); p->f44 = 1; p->b50 = t2; p->f48 = b; } }

EXTERN_C void func_800D4094(T_D4094 *p, SVec4 *v) { p->f52 = *v; }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D40BC);

EXTERN_C void func_800D41D4(T_D41D4 *p, int a) { if (p->f8) { func_8005C088(p, a, 1); void *x = func_800D43B0(operator new(0x60), p->h1C); if (p->f44) { func_800D4718((T_D4718 *)x, &p->s52); func_8005388C(p ? p->f38 : 0, 0x1E); } List *l = p->f30; func_80019A6C(l, (int)x, l->count); func_8002DA94(a, p->f30); } }

EXTERN_C void func_800D4290(T_D4290 *self, int in_chrg)
{
    self->vt40 = D_800B7D64;
    self->vt2C = D_800B7C6C;
    self->vb0->vptr = (T_VTable10 *)&D_800B7C1C;
    if (!in_chrg) {
        T_VTable10 vt = D_800B7C1C;
        self->vb0->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B7C1C.e[1].delta + (adj = (char *)self - (full = (char *)self->vb0 - 0x5C));
        vt.e[5].delta = D_800B7C1C.e[5].delta + adj;
        vt.e[7].delta = D_800B7C1C.e[7].delta + adj;
        vt.e[9].delta = D_800B7C1C.e[9].delta + adj;
    }
    func_800537DC(self->f38, 0);
    func_8005BDA4(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb0, 0);
    if (in_chrg & 1)
        operator delete(self);
}

EXTERN_C void *func_800D43B0(void *vp, int a1) {
    T_D43B0n *p = (T_D43B0n *)vp;
    ((F_5F0E4)func_8005F0E4)(p, a1);
    p->vtbl = D_800B7D84;
    p->f10 = 0;
    SVec4 *v = &p->s54;
    v->x = 0; v->y = 0; v->z = 0; v->w = 0;
    p->h5C = 0; p->h5E = 0;
    SetDrawMode(&p->dm[0], 0, 0, (unsigned short)func_80060154(D_800AE640, 0x40), 0);
    SetDrawMode(&p->dm[1], 0, 0, (unsigned short)func_80060154(D_800AE640, 0x40), 0);
    p->s[0].len = 4;
    p->s[0].code = 0x64;
    p->s[1].code = 0x64;
    p->s[1].len = 4;
    int i = D_800B4CF0[0];
    p->s[i].b = 0x20;
    p->s[i].x = 0x78;
    p->s[i].y = 4;
    p->s[i].h = 8;
    p->s[i].clut = func_800600A4(D_800AE640, 0x40);
    f4518_2(p, 4);
    register T_D43B0n *r asm("$2") = p;
    T_D43B0n_s *a = &r->s[i];
    T_D43B0n_s *b = &r->s[i ^ 1];
    int w1 = ((int *)a)[1], w2 = ((int *)a)[2], w3 = ((int *)a)[3], w4 = ((int *)a)[4];
    ((int *)b)[1] = w1; ((int *)b)[2] = w2; ((int *)b)[3] = w3; ((int *)b)[4] = w4;
    return r;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D4518);

EXTERN_C void func_800D4718(T_D4718 *p, SVec4 *v) { p->f10 = 1; p->f54 = *v; }

EXTERN_C void func_800D4748(T_D4748 *p, int a, int b) { if (p->f10) { T_D4748b *q = (T_D4748b *)p; q->s5C += a; q->s5E += b; } else { int i = D_800B4CF0[0]; p->e[i].x += a; p->e[i].y += b; } func_8005F1D8(p); }

EXTERN_C void func_800D47C8() {}

EXTERN_C void func_800D47D0(T_D47D0 *p, int a, int b) { p->v11(a - p->e[D_800B4CF0[0]].x, b - p->e[D_800B4CF0[0]].y); }

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D4828);

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D4968);

EXTERN_C void func_800D4BD4() {}

EXTERN_C void func_800D4BDC(void *p, int flags) { func_8005F120(p, flags); }

EXTERN_C T_D4BFC *func_800D4BFC(T_D4BFC *self, int in_chrg, int a)
{
    T_VTable10 vt;
    if (in_chrg) {
        T_D3044_vb *v = &self->v2318;
        self->vb50 = (T_VBase *)v;
        self->v2318.vptr = D_80010178;
        v->f4 = 0;
        self->v2318.vptr = D_800104A8;
    }
    func_80068770(self, 0);
    self->vb50->vptr = (T_VTable10 *)&D_800B7DEC;
    if (!in_chrg) {
        vt = D_800B7DEC;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B7DEC.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x2318));
        vt.e[6].delta = D_800B7DEC.e[6].delta + adj;
    }
    self->vt54 = D_800B7E5C;
    self->vt58 = D_800B7E3C;
    self->vt18 = D_800B7E8C;
    self->f227C = a;
    self->f2280 = 0xFFFF;
    func_80054AF0(self->f2284, 2);
    func_80053928(self->f22D4);
    func_80054584(self->f22F0, 0);
    func_800557C8(self, 0, 7);
    func_80054EB4(self, 0xE0, 0x70);
    { S4 v; short z = 2; v.x = -2; v.y = 0; v.z = z; v.w = 0; func_80054F30(self, 5, (SVec4 *)&v, 2); }
    func_8006897C(self, 1, 1);
    { S4 v; short z = 2; v.x = -2; v.y = 0; v.z = z; v.w = 0; func_80054F30(self->f2284, 5, (SVec4 *)&v, 2); }
    func_80054EB4(self->f2284, 0xE0, 0x14);
    func_80055020(self->f2284, SVec2C(8, 0x51));
    func_8005408C(self->f22F0, 2);
    func_80053F48(self->f22F0, SVec2C(0xD6, 3));
    func_80054E18(self->f2284, self->f22D4);
    func_80054E18(self->f2284, self->f22F0);
    return self;
}

EXTERN_C int func_800D4E68(T_D4E68 *p) { return (p->f2280 << 16) | 0x10F0; }

EXTERN_C void func_800D4E7C(T_D4E7C *p) {
    func_8005457C(p, 1);
    p->v4(SVec2C(8, 0xD7));
    p->f5C = 1;
    func_80068E60(p);
    T_D4E7C_D *d = ((T_D4E7C_G *)func_800787B4())->f328; int n = (int)D_800B4D5C[0];
    T_D4E7C_B *b = d;
    T_D4E7C_s *s = b->items[n];
    if (s->f550) {
        func_80053BCC(((T_D4E7C_c *)p)->f22D4, (char *)s->f550 + 0x1C, 0);
        func_800540A8(((T_D4E7C_c *)p)->f22D4);
        int k0 = s->f550->b1B;
        if (k0 == 0x4C) func_80054094(&p->a9C[((T_D4E7C_c *)p)->h1CF0], 1);
        int k1 = s->f550->b8C;
        if (!func_80068660(&k0, &k1, ((T_D4E7C_c *)p)->f22F0)) func_80053CD8(((T_D4E7C_c *)p)->f22F0);
    } else {
        char *x = (char *)func_80061164(D_800B4DD0[0], 0);
        func_80053BCC(((T_D4E7C_c *)p)->f22D4, x + 0x1C, 0);
        func_800540A8(((T_D4E7C_c *)p)->f22D4);
        func_80054094(&p->a9C[((T_D4E7C_c *)p)->h1CF0], 1);
    }
    func_80054CE4(p);
    func_80054094(((T_D4E7C_c *)p)->f22D4, 0);
    func_80054FC0(((T_D4E7C_c *)p)->f2284);
}

EXTERN_C void func_800D5038(T_D2284 *p) { func_80054FE0(p->f2284); func_80068EE8(p); func_8005457C(p, 0); }

EXTERN_C int func_800D5074(T_D5074 *p, T_D19F0_q *q) {
    if (func_8005618C(q)) return 1;
    if (q->h18 & 0x2000) {
    if (!func_8005409C(func_800550BC(p))) { func_8008EF40(0xE); return 1; }
    T_D5074_D *d = ((T_D5074_G *)func_800787B4())->f328; int n = (int)D_800B4D5C[0];
    T_D5074_B *b = d;
    T_D5074_s *s = b->items[n];
    T_D5074_x *x = s->f550;
    if (x) x->b1A = 0;
    p->f2280 = 0xFFFF;
    int c = ((signed char *)p + p->f20)[0x68];
    x = 0;
    if (c >= 0) { void *d0 = D_800B4DD0[0]; p->f2280 = c; x = (T_D5074_x *)func_80061188(d0, c); }
    if (x) x->b1A = (int)D_800B4D5C[0] + 1;
    else x = func_80061164(D_800B4DD0[0], 0);
    func_8008B150(s, x, s->f554, s->f558, s->f55C);
    p->f5C = 2; p->v3();
    func_8005549C(p->f227C, p, 0, -1);
    } else func_80068F3C(p, q);
    return 1;
}

EXTERN_C void func_800D51FC(T_D51FC *self, int in_chrg)
{
    self->vt54 = D_800B7E5C;
    self->vt58 = D_800B7E3C;
    self->vt18 = D_800B7E8C;
    self->vb50->vptr = (T_VTable10 *)&D_800B7DEC;
    if (!in_chrg) {
        T_VTable10 vt = D_800B7DEC;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B7DEC.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x2318));
        vt.e[6].delta = D_800B7DEC.e[6].delta + adj;
    }
    func_80053964(self->f22F0, 2);
    func_80053964(self->f22D4, 2);
    func_80054C34(self->f2284, 2);
    func_80069264(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb50, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7B3C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7B6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7BBC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7BDC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7C1C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7C6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7D64);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7D84);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7DEC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7E3C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7E5C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7E8C);

INCLUDE_ASM("asm/battle/nonmatchings/battle_c", func_800D5328);

EXTERN_C int func_800D5740(T_D5740 *p) { return (p->b6C[p->f20] << 16) | 0x10DC; }

EXTERN_C void func_800D5760(T_D5760 *p)
{
    p->f5C = 1;
    func_80053F48(p, SVec2C(8, 0xD7));
    T_D2C50_D *d = ((T_D2C50_G *)func_800787B4())->f328;
    int n = (int)D_800B4D5C[0];
    T_D2C50_B *b = d;
    T_D5760_s *s = (T_D5760_s *)b->items[n];
    T_PK *t = s->f578;
    for (int i = 0; i < 15; i++) {
        T_D5760_e28 *q;
        func_80054094(&p->e7C[i], s->v400[0].v10(p->b6C[i]) == 0);
        q = &p->e220[i];
        func_80054708(q, (t[p->b6C[i]].h >> 10) + 1);
        int k = func_800549D8(q);
        func_80054708(&p->e478[i], D_800AEBD4[p->b6C[i]].b1F << (k - 1));
    }
    for (unsigned j = 0; j < 15; j++) {
        if (p->b6C[j] == 9 && func_8005409C(&p->e7C[j])) {
            if (func_800D0390()) func_80054094(&p->e7C[j], 1);
            j = 15;
        }
    }
    p->f20 = D_800B4DD0[0]->s1F6;
    func_800631D4(p);
}

EXTERN_C void func_800D596C(T_D596C *p) { func_8006323C(p); int v = p->f20; D_800B4DD0[0]->s1F6 = v; func_8005457C(p, 0); }

EXTERN_C int func_800D59AC(T_D59AC *p, T_D19F0_q *q) {
    if (func_8005618C(q)) return 1;
    int i = p->f20;
    if (q->h18 & 0x2000) {
        if (!func_80053880(p->f3C ? p->f3C->f50 : 0)) return 1;
        if (func_8005409C(func_800550BC(p))) {
            p->f5C = 2; p->v3();
            T_4DD0f *t = (T_4DD0f *)D_800B4DD0[0];
            if (t->s1F4 < 3 && ((signed char *)p + i)[0x6C] == 9) { t->s1F4++; func_800C5020(operator new(0x78), D_800B7EDC, 0x3C); }
            func_8005549C(p->f68, p, 0, -1);
        } else func_8008EF40(0xE);
    } else func_80063340(p, q);
    return 1;
}

EXTERN_C void func_800D5AE4(T_D5AE4 *self, int in_chrg)
{
    T_VTable10 vt;
    self->vt54 = D_800B7F8C;
    self->vt58 = D_800B7F6C;
    self->vt18 = D_800B7FBC;
    self->vb50->vptr = (T_VTable10 *)&D_800B7F1C;
    if (!in_chrg) {
        vt = D_800B7F1C;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B7F1C.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x6D0));
        vt.e[6].delta = D_800B7F1C.e[6].delta + adj;
    }
    destroy28(self->e478, 15);
    destroy28(self->e220, 15);
    destroy1C(self->e7C, 15);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb50->vptr = (T_VTable10 *)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_80014E0C.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x68));
        vt.e[6].delta = D_80014E0C.e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb50, 0);
    if (in_chrg & 1)
        operator delete(self);
}

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7EDC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7F1C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7F6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7F8C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle_c", D_800B7FBC);
