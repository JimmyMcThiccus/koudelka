/* func_8003C5EC: near miss. 70 differing: structure matches (compare func_8003BF30), allocation differs (retail p=s2 a=s4 v=s3 o=s0 t=s1). Needs a2b.h plus a2.h. */
EXTERN_C void *D_8001276C[];
EXTERN_C void func_8003C5EC(void *p, int a)
{
    AT(p, void **, 0) = D_8001276C;
    if (AT(p, void *, 8)) {
        if (AT(p, int, 0xC)) {
            ((A2VObj0 *)AT(p, void *, 8))->v01();
        } else {
            void *o = operator new(0xC);
            char *v = 0;
            char *t = 0;
            if (AT(p, char *, 8))
                v = AT(p, char *, 8) - 8;
            AT(o, void **, 0) = D_80010160;
            AT(o, int, 4) = 0;
            char *g = (char *)&D_800AC57C;
            if (g) t = g + 0xF8;
            func_8001D150(t, new S_A2_X1(o));
            AT(o, void **, 0) = D_80010148;
            AT(o, void *, 8) = v;
        }
    }
    if (AT(p, void *, 0x14))
        delete (A2VObj0 *)AT(p, void *, 0x14);
    if (AT(p, void *, 0x18))
        operator delete(AT(p, void *, 0x18));
    func_8001A610(p, a);
}
