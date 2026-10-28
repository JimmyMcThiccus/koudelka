#include "pre.h"
// NONMATCH: ~254 diffs, logic complete; s1/s2 (t vs t+0x40) and a0/a1 register swaps, lb vs lbu for t->5F, 1 extra insn
typedef unsigned char *(*SeqCmd_80090CF4)(void *drv, SeqTrack *t, unsigned char *p);
struct Cmds_800AF8BC {
    SeqCmd_80090CF4 v[0x100];
};
struct Notes_800AFDC4 {
    unsigned short v[0x100];
};
struct Lens_800AFF9C {
    unsigned char v[0x100];
};
EXTERN_C Cmds_800AF8BC D_800AF8BC;
EXTERN_C Notes_800AFDC4 D_800AFDC4;
EXTERN_C Lens_800AFF9C D_800AFF9C;
EXTERN_C int func_800912DC(void *drv, SeqTrack *t);

struct Ev_80090CF4 {
    unsigned char play;
    unsigned char unk1;
    unsigned char vel;
    unsigned char note;
    int len;
};

EXTERN_C void func_80090CF4(void *drv)
{
    SeqTrack *t = FIELD_AT(drv, SeqTrack *, 0xC);
    int i = FIELD_AT(drv, unsigned char, 0x2A);
    unsigned char *p;
    unsigned short f;
    unsigned short f2;
    Ev_80090CF4 ev;
    unsigned char c;
    unsigned int cmd;
    unsigned short k;
    int len;
    int skip;
    Loop_80091910 *lp;
    char *v;
    int n;
    Node_80093800 *nd;
    unsigned short nf;
    int a;
    int gate;

    do {
        if ((short)t->flags < 0) {
            if (func_800912DC(drv, t)) {
                t->flags = 0;
            }
            ev.play = 0;
            p = FIELD_AT(t, unsigned char *, 0x1C);
            f = t->flags;
            if (p != 0) {
                while (t->unk40 == 0) {
                    if (!(f & 0xA00)) {
                        FIELD_AT(t, int, 0x58) = 0;
                    }
                    t->flags &= 0xF8FF;
                    ev.vel = FIELD_AT(t, signed char, 0x5F);
                    ev.note = FIELD_AT(t, unsigned char, 0x52);
                    do {
                        cmd = *p++;
                        if (cmd < 0x80) {
                            ev.vel = FIELD_AT(t, signed char, 0x5F);
                            k = D_800AFDC4.v[*p++];
                            len = k & 0xFF;
                            ev.note = t->octave + (k >> 8);
                            if (len == 0) {
                                len = *p++;
                            }
                            t->unk40 = len;
                            t->flags |= 0x100;
                        } else {
                            p = D_800AF8BC.v[cmd](drv, t, p);
                            if (!((short)t->flags & 0x8000)) {
                                FIELD_AT(drv, int, 0x20) &= ~(1 << FIELD_AT(t, unsigned char, 0x4));
                                t->flags |= 0x4000;
                                break;
                            }
                        }
                    } while (!(t->flags & 0x500));
                    FIELD_AT(t, unsigned char *, 0x1C) = p;
                    if (!((short)t->flags & 0x8000)) {
                        break;
                    }
                    if (t->flags & 0x500) {
                        ev.play = 1;
                    }
                    if (t->flags & 0x800) {
                        t->flags |= 0x200;
                    }
                    lp = &((Loop_80091910 *)((char *)t + 0x90))[FIELD_AT(t, unsigned char, 0xE)];
                    c = *p;
                    while (c >= 0x80) {
                        if (c == 0x90) {
                            p = t->mark;
                            if (p != 0) {
                                goto next;
                            }
                            goto out;
                        } else {
                            if (c == 0x88) {
                                FIELD_AT(t, short, 0x0) &= ~0x200;
                                goto out;
                            } else if (c == 0x89) {
                                t->flags |= 0x200;
                                goto out;
                            } else if (c == 0xC0 || c == 0xC1) {
                                FIELD_AT(t, short, 0x0) &= ~0x200;
                                goto out;
                            }
                            if (c == 0x99) {
                                if (lp->count != 0) {
                                    p = lp->start;
                                    goto next;
                                }
                                lp--;
                            }
                            if (c == 0x9A && lp->count == 0) {
                                p = lp->end;
                                lp--;
                            } else {
                                skip = D_800AFF9C.v[c];
                                if (skip == 0) {
                                    func_8009484C(0xC2, (int)p);
                                    t->flags = 0;
                                    goto out;
                                }
                                p += skip;
                            }
                        }
                    next:
                        c = *p;
                    }
                out:;
                }
            } else {
                f2 = f;
                if (f & 0x20) {
                    f2 = (f & ~0x20) | 0x100;
                    ev.vel = FIELD_AT(t, signed char, 0x5F);
                    ev.note = FIELD_AT(t, unsigned char, 0x52);
                    ev.play = 1;
                }
                if (t->unk40 == 0) {
                    func_8008E2A0(t);
                    FIELD_AT(drv, int, 0x20) &= ~(1 << FIELD_AT(t, unsigned char, 0x4));
                    t->flags = (f2 & 0x7EFF) | 0x4000;
                    return;
                }
                t->flags = f2;
            }
            if ((short)t->flags < 0 && ev.play) {
                n = t->unk40;
                v = FIELD_AT(t, char *, 0x24);
                gate = t->unk50;
                switch (gate) {
                case 16:
                    FIELD_AT(v, int, 0x0) = n;
                    goto set;
                case 15:
                    n--;
                    break;
                default:
                    n = n * gate >> 4;
                    break;
                }
                if (n <= 0) {
                    n = 1;
                }
                FIELD_AT(v, int, 0x0) = n;
            set:
                FIELD_AT(t, unsigned char, 0x53) = FIELD_AT(t, unsigned char, 0x52) = ev.note;
                if (FIELD_AT(t, unsigned short, 0x2) & 0x100) {
                    FIELD_AT(t, short, 0x8A) = FIELD_AT(t, unsigned short, 0x6C);
                    FIELD_AT(t, int, 0x78) = FIELD_AT(t, int, 0x68);
                    FIELD_AT(t, int, 0x64) = FIELD_AT(t, unsigned short, 0x6E) << 22;
                    FIELD_AT(t, unsigned short, 0x2) |= 8;
                }
                if (!(f & 0xA00)) {
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
                }
                if (FIELD_AT(v, unsigned char, 0xA) & 0x20) {
                    FIELD_AT(v, short, 0xBA) = 0x7FFF;
                    FIELD_AT(v, unsigned char, 0xA) &= ~0x20;
                }
                if (t->flags & 0x100) {
                    FIELD_AT(v, short, 0x4) = FIELD_AT(v, unsigned short, 0xE) + ((ev.note + (signed char)FIELD_AT(v, unsigned char, 0x9)) << 8);
                    FIELD_AT(v, short, 0x6) = ev.vel * FIELD_AT(v, unsigned char, 0xD);
                    FIELD_AT(v, char *, 0xAC) = FIELD_AT(t, char *, 0x28);
                    FIELD_AT(t, char *, 0x28) = v;
                    a = FIELD_AT(v, unsigned char, 0xA);
                    FIELD_AT(v, unsigned short, 0xBA) |= 0x80;
                    FIELD_AT(v, unsigned char, 0xDE) = FIELD_AT(v, unsigned char, 0x8);
                    if (a & 2) {
                        FIELD_AT(v, unsigned char, 0xB) |= 0xC;
                    } else {
                        FIELD_AT(v, unsigned char, 0xB) |= 0xD;
                    }
                    a = (a | 0x80) & ~2;
                    if ((t->flags & 0xA00) && !(f & 0x400)) {
                        a |= 2;
                        FIELD_AT(v, unsigned char, 0xB) &= ~1;
                    }
                    FIELD_AT(v, unsigned char, 0xA) = a;
                    FIELD_AT(t, unsigned char, 0x53) = ev.note;
                }
            }
        }
        t->unk40--;
        t = (SeqTrack *)((char *)t + 0x160);
    } while (--i);
}
