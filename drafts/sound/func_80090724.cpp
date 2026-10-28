#include "pre.h"
// NONMATCH: 1 diff, operand order of addu (note + (signed char)v->9) at 0x278
struct Ent_80090A88;
EXTERN_C Ent_80090A88 *func_80090A88(Ent_80090A88 *e, int x);
EXTERN_C void func_80093F40(Slot_80093D8C *s);
EXTERN_C void func_8008D5E8(void *v, void *song, short idx);

EXTERN_C void func_80090724(void *drv, SeqTrack *t, unsigned char *ev)
{
    char *v;
    char *prev;
    int n;
    int note;
    unsigned char *d;
    unsigned char key;
    unsigned char *e;
    char *song;
    char *smp;
    int base;
    unsigned short nf;
    Node_80093800 *nd;

    if (t->flags & 0x800) {
        n = FIELD_AT(t, unsigned char, 0x8);
        v = FIELD_AT(t, char *, 0x24);
        while (n--) {
            if (FIELD_AT(v, unsigned char, 0xA) & 2) {
                return;
            }
            v += 0xE4;
        }
        if (n < 0) {
            v = FIELD_AT(t, char *, 0x2C);
        }
    } else {
        v = FIELD_AT(t, char *, 0x2C);
        if (v != 0) {
            FIELD_AT(t, char *, 0x2C) = FIELD_AT(v, char *, 0xB0);
        } else {
            v = FIELD_AT(t, char *, 0x28);
            prev = 0;
            while (FIELD_AT(v, char *, 0xAC) != 0) {
                prev = v;
                v = FIELD_AT(v, char *, 0xAC);
            }
            if (prev != 0) {
                FIELD_AT(prev, char *, 0xAC) = 0;
            } else {
                FIELD_AT(v, char *, 0xAC) = 0;
                FIELD_AT(t, char *, 0x28) = 0;
            }
            func_80093F40((Slot_80093D8C *)(v + 0xB4));
        }
    }
    note = ev[3];
    if (t->flags & 1) {
        key = note;
        d = FIELD_AT(drv, unsigned char *, 0x14) + (key * 4 - 0x60);
        if (FIELD_AT(t, unsigned char, 0x53) != key || FIELD_AT(v, unsigned char, 0xC) != d[0]) {
            FIELD_AT(t, unsigned char, 0x53) = note;
            func_8008D5E8(v, FIELD_AT(t, char *, 0x30), d[0]);
            FIELD_AT(v, unsigned char, 0xD) = d[2];
            FIELD_AT(t, int, 0x60) = d[3] << 16;
        }
        note = d[1];
    } else {
        if (FIELD_AT(t, signed char, 0x4E) >= 0 && !(FIELD_AT(v, unsigned char, 0xA) & 2)) {
            e = (unsigned char *)func_80090A88(FIELD_AT(t, Ent_80090A88 *, 0x34), note);
            song = FIELD_AT(t, char *, 0x30);
            smp = FIELD_AT(song, char *, 0x14) + e[0] * 16;
            base = FIELD_AT(smp, int, 0x0);
            FIELD_AT(v, int, 0xD0) = base + FIELD_AT(song, int, 0xC);
            FIELD_AT(v, int, 0xD4) = base + FIELD_AT(smp, unsigned short, 0x4) * 8;
            FIELD_AT(v, unsigned char, 0xC) = e[0];
            FIELD_AT(v, unsigned char, 0xD) = FIELD_AT(smp, unsigned char, 0xE) * e[4] / 127;
            FIELD_AT(v, unsigned short, 0xE) = FIELD_AT(smp, unsigned short, 0x6);
            FIELD_AT(v, unsigned char, 0xA) |= 0x20;
            FIELD_AT(v, unsigned char, 0x9) = 0x3C - e[1];
        }
        FIELD_AT(t, unsigned char, 0x53) = note;
    }
    if (FIELD_AT(v, unsigned char, 0xA) & 0x20) {
        FIELD_AT(v, short, 0xBA) = 0x7FFF;
        FIELD_AT(v, unsigned char, 0xA) &= ~0x20;
    }
    FIELD_AT(v, int, 0x0) = FIELD_AT(ev, int, 0x4);
    FIELD_AT(v, short, 0x4) = FIELD_AT(v, unsigned short, 0xE) + ((note + (signed char)FIELD_AT(v, unsigned char, 0x9)) << 8);
    FIELD_AT(v, short, 0x6) = ev[2] * FIELD_AT(v, unsigned char, 0xD);
    FIELD_AT(v, char *, 0xAC) = FIELD_AT(t, char *, 0x28);
    FIELD_AT(t, char *, 0x28) = v;
    for (nd = FIELD_AT(v, Node_80093800 *, 0xA8); nd != 0; nd = nd->next) {
        nf = nd->flags;
        if (nf & 0x10) {
            nd->unk8 = 0;
            nd->unk14 = 1;
            nd->flags = nf & ~0x60;
            nd->unk18 = nd->unk1A;
            nd->unk1C = nd->unk1E;
        }
    }
    FIELD_AT(v, unsigned char, 0xB) = (FIELD_AT(v, unsigned char, 0xB) | 0xD) & ~2;
    FIELD_AT(v, unsigned char, 0xA) |= 0x80;
    if (t->flags & 0x800) {
        FIELD_AT(v, unsigned char, 0xA) |= 2;
    }
}
