// func_800BE204: ~228 differ (+12 bytes). Logic, case order (6,4,11,1,7,13,12) and the inner ShortPair loop are right; loop.c
// hoists &D_800102D0 into $s7 where retail hoists the constant 1 (retail: fp=0x1000, s4=2, s7=1, s6=D_80010178, s5=D_80010300).
// The jump table now lands (master a533c9f moved capture_b's rodata start).
#include "common.h"
#include "capture/capture.h"

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
/* the message vtable as a small object: one `la` insn, which loop.c doesn't hoist */
EXTERN_C int D_800102D0_obj __asm__("D_800102D0");
EXTERN_C void *D_800B4ED8[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C char *func_8001ED2C(void *, int, int);
EXTERN_C ShortPair func_800C0A28(char *p, short key, int c);
EXTERN_C void func_800C0D14(char *, ShortPair);
EXTERN_C void func_800665C8(void *);
EXTERN_C void *func_800663EC(void *, int, void *, int, int, int);
EXTERN_C void *func_80066FB0(void *, void *, int, int, int);
EXTERN_C void func_800670A4(void *);
EXTERN_C void func_800BE8E0(char *p);
EXTERN_C void func_800BF094(char *p);
EXTERN_C void func_800BE5EC(char *p);
EXTERN_C void func_800BE5E4(char *p);
EXTERN_C void func_800BDFE0(char *p);
EXTERN_C void func_800BEC00(void *);
EXTERN_C void func_800BEBB0(char *p);

EXTERN_C void func_800BE204(char *p)
{
    while (*(int *)(p + 0x26C)) {
        VObject *m = (VObject *)func_8001ED2C(p, 1, 1);
        short c = *(short *)(p + 0x3D2);
        ShortPair t;
        while (c) {
            c--;
            t = func_800C0A28(p, c, 1);
            if (t.b != 0x1000)
                func_800C0D14(p, ShortPair(t));
        }
        if (*(int *)(p + 0x628)) {
            VObject *o = *(VObject **)(p + 0x624);
            if (o) {
                VtblEntry *e = &o->vt[3];
                ((void (*)(void *))e->pfn)((char *)o + e->delta);
                func_800665C8(*(void **)(p + 0x624));
                *(int *)(p + 0x628) = 0;
            }
        }
        if (*(int *)(p + 0x630)) {
            VObject *o = *(VObject **)(p + 0x62C);
            if (o) {
                VtblEntry *e = &o->vt[3];
                ((void (*)(void *))e->pfn)((char *)o + e->delta);
                func_800665C8(*(void **)(p + 0x62C));
                *(int *)(p + 0x630) = 0;
            }
        }
        if (!m)
            continue;
        if (((unsigned short *)m)[5] == 2) {
            switch (((int *)m)[4]) {
            case 6: {
                void *o;
                *(int *)((char *)D_800B4ED8[0] + 0x278) = 2;
                *(int *)((char *)D_800B4ED8[0] + 0x26C) = 0;
                o = func_800663EC(operator new(0x6C), 1, p, 3, *(int *)(p + 0x618), *(int *)(p + 0x61C));
                *(void **)(p + 0x624) = o;
                func_800665C8(o);
                break;
            }
            case 4:
                *(int *)(p + 0x604) = 1;
                func_800670A4(func_80066FB0(operator new(0x18), p, 0x6D, *(int *)(p + 0x620), 100));
                break;
            case 11: {
                char *o;
                char *vt;
                func_800BE8E0(p);
                o = func_8001CA10(0x14);
                vt = (char *)&D_800102D0_obj;
                *(char **)o = D_80010178;
                *(int *)(o + 4) = 0;
                *(char **)o = D_80010300;
                *(short *)(o + 8) = 2;
                *(short *)(o + 0xA) = 2;
                *(int *)(o + 0x10) = 0;
                *(void **)(o + 0xC) = p;
                *(char **)o = vt;
                func_8001EFE4(p, o);
                o = func_8001CA10(0x14);
                *(char **)o = D_80010178;
                *(int *)(o + 4) = 0;
                *(char **)o = D_80010300;
                *(short *)(o + 8) = 2;
                *(short *)(o + 0xA) = 2;
                *(int *)(o + 0x10) = 1;
                *(void **)(o + 0xC) = p;
                *(char **)o = vt;
                func_8001EFE4(p, o);
                break;
            }
            case 1: {
                char *o;
                char *vt;
                func_800BF094(p);
                func_800BE5EC(p);
                o = func_8001CA10(0x14);
                *(char **)o = D_80010178;
                *(int *)(o + 4) = 0;
                *(char **)o = D_80010300;
                *(short *)(o + 8) = 2;
                *(short *)(o + 0xA) = 9;
                *(int *)(o + 0x10) = 10000;
                *(void **)(o + 0xC) = p;
                vt = (char *)&D_800102D0_obj;
                *(char **)o = vt;
                func_8001EFE4(*(void **)(p + 0x620), o);
                break;
            }
            case 7:
                *(int *)(p + 0x604) = 1;
                func_800BE5E4(p);
                func_800670A4(func_80066FB0(operator new(0x18), p, 0x6E, *(int *)(p + 0x620), 100));
                break;
            case 13:
                func_800BDFE0(p);
                break;
            case 12:
                func_800BEC00(p);
                func_800BEBB0(p);
                *(int *)(p + 0x26C) = 0;
                break;
            }
        }
        {
            VtblEntry *e = &m->vt[2];
            ((void (*)(void *))e->pfn)((char *)m + e->delta);
        }
    }
}
