/* func_8003C5EC: near miss. 11 differing: allocation and size match; retail computes v=p8-8 (s3) before the base-ctor stores of the 0xC message (vt D_80010160, +4=0 via a copy of the pointer in $v0), mine stores first. Needs a2b.h plus a2.h. */
// exe.h declares the argument as void *; the typed struct is needed for the scheduling to match.
struct S_A2B_M160 { void *vt; int u4; void *u8; S_A2B_M160() { vt = D_80010160; u4 = 0; } };
struct S_A2B_C5EC { void *vt; int u4; void *p8; int pC; void *p10; void *p14; void *p18; };
EXTERN_C void func_8003C5EC_t(S_A2B_C5EC *p, int a) asm("func_8003C5EC");
EXTERN_C void func_8003C5EC_t(S_A2B_C5EC *p, int a)
{
    p->vt = D_8001276C;
    if (p->p8) {
        if (p->pC) {
            ((A2VObj0 *)p->p8)->v01();
        } else {
            S_A2B_M160 *o = new S_A2B_M160;
            char *v = 0;
            char *t = 0;
            if (p->p8)
                v = (char *)p->p8 - 8;
            char *g = (char *)&D_800AC57C;
            if (g) t = g + 0xF8;
            func_8001D150(t, new S_A2_X1(o));
            o->vt = D_80010148;
            o->u8 = v;
        }
    }
    if (p->p14)
        ((A2VObj0 *)p->p14)->v00(3);
    if (p->p18)
        operator delete(p->p18);
    func_8001A610(p, a);
}
