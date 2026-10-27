#include "common.h"
#include "movie/movie.h"

EXTERN_C void func_800B8AB4(Unk800B8AB4* p) { if (p->x8 == 0) p->x8 = func_800B9B14(operator new(0x38), p, p->x30); func_8002A110(p); }

EXTERN_C s32 func_800B8B08(Unk800B8B08* p) { return p->x8; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B8B14);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B8CF0);

EXTERN_C s32 func_800B8E9C(Unk800B8E9C* p) { s32 v = p->x40; if (v == 0) v = -1; return v; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B8EB8);

EXTERN_C s32 func_800B8F34(Unk800B8F34* p) { Unk800B8F34B* b = p->x4; s32 i = b->x4; s32 r; if (i >= 0) { r = p->x40[i]; b->x4 = i + 1; } else r = -1; return r; }

EXTERN_C s32 func_800B8F74(Unk800B8F74* p, void* dst, s32 n) { if (p->x4->x4 < 0) return 0; func_80025CE0(dst, p->x40 + p->x4->x4, n); p->x4->x4 += n; return n; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B8FE0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9060);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B914C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9208);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B92B8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B93D8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9484);

EXTERN_C void func_800B95A8(void* p, void* q) { StFreeRing(q); }

EXTERN_C s32 func_800B95C8(Unk800B95C8* p) { return p->x28; }

EXTERN_C int func_800B95D4() { return 0x20; }

EXTERN_C void func_800B95DC(Unk800B95DC* p, char* q) { if (q) ((Unk800B95DCB*)(q - 8))->v2(p->x8, 0x20); }

EXTERN_C void func_800B9620(void* p, void* q) { func_8003546C(p, q); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9640);

EXTERN_C void func_800B9704(Unk800B9704* p, s32 f) { p->x8 = D_800B6F34; p->x0 = D_800B6F4C; p->x8 = D_80012294; p->x0 = D_80012224; func_80035304(p, 0); if (f & 1) operator delete(p); }

EXTERN_C Unk800B977C* func_800B977C(Unk800B977C* p) { p->x0 = D_800B6FBC; return p; }

EXTERN_C void func_800B9790(Unk800B9790* p) { if (p->x8 == 0) p->x8 = func_800BA498(operator new(0x38), p, p->x30); func_8002A110(p); }

EXTERN_C void func_800B97E4(Unk800B97E4* p, Unk800B97E4R* r) { p->x30 = *r; if (p->x8) p->x8->v21(); }

EXTERN_C void func_800B9848(Unk800B9848* p) { if (p->x8) p->x8->v8(); }

EXTERN_C s32 func_800B988C(Unk800B988C* p, s32 a) { return p->v14(a); }

EXTERN_C s32 func_800B98C8(Unk800B98C8* p) { return p->x8; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B98D4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9A0C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B6DF0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B6DF4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B6E44);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B6F34);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B6F4C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B6FBC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B6FF4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7044);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9B14);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9B48);

EXTERN_C Unk800B9C34* func_800B9C34(Unk800B9C34* p) { p->x0 = 3; p->x2 = 3; return p; }

EXTERN_C Unk800B9C48* func_800B9C48(Unk800B9C48* p) { p->x0 = 0; p->x2 = 0; p->x4 = 3; p->x6 = 3; return p; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9C64);

EXTERN_C s32 func_800B9CEC(Unk800B9CEC* p) { return p->x4; }

EXTERN_C void func_800B9CF8(void* p) { func_800386B8(p); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9D18);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9DB4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9E78);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800B9F74);

EXTERN_C void func_800BA3E4(Unk800BA3E4* p, s16 a, s16 b) { p->x3C = a; p->x3E = b; p->x8 = 2; }

EXTERN_C void func_800BA3F8(Unk800BA3F8* p, s16 a, s16 b) { p->x40 = a; p->x42 = b; p->x8 = 2; }

EXTERN_C void func_800BA40C(Unk800BA40C* p, Unk800BA40CR* r) { p->x3C = *r; p->x8 = 2; }

EXTERN_C void func_800BA438(Unk800BA438* p, Unk800BA438R* r) { p->x44 = *r; p->x8 = 2; }

EXTERN_C void func_800BA464() {}

EXTERN_C s32 func_800BA46C(Unk800BA46C* p) { return p->x4; }

EXTERN_C void func_800BA478(void* p) { func_8001A610(p); }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B71E4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BA498);

EXTERN_C void func_800BA50C(Unk800BA50C* p, Unk800BA50CR* r) { p->x30 = *r; }

EXTERN_C void func_800BA534(Unk800BA534* p) { s32 r = p->v12(); if (r) p->v8(r); }

EXTERN_C s32 func_800BA598(Unk800BA598* p) { return p->x4; }

EXTERN_C void func_800BA5A4(void* p) { func_800386B8(p); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BA5C4);

EXTERN_C void func_800BBF74(Unk800BBF74* p) { p->x108 = 0; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BBF7C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BC12C);

EXTERN_C int func_800BC54C() { return 1; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BC554);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7534);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7564);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B75B4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B75CC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B75E4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BC714);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BCB14);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BCCAC);

EXTERN_C Unk800BCE4CR* func_800BCE4C(Unk800BCE4C* p) { return p->x4C == 3 ? &p->x14[p->x30] : p->x14; }

EXTERN_C s32 func_800BCE7C(Unk800BCE7C* p) { s32 r; if (p->x34 < p->x50) r = 0; else r = p->x40; return r; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BCEA0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BD008);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BD83C);

EXTERN_C void func_800BD8E8() { if (D_800CBA90[0] == 0) D_800CBA90[0] = func_800BD988(operator new(0x28)); }

EXTERN_C void func_800BD928() { if (D_800CBA90[0]) { DecDCToutCallback(0); Unk800BD928* t = (Unk800BD928*)D_800CBA90[0]; if (t) { func_80019920(t->x0, 0); operator delete(t); } D_800CBA90[0] = 0; } }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BD988);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BD9DC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BDADC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7644);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BDBAC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BDC88);

EXTERN_C void func_800BDDC8(void* vp, s32 a, s32 b) { Unk800BDDC8* p = (Unk800BDDC8*)vp; p->x20 = 0; p->x50 = func_800A0D2C(0x38400); func_800B93D8(p->x44, a, b, 1); func_8003546C(p->x44, p ? (char*)p + 8 : 0); }

EXTERN_C void func_800BDE40(Unk800BDE40* p) { p->x44->v3(); func_800BDADC(D_800CBA90[0], p->x48); func_8001AA68(p ? (char*)p + 0x30 : 0, 0); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BDEAC);

EXTERN_C void func_800BDF48(char* p) { func_8001AB50(p ? p + 0x30 : 0, 0); }

EXTERN_C void func_800BDF78(Unk800BDF78* p) { p->x58 = 1; }

EXTERN_C void func_800BDF84(void* p, u32 n) { while (D_800A4534.xC < n) {} }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BDFA8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BE1CC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BE2C4);

EXTERN_C void func_800BE368(Unk800BE368* p) { func_8002DC34(D_800A4578[0]->x8->x14, p, 0); func_80025714(D_800B4C48, p->x68); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BE3B4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BE4B4);

EXTERN_C s16 func_800BE54C(Unk800BE54C* p, s16 a) { if (a != 0) p->x64 = a; return p->x6E; }

EXTERN_C s16 func_800BE568(Unk800BE568* p, s16 a) { if (a != 0) p->x64 = a; return p->x6E; }

EXTERN_C void func_800BE584(Unk800BE584* p, s16 f) { if (!f) p->v9(0, 0); else p->v9(p->x5A, p->x5C); p->v7(); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BE5F8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BE684);

EXTERN_C void* func_800BE880(void* p) { return p; }

EXTERN_C void func_800BE888(void* p, int f) { if (f & 1) operator delete(p); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BE8B0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BE9D4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BEB0C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BEC54);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BEDD0);

EXTERN_C void func_800BEED4(Unk800BEED4* p) { p->x68->v3(); func_80036D8C(p->x68); if (p->x64) func_80048D2C(p->x64, 3); }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7664);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B767C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B76B4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B76C4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B76D4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B76EC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7704);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BEF3C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BF51C);

EXTERN_C void func_800BF898(Unk800BF898* p, s32 v) { if (p->x78) func_800C3D5C(p->x78, v); }

EXTERN_C void func_800BF8C8(void* p) { func_800279A8(p); func_800C5E34(); func_800566E4(p); func_80055330(0); func_8005549C(6, p, 0, -1); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BF918);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800BFA58);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C01C4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7778);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B77A0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B77B0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C02D8);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7810);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7814);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7854);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7888);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B78B8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C06BC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B792C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7968);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", jtbl_800B799C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C0DA4);

EXTERN_C void func_800C0E9C() {}

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C0EA4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C10BC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C11A0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C1278);

EXTERN_C void func_800C1690(void* p, s32* a, s32* b, s32* c, s32* d) { Unk800C1690B* g = D_800B4DD0[0]; g->x1BC = *a; g->x1C0 = *b; g->x204 = *c; g->x208 = *d; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C16C8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C1AE0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C1BF8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C21B8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C22E8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2360);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C23D8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2450);

EXTERN_C int func_800C24C8(int x) { return (x + 0x1FFF) / 0x2000; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C24E0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C259C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2624);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2848);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C29C0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2AF0);

EXTERN_C void func_800C2CE4(Unk800C2CE4* p) { if (p->x34 != -1) { func_800356F4(p); close(p->x34); Unk800C2CE4B* b = p->x4; void* d = D_800CBA94[0]; p->x34 = -1; b->x4 = -1; if (d == p) D_800CBA94[0] = 0; } }

EXTERN_C s32 func_800C2D4C(Unk800C2D4C* p) { return p->x5C; }

EXTERN_C s32 func_800C2D58(Unk800C2D58* p) { Unk800C2D58B* b = p->x4; s32 i = b->x4; if (i >= 0 && i < p->x58) { s32 r = p->x5C[i]; b->x4 = i + 1; return r; } return -1; }

EXTERN_C void func_800C2DA8(Unk800C2DA8* p, u8 c) { Unk800C2DA8B* b = p->x4; s32 i = b->x4; if (i >= 0 && i < p->x58) { p->x5C[i] = c; b->x4 = i + 1; } }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2DF4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2E7C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2F04);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C2F90);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C3024);

EXTERN_C s32 func_800C30B0(Unk800C30B0* p) { return p->x58; }

EXTERN_C int func_800C30BC(void* x) { return D_800CBA94[0] != x; }

EXTERN_C void* func_800C30D4(void* p, void* q) { return q; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C30DC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C3228);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C3484);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C3674);

EXTERN_C int func_800C38C0(void* p) { DIRENTRY d; func_800C40D0(p); return firstfile(D_800CBAAC, &d) != 0; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C38F0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C39D4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7BC4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7BF4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7C44);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7C64);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CAC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CB4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C3B88);

EXTERN_C int func_800C3D08(Unk800C3D08* p) { return p->x4->x0 == 0; }

EXTERN_C int func_800C3D1C(Unk800C3D1C* p, char* q) { if (q == 0) { p->x2C = 0; } else { if (p->x2C) return 0; p->x2C = q + 4; } return 1; }

EXTERN_C s32 func_800C3D50(Unk800C3D50* p) { return p->x38; }

EXTERN_C int func_800C3D5C(Unk800C3D5C* p, s32 v) { if (p->x38 == v || p->x34 != -1) return 0; p->x38 = v; return 1; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C3D90);

EXTERN_C void func_800C3E10(Unk800C3E10* p, void* b) { func_80025CE0(p->x54, b, p->x50 * 128); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C3E38);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C3F68);

EXTERN_C void func_800C407C(Unk800C407C* p) { p->x48 = p->x44->d; p->x4C = p->x44->e; p->x54 = (char*)p->x44->rows; p->x5C = p->x54 + p->x50 * 128; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C40B8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C40D0);

EXTERN_C s32 func_800C4178(Unk800C4178* p) { return p->x54; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C4184);

EXTERN_C s32 func_800C420C(Unk800C420C* p) { return p->x4C; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C4218);

EXTERN_C s32 func_800C42B8(Unk800C42B8* p) { return p->x48; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C42C4);

EXTERN_C s32 func_800C4364(Unk800C4364* p) { return p->x44; }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CD4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7CFC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D14);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7D54);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C4370);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C46B8);

EXTERN_C s32 func_800C4854(Unk800C4854* p) { return p->x78; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C4860);

EXTERN_C char* func_800C4994(char* p) { return p + 0x54; }

EXTERN_C char* func_800C499C(char* p) { return p + 0x5D; }

EXTERN_C s32 func_800C49A4(Unk800C49A4* p) { return p->x50; }

EXTERN_C s8 func_800C49B0(Unk800C49B0* p) { return p->x82; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C49BC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C4D5C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C4DE8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C4F10);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5074);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5148);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5278);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5380);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5510);

EXTERN_C void func_800C55F8(Unk800C55F8* p) { func_8002B27C(D_800A4578[0], p->x6C); p->x6C = 0; func_8006323C(p); func_80054FE0(p->x70); }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7DEC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7E1C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7E6C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7F64);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5640);

EXTERN_C int func_800C5770(void* p, s32 a) { func_8001FC78(a, 0, 0); return 1; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5798);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B7FB4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8004);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8024);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8054);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C595C);

EXTERN_C void func_800C5A14(Unk800C5A14* p, s32 v) { if (v >= 0 && v <= p->x50) { p->x54 = v; if (p->x58) func_800648E8(p->x58); } }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5A60);

EXTERN_C void func_800C5B30(Unk800C5B30* p) { p->x58 = 0; func_80054FE0(p); }

EXTERN_C void func_800C5B50(void* p) { func_80054C34(p); }

EXTERN_C Unk800C5B70* func_800C5B70(Unk800C5B70* p, s32 a, s32 b) { p->x4 = b; p->x0 = a; return p; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5B80);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C5E34);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C6024);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C60E8);

EXTERN_C void func_800C6298(Unk800C6298* p, s32 dx, s32 dy) { s32 i = D_800B4CF0[0]; p->x2C[i].x += dx; p->x2C[i].y += dy; func_8005F1D8(p, dx, dy); }

EXTERN_C void func_800C62E4(Unk800C62E4* p, Unk800C62E4B* q) { u8 r = q->x5, g = q->x6, b = q->x7; s32 i = D_800B4CF0[0]; p->x2C[i].r = r; p->x2C[i].g = g; p->x2C[i].b = b; func_8005F1D8(p); }

EXTERN_C void func_800C6330(Unk800C6330* p, s32 x, s32 y) { s32 i = D_800B4CF0[0]; p->v11(x - p->x28[i].x0, y - p->x28[i].y0); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C6388);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C648C);

EXTERN_C void func_800C65FC() {}

EXTERN_C void func_800C6604(void* p) { func_8005F120(p); }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B80D4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C6624);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C6B94);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C6C38);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C6D80);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C71E8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C7290);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C7740);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C77F0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C7AC0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C7C3C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8214);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8264);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8284);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B82B4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B82F4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8344);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C7D60);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C7F60);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C800C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8114);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8228);

EXTERN_C void func_800C8338() {}

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8340);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C83CC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C84FC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8594);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8674);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8894);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C899C);

EXTERN_C void func_800C8A54(Unk800C8A54* p, Unk800C8A54B* q) { p->x0[D_800B4CF0[0]].x1E = q->x8; func_8005F1D8(p, q); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8A90);

EXTERN_C void func_800C8B24(Unk800C8B24* p, Unk800C8B24B* q) { s32 i = D_800B4CF0[0]; p->x0[i].x14 = q->x5; p->x0[i].x15 = q->x6; p->x0[i].x16 = q->x7; func_8005F1D8(p); }

EXTERN_C void func_800C8B74(Unk800C8B74* p, s32 w, s32 h) { s32 i = D_800B4CF0[0]; s32 x = p->x10[i].x0, y = p->x10[i].y0;
  p->x10[i].x1 = x + w; p->x10[i].y1 = y; p->x10[i].x2 = x; p->x10[i].y2 = y + h; p->x10[i].x3 = x + w; p->x10[i].y3 = y + h; func_8005F1D8(p); }

EXTERN_C void func_800C8BD0(Unk800C8BD0* p, s32 x, s32 y) { s32 i = D_800B4CF0[0]; p->v11(x - p->x10[i].x0, y - p->x10[i].y0); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8C28);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8D18);

EXTERN_C void func_800C8E44(void* p) { func_8005F120(p); }

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8384);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B83D4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B84CC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B85C4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8614);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C8E64);

EXTERN_C void func_800C9058(Unk800C9058* p) { p->x20 = D_800A4578[0]->x1D2 != 0; func_800550FC(p, 2); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C908C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C910C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C91A0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C9364);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C95EC);

EXTERN_C s32 func_800C96B0() { return D_800CBAE4[0]; }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C96C0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C9874);

EXTERN_C void func_800C98EC(Unk800C98EC* p, Unk800C98ECB* q) { s32 c = D_800B4CF0[0]; u32 i = 0; loop: if (i < 4) { p->x28[c + i].r0 = q->x5; p->x28[c + i].g0 = q->x6; p->x28[c + i].b0 = q->x7; i += 2; goto loop; } func_8005F1D8(p, q); }

EXTERN_C void func_800C9958(Unk800C9958* p, s32 x, s32 y) { s32 i = D_800B4CF0[0]; p->v11(x - p->x28[i].x0, y - p->x28[i].y0); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C99B0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C9AB4);

EXTERN_C void func_800C9CB4() {}

EXTERN_C void func_800C9CBC(void* p) { func_8005F120(p); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C9CDC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B86B4);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8704);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8724);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8754);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8794);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800C9ED8);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800CA59C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800CA610);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800CA7EC);

EXTERN_C int func_800CA864() { return 1; }

EXTERN_C void func_800CA86C(Unk800CA86C* p) { func_800BDDC8(p->x10C, 0x30, 0xC0); }

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800CA894);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800CA928);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTReset);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTGetEnv);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTPutEnv);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTin);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_188);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_1B4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTout);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTinSync);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_220);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCToutSync);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_268);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTinCallback);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCToutCallback);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_2C0);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B899C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B89CC);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8A1C);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8A34);

INCLUDE_RODATA("asm/movie/nonmatchings/movie", D_800B8A4C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_394);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_3A0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_3B0);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_440);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_4CC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_550);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_560);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_5E4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_5F4);

INCLUDE_ASM("asm/movie/nonmatchings/movie", LIBPRESS_OBJ_60C);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTvlcSize2);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTvlc2);

INCLUDE_ASM("asm/movie/nonmatchings/movie", DecDCTvlcBuild);

INCLUDE_ASM("asm/movie/nonmatchings/movie", BUILD_OBJ_AC);

INCLUDE_ASM("asm/movie/nonmatchings/movie", func_800CBA80);
