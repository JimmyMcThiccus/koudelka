#include "pre.h"
// NONMATCH: 15 diffs, retail copies the head into a separate register (q=v1, prev=a1 set first)
EXTERN_C void func_8008BE08(char *p)
{
    Blk_8008BE08 *b = (Blk_8008BE08 *)(p - 0x10);
    Blk_8008BE08 *prev = 0;
    Blk_8008BE08 *q = FIELD_AT(&D_800B18FC, Blk_8008BE08 *, 0x8);

    while (q != b) {
        prev = q;
        q = prev->next;
    }
    if (prev != 0) {
        prev->next = b->next;
    }
}
