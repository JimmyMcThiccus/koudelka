// func_800CE910: NOT MATCHING. ~40 instructions: logic is right (compare squared distances, tie-break on Manhattan distance) but retail interleaves the mults and abs() differently.
#include "common.h"
#include "battle/battle.h"
inline int iabs(int x) { return x < 0 ? -x : x; }
EXTERN_C int func_800CE910(SVec2 *a, SVec2 *b, SVec2 *c) { int dx1 = b->x - a->x; int dy1 = b->y - a->y; int dx2 = c->x - a->x; int dy2 = c->y - a->y; int d1 = dx1 * dx1 + dy1 * dy1; int d2 = dx2 * dx2 + dy2 * dy2; int m1 = iabs(dx1) + iabs(dy1); int m2 = iabs(dx2) + iabs(dy2); if (d1 != d2) return d1 - d2; return m1 - m2; }
