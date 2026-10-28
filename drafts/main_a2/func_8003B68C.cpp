/* func_8003B68C: near miss. 46 differing: body and calls match; stack layout differs (retail: t@10, BD08 result@18, v2@20, B310 result@28, S8 arg temps@38..50, frame 0x70; ours puts the B310 result at 18 and the result copy via lwl/lwr). Needs the result temp declared before v2/tr and a field-wise (lhu/sh) copy. func_8003B598 is the int version (ApplyMatrixLV, func_8003BDB8, 12-bit shifts) with the same shape. Uses include/game/a2/a2.h. */
struct S_A2_S8 { short v; short pad[3]; S_A2_S8() {} S_A2_S8(int x) { v = x; } S_A2_S8(const S_A2_S8 &o) { v = o.v; } };
struct S_A2_Sv4c { short x, y, z, w; S_A2_Sv4c() { x = 0; y = 0; z = 0; w = 0; } S_A2_Sv4c(const S_A2_Sv4c &o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    S_A2_Sv4c(S_A2_S8 a, S_A2_S8 b, S_A2_S8 c, S_A2_S8 d) { x = a.v; y = b.v; z = c.v; w = d.v; } };
EXTERN_C S_A2_Sv4c func_8003BD08(short *a, short *b);
EXTERN_C void ApplyMatrixSV(MATRIX *m, SVECTOR *v0, SVECTOR *v1);
EXTERN_C S_A2_V4 func_8003B310(void *s);
EXTERN_C S_A2_Sv4c func_8003B68C(MATRIX *m, SVECTOR *v)
{
    S_A2_Sv4c t;
    ApplyMatrixSV(m, v, (SVECTOR *)&t);
    S_A2_V4 tr = func_8003B310(m);
    S_A2_V4 *tp = &tr;
    S_A2_Sv4c v2(S_A2_S8(tp->a << 12), S_A2_S8(tp->b << 12), S_A2_S8(tp->c << 12), S_A2_S8(tp->d << 12));
    S_A2_Sv4c res = func_8003BD08((short *)&t, (short *)&v2);
    return res;
}
