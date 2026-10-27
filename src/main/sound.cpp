#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/sound/sound.h"

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008B6B0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008B888);

EXTERN_C void func_8008B96C(void)
{
    char **pp = &FIELD_AT(&D_800B18FC, char *, 0x1CC);
    int i;

    for (i = 0; i < 0x18; i++, pp++) {
        if (*pp != 0) {
            FIELD_AT(*pp, unsigned short, 0x6) |= 0x1F5;
        }
    }
    D_800B18FC.flags &= ~0x80;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008B9C0);

EXTERN_C void func_8008BA68(void)
{
    SoundState *s = &D_800B18FC;

    if (!(s->flags & 0x2000) && !(s->flags & 1)) {
        EnableEvent(FIELD_AT(s, int, 0x13C));
        D_800B18FC.flags |= 1;
    }
}

EXTERN_C void func_8008BAC4(void)
{
    SoundState *s = &D_800B18FC;

    if (!(s->flags & 0x2000) && (s->flags & 1)) {
        DisableEvent(FIELD_AT(s, int, 0x13C));
        D_800B18FC.flags &= ~1;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BB20);

EXTERN_C void func_8008BBB0(char *p, int n)
{
    SoundState *s;

    n &= 0x7FFFFFFC;
    if ((int)p & 3) {
        n -= 4;
        p = (char *)(((int)p + 3) & ~3);
    }
    s = &D_800B18FC;
    FIELD_AT(s, char *, 0x8) = p;
    FIELD_AT(s, char *, 0xC) = p + n;
    FIELD_AT(s, int, 0x10) = n;
    FIELD_AT(p, unsigned short, 0x0) = 0x8000;
    FIELD_AT(p, short, 0x2) = 0;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, char *, 0x8) = p + 0x10;
    FIELD_AT(p, int, 0xC) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BC0C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BD04);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BE08);

EXTERN_C int func_8008BE50(void)
{
    Blk_8008BE08 *b = FIELD_AT(&D_800B18FC, Blk_8008BE08 *, 0x8);
    int max = 0;
    int d;

    while (b->next != 0) {
        d = (char *)b->next - b->end;
        if (max < d) {
            max = d;
        }
        b = b->next;
    }
    d = FIELD_AT(&D_800B18FC, char *, 0xC) - b->end;
    if (max < d) {
        max = d;
    }
    return max & ~3;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BECC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BF78);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BFEC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C060);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C168);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C27C);

EXTERN_C int func_8008C3AC(int id)
{
    unsigned char *p = &FIELD_AT(&D_800B18FC, unsigned char, 0x14);
    unsigned char *prev = 0;
    unsigned char *base = p;

    for (;;) {
        if (FIELD_AT(p, int, 0x4) == id) {
            *prev = *p;
            p[1] = 0;
            FIELD_AT(p, short, 0x2) = 0;
            FIELD_AT(p, int, 0x4) = 0;
            *p = 0;
            return id;
        }
        if (*p == 0) {
            return 0;
        }
        prev = p;
        p = (unsigned char *)((*p << 4) + (int)base);
    }
}

EXTERN_C void func_8008C414(int id, int v)
{
    char *p = func_8008C4F0(id);

    if (p != 0) {
        FIELD_AT(p, short, 0x2) = v;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C448);

EXTERN_C int func_8008C4B8(void)
{
    unsigned char *p = &FIELD_AT(&D_800B18FC, unsigned char, 0x14);
    int i;

    for (i = 0; i < 16; i++, p += 0x10) {
        if (p[1] == 0) {
            return i;
        }
    }
    return -1;
}

EXTERN_C char *func_8008C4F0(int id)
{
    char *p = &FIELD_AT(&D_800B18FC, char, 0x14);
    char *base = p;

    for (;;) {
        if (FIELD_AT(p, int, 0x4) == id) {
            return p;
        }
        if (*p != 0) {
            return 0;
        }
        p = base;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C52C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C6B0);

EXTERN_C void func_8008C6F8(void)
{
    FIELD_AT(&D_800B18FC, void *, 0x164) = func_8008BC0C(0xE0);
    func_8008CBE4();
}

EXTERN_C void func_8008C724(int a, int b, int c, int d)
{
    func_8008C7B4(a, b, c, d, 1);
}

EXTERN_C void func_8008C748(int a, int b, int c, int d)
{
    func_8008C7B4(a, b, c, d, 2);
}

EXTERN_C void func_8008C76C(int a, int b, int c, int d)
{
    func_8008C7B4(a, b, c, d, 3);
}

EXTERN_C void func_8008C790(int a, int b, int c, int d)
{
    func_8008C7B4(a, b, c, d, 4);
}

EXTERN_C void func_8008C7B4(int a, int b, int c, int d, int e)
{
    int flags = D_800B18FC.flags;
    char *n;
    char *p;
    SoundState *s;

    if (FIELD_AT(&D_800B18FC, int, 0x160) != 0) {
        func_8008CBE4();
    }
    n = func_8008C970();
    if (!(flags & 0x30)) {
        while (n == 0) {
            n = func_8008C970();
        }
        func_80094990();
    }
    if (n == 0) {
        func_8009484C(0xE1, b);
        return;
    }
    *n = e & 0xF;
    FIELD_AT(n, short, 0x2) = 0;
    FIELD_AT(n, int, 0x4) = b;
    FIELD_AT(n, int, 0x8) = a & 0x7FFF8;
    FIELD_AT(n, int, 0xC) = c;
    FIELD_AT(n, int, 0x10) = d;
    FIELD_AT(n, int, 0x18) = 0;
    s = &D_800B18FC;
    if (FIELD_AT(s, int, 0x160) != 0 || FIELD_AT(s, char *, 0x168) == 0) {
        FIELD_AT(s, char *, 0x168) = n;
        func_8008CA50();
    } else {
        p = FIELD_AT(s, char *, 0x168);
        while (FIELD_AT(p, char *, 0x18) != 0) {
            p = FIELD_AT(p, char *, 0x18);
        }
        FIELD_AT(p, char *, 0x18) = n;
    }
    if (!(flags & 0x30)) {
        func_800949A0();
    }
}

EXTERN_C unsigned char func_8008C928(int flags)
{
    unsigned char *p;

    if (flags & 0x10) {
        while (*(volatile unsigned short *)&D_800B18FC.flags & 2) {
        }
    }
    p = FIELD_AT(&D_800B18FC, unsigned char *, 0x168);
    if (p != 0) {
        return *p;
    }
    return 0;
}

EXTERN_C char *func_8008C970(void)
{
    char *p = FIELD_AT(&D_800B18FC, char *, 0x164);
    int i;

    for (i = 0; i < 6; i++, p += 0x1C) {
        if (*p == 0) {
            return p;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C9A8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CA50);

typedef void (*Hook_8008CB84)(void);
EXTERN_C void func_8008CB84(void)
{
    SoundState *s = &D_800B18FC;

    D_800B18FC.flags |= 0x20;
    FIELD_AT(s, int, 0x14C)++;
    if (FIELD_AT(s, Hook_8008CB84, 0x140) != 0) {
        FIELD_AT(s, Hook_8008CB84, 0x140)();
    }
    D_800B18FC.flags &= ~0x20;
}

struct SndVoice_800B1A60 { unsigned char unk0; char pad[0x1B]; };
struct GlobalPtr_800B1A60 { SndVoice_800B1A60 *p; int pad[2]; };
EXTERN_C GlobalPtr_800B1A60 D_800B1A60;

EXTERN_C void func_8008CBE4(void)
{
    SndVoice_800B1A60 *e = D_800B1A60.p;
    int i;

    for (i = 0; i < 8; i++, e++) {
        e->unk0 = 0;
    }
    D_800B18FC.unk168 = 0;
    D_800B18FC.unk25B = 0;
    D_800B18FC.flags &= ~2;
}

EXTERN_C void func_8008CC20(int mode)
{
    SoundState *s = &D_800B18FC;
    char *p;

    FIELD_AT(s, unsigned char, 0x1A3) = mode;
    func_8008CFD4();
    func_800A0800(FIELD_AT(s, short, 0x1BE), FIELD_AT(s, short, 0x1C0));
    for (p = FIELD_AT(s, char *, 0x150); p != 0; p = FIELD_AT(p, char *, 0x4)) {
        func_80093A80(p, 4);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CC88);

EXTERN_C void func_8008CD1C(int v, int dur)
{
    SoundState *s = &D_800B18FC;

    FIELD_AT(s, short, 0x1BA) = v;
    if (dur == 0) {
        FIELD_AT(s, int, 0x1B0) = v << 16;
        FIELD_AT(s, short, 0x1B8) = 0;
        FIELD_AT(s, short, 0x19A) = v;
        FIELD_AT(s, short, 0x182) = v;
        FIELD_AT(s, short, 0x180) = v;
        FIELD_AT(s, int, 0x170) |= 0xC0;
    } else {
        int d = (v << 8) - (FIELD_AT(s, int, 0x1B0) >> 8);
        if (d != 0) {
            FIELD_AT(s, short, 0x1B8) = dur;
            FIELD_AT(s, int, 0x1B4) = (d / dur) << 8;
        }
    }
}

EXTERN_C void func_8008CD88(int a, int b)
{
    D_800B18FC.unk184 = a;
    D_800B18FC.unk188 = b;
    D_800B18FC.unk170 |= 0x300;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CDA8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CE18);

EXTERN_C void func_8008CFD4(void)
{
    SoundState *s = &D_800B18FC;

    func_8008D038(FIELD_AT(s, short, 0x198), &FIELD_AT(s, short, 0x174), 0);
    FIELD_AT(s, short, 0x180) = FIELD_AT(s, short, 0x182) = FIELD_AT(s, short, 0x19A);
    func_8008D038(FIELD_AT(s, short, 0x19C), &FIELD_AT(s, short, 0x1BE), 1);
    FIELD_AT(s, int, 0x170) |= 0xC3;
}

EXTERN_C void func_8008D038(int v, short *out, int side)
{
    unsigned int mode;

    out[1] = v;
    out[0] = v;
    mode = D_800B1A9F.v;
    if (mode >= 2) {
        if (mode == 2) {
            if (side != 1) {
                out[0] = -v;
            } else {
                out[1] = -v;
            }
        } else {
            if (side != 0) {
                out[0] = -v;
            } else {
                out[1] = -v;
            }
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D08C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D114);

EXTERN_C void *func_8008D1E4(void)
{
    return D_800B1B48.p;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D1F4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D450);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D4C0);

EXTERN_C char *func_8008D5A8(unsigned short id)
{
    char *p;

    for (p = FIELD_AT(&D_800B18FC, char *, 0x15C); p != 0; p = FIELD_AT(p, char *, 0x20)) {
        if (FIELD_AT(p, unsigned short, 0x4) == id) {
            return p;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D5E8);

struct SndNode_800B1A58 { int unk0; unsigned short unk4; char pad6[6]; int unkC; char pad10[0x10]; SndNode_800B1A58 *next; };
struct GlobalPtr_800B1A58 { SndNode_800B1A58 *p; int pad[2]; };
EXTERN_C GlobalPtr_800B1A58 D_800B1A58;

EXTERN_C SndNode_800B1A58 *func_8008D6AC(int id)
{
    SndNode_800B1A58 *p;

    for (p = D_800B1A58.p; p != 0; p = p->next) {
        if (p->unkC == id) {
            break;
        }
    }
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D6E8);

EXTERN_C void func_8008D808(void *n)
{
    SoundState *s;

    func_8008BAC4();
    s = &D_800B18FC;
    FIELD_AT(n, void *, 0x4) = FIELD_AT(s, void *, 0x150);
    FIELD_AT(s, void *, 0x150) = n;
    func_8008BA68();
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D84C);

EXTERN_C void func_8008D8F4(char *p)
{
    if (FIELD_AT(p, char *, 0x10) != 0) {
        func_8008BE08(FIELD_AT(p, char *, 0x10));
    }
    if (FIELD_AT(p, char *, 0xC) != 0) {
        func_8008BE08(FIELD_AT(p, char *, 0xC));
    }
    func_8008BE08(p);
}

EXTERN_C int func_8008D950(void *self)
{
    if (!(FIELD_AT(self, short, 0x24) & 0x8000)) {
        return (FIELD_AT(self, unsigned short, 0x24) & 0x100) != 0 ? 2 : 0;
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D97C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DA00);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DACC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DBEC);

EXTERN_C void func_8008DC78(void *self, int v, int dur)
{
    FIELD_AT(self, short, 0x86) = v << 8;
    if (dur == 0) {
        FIELD_AT(self, int, 0x7C) = v << 24;
        FIELD_AT(self, short, 0x84) = 0;
        func_80093A80(self, 8);
    } else {
        int d = (v << 16) - (FIELD_AT(self, int, 0x7C) >> 8);
        if (d != 0) {
            FIELD_AT(self, short, 0x84) = dur;
            FIELD_AT(self, int, 0x80) = (d / dur) << 8;
        }
    }
}

EXTERN_C void func_8008DCE4(void *self, int v, int dur)
{
    FIELD_AT(self, short, 0x86) = v << 8;
    if (dur == 0) {
        FIELD_AT(self, int, 0x7C) = v << 24;
        FIELD_AT(self, short, 0x84) = 0;
        func_80093A80(self, 4);
    } else {
        int d = (v << 16) - (FIELD_AT(self, int, 0x7C) >> 8);
        if (d != 0) {
            FIELD_AT(self, short, 0x84) = dur;
            FIELD_AT(self, int, 0x80) = (d / dur) << 8;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DD50);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DEE4);

EXTERN_C void func_8008E024(void *drv)
{
    int n = FIELD_AT(drv, unsigned char, 0x2A) - 1;
    char *t = FIELD_AT(drv, char *, 0xC);

    while (n != 0) {
        n--;
        FIELD_AT(t, short, 0x1D0) = 0x7F;
        FIELD_AT(t, short, 0x1D2) = 0x40;
        t += 0x160;
    }
}

EXTERN_C void func_8008E060(void)
{
}

EXTERN_C void func_8008E068(void *self, Time_8008E134 *t)
{
    func_8008E134(FIELD_AT(self, unsigned int, 0x50) >> 8, t);
    FIELD_AT(t, int, 0x8) = FIELD_AT(self, int, 0x4C);
}

EXTERN_C void *func_8008E0B0(void *self)
{
    return (char *)self + 0x58;
}

EXTERN_C void func_8008E0B8(void *self, unsigned char **out)
{
    unsigned char *p = FIELD_AT(self, unsigned char *, 0x1C);

    out[0] = p;
    while (*p++ != 0) {
    }
    out[1] = p;
    while (*p++ != 0) {
    }
    out[2] = p;
    while (*p++ != 0) {
    }
    out[3] = p;
}

EXTERN_C void func_8008E104(void)
{
}

EXTERN_C unsigned char func_8008E10C(void *self)
{
    return FIELD_AT(self, unsigned char, 0x2E);
}

EXTERN_C void func_8008E118(void *self, int b)
{
    FIELD_AT(self, char, 0x2D) = b;
}

EXTERN_C void func_8008E120(void *self, int b)
{
    FIELD_AT(self, int, 0xAC) = b;
}

EXTERN_C void func_8008E128(void *self, int b, int c)
{
    FIELD_AT(self, int, 0xB0) = b;
    FIELD_AT(self, char, 0x2F) = c;
}

EXTERN_C void func_8008E134(unsigned int n, Time_8008E134 *t)
{
    unsigned int s = n / 240;
    unsigned int m = s / 60;

    t->unk7 = 0;
    t->ticks = n % 240;
    t->unk6 = (n % 240) >> 3;
    t->seconds = s % 60;
    t->hours = m / 60;
    t->minutes = m % 60;
}

EXTERN_C void func_8008E1B4(void *t)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    char *v = FIELD_AT(t, char *, 0x24);

    while (n--) {
        func_80093E80((Slot_80093D8C *)(v + 0xB4));
        v += 0xE4;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E210);

EXTERN_C void func_8008E2A0(void *t)
{
    if (FIELD_AT(t, short, 0x0) != 0) {
        int n = FIELD_AT(t, unsigned char, 0x8);
        char *v = FIELD_AT(t, char *, 0x24);

        while (n--) {
            func_80093EE0((Slot_80093D8C *)(v + 0xB4));
            v += 0xE4;
        }
    }
}

EXTERN_C void *func_8008E308(int id, int a, int b)
{
    void *p = func_8008E360(id);

    if (p != 0) {
        func_8008E590(p, a, b);
    }
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E360);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E504);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E590);

EXTERN_C void func_8008E678(void *self, int a, int b)
{
    func_8008DACC(self, a, b);
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E698);

EXTERN_C void func_8008E70C(void *self, int a)
{
    if (self == 0) {
        func_8009482C(5, 0);
        return;
    }
    if (!(FIELD_AT(self, unsigned short, 0x24) & 0x100)) {
        func_8008DACC(self, 0, a);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E75C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E994);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EA9C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EB40);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008ECB4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008ED44);

EXTERN_C void func_8008EDE0(void *n)
{
    SoundState *s;

    func_8008BAC4();
    s = &D_800B18FC;
    FIELD_AT(n, void *, 0x18) = FIELD_AT(s, void *, 0x158);
    FIELD_AT(s, void *, 0x158) = n;
    func_8008BA68();
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EE24);

EXTERN_C unsigned char func_8008EECC(int a)
{
    SoundState *s = &D_800B18FC;
    int max = FIELD_AT(FIELD_AT(s, char *, 0x154), unsigned char, 0x2A);

    if (a != 0) {
        if (max < a) {
            a = max;
        }
        if (a < 4) {
            a = 4;
        }
        FIELD_AT(s, unsigned char, 0x252) = a;
    }
    return FIELD_AT(&D_800B18FC, unsigned char, 0x252);
}

EXTERN_C void func_8008EF18(int a)
{
    func_8008F0CC(a, 0x60, 0x40, 0x100);
}

EXTERN_C void func_8008EF40(int a)
{
    func_8008EF64(a, 0x60, 0x40);
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EF64);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008F0CC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008F1DC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008F4B0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008F618);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FA34);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FAB4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FB80);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FC38);

EXTERN_C int func_8008FD04(void)
{
    char *drv = FIELD_AT(&D_800B18FC, char *, 0x154);
    char *t = FIELD_AT(drv, char *, 0xC);
    int i = FIELD_AT(drv, unsigned char, 0x2A);

    do {
        if (FIELD_AT(t, short, 0x0) & 0x8000) {
            return 1;
        }
        t += 0x160;
    } while (--i);
    return 0;
}

EXTERN_C int func_8008FD44(int id)
{
    char *drv = FIELD_AT(&D_800B18FC, char *, 0x154);
    char *t = FIELD_AT(drv, char *, 0xC);
    int i = FIELD_AT(drv, unsigned char, 0x2A);

    do {
        if ((FIELD_AT(t, short, 0x0) & 0x8000) && FIELD_AT(t, int, 0x10) == id) {
            return 1;
        }
        t += 0x160;
    } while (--i);
    return 0;
}

EXTERN_C int func_8008FD94(unsigned short id)
{
    char *drv = FIELD_AT(&D_800B18FC, char *, 0x154);
    char *t = FIELD_AT(drv, char *, 0xC);
    int i = FIELD_AT(drv, unsigned char, 0x2A);

    do {
        if ((FIELD_AT(t, short, 0x0) & 0x8000) && FIELD_AT(t, unsigned short, 0x12) == id) {
            return 1;
        }
        t += 0x160;
    } while (--i);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FDE4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FEAC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FFF0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009031C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80090550);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80090724);

struct Ent_80090A88 {
    char pad[3];
    unsigned char unk3;
    char pad4[4];
};

EXTERN_C Ent_80090A88 *func_80090A88(Ent_80090A88 *e, int x)
{
    do {
        e++;
    } while (e->unk3 < x);
    return e;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80090AAC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80090CF4);

EXTERN_C int func_800912DC(void *drv, SeqTrack *t)
{
    char *p = FIELD_AT(&D_800B18FC, char *, 0x158);
    unsigned short id = FIELD_AT(t, unsigned short, 0x12);

    for (; p != 0; p = FIELD_AT(p, char *, 0x18)) {
        if (id == FIELD_AT(p, unsigned short, 0x14)) {
            return 0;
        }
    }
    func_8009484C(0xC3, (int)t);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091334);

EXTERN_C unsigned char *func_800916A0(void *drv, SeqTrack *t, unsigned char *p)
{
    func_8009484C(0xC0, (int)p);
    t->flags &= 0x7FFF;
    func_8008E1B4(t);
    return --p;
}

EXTERN_C unsigned char *func_800916F4(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44;
    return p;
}

EXTERN_C unsigned char *func_80091708(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = t->unk48;
    return p;
}

EXTERN_C unsigned char *func_80091720(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = (signed char)*p + t->unk44;
    return p + 1;
}

EXTERN_C unsigned char *func_80091740(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = (signed char)*p + t->unk48;
    return p + 1;
}

EXTERN_C unsigned char *func_80091760(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = *p;
    return p + 1;
}

EXTERN_C unsigned char *func_80091778(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk40 = t->unk44 = p[0] + (p[1] << 8);
    return p + 2;
}

EXTERN_C unsigned char *func_80091798(void *drv, SeqTrack *t, unsigned char *p)
{
    int v = p[0];
    v += p[1] << 8;
    v += p[2] << 16;
    t->unk40 = t->unk44 = v;
    return p + 3;
}

EXTERN_C unsigned char *func_800917C4(void *drv, SeqTrack *t, unsigned char *p)
{
    int v = *p;
    t->flags = (t->flags | 0x400) & ~0x300;
    t->unk40 = v;
    return p + 1;
}

EXTERN_C unsigned char *func_800917E4(void *drv, SeqTrack *t, unsigned char *p)
{
    int v = *p;
    t->flags |= 0x100;
    t->unk40 = v;
    return p + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091800);

EXTERN_C unsigned char *func_80091878(void *drv, SeqTrack *t, unsigned char *p)
{
    t->mark = p;
    t->unk44 = 0;
    t->unk48 = 0;
    t->unk3F = t->octave;
    return p;
}

EXTERN_C unsigned char *func_80091894(void *drv, SeqTrack *t, unsigned char *p)
{
    t->octave = *p * 12;
    return p + 1;
}

EXTERN_C unsigned char *func_800918B4(void *drv, SeqTrack *t, unsigned char *p)
{
    t->octave = (t->octave + (signed char)*p * 12) & 0x7F;
    return p + 1;
}

EXTERN_C unsigned char *func_800918E0(void *drv, SeqTrack *t, unsigned char *p)
{
    t->octave += 12;
    return p;
}

EXTERN_C unsigned char *func_800918F8(void *drv, SeqTrack *t, unsigned char *p)
{
    t->octave -= 12;
    return p;
}

EXTERN_C unsigned char *func_80091910(void *drv, SeqTrack *t, unsigned char *p)
{
    Loop_80091910 *e;

    FIELD_AT(t, unsigned char, 0xE)++;
    e = &((Loop_80091910 *)((char *)t + 0x90))[FIELD_AT(t, unsigned char, 0xE)];
    e->count = *p++ - 1;
    e->start = p;
    e->octave = t->octave;
    return p;
}

EXTERN_C unsigned char *func_80091958(void *drv, SeqTrack *t, unsigned char *p)
{
    Loop_80091910 *e = &((Loop_80091910 *)((char *)t + 0x90))[FIELD_AT(t, unsigned char, 0xE)];

    if (--e->count != 0xFF) {
        e->end = p;
        e->octave2 = t->octave;
        p = e->start;
        t->octave = e->octave;
    } else {
        FIELD_AT(t, unsigned char, 0xE)--;
    }
    return p;
}

EXTERN_C unsigned char *func_800919C4(void *drv, SeqTrack *t, unsigned char *p)
{
    Loop_80091910 *e = &((Loop_80091910 *)((char *)t + 0x90))[FIELD_AT(t, unsigned char, 0xE)];

    if (e->count == 0) {
        p = e->end;
        t->octave = e->octave2;
        FIELD_AT(t, unsigned char, 0xE)--;
    }
    return p;
}

EXTERN_C unsigned char *func_80091A10(void *t, void *drv, unsigned char *p)
{
    int v = *p;

    FIELD_AT(t, int, 0x34) = v << 16;
    FIELD_AT(t, int, 0x44) = (v * 13981 >> 14) * FIELD_AT(t, short, 0x72);
    return p + 1;
}

EXTERN_C unsigned char *func_80091A5C(void *t, void *drv, unsigned char *p)
{
    int v = FIELD_AT(t, int, 0x34) + (*p << 16);

    FIELD_AT(t, int, 0x34) = v;
    FIELD_AT(t, int, 0x44) = ((v >> 16) * 55924 >> 16) * FIELD_AT(t, short, 0x72);
    return p + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091AB4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091B38);

EXTERN_C unsigned char *func_80091B68(void *drv, SeqTrack *t, unsigned char *p)
{
    FIELD_AT(drv, short, 0x5A) = p[0] - 1;
    FIELD_AT(drv, short, 0x5C) = p[1] - 1;
    return p + 2;
}

EXTERN_C unsigned char *func_80091B90(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk4C = *p + (t->unk4C & 0xFF00);
    return p + 1;
}

EXTERN_C unsigned char *func_80091BAC(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk4C = (unsigned char)t->unk4C + (*p << 8);
    return p + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091BC8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091C94);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091D70);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091ED0);

EXTERN_C unsigned char *func_80091FB4(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];
    int b = p[1];
    int c = p[2];

    while (n--) {
        v->unkD8 = a;
        v->unkD9 = b;
        v->unkDA = c;
        v->flags |= 0x1F0;
        v++;
    }
    return p + 3;
}

EXTERN_C unsigned char *func_8009200C(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];

    while (n--) {
        v->unkDB = a;
        v->flags |= 0x10;
        v++;
    }
    return p + 1;
}

EXTERN_C unsigned char *func_80092054(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];

    while (n--) {
        v->unkDC = a;
        v->flags |= 0x20;
        v++;
    }
    return p + 1;
}

EXTERN_C unsigned char *func_8009209C(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];

    while (n--) {
        v->unkDF = a;
        v->flags |= 0x100;
        v++;
    }
    return p + 1;
}

EXTERN_C unsigned char *func_800920E4(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];

    while (n--) {
        v->unkDD = a;
        v->flags |= 0x40;
        v++;
    }
    return p + 1;
}

EXTERN_C unsigned char *func_8009212C(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];

    while (n--) {
        v->unk8 = a;
        v->unkDE = a;
        v->flags |= 0x80;
        v++;
    }
    return p + 1;
}

EXTERN_C unsigned char *func_80092178(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];
    int b = p[1];

    while (n--) {
        v->unkDC = a;
        v->unkDF = b;
        v->flags |= 0x120;
        v++;
    }
    return p + 2;
}

EXTERN_C unsigned char *func_800921C8(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];

    while (n--) {
        v->unkD8 = a;
        v->flags |= 0x10;
        v++;
    }
    return p + 1;
}

EXTERN_C unsigned char *func_80092210(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];

    while (n--) {
        v->unkD9 = a;
        v->flags |= 0x40;
        v++;
    }
    return p + 1;
}

EXTERN_C unsigned char *func_80092258(void *drv, void *t, unsigned char *p)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    int a = p[0];

    while (n--) {
        v->unkDA = a;
        v->flags |= 0x80;
        v++;
    }
    return p + 1;
}

EXTERN_C unsigned char *func_800922A0(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk50 = *p;
    return p + 1;
}

EXTERN_C unsigned char *func_800922B4(void *drv, SeqTrack *t, unsigned char *p)
{
    t->flags |= 0x800;
    return p;
}

EXTERN_C unsigned char *func_800922CC(void *drv, SeqTrack *t, unsigned char *p)
{
    t->flags &= ~0x800;
    return p;
}

EXTERN_C unsigned char *func_800922E4(void *drv, void *t, unsigned char *p)
{
    func_800939A8(t, 0x10, 0x1000);
    return p;
}

EXTERN_C unsigned char *func_8009231C(void *drv, void *t, unsigned char *p)
{
    func_800939F4(t, 0x10, 0x1000);
    return p;
}

EXTERN_C unsigned char *func_80092354(void *drv, void *t, unsigned char *p)
{
    int v = *p;

    FIELD_AT(drv, unsigned char, 0x30) = v;
    SpuSetNoiseClock(v);
    func_800939A8(t, 0x20, 0x2000);
    return p + 1;
}

EXTERN_C unsigned char *func_800923A8(void *drv, void *t, unsigned char *p)
{
    int v = (FIELD_AT(drv, unsigned char, 0x30) + (signed char)*p) & 0x3F;

    FIELD_AT(drv, unsigned char, 0x30) = v;
    SpuSetNoiseClock(v);
    func_800939A8(t, 0x20, 0x2000);
    return p + 1;
}

EXTERN_C unsigned char *func_80092408(void *drv, void *t, unsigned char *p)
{
    func_800939A8(t, 0x20, 0x2000);
    return p;
}

EXTERN_C unsigned char *func_80092440(void *drv, void *t, unsigned char *p)
{
    func_800939F4(t, 0x20, 0x2000);
    return p;
}

EXTERN_C unsigned char *func_80092478(void *t, void *drv, unsigned char *p)
{
    int a = p[0];
    int b;
    int c;

    FIELD_AT(t, short, 0x6A) = a << 8;
    FIELD_AT(t, signed char, 0x6E) = b = (signed char)p[1];
    FIELD_AT(t, signed char, 0x6F) = c = (signed char)p[2];
    func_8008CE18(-1, (short)(a << 8), b, c);
    return p + 3;
}

EXTERN_C unsigned char *func_800924D0(void *drv, void *t, unsigned char *p)
{
    func_800939A8(t, 0x40, 0x4000);
    return p;
}

EXTERN_C unsigned char *func_80092508(void *drv, void *t, unsigned char *p)
{
    func_800939F4(t, 0x40, 0x4000);
    return p;
}

EXTERN_C unsigned char *func_80092540(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, short, 0x54) = (signed char)*p << 5;
    func_80093A40(t, 8);
    return p + 1;
}

EXTERN_C unsigned char *func_80092584(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, short, 0x54) += (signed char)*p << 5;
    func_80093A40(t, 8);
    return p + 1;
}

EXTERN_C unsigned char *func_800925D0(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, short, 0x54) += (signed char)*p << 3;
    func_80093A40(t, 8);
    return p + 1;
}

EXTERN_C unsigned char *func_8009261C(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, short, 0x54) = p[0] + ((signed char)p[1] << 8);
    func_80093A40(t, 8);
    return p + 2;
}

EXTERN_C unsigned char *func_80092668(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, int, 0x58) = (p[0] << 16) + ((signed char)p[1] << 24);
    FIELD_AT(t, short, 0x88) = 0;
    func_80093A40(t, 8);
    return p + 2;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800926B8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092754);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800927C8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092910);

EXTERN_C unsigned char *func_80092A98(void *drv, void *t, unsigned char *p)
{
    func_80093710(t, 0);
    return p;
}

EXTERN_C unsigned char *func_80092ACC(void *drv, void *t, unsigned char *p)
{
    func_80093788(t, 0);
    return p;
}

EXTERN_C unsigned char *func_80092B00(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, int, 0x58) = 0;
    FIELD_AT(t, short, 0x88) = 0;
    func_80093A40(t, 8);
    return p;
}

EXTERN_C unsigned char *func_80092B3C(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, int, 0x64) = *p << 22;
    func_80093A40(t, 4);
    FIELD_AT(t, unsigned short, 0x2) &= ~0x108;
    return p + 1;
}

EXTERN_C unsigned char *func_80092B98(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, int, 0x64) = (*p << 22) + FIELD_AT(t, int, 0x64);
    func_80093A40(t, 4);
    FIELD_AT(t, unsigned short, 0x2) &= ~0x108;
    return p + 1;
}

EXTERN_C unsigned char *func_80092BFC(void *drv, SeqTrack *t, unsigned char *p)
{
    int dur = p[0] + (p[1] << 8);
    int target = p[2];
    int d = (target << 22) - FIELD_AT(t, int, 0x64);

    if (dur != 0 && d != 0) {
        int q = d / dur;
        FIELD_AT(t, unsigned char, 0x85) = target;
        FIELD_AT(t, short, 0x8A) = dur;
        FIELD_AT(t, unsigned short, 0x2) = (FIELD_AT(t, unsigned short, 0x2) | 8) & ~0x100;
        FIELD_AT(t, int, 0x78) = q;
    }
    return p + 3;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092C54);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092CC8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092DE8);

EXTERN_C unsigned char *func_80092F54(void *drv, void *t, unsigned char *p)
{
    func_80093710(t, 1);
    return p;
}

EXTERN_C unsigned char *func_80092F88(void *drv, void *t, unsigned char *p)
{
    func_80093788(t, 1);
    return p;
}

EXTERN_C unsigned char *func_80092FBC(void *drv, void *t, unsigned char *p)
{
    FIELD_AT(t, int, 0x60) = *p << 16;
    func_80093A40(t, 4);
    FIELD_AT(t, unsigned short, 0x2) &= ~0x10;
    return p + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093018);

EXTERN_C unsigned char *func_80093088(void *drv, SeqTrack *t, unsigned char *p)
{
    unsigned short dur = p[0] + (p[1] << 8);
    int target = p[2];
    int d = (target << 16) - FIELD_AT(t, int, 0x60);

    if (dur != 0 && d != 0) {
        int q = d / dur;
        FIELD_AT(t, unsigned char, 0x86) = target;
        FIELD_AT(t, short, 0x8C) = dur;
        FIELD_AT(t, unsigned short, 0x2) |= 0x10;
        FIELD_AT(t, int, 0x7C) = q;
    }
    return p + 3;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800930E0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093154);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009327C);

EXTERN_C unsigned char *func_800933E8(void *drv, void *t, unsigned char *p)
{
    func_80093710(t, 2);
    return p;
}

EXTERN_C unsigned char *func_8009341C(void *drv, void *t, unsigned char *p)
{
    func_80093788(t, 2);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093450);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093524);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093610);

EXTERN_C unsigned char *func_800936A0(void *drv, void *t, unsigned char *p)
{
    func_80093710(t, *p);
    return p + 1;
}

EXTERN_C unsigned char *func_800936D8(void *drv, void *t, unsigned char *p)
{
    func_80093788(t, *p);
    return p + 1;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093710);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093788);

EXTERN_C void func_80093800(void *drv, Node_80093800 *n)
{
    n->unk8 = 0;
    n->flags &= ~0x60;
    n->unk14 = 1;
    n->unk18 = n->unk1A;
    n->unk1C = n->unk1E;
    if (!(n->flags & 1)) {
        n->flags |= 1;
        n->next = FIELD_AT(drv, Node_80093800 *, 0xA8);
        FIELD_AT(drv, Node_80093800 *, 0xA8) = n;
    }
}

EXTERN_C void func_80093858(void *drv, Node_80093800 *n)
{
    Node_80093800 *p;

    if (n->flags & 1) {
        n->flags = 0;
        p = FIELD_AT(drv, Node_80093800 *, 0xA8);
        if (p == n) {
            FIELD_AT(drv, Node_80093800 *, 0xA8) = p->next;
        } else {
            if (p->next != n) {
                n = p->next;
            }
            p->next = n->next;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800938B4);

EXTERN_C int func_80093928(void *self, int b, int c)
{
    return c + 3;
}

EXTERN_C int func_80093930(void *self, int b, int c)
{
    return c + 2;
}

EXTERN_C unsigned char *func_80093938(void *self, int b, unsigned char *p)
{
    FIELD_AT(self, int, 0x50) = (p[0] * 864000 + p[1] * 14400 + p[2] * 240 + p[3] * 8) << 8;
    return p + 5;
}

EXTERN_C void func_800939A8(void *t, int a, int b)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);

    while (n--) {
        v->unkB6 |= a;
        v->flags |= b;
        v++;
    }
}

EXTERN_C void func_800939F4(void *t, int a, int b)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80091FB4 *v = FIELD_AT(t, Voice_80091FB4 *, 0x24);

    a = ~a; // before the loop, so the assembler can fill the branch delay slot with it (GCC 2.7.2)
    while (n--) {
        v->unkB6 &= a;
        v->flags |= b;
        v++;
    }
}

EXTERN_C void func_80093A40(void *t, int bits)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    char *v = FIELD_AT(t, char *, 0x24);

    while (n--) {
        FIELD_AT(v, unsigned char, 0xB) |= bits;
        v += 0xE4;
    }
}

EXTERN_C void func_80093A80(void *drv, int bits)
{
    char *t = FIELD_AT(drv, char *, 0xC);
    int i = FIELD_AT(drv, unsigned char, 0x2A);

    do {
        if (FIELD_AT(t, short, 0x0) < 0) {
            int n = FIELD_AT(t, unsigned char, 0x8);
            char *v = FIELD_AT(t, char *, 0x24);
            while (n--) {
                FIELD_AT(v, unsigned char, 0xB) |= bits;
                v += 0xE4;
            }
        }
        t += 0x160;
    } while (--i);
}

EXTERN_C void func_80093AEC(void)
{
    SoundState *s = &D_800B18FC;
    int i;

    for (i = 0x17; i >= 0; i--) {
        FIELD_AT(s, void *, i * 4 + 0x1CC) = 0;
    }
    FIELD_AT(&D_800B18FC, void *, 0x238) = 0;
    SpuSetKey(0, 0xFFFFFF);
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093B3C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093BB8);

EXTERN_C void func_80093C9C(void)
{
    char *n;

    for (n = FIELD_AT(&D_800B18FC, char *, 0x238); n != 0; n = FIELD_AT(n, char *, 0x2C)) {
        func_80093DE8(n);
    }
    FIELD_AT(&D_800B18FC, char *, 0x238) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093CE8);

EXTERN_C void func_80093D8C(Slot_80093D8C *s)
{
    int i = s->idx;
    Slot_80093D8C **slot = &(&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC))[i];

    if ((unsigned int)i < 0x18) {
        Slot_80093D8C *cur = *slot;
        if (cur != s && (cur == 0 || cur->prio <= s->prio)) {
            *slot = s;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093DE8);

EXTERN_C void func_80093E80(Slot_80093D8C *s)
{
    int i = s->idx;
    Slot_80093D8C **slot = &(&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC))[i];

    if ((unsigned int)i < 0x18 && *slot == s) {
        SoundState *d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC) - 0x1CC);
        *slot = 0;
        FIELD_AT(d, int, 0x234) |= 1 << i;
        FIELD_AT(d, int, 0x22C) &= ~(1 << i);
    }
}

EXTERN_C void func_80093EE0(Slot_80093D8C *s)
{
    int i = s->idx;
    Slot_80093D8C **slot = &(&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC))[i];

    if ((unsigned int)i < 0x18 && *slot == s) {
        SoundState *d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, Slot_80093D8C *, 0x1CC) - 0x1CC);
        *slot = 0;
        FIELD_AT(d, int, 0x230) |= 1 << i;
        FIELD_AT(d, int, 0x22C) &= ~(1 << i);
    }
}

EXTERN_C void func_80093F40(Slot_80093D8C *s)
{
    int i = s->idx;

    if ((unsigned int)i < 0x18) {
        SoundState *d = &D_800B18FC;
        if ((&FIELD_AT(d, Slot_80093D8C *, 0x1CC))[i] == s) {
            int m = 1 << i;
            FIELD_AT(d, int, 0x234) |= m;
            FIELD_AT(d, int, 0x22C) &= ~m;
        }
    }
}

EXTERN_C void func_80093F98(Slot_80093D8C *s)
{
    int i = s->idx;

    if ((unsigned int)i < 0x18) {
        SoundState *d = &D_800B18FC;
        if ((&FIELD_AT(d, Slot_80093D8C *, 0x1CC))[i] == s) {
            FIELD_AT(d, int, 0x230) |= 1 << i;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093FE0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009422C);

struct Bytes_800AFFA4 {
    unsigned char v[0xF8];
};
EXTERN_C Bytes_800AFFA4 D_800AFFA4;
struct Shorts_800B009C {
    short v[0x100];
};
EXTERN_C Shorts_800B009C D_800B009C;

EXTERN_C int func_800942E0(unsigned int a)
{
    unsigned int i = (a & 0x7FFF) >> 8;
    int b = D_800AFFA4.v[i];
    int k = (a & 0xFF) + ((b & 0xF) << 8);

    return D_800B009C.v[k] >> (6 - (b >> 4));
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80094330);

EXTERN_C int func_800944E8(unsigned short *flags)
{
    *flags &= ~1;
    return 0;
}

struct Lfo_80094500 {
    unsigned short flags;
    char pad2[6];
    int value;
    int step;
    int depth;
    unsigned short count;
    unsigned short period;
};

EXTERN_C int func_80094500(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        int v = 0;
        l->count = l->period;
        if (l->value == 0) {
            v = l->depth;
        }
        l->value = v;
    }
    return l->value;
}

EXTERN_C int func_80094548(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        int v = l->depth;
        l->count = l->period;
        if (l->flags & 0x40) {
            v = -v;
        }
        l->value = v;
        l->flags ^= 0x40;
    }
    return l->value;
}

EXTERN_C int func_8009459C(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        int v = l->depth;
        l->count = l->period;
        if (l->flags & 0x40) {
            v = -v;
        }
        l->step = v;
        l->flags ^= 0x40;
    }
    return l->value += l->step;
}

EXTERN_C int func_800945FC(Lfo_80094500 *l)
{
    int n = l->count;

    if (--n == 0) {
        unsigned short f = l->flags;
        int v;
        n = l->period;
        if (f & 0x20) {
            n <<= 1;
        }
        v = l->depth;
        l->step = v;
        if (f & 0x40) {
            l->step = -v;
        }
        l->flags = (f | 0x20) ^ 0x40;
    }
    l->count = n;
    return l->value += l->step;
}

struct Timer_80094664 {
    char pad0[0x8];
    int value;
    char padC[0x4];
    int step;
    unsigned short count;
    unsigned short period;
};

EXTERN_C int func_80094664(Timer_80094664 *t)
{
    if (--t->count == 0) {
        t->value = 0;
        t->count = t->period;
    } else {
        t->value += t->step;
    }
    return t->value;
}

struct Rng_800946B0 {
    char pad[0x254];
    int seed;
};

EXTERN_C int func_800946B0(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        Rng_800946B0 *s = (Rng_800946B0 *)&D_800B18FC;
        int r;
        l->count = l->period;
        r = s->seed;
        r ^= r << 17;
        r ^= r >> 15;
        s->seed = r;
        l->value = (l->depth >> 15) * (r & 0x7FFF);
    }
    return l->value;
}

EXTERN_C int func_8009471C(Lfo_80094500 *l)
{
    if (--l->count == 0) {
        Rng_800946B0 *s = (Rng_800946B0 *)&D_800B18FC;
        int r;
        l->count = l->period;
        r = s->seed;
        r ^= r << 17;
        r ^= r >> 15;
        s->seed = r;
        l->value = (l->depth >> 14) * (r & 0x7FFF) - l->depth;
    }
    return l->value;
}

EXTERN_C int func_8009478C(void)
{
    SoundState *s = &D_800B18FC;
    int v = FIELD_AT(s, int, 0x254);
    v ^= v << 17;
    v ^= v >> 15;
    FIELD_AT(s, int, 0x254) = v;
    return v & 0x7FFF;
}

EXTERN_C int func_800947B8(void)
{
    return 0;
}

EXTERN_C int func_800947C0(unsigned int *p, unsigned int v)
{
    if (*p == v) {
        return func_80094800(p) != 0 ? 2 : 0;
    }
    return 1;
}

EXTERN_C unsigned int func_80094800(unsigned int *p)
{
    unsigned int n = (p[2] + 3) >> 2;
    unsigned int s = 0;

    do {
        s += *p++;
    } while (--n != 0);
    return s;
}

EXTERN_C void func_8009482C(int a, int b)
{
    D_800B18FC.unk003 = a;
    D_800B18FC.unk004 = b;
    D_800B18FC.flags |= 8;
}

EXTERN_C void func_8009484C(int a, int b)
{
    D_800B18FC.unk003 = a;
    D_800B18FC.unk004 = b;
    D_800B18FC.flags |= 8;
}

EXTERN_C void func_80094888(void);

EXTERN_C void func_8009486C(void *self)
{
    void *p = D_800B1A68.p;
    FIELD_AT(self, void *, 0x10) = (void *)func_80094888;
    FIELD_AT(self, void *, 0x14) = p;
}

EXTERN_C void func_80094888(void)
{
}

struct Short_800B1B54 { unsigned short v; char pad[0xA]; };
struct Byte_800B1B56 { unsigned char v; char pad[0xB]; };
EXTERN_C Short_800B1B54 D_800B1B54;
EXTERN_C Byte_800B1B56 D_800B1B56;

EXTERN_C void func_80094890(void *p)
{
    if (p != 0) {
        D_800B1B54.v = FIELD_AT(p, unsigned short, 0x14);
    } else {
        D_800B1B54.v = 0;
    }
    D_800B1B56.v = 0;
}

EXTERN_C void func_800948B4(int a, int b, int c)
{
    SoundState *s = &D_800B18FC;
    int k = FIELD_AT(s, unsigned short, 0x258);

    if (k != 0) {
        int t = FIELD_AT(s, unsigned char, 0x25A);
        FIELD_AT(s, unsigned char, 0x25A) = t == 0;
        func_8008EF64((k << 16) + a * 2 + t, b, c);
    }
}

EXTERN_C void func_80094908(void)
{
}
