// func_8001B46C (u_8001986C): ctor of the main game object (vbase at +0x3AC; counterpart of the dtor func_8001C38C).
// 2 instructions off: in the `if (!D_800B4C54) func_80026214(S_Rect2_986C(0x400, 0x200))` temp, retail stores the
// size half through $sp (0x6C/0x6E($sp)); here GCC uses 0x4/0x6($s0) ($s0 = the same temp address). Store-order
// variants of the 2-arg ctor and nested/flat layouts tried. Needs the h_u_8001986C.h types (S_Pt4_986C etc.).
inline void *operator new(unsigned int, void *p) { return p; }
struct VTab50_986C { VEnt_986C e[10]; };
EXTERN_C const VTab50_986C D_80010210;
EXTERN_C void *D_80010498[];
EXTERN_C void *D_80010260[];
EXTERN_C void *D_80010288[];
EXTERN_C void *D_80010278[];
EXTERN_C void *D_8001167C[];
EXTERN_C void *D_800104A8[];
EXTERN_C int D_800B4C38 __attribute__((section(".data")));
EXTERN_C char D_800B4C90[];
EXTERN_C char D_800B4C80[];
EXTERN_C char D_800A4554[];
struct S_VB_986C {
    VEnt_986C *vt;
    int unk4;
    S_VB_986C() { vt = (VEnt_986C *)D_80010178; unk4 = 0; vt = (VEnt_986C *)D_800104A8; }
};
struct S_Size_986C {
    short w, h;
    S_Size_986C(short a, short b) : w(a), h(b) {}
};
struct S_GameV_986C {
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(int x, int y);
};
struct S_8001B46C {
    S_VB_986C *vb;
    char pad4[0x28];
    VEnt_986C *vt2C;
    char pad30[0x20];
    void **vt50;
    char pad54[0x88];
    void **vtDC;
    char padE0[0x68];
    void **vt148;
    int unk14C;
    char pad150[0x4];
    char unk154[0x9C];
    char unk1F0[0x90];
    char unk280[0x9C];
    char unk31C[0x90];
    void v9(int x, int y) { VEnt_986C *e = &vt2C[9]; ((void (*)(void *, int, int))e->f)((char *)this + e->d, x, y); }
};
EXTERN_C void func_8002C2B8(void *p, int in_chrg);
EXTERN_C void func_8001E40C(void *p, int in_chrg, int a, int b, int c);
EXTERN_C void func_80022FB8(void *p, int a);
EXTERN_C void SsUtReverbOff();
EXTERN_C void PadInitDirect(void *a, void *b);
EXTERN_C void func_80035BF8();
struct S_Rect2_986C {
    short x, y, w, h;
    S_Rect2_986C(short aw, short ah) { w = aw; x = 0; y = 0; h = ah; }
    S_Rect2_986C(short ax, short ay, short aw, short ah) { x = ax; y = ay; w = aw; h = ah; }
};
struct S_8002900C_986C {
    char pad[0x3C];
    S_8002900C_986C(int a, int b, int c, int d, const S_Rect2_986C &r) asm("func_8002900C");
};
EXTERN_C void func_80026214(const S_Rect2_986C &r);
EXTERN_C void func_80021300(S_RectPS_986C *r, int a);
EXTERN_C void func_8002A400(void *p, void *q);
EXTERN_C void func_8002A37C(void *p, void *q);
EXTERN_C int func_8001E07C(void *p, int a);
//// func_8001B46C
EXTERN_C void *func_8001B46C(S_8001B46C *p, int in_chrg, const S_Size_986C &sz, int mode, int arg)
{
    VTab50_986C tmp;
    if (in_chrg) {
        p->vb = (S_VB_986C *)((char *)p + 0x3AC);
        new ((char *)p + 0x3AC) S_VB_986C;
    }
    func_8002C2B8(p, 0);
    func_8001E40C((char *)p + 0x50, 0, (unsigned short)mode, arg, 0);
    p->vt148 = D_80010498;
    p->vb->vt = (VEnt_986C *)D_80010210.e;
    if (!in_chrg) {
        tmp = D_80010210;
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - 0x3AC;
        tmp.e[1].d = D_80010210.e[1].d + ((char *)p - q);
        tmp.e[5].d = D_80010210.e[5].d + ((char *)p - q);
        tmp.e[7].d = D_80010210.e[7].d + ((char *)p - q);
        tmp.e[9].d = D_80010210.e[9].d + ((char *)p - q);
    }
    p->vtDC = D_80010260;
    p->vt50 = D_80010288;
    p->vt148 = D_80010278;
    p->vt2C = (VEnt_986C *)D_8001167C;
    p->unk14C = 0;
    func_80022FB8(p->unk154, 0);
    func_80022FB8(p->unk280, 1);
    SsUtReverbOff();
    PadInitDirect(p->unk1F0, p->unk31C);
    func_80035BF8();
    new S_8002900C_986C(0, 0, 0, 2, S_Rect2_986C(0, 0, sz.w * 2, sz.h));
    if (!D_800B4C54)
        func_80026214(S_Rect2_986C(0x400, 0x200));
    short x = (sz.w + 127) / 128 * 256;
    S_Pt4_986C pos = D_800B4C54->f4(S_Pt4c_986C(x, sz.h));
    if (!D_800B4C38) {
        S_Pt4c_986C pt(x, 0x100 - sz.h);
        func_80021300(&S_RectPS_986C(D_800B4C54->f4(pt), pt.pt()), 0);
    }
    D_800B4C54->f5(pos);
    func_8002CDC0(&S_RectPS_986C(D_800B4C54->f4(S_Pt4c_986C(sz.w * 2, sz.h)), *(S_Pt4_986C *)&sz));
    ((S_8001B46C *)p)->v9(sz.w, sz.h);
    func_8002A400(p, D_800B4C90);
    func_8002A37C(p, D_800B4C80);
    while (func_8001E07C(D_800A4554, -0x8000))
        ;
    return p;
}
