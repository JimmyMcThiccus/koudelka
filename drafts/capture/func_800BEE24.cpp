// func_800BEE24: retail copies the 4-byte struct returned by func_800C0B7C through two stack temporaries (0x18 -> 0x10 -> 0x18) before passing it by value; GCC here elides them. Same in func_800BED7C.
#include "common.h"
#include "capture/capture.h"

EXTERN_C signed char *func_800C0CB0(void *, int);
EXTERN_C void func_800BF6E8(S_800BF6E8 *p);
EXTERN_C ShortPair func_800C0B7C(void *, int);
EXTERN_C void func_800C0D14(void *, ShortPair);
EXTERN_C void func_800BEE24(void *p, short id)
{
    signed char *e = func_800C0CB0(p, id);
    ShortPair t;
    if (e) {
        func_800BF6E8((S_800BF6E8 *)e);
        t = func_800C0B7C(p, id);
        if (t.b != 0x1000)
            func_800C0D14(p, t);
    }
}
