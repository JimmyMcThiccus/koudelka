// func_80028AE8 (u_80028428): copy the other buffer's DR_MODE/SPRT bodies into the current one. Retail forms element
// pointers (a3/a2) and copies with the block-move scratch regs t0/t1 (then t0/t1/v1/a1); this pointer form has the right
// shape but allocates the pointers to v1/v0 and the scratches to a3/t0.. (39 diffs, 4 bytes long).
struct S_DmX { int tag; S_DmBody b; };
struct S_SpX { int tag; S_SpBody b; };
struct S_Spr2X { void **vt; int unk4; short unk8; short unkA; void **vtC; S_DmX dm[2]; S_SpX sp[2]; };
inline void cpdm(S_DmX *d, S_DmX *s) { d->b = s->b; }
inline void cpsp(S_SpX *d, S_SpX *s) { d->b = s->b; }
EXTERN_C void func_80028AE8(S_Spr2 *q)
{
    S_Spr2X *p = (S_Spr2X *)q;
    int i = D_800B4CF0;
    S_DmX *s = &p->dm[i ^ 1];
    S_DmX *d = &p->dm[i];
    d->b = s->b;
    S_SpX *s2 = &p->sp[i ^ 1];
    S_SpX *d2 = &p->sp[i];
    d2->b = s2->b;
    func_80028184(q);
}
