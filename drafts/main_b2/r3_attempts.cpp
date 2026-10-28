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
