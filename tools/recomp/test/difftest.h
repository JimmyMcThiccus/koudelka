/* Shared between harness.c and the generated cases.c. */
#ifndef DIFFTEST_H
#define DIFFTEST_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    const char *name;
    void *decomp;         /* the decompiled function, built natively */
    void *recomp;         /* its recompiled twin */
    int nargs;            /* 4 + incoming stack words */
    int ret_bits;         /* 0 (void), 8, 16, 32 or 64 */
    const char *argkinds; /* per argument: p pointer, c/C s8/u8, s/S s16/u16, i 32-bit, b bool */
} Case;

extern const Case cases[];
extern const int ncases;

#endif
