/* func_8003F3DC: near miss. 53 differing: logic and size match; only register allocation (retail: p=s0 s=s1 q=s2 i=s3 and i copied from v0 after the beqz). Needs a2b.h plus func_800402A8/func_800948B4 prototypes. */
EXTERN_C char *func_800402A8(void *p, short i);
EXTERN_C void func_800948B4(int a, int b, int c);
EXTERN_C void func_8003F3DC(void *p, void *q)
{
    int i = AT(p, int, 0x1CC);
    if (i) {
        for (; i < AT(q, short, 0xE); i++) {
            char *s = func_800402A8(q, AT(f40294(q, (short)i), short, 0xC));
            while (s) {
                signed char sc = *(signed char *)s;
                unsigned c = (unsigned char)*s;
                if (!sc)
                    break;
                if ((c & 0x30) == 0x20) {
                    func_800948B4(((AT(p, unsigned, 0x110) >> 22) & 3) + 1, 0x60, 0x40);
                    s++;
                } else {
                    unsigned h = sc & 0xF0;
                    if ((c & 0x30) == 0x30) {
                        if (((A2VObj0 *)p)->v03(c & 1) && AT(q, short, 0x36)) {
                            func_8008EF40((AT(q, unsigned short, 0x1C) << 16) + AT(p, short, 0x1A4) * 0x20 + AT(p, short, 0x1A2) + 1);
                            AT(p, short, 0x1A2)++;
                        }
                    } else if ((h == 0x40 || h == 0x50) && AT(q, short, 0x36)) {
                        unsigned u = AT(q, unsigned short, 0x1C);
                        int r;
                        unsigned x = u & 0xF;
                        int in = x < 6 ? 0 : x < 12;
                        if (in)
                            r = (u << 16) + AT(p, short, 0x1A4) * 0x20;
                        else
                            r = u << 16;
                        func_8008EF40(r + (c & 0xF) + 1);
                    }
                    s++;
                }
            }
        }
    }
}
