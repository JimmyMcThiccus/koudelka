// func_80025880 (u_80025854): image-with-source ctor. 5 instructions differ, all the stack slot of the final
// S_XYc copy: retail has it at sp+0x10 in a 0x18 frame (an unused 8-byte slot between it and the (-1,-1) temp at
// sp+4); this reuses sp+0 (frame 0x10). Types: S_Img/S_XYc in include/game/a/h_u_80025854.h.
EXTERN_C void *D_80010840[];
EXTERN_C void *D_80010858[];
inline void *operator new(unsigned int, void *p) { return p; }
struct S_M20b { void **volatile vt; S_M20b() { vt = D_80010348; } };
struct S_M20 : S_M20b { S_M20() { vt = D_80010840; } };
inline void set_80025880(S_XYc *d, S_XYc v) { *d = v; }
struct S_80025880 {
    void **vt;
    int unk4;
    void **unk8;
    int unkC;
    S_XYc unk10;
    S_XYc unk14;
    int unk18;
    short unk1C;
    short unk1E;
    S_M20 m20;
    S_Img *unk24;
    int unk28;
    int unk2C;
};

EXTERN_C S_80025880 *func_80025880(S_80025880 *p, S_Img *src, int a)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->unk8 = D_80010888;
    p->vt = D_800108A0;
    p->unkC = 0;
    setPos_80025BE0((S_Img *)p, S_XYc(-1, -1));
    new (&p->unk14) S_XYc(0, 0);
    new (&p->m20) S_M20;
    p->vt = D_80010858;
    p->unk18 = 0;
    p->unk1E = 0;
    p->unk8 = D_80010888;
    p->unk24 = src;
    p->unk2C = a;
    S_XYc v = src->unk14;
    char *x = (char *)p + 0x10;
    S_XYc *d = x ? (S_XYc *)(x + 4) : 0;
    *d = v;
    return p;
}
