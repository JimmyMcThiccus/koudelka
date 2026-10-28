/* main_b round 2: near misses in u_80071A74 (helper attempts). Not built.
   func_80079ABC  12 diffs  also needs void *D_800B4ED8[]; remaining: D_800AF470 lui reused (s0) instead of fresh lui, reg for v
   func_8007E47C  8 diffs  sra of the /512 scheduled earlier than retail around the D_800B4DD0 reload stores
   func_800766F8  6 diffs  prologue: retail stores self->1BC=1 before loading the stack arg a4 into s0
   func_8007FD60  3 diffs  lui of D_800AC86C hoisted before the s1=v0 move (scheduling)
   func_8007F9B4  13 diffs  switch layout: retail has dead addiu v0,s0,0x448 in delay slot + v1 for default value; case 2/default order
   func_8007698C  18 diffs  inline ctor (same class as 80076C1C): retail delays the C=D_80012104 store (lui hoisted into v1)
   func_80076C1C  26 diffs  inline base-ctor chain: retail loads stack args (shorts) after the first vptr stores
   func_8007B1FC  28 diffs  two find-free-slot loops: retail places found-blocks before 2nd loop, different loop rotation
   func_80081ED0  41 diffs  loop-invariant hoisting: retail hoists const 2, D_80010178, D_80010300 (not D_800102D0) above the loop entry test
   func_80075EC8  43 diffs  new'd object: retail computes p+4 before the null test (a0=p+4; bnez p) and uses v0 directly
   func_8007B5F8  74 diffs  register swap self(s1)/t(s2) and t loaded into v1 first; logic is right
   func_800729E8  6 diffs  only the k=0 (b&0x40) case: retail single lh + inverted branch; uses #define ROT macro in near.cpp
   func_8007C7B0  ~119 diffs  switch of 3 near-identical cases: GCC cross-jumps case1 into case2's call; retail keeps 3 separate call sequences (t63.cpp)
   -- not attempted (structurally out of reach for now):
   func_80072130 func_80071F6C func_80074C90 func_8007E684 func_8007E8C0 func_80078A30 func_8007479C func_800722EC func_800787C4  virtual-base ctor/dtor pattern (vtable copied to stack + delta patching via self->vbptr)
   func_80074AB4 func_8007398C  SVECTOR/struct-return temporaries with lwl/lwr copies
   func_80076038  uses the same inline-ctor chain as func_80076C1C/func_8007698C (unmatched)
   func_800820B4  .s contains two functions (an infinite loop + a static-init stub after it)
*/
// Types used here (List_8007AB78, V4_80085578, ...) are already in include/game/b/decls_b.h.

//// func_8007F9B4
extern "C" void func_8007F9B4(void *self, B16_B *b)
{
    int c;
    switch (FIELD_AT(self, int, 0x370)) {
    case 1: {
        int *v = func_800BFED4(D_800EA0B0.p, b);
        FIELD_AT(self, B16_B, 0x214) = *b;
        FIELD_AT(self, int, 0x20C) = v[0];
        FIELD_AT(self, int, 0x210) = v[1];
        return;
    }
    case 2:
        c = 0;
        break;
    default:
        c = 0xFF000000;
        break;
    }
    FIELD_AT(self, int, 0x448) = c;
    FIELD_AT(self, int, 0x44C) = 0;
}

//// func_8007B1FC
extern "C" int func_8007B1FC(void *self, int x, int kind)
{
    int i;
    switch (kind) {
    case 1:
        for (i = 0; i < 3; i++) {
            if (D_800AFA64[i] == 0) {
                D_800AFA64[i] = x;
                FIELD_AT(self, int, 0x14)++;
                return 1;
            }
        }
        return 0;
    case 2:
        for (i = 0; i < 3; i++) {
            if (D_800AFA58[i] == 0) {
                D_800AFA58[i] = x;
                FIELD_AT(self, int, 0x18)++;
                return 2;
            }
        }
        return 0;
    }
    return 0;
}

//// func_80076C1C
extern "C" void *func_80076C1C(void *self, int a1, int a2, short a3, short a4, short a5, short a6)
{
    char *s = (char *)self + 8;
    FIELD_AT(self, void *, 0x0) = D_80011FE4;
    FIELD_AT(self, void *, 0x8) = D_800100F8;
    FIELD_AT(self, void *, 0xC) = D_80010198;
    FIELD_AT(s, void *, 0x4) = D_800101C0;
    FIELD_AT(self, void *, 0x8) = D_800101B0;
    FIELD_AT(s, int, 0x8) = a1;
    FIELD_AT(s, short, 0x12) = a3;
    FIELD_AT(s, short, 0xC) = a4;
    FIELD_AT(s, short, 0xE) = a5;
    FIELD_AT(s, short, 0x10) = a6;
    FIELD_AT(self, void *, 0x8) = D_800120F4;
    FIELD_AT(self, void *, 0x0) = D_8001211C;
    FIELD_AT(self, void *, 0x24) = (char *)self + 0x28;
    FIELD_AT(self, void *, 0x8) = D_80016820;
    FIELD_AT(self, void *, 0xC) = D_80012104;
    FIELD_AT(self, int, 0x1C) = a2;
    FIELD_AT(self, int, 0x20) = 0;
    FIELD_AT(self, void *, 0x0) = D_80016830;
    return self;
}

//// func_8007FD60
extern "C" void func_8007FD60(void *self, int a1)
{
    Sub_8007FD60 *p;
    FIELD_AT(self, char, 0x360) = 1;
    p = (Sub_8007FD60 *)__builtin_new(0x14);
    p->vt = D_800100F8;
    p->vt2 = D_800101C0;
    p->vt = D_800101B0;
    p->a = 0x2032;
    p->b = 0x2033;
    p->owner = self;
    p->c = 2;
    p->d = 2;
    while (func_800382A4(D_800AC86C, a1, p ? (char *)p + 4 : 0)) {
    }
}

//// func_80075EC8
extern "C" void func_80075EC8(void *self, int b)
{
    char *p;
    if (func_80036FC0(self ? (char *)self + 0xF8 : 0, FIELD_AT(self, int, 0x140), FIELD_AT(self, int, 0x144)) == 0) {
        FIELD_AT(self, int, 0x13C) = 1;
        p = (char *)__builtin_new(0x14);
        FIELD_AT(p, void *, 0x0) = D_800100F8;
        FIELD_AT(p, void *, 0x4) = D_800101C0;
        FIELD_AT(p, void *, 0x0) = D_800101B0;
        FIELD_AT(p, short, 0x10) = 5;
        FIELD_AT(p, void *, 0x8) = self;
        FIELD_AT(p, short, 0xC) = 0;
        FIELD_AT(p, short, 0xE) = 1;
        FIELD_AT(p, short, 0x12) = 2;
        FIELD_AT(self, void *, 0x14C) = p;
        func_80035DE0(FIELD_AT(self, char *, 0x14C) ? FIELD_AT(self, char *, 0x14C) + 4 : 0);
    } else {
        FIELD_AT(self, int, 0x13C) = 2;
        if (FIELD_AT(self, int, 0x140) < 0) {
            FIELD_AT(self, int, 0x144) = func_80037258(self ? (char *)self + 0xF8 : 0);
        }
        func_80075FD4(self);
    }
}

//// func_80081ED0
extern "C" void func_80081ED0(void *p, int dt)
{
    List_8007AB78 *self = (List_8007AB78 *)p;
    char *n;
    int a;
    int b;
    unsigned short c;
    Msg_8007EF90 *m;
    FIELD_AT(self, int, 0x10) += dt;
    while (self->head != 0 && FIELD_AT(self->head, int, 0xC) <= FIELD_AT(self, int, 0x10)) {
        n = (char *)func_800751AC(self);
        a = FIELD_AT(n, int, 0x10);
        b = FIELD_AT(n, int, 0x1C);
        c = FIELD_AT(n, unsigned short, 0x14);
        m = (Msg_8007EF90 *)func_8001CA10(0x14);
        m->vt = D_80010178;
        m->next = 0;
        m->vt = D_80010300;
        m->type = 2;
        m->vt = D_800102D0;
        m->sub = c;
        m->d = a;
        m->c = b;
        func_8001EFE4(FIELD_AT(n, void *, 0x18), m);
        if (n != 0) {
            ((VObj<8> *)n)->v00(3);
        }
    }
}

//// func_8007E47C
extern "C" void func_8007E47C(void *self)
{
    char *t;
    char *o;
    short *v;
    short d;
    char *g;
    B16_B tmp;
    g = (char *)D_800B4DD0.p;
    FIELD_AT(g, int, 0x1BC) = FIELD_AT(self, int, 0x168);
    FIELD_AT(g, int, 0x1C0) = FIELD_AT(self, int, 0x16C);
    FIELD_AT(g, int, 0x204) = FIELD_AT(self, int, 0x178);
    FIELD_AT(g, int, 0x208) = FIELD_AT(self, int, 0x17C);
    FIELD_AT(g, short, 0x1FE) = FIELD_AT(self, short, 0x170);
    FIELD_AT(g, short, 0x200) = FIELD_AT(self, short, 0x174);
    t = self ? (char *)self + 0xB8 : 0;
    o = FIELD_AT(t, char *, 0x8);
    tmp = FIELD_AT(FIELD_AT(o, char *, 0x1B8), B16_B, 0x34);
    v = (short *)(FIELD_AT(o, char *, 0x1B8) + 0x2C);
    d = SquareRoot0(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    {
        int k = (d + 0x100) / 512;
        char *g2 = (char *)D_800B4DD0.p;
        FIELD_AT(g2, int, 0x1C8) = tmp.w[0];
        FIELD_AT(g2, int, 0x1CC) = tmp.w[1];
        FIELD_AT(g2, char, 0x1FC) = k & 7;
        FIELD_AT(g2, int, 0x1D0) = tmp.w[2];
    }
}

//// func_8007B5F8
extern "C" void func_8007B5F8(void *self, int a1, int a2)
{
    char *g = (char *)D_800AF470.p;
    Tab_8007B5F8 *t;
    FIELD_AT(self, int, 0x2C) = a2;
    FIELD_AT(self, int, 0x38) = 0;
    t = FIELD_AT(g, Tab_8007B5F8 *, 0x328);
    if (FIELD_AT(g, int, 0x33C) != 0) {
        FIELD_AT(self, int, 0x24) = func_8007FE4C(g + 0x498, 0x3C0, 0x20);
        FIELD_AT(self, int, 0x28) = func_8007FE4C((char *)D_800AF470.p + 0x498, 0x3E0, 0x20);
    } else {
        if (a2 == 0) {
            int n = func_8007E658((Obj_8007E658 *)t);
            FIELD_AT(self, int, 0x50) = rand() % n;
        }
        FIELD_AT(self, int, 0x24) = t->e[FIELD_AT(self, int, 0x50)].a;
        FIELD_AT(self, int, 0x28) = t->e[FIELD_AT(self, int, 0x50)].b;
    }
    func_8007BE44(self);
    func_8007BEA8(self, 0x981C, (int)D_800D5DAC, 0, 1);
    func_8007BF48(self, 0, FIELD_AT(self, int, 0x24), 0xA000);
}

//// func_800766F8
extern "C" void func_800766F8(void *self, int a1, int a2, int a3, int a4)
{
    char *n;
    char *m;
    char *s;
    int x;
    int y;
    FIELD_AT(self, int, 0x1BC) = 1;
    n = (char *)func_80075744((Obj_80075744 *)__builtin_new(0x24), a1, a2, a3, a4);
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

//// func_800729E8
#define ROT(k) (FIELD_AT(self, short, 0x5CA) + (k) < 8 ? FIELD_AT(self, short, 0x5CA) + (k) : FIELD_AT(self, short, 0x5CA) + (k) - 8)
extern "C" short func_800729E8(void *self, int b)
{
    short r = 1;
    if ((b & 0xC0) == 0xC0) {
        FIELD_AT(self, short, 0x1BC) = ROT(1);
    } else if ((b & 0x90) == 0x90) {
        FIELD_AT(self, short, 0x1BC) = ROT(3);
    } else if ((b & 0x30) == 0x30) {
        FIELD_AT(self, short, 0x1BC) = ROT(5);
    } else if ((b & 0x60) == 0x60) {
        FIELD_AT(self, short, 0x1BC) = ROT(7);
    } else if (b & 0x40) {
        FIELD_AT(self, short, 0x1BC) = ROT(0);
    } else if (b & 0x10) {
        FIELD_AT(self, short, 0x1BC) = ROT(4);
    } else if (b & 0x20) {
        FIELD_AT(self, short, 0x1BC) = ROT(6);
    } else if (b & 0x80) {
        FIELD_AT(self, short, 0x1BC) = ROT(2);
    } else {
        r = 0;
    }
    return r;
}

//// func_8007C7B0
extern "C" void func_8007C7B0(void *self, int k)
{
    char *p;
    switch (k) {
    case 0:
        p = func_80072130(__builtin_new(0x5E8), 1, FIELD_AT(self, void *, 0x10C), 0, D_8001705C, V4_80085578(0, 0, 0, 0), 0);
        func_8007AFD0((Set_8007AFD0 *)(self ? (char *)self + 0xB8 : 0), (int)p);
        FIELD_AT(p, char, 0x4BC) = 0;
        break;
    case 1:
        p = func_80072130(__builtin_new(0x5E8), 1, FIELD_AT(self, void *, 0x10C), 1, D_80017068, V4_80085578(0, 0, 0, 0), 0);
        func_8007AFD0((Set_8007AFD0 *)(self ? (char *)self + 0xB8 : 0), (int)p);
        FIELD_AT(p, char, 0x4BC) = 1;
        break;
    case 2:
        p = func_80072130(__builtin_new(0x5E8), 1, FIELD_AT(self, void *, 0x10C), 2, D_80017070, V4_80085578(0, 0, 0, 0), 0);
        func_8007AFD0((Set_8007AFD0 *)(self ? (char *)self + 0xB8 : 0), (int)p);
        FIELD_AT(p, char, 0x4BC) = k;
        break;
    default:
        return;
    }
    FIELD_AT(p, char, 0x4BD) = 1;
    ((void (*)(void *, int))func_800824C8)(p + 0x2A4, 1);
    func_800825FC((short *)(p + 0x2A4), 0);
    func_80084824(p, 0);
    func_8001E848(FIELD_AT(self, void *, 0x10C), p);
}

//// func_8007698C
extern "C" void func_8007698C(void *self, int a1, int a2, int a3)
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
    FIELD_AT(m, void *, 0x8) = D_800120F4;
    FIELD_AT(m, void *, 0x0) = D_8001211C;
    FIELD_AT(m, void *, 0x24) = m + 0x28;
    FIELD_AT(m, void *, 0x8) = D_80016820;
    FIELD_AT(m, void *, 0xC) = D_80012104;
    FIELD_AT(m, int, 0x1C) = a1;
    FIELD_AT(m, int, 0x20) = 0;
    FIELD_AT(m, void *, 0x0) = D_80016830;
    func_80075894(n, (int)m);
    func_8001A678((char *)self + 0x150, n);
    func_8003546C(self ? (char *)self + 0xF8 : 0, m);
}

//// func_80079ABC
// also needs void *D_800B4ED8[] (see func_8007B108)
extern "C" void *D_800B4ED8[];
extern "C" void func_8007CC14(Derived_8007CC14 *self);
extern "C" void func_8007CCB4(void *self);
extern "C" void func_8007F89C(void *self);
extern "C" int func_8006B540(void *self);
extern "C" void func_8007FC90(void *self, int k);
extern "C" void func_80079ABC(void *self)
{
    char *g;
    int v;
    if (!((bool (*)(void *))func_8006F630)(FIELD_AT(self, void *, 0x328))) {
        return;
    }
    func_8007F434(D_800AF470.p);
    func_80080828((char *)D_800AF470.p + 0x4F0);
    {
        char *g1 = (char *)D_800AF470.p;
        v = 1;
        if (FIELD_AT(g1, int, 0x560) != 0) {
            v = FIELD_AT(g1, int, 0x564);
            FIELD_AT(g1, int, 0x560) = 0;
        }
        FIELD_AT(g1, int, 0x568) = v;
    }
    FIELD_AT(D_800B4DD0.p, unsigned short, 0x1F6)++;
    g = (char *)D_800AF470.p;
    FIELD_AT(self, int, 0x33C) = 1;
    FIELD_AT(self, int, 0x344) = 1;
    FIELD_AT(self, int, 0x348) = 0;
    func_8007FC90(g, -1);
    if (FIELD_AT(self, int, 0x370) == 1) {
        char *b = FIELD_AT(self, char *, 0x328) ? FIELD_AT(self, char *, 0x328) + 0xB8 : 0;
        void *o = FIELD_AT(b, void *, 0x8);
        func_80043DC0(o);
        func_80072970(o);
        func_80074564(o);
        func_8007E214(FIELD_AT(self, void *, 0x328));
        func_8007CC14(FIELD_AT(self, Derived_8007CC14 *, 0x328));
    }
    func_8007CCB4(FIELD_AT(self, void *, 0x328));
    if (FIELD_AT(self, int, 0x370) != 1) {
        char *b = (char *)D_800B4ED8[0];
        FIELD_AT(b, int, 0x278) = 3;
        FIELD_AT(b, int, 0x26C) = 0;
        func_8006BB04(b);
        func_8007F89C(D_800AF470.p);
    } else {
        ((int (*)(void *, int))func_8006B540)(D_800B4ED8[0], 0);
    }
}
