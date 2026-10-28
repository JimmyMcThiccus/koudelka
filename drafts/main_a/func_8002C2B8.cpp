// func_8002C2B8 (u_80029BBC): most-derived ctor of the func_8002C6D4 class, with the func_8002C188 ctor inlined
// (not in charge). 6 instructions differ: retail forms &t1 as `addiu $a1, $zero, 0x10; addu $v0, $sp, $a1` (sharing
// the 0x10 later passed to func_800198E0) and schedules the first two delta fixups differently. Types in
// include/game/a/h_u_80029BBC.h.
struct S_8002C2B8 : S_8002C188 { };

EXTERN_C S_8002C2B8 *func_8002C2B8(S_8002C2B8 *p, int in_chrg)
{
    VTab50 t1, t2;
    if (in_chrg) {
        p->vb = (S_VB50 *)((char *)p + 0x50);
        new ((char *)p + 0x50) S_VB30;
    }
    func_80029C54((S_W *)p, 0, 2);
    p->vb->vt = (VEnt *)D_800114CC.e;
    {
        t1 = D_800114CC;
        p->vb->vt = t1.e;
        char *q = (char *)p->vb - 0x50;
        int adj = (char *)p - q;
        t1.e[1].d = D_800114CC.e[1].d + adj;
        t1.e[5].d = D_800114CC.e[5].d + adj;
        t1.e[7].d = D_800114CC.e[7].d + adj;
        t1.e[9].d = D_800114CC.e[9].d + adj;
    }
    p->vt2C = D_8001151C;
    S_8002C188m *m = (S_8002C188m *)((char *)p + 0x30);
    m->vbp = m->vbase;
    m->vb = m->vbase;
    func_800198E0(m->vbp, 0x10, 4);
    m->idx = 0;
    p->vb->vt = (VEnt *)D_8001162C.e;
    if (!in_chrg) {
        t2 = D_8001162C;
        p->vb->vt = t2.e;
        char *q = (char *)p->vb - 0x50;
        int adj = (char *)p - q;
        t2.e[1].d = D_8001162C.e[1].d + adj;
        t2.e[5].d = D_8001162C.e[5].d + adj;
        t2.e[7].d = D_8001162C.e[7].d + adj;
        t2.e[9].d = D_8001162C.e[9].d + adj;
    }
    p->vt2C = D_8001167C;
    ((S_W *)p)->unk20 = 0;
    return p;
}
