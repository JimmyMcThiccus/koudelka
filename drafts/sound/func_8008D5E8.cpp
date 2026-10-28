#include "pre.h"
// NONMATCH: 17 diffs; retail never recycles the m/w temp register for the last bit-field extract and orders the final 0xD/0xA/0xE stores differently
EXTERN_C void func_8008D5E8(void *v, void *b, short idx)
{
    char *e = FIELD_AT(b, char *, 0x14) + (idx << 4);
    int a = FIELD_AT(e, int, 0x0);
    unsigned int m;
    unsigned int w;

    FIELD_AT(v, int, 0xD0) = a + FIELD_AT(b, int, 0xC);
    FIELD_AT(v, int, 0xD4) = a + (FIELD_AT(e, unsigned short, 0x4) << 3);
    m = FIELD_AT(e, unsigned short, 0xC);
    FIELD_AT(v, unsigned char, 0xD8) = m & 7;
    FIELD_AT(v, unsigned char, 0xD9) = (m >> 4) & 7;
    FIELD_AT(v, unsigned char, 0xDA) = (m >> 8) & 7;
    w = FIELD_AT(e, unsigned int, 0x8);
    FIELD_AT(v, unsigned char, 0xC) = idx;
    FIELD_AT(v, unsigned char, 0xDB) = w & 0x7F;
    FIELD_AT(v, unsigned char, 0xDC) = (w >> 8) & 0xF;
    FIELD_AT(v, unsigned char, 0xDD) = (w >> 16) & 0x7F;
    FIELD_AT(v, unsigned char, 0xDE) = (w >> 24) & 0x1F;
    FIELD_AT(v, unsigned char, 0xDF) = (w >> 12) & 0xF;
    FIELD_AT(v, unsigned char, 0xD) = FIELD_AT(e, unsigned char, 0xE);
    FIELD_AT(v, unsigned char, 0xA) |= 0x20;
    FIELD_AT(v, unsigned short, 0xE) = FIELD_AT(e, unsigned short, 0x6);
}
