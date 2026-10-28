// func_8001AF8C: pool allocator (best fit in 0x4008-byte pools, new pool when all are full). Same size;
// retail keeps best in $a2 / n in $a1 (swapped here) and lays out the split-and-return block right after the
// search loop (here GCC moves it to the end). ~36 instructions differ.
struct S_HeapE { unsigned short next; unsigned short size; };
struct S_Heap { int unk0; int unk4; S_HeapE e[1]; };
static inline S_Heap *newpool_8001AF8C()
{
    S_Heap *p = (S_Heap *)func_8001ACDC(operator new(0x4008));
    D_800B4C04 = func_8001AEFC((S_Link *)D_800B4C04, (S_Link *)p);
    return p;
}

extern "C" void *func_8001AF8C(S_Heap *h, unsigned int size)
{
    S_HeapE *best, *prev, *n;
    for (;;) {
        best = 0;
        if (size >= 0x400)
            return func_80018C90(size);
        size = ((size + 3) >> 2) + 1;
        prev = h->e;
        if (h->e[0].next) {
            do {
                n = &h->e[prev->next];
                if (n->size >= size && (!best || n->size < best->size)) {
                    best = n;
                    if (size == n->size) {
                        prev->next = n->next;
                        return n + 1;
                    }
                }
                prev = n;
            } while (n->next);
        }
        if (!best) {
            size = size * 4 - 4;
            h = (S_Heap *)h->unk4;
            if (!h)
                h = newpool_8001AF8C();
            continue;
        }
        best->size -= size;
        best += best->size;
        best->size = size;
        return best + 1;
    }
}
