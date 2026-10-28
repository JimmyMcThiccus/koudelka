/* main_b round 2: near misses in u_80082174 (helper attempts). Not built.
   func_80089AC0  6 diffs  regalloc only: dst pointer and (f-e+1) divisor swap t1/t2
   func_8008687C  12 diffs  &t1/&t2 address pseudos swap s0/s1; final 8-byte copy scheduled differently
   func_80089B44  9 diffs  regalloc only: b/c source pointers swap s2/s3
   func_8008A770  30 diffs  retail copies the 0x550 pointer into v1 before the 0x8A load (one extra move); conversion result in a0 vs v1
   func_80086578  7 diffs  second loop: x gets an extra andi 0xFFFF copy; retail keeps x in a2 and copies m (v1->v0) before the test
   func_8008B150  62 diffs  4 pointer args (a1-a3 + stack) all homed and stored straight from regs to 0x550..; arg form (struct by value / 4 params / varargs) not found
   func_8008A188  7 diffs  final compare: regs for hi()/0x496/0x420 loads rotated (a0/v0/v1 vs v1/a0/v0)
   func_800849D0  ~65 diffs  retail loads the stack short param (0x44) at the very top, before the 16-byte by-value struct copy; everything else same
   func_80089BF4  14 diffs  regalloc only: s1..s4 permuted (retail c=s1,b=s2,dst=s3,min=s4)
   func_800824C8  not attempted  header prototype is func_800824C8(void *self) but the asm uses a second arg (sw a1,0x34(a0)); func_800824A0 calls it with one arg
   func_80088C8C  23 diffs  q->0x90 / mask loads land in swapped regs, and GCC CSEs the constant 1 for both 0x76++ and return 1 (retail uses addiu +1 and li v0,1 separately)
   func_80088794  13 diffs  same as 80088C8C: (q->0x90 & mask) result/operand regs v0/v1 swapped; control flow and loads all match
   func_8008586C  8 diffs  regalloc only: the 0x4BD value (==1) and the 0x550->0x1B byte swap s2/s3
   func_8008A2A0  3 diffs  only the final (sa+sb) < (ta+tb): the two sums land in v1/v0 instead of v0/v1
   func_8008891C  ~200 diffs (mostly a 1-insn shift)  body all matches structurally; differences: beq delay slot after (q != self) left empty (nop) where retail fills it with addu a0,s4, and the (q->0x90 & mask) operand regs as in 80088794
   func_800891C0 / func_800883A0  not attempted (large bit-twiddling / size)
   func_8008B30C func_80084454 func_80084130 func_80089FD0  not attempted: virtual-base ctor/dtors that copy a vtable to the stack and patch thunk deltas (needs the real class hierarchy)
*/
extern "C" void func_8008691C(void *self);

extern "C" void func_80086990(void *self, int n, signed char *first, ...);
extern "C" void func_80089804(char *out, char *src, int idx, int lo, int hi);
extern "C" E8C_8008A188 D_800AEBD4[];

extern "C" void func_80088114(void *self, int b);
extern "C" void func_8008805C(void *self, void *b, int c, int d);
extern "C" void func_80087EF4(void *self, void *b, int c, int d);
extern "C" void func_80087D98(void *self, void *b, int c, int d);
extern "C" void func_80088310(void *self, void *b);
struct Q_80088794 { char pad[0x8C]; short c; short d; unsigned short f; };

static inline void post_8008586C(void *self, short t, short s, int c, int d)
{
    char *p = (char *)func_8001CA10(0x14);
    FIELD_AT(p, void *, 0) = D_80010178;
    FIELD_AT(p, int, 4) = 0;
    FIELD_AT(p, void *, 0) = D_80010300;
    FIELD_AT(p, short, 8) = t;
    FIELD_AT(p, short, 0xA) = s;
    FIELD_AT(p, int, 0x10) = d;
    FIELD_AT(p, int, 0xC) = c;
    FIELD_AT(p, void *, 0) = D_800102D0;
    func_8001EFE4(self, p);
}

extern "C" int func_80087284(void *self, void *b);
extern "C" void func_80087FC4(void *self, void *b, int c);
extern "C" void func_80087AF4(void *self, void *b, int c);
extern "C" void func_80087E50(void *self, void *b, int c);
extern "C" void func_80087A58(void *self, void *b, int c);
extern "C" void func_80087CFC(void *self, void *b, int c);
extern "C" void func_800879CC(void *self, void *b, int c);
extern "C" void func_80087B78(void *self, char *b, int c);
extern "C" void func_8008792C(void *self, char *b, int c);
//// func_80089AC0
extern "C" unsigned char *func_80089AC0(unsigned char *a, unsigned char *b, unsigned char *c, unsigned int d, unsigned int e, unsigned int f)
{
    unsigned int range = f - e + 1;
    unsigned int span = d - e;
    unsigned char *dst = a;
    unsigned int i = 0;
    while (i < 8) {
        i++;
        int lo = *b++;
        int hi = *c++;
        *dst++ = ((hi - lo + 1) * span) / range + lo;
    }
    return a;
}

//// func_8008687C
extern "C" void func_8008687C(char *self, int b)
{
    Col_800899AC t3;
    Col_800899AC t2;
    Col_800899AC t1;
    Col_800899AC *p2;
    Col_800899AC *p1;
    if (b) {
        p1 = &t1;
        func_800899AC(p1, (Col_800899AC *)(self + 0x24), (signed char *)(self + 0x2C));
        p2 = &t2;
        func_800899AC(p2, p1, (signed char *)(self + 0x84));
    } else {
        p2 = &t2;
        func_800899AC(p2, (Col_800899AC *)(self + 0x24), (signed char *)(self + 0x2C));
    }
    func_800899AC(&t3, p2, (signed char *)(self + 0x34));
    FIELD_AT(self, int, 0x3C) = t3.w[0];
    FIELD_AT(self, int, 0x40) = t3.w[1];
    func_80089D80((unsigned char *)(self + 0x3C), 0xB4);
}

//// func_80089B44
extern "C" signed char *func_80089B44(signed char *a, signed char *b, signed char *c)
{
    signed char *dst = a;
    for (unsigned int i = 0; i < 8; i++) {
        int lo = *b++;
        *dst++ = ((*c++ - lo + 1) * rand()) / 0x8000 + lo;
    }
    return a;
}

//// func_8008A770
extern "C" int func_8008A770(char *self, int b, int c)
{
    if (!func_8008A54C(self, 1)) {
        return 0;
    }
    FIELD_AT(self, W20_80089658, 0x484) = *FIELD_AT(self, W20_80089658 *, 0x550);
    FIELD_AT(self, char *, 0x498) = FIELD_AT(self, char *, 0x550) ? FIELD_AT(self, char *, 0x550) + 0x14 : 0;
    FIELD_AT(self, char *, 0x544) = FIELD_AT(self, char *, 0x550);
    func_8008B4E8(&((T_8008A858 *)self)->d[(FIELD_AT(FIELD_AT(self, unsigned char *, 0x544), unsigned char, 0x8A) & 0xF) - 1], 0x28);
    func_8008687C(self ? self + 0x400 : 0, 0);
    return func_800D9048(self ? self + 0x400 : 0, b, c);
}

//// func_80086578
extern "C" Vec_80086670 *func_80086578(Vec_80086670 *a, void *b)
{
    unsigned short tmp[5];
    unsigned short *p = (unsigned short *)a;
    unsigned short *q = (unsigned short *)b;
    unsigned int i;
    for (unsigned int k = 0; k < 5; k++) {
        tmp[k] = 0;
    }
    for (i = 0; i < 5; i++) {
        unsigned short v = *p | *q++;
        *p++ = v;
        for (unsigned int j = 0; j < 5; j++) {
            if (j != i) {
                tmp[j] |= v;
            }
        }
    }
    p = (unsigned short *)a;
    for (i = 0; i < 5; i++) {
        unsigned short x = *p;
        unsigned short m = x & (x >> 1) & 0x5500;
        if (m) {
            unsigned short mm = m | (m << 1);
            *p = x & ~((tmp[i] & mm) ? (tmp[i] & mm) : mm);
        }
        p++;
    }
    return a;
}

//// func_8008B150
extern "C" void func_8008B150(char *self, P4_8008B150 s)
{
    char **pp = s.p;
    int i = 0;
    FIELD_AT(self, P4_8008B150, 0x550) = s;
    func_8008655C((short *)(self + 0x44E));
    for (; i < 4; i++) {
        if (*pp != 0) {
            func_80086578((Vec_80086670 *)(self + 0x44E), *pp + 0x80);
        }
        pp++;
    }
    func_80086990(self ? self + 0x400 : 0, 4, (signed char *)s.p[0], s.p[1], s.p[2], s.p[3]);
    FIELD_AT(self, char, 0x46C) = (s.p[1] ? FIELD_AT(s.p[1], unsigned char, 0xE) : 0) | (s.p[2] ? FIELD_AT(s.p[2], unsigned char, 0xE) : 0) | (s.p[3] ? FIELD_AT(s.p[3], unsigned char, 0xE) : 0);
}

//// func_8008A188
extern "C" int func_8008A188(char *self, int i)
{
    int r;
    func_80089804(self + 0x484, (char *)&D_800AEBD4[i], ((T_8008A858 *)self)->e[i].hi(), 0, 2);
    FIELD_AT(self, char *, 0x498) = D_800AEBD4[i].sub;
    func_8008687C(self ? self + 0x400 : 0, FIELD_AT(self, unsigned char, 0x497) == 0);
    FIELD_AT(self, short, 0x480) = muldiv2_80086EF0(FIELD_AT(FIELD_AT(self, unsigned char *, 0x498), unsigned char, 1), 0x100, FIELD_AT(self, unsigned char, 0x43E));
    r = 0;
    if (!(FIELD_AT(self, unsigned char, 0x46D) & 0x40)) {
        int sh = ((T_8008A858 *)self)->e[i].hi();
        int lim = FIELD_AT(self, unsigned char, 0x496) << sh;
        r = !(FIELD_AT(self, short, 0x420) < lim);
    }
    return r;
}
//// func_800849D0
extern "C" void func_800849D0(char *self, S16_800849D0 s, short e, int f)
{
    FIELD_AT(self, S16_800849D0, 0x518) = s;
    FIELD_AT(self, short, 0x528) = e;
    if (FIELD_AT(self, signed char, 0x517) == 0) {
        FIELD_AT(self, short, 0x52A) = 1;
        return;
    }
    func_8008299C(self ? self + 0x2A0 : 0, 0x1F, FIELD_AT(self, int, 0x518), FIELD_AT(self, int, 0x51C), FIELD_AT(self, int, 0x520), FIELD_AT(self, short, 0x528), 0);
    if (FIELD_AT(self, unsigned short, 0x52A) < 2) {
        func_8008299C(self ? self + 0x2A0 : 0, 0x1C, 1, 0, 0, 0, 0);
        FIELD_AT(self, short, 0x52A) = 2;
    }
    if (f) {
        func_80082E14(self ? self + 0x2A0 : 0, 0);
    }
}

//// func_80089BF4
extern "C" signed char *func_80089BF4(signed char *a, signed char *b, signed char *c, int d)
{
    int mn = -((unsigned char)d * (unsigned char)d);
    int range = (0x100 - (unsigned char)d) * (0x100 - (unsigned char)d) - mn;
    signed char *dst = a;
    for (unsigned int i = 0; i < 8; i++) {
        int t = (rand() & 0xFF) - (unsigned char)d;
        int w = (t >= 0 ? t * t : -t * t) - mn;
        int lo = *b++;
        *dst++ = ((*c++ - lo + 1) * w) / range + lo;
    }
    return a;
}

//// func_80088C8C
extern "C" int func_80088C8C(char *self, char *b)
{
    char *q = 0;
    if (b != 0) {
        q = b + 0x400;
    }
    func_8008691C(self);
    if (q != self) {
        func_8008687C(self, 0);
    }
    FIELD_AT(self, unsigned char, 0x6D) |= 1;
    unsigned short *m = &FIELD_AT(self, unsigned short, 0x62);
    FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(q, unsigned short, 0x90) & m[1];
    if (FIELD_AT(self, unsigned short, 0x14)) {
        func_8008805C(self, b, FIELD_AT(q, short, 0x8C), FIELD_AT(q, short, 0x8E));
    } else {
        FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(q, unsigned short, 0x90) & m[2];
        if (FIELD_AT(self, unsigned short, 0x14)) {
            func_80088114(self, (int)b);
        } else {
            FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(q, unsigned short, 0x90) & m[3];
            if (FIELD_AT(self, unsigned short, 0x14)) {
                func_80087EF4(self, b, FIELD_AT(q, short, 0x8C), FIELD_AT(q, short, 0x8E));
            } else {
                FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(q, unsigned short, 0x90) & m[4];
                if (FIELD_AT(self, unsigned short, 0x14)) {
                    func_80087D98(self, b, FIELD_AT(q, short, 0x8C), FIELD_AT(q, short, 0x8E));
                } else {
                    func_80087C2C(self, b, FIELD_AT(q, short, 0x8C), FIELD_AT(q, short, 0x8E));
                }
            }
        }
    }
    FIELD_AT(self, unsigned char, 0x6D) &= ~1;
    FIELD_AT(self, char, 0x76)++;
    return 1;
}
//// func_80088794
extern "C" int func_80088794(char *self, char *b)
{
    Q_80088794 *q = 0;
    if (b != 0) {
        q = (Q_80088794 *)(b + 0x400);
    }
    func_8008691C(self);
    FIELD_AT(self, unsigned char, 0x6D) &= 0xE2;
    func_80086DB4((Obj_80086DB4 *)self);
    if ((char *)q != self) {
        func_8008687C(self, 0);
    }
    if (q->f & FIELD_AT(self, unsigned short, 0x62)) {
        func_80088310(self, b);
    } else {
        for (FIELD_AT(self, char, 0x76) = 0; FIELD_AT(self, signed char, 0x76) < FIELD_AT(b, signed char, 0x475); FIELD_AT(self, char, 0x76)++) {
            unsigned short *m = &FIELD_AT(self, unsigned short, 0x62);
            int c = q->c;
            int d = q->d;
            if ((FIELD_AT(self, unsigned short, 0x14) = q->f & m[1])) {
                func_8008805C(self, b, c, d);
            } else if ((FIELD_AT(self, unsigned short, 0x14) = q->f & m[2])) {
                func_80088114(self, (int)b);
            } else if ((FIELD_AT(self, unsigned short, 0x14) = q->f & m[3])) {
                func_80087EF4(self, b, c, d);
            } else if ((FIELD_AT(self, unsigned short, 0x14) = q->f & m[4])) {
                func_80087D98(self, b, c, d);
            } else {
                func_80087C2C(self, b, c, d);
            }
        }
    }
    return 1;
}
//// func_8008586C
extern "C" void func_8008586C(char *self, int b)
{
    int k;
    if (FIELD_AT(self, signed char, 0x4BD) != 1) {
        return;
    }
    k = FIELD_AT(FIELD_AT(self, char *, 0x550), unsigned char, 0x1B);
    switch (b) {
    case -1:
        func_80071D90(self, 0, 1);
        FIELD_AT(self, char, 0x4F1) = 0;
        FIELD_AT(self, short, 0x4F2) = b;
        break;
    case 0:
        if (k != 0x4C) {
            func_80071D90(self, 0, 1);
            FIELD_AT(self, char, 0x4F1) = 0;
        }
        FIELD_AT(self, short, 0x4F2) = k;
        break;
    case 1:
        if (FIELD_AT(self, signed char, 0x4F1) == 0) {
            post_8008586C(self, 2, 0xC, 0, 100);
            FIELD_AT(self, char, 0x4F1) = 1;
        }
        FIELD_AT(self, short, 0x4F2) = k;
        break;
    case 2:
        if (FIELD_AT(self, signed char, 0x4F1) == 0 || FIELD_AT(self, short, 0x4F2) != k) {
            post_8008586C(self, 2, 0xC, 0, 100);
            FIELD_AT(self, char, 0x4F1) = 1;
        }
        FIELD_AT(self, short, 0x4F2) = k;
        break;
    }
}
//// func_8008A2A0
extern "C" int func_8008A2A0(char *self)
{
    int n = 0;
    int sa = 0;
    int sb = 0;
    int i;
    for (i = 0; i < 3; i++) {
        char *e = (char *)D_800AFA58[i];
        if (e != 0) {
            if (FIELD_AT(e, unsigned char, 0x948)) {
                return 0;
            }
            ((VObj<0x9C> *)(e + 0x400))->v01();
            n++;
            sa += FIELD_AT(e, unsigned char, 0x43E);
            sb += FIELD_AT(e, unsigned char, 0x443);
        }
    }
    if (n == 0) {
        return 1;
    }
    sa = sa * rand() / n;
    sb = sb * rand() / n;
    n = 1;
    ((VObj<0x9C> *)(self ? self + 0x400 : 0))->v01();
    int ta = FIELD_AT(self, unsigned char, 0x43E);
    int tb = FIELD_AT(self, unsigned char, 0x443);
    for (int j = 0; j < 3; j++) {
        char *e = (char *)D_800AFA64[j];
        VObj<0x9C> *o = (VObj<0x9C> *)(e + 0x400);
        if (e != 0) {
            o->v01();
            n++;
            ta += FIELD_AT(e, unsigned char, 0x43E);
            tb += FIELD_AT(e, unsigned char, 0x443);
        }
    }
    ta = ta * rand() / n;
    tb = tb * rand() / n;
    return ta + tb > sa + sb;
}
//// func_8008891C
extern "C" int func_8008891C(char *self, char *b)
{
    char *q = 0;
    if (b != 0) {
        q = b + 0x400;
    }
    func_8008691C(self);
    if (q != self) {
        func_8008687C(self, 0);
    }
    Quad_80086380 p1 = FIELD_AT(func_8008672C(self), Quad_80086380, 0x4C6);
    Quad_80086380 p2 = FIELD_AT(b, Quad_80086380, 0x4C6);
    int dist = SquareRoot0(((p1.a - p2.a) * (p1.a - p2.a) + (p1.c - p2.c) * (p1.c - p2.c)) * 5);
    FIELD_AT(self, unsigned char, 0x6D) |= 1;
    int n = FIELD_AT(q, unsigned char, 0x41) - (FIELD_AT(self, unsigned char, 0x41) >> 1);
    if (n != 0) {
        int k = func_80087284(self, q + 0x84) * 328;
        int dmg = 0;
        for (int i = 0; i < n; i++) {
            if (rand() < k) {
                int r1 = rand();
                int r2 = rand();
                int t = FIELD_AT(q, unsigned char, 0x42) + r1 * FIELD_AT(q, unsigned char, 0x43) / 0x10000 - dist
                        - (FIELD_AT(self, unsigned char, 0x40) + r2 * FIELD_AT(self, unsigned char, 0x43) / 0x8000) / 2;
                if (t < 0) {
                    t = 0;
                }
                dmg += t;
            }
        }
        unsigned short *m = &FIELD_AT(self, unsigned short, 0x62);
        if ((FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(q, unsigned short, 0x90) & m[1])) {
            if (FIELD_AT(self, unsigned short, 0x14) & 0x100) {
                func_80087FC4(self, b, dmg);
            } else {
                func_80087AF4(self, b, dmg);
            }
        } else if ((FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(q, unsigned short, 0x90) & m[2])) {
            func_80088114(self, (int)b);
        } else if ((FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(q, unsigned short, 0x90) & m[3])) {
            if (FIELD_AT(self, unsigned short, 0x14) & 0x100) {
                func_80087E50(self, b, dmg);
            } else {
                func_80087A58(self, b, dmg);
            }
        } else if ((FIELD_AT(self, unsigned short, 0x14) = FIELD_AT(q, unsigned short, 0x90) & m[4])) {
            if (FIELD_AT(self, unsigned short, 0x14) & 0x100) {
                func_80087CFC(self, b, dmg);
            } else {
                func_800879CC(self, b, dmg);
            }
        } else if (FIELD_AT(q, unsigned short, 0x90) & 0x100) {
            func_80087B78(self, b, dmg);
        } else {
            func_8008792C(self, b, dmg);
        }
    }
    FIELD_AT(self, unsigned char, 0x6D) &= ~1;
    FIELD_AT(self, char, 0x76)++;
    return 1;
}
