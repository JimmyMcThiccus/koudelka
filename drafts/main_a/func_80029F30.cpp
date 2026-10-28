// func_80029F30 (u_80029BBC): matches except the frame: retail has an unused 4-byte slot at sp+0x10 (call result
// at sp+0x14, frame 0x28); this gives frame 0x20 with the result at sp+0x10.
struct S_Box2 { S_XY a; S_XY b; S_Box2(short x, short y, const S_XY &s) : a(x, y), b(s) {} };
EXTERN_C S_Box2 func_80029F30(S_W *p)
{
    VObj *o = p->unk8;
    if (o) {
        VEnt *e = &o->vt[14];
        return ((S_Box2 (*)(void *))e->f)((char *)o + e->d);
    }
    VEnt *e = &p->vt[10];
    return S_Box2(0, 0, ((S_XY (*)(void *))e->f)((char *)p + e->d));
}
