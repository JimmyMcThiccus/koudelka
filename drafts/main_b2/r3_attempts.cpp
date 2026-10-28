/* main_b2 round 3: attempts that do not match yet. Not built. See README.md. */

//// func_8006C9F8
EXTERN_C void func_8006C9F8(void *self, int b)
{
    char tmp[8];
    FIELD_AT(self, void *, 0) = D_80015E5C;
    if (FIELD_AT(self, int, 0x1C) == 0) {
        func_8006B7B8(D_800B4ED8_a[0]);
    }
    if (FIELD_AT(self, int, 8) != 0xCD) {
        func_800BE09C(tmp);
        func_800BE18C(tmp, (char *)D_800B4ED8_a[0] + 0x2A0);
    }
    func_8001D024(self, b);
}

//// func_80075788
EXTERN_C void *func_80075788(void *self_, int a, int b, int c, int d)
{
    char *self = (char *)self_;
    FIELD_AT(self, void *, 0) = D_80010178;
    FIELD_AT(self, int, 4) = 0;
    FIELD_AT(self, void *, 0) = D_800167F8;
    FIELD_AT(self, int, 8) = a;
    if (d == 0) {
        FIELD_AT(self, void *, 0xC) = func_800A0D2C(0);
        FIELD_AT(self, int, 0x10) = 1;
    } else {
        FIELD_AT(self, int, 0xC) = 0;
        FIELD_AT(self, int, 0x10) = 0;
    }
    FIELD_AT(self, int, 0x14) = b;
    FIELD_AT(self, int, 0x18) = 0;
    FIELD_AT(self, int, 0x1C) = d;
    FIELD_AT(self, int, 0x20) = c;
    return self;
}

//// func_80076CD0
EXTERN_C void func_80076CD0(void *self_, int flag)
{
    char *self = (char *)self_;
    char *b = self + 8;
    FIELD_AT(self, void *, 0xC) = D_80012104;
    FIELD_AT(self, void *, 8) = D_80016820;
    FIELD_AT(self, void *, 0) = D_80016830;
    FIELD_AT(self, void *, 8) = D_800120F4;
    FIELD_AT(self, void *, 0) = D_8001211C;
    FIELD_AT(b, void *, 4) = D_800101C0;
    FIELD_AT(self, void *, 8) = D_800101B0;
    func_800198AC(b, 0);
    if (flag & 1) {
        __builtin_delete(self);
    }
}

//// func_8007E5B0
EXTERN_C void func_8007E5B0(void *self)
{
    char *o = (char *)D_800B4DD0.p;
    FIELD_AT(self, int, 0x168) = FIELD_AT(o, int, 0x1BC);
    FIELD_AT(self, int, 0x16C) = FIELD_AT(o, int, 0x1C0);
    FIELD_AT(self, int, 0x178) = FIELD_AT(o, int, 0x204);
    FIELD_AT(self, int, 0x17C) = FIELD_AT(o, int, 0x208);
    char *o2 = (char *)D_800B4DD0.p;
    FIELD_AT(self, int, 0x170) = FIELD_AT(o, short, 0x1FE);
    FIELD_AT(self, int, 0x174) = FIELD_AT(o, short, 0x200);
    FIELD_AT(self, B16_C, 0x180) = B16_C(FIELD_AT(o, int, 0x1C8), FIELD_AT(o, int, 0x1CC), FIELD_AT(o, int, 0x1D0));
    FIELD_AT(self, int, 0x190) = FIELD_AT(o2, signed char, 0x1FC);
}

//// func_80085578
EXTERN_C void func_80085578(void *self, int a, int b, int c, int d, int e)
{
    FIELD_AT(self, char, 0x4E0) = 1;
    B16_B v;
    v.w[0] = a;
    v.w[1] = b;
    v.w[2] = c;
    v.w[3] = 0;
    FIELD_AT(FIELD_AT(self, char *, 0x1B8), B16_B, 0x34) = v;
    func_80039DD8(FIELD_AT(self, void *, 0x1B8));
    FIELD_AT(self, int, 0x108) = v.w[1];
    func_80042D3C(self);
    func_800435AC(self, d, e);
}

//// func_80085710
EXTERN_C void func_80085710(void *self, int a)
{
    int k = FIELD_AT(self, signed char, 0x4BC);
    char *o;
    if (k < 3) {
        o = (char *)FIELD_AT(D_800AF470.p, void *, 0x328);
        func_8007BB48(o ? o + 0xB8 : 0, 1 << k, a);
    } else {
        o = (char *)FIELD_AT(D_800AF470.p, void *, 0x328);
        func_8007BC3C(o ? o + 0xB8 : 0, 1 << (k - 3), a);
    }
}

//// func_8008687C
EXTERN_C void func_8008687C(char *self, int flag)
{
    Col_800899AC t3;
    Col_800899AC t2;
    Col_800899AC t1;
    if (flag) {
        func_800899AC(&t1, (Col_800899AC *)(self + 0x24), (signed char *)(self + 0x2C));
        func_800899AC(&t2, &t1, (signed char *)(self + 0x84));
    } else {
        func_800899AC(&t2, (Col_800899AC *)(self + 0x24), (signed char *)(self + 0x2C));
    }
    func_800899AC(&t3, &t2, (signed char *)(self + 0x34));
    FIELD_AT(self, int, 0x3C) = t3.w[0];
    FIELD_AT(self, int, 0x40) = t3.w[1];
    func_80089D80((unsigned char *)(self + 0x3C), 0xB4);
}

//// func_8006C95C
EXTERN_C void *func_8006C95C(void *self_, void *a, int b)
{
    char *self = (char *)self_;
    int kind = b;
    FIELD_AT(self, void *, 0) = D_80015E5C;
    FIELD_AT(self, int, 8) = kind;
    FIELD_AT(self, void *, 4) = a;
    unsigned t = D_800A4534.ticks;
    FIELD_AT(self, int, 0x14) = 0;
    FIELD_AT(self, unsigned, 0xC) = t;
    FIELD_AT(self, unsigned, 0x18) = t;
    switch (kind) {
    case 0xC9:
        FIELD_AT(self, int, 0x14) = 0x10;
        break;
    case 0xCA:
        FIELD_AT(self, int, 0x14) = 0x10;
        break;
    case 0xCB:
        FIELD_AT(self, int, 0x14) = 0x10;
        break;
    case 0xCC:
        FIELD_AT(self, int, 0x14) = 0x10;
        break;
    case 0xCD:
        FIELD_AT(self, int, 0x14) = 0xB4;
        break;
    }
    FIELD_AT(self, int, 0x10) = FIELD_AT(self, int, 0x14);
    FIELD_AT(self, int, 0x1C) = 1;
    return self;
}

//// func_8006CAF8
EXTERN_C int func_8006CAF8(void *self)
{
    int k = FIELD_AT(self, int, 8);
    bool r;
    switch (k) {
    case 0xC8:
        return 1;
    case 0xC9:
        r = !func_8006CBCC_b(self, 0xC9);
        break;
    case 0xCA:
        r = !func_8006CBCC_b(self, 0xCA);
        break;
    case 0xCB:
        r = !func_8006CD98_b(self, 0xCB);
        break;
    case 0xCC:
        r = !func_8006CD98_b(self, 0xCC);
        break;
    case 0xCD:
        r = !func_8006CF84_b(self, 0);
        break;
    default:
        return 0;
    }
    if (r) {
        FIELD_AT(self, int, 0x1C) = 0;
        return 1;
    }
    return 0;
}

//// func_80072534
EXTERN_C void func_80072534(void *self, void *m)
{
    int t = FIELD_AT(m, unsigned short, 0xA);
    if (t == 2) {
        int v = FIELD_AT(m, int, 0x10);
        if (v != 0) {
            if (v == t) {
                FIELD_AT(self, unsigned char, 0x120) += 1;
                FIELD_AT(self, short, 0x220) = v;
                FIELD_AT(self, int, 0xF8) = 0;
            }
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

//// func_8006B180
EXTERN_C void func_8006B180(void *self, int d)
{
    int s = FIELD_AT(self, unsigned short, 0x2A0) + d;
    if ((short)s > 0xF6E) {
        s = 0xF6E;
    }
    if ((short)s < 0xE42) {
        s = 0xE42;
    }
    FIELD_AT(self, short, 0x2A0) = s;
}

//// func_8008623C
struct MI_8008623C : VPad<0x400>, VObj<0x9C> {};
EXTERN_C void func_8008623C(void *self)
{
    ((MI_8008623C *)self)->v08();
}
//// func_8008640C
EXTERN_C void func_8008640C(char *self, int a, int c)
{
    FIELD_AT(self, char, 0x4BD) = a;
    func_800824C8(self + 0x2A4);
    func_800825FC((short *)(self + 0x2A4), c);
}


/* ---- round 3, second batch ---- */

//// func_8006D964
EXTERN_C int func_8006D964(void *self)
{
    int i;
    int r;
    if (FIELD_AT(self, int, 0xC) == 0xC8) {
        r = 1;
    } else {
        for (i = 0x41EB0; i > 0; i--) {
        }
        if (FIELD_AT(self, int, 0xC) != 0xC9) {
            r = 1;
        } else {
            FIELD_AT(self, int, 0x50) += 1;
            if (FIELD_AT(self, int, 0x50) >= 0x65) {
                FIELD_AT(self, int, 0x50) = 0;
            }
            if (FIELD_AT(self, int, 0x60) == 0) {
                if (FIELD_AT(self, unsigned, 0x4C) < 0x64) {
                    func_8006DA6C(self);
                }
                if (FIELD_AT(self, int, 0x4C) >= 0x64) {
                    func_8006DF68(self);
                }
                FIELD_AT(self, int, 0x4C) += 1;
                r = 0;
            } else {
                r = 0;
                if (!func_8006E234_b(self)) {
                    func_800B92E0(D_800D5D7C);
                    r = 1;
                }
            }
        }
    }
    return r;
}

//// func_8006EACC
EXTERN_C void func_8006EACC_def(void *self, void *m, int f) asm("func_8006EACC");

EXTERN_C void func_8006EACC_def(void *self, void *m, int f)
{
    int v;
    if (FIELD_AT(self, short, 8) == 1) {
        func_8006EF84(self);
    }
    v = FIELD_AT(m, unsigned short, 0x1C);
    if ((short)f != 0) {
        v = (v & 0xFF9F) | ((f & 3) << 5);
    }
    SetDrawMode((char *)self + (D_800B4CF0_w * 12 + 0xC), 0, 0, (short)v, 0);
    FIELD_AT(IDX40(self), short, 0x3A) = v;
    FIELD_AT(IDX40(self), unsigned short, 0x32) = FIELD_AT(FIELD_AT(m, void *, 0xC), unsigned short, 8);
    FIELD_AT(self, short, 8) = 2;
}

//// func_8006EE94
EXTERN_C void func_8006EE94(void *self)
{
    if (FIELD_AT(self, short, 8) != 0) {
        int i = D_800B4CF0_w;
        char *s = (char *)self + (i * 12 + 0xC);
        char *d = (char *)self + ((i ^ 1) * 12 + 0xC);
        char *s2;
        char *d2;
        *(W2_B *)(d + 4) = *(W2_B *)(s + 4);
        s2 = (char *)self + (i * 40 + 0x24);
        d2 = (char *)self + ((i ^ 1) * 40 + 0x24);
        *(B16_B *)(d2 + 4) = *(B16_B *)(s2 + 4);
        *(B16_B *)(d2 + 0x14) = *(B16_B *)(s2 + 0x14);
        FIELD_AT(d2, int, 0x24) = FIELD_AT(s2, int, 0x24);
    }
    func_80028184(self);
}

//// func_8006EF84
EXTERN_C void func_8006EF84(void *self)
{
    int i = D_800B4CF0_w;
    int j = i ^ 1;
    char *s = (char *)self + (j * 12 + 0xC);
    char *d = (char *)self + (i * 12 + 0xC);
    int ks = j * 40 + 0x24;
    int kd = i * 40 + 0x24;
    char *s2;
    char *d2;
    *(W2_B *)(d + 4) = *(W2_B *)(s + 4);
    s2 = (char *)self + ks;
    d2 = (char *)self + kd;
    *(B16_B *)(d2 + 4) = *(B16_B *)(s2 + 4);
    *(B16_B *)(d2 + 0x14) = *(B16_B *)(s2 + 0x14);
    FIELD_AT(d2, int, 0x24) = FIELD_AT(s2, int, 0x24);
}

//// func_8006F3DC
EXTERN_C int func_8006F3DC_def(void *self, int a, int b, int c, int d, int e)
{
    switch (D_800AF410.state) {
    case 0:
        func_8006FE14((char *)self + 4, a, b, c, d, e);
        func_8006F10C(self);
        return 1;
    case 1:
        goto L1;
    case 2:
        goto L2;
    case 3:
    L1: {
        char *s = (char *)self + 4;
        bool ok = !func_8006FE30_b(s, a, b, c);
        if (ok) {
            func_8006FE14(s, a, b, c, d, e);
            D_800AF40C.v = 1;
            func_8006F154(self);
            return 1;
        }
        break;
    }
    case 4:
    case 5:
    case 6:
    L2:
        func_8006FE14((char *)self + 4, a, b, c, d, e);
        {
            int t = 1;
            D_800AF40C.v = t;
            return t;
        }
    default:
        return 0;
    }
    return 1;
}

//// func_80078FD4
EXTERN_C int func_80078FD4(void *self, void *m)
{
    func_8001FC78(m, self ? (char *)self + 0x100 : 0, 1);
    int a = ~FIELD_AT(m, unsigned short, 0x1A);
    if (FIELD_AT(self, void *, 0x32C) != 0) {
        func_800CB174_c(FIELD_AT(self, void *, 0x32C), m, 0);
    } else if (FIELD_AT(self, int, 0x378) == 1 && FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x1AC) != 0 && D_800AF410_w == 0 && (a & 0x1000)) {
        func_80079E8C(self);
    }
    return 1;
}

//// func_8007C6A8 (matches in try_compile but its jump table lands after the unit's rodata cluster)
EXTERN_C void func_8007C6A8(void *self, void *m)
{
    if (FIELD_AT(m, unsigned short, 0xA) == 2) {
        switch (FIELD_AT(m, int, 0x10) & 0xFFF) {
        case 0:
            func_8006F2A8(self);
            break;
        case 1:
            func_8006F2E8(self);
            break;
        case 2:
            func_8006F31C(self);
            break;
        case 3:
            func_8006F35C(self);
            break;
        case 4:
            func_800DDFB0_c(self, 0, FIELD_AT(self, int, 0x168), FIELD_AT(self, int, 0x16C), FIELD_AT(self, int, 0x170), FIELD_AT(self, int, 0x174), FIELD_AT(self, int, 0x178), FIELD_AT(self, int, 0x17C), FIELD_AT(self, B16_B, 0x180), FIELD_AT(self, int, 0x190));
            break;
        }
    }
}

EXTERN_C int SsGetMute_i(void *a) asm("SsGetMute");

EXTERN_C void *func_800787B4_p(void) asm("func_800787B4");

EXTERN_C void func_800CFB08(void *a, int b);

EXTERN_C void func_800BE208(void *a, void *b);

//// func_8006AE68
EXTERN_C void func_8006AE68(void *self)
{
    int k = FIELD_AT(self, int, 0x278);
    char tmp[8];
    char *p;
    if (k == 0) {
        return;
    }
    if (FIELD_AT(self, int, 0x274) != 0) {
        return;
    }
    switch (k - 1) {
    case 0:
        FIELD_AT(self, int, 0x278) = 0;
        return;
    case 2:
        FIELD_AT(self, unsigned short, 0x2A2) = (FIELD_AT(self, unsigned short, 0x2A2) + 4) & 0xFFF;
        func_8006B3D0(self, (char *)self + 0x2A0);
        FIELD_AT(self, int, 0x26C) = 1;
        return;
    case 4:
        if (SsGetMute_i(self) && FIELD_AT(self, int, 0x224) == 0) {
            func_8006B884(self);
            func_800BE09C(tmp);
            p = (char *)self + 0x2A0;
            func_800BE208(tmp, p);
            FIELD_AT(self, int, 0x278) = 6;
            FIELD_AT(self, int, 0x26C) = 0;
            func_800CFB08(FIELD_AT(func_800787B4_p(), void *, 0x32C), 0);
            func_8006B3D0(self, p);
        } else {
            FIELD_AT(self, unsigned short, 0x2A2) = (FIELD_AT(self, unsigned short, 0x2A2) + 0x30) & 0xFFF;
            func_8006B3D0(self, (char *)self + 0x2A0);
        }
        FIELD_AT(self, int, 0x26C) = 1;
        return;
    case 5:
        func_8006B3D0(self, (char *)self + 0x2A0);
        FIELD_AT(self, int, 0x26C) = 1;
        return;
    }
}
static inline void post_80081ED0(void *dst, int kind, int z, int x, int y)
{
    char *m = (char *)func_8001CA10(0x14);
    FIELD_AT(m, void *, 0) = D_80010178;
    FIELD_AT(m, int, 4) = 0;
    FIELD_AT(m, void *, 0) = D_80010300;
    FIELD_AT(m, short, 8) = kind;
    FIELD_AT(m, void *, 0) = D_800102D0;
    FIELD_AT(m, short, 0xA) = z;
    FIELD_AT(m, int, 0x10) = x;
    FIELD_AT(m, int, 0xC) = y;
    func_8001EFE4(dst, m);
}

//// func_80081ED0
EXTERN_C void func_80081ED0(void *self, int a)
{
    FIELD_AT(self, int, 0x10) += a;
    while (FIELD_AT(self, void *, 0) != 0) {
        if (FIELD_AT(self, int, 0x10) < FIELD_AT(FIELD_AT(self, void *, 0), int, 0xC)) {
            break;
        }
        char *n = (char *)func_800751AC(self);
        int x = FIELD_AT(n, int, 0x10);
        int y = FIELD_AT(n, int, 0x1C);
        int z = FIELD_AT(n, unsigned short, 0x14);
        post_80081ED0(FIELD_AT(n, void *, 0x18), 2, z, x, y);
        if (n != 0) {
            ((VObj<8> *)n)->v00(3);
        }
    }
}

//// func_8007DB04
EXTERN_C void func_8007DB04(void *self, int v)
{
    int k = FIELD_AT(self, int, 0x11C);
    void *o;
    char *m;
    switch (k) {
    case 1:
        o = FIELD_AT(D_800AF470.p, void *, 0x380);
        m = (char *)func_8001CA10(0x14);
        FIELD_AT(m, void *, 0) = D_80010178;
        FIELD_AT(m, void *, 0) = D_80010300;
        FIELD_AT(m, int, 4) = 0;
        FIELD_AT(m, short, 8) = 2;
        FIELD_AT(m, short, 0xA) = 2;
        FIELD_AT(m, int, 0x10) = v;
        FIELD_AT(m, int, 0xC) = 0;
        FIELD_AT(m, void *, 0) = D_800102D0;
        func_8001EFE4(o, m);
        break;
    case 2:
        o = FIELD_AT(D_800AF470.p, void *, 0x384);
        m = (char *)func_8001CA10(0x14);
        FIELD_AT(m, void *, 0) = D_80010178;
        FIELD_AT(m, void *, 0) = D_80010300;
        FIELD_AT(m, int, 4) = 0;
        FIELD_AT(m, short, 8) = k;
        FIELD_AT(m, short, 0xA) = k;
        FIELD_AT(m, int, 0x10) = v;
        FIELD_AT(m, int, 0xC) = 0;
        FIELD_AT(m, void *, 0) = D_800102D0;
        func_8001EFE4(o, m);
        break;
    }
}

//// func_80084C50
EXTERN_C void func_80084C50(void *self)
{
    int k = FIELD_AT(self, short, 0x4E2);
    FIELD_AT(self, char, 0x517) = 1;
    FIELD_AT(self, char, 0x4AC) = 1;
    if (k == 0) {
        func_80082C68(self ? (char *)self + 0x2A0 : 0, 0x21, D_800AF470.p, D_800AFAA4[FIELD_AT(self, signed char, 0x4BC)], 2);
        func_80082E14(self ? (char *)self + 0x2A0 : 0, 0);
    } else if (k == 1) {
        func_80082C68(self ? (char *)self + 0x2A0 : 0, 0x21, D_800AF470.p, D_800AFAA4[FIELD_AT(self, signed char, 0x4BC)], 2);
        func_80082E14(self ? (char *)self + 0x2A0 : 0, 0);
    } else if (k == 2) {
        func_80082C68(self ? (char *)self + 0x2A0 : 0, 0x21, D_800AF470.p, D_800AFAA4[FIELD_AT(self, signed char, 0x4BC)], k);
        func_80082E14(self ? (char *)self + 0x2A0 : 0, 0);
    }
}

//// func_800846EC
EXTERN_C void func_800846EC(void *self_, int v_)
{
    void *self = self_;
    int v = v_;
    if (FIELD_AT(self, signed char, 0x4BB) != v) {
        int k = FIELD_AT(self, short, 0x4E2);
        char *o;
        FIELD_AT(self, signed char, 0x4BB) = v;
        if (k == 1) {
            o = (char *)FIELD_AT(D_800AF470.p, void *, 0x328);
            func_8007B108(o ? o + 0xB8 : 0, v);
        } else if (k == 2) {
            o = (char *)FIELD_AT(D_800AF470.p, void *, 0x328);
            func_8007B404(o ? o + 0xB8 : 0, self);
        }
    }
}

//// func_80075EC8
EXTERN_C void func_80075EC8(void *self, int b)
{
    if (func_80036FC0(self ? (char *)self + 0xF8 : 0, FIELD_AT(self, int, 0x140), FIELD_AT(self, int, 0x144)) == 0) {
        char *p;
        FIELD_AT(self, int, 0x13C) = 1;
        char *sub;
        p = (char *)__builtin_new(0x14);
        sub = p ? p + 4 : 0;
        FIELD_AT(p, void *, 0) = D_800100F8;
        FIELD_AT(p, void *, 4) = D_800101C0;
        FIELD_AT(p, void *, 0) = D_800101B0;
        FIELD_AT(p, short, 0x10) = 5;
        FIELD_AT(p, void *, 8) = self;
        FIELD_AT(p, short, 0xC) = 0;
        FIELD_AT(p, short, 0xE) = 1;
        FIELD_AT(p, short, 0x12) = 2;
        FIELD_AT(self, void *, 0x14C) = p;
        func_80035DE0(sub);
    } else {
        FIELD_AT(self, int, 0x13C) = 2;
        if (FIELD_AT(self, int, 0x140) < 0) {
            FIELD_AT(self, int, 0x144) = func_80037258(self ? (char *)self + 0xF8 : 0);
        }
        func_80075FD4(self);
    }
}

/* ---- round 3, third batch ---- */
//// func_800766F8
EXTERN_C void func_800766F8(void *self, int a1, int a2, int a3, int a4)
{
    char *n;
    char *m;
    char *s;
    int x;
    int y;
    int e;
    FIELD_AT(self, int, 0x1BC) = 1;
    e = a4;
    n = (char *)func_80075744(__builtin_new(0x24), a1, a2, a3, e);
    m = (char *)__builtin_new(0x28);
    x = FIELD_AT(n, int, 0x8);
    y = FIELD_AT(n, int, 0xC);
    s = m + 8;
    FIELD_AT(m, void *, 0x0) = D_80011FE4;
    FIELD_AT(m, void *, 0x8) = D_800100F8;
    FIELD_AT(m, void *, 0xC) = D_80010198;
    FIELD_AT(s, void *, 0x4) = D_800101C0;
    FIELD_AT(m, void *, 0x8) = D_800101B0;
    FIELD_AT(s, short, 0xC) = 6;
    FIELD_AT(s, short, 0xE) = 4;
    FIELD_AT(s, short, 0x10) = 5;
    FIELD_AT(s, short, 0x12) = 2;
    FIELD_AT(s, void *, 0x8) = self;
    FIELD_AT(m, void *, 0xC) = D_80012104;
    FIELD_AT(m, void *, 0x8) = D_800120F4;
    FIELD_AT(m, void *, 0x0) = D_8001211C;
    FIELD_AT(m, int, 0x20) = 0;
    FIELD_AT(m, int, 0x1C) = x;
    FIELD_AT(m, int, 0x24) = y;
    func_80075894(n, (int)m);
    func_8001A678((char *)self + 0x150, n);
    func_8003546C(self ? (char *)self + 0xF8 : 0, m);
}
//// func_8007698C
EXTERN_C void func_8007698C(void *self, int a1, int a2, int a3)
{
    char *n;
    char *m;
    char *s;
    FIELD_AT(self, int, 0x1BC) = 1;
    n = (char *)func_80075788(__builtin_new(0x24), a1, a2, a3, 1);
    m = (char *)__builtin_new(0x2C);
    s = m + 8;
    FIELD_AT(m, void *, 0x0) = D_80011FE4;
    FIELD_AT(m, void *, 0x8) = D_800100F8;
    FIELD_AT(m, void *, 0xC) = D_80010198;
    FIELD_AT(s, void *, 0x4) = D_800101C0;
    FIELD_AT(m, void *, 0x8) = D_800101B0;
    FIELD_AT(s, short, 0xC) = 6;
    FIELD_AT(s, short, 0xE) = 4;
    FIELD_AT(s, short, 0x10) = 5;
    FIELD_AT(s, short, 0x12) = 2;
    FIELD_AT(s, void *, 0x8) = self;
    FIELD_AT(m, void *, 0xC) = D_80012104;
    FIELD_AT(m, void *, 0x8) = D_800120F4;
    FIELD_AT(m, void *, 0x0) = D_8001211C;
    FIELD_AT(m, void *, 0x24) = m + 0x28;
    FIELD_AT(m, void *, 0x8) = D_80016820;
    FIELD_AT(m, int, 0x1C) = a1;
    FIELD_AT(m, int, 0x20) = 0;
    FIELD_AT(m, void *, 0x0) = D_80016830;
    func_80075894(n, (int)m);
    func_8001A678((char *)self + 0x150, n);
    func_8003546C(self ? (char *)self + 0xF8 : 0, m);
}
//// func_80076CD0
EXTERN_C void func_80076CD0(void *p, int flags)
{
    char *b = (char *)p + 8;
    void *vt = D_80012104;
    FIELD_AT(p, void *, 8) = D_80016820;
    FIELD_AT(p, void *, 0) = D_80016830;
    FIELD_AT(p, void *, 8) = D_800120F4;
    FIELD_AT(p, void *, 0) = D_8001211C;
    FIELD_AT(p, void *, 0xC) = vt;
    FIELD_AT(b, void *, 4) = D_800101C0;
    FIELD_AT(b, void *, 0) = D_800101B0;
    func_800198AC(b, 0);
    if (flags & 1)
        __builtin_delete(p);
}
