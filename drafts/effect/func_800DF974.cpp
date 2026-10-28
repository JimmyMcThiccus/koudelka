// func_800DF974:
// MATCHES (0 differing) but can't land yet: its jump table's retail address lies in 0x800D61B0-0x800D6528, where
// tables are 8-aligned absolutely; effect.cpp's rodata starts at 0x800D5DAC (4 mod 8) and GCC aligns compiled
// tables to 8 within the unit, so the table lands 4 bytes off. Needs EFFECT split at the original file boundary.
// matches; jump tables jtbl_800D64D0 (9 words + trailing 0 pad word) and jtbl_800D64F8 (12 words) are in the blocked 0x800D61B0-0x800D6528 range
#include "common.h"
#include "effect/effect.h"

EXTERN_C void *func_800E4CAC(void *self, short id);
EXTERN_C void *func_800E5030(void *self, short id);
EXTERN_C void *func_800E5254(void *self, short id);
EXTERN_C void *func_800E5450(void *self, short id);

EXTERN_C char *func_800DF974(void *self, char *src, void *obj)
{
    char *next = 0;
    void *p = 0;
    Key *k = 0;
    VtEntry *vt;
    char *h = src;
    switch ((short)(FIELD_AT(h, short, 0x0) - 1)) {
    case 0:
        {
            short t = FIELD_AT(h, short, 0x8);
            FIELD_AT(obj, int, 0x6C) = FIELD_AT(h, short, 0x4);
            FIELD_AT(obj, short, 0x74) = t;
        }
        next = h + 0xC;
        break;
    case 1:
        switch (FIELD_AT(h, short, 0x2) >> 8) {
        case 0:
            p = func_800E4CAC(operator new(0x48), FIELD_AT(obj, short, 0x8));
            break;
        case 1:
            p = func_800E5030(operator new(0x48), FIELD_AT(obj, short, 0x8));
            break;
        case 2:
            p = func_800E5254(operator new(0x48), FIELD_AT(obj, short, 0x8));
            break;
        case 3:
            p = func_800E5450(operator new(0x48), FIELD_AT(obj, short, 0x8));
            break;
        }
        vt = FIELD_AT(p, VtEntry *, 0x0);
        next = ((char *(*)(void *, char *))vt[2].pfn)((char *)p + vt[2].delta, src);
        FIELD_AT(obj, void *, 0x2C) = p;
        break;
    case 2:
        switch (FIELD_AT(h, short, 0x2) >> 8) {
        case 0:
            p = func_800E4CAC(operator new(0x48), FIELD_AT(obj, short, 0x8));
            break;
        case 1:
            p = func_800E5030(operator new(0x48), FIELD_AT(obj, short, 0x8));
            break;
        case 2:
            p = func_800E5254(operator new(0x48), FIELD_AT(obj, short, 0x8));
            break;
        case 3:
            p = func_800E5450(operator new(0x48), FIELD_AT(obj, short, 0x8));
            break;
        }
        vt = FIELD_AT(p, VtEntry *, 0x0);
        next = ((char *(*)(void *, char *))vt[2].pfn)((char *)p + vt[2].delta, src);
        FIELD_AT(obj, void *, 0x30) = p;
        break;
    case 3:
        switch (FIELD_AT(h, short, 0x2)) {
        case 0: {
            KeyVec *kv = (KeyVec *)operator new(0x20);
            keyvec_init(kv, 0);
            k = kv;
            break;
        }
        case 1: {
            KeyInt *ki = (KeyInt *)operator new(0x10);
            key_init(ki, 1);
            ki->vptr = D_800D6138;
            ki->value = 0;
            k = ki;
            break;
        }
        case 2: {
            KeyInt *ki = (KeyInt *)operator new(0x10);
            key_init(ki, 2);
            ki->vptr = D_800D6110;
            ki->value = 0;
            k = ki;
            break;
        }
        case 5:
            k = (Key *)operator new(0xC);
            key_init(k, 5);
            k->vptr = D_800D60E8;
            break;
        case 6:
            k = (Key *)operator new(0xC);
            key_init(k, 6);
            k->vptr = D_800D60C0;
            break;
        case 8:
            k = (Key *)operator new(0xC);
            key_init(k, 8);
            k->vptr = D_800D6098;
            break;
        case 10: {
            KeyVec *kv = (KeyVec *)operator new(0x20);
            keyvec_init(kv, 10);
            kv->vptr = D_800D6070;
            k = kv;
            break;
        }
        case 11: {
            KeyVec *kv = (KeyVec *)operator new(0x20);
            keyvec_init(kv, 11);
            kv->vptr = D_800D6048;
            k = kv;
            break;
        }
        }
        vt = (VtEntry *)k->vptr;
        next = ((char *(*)(void *, char *))vt[2].pfn)((char *)k + vt[2].delta, src);
        FIELD_AT(obj, Key *, 0x50) = k;
        break;
    case 4:
        FIELD_AT(obj, int, 0x70) = FIELD_AT(h, short, 0x4);
        next = h + 0xC;
        break;
    case 5:
        FIELD_AT(obj, short, 0x7A) = FIELD_AT(h, short, 0x4);
        FIELD_AT(obj, short, 0x7C) = FIELD_AT(h, short, 0x6);
        FIELD_AT(obj, short, 0x7E) = FIELD_AT(h, short, 0x8);
        next = h + 0xC;
        break;
    case 6:
        FIELD_AT(obj, char, 0x86) = FIELD_AT(h, char, 0x4);
        FIELD_AT(obj, char, 0x87) = FIELD_AT(h, char, 0x5);
        FIELD_AT(obj, char, 0x88) = FIELD_AT(h, char, 0x6);
        next = h + 8;
        break;
    case 7:
        FIELD_AT(obj, short, 0x80) = FIELD_AT(h, short, 0x2);
        FIELD_AT(obj, short, 0x82) = FIELD_AT(h, short, 0x4);
        FIELD_AT(obj, short, 0x84) = FIELD_AT(h, short, 0x6);
        next = h + 8;
        break;
    case 8:
        {
            char *p = h;
            h += 4;
            FIELD_AT(obj, short, 0x78) = FIELD_AT(p, short, 0x2);
            next = h;
        }
        break;
    }
    return next;
}
