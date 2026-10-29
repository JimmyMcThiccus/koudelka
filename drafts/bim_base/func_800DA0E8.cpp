// func_800DA0E8: ~19-22 differing instructions. Retail: v1=p+i*0x80, copies 0x548(v1)..; the null-tested pointer is p+(i*0x80+0x548) computed separately. Struct copy of a 5-word record (lw x4, sw x4, lw, sw) is right.
struct BimSlotView { char pad[0x548]; BimRec5 r; };
EXTERN_C void func_800DA0E8(BimMon *p, int i) {
    BimSlotView *v = (BimSlotView *)((char *)p + i * 0x80);
    p->r484 = v->r;
    BimRec5 *s = &v->r;
    if (s) p->f498 = (char *)s + 0x14; else p->f498 = 0;
    func_80086EF0(p ? (char *)p + 0x400 : 0);
}
