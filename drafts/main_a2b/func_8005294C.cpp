/* func_8005294C: near miss. 44 differing: structure and size match; allocation differs (retail p=s1 u=s2 l=s3 &rect=s0; mine p=s2 u=s3 l=s0 &rect=s1). Needs a2b.h plus the aliases below. */
struct S_A2B_Rect { S_A2B_Pt a, b; S_A2B_Rect(short x, short y, short w, short h) : a(x, y), b(w, h) {} };
extern "C++" void *f53250(void *p, const S_A2B_Rect &r, void *t, int c) asm("func_80053250");
extern "C++" void *f2860C(void *p, const S_A2B_Rect &r, void *t, int c, int d) asm("func_8002860C");
extern "C++" void fAddL(List *l, void *e, int n) asm("func_80019A6C");
extern "C++" void f2DA94(int a, void *b) asm("func_8002DA94");
EXTERN_C char D_800B4C98[];
EXTERN_C int D_800B4C74;
EXTERN_C void func_8005294C(void *p, int s)
{
    if (AT(p, int, 8)) {
        func_8005C088(p, s, 1);
        unsigned short u = AT(p, unsigned short, 0x1C);
        List *l = AT(p, List *, 0x30) ? *AT(p, List **, 0x30) : 0;
        void *o = operator new(0x2C);
        void *r = f53250(o, S_A2B_Rect(0, 0, 0x140, 0xF0), D_800B4C98, u);
        fAddL(l, r, l->count);
        l = AT(p, List *, 0x30) ? *AT(p, List **, 0x30) : 0;
        o = operator new(0x50);
        r = f2860C(o, S_A2B_Rect(0, 0, 0x80, 0xF0), AT(p, void *, 0x48), AT(p, unsigned short, 0x1C), D_800B4C74);
        fAddL(l, r, l->count);
        l = AT(p, List *, 0x30) ? *AT(p, List **, 0x30) : 0;
        o = operator new(0x50);
        r = f2860C(o, S_A2B_Rect(0x80, 0, 0x80, 0xF0), AT(p, void *, 0x4C), AT(p, unsigned short, 0x1C), D_800B4C74);
        fAddL(l, r, l->count);
        l = AT(p, List *, 0x30) ? *AT(p, List **, 0x30) : 0;
        o = operator new(0x50);
        r = f2860C(o, S_A2B_Rect(0x100, 0, 0x40, 0xF0), AT(p, void *, 0x50), AT(p, unsigned short, 0x1C), D_800B4C74);
        fAddL(l, r, l->count);
        ((A2VObj<0x2C> *)p)->v28(0);
        f2DA94(s, AT(p, void *, 0x30));
    }
}
