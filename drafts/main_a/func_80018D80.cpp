// func_80018D80: allocate from the head free block. Retail copies size into $a1 (an inline helper's
// parameter?) and puts `return 0` in its own block before the epilogue; tried if/else, inline helpers
// (see func_80018C1C's link helper) - best is 23 instructions off, 4 bytes short.
struct S_Block { S_Block *next; unsigned int size; };
extern "C" S_Block *D_800B4EE8;

extern "C" void *func_80018D80(unsigned int size)
{
    S_Block *h, *n;
    size = (((size + 7) >> 3) + 1) << 3;
    h = D_800B4EE8;
    if (h->size < size)
        return 0;
    if (h->size == size) {
        D_800B4EE8 = h->next;
        return h + 1;
    }
    n = (S_Block *)((char *)h + size);
    n->size = h->size - size;
    n->next = h->next;
    D_800B4EE8 = n;
    h->size = size;
    return h + 1;
}
