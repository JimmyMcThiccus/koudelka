// Round 3 (main_b1) near misses. Not built. Each section: one-line note, then the best attempt.
// Prelude assumed: include/game/b/decls_b.h plus these helpers:
//   struct VE_B{short delta;short index;void(*pfn)(void*,int,int);}; EXTERN_C int D_800B4CF0_w asm("D_800B4CF0");

// ===== func_80054B98 / 54A4C / 54AF0: 8 differing: with a struct for the object (O54) the v0=this hoist after func_800198E0 works; remaining: retail hoists `addiu a0,0x10; lhu a1,D_800B4D7C` above the stores
EXTERN_C O54 *func_80054AF0(O54 *self, int b)
{
    char *l;
    func_80053928(self);
    FIELD_AT(self, void *, 0x18) = D_80013B70;
    l = (char *)self + 0x1C;
    FIELD_AT(l, char *, 0x8) = (char *)self + 0x28;
    FIELD_AT(self, char *, 0x1C) = (char *)self + 0x28;
    ((int (*)(void *, int, int))func_800198E0)(FIELD_AT(l, void *, 0x8), b, 0);
    FIELD_AT(l, int, 0x4) = 0;
    {
    int w = 0x10;
    unsigned short t = D_800B4D7C;
    self->s46 = -2;
    self->s48 = -1;
    self->s4A = 4;
    self->s40 = w;
    self->s42 = w;
    self->s4C = 2;
    self->s4E = w;
    self->i3C = 0;
    self->s44 = t;
    return self;
    }
}

// ===== func_8005CA4C: 12 differing: explicit n+=4 loop copying 4 words (unrotated shape right), but GCC strength-reduces s/d to base+0x20 with negative offsets; retail keeps base+0x10 and +4..+0x10
EXTERN_C int func_8005CA4C(void *self)
{
    if (func_8005F1B4(self)) {
        int i = D_800B4CF0_w;
        int *d = (int *)((char *)self + (i * 36 + 0x10));
        int *s = (int *)((char *)self + (((i ^ 1) * 36) + 0x10));
        unsigned n = 0;
        while (n < 8) {
            int a = s[1];
            int b = s[2];
            int c = s[3];
            int e = s[4];
            d[1] = a;
            d[2] = b;
            d[3] = c;
            d[4] = e;
            n += 4;
            s += 4;
            d += 4;
        }
    }
    D_800B4CFC->add((P_TAG_B *)(D_800B4CF0_w * 36 + (int)self + 0x10), FIELD_AT(self, unsigned short, 0xA));
    return 1;
}

// ===== func_80066FB0: 39 differing (incl. size 200 vs 204): switch layout right, D_800B4ED8 lui form right; retail copies a1 through v0 (`addu v0,a1,zero; sw v0,0xC`) in the c==0 branch
EXTERN_C void *func_80066FB0(void *self, void *a, int b, int c, int d)
{
    FIELD_AT(self, void *, 0x0) = D_800154EC;
    FIELD_AT(self, void *, 0x8) = a;
    FIELD_AT(self, int, 0x10) = b;
    FIELD_AT(self, int, 0xC) = c;
    if (c == 0) {
        void *t = a;
        FIELD_AT(self, void *, 0xC) = t;
    }
    FIELD_AT(self, int, 0x14) = d;
    switch (b) {
    case 0x65:
    case 0x6B:
    case 0x6C:
        FIELD_AT(self, int, 0x4) = 0xFF;
        break;
    case 0x6F:
        func_8008E70C(FIELD_AT((char *)D_800B4ED8, void *, 0x248), 0xF0);
    case 0x66:
    case 0x69:
    case 0x6A:
    case 0x6D:
    case 0x6E:
        FIELD_AT(self, int, 0x4) = 0;
        break;
    }
    char *g = (char *)D_800B4ED8;
    func_8006A4E4(FIELD_AT(g, void *, 0x250), FIELD_AT(self, unsigned char, 0x4));
    func_8006BD34(g);
    return self;
}

// ===== func_80066BC0: 22 differing: retail keeps `base` (a2) and `h` (a1) as separate pseudos and loads g into a3; mine coalesces
EXTERN_C int func_80066BC0(void *self)
{
    char *h = FIELD_AT(self, char *, 0x2C);
    char *g = FIELD_AT(self, char *, 0x48);
    char *base = h;
    if (h[0] != 'b' || h[1] != 'g' || h[2] != 'm' || h[3] != '0') {
        func_80066C7C(self);
        return 0;
    }
    if (h[8] != 2) {
        return 0;
    }
    h += 0xC;
    FIELD_AT(g, int, 0x51C) = (int)base + ((int *)h)[0];
    FIELD_AT(g, int, 0x520) = ((int *)h)[1];
    h += 8;
    FIELD_AT(g, int, 0x524) = (int)base + ((int *)h)[0];
    FIELD_AT(g, int, 0x528) = ((int *)h)[1];
    return 1;
}

// ===== func_80066A54: 14 differing: same base/h split as 66BC0
EXTERN_C int func_80066A54(void *self)
{
    char *h = FIELD_AT(self, char *, 0x2C);
    char *base = h;
    if (h[0] != 'b' || h[1] != 'd' || h[2] != 't' || h[3] != '0') {
        func_80066C7C(self);
        return 0;
    }
    if (h[8] != 1) {
        return 0;
    }
    h += 0xC;
    FIELD_AT(FIELD_AT(self, char *, 0x48), int, 0x41C) = (int)base + ((int *)h)[0];
    FIELD_AT(FIELD_AT(self, char *, 0x48), int, 0x420) = ((int *)h)[1];
    return 1;
}

// ===== func_800624A4: 10 differing: retail rematerialises 0x8000 (ori) in the second shift, mine CSEs it; shift operand regs swapped
EXTERN_C void func_800624A4(void *unused, void *s0, void *s1)
{
    int r = rand();
    int a = (r >> 8) & 3;
    int v;
    if ((r >> 8) & 1) v = a - 1; else v = a + 1;
    FIELD_AT(s0, short, 0x88) = 0x8000 >> v;
    if ((r >> 4) & 1) {
        short *p = &FIELD_AT(s0, short, 0x80 + (r & 3) * 2);
        *p = 0x8000 >> a;
    }
    *(U8b *)s1 = *(U8b *)func_80053BC0(&D_800AE86C[a]);
}

// ===== func_8005B378: 2 differing: delay-slot filler order after the first call (addu s0,v0 vs addiu a1,0xB)
struct Ent16d { char p[0xE]; unsigned short h; };
EXTERN_C void func_8005B378(void *self, int n)
{
    unsigned i;
    int idx = D_800B4CF0_w;
    int v = func_80060118(&D_800AE640);
    int w = func_800600A4(&D_800AE640, 0xB);
    for (i = 0; i < FIELD_AT(self, unsigned, 0x18); i += 2) {
        if (FIELD_AT(self, Ent16d *, 0x14)[i + idx].h != (unsigned short)w) {
            FIELD_AT(self, Ent16d *, 0x14)[i + idx].h = v;
        }
    }
    func_8005F1D8(self);
}

// ===== func_8005C910: 6 differing: retail loads both lh before the vtable add and reuses v0 for the 0x1A value
EXTERN_C int func_8005C910(void *self, int a, int b)
{
    short *p = (short *)((char *)self + D_800B4CF0_w * 36);
    return ((VObj0 *)self)->v10(a - p[0xC], b - p[0xD]);
}

// ===== func_80063584: needs `~f & mask` in a1 not CSEd and self=s1/b=s0; see b8 variants
EXTERN_C int func_80063584(void *self, unsigned short *b)
{
    if (!func_800557A0(self)) {
        unsigned short f = b[0xD];
        if (~f & 0x10) {
            func_8005549C(1, self, 0, -1);
        } else if (~f & 0x40) {
            func_8005549C(2, self, 0, -1);
        }
    }
    return 1;
}

