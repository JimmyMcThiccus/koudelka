// func_80025BE0 / func_80025B44 (u_80025854): image ctor. Everything matches except the S_XY(-1, -1) temporary:
// retail builds it at sp+4 through a `this` register (sh 4(sp); sh 2($v1)) with an unused slot at sp+0
// (frame 0x10; B44: temp at sp+0x14, frame 0x28); this gives one temp at sp+0 (frame 8).
EXTERN_C S_Img *func_80025BE0(S_Img *p, int a, int b)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->unk8 = D_80010888;
    p->vt = D_800108A0;
    p->unkC = a;
    p->unk10 = S_XYc(-1, -1);
    p->unk14.x = 0;
    p->unk14.y = 0;
    p->unk18 = 0;
    p->unk1E = b;
    return p;
}
