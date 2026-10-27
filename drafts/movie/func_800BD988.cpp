// func_800BD988: retail is 4 bytes longer: it computes &xC into $v0, stores x8, then copies it to $a0
// (built uses $a0 directly). Constructor; source shape of the x0/x8 = &xC init not found yet.
struct A { void* x0; s32 x4; void* x8; char xC[0x14]; s32 x20, x24; };
extern "C" void func_800198E0(void*, s32, s32);
extern "C" void DecDCTReset(s32);
inline void* set(A* p, void* q) { p->x8 = q; p->x0 = q; return q; }
extern "C" void* func_800BD988(void* vp) { A* p = (A*)vp; func_800198E0(set(p, p->xC), 4, 0); p->x4 = 0; p->x20 = 0; p->x24 = 0; DecDCTReset(0); return p; }
