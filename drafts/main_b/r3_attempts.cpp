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

// ===== func_80066E7C: 52 differing: 4-way compare chain (0x64 handled first, loads of D_800B4ED8/D_800EA0B0, then 0x66/<0x67/0x65/0x67); my switch/if forms lay the blocks out differently
EXTERN_C int func_80066E7C(void *self)
{
    int c = FIELD_AT(self, int, 0xC);
    char *s1;
    char *s0;
    if (c == 0x64) return 1;
    s1 = (char *)D_800B4ED8;
    s0 = (char *)D_800EA0B0_w;
    if (c == 0x65) {
        if (!func_80066F8C()) return 0;
        func_80036D8C(FIELD_AT(s1, void *, 0x2DC));
        FIELD_AT(s1, int, 0x2DC) = 0;
        return 1;
    } else if (c == 0x66) {
        if (!func_80066F8C()) return 0;
        func_80036D8C(FIELD_AT(s1, void *, 0x2DC));
        FIELD_AT(s1, int, 0x2DC) = 0;
        func_8006BB04(s1);
        return 1;
    } else if (c == 0x67) {
        if (!func_80066F8C()) return 0;
        if (!s0) return 1;
        func_80036D8C(FIELD_AT(s0, void *, 0x674));
        FIELD_AT(s0, int, 0x674) = 0;
        func_8007F6C4(func_800787B4());
        return 1;
    }
    return 0;
}

// ===== func_800594A8: 35 differing: ctor with stack args; struct typing fixes the prologue regs, but retail keeps `sh s3,0xA(s0)` in the delay slot of the last call and the vtable/zero stores in a different order
EXTERN_C O594 *func_800594A8(O594 *self, int a, int b, int c, int d, unsigned char *e, int f)
{
    self->vt = D_80010178;
    self->vt = D_800111BC;
    self->i4 = 0;
    self->s8 = 0;
    self->vt = D_80014278;
    self->sA = f;
    func_80098E10((char *)self + 0xC);
    func_80098E10((char *)self + 0x1C);
    func_80059800(self, a, b, c, d);
    func_80059888(self, e);
    self->sA = f;
    ((int (*)(void *))func_80059790)(self);
    return self;
}

// ===== func_8005717C: 3 differing: `c = A0 ? 0 : 0xFF` as ternary gives the 0xFF/`beqz` sense backwards; the if-form moves the lw before the 0xFF
EXTERN_C void func_8005717C(void *self, int a, int b)
{
    FIELD_AT(self, int, 0x9C) = a / 2;
    FIELD_AT(self, int, 0xA8) = b;
    FIELD_AT(self, int, 0xA4) = 0;
    if (FIELD_AT(self, int, 0x8) == 0) {
        func_8002B174(D_800A4578.p, self, -1);
        ((VObj<0x2C> *)self)->v27();
        func_8002A210(self);
        int c = 0xFF;
        if (FIELD_AT(self, int, 0xA0) != 0) {
            c = 0;
        }
        func_8005D9D4((char *)self + 0x5C, c);
    }
}

// ===== func_8005854C: 37 differing: retail keeps a separate pseudo for the `(u16)a != 0` test (addu s2,s1) and s4=b,s3=c
EXTERN_C void func_8005854C(void *self, int a, void *b, int c)
{
    int t = a;
    if (FIELD_AT(self, int, 0x140) != 0) {
        ((VObj<8> *)((char *)self + 0x50))->v02();
    }
    FIELD_AT(self, short, 0x144) = a;
    if ((unsigned short)t != 0) {
        FIELD_AT(self, U8b, 0x148) = *(U8b *)b;
        FIELD_AT(self, short, 0x146) = c;
    }
}

// ===== func_80061A20: 30 differing: loop shape matches (test at bottom `beqz found`), but self=s2/b=s1 in retail, s1/s2 swapped here
EXTERN_C int func_80061A20(void *self, unsigned char *b)
{
    int found = 0;
    if (b[0x18] == 4) {
        unsigned n = func_800619F4((Obj_800619F4 *)self);
        unsigned i = 0;
        unsigned char *p = (unsigned char *)self;
        while (i < n) {
            if (p[0x23F] == b[0x1B]) {
                found = 1;
            }
            p += 0x94;
            i++;
            if (found) break;
        }
    }
    return found;
}

// ===== func_80057214: 78 differing: composite dtor with an inlined member dtor (member at +0x5C); retail keeps the member pointer in a callee-saved reg (s0) and reads member->vb via p+0x5C
EXTERN_C void func_80057214_def(S_DtorB *p, int flags)
{
    S_DtorB *m;
    FIELD_AT(p, void **, 0x58) = D_80013E10;
    p->vt2C = D_80013D00;
    p->vb->vt = (VEntB *)D_80013CB0.e;
    if (!flags) {
        VTabB50 tmp = D_80013CB0;
        p->vb->vt = tmp.e;
        char *q;
        int adj;
        tmp.e[1].d = D_80013CB0.e[1].d + (adj = (char *)p - (q = (char *)p->vb - 0xAC));
        tmp.e[5].d = D_80013CB0.e[5].d + adj;
        tmp.e[7].d = D_80013CB0.e[7].d + adj;
        tmp.e[9].d = D_80013CB0.e[9].d + adj;
    }
    m = (S_DtorB *)((char *)p + 0x5C);
    m->vt2C = D_80014A08;
    m->vb->vt = (VEntB *)D_800149B8.e;
    func_8005BDA4(m, 0);
    func_8001A610(m->vb, 0);
    func_80057558(p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}
// ===== func_80057368: 4 differing: two-stage vb ctor; stage-1 fix-up loads/adds are paired (lhu,lhu,addu,addu,sh,sh) in retail but interleaved here
EXTERN_C S_Ct5Cb *func_80057368_def(S_Ct5Cb *p, int in_chrg) asm("func_80057368");
EXTERN_C S_Ct5Cb *func_80057368_def(S_Ct5Cb *p, int in_chrg)
{
    VTabB50 tmp1;
    VTabB50 tmp;
    if (in_chrg) {
        p->vb = (S_VBB *)&p->vobj;
        S_VBobjB *v = (S_VBobjB *)p->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80029C54_v(p, 0, 2);
    {
        char *q;
        int adj;
        p->vb->vt = (VEntB *)D_800114CC.e;
        tmp1 = D_800114CC;
        p->vb->vt = tmp1.e;
        tmp1.e[1].d = D_800114CC.e[1].d + (adj = (char *)p - (q = (char *)p->vb - 0x50));
        tmp1.e[5].d = D_800114CC.e[5].d + adj;
        tmp1.e[7].d = D_800114CC.e[7].d + adj;
        tmp1.e[9].d = D_800114CC.e[9].d + adj;
    }
    FIELD_AT(p, void **, 0x2C) = D_8001151C;
    {
        char *l = (char *)p + 0x30;
        FIELD_AT(l, char *, 0x8) = (char *)p + 0x3C;
        FIELD_AT(p, char *, 0x30) = (char *)p + 0x3C;
        func_800198E0_v(FIELD_AT(l, void *, 0x8), 0x10, 4);
        FIELD_AT(l, int, 0x4) = 0;
        func_800537C0((char *)p + 0x50);
    }
    p->vb->vt = (VEntB *)D_80013F40.e;
    if (!in_chrg) {
        char *q;
        int adj;
        tmp = D_80013F40;
        p->vb->vt = tmp.e;
        tmp.e[1].d = D_80013F40.e[1].d + (adj = (char *)p - (q = (char *)p->vb - 0x5C));
        tmp.e[5].d = D_80013F40.e[5].d + adj;
        tmp.e[7].d = D_80013F40.e[7].d + adj;
        tmp.e[9].d = D_80013F40.e[9].d + adj;
    }
    FIELD_AT(p, void **, 0x58) = D_80013F90;
    FIELD_AT(p, void **, 0x2C) = D_80013E30;
    return p;
}
// ===== func_80064290: 48 differing: retail keeps `andi s4,s4,0xFFFF; sll s4,s4,4` on the char argument (mine drops the andi) and different saved-reg order
EXTERN_C void *func_80064290_def(void *p, Pt4w pos, unsigned short c, int d)
{
    int i;
    int off;
    char *q;
    func_8005F0E4_v(p, d);
    FIELD_AT(p, void *, 0) = D_800151B4;
    SetDrawMode((char *)p + 0x10, 0, 0, func_80060154_v(&D_800AE640, 0xD) & 0xFFFF, 0);
    SetDrawMode((char *)p + 0x1C, 0, 0, func_80060154_v(&D_800AE640, 0xD) & 0xFFFF, 0);
    FIELD_AT(p, unsigned char, 0x2F) = 0x7C;
    FIELD_AT(p, unsigned char, 0x3F) = 0x7C;
    FIELD_AT(p, unsigned char, 0x2B) = 3;
    FIELD_AT(p, unsigned char, 0x3B) = 3;
    i = D_800B4CF0_w;
    off = i << 4;
    q = (char *)p + off;
    FIELD_AT(q, unsigned char, 0x2C) = 0x80;
    FIELD_AT(q, unsigned char, 0x2D) = 0x80;
    FIELD_AT(q, unsigned char, 0x2E) = 0x80;
    FIELD_AT(q, short, 0x30) = pos.x;
    FIELD_AT(q, unsigned char, 0x34) = c << 4;
    FIELD_AT(q, unsigned char, 0x35) = 0x40;
    FIELD_AT(q, short, 0x32) = pos.y;
    FIELD_AT(q, short, 0x36) = func_800600A4_v(&D_800AE640, 0xD);
    {
        int *s = (int *)((char *)p + (off + 0x28));
        int *dd = (int *)((char *)p + ((i ^ 1) * 16 + 0x28));
        int a = s[1];
        int b = s[2];
        int e = s[3];
        dd[1] = a;
        dd[2] = b;
        dd[3] = e;
    }
    return p;
}
// ===== func_80062988: 58 differing (register assignment): retail keeps self in s1 / t in s0 and builds the message in v0, mine puts it in a1
EXTERN_C void func_80062988(void *self)
{
    int eq = FIELD_AT(self, int, 0x64) == D_800B4D60_w;
    int t;
    S_MsgB *m;
    FIELD_AT(self, int, 0x6C) = 1;
    if (eq) {
        func_80062E70(self);
        t = FIELD_AT(self, int, 0x68);
        m = (S_MsgB *)func_8001CA10(0x14);
        m->vt = D_80010178;
        m->vt = D_80010300;
        m->s8 = 2;
        m->sA = 7;
        m->u4 = 0;
        m->pC = self;
        m->vt = D_800102D0;
        m->i10 = t;
        func_8001EFE4(FIELD_AT(self, void *, 0x64), m);
    } else {
        t = FIELD_AT(self, int, 0x68);
        m = (S_MsgB *)func_8001CA10(0x14);
        m->vt = D_80010178;
        m->vt = D_80010300;
        m->s8 = 2;
        m->sA = 7;
        m->u4 = 0;
        m->pC = self;
        m->vt = D_800102D0;
        m->i10 = t;
        func_8001EFE4(FIELD_AT(self, void *, 0x64), m);
        func_80062E70(self);
    }
}
