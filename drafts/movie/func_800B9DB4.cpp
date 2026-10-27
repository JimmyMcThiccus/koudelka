// func_800B9DB4: 41 differing: retail copies xC[] with a 24-byte-per-iteration counted loop (count 1 -> -1); the built struct copy uses a 16-byte loop.
struct M { s32 v[6]; };
struct A { char pad[0xC]; M xC[2]; RECT x3C; RECT x44; };
extern "C" void func_80027FEC(A*, A*);
extern "C" A* func_800B9DB4(A* p, A* q) { s32 i; func_80027FEC(p, q); for (i = 0; i < 2; i++) q->xC[i] = p->xC[i]; q->x3C = p->x3C; q->x44 = p->x44; return q; }
