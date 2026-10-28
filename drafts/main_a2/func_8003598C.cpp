/* func_8003598C: near miss. 15 differing: the four stack-arg loads (t3,t0,t1,t2) are scheduled at the start in ours, but after the third vtable store in retail. Store sequence and registers otherwise match (the p+0xC double store must be kept as two stores). Uses include/game/a2/a2.h. */
EXTERN_C void *D_800100F8[];
extern "C++" void *f3598C(void *p, int a, int b, int c, int e, int f, int g, int h) asm("func_8003598C");
void *f3598C(void *p, int a, int b, int c, int e, int f, int g, int h)
{
    AT(p, void **, 0) = D_80011FE4;
    AT(p, void **, 8) = D_800100F8;
    AT(p, void **, 0xC) = D_80010198;
    char *q = (char *)p + 8;
    AT(q, void **, 4) = D_800101C0;
    AT(p, void **, 8) = D_800101B0;
    AT(q, int, 8) = a;
    AT(q, short, 0xC) = f;
    AT(q, short, 0xE) = g;
    AT(q, short, 0x10) = h;
    AT(q, short, 0x12) = e;
    AT(p, void **, 0xC) = D_80012104;
    AT(p, void **, 8) = D_800120F4;
    AT(p, void **, 0) = D_8001211C;
    AT(p, int, 0x1C) = b;
    AT(p, int, 0x20) = 0;
    AT(p, int, 0x24) = c;
    return p;
}
