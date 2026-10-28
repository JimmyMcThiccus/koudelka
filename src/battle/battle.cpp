#include "common.h"
#include "battle/battle.h"

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B7FFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8210);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B82C0);

EXTERN_C int func_800B8474(T_B8474 *p) {
    if (p->f4) { p->f4--; }
    else {
        delete p->f8;
        D_800D5D78[0]--;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800B84EC() { return D_800D5D78[0] != 0; }

EXTERN_C T_B84FC *func_800B84FC(T_B84FC *p, int a, int b) {
    p->vtbl = D_800B6DF4;
    p->f4 = b;
    p->f8 = a;
    void *g = D_800A4544;
    T_BC180 *o = (T_BC180 *)operator new(0x14);
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_80010338;
    o->sC = 0x80;
    o->f8 = p;
    o->f10 = 1;
    func_8001D150(g, o);
    D_800D5D78[0]++;
    return p;
}

EXTERN_C void func_800B8598(void *p, int flags) { func_8001D024(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B85B8);

EXTERN_C void func_800B8778(T_B8778 *p, int flags) { dtor_B8778(p, D_800B6E64, D_800B6E0C, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B881C);

EXTERN_C void func_800B8924(T_B8924 *p, int flags) {
    p->vtbl8C = D_800B6EE4;
    p->vtblF8 = D_800B6ECC;
    p->vtbl = D_800B6EFC;
    func_800B8F5C((T_B8F5C *)p);
    func_8008E504(((T_B8924_g *)D_800B4ED8[0])->f248);
    ((T_B8924_g *)D_800B4ED8[0])->f248 = 0;
    func_80019920(p->f530, 0);
    func_80019920(p->f510, 0);
    func_80019920(p->f4E8, 0);
    func_800BC310((T_BC310 *)p, flags);
}

EXTERN_C void func_800B89D4(void *p) {
    func_800B9480((T_B9480 *)p);
    func_800B9530((T_B9530 *)p);
    func_800BC180(func_800BC114((T_BBC7C *)operator new(0x18), (int)p, 0x12D, 0, 0x12C, 4));
    T_B89D4_B *g = (T_B89D4_g *)D_800B4ED8[0];
    T_B9844 *o = (T_B9844 *)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_80010300;
    o->s8 = 2;
    o->sA = 2;
    o->f10 = 9;
    o->fC = p;
    o->vtbl = D_800102D0;
    func_8001EFE4(g, o);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8AA8);

EXTERN_C int func_800B8EFC(S_800BA418 *p) { S_800BA418_41C *q = p->f41C; p->b100 = q->b8; p->b101 = q->b9; func_800B9A30(p, q->fC, &p->f3E8, p->f3F8); func_800BA248(p); func_800BA024(p); func_800BA2F4(p); return 1; }

EXTERN_C void func_800B8F5C(T_B8F5C *p) {
    p->m3E8.clear();
    p->m3F8.clear();
    p->s3D8 = 0;
    p->s3DA = 0;
}

EXTERN_C void func_800B8FF4(T_B8FF4 *p) {
    p->f550 = (T_V2 *)func_800BA700((T_BA700 *)operator new(0x14), 0);
    int a = func_800B9FC4((S_800BA418 *)p, 0);
    func_800BC0E8((S_800BC0E8 *)p->f550, a, func_800B9FC4((S_800BA418 *)p, 1));
    p->f550->v2();
    link_B8FF4(&p->m408, p->f550);
    p->f554 = (T_V2 *)func_800BAD6C((T_BAD6C *)operator new(0xA4), 0);
    func_800BC0E8((S_800BC0E8 *)p->f554, func_800B9FC4((S_800BA418 *)p, 2), 0);
    p->f554->v2();
    link_B8FF4(&p->m408, p->f554);
    p->f558 = (T_V2 *)func_800BB860((T_BAD6C *)operator new(0xA4), 0);
    func_800BC0E8((S_800BC0E8 *)p->f558, func_800B9FC4((S_800BA418 *)p, 2), 0);
    p->f558->v2();
    link_B8FF4(&p->m408, p->f558);
    p->f55C = (T_V2 *)func_800BBC7C((T_BBC7C *)operator new(0x18));
    func_800BC0E8((S_800BC0E8 *)p->f55C, func_800B9FC4((S_800BA418 *)p, 0), 0);
    p->f55C->v2();
    link_B8FF4(&p->m408, p->f55C);
    for (T_B9480_n *n = p->m408.head; n; n = n->next) {
        int v = n->f10;
        func_80039BEC((T_B9480_g *)p->f278, v);
    }
}

EXTERN_C int func_800B9268(T_B9268 *p, int *t) { func_800BB118(p->f554, t); return 1; }

EXTERN_C int func_800B928C(T_B9268 *p, int *t) { func_800BBC04(p->f558, t); return 1; }

EXTERN_C void func_800B92B0() { func_8007F5B8(func_800787B4(), 0, 0); }

EXTERN_C void func_800B92E0(T_B92E0 *p) {
    if (p->f508 || p->f50C) return;
    SVec2 v[4];
    T_BCB6C_c c1, c2;
    v[0].x = 0; v[0].y = 0;
    v[1].x = 320; v[1].y = 0;
    v[2].x = 0; v[2].y = 240;
    v[3].x = 320; v[3].y = 240;
    func_8002972C(&c1, 100, 100, 200, 1);
    func_8002972C(&c2, 0, 0, 0, 1);
    void *o = func_800BC704((T_BC704 *)operator new(0x70), v, &c1, &c1, &c2, &c2, 0x1FFF, -1, 0);
    p->f508 = o;
    LV *l = lv_ofx(&p->x4E8);
    func_80019A6C((List *)l, (int)o, l->count);
    o = func_800BC704((T_BC704 *)operator new(0x70), v, &c2, &c2, &c2, &c2, 0x1FFF, -1, 0);
    p->f50C = o;
    l = lv_ofx(&p->x4E8);
    func_80019A6C((List *)l, (int)o, l->count);
    func_8002DA94((int)p->f278->f254, (Holder *)(void *)&p->x4E8);
    func_800198AC(&c2, 2);
    func_800198AC(&c1, 2);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9480);

EXTERN_C void func_800B9530(T_B9530 *p) {
    void *g = p->f278->f254;
    while (lv_count(&p->x4E8)) {
        void *o = lv_back(lv_of(&p->x4E8));
        if (!o) continue;
        func_8002DC34(g, o, 0);
        func_80019CFC(lv_of(&p->x4E8), o);
        LV *l = lv_ofx(&p->x530);
        func_80019A6C((List *)l, (int)o, l->count);
    }
    p->f508 = 0;
    p->f50C = 0;
}

EXTERN_C int func_800B9654(void *q) {
    while (lv_count(&((T_B9654 *)q)->x510)) {
        T_B9654_o *o = (T_B9654_o *)lv_back(lv_of(&((T_B9654 *)q)->x510));
        o->v7(0);
        func_80019CFC(lv_of(&((T_B9654 *)q)->x510), o);
        delete o;
    }
    return 1;
}

EXTERN_C int func_800B9758(void *q) {
    while (lv_count(&((T_B9758 *)q)->x530)) {
        T_Obj0 *o = (T_Obj0 *)lv_back(lv_of(&((T_B9758 *)q)->x530));
        func_80019CFC(lv_of(&((T_B9758 *)q)->x530), o);
        delete o;
    }
    return 1;
}

EXTERN_C int func_800B9844(void *p) {
    T_B9844 *o = (T_B9844 *)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_80010300;
    o->s8 = 2;
    o->sA = 2;
    o->f10 = 0;
    o->fC = p;
    o->vtbl = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C int func_800B98B8() { return D_800D5D7C; }

EXTERN_C T_B98C8 *func_800B98C8(T_B98C8 *p, int x) {
    func_8001E40C(p, x, 2, 0x1000, 0);
    func_800514C8(&p->vtblF8);
    T_B98C8_s *a = &p->f3E8;
    p->vtbl8C = D_800B6F2C;
    p->vtblF8 = D_800B6F14;
    p->vtbl = D_800B6F44;
    func_800BA564((T_VObj8 *)a, 0, 0);
    T_B98C8_s *b = &p->f3F8;
    func_800BDE2C((T_VObj8 *)b);
    T_B98C8_s *c = &p->f408;
    func_800BC094((T_VObj *)c, 0, 0);
    T_BE390 *g = D_800B4ED8[0];
    register T_B98C8 *r asm("$2") = p;
    r->f274 = 1;
    r->b100 = 0;
    r->b101 = 0;
    r->s3D8 = 0;
    r->s3DA = 0;
    r->f278 = g;
    c->f4 = 0;
    a->f4 = 0;
    b->f4 = 0;
    return r;
}

EXTERN_C void func_800B99A4(T_B99A4 *p, int flags) {
    p->vtbl8C = D_800B6F2C;
    p->vtblF8 = D_800B6F14;
    p->vtbl = D_800B6F44;
    func_800BC0C0(&p->f408, 2);
    func_800BDE5C(&p->f3F8, 2);
    func_800BA594(&p->f3E8, 2);
    func_80051514(&p->vtblF8, 0);
    func_8001E508(p, flags);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9A30);

EXTERN_C int func_800B9F48(S_800BA418 *p, signed char a) {
    S_800BA6B4 *q = p->f3E8.f4;
    while (p->b101) {
        S_800BA6B4 *r = q;
        if (a == func_800BA6D0(r)) return r->fC;
        q = (S_800BA6B4 *)r->f4;
    }
    exit(1);
}

EXTERN_C int func_800B9FC4(S_800BA418 *p, signed char a) {
    S_800BA418_3FC *q = p->f3FC;
    for (signed char n = p->b100; n; n--) {
        S_800BA418_3FC *r = q;
        if (a == r->b8) return r->fC;
        q = r->f4;
    }
    exit(1);
}

#define Q ((T_BA024 *)p)
EXTERN_C int func_800BA024(S_800BA418 *p) {
    Q->f278->f11C = Q->f2A0;
    func_80099C80(Q->f278->f11C);
    Q->f278->f84 = Q->f290 * 10;
    Q->f278->f88 = Q->f294 * 10;
    Q->f278->f8C = Q->f298 * 10;
    Q->f278->s7C = Q->h2A4;
    Q->f278->s7E = Q->h2A6;
    Q->f278->s80 = Q->h2A8;
    T_BA024_G *g = Q->f278;
    g->v34(&g->s7C, &g->f84);
    T_CV c;
    c.r = Q->b2AC;
    c.g = Q->b2AD;
    c.b = Q->b2AE;
    T_BA024_B *h = Q->f278;
    h->fB8 = c;
    h->fBC = 1;
    int n = p->s28C;
    int m = 3 - n;
    for (int i = 0; i < n; i++)
        func_80065D20(Q->f278, i, Q->n32C[i].x, Q->n32C[i].y, Q->n32C[i].z, Q->e2B4[i].b0, Q->e2B4[i].b1, Q->e2B4[i].b2);
    for (int j = 0; j < m; j++)
        func_80065E10(Q->f278, 2 - j);
    return 1;
}
#undef Q

EXTERN_C void func_800BA248(S_800BA418 *p) {
    int n = p->s28C;
    T_VEC v;
    for (int i = 0; i < n; i++) {
        v.x = ((T_BA248 *)p)->e[i].b.x - ((T_BA248 *)p)->e[i].a.x;
        v.y = ((T_BA248 *)p)->e[i].b.y - ((T_BA248 *)p)->e[i].a.y;
        v.z = ((T_BA248 *)p)->e[i].b.z - ((T_BA248 *)p)->e[i].a.z;
        VectorNormal(&v, &((T_BA248 *)p)->n[i]);
    }
}

EXTERN_C void func_800BA2F4(S_800BA418 *p) {
    T_BA2F4 *q = (T_BA2F4 *)p;
    q->f424.a = q->f290.a; q->f424.b = q->f290.b; q->f424.c = q->f290.c; q->f424.d = q->f290.d; q->f424.e = q->f290.e;
    q->f424.h0 = q->f290.h0; q->f424.h1 = q->f290.h1; q->f424.h2 = q->f290.h2; q->f424.h3 = q->f290.h3;
    q->f424.c0 = q->f290.c0; q->f424.c1 = q->f290.c1; q->f424.c2 = q->f290.c2; q->f424.c3 = q->f290.c3; q->f424.f = q->f290.f;
    for (int i = 0; i < 3; i++) {
        q->f448[i].w0 = q->e2B4[i].w0; q->f448[i].w1 = q->e2B4[i].w1; q->f448[i].w2 = q->e2B4[i].w2; q->f448[i].w3 = q->e2B4[i].w3;
        q->f448[i].w4 = q->e2B4[i].w4; q->f448[i].w5 = q->e2B4[i].w5; q->f448[i].w6 = q->e2B4[i].w6; q->f448[i].w7 = q->e2B4[i].w7;
        q->f448[i].b0 = q->e2B4[i].b0; q->f448[i].b1 = q->e2B4[i].b1; q->f448[i].b2 = q->e2B4[i].b2; q->f448[i].b3 = q->e2B4[i].b3;
        q->f448[i].b4 = q->e2B4[i].b4; q->f448[i].b5 = q->e2B4[i].b5; q->f448[i].b6 = q->e2B4[i].b6; q->f448[i].b7 = q->e2B4[i].b7;
    }
}

EXTERN_C char *func_800BA418(S_800BA418 *p) { return p->f424; }

EXTERN_C S_800BA418_448 *func_800BA420(S_800BA418 *p, int i) { return &p->f448[i]; }

EXTERN_C int func_800BA438(S_800BA418 *p) { return p->f104.f8; }

EXTERN_C int func_800BA444(S_800BA418 *p, int v) { p->f104.f8 = v; return 1; }

EXTERN_C SVec4 func_800BA450(S_800BA418 *p) { return p->f1EC; }

EXTERN_C SVec4 func_800BA47C(S_800BA418 *p) { return p->f1E4; }

EXTERN_C void func_800BA4A8(S_800BA418 *p, S_800BA418_60 *v) { p->f164 = *v; }

EXTERN_C void func_800BA4E4(S_800BA418 *p, S_800BA418_60 *v) { p->f104 = *v; }

EXTERN_C S_800BA418_60 *func_800BA520(S_800BA418 *p) { return &p->f104; }

EXTERN_C S_800BA418_60 *func_800BA528(S_800BA418 *p) { return &p->f164; }

EXTERN_C int func_800BA530(S_800BA418 *p) { return p->s28C; }

EXTERN_C int func_800BA53C(S_800BA418 *p) { return p->s3DA; }

EXTERN_C void func_800BA548(S_800BA418 *p, char v) { p->b101 = v; }

EXTERN_C void func_800BA550(S_800BA418 *p, char v) { p->b100 = v; }

EXTERN_C int func_800BA558(S_800BA418 *p) { return p->f278; }

EXTERN_C T_VObj8 *func_800BA564(T_VObj8 *p, char a, short b) { p->vtbl = D_80010178; p->f4 = 0; p->vtbl = D_800B6F5C; p->b8 = a; p->sA = b; p->fC = 0; return p; }

EXTERN_C void func_800BA594(T_BA594 *p, int flags) {
    p->vtbl = D_800B6F5C;
    delete p->fC;
    func_8001A610(p, flags);
}

EXTERN_C void func_800BA5FC(T_BA5FC *p, int a) {
    T_BA5FC_o *o = (T_BA5FC_o *)operator new(0x20C);
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_800106EC;
    o->s8 = 0;
    o->sA = 0;
    o->vtbl = D_80010624;
    func_80021F48(o, a);
    T_BA5FC_g *g = D_800B4C38[0];
    p->fC = o;
    g->v1(o);
    p->sA = p->fC->s8;
}

EXTERN_C int func_800BA6B4(S_800BA6B4 *p) { if (p->fC) return p->sA; return 0; }

EXTERN_C signed char func_800BA6D0(S_800BA6B4 *p) { if (p->fC) return p->b8; else return 0; }

EXTERN_C int func_800BA6EC(S_800BA6B4 *p) { return p->fC; }

EXTERN_C void func_800BA6F8(S_800BA6B4 *p, char v) { p->b8 = v; }

EXTERN_C T_BA700 *func_800BA700(T_BA700 *p, int a) { func_800BC094((T_VObj *)p, a, 0); p->vtbl = D_800B6F6C; p->f10 = 0; return p; }

EXTERN_C void func_800BA73C(T_VObj *p, int flags) { p->vtbl = D_800B6F6C; func_800BC0C0(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA764);

EXTERN_C T_BAD6C *func_800BAD6C(T_BAD6C *p, int a) {
    func_800BC094((T_VObj *)p, a, 0);
    p->vtbl = D_800B6F84;
    p->f10 = func_8003BEF8(operator new(0x4C));
    for (int i = 0; i < 35; i++) p->f18[i] = -1;
    p->f14 = p->f18;
    return p;
}

EXTERN_C void func_800BADDC(T_VObj *p, int flags) { p->vtbl = D_800B6F84; func_800BC0C0(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BAE04);

EXTERN_C void func_800BAFEC(void *p, T_BAFEC *q, int n) {
    int x = n % 5 * 2400;
    int z = n / 5 * 2400;
    q->v[0] = SV4C(x - 6000, 0, 8400 - z);
    q->v[1] = SV4C(x - 3600, 0, 8400 - z);
    q->v[2] = SV4C(x - 6000, 0, 6000 - z);
    q->v[3] = SV4C(x - 3600, 0, 6000 - z);
}

EXTERN_C void func_800BB118(T_BB118 *p, int *t) { p->f14 = t; for (int i = 0; i < 35; i++) p->f18[i] = -1; for (int i = 0; i < 35; i++) { int v = p->f14[i]; if (v == -1) break; if ((unsigned)v < 35) p->f18[v] = v; } }

EXTERN_C void func_800BB188(S_800BA6B4 *p) { p->f14 = 0; }

EXTERN_C T_BB190 *func_800BB190(T_BB190 *p) {
    ctor_BB190(p);
    p->vtbl8 = D_800B6F9C;
    p->vtbl = D_800B7004;
    p->f9C = -1;
    p->f98 = 0;
    return p;
}

EXTERN_C void func_800BB2B0(T_B8778 *p, int flags) { dtor_B8778(p, D_800B6F9C, D_800B7004, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB354);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB5EC);

EXTERN_C int func_800BB854(S_800BA6B4 *p) { return p->f4; }

EXTERN_C T_BAD6C *func_800BB860(T_BAD6C *p, int a) {
    func_800BC094((T_VObj *)p, a, 0);
    p->vtbl = D_800B7054;
    p->f10 = func_8003BEF8(operator new(0x4C));
    for (int i = 0; i < 35; i++) p->f18[i] = -1;
    p->f14 = p->f18;
    return p;
}

EXTERN_C void func_800BB8D0(T_VObj *p, int flags) { p->vtbl = D_800B7054; func_800BC0C0(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB8F8);

EXTERN_C void func_800BBAD4(void *p, T_BAFEC *q, int n) {
    int x = n % 5 * 2400;
    int z = n / 5 * 2400;
    q->v[0] = SV4C(x - 6000, -100, 8400 - z);
    q->v[1] = SV4C(x - 3600, -100, 8400 - z);
    q->v[2] = SV4C(x - 6000, -100, 6000 - z);
    q->v[3] = SV4C(x - 3600, -100, 6000 - z);
}

EXTERN_C void func_800BBC04(T_BB118 *p, int *t) { p->f14 = t; for (int i = 0; i < 35; i++) p->f18[i] = -1; for (int i = 0; i < 35; i++) { int v = p->f14[i]; if (v == -1) break; if ((unsigned)v < 35) p->f18[v] = v; } }

EXTERN_C void func_800BBC74(S_800BA6B4 *p) { p->f14 = 0; }

EXTERN_C T_BBC7C *func_800BBC7C(T_BBC7C *p) { func_800BC094((T_VObj *)p, 0, 0); p->vtbl = D_800B706C; p->f10 = 0; p->f14 = 0; return p; }

EXTERN_C void func_800BBCC0(T_VObj *p, int flags) { p->vtbl = D_800B706C; func_800BC0C0(p, flags); }

EXTERN_C int func_800BBCE8(T_BBCE8 *p) { p->f10 = func_8003BEF8(operator new(0x4C)); p->f14 = func_800BBD60(operator new(0xBC)); p->f10->v5(p->f14); return 1; }

EXTERN_C int func_800BBD54(S_800BA6B4 *p) { return p->f14; }

EXTERN_C void *func_800BBD60(void *q) {
    T_BBD60 *p = (T_BBD60 *)q;
    ctor_BB190(p);
    p->vtbl8 = D_800B7084;
    p->vtbl = D_800B70EC;
    new (p->v) SV4z[4];
    p->v[0].x = -8400; p->v[0].y = 0; p->v[0].z = 8400;
    p->v[1].x = 8400; p->v[1].y = 0; p->v[1].z = 8400;
    p->v[2].x = -8400; p->v[2].y = 0; p->v[2].z = -8400;
    p->v[3].x = 8400; p->v[3].y = 0; p->v[3].z = -8400;
    p->fB8 = 0;
    return p;
}

EXTERN_C void func_800BBEE0(T_B8778 *p, int flags) { dtor_B8778(p, D_800B7084, D_800B70EC, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BBF84);

EXTERN_C int func_800BC074(T_BC074 *p) { return p->fB8; }

EXTERN_C int func_800BC080(S_800BA6B4 *p) { return p->f4; }

EXTERN_C int func_800BC08C() { return 0; }

EXTERN_C T_VObj *func_800BC094(T_VObj *p, int a, int b) { p->vtbl = D_80010178; p->f4 = 0; p->vtbl = D_800B713C; p->f8 = a; p->fC = b; return p; }

EXTERN_C void func_800BC0C0(T_VObj *p, int flags) { p->vtbl = D_800B713C; func_8001A610(p, flags); }

EXTERN_C int func_800BC0E8(S_800BC0E8 *p, int a, int b) { p->f8 = a; p->fC = b; return 1; }

EXTERN_C int func_800BC0F8() { return 0; }

EXTERN_C void func_800BC100(S_800BA6B4 *p) { p->f10 = 0; }

EXTERN_C int func_800BC108(S_800BA6B4 *p) { return p->f10; }

EXTERN_C T_BBC7C *func_800BC114(T_BBC7C *p, int a, int b, int c, int d, int e) { p->vtbl = D_800B7154; p->f4 = a; p->fC = b; p->f8 = c; if (!c) p->f8 = p->f4; p->f10 = d; p->f14 = e; return p; }

EXTERN_C void func_800BC158(T_VObj *p, int flags) { p->vtbl = D_800B7154; func_8001D024(p, flags); }

EXTERN_C int func_800BC180(void *p) {
    void *g = D_800A454C;
    T_BC180 *o = (T_BC180 *)operator new(0x14);
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_80010338;
    o->sC = 0x80;
    o->f8 = p;
    o->f10 = 1;
    func_8001D150(g, o);
    return 1;
}

EXTERN_C int func_800BC1F8(S_800BA6B4 *p) { if (p->fC == 300) return 1; else { void *s = (void *)p->f4; if (p->fC == 301) { if (p->f14 == 0) { func_800BC270((T_BC270 *)p); func_800B9758(s); func_800B9844(s); return 1; } p->f14--; } return 0; } }

EXTERN_C int func_800BC270(T_BC270 *p) { func_800B9654(p->f4); return 1; }

EXTERN_C T_BC294 *func_800BC294(T_BC294 *p, int x) {
    func_800B98C8((T_B98C8 *)p, x);
    p->vtbl8C = D_800B7184;
    p->vtblF8 = D_800B716C;
    p->vtbl = D_800B719C;
    T_BC294_l *l = (T_BC294_l *)&p->f4C0;
    l->f8 = (char *)p + 0x4CC;
    p->f4C0 = (char *)p + 0x4CC;
    func_800198E0(l->f8, 0x10, 0);
    l->f4 = 0;
    p->f4E0 = 0;
    return p;
}

EXTERN_C void func_800BC310(T_BC310 *p, int flags) {
    p->vtbl8C = D_800B7184;
    p->vtblF8 = D_800B716C;
    p->vtbl = D_800B719C;
    func_80019920(p->f4C0, 0);
    func_800B99A4((T_B99A4 *)p, flags);
}

EXTERN_C int func_800BC378(T_BC420 *p, int a) { List *l = &p->h4C0; func_80019A6C(l, a, l->count); return 1; }

EXTERN_C T_BC3B4_item *func_800BC3B4(T_BC3B4 *p, int i) { T_BC3B4_M *m = &p->x4C0; p->f4E0 = func_80019F64(m, i); if (!p->f4E0) return 0; if (!p->f4E0->f1B8) return 0; return p->f4E0; }

EXTERN_C int func_800BC420(T_BC420 *p) { return count_of(&p->h4C0); }

EXTERN_C int func_800BC440(T_BC3B4 *p, int i, T_V4C *out) {
    T_BC3B4_M *m = &p->x4C0;
    T_BC514_item *it = (T_BC514_item *)(p->f4E0 = func_80019F64(m, i));
    if (it && it->f1B8) { *out = pos2_BC440(&it->f1B8->f34); return 1; }
    return 0;
}

EXTERN_C int func_800BC514(T_BC3B4 *p, int i, T_VEC *out) {
    T_BC3B4_M *m = &p->x4C0;
    T_BC514_item *it = (T_BC514_item *)(p->f4E0 = func_80019F64(m, i));
    if (it && it->f1B8) { *out = it->f1B8->f34; return 1; }
    return 0;
}

EXTERN_C int func_800BC5A8(T_BC3B4 *p, int i, T_VEC *in) {
    T_BC3B4_M *m = &p->x4C0;
    T_BC514_item *it = (T_BC514_item *)(p->f4E0 = func_80019F64(m, i));
    if (it) {
        T_BC514_o *o = it->f1B8;
        if (!o) return 0;
        o->f34 = *in;
        func_80039DD8(o);
        return 1;
    }
    return 0;
}

EXTERN_C int func_800BC644(T_BC3B4 *p, int i, short *out) {
    T_BC3B4_M *m = &p->x4C0;
    T_BC644_item *it = (T_BC644_item *)(p->f4E0 = func_80019F64(m, i));
    if (it && it->f1B8) { *out = it->s1BC; return 1; }
    *out = -1;
    return 0;
}

EXTERN_C void func_800BC6C8(T_BC420 *p) { func_80019D40(&p->h4C0); }

EXTERN_C Holder *func_800BC6FC(T_BC420 *p) { return &p->h4C0; }

EXTERN_C T_BC704 *func_800BC704(T_BC704 *p, SVec2 *v, T_BCB6C_c *a, T_BCB6C_c *b, T_BCB6C_c *c, T_BCB6C_c *d, short e, short f, int g) {
    p->vtbl = D_80010178;
    p->f4 = 0;
    p->vtbl = D_800111BC;
    p->s8 = 0;
    p->vtbl = D_800B71B4;
    ((char *)&p->prims[0])[3] = 8; p->prims[0].code = 0x38;
    ((char *)&p->prims[1])[3] = 8; p->prims[1].code = 0x38;
    p->sA = e;
    p->f6C = g;
    SetDrawMode(&p->dm[0], 0, 1, 0, 0);
    SetDrawMode(&p->dm[1], 0, 1, 0, 0);
    if ((unsigned short)f < 4) {
        func_80098DC0(&p->prims[0], 1);
        func_80098DC0(&p->prims[1], 1);
    } else {
        func_80098DC0(&p->prims[0], 0);
        func_80098DC0(&p->prims[1], 0);
    }
    func_800BCCEC((T_BCA6C *)p, v);
    func_800BCDC0((T_BCA6C *)p, a, b, c, d);
    func_800BCFC4(p);
    return p;
}

EXTERN_C void func_800BC850(T_VObj *p, int flags) { p->vtbl = D_800B71B4; func_8001A610(p, flags); }

EXTERN_C int func_800BC878(T_BC878 *p) {
    switch (p->s8) {
    case 1: p->v8();
    case 2: p->s8--;
    }
    if (p->f6C) {
        add_prim(p->sA, &p->prims[D_800B4CF0[0]]);
        add_prim(p->sA, &p->dm[D_800B4CF0[0]]);
        return 2;
    }
    add_prim(p->sA, &p->prims[D_800B4CF0[0]]);
    return 1;
}

EXTERN_C void func_800BCA6C(T_BCA6C *p, short y) {
    if (p->s8 == 1) p->v8();
    int i = D_800B4CF0[0];
    p->prims[i].y2 = y;
    p->prims[i].y3 = y;
    p->s8 = 2;
}

EXTERN_C void func_800BCAEC(T_BCA6C *p, short y) {
    if (p->s8 == 1) p->v8();
    int i = D_800B4CF0[0];
    p->prims[i].y0 = y;
    p->prims[i].y1 = y;
    p->s8 = 2;
}

EXTERN_C void func_800BCB6C(T_BCA6C *p, T_BCB6C_c *c) {
    if (p->s8 == 1) p->v8();
    p->prims[D_800B4CF0[0]].r0 = c->r;
    p->prims[D_800B4CF0[0]].g0 = c->g;
    p->prims[D_800B4CF0[0]].b0 = c->b;
    p->s8 = 2;
}

EXTERN_C void func_800BCC2C(T_BCA6C *p, T_BCB6C_c *c) {
    if (p->s8 == 1) p->v8();
    p->prims[D_800B4CF0[0]].r1 = c->r;
    p->prims[D_800B4CF0[0]].g1 = c->g;
    p->prims[D_800B4CF0[0]].b1 = c->b;
    p->s8 = 2;
}

EXTERN_C void func_800BCCEC(T_BCA6C *p, SVec2 *v) {
    if (p->s8 == 1) p->v8();
    int i = D_800B4CF0[0];
    p->prims[i].x0 = v[0].x;
    p->prims[i].y0 = v[0].y;
    p->prims[i].x1 = v[1].x;
    p->prims[i].y1 = v[1].y;
    p->prims[i].x2 = v[2].x;
    p->prims[i].y2 = v[2].y;
    p->prims[i].x3 = v[3].x;
    p->prims[i].y3 = v[3].y;
    p->s8 = 2;
}

EXTERN_C void func_800BCDC0(T_BCA6C *p, T_BCB6C_c *a, T_BCB6C_c *b, T_BCB6C_c *c, T_BCB6C_c *d) {
    if (p->s8 == 1) p->v8();
    p->prims[D_800B4CF0[0]].r0 = a->r;
    p->prims[D_800B4CF0[0]].g0 = a->g;
    p->prims[D_800B4CF0[0]].b0 = a->b;
    p->prims[D_800B4CF0[0]].r1 = b->r;
    p->prims[D_800B4CF0[0]].g1 = b->g;
    p->prims[D_800B4CF0[0]].b1 = b->b;
    p->prims[D_800B4CF0[0]].r2 = c->r;
    p->prims[D_800B4CF0[0]].g2 = c->g;
    p->prims[D_800B4CF0[0]].b2 = c->b;
    p->prims[D_800B4CF0[0]].r3 = d->r;
    p->prims[D_800B4CF0[0]].g3 = d->g;
    p->prims[D_800B4CF0[0]].b3 = d->b;
    p->s8 = 2;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BCFC4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD0A4);

EXTERN_C int func_800BD158(S_800BA6B4 *p) { return p->f4; }

EXTERN_C T_BB190 *func_800BD164(T_BB190 *p) {
    ctor_BB190(p);
    p->vtbl8 = D_800B7204;
    p->vtbl = D_800B726C;
    p->f9C = -1;
    p->f98 = 0;
    return p;
}

EXTERN_C void func_800BD284(T_B8778 *p, int flags) { dtor_B8778(p, D_800B7204, D_800B726C, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD328);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD5C4);

EXTERN_C int func_800BD830(S_800BA6B4 *p) { return p->f4; }

EXTERN_C T_BB190 *func_800BD83C(T_BB190 *p) {
    ctor_BB190(p);
    p->vtbl8 = D_800B72BC;
    p->vtbl = D_800B7324;
    return p;
}

EXTERN_C void func_800BD950(T_B8778 *p, int flags) { dtor_B8778(p, D_800B72BC, D_800B7324, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD9F4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BDC28);

EXTERN_C int func_800BDE20(S_800BA6B4 *p) { return p->f4; }

EXTERN_C T_VObj8 *func_800BDE2C(T_VObj8 *p) { p->vtbl = D_80010178; p->f4 = 0; p->vtbl = D_800B7374; p->b8 = 0; p->sA = 0; p->fC = 0; return p; }

EXTERN_C void func_800BDE5C(T_BDE5C *p, int flags) {
    p->vtbl = D_800B7374;
    if (p->fC) {
        func_80024FEC(p->fC, 0);
        delete p->fC;
    }
    func_8001A610(p, flags);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BDEDC);

EXTERN_C int func_800BE068(S_800BE068 *p) { return p->fC; }

EXTERN_C void func_800BE074(S_800BE068 *p, char v) { p->b8 = v; }

EXTERN_C void func_800BE07C(S_800BE068 *p, short v) { p->sA = v; }

EXTERN_C int func_800BE084(S_800BE068 *p) { return p->b8; }

EXTERN_C int func_800BE090(S_800BE068 *p) { return p->sA; }

EXTERN_C T_BE0F8 *func_800BE09C(T_BE0F8 *p) {
    T_4DD0 *g = D_800B4DD0[0];
    p->f0 = 1;
    p->f4 = ((((short *)func_80062118(g))[1] + 0x200) & 0xFFF) / 1024;
    return p;
}

EXTERN_C T_BE0F8 *func_800BE0F8(T_BE0F8 *p, T_BE0F8 *q) { p->f0 = q->f0; return p; }

EXTERN_C T_BE0F8 *func_800BE108(T_BE0F8 *p, void *qv) {
    unsigned short v = ((T_BE108 *)qv)->h18;
    if (v & 0x400) func_800BE29C(&p->f0, -1);
    else if (v & 0x800) func_800BE29C(&p->f0, 1);
    else if (v & 0x100) func_800BE2EC(&p->f0, -1);
    else if (v & 0x200) func_800BE2EC(&p->f0, 1);
    return p;
}

EXTERN_C T_BE0F8 *func_800BE18C(T_BE0F8 *p, void *x) {
    func_80062120(D_800B4DD0[0], x);
    p->f4 = ((((short *)func_80062118(D_800B4DD0[0]))[1] + 0x200) & 0xFFF) / 1024;
    return p;
}

EXTERN_C T_BE0F8 *func_800BE1F8(T_BE0F8 *p, int *out) { *out = p->f4; return p; }

EXTERN_C T_BE0F8 *func_800BE208(T_BE0F8 *p, T_BE208 *out) {
    *out = *func_80062118(D_800B4DD0[0]);
    return p;
}

EXTERN_C void func_800BE274() { func_8006B850(D_800B4ED8[0]); }

EXTERN_C void func_800BE29C(int *p, int a) { if (!*p || !a) func_8006B850(D_800B4ED8[0]); else func_8006B7D8(D_800B4ED8[0], a > 0); }

EXTERN_C void func_800BE2EC(int *p, int a) { if (!*p || !a) func_8006B850(D_800B4ED8[0]); else func_8006B814(D_800B4ED8[0], a < 1); }

EXTERN_C void *func_800BE33C(void *p) { return p; }

EXTERN_C void func_800BE344(int a) { T_BE390 *g = D_800B4ED8[0]; T_BE390 *h = g; if (a) { int old = g->f278; g->f278 = 4; g->f26C = 0; D_800D5D80[0] = old; } func_8006B740(h, 0xCD); }

EXTERN_C void func_800BE390() { T_BE390 *p = D_800B4ED8[0]; int old = D_800D5D80[0]; D_800D5D80[0] = 6; p->f278 = old; p->f26C = 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE3B4);

EXTERN_C T_BE484 *func_800BE484(T_BE484 *p, int a) {
    func_800756F8(p);
    p->vtbl = D_800B7384;
    p->f28 = a;
    new (p->e30) T_BE484_e[7];
    T_BE484_c t;
    T_BE484_c *tp = &t;
    be484_set(&p->e30[0], t, tp);
    be484_set(&p->e30[1], t, tp);
    be484_set(&p->e30[2], t, tp);
    be484_set(&p->e30[3], t, tp);
    be484_set(&p->e30[4], t, tp);
    be484_set(&p->e30[5], t, tp);
    be484_set(&p->e30[6], t, tp);
    p->f4 = 0;
    for (int i = 6; i >= 0; i--) p->f8[i] = 0;
    p->s26 = 0;
    p->s24 = 0;
    void *x = func_800758F8(operator new(0x1C8), 1, D_800B4C18[0], p);
    void *d = D_800B4C18[0];
    p->f2C = x;
    func_8001E848(d, x);
    func_8007669C(p->f2C, 0x7535, 0x9000);
    return p;
}

EXTERN_C void func_800BE6B8(T_BE6B8 *p, int flags) {
    p->vtbl = D_800B7384;
    if (p->f4) {
        func_80024FEC(p->f4, 0);
        delete p->f4;
    }
    for (int i = 0; i < p->s26; i++) delete p->f8[i];
    if (flags & 1) operator delete(p);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE7A4);

EXTERN_C int func_800BE928(void *self, int b) { if (b & 0x8000) return 1; if (b & 0x4000) return 2; if (b & 0x2000) return 3; if (b & 0x1000) return 4; if (b & 0x800) return 5; if (b & 0x400) return 6; return 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE990);

EXTERN_C void func_800BEBD8() {}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BEBE0);

EXTERN_C void func_800BEDE8(T_BEDE8 *p, int flags) {
    p->vtbl = D_800B73A4;
    delete p->f14;
    func_8001D024(p, flags);
}

EXTERN_C void func_800BEE50(T_BEBE0 *pv, T_BEE50_r *a, T_BEE50_r *b) {
    T_BEE50 *p = (T_BEE50 *)pv;
    int cols = 2;
    int rows = 8 / cols;
    int w = (p->b12 - p->b10 + 1) / cols;
    int row = (signed char)p->b24 / cols;
    int h = (p->b13 - p->b11 + 1) / rows;
    a->x = p->b10 + w * (p->b24 - row * cols);
    a->y = p->b11 + h * row;
    b->x = a->x + w - 1;
    b->y = a->y + h - 1;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BEF98);

EXTERN_C T_VEC func_800BF1D0(void *self, T_VEC *b) {
    T_VEC c = ((T_BF1D0_g *)D_800B4ED8[0])->v2C8;
    T_VEC r;
    r = func_800BF3B4(&c, b);
    int len = SquareRoot0(r.x * r.x + r.y * r.y + r.z * r.z);
    int x = r.x * 1000 / len;
    int y = r.y * 1000 / len;
    int z = r.z * 1000 / len;
    r.x = x + b->x;
    r.y = y + b->y;
    r.z = z + b->z;
    return r;
}

/* GCC named return value: the result is built in place. */
EXTERN_C T_VEC func_800BF3B4(T_VEC *a, T_VEC *b) return r
{
    int x = a->x - b->x;
    int y = a->y - b->y;
    int z = a->z - b->z;
    int w = a->w;
    r.x = x;
    r.y = y;
    r.z = z;
    r.w = w;
}

EXTERN_C void func_800BF3F4() {}

EXTERN_C int func_800BF3FC() { return 0; }

EXTERN_C void func_800BF404() {}

EXTERN_C void func_800BF40C() {}

EXTERN_C void func_800BF414(T_BF5FC *p) {
    T_BF5FC_n *a = (T_BF5FC_n *)func_800BFCB8((T_BFCB8 *)p, 0);
    if (!a) return;
    T_BF5FC_n *b = (T_BF5FC_n *)func_800BFCB8((T_BFCB8 *)p, (int *)a);
    if (!b) return;
    T_AFA58 *o[4];
    T_AFA58 *d[4];
    T_BF414_x x;
    int team = p->b4BC;
    T_C19BC_g *g = (T_C19BC_g *)D_800AF470[0];
    for (int i = 0; i < 3; i++) {
        T_BF414_b *q = g->f328 ? (T_BF414_b *)g->f328->fB8 : 0;
        o[i] = q->f8[i];
        d[i] = D_800AFA58[i];
        x.e[i] = o[i] ? (T_AFA58 *)o[i]->f1B8 : 0;
        x.e[i + 3] = d[i] ? (T_AFA58 *)d[i]->f1B8 : 0;
    }
    p->f4C0 = func_800D7048(operator new(0x24), team, x.e[0], x.e[1], x.e[2], x.e[3], x.e[4], x.e[5]);
    a->sC = (a->sC + b->sC) / 2;
    a->sE = (a->sE + b->sE) / 2;
    func_8008299C(p ? p->f2A0 : 0, 9, a->sC, a->sE, p->b4E4 != 0, 0, 0);
    func_800BFC18((T_BFCB8 *)p);
}

EXTERN_C int func_800BF5FC(T_BF5FC *p) {
    T_BF5FC_n *a = (T_BF5FC_n *)func_800BFCB8((T_BFCB8 *)p, 0);
    if (!a) {
        func_8008299C(p ? p->f2A0 : 0, 0xB, p->b4E4 != 0, 0, 0, 0, 0);
        if (p->b4BD == 1) func_8008299C(p ? p->f2A0 : 0, 0x1E, 0x800, 0x14, 0, 0, 0);
        else func_8008299C(p ? p->f2A0 : 0, 0x1E, 0, 0x14, 0, 0, 0);
        return 0;
    }
    T_BF5FC_n *b = (T_BF5FC_n *)func_800BFCB8((T_BFCB8 *)p, (int *)a);
    if (!b) {
        func_8008299C(p ? p->f2A0 : 0, 0xA, a->sC, a->sE, p->b4E4 != 0, 0, 0);
    } else {
        a->sC = (a->sC + b->sC) / 2;
        a->sE = (a->sE + b->sE) / 2;
        func_8008299C(p ? p->f2A0 : 0, 0xA, a->sC, a->sE, p->b4E4 != 0, 0, 0);
    }
    func_800BFC18((T_BFCB8 *)p);
    return 1;
}

EXTERN_C void func_800BF76C(T_BF76C *p, SVec2 pos, int flag) {
    func_800D8F98(p ? p->f400 : 0);
    p->f4B4 += p->h480;
    p->h4B8 |= 1;
    if (flag) {
        func_8008299C(p ? p->f2A0 : 0, 0x19, 3, 0, 0, 0, 0);
        T_VEC v;
        T_VEC *q = &v;
        v.x = 0;
        q->y = 0;
        q->z = 0;
        q->w = 0;
        v.x = (pos.x - 2) * 0x960;
        v.y = 0;
        v.z = (3 - pos.y) * 0x960;
        func_8008299C(p ? p->f2A0 : 0, 0x1D, v.x, v.y, v.z, 0, 0);
    } else {
        func_800CAAF8(((T_C19BC_g *)D_800AF470[0])->f32C, p, &pos);
        func_800BF414((T_BF5FC *)p);
        while (func_800BF5FC((T_BF5FC *)p)) ;
    }
}

EXTERN_C void func_800BF8B4(T_BF968 *p, int mode, short x, short y) {
    SVec2C v(x, y);
    if (p->b4E4 == 0) {
        switch (mode) {
        case 0: func_80043460(p, v, 0, 0); break;
        case 1: func_80043460(p, v, 0, 1); break;
        }
    } else {
        func_80043540(p, v, 0x14);
    }
}

EXTERN_C void func_800BF968(T_BF968 *p) { if (p->f4C0) { delete p->f4C0; p->f4C0 = 0; } if (p->b4E4 == 0) { p->fF8 = 0; p->s220 = 0; p->b120++; } }

EXTERN_C void func_800BF9DC(T_C1158 *p, int a, int b) {
    SVec4 *r = &p->f1B8->v2C;
    short d = SquareRoot0(r->x * r->x + r->y * r->y + r->z * r->z);
    T_VEC pos = p->f1B8->f34;
    int c = -func_80026014(d) * a;
    int sn = -func_800260A4(d) * a;
    int dx = c / 4096;
    int dz = sn / 4096;
    func_80043540(p, SVec2C(pos.x + dx, pos.z + dz), b);
}

EXTERN_C void func_800BFB18(T_BFB18 *p, int a, int b) { T_BFB18_t t; func_8003A150(&t, func_8003912C(p->f1B8, 9), 0); func_800C3FF4(operator new(0x60), 1, &t, a, b); }

EXTERN_C void func_800BFB80(T_BFCB8 *p, int a) { func_8007505C(&p->f52C, func_80085B28(operator new(0x10), a)); }

EXTERN_C void func_800BFBCC(T_BFCB8 *p, int a) { func_80075004(&p->f52C, func_80085B28(operator new(0x10), a)); }

EXTERN_C void func_800BFC18(T_BFCB8 *p) { delete (T_Obj8 *)func_800751AC(&p->f52C); }

EXTERN_C void func_800BFC60(T_BFCB8 *p) { T_Obj8 *n; while ((n = (T_Obj8 *)func_800751AC(&p->f52C)) != 0) delete n; }

EXTERN_C int func_800BFCB8(T_BFCB8 *p, int *q) { if (q) return *q; return p->f52C; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BFCD8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C02C8);

EXTERN_C void func_800C0608(T_C1340 *p, SVec2 v, int a) {
    p->f4D0 = grid_at((T_CFD98 *)((T_C19BC_g *)D_800AF470[0])->f32C, v);
    func_800C0694_t((T_C0694 *)p, a);
}

EXTERN_C void func_800C0670(T_B9268 *p, void *a, int b) { p->f4D0 = a; func_800C0694(p, b); }

EXTERN_C int func_800C0694_t(T_C0694 *p, int a) {
    int n;
    if (p->b4BD == 1) {
        n = e_bits(&((T_C0694_e *)p->b578)[p->s53E]);
        if (n >= 3) n = 2;
    } else {
        n = 2;
    }
    void *g = ((T_C19BC_g *)D_800AF470[0])->f32C;
    if (!func_800C9D6C(g, p, p->f4D0, p->f4D4, p->f4D8, n)) return 0;
    p->s53C = 2;
    p->s50C = 2;
    if (!a) (p ? (T_C0694_B *)p->f400 : 0)->v10(p->s53E);
    p->b4AD = 1;
    if (p->b4BD == 1) func_8008299C(p ? p->f2A0 : 0, 0, 0, 0, 0, 0, 0);
    func_8008299C(p ? p->f2A0 : 0, 0x13, 0, 0, 0, 0, 0);
    func_80085F90(p);
    return 1;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C07F8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C0EB8);

EXTERN_C void func_800C1118(T_C1340 *p) { if (p->s410 == 0) func_80082E14(p ? p->f2A0 : 0, 0); }

EXTERN_C void func_800C1158(T_C1158 *p) {
    if (p->f4D0) {
        T_VEC a = p->f1B8->f34;
        T_VEC b = p->f4D0->f1B8->f34;
        int dz = b.z - a.z;
        int dx = b.x - a.x;
        if (dz || dx) {
            int ang = ratan2(dx, dz);
            while (ang < 0) ang += 0x1000;
            ang = (ang + 0x800) & 0xFFF;
            func_8008299C(p ? p->f2A0 : 0, 0x1E, ang, 0x14, 0, 0, 0);
        }
    }
}

EXTERN_C void func_800C1254(T_C1340 *p) { if (p->f4D0) { if (p->b4BD == 1) func_8008299C(p ? p->f2A0 : 0, 0x1E, 0x800, 0x14, 0, 0, 0); else func_8008299C(p ? p->f2A0 : 0, 0x1E, 0x1000, 0x14, 0, 0, 0); } }

EXTERN_C void func_800C12D0(T_C1340 *p, SVec2 v) {
    T_C19BC_g *g = (T_C19BC_g *)D_800AF470[0];
    p->s53C = 3;
    p->s50C = 3;
    p->f4D0 = grid_at((T_CFD98 *)g->f32C, v);
    func_800C1360(p);
}

EXTERN_C void func_800C1340(T_C1340 *p, int v) { p->f4D0 = v; func_800C1360(p); }

EXTERN_C int func_800C1360(T_C1340 *p) { p->s53C = 3; p->s50C = 3; p->s480 = 0; p->b4AE = 1; func_8008299C(p ? p->f2A0 : 0, 0, 0, 0, 0, 0, 0); func_80085FD4(p); return 1; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C13CC);

EXTERN_C void func_800C18B4(T_C19BC *p, int x) {
    func_800C19BC(p, x, p->f4D0);
    func_800BE7A4((T_BE7A4 *)((T_C19BC_g *)D_800AF470[0])->f328->f114, p->h490, p->f4D0->f1B8, 0x10, 0, 0);
    func_800CBB84_b(((T_C19BC_g *)D_800AF470[0])->f32C);
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1924);

EXTERN_C void func_800C19BC(T_C19BC *a, int unused, T_C19BC *b) {
    short s = a->s50C;
    b->b50E = 1;
    b->s50C = s;
    if (b) func_800C1BE4(b, a);
    func_800CBB84_b(((T_C19BC_g *)D_800AF470[0])->f32C);
}

EXTERN_C T_C1A44 *func_800C1A10(T_C1A44 *p) { func_80074F58(p); p->vtblC = D_80017904; return p; }

EXTERN_C void func_800C1A44(T_C1A44 *p, int flags) { p->vtblC = D_80017904; func_80074F78(p, flags); }

EXTERN_C void *func_800C1A6C_2(void *lv, int team) {
    T_C1A6C *l = (T_C1A6C *)lv;
    if (!l->head) return 0;
    l->cur = l->head;
    for (;;) {
        if (l->get()->b4BC == team) return l->get();
        if (l->is_last()) break;
        l->next();
    }
    return 0;
}

EXTERN_C void func_800C1B48(void *p) { T_Obj0 *q; while ((q = func_800C1B48_pop(p)) != 0) delete q; }

EXTERN_C void func_800C1BA8(void *p) { char *q; do { char *r = (char *)func_800751AC(p); q = r ? r - 0x4A0 : 0; } while (q); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1BE4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B73D0);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7420);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7518);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7538);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B75A0);
