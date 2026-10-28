/* main_b round 2 (lead): best attempts that do not match yet. Not built. See README.md. */

//// func_80054B98
static inline char *init_80054B98(char *r)
{
    FIELD_AT(r, short, 0x46) = -2;
    FIELD_AT(r, short, 0x48) = -1;
    FIELD_AT(r, short, 0x4A) = 4;
    FIELD_AT(r, short, 0x40) = 0x10;
    FIELD_AT(r, short, 0x42) = 0x10;
    FIELD_AT(r, short, 0x4C) = 2;
    FIELD_AT(r, short, 0x4E) = 0x10;
    FIELD_AT(r, int, 0x3C) = 0;
    FIELD_AT(r, short, 0x44) = D_800B4D7C;
    return r;
}

extern "C" void *func_80054B98(void *self)
{
    char *m;
    func_80053928(self);
    FIELD_AT(self, void *, 0x18) = D_80013B70;
    m = (char *)self + 0x1C;
    FIELD_AT(m, void *, 0x8) = (char *)self + 0x28;
    FIELD_AT(self, void *, 0x1C) = (char *)self + 0x28;
    func_800198E0(FIELD_AT(m, void *, 0x8), 0x10, 0);
    FIELD_AT(m, int, 0x4) = 0;
    return init_80054B98((char *)self);
}

//// func_800553D8
extern "C" void func_800553D8(int a)
{
    char *o = (char *)D_800B4D84;
    if (FIELD_AT(o, int, 0x44FC) != 0) {
        View_80072970 *g = (View_80072970 *)&D_800A4534;
        if (a != 0) {
            char *d;
            func_800232A0((char *)g->p + 0x154, o);
            d = (char *)D_800B4D84;
            g->p->c = FIELD_AT(d, int, 0x6798);
            FIELD_AT(d, int, 0x44FC) = 0;
        } else {
            int t;
            FIELD_AT(o, int, 0x4500) = 1;
            func_800230E8((char *)g->p + 0x154, o);
            {
                Sub_80055330 *v = (Sub_80055330 *)((char *)g->p + 0x154);
                char *d = (char *)D_800B4D84;
                t = v->v;
                v->v = 0;
                if (FIELD_AT(d, int, 0x6798) < t) {
                    FIELD_AT(d, int, 0x6798) = t;
                }
            }
        }
    } else if (a == 0) {
        func_800232A0((char *)D_800A4578.p + 0x154, 0);
    }
}

//// func_80055624
extern "C" void func_80055624(void *x, int b)
{
    if (b) {
        if (FIELD_AT((char *)D_800B4D84, char *, 0x44F4) == 0) {
            char *h = (char *)__builtin_new(0x20);
            FIELD_AT(h, void *, 0x8) = h + 0xC;
            FIELD_AT(h, void *, 0x0) = h + 0xC;
            func_800198E0(h + 0xC, 4, 0);
            FIELD_AT(h, int, 0x4) = 0;
            FIELD_AT((char *)D_800B4D84, char *, 0x44F4) = h;
        }
        if (!func_80019C24(FIELD_AT((char *)D_800B4D84, char *, 0x44F4) ? *FIELD_AT((char *)D_800B4D84, void **, 0x44F4) : 0, x)) {
            List *l;
            char *p = (char *)func_8001CA10(0x14);
            FIELD_AT(p, void *, 0x0) = D_80010178;
            FIELD_AT(p, int, 0x4) = 0;
            FIELD_AT(p, void *, 0x0) = D_80010300;
            FIELD_AT(p, short, 0x8) = 2;
            FIELD_AT(p, short, 0xA) = 8;
            FIELD_AT(p, int, 0x10) = 0;
            FIELD_AT(p, int, 0xC) = 0;
            FIELD_AT(p, void *, 0x0) = D_800102D0;
            func_8001EFE4(D_800B4D84, p);
            l = FIELD_AT((char *)D_800B4D84, char *, 0x44F4) ? *FIELD_AT((char *)D_800B4D84, List **, 0x44F4) : 0;
            func_80019A6C(l, (int)x, l->count);
            FIELD_AT((char *)D_800B4D84, int, 0x44F0)++;
        }
    } else {
        char *h = FIELD_AT((char *)D_800B4D84, char *, 0x44F4);
        if (h != 0 && func_80019C24(*(void **)h, x)) {
            func_80055F0C(D_800B4D84, x);
        }
    }
}

//// func_80055F98
extern "C" int func_80055F98(char *x)
{
    char *h = (char *)&D_800AE620;
    int r;
    if ((h ? *(List **)h : 0)->count == 0) {
        return 0;
    }
    r = 1;
    D_800B4D98 = r;
    D_800B4D94 = r;
    while (x != 0 && D_800B4D90 == 0) {
        if ((h ? *(List **)h : 0)->count > 0) {
            char *v = h ? h + 8 : 0;
            List *l = v ? *(List **)v : 0;
            char *e = l->count ? ((char **)*(void **)l)[l->count - 1] : 0;
            VObj0 *o = e ? *(VObj0 **)(e + 0x50) : 0;
            r = (r & o->v02(x)) != 0;
        }
        x = FIELD_AT(x, char *, 0x4);
        D_800B4D94 = 0;
    }
    D_800B4D98 = 0;
    D_800B4D90 = 0;
    return r;
}
//// func_80056B44
extern "C" int func_80056B44(void *self, int b)
{
    VEnt2_B *vt;
    VEnt2_B *e;
    if (b == 0) {
        return 0;
    }
    vt = *(VEnt2_B **)(self ? *(char **)((char *)self + 0x50) : 0);
    e = &vt[2];
    return e->pfn((self ? *(char **)((char *)self + 0x50) : 0) + vt[2].delta, b);
}
//// func_8005717C
extern "C" void func_8005717C(void *self, int a, int b)
{
    FIELD_AT(self, int, 0x9C) = a / 2;
    FIELD_AT(self, int, 0xA8) = b;
    FIELD_AT(self, int, 0xA4) = 0;
    if (FIELD_AT(self, int, 0x8) == 0) {
        func_8002B174(D_800A4578.p, self, -1);
        ((VObj<0x2C> *)self)->v27();
        func_8002A210(self);
        func_8005D9D4((char *)self + 0x5C, FIELD_AT(self, int, 0xA0) != 0 ? 0 : 0xFF);
    }
}

//// func_800576F8
extern "C" SV2R_800576F8 func_800576F8(char *h)
{
    unsigned int i;
    unsigned int m;
    int n;
    char *v = h ? h + 8 : 0;
    m = func_8005F87C(func_80019F64(v ? *(void **)v : 0, 0));
    for (i = 1; i < (unsigned int)(h ? *(List **)h : 0)->count; i++) {
        char *w = h ? h + 8 : 0;
        unsigned int t = func_8005F87C(func_80019F64(w ? *(void **)w : 0, i));
        if (m < t) {
            m = t;
        }
    }
    return SV2R_800576F8(D_800B4DA0 + (D_800B4D9E + m), D_800B4DA4 + D_800B4D9C * (D_800B4DA8 < (h ? *(List **)h : 0)->count ? D_800B4DA8 : (h ? *(List **)h : 0)->count));
}
//// func_80057F20
static inline List *hlist_B(char *h)
{
    return h ? *(List **)h : 0;
}

static inline void *hlist8_B(char *h)
{
    char *v = h ? h + 8 : 0;
    return v ? *(void **)v : 0;
}

extern "C" void func_80057F20(void *self, short b)
{
    int i;
    FIELD_AT(self, short, 0x13C) = b;
    func_80059F0C((char *)self + 0x5C, b & 0xFF);
    func_8005A784((char *)self + 0xC8, b & 0xFF);
    for (i = hlist_B((char *)self + 0x110)->count - 1; i >= 0; i--) {
        ((VObj<0x2C> *)func_80019F64(hlist8_B((char *)self + 0x110), i))->v28(b & 0xFF);
    }
}

//// func_80058270
extern "C" int func_80058270(void *self, int d)
{
    int n = FIELD_AT(self, int, 0x138) + d;
    if (n >= 0 && (unsigned int)n < FIELD_AT(self, unsigned int, 0x130) && FIELD_AT(self, int, 0x140) == 0) {
        int m = -d * D_800B4DA6;
        if (D_800B4DA6 < FIELD_AT(self, int, 0x150)) {
            FIELD_AT(D_800A4578.p, short, 0x1A4) = 1;
            FIELD_AT(self, int, 0x150) -= D_800B4DA6;
            func_8005BF04((char *)self + 0x5C, 0, m);
        } else {
            int s = 1;
            int lim;
            int k;
            if (d < 0) {
                s = -1;
                FIELD_AT(self, int, 0x138) += s;
                lim = 1;
                k = FIELD_AT(self, int, 0x138) - 1;
            } else {
                FIELD_AT(self, int, 0x138) += s;
                lim = D_800B4DAA;
                k = FIELD_AT(self, int, 0x130) - (D_800B4DA8 - D_800B4DAA) - FIELD_AT(self, int, 0x138);
            }
            if (FIELD_AT(self, int, 0x134) == lim && k >= 0) {
                func_8005BF04((char *)self + 0x5C, 0, m);
                FIELD_AT(self, int, 0x150) = FIELD_AT(self, int, 0x150) + 13 - D_800B4DA6;
            } else {
                FIELD_AT(self, int, 0x134) += s;
                if (FIELD_AT(self, int, 0x150) > 0) {
                    func_8005BF04((char *)self + 0x5C, 0, -s * FIELD_AT(self, int, 0x150));
                    FIELD_AT(self, int, 0x150) = 0;
                }
            }
            func_80059C54((char *)self + 0x5C, FIELD_AT(self, int, 0x138) - s, 0);
            ((VObj<0x2C> *)self)->v14();
            func_8008EF40(8);
        }
    }
    return FIELD_AT(self, int, 0x138);
}
//// func_8005854C
extern "C" void func_8005854C(void *self, int a, void *v, int d)
{
    if (FIELD_AT(self, int, 0x140) != 0) {
        ((VObj<8> *)((char *)self + 0x50))->v02();
    }
    FIELD_AT(self, short, 0x144) = a;
    if ((unsigned short)a) {
        FIELD_AT(self, SV_80054F30, 0x148) = *(SV_80054F30 *)v;
        FIELD_AT(self, short, 0x146) = d;
    }
}

//// func_80058728
extern "C" void func_80058728(void *self)
{
    Iter_B *it;
    VObj<0x2C> *p;
    if (FIELD_AT(self, unsigned short, 0x144) != 0 && FIELD_AT(self, int, 0x140) == 0) {
        func_8005388C(self ? (char *)self + 0x50 : 0, FIELD_AT(self, unsigned short, 0x144));
        FIELD_AT(self, int, 0x140) = 1;
        return;
    }
    FIELD_AT(self, int, 0x20) = 0;
    it = (Iter_B *)((char *)self + 0x30);
    it->i = 0;
    for (p = (VObj<0x2C> *)iter_next_B(it); p != 0; p = (VObj<0x2C> *)iter_next_B(it)) {
        p->v04();
    }
}

//// func_80058B98
extern "C" int func_80058B98(void *self)
{
    int r = 1;
    if (D_800B4DA6 < FIELD_AT(self, int, 0x150)) {
        func_8005BF04((char *)self + 0x5C, 0, FIELD_AT(self, int, 0x154));
        FIELD_AT(self, int, 0x150) -= D_800B4DA6;
    } else {
        if (FIELD_AT(self, int, 0x150) > 0) {
            func_8005BF04((char *)self + 0x5C, 0, FIELD_AT(self, int, 0x154) > 0 ? FIELD_AT(self, int, 0x150) : -FIELD_AT(self, int, 0x150));
            FIELD_AT(self, int, 0x150) = 0;
        }
        FIELD_AT(self, int, 0x140) = 0;
        r = 0;
    }
    ((VObj<0x2C> *)self)->v14();
    return r;
}

//// func_800594A8
extern "C" void *func_800594A8(void *self, int a, int b, int c, int d, int e, int f)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, void *, 0x0) = D_800111BC;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, short, 0x8) = 0;
    FIELD_AT(self, void *, 0x0) = D_80014278;
    FIELD_AT(self, short, 0xA) = f;
    func_80098E10((char *)self + 0xC);
    func_80098E10((char *)self + 0x1C);
    func_80059800(self, a, b, c, d);
    func_80059888(self, e);
    FIELD_AT(self, short, 0xA) = f;
    func_80059790(self);
    return self;
}

//// func_800595F8
extern "C" void *func_800595F8(void *self)
{
    char *p = (char *)__builtin_new(0x2C);
    B16_B *d;
    B16_B *s;
    int n;
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, void *, 0x0) = D_800111BC;
    FIELD_AT(p, int, 0x4) = FIELD_AT(self, int, 0x4);
    FIELD_AT(p, short, 0x8) = FIELD_AT(self, short, 0x8);
    FIELD_AT(p, void *, 0x0) = D_80014278;
    FIELD_AT(p, short, 0xA) = FIELD_AT(self, short, 0xA);
    d = (B16_B *)(p + 0xC);
    s = (B16_B *)((char *)self + 0xC);
    n = 1;
    do {
        *d++ = *s++;
    } while (--n != -1);
    return p;
}
//// func_80059800
extern "C" void func_80059800(void *self, int a, int b, int c, int d)
{
    S_80059800 *s = (S_80059800 *)self;
    E16_80059800 *e;
    if (s->state == 1) {
        int i = D_800B4CF0.value;
        s->e[i] = s->e[i ^ 1];
    }
    e = &s->e[D_800B4CF0.value];
    e->x = a;
    e->y = b;
    e->z = c;
    e->w = d;
    s->state = 2;
}

//// func_8005B450
extern "C" void func_8005B450(void *self, unsigned char *c)
{
    int i = D_800B4CF0.value;
    unsigned int k;
    unsigned char r = c[5];
    unsigned char g = c[6];
    unsigned char bl = c[7];
    for (k = 0; k < FIELD_AT(self, unsigned int, 0x18); k += 2) {
        FIELD_AT(self, TILE_B *, 0x14)[k + i].r0 = r;
        FIELD_AT(self, TILE_B *, 0x14)[k + i].g0 = g;
        FIELD_AT(self, TILE_B *, 0x14)[k + i].b0 = bl;
    }
    func_8005F1D8(self);
}

//// func_8005B4D8
extern "C" void func_8005B4D8(void *self, int dx, int dy)
{
    unsigned int k;
    int i = D_800B4CF0.value;
    for (k = 0; k < FIELD_AT(self, unsigned int, 0x18); k += 2) {
        FIELD_AT(self, TILE_B *, 0x14)[k + i].x0 += dx;
        FIELD_AT(self, TILE_B *, 0x14)[k + i].y0 += dy;
    }
    func_8005F1D8(self);
}

//// func_8005B5B4
extern "C" void *func_8005B5B4(void *self)
{
    char *p = (char *)__builtin_new(0x24);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, void *, 0x0) = D_800111BC;
    FIELD_AT(p, int, 0x4) = FIELD_AT(self, int, 0x4);
    FIELD_AT(p, short, 0x8) = FIELD_AT(self, short, 0x8);
    FIELD_AT(p, void *, 0x0) = D_80014BD0;
    FIELD_AT(p, short, 0xA) = FIELD_AT(self, short, 0xA);
    FIELD_AT(p, void *, 0x0) = D_80014548;
    FIELD_AT(p, int, 0xC) = FIELD_AT(self, int, 0xC);
    FIELD_AT(p, int, 0x10) = FIELD_AT(self, int, 0x10);
    FIELD_AT(p, int, 0x14) = FIELD_AT(self, int, 0x14);
    FIELD_AT(p, int, 0x18) = FIELD_AT(self, int, 0x18);
    FIELD_AT(p, int, 0x1C) = FIELD_AT(self, int, 0x1C);
    FIELD_AT(p, int, 0x20) = FIELD_AT(self, int, 0x20);
    return p;
}

//// func_8005BF04
extern "C" void func_8005BF04(void *self, int a, int b)
{
    VEnt3_B *vt = FIELD_AT(self, VEnt3_B *, 0x2C);
    vt[7].pfn((char *)self + vt[7].delta, FIELD_AT(self, short, 0xC) + a, FIELD_AT(self, short, 0xE) + b);
}

//// func_8005C088
extern "C" void func_8005C088(void *self, int b, int c)
{
    unsigned int n = (FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count;
    if (n != 0) {
        unsigned int i;
        void *pool;
        char *v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
        char *e = (char *)func_80019F64(v ? *(void **)v : 0, 0);
        func_8002DC34((void *)b, (int)e, 0);
        FIELD_AT(e, int, 0x4) = 0;
        pool = func_8005F50C((Pool_8005F50C *)__builtin_new(0x14), (int)e, 1, n);
        for (i = 1; i < n; i++) {
            char *w = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
            char *f = (char *)func_80019F64(w ? *(void **)w : 0, i);
            func_8002DC34((void *)b, (int)f, 0);
            FIELD_AT(f, int, 0x4) = 0;
            func_8005F704((Arr_8005F704 *)pool, i, (int)f);
        }
        func_80019D40(FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0);
    }
}

//// func_8005C26C
extern "C" void *func_8005C26C(void *self, void *b, int c)
{
    char *r;
    func_80038654(self, b, c);
    r = (char *)self;
    FIELD_AT(r, void *, 0x0) = D_800145B0;
    FIELD_AT(r, void *, 0x30) = b;
    FIELD_AT(b, void *, 0x30) = r + 0x10;
    return r;
}
//// func_8005C380
extern "C" void func_8005C380(void *self)
{
    char *o = FIELD_AT(self, char *, 0x30);
    VEnt3_B *vt = FIELD_AT(o, VEnt3_B *, 0x2C);
    VEnt3_B *e = &vt[13];
    char *t = o + e->delta;
    ((int (*)(void *))e->pfn)(t);
}
//// func_8005C968
extern "C" void *func_8005C968(void *self)
{
    char *p = (char *)__builtin_new(0x58);
    E36_8005C968 *d;
    E36_8005C968 *s;
    int n;
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, void *, 0x0) = D_800111BC;
    FIELD_AT(p, int, 0x4) = FIELD_AT(self, int, 0x4);
    FIELD_AT(p, short, 0x8) = FIELD_AT(self, short, 0x8);
    FIELD_AT(p, void *, 0x0) = D_80014BD0;
    FIELD_AT(p, short, 0xA) = FIELD_AT(self, short, 0xA);
    FIELD_AT(p, void *, 0x0) = D_800147A0;
    FIELD_AT(p, int, 0xC) = FIELD_AT(self, int, 0xC);
    d = (E36_8005C968 *)(p + 0x10);
    s = (E36_8005C968 *)((char *)self + 0x10);
    n = 1;
    do {
        *d++ = *s++;
    } while (--n != -1);
    return p;
}

//// func_8005DFE8
extern "C" void *func_8005DFE8(void *self)
{
    char *p = (char *)__builtin_new(0x48);
    E12_8005DFE8 *d;
    E12_8005DFE8 *s;
    B16_B *d2;
    B16_B *s2;
    int n;
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, void *, 0x0) = D_800111BC;
    FIELD_AT(p, int, 0x4) = FIELD_AT(self, int, 0x4);
    FIELD_AT(p, short, 0x8) = FIELD_AT(self, short, 0x8);
    FIELD_AT(p, void *, 0x0) = D_80014BD0;
    FIELD_AT(p, short, 0xA) = FIELD_AT(self, short, 0xA);
    FIELD_AT(p, void *, 0x0) = D_80014B00;
    FIELD_AT(p, int, 0xC) = FIELD_AT(self, int, 0xC);
    d = (E12_8005DFE8 *)(p + 0x10);
    s = (E12_8005DFE8 *)((char *)self + 0x10);
    n = 1;
    do {
        *d++ = *s++;
    } while (--n != -1);
    d2 = (B16_B *)(p + 0x28);
    s2 = (B16_B *)((char *)self + 0x28);
    n = 1;
    do {
        *d2++ = *s2++;
    } while (--n != -1);
    return p;
}

//// func_80061758
extern "C" int func_80061758(S_800615B4 *self, unsigned char *r)
{
    int flag = 1;
    unsigned int i;
    int n;
    int found;
    for (i = 0; i < 8; i++) {
        if (!flag) {
            break;
        }
        if (r[0x1B] == D_800B4E24[i]) {
            flag = 0;
        }
    }
    if (r[0x1B] == 0x71) {
        if (FIELD_AT(self, signed char, 0x1FD) == 0) {
            FIELD_AT(self, signed char, 0x1FD) = 1;
        }
        return 0;
    }
    if (r[0x1B] == 0x72) {
        FIELD_AT(self, signed char, 0x1FD) = 2;
        return 0;
    }
    if (!flag) {
        for (n = 0; n < 8; n++) {
            if (FIELD_AT(&self->f[n], unsigned char, 0x18) == 0) {
                break;
            }
        }
        self->f[n] = *(E94_80061AAC *)r;
        return n;
    }
    n = func_800619F4((Obj_800619F4 *)self);
    found = 0;
    switch (r[0x18]) {
    case 1:
    case 2:
    case 3:
        if ((FIELD_AT(r, unsigned short, 0xC) & 0xFF00) == 0xFF00) {
            FIELD_AT(r, unsigned short, 0xC) &= 0xFF;
            func_8008655C((short *)(r + 0x80));
            r[0xE] &= 0xF;
            func_8006228C(self, r);
        }
        break;
    case 4: {
        unsigned int j = 0;
        char *p = (char *)self;
    loop:
        if (j < (unsigned int)n) {
            if ((unsigned char)p[0x23F] == r[0x1B]) {
                unsigned char *q = (unsigned char *)p + 0x2A4;
                found = 1;
                n = -99;
                if (q[0xC] < 99) {
                    q[0xC] += r[0x8C];
                    n = j;
                    if (q[0xC] >= 100) {
                        q[0xC] = 99;
                    }
                }
            }
            p += 0x94;
            j++;
            if (!found) {
                goto loop;
            }
        }
        break;
    }
    }
    if (found) {
        return n;
    }
    if (n >= 0x30) {
        return -1;
    }
    self->e[n] = *(E94_80061AAC *)r;
    return n;
}
//// func_80061A20
extern "C" int func_80061A20(Obj_800619F4 *self, unsigned char *b)
{
    int found = 0;
    if (b[0x18] == 4) {
        unsigned int n = func_800619F4(self);
        unsigned int i = 0;
    loop:
        if (i < n) {
            if ((unsigned char)self->e[i].pad[3] == b[0x1B]) {
                found = 1;
            }
            i++;
            if (!found) {
                goto loop;
            }
        }
    }
    return found;
}
//// func_8006237C
extern "C" void func_8006237C(void *self, unsigned char *a, B8_B *b)
{
    int r = rand();
    int k = (r >> 8) & 0xF;
    int m;
    if (k >= 15) {
        a[0xE] |= 0x80;
    } else if (k >= 14) {
        a[0xE] |= 0x40;
    } else if (k >= 12) {
        a[0xE] |= 0x20;
    } else if (((r >> 8) & 0xF) >= 8) {
        a[0xE] |= 0x10;
    }
    m = r & 7;
    if (((r >> 4) & 3) == 0) {
        m = 8;
    } else {
        FIELD_AT(a, unsigned short, 0xC) |= 0x8000 >> m;
        a[0] = a[0] * 5 / 4;
    }
    *b = *func_80053BC0(&D_800AE86C[m]);
}

//// func_800624A4
extern "C" void func_800624A4(void *self, char *a, B8_B *b)
{
    int r = rand();
    int k = (r >> 8) & 3;
    int s = ((r >> 8) & 1) ? k - 1 : k + 1;
    FIELD_AT(a, short, 0x88) = 0x8000 >> s;
    if ((r >> 4) & 1) {
        ((short *)(a + 0x80))[r & 3] = 0x8000 >> k;
    }
    *b = *func_80053BC0(&D_800AE86C[k]);
}

//// func_80063584
extern "C" int func_80063584(void *self, char *b)
{
    if (!func_800557A0(self)) {
        unsigned short f = FIELD_AT(b, unsigned short, 0x1A);
        if (!(f & 0x10)) {
            func_8005549C(1, self, 0, -1);
        } else if (!(f & 0x40)) {
            func_8005549C(2, self, 0, -1);
        }
    }
    return 1;
}
//// func_800635FC
extern "C" int func_800635FC(void *self, char *b)
{
    int r = 0;
    unsigned short f;
    func_8001FC78(b, 0, 0);
    if (func_8005618C(b) != 0 || (FIELD_AT(self, char *, 0x3C) != 0 && func_80053880(FIELD_AT(self, char *, 0x3C) + 0x50) == 0)) {
        r = 1;
    }
    if (r) {
        return 1;
    }
    FIELD_AT(D_800A4578.p, short, 0x1A4) = 3;
    f = FIELD_AT(b, unsigned short, 0x18);
    if (f & 0x4000) {
        D_800B4D90 = 1;
        ((VObj<0x18> *)self)->v02();
        return 1;
    }
    if (f & 0x10) {
        if (FIELD_AT(self, void *, 0x3C) != 0) {
            FIELD_AT(self, int, 0x20) = func_80058404(FIELD_AT(self, void *, 0x3C), -1);
            return 1;
        }
    }
    if (f & 0x40) {
        if (FIELD_AT(self, void *, 0x3C) != 0) {
            FIELD_AT(self, int, 0x20) = func_80058404(FIELD_AT(self, void *, 0x3C), 1);
        }
    }
    return 1;
}
//// func_80063BE4
extern "C" void func_80063BE4(void *self)
{
    char *h = (char *)self + 0x30;
    int i;
    for (i = (h ? FIELD_AT(self, List *, 0x30) : 0)->count - 1; i >= 0; i--) {
        char *v = h ? (char *)self + 0x38 : 0;
        void **o = (void **)func_80019F64(v ? *(void **)v : 0, i);
        if (o != 0) {
            ((VObj0 *)*o)->v00(3);
        }
    }
    func_80019D40(h ? FIELD_AT(self, List *, 0x30) : 0);
}

//// func_80063CA4
extern "C" int func_80063CA4(void *self)
{
    Iter_B *it = (Iter_B *)((char *)self + 0x30);
    void *p;
    it->i = 0;
    for (p = iter_next_B(it); p != 0; p = iter_next_B(it)) {
        func_80063F3C(p);
    }
    return 1;
}

//// func_80063D64
extern "C" void func_80063D64(void *self)
{
    Iter_B *it = (Iter_B *)((char *)self + 0x30);
    VObj<0x2C> *p;
    it->i = 0;
    for (p = (VObj<0x2C> *)iter_next_B(it); p != 0; p = (VObj<0x2C> *)iter_next_B(it)) {
        p->v04();
    }
    func_8002A210(self);
    func_8005388C(self ? (char *)self + 0x50 : 0, -1);
}
//// func_80063F3C
extern "C" void func_80063F3C(void *self)
{
    unsigned short v = (FIELD_AT(self, unsigned short, 0x3A) + 1) & 7;
    FIELD_AT(self, unsigned short, 0x3A) = v;
    if ((v & 1) == 1) {
        int d = v < 7 ? 1 : -3;
        int x, y;
        switch (FIELD_AT(self, unsigned short, 0x38)) {
        case 2:
            x = d;
            y = 0;
            break;
        case 3:
            x = 0;
            y = -d;
            break;
        case 4:
            x = 0;
            y = d;
            break;
        default:
            x = -d;
            y = 0;
            break;
        }
        ((VObj<0x2C> *)self)->v29(x, y);
    }
}

//// func_80064884
extern "C" void func_80064884(void *self, int a, int b)
{
    if (FIELD_AT(self, int, 0x48) == b && FIELD_AT(self, int, 0x44) == a) {
        return;
    }
    if (a < b) {
        return;
    }
    FIELD_AT(self, int, 0x44) = a;
    FIELD_AT(self, int, 0x48) = b;
    if (FIELD_AT(self, int, 0x44) < FIELD_AT(self, int, 0x4C)) {
        FIELD_AT(self, int, 0x4C) = FIELD_AT(self, int, 0x44);
    } else if (FIELD_AT(self, int, 0x4C) < b) {
        FIELD_AT(self, int, 0x4C) = b;
    }
}
//// func_80065A00
extern "C" void *func_80065A00(void *self)
{
    char *r;
    int *v;
    func_80039A14(self);
    FIELD_AT(self, void *, 0x0) = D_80015384;
    func_8003A754((char *)self + 0x48, 0x1000);
    v = (int *)((char *)self + 0x68);
    v[0] = 0x1000;
    v[1] = 0x1000;
    v[2] = 0x1000;
    v[3] = 0;
    func_8003A754((char *)self + 0x78, 0x1000);
    func_8003A754((char *)self + 0x98, 0x1000);
    func_8001AA28((char *)self + 0x78, 0x10);
    r = (char *)self;
    FIELD_AT(r, int, 0xB8) = 0x808080;
    FIELD_AT(r, int, 0x44) = 1;
    FIELD_AT(r, int, 0xBC) = 1;
    return r;
}

//// func_80065C64
extern "C" void func_80065C64(void *self, int b)
{
    MATRIX_B m1;
    MATRIX_B m2;
    func_8003B35C(&m1, (char *)self + 0x78, b);
    SetLightMatrix(&m1);
    func_8003B3EC(&m2, (char *)self + 0x48, b);
    m1 = m2;
    SetRotMatrix(ScaleMatrix(&m1, (char *)self + 0x68));
    SetTransMatrix(&m1);
}

//// func_80066A54
extern "C" int func_80066A54(void *self)
{
    unsigned char *p = FIELD_AT(self, unsigned char *, 0x2C);
    char *o;
    if (p[0] != 'b' || p[1] != 'd' || p[2] != 't' || p[3] != '0') {
        func_80066C7C(self);
        return 0;
    }
    if (p[8] != 1) {
        return 0;
    }
    o = FIELD_AT(self, char *, 0x48);
    FIELD_AT(o, unsigned char *, 0x41C) = p + FIELD_AT(p, int, 0xC);
    FIELD_AT(o, int, 0x420) = FIELD_AT(p, int, 0x10);
    return 1;
}

//// func_80066BC0
extern "C" int func_80066BC0(void *self)
{
    unsigned char *p = FIELD_AT(self, unsigned char *, 0x2C);
    char *o = FIELD_AT(self, char *, 0x48);
    if (p[0] != 'b' || p[1] != 'g' || p[2] != 'm' || p[3] != '0') {
        func_80066C7C(self);
        return 0;
    }
    if (p[8] != 2) {
        return 0;
    }
    FIELD_AT(o, unsigned char *, 0x51C) = p + FIELD_AT(p, int, 0xC);
    FIELD_AT(o, int, 0x520) = FIELD_AT(p, int, 0x10);
    FIELD_AT(o, unsigned char *, 0x524) = p + FIELD_AT(p, int, 0x14);
    FIELD_AT(o, int, 0x528) = FIELD_AT(p, int, 0x18);
    return 1;
}

//// func_8006AF94
extern "C" void func_8006AF94(void *self)
{
    if (FIELD_AT(self, int, 0x26C) != 0) {
        FIELD_AT(self, int, 0x11C) = FIELD_AT(self, int, 0x28C);
        func_80099C80(FIELD_AT(self, int, 0x28C));
        FIELD_AT(self, V3s_B, 0x7C) = FIELD_AT(self, V3s_B, 0x290);
        FIELD_AT(self, V3i_B, 0x84) = FIELD_AT(self, V3i_B, 0x27C);
        ((VObj<0x2C> *)self)->v33((char *)self + 0x7C, (char *)self + 0x84);
        FIELD_AT(self, int, 0x26C) = 0;
    }
}

//// func_8006D290
extern "C" SV4_B func_8006D290(void *self, int *v)
{
    SV4_B t;
    int a = ratan2(v[0], v[2]) - 0x800;
    int r = SquareRoot0(v[0] * v[0] + v[2] * v[2]);
    t.x = ratan2(v[1], r);
    t.y = a;
    t.z = 0;
    t.w = 0;
    return t;
}

//// func_8006FF50
extern "C" void func_8006FF50(void *self, int a, int b, void *c)
{
    void *q;
    FIELD_AT(self, void *, 0x68) = c;
    q = func_800758F8(__builtin_new(0x1C8), 1, D_800B4C18.p, self ? (char *)self + 0x40 : 0);
    FIELD_AT(self, void *, 0x64) = q;
    func_8001E848(D_800B4C18.p, q);
    func_8007669C(FIELD_AT(self, void *, 0x64), a, b);
}

//// func_80072534
extern "C" void func_80072534(void *self, char *m)
{
    unsigned short t = FIELD_AT(m, unsigned short, 0xA);
    if (t == 2) {
        int v = FIELD_AT(m, int, 0x10);
        if (v != 0 && v == 2) {
            FIELD_AT(self, short, 0x220) = v;
            FIELD_AT(self, int, 0xF8) = 0;
            FIELD_AT(self, unsigned char, 0x120)++;
        }
    } else if (t == 0xC) {
        int v = FIELD_AT(m, int, 0x10);
        if (v == 0x64) {
            func_80071C78(self, self);
        } else if (v == 0x65) {
            func_80071D90(self, self, 1);
        }
    }
    func_800852A0(self, (int)m);
}

//// func_800752B8
extern "C" void *func_800752B8(void *self)
{
    LList_B *l = (LList_B *)self;
    LNode_B *n;
    if (l->head == l->cur) {
        return func_800751AC(l);
    }
    if (at_end_B(l)) {
        return func_80075220(l);
    } else {
        n = l->cur;
        l->cur = (LNode_B *)func_80074EA4((Node_80074EA4 *)n);
        l->count--;
        return n;
    }
}

//// func_80075358
extern "C" void *func_80075358(LList_B *l)
{
    if (at_end_B(l)) {
        return 0;
    }
    if (l->head != 0 && !at_end_B(l)) {
        l->cur = l->cur->next;
    }
    return func_800752B8(l);
}

//// func_80075788
extern "C" void *func_80075788(void *self, int a, int b, int c, int d)
{
    char *r;
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800167F8;
    FIELD_AT(self, int, 0x8) = a;
    if (d == 0) {
        FIELD_AT(self, void *, 0xC) = func_800A0D2C(a);
        FIELD_AT(self, int, 0x10) = 1;
    } else {
        FIELD_AT(self, void *, 0xC) = 0;
        FIELD_AT(self, int, 0x10) = 0;
    }
    r = (char *)self;
    FIELD_AT(r, int, 0x14) = b;
    FIELD_AT(r, int, 0x18) = 0;
    FIELD_AT(r, int, 0x1C) = d;
    FIELD_AT(r, int, 0x20) = c;
    return r;
}

//// func_80076CD0
extern "C" void func_80076CD0(void *self, int flags)
{
    char *b = (char *)self + 8;
    FIELD_AT(self, void *, 0x8) = D_80016820;
    FIELD_AT(self, void *, 0x0) = D_80016830;
    FIELD_AT(self, void *, 0xC) = D_80012104;
    FIELD_AT(self, void *, 0x8) = D_800120F4;
    FIELD_AT(self, void *, 0x0) = D_8001211C;
    FIELD_AT(b, void *, 0x4) = D_800101C0;
    FIELD_AT(self, void *, 0x8) = D_800101B0;
    func_800198AC(b, 0);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

//// func_8007B36C
extern "C" int func_8007B36C(void *self, int a, int i)
{
    int v;
    if (a == 1) {
        v = D_800AFA64[i];
        if (v != 0) {
            D_800AFA64[i] = 0;
            FIELD_AT(self, int, 0x14)--;
            return v;
        }
    } else if (a == 2) {
        v = D_800AFA58[i];
        if (v != 0) {
            D_800AFA58[i] = 0;
            FIELD_AT(self, int, 0x18)--;
            return v;
        }
    } else {
        return 0;
    }
    return 0;
}

//// func_80080350
extern "C" void func_80080350(void *self, int x)
{
    unsigned int t = D_800A4534.ticks;
    char *n = FIELD_AT(self, char *, 0x4);
    while (n != 0) {
        if (FIELD_AT(n, int, 0xC) == x && !(t < FIELD_AT(n, unsigned int, 0x8))) {
            func_8001A744(self, n);
            FIELD_AT(n, int, 0x4) = 0;
            ((VObj0 *)n)->v00(3);
            return;
        }
        n = FIELD_AT(n, char *, 0x4);
    }
}

//// func_80081260
extern "C" void func_80081260(char *self, char *p, char *q, int r, int s, int t)
{
    B4_80081260 *e = (B4_80081260 *)(self + 0x3B0);
    int k = (FIELD_AT(p, signed char, 0x4BC) << 4) | 3;
    int m = q ? FIELD_AT(q, signed char, 0x4BC) : 0xFF;
    int i;
    if (s) {
        r |= 0x80;
    }
    for (i = 31; i > 0; i--) {
        e[i] = e[i - 1];
    }
    e[0].a = k;
    e[0].b = m;
    e[0].c = r;
    e[0].d = t != 0;
}

//// func_80085578
extern "C" void func_80085578(void *self, int a, int b, int c, int d, int e)
{
    void *p;
    FIELD_AT(self, char, 0x4E0) = 1;
    {
        V4_80085578 v(a, b, c, 0);
        p = FIELD_AT(self, void *, 0x1B8);
        FIELD_AT(p, V4_80085578, 0x34) = v;
        func_80039DD8(p);
        FIELD_AT(self, int, 0x108) = v.y;
    }
    func_80042D3C(self);
    func_800435AC(self, d, e);
}
