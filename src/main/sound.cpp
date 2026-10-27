#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BA68);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008BAC4);

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

struct Blk_8008BE08 {
    int unk0;
    int unk4;
    char *end;
    Blk_8008BE08 *next;
};

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C3AC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C414);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C448);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C4B8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C4F0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C52C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C6B0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C6F8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C724);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C748);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C76C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C790);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C7B4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C928);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C970);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008C9A8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CA50);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CB84);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CC20);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CC88);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CD1C);

EXTERN_C void func_8008CD88(int a, int b)
{
    D_800B18FC.unk184 = a;
    D_800B18FC.unk188 = b;
    D_800B18FC.unk170 |= 0x300;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CDA8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CE18);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008CFD4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D038);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D08C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D114);

EXTERN_C void *func_8008D1E4(void)
{
    return D_800B1B48.p;
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D1F4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D450);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D4C0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D5A8);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D808);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D84C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D8F4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D950);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008D97C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DA00);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DACC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DBEC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DC78);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DCE4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DD50);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008DEE4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E024);

EXTERN_C void func_8008E060(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E068);

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

struct Time_8008E134 {
    char pad0[2];
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
    unsigned char unk6;
    unsigned char unk7;
    char pad8[4];
    unsigned short ticks;
};

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E1B4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E210);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E2A0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E308);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E360);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E504);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E590);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E678);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E698);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E70C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E75C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008E994);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EA9C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EB40);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008ECB4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008ED44);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EDE0);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EF18);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EF40);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008EF64);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008F0CC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008F1DC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008F4B0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008F618);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FA34);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FAB4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FB80);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FC38);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FD04);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FD44);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8008FD94);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800912DC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091334);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800916A0);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091910);

struct Loop_80091910 {
    unsigned char count;
    unsigned char unk1;
    unsigned char octave;
    unsigned char octave2;
    unsigned char *start;
    unsigned char *end;
};

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80091FB4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009200C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092054);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009209C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800920E4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009212C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092178);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800921C8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092210);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092258);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800922E4);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009231C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092354);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800923A8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092408);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092440);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092478);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800924D0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092508);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092540);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092584);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800925D0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009261C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092668);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800926B8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092754);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800927C8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092910);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092A98);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092ACC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092B00);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092B3C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092B98);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092F54);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092F88);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80092FBC);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800933E8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_8009341C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093450);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093524);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093610);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800936A0);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800936D8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093710);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093788);

struct Node_80093800 {
    unsigned short flags;
    char pad2[6];
    int unk8;
    char padC[8];
    short unk14;
    char pad16[2];
    short unk18;
    short unk1A;
    short unk1C;
    short unk1E;
    Node_80093800 *next;
};

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093858);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800939A8);

struct Voice_80091FB4 {
    char pad0[0x8];
    unsigned char unk8;
    char pad9[0x23];
    short unk2C;
    short unk2E;
    char pad30[0x20];
    short unk50;
    short unk52;
    char pad54[0x20];
    short unk74;
    short unk76;
    char pad78[0x3E];
    unsigned char unkB6;
    char padB7[3];
    unsigned short flags;
    char padBC[0x1C];
    unsigned char unkD8;
    unsigned char unkD9;
    unsigned char unkDA;
    unsigned char unkDB;
    unsigned char unkDC;
    unsigned char unkDD;
    unsigned char unkDE;
    unsigned char unkDF;
    char padE0[4];
};

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093A40);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093AEC);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093B3C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093BB8);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093C9C);

INCLUDE_ASM("asm/main/nonmatchings/sound", func_80093CE8);

struct Slot_80093D8C {
    short idx;
    char pad2[2];
    short prio;
};

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800947C0);

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

INCLUDE_ASM("asm/main/nonmatchings/sound", func_800948B4);

EXTERN_C void func_80094908(void)
{
}
