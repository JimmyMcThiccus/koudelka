// func_80018C90: best-fit malloc over the free list (head block checked last). Same size as retail,
// ~28 instructions differ (branch layout and register choice); not iterated much.
struct S_Block { S_Block *next; unsigned int size; };
extern "C" S_Block *D_800B4EE8;

extern "C" void *func_80018C90(unsigned int size)
{
    S_Block *best = 0;
    S_Block *prev, *c, *n;
    size = (((size + 7) >> 3) + 1) << 3;
    prev = D_800B4EE8;
    for (c = prev->next; c; prev = c, c = c->next) {
        if (c->size >= size && (!best || c->size < best->size)) {
            best = c;
            if (size == c->size) {
                prev->next = c->next;
                return c + 1;
            }
        }
    }
    if (!best) {
        best = D_800B4EE8;
        if (best->size < size)
            return 0;
        if (best->size == size) {
            D_800B4EE8 = best->next;
            return best + 1;
        }
        if (!best)
            return 0;
    }
    best->size -= size;
    n = (S_Block *)((char *)best + best->size);
    n->size = size;
    return n + 1;
}
