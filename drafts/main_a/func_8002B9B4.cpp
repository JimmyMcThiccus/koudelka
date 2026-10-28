// func_8002B9B4 (u_80029BBC, types in include/game/a/h_u_80029BBC.h): hit-test children. Logic is right; the
// S_XY temporaries come out in the wrong stack slots (retail: child pos copy at sp+0x18, difference at sp+0x10,
// frame 0x30) and the loop tail differs. Needs operator-(const S_XY &, S_XY) or similar.
inline S_XY operator-(const S_XY &a, S_XY b) { return S_XY(a.x - b.x, a.y - b.y); }
EXTERN_C S_W *func_8002B9B4(S_W *p, S_XY *pt)
{
    S_W *c;
    if (!func_8002A064(p, pt->x, pt->y))
        return 0;
    p->coll.idx = 0;
loop:
    c = (S_W *)p->coll.next();
    if (!c)
        return p;
    S_XY r = *pt - *(S_XY *)&c->x;
    if (!func_8002A064(c, r.x, r.y))
        goto loop;
    return c;
}
