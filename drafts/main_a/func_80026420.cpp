// func_80026420 (u_80025854): picks a texture-page allocator for a rect. 3 instructions differ: retail keeps
// the first (short)(x % 64) in $v1 (the register x was loaded into), this puts it in $v0.
struct S_Rect16 { short x, y, w, h; };
struct S_80026420 { void **vt; void *unk4; };

EXTERN_C void *func_80026420(void *o, S_Rect16 *r, S_XYc sz)
{
    if (r->w < sz.x || r->h < sz.y)
        return 0;
    if (r->w == sz.x && r->h == sz.y) {
        short mx = r->x % 64;
        if (mx && mx + r->w > 64)
            return 0;
        short my = r->y % 256;
        if (my && my + sz.y > 256)
            return 0;
        S_80026420 *p = (S_80026420 *)operator new(8);
        p->vt = D_80011124;
        p->unk4 = o;
        p->vt = D_800110F4;
        return p;
    }
    return func_80026274((S_80026274 *)operator new(0x20), (S_8b *)r, (int)o);
}
