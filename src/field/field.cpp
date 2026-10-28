#include "common.h"
#include "field/field.h"

EXTERN_C Unk_800BA800* func_800BA800(Unk_800BA800* p, Unk_Short2 xy, Unk_800BA800_uv uv, Unk_800BB1BC_arg* q, int a, short b, short c, int, int d) {
    char col[8];
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800111BC;
    p->unk8 = 0;
    p->vtbl = D_800B6DF4;
    p->unk48 = 1;
    p->unkA = c;
    p->unk44 = d;
    func_8002972C(col, 0x80, 0x80, 0x80, 1);
    SetDrawMode(p->unkC, 0, 0, 0, 0);
    SetDrawMode(p->unk18, 0, 0, 0, 0);
    ((unsigned char*)&p->unk24[0].tag)[3] = 3;
    p->unk24[0].code = 0x7C;
    ((unsigned char*)&p->unk24[1].tag)[3] = 3;
    p->unk24[1].code = 0x7C;
    func_800BB1BC((Unk_800BB1BC*)p, q);
    func_800BB068(p, a, b);
    func_800BAC9C((Unk_800BAC9C*)p, xy.x, xy.y);
    func_800BB128((Unk_Sprt16_24*)p, uv.u, uv.v);
    func_800BAED8((Unk_Sprt16_24c*)p, (Unk_ColorSrc*)col);
    if (b) {
        func_80098DC0(&p->unk24[0], 1);
        func_80098DC0(&p->unk24[1], 1);
    } else {
        func_80098DC0(&p->unk24[0], 0);
        func_80098DC0(&p->unk24[1], 0);
    }
    func_800BADB4(p);
    func_800198AC(col, 2);
    return p;
}

EXTERN_C Unk_800BA994* func_800BA994(Unk_800BA994* p) {
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800111BC;
    p->unk8 = 0;
    p->unkA = 0;
    p->vtbl = D_800B6DF4;
    return p;
}

EXTERN_C void func_800BA9CC(Unk_800BA9CC* p, int a) {
    p->vtbl = D_800B6DF4;
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BA9F4);

EXTERN_C int func_800BAAA0(Unk_800BAAA0* p) {
    if (p->unk48 == 0) {
        return 0;
    }
    switch (p->unk8) {
    case 1:
        p->vf09();
    case 2:
        p->unk8--;
    }
    if (p->unk44) {
        addPrimN(p->unkA, &p->unk24[D_800B4CF0[0]]);
        addPrimN(p->unkA, &p->unkC[D_800B4CF0[0]]);
        return 2;
    }
    addPrimN(p->unkA, &p->unk24[D_800B4CF0[0]]);
    return 1;
}

EXTERN_C void func_800BAC9C(Unk_800BAC9C* p, int x, int y) {
    int i;
    if (p->unk8 == 1) {
        p->vf09();
    }
    i = D_800B4CF0[0];
    p->unk24[i].x0 = x;
    p->unk24[i].y0 = y;
    p->unk8 = 2;
}

EXTERN_C void func_800BAD20(Unk_Sprt16_24* p, int dx, int dy) {
    int i;
    if (p->unk8 == 1) {
        p->vf09();
    }
    i = D_800B4CF0[0];
    p->unk24[i].x0 += dx;
    p->unk24[i].y0 += dy;
    p->unk8 = 2;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BADB4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BAE5C);

EXTERN_C void func_800BAED8(Unk_Sprt16_24c* p, Unk_ColorSrc* c) {
    if (p->unk8 == 1) {
        p->vf09();
    }
    p->unk24[D_800B4CF0[0]].r0 = c->unk5;
    p->unk24[D_800B4CF0[0]].g0 = c->unk6;
    p->unk24[D_800B4CF0[0]].b0 = c->unk7;
    p->unk8 = 2;
}

EXTERN_C void func_800BAF74(Unk_Sprt16_24* p, unsigned char* c) {
    if (p->unk8 == 1) {
        p->vf09();
    }
    p->unk24[D_800B4CF0[0]].r0 = c[0];
    p->unk24[D_800B4CF0[0]].g0 = c[1];
    p->unk24[D_800B4CF0[0]].b0 = c[2];
    p->unk8 = 2;
}

EXTERN_C void func_800BB010(Unk_800BB010* p, unsigned char* out) {
    out[0] = p->unk28[D_800B4CF0[0]].unk0;
    out[1] = p->unk28[D_800B4CF0[0]].unk1;
    out[2] = p->unk28[D_800B4CF0[0]].unk2;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB068);

EXTERN_C void func_800BB128(Unk_Sprt16_24* p, int u, int v) {
    if (p->unk8 == 1) {
        p->vf09();
    }
    p->unk24[D_800B4CF0[0]].u0 = u;
    p->unk24[D_800B4CF0[0]].v0 = v;
    p->unk8 = 2;
}

EXTERN_C void func_800BB1BC(Unk_800BB1BC* p, Unk_800BB1BC_arg* a) {
    if (p->unk8 == 1) {
        p->vf09();
    }
    p->unk28[D_800B4CF0[0]].y0 = a->unk8;
    p->unk8 = 2;
}

EXTERN_C void func_800BB230(Unk_800BB230* p) { p->unk48 = 1; }

EXTERN_C void func_800BB23C(Unk_800BB230* p) { p->unk48 = 0; }

EXTERN_C void func_800BB244() { D_800EA0A8[0] = 0; }

EXTERN_C int func_800BB250(Unk_800BB230* p) { return p->unk4; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB25C);

EXTERN_C void func_800BB33C(Unk_800BB33C* p, int a) {
    p->unk8C = D_800B6E9C;
    p->unkF8 = D_800B6E84;
    p->vtbl = D_800B6EB4;
    Unk_800BB33C_t* t = p->unk66C;
    D_800EA0B0[0] = 0;
    if (t) {
        t->unk60 = 1;
        func_80036D8C(p->unk66C);
        p->unk66C = 0;
    }
    if (p->unk674) {
        p->unk674->unk60 = 1;
        func_80036D8C(p->unk674);
        p->unk674 = 0;
    }
    func_800BC0D8((Unk_800BCBE8*)p);
    func_800BC130((Unk_800BCBE8*)p);
    func_800BC18C((Unk_800BCBE8*)p);
    func_800BC1E8((Unk_800BCBE8*)p);
    func_800BFA54((Unk_800BFA54*)p, a);
}

EXTERN_C void func_800BB404(Unk_800BF204* p) {
    p->unk3D8 = 0;
    p->unk3DA = 0;
    func_800C01F8(func_800C0198((Unk_800C0198*)operator new(0x14), p, 0xC9, 0, 0xC8));
    if (p->unk67C) {
        func_8001D324(D_800A4544, func_8001D25C(D_800A4544, p->unk67C));
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB480);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB538);

EXTERN_C int func_800BB5E8(void* q, unsigned char* a) {
    Unk_GrpList* l = &((Unk_GrpOwner*)q)->unk450;
    int c = ((int (*)(void*))func_8001A6E8)(l->unk4);
    Unk_GrpNode* n;
    if (c == 0) {
        return 0;
    }
    for (n = l->unk4; c != 0; c--) {
        Unk_TblIt* it = &n->unkC;
        int k;
        it->unk4 = 0;
        for (k = n->unk30; k != 0; k--) {
            void* x = 0;
            int i = it->unk4;
            if (i < it->unk0->unk4) {
                void** arr = it->unk0->unk0;
                x = arr[i];
                it->unk4 = i + 1;
            }
            func_800BAF74((Unk_Sprt16_24*)x, a);
        }
        n = n->unk4;
    }
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB6B4);

EXTERN_C int func_800BB758(void* p, unsigned char* a) { return func_800BB5E8(p, a) == 1; }

EXTERN_C void func_800BB77C(void* p) {
    func_800670A4(func_80066FB0(operator new(0x18), p, 0x6A, 0, 0));
}

EXTERN_C void func_800BB7C4(Unk_800BCBE8* p) {
    func_800BC228(p);
    p->unk63C = 1;
    func_800670A4(func_80066FB0(operator new(0x18), p, 0x6B, 0, 0x70));
}

EXTERN_C void func_800BB81C(Unk_800BB81C* p) {
    p->unk48C = -((p->unk280 - 320) / 2);
    p->unk490 = -((p->unk282 - 240) / 2);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB85C);

EXTERN_C int func_800BBE68(Unk_800BBE68* p) {
    Unk_800BBE68_q* q = p->unk4DC;
    p->unk100 = q->unk8;
    p->unk101 = q->unk9;
    func_800BD84C(p, q->unkC, p->unk430, p->unk440, p->unk3E8, p->unk410);
    func_800BB81C((Unk_800BB81C*)p);
    func_800BED4C((Unk_800BED4C*)p);
    func_800BEB2C(p);
    func_800BF0E0(p);
    func_800BE470(p, &p->unk450);
    func_800BDEA4(p, &p->unk450);
    Unk_GrpNode* n = (Unk_GrpNode*)&p->unk450;
    int c = ((int (*)(void*))func_8001A6E8)(n->unk4);
    while (n = next_800BBE68(n), c != 0) {
        func_8002DA94(p->unk278->unk254, &n->unkC);
        c--;
    }
    p->unk650 = 0;
    return 1;
}

EXTERN_C int func_800BBF48(Unk_800BCBE8* p) {
    p->unk52C = operator new[](p->unk500);
    func_80025CE0(p->unk52C, p->unk4FC, p->unk500);
    func_8008ECB4(p->unk52C);
    func_80094890(p->unk52C);
    return 1;
}

EXTERN_C int func_800BBFA4(Unk_800BCBE8* p) {
    p->unk530 = operator new[](p->unk508);
    func_80025CE0(p->unk530, p->unk504, p->unk508);
    p->unk538 = func_8008D1F4(p->unk530, 0);
    func_8008C928(16);
    if (p->unk530) {
        operator delete[](p->unk530);
        p->unk530 = 0;
    }
    return 1;
}

EXTERN_C int func_800BC01C(Unk_800BCBE8* p) {
    func_800BC18C(p);
    p->unk534 = operator new[](p->unk520);
    func_80025CE0(p->unk534, p->unk51C, p->unk520);
    p->unk540 = func_8008E360(p->unk534);
    return 1;
}

EXTERN_C int func_800BC074(Unk_800BCBE8* p) {
    func_800BC1E8(p);
    p->unk53C = func_8008D1F4(p->unk524, 0);
    func_80066E04(func_80066DA4(operator new(0x14), p, 0x67, 0, 0x64));
    return 1;
}

EXTERN_C int func_800BC0D8(Unk_800BCBE8* p) {
    if (p->unk52C) {
        func_8008ED44(p->unk52C);
        if (p->unk52C) {
            operator delete[](p->unk52C);
        }
        p->unk52C = 0;
    }
    return 1;
}

EXTERN_C int func_800BC130(Unk_800BCBE8* p) {
    if (p->unk530) {
        operator delete[](p->unk530);
        p->unk530 = 0;
    }
    if (p->unk538) {
        func_8008D4C0(p->unk538);
        p->unk538 = 0;
    }
    return 1;
}

EXTERN_C int func_800BC18C(Unk_800BCBE8* p) {
    if (p->unk540) {
        func_8008E504(p->unk540);
        p->unk540 = 0;
    }
    if (p->unk534) {
        operator delete[](p->unk534);
        p->unk534 = 0;
    }
    return 1;
}

EXTERN_C int func_800BC1E8(Unk_800BCBE8* p) {
    if (p->unk53C) {
        func_8008D4C0(p->unk53C);
        p->unk53C = 0;
    }
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BC228);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BC2B0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BC320);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BC394);

EXTERN_C int func_800BC500(Unk_800BC500* p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        Unk_Tbl* t = (Unk_Tbl*)first2(&p->unk5E0);
        Unk_Deletable* o = t->unk4 ? (Unk_Deletable*)t->unk0[t->unk4 - 1] : 0;
        if (!o) {
            break;
        }
        func_80019CFC(first2(&p->unk5E0), o);
        delete o;
    }
    return i;
}

EXTERN_C void func_800BC5F0(Unk_800BC5F0* p) {
    Unk_800BC5F0_sub* s = &p->unk494;
    if (s->unk4) {
        delete s->unk4;
        s->unk4 = 0;
    }
}

EXTERN_C void func_800BC640(Unk_800BC640* p) {
    clear(&p->unk3E8);
    clear(&p->unk410);
    clear(&p->unk430);
    clear(&p->unk440);
    clear(&p->unk450);
    p->unk3D8 = 0;
    p->unk3DA = 0;
}

EXTERN_C void func_800BC774(Unk_800BF204* p, short id) {
    Unk_800BD3E0* q = func_800BE200(p, id);
    if (q && q->unkC == 0) {
        func_800BD3E0(q, 1);
    }
}

EXTERN_C void func_800BC7BC(Unk_800BF204* p, short a) {
    Unk_800BD3E0* o = func_800BE200(p, a);
    if (o) {
        Unk_Short2 v;
        o->unk18 = 0;
        o->unk14 = o->unk10;
        v = func_800BE0C8(p, a);
        if (v.y != 0x1000) {
            func_800BE264(p, Unk_Short2(v));
        }
    }
}

EXTERN_C void func_800BC864(Unk_800BF204* p, short a) {
    Unk_800BD3E0* o = func_800BE200(p, a);
    if (o) {
        Unk_Short2 v;
        func_800BD3A8(o);
        v = func_800BE0C8(p, a);
        if (v.y != 0x1000) {
            func_800BE264(p, Unk_Short2(v));
        }
    }
}

EXTERN_C void func_800BC908(Unk_800BF204* p, short id) {
    Unk_800BD3E0* q = func_800BE200(p, id);
    if (q && q->unkC == 1) {
        func_800BD410(q);
    }
}

EXTERN_C void func_800BC950(Unk_800BF204* p, short id) {
    Unk_800BD3E0* q = func_800BE200(p, id);
    int ok = 0;
    if (q && q->unk20 == 1) {
        ok = q->unkC != 0;
    }
    if (ok) {
        func_800BD3FC(q);
    }
}

EXTERN_C void func_800BC9AC(Unk_800BF204* p, short id, int a) {
    Unk_800BD3E0* q = func_800BE200(p, id);
    if (q) {
        func_800BD468(q, a);
    }
}

EXTERN_C int func_800BC9E8(Unk_800BF204* p, short id) {
    Unk_800BD3E0* q = func_800BE200(p, id);
    if (q) {
        return q->unkC;
    }
    return 0xFF;
}

EXTERN_C int func_800BCA20(Unk_800BF204* p, short id) {
    Unk_800BD3E0* q = func_800BE200(p, id);
    if (q) {
        return q->unk20;
    }
    return 0xFF;
}

EXTERN_C void func_800BCA58() { func_8007F5B8(func_800787B4(), 0, 0); }

EXTERN_C void func_800BCA88(void* p) {
    Unk_800BCA88* o = (Unk_800BCA88*)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010300;
    o->unk8 = 2;
    o->unkA = 2;
    o->unkC = p;
    o->unk10 = 13;
    o->vtbl = D_800102D0;
    func_8001EFE4(p, o);
}

EXTERN_C void func_800BCAFC(Unk_800BCBE8* p) {
    unsigned char c[3];
    Unk_800BCDB0* o;
    func_800BC640((Unk_800BC640*)p);
    func_800BC0D8(p);
    func_800BC130(p);
    func_800BBE68((Unk_800BBE68*)p);
    func_800BBF48(p);
    func_800BBFA4(p);
    c[0] = 0x80;
    c[1] = 0x80;
    c[2] = 0x80;
    func_800BB5E8(p, c);
    if (((Unk_800BCAFC*)p)->unk668 || ((Unk_800BCAFC*)p)->unk654) {
        func_800BC5F0((Unk_800BC5F0*)p);
        func_800BC2B0(p);
    }
    o = (Unk_800BCDB0*)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010300;
    o->unk8 = 2;
    o->unkA = 2;
    o->unk10 = 0xE;
    o->unkC = (int)p;
    o->vtbl = D_800102D0;
    func_8001EFE4(p, o);
}

EXTERN_C int func_800BCBE8(Unk_800BCBE8* p, Unk_Pair* out) {
    *out = p->unk4EC;
    return 1;
}

EXTERN_C int func_800BCC00(Unk_800BCBE8* p, Unk_Pair* out) {
    *out = p->unk4F4;
    return 1;
}

EXTERN_C int func_800BCC18(Unk_800BCBE8* p, Unk_Pair* out) {
    *out = p->unk50C;
    return 1;
}

EXTERN_C int func_800BCC30(Unk_800BCBE8* p, Unk_Pair* out) {
    *out = p->unk514;
    return 1;
}

EXTERN_C int func_800BCC48(void* p) {
    Unk_800BCA88* o = (Unk_800BCA88*)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010300;
    o->unk8 = 2;
    o->unkA = 2;
    o->unkC = p;
    o->unk10 = 1;
    o->vtbl = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C int func_800BCCC0(void* p) {
    Unk_800BCA88* o = (Unk_800BCA88*)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010300;
    o->unk8 = 2;
    o->unkA = 2;
    o->unkC = p;
    o->unk10 = 10;
    o->vtbl = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C int func_800BCD38(void* p) {
    Unk_800BCA88* o = (Unk_800BCA88*)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010300;
    o->unk8 = 2;
    o->unkA = 2;
    o->unkC = p;
    o->unk10 = 12;
    o->vtbl = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C int func_800BCDB0(int a, void* list, int c) {
    Unk_800BCDB0* o = (Unk_800BCDB0*)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010300;
    o->unk8 = 2;
    o->unkA = 9;
    o->unk10 = c;
    o->unkC = a;
    o->vtbl = D_800102D0;
    func_8001EFE4(list, o);
    return 1;
}

EXTERN_C int func_800BCE40(void* p) {
    func_800C01F8(func_800C0198((Unk_800C0198*)operator new(0x14), p, 0xCA, 0, 0xC8));
    return 1;
}

EXTERN_C int func_800BCE90(void* p) {
    Unk_800BCA88* o = (Unk_800BCA88*)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010300;
    o->unk8 = 2;
    o->unkA = 2;
    o->unkC = p;
    o->unk10 = 11;
    o->vtbl = D_800102D0;
    func_8001EFE4(p, o);
    return 1;
}

EXTERN_C void func_800BCF08(void* p, short a, int b) {
    func_800BF66C(func_800BF624((Unk_800BF624*)operator new(0x10), p, b, a));
}

EXTERN_C int func_800BCF68(Unk_800BCBE8* p) { return p->unk664; }

EXTERN_C int func_800BCF74(Unk_800BCBE8* p) { return p->unk654; }

EXTERN_C void func_800BCF80(Unk_800BCBE8* p) { p->unk644 = 1; }

EXTERN_C void func_800BCF8C(Unk_800BCBE8* p) { p->unk644 = 0; }

EXTERN_C int func_800BCF94(Unk_800BCBE8* p) { return p->unk644; }

EXTERN_C int func_800BCFA0(Unk_800BCBE8* p) { return p->unk64C; }

EXTERN_C void func_800BCFAC(Unk_800BCBE8* p) { p->unk64C = 0; }

EXTERN_C void func_800BCFB4(Unk_800BCBE8* p) { p->unk64C = 1; }

EXTERN_C int func_800BCFC0() { return D_800EA0B0[0]; }

EXTERN_C Unk_800BCFD0* func_800BCFD0(Unk_800BCFD0* p, int a) {
    p->vtbl = D_800B6ECC;
    p->unk4 = a;
    return p;
}

EXTERN_C void func_800BCFE8(Unk_800BA9CC* p) {
    p->vtbl = D_800B6ECC;
    func_8001D024(p);
}

EXTERN_C int func_800BD010(void* p) {
    char* l = D_800A4544;
    Unk_800BD010* o = (Unk_800BD010*)operator new(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010338;
    o->unk8 = p;
    o->unkC = 0x80;
    o->unk10 = 1;
    func_8001D150(l, o);
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BD088);

EXTERN_C Unk_800BD3E0* func_800BD1D8(Unk_800BD3E0* p) {
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800B6EE4;
    p->unk8 = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
    p->unk20 = 1;
    return p;
}

C_800BD220::C_800BD220(short a, short n, signed char c) {
    vtbl = D_80010178;
    unk4 = 0;
    vtbl = D_800B6EE4;
    unkA = n;
    unk8 = a;
    unkC = c;
    unk14 = unk10 = operator new[](n * 4);
    unk18 = 0;
    unk1C = 0;
    unk24 = 0;
    unk20 = 1;
}

EXTERN_C void func_800BD298(Unk_800BD3E0* p, int a) {
    p->vtbl = D_800B6EE4;
    if (p->unk10) {
        operator delete[](p->unk10);
    }
    func_8001A610(p, a);
}

EXTERN_C void func_800BD2EC(Unk_800BD3E0* p, short a, short b) {
    if (p->unk1C < p->unkA) {
        Unk_800BD2EC* e = &p->unk10[p->unk1C];
        e->unk0 = a;
        e->unk2 = b;
        p->unk1C++;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BD330);

EXTERN_C void func_800BD3A8(Unk_800BD3E0* p) {
    while (!atLast(p)) {
        p->unk18++;
        p->unk14++;
    }
}

EXTERN_C void func_800BD3E0(Unk_800BD3E0* p, signed char a) {
    p->unk20 = p->unkC;
    p->unkC = a;
    p->unk18 = 0;
    p->unk14 = p->unk10;
}

EXTERN_C void func_800BD3FC(Unk_800BD3E0* p) {
    p->unkC = p->unk20;
    p->unk20 = 1;
}

EXTERN_C void func_800BD410(Unk_800BD3E0* p) {
    if (p->unk20 == 1 && p->unkC == 1) {
        p->unkC = 2;
    }
}

EXTERN_C void func_800BD43C(Unk_800BD3E0* p) {
    if (p->unk20 == 1 && p->unkC == 2) {
        p->unkC = 1;
    }
}

EXTERN_C void func_800BD468(Unk_800BD3E0* p, int a) {
    p->unkC = a;
    p->unk20 = 1;
}

EXTERN_C Unk_800BD2EC* func_800BD478(Unk_800BD3E0* p) { return p->unk14; }

EXTERN_C void func_800BD484(Unk_800BD3E0* p) {
    p->unk18 = 0;
    p->unk14 = p->unk10;
}

EXTERN_C signed char func_800BD494(Unk_800BD3E0* p) { return p->unk20; }

EXTERN_C void func_800BD4A0(Unk_800BD3E0* p, char a) { p->unk20 = a; }

EXTERN_C signed char func_800BD4A8(Unk_800BD3E0* p) { return p->unkC; }

EXTERN_C short func_800BD4B4(Unk_800BD3E0* p) { return p->unkA; }

EXTERN_C short func_800BD4C0(Unk_800BD3E0* p) { return p->unk8; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BD4CC);

EXTERN_C void func_800BD62C(void* q, int a) {
    Unk_800BD62C* p = (Unk_800BD62C*)q;
    p->unk8C = D_800B6F0C;
    p->unkF8 = D_800B6EF4;
    p->vtbl = D_800B6F24;
    func_80019920(p->unk5E0, 0);
    func_800BF8AC((Unk_800BF8AC*)p->unk494, 2);
    func_800C03CC((Unk_800C03CC*)p->unk450, 2);
    func_800C05D4((Unk_800BF4B8*)p->unk440, 2);
    func_800BF4B8((Unk_800BF4B8*)p->unk430, 2);
    func_800BF35C((Unk_800BF420*)p->unk410, 2);
    func_800BD298((Unk_800BD3E0*)p->unk3E8, 2);
    func_80051514(&p->unkF8, 0);
    func_8001E508(p, a);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BD6E8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BD84C);

EXTERN_C int func_800BDD8C(Unk_800BDD8C* p, signed char a) {
    Unk_800BDD8C_node* n = p->unk434;
    while (active(p)) {
        if (a == func_800BF5F4((Unk_800BF488*)n)) {
            return n->unkC;
        }
        n = n->unk4;
    }
    return 0;
}

EXTERN_C int func_800BDE08(Unk_800BF204* p, signed char id) {
    Unk_800BDE08_node* n = p->unk444;
    for (signed char i = p->unk100; i != 0; i--) {
        if (id == n->unk8) {
            return n->unkC;
        }
        n = next(n);
    }
    return 0;
}

EXTERN_C int func_800BDE58(Unk_800BF204* p, signed char id) {
    Unk_800BDE58_node* n = p->unk414;
    for (short i = p->unk3D8; i != 0; i--) {
        if (id == n->unk8) {
            return n->unk18;
        }
        n = next(n);
    }
    return 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BDEA4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BDF74);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BE0C8);

EXTERN_C Unk_800BD3E0* func_800BE200(Unk_800BF204* p, int id) {
    Unk_800BD3E0* n = p->unk3EC;
    for (short i = func_8001A6E8(n); i != 0; i--) {
        if (id == n->unk8) {
            break;
        }
        n = next(n);
    }
    return n;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BE264);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BE470);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BE7EC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BEB2C);

EXTERN_C void func_800BED4C(Unk_800BED4C* p) {
    int n = p->unk28C;
    int i;
    for (i = 0; i < n; i++) {
        Unk_V3 v;
        v.x = p->unk2B4[i].b[0] - p->unk2B4[i].a[0];
        v.y = p->unk2B4[i].b[1] - p->unk2B4[i].a[1];
        v.z = p->unk2B4[i].b[2] - p->unk2B4[i].a[2];
        VectorNormal(&v, (char*)p + 0x32C + i * 16);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BEDF8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF0E0);

EXTERN_C void* func_800BF204(Unk_800BF204* p) { return p->unk544; }

EXTERN_C Unk_800BF20C* func_800BF20C(Unk_800BF204* p, int i) { return &p->unk568[i]; }

EXTERN_C short func_800BF224(Unk_800BF204* p) { return p->unk28C; }

EXTERN_C short func_800BF230(Unk_800BF204* p) { return p->unk3DA; }

EXTERN_C void func_800BF23C(Unk_800BF204* p, char a) { p->unk101 = a; }

EXTERN_C void func_800BF244(Unk_800BF204* p, char a) { p->unk100 = a; }

EXTERN_C void* func_800BF24C(Unk_800BF204* p) { return p->unk450; }

EXTERN_C void* func_800BF254(Unk_800BF204* p) { return p->unk494; }

EXTERN_C int func_800BF25C(Unk_800BF204* p) { return p->unk278; }

EXTERN_C Unk_800BF420* func_800BF268(Unk_800BF420* p) {
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800B6F3C;
    p->unk8 = 0xEFEFEFEF;
    p->unkC = 0xEFEFEFEF;
    p->unk10 = 0xEF;
    p->unk11 = 0xEF;
    p->unk12 = 0xEFEF;
    p->unk14 = 0xEFEF;
    p->unk1C = 0xEF;
    p->unk18 = 0;
    return p;
}

C_800BF2C0::C_800BF2C0(Unk_800BF2C0_src* s) {
    vtbl = D_80010178;
    unk4 = 0;
    vtbl = D_800B6F3C;
    unk8 = s->unk0;
    unkC = s->unk4;
    unk10 = s->unk8;
    unk11 = s->unk9;
    unk12 = s->unkA;
    unk14 = s->unkC;
    unk1C = 0;
    unk18 = operator new[](unk14 * 8);
}

EXTERN_C void func_800BF35C(Unk_800BF420* p, int a) {
    p->vtbl = D_800B6F3C;
    if (p->unk18) {
        operator delete[](p->unk18);
    }
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF3B0);

EXTERN_C int func_800BF420(Unk_800BF420* p) { return p->unk12 != 0; }

EXTERN_C void* func_800BF42C(Unk_800BF420* p) { return p->unk18; }

EXTERN_C int func_800BF438(Unk_800BF420* p) { return p->unk1C; }

EXTERN_C void func_800BF444(Unk_800BF420* p, int a) { p->unk1C = a; }

EXTERN_C short func_800BF44C(Unk_800BF420* p) { return p->unk14; }

EXTERN_C signed char func_800BF458(Unk_800BF420* p) { return p->unk11; }

EXTERN_C signed char func_800BF464(Unk_800BF420* p) { return p->unk10; }

EXTERN_C int func_800BF470(Unk_800BF420* p) { return p->unkC; }

EXTERN_C int func_800BF47C(Unk_800BF420* p) { return p->unk8; }

EXTERN_C Unk_800BF488* func_800BF488(Unk_800BF488* p, signed char a, short b) {
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800B6F4C;
    p->unk8 = a;
    p->unkA = b;
    p->unkC = 0;
    return p;
}

EXTERN_C void func_800BF4B8(Unk_800BF4B8* p, int a) {
    p->vtbl = D_800B6F4C;
    if (p->unkC) {
        delete p->unkC;
    }
    func_8001A610(p, a);
}

EXTERN_C void func_800BF520(Unk_800BF520* p, int a) {
    Unk_800BF520_o* o = (Unk_800BF520_o*)operator new(0x20C);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_800106EC;
    o->unk8 = 0;
    o->unkA = 0;
    o->vtbl = D_80010624;
    func_80021F48(o, a);
    VAt<0x10>* g = (VAt<0x10>*)D_800B4C38[0];
    p->unkC = o;
    g->vf00(o);
    p->unkA = p->unkC->unk8;
}

EXTERN_C int func_800BF5D8(Unk_800BF488* p) {
    int r;
    if (p->unkC == 0) {
        r = 0;
    } else {
        r = p->unkA;
    }
    return r;
}

EXTERN_C signed char func_800BF5F4(Unk_800BF488* p) {
    int r;
    if (p->unkC == 0) {
        r = 0;
    } else {
        r = p->unk8;
    }
    return r;
}

EXTERN_C int func_800BF610(Unk_800BF488* p) { return p->unkC; }

EXTERN_C void func_800BF61C(Unk_800BF488* p, char a) { p->unk8 = a; }

EXTERN_C Unk_800BF624* func_800BF624(Unk_800BF624* p, void* a, int b, short c) {
    p->vtbl = D_800B6F74;
    p->unk4 = a;
    p->unk8 = b;
    p->unkC = c;
    return p;
}

EXTERN_C void func_800BF644(Unk_800BA9CC* p) {
    p->vtbl = D_800B6F74;
    func_8001D024(p);
}

EXTERN_C int func_800BF66C(void* p) {
    char* l = D_800A4544;
    Unk_800BD010* o = (Unk_800BD010*)operator new(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010338;
    o->unk8 = p;
    o->unkC = 0x80;
    o->unk10 = 1;
    func_8001D150(l, o);
    return 1;
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6E84);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6E9C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6EB4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6ECC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6EE4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6EF4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6F0C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6F24);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6F3C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6F4C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF6E4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF7C0);

EXTERN_C void func_800BF8AC(Unk_800BF8AC* p, int a) {
    p->vtbl8 = D_800B6F8C;
    p->vtbl = D_800B6FF4;
    p->vtbl8 = D_80011C44;
    p->vtbl = D_80011CAC;
    p->vtbl8 = D_80011B8C;
    p->vtbl = D_80011BF4;
    p->vtbl8 = D_80011AAC;
    p->vtbl = D_80011B14;
    func_800198AC(&p->vtbl8, 0);
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF950);

EXTERN_C int func_800BF9BC() { return 0; }

EXTERN_C void func_800BF9C4(Unk_800BF9BC* p, int a) { p->unk44 = a; }

EXTERN_C int func_800BF9CC(Unk_800BF9BC* p) { return p->unk44; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF9D8);

EXTERN_C void func_800BFA54(Unk_800BFA54* p, int a) {
    p->unk8C = D_800B706C;
    p->unkF8 = D_800B7054;
    p->vtbl = D_800B7084;
    func_80019920(p->unk610, 0);
    func_800BFE94((Unk_800BFE48*)p, a);
}

EXTERN_C int func_800BFABC(Unk_800BF9BC* p, int a) {
    Unk_800BFB64_node* n = first(&p->unk610);
    func_80019A6C(n, a, n->unk4);
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BFAF8);

EXTERN_C int func_800BFB64(Unk_800BF9BC* p) { return first(&p->unk610)->unk4; }

EXTERN_C int func_800BFB84(Unk_800BFB84* p, int a, Unk_W4* out) {
    Unk_800BFC58_r* r;
    p->unk630 = r = (Unk_800BFC58_r*)func_80019F64(first2(&p->unk610), a);
    if (r && r->unk1B8) {
        *out = get_800BFB84(&r->unk1B8->unk34);
        return 1;
    }
    return 0;
}

EXTERN_C int func_800BFC58(Unk_800BFC58* p, int a, Unk_W4* out) {
    Unk_800BFC58_r* r;
    p->unk630 = r = (Unk_800BFC58_r*)func_80019F64(first(&p->unk610), a);
    if (r && r->unk1B8) {
        *out = r->unk1B8->unk34;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800BFCEC(Unk_800BFCEC* p, int a, Unk_W4* in) {
    Unk_800BFCEC_r* r;
    p->unk630 = r = (Unk_800BFCEC_r*)func_80019F64(first(&p->unk610), a);
    if (r) {
        Unk_800BFC58_s* s = r->unk1B8;
        if (s) {
            s->unk34 = *in;
            func_80039DD8(s);
            return 1;
        }
        return 0;
    }
    return 0;
}

EXTERN_C int func_800BFD88(Unk_800BFD88* p, int a, short* out) {
    Unk_800BFD88_r* r;
    p->unk630 = r = (Unk_800BFD88_r*)func_80019F64(first(&p->unk610), a);
    if (r && r->unk1B8) {
        *out = r->unk1BC;
        return 1;
    }
    *out = -1;
    return 0;
}

EXTERN_C void func_800BFE0C(Unk_800BF9BC* p) { func_80019D40(first(&p->unk610)); }

EXTERN_C void* func_800BFE40(Unk_800BF9BC* p) { return &p->unk610; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BFE48);

EXTERN_C void func_800BFE94(Unk_800BFE48* p, int a) {
    p->unk8C = D_800B70B4;
    p->unkF8 = D_800B709C;
    p->vtbl = D_800B70CC;
    func_800BD62C(p, a);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BFED4);

EXTERN_C int func_800C0054(Unk_800C0054* p, int a, int b) {
    Unk_800C0054_node* n = p->unk498;
    if (!n) {
        return 0;
    }
    a <<= 8;
    while (n) {
        if (a == (n->unk44 & 0xF00)) {
            n->unk16 += b;
        }
        n = next(n);
    }
    return 1;
}

EXTERN_C int func_800C00AC(Unk_800C0054* p, int a, int b, int c) {
    Unk_800C0054_node* n = p->unk498;
    if (!n) {
        return 0;
    }
    a <<= 8;
    c &= 0xFFFF0000;
    while (n) {
        if (a == (n->unk44 & 0xF00)) {
            n->unk44 = c;
            n->unk16 += b;
        }
        n = next(n);
    }
    return 1;
}

EXTERN_C int func_800C010C(Unk_800C0054* p, int a, int b) {
    Unk_800C0054_node* n = p->unk498;
    if (!n) {
        return 0;
    }
    a <<= 8;
    while (n) {
        if (a == (n->unk44 & 0xF00)) {
            switch (b) {
            case 2:
                n->unk44 |= 0x80000000;
                break;
            case 3:
                n->unk44 &= 0x7FFFFFFF;
                break;
            }
        }
        n = next(n);
    }
    return 1;
}

EXTERN_C void func_800C0188() {}

EXTERN_C void func_800C0190() {}

EXTERN_C Unk_800C0198* func_800C0198(Unk_800C0198* p, void* a, int b, void* c, int d) {
    p->vtbl = D_800B70E4;
    p->unk4 = a;
    p->unkC = b;
    p->unk8 = c;
    if (!p->unk8) {
        p->unk8 = p->unk4;
    }
    p->unk10 = d;
    return p;
}

EXTERN_C void func_800C01D0(Unk_800BA9CC* p) {
    p->vtbl = D_800B70E4;
    func_8001D024(p);
}

EXTERN_C int func_800C01F8(void* p) {
    char* l = D_800A454C;
    Unk_800BD010* o = (Unk_800BD010*)operator new(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010338;
    o->unk8 = p;
    o->unkC = 0x80;
    o->unk10 = 1;
    func_8001D150(l, o);
    return 1;
}

EXTERN_C int func_800C0270(Unk_800C0270* p) {
    int v = p->unkC;
    void* o;
    if (v == 200) {
        return 1;
    }
    o = p->unk4;
    switch (v) {
    case 201:
        if (func_800C02FC((Unk_800C02FC*)p, 30)) {
            return 0;
        }
        func_800BCE40(o);
        return 1;
    case 202:
        if (func_800C0320((Unk_800C02FC*)p, 30)) {
            return 0;
        }
        func_800BCE90(o);
        return 1;
    }
    return 0;
}

EXTERN_C int func_800C02FC(Unk_800C02FC* p, int) { return func_800BC394(p->unk4); }

EXTERN_C int func_800C0320(Unk_800C02FC* p, int a) { return func_800BC500((Unk_800BC500*)p->unk4, a); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C0344);

EXTERN_C void func_800C03CC(Unk_800C03CC* p, int a) {
    p->vtbl = D_800B70FC;
    func_800C04A0(p->unk14);
    func_80019920(p->unkC, 0);
    func_8001A610(p, a);
}

EXTERN_C void func_800C0424(Unk_800C0424* p, Unk_800C0424_node* n) {
    if (p->unk34) {
        while (n) {
            Unk_800BFB64_node* h = first(&p->unkC);
            func_80019A6C(h, (int)n, h->unk4);
            n = next(n);
        }
        p->unk34 = 0;
        p->unk38 = 0;
    }
}

EXTERN_C void func_800C04A0(void* q) {
    Unk_800BFB64_list* l = (Unk_800BFB64_list*)q;
    int n;
    while ((n = first(l)->unk4) != 0) {
        n--;
        delete (Unk_Deletable*)func_80019F64(first(l), n);
        func_80019C68(first(l), n);
    }
}

EXTERN_C int func_800C0540(Unk_800C0540* p) { return p->unk38; }

EXTERN_C void* func_800C054C(Unk_800C0540* p) { return p->unkC; }

EXTERN_C short func_800C0554(Unk_800C0540* p) { return p->unk2C; }

EXTERN_C void func_800C0560(Unk_800C0540* p, short a) { p->unk2C = a; }

EXTERN_C int func_800C0568(Unk_800C0540* p) { return p->unk30; }

EXTERN_C void func_800C0574(Unk_800C0540* p) { p->unk30--; }

EXTERN_C void func_800C0588(Unk_800C0540* p, int a) { p->unk30 = a; }

EXTERN_C short func_800C0590(Unk_800C0540* p) { return p->unk8; }

EXTERN_C void func_800C059C(Unk_800C0540* p, short a) { p->unk8 = a; }

EXTERN_C Unk_800C07E0* func_800C05A4(Unk_800C07E0* p) {
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800B710C;
    p->unk8 = 0;
    p->unkA = 0;
    p->unkC = 0;
    return p;
}

EXTERN_C void func_800C05D4(Unk_800BF4B8* p, int a) {
    p->vtbl = D_800B710C;
    if (p->unkC) {
        func_80024FEC(p->unkC, 0);
        delete p->unkC;
    }
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C0654);

EXTERN_C int func_800C07E0(Unk_800C07E0* p) { return p->unkC; }

EXTERN_C void func_800C07EC(Unk_800C07E0* p, char a) { p->unk8 = a; }

EXTERN_C void func_800C07F4(Unk_800C07E0* p, unsigned short a) { p->unkA = a; }

EXTERN_C signed char func_800C07FC(Unk_800C07E0* p) { return p->unk8; }

EXTERN_C unsigned short func_800C0808(Unk_800C07E0* p) { return p->unkA; }

EXTERN_C void func_800C0814(int a, int b) {
    if (b) {
        func_800C9E48(&D_800EA0B8[0]->unk6C);
    } else {
        func_800C9D60(&D_800EA0B8[0]->unk6C, a);
    }
}

EXTERN_C void func_800C0860(int a) { func_800C20B0(D_800EA0B8[0]->unk70A0, a); }

EXTERN_C void func_800C0890(int a) {
    if (a) {
        func_800C1AF0(D_800EA0B8[0]);
    } else {
        func_800C1BB8(D_800EA0B8[0]);
    }
}

EXTERN_C int func_800C08D4(int a) {
    if (func_800C9DD4(&D_800EA0B8[0]->unk6C)) {
        return func_800C1A74(D_800EA0B8[0], a);
    }
    return 0;
}

EXTERN_C void func_800C0920() { func_800C1000(D_800EA0B8[0]); }

EXTERN_C void func_800C0948() { func_800553D8(0); }

EXTERN_C void func_800C0968() {
    func_800557C8((char*)D_800EA0B8[0] + 0x25C, 1, 0);
    func_800D6D44((Unk_800CD3C8*)((char*)D_800EA0B8[0] + 0x65DC));
    func_800C2A0C((Unk_800C2A0C*)((char*)D_800EA0B8[0] + 0x3D18));
    func_800C56B8((char*)D_800EA0B8[0] + 0x958);
    func_800C6CCC((Unk_800C6CCC*)((char*)D_800EA0B8[0] + 0x69A8));
    func_800C3AAC((Unk_800C3AAC*)((char*)D_800EA0B8[0] + 0x68C0));
    func_800CD3C8((Unk_800CD3C8*)((char*)D_800EA0B8[0] + 0x438));
    func_800C88D8((Unk_800C88D8*)((char*)D_800EA0B8[0] + 0x6A8C));
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6F74);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6F8C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6FF4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7054);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B706C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7084);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B709C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B70B4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B70CC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B70E4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B70FC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B710C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C09F0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C0C8C);

EXTERN_C void func_800C1000(Unk_800C0814* q) {
    Unk_800C1000* p = (Unk_800C1000*)q;
    if (--p->unk68 == 0) {
        int i;
        func_80054FE0(p);
        func_800C9D20(&p->unk6C);
        func_800C1BB8(q);
        func_8002B27C(D_800A4578[0], p->unk70A0);
        p->unk70A0 = 0;
        for (i = first((Unk_800BFB64_list*)&p->unk23C)->unk4 - 1; i >= 0; i--) {
            delete (Unk_Deletable18*)func_80019F64(first2(&p->unk23C), i);
        }
        func_80019D40(first((Unk_800BFB64_list*)&p->unk23C));
        func_800CF830();
        func_800D0248();
        func_800553D8(0);
        func_8008EF40(0x11);
    }
}

EXTERN_C void func_800C1120(char* p) {
    Unk_EntTabObj* o = ((Unk_EntOwner*)func_800787B4())->unk328;
    int k = D_800B4D5C[0];
    Unk_800C1120_e* e = (Unk_800C1120_e*)base(o)->unk8[k];
    if (D_800EA0B4[0] != 0) {
        func_80054094(p + 0x25C, e->vf09(0) == 0);
    } else {
        D_800EA0B4[0] = 1;
    }
    func_80054CE4(p);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C11BC);

EXTERN_C void func_800C13E4(Unk_800C13E4* p) {
    func_80056874(p);
    func_80055330(0);
    p->unk68 -= 0x10;
    func_800BB7C4(func_800787B4()->unk380);
}

EXTERN_C void func_800C1430(int, Unk_Short2) {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1438);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1628);

EXTERN_C void func_800C16DC(Unk_800C16DC* p, int a) {
    if (a == 0) {
        Unk_Short4 v(0, 0);
        v.z = 0;
        v.w = 0;
        func_80054F30(p, 9, &v, -8);
        func_80054F5C(p);
    } else {
        func_80054094(p->unk958, func_800619F4(D_800B4DD0[0]) < 1);
        func_80054094(p->unk69A8, ((Unk_800C16DC_g*)D_800B4DD0[0])->unk1FD < 1);
        func_800C20B0(p->unk70A0, 1);
        Unk_Short4 v(0, 0);
        v.z = 0;
        v.w = 0;
        func_80054F30(p, 9, &v, 8);
        func_80054FC0(p);
        p->vf04();
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C17C0);

EXTERN_C int func_800C1A74(Unk_800C0814* q, int a) {
    Unk_800C1A74* p = (Unk_800C1A74*)q;
    if (a == 0) {
        func_800C9E04(&p->unk6C);
    } else if (func_800C9EE8((Unk_800C9D90*)&p->unk6C, (Unk_FlagArg*)a)) {
        if (p->unk3C->unk20 != 0) {
            p->vf04();
        }
        return 1;
    } else {
        return 0;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1AF0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1BB8);

EXTERN_C void func_800C1C80(char* p) {
    int k;
    Unk_EntTabObj* o;
    int j;
    Unk_800C1C80_e* e;
    Unk_800C1C80_e* f;
    func_80055330(0);
    k = func_800CEC9C((Unk_800CEC9C*)(p + 0x25C));
    o = ((Unk_EntOwner*)func_800787B4())->unk328;
    j = D_800B4D5C[0];
    e = (Unk_800C1C80_e*)base(o)->unk8[j];
    f = (Unk_800C1C80_e*)base(((Unk_EntOwner*)func_800787B4())->unk328)->unk8[k];
    e->vf09(0);
    e->vf03(f, 1);
    func_8005549C(5, p, 0, -1);
}

EXTERN_C Unk_800C1D70* func_800C1D70(Unk_800C1D70* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80057368(self, 0);
    self->vb->vptr = (Unk_VTbl10*)&D_800B732C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B732C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B732C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xAC));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B732C).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B732C).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B732C).e[9].delta + adj;
    }
    self->vt58 = D_800B737C;
    self->vt2C = D_800B721C;
    self->unk5C = 0;
    self->unk60 = 1;
    self->unk64 = 1;
    func_8005D8C4(self->unk68, 1, 2);
    ((VAt<0x2C>*)self)->vf07(0, 0);
    ((VAt<0x2C>*)self)->vf08(0x140, 0xF0);
    self->unkA8 = 0;
    func_8002B174(self, self->unk68, -1);
    return self;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1EFC);

EXTERN_C void func_800C206C(Unk_800C206C* p, unsigned char a) {
    if (p->unkA8) {
        p->unkA8->vf28(a);
    }
}

EXTERN_C void func_800C20B0(void* q, int a) {
    Unk_800C20B0* p = (Unk_800C20B0*)q;
    if (p->unk5C == a) {
        return;
    }
    p->unk5C = a;
    if (a == 0) {
        p->unk64 = 0;
        func_8002B27C(p, p->unkA8);
        p->unkA8 = 0;
        ((VWith<Unk_800C20B0_h>*)p)->vf02();
        func_80055624((char*)p + 0x50, 0);
    } else {
        p->unk64 = 1;
        if (p->unkA8 == 0) {
            p->unk60 = 2;
        } else {
            p->unk60 = 3;
            func_800C206C((Unk_800C206C*)p, 0x80);
        }
        func_8005388C(p, 0x10);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C2184);

EXTERN_C void func_800C259C(Unk_800C259C* p) {
    func_8002A210(p);
    p->unk60 = 1;
    func_8005388C(p, 0x16);
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B713C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B716C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B71BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B71DC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B721C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B732C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B737C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C25DC);

EXTERN_C void func_800C2A0C(Unk_800C2A0C* p) {
    func_800557C8(p, 1, 2);
    func_80053C6C(p->unkC4, p);
    func_8005457C(p->unkC4, 0);
    func_80053FB0(p->unkC4, 0, 0x130);
}

EXTERN_C void func_800C2A6C(void* vp, int v) {
    Unk_EntTabObj* o = ((Unk_EntOwner*)func_800787B4())->unk328;
    int k = D_800B4D5C[0];
    Unk_800C2A6C_e* e = (Unk_800C2A6C_e*)base(o)->unk8[k];
    Unk_W4 a;
    for (unsigned int j = 0; j < 4; j++) {
        ((int*)&a)[j] = e->unk550[j];
    }
    int idx = ((Unk_800C2A6C*)vp)->unk20;
    int* ap = idx + (int*)&a;
    int saved = *ap;
    *ap = v;
    func_8008B150(e, a);
    func_8008687C(e, 0);
    for (unsigned int i = 0; i < 8; i++) {
        int c = *(D_80015904[i] + e->unk43C);
        if (func_800549D8(&((Unk_800C2A6C*)vp)->unk1B4[i]) < c) {
            func_8005408C(&((Unk_800C2A6C*)vp)->unk4F4[i], 5);
        } else if (c < func_800549D8(&((Unk_800C2A6C*)vp)->unk1B4[i])) {
            func_8005408C(&((Unk_800C2A6C*)vp)->unk4F4[i], 9);
        } else {
            func_8005408C(&((Unk_800C2A6C*)vp)->unk4F4[i], 1);
        }
        func_80054708(&((Unk_800C2A6C*)vp)->unk4F4[i], c);
    }
    ((int*)&a)[idx] = saved;
    func_8008B150(e, a);
    func_800697A4(((Unk_800C2A6C*)vp)->unk150);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C2C3C);

EXTERN_C void func_800C2D40(Unk_800C2D40* p) {
    Unk_EntTabObj* o = ((Unk_EntOwner*)func_800787B4())->unk328;
    int k = D_800B4D5C[0];
    Unk_Ent400* e = (Unk_Ent400*)base(o)->unk8[k];
    p->unk68 = e->unk410;
    p->unk6A = e->unk420;
    p->vf04();
    func_8005457C(p, 1);
    func_800631D4(p);
    func_80055330(0);
    func_8005457C(p, 0);
    func_80054EB4(p, 0xA0, 0x58);
    {
        Unk_Short4 v(0, 1);
        v.z = 0;
        v.w = 2;
        func_80054F30(p->unk74, 7, &v, 0);
        func_80054FC0(p->unk74);
    }
    func_80069978(p->unk150, Unk_PtS(8, 0xE), 0x36, 0x72, 0x10);
    func_80069914(p->unk150);
    func_800C0814(0, 0);
    func_800C0890(0);
    func_8005783C(6);
    if (!p->unk6C) {
        p->unk6C = func_8006753C(operator new(0x574), 1);
    }
}

EXTERN_C void func_800C2EB8(Unk_800C2EB8* p) {
    Unk_EntTabObj* o = ((Unk_EntOwner*)func_800787B4())->unk328;
    int k = D_800B4D5C[0];
    Unk_Ent400s* e = (Unk_Ent400s*)base(o)->unk8[k];
    func_8008687C(e, 0);
    e->unk410 = (e->unk412 < p->unk68) ? e->unk412 : p->unk68;
    e->unk420 = (e->unk422 < p->unk6A) ? e->unk422 : p->unk6A;
    func_8005783C(0);
    func_800C0890(1);
    func_800C0814(1, 0);
    func_80069958(p->unk150);
    func_80054FE0(p->unk74);
    func_8006323C(p);
    delete p->unk6C;
    p->unk6C = 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C2FCC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C32BC);

EXTERN_C int func_800C3438(void* p, int a) {
    if (a != 0) {
        return 0;
    }
    func_800553D8(0);
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C3468);

EXTERN_C Unk_800C375C* func_800C375C(Unk_800C375C* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_800630BC(self, 0, 1);
    self->vb->vptr = (Unk_VTbl10*)&D_800B74B4;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B74B4);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B74B4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xE0));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B74B4).e[6].delta + adj;
    }
    self->vt54 = D_800B7484;
    self->vt58 = D_800B7504;
    self->vt18 = D_800B7524;
    self->unk68 = 0;
    func_80054AF0(self->unk6C, 1);
    func_80053928(self->unkBC);
    self->unkD8 = 0;
    func_800C3AAC((Unk_800C3AAC*)self);
    self->unkDC = 0;
    func_80055020(self->unk6C, Unk_Pt(8, 0xC));
    func_80054EB4(self->unk6C, 0x130, 0x10);
    func_80054E18(self->unk6C, self->unkBC);
    return self;
}

EXTERN_C void func_800C38E0(Unk_800C38E0* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800B7484;
    self->vt58 = D_800B7504;
    self->vt18 = D_800B7524;
    self->vb->vptr = (Unk_VTbl10*)&D_800B74B4;
    if (!in_chrg) {
        vt = D_800B74B4;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B74B4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xE0));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B74B4).e[6].delta + adj;
    }
    func_800C3E00((Unk_800C3C08*)self);
    func_80053964(self->unkBC, 2);
    ((void (*)(void*, int))func_80054C34)(self->unk6C, 2);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_800C3AAC(Unk_800C3AAC* p) {
    func_800557C8(p, 1, 4);
    func_80053C6C(p->unkBC, p);
    func_8005457C(p->unkBC, 0);
    func_80053FB0(p->unkBC, 0, 0x130);
}

EXTERN_C void func_800C3B0C(Unk_800C3B0C* p) {
    func_800566E4(p);
    func_800C0860(2);
    p->unkDC = func_800C3E40(operator new(0xA0), 1);
    func_8002B174(D_800A4578[0], p->unkDC, -1);
    p->unkDC->vf27();
    p->unkDC->vf03();
    func_800C41E0(p->unkDC, 0, 0, 0);
    func_800C08D4(0);
    Unk_Short4 v(0, 1);
    v.z = 0;
    v.w = 2;
    func_80054F30(p->unk6C, 7, &v, 0);
    func_80054FC0(p->unk6C);
    func_8008EF40(12);
}

EXTERN_C void func_800C3C08(Unk_800C3C08* p) {
    func_80054FE0(p->unk6C);
    func_800C3E00(p);
    func_800C0860(1);
    func_80056874(p);
    p->unk68 = 0;
    func_8008EF40(13);
}

EXTERN_C int func_800C3C54(Unk_800C3C54* p, Unk_FlagArg* q) {
    if (p->unk68) {
        func_8001FC78((int)q, 0, 0);
        unsigned short f = q->unk18;
        if (p->unkD8) {
            if (f & 0x80) {
                func_800C41E0(p->unkDC, (unsigned char)D_800B4D5C[0], 1, 0);
            } else if (f & 0x20) {
                func_800C41E0(p->unkDC, (unsigned char)D_800B4D5C[0], -1, 0);
            } else if (f & 0x10) {
                func_800C41E0(p->unkDC, (unsigned char)D_800B4D5C[0], 0, 1);
            } else if (f & 0x40) {
                func_800C41E0(p->unkDC, (unsigned char)D_800B4D5C[0], 0, -1);
            } else if (f & 0x6000) {
                func_800C43DC(p->unkDC, D_800B4D5C[0], (p->unkD8 = 0, 0x80));
            }
        } else {
            if (f & 0xC00) {
                func_800C08D4((int)q);
            } else if (f & 0x2000) {
                func_800C43DC(p->unkDC, D_800B4D5C[0], (p->unkD8 = 1, 0xC0));
            } else if (f & 0x4000) {
                p->vf02();
            }
        }
    }
    return 1;
}

EXTERN_C int func_800C3DC0(void* p, int a) {
    func_8001FC78(a, 0, 0);
    return 1;
}

EXTERN_C int func_800C3DE8(Unk_800C3DE8* p, int a) {
    if (a != 0) {
        return 0;
    }
    p->unk68 = 1;
    return 1;
}

EXTERN_C void func_800C3E00(Unk_800C3C08* p) {
    if (p->unkDC) {
        func_8002B27C(D_800A4578[0], p->unkDC);
        p->unkDC = 0;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C3E40);

EXTERN_C void func_800C402C(Unk_800C402C* self, int in_chrg) {
    self->vt58 = D_800B75B4;
    self->vt2C = D_80013E30;
    self->vb->vptr = (Unk_VTbl10*)&D_800B7564;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B7564;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B7564).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x98));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B7564).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B7564).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B7564).e[9].delta + adj;
    }
    {
        int i;
        for (i = first(&self->unk30)->unk4 - 1; i >= 0; i--) {
            void** o = (void**)func_80019F64(first2(&self->unk30), i);
            if (o) {
                ((VAt0*)*o)->vf00(3);
            }
        }
        func_80019D40(first(&self->unk30));
    }
    func_80057558(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_800C41E0(void* vp, unsigned char sel, int dx, int dy) {
    VAt<0x2C>* o = (VAt<0x2C>*)at_800C41E0(&((Unk_800C41E0*)vp)->unk30, sel);
    int k = func_800C46E4((Unk_800C46E4*)o);
    int row = k / 5;
    if ((unsigned int)(k - row * 5 + dx) < 5 && row + dy >= 0 && row + dy < 3 && ((Unk_800C41E0*)vp)->unk5C[k + dx + dy * 5]) {
        ((Unk_800C41E0*)vp)->unk5C[k] = 1;
        o->vf29(dx, dy);
        ((Unk_800C41E0*)vp)->unk5C[k + dx + dy * 5] = 0;
        func_8008EF40(1);
    }
    int n = first(&((Unk_800C41E0*)vp)->unk30)->unk4;
    if (n >= 2) {
        for (int r = 1; r >= 0; r--) {
            for (int i = 0; i < n; i++) {
                if (func_800C46E4((Unk_800C46E4*)at_800C41E0(&((Unk_800C41E0*)vp)->unk30, i)) / 5 == r) {
                    ((VAt<0x2C>*)at_800C41E0(&((Unk_800C41E0*)vp)->unk30, i))->vf27();
                }
            }
        }
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C43DC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C44C4);

EXTERN_C int func_800C46E4(Unk_800C46E4* p) { return p->unk44; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C46F0);

EXTERN_C void func_800C47B0(Unk_800C47B0* p, int a, int b) {
    ent_800C47B0(((Unk_EntOwner*)func_800787B4())->unk328, p->unk48)->unk54A += a;
    ent_800C47B0(((Unk_EntOwner*)func_800787B4())->unk328, p->unk48)->unk54B += b;
    p->unk4A = b * 22 - a * 29;
    p->unk4C = -a * 9 - b * 11;
    p->unk44 += a + b * 5;
    func_8005388C(p, 6);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C48C4);

EXTERN_C void func_800C497C(Unk_800C497C* p) {
    if (p->unk8 && first((Unk_800BFB64_list*)p->unk30)->unk4 > 0) {
        VAt0* o = (VAt0*)func_80019F64(first2(p->unk30), 0);
        o->vf07(p->unkC, p->unkE - 0x40);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C4A18);

EXTERN_C void func_800C4C04(Unk_800C4C04* p) {
    void* r = (void*)p->vf11();
    if (p->unk8 && first((Unk_800BFB64_list*)p->unk30)->unk4 > 0 && r) {
        func_8002DD34(r, p->unk30, 0);
        func_8002DA94(r, p->unk30);
    }
}

EXTERN_C void func_800C4CA0(Unk_800C4CA0* self, int in_chrg) {
    self->vt40 = D_800B7624;
    self->vt2C = D_800B7644;
    self->vb->vptr = (Unk_VTbl10*)&D_800B75D4;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B75D4;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B75D4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x50));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B75D4).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B75D4).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B75D4).e[9].delta + adj;
    }
    func_800537DC(self->unk38, 0);
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C4DC0);

EXTERN_C void func_800C4F50(Unk_800C4F50* p, int dx, int dy) {
    int i = D_800B4CF0[0];
    p->unk28[i].x0 += dx;
    p->unk28[i].y0 += dy;
    p->unk50[i].x0 += dx;
    p->unk50[i].y0 += dy;
    func_8005F1D8(p);
}

EXTERN_C void func_800C4FBC(Unk_Sprt28* p, Unk_ColorSrc* c) {
    int i = D_800B4CF0[0];
    unsigned char r = c->unk5;
    unsigned char g = c->unk6;
    unsigned char b = c->unk7;
    p->unk28[i].r0 = r;
    p->unk28[i].g0 = g;
    p->unk28[i].b0 = b;
    func_8005F1D8(p);
}

EXTERN_C void func_800C5008(Unk_Sprt28* p, int x, int y) {
    p->vf10(x - p->unk28[D_800B4CF0[0]].x0, y - p->unk28[D_800B4CF0[0]].y0);
}

EXTERN_C void func_800C5060(void* p) { func_800C5408(operator new(0x70), p); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C5094);

EXTERN_C void func_800C52A0(Unk_800C52A0* p, unsigned char mode) {
    int b = D_800B4CF0[0];
    int k = 3;
    char* t;
    switch (mode) {
    case 1:
        k = 4;
        break;
    case 2:
        k = 5;
        break;
    }
    t = D_800AE640;
    SetDrawMode(p->unk10, 0, 0, func_80060154(t, k), 0);
    SetDrawMode(p->unk1C, 0, 0, func_80060154(t, k), 0);
    p->unk28[b].u0 = func_80060188(t, k).x;
    p->unk28[b].v0 = func_80060188(t, k).y;
    p->unk28[b].clut = func_800600A4(t, k);
    p->unk50[b].u0 = func_80060188(t, 2).x;
    p->unk50[b].v0 = func_80060188(t, 2).y;
    p->unk50[b].clut = func_800600A4(t, 2);
}

EXTERN_C void func_800C5400() {}

EXTERN_C void* func_800C5408(void* dv, void* sv) {
    Unk_800C5408* d = (Unk_800C5408*)dv;
    Unk_800C5408* s = (Unk_800C5408*)sv;
    d->vtbl = D_80010178;
    d->unk4 = s->unk4;
    d->vtbl = D_800111BC;
    d->unk8 = s->unk8;
    {
        short a = s->unkA;
        d->vtbl = D_80014BD0;
        d->unkA = a;
    }
    {
        int c = s->unkC;
        d->vtbl = D_800B773C;
        d->unkC = c;
    }
    {
        Unk_W3* dp = d->unk10;
        int n = 1;
        Unk_W3* sp = s->unk10;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    {
        Unk_W5* dp = d->unk28;
        int n = 1;
        Unk_W5* sp = s->unk28;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    {
        Unk_W4* dp = d->unk50;
        int n = 1;
        Unk_W4* sp = s->unk50;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    return d;
}

EXTERN_C void func_800C5524(void* p, int a) { func_8005F120(p, a); }

EXTERN_C Unk_800C5544* func_800C5544(Unk_800C5544* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_800630BC(self, 0, 4);
    self->vb->vptr = (Unk_VTbl10*)&D_800B77E4;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B77E4);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B77E4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x33B8));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B77E4).e[6].delta + adj;
    }
    self->vt54 = D_800B7854;
    self->vt58 = D_800B7834;
    self->vt18 = D_800B7884;
    {
        Unk_Elem28* q = self->unk68;
        int n = 3;
        for (; n != -1; n--) {
            func_80053928(q);
            q++;
        }
    }
    func_800C5BE8((Unk_800C5BE8*)self->unkD8, 1);
    func_800C56B8(self);
    {
        unsigned int i;
        for (i = 0; i < 4; i++) {
            func_80054E18(self, &self->unk68[i]);
        }
    }
    return self;
}

EXTERN_C void func_800C56B8(void* p) {
    func_800557C8(p, 1, 3);
    func_80053BCC((char*)p + 0x68, (int)D_800B77A4, 6);
    func_80053BCC((char*)p + 0x84, (int)D_800B77B4, 5);
    func_80053BCC((char*)p + 0xA0, (int)D_800B77C0, 9);
    func_80053BCC((char*)p + 0xBC, (int)D_800B77D4, 4);
}

EXTERN_C void func_800C5734(char* p) {
    unsigned int i;
    for (i = 0; i < 4; i++) {
        func_8006897C(p + 0xD8, i + 1, 0);
        func_80054094(&((Unk_800C5734*)p)->unk68[i], func_80068A5C(p + 0xD8) != 0);
    }
    func_800631D4(p);
}

EXTERN_C int func_800C57C4(Unk_800C57C4* p, Unk_FlagArg* q) {
    int f;
    func_8001FC78((int)q, 0, 0);
    if (func_8005618C(q)) {
        return 1;
    }
    if (p->unk3C && !func_80053880((char*)p->unk3C + 0x50)) {
        p->unk3C->vf02();
    }
    f = q->unk18;
    if (f & 0x10) {
        p->unk20 = ((int (*)(void*, int))func_80058270)(p->unk3C, -1);
    } else if (f & 0x40) {
        p->unk20 = ((int (*)(void*, int))func_80058270)(p->unk3C, 1);
    } else if (f & 0x2000) {
        if (func_8005409C(func_800550BC(p))) {
            func_8006897C(p->unkD8, *(volatile int*)&p->unk20 + 1, 0);
            func_800C5F68(p->unkD8);
            return 1;
        }
        func_8008EF40(14);
    } else if (f & 0xC00) {
        if (D_800B4DD0[0]->unk1FB < 2) {
            return 1;
        }
        if (func_800C08D4((int)q)) {
            func_8008EF40(2);
        }
    }
    return 1;
}

EXTERN_C void func_800C5928(char* p, int a) {
    if (a == 1) {
        unsigned int i;
        for (i = 0; i < 4; i++) {
            func_8006897C(p + 0xD8, i + 1, 0);
            func_80054094(&((Unk_800C5734*)p)->unk68[i], func_80068A5C(p + 0xD8) != 0);
        }
        func_80054CE4(p);
    }
    func_80056D60(p, a);
}

EXTERN_C void func_800C59D8(Unk_800C59D8* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800B7854;
    self->vt58 = D_800B7834;
    self->vt18 = D_800B7884;
    self->vb->vptr = (Unk_VTbl10*)&D_800B77E4;
    if (!in_chrg) {
        vt = D_800B77E4;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B77E4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x33B8));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B77E4).e[6].delta + adj;
    }
    func_800C68AC(self->unkD8, 2);
    Unk_destroy(self->unk68, 4);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B73A4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B73F4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7414);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7444);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7484);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B74B4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7504);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7524);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7564);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B75B4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B75D4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7624);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7644);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B773C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B77A4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B77B4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B77C0);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B77D4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B77E4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7834);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7854);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7884);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C5BE8);

EXTERN_C void func_800C5EE0(Unk_800C5EE0* p) {
    func_800557C8(p->unk22CC, 1, 3);
    func_8005457C(p->unk22CC, 0);
    func_80053FB0(p->unk22CC, 0, 0x130);
    func_800557C8(p->unk24AC, 1, 8);
    func_800557C8(p->unk2358, 1, 9);
    func_800D56C4(p->unk2524);
    func_800D1078(p->unk3070);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C5F68);

EXTERN_C void func_800C6104(Unk_800C6104* p) {
    p->unk32D4 = 0;
    func_8005457C(p, 0);
    func_8005783C(0);
    func_800C0814(1, 0);
    func_80054FE0(p->unk227C);
    func_80068EE8(p);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C6154);

EXTERN_C int func_800C6380(Unk_800C6104* p, Unk_800C6380_arg* q) {
    if (func_8005618C(q)) {
        return 1;
    }
    if (q->unk18 & 0x8000) {
        if (p->unk32D4) {
            p->unk32D4 = 0;
        }
        return 1;
    }
    func_800690C8(p, q);
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C63F8);

EXTERN_C void func_800C66D4(Unk_800C66D4* p, int i, int j) {
    if (i == j) {
        return;
    }
    func_80061AAC(D_800B4DD0[0], p->unk68[i], p->unk68[j]);
    Unk_E6C_800C66D4* a = &p->unk9C[i];
    Unk_800C66D4_t t;
    func_800538CC(&t, func_80053BC0(a), 0);
    func_80054094(&t, !func_8005409C(a));
    Unk_E6C_800C66D4* b = &p->unk9C[j];
    func_80053C6C(a, b);
    func_80053C6C(b, &t);
    Unk_Elem40* c = &((Unk_Elem40*)((char*)p + 0x1548))[i];
    func_80053C6C(&t, c);
    Unk_Pt q = ((Unk_Pt (*)(void*))func_80054054)(c);
    Unk_Elem40* d = &((Unk_Elem40*)((char*)p + 0x1548))[j];
    func_80053C6C(c, d);
    func_8005457C(c, 0);
    func_80053F48(c, q);
    q = ((Unk_Pt (*)(void*))func_80054054)(d);
    func_80053C6C(d, &t);
    func_8005457C(d, 0);
    func_80053F48(d, q);
    func_80054CE4(p);
    func_80053964(&t, 2);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C68AC);

EXTERN_C Unk_800C6B44* func_800C6B44(Unk_800C6B44* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80056364(self, 0, 0, 1);
    self->vb->vptr = (Unk_VTbl10*)&D_800B79C4;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B79C4);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B79C4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xDC));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B79C4).e[6].delta + adj;
    }
    self->vt54 = D_800B7A34;
    self->vt58 = D_800B7A14;
    self->vt18 = D_800B7A64;
    func_80054AF0(self->unk64, 1);
    func_80053928(self->unkB4);
    self->unkD8 = 0;
    func_800C6CCC((Unk_800C6CCC*)self);
    self->unkD0 = 0;
    self->unkD4 = 0;
    func_80055020(self->unk64, Unk_Pt(8, 0xC));
    func_80054EB4(self->unk64, 0x130, 0x10);
    func_80054E18(self->unk64, self->unkB4);
    return self;
}

EXTERN_C void func_800C6CCC(Unk_800C6CCC* p) {
    func_800557C8(p, 1, 7);
    func_80053C6C(p->unkB4, p);
    func_8005457C(p->unkB4, 0);
    func_80053FB0(p->unkB4, 0, 0x130);
}

EXTERN_C void func_800C6D2C(Unk_800C6D2C* p) {
    func_800566E4(p);
    p->unkD8 = 0;
    func_800C0860(3);
    func_800C0890(0);
    func_800C0814(0, 1);
    Unk_Short4 v(0, 1);
    v.z = 0;
    v.w = 2;
    func_80054F30(p->unk64, 7, &v, 0);
    func_80054FC0(p->unk64);
    func_8008EF40(12);
}

EXTERN_C void func_800C6DB0(Unk_800C6DB0* p) {
    Unk_Vobj2C* q = p->unkD4;
    p->unkD8 = 0;
    q->vf4();
    func_8008EF40(13);
}

EXTERN_C int func_800C6DF4(Unk_800C6DB0* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (p->unkD8) {
        if (q->unk18 & 0x40) {
            func_800C7984(p->unkD4);
            func_8008EF40(10);
            p->unkD8 = 0;
        } else if (q->unk18 & 0x10) {
            func_800C7890(p->unkD4);
            func_8008EF40(10);
            p->unkD8 = 0;
        }
    }
    return 1;
}

EXTERN_C int func_800C6E8C(Unk_800C6E8C* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (p->unkD8 && (q->unk18 & 0x4000)) {
        p->vf02();
    }
    return 1;
}

EXTERN_C int func_800C6F0C(Unk_800C6F0C* p, int a) {
    VAt<0x2C>* o;
    switch (a) {
    case 0:
        func_800D0248();
        p->unkD0 = func_80057368(operator new(0x64), 1);
        func_8002B174(D_800A4578[0], p->unkD0, -1);
        o = p->unkD0;
        o->vf07(0, 0);
        o->vf08(0x140, 0xF0);
        p->unkD0->vf27();
        p->unkD0->vf03();
        p->unkD4 = func_800C7230(operator new(0x58), 1, 2);
        p->unkD0->vf29(p->unkD4, -1);
        p->unkD4->vf03();
        return 1;
    case 2:
        func_8002B27C(p->unkD0, p->unkD4);
        p->unkD4 = 0;
        func_8002B27C(D_800A4578[0], p->unkD0);
        p->unkD0 = 0;
        func_800CF32C();
        func_800CFF6C();
        func_80054FE0(p->unk64);
        func_800C0814(1, 0);
        func_800C0890(1);
        func_800C0860(1);
        func_80056874(p);
        func_8005457C(p, 0);
    case 1:
        p->unkD8 = 1;
        return 1;
    }
    return 0;
}

EXTERN_C void func_800C7110(Unk_800C7110* self, int in_chrg) {
    self->vt54 = D_800B7A34;
    self->vt58 = D_800B7A14;
    self->vt18 = D_800B7A64;
    self->vb->vptr = (Unk_VTbl10*)&D_800B79C4;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B79C4;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B79C4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xDC));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B79C4).e[6].delta + adj;
    }
    func_80053964(self->unkB4, 2);
    ((void (*)(void*, int))func_80054C34)(self->unk64, 2);
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7230);

EXTERN_C void func_800C7740(Unk_800C7740* self, int in_chrg) {
    self->vt40 = D_800B7BEC;
    self->vt2C = D_800B7AA4;
    self->vb->vptr = (Unk_VTbl10*)&D_800B7B9C;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B7B9C;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B7B9C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x50));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B7B9C).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B7B9C).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B7B9C).e[9].delta + adj;
    }
    func_80053848(self);
    func_80055624((char*)self + 0x38, 0);
    func_800D3534();
    func_800537DC((char*)self + 0x38, 0);
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7890);

EXTERN_C void func_800C7984(void* q) {
    Unk_800C7984* p = (Unk_800C7984*)q;
    int n = ((Unk_800C7984_g*)D_800B4DD0[0])->unk1FD * 4;
    p->unk48 = -2;
    p->unk44 = (p->unk44 + n - 1) % n;
    if (p->unk8) {
        ((VAt<8>*)((char*)Unk_800E9820_at(first2(p->unk30), 0) + 0x10))->vf02();
        func_8005388C(p, 0x11);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7A7C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7DE4);

EXTERN_C void func_800C7EC8(Unk_800C7EC8* p, void* a) {
    if (p->unk8) {
        VAt0* o;
        Unk_800BFB64_node* n;
        func_8005C088(p, a, 1);
        o = func_800D35F8(operator new(0x738), p->unkC, p->unk44, p->unk1C);
        o->vf11(D_800B4C98);
        n = first(p->unk30);
        func_80019A6C(n, (int)o, n->unk4);
        func_8002DA94(a, p->unk30);
    }
}

EXTERN_C void func_800C7F80(Unk_800C7F80* p) {
    func_8002A210(p);
    if (p->unk8) {
        func_8005388C(p, 0xC);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7FC8);

EXTERN_C Unk_800C807C* func_800C807C(Unk_800C807C* self, int in_chrg, int a) {
    if (in_chrg) {
        Unk_800BCFD0* b = &self->unk38;
        self->vb0 = (Unk_VBase*)b;
        b->vtbl = D_80010178;
        b->unk4 = 0;
        b->vtbl = D_800104A8;
    }
    func_8005BC84(self, 0, (unsigned short)a, 0x10);
    self->vb0->vptr = (Unk_VTbl10*)&D_800B7D04;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B7D04;
        char* full;
        int adj;
        self->vb0->vptr = &vt;
        vt.e[1].delta = D_800B7D04.e[1].delta + (adj = (char*)self - (full = (char*)self->vb0 - 0x38));
        vt.e[5].delta = D_800B7D04.e[5].delta + adj;
        vt.e[7].delta = D_800B7D04.e[7].delta + adj;
        vt.e[9].delta = D_800B7D04.e[9].delta + adj;
    }
    self->vt2C = D_800B7C0C;
    func_800D4674();
    return self;
}

EXTERN_C void func_800C8190(Unk_VbDtor2C* self, int in_chrg) {
    self->vt2C = D_800B7C0C;
    self->vb0->vptr = (Unk_VTbl10*)&D_800B7D04;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B7D04;
        char* full;
        int adj;
        self->vb0->vptr = &vt;
        vt.e[1].delta = D_800B7D04.e[1].delta + (adj = (char*)self - (full = (char*)self->vb0 - 0x38));
        vt.e[5].delta = D_800B7D04.e[5].delta + adj;
        vt.e[7].delta = D_800B7D04.e[7].delta + adj;
        vt.e[9].delta = D_800B7D04.e[9].delta + adj;
    }
    func_800D48FC();
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb0, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_800C82A0(Unk_Hdr38d* p, unsigned char a) {
    if (p->unk8 && ((Unk_800BFB64_node*)(p->unk30 ? p->unk30->Unk_800BFB64_list::head : 0))->unk4 > 0) {
        Unk_W2 t;
        func_8002972C(&t, a, a, a, 1);
        ((VAt0*)at0((Unk_Tbl*)first2(p->unk30)))->vf11(&t);
        func_800198AC(&t, 2);
    }
}

EXTERN_C void func_800C8384(Unk_800C8384* p, void* a) {
    if (p->unk8) {
        Unk_800BFB64_node* n;
        func_8005C088(p, a, 1);
        n = first(p->unk30);
        func_80019A6C(n, (int)func_800D49D0(operator new(0x78), p->unk1C), n->unk4);
        func_8002DA94(a, p->unk30);
    }
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B78E4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7934);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7954);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7984);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B79C4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7A14);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7A34);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7A64);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7AA4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7B9C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7BEC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7C0C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7D04);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C8410);

EXTERN_C void func_800C88D8(Unk_800C88D8* p) {
    func_800557C8(p, 1, 6);
    func_80053C6C(p->unk510, p);
    func_8005457C(p->unk510, 0);
    func_80053FB0(p->unk510, 0, 0x130);
}

EXTERN_C void func_800C8938(Unk_800C8938* p) {
    p->unk68 = 0;
    func_800566E4(p);
    func_800C0860(4);
    func_800C0890(0);
    func_800C0814(0, 1);
    Unk_Short4 v(0, 1);
    v.z = 0;
    v.w = 2;
    func_80054F30(p->unk4C0, 7, &v, 0);
    func_80054FC0(p->unk4C0);
    func_8008EF40(12);
}

EXTERN_C void func_800C89BC(Unk_800C89BC* p) {
    unsigned int i;
    func_800CCF4C((Unk_800CCF18*)p->unk564);
    func_80054FE0(p);
    func_8005457C(p, 0);
    for (i = 0; i < 8; i++) {
        p->unk70[i].vf02();
    }
    if (p->unk4B0) {
        func_8002B27C(D_800A4578[0], p->unk4B0);
        p->unk4B0 = 0;
    }
    p->unk6C = 0;
    func_80054FE0(p->unk4C0);
    func_800C0814(1, 0);
    func_800C0890(1);
    func_800C0860(1);
    func_80054FE0(p);
    func_80056874(p);
    func_8008EF40(13);
    func_80061058(D_800B4DD0[0]);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C8AC0);

EXTERN_C int func_800C8F34(Unk_800C8F34* p, Unk_FlagArg* q) {
    if (p->unk6C) {
        int f = q->unk18;
        func_8001FC78((int)q, 0, 0);
        if (((Unk_800C8F34_g*)D_800B4DD0[0])->unk120->unk18 & f) {
            if (p->unk4B4) {
                func_8002B27C(D_800A4578[0], p->unk4B4);
                p->unk4B4 = 0;
            } else {
                p->vf02();
            }
        }
    }
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C8FE8);

EXTERN_C void func_800C9424(Unk_800C9424p* p) {
    int idx = p->unk4B8;
    VAt<0x2C>* t = p->unk4B4;
    VAt<0x2C>* o = p->unk4B0;
    int k = 2;
    Unk_Short2 v;
    if (t) {
        idx = p->unk4BC;
        k = 1;
        o = t;
    }
    func_80054054(&v, &((Unk_800C9424*)p)->unk70[idx]);
    v.x -= 4;
    v.y += 4;
    func_80063BE4(o);
    func_80063B14(o, &v, k);
    o->vf03();
}

EXTERN_C void func_800C94D4(Unk_800C94D4* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800B7E8C;
    self->vt58 = D_800B7E6C;
    self->vt18 = D_800B7EBC;
    self->vb->vptr = (Unk_VTbl10*)&D_800B7E1C;
    if (!in_chrg) {
        vt = D_800B7E1C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B7E1C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x60C));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B7E1C).e[6].delta + adj;
    }
    func_800CD060((Unk_800CD060*)self->unk564, 2);
    func_80053964(self->unk548, 2);
    func_80053964(self->unk52C, 2);
    func_80053964(self->unk510, 2);
    ((void (*)(void*, int))func_80054C34)(self->unk4C0, 2);
    Unk_destroy(self->unk3D0, 8);
    Unk_destroy(self->unk2F0, 8);
    Unk_destroy(self->unk70, 8);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7E1C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7E6C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7E8C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7EBC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C97A4);

EXTERN_C void func_800C99A4(Unk_Hdr38* p, void* a) {
    if (p->unk8) {
        Unk_800BFB64_node* n;
        void* o;
        func_8005C088(p, a, 1);
        n = first(p->unk30);
        o = operator new(0x64);
        func_80019A6C(n, (int)func_800CC28C((Unk_800CC28C*)o, p->unkC, func_800D49C0(), (char*)p + 0x38, p->unk1C), n->unk4);
        func_8002DA94(a, p->unk30);
    }
}

EXTERN_C void func_800C9A50(Unk_VbDtor2C* self, int in_chrg) {
    self->vt2C = D_800B7F6C;
    self->vb0->vptr = (Unk_VTbl10*)&D_800B7F1C;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B7F1C;
        char* full;
        int adj;
        self->vb0->vptr = &vt;
        vt.e[1].delta = D_800B7F1C.e[1].delta + (adj = (char*)self - (full = (char*)self->vb0 - 0x3C));
        vt.e[5].delta = D_800B7F1C.e[5].delta + adj;
        vt.e[7].delta = D_800B7F1C.e[7].delta + adj;
        vt.e[9].delta = D_800B7F1C.e[9].delta + adj;
    }
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb0, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

EXTERN_C Unk_800C9B58* func_800C9B58(Unk_800C9B58* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80056198(self, 0, D_800B8064, 0, 1);
    self->vb->vptr = (Unk_VTbl10*)&D_800B806C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B806C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B806C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B806C).e[6].delta + adj;
    }
    {
        register Unk_800C9B58* r asm("$2") = self;
        r->vt54 = D_800B80DC;
        r->vt58 = D_800B80BC;
        r->vt18 = D_800B810C;
        r->unk64 = 0;
        return r;
    }
}

EXTERN_C void func_800C9C78(Unk_800C9D60* p) {
    if (!p->unk64) {
        p->unk64 = (Unk_800C9D60_sub*)func_800CA1CC(operator new(0xCC), 1, Unk_Pt(0x42, 0x5C));
        func_8002B174(D_800A4578[0], p->unk64, -1);
    }
    p->unk64->vf27();
    func_800CA7A0(p->unk64);
}

EXTERN_C void func_800C9D20(Unk_800C9D60* p) {
    if (p->unk64) {
        func_8002B27C(D_800A4578[0], p->unk64);
        p->unk64 = 0;
    }
}

EXTERN_C void func_800C9D60(Unk_800C9D60* p, int a) {
    if (p->unk64) {
        func_800CAAD4(p->unk64, a);
    }
}

EXTERN_C void func_800C9D90(Unk_800C9D90* p) {
    if (p->unk64) {
        p->unk64->vf02();
    }
}

EXTERN_C int func_800C9DD4(Unk_800C9D60* p) {
    if (p->unk64) {
        return func_80053880(p->unk64->unk50);
    }
    return 1;
}

EXTERN_C void func_800C9E04(Unk_800C9D60* p) {
    if (p->unk64) {
        p->unk64->vf27();
    }
}

EXTERN_C void func_800C9E48(Unk_800C9D60* p) {
    if (p->unk64) {
        p->unk64->vf4();
    }
}

EXTERN_C int func_800C9E8C(void* p, int a) {
    int r = 1;
    switch (a) {
    case 1:
        func_800C9FAC(p);
        break;
    case 2:
        func_800CA038(p);
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

EXTERN_C int func_800C9EE8(Unk_800C9D90* p, Unk_FlagArg* f) {
    func_8001FC78((int)f, 0, 0);
    if (p->unk64 && !((bool (*)(void*))func_80053880)((char*)p->unk64 + 0x50)) {
        p->unk64->vf02();
    } else if (f->unk18 & 0x400) {
        func_800C9FAC(p);
    } else if (f->unk18 & 0x800) {
        func_800CA038(p);
    }
    return 1;
}

EXTERN_C void func_800C9FAC(void* q) {
    Unk_800C9D60* p = (Unk_800C9D60*)q;
    if (p->unk64 && func_80053880(p->unk64->unk50)) {
        p->unk64->vf27();
        func_800CA9C4((Unk_800CA9C4*)p->unk64);
        func_800538B4(func_800CAD68(p->unk64));
        func_8008EF40(2);
    }
}

EXTERN_C void func_800CA038(void* q) {
    Unk_800C9D60* p = (Unk_800C9D60*)q;
    if (p->unk64 && func_80053880(p->unk64->unk50)) {
        p->unk64->vf27();
        func_800CAA4C((Unk_800CA9C4*)p->unk64);
        func_800538B4(func_800CAD68(p->unk64));
        func_8008EF40(2);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CA0C4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CA1CC);

EXTERN_C void func_800CA5A4(Unk_800CA5A4* self, int in_chrg) {
    self->vt58 = D_800B82AC;
    self->vt2C = D_800B814C;
    self->vb->vptr = (Unk_VTbl10*)&D_800B825C;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B825C;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B825C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xC4));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B825C).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B825C).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B825C).e[9].delta + adj;
    }
    {
        int i;
        for (i = first(&self->unk84)->unk4 - 1; i >= 0; i--) {
            void** o = (void**)func_80019F64(first2(&self->unk84), i);
            if (o) {
                ((VAt0*)*o)->vf00(3);
            }
        }
        func_80019D40(first(&self->unk84));
    }
    func_80019D40(first(&self->unk30));
    func_800198AC(self->unkB4, 2);
    func_800198AC(self->unkAC, 2);
    func_800198AC(self->unkA4, 2);
    func_80019920(self->unk84.Unk_800BFB64_list::head, 0);
    func_80057558(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CA7A0);

EXTERN_C void func_800CA9C4(Unk_800CA9C4* p) {
    if (p->unk64 == 0 && first(&p->unk84)->unk4 >= 3) {
        p->unk5C = func_800CAF84((Unk_800CAF84*)p, p->unk5C - 1);
        p->unk60 = 12;
        func_8005388C(p, 12);
        p->unk64 = 2;
    }
}

EXTERN_C void func_800CAA4C(Unk_800CA9C4* p) {
    if (p->unk64 == 0 && first(&p->unk84)->unk4 >= 3) {
        p->unk5C = func_800CAF84((Unk_800CAF84*)p, p->unk5C + 1);
        p->unk60 = 12;
        func_8005388C(p, 12);
        p->unk64 = 3;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CAAD4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CAD68);

EXTERN_C int func_800CADB0(Unk_800CA9C4* p) {
    int r = func_80053830(p);
    if (r) {
        switch (p->unk64) {
        case 1:
            func_800CAFE0(p);
            break;
        case 2:
            func_800CB74C(p);
            break;
        case 3:
            func_800CB418(p);
            break;
        case 4:
            func_800CBA70(p);
            break;
        }
    } else {
        if (p->unk64 == 4) {
            func_8005549C(0, p, 0, -1);
        }
        p->unk64 = 0;
    }
    return r;
}

EXTERN_C void func_800CAEA4(Unk_Derived50* p) {
    func_80053848(p);
    func_800CAAD4(p, 1);
}

EXTERN_C void func_800CAEE4(Unk_800CAEE4* p) {
    unsigned int i;
    for (i = 0; i < first((Unk_800BFB64_list*)&p->unk84)->unk4; i++) {
        VAt<0x2C>* o = (VAt<0x2C>*)func_80019F64(first2(&p->unk84), i);
        o->vf04();
    }
}

EXTERN_C int func_800CAF84(Unk_800CAF84* p, int a) {
    int n = first(&p->unk84)->unk4 - 1;
    return (a + n - 1) % n + 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CAFE0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CB418);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CB74C);

EXTERN_C void func_800CBA70(void* vp) {
    int x0 = ((Unk_800CBA70*)vp)->unkBC;
    int y0 = ((Unk_800CBA70*)vp)->unkC0;
    int n = func_80053874((Unk_800CBA70*)vp);
    if (n == 0x13 && first(&((Unk_800CBA70*)vp)->unk84)->unk4 >= 3) {
        at_800CBA70(&((Unk_800CBA70*)vp)->unk84, func_800CAF84((Unk_800CAF84*)vp, ((Unk_800CBA70*)vp)->unk5C + 1))->vf04();
        if (first(&((Unk_800CBA70*)vp)->unk84)->unk4 >= 4) {
            at_800CBA70(&((Unk_800CBA70*)vp)->unk84, func_800CAF84((Unk_800CAF84*)vp, ((Unk_800CBA70*)vp)->unk5C + 2))->vf04();
        }
    }
    func_800CBCCC(vp, n * 2, 20, x0 + (((Unk_800CBA70*)vp)->unk68 - x0) * n / 20, y0 + (((Unk_800CBA70*)vp)->unk6A - y0) * n * (n * 8 - 100) / 1200);
    if (n == 1) {
        VAt<0x2C>* o = at_800CBA70(&((Unk_800CBA70*)vp)->unk84, ((Unk_800CBA70*)vp)->unk5C);
        short x = ((Unk_800CBA70*)vp)->unkBC, y = ((Unk_800CBA70*)vp)->unkC0, z = ((Unk_800CBA70*)vp)->unk6C, w = ((Unk_800CBA70*)vp)->unk6E;
        Unk_S4_800CBA70 r;
        r.x = x;
        r.y = y;
        r.z = z;
        r.w = w;
        ((void (*)(void*, Unk_S4_800CBA70, void*))func_800D0608)(o, r, ((Unk_800CBA70*)vp)->unkA4);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CBCCC);

EXTERN_C void func_800CC138(Unk_800CC138* p, int a, int b, int c) {
    int x = p->unk68 + 0x1A;
    int y = p->unk6A + 0x100;
    func_800D04E4(at_800CC138(&p->unk84, p->unk5C), a, x, y);
    func_800D04E4(at_800CC138(&p->unk84, func_800CAF84((Unk_800CAF84*)p, p->unk5C + 1)), b, x, y);
    if (first(&p->unk84)->unk4 >= 4) {
        func_800D04E4(at_800CC138(&p->unk84, func_800CAF84((Unk_800CAF84*)p, p->unk5C + 2)), c, x, y);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC28C);

EXTERN_C void func_800CC3BC(Unk_Ft4_10* p, Unk_Short2 a, Unk_Short2 b, Unk_Short2 c, Unk_Short2 d) {
    int i = D_800B4CF0[0];
    p->unk10[i].x0 = a.x;
    p->unk10[i].y0 = a.y;
    p->unk10[i].x1 = b.x;
    p->unk10[i].y1 = b.y;
    p->unk10[i].x2 = c.x;
    p->unk10[i].y2 = c.y;
    p->unk10[i].x3 = d.x;
    p->unk10[i].y3 = d.y;
    func_8005F1D8(p);
}

EXTERN_C void func_800CC454(Unk_Ft4_10* p, Unk_800CC454_q q) {
    int b = D_800B4CF0[0];
    p->unk10[b].x0 += q.x0;
    p->unk10[b].y0 += q.y0;
    p->unk10[b].x1 += q.x1;
    p->unk10[b].y1 += q.y1;
    p->unk10[b].x2 += q.x2;
    p->unk10[b].y2 += q.y2;
    p->unk10[b].x3 += q.x3;
    p->unk10[b].y3 += q.y3;
    func_8005F1D8(p);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC534);

EXTERN_C void func_800CC754(Unk_800CC754* p, Unk_800CC754_s* s) {
    if (s) {
        int i = D_800B4CF0[0];
        int u;
        p->unk10[i].tpage = s->unk1C;
        if (s->unkC == 0) {
            u = s->unk10 & 0x3F;
        } else if (s->unkC->vf02()) {
            u = (s->unk10 << 1) & 0x7F;
        } else {
            u = s->unk10 << 2;
        }
        Unk_800CC754_uv t(u, s->unk12);
        p->unk10[i].u0 = t.u;
        p->unk10[i].v0 = t.v;
        p->unk60 = *(unsigned short*)&t;
        p->unk10[i].clut = *(unsigned short*)((char*)s->unkC + 8);
        func_8005F1D8(p);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC85C);

EXTERN_C void func_800CC914(Unk_Ft4_10* p, Unk_ColorSrc* c) {
    p->unk10[D_800B4CF0[0]].clut = c->unk8;
    func_8005F1D8(p);
}

EXTERN_C void func_800CC950(Unk_Ft4_10* p, int dx, int dy) {
    int i = D_800B4CF0[0];
    p->unk10[i].x0 += dx;
    p->unk10[i].y0 += dy;
    p->unk10[i].x1 += dx;
    p->unk10[i].y1 += dy;
    p->unk10[i].x2 += dx;
    p->unk10[i].y2 += dy;
    p->unk10[i].x3 += dx;
    p->unk10[i].y3 += dy;
    func_8005F1D8(p);
}

EXTERN_C void func_800CC9E4(Unk_Ft4_10* p, Unk_ColorSrc* c) {
    int i = D_800B4CF0[0];
    p->unk10[i].r0 = c->unk5;
    p->unk10[i].g0 = c->unk6;
    p->unk10[i].b0 = c->unk7;
    func_8005F1D8(p);
}

EXTERN_C void func_800CCA34(Unk_Ft4_10* p, int w, int h) {
    int i = D_800B4CF0[0];
    int x = p->unk10[i].x0;
    int y = p->unk10[i].y0;
    p->unk10[i].x1 = x + w;
    p->unk10[i].y1 = y;
    p->unk10[i].x2 = x;
    p->unk10[i].y2 = y + h;
    p->unk10[i].x3 = x + w;
    p->unk10[i].y3 = y + h;
    func_8005F1D8(p);
}

EXTERN_C void func_800CCA90(Unk_Ft4_10* p, int x, int y) {
    p->vf10(x - p->unk10[D_800B4CF0[0]].x0, y - p->unk10[D_800B4CF0[0]].y0);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CCAE8);

EXTERN_C int func_800CCBD8(Unk_Ft4_10* p) {
    if (func_8005F1B4(p)) {
        int b = D_800B4CF0[0];
        POLY_FT4* dst = &p->unk10[b];
        POLY_FT4* src = &p->unk10[b ^ 1];
        int* d = (int*)dst;
        int* s = (int*)src;
        unsigned int i;
        for (i = 0; i < 8; i += 4) {
            int w0, w1, w2, w3;
            w0 = s[i + 1]; w1 = s[i + 2]; w2 = s[i + 3]; w3 = s[i + 4];
            d[i + 1] = w0; d[i + 2] = w1; d[i + 3] = w2; d[i + 4] = w3;
        }
        ((int*)dst)[9] = ((int*)src)[9];
    }
    addPrimN(((unsigned short*)p)[5], &p->unk10[D_800B4CF0[0]]);
    return 1;
}

EXTERN_C void func_800CCD04(void* p, int a) { func_8005F120(p, a); }

EXTERN_C Unk_800CCD24* func_800CCD24(Unk_800CCD24* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_800630BC(self, 0, 2);
    self->vb->vptr = (Unk_VTbl10*)&D_800B836C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B836C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B836C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xA0));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B836C).e[6].delta + adj;
    }
    self->vt54 = D_800B83DC;
    self->vt58 = D_800B83BC;
    self->vt18 = D_800B840C;
    func_800538CC(self->unk68, D_800B8334, 0xC);
    func_800538CC(self->unk84, D_800B8350, 0xD);
    func_80054EB4(self, 0x6E, 0x21);
    func_8005457C(self, 1);
    func_80063270(self, Unk_Pt(0x5F, 0x3F));
    func_80053F48(self->unk68, Unk_Pt(9, 2));
    func_80053F48(self->unk84, Unk_Pt(9, 0xF));
    func_80054E18(self, self->unk68);
    func_80054E18(self, self->unk84);
    return self;
}

EXTERN_C void func_800CCF18(Unk_800CCF18* p) {
    p->unk20 = D_800A4578[0]->unk1D2 != 0;
    func_800550FC(p, 2);
}

EXTERN_C void func_800CCF4C(Unk_800CCF18* p) {
    if (p->unk20 == 0) {
        func_8002456C(D_800A4534.unk44 + 0x1AC);
        func_8002456C(D_800A4534.unk44 + 0x2D8);
    } else {
        func_80024524(D_800A4534.unk44 + 0x1AC);
        func_80024524(D_800A4534.unk44 + 0x2D8);
    }
    func_80054FE0(p);
}

EXTERN_C int func_800CCFCC(Unk_800CCFCC* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (q->unk18 & 0x10) {
        func_80058270(p->unk3C, -1);
        p->unk20 = func_80058404(p->unk3C, -1);
    } else if (q->unk18 & 0x40) {
        func_80058270(p->unk3C, 1);
        p->unk20 = func_80058404(p->unk3C, 1);
    }
    return 1;
}

EXTERN_C void func_800CD060(Unk_800CD060* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800B83DC;
    self->vt58 = D_800B83BC;
    self->vt18 = D_800B840C;
    self->vb->vptr = (Unk_VTbl10*)&D_800B836C;
    if (!in_chrg) {
        vt = D_800B836C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B836C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xA0));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B836C).e[6].delta + adj;
    }
    func_80053964(self->unk84, 2);
    func_80053964(self->unk68, 2);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

EXTERN_C Unk_800CD224* func_800CD224(Unk_800CD224* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_800630BC(self, 0, 8);
    self->vb->vptr = (Unk_VTbl10*)&D_800B844C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B844C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B844C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x518));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B844C).e[6].delta + adj;
    }
    self->vt54 = D_80014E7C;
    self->vt58 = D_800B849C;
    self->vt18 = D_800B84BC;
    func_80054AF0(self->unk68, 1);
    func_80053928(self->unkB8);
    {
        Unk_EB88* q = self->unkD4;
        int n = 7;
        for (; n != -1; n--) {
            func_800D0E90((Unk_800D0E90*)q, 1);
            q++;
        }
    }
    self->unk514 = 0;
    func_800CD3C8((Unk_800CD3C8*)self);
    func_80055020(self->unk68, Unk_Pt(8, 0xC));
    func_80054EB4(self->unk68, 0x130, 0x10);
    func_80054E18(self->unk68, self->unkB8);
    return self;
}

EXTERN_C void func_800CD3C8(Unk_800CD3C8* p) {
    func_800557C8(p, 1, 5);
    func_80053C6C(p->unkB8, p);
    func_8005457C(p->unkB8, 0);
    func_80053FB0(p->unkB8, 0, 0x130);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD428);

EXTERN_C void func_800CD554(Unk_800CD554* p) {
    Unk_TblIt* it = (Unk_TblIt*)&p->unk1C;
    it->unk4 = 0;
    p->vf04();
    func_80054EB4(p, 0xE0, first((Unk_800BFB64_list*)it)->unk4 * 13 + 8);
    func_8005457C(p, 1);
    p->vf03(Unk_Pt(8, func_80054F28(p)->y + 0x52));
    func_80063714(p, -1);
    Unk_Short4 v(0, 1);
    v.z = 0;
    v.w = 2;
    func_80054F30(p->unk68, 7, &v, 0);
    func_80054FC0(p->unk68);
    func_800C0814(0, 1);
    func_800631D4(p);
}

EXTERN_C void func_800CD678(Unk_800CD678* p) {
    func_8005457C(p, 0);
    func_8006323C(p);
    func_800C0814(1, 0);
    func_80054FE0(p->unk68);
}

EXTERN_C void func_800CD6BC(Unk_800CD6BC* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_80014E7C;
    self->vt58 = D_800B849C;
    self->vt18 = D_800B84BC;
    self->vb->vptr = (Unk_VTbl10*)&D_800B844C;
    if (!in_chrg) {
        vt = D_800B844C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B844C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x518));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B844C).e[6].delta + adj;
    }
    Unk_destroy(self->unkD4, 8);
    func_80053964(self->unkB8, 2);
    ((void (*)(void*, int))func_80054C34)(self->unk68, 2);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

EXTERN_C Unk_800CD8D8* func_800CD8D8(Unk_800CD8D8* self, int in_chrg, void* a) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80068770(self, 0);
    self->vb->vptr = (Unk_VTbl10*)&D_800B84FC;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B84FC);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B84FC).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x2280));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B84FC).e[6].delta + adj;
    }
    {
        register Unk_800CD8D8* r asm("$2") = self;
        r->vt54 = D_800B856C;
        r->vt58 = D_800B854C;
        r->vt18 = D_800B859C;
        r->unk227C = a;
        return r;
    }
}

EXTERN_C void func_800CD9F0(Unk_800CD9F0* p) {
    func_80068E60(p);
    func_800C2A6C(p->unk227C, func_800689E0(p));
}

EXTERN_C int func_800CDA28(Unk_800CD9F0* p, Unk_FlagArg* q) {
    if (func_8005618C(q)) {
        return 1;
    }
    func_800690C8(p, q);
    if (func_800CDA28_test(q->unk18)) {
        func_800C2A6C(p->unk227C, func_800689E0(p));
    }
    return 1;
}

EXTERN_C void func_800CDAAC(Unk_800CDAAC* p, int flag) {
    p->unk54 = D_800B856C;
    p->unk58 = D_800B854C;
    p->unk18 = D_800B859C;
    p->unk50->vtbl = &D_800B84FC;
    if (!flag) {
        Unk_Vt50_800CDAAC t = D_800B84FC;
        p->unk50->vtbl = &t;
        Unk_Vt50_800CDAAC* v = &D_800B84FC;
        char* x = (char*)p->unk50 - 0x2280;
        t.d8 = v->d8 + ((char*)p - x);
        t.d30 = v->d30 + ((char*)p - x);
    }
    func_80069264(p, 0);
    if (flag & 2) {
        func_8001A610(p->unk50, 0);
    }
    if (flag & 1) {
        operator delete(p);
    }
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7F1C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7F6C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8064);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B806C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B80BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B80DC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B810C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B814C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B825C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B82AC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B82CC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8334);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8350);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B836C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B83BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B83DC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B840C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B844C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B849C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B84BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B84FC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B854C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B856C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B859C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CDBB4);

EXTERN_C void func_800CDE70(Unk_800CDE70* p, int a) {
    p->unk50 = a;
    switch (a) {
    case 0:
        func_80053BCC(p->unk58, (int)D_800B85F4, 8);
        break;
    case 1:
        func_80053BCC(p->unk58, (int)D_800B8608, 6);
        break;
    default:
        func_80053BCC(p->unk58, (int)D_800B8618, 5);
        break;
    }
    func_800CDEEC(p);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CDEEC);

EXTERN_C void func_800CDF68(Unk_800CDF68* p) {
    if (!p->unk140) {
        return;
    }
    Unk_EntTabObj* o = ((Unk_EntOwner*)func_800787B4())->unk328;
    int k = p->unk50;
    Unk_Ent400s* e = (Unk_Ent400s*)base(o)->unk8[k];
    func_8008687C(e, 0);
    if (e->unk410 < p->unk54) {
        e->unk410 = p->unk54;
    } else if (p->unk54 < e->unk410) {
        p->unk54 = e->unk410;
    }
    if (e->unk420 < p->unk56) {
        e->unk420 = p->unk56;
    } else if (p->unk56 < e->unk420) {
        p->unk56 = e->unk420;
    }
    ((VAt<0x9C>*)(Unk_800CDF68_v*)e)->vf01();
    func_80064884(p->unk140, e->unk412, 0);
    if (func_800549C4(p->unkF0, e->unk410)) {
        ((void (*)(void*, int))func_800648E8)(p->unk140, e->unk410);
        func_80054708(p->unkF0, e->unk410);
    }
    p->unk140->vf14();
    func_80064884(p->unk144, e->unk422, 0);
    if (func_800549C4(p->unk118, e->unk420)) {
        ((void (*)(void*, int))func_800648E8)(p->unk144, e->unk420);
        func_80054708(p->unk118, e->unk420);
    }
    p->unk144->vf14();
    func_80054CE4(p);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CE154);

EXTERN_C void func_800CE30C(Unk_800CE30C* p) {
    p->unk140 = 0;
    p->unk144 = 0;
    func_80054FE0(p);
}

EXTERN_C void func_800CE330(char* p, int a) {
    func_80053964(p + 0x118, 2);
    func_80053964(p + 0xF0, 2);
    func_80053964(p + 0xC8, 2);
    func_80053964(p + 0xAC, 2);
    func_80053964(p + 0x90, 2);
    func_80053964(p + 0x74, 2);
    func_80053964(p + 0x58, 2);
    ((void (*)(void*, int))func_80054C34)(p, a);
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B85F4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8608);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8618);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8624);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CE3BC);

EXTERN_C int func_800CE6B8(VAt<0x18>* p) {
    unsigned int t = ((volatile Unk_800A4534*)&D_800A4534)->unkC;
    unsigned int r = func_80062158(D_800B4DD0[0])->unk0;
    if (t / 60 != r) {
        func_80062188(D_800B4DD0[0]);
        func_800CE820((Unk_800CE820*)p);
        p->vf04();
    }
    return 1;
}

EXTERN_C void func_800CE758(Unk_Derived50* p) {
    func_80062188(D_800B4DD0[0]);
    func_800CE820((Unk_800CE820*)p);
    func_8005388C(p, -1);
    func_80054FC0(p);
}

EXTERN_C void func_800CE7AC(Unk_800CE7AC* p) {
    func_80054FE0(p);
    ((VAt<8>*)p)->vf02();
    func_80055624((char*)p + 0x50, 0);
    func_80062160(D_800B4DD0[0]);
}

EXTERN_C void func_800CE820(Unk_800CE820* p) {
    int t = ((Unk_800CE820_g*)D_800B4DD0[0])->unk1C4;
    func_80054708(p->unk5C, t % 60);
    t /= 60;
    if (func_800549D8(p->unk5C) >= 10) {
        func_80053CD8(p->unkD4);
    } else {
        func_80053BCC(p->unkD4, (int)D_800B4D6C, 1);
    }
    func_80054708(p->unk84, t % 60);
    if (func_800549D8(p->unk84) >= 10) {
        func_80053CD8(p->unkF0);
    } else {
        func_80053BCC(p->unkF0, (int)D_800B4D6C, 1);
    }
    func_80054708(p->unkAC, t / 60);
}

EXTERN_C void func_800CE974(char* p, int a) {
    *(void**)(p + 0x58) = D_800B8694;
    *(void**)(p + 0x18) = D_800B8664;
    func_80053964(p + 0x144, 2);
    func_80053964(p + 0x128, 2);
    func_80053964(p + 0x10C, 2);
    func_80053964(p + 0xF0, 2);
    func_80053964(p + 0xD4, 2);
    func_80053964(p + 0xAC, 2);
    func_80053964(p + 0x84, 2);
    func_80053964(p + 0x5C, 2);
    func_800537DC(p + 0x50, 0);
    ((void (*)(void*, int))func_80054C34)(p, a);
}

EXTERN_C Unk_800CEA30* func_800CEA30(Unk_800CEA30* self, int in_chrg, int a, int b, int c) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80062FA4(self, 0, a, 3);
    self->vb->vptr = (Unk_VTbl10*)&D_800B86F4;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B86F4);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B86F4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x1D4));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B86F4).e[6].delta + adj;
    }
    self->vt54 = D_800B8764;
    self->vt58 = D_800B8744;
    self->vt18 = D_800B8794;
    {
        Unk_800CEA30_e* q = self->unk68;
        int n = 2;
        for (; n != -1; n--) {
            func_80062D60(q, 1);
            q++;
        }
    }
    func_800538CC(self->unk1AC, D_800B86B4, 7);
    self->unk1C8 = b;
    self->unk1CC = 0;
    self->unk1D0 = c;
    func_80053BCC(&self->unk68[0], (int)D_800B86C4, 8);
    func_80053BCC(&self->unk68[1], (int)D_800B86D8, 6);
    func_80053BCC(&self->unk68[2], (int)D_800B86E8, 5);
    {
        unsigned int i;
        for (i = 0; i < 3; i++) {
            self->unk68[i].unk5C = 2;
            func_80053F48(&self->unk68[i], Unk_Pt(0xC, i * 0xD + 0x11));
        }
    }
    func_80053F48(self->unk1AC, Unk_Pt(8, 4));
    return self;
}

EXTERN_C void func_800CEC60(Unk_800CEC60* p, int i, int a) { func_80054094(&p->unk68[i], a); }

EXTERN_C int func_800CEC9C(Unk_800CEC9C* p) { return p->unk20; }

EXTERN_C void func_800CECA8(Unk_800CEC60* p) {
    for (unsigned int i = 0; i < D_800B4DD0[0]->unk1FB; i++) {
        Unk_800CECA8_e* e = (Unk_800CECA8_e*)base(((Unk_EntOwner*)func_800787B4())->unk328)->unk8[i];
        func_8008687C(e, 0);
        func_80054094(&p->unk68[i], e->unk410 == e->unk412);
    }
}

EXTERN_C void func_800CED70(Unk_800CEC60* p, Unk_800CED70_q* q) {
    unsigned int i;
    if ((unsigned int)(q->unk1B - 12) < 4) {
        for (i = 0; i < D_800B4DD0[0]->unk1FB; i++) {
            void* e = base(((Unk_EntOwner*)func_800787B4())->unk328)->unk8[i];
            func_80054094(&p->unk68[i], func_8008A5C8(e, e, q) == 0);
        }
    } else {
        for (i = 0; i < D_800B4DD0[0]->unk1FB; i++) {
            func_80054094(&p->unk68[i], 0);
        }
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CEE80);

EXTERN_C void func_800CEFC4(Unk_800CEFC4* p) {
    if (D_800B4DD0[0]->unk1FB >= 2) {
        func_8006323C(p);
    }
    if (p->unk1CC) {
        p->unk1CC = 0;
        func_8005549C(p->unk1C8, p, 0, -1);
    }
}

EXTERN_C int func_800CF028(Unk_800CF028* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (p->unk3C) {
        if (q->unk18 & 0x10) {
            p->unk20 = ((int (*)(void*, int))func_80058270)(p->unk3C, -1);
        } else if (q->unk18 & 0x40) {
            p->unk20 = ((int (*)(void*, int))func_80058270)(p->unk3C, 1);
        } else if ((q->unk18 & 0x2000) && func_80053880(p->unk3C + 0x50)) {
            VAt<0x18>* o = (VAt<0x18>*)func_800550BC(p);
            if (func_8005409C(o)) {
                p->unk1CC = 1;
                o->vf01();
            } else {
                func_8008EF40(0xE);
            }
        }
    }
    return 1;
}

EXTERN_C void func_800CF11C(Unk_800CF11C* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800B8764;
    self->vt58 = D_800B8744;
    self->vt18 = D_800B8794;
    self->vb->vptr = (Unk_VTbl10*)&D_800B86F4;
    if (!in_chrg) {
        vt = D_800B86F4;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B86F4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x1D4));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B86F4).e[6].delta + adj;
    }
    func_80053964(self->unk1AC, 2);
    Unk_destroy(self->unk68, 3);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF32C);

EXTERN_C void func_800CF830() {
    if (D_800EA11C[0]) {
        func_80024FEC((void*)D_800EA11C[0], 0);
        func_8005F5F4(operator new(0x14), (void*)D_800EA11C[0], 2);
        D_800EA11C[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA128[0]);
        delete D_800EA128[0];
        D_800EA128[0] = 0;
        func_80024FEC(D_800EA120[0], 0);
        func_8005F5F4(operator new(0x14), D_800EA120[0], 2);
        D_800EA120[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA12C[0]);
        delete D_800EA12C[0];
        D_800EA12C[0] = 0;
        func_80024FEC(D_800EA124[0], 0);
        func_8005F5F4(operator new(0x14), D_800EA124[0], 2);
        D_800EA124[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA130[0]);
        delete D_800EA130[0];
        D_800EA130[0] = 0;
    }
}

EXTERN_C Unk_800CF9A8* func_800CF9A8(Unk_800CF9A8* self, int in_chrg, unsigned short a) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_8005BC84(self, 0, a, 0x10);
    self->vb->vptr = (Unk_VTbl10*)&D_800B87D4;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B87D4);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B87D4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x38));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B87D4).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B87D4).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B87D4).e[9].delta + adj;
    }
    self->vt2C = D_800B8824;
    if (*(const int*)D_800EA11C == 0) {
        func_800CF32C();
    }
    return self;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CFACC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CFCA4);

EXTERN_C void func_800CFE64(Unk_VbDtor2C* self, int in_chrg) {
    self->vt2C = D_800B8824;
    self->vb0->vptr = (Unk_VTbl10*)&D_800B87D4;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B87D4;
        char* full;
        int adj;
        self->vb0->vptr = &vt;
        vt.e[1].delta = D_800B87D4.e[1].delta + (adj = (char*)self - (full = (char*)self->vb0 - 0x38));
        vt.e[5].delta = D_800B87D4.e[5].delta + adj;
        vt.e[7].delta = D_800B87D4.e[7].delta + adj;
        vt.e[9].delta = D_800B87D4.e[9].delta + adj;
    }
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb0, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CFF6C);

EXTERN_C void func_800D0248() {
    if (D_800EA134[0]) {
        func_80024FEC(D_800EA134[0], 0);
        func_8005F5F4(operator new(0x14), D_800EA134[0], 2);
        D_800EA134[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA13C[0]);
        delete D_800EA13C[0];
        D_800EA13C[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA140[0]);
        delete D_800EA140[0];
        D_800EA140[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA144[0]);
        delete D_800EA144[0];
        D_800EA144[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA138[0]);
        delete D_800EA138[0];
        D_800EA138[0] = 0;
    }
}

EXTERN_C Unk_800D03B0* func_800D03B0(Unk_800D03B0* self, int in_chrg, int b, unsigned short a) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_8005BC84(self, 0, a, 0x10);
    self->vb->vptr = (Unk_VTbl10*)&D_800B891C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B891C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B891C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x3C));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B891C).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B891C).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B891C).e[9].delta + adj;
    }
    self->unk38 = b;
    self->vt2C = D_800B896C;
    if (*(const int*)D_800EA134 == 0) {
        func_800CFF6C();
    }
    return self;
}

EXTERN_C void func_800D04E4(Unk_800D04E4* p, int a, int x, int y) {
    if (p->unk8 && first((Unk_800BFB64_list*)p->unk30)->unk4 > 0) {
        VAt0* o = (VAt0*)func_80019F64(first2(p->unk30), 0);
        o->vf08(p->unk10, p->unk12);
        o->vf07(p->unkC - x, p->unkE - y);
        func_800CC534(o, a);
        o->vf10(x, y);
    }
}

EXTERN_C unsigned char func_800D05FC(Unk_800D05FC* p) { return p->unk38; }

EXTERN_C void func_800D0608(Unk_800D0704* p, Unk_Short2 a, Unk_Short2 b, int c) {
    if (p->unk8) {
        p->vf04();
        p->vf07(a.x, a.y);
        p->vf08(b.x, b.y);
        p->vf03();
        ((VAt0*)func_80019F64(first2(p->unk30), 0))->vf11(c);
    }
}

EXTERN_C void func_800D0704(Unk_800D0704* p, int a) {
    if (p->unk8) {
        p->vf04();
        p->vf03();
        ((VAt0*)func_80019F64(first2(p->unk30), 0))->vf11(a);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D07B8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0878);

EXTERN_C void func_800D09E8(Unk_800D09E8* p) {
    if (p->unk8 && first((Unk_800BFB64_list*)p->unk30)->unk4 > 0) {
        VAt0* o = (VAt0*)func_80019F64(first2(p->unk30), 0);
        o->vf07(p->unkC, p->unkE);
        o->vf08(p->unk10, p->unk12);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0AAC);

EXTERN_C void func_800D0BB4() {
    char o[8];
    func_8005F238(o);
    func_8005F298(o, 0x15085, 0x800);
    D_800EA148 = *(Unk_Blk8D*)func_8005F28C(o);
    func_8005F3E0(o);
    func_8005F248(o, 2);
}

EXTERN_C Unk_800D0CDC* func_800D0CDC(Unk_800D0CDC* self, int in_chrg, int a, int b) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80056364(self, 0, 0, 1);
    self->vb->vptr = (Unk_VTbl10*)&D_800B8A64;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B8A64);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B8A64).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x80));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B8A64).e[6].delta + adj;
    }
    self->vt54 = D_800B8AD4;
    self->vt58 = D_800B8AB4;
    self->vt18 = D_800B8B04;
    self->unk64 = 0;
    self->unk6C = 1;
    self->unk7C = 0;
    func_800D1078(self);
    if (*(signed char*)&D_800EA148 == 0) {
        func_800D0BB4();
    }
    self->unk68 = 0;
    self->unk70 = 0;
    self->unk74 = 0;
    self->unk78 = 0;
    func_800D1004((Unk_800D1004*)self, a);
    Unk_Short4v v(0, 0, 0, 0);
    func_80054F30(self, 0, &v, 0);
    if (b) {
        func_800566E4(self);
        func_8008EF40(0x12);
    }
    return self;
}

EXTERN_C Unk_800D0E90* func_800D0E90(Unk_800D0E90* self, int in_chrg) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80056364(self, 0, 0, 1);
    self->vb->vptr = (Unk_VTbl10*)&D_800B8A64;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B8A64);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B8A64).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x80));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B8A64).e[6].delta + adj;
    }
    self->vt54 = D_800B8AD4;
    self->vt58 = D_800B8AB4;
    self->vt18 = D_800B8B04;
    self->unk64 = 0;
    self->unk6C = 1;
    self->unk7C = 0;
    func_800D1078(self);
    if (*(signed char*)&D_800EA148 == 0) {
        func_800D0BB4();
    }
    self->unk68 = 0;
    self->unk74 = 0;
    self->unk78 = 0;
    Unk_Short4v v(0, 0, 0, 0);
    func_80054F30(self, 0, &v, 0);
    return self;
}

EXTERN_C void func_800D1004(Unk_800D1004* p, int a) {
    if (p->unk3C == 0) {
        p->unk64 = a;
        p->unk68 = 0;
        func_80054EB4(p, 0xD6, 0x84);
    }
}

EXTERN_C void func_800D103C(Unk_800D1004* p, Unk_800D103C_arg* a) {
    if (p->unk3C == 0) {
        p->unk68 = a;
        p->unk64 = a->unk90;
        func_80054EB4(p, 0x130, 0x84);
    }
}

EXTERN_C void func_800D1078(void* p) { func_800557C8(p, 1, 11); }

EXTERN_C void func_800D109C(Unk_800D109C* p) {
    p->unk6C = 1;
    if (p->unk68) {
        func_80053F48(p, Unk_Pt(8, 0x5C));
        func_800566E4(p);
        func_800D1490(p);
        func_8008EF40(0xC);
    }
    func_80054FC0(p);
    if (p->unk70) {
        p->unk70->vf27();
    }
    VAt<0x2C>* o = (VAt<0x2C>*)func_800D18F4((Unk_800D18F4*)operator new(0x4C), 1, 1, 2);
    o->vf07(p->unk68 ? 0xAC : 0x2B, 2);
    Unk_800D109C_t t;
    func_80069D1C(&t, (p->unk64 - 1) * 9 + 0x14BBD, 0x4800);
    func_800D1BA4(o, &t);
    func_80069E60(&t, 2);
    func_8005800C(p->unk3C, o);
    if (p->unk78) {
        p->unk78->vf27();
    }
    p->unk7C = ((volatile Unk_800A4534*)&D_800A4534)->unkC;
}

EXTERN_C void func_800D122C(Unk_800D122C* p) {
    if (p->unk7C > 0) {
        if (!(p->unk7C + 0x14 < ((volatile Unk_800A4534*)&D_800A4534)->unkC)) {
            return;
        }
        p->unk7C = 0;
    }
    if (p->unk68) {
        func_8008EF40(0xD);
    }
    if (p->unk78) {
        func_8002B27C(D_800A4578[0], p->unk78);
        p->unk78 = 0;
    }
    if (p->unk74) {
        func_8002B27C(p->unk70, p->unk74);
        p->unk74 = 0;
        func_8002B27C(D_800A4578[0], p->unk70);
        p->unk70 = 0;
    }
    func_80056874(p);
    func_80054FE0(p);
    func_8005457C(p, 0);
}

EXTERN_C int func_800D1304(Unk_800D1304* p, Unk_FlagArg* q) {
    int f;
    int c;
    unsigned int v;
    if (!p->unk68) {
        return 1;
    }
    if (p->unk7C > 0) {
        if (!((unsigned int)(p->unk7C + 20) < ((volatile Unk_800A4534*)&D_800A4534)->unkC)) {
            return 1;
        }
        p->unk7C = 0;
    }
    func_8001FC78((int)q, 0, 0);
    f = q->unk18;
    if (f & 0x2000) {
        p->vf02();
        return 1;
    }
    c = D_800EA148.v[p->unk68->unk8E];
    if (c < 2) {
        return 1;
    }
    if (f & 0x10) {
        if (p->unk6C < 2) {
            return 1;
        }
        v = p->unk6C - 1;
    } else {
        if (!(f & 0x40)) {
            return 1;
        }
        if (!(p->unk6C < c)) {
            return 1;
        }
        v = p->unk6C + 1;
    }
    p->unk6C = v;
    func_800D1490(p);
    return 1;
}

EXTERN_C int func_800D142C(Unk_800D142C* p, int a) {
    func_8001FC78(a, 0, 0);
    if (p->unk68) {
        return func_80056BA8(p, a);
    }
    return 1;
}

EXTERN_C void func_800D1488() {}

EXTERN_C void func_800D1490(void* p0) {
    Unk_800D1490* p = (Unk_800D1490*)p0;
    Unk_800A4534* g = &D_800A4534;
    VAt<0x2C>* o;
    VAt<0x2C>* q;
    unsigned int i;
    int n;
    p->unk7C = g->unkC;
    if (p->unk74) {
        func_8008EF40(9);
        func_8002B27C(p->unk70, p->unk74);
        p->unk74 = 0;
        func_8002B27C(g->unk44, p->unk70);
        p->unk70 = 0;
    }
    p->unk70 = func_80057368(operator new(0x64), 1);
    func_8002B174(g->unk44, p->unk70, -1);
    o = p->unk70;
    o->vf07(0, 0);
    o->vf08(0x140, 0xF0);
    p->unk70->vf27();
    p->unk70->vf03();
    q = (VAt<0x2C>*)func_800D18F4((Unk_800D18F4*)operator new(0x4C), 1, 1, 2);
    p->unk74 = q;
    q->vf07(0x12, 0x64);
    n = p->unk6C - 1;
    for (i = 1; i < p->unk68->unk8E; i++) {
        n += D_800EA148.v[i];
    }
    {
        char s[0x28];
        func_80069D1C(s, n * 9 + 0x143A7, 0x4800);
        func_800D1BA4(p->unk74, s);
        func_80069E60(s, 2);
    }
    p->unk70->vf29(p->unk74, -1);
    p->unk74->vf03();
    if (D_800EA148.v[p->unk68->unk8E] >= 2) {
        if (p->unk78 == 0) {
            p->unk78 = func_800638A8(operator new(0x64), 1);
            func_8002B174(D_800A4578[0], p->unk78, -1);
            p->unk78->vf27();
            p->unk78->vf3();
        }
        func_80063BE4(p->unk78);
        if (p->unk6C >= 2) {
            func_80063B14(p->unk78, &Unk_Pt(0xA4, 0x58), 3);
        }
        if (p->unk6C < D_800EA148.v[p->unk68->unk8E]) {
            func_80063B14(p->unk78, &Unk_Pt(0xA4, 0xDA), 4);
        }
    }
}

EXTERN_C void func_800D17EC(Unk_800D17EC* p, int f) {
    p->unk54 = D_800B8AD4;
    p->unk58 = D_800B8AB4;
    p->unk18 = D_800B8B04;
    p->unk50->vptr = &D_800B8A64;
    if (f == 0) {
        Unk_Vt10_800D17EC vt = D_800B8A64;
        p->unk50->vptr = &vt;
        char* q = (char*)p->unk50 - 0x80;
        vt.e[1].delta = D_800B8A64.e[1].delta + ((char*)p - q);
        vt.e[6].delta = D_800B8A64.e[6].delta + ((char*)p - q);
    }
    func_8005652C(p, 0);
    if (f & 2) {
        func_8001A610(p->unk50, 0);
    }
    if (f & 1) {
        operator delete(p);
    }
}

EXTERN_C Unk_800D18F4* func_800D18F4(Unk_800D18F4* self, int in_chrg, int b, unsigned short a) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_8005BC84(self, 0, a, 0x10);
    self->vb->vptr = (Unk_VTbl10*)&D_800B8C3C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B8C3C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B8C3C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x44));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B8C3C).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B8C3C).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B8C3C).e[9].delta + adj;
    }
    {
        register Unk_800D18F4* r asm("$2") = self;
        r->vt2C = D_800B8B44;
        r->unk38 = b;
        r->unk3C = 0;
        r->unk40 = 0;
        return r;
    }
}

EXTERN_C void func_800D1A1C(Unk_800D1A1C* self, int in_chrg) {
    self->vt2C = D_800B8B44;
    self->vb->vptr = (Unk_VTbl10*)&D_800B8C3C;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B8C3C;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B8C3C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x44));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B8C3C).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B8C3C).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B8C3C).e[9].delta + adj;
    }
    if (self->unk3C) {
        func_80024FEC(self->unk3C, 0);
        func_8005F5F4(operator new(0x14), self->unk3C, 2);
        self->unk3C = 0;
    }
    if (self->unk40) {
        func_800215E8(D_800B4C38[0], self->unk40);
        delete self->unk40;
        self->unk40 = 0;
    }
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1BA4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1DAC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D203C);

EXTERN_C void func_800D2214(Unk_800D2214* p, Unk_800D2214_q* q) {
    int b = D_800B4CF0[0];
    int u;
    p->unk10[b].tpage = q->unk1C;
    if (!q->unkC) {
        u = q->unk10 & 0x3F;
    } else if (q->unkC->vf02()) {
        u = (q->unk10 << 1) & 0x7F;
    } else {
        u = q->unk10 << 2;
    }
    p->unkA8 = Unk_800D2214_uv(u, q->unk12);
    p->unk10[b].clut = q->unkC->unk8;
    func_8005F1D8(p);
}

EXTERN_C void func_800D2310(Unk_Gt4_10* p, int dx, int dy) {
    int i = D_800B4CF0[0];
    p->unk10[i].x0 += dx;
    p->unk10[i].y0 += dy;
    p->unk10[i].x1 += dx;
    p->unk10[i].y1 += dy;
    p->unk10[i].x2 += dx;
    p->unk10[i].y2 += dy;
    p->unk10[i].x3 += dx;
    p->unk10[i].y3 += dy;
    func_8005F1D8(p);
}

EXTERN_C void func_800D23AC(Unk_Gt4_10* p, Unk_ColorSrc* c) {
    int i = D_800B4CF0[0];
    unsigned char r = c->unk5, g = c->unk6, b = c->unk7;
    p->unk10[i].r0 = r; p->unk10[i].g0 = g; p->unk10[i].b0 = b;
    p->unk10[i].r1 = r; p->unk10[i].g1 = g; p->unk10[i].b1 = b;
    p->unk10[i].r2 = r; p->unk10[i].g2 = g; p->unk10[i].b2 = b;
    p->unk10[i].r3 = r; p->unk10[i].g3 = g; p->unk10[i].b3 = b;
    func_8005F1D8(p);
}

EXTERN_C void func_800D2424(void* p) { func_800D29D8(operator new(0xAC), p); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2458);

EXTERN_C void func_800D24F4(Unk_Gt4_10* p, int x, int y) {
    p->vf10(x - p->unk10[D_800B4CF0[0]].x0, y - p->unk10[D_800B4CF0[0]].y0);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2554);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D277C);

EXTERN_C void func_800D2908(Unk_Gt4_10* p, Unk_S3 c0, Unk_S3 c1, Unk_S3 c2, Unk_S3 c3) {
    int i = D_800B4CF0[0];
    p->unk10[i].r0 = c0.r;
    p->unk10[i].g0 = c0.g;
    p->unk10[i].b0 = c0.b;
    p->unk10[i].r1 = c1.r;
    p->unk10[i].g1 = c1.g;
    p->unk10[i].b1 = c1.b;
    p->unk10[i].r2 = c2.r;
    p->unk10[i].g2 = c2.g;
    p->unk10[i].b2 = c2.b;
    p->unk10[i].r3 = c3.r;
    p->unk10[i].g3 = c3.g;
    p->unk10[i].b3 = c3.b;
    func_8005F1D8(p);
}

EXTERN_C void* func_800D29D8(void* dv, void* sv) {
    Unk_800D29D8* d = (Unk_800D29D8*)dv;
    Unk_800D29D8* s = (Unk_800D29D8*)sv;
    d->vtbl = D_80010178;
    d->unk4 = s->unk4;
    d->vtbl = D_800111BC;
    d->unk8 = s->unk8;
    {
        short a = s->unkA;
        d->vtbl = D_80014BD0;
        d->unkA = a;
    }
    {
        int c = s->unkC;
        d->vtbl = D_800B8C8C;
        d->unkC = c;
    }
    {
        POLY_GT4* dp = d->unk10;
        int n = 1;
        POLY_GT4* sp = s->unk10;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    {
        Unk_W3* dp = d->unk78;
        int n = 1;
        Unk_W3* sp = s->unk78;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    {
        Unk_W3* dp = d->unk90;
        int n = 1;
        Unk_W3* sp = s->unk90;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    d->unkA8 = s->unkA8;
    return d;
}

EXTERN_C void func_800D2B10(void* p, int a) { func_8005F120(p, a); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2B30);

EXTERN_C void func_800D2DD8(Unk_800D2DD8* self, int in_chrg) {
    self->vt2C = D_800B8CF4;
    self->vb->vptr = (Unk_VTbl10*)&D_800B8DEC;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B8DEC;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B8DEC).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x40));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B8DEC).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B8DEC).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B8DEC).e[9].delta + adj;
    }
    func_80024FEC(self->unk38, 0);
    func_8005F5F4(operator new(0x14), self->unk38, 2);
    self->unk38 = 0;
    func_800215E8(*(const int*)D_800B4C38, self->unk3C);
    delete self->unk3C;
    self->unk3C = 0;
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2F48);

EXTERN_C void func_800D3090(Unk_800D3090* p, void* a) {
    if (p->unk8) {
        func_8005C088(p, a, 1);
        {
            Unk_800BFB64_node* n = first(p->unk30);
            func_80019A6C(n, (int)func_800CC28C(operator new(0x64), &Unk_800D3090_r(0x6C, 0x68, 0x70, 0x7F), (void*)p->unk38, &Unk_Pt(0, 0), p->unk1C), n->unk4);
        }
        {
            Unk_800BFB64_node* n = first(p->unk30);
            func_80019A6C(n, (int)func_800CC28C(operator new(0x64), &Unk_800D3090_r(0xDC, 0x68, 0x7F, 0x7F), (void*)p->unk38, &Unk_Pt(0, 0x80), p->unk1C), n->unk4);
        }
        func_8002DA94(a, p->unk30);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D31E8);

EXTERN_C void func_800D3534() {
    if (D_800EA1E0[0]) {
        func_80024FEC(D_800EA1E0[0], 0);
        func_8005F5F4(operator new(0x14), D_800EA1E0[0], 2);
        D_800EA1E0[0] = 0;
        func_80024FEC(D_800EA1E4[0], 0);
        func_8005F5F4(operator new(0x14), D_800EA1E4[0], 2);
        D_800EA1E4[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA1E8[0]);
        delete D_800EA1E8[0];
        D_800EA1E8[0] = 0;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D35F8);

EXTERN_C void func_800D3AC8(Unk_800D3AC8* p, int a) {
    p->unk18 = D_800B8E3C;
    p->vtbl = D_800B8E5C;
    func_800D3D54((Unk_800D3D54*)p);
    func_800537DC(p->unk10, 0);
    func_8005F120(p, a);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3B28);

EXTERN_C int func_800D3C50(Unk_800D3C50* p) {
    int a = func_80053874(p);
    int v = a * (0x1F - func_80053874(p));
    p->unk110[p->unk1C + D_800B4CF0[0]].unkC = v;
    p->unk110[p->unk1C + D_800B4CF0[0]].unkD = v / 4;
    p->unk110[p->unk1C + D_800B4CF0[0]].unkE = v / 4;
    if (!func_80053830(p)) {
        func_8005388C(p, 0x1F);
    }
    func_8005F1D8(p);
    return 1;
}

EXTERN_C void func_800D3D54(Unk_800D3D54* p) {
    func_80055624((char*)p + 0x10, 0);
    func_80053848(p);
    if (p->unk1C >= 0) {
        p->unk110[p->unk1C + D_800B4CF0[0]].unkD = 0;
        p->unk110[p->unk1C + D_800B4CF0[0]].unkE = 0;
        func_8005F1D8(p);
    }
}

EXTERN_C void func_800D3DE8(Unk_800D3DE8* p, int dx, int dy) {
    int b = D_800B4CF0[0];
    unsigned int i;
    for (i = 0; i < 0x60; i += 2) {
        p->unk118[b + i].x0 += dx;
        p->unk118[b + i].y0 += dy;
    }
    for (i = 0; i < 10; i += 2) {
        p->unk50[b + i].x0 += dx;
        p->unk50[b + i].y0 += dy;
    }
    p->unk718[b].x0 += dx;
    p->unk718[b].y0 += dy;
    func_8005F1D8(p);
}

EXTERN_C void func_800D3EAC(Unk_800D3EAC* p, Unk_800D3EAC_c* c) {
    unsigned int i;
    int d = D_800B4CF0[0];
    int r = c->r;
    int g = c->g;
    int b = c->b;
    for (i = 0; i < 10; i += 2) {
        p->unk50[d + i].r0 = r * 29 / 16;
        p->unk50[d + i].g0 = g * 15 / 8;
        p->unk50[d + i].b0 = b * 14 / 8;
    }
    for (i = 0; i < 0x60; i += 2) {
        p->unk118[i + d].r0 = r * 3 / 8;
        p->unk118[i + d].b0 = r * 3 / 16;
    }
    if (p->unk1C >= 0) {
        p->unk118[p->unk1C + d].r0 = r * 184 / 128;
        p->unk118[p->unk1C + d].b0 = 0;
        p->unk718[d].r0 = r * 2;
        p->unk718[d].g0 = r * 2;
        p->unk718[d].b0 = r;
    }
    func_8005F1D8(p);
}

EXTERN_C void func_800D401C(Unk_Sprt50* p, int x, int y) {
    p->vf10(x - p->unk50[D_800B4CF0[0]].x0, y - p->unk50[D_800B4CF0[0]].y0);
}

EXTERN_C void func_800D4074(void* p) { func_800D44D4(operator new(0x738), p); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D40A8);

EXTERN_C void func_800D44CC() {}

EXTERN_C void* func_800D44D4(void* dv, void* sv) {
    Unk_800D44D4* d = (Unk_800D44D4*)dv;
    Unk_800D44D4* s = (Unk_800D44D4*)sv;
    d->vtbl = D_80010178;
    d->unk4 = s->unk4;
    d->vtbl = D_800111BC;
    d->unk8 = s->unk8;
    {
        short a = s->unkA;
        d->vtbl = D_80014BD0;
        d->unkA = a;
    }
    d->unkC = s->unkC;
    {
        Unk_800D44D4_b* sb = s;
        Unk_800D44D4_b* db = (Unk_800D44D4_b*)((char*)d + 0x10);
        db->vt = D_80013B00;
        db->a = sb->a;
        db->b = sb->b;
    }
    d->vt = D_800B8E3C;
    d->vtbl = D_800B8E5C;
    d->unk1C = s->unk1C;
    {
        Unk_W3* dp = d->unk20;
        int n = 3;
        Unk_W3* sp = s->unk20;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    {
        Unk_W5* dp = d->unk50;
        int n = 9;
        Unk_W5* sp = s->unk50;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    {
        Unk_W4* dp = d->unk118;
        int n = 95;
        Unk_W4* sp = s->unk118;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    {
        Unk_W4* dp = d->unk718;
        int n = 1;
        Unk_W4* sp = s->unk718;
        for (; n != -1; n--) {
            *dp = *sp;
            dp++;
            sp++;
        }
    }
    return d;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D4674);

EXTERN_C void func_800D48FC() {
    if (D_800EA2DC[0]) {
        func_80024FEC(D_800EA2DC[0], 0);
        func_8005F5F4(operator new(0x14), D_800EA2DC[0], 2);
        D_800EA2DC[0] = 0;
        func_80024FEC((void*)D_800EA2E0[0], 0);
        func_8005F5F4(operator new(0x14), (void*)D_800EA2E0[0], 2);
        D_800EA2E0[0] = 0;
        func_800215E8(D_800B4C38[0], D_800EA2E4[0]);
        delete D_800EA2E4[0];
        D_800EA2E4[0] = 0;
    }
}

EXTERN_C int func_800D49C0() { return D_800EA2E0[0]; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D49D0);

EXTERN_C void func_800D4B84(Unk_Sprt28* p, int dx, int dy) {
    int i = D_800B4CF0[0];
    p->unk28[i].x0 += dx;
    p->unk28[i].y0 += dy;
    p->unk28[i + 2].x0 += dx;
    p->unk28[i + 2].y0 += dy;
    func_8005F1D8(p);
}

EXTERN_C void func_800D4BFC(Unk_800D4BFC* p, Unk_ColorSrc* c) {
    int b = D_800B4CF0[0];
    for (unsigned int i = 0; i < 4; i += 2) {
        int k = b + i;
        p->unk28[k].r0 = c->unk5;
        p->unk28[k].g0 = c->unk6;
        p->unk28[k].b0 = c->unk7;
    }
    func_8005F1D8(p);
}

EXTERN_C void func_800D4C68(Unk_Sprt28* p, int x, int y) {
    p->vf10(x - p->unk28[D_800B4CF0[0]].x0, y - p->unk28[D_800B4CF0[0]].y0);
}

EXTERN_C Unk_800D4CC0* func_800D4CC0(Unk_800D4CC0* s) {
    Unk_800D4CC0* o = (Unk_800D4CC0*)operator new(0x78);
    o->vtbl = D_80010178;
    o->unk4 = s->unk4;
    o->vtbl = D_800111BC;
    o->unk8 = s->unk8;
    o->unkA = s->unkA;
    o->vtbl = D_80014BD0;
    o->unkC = s->unkC;
    o->vtbl = D_800B8EC4;
    {
        Unk_W3* d = o->unk10;
        int n = 1;
        Unk_W3* q = s->unk10;
        do {
            *d = *q;
            d++;
            q++;
        } while (--n != -1);
    }
    {
        Unk_W5_800D4CC0* d = o->unk28;
        int n = 3;
        Unk_W5_800D4CC0* q = s->unk28;
        do {
            *d = *q;
            d++;
            q++;
        } while (--n != -1);
    }
    return o;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D4DC4);

EXTERN_C void func_800D4FC4() {}

EXTERN_C void func_800D4FCC(void* p, int a) { func_8005F120(p, a); }

EXTERN_C void func_800D4FEC(Unk_Blk2B0* s) {
    D_800EA2E8 = *s;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D508C);

EXTERN_C void func_800D56BC(Unk_800D56BC* p, int a) { p->unkA40 = a; }

EXTERN_C void func_800D56C4(void* p) { func_800557C8(p, 1, 10); }

EXTERN_C void func_800D56E8(Unk_800D56E8* p) {
    p->unk5C = 1;
    func_800D5E24(p);
    func_8005457C(p, 1);
    Unk_Pt t(0x30, 0xD0);
    p->vf03(t);
    p->unkB3C = 0;
    p->unkB38 = 1;
    func_800631D4(p);
    func_800588C8(p->unk3C);
    func_800C0860(0);
    func_80053BCC(p->unkAE4, (int)(func_80061188(D_800B4DD0[0], p->unkA40) + 0x1C), 0);
    func_800540A8(p->unkAE4);
    func_80054FC0(p->unkA44);
    func_80053BCC(p->unkB00, (int)(func_80061188(D_800B4DD0[0], p->unkA40) + 0x1C), 1);
    func_80053C6C(p->unkB1C, p->unkB00);
    for (int n = func_80053BB4(p->unkB00) - 1; n > 0; n--) {
        func_80053B68(p->unkB1C);
    }
    for (unsigned int i = 0; i < 12; i++) {
        func_800601D8(&t, D_800B8F2C);
        func_800539D0(p->unkB1C, &t);
    }
    func_80054FC0(p->unkA94);
}

EXTERN_C void func_800D5844(Unk_800D5844* p) {
    func_80054FE0(p->unkA44);
    func_80054FE0(p->unkA94);
    func_800C0860(1);
    func_8006323C(p);
    func_8005457C(p, 0);
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8664);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8694);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B86B4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B86C4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B86D8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B86E8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B86F4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8744);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8764);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8794);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B87D4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8824);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B891C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B896C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8A64);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8AB4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8AD4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8B04);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8B44);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8C3C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8C8C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8CF4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8DEC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8E3C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8E5C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8EC4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8F2C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D5890);

EXTERN_C int func_800D5C60(void* p, Unk_800D5C60_arg* q) {
    if (!func_800557A0(p)) {
        int f = ~q->unk1A;
        int k;
        if (f & 0x10) {
            k = 3;
        } else if (f & 0x40) {
            k = 4;
        } else if (f & 0x20) {
            k = 5;
        } else if (f & 0x80) {
            k = 6;
        } else {
            goto end;
        }
        func_8005549C(k, p, 0, -1);
    }
end:
    return 1;
}

EXTERN_C int func_800D5CEC(Unk_800D5CEC* p, Unk_FlagArg* q) {
    int r;
    func_8001FC78((int)q, 0, 0);
    r = 0;
    if (!func_8005618C(q)) {
        if ((p->unk3C == 0 || func_80053880(p->unk3C + 0x50)) && (q->unk18 & 0x4000)) {
            r = 1;
        }
    }
    if (r) {
        p->vf02();
    }
    return 1;
}

EXTERN_C int func_800D5DA4(void* p, int a) {
    int k;
    switch (a) {
    case 5: k = 1; break;
    case 3: k = 2; break;
    case 6: k = 3; break;
    case 4: k = 4; break;
    default: return 0;
    }
    func_800D5F94(p, k);
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D5E24);

EXTERN_C void func_800D5EFC(Unk_800D5EFC* p) {
    switch (p->unkB38) {
    case 4:
        func_8005816C(p->unk3C, p->unkB3C + 0x3E);
        break;
    case 3:
        func_8005816C(p->unk3C, p->unkB3C + 0x34);
        break;
    case 2:
        func_8005816C(p->unk3C, p->unkB3C + 0x1A);
        break;
    default:
        func_8005816C(p->unk3C, p->unkB3C);
        break;
    }
    func_8008EF40(8);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D5F94);

EXTERN_C void func_800D633C(Unk_800D633C* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800B8FA4;
    self->vt58 = D_800B8F84;
    self->vt18 = D_800B8FD4;
    self->vb->vptr = (Unk_VTbl10*)&D_800B8F34;
    if (!in_chrg) {
        vt = D_800B8F34;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B8F34).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xB44));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B8F34).e[6].delta + adj;
    }
    func_80053964(self->unkB1C, 2);
    func_80053964(self->unkB00, 2);
    func_80053964(self->unkAE4, 2);
    ((void (*)(void*, int))func_80054C34)(self->unkA94, 2);
    ((void (*)(void*, int))func_80054C34)(self->unkA44, 2);
    Unk_destroy(self->unk9D0, 4);
    Unk_destroy(self->unk8B8, 10);
    Unk_destroy(self->unk5E0, 26);
    Unk_destroy(self->unk68, 50);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_800D6654(Unk_C20A* p) {
    D_800EA598 = *p;
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8F34);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8F84);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8FA4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8FD4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D6720);

EXTERN_C void func_800D6D44(Unk_800CD3C8* p) {
    func_800557C8(p, 1, 1);
    func_80053C6C(p->unkB8, p);
    func_8005457C(p->unkB8, 0);
    func_80053FB0(p->unkB8, 0, 0x130);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D6DA4);

EXTERN_C void func_800D72B8(Unk_800D72B8* p) {
    func_80055330(0);
    ((void (*)(void*, int, const Unk_R_800D72B8&, int))func_80054F30)(p->unk68, 7, Unk_R_800D72B8(0, 1, 0, 2), 0);
    func_80054FC0(p->unk68);
    func_8005457C(p, 1);
    func_800566E4(p);
    if (!p->unkD8) {
        func_800D7B6C((Unk_800D7B6C*)p);
        func_800D7F10((Unk_800D7F10*)p);
        func_800D7FB4((Unk_800D7FB4*)p);
    }
    if (!p->unk100) {
        p->unk100 = ((void* (*)(void*, int, const Unk_R_800D72B8&, int))func_800646FC)(operator new(0x58), 1, Unk_R_800D72B8(0x1C, 0x3B, 0x4C, 4), 2);
        p->unk104 = ((void* (*)(void*, int, const Unk_R_800D72B8&, int))func_800646FC)(operator new(0x58), 1, Unk_R_800D72B8(0x1C, 0x4F, 0x4C, 4), 2);
        p->unkFC = (VAt<0x2C>*)func_800D8FD4((Unk_800D8FD4*)operator new(0x44), 1, 2);
    }
    p->unkFC->vf07(0x10, 4);
    p->vf04();
    func_80054FC0(p);
    func_8005800C(p->unk3C, p->unkFC);
    func_8005800C(p->unk3C, p->unk100);
    func_8005800C(p->unk3C, p->unk104);
    p->unkD4 = 0;
    p->unkD8->vf01();
    func_800C0860(0);
    func_800C0814(0, 0);
    func_800C0890(0);
    if (!p->unkF8) {
        p->unkF8 = func_800638A8(operator new(0x64), 1);
        func_8002B174(D_800A4578[0], p->unkF8, -1);
        p->unkF8->vf27();
        ((void (*)(void*, const Unk_Pt&, int))func_80063B14)(p->unkF8, Unk_Pt(4, 0xBA), 1);
        ((void (*)(void*, const Unk_Pt&, int))func_80063B14)(p->unkF8, Unk_Pt(0x132, 0xBA), 2);
        p->unkF8->vf3();
    }
    p->unk64 = ((volatile Unk_800A4534*)&D_800A4534)->unkC;
    func_8008EF40(0xC);
}

EXTERN_C void func_800D75B4(Unk_800D75B4* p) {
    unsigned int i = 0;
    func_8005457C(p, 0);
    func_8002B27C(D_800A4578[0], p->unkF8);
    p->unkF8 = 0;
    func_800C0890(1);
    func_800C0814(1, 0);
    func_800C0860(1);
    func_80054FE0(p);
    for (; i < 4; i++) {
        p->unkD8[i]->vf02();
        delete p->unkD8[i];
        p->unkD8[i] = 0;
    }
    delete[] p->unk10C;
    p->unk10C = 0;
    delete[] p->unk110;
    p->unk110 = 0;
    delete[] p->unk114;
    p->unk114 = 0;
    p->unkFC = 0;
    p->unk100 = 0;
    p->unk104 = 0;
    func_80056874(p);
    func_80054FE0(p->unk68);
    func_8008EF40(0xD);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D77F8);

EXTERN_C void func_800D7AE8() {}

EXTERN_C int func_800D7AF0(Unk_800D7AF0* p, int a) {
    switch (a) {
    case 1:
        delete p->unk108;
        p->unk108 = 0;
        return 1;
    case 0:
        func_800553D8(0);
        return 1;
    }
    return 0;
}

EXTERN_C void func_800D7B6C(Unk_800D7B6C* p) {
    unsigned int i;
    p->unkD8 = func_800694BC(operator new(0x2C4), 1, 0x12, 1);
    p->unkD8->vf03(Unk_Pt(8, 0x88));
    func_80054EB4(p->unkD8, 0x130, 0x58);
    p->unk10C = new Unk_800D7B6C_a[2];
    func_80053BCC(p->unk10C, (int)D_800B9078, 4);
    func_80053BCC(&p->unk10C[1], (int)D_800B9084, 4);
    func_80053F48(&p->unk10C[0], Unk_Pt(0x18, 0x40));
    func_80053F48(&p->unk10C[1], Unk_Pt(0x98, 0x40));
    func_80054E18(p->unkD8, &p->unk10C[0]);
    func_80054E18(p->unkD8, &p->unk10C[1]);
    p->unk110 = new Unk_800D7B6C_b[10];
    p->unk114 = new Unk_800D7B6C_b[8];
    func_800549EC(&p->unk110[8], 1000000);
    func_80053F48(&p->unk110[8], Unk_Pt(0x3C, 0x40));
    func_80054E18(p->unkD8, &p->unk110[8]);
    func_800549EC(&p->unk110[9], 1000000);
    func_80053F48(&p->unk110[9], Unk_Pt(0xBC, 0x40));
    func_80054E18(p->unkD8, &p->unk110[9]);
    for (i = 0; i < 8; i++) {
        int x = (i & 1) << 7;
        int y = (i >> 1) * 13 + 10;
        func_8005408C(&p->unk110[i], 2);
        func_80053F48(&p->unk110[i], Unk_Pt(x + 0x48, y));
        func_80054E18(p->unkD8, &p->unk110[i]);
        func_8005408C(&p->unk114[i], 2);
        func_800549E4(&p->unk114[i], 1);
        func_80053F48(&p->unk114[i], Unk_Pt(x + 0x68, y));
        func_80054E18(p->unkD8, &p->unk114[i]);
    }
    func_80069978(p->unkD8, Unk_PtS(0x18, 0xA), 0x6C, 0x80, 0xD);
}

EXTERN_C void func_800D7F10(Unk_800D7F10* p) {
    void* o = operator new(0x7C);
    {
        char s[0x20];
        func_800538CC(s, D_800EA76C, 6);
        p->unkDC = func_800D82E0(o, s, 10, 16);
        func_80053964(s, 2);
    }
    p->unkDC->vf03(Unk_Pt(8, 0x88));
}

EXTERN_C void func_800D7FB4(Unk_800D7FB4* p) {
    Unk_800D7F10_o* r;
    {
        void* o = operator new(0x7C);
        char s[0x20];
        func_800538CC(s, D_800EA77E, 5);
        Unk_800D7F10_o* t = func_800D82E0(o, s, 8, 0x58);
        func_80053964(s, 2);
        r = t;
    }
    r->vf03(Unk_Pt(8, 0x88));
    p->unkE0 = r;
    {
        void* o = operator new(0x7C);
        char s[0x20];
        func_800538CC(s, D_800EA77E + 0x12, 5);
        Unk_800D7F10_o* t = func_800D82E0(o, s, 7, 0x58);
        func_80053964(s, 2);
        r = t;
    }
    r->vf03(Unk_Pt(8, 0x88));
    p->unkE4 = r;
}

EXTERN_C void func_800D80F0(Unk_800D80F0* self, int in_chrg) {
    self->vt54 = D_800B9104;
    self->vt58 = D_800B90E4;
    self->vt18 = D_800B9134;
    self->vb->vptr = (Unk_VTbl10*)&D_800B9094;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B9094;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B9094).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x2DC));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B9094).e[6].delta + adj;
    }
    Unk_destroy(self->unk26C, 4);
    func_80053964(self->unk244, 2);
    func_80053964(self->unk21C, 2);
    func_80053964(self->unk1F4, 2);
    func_80053964(self->unk1CC, 2);
    func_80053964(self->unk1A4, 2);
    func_80053964(self->unk188, 2);
    func_80053964(self->unk16C, 2);
    func_80053964(self->unk150, 2);
    func_80053964(self->unk134, 2);
    func_80053964(self->unk118, 2);
    func_80053964(self->unkB8, 2);
    ((void (*)(void*, int))func_80054C34)(self->unk68, 2);
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9078);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9084);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9094);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B90E4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9104);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9134);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D82E0);

EXTERN_C void func_800D876C(Unk_800D876C* p, int flag) {
    p->vtbl18 = D_800B917C;
    delete[] p->unk6C;
    p->unk6C = 0;
    delete[] p->unk70;
    p->unk70 = 0;
    delete[] p->unk74;
    p->unk74 = 0;
    delete[] p->unk78;
    p->unk78 = 0;
    func_80053964(p->unk50, 2);
    ((void (*)(void*, int))func_80054C34)(p, flag);
}

EXTERN_C void func_800D8970(Unk_800D8970* p, int i, void* a) { func_80053C6C(&p->unk70[i], a); }

EXTERN_C void func_800D89A4(Unk_800D8970* p, int i, int a, int b) {
    func_80054708(&p->unk74[i], a + 1);
    func_80054708(&p->unk78[i], b);
}

EXTERN_C Unk_800D8A04* func_800D8A04(Unk_800D8A04* self, int in_chrg, int a, int b) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80056364(self, 0, 0, 1);
    self->vb->vptr = (Unk_VTbl10*)&D_800B91AC;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B91AC);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B91AC).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x78));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B91AC).e[6].delta + adj;
    }
    {
        register Unk_800D8A04* r asm("$2") = self;
        r->vt54 = D_800B921C;
        r->vt58 = D_800B91FC;
        r->vt18 = D_800B924C;
        r->unk64 = a;
        r->unk68 = b;
        r->unk74 = 0;
        r->unk6C = 0;
        r->unk70 = 0;
        return r;
    }
}

EXTERN_C void func_800D8B40(Unk_800D8B40* p) {
    VAt<0x2C>* o;
    unsigned int i;
    func_800566E4(p);
    p->unk74 = 0;
    p->unk6C = func_80057368(operator new(0x64), 1);
    func_8002B174(D_800A4578[0], p->unk6C, -1);
    o = p->unk6C;
    o->vf07(0, 0);
    o->vf08(0x140, 0xF0);
    p->unk6C->vf27();
    p->unk6C->vf03();
    p->unk70 = (void*)func_800D98D0((Unk_800D98D0*)operator new(0x48), 1, 2);
    p->unk6C->vf29(p->unk70, -1);
    func_800D9AF8(p->unk70, p->unk68);
    func_8008EF40(0xC);
    for (i = 0; i < 20; i++) {
        func_8005556C(2, 1);
    }
    p->unk74 = 1;
}

EXTERN_C void func_800D8CA4(Unk_800D8CA4* p) {
    func_8002B27C(p->unk6C, p->unk70);
    p->unk70 = 0;
    func_8002B27C(D_800A4578[0], p->unk6C);
    p->unk6C = 0;
    p->unk74 = 0;
    func_80056874(p);
    func_8005549C(1, p, 0, -1);
    func_8008EF40(13);
}

EXTERN_C int func_800D8D18(Unk_800D8D18* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (p->unk74) {
        unsigned int i;
        if (q->unk18 & 0x80) {
            if (p->unk68 < 2) {
                p->unk68 = p->unk64 + 1;
            }
            func_800D9AF8(p->unk70, --p->unk68);
            func_8008EF40(9);
            p->unk74 = 0;
            for (i = 0; i < 4; i++) {
                func_8005556C(2, 1);
            }
            p->unk74 = 1;
        } else if (q->unk18 & 0x20) {
            if (!(p->unk68 < p->unk64)) {
                p->unk68 = 0;
            }
            func_800D9AF8(p->unk70, ++p->unk68);
            func_8008EF40(9);
            p->unk74 = 0;
            for (i = 0; i < 4; i++) {
                func_8005556C(2, 1);
            }
            p->unk74 = 1;
        }
    }
    return 1;
}

EXTERN_C int func_800D8E4C(Unk_800D8E4C* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (p->unk74 && (q->unk18 & 0x4000)) {
        p->vf02();
    }
    return 1;
}

EXTERN_C void func_800D8ECC(Unk_800D8ECC* p, int flag) {
    p->unk54 = D_800B921C;
    p->unk58 = D_800B91FC;
    p->unk18 = D_800B924C;
    p->unk50->vtbl = &D_800B91AC;
    if (!flag) {
        Unk_Vt50_800D8ECC t = D_800B91AC;
        p->unk50->vtbl = &t;
        Unk_Vt50_800D8ECC* v = &D_800B91AC;
        char* x = (char*)p->unk50 - 0x78;
        t.d8 = v->d8 + ((char*)p - x);
        t.d30 = v->d30 + ((char*)p - x);
    }
    func_8005652C(p, 0);
    if (flag & 2) {
        func_8001A610(p->unk50, 0);
    }
    if (flag & 1) {
        operator delete(p);
    }
}

EXTERN_C Unk_800D8FD4* func_800D8FD4(Unk_800D8FD4* self, int in_chrg, unsigned short a) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_8005BC84(self, 0, a, 0x10);
    self->vb->vptr = (Unk_VTbl10*)&D_800B928C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B928C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B928C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x3C));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B928C).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B928C).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B928C).e[9].delta + adj;
    }
    {
        register Unk_800D8FD4* r asm("$2") = self;
        r->vt2C = D_800B92DC;
        r->unk38 = 0;
        return r;
    }
}

EXTERN_C void func_800D90E8(Unk_800D90E8* p, int a) {
    if (p->unk38 != a) {
        int r;
        p->unk38 = a;
        r = p->vf11();
        if (r) {
            p->vf13(r);
        }
    }
}

EXTERN_C void func_800D915C(Unk_800D915C* p, void* a) {
    if (p->unk8) {
        Unk_800BFB64_node* n;
        func_8005C088(p, a, 1);
        n = first(p->unk30);
        func_80019A6C(n, (int)func_800D9300(operator new(0x50), p->unk38, p->unkC, p->unk1C), n->unk4);
        func_8002DA94(a, p->unk30);
    }
}

EXTERN_C void func_800D91F0() {}

EXTERN_C void func_800D91F8(Unk_VbDtor2C* self, int in_chrg) {
    self->vt2C = D_800B92DC;
    self->vb0->vptr = (Unk_VTbl10*)&D_800B928C;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B928C;
        char* full;
        int adj;
        self->vb0->vptr = &vt;
        vt.e[1].delta = D_800B928C.e[1].delta + (adj = (char*)self - (full = (char*)self->vb0 - 0x3C));
        vt.e[5].delta = D_800B928C.e[5].delta + adj;
        vt.e[7].delta = D_800B928C.e[7].delta + adj;
        vt.e[9].delta = D_800B928C.e[9].delta + adj;
    }
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb0, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D9300);

EXTERN_C void func_800D9404(Unk_Sprt28* p, int x, int y) {
    int i = D_800B4CF0[0];
    p->unk28[i].x0 += x;
    p->unk28[i].y0 += y;
    func_8005F1D8(p);
}

EXTERN_C void func_800D9450(Unk_Sprt28* p, Unk_ColorSrc* c) {
    int i = D_800B4CF0[0];
    unsigned char r = c->unk5;
    unsigned char g = c->unk6;
    unsigned char b = c->unk7;
    p->unk28[i].r0 = r;
    p->unk28[i].g0 = g;
    p->unk28[i].b0 = b;
    func_8005F1D8(p);
}

EXTERN_C void func_800D949C(Unk_Sprt28* p, int x, int y) {
    p->vf10(x - p->unk28[D_800B4CF0[0]].x0, y - p->unk28[D_800B4CF0[0]].y0);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D94F4);

EXTERN_C int func_800D95F8(Unk_800D95F8* p) {
    if (func_8005F1B4(p)) {
        int b = D_800B4CF0[0];
        Unk_Dr20_800D95F8* src = &p->unk28[b ^ 1];
        Unk_Dr20_800D95F8* dst = &p->unk28[b];
        int x = src->body.a, y = src->body.b, z = src->body.c, w = src->body.d;
        dst->body.a = x;
        dst->body.b = y;
        dst->body.c = z;
        dst->body.d = w;
    }
    addPrimN(p->unkA, &p->unk28[D_800B4CF0[0]]);
    addPrimN(p->unkA, &p->unk10[D_800B4CF0[0]]);
    return 2;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D9778);

EXTERN_C void func_800D98A8() {}

EXTERN_C void func_800D98B0(void* p, int a) { func_8005F120(p, a); }

EXTERN_C Unk_800D98D0* func_800D98D0(Unk_800D98D0* self, int in_chrg, unsigned short a) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_8005BC84(self, 0, a, 0x10);
    self->vb->vptr = (Unk_VTbl10*)&D_800B9534;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B9534);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B9534).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x40));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B9534).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B9534).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B9534).e[9].delta + adj;
    }
    {
        register Unk_800D98D0* r asm("$2") = self;
        r->vt2C = D_800B943C;
        r->unk38 = 0;
        r->unk3C = 0;
        return r;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D99E8);

EXTERN_C void func_800D9AF8(void* p, int a) {
    func_800D9E4C((Unk_800D9E4C*)p);
    func_800D9C84(p, a);
    func_8002A210(p);
}

EXTERN_C void func_800D9B3C() {}

EXTERN_C void func_800D9B44(Unk_800D9B44* p, void* a) {
    if (p->unk8) {
        func_8005C088(p, a, 1);
        Unk_800BFB64_node* m = first(p->unk30);
        func_80019A6C(m, (int)func_80053250(operator new(0x2C), Unk_RectP(0, 0x22, 0x140, 0xBE), D_800B4C98, p->unk1C), m->unk4);
        Unk_800BFB64_node* n = first(p->unk30);
        func_80019A6C(n, (int)func_8002860C(operator new(0x50), Unk_RectP(0x20, 0x22, 0x100, 0xBE), p->unk38, p->unk1C, D_800B4C74), n->unk4);
        func_8002DA94(a, p->unk30);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D9C84);

EXTERN_C void func_800D9E4C(Unk_800D9E4C* p) {
    if (p->unk38) {
        func_80024FEC(p->unk38, 0);
        func_8005F5F4(operator new(0x14), p->unk38, 2);
        int g = D_800B4C38[0];
        Unk_Deletable* d = p->unk3C;
        p->unk38 = 0;
        func_800215E8(g, d);
        delete p->unk3C;
        p->unk3C = 0;
    }
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B917C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B91AC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B91FC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B921C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B924C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B928C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B92DC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B93D4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B943C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9534);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D9EE0);

EXTERN_C void func_800DA204(Unk_800DA204* p) { func_800DB618(p->unk22F0); }

EXTERN_C void func_800DA224(Unk_800DA224* p) {
    if (!func_800DB9F8((Unk_800DB9F8*)p->unk22F0)) {
        p->vf02();
        return;
    }
    p->unk246C = func_80056E0C(operator new(0xB4), 1);
    func_8002B174(D_800A4578[0], p->unk246C, -1);
    p->unk246C->vf27();
    p->unk246C->vf03();
    func_80054FC0(p->unk2284);
    for (unsigned int i = 0; i < D_800B4DD0[0]->unk1FB; i++) {
        p->unk2470[i] = func_800CDBB4(operator new(0x148));
        func_800CDE70((Unk_800CDE70*)p->unk2470[i], i);
        p->unk2470[i]->vf03(Unk_Pt(i * 0x48 + 8, 0x1E));
        p->unk2470[i]->vf01();
    }
    func_80068E60(p);
    func_8005783C(10);
    func_800DAD54((Unk_800DAD54*)p);
    func_80055330(0);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DA3E4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DA6A4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DA8E4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DAADC);

EXTERN_C void func_800DABA8(Unk_800DABA8* p, int a) {
    if (a) {
        if (p->unk2468 == 0) {
            p->unk2468 = func_800DB8D8(p->unk22F0);
            func_800DADD4((Unk_800DADD4*)p, 0);
            p->unk247C->vf04();
            func_800DAD54((Unk_800DAD54*)p);
        } else {
            p->unk2468 = func_800DB8D8(p->unk22F0);
            if (p->unk2468 == 0) {
                p->vf02();
            } else if (p->unk247C == 0) {
                func_8008EF40(0xC);
                p->unk247C = (VAt<0x18>*)func_80054AF0(operator new(0x50), 2);
                func_80054EB4(p->unk247C, 0xE0, 0x13);
                func_80053F48(p->unk247C, Unk_Pt(8, 0x40));
                p->unk2480 = func_80053928(operator new(0x1C));
                func_80054E18(p->unk247C, p->unk2480);
                p->unk2484 = func_8005464C(operator new(0x28));
                func_80054E18(p->unk247C, p->unk2484);
                func_800DADD4((Unk_800DADD4*)p, 0);
                p->unk247C->vf01();
            }
        }
    }
    if (p->unk3C) {
        func_80057F20(p->unk3C, a ? 0x80 : 0x40);
    }
}

EXTERN_C void func_800DAD54(Unk_800DAD54* p) {
    int i;
    unsigned int j;
    for (i = func_800619F4(D_800B4DD0[0]) - 1; i >= 0; i--) {
        func_800691EC(p, i, 1);
    }
    func_80054CE4(p);
    for (j = 0; j < 0x30; j++) {
        p->unk23A8[j] = 0;
    }
}

EXTERN_C void func_800DADD4(Unk_800DADD4* p, int a) {
    switch (a) {
    case -1:
        func_80053BCC(p->unk2480, (int)D_800B95BC, 0x1A);
        break;
    case 0:
        func_80053BCC(p->unk2480, (int)D_800B95F4, 7);
        func_80054708(p->unk2484, p->unk2468);
        func_80053DDC(p->unk2480, p->unk2484);
        break;
    case 1:
        func_80053BCC(p->unk2480, (int)D_800B9604, 0x17);
        break;
    case 2:
        func_80053BCC(p->unk2480, (int)D_800B9634, 0x15);
        break;
    default:
        func_80053BCC(p->unk2480, (int)D_800B9660, 0x14);
        break;
    }
    if (a == 0) {
        char s[0x20];
        func_800538CC(s, D_800B968C, 0x15);
        func_80053DDC(p->unk2480, s);
        func_80053964(s, 2);
    }
    func_80053CD8(p->unk2484);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DAEFC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B95BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B95F4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9604);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9634);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9660);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B968C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B96BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B970C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B972C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B975C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB120);

EXTERN_C void func_800DB318(Unk_800DB318* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800B97B4;
    self->vt58 = D_800B9834;
    self->vt18 = D_800B9854;
    self->vb->vptr = (Unk_VTbl10*)&D_800B97E4;
    if (!in_chrg) {
        vt = D_800B97E4;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B97E4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xB0));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B97E4).e[6].delta + adj;
    }
    if (self->unk6C) {
        Unk_800DB318_e* e = self->unk6C + ((int*)self->unk6C)[-2];
        if (self->unk6C != e) {
            do {
                --e;
                e->~Unk_800DB318_e();
            } while (self->unk6C != e);
        }
        operator delete[]((char*)self->unk6C - 8);
    }
    self->unk6C = 0;
    if (self->unk70) {
        operator delete[](self->unk70);
    }
    self->unk70 = 0;
    Unk_destroy(self->unk78, 2);
    self->vt54 = D_80014E7C;
    self->vt58 = D_80014E5C;
    self->vt18 = D_80014EAC;
    self->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    {
        vt = D_80014E0C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x68));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_80014E0C).e[6].delta + adj;
    }
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB5A4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB618);

EXTERN_C int func_800DB7E8(Unk_800DB7E8* p, Unk_800DB7E8_a* a) {
    int r = 0;
    if (a->unk18 == 4) {
        unsigned int n = first(&p->unk1C)->unk4 - 1;
        unsigned int i;
        for (i = 0; i < n && !r; i++) {
            if (p->unk70[i].unk1B == a->unk1B && func_8005409C(&p->unk6C[i + 1])) {
                r = 1;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB8D8);

EXTERN_C int func_800DB9F8(Unk_800DB9F8* p) { return first(&p->unk1C)->unk4 - 1; }

EXTERN_C int func_800DBA18(Unk_800DBA18* p) { return p->unk68; }

EXTERN_C void func_800DBA24(Unk_800DBA24* p) {
    if (p->unk74) {
        delete p->unk74;
        p->unk74 = 0;
    }
    func_80054FE0(p);
    func_80056874(p);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DBA84);

EXTERN_C int func_800DBDD8(Unk_800DBDD8* p, Unk_FlagArg* q) {
    if (func_8005618C(q)) {
        return 1;
    }
    if (!p->unk3C) {
        return 1;
    }
    if (q->unk18 & 0x2000) {
        int i = p->unk20;
        if (i == 0) {
            p->vf02();
            return 1;
        }
        if (!(p->unk70[i - 1].unk8B >> 7)) {
            void* o = func_800550BC(p);
            func_80054094(o, func_8005409C(func_800550BC(p)) != 0);
            p->vf04();
            func_8008EF40(0xC);
            return 1;
        }
        func_8008EF40(0xE);
        return 1;
    }
    func_80063340(p, q);
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DBF0C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B97B4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B97E4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9834);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9854);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DBFC4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DC978);

EXTERN_C void func_800DCB4C(Unk_800DCB4C* p) {
    func_800566E4(p);
    func_80055330(0);
    func_8005783C(0x28);
    p->unk3E8 = func_80056E0C(operator new(0xB4), 1);
    func_8002B174(D_800A4578[0], p->unk3E8, -1);
    p->unk3E8->vf27();
    p->unk3E8->vf03();
    func_800538B4(0);
    func_8006BDE0(D_800B4ED8[0]);
}

EXTERN_C void func_800DCC0C(Unk_800DCC0C* p) {
    func_80054FE0(p);
    p->unk3DC = 0;
    p->unk3E0 = 0;
    p->unk3E4 = 0;
    func_80054FE0(p->unk38C);
    func_8002B27C(p->unk3EC, p->unk3F0);
    p->unk3F0 = 0;
    func_8002B27C(D_800A4578[0], p->unk3EC);
    p->unk3EC = 0;
    func_80054FE0(p->unk320);
    Unk_EntTabObj* o = ((Unk_EntOwner*)func_800787B4())->unk328;
    int k = D_800B4D5C[0];
    Unk_800DCC0C_e* e = (Unk_800DCC0C_e*)base(o)->unk8[k];
    char* c = (char*)e + 0x424;
    for (unsigned int i = 0; i < 8; i++) {
        c[D_80015904[i]] = func_800549D8(&p->unk3FC[i]);
        func_8005408C(&p->unk3FC[i], 2);
        func_8005408C(&p->unk64[i], 2);
    }
    ((VAt<0x9C>*)e)->vf01();
    Unk_Ent400* f = (Unk_Ent400*)e;
    f->unk410 = f->unk412;
    f->unk420 = f->unk422;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DCD7C);

EXTERN_C int func_800DD304(void* p, int a) {
    func_8001FC78(a, 0, 0);
    return 1;
}

EXTERN_C void func_800DD32C() {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DD334);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DDB7C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B994C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B999C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B99BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B99EC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DDDF8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DDE6C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DDFB0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DE1E8);
