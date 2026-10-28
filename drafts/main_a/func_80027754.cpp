// func_80027754 (u_80025854): forward a point to whichever of two child objects' rects contains it (vslot 5).
// Control flow matches; register allocation of the inline Rect::contains differs (retail result in $a3, rect
// in $a1, point in $a2) and the final call block is placed before the `return 0`.
struct S_Rc {
    short x, y, w, h;
    int contains(S_XYc pt)
    {
        int r = 0;
        if (x <= pt.x && pt.x < x + w && y <= pt.y)
            r = pt.y < y + h;
        return r;
    }
};
struct S_80027754 { char pad0[8]; S_Rc r8; VObj *o10; S_Rc r14; VObj *o1C; };
EXTERN_C int func_80027754(S_80027754 *p, S_XYc pt)
{
    VObj *o;
    if (p->o10 && p->r8.contains(pt))
        o = p->o10;
    else if (p->o1C && p->r14.contains(pt))
        o = p->o1C;
    else
        return 0;
    VEnt *e = &o->vt[5];
    return ((int (*)(void *, S_XYc))e->f)((char *)o + e->d, pt);
}
