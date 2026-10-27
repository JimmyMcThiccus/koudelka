// func_800B9DB4: 25 differing: element loop now has g++'s count-down shape; retail has p in $s0 / q in $s1 (swapped) and does the RECT copies through a $v0 copy of q.
struct M { s32 v[6]; };
struct A { char pad[0xC]; M xC[2]; RECT x3C; RECT x44; };
extern "C" void func_80027FEC(A*, A*);
extern "C" A* func_800B9DB4(A* p, A* q) { func_80027FEC(p, q); M* d = q->xC; s32 n = 1; M* s = p->xC; do { *d++ = *s++; } while (--n != -1); q->x3C = p->x3C; q->x44 = p->x44; return q; }
