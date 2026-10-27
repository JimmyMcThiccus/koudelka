// func_8002D780: right shape, 23 diffs in register allocation: retail keeps &p->pos in $s1 (y via 2($s1)) and
// writes ofs straight to the stack; this keeps p in $s1 and writes ofs through $s0. D_800B4CF4 is $gp here.
struct S_Pt2u { short x, y; void set(short ax, short ay) { x = ax; y = ay; } };
EXTERN_C void SetDrawOffset(void *env, void *ofs);
struct S_8002D780 {
    char pad[0x18];
    S_8002D780 *parent;
    char pad1C[0xC];
    S_Pt2u pos;
    int unk2C;
    int unk30;
    char pad34[0x18];
    char d4C[0xC];
    char d58[0xC];
};
EXTERN_C void func_8002D780(S_8002D780 *p, S_Pt2u pos)
{
    S_Pt2u ofs;
    if (p->parent) {
        S_Pt2u t = p->parent->pos;
        ofs.set(pos.x + t.x, pos.y + t.y);
    } else {
        ofs = pos;
    }
    p->pos = ofs;
    if (p->unk30) {
        ofs.set(p->pos.x + D_800B4CF4[0].a, p->pos.y + D_800B4CF4[0].b);
        SetDrawOffset(p->d4C, &ofs);
        ofs.set(p->pos.x + D_800B4CF4[1].a, p->pos.y + D_800B4CF4[1].b);
        SetDrawOffset(p->d58, &ofs);
    } else {
        SetDrawOffset(p->d4C, &p->pos);
        SetDrawOffset(p->d58, &p->pos);
    }
}
