#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6198);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6328);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6584);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D66B0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6740);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D67EC);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D68EC);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D69B4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6B98);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6C1C);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6D08);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6D84);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D6DF4);

EXTERN_C BimVec4 *func_800D7008(BimVec4 *r, BimVec4 *a, BimVec4 *b) {
    int ax = a->x, bx = b->x, ay = a->y, by = b->y, az = a->z, bz = b->z, aw = a->w;
    r->x = ax - bx; r->y = ay - by; r->z = az - bz; r->w = aw; return r; }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7048);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D71F4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D731C);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D73E8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D76C8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7818);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7914);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7A20);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7A4C);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7A78);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7AC4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7BB4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7C7C);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7D64);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7DB4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7DFC);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7E8C);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7ECC);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D7F3C);

EXTERN_C int func_800D7F90(void *p, int a, int b) { return func_8007FE4C((char *)D_800AF470[0] + 0x498, a, b); }

EXTERN_C void func_800D7FB8(void *p, int a, int b, int c) { func_8007FF58((char *)D_800AF470[0] + 0x498, a, b, c); }

EXTERN_C void func_800D7FE0() { func_800CFC50(D_800AF470[0]->f32C); }

EXTERN_C int func_800D800C() { return D_800AF470[0]->f32C->f950; }

EXTERN_C int func_800D802C() { int a, b; func_800C8D9C(D_800AF470[0]->f32C, 2, &a, &b); return b + 1; }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8064);

EXTERN_C void func_800D8118(void *p) { func_80085E74(p, 0); }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8138);

EXTERN_C void func_800D817C(BimMon *p, char v) { p->b4E4 = v; }

EXTERN_C void func_800D8184(BimMon *p, int a, int b) { p->f4E8 = a; p->f4EC = b; }

EXTERN_C void func_800D8190() { func_800CDA8C(D_800AF470[0]->f32C); }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D81BC);

EXTERN_C void func_800D81FC(BimMon *p, int a) { p->f9A4 = a; }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8204);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8260);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D82BC);

EXTERN_C void func_800D82F0() { func_800D8AE4(); }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8310);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8350);

EXTERN_C int func_800D83BC(void *, int *p) { *p &= ~3; return 1; }

EXTERN_C int func_800D83D4(void *, int *p) { return *p == 0; }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D83E0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8464);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D84C8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8524);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8634);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8744);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8854);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8964);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D89B8);

EXTERN_C void func_800D8A0C(void *p, int a) { func_800D7C7C(p, a, 0); }

EXTERN_C void func_800D8A2C(void *p, int a) { func_800D7C7C(p, -a, 0); }

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8A50);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8AB8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8AE4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8C0C);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8CC0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8D64);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8E38);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8E64);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D8EF4);

EXTERN_C int func_800D8F48() { return 1; }

EXTERN_C void func_800D8F50(BimMon *p) { p->f9CC++; }

EXTERN_C void func_800D8F64() {}

EXTERN_C int func_800D8F6C(BimMon *p) { return p->f9E4; }

EXTERN_C int func_800D8F78(BimMon *p) { return p->f9DC != 0; }

EXTERN_C int func_800D8F84(BimMon *p) { return p->f9E0; }

EXTERN_C void func_800D8F90() {}

EXTERN_C unsigned short func_800D8F98(BimMon *p) {
    func_8008687C(p, 0);
    int k = 0x100;
    return p->s80 = ((long long)(int)p->b7D * (long long)k) / p->b3E;
}

EXTERN_C unsigned short func_800D8FF8(BimMon *p) {
    func_8008687C(p, 0);
    return p->s80 = 0x100LL / p->b3E;
}

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9048);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9170);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D91A4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9218);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D94A8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D94F4);

EXTERN_C void func_800D96F0() {}

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D96F8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D98E0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9970);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9CB0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800D9F88);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA0E8);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA164);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA2E4);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA400);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA5E0);

INCLUDE_ASM("asm/bim_base/nonmatchings/bim_base", func_800DA690);
