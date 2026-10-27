#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062610);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062764);

EXTERN_C void func_800627E8(Entry_800627E8 *out, int i)
{
    *out = D_800B4E30[i - 1];
}

EXTERN_C void *func_80062834(void *self)
{
    return self;
}

EXTERN_C int func_8006283C(void)
{
    return D_800B4E34;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062848);

EXTERN_C int func_80062978(void *self)
{
    int old = FIELD_AT(self, int, 0x6C) != 0;
    FIELD_AT(self, int, 0x6C) = 0;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062988);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062A90);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062C3C);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062D60);

EXTERN_C void func_80062E70(void *self)
{
    func_800566E4(self);
    func_80056874(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062E9C);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062FA4);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800630BC);

EXTERN_C void func_800631D4(void *self)
{
    func_8008EF40(0xC);
    func_800566E4(self);
    if (FIELD_AT(self, int, 0x64) < 0) {
        char *h = (char *)self + 0x1C;
        FIELD_AT(self, int, 0x64) = (h ? FIELD_AT(h, List *, 0x0) : 0)->count;
    }
    func_800550FC(self, FIELD_AT(self, int, 0x64));
}

EXTERN_C void func_8006323C(void *self)
{
    func_80054FE0(self);
    func_80056874(self);
    func_8008EF40(0xD);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063270);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063340);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063584);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800635FC);

EXTERN_C void func_80063714(void *self, unsigned int b)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    FIELD_AT(self, unsigned int, 0x64) = b;
    if (p != 0) {
        func_800588EC(p, b);
    }
}

EXTERN_C int func_80063744(void *self, int b)
{
    switch (b) {
    case 1:
        FIELD_AT(self, int, 0x20) = func_80058270(FIELD_AT(self, void *, 0x3C), -1);
        return 1;
    case 2:
        FIELD_AT(self, int, 0x20) = func_80058270(FIELD_AT(self, void *, 0x3C), 1);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800637A0);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800638A8);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800639F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063B14);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063BE4);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063CA4);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063D64);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063E18);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063F3C);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063FFC);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800640D0);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064188);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064290);

EXTERN_C void func_800643DC(void *self, int dx, int dy)
{
    Entry_800643DC *e = (Entry_800643DC *)((char *)self + D_800B4CF0.value * 16);
    e->x += dx;
    e->y += dy;
    func_8005F1D8(self);
}

EXTERN_C void func_80064420(void)
{
}

EXTERN_C void func_80064428(void *self, int b, int c)
{
    VEnt_80064428 *vt = FIELD_AT(self, VEnt_80064428 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064478);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064570);

EXTERN_C void func_800646D4(void)
{
}

EXTERN_C void func_800646DC(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800646FC);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064884);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800648E8);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064B3C);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064C78);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064E0C);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80065458);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80065870);
