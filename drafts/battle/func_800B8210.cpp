// func_800B8210: 8 differing instructions (scheduling only: addiu a0,0x38 / t1=base / andi-srl of base placed later than retail among the stack stores)
#include "common.h"
#include "battle/battle.h"
struct UVO { unsigned char u, v; short pad; };
struct T_B8210x { char pad[0x38]; UVO e38[4]; char pad48[0x54]; UVH uv9C; };
inline void put_uv(UVO *o, UVH base, UVH uv) {
    o->u = uv.h + base.h;
    o->v = (uv.h >> 8) + (base.h >> 8);
}
//@ func_800B8210 best
EXTERN_C void func_800B8210(T_B8210x *p, UVB *a, UVB *b) {
    UVH base = p->uv9C;
    UVH uv[4];
    uv[0].b = *b;
    uv[1].b.u = b->u;
    uv[1].b.v = a->v;
    uv[2].b.u = a->u;
    uv[2].b.v = b->v;
    uv[3].b = *a;
    UVO *o;
    int i;
    for (i = 0, o = p->e38; i < 4; i++, o++) put_uv(o, base, uv[i]);
}
