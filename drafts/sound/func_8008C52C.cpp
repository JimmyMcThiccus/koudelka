#include "pre.h"
// NONMATCH: 16 diffs, register allocation in the record-copy loop only (retail keeps i/e/giv in v0/a1/v1 and re-materializes the constant 1). Contains an inlined copy of func_8008BC0C (early-return form); needs BC0C as an inline helper when landed.
struct Blk_8008C52C {
    unsigned short flags;
    short unk2;
    int unk4;
    char *end;
    Blk_8008C52C *next;
};
struct SpuBlk_8008C52C {
    unsigned char next;
    unsigned char flags;
    unsigned short id;
    int addr;
    int size;
    int pad;
};
struct Rec_8008C52C {
    int addr;
    int size;
    unsigned short id;
    short used;
};
EXTERN_C void func_8008BF78(char *p, int n);

static inline void *alloc_8008C52C(int size)
{
    SoundState *s = &D_800B18FC;
    Blk_8008C52C *b = FIELD_AT(s, Blk_8008C52C *, 0x8);
    unsigned int need = ((size + 3) & ~3) + 0x10;
    Blk_8008C52C *n;
    char *data;
    char *lim;

    for (;;) {
        if (b->next == 0) {
            lim = FIELD_AT(&D_800B18FC, char *, 0xC);
            break;
        }
        if ((unsigned int)((char *)b->next - b->end) >= need) {
            goto found;
        }
        b = b->next;
    }
    if ((unsigned int)(lim - b->end) < need) {
        return 0;
    }
found:
    n = (Blk_8008C52C *)(((int)b->end + 3) & ~3);
    data = (char *)n + 0x10;
    n->end = data + size;
    n->next = 0;
    n->unk4 = 0;
    n->flags = 2;
    n->unk2 = 0;
    n->next = b->next;
    b->next = n;
    func_8008BF78(data, size);
    return data;
}

#define TBL (&FIELD_AT(&D_800B18FC, SpuBlk_8008C52C, 0x14))
EXTERN_C Rec_8008C52C *func_8008C52C(Rec_8008C52C *buf)
{
    Rec_8008C52C *r = buf;
    SpuBlk_8008C52C *e;
    int i;

    if (buf == 0) {
        buf = (Rec_8008C52C *)alloc_8008C52C(0xCC);
        r = buf;
    }
    r->addr = TBL->addr;
    r->size = TBL->size;
    r->id = TBL->id;
    r->used = 1;
    i = TBL->next;
    r++;
    while (i != 0) {
        e = (SpuBlk_8008C52C *)((i << 4) + (int)TBL);
        r->addr = e->addr;
        r->size = e->size;
        r->id = e->id;
        r->used = 1;
        r++;
        i = e->next;
    }
    r->used = 0;
    return buf;
}
