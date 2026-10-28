// __10C_800BFE58i (C_800BFE58::C_800BFE58(int)): 3 differ (same size). Needs B_8001E40C moved into capture.h with C_800BFE58 : B_8001E40C (and vt2 renamed vt8C in C_800BFC28/C_800BDEB0/C_800BF80C, pad2 = 0x5E0 - sizeof(C_800BFC28)). Left: retail copies this to $v0 before the D_800B4ED8 load (hi in $v1); here the copy comes after the load (hi in $v0).
EXTERN_C char D_800B7404[];
EXTERN_C char D_800B741C[];
EXTERN_C void *ctor_800C23F8(void *) asm("__10C_800C23F8");
EXTERN_C void *ctor_800C21E0(void *) asm("__10C_800C21E0");
EXTERN_C char *func_800C1E24(char *p);
EXTERN_C char *func_800C2044(char *p, char a, short b);
EXTERN_C char *func_800C2F6C(char *p);
EXTERN_C void *D_800B4ED8[];
struct Mem_800BFE58 { int pad; int f4; };
C_800BFE58::C_800BFE58(int a) : B_8001E40C(a, 2, 0x1000, 0)
{
    char *p = (char *)this;
    vt8C = D_800B7404;
    vt = D_800B741C;
    Mem_800BFE58 *m0 = (Mem_800BFE58 *)(p + 0x3E0);
    func_800BF518((char *)m0);
    Mem_800BFE58 *m1 = (Mem_800BFE58 *)(p + 0x408);
    func_800C1E24((char *)m1);
    Mem_800BFE58 *m2 = (Mem_800BFE58 *)(p + 0x428);
    func_800C2044((char *)m2, 0, 0);
    Mem_800BFE58 *m3 = (Mem_800BFE58 *)(p + 0x438);
    func_800C2F6C((char *)m3);
    Mem_800BFE58 *m4 = (Mem_800BFE58 *)(p + 0x448);
    ctor_800C23F8(m4);
    Mem_800BFE58 *m5 = (Mem_800BFE58 *)(p + 0x48C);
    ctor_800C21E0(m5);
    Vec_800BF80C *v = (Vec_800BF80C *)(p + 0x5B0);
    v->data = v->buf;
    v->p = v->buf;
    func_800198E0(v->data, 16, 0);
    void *g = D_800B4ED8[0];
    v->n = 0;
    *(int *)(p + 0x26C) = 1;
    p[0xF8] = 0;
    p[0xF9] = 0;
    *(short *)(p + 0x3D0) = 0;
    *(short *)(p + 0x3D2) = 0;
    *(void **)(p + 0x270) = g;
    m0->f4 = 0;
    m1->f4 = 0;
    m2->f4 = 0;
    m3->f4 = 0;
    m4->f4 = 0;
    m5->f4 = 0;
}
