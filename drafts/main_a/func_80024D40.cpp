// func_80024D40 (u_80020B70): close. Retail keeps (r.w << 16) in $s0 (lhu+sll) and derives sra 16/17/18 per branch with the store in a delay slot; none of the short/int/ternary forms tried reproduce that allocation.
extern "C" void func_80024D40(S_TexImg *p, S_Pt4 pos, int abr)
{
    S_Rect8 r;
    int w;
    p->pos = pos;
    r = *(S_Rect8 *)&p->pos;
    w = *(unsigned short *)&r.w << 16;
    {
        int v = w >> 16;
        if (p->unkC) {
            v = w >> 17;
            if (!p->unkC->f3())
                v = w >> 18;
        }
        r.w = v;
    }
    LoadImage(&r, p->unk18);
    p->unk1C = GetTPage(p->unkC ? p->unkC->f3() != 0 : 2, abr, pos.x, pos.y);
}
