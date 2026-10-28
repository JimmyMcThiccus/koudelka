/* func_8003C764: near miss (list cleanup: v01 on the head, or deferred-delete message via S_A2_X1, then v00(3) on +0x14 and func_800A0D0C on +0x18). 15 differing: retail copies the new object to $v0 for the vt/u4 stores and keeps `&D_800AC57C ? .. +0xF8 : 0` with the address in $v0; same shape as func_8003C5EC. Logic from Ghidra. */
struct S_A2B_Gx { char pad[4]; };
EXTERN_C S_A2B_Gx D_800AC57C_g asm("D_800AC57C");
inline void *a2b_f8(void *x) { return x ? (char *)x + 0xF8 : 0; }
struct S_A2B_C0b { void *vt; int u4; void *u8; void init() { vt = D_80010160; u4 = 0; } };
//// func_8003C764
EXTERN_C void func_8003C764(void *p, int flag)
{
    void *s = AT(p, void *, 8);
    if (s) {
        if (AT(p, int, 0xC)) {
            ((A2VObj0 *)s)->v01();
            AT(p, int, 8) = 0;
        } else {
            s = (char *)s - 8;
            if (flag) {
                S_A2B_C0b *o = (S_A2B_C0b *)operator new(0xC);
                char *base = 0;
                void *g;
                if (AT(p, void *, 8)) base = (char *)AT(p, void *, 8) - 8;
                o->init();
                { void *gx = &D_800AC57C_g; g = gx ? (char *)gx + 0xF8 : 0; }
                func_8001D150(g, new S_A2_X1(o));
                o->vt = D_80010148;
                o->u8 = base;
            } else {
                while (s) {
                    void *nx = AT(s, void *, 4);
                    AT(s, void *, 4) = 0;
                    ((A2VObj0 *)s)->v00(3);
                    s = nx;
                }
            }
            AT(p, int, 8) = 0;
        }
    }
    if (AT(p, A2VObj0 *, 0x14)) {
        AT(p, A2VObj0 *, 0x14)->v00(3);
        AT(p, int, 0x14) = 0;
    }
    if (AT(p, void *, 0x18)) {
        func_800A0D0C(AT(p, void *, 0x18));
        AT(p, int, 0x18) = 0;
    }
}
