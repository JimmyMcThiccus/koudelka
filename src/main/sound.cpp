#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/sound/sound.h"

EXTERN_C void func_8008BBB0(char *p, int n);
EXTERN_C void func_8009482C(int a, int b);
EXTERN_C void func_8008BFEC(void);
EXTERN_C void func_8008C6F8(void);
EXTERN_C void func_80093AEC(void);
EXTERN_C int func_8008FDE4(void);
EXTERN_C void func_8008C9A8(void);
EXTERN_C void func_8008CB84(void);
EXTERN_C void func_8009F6D0(void (*f)(void));
EXTERN_C long OpenEvent(unsigned long desc, long spec, long mode, void (*func)(void));
EXTERN_C long SetRCnt(unsigned long spec, unsigned short target, long mode);
EXTERN_C long StartRCnt(unsigned long spec);
EXTERN_C long EnableEvent(unsigned long event);
EXTERN_C void SpuSetIRQ(long on_off);
EXTERN_C void SpuSetIRQCallback(void (*f)(void));
EXTERN_C long SpuSetReverb(long on_off);
EXTERN_C void func_8008CC20(int a);
EXTERN_C void func_8008CC88(int a, int b);
EXTERN_C void func_8008CD1C(int v, int dur);
EXTERN_C void func_8008CDA8(int a);
EXTERN_C void func_8008CD88(int a, int b);
EXTERN_C void func_8008CE18(int a, int b, int c, int d);

EXTERN_C char *func_8008B6B0(char *p, int n, int mode)
{
    SoundState *s = &D_800B18FC;
    int flags;

    if ((short)D_800B18FC.flags < 0) {
        func_8009482C(0x80, 0);
        return 0;
    }
    flags = 0x8E01;
    if (mode & 1) {
        flags = 0xAE01;
    }
    D_800B18FC.flags = flags;
    FIELD_AT(s, int, 0x254) = 0x12345678;
    FIELD_AT(s, int, 0x150) = 0;
    FIELD_AT(s, int, 0x154) = 0;
    FIELD_AT(s, int, 0x158) = 0;
    FIELD_AT(s, int, 0x15C) = 0;
    FIELD_AT(s, int, 0x160) = 0;
    FIELD_AT(s, int, 0x22C) = 0;
    FIELD_AT(s, int, 0x230) = 0;
    FIELD_AT(s, int, 0x234) = 0;
    FIELD_AT(s, int, 0x144) = 0;
    FIELD_AT(s, int, 0x14C) = 0;
    func_8008BBB0(p, n);
    func_8008BFEC();
    func_8008C6F8();
    func_80093AEC();
    func_80094990();
    if (!(flags & 0x2000)) {
        FIELD_AT(s, long, 0x13C) = OpenEvent(0xF2000002, 2, 0x1000, (void (*)(void))func_8008FDE4);
        SetRCnt(0xF2000002, 0x44E8, 0x1000);
        StartRCnt(0xF2000002);
        EnableEvent(FIELD_AT(s, long, 0x13C));
    }
    func_8009F6D0(func_8008C9A8);
    SpuSetIRQ(0);
    SpuSetIRQ(3);
    SpuSetIRQCallback(func_8008CB84);
    func_800949A0();
    FIELD_AT(s, short, 0x178) = 0;
    FIELD_AT(s, short, 0x17A) = 0;
    FIELD_AT(s, int, 0x170) = 0xC;
    func_8008CC20(1);
    func_8008CC88(0x3FFF, 0);
    func_8008CD1C(0, 0);
    func_8008CDA8(0x80);
    func_8008CD88(0, 1);
    FIELD_AT(s, char *, 0x154) = (char *)func_8008EB40(0xC);
    func_8008D808(FIELD_AT(s, char *, 0x154));
    FIELD_AT(s, unsigned char, 0x252) = 0xC;
    SpuSetReverb(1);
    FIELD_AT(s, int, 0x1C8) = -1;
    FIELD_AT(s, int, 0x24C) = 0;
    FIELD_AT(s, unsigned char, 0x1BD) = 0xFF;
    func_8008CE18(4, 0, 0, 0);
    return p;
}

EXTERN_C void func_8009482C(int a, int b);
EXTERN_C long StopRCnt(unsigned long spec);
EXTERN_C long CloseEvent(unsigned long event);
EXTERN_C void SpuSetIRQ(long on_off);
EXTERN_C void SpuSetIRQCallback(void (*f)(void));
EXTERN_C void func_8009F6D0(void (*f)(void));
EXTERN_C void SpuSetKey(long on_off, unsigned long voice_bit);
EXTERN_C void func_800A0800(int a, int b);

EXTERN_C int func_8008B888(void)
{
    SoundState *s = &D_800B18FC;
    int i;

    if (!((short)D_800B18FC.flags & 0x8000)) {
        func_8009482C(0x81, 0);
        return 0;
    }
    if (!(D_800B18FC.flags & 0x2000)) {
        StopRCnt(0xF2000002);
        CloseEvent(FIELD_AT(s, long, 0x13C));
    }
    SpuSetIRQ(0);
    func_8009F6D0(0);
    SpuSetIRQCallback(0);
    D_800B18FC.flags = 0;
    for (i = 0; i < 0x18; i++) {
        SpuSetVoiceRRAttr(i, 6, 3);
    }
    SpuSetKey(0, 0xFFFFFF);
    func_800A0800(0, 0);
    D_800B18FC.unk003 = 0;
    D_800B18FC.unk004 = 0;
    return FIELD_AT(&D_800B18FC, int, 0x8);
}

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

EXTERN_C GlobalWord D_800B4EE0;
EXTERN_C void SpuSetVoiceVolume(int voice, short l, short r);
EXTERN_C void SpuSetVoicePitch(int voice, unsigned short pitch);
EXTERN_C void SpuSetVoiceARAttr(int voice, unsigned short ar, long mode);
EXTERN_C void SpuSetVoiceSRAttr(int voice, unsigned short sr, long mode);

EXTERN_C void func_8008B9C0(void)
{
    volatile int p;
    int i;

    D_800B18FC.flags |= 0x80;
    p = (int)D_800B4EE0.p;
    for (i = 0; i < 0x18; i++) {
        SpuSetVoiceVolume(i, 0, 0);
        SpuSetVoicePitch(i, 0);
        SpuSetVoiceARAttr(i, 0x7F, 1);
        SpuSetVoiceSRAttr(i, 0x7F, 3);
        SpuSetVoiceRRAttr(i, 6, 3);
        p += 0x10;
    }
}

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

EXTERN_C void SpuSetKey(long on_off, unsigned long voice_bit);

EXTERN_C void func_8008BB20(void)
{
    char **pp;
    int i;

    for (i = 0; i < 0x18; i++) {
        SpuSetVoiceRRAttr(i, 6, 3);
    }
    SpuSetKey(0, 0xFFFFFF);
    pp = &FIELD_AT(&D_800B18FC, char *, 0x1CC);
    for (i = 0; i < 0x18; i++, pp++) {
        if (*pp != 0) {
            FIELD_AT(*pp, unsigned short, 0x6) |= 0x1F5;
        }
    }
}

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

struct SpuBlk_8008C060 {
    unsigned char next;
    unsigned char flags;
    unsigned short id;
    int addr;
    int size;
    int pad;
};
EXTERN_C int func_8008C4B8(void);

EXTERN_C int func_8008C060(int size, unsigned short id)
{
    SpuBlk_8008C060 *b = &FIELD_AT(&D_800B18FC, SpuBlk_8008C060, 0x14);
    SpuBlk_8008C060 *n;
    int end = b->addr + b->size;
    int i;

    if (b->next != 0) {
    loop:
        n = &(&FIELD_AT(&D_800B18FC, SpuBlk_8008C060, 0x14))[b->next];
        if (n->addr - end >= size) {
            goto found;
        }
        b = n;
        end = n->addr + n->size;
        if (b->next != 0) {
            goto loop;
        }
    }
    if (0x80000 - end < size) {
        return 0;
    }
found:
    i = func_8008C4B8();
    if (i < 0) {
        return 0;
    }
    n = &(&FIELD_AT(&D_800B18FC, SpuBlk_8008C060, 0x14))[i];
    n->flags = 0x80;
    n->id = id;
    n->addr = end;
    n->size = size;
    n->next = b->next;
    b->next = i;
    return end;
}

struct SpuBlk_8008C168 {
    unsigned char next;
    unsigned char flags;
    unsigned short id;
    int addr;
    int size;
    int pad;
};
EXTERN_C int func_8008C4B8(void);

EXTERN_C int func_8008C168(int size, unsigned short id)
{
    SpuBlk_8008C168 *b = &FIELD_AT(&D_800B18FC, SpuBlk_8008C168, 0x14);
    SpuBlk_8008C168 *best = 0;
    SpuBlk_8008C168 *n;
    int addr;
    int end;
    int i;

    for (;;) {
        end = b->addr + b->size;
        if (b->next == 0) {
            if (0x80000 - end >= size) {
                best = b;
                addr = 0x80000 - size;
            }
            break;
        }
        n = &(&FIELD_AT(&D_800B18FC, SpuBlk_8008C168, 0x14))[b->next];
        if (n->addr - end >= size) {
            best = b;
            addr = n->addr - size;
        }
        b = n;
    }
    if (best == 0) {
        return 0;
    }
    i = func_8008C4B8();
    if (i < 0) {
        return 0;
    }
    n = &(&FIELD_AT(&D_800B18FC, SpuBlk_8008C168, 0x14))[i];
    n->flags = 0x80;
    n->id = id;
    n->addr = addr;
    n->size = size;
    n->next = b->next;
    b->next = i;
    return addr;
}

struct SpuBlk_8008C27C {
    unsigned char next;
    unsigned char flags;
    unsigned short id;
    int addr;
    int size;
    int pad;
};
EXTERN_C int func_8008C4B8(void);

EXTERN_C int func_8008C27C(int size, int addr, unsigned short id)
{
    SpuBlk_8008C27C *b = &FIELD_AT(&D_800B18FC, SpuBlk_8008C27C, 0x14);
    SpuBlk_8008C27C *n;
    int gap = 0;
    int end = b->addr + b->size;
    int lim = addr + size;
    int i;

    while (b->addr < addr) {
        if (b->next == 0) {
            gap = 0x80000 - end;
            break;
        }
        n = &(&FIELD_AT(&D_800B18FC, SpuBlk_8008C27C, 0x14))[b->next];
        if (n->addr >= lim) {
            gap = n->addr - end;
            break;
        }
        end = n->addr + n->size;
        b = n;
    }
    if (gap < size || addr < end) {
        return 0;
    }
    i = func_8008C4B8();
    if (i < 0) {
        return 0;
    }
    n = &(&FIELD_AT(&D_800B18FC, SpuBlk_8008C27C, 0x14))[i];
    n->flags = 0x80;
    n->id = id;
    n->addr = addr;
    n->size = size;
    n->next = b->next;
    b->next = i;
    return addr;
}

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

struct SpuBlk_8008C448 {
    unsigned char next;
    unsigned char flags;
    unsigned short id;
    int addr;
    int size;
    int pad;
};

EXTERN_C int func_8008C448(void)
{
    SpuBlk_8008C448 *b = &FIELD_AT(&D_800B18FC, SpuBlk_8008C448, 0x14);
    int max = 0;
    SpuBlk_8008C448 *tbl = &FIELD_AT(&D_800B18FC, SpuBlk_8008C448, 0x14);
    int end;
    int i;
    int d;

loop:
    end = b->addr + b->size;
    i = b->next;
    if (i != 0) {
        b = (SpuBlk_8008C448 *)((i << 4) + (int)tbl);
        d = b->addr - end;
        if (max < d) {
            max = d;
        }
        goto loop;
    }
    d = 0x80000 - end;
    if (max < d) {
        max = d;
    }
    return max;
}

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

EXTERN_C void func_8008E698(void *a);
EXTERN_C void func_8008D6E8(void *a);
EXTERN_C int func_8008E75C(void *a);
EXTERN_C void func_8008E590(void *s, int b, int c)
{
    short err;

    if (s == 0) {
        func_8009482C(5, 0);
        return;
    }
    if (FIELD_AT(s, short, 0x24) & 0x8000) {
        func_8008E698(s);
    }
    err = func_800947B8(FIELD_AT(s, void *, 0x8));
    if (err != 0) {
        func_8009482C(err, FIELD_AT(s, int, 0x8));
        return;
    }
    func_8008D6E8(s);
    if (func_8008E75C(s) != 0) {
        func_8009482C(0x10, FIELD_AT(s, unsigned short, 0x28));
        return;
    }
    FIELD_AT(s, int, 0x88) = 0;
    FIELD_AT(s, unsigned short, 0x24) |= 0x100;
    func_8008DACC(s, b, c);
}

EXTERN_C void func_8008E678(void *self, int a, int b)
{
    func_8008DACC(self, a, b);
}

EXTERN_C void func_8008E210(void *a);
EXTERN_C void func_8008E698(void *s)
{
    if (s == 0) {
        func_8009482C(5, 0);
        return;
    }
    func_8008BAC4();
    if (FIELD_AT(s, short, 0x24) & 0x8000) {
        func_8008E210(s);
    }
    FIELD_AT(s, unsigned short, 0x24) &= 0x7EFF;
    func_8008BA68();
}

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

struct Voice_8008E75C {
    char pad0[0x9];
    unsigned char unk9;
    unsigned char unkA;
    char padB;
    unsigned char unkC;
    unsigned char unkD;
    short unkE;
    char pad10[0x90];
    short unkA0;
    short unkA2;
    short unkA4;
    short unkA6;
    int unkA8;
    char padAC[4];
    Voice_8008E75C *next;
    short unkB4;
    unsigned char unkB6;
    char padB7;
    short unkB8;
    short unkBA;
    char padBC[0x28];
};
struct Track_8008E75C {
    unsigned short flags;
    short unk02;
    char pad04;
    unsigned char unk05;
    char pad06;
    unsigned char unk07;
    unsigned char nvoice;
    unsigned char voice0;
    unsigned char unk0A;
    char pad0B[3];
    unsigned char unk0E;
    char pad0F;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    Voice_8008E75C *voices;
    int unk28;
    Voice_8008E75C *head;
    char *song;
    int unk34;
    int unk38;
    short unk3C;
    unsigned char unk3E;
    char pad3F;
    int unk40;
    int unk44;
    int unk48;
    short unk4C;
    unsigned char unk4E;
    unsigned char unk4F;
    unsigned char unk50;
    unsigned char unk51;
    unsigned char unk52;
    unsigned char unk53;
    short unk54;
    char pad56[2];
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    char pad68[0xF4];
    int unk15C;
};
EXTERN_C char *func_8008D5A8(unsigned short id);
EXTERN_C void func_8008D5E8(void *v, void *song, short idx);
EXTERN_C int func_8008E75C(void *s)
{
    Track_8008E75C *t = FIELD_AT(s, Track_8008E75C *, 0xC);
    int i = 0;
    int mask = 0;
    char *song;
    Voice_8008E75C *v;
    int n;
    int idx;
    int j;
    int f, x;
    SoundState *ss = &D_800B18FC;

    song = func_8008D5A8(FIELD_AT(s, unsigned short, 0x28));
    if (song == 0) {
        return 0x10;
    }
    FIELD_AT(s, int, 0x14) = FIELD_AT(song, int, 0x1C);
    do {
        f = t->flags | 0x8400;
        x = FIELD_AT(ss, int, 0x144);
        t->unk0A = 0x10;
        t->unk10 = 0;
        t->unk14 = x;
        t->flags = t->unk07 | f;
        t->unk02 = 0;
        t->unk05 = 0;
        t->unk20 = 0;
        t->unk38 = 0;
        t->unk3C = 0;
        t->unk3E = 0;
        t->song = song;
        t->unk34 = 0;
        t->unk40 = 0;
        t->unk44 = 0;
        t->unk48 = 0;
        t->unk1C = t->unk18;
        t->unk4C = FIELD_AT(s, unsigned short, 0x28);
        t->unk50 = 0xF;
        t->unk51 = 0x3C;
        t->unk52 = 0x3C;
        t->unk53 = 0x3C;
        t->unk5C = 0x60000000;
        t->unk64 = 0x19000000;
        t->unk60 = 0x400000;
        t->unk4E = 0xFF;
        t->unk4F = 0;
        t->unk58 = 0;
        t->unk54 = 0;
        t->unk0E = 0xFF;
        mask |= 1 << i;
        v = t->voices;
        n = t->nvoice;
        idx = t->voice0;
        t->unk15C = 0;
        if (n != 0) {
            t->head = v;
            for (;;) {
                n--;
                v->unkA = 0x20;
                v->unkB4 = idx;
                v->unkB6 = 0;
                v->unk9 = 0;
                v->unkE = 0;
                v->unkC = 0;
                v->unkD = 0x7F;
                v->unkA8 = 0;
                for (j = 3; j >= 0; j--) {
                    FIELD_AT(v, short, 0x10 + j * 0x24) = 0;
                }
                v->unkA0 = 0;
                v->unkA2 = 0;
                v->unkA4 = 0;
                v->unkA6 = 0;
                func_8008D5E8(v, song, 0);
                v->unkBA = 0x7FFF;
                v->unkB8 = 0x100;
                if (n == 0) {
                    v->next = 0;
                    break;
                }
                v->next = v + 1;
                idx++;
                v++;
            }
        } else {
            t->head = 0;
        }
        i++;
        t->unk28 = 0;
        t++;
    } while (i < FIELD_AT(s, unsigned char, 0x2A));
    FIELD_AT(s, int, 0x20) = mask & 0xFF;
    return 0;
}

struct Chunk_8008E994 {
    unsigned short type;
    unsigned short size;
    unsigned char unk4;
    unsigned char unk5;
    unsigned char unk6;
    unsigned char unk7;
};
struct Track_8008E994 {
    unsigned short flags;
    char pad02[2];
    unsigned char unk04;
    char pad05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char nvoice;
    unsigned char voice0;
    char pad0A[0xE];
    void *unk18;
    char pad1C[8];
    char *voices;
    char pad28[0x138];
};
EXTERN_C void func_8008E994(void *s)
{
    int go = 1;
    int i = 0;
    Track_8008E994 *t = FIELD_AT(s, Track_8008E994 *, 0xC);
    Chunk_8008E994 *c = (Chunk_8008E994 *)(FIELD_AT(s, char *, 0x8) + 0x20);
    char *data = FIELD_AT(s, char *, 0x10);
    int n;

    do {
        switch (c->type) {
        case 1:
            FIELD_AT(s, void *, 0x1C) = &c->unk4;
            break;
        case 2:
            t->unk04 = i;
            t->unk18 = c + 1;
            n = c->unk4;
            t->voice0 = c->unk5;
            t->nvoice = n;
            t->unk06 = c->unk6;
            t->unk07 = c->unk7;
            t->flags = 0;
            if (n != 0) {
                t->voices = data;
                data += n * 0xE4;
            } else {
                t->voices = 0;
            }
            t++;
            i++;
            break;
        case 5:
            FIELD_AT(s, void *, 0x18) = c;
            break;
        case 4:
        case 0xFFFF:
            go = 0;
            break;
        }
        c = (Chunk_8008E994 *)((char *)c + c->size);
    } while (go);
}

EXTERN_C void *func_8008BD04(int size);
EXTERN_C int *func_8008EA9C(unsigned char *p)
{
    int n = p[4];
    int *tbl = (int *)func_8008BD04(0x120);
    int v;
    unsigned char k;

    while (n--) {
        k = p[9] - 0x18;
        v = p[10] + (p[11] << 8) + (p[12] << 16) + (p[13] << 24);
        tbl[k] = v;
        p += 6;
    }
    return tbl;
}

struct Voice_8008EB40 {
    char pad0[0x9];
    unsigned char unk9;
    unsigned char unkA;
    char padB[0xA9];
    short unkB4;
    char padB6[0x2E];
};
struct Track_8008EB40 {
    unsigned short flags;
    short unk02;
    unsigned char unk04;
    char pad05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char nvoice;
    unsigned char voice0;
    char pad0A[0xE];
    int unk18;
    char pad1C[8];
    Voice_8008EB40 *voices;
    char pad28[0x26];
    unsigned char unk4E;
    char pad4F[0x21];
    short unk70;
    short unk72;
    char pad74[0xEC];
};
struct Song_8008EB40 {
    int magic;
    char pad4[4];
    int unk8;
    Track_8008EB40 *tracks;
    Voice_8008EB40 *voices;
    char pad14[8];
    int unk1C;
    char pad20[0xA];
    unsigned char ntrack;
    unsigned char unk2B;
    unsigned char unk2C;
    unsigned char unk2D;
    unsigned char unk2E;
    unsigned char unk2F;
    unsigned char unk30;
    unsigned char unk31;
    short unk32;
};
EXTERN_C void func_8008D6E8(void *a);
EXTERN_C Song_8008EB40 *func_8008EB40(int n)
{
    Song_8008EB40 *s = (Song_8008EB40 *)func_8008BC0C(0xC0);
    Track_8008EB40 *t = (Track_8008EB40 *)func_8008BC0C(n * sizeof(Track_8008EB40));
    Voice_8008EB40 *v = (Voice_8008EB40 *)func_8008BC0C(n * sizeof(Voice_8008EB40));
    int i;
    int idx;

    s->unk8 = 0;
    func_8008D6E8(s);
    s->magic = 0x71657373;
    s->unk2C = 0x60;
    s->unk1C = 0;
    s->tracks = t;
    s->voices = v;
    s->ntrack = n;
    s->unk2B = 0;
    s->unk2D = 0;
    s->unk2E = 0;
    s->unk2F = 0;
    s->unk30 = 0;
    s->unk31 = 1;
    s->unk32 = 0;
    idx = 0x18 - n;
    for (i = 0; i < n; i++) {
        t->flags = 0;
        t->unk02 = 0;
        t->unk04 = i;
        t->unk18 = 0;
        t->unk4E = 0xFF;
        t->voice0 = idx;
        t->unk06 = 0;
        t->nvoice = 1;
        t->voices = v;
        v->unkA = 0x20;
        v->unkB4 = idx;
        v->unk9 = 0;
        v++;
        t++;
        idx++;
    }
    t = s->tracks;
    i = n;
    while (i != 0) {
        i--;
        t->unk70 = 0x7F;
        t->unk72 = 0x40;
        t++;
    }
    return s;
}

EXTERN_C int func_800947C0(unsigned int *p, unsigned int v);
EXTERN_C void func_8008EDE0(void *n);
EXTERN_C void func_8008ECB4(void *s)
{
    short e;

    if ((FIELD_AT(s, unsigned short, 0x14) >= 0xC000 && FIELD_AT(s, unsigned short, 0x14) < 0xF000)) {
        e = func_800947C0((unsigned int *)s, 0x73646573);
        if (e != 0) {
            func_8009482C(e, (int)s);
            return;
        }
    }
    if (!(FIELD_AT(s, unsigned int, 0) == 0x73646573 || FIELD_AT(s, unsigned int, 0) == 0x70646573)) {
        func_8009482C(0xB, (int)s);
        return;
    }
    func_8008EDE0(s);
}

EXTERN_C int func_800947C0(unsigned int *p, unsigned int v);
EXTERN_C void func_8008FC38(unsigned short id);
EXTERN_C int func_8008EE24(void *s);
EXTERN_C void func_8008ED44(void *s)
{
    short e;

    if (FIELD_AT(s, unsigned int, 0) != 0x73646573 && FIELD_AT(s, unsigned int, 0) != 0x70646573) {
        func_8009482C(0xB, (int)s);
        return;
    }
    func_8008FC38(FIELD_AT(s, unsigned short, 0x14));
    func_8008EE24(s);
    FIELD_AT(s, int, 0x18) = 0;
    if (FIELD_AT(s, unsigned short, 0x14) >= 0xC000 && FIELD_AT(s, unsigned short, 0x14) < 0xF000) {
        e = func_800947C0((unsigned int *)s, 0x73646573);
        if (e != 0) {
            func_8009482C(e, (int)s);
        }
    }
}

EXTERN_C void func_8008EDE0(void *n)
{
    SoundState *s;

    func_8008BAC4();
    s = &D_800B18FC;
    FIELD_AT(n, void *, 0x18) = FIELD_AT(s, void *, 0x158);
    FIELD_AT(s, void *, 0x158) = n;
    func_8008BA68();
}

EXTERN_C int func_8008EE24(void *s)
{
    char *p;
    char *prev;

    func_8008BAC4();
    prev = 0;
    for (p = FIELD_AT(&D_800B18FC, char *, 0x158); p != 0; p = FIELD_AT(p, char *, 0x18)) {
        if (p == s) {
            break;
        }
        prev = p;
    }
    if (p == 0) {
        func_8008BA68();
        func_8009482C(0x12, (int)s);
        return 0x12;
    }
    if (prev != 0) {
        FIELD_AT(prev, char *, 0x18) = FIELD_AT(s, char *, 0x18);
    } else {
        FIELD_AT(&D_800B18FC, char *, 0x158) = FIELD_AT(s, char *, 0x18);
    }
    func_8008BA68();
    return 0;
}

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

struct Bank_8008EF64 {
    unsigned int magic;
    char pad4[0xE];
    unsigned short count;
    unsigned short id;
    unsigned short unk16;
    Bank_8008EF64 *next;
    unsigned short offs[1];
};
EXTERN_C void func_8008EF64(int a, int b, int c)
{
    Req_8008EF64 r;
    unsigned short id = (unsigned int)a >> 16;
    Bank_8008EF64 *p = FIELD_AT(&D_800B18FC, Bank_8008EF64 *, 0x158);
    unsigned short idx;
    unsigned char *q;
    unsigned short *tbl;

    if (p == 0) {
        func_8009482C(0x12, a);
        return;
    }
    if (p->magic != 0x73646573 && p->magic != 0x70646573) {
        func_8009482C(0xB, (int)p);
        return;
    }
    while (p->id != id) {
        p = p->next;
        if (p == 0) {
            func_8009482C(0x12, a);
            return;
        }
    }
    idx = a;
    if (idx >= p->count) {
        func_8009482C(0x13, a);
        return;
    }
    tbl = p->offs;
    if (p->magic == 0x73646573) {
        q = (unsigned char *)p + *(unsigned short *)((char *)tbl + (idx << 1));
        r.unk17 = q[3];
        if (r.unk17 == 0) {
            return;
        }
        r.id = a;
        r.unk14 = p->unk16;
        r.unk16 = 0;
        r.unk18 = 0;
        r.unk19 = 0;
        r.data = q;
        func_8008F4B0(&r);
        func_8008F1DC(&r, b, c);
    } else {
        func_8008F618(a, (Ent_8008F618 *)((char *)tbl + idx * 10), b, c);
    }
}

struct Bank_8008F0CC {
    unsigned int magic;
    char pad4[0xE];
    unsigned short count;
    unsigned short id;
    unsigned short unk16;
    Bank_8008F0CC *next;
    unsigned short offs[1];
};
EXTERN_C void func_8008F0CC(int a, int b, int c, int d)
{
    Req_8008EF64 r;
    unsigned short id = (unsigned int)a >> 16;
    Bank_8008F0CC *p = FIELD_AT(&D_800B18FC, Bank_8008F0CC *, 0x158);
    unsigned short idx;
    unsigned char *q;
    unsigned short *tbl;

    if (p == 0) {
        func_8009482C(0x12, a);
        return;
    }
    while (p->id != id) {
        p = p->next;
        if (p == 0) {
            func_8009482C(0x12, a);
            return;
        }
    }
    idx = a;
    if (idx >= p->count) {
        func_8009482C(0x13, a);
        return;
    }
    tbl = p->offs;
    if (p->magic == 0x73646573) {
        r.id = a;
        r.unk14 = p->unk16;
        r.unk16 = 0;
        r.unk18 = 0;
        r.unk19 = 0;
        q = (unsigned char *)p + *(unsigned short *)((char *)tbl + (idx << 1));
        r.unk17 = q[3];
        r.data = q;
        func_8008F1DC(&r, b, c);
    } else {
        func_8008F618(a, (Ent_8008F618 *)((char *)tbl + idx * 10), b, c);
    }
}

struct Voice_8008F1DC {
    char pad0[0x9];
    unsigned char unk9;
    unsigned char unkA;
    char padB;
    unsigned char unkC;
    unsigned char unkD;
    short unkE;
    char pad10[0x90];
    short unkA0;
    short unkA2;
    short unkA4;
    short unkA6;
    int unkA8;
    char padAC[4];
    Voice_8008F1DC *next;
    short unkB4;
    unsigned char unkB6;
    char padB7;
    short unkB8;
    short unkBA;
    char padBC[0x28];
};
struct Track_8008F1DC {
    short flags;
    short unk02;
    unsigned char unk04;
    unsigned char unk05;
    char pad06;
    unsigned char unk07;
    unsigned char nvoice;
    unsigned char voice0;
    unsigned char unk0A;
    char pad0B[3];
    unsigned char unk0E;
    char pad0F;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    Voice_8008F1DC *voices;
    int unk28;
    Voice_8008F1DC *head;
    char *song;
    int unk34;
    int unk38;
    short unk3C;
    unsigned char unk3E;
    char pad3F;
    int unk40;
    int unk44;
    int unk48;
    short unk4C;
    unsigned char unk4E;
    unsigned char unk4F;
    unsigned char unk50;
    unsigned char unk51;
    unsigned char unk52;
    unsigned char unk53;
    short unk54;
    char pad56[2];
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    char pad68[0xF4];
    int unk15C;
};
EXTERN_C char *func_8008D5A8(unsigned short id);
EXTERN_C void func_8008D5E8(void *v, void *song, short idx);
EXTERN_C void func_8008FAB4(int id);
EXTERN_C int func_8008F1DC(Req_8008EF64 *r, int vol, int pan)
{
    char *song;
    SoundState *ss;
    unsigned char *q;
    char *drv;
    int n;
    int ti;
    Track_8008F1DC *t;
    unsigned short *offs;
    int mask;
    int x;
    int off;
    Voice_8008F1DC *v;
    int j;

    song = func_8008D5A8(r->unk14);
    if (song == 0) {
        func_8009482C(0x14, r->id);
        return 0;
    }
    ss = &D_800B18FC;
    q = r->data;
    drv = FIELD_AT(ss, char *, 0x154);
    n = q[3];
    if (n == 0) {
        return 0;
    }
    ti = r->unk18;
    t = FIELD_AT(drv, Track_8008F1DC *, 0xC) + ti;
    if (t->flags != 0) {
        func_8008FAB4(t->unk10);
    }
    vol = q[1] * vol / 127;
    offs = (unsigned short *)(q + 8);
    mask = 0;
    x = FIELD_AT(ss, int, 0x144);
    func_8008BAC4();
    do {
        off = *offs++;
        if (off != 0) {
            t->unk14 = x;
            t->unk10 = r->id;
            t->unk0A = 0x20;
            t->flags = (short)0x8400;
            t->unk02 = 0;
            t->unk05 = 1;
            t->unk18 = (int)(q + off);
            t->unk1C = (int)(q + off);
            t->unk20 = 0;
            t->unk38 = 0;
            t->unk3C = 0;
            t->unk3E = 0;
            t->song = song;
            t->unk34 = 0;
            t->unk40 = 0;
            t->unk44 = 0;
            t->unk48 = 0;
            t->unk4C = r->unk14;
            t->unk4E = 0xFF;
            t->unk4F = 0;
            t->unk50 = 0xF;
            t->unk51 = 0x3C;
            t->unk52 = 0x3C;
            t->unk53 = 0x3C;
            t->unk5C = vol << 24;
            t->unk64 = 0x1FC00000;
            t->unk60 = pan << 16;
            t->unk58 = 0;
            t->unk54 = 0;
            t->unk0E = 0xFF;
            t->unk15C = 0;
            v = t->voices;
            t->head = v;
            FIELD_AT(v, int, 0) = 0;
            v->unkB6 = 0;
            v->unkB8 = 0x200;
            v->unkA = 0x20;
            func_8008D5E8(v, song, 0);
            v->unk9 = 0;
            v->unkA8 = 0;
            for (j = 3; j >= 0; j--) {
                FIELD_AT(v, short, 0x10 + j * 0x24) = 0;
            }
            v->unkA0 = 0;
            v->unkA2 = 0;
            v->unkA4 = 0;
            v->unkA6 = 0;
            t->unk28 = 0;
            mask |= 1 << t->unk04;
        } else {
            t->flags = 0;
        }
        n--;
        t++;
    } while (n != 0);
    FIELD_AT(drv, short, 0x24) = 0x8000;
    FIELD_AT(drv, int, 0x20) |= mask;
    func_8008BA68();
    return ti;
}

struct Track_8008F4B0 {
    short flags;
    char pad02[0xE];
    int id;
    unsigned int time;
    char pad18[0x148];
};
struct Drv_8008F4B0 {
    char pad0[0xC];
    Track_8008F4B0 *tracks;
    char pad10[0x1A];
    unsigned char ntrack;
};
EXTERN_C void func_8008FAB4(int id);
EXTERN_C void func_8008F4B0(Req_8008EF64 *r)
{
    Drv_8008F4B0 *drv = FIELD_AT(&D_800B18FC, Drv_8008F4B0 *, 0x154);
    unsigned char *q;
    int need;
    int i;
    int k;
    Track_8008F4B0 *t;
    Track_8008F4B0 *p;
    unsigned int min;

    func_8008FAB4(r->id);
    q = r->data;
    for (;;) {
        need = q[3];
        i = drv->ntrack - need;
        t = drv->tracks + i;
        while (i >= 0) {
            k = need;
            if (t->flags == 0) {
                p = t + 1;
                for (k--; k != 0; k--) {
                    if (p->flags != 0) {
                        break;
                    }
                    p++;
                }
                if (k == 0) {
                    r->unk18 = i;
                    return;
                }
            }
            i -= k;
            t -= k;
        }
        t = 0;
        min = -1;
        i = drv->ntrack;
        p = &drv->tracks[i - 1];
        while (i != 0) {
            if (p->flags != 0 && p->time < min) {
                min = p->time;
                t = p;
            }
            i--;
            p--;
        }
        if (t != 0) {
            func_8008FAB4(t->id);
        }
    }
}

struct Voice_8008F618 {
    char pad0[0x9];
    unsigned char unk9;
    unsigned char unkA;
    char padB;
    unsigned char unkC;
    unsigned char unkD;
    short unkE;
    char pad10[0x90];
    short unkA0;
    short unkA2;
    short unkA4;
    short unkA6;
    int unkA8;
    char padAC[4];
    Voice_8008F618 *next;
    short unkB4;
    unsigned char unkB6;
    char padB7;
    short unkB8;
    short unkBA;
    char padBC[0x28];
};
struct Track_8008F618 {
    short flags;
    short unk02;
    unsigned char unk04;
    unsigned char unk05;
    char pad06;
    unsigned char unk07;
    unsigned char nvoice;
    unsigned char voice0;
    unsigned char unk0A;
    char pad0B[3];
    unsigned char unk0E;
    char pad0F;
    int id;
    unsigned int time;
    int unk18;
    int unk1C;
    int unk20;
    Voice_8008F618 *voices;
    int unk28;
    Voice_8008F618 *head;
    char *song;
    int unk34;
    int unk38;
    short unk3C;
    unsigned char unk3E;
    char pad3F;
    int unk40;
    int unk44;
    int unk48;
    short unk4C;
    unsigned char unk4E;
    unsigned char unk4F;
    unsigned char unk50;
    unsigned char unk51;
    unsigned char unk52;
    unsigned char unk53;
    short unk54;
    char pad56[2];
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    char pad68[0xF4];
    int unk15C;
};
struct Drv_8008F618 {
    char pad0[0xC];
    Track_8008F618 *tracks;
    char pad10[0x10];
    int mask;
    unsigned short flags;
    char pad26[4];
    unsigned char ntrack;
};
EXTERN_C char *func_8008D5A8(unsigned short id);
EXTERN_C void func_8008D5E8(void *v, void *song, short idx);
EXTERN_C void func_8008FAB4(int id);
EXTERN_C void *func_8008F618(int id, Ent_8008F618 *e, int vol, int pan)
{
    char *song;
    Drv_8008F618 *drv;
    int last;
    int i;
    Track_8008F618 *t;
    Track_8008F618 *best;
    unsigned int min;
    Voice_8008F618 *v;
    SoundState *ss;
    int x;
    short d;
    int j;

    if (!(e->flags & 1)) {
        func_8009482C(0x12, id);
        return 0;
    }
    song = func_8008D5A8(e->song);
    if (song == 0) {
        return 0;
    }
    drv = FIELD_AT(&D_800B18FC, Drv_8008F618 *, 0x154);
    last = drv->ntrack - 1;
    if (!(e->flags & 4)) {
        for (i = last, t = &drv->tracks[i]; i >= 0; i--, t--) {
            if (t->flags < 0 && t->id == id) {
                func_8008FAB4(id);
                break;
            }
        }
    }
    for (i = last, t = &drv->tracks[i]; i >= 0; i--, t--) {
        if (t->flags >= 0) {
            break;
        }
    }
    if (i < 0) {
        t = 0;
        min = -1;
        i = drv->ntrack;
        best = &drv->tracks[i - 1];
        while (i != 0) {
            if (best->flags != 0 && best->time < min) {
                min = best->time;
                t = best;
            }
            i--;
            best--;
        }
        if (t->flags < 0) {
            func_8008FAB4(t->id);
        }
        for (i = last, t = &drv->tracks[i]; i >= 0; i--, t--) {
            if (t->flags >= 0) {
                break;
            }
        }
    }
    func_8008BAC4();
    ss = &D_800B18FC;
    x = FIELD_AT(ss, int, 0x144);
    t->unk0A = 0x30;
    t->id = id;
    t->unk02 = 0;
    t->unk05 = 2;
    t->unk18 = 0;
    t->unk1C = 0;
    t->unk20 = 0;
    t->unk38 = 0;
    t->unk3C = 0;
    t->unk3E = 0;
    t->song = song;
    t->unk34 = 0;
    t->time = x;
    t->unk40 = e->time;
    t->unk44 = 0;
    t->unk48 = 0;
    t->unk4C = e->song;
    t->unk4E = 0xFF;
    t->unk4F = e->unk1;
    t->unk50 = 0xF;
    t->unk51 = 0x3C;
    t->unk52 = 0x3C;
    t->unk53 = 0x3C;
    t->unk5C = (e->vol * vol / 127) << 24;
    t->unk58 = 0;
    t->unk64 = 0x1FC00000;
    t->unk60 = pan << 16;
    d = e->rnd;
    if ((e->flags & 2) && d != 0) {
        int r = FIELD_AT(ss, int, 0x254);
        r ^= r << 17;
        r ^= r >> 15;
        FIELD_AT(ss, int, 0x254) = r;
        d = (r & 0x7FFF) % (d * 2);
    }
    t->unk54 = d;
    v = t->voices;
    t->unk0E = 0xFF;
    t->unk15C = 0;
    t->unk28 = 0;
    t->head = v;
    FIELD_AT(v, int, 0) = e->time;
    v->unkA = 0x20;
    func_8008D5E8(v, song, e->unk1);
    v->unkBA = 0;
    if (e->flags & 8) {
        v->unkB6 = 0x40;
    } else {
        v->unkB6 = 0;
    }
    v->unkB8 = 0x200;
    v->unk9 = 0;
    v->unkA8 = 0;
    for (j = 3; j >= 0; j--) {
        FIELD_AT(v, short, 0x10 + j * 0x24) = 0;
    }
    v->unkA0 = 0;
    v->unkA2 = 0;
    v->unkA4 = 0;
    v->unkA6 = 0;
    t->flags = (short)0x8420;
    drv->mask |= 1 << t->unk04;
    drv->flags |= 0x8000;
    func_8008BA68();
    return t;
}

struct Track_8008FA34 {
    short flags;
    char pad02[0x1E];
    int unk20;
    char *voices;
    char pad28[0x138];
};
struct Drv_8008FA34 {
    char pad0[0xC];
    Track_8008FA34 *tracks;
    char pad10[0x10];
    int mask;
    char pad24[6];
    unsigned char ntrack;
};
EXTERN_C void func_8008FA34(void)
{
    Drv_8008FA34 *drv = FIELD_AT(&D_800B18FC, Drv_8008FA34 *, 0x154);
    Track_8008FA34 *t = drv->tracks;
    int n = drv->ntrack;

    func_8008BAC4();
    do {
        if (t->flags & 0x8000) {
            t->flags = 0;
            func_80093E80((Slot_80093D8C *)(t->voices + 0xB4));
        }
        t++;
    } while (--n);
    drv->mask = 0;
    func_8008BA68();
}

struct Track_8008FAB4 {
    short flags;
    char pad02[2];
    unsigned char unk04;
    char pad05[0xB];
    int id;
    char pad14[0x10];
    char *voices;
    char pad28[0x138];
};
struct Drv_8008FAB4 {
    char pad0[0xC];
    Track_8008FAB4 *tracks;
    char pad10[0x10];
    int mask;
    char pad24[6];
    unsigned char ntrack;
};
EXTERN_C void func_8008FAB4(int id)
{
    Drv_8008FAB4 *drv = FIELD_AT(&D_800B18FC, Drv_8008FAB4 *, 0x154);
    Track_8008FAB4 *t = drv->tracks;
    int n = drv->ntrack;

    func_8008BAC4();
    do {
        if ((t->flags & 0x8000) && t->id == id) {
            drv->mask &= ~(1 << t->unk04);
            func_80093E80((Slot_80093D8C *)(t->voices + 0xB4));
            t->flags = 0;
        }
        t++;
    } while (--n);
    func_8008BA68();
}

struct Track_8008FB80 {
    short flags;
    short unk02;
    char pad04[0xC];
    int id;
    char pad14[0x48];
    int vol;
    char pad60[0x20];
    int unk80;
    char pad84[0xA];
    short unk8E;
    char pad90[0xD0];
};
struct Drv_8008FB80 {
    char pad0[0xC];
    Track_8008FB80 *tracks;
    char pad10[0x1A];
    unsigned char ntrack;
};
EXTERN_C void func_8008FB80(int id, int dur)
{
    Drv_8008FB80 *drv = FIELD_AT(&D_800B18FC, Drv_8008FB80 *, 0x154);
    Track_8008FB80 *t = drv->tracks;
    int n = drv->ntrack;

    func_8008BAC4();
    do {
        if ((t->flags & 0x8000) && t->id == id) {
            t->unk8E = dur;
            t->unk80 = -(t->vol / dur);
            t->unk02 = 0x20;
        }
        t++;
    } while (--n);
    func_8008BA68();
}

struct Track_8008FC38 {
    short flags;
    char pad02[2];
    unsigned char unk04;
    char pad05[0xD];
    unsigned short id;
    char pad14[0x10];
    char *voices;
    char pad28[0x138];
};
struct Drv_8008FC38 {
    char pad0[0xC];
    Track_8008FC38 *tracks;
    char pad10[0x10];
    int mask;
    char pad24[6];
    unsigned char ntrack;
};
EXTERN_C void func_8008FC38(unsigned short id)
{
    Drv_8008FC38 *drv = FIELD_AT(&D_800B18FC, Drv_8008FC38 *, 0x154);
    Track_8008FC38 *t = drv->tracks;
    int n = drv->ntrack;

    func_8008BAC4();
    do {
        if ((t->flags & 0x8000) && t->id == id) {
            drv->mask &= ~(1 << t->unk04);
            func_80093E80((Slot_80093D8C *)(t->voices + 0xB4));
            t->flags = 0;
        }
        t++;
    } while (--n);
    func_8008BA68();
}

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

EXTERN_C void func_8008C9A8(void);
EXTERN_C void func_8008FEAC(void);
EXTERN_C void func_80093FE0(void);
EXTERN_C void func_8008FFF0(void);
EXTERN_C void func_8009422C(void);
EXTERN_C int func_8008FDE4(void)
{
    SoundState *s = &D_800B18FC;
    unsigned char v;

    v = s->unk25B;
    if (v != 0 && (D_800B18FC.flags & 2)) {
        s->unk25B = --v;
        if (v < 1 || v > 0x2F) {
            func_8009484C(0xE0, FIELD_AT(s, int, 0x168));
            func_8008C9A8();
        }
    }
    if (!(D_800B18FC.flags & 0x80)) {
        SoundState *t = &D_800B18FC;
        FIELD_AT(t, int, 0x144)++;
        FIELD_AT(t, int, 0x148)++;
        if (FIELD_AT(t, int, 0x144) & 1) {
            func_8008FEAC();
        }
        func_80093FE0();
        func_8008FFF0();
        func_8009422C();
    }
    return 0;
}

struct Fade_8008FEAC {
    int cur;
    int step;
    short count;
    short target;
};
EXTERN_C void SpuSetCommonAttr(void *attr);
EXTERN_C void func_8008FEAC(void)
{
    SoundState *s;
    SoundState *d;
    Fade_8008FEAC *f;
    int v;

    s = &D_800B18FC;
    if (FIELD_AT(s, short, 0x1AC) != 0) {
        f = &FIELD_AT(s, Fade_8008FEAC, 0x1A4);
        if (--f->count != 0) {
            f->cur += f->step;
        } else {
            f->cur = f->target << 16;
        }
        SoundState *d1 = &D_800B18FC;
        v = FIELD_AT(d1, short, 0x1A6);
        FIELD_AT(d1, short, 0x198) = v;
        func_8008D038(v, &FIELD_AT(d1, short, 0x174), 0);
        FIELD_AT(d1, int, 0x170) |= 3;
    }
    s = &D_800B18FC;
    if (FIELD_AT(s, short, 0x1B8) != 0) {
        f = &FIELD_AT(s, Fade_8008FEAC, 0x1B0);
        if (--f->count != 0) {
            f->cur += f->step;
        } else {
            f->cur = f->target << 16;
        }
        SoundState *d2 = &D_800B18FC;
        v = FIELD_AT(d2, short, 0x1B2);
        FIELD_AT(d2, short, 0x19A) = v;
        func_8008D038(v, &FIELD_AT(d2, short, 0x180), 0);
        FIELD_AT(d2, int, 0x170) |= 0xC0;
    }
    d = &D_800B18FC;
    if (FIELD_AT(d, int, 0x170) != 0) {
        SpuSetCommonAttr(&FIELD_AT(d, int, 0x170));
        FIELD_AT(d, int, 0x170) = 0;
    }
}

struct Fade_8008FFF0 {
    int cur;
    int step;
    short count;
    short target;
};
EXTERN_C void func_8009031C(void *s);
EXTERN_C void func_80090550(void *s);
EXTERN_C void func_80090AAC(void *drv);
EXTERN_C void func_80090CF4(void *s);
EXTERN_C void func_8008E210(void *a);
EXTERN_C void func_80094330(void *drv);
EXTERN_C void func_80091334(void *s);
EXTERN_C void func_8008FFF0(void)
{
    char *s;

    for (s = FIELD_AT(&D_800B18FC, char *, 0x150); s != 0; s = FIELD_AT(s, char *, 0x4)) {
        Fade_8008FFF0 *f;

        if (FIELD_AT(s, short, 0x24) >= 0) {
            continue;
        }
        FIELD_AT(s, int, 0xB8)++;
        if (FIELD_AT(s, short, 0x78) != 0) {
            f = &FIELD_AT(s, Fade_8008FFF0, 0x70);
            if (--f->count != 0) {
                f->cur += f->step;
            } else {
                f->cur = f->target << 16;
            }
            FIELD_AT(s, int, 0x44) = (FIELD_AT(s, short, 0x36) * 0xDA74 >> 16) * FIELD_AT(s, short, 0x72);
        }
        if (FIELD_AT(s, short, 0x90) != 0) {
            f = &FIELD_AT(s, Fade_8008FFF0, 0x88);
            if (--f->count != 0) {
                f->cur += f->step;
            } else {
                f->cur = f->target << 16;
            }
            func_80093A80(s, 4);
        }
        if (FIELD_AT(s, short, 0x84) != 0) {
            f = &FIELD_AT(s, Fade_8008FFF0, 0x7C);
            if (--f->count != 0) {
                f->cur += f->step;
            } else {
                f->cur = f->target << 16;
            }
            func_80093A80(s, 8);
        }
        if (FIELD_AT(s, short, 0x9C) != 0) {
            f = &FIELD_AT(s, Fade_8008FFF0, 0x94);
            if (--f->count != 0) {
                f->cur += f->step;
            } else {
                f->cur = f->target << 16;
            }
            func_80093A80(s, 4);
        }
        FIELD_AT(s, int, 0x48)++;
        FIELD_AT(s, int, 0x50) += FIELD_AT(s, short, 0x72);
        FIELD_AT(s, int, 0x40) -= FIELD_AT(s, int, 0x44);
        while (FIELD_AT(s, int, 0x40) < 0) {
            FIELD_AT(s, int, 0x40) += 0x10000;
            FIELD_AT(s, int, 0xBC)++;
            if (++FIELD_AT(s, unsigned short, 0x5E) == FIELD_AT(s, unsigned short, 0x62)) {
                FIELD_AT(s, unsigned short, 0x5E) = 0;
                if (++FIELD_AT(s, unsigned short, 0x5C) >= FIELD_AT(s, unsigned short, 0x60)) {
                    FIELD_AT(s, unsigned short, 0x5C) = 0;
                    FIELD_AT(s, unsigned short, 0x5A)++;
                }
            }
            if (FIELD_AT(s, unsigned char, 0x31) == 0) {
                func_8009031C(s);
                func_80090550(s);
            } else {
                func_80090AAC(s);
                func_80090CF4(s);
            }
            if (FIELD_AT(s, int, 0x20) == 0) {
                FIELD_AT(s, unsigned short, 0x24) &= 0x7FFF;
                break;
            }
            FIELD_AT(s, int, 0x4C)++;
            if (FIELD_AT(s, int, 0x88) == 0) {
                FIELD_AT(s, unsigned short, 0x24) = (FIELD_AT(s, unsigned short, 0x24) | 0x100) & 0x7FFF;
                func_8008E210(s);
            }
        }
        func_80094330(s);
        func_80091334(s);
    }
}

struct Voice_8009031C {
    int time;
    char pad4[6];
    unsigned char unkA;
    unsigned char upd;
    char padC[0xA0];
    Voice_8009031C *next;
    Voice_8009031C *free;
};
struct Track_8009031C {
    short flags;
    unsigned short flags2;
    char pad04[4];
    unsigned char nvoice;
    char pad09[0x1F];
    Voice_8009031C *active;
    Voice_8009031C *head;
    char pad30[0x28];
    int unk58;
    char pad5C[4];
    int unk60;
    int unk64;
    char pad68[0xC];
    int unk74;
    int unk78;
    int unk7C;
    char pad80[4];
    signed char unk84;
    unsigned char unk85;
    unsigned char unk86;
    char pad87;
    unsigned short unk88;
    unsigned short unk8A;
    unsigned short unk8C;
    char pad8E[0xD2];
};
EXTERN_C void func_8009031C(void *s)
{
    int n = FIELD_AT(s, unsigned char, 0x2A);
    Track_8009031C *t = FIELD_AT(s, Track_8009031C *, 0xC);
    unsigned short f;
    unsigned short upd;
    Voice_8009031C *v;
    Voice_8009031C *prev;
    Voice_8009031C *p;
    int time;

    while (n--) {
        if (t->flags < 0) {
            f = t->flags2;
            upd = 0;
            if (f & 8) {
                if (--t->unk8A == 0) {
                    f &= ~8;
                    t->unk64 = t->unk85 << 22;
                } else {
                    t->unk64 += t->unk78;
                }
                upd |= 4;
            }
            if (f & 1) {
                if (!(f & 2)) {
                    if (--t->unk88 == 0) {
                        f &= ~1;
                        t->unk58 = t->unk84 << 24;
                    } else {
                        t->unk58 += t->unk74;
                    }
                }
                upd |= 8;
            }
            if (f & 0x10) {
                if (--t->unk8C == 0) {
                    f &= ~0x10;
                    t->unk60 = t->unk86 << 16;
                } else {
                    t->unk60 += t->unk7C;
                }
                upd |= 4;
            }
            t->flags2 = f;
            prev = 0;
            for (v = t->active; v != 0; v = v->next) {
                time = v->time - 1;
                if (time == 0) {
                    if (!(v->unkA & 0x100)) { /* always true; reproduces retail's dead "li v0,0; bnez v0" */
                        if (t->nvoice == 1) {
                            t->active = 0;
                            t->head = v;
                        } else {
                            if (prev != 0) {
                                prev->next = v->next;
                            } else {
                                t->active = v->next;
                            }
                            v->unkA &= 0x7F;
                            p = t->head;
                            if (p != 0) {
                                while (p->free != 0) {
                                    p = p->free;
                                }
                                p->free = v;
                            } else {
                                t->head = v;
                            }
                        }
                        v->free = 0;
                        upd |= 2;
                    }
                } else {
                    prev = v;
                }
                v->time = time;
                v->upd |= upd;
            }
        }
        t++;
    }
}

struct Note_80090550 {
    char pad0[2];
    unsigned char cmd;
    unsigned char key;
    int dur;
};
typedef unsigned char *(*SeqCmd_80090550)(void *drv, SeqTrack *t, unsigned char *p);
/* The command table starts at 0x800AFABC, 6 words into splat's D_800AFAA4 blob. */
EXTERN_C SeqCmd_80090550 D_800AFAA4[];
EXTERN_C void func_80090724(void *drv, SeqTrack *t, unsigned char *ev);
EXTERN_C void func_80090550(void *drv)
{
    int n = FIELD_AT(drv, unsigned char, 0x2A);
    SeqTrack *t = FIELD_AT(drv, SeqTrack *, 0xC);
    unsigned char *p;
    unsigned char c;
    unsigned char x;
    int len;
    int v;
    Note_80090550 ev;

    while (n--) {
        if ((short)t->flags < 0) {
            p = FIELD_AT(t, unsigned char *, 0x1C);
            if (p != 0) {
                while (t->unk40 == 0) {
                    c = *p++;
                    if (c >= 0x80) {
                        p = D_800AFAA4[c - 0x80 + 6](drv, t, p);
                    } else {
                        ev.cmd = c;
                        x = *p++;
                        len = x >> 6;
                        t->octave += (((x >> 4) & 3) - 1) * 12;
                        ev.key = t->octave + (x & 0xF);
                        if (len != 0) {
                            v = 0;
                            while (len--) {
                                v <<= 8;
                                v += *p++;
                            }
                            t->unk48 = v;
                        } else {
                            v = t->unk48;
                        }
                        ev.dur = v;
                        func_80090724(drv, t, (unsigned char *)&ev);
                    }
                    if ((short)t->flags >= 0) {
                        FIELD_AT(drv, int, 0x20) &= ~(1 << FIELD_AT(t, unsigned char, 0x4));
                        t->flags |= 0x4000;
                        break;
                    }
                }
            }
            t->unk40--;
            FIELD_AT(t, unsigned char *, 0x1C) = p;
        }
        t = (SeqTrack *)((char *)t + 0x160);
    }
}

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

EXTERN_C void func_80090AAC(void *drv)
{
    int i = FIELD_AT(drv, unsigned char, 0x2A);
    char *t = FIELD_AT(drv, char *, 0xC);
    unsigned short f;
    unsigned short bits;
    char *v;
    int c;

    while (i != 0) {
        i--;
        if (FIELD_AT(t, short, 0x0) < 0) {
            f = FIELD_AT(t, unsigned short, 0x2);
            bits = 0;
            if (f & 8) {
                if (--FIELD_AT(t, unsigned short, 0x8A) == 0) {
                    f &= ~8;
                    FIELD_AT(t, int, 0x64) = FIELD_AT(t, unsigned char, 0x85) << 22;
                } else {
                    FIELD_AT(t, int, 0x64) += FIELD_AT(t, int, 0x78);
                }
                bits |= 4;
            }
            if (f & 1) {
                if (!(f & 2)) {
                    if (--FIELD_AT(t, unsigned short, 0x88) == 0) {
                        f &= ~1;
                    } else {
                        FIELD_AT(t, int, 0x58) += FIELD_AT(t, int, 0x74);
                    }
                }
                bits |= 8;
            }
            if (f & 0x10) {
                if (--FIELD_AT(t, unsigned short, 0x8C) == 0) {
                    f &= ~0x10;
                    FIELD_AT(t, int, 0x60) = FIELD_AT(t, unsigned char, 0x86) << 16;
                } else {
                    FIELD_AT(t, int, 0x60) += FIELD_AT(t, int, 0x7C);
                }
                bits |= 4;
            }
            if (f & 0x20) {
                v = FIELD_AT(t, char *, 0x24);
                bits |= 4;
                if (--FIELD_AT(t, unsigned short, 0x8E) == 0) {
                    func_80093E80((Slot_80093D8C *)(v + 0xB4));
                    FIELD_AT(t, short, 0x0) = 0;
                    FIELD_AT(drv, int, 0x20) &= ~(1 << FIELD_AT(t, unsigned char, 0x4));
                    t += 0x160;
                    continue;
                }
                FIELD_AT(t, int, 0x5C) += FIELD_AT(t, int, 0x80);
                FIELD_AT(v, short, 0x6) = (FIELD_AT(t, int, 0x5C) >> 24) * FIELD_AT(v, unsigned char, 0xD);
            }
            FIELD_AT(t, unsigned short, 0x2) = f;
            v = FIELD_AT(t, char *, 0x28);
            if (v != 0) {
                c = FIELD_AT(v, int, 0x0) - 1;
                if (c == 0 && !(FIELD_AT(v, unsigned char, 0xA) & 2)) {
                    FIELD_AT(t, char *, 0x28) = 0;
                    FIELD_AT(t, char *, 0x2C) = v;
                    FIELD_AT(t, unsigned short, 0x0) |= 0x400;
                    bits |= 2;
                }
                FIELD_AT(v, int, 0x0) = c;
                FIELD_AT(v, unsigned char, 0xB) |= bits;
            }
        }
        t += 0x160;
    }
}

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

EXTERN_C int func_800942E0(unsigned int a);
EXTERN_C void func_80093F98(Slot_80093D8C *s);

EXTERN_C void func_80091334(void *drv)
{
    char *t;
    int i;
    int n;
    char *v;
    int f;
    int vol;
    int pan;
    int l;
    int r;
    int p;
    int c;

    if (FIELD_AT(drv, unsigned short, 0x24) & 0x20) {
        return;
    }
    t = FIELD_AT(drv, char *, 0xC);
    i = FIELD_AT(drv, unsigned char, 0x2A);
    do {
        if (FIELD_AT(t, short, 0x0) & 0xC000) {
            if (FIELD_AT(t, unsigned short, 0x0) & 0x4000) {
                FIELD_AT(t, short, 0x0) = 0;
            }
            n = FIELD_AT(t, unsigned char, 0x8);
            v = FIELD_AT(t, char *, 0x24);
            while (n--) {
                f = FIELD_AT(v, unsigned char, 0xB);
                if (f & 4) {
                    vol = (FIELD_AT(t, int, 0x64) >> 14) * FIELD_AT(v, unsigned short, 0x6) >> 14;
                    vol -= vol * FIELD_AT(v, short, 0xA2) >> 15;
                    if (vol > 0x7FFF) {
                        vol = 0x7FFF;
                    }
                    if (vol < -0x7FFF) {
                        vol = -0x7FFF;
                    }
                    vol = FIELD_AT(drv, short, 0x8A) * FIELD_AT(t, short, 0x70) / 127 * vol >> 16;
                    pan = FIELD_AT(v, short, 0xA4) + ((FIELD_AT(t, int, 0x60) + FIELD_AT(drv, int, 0x94)) >> 8);
                    c = pan - 0x4000;
                    pan = c + (FIELD_AT(t, short, 0x72) << 8);
                    if (pan > 0x7F00) {
                        pan = 0x7F00;
                    }
                    if (pan < 0) {
                        pan = 0;
                    }
                    if (D_800B1A9F.v != 0) {
                        if (pan < 0x4000) {
                            r = pan * 23040 >> 14;
                            l = 0x7F00 - (pan * 9472 >> 14);
                        } else {
                            pan = 0x7F00 - pan;
                            l = pan * 23040 >> 14;
                            r = 0x7F00 - (pan * 9472 >> 14);
                        }
                        l = l * vol >> 15;
                        r = r * vol >> 15;
                    } else {
                        l = r = vol * 23040 >> 15;
                    }
                    FIELD_AT(v, short, 0xBC) = l;
                    FIELD_AT(v, short, 0xBE) = r;
                    FIELD_AT(v, unsigned short, 0xBA) |= 1;
                }
                if (f & 8) {
                    p = FIELD_AT(v, unsigned short, 0x4) + FIELD_AT(t, short, 0x54) + FIELD_AT(v, short, 0xA0) +
                          ((FIELD_AT(t, int, 0x58) + FIELD_AT(drv, int, 0x7C)) >> 16);
                    FIELD_AT(v, short, 0xC8) = func_800942E0((short)p) & 0x3FFF;
                    FIELD_AT(v, unsigned short, 0xBA) |= 4;
                }
                if (f & 1) {
                    if (!(FIELD_AT(t, unsigned short, 0x0) & 2)) {
                        func_80093DE8(v + 0xB4);
                        FIELD_AT(v, unsigned char, 0xA) |= 0x11;
                    }
                }
                if (f & 2) {
                    if (!(FIELD_AT(t, unsigned short, 0x0) & 0x802)) {
                        func_80093F98((Slot_80093D8C *)(v + 0xB4));
                        FIELD_AT(v, unsigned char, 0xA) &= ~0x10;
                    }
                }
                FIELD_AT(v, unsigned char, 0xB) = 0;
                v += 0xE4;
            }
        }
        t += 0x160;
    } while (--i);
}

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

EXTERN_C unsigned char *func_80091800(void *drv, SeqTrack *t, unsigned char *p)
{
    t->unk44 = 0;
    t->unk48 = 0;
    if (t->mark != 0) {
        p = t->mark;
        FIELD_AT(t, unsigned short, 0x3C)++;
        t->octave = t->unk3F;
    } else {
        func_8008E1B4(t);
        p--;
        t->flags &= 0x7FFF;
    }
    return p;
}

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

EXTERN_C unsigned char *func_80091AB4(void *t, void *drv, unsigned char *p)
{
    int n = p[0];
    int v = p[1];

    FIELD_AT(t, short, 0x3E) = v << 8;
    if (n == 0) {
        FIELD_AT(t, short, 0x3C) = 0;
        FIELD_AT(t, int, 0x34) = v << 16;
        FIELD_AT(t, int, 0x44) = (v * 13981 >> 14) * FIELD_AT(t, short, 0x72);
    } else {
        int d = (v << 16) - FIELD_AT(t, int, 0x34);
        if (d != 0) {
            FIELD_AT(t, short, 0x3C) = n;
            FIELD_AT(t, int, 0x38) = d / n;
        }
    }
    return p + 2;
}

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

EXTERN_C char *func_8008D5A8(unsigned short id);
EXTERN_C void func_8008D5E8(void *v, void *song, short idx);

EXTERN_C unsigned char *func_80091BC8(void *drv, SeqTrack *t, unsigned char *p)
{
    int prog = *p++;
    char *song;
    int n;
    char *v;

    FIELD_AT(t, unsigned char, 0x4F) = prog;
    song = func_8008D5A8(t->unk4C);
    if (song != 0) {
        FIELD_AT(t, char *, 0x30) = song;
    }
    n = FIELD_AT(t, unsigned char, 0x8);
    v = FIELD_AT(t, char *, 0x24);
    while (n--) {
        func_8008D5E8(v, FIELD_AT(t, char *, 0x30), prog);
        FIELD_AT(v, unsigned char, 0x9) = 12;
        v += 0xE4;
    }
    FIELD_AT(t, int, 0x34) = 0;
    FIELD_AT(t, unsigned char, 0x4E) = 0xFF;
    return p;
}

EXTERN_C char *func_8008D5A8(unsigned short id);
EXTERN_C void func_8008D5E8(void *v, void *song, short idx);

EXTERN_C unsigned char *func_80091C94(void *drv, SeqTrack *t, unsigned char *p)
{
    int id = p[1] + (p[2] << 8);
    int prog = p[0];
    char *song;
    int n;
    char *v;

    FIELD_AT(t, unsigned char, 0x4F) = prog;
    t->unk4C = id;
    song = func_8008D5A8(id);
    if (song != 0) {
        FIELD_AT(t, char *, 0x30) = song;
    } else {
        song = FIELD_AT(t, char *, 0x30);
    }
    n = FIELD_AT(t, unsigned char, 0x8);
    v = FIELD_AT(t, char *, 0x24);
    while (n != 0) {
        n--;
        func_8008D5E8(v, song, prog);
        FIELD_AT(v, unsigned char, 0x9) = 12;
        v += 0xE4;
    }
    FIELD_AT(t, int, 0x34) = 0;
    FIELD_AT(t, unsigned char, 0x4E) = 0xFF;
    return p + 3;
}

EXTERN_C unsigned char *func_80091D70(void *drv, SeqTrack *t, unsigned char *p)
{
    int prog = -1;
    char *song;
    unsigned char *e;
    int cnt;
    int n;
    Voice_80091FB4 *v;
    unsigned short a;
    unsigned int b;

    if (!(t->flags & 1)) {
        song = func_8008D5A8(FIELD_AT(drv, unsigned short, 0x28));
        if (song != 0) {
            FIELD_AT(t, char *, 0x30) = song;
            e = FIELD_AT(song, unsigned char *, 0x18);
            if (e != 0) {
                prog = *p;
            }
        }
        if (prog >= 0) {
            cnt = FIELD_AT(song, unsigned short, 0x8);
            while (cnt--) {
                if (*e == prog) {
                    n = FIELD_AT(t, unsigned char, 0x8);
                    v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
                    a = FIELD_AT(e, unsigned short, 0x2);
                    b = FIELD_AT(e, unsigned int, 0x4);
                    while (n--) {
                        v->unkD8 = a & 7;
                        v->unkD9 = (a >> 4) & 7;
                        v->unkDA = (a >> 8) & 7;
                        v->unkDB = b & 0x7F;
                        v->unkDC = (b >> 8) & 0xF;
                        v->unkDD = (b >> 16) & 0x7F;
                        v->unkDE = v->unk8 = (b >> 24) & 0x1F;
                        v->unkDF = (b >> 12) & 0xF;
                        v++;
                    }
                    break;
                }
                e += 0x88;
            }
            FIELD_AT(t, unsigned char *, 0x34) = e;
        }
    }
    FIELD_AT(t, unsigned char, 0x4E) = prog;
    return p + 1;
}

EXTERN_C unsigned char *func_80091ED0(void *drv, void *t, unsigned char *p)
{
    unsigned short a;
    unsigned int b;
    int n;
    Voice_80091FB4 *v;

    if (FIELD_AT(t, signed char, 0x4E) >= 0) {
        char *e = FIELD_AT(t, char *, 0x34);
        a = FIELD_AT(e, unsigned short, 0x2);
        b = FIELD_AT(e, unsigned int, 0x4);
    } else {
        char *e = FIELD_AT(FIELD_AT(t, char *, 0x30), char *, 0x14) + FIELD_AT(t, unsigned char, 0x4F) * 16;
        a = FIELD_AT(e, unsigned short, 0xC);
        b = FIELD_AT(e, unsigned int, 0x8);
    }
    n = FIELD_AT(t, unsigned char, 0x8);
    v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    while (n--) {
        v->unkD8 = a & 7;
        v->unkD9 = (a >> 4) & 7;
        v->unkDA = (a >> 8) & 7;
        v->unkDB = b & 0x7F;
        v->unkDC = (b >> 8) & 0xF;
        v->unkDD = (b >> 16) & 0x7F;
        v->unkDE = v->unk8 = (b >> 24) & 0x1F;
        v->unkDF = (b >> 12) & 0xF;
        v->flags |= 0x1F0;
        v++;
    }
    return p;
}

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

EXTERN_C void func_80093A40(void *t, int bits);

EXTERN_C unsigned char *func_800926B8(void *drv, SeqTrack *t, unsigned char *p)
{
    unsigned short dur = p[0] + (p[1] << 8);
    int target = p[2];
    int d = (target << 24) - FIELD_AT(t, int, 0x58);

    if (dur != 0 && d != 0) {
        int q = d / dur;
        FIELD_AT(t, unsigned char, 0x84) = target;
        FIELD_AT(t, short, 0x88) = dur;
        FIELD_AT(t, unsigned short, 0x2) |= 1;
        FIELD_AT(t, int, 0x74) = q;
        func_80093A40(t, 8);
    } else {
        FIELD_AT(t, unsigned short, 0x2) &= ~1;
    }
    return p + 3;
}

EXTERN_C unsigned char *func_80092754(void *drv, void *t, unsigned char *p)
{
    unsigned char c;
    int r;
    int n;
    Voice_80091FB4 *v;

    if ((c = *p++ + 1) != 0) {
        r = 0x400 / (c << 2);
    } else {
        r = 0;
    }
    n = FIELD_AT(t, unsigned char, 0x8);
    v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    while (n--) {
        v->unk2E = r;
        v->unk2C = r;
        v++;
    }
    return p;
}

struct Lfo_80094500;
EXTERN_C int func_800945FC(Lfo_80094500 *l);
EXTERN_C int func_800938B4(int a, short b, short c);
EXTERN_C void func_80093800(void *drv, Node_80093800 *n);

struct Voice_800927C8 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_800927C8(void *drv, void *t, unsigned char *p)
{
    int depth = (signed char)p[1];
    int b = p[0];

    if (depth != 0 && b != 0) {
        int n;
        short c;
        Voice_800927C8 *v;
        Node_80093800 *nd;

        if (depth < 0) {
            depth *= -depth;
        } else {
            depth *= depth;
        }
        b += b * b / 64;
        c = p[2] << 2;
        n = FIELD_AT(t, unsigned char, 0x8);
        v = FIELD_AT(t, Voice_800927C8 *, 0x24);
        depth <<= 14;
        while (n--) {
            nd = &v->nodes[0];
            FIELD_AT(nd, int, 0x10) = func_800938B4(depth, b, 3);
            nd->unk1E = 0x400;
            FIELD_AT(nd, short, 0x16) = b;
            nd->unk1A = c;
            FIELD_AT(nd, void *, 0x4) = (void *)func_800945FC;
            FIELD_AT(nd, unsigned char, 0x2) = 3;
            FIELD_AT(nd, unsigned char, 0x3) = 0;
            nd->flags |= 0x10;
            func_80093800(v, nd);
            v++;
        }
    }
    return p + 3;
}

struct Fn_800AFCBC {
    void *v[8];
};
EXTERN_C Fn_800AFCBC D_800AFCBC;
EXTERN_C int func_800938B4(int a, short b, short c);
EXTERN_C void func_80093800(void *drv, Node_80093800 *n);

struct Voice_80092910 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_80092910(void *drv, void *t, unsigned char *p)
{
    short b = p[0];
    unsigned char ty = p[2];
    int depth = (signed char)p[1];
    int n;
    unsigned char fl;
    Voice_80092910 *v;
    Node_80093800 *nd;

    if (ty >= 8) {
        func_8009484C(0xC1, (int)p);
        return p + 3;
    }
    if (depth != 0 && b != 0) {
        if (depth < 0) {
            depth *= -depth;
        } else {
            depth *= depth;
        }
        b += b * b / 64;
        depth <<= 14;
        fl = !(ty & 0x10) << 4;
        ty &= 0xF;
        n = FIELD_AT(t, unsigned char, 0x8);
        v = FIELD_AT(t, Voice_80092910 *, 0x24);
        while (n--) {
            nd = &v->nodes[0];
            FIELD_AT(nd, int, 0x10) = func_800938B4(depth, b, ty);
            FIELD_AT(nd, short, 0x16) = b;
            nd->unk1A = 0;
            nd->unk1E = 0x400;
            FIELD_AT(nd, void *, 0x4) = D_800AFCBC.v[ty];
            FIELD_AT(nd, unsigned char, 0x2) = ty;
            FIELD_AT(nd, unsigned char, 0x3) = 0;
            nd->flags = fl | (nd->flags & 1);
            func_80093800(v, nd);
            v++;
        }
    }
    return p + 3;
}

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

EXTERN_C unsigned char *func_80092C54(void *drv, void *t, unsigned char *p)
{
    unsigned char c;
    int r;
    int n;
    Voice_80091FB4 *v;

    if ((c = *p++ + 1) != 0) {
        r = 0x400 / (c << 2);
    } else {
        r = 0;
    }
    n = FIELD_AT(t, unsigned char, 0x8);
    v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    while (n--) {
        v->unk52 = r;
        v->unk50 = r;
        v++;
    }
    return p;
}

struct Lfo_80094500;
EXTERN_C int func_8009459C(Lfo_80094500 *l);
EXTERN_C int func_800938B4(int a, short b, short c);
EXTERN_C void func_80093800(void *drv, Node_80093800 *n);

struct Voice_80092CC8 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_80092CC8(void *drv, void *t, unsigned char *p)
{
    int depth = (signed char)p[1];
    int b = p[0];

    if (depth != 0 && b != 0) {
        int n;
        short c;
        Voice_80092CC8 *v;
        Node_80093800 *nd;

        depth <<= 24;
        b += b * b / 64;
        c = p[2] << 2;
        n = FIELD_AT(t, unsigned char, 0x8);
        v = FIELD_AT(t, Voice_80092CC8 *, 0x24);
        while (n--) {
            nd = &v->nodes[1];
            FIELD_AT(nd, int, 0x10) = func_800938B4(depth, b, 2);
            nd->unk1E = 0x400;
            FIELD_AT(nd, unsigned char, 0x2) = 2;
            FIELD_AT(nd, short, 0x16) = b;
            nd->unk1A = c;
            FIELD_AT(nd, void *, 0x4) = (void *)func_8009459C;
            FIELD_AT(nd, unsigned char, 0x3) = 1;
            func_80093800(v, nd);
            nd->flags |= 0x10;
            v++;
        }
    }
    return p + 3;
}

EXTERN_C Fn_800AFCBC D_800AFCBC;
EXTERN_C int func_800938B4(int a, short b, short c);
EXTERN_C void func_80093800(void *drv, Node_80093800 *n);

struct Voice_80092DE8 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_80092DE8(void *drv, void *t, unsigned char *p)
{
    short b = p[0];
    unsigned char ty = p[2];
    int depth = (signed char)p[1];
    int n;
    unsigned char fl;
    Voice_80092DE8 *v;
    Node_80093800 *nd;

    if (ty >= 8) {
        func_8009484C(0xC1, (int)p);
        return p + 3;
    }
    if (depth != 0 && b != 0) {
        depth <<= 24;
        b += b * b / 64;
        fl = !(ty & 0x10) << 4;
        ty &= 0xF;
        n = FIELD_AT(t, unsigned char, 0x8);
        v = FIELD_AT(t, Voice_80092DE8 *, 0x24);
        while (n--) {
            nd = &v->nodes[1];
            FIELD_AT(nd, int, 0x10) = func_800938B4(depth, b, ty);
            FIELD_AT(nd, short, 0x16) = b;
            nd->unk1A = 0;
            nd->unk1E = 0x400;
            FIELD_AT(nd, void *, 0x4) = D_800AFCBC.v[ty];
            FIELD_AT(nd, unsigned char, 0x2) = ty;
            FIELD_AT(nd, unsigned char, 0x3) = 1;
            nd->flags = fl | (nd->flags & 1);
            func_80093800(v, nd);
            v++;
        }
    }
    return p + 3;
}

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

EXTERN_C void func_80093A40(void *t, int bits);

EXTERN_C unsigned char *func_80093018(void *drv, SeqTrack *t, unsigned char *p)
{
    FIELD_AT(t, int, 0x60) = ((FIELD_AT(t, int, 0x60) + (signed char)*p) << 16) & 0x7FFFFF;
    func_80093A40(t, 4);
    FIELD_AT(t, unsigned short, 0x2) &= ~0x10;
    return p + 1;
}

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

EXTERN_C unsigned char *func_800930E0(void *drv, void *t, unsigned char *p)
{
    unsigned char c;
    int r;
    int n;
    Voice_80091FB4 *v;

    if ((c = *p++ + 1) != 0) {
        r = 0x400 / (c << 2);
    } else {
        r = 0;
    }
    n = FIELD_AT(t, unsigned char, 0x8);
    v = FIELD_AT(t, Voice_80091FB4 *, 0x24);
    while (n--) {
        v->unk76 = r;
        v->unk74 = r;
        v++;
    }
    return p;
}

struct Lfo_80094500;
EXTERN_C int func_800945FC(Lfo_80094500 *l);
EXTERN_C int func_800938B4(int a, short b, short c);
EXTERN_C void func_80093800(void *drv, Node_80093800 *n);

struct Voice_80093154 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_80093154(void *drv, void *t, unsigned char *p)
{
    int depth = (signed char)p[1];
    int b = p[0];

    if (depth != 0 && b != 0) {
        int n;
        short c;
        Voice_80093154 *v;
        Node_80093800 *nd;

        depth <<= 24;
        b += b * b / 64;
        c = p[2] << 2;
        n = FIELD_AT(t, unsigned char, 0x8);
        v = FIELD_AT(t, Voice_80093154 *, 0x24);
        while (n--) {
            nd = &v->nodes[2];
            FIELD_AT(nd, int, 0x10) = func_800938B4(depth, b, 3);
            FIELD_AT(nd, short, 0x16) = b;
            nd->unk1A = c;
            nd->unk1E = 0x400;
            FIELD_AT(nd, void *, 0x4) = (void *)func_800945FC;
            FIELD_AT(nd, unsigned char, 0x2) = 2;
            FIELD_AT(nd, unsigned char, 0x3) = 2;
            func_80093800(v, nd);
            nd->flags |= 0x10;
            v++;
        }
    }
    return p + 3;
}

EXTERN_C Fn_800AFCBC D_800AFCBC;
EXTERN_C int func_800938B4(int a, short b, short c);
EXTERN_C void func_80093800(void *drv, Node_80093800 *n);

struct Voice_8009327C {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_8009327C(void *drv, void *t, unsigned char *p)
{
    short b = p[0];
    unsigned char ty = p[2];
    int depth = (signed char)p[1];
    int n;
    unsigned char fl;
    Voice_8009327C *v;
    Node_80093800 *nd;

    if (ty >= 8) {
        func_8009484C(0xC1, (int)p);
        return p + 3;
    }
    if (depth != 0 && b != 0) {
        depth <<= 24;
        b += b * b / 64;
        fl = !(ty & 0x10) << 4;
        ty &= 0xF;
        n = FIELD_AT(t, unsigned char, 0x8);
        v = FIELD_AT(t, Voice_8009327C *, 0x24);
        while (n--) {
            nd = &v->nodes[2];
            FIELD_AT(nd, int, 0x10) = func_800938B4(depth, b, ty);
            FIELD_AT(nd, short, 0x16) = b;
            nd->unk1A = 0;
            nd->unk1E = 0x400;
            FIELD_AT(nd, void *, 0x4) = D_800AFCBC.v[ty];
            FIELD_AT(nd, unsigned char, 0x2) = ty;
            FIELD_AT(nd, unsigned char, 0x3) = 2;
            nd->flags = fl | (nd->flags & 1);
            func_80093800(v, nd);
            v++;
        }
    }
    return p + 3;
}

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

EXTERN_C Fn_800AFCBC D_800AFCBC;

struct Voice_80093450 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_80093450(void *drv, void *t, unsigned char *p)
{
    unsigned char k = p[0];
    unsigned char type = p[1] & 0xF;
    unsigned char fl = !(p[1] & 0x10) << 4;
    int w = p[2];
    int n;
    Voice_80093450 *v;
    Node_80093800 *nd;

    if (type >= 8) {
        func_8009484C(0xC1, (int)p);
        return p + 3;
    }
    FIELD_AT(t, unsigned char, 0xF) = k;
    n = FIELD_AT(t, unsigned char, 0x8);
    v = FIELD_AT(t, Voice_80093450 *, 0x24);
    while (n--) {
        nd = &v->nodes[k];
        FIELD_AT(nd, unsigned char, 0x2) = type;
        FIELD_AT(nd, void *, 0x4) = D_800AFCBC.v[type];
        nd->flags = fl;
        FIELD_AT(nd, unsigned char, 0x3) = w;
        nd->unk1A = 0;
        nd->unk1E = 0x400;
        v++;
    }
    return p + 3;
}

EXTERN_C int func_800938B4(int a, short b, short c);

struct Voice_80093524 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_80093524(void *drv, void *t, unsigned char *p)
{
    short b = p[0] * p[0] / 64 + p[0];
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80093524 *v = FIELD_AT(t, Voice_80093524 *, 0x24);
    unsigned char k = FIELD_AT(t, unsigned char, 0xF);
    int depth = (p[1] << 24) + (p[2] << 16);
    Node_80093800 *nd;

    while (n--) {
        nd = &v->nodes[k];
        FIELD_AT(nd, short, 0x16) = b;
        FIELD_AT(nd, int, 0x10) = func_800938B4(depth, b, FIELD_AT(nd, unsigned char, 0x2));
        v++;
    }
    return p + 3;
}

struct Voice_80093610 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C unsigned char *func_80093610(void *drv, void *t, unsigned char *p)
{
    int a = p[0] << 2;
    unsigned char c;
    int r;
    int n;
    int k;
    Voice_80093610 *v;
    Node_80093800 *nd;

    if ((c = p[1] + 1) != 0) {
        r = 0x400 / (c << 2);
    } else {
        r = 0;
    }
    n = FIELD_AT(t, unsigned char, 0x8);
    v = FIELD_AT(t, Voice_80093610 *, 0x24);
    k = FIELD_AT(t, unsigned char, 0xF);
    while (n--) {
        nd = &v->nodes[k];
        nd->unk1A = a;
        nd->unk1E = r;
        nd->unk1C = r;
        v++;
    }
    return p + 2;
}

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

EXTERN_C void func_80093800(void *drv, Node_80093800 *n);

struct Voice_80093710 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C void func_80093710(void *t, int i)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80093710 *v = FIELD_AT(t, Voice_80093710 *, 0x24);

    while (n--) {
        func_80093800(v, &v->nodes[i]);
        v++;
    }
}

EXTERN_C void func_80093858(void *drv, Node_80093800 *n);

struct Voice_80093788 {
    char pad0[0x10];
    Node_80093800 nodes[4];
    char padA0[0x44];
};

EXTERN_C void func_80093788(void *t, int i)
{
    int n = FIELD_AT(t, unsigned char, 0x8);
    Voice_80093788 *v = FIELD_AT(t, Voice_80093788 *, 0x24);

    while (n--) {
        func_80093858(v, &v->nodes[i]);
        v++;
    }
}

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

EXTERN_C int func_800938B4(int a, short b, short c)
{
    if (a != 0 && b != 0) {
        switch (c) {
        case 2:
        case 3:
            a = a / b;
            break;
        case 4:
            if (b != 1) {
                a = a / (b - 1);
            }
            break;
        }
    }
    return a;
}

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

EXTERN_C void func_80093B3C(void *n)
{
    SoundState *s;
    char *p;

    func_8008BAC4();
    s = &D_800B18FC;
    p = FIELD_AT(s, char *, 0x238);
    if (p != 0) {
        while (FIELD_AT(p, char *, 0x2C) != 0) {
            p = FIELD_AT(p, char *, 0x2C);
        }
        FIELD_AT(p, void *, 0x2C) = n;
    } else {
        FIELD_AT(s, void *, 0x238) = n;
    }
    FIELD_AT(n, void *, 0x2C) = 0;
    func_8008BA68();
}

EXTERN_C void func_80093BB8(void *n)
{
    int i;
    void **slot;

    func_8008BAC4();
    i = FIELD_AT(n, short, 0x0);
    slot = &(&FIELD_AT(&D_800B18FC, void *, 0x1CC))[i];
    if ((unsigned int)i < 0x18) {
        if (*slot == n) {
            SoundState *d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, void *, 0x1CC) - 0x1CC);
            *slot = 0;
            FIELD_AT(d, int, 0x230) |= 1 << i;
            FIELD_AT(d, int, 0x22C) &= ~(1 << i);
        } else {
            SoundState *d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, void *, 0x1CC) - 0x1CC);
            char *p;
            FIELD_AT(n, unsigned char, 0x3) = 0;
            p = FIELD_AT(d, char *, 0x238);
            if (p != 0) {
                if (p == n) {
                    FIELD_AT(d, char *, 0x238) = FIELD_AT(n, char *, 0x2C);
                } else {
                    while (FIELD_AT(p, char *, 0x2C) != 0) {
                        if (FIELD_AT(p, char *, 0x2C) == n) {
                            FIELD_AT(p, char *, 0x2C) = FIELD_AT(FIELD_AT(p, char *, 0x2C), char *, 0x2C);
                            break;
                        }
                    }
                }
            }
        }
        func_8008BA68();
    }
}

EXTERN_C void func_80093C9C(void)
{
    char *n;

    for (n = FIELD_AT(&D_800B18FC, char *, 0x238); n != 0; n = FIELD_AT(n, char *, 0x2C)) {
        func_80093DE8(n);
    }
    FIELD_AT(&D_800B18FC, char *, 0x238) = 0;
}

struct Slot_80093CE8 {
    short idx;
    char pad2[2];
    short prio;
    short unk6;
};

EXTERN_C void func_80093CE8(Slot_80093CE8 *s)
{
    int i = s->idx;
    Slot_80093CE8 **slot = &(&FIELD_AT(&D_800B18FC, Slot_80093CE8 *, 0x1CC))[i];

    if ((unsigned int)i < 0x18) {
        Slot_80093CE8 *cur = *slot;
        if (cur == s) {
            SoundState *d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, Slot_80093CE8 *, 0x1CC) - 0x1CC);
            FIELD_AT(d, int, 0x234) |= 1 << i;
        } else if (cur == 0 || cur->prio <= s->prio) {
            SoundState *d;
            s->unk6 = 0x7FFF;
            *slot = s;
            d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, Slot_80093CE8 *, 0x1CC) - 0x1CC);
            FIELD_AT(d, int, 0x234) |= 1 << i;
            FIELD_AT(d, int, 0x22C) &= ~(1 << i);
        }
    }
}

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

EXTERN_C void func_80093DE8(void *n)
{
    int i = FIELD_AT(n, short, 0x0);
    void **slot = &(&FIELD_AT(&D_800B18FC, void *, 0x1CC))[i];

    if ((unsigned int)i < 0x18) {
        void *cur = *slot;
        if (cur != n) {
            if (cur == 0 || FIELD_AT(cur, short, 0x4) <= FIELD_AT(n, short, 0x4)) {
                SoundState *d;
                FIELD_AT(n, short, 0x6) = 0x7FFF;
                *slot = n;
                d = (SoundState *)((char *)&FIELD_AT(&D_800B18FC, void *, 0x1CC) - 0x1CC);
                FIELD_AT(d, int, 0x234) |= 1 << i;
            } else {
                return;
            }
        }
        {
            SoundState *d2 = &D_800B18FC;
            FIELD_AT(d2, int, 0x22C) |= 1 << i;
        }
    }
}

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

EXTERN_C void SpuSetVoiceVolume(int voice, short l, short r);
EXTERN_C void SpuSetVoicePitch(int voice, unsigned short pitch);
EXTERN_C void SpuSetVoiceStartAddr(int voice, unsigned long addr);
EXTERN_C void SpuSetVoiceLoopStartAddr(int voice, unsigned long addr);
EXTERN_C void SpuSetVoiceARAttr(int voice, unsigned short ar, long mode);
EXTERN_C void SpuSetVoiceDR(int voice, unsigned short dr);
EXTERN_C void SpuSetVoiceSL(int voice, unsigned short sl);
EXTERN_C void SpuSetVoiceSRAttr(int voice, unsigned short sr, long mode);
EXTERN_C unsigned long func_8009F700(long on_off, unsigned long voice_bit); /* SpuSetPitchLFOVoice */
EXTERN_C unsigned long func_8009EBC0(long on_off, unsigned long voice_bit); /* SpuSetNoiseVoice */
EXTERN_C unsigned long func_8009F0E0(long on_off, unsigned long voice_bit); /* SpuSetReverbVoice */

EXTERN_C void func_80093FE0(void)
{
    char **pp = &FIELD_AT(&D_800B18FC, char *, 0x1CC);
    unsigned int m3 = 0;
    unsigned int m2 = m3;
    unsigned int m1 = m2;
    unsigned short acc = m1;
    int i = m1;
    char *v;
    unsigned short f;
    unsigned int b;
    SoundState *s;

    for (; i < 0x18; i++, pp++) {
        v = *pp;
        if (v == 0) {
            continue;
        }
        f = FIELD_AT(v, unsigned short, 0x6);
        if (f != 0) {
            if (f & 1) {
                SpuSetVoiceVolume(i, FIELD_AT(v, short, 0x8), FIELD_AT(v, short, 0xA));
            }
            if (f & 4) {
                SpuSetVoicePitch(i, FIELD_AT(v, unsigned short, 0x14));
            }
            if (f & 8) {
                SpuSetVoiceStartAddr(i, FIELD_AT(v, unsigned long, 0x1C));
                SpuSetVoiceLoopStartAddr(i, FIELD_AT(v, unsigned long, 0x20));
            }
            if (f & 0x10) {
                SpuSetVoiceARAttr(i, FIELD_AT(v, unsigned char, 0x27), FIELD_AT(v, unsigned char, 0x24));
            }
            if (f & 0x20) {
                SpuSetVoiceDR(i, FIELD_AT(v, unsigned char, 0x28));
            }
            if (f & 0x100) {
                SpuSetVoiceSL(i, FIELD_AT(v, unsigned char, 0x2B));
            }
            if (f & 0x40) {
                SpuSetVoiceSRAttr(i, FIELD_AT(v, unsigned char, 0x29), FIELD_AT(v, unsigned char, 0x25));
            }
            if (f & 0x80) {
                SpuSetVoiceRRAttr(i, FIELD_AT(v, unsigned char, 0x2A), FIELD_AT(v, unsigned char, 0x26));
            }
            acc |= f & 0x7000;
            FIELD_AT(v, unsigned short, 0x6) = 0;
        }
        b = FIELD_AT(v, unsigned char, 0x2);
        m1 |= ((b >> 4) & 1) << i;
        m2 |= ((b >> 5) & 1) << i;
        m3 |= ((b >> 6) & 1) << i;
    }
    if (acc != 0) {
        if (acc & 0x1000) {
            func_8009F700(1, m1);
            func_8009F700(0, ~m1);
        }
        if (acc & 0x2000) {
            func_8009EBC0(1, m2);
            func_8009EBC0(0, ~m2);
        }
        if (acc & 0x4000) {
            func_8009F0E0(1, m3);
            func_8009F0E0(0, ~m3);
        }
    }
    s = &D_800B18FC;
    if (FIELD_AT(s, int, 0x22C) != 0) {
        SpuSetKey(1, FIELD_AT(s, int, 0x22C));
        FIELD_AT(s, int, 0x22C) = 0;
    }
}

EXTERN_C GlobalWord D_800B4EE0;

EXTERN_C void func_8009422C(void)
{
    unsigned int mask = FIELD_AT(&D_800B18FC, unsigned int, 0x234);
    int base = (int)D_800B4EE0.p;
    volatile int p;
    int i;
    SoundState *s;

    if (mask != 0) {
        p = base;
        for (i = 0; i < 0x18; i++) {
            if (mask & (1 << i)) {
                SpuSetVoiceRRAttr(i, 6, 3);
            }
            p += 0x10;
        }
    }
    s = &D_800B18FC;
    mask |= FIELD_AT(s, unsigned int, 0x230);
    if (mask != 0) {
        SpuSetKey(0, mask);
        FIELD_AT(s, int, 0x234) = 0;
        FIELD_AT(s, int, 0x230) = 0;
    }
}

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

typedef int (*LfoFn_80094330)(Node_80093800 *n);

EXTERN_C void func_80094330(void *drv)
{
    char *t = FIELD_AT(drv, char *, 0xC);
    int i = FIELD_AT(drv, unsigned char, 0x2A);
    int n;
    char *v;
    Node_80093800 *nd;
    int f;
    int r;
    int c;

    do {
        if (FIELD_AT(t, short, 0x0) < 0 && FIELD_AT(t, char *, 0x24) != 0) {
            n = FIELD_AT(t, unsigned char, 0x8);
            v = FIELD_AT(t, char *, 0x24);
            while (n--) {
                nd = FIELD_AT(v, Node_80093800 *, 0xA8);
                f = FIELD_AT(v, unsigned char, 0xB);
                FIELD_AT(v, short, 0xA4) = 0;
                FIELD_AT(v, short, 0xA2) = 0;
                FIELD_AT(v, short, 0xA0) = 0;
                for (; nd != 0; nd = nd->next) {
                    if (FIELD_AT(nd, unsigned short, 0x18) != 0) {
                        FIELD_AT(nd, unsigned short, 0x18)--;
                        continue;
                    }
                    r = FIELD_AT(nd, LfoFn_80094330, 0x4)(nd);
                    c = nd->unk1C;
                    if (c < 0x400) {
                        r = (r >> 10) * c;
                        nd->unk1C = nd->unk1E + c;
                    }
                    r >>= 16;
                    switch (FIELD_AT(nd, unsigned char, 0x3)) {
                    case 0:
                        FIELD_AT(v, short, 0xA0) += r;
                        f |= 8;
                        break;
                    case 1:
                        FIELD_AT(v, short, 0xA2) += r;
                        f |= 4;
                        break;
                    case 2:
                        FIELD_AT(v, short, 0xA4) += r;
                        f |= 4;
                        break;
                    }
                }
                FIELD_AT(v, unsigned char, 0xB) = f;
                v += 0xE4;
            }
        }
        t += 0x160;
    } while (--i);
}

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

EXTERN_C int func_800947B8(void *a)
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
