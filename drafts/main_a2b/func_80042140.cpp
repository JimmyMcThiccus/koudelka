/* func_80042140: near miss (virtual-base dtor, recipe form). 34 differing: register allocation only (retail copies the vtable through t0-t3 and keeps &p->vb in $a3; mine uses a3,t0-t2 and a2). Needs a2b.h; types here. */
EXTERN_C void *D_80012864[];
EXTERN_C void *D_8001289C[];
EXTERN_C void *D_8001287C[];
EXTERN_C void *D_800128CC[];
EXTERN_C void *D_80010508[];
EXTERN_C const S_A2B_VTab50 D_80012814_t asm("D_80012814");
EXTERN_C const S_A2B_VTab50 D_80010538_t asm("D_80010538");
EXTERN_C void f205D4(void *p) asm("func_800205D4");
EXTERN_C void *f1D25C(void *v, void *key) asm("func_8001D25C");
struct S_A2B_42140 {
    void *vt0; char pad4[0x8C - 4]; void *vt8C; char pad90[0x1DC - 0x90]; S_A2B_VBp *vb; void *vt1E0; void *vt1E4; void *p1E8;
    char pad1EC[0x22C - 0x1EC]; int u22C;
};
// exe.h has no entry for this; the typed struct keeps the vbase pointer accesses as in retail.
EXTERN_C void func_80042140_t(S_A2B_42140 *p, int flags) asm("func_80042140");
EXTERN_C void func_80042140_t(S_A2B_42140 *p, int flags)
{
    p->vt8C = D_80012864;
    p->vt1E0 = D_8001289C;
    p->vt1E4 = D_8001287C;
    p->vt0 = D_800128CC;
    p->vb->vt = (S_A2B_VEnt *)D_80012814_t.e;
    S_A2B_VTab50 tmp;
    if (!flags) {
        int adj;
        tmp = D_80012814_t;
        p->vb->vt = tmp.e;
        tmp.e[1].d = D_80012814_t.e[1].d + (adj = (char *)p - ((char *)p->vb - 0x2A0));
        tmp.e[6].d = D_80012814_t.e[6].d + adj;
    }
    f205D4(p ? &p->vt1E4 : 0);
    {
        char *g = D_800A4544;
        void *s1 = &p->u22C;
        void *r = f1D25C(g, s1);
        func_8001D324(g, r);
        void *o = func_8001CA10(0x14);
        ((S_A2B_E2D0 *)o)->init(2, 0xC, 0, 9);
        func_8001EFE4(p->p1E8, o);
        D_800B4D34--;
        func_8001D024(s1, 2);
    }
    func_8002EE9C(&p->vt1E4, 0);
    {
        S_A2B_VBp **pv = &p->vb;
        int adj;
        pv[1] = (S_A2B_VBp *)D_80010508;
        (*pv)->vt = (S_A2B_VEnt *)D_80010538_t.e;
        tmp = D_80010538_t;
        (*pv)->vt = tmp.e;
        tmp.e[1].d = D_80010538_t.e[1].d + (adj = (char *)pv - ((char *)*pv - 8));
        tmp.e[6].d = D_80010538_t.e[6].d + adj;
    }
    func_8003DC54(p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}
