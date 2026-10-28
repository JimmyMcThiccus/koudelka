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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B98C8);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC294);

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

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6DF0);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6DF4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6E0C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6E64);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6ECC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6EE4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6EFC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F14);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F2C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F44);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F5C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F84);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F9C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7004);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7054);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B706C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7084);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B70EC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B713C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7154);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B716C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7184);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B719C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B71B4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7204);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B726C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B72BC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7324);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7374);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7384);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B73A4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1BE4);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1F5C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C220C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C2538);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C2814);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C2B70);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C2ECC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C30F0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3374);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C35F8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C38FC);

EXTERN_C int func_800C3CF4() { return 1; }

EXTERN_C int func_800C3CFC() { return 1; }

EXTERN_C int func_800C3D04(T_C3D04 *p, int a, int b, int c) { if (~c & b & 2) { p->b516 = 1; return 0; } return 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3D2C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3DAC);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3FF4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C41AC);

EXTERN_C void func_800C435C(T_C435C *p, int x) {
    if (p->f8) {
        func_8005C088(p, x, 1);
        List *l = p->f30;
        func_80019A6C(l, (int)func_800C4510((T_C4510 *)operator new(0x3C), (SVec4 *)p->f44, p->f4C, p->f50), count_of(l));
        func_8002DA94(x, p->f30);
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C43F0);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C48D8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C4B70);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C51D0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5474);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C54D8);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C56A8);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5F84);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C6194);

EXTERN_C int func_800C65C8(T_C65C8 *p, int a) {
    if (p->fA0) ((F_C51D0)func_800C51D0)(&p->fA4, p->fA0, a);
    p->fA0 = 0;
    if (!p->fA4.f0) return 0;
    T_C5474 *l = &p->fA4;
    while (!(p->fA0 = func_800C5474(l))) l->f12C++;
    func_800D94F4(p->fA0 ? p->fA0 + 0x400 : 0);
    return 1;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C666C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B73D0);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7420);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7518);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7538);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B75A0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C68D8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C6DF4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7158);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7604);

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
        func_800C7B5C(p, 0, l, x, y);
        func_80075004(l, func_80085AD4(operator new(0x10), x, y));
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7B5C);

EXTERN_C void func_800C7D88(T_Grids *p) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) p->b2C8[i][j] = -1; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7DD0);

EXTERN_C void func_800C7F30(T_Grids *p, char v) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) p->b380[i][j] = v; }

EXTERN_C void func_800C7F74(T_Grids *p, char v) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) p->b3A3[i][j] = v; }

EXTERN_C void func_800C7FB8(T_Grids *p) { for (int i = 0; i < 7; i++) for (int j = 0; j < 5; j++) p->b3A3[i][j] |= p->b380[i][j]; }

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B75F0);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7620);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C800C);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C8BA4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C8D9C);

EXTERN_C void func_800C8EE4(T_C8EE4 *p, int a) {
    int lo, hi;
    if (((F_C8D9C)func_800C8D9C)(p, a == 1 ? 2 : 1, &hi, &lo) < 0) return;
    for (int y = lo; y <= hi; y++) {
        for (int x = 0; x < 5; x++) p->b2C8[y][x] = -3;
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C8F78);

EXTERN_C int func_800C9284(T_C9A4C *p, int a, T_C9284 *q, int c) {
    p->f848 = 0;
    func_800CA9D0(p, c, 2);
    func_800C7F30((T_Grids *)p, 0);
    if (c != 12 && !q->s410) return 0;
    add_cell(p, q->s4C6, q->s4CA);
    return p->f848;
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9374);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9D6C);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CA1B4);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CA918);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CAAF8);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CADDC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CB174);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CBBB4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC110);

EXTERN_C void *func_800CC1B0(T_CC1B0 *p) { for (T_CE044_10 *e = func_800CE044(&p->f3D8); e; e = func_800CE090(&p->f3D8)) if ((e->h8 & 1) && (e->h8 & 0x20)) return e->p4; return 0; }

EXTERN_C T_CE044_10 *func_800CC220(T_CC1B0 *p, void *a) { for (T_CE044_10 *e = func_800CE044(&p->f3D8); e; e = func_800CE090(&p->f3D8)) if ((e->h8 & 1) && e->p4 == a) return e; return 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC298);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC3DC);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC98C);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CCDCC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CCFC0);

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
        func_800C7B5C(p, 0, l, x, y);
        func_80075004(l, func_80085AD4(operator new(0x10), x, y));
    }
}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CD488);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CD790);

EXTERN_C void func_800CDA8C(T_CDA8C *p, int v) { p->f818 = v; }

EXTERN_C void func_800CDA94(T_CDA94 *p, int bit, int on) { int m = 1 << bit; if (on) p->f814 |= m; else p->f814 &= ~m; }

EXTERN_C void func_800CDAC8(void *p) { func_800C757C(p, 1); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CDAE8);

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

EXTERN_C void func_800CE064(T_CE044 *p) { p->f8 = p->fC - 1; func_800CE00C(p); }

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE4E4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE7A4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE854);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE910);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CED08);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEFE8);

EXTERN_C void func_800CF080(T_CF080 *p, void *q, int i) { func_80042430(q, q, p->f808[i], 1); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF0B0);

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

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B772C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF408);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFDE0);

EXTERN_C int func_800CFE08(S_800CFCB0 *p) { p->f90 = 0; return p->f8C != 0; }

EXTERN_C int func_800CFE18(S_800CFCB0 *p) { return p->f8C; }

EXTERN_C void func_800CFE24(S_800CFCB0 *p) { p->f8C = 0; p->f90 = 0; }

EXTERN_C void func_800CFE30(T_CFE8C *p, SVec2 v) { p->f0[p->f8C++] = v; }

EXTERN_C void func_800CFE64(void *p, int flags) { if (flags & 1) operator delete(p); }

EXTERN_C T_CFE8C *func_800CFE8C(T_CFE8C *p) { SVec2 *q = p->f0; for (int i = 0x22; i != -1; i--) { q->x = 0; q->y = 0; q++; } p->f8C = 0; p->f90 = 0; return p; }

EXTERN_C void func_800CFEBC(T_CFEBC *p, T_CFEBC_18 *v) { p->f3E8 = *v; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFEF4);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D044C);

EXTERN_C void func_800D0588() {}

EXTERN_C void func_800D0590(void *self) {}

EXTERN_C void func_800D0598(void *self) { func_8005F440(func_800787B4(), 0x1262); }

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7748);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7768);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7778);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D05C4);

EXTERN_C void func_800D0BCC(void *q) { T_D0BCC *p = (T_D0BCC *)q; func_800D119C(p->f54); delete p->f54; p->f54 = 0; for (unsigned i = 0; i < 3; i++) { if (p->f58[i]) { func_8002B27C(p->f64, p->f58[i]); p->f58[i] = 0; } } func_8002B27C(D_800A4578[0], p->f64); p->f64 = 0; }

EXTERN_C void func_800D0C88(void *self) {}

EXTERN_C void func_800D0C90(T_D0C90 *p) { p->f68 = 1; func_80062280(D_800B4DD0[0], 1); }

EXTERN_C void func_800D0CC0(T_D0CC0 *p) { if (p->f68) func_800C5020(operator new(0x78), D_800B77D8, 0x3C); else func_800C5020(operator new(0x78), D_800B7800, 0x3C); }

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B77D8);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7800);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0D1C);

EXTERN_C void func_800D10D4(T_D10D4 *p, int m, int a) { if (m & 1) func_80054094(p->f54FC, a); if (m & 2) func_80054094(p->f5574, a); if (m & 4) func_80054094(p->f56DC, a); }

EXTERN_C void func_800D1148(T_D1148 *p) { D_800B4DA6[0] = 6; func_80063714(p, count_of(&p->h1C)); func_800D1458(p); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D119C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1458);

EXTERN_C void func_800D168C(T_D168C *p) { SVec4 v; SVec4 *q = &v; v.x = 0; q->y = 0; v.z = 0; v.w = 0; func_80054F30(p, 5, q, -8); func_80054F5C(p); for (unsigned i = 0; i < ((T_4DD0c *)D_800B4DD0[0])->b1FB; i++) p->e[i].v3(); }

EXTERN_C void func_800D1758(T_D1758 *p) { p->f5750 = 1; }

EXTERN_C void func_800D1764(void *p) { func_800566E4(p); func_80055330(0); func_8005549C(3, p, 0, -1); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D17A4);

EXTERN_C void func_800D1950(T_D1950 *p) { for (unsigned i = 0; i < ((T_4DD0b *)D_800B4DD0[0])->b1FB; i++) p->e[i].v5(); }

EXTERN_C int func_800D19F0(T_D19F0 *p, T_D19F0_q *q) { if (func_8005618C(q)) return 1; T_BE0F8 t; func_800BE09C(&t); T_BE0F8 k; k.f0 = 1; func_800BE108(func_800BE0F8(&t, &k), q); if (q->h18 & 0x1000) func_800631D4(p->f68); else if (!(q->h18 & 0xC00)) func_80063340(p, q); return 1; }

EXTERN_C int func_800D1A90(T_D1A90 *p, T_D19F0_q *q) { func_8001FC78(q, 0, 0); if (func_8005618C(q)) return 1; T_BE0F8 t; func_800BE09C(&t); T_BE0F8 k; k.f0 = 0; func_800BE108(func_800BE0F8(&t, &k), q); ((T_A4578 *)D_800A4578[0])->s1A4 = 3; if ((q->h18 & 0x10) && p->f3C) p->f20 = func_80058404(p->f3C, -1); else if ((q->h18 & 0x40) && p->f3C) p->f20 = func_80058404(p->f3C, 1); return 1; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1B68);

EXTERN_C void func_800D1C50(T_D1C50 *p) { for (unsigned i = 0; i < 4; i++) func_8005556C(2, 1); func_800D1148((T_D1148 *)p); int n = (int)D_800B4D5C[0]; T_D0390_G *g = (T_D0390_G *)func_800787B4(); T_D0390_B *b = g->f328; char *s = (char *)b->items[n]; if (func_8005409C(p->f5574)) func_80054094(p->f5574, func_8008A54C(s, 1) == 0); func_80054094(p->f2B04, (((unsigned char *)s)[0x46D] >> 6) & 1); func_80054094(p->f87C, func_80068A5C(p->f87C) != 0); func_800553D8(0); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1D38);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2254);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7884);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B78D4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B78F4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7924);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D23C0);

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

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B79A4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B79F4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7A14);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7A44);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2778);

EXTERN_C void func_800D2A2C(T_D2A2C *p, int a) { p->f7C = a; switch (a) { case 0: func_80053BCC(p->f60, D_800B7A98, 8); break; case 1: func_80053BCC(p->f60, D_800B7AAC, 6); break; default: func_80053BCC(p->f60, D_800B7ABC, 5); break; } }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2A98);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2D60);

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

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7A94);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7A98);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7AAC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7ABC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7ACC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7AFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D3574);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D3ED0);

EXTERN_C void func_800D401C(T_D401C *p) { T_D401C_M *m = p->f30; T_D401C_V *v = m; func_800D4518(v->count ? v->items[0] : 0); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D407C);

EXTERN_C void func_800D4094(T_D4094 *p, SVec4 *v) { p->f52 = *v; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D40BC);

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

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D43B0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4518);

EXTERN_C void func_800D4718(T_D4718 *p, SVec4 *v) { p->f10 = 1; p->f54 = *v; }

EXTERN_C void func_800D4748(T_D4748 *p, int a, int b) { if (p->f10) { T_D4748b *q = (T_D4748b *)p; q->s5C += a; q->s5E += b; } else { int i = D_800B4CF0[0]; p->e[i].x += a; p->e[i].y += b; } func_8005F1D8(p); }

EXTERN_C void func_800D47C8() {}

EXTERN_C void func_800D47D0(T_D47D0 *p, int a, int b) { p->v11(a - p->e[D_800B4CF0[0]].x, b - p->e[D_800B4CF0[0]].y); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4828);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4968);

EXTERN_C void func_800D4BD4() {}

EXTERN_C void func_800D4BDC(void *p, int flags) { func_8005F120(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4BFC);

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

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7B3C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7B6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7BBC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7BDC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7C1C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7C6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7D64);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7D84);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7DEC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7E3C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7E5C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7E8C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D5328);

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

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7EDC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7F1C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7F6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7F8C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7FBC);
