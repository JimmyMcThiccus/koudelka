// func_800B914C: 41 differing: GCC treats p and the D_800B4D0C value as one register after the equality check (cse jump equivalence); retail keeps them in s1/s0 and loads p->x3C before the byte stores.
extern "C" void VSync(s32);
extern "C" void func_8009A470();
extern "C" void func_800B914C(Unk800B93D8T* p) { Unk800B93D8T* s = D_800B4D0C[0]; if (s != p) return; if (p->x30 >= 0) { func_8008CD1C(0, 0); VSync(0); func_8009A470(); } p->x36 = 0; p->x35 = 0x15; D_800B4D0C[0] = 0; if (p->x3C) func_800A0D0C(p->x3C); s->x44 = 0; s->x40 = 0; s->x3C = 0; s->x4->x4 = -1; StreamStat* st = s ? s->x4 : 0; st->x0 |= 0x11; }
