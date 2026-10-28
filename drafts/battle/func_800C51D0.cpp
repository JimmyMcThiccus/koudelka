// WIP, not a match: 71 differing instructions (same size 676). Remaining: node address computed from i (not the byte-offset giv), loop reg allocation.
#include "common.h"
#include "battle/battle.h"
struct Q51D0 { char pad[0x4BC]; signed char b4BC; };
struct N51D0 { N51D0 *f0; N51D0 *f4; int pad8; int fC; int f10; Q51D0 *f14; bool isFree() { return fC != 1; } };
struct E51D0 { char b10; char p11; char b12; signed char b13; Q51D0 *f14; unsigned short h18; unsigned short h1A; int pad1C; };
struct L51D0 {
    N51D0 *head; N51D0 *cur; char pad8[8];
    E51D0 e[16]; char pad110[0x1C]; int f12C; N51D0 nodes[10];
};
EXTERN_C void func_800750B8(void *a, void *b);
inline void shift51d0(L51D0 *self) { for (int i = 15; i > 0; i--) self->e[i] = self->e[i - 1]; memset(self->e, 0xFF, 0x10); }
//@ func_800C51D0 E
EXTERN_C void func_800C51D0(L51D0 *self, Q51D0 *q, int n) {
    if (!q) return;
    N51D0 *nd;
    if (n < 0) {
        shift51d0(self);
        int t = self->f12C;
        int team = q->b4BC;
        self->e[0].b10 = 3; self->e[0].b12 = 0; self->e[0].b13 = team; self->e[0].f14 = q;
        unsigned short h = *(unsigned short *)&self->f12C;
        self->e[0].h18 = h; self->e[0].h1A = h;
        nd = 0; for (int i = 0; i < 10; i++) { if (self->nodes[i].isFree()) { self->nodes[i].f4 = &self->nodes[i]; self->nodes[i].f0 = &self->nodes[i]; self->nodes[i].fC = 1; self->nodes[i].f10 = t; self->nodes[i].f14 = q; nd = &self->nodes[i]; break; } }
        func_80075004(self, nd);
    } else {
        shift51d0(self);
        int team = q->b4BC;
        self->e[0].b13 = team; self->e[0].f14 = q;
        self->e[0].b10 = n > 0 ? 1 : 2;
        unsigned short h = *(unsigned short *)&self->f12C;
        self->e[0].b12 = n; self->e[0].h18 = h; self->e[0].h1A = h + n;
        if (n <= 0) n = 1;
        int thr = n + self->f12C;
        nd = 0; for (int i = 0; i < 10; i++) { if (self->nodes[i].isFree()) { self->nodes[i].f4 = &self->nodes[i]; self->nodes[i].f0 = &self->nodes[i]; self->nodes[i].fC = 1; self->nodes[i].f10 = thr; self->nodes[i].f14 = q; nd = &self->nodes[i]; break; } }
        if (!self->head) func_8007505C(self, nd);
        else {
            self->cur = self->head->f4;
            for (;;) {
                if (!(thr < self->cur->f10)) { func_800750B8(self, nd); goto done; }
                if (self->head == self->cur) break;
                if (self->head) self->cur = self->cur->f4;
            }
            func_80075004(self, nd);
        }
    }
done:
    func_800C55C4((T_C55C4 *)self);
}
