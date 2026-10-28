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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BAAA0);

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
    p->unk52C = func_800A0D2C(p->unk500);
    func_80025CE0(p->unk52C, p->unk4FC, p->unk500);
    func_8008ECB4(p->unk52C);
    func_80094890(p->unk52C);
    return 1;
}

EXTERN_C int func_800BBFA4(Unk_800BCBE8* p) {
    p->unk530 = func_800A0D2C(p->unk508);
    func_80025CE0(p->unk530, p->unk504, p->unk508);
    p->unk538 = func_8008D1F4(p->unk530, 0);
    func_8008C928(16);
    if (p->unk530) {
        func_800A0D0C(p->unk530);
        p->unk530 = 0;
    }
    return 1;
}

EXTERN_C int func_800BC01C(Unk_800BCBE8* p) {
    func_800BC18C(p);
    p->unk534 = func_800A0D2C(p->unk520);
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
            func_800A0D0C(p->unk52C);
        }
        p->unk52C = 0;
    }
    return 1;
}

EXTERN_C int func_800BC130(Unk_800BCBE8* p) {
    if (p->unk530) {
        func_800A0D0C(p->unk530);
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
        func_800A0D0C(p->unk534);
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
    unk14 = unk10 = func_800A0D2C(n * 4);
    unk18 = 0;
    unk1C = 0;
    unk24 = 0;
    unk20 = 1;
}

EXTERN_C void func_800BD298(Unk_800BD3E0* p, int a) {
    p->vtbl = D_800B6EE4;
    if (p->unk10) {
        func_800A0D0C(p->unk10);
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
    unk18 = func_800A0D2C(unk14 * 8);
}

EXTERN_C void func_800BF35C(Unk_800BF420* p, int a) {
    p->vtbl = D_800B6F3C;
    if (p->unk18) {
        func_800A0D0C(p->unk18);
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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1D70);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C2A6C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C375C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C38E0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C3C54);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C402C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C41E0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C4CA0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C52A0);

EXTERN_C void func_800C5400() {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C5408);

EXTERN_C void func_800C5524(void* p, int a) { func_8005F120(p, a); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C5544);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C59D8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C66D4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C68AC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C6B44);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C6F0C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7110);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7230);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7740);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C94D4);

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

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7F1C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7F6C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C9B58);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CA5A4);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CBA70);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CBCCC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC138);

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

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B806C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B80BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B80DC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B810C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B814C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B825C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B82AC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B82CC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CCD24);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD060);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD224);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD6BC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD8D8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CDF68);

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

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8664);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8694);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CEA30);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF11C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF32C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF830);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF9A8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D03B0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0CDC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0E90);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D109C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1490);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D18F4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1A1C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D29D8);

EXTERN_C void func_800D2B10(void* p, int a) { func_8005F120(p, a); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2B30);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2DD8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2F48);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3090);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3EAC);

EXTERN_C void func_800D401C(Unk_Sprt50* p, int x, int y) {
    p->vf10(x - p->unk50[D_800B4CF0[0]].x0, y - p->unk50[D_800B4CF0[0]].y0);
}

EXTERN_C void func_800D4074(void* p) { func_800D44D4(operator new(0x738), p); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D40A8);

EXTERN_C void func_800D44CC() {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D44D4);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D56E8);

EXTERN_C void func_800D5844(Unk_800D5844* p) {
    func_80054FE0(p->unkA44);
    func_80054FE0(p->unkA94);
    func_800C0860(1);
    func_8006323C(p);
    func_8005457C(p, 0);
}

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D633C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D72B8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D75B4);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D7B6C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D7FB4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D80F0);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9094);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B90E4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9104);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9134);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D82E0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D876C);

EXTERN_C void func_800D8970(Unk_800D8970* p, int i, void* a) { func_80053C6C(&p->unk70[i], a); }

EXTERN_C void func_800D89A4(Unk_800D8970* p, int i, int a, int b) {
    func_80054708(&p->unk74[i], a + 1);
    func_80054708(&p->unk78[i], b);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D8A04);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D8B40);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D8FD4);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D95F8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D9778);

EXTERN_C void func_800D98A8() {}

EXTERN_C void func_800D98B0(void* p, int a) { func_8005F120(p, a); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D98D0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DA224);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DA3E4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DA6A4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DA8E4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DAADC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DABA8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB318);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DBDD8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DCC0C);

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
