// 3 differing: in next() retail materializes empty() (sltiu v0,v1,1; bnez v0) and has `addiu t0,a0,4` in the delay slot of the exit bnez; ours folds to beqz v1 / nop
#include "common.h"
#include "shared/exe.h"
#include "battle/battle.h"
struct T_LNode { T_LNode *next; T_LNode *prev; };
struct T_LIter {
    T_LNode *head; T_LNode *cur; int f8; int fC;
    T_LIter *first() { cur = head; return this; }
    bool empty() { return head == 0; }
    bool last() { return !empty() && head->prev == cur; }
    bool is_last() { if (head == 0) return false; return head->prev == cur; }
    void next() { if (head) { if (!last()) cur = cur->next; } }
};
struct T_C8D9C { int pad0; T_LIter it; };
inline T_C9284 *c8d9c_obj(T_LNode *n) { return n ? (T_C9284 *)((char *)n - 0x4A0) : 0; }
//@ func_800C8D9C best
EXTERN_C int func_800C8D9C(T_C8D9C *p, int side, int *hi, int *lo) {
    if (!p->it.head) return -1;
    int l = 6, h = 0, r;
    switch (side) {
    case 1: r = 2; h = 6; break;
    case 2: r = 1; l = 0; break;
    default: return -1;
    }
    T_LIter *it = p->it.first();
    for (;;) {
        T_C9284 *o = c8d9c_obj(it->cur);
        if (o->b4BD == side && o->s410) {
            int y = o->s4CA;
            l = l < y ? l : y;
            if (y < h) y = h;
            h = y;
        }
        if (p->it.is_last()) break;
        p->it.next();
    }
    *lo = l;
    *hi = h;
    return r;
}
