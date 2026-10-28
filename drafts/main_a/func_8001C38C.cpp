// func_8001C38C (u_8001C2D0): destructor of a class with a virtual base (vb at +0, base S_8002C6D4 dtor inlined).
// 2 instructions off: before the jal func_8002AFEC, retail sets `a1 = 0` before `v0 = &tmp`; here they're swapped.
// Tried: adj vs inline delta, inline base dtor with/without flags param, z temp, separate vb local.
struct VEnt_C38C { short d; short i; void *f; };
struct VTab50_C38C { VEnt_C38C e[10]; };
EXTERN_C const VTab50_C38C D_80010210;
EXTERN_C const VTab50_C38C D_8001162C;
EXTERN_C void *D_80010260[];
EXTERN_C void *D_80010288[];
EXTERN_C void *D_80010278[];
EXTERN_C void *D_8001167C[];
struct S_VB_C38C { VEnt_C38C *vt; };
struct S_8001C38C {
    S_VB_C38C *vb;
    char pad4[0x28];
    void **vt2C;
    char pad30[0x20];
    void **vt50;
    char pad54[0x88];
    void **vtDC;
    char padE0[0x68];
    void **vt148;
    char pad14C[0x8];
    char unk154[0x12C];
    char unk280[0x4];
};
EXTERN_C void func_80023AEC(void *p, int flags);
EXTERN_C void func_8002AFEC(void *p, int flags);
inline void dtor_8002C6D4(S_8001C38C *p, int flags)
{
    p->vt2C = D_8001167C;
    p->vb->vt = (VEnt_C38C *)D_8001162C.e;
    if (!flags) {
        VTab50_C38C tmp = D_8001162C;
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - 0x50;
        int adj = (char *)p - q;
        tmp.e[1].d = D_8001162C.e[1].d + adj;
        tmp.e[5].d = D_8001162C.e[5].d + adj;
        tmp.e[7].d = D_8001162C.e[7].d + adj;
        tmp.e[9].d = D_8001162C.e[9].d + adj;
    }
    func_8002AFEC(p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}
//// func_8001C38C
EXTERN_C void func_8001C38C(S_8001C38C *p, int flags)
{
    p->vtDC = D_80010260;
    p->vt50 = D_80010288;
    p->vt148 = D_80010278;
    p->vt2C = D_8001167C;
    p->vb->vt = (VEnt_C38C *)D_80010210.e;
    if (!flags) {
        VTab50_C38C tmp = D_80010210;
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - 0x3AC;
        tmp.e[1].d = D_80010210.e[1].d + ((char *)p - q);
        tmp.e[5].d = D_80010210.e[5].d + ((char *)p - q);
        tmp.e[7].d = D_80010210.e[7].d + ((char *)p - q);
        tmp.e[9].d = D_80010210.e[9].d + ((char *)p - q);
    }
    func_80023AEC(p->unk280, 2);
    func_80023AEC(p->unk154, 2);
    func_8001E508((char *)p + 0x50, 0);
    dtor_8002C6D4(p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}
