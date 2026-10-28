// func_80023450 (u_80020B70): pad poll -> button press/release events (0x201/0x202) and auto-repeat (func_800207C4).
// Control flow right, 194 diffs: retail tests the first loop with `slt $v0, $s2(ev = 0), n` (not blez), keeps the
// 16-entry history shift unreduced (hist[i] = hist[i-1] with i*2 recomputed), and holds ev in $s2.
EXTERN_C int PadGetState(int port);
EXTERN_C void func_80027948();
EXTERN_C void *func_80020884(void *p, void *out);
EXTERN_C int func_80020A30(void *p, void *e);
EXTERN_C void *func_800207C4(void *p, void *o);
EXTERN_C void *D_800B4C44;
struct S_PadBuf24 { int w[9]; };
struct S_PadEvt {
    void **vtbl;
    struct S_PadEvt *next;
    char pad8[0xC];
    int unk14;
    unsigned short unk18;
    unsigned short unk1A;
    S_PadEvt(void *a, int type, unsigned short key, unsigned short mask)
    {
        func_8001FC38(this, type, (int)a, 0);
        vtbl = D_800105DC;
        unk14 = 0;
        vtbl = D_80010588;
        unk1A = mask;
        unk18 = key;
    }
};
EXTERN_C void *func_80023450(void *pv)
{
    char *p = (char *)pv;
    S_PadEvt *ev = 0;
    S_PadEvt *e;
    unsigned short btn, old, mask, rep, bit, chg, prs, rel, key;
    unsigned short *q;
    int i;
    unsigned int t;
    if (!PadGetState(*(unsigned char *)(p + 0x7C))) {
        *(int *)(p + 0x9C) = *(int *)(p + 0xC0);
        *(unsigned short *)(p + 0x9E) = 0xFFFF;
    }
    if (*(signed char *)(p + 0x9C) || *(signed char *)(p + 0xC0))
        goto done;
    if (!D_800B4C40 && PadGetState(*(unsigned char *)(p + 0x7C)))
        goto done;
    t = (*(unsigned int *)(p + 0x9C) >> 12) & 0xF;
    if (t < 4)
        goto done;
    if (t < 6)
        mask = 0xFFFF;
    else if (t == 7)
        mask = 0xFFFF;
    else
        goto done;
    btn = *(unsigned short *)(p + 0x9E);
    for (i = 0; i < *(short *)(p + 0x104); i++)
        mask &= ((unsigned short *)(p + 0xE4))[i];
    old = *(unsigned short *)(p + 0xC2);
    btn |= old & ~mask;
    for (i = 15; i != 0; i--)
        ((unsigned short *)(p + 0xE4))[i] = ((unsigned short *)(p + 0xE4))[i - 1];
    ((unsigned short *)(p + 0xE4))[0] = *(unsigned short *)(p + 0xC2) | ~mask;
    if (btn != 0xFFFF) {
        if ((btn ^ 0xFFFF) == 9)
            func_80027948();
        rep = 0xFFFF;
        q = (unsigned short *)(p + 0x108);
        for (bit = 1; bit; bit <<= 1, q++)
            if (!(bit & btn))
                rep &= ~*q;
    } else
        rep = 0xFFFF;
    if (btn != old) {
        chg = btn ^ old;
        prs = chg & ~btn;
        rel = chg & btn;
        if (prs) {
            q = (unsigned short *)(p + 0x126);
            for (bit = 0x8000; bit; bit >>= 1, q--) {
                if (prs & bit) {
                    D_800B4C44 = p;
                    e = new S_PadEvt(p, 0x201, *q, rep);
                    e = (S_PadEvt *)func_80020884(p, e);
                    if (e->next && ev)
                        func_8001A864(ev, e->next);
                    e->next = ev;
                    ev = e;
                    func_80020A30(p, ev);
                }
            }
        }
        if (rel) {
            q = (unsigned short *)(p + 0x126);
            for (bit = 0x8000; bit; bit >>= 1, q--) {
                if (rel & bit) {
                    D_800B4C44 = p;
                    e = new S_PadEvt(p, 0x202, *q, rep);
                    e = (S_PadEvt *)func_80020884(p, e);
                    if (e->next && ev)
                        func_8001A864(ev, e->next);
                    e->next = ev;
                    ev = e;
                    func_80020A30(p, ev);
                }
            }
        }
    } else {
        ev = (S_PadEvt *)func_800207C4(p, &D_800AC6A8);
        if (ev) {
            ev->unk1A = rep;
            if (func_80020A30(p, ev)) {
                VCALL(ev, 1, Fn_vi, 3);
                ev = 0;
            }
        }
    }
done:
    *(S_PadBuf24 *)(p + 0xC0) = *(S_PadBuf24 *)(p + 0x9C);
    return ev;
}
