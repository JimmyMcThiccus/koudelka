// Pass 5: block-move scratch register choice; tried an early load of unk10, a pointer to the rect, inline by-value/
// by-ref setters, memberwise pos copy (~40 variants): still $a2. Retail F028/F338 (same code) use a2/a3, so a2 is
// busy here in retail for an unknown reason.
// func_8002F21C (and func_8002F2A4, same with func_8002EAE8): matches except the second temp of the
// 8-byte rect copy: retail lwl/lwr into $a3, this gives $a2.
EXTERN_C void func_8002F21C(S_8002F21C *p)
{
    func_8002EADC(p);
    if (p->unk10) {
        S_Pt2 pos;
        S_Rect8 r;
        func_8002D24C(p->unk10, &p->rect);
        r = p->rect;
        pos = r.pos;
        func_8002D780(p->unk10, pos);
    }
}
