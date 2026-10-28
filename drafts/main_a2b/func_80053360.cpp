/* func_80053360: near miss. 34 differing: retail keeps the vptr stores for the intermediate classes; GCC removes them here. Needs the a2b.h declarations plus this prelude. */
struct S_A2B_C0 { void *vt; void *u4; S_A2B_C0() { vt = D_80010178; } };
struct S_A2B_C1 : S_A2B_C0 { short u8, uA; S_A2B_C1(S_A2B_C1 *o) { vt = D_800111BC; u4 = o->u4; u8 = o->u8; } };
struct S_A2B_C2_1 : S_A2B_C1 {
    S_A2_V4 d[2];
    S_A2B_C2_1(S_A2B_C2_1 *o) : S_A2B_C1(o) {
        S_A2_V4 *dd; S_A2_V4 *ss; int i;
        uA = o->uA;
        vt = D_80013AA8;
        dd = d; i = 1; ss = o->d;
        do { *dd = *ss; dd++; ss++; } while (--i != -1);
    }
};
EXTERN_C void *func_80053360(void *p)
{
    return new S_A2B_C2_1((S_A2B_C2_1 *)p);
}
