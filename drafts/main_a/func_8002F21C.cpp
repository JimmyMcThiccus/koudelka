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
