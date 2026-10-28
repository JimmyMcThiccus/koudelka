// func_8001B0C0: size of an allocated block (pool or system heap). Same size as retail; retail lays out
// the "below this pool -> try next pool" branch as the fall-through, GCC here inverts it (10 instructions).
struct S_HeapE { unsigned short next; unsigned short size; };
struct S_Heap { int unk0; int unk4; S_HeapE e[1]; };
extern "C" int func_80018DF4(int *p);

extern "C" int func_8001B0C0(void *v, void *q)
{
    S_Heap *h = (S_Heap *)v;
    char *p = (char *)q;
    do {
        if (p >= (char *)h->e) {
            if (p < (char *)h + 0x4008)
                goto found;
            break;
        }
        h = (S_Heap *)h->unk4;
    } while (h);
    return func_80018DF4((int *)p);
found:
    if (!p)
        return 0;
    return ((unsigned short *)p)[-1] - 4;
}
