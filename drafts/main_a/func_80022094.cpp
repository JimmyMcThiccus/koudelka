// func_80022094 (u_80020B70): 256-colour CLUT fade table (each row brightens the previous one, LoadImage per row),
// then new S_800225C0(buf, 1). 145 diffs, all in the per-channel fade: retail re-masks the accumulated colour
// (andi 0xFFFF) and the channel at each use and masks the i<<2/<<7/<<12 limits inside the loop; an inline
// helper with u16 params gives the masks but stops loop rotation / hoists the limit masks (~190 diffs).
EXTERN_C int GetClut(int x, int y);
struct S_BufC { void *data; S_BufC(void *p) { data = p; } };
struct S_Blk100 { unsigned short c[128]; };
struct S_PalDesc { char pad0[6]; short dy; char pad8[4]; short x; short y; char pad10[8]; int n; };
EXTERN_C void func_80022094(S_Pal256 *p, S_Pt4 pos, S_PalDesc *d)
{
    S_Rect8 r;
    S_Rect8 r2;
    S_Buf *h;
    unsigned short *src, *dst;
    unsigned short lr, lg, lb, c, o, v;
    int i, j;
    if (d) {
        h = (S_Buf *)new S_BufC(func_800A0D2C(d->n << 9));
        *(S_Blk100 *)h->data = *(S_Blk100 *)p->c;
        r.x = pos.x + d->x;
        r.y = pos.y + d->y;
        r.w = 0x100;
        r.h = 1;
        LoadImage(&r, h->data);
        for (i = 1; i < d->n; i++) {
            src = (unsigned short *)((char *)h->data + (i - 1) * 0x200);
            dst = (unsigned short *)((char *)h->data + i * 0x200);
            lr = i << 2;
            lg = i << 7;
            lb = i << 12;
            for (j = 0; j < 0x100; j++) {
                c = *src++;
                o = c & 0x8000;
                v = c & 0x1F;
                if (v < lr)
                    o |= v + 4;
                else if (v < 0x1F)
                    o |= v + 1;
                else
                    o |= v;
                v = c & 0x3E0;
                if (v < lg)
                    o |= v + 0x80;
                else if (v < 0x3E0)
                    o |= v + 0x20;
                else
                    o |= v;
                v = c & 0x7C00;
                if (v < lb)
                    o |= v + 0x1000;
                else if (v < 0x7C00)
                    o |= v + 0x400;
                else
                    o |= v;
                *dst++ = o;
            }
            r2.x = pos.x + d->x;
            r2.y = pos.y + d->y + d->dy * i;
            r2.w = 0x100;
            r2.h = 1;
            LoadImage(&r2, (char *)h->data + i * 0x200);
        }
        new S_800225C0((int)h, 1);
    } else {
        r.x = pos.x;
        r.y = pos.y;
        r.w = 0x100;
        r.h = 1;
        LoadImage(&r, p->c);
    }
    p->clut = GetClut(pos.x, pos.y);
}
