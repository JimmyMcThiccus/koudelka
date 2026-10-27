// func_80025714 (u_80020B70): logic matches; retail reaches D_800B4C54 with the unsplit macro form (lui $a2; lw $a2, %lo($a2)) and no $gp. Declared as a small extern it gets $gp (maspsx_extern registers .extern <= 8); declared incomplete/zero-length, GCC splits the address and the scheduler hoists the lui. Needs a way to keep this one symbol off $gp in this unit (tooling change).
// Declarations: S_VramV {virtual f1..f4; virtual int f5(S_Pt4);}, S_TexImg (see b20 prelude in the batch).
extern "C" void func_80025714(void *q, void *r)
{
#define P ((S_TexImg *)r)
    int s = P->getSize().x + P->getSize().y;
    if (s == 0)
        return;
    if (s <= 64 && ((S_TexImg *)q)->unk4->f5(P->getPos()))
        return;
    D_800B4C54[0]->f5(P->getPos());
#undef P
}
