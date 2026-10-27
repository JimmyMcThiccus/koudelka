#include "common.h"
#include "field/field.h"

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BA800);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BAD20);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BADB4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BAE5C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BAED8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BAF74);

EXTERN_C void func_800BB010(Unk_800BB010* p, unsigned char* out) {
    out[0] = p->unk28[D_800B4CF0[0]].unk0;
    out[1] = p->unk28[D_800B4CF0[0]].unk1;
    out[2] = p->unk28[D_800B4CF0[0]].unk2;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB068);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB128);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB33C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB5E8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB6B4);

EXTERN_C int func_800BB758(void* p) { return func_800BB5E8(p) == 1; }

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

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6DF0);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B6DF4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BB85C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BBE68);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BC500);

EXTERN_C void func_800BC5F0(Unk_800BC5F0* p) {
    Unk_800BC5F0_sub* s = &p->unk494;
    if (s->unk4) {
        delete s->unk4;
        s->unk4 = 0;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BC640);

EXTERN_C void func_800BC774(Unk_800BF204* p, short id) {
    Unk_800BD3E0* q = func_800BE200(p, id);
    if (q && q->unkC == 0) {
        func_800BD3E0(q, 1);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BC7BC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BC864);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BCAFC);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BCDB0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BD62C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BED4C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF2C0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF520);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BF8AC);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BFB84);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BFC58);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800BFCEC);

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

EXTERN_C int func_800C0320(Unk_800C02FC* p, int) { return func_800BC500(p->unk4); }

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C04A0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1000);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1120);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C16DC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C17C0);

EXTERN_C int func_800C1A74(Unk_800C0814* q, int a) {
    Unk_800C1A74* p = (Unk_800C1A74*)q;
    if (a == 0) {
        func_800C9E04(&p->unk6C);
    } else if (func_800C9EE8(&p->unk6C)) {
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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1C80);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1D70);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C1EFC);

EXTERN_C void func_800C206C(Unk_800C206C* p, unsigned char a) {
    if (p->unkA8) {
        p->unkA8->vf28(a);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C20B0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C2D40);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C2EB8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C3B0C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C47B0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C48C4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C497C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C4A18);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C4C04);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C56B8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C5734);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C57C4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C5928);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C59D8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C6DF4);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7984);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7A7C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7DE4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7EC8);

EXTERN_C void func_800C7F80(Unk_800C7F80* p) {
    func_8002A210(p);
    if (p->unk8) {
        func_8005388C(p, 0xC);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C7FC8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C807C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C8190);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C82A0);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C89BC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C8AC0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C8F34);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C8FE8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C9424);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C94D4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7E1C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7E6C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7E8C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7EBC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C97A4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C99A4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C9A50);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7F1C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B7F6C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C9B58);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C9C78);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800C9EE8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CADB0);

EXTERN_C void func_800CAEA4(Unk_Derived50* p) {
    func_80053848(p);
    func_800CAAD4(p, 1);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CAEE4);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC3BC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC454);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC534);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC754);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC85C);

EXTERN_C void func_800CC914(Unk_Ft4_10* p, Unk_ColorSrc* c) {
    p->unk10[D_800B4CF0[0]].clut = c->unk8;
    func_8005F1D8(p);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CC950);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CCBD8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CCFCC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD060);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD224);

EXTERN_C void func_800CD3C8(Unk_800CD3C8* p) {
    func_800557C8(p, 1, 5);
    func_80053C6C(p->unkB8, p);
    func_8005457C(p->unkB8, 0);
    func_80053FB0(p->unkB8, 0, 0x130);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD428);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CD554);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CDAAC);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CDE70);

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

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8624);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CE3BC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CE6B8);

EXTERN_C void func_800CE758(Unk_Derived50* p) {
    func_80062188(D_800B4DD0[0]);
    func_800CE820(p);
    func_8005388C(p, -1);
    func_80054FC0(p);
}

EXTERN_C void func_800CE7AC(Unk_800CE7AC* p) {
    func_80054FE0(p);
    ((VAt<8>*)p)->vf02();
    func_80055624((char*)p + 0x50, 0);
    func_80062160(D_800B4DD0[0]);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CE820);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CE974);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8664);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B8694);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CEA30);

EXTERN_C void func_800CEC60(Unk_800CEC60* p, int i, int a) { func_80054094(&p->unk68[i], a); }

EXTERN_C int func_800CEC9C(Unk_800CEC9C* p) { return p->unk20; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CECA8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CED70);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF028);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF11C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF32C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF830);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CF9A8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CFACC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CFCA4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CFE64);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800CFF6C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0248);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D03B0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D04E4);

EXTERN_C unsigned char func_800D05FC(Unk_800D05FC* p) { return p->unk38; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0608);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0704);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D07B8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0878);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D09E8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0AAC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D0BB4);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D122C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1304);

EXTERN_C int func_800D142C(Unk_800D142C* p, int a) {
    func_8001FC78(a, 0, 0);
    if (p->unk68) {
        return func_80056BA8(p, a);
    }
    return 1;
}

EXTERN_C void func_800D1488() {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1490);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D17EC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D18F4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1A1C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1BA4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D1DAC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D203C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2214);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2310);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2908);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D29D8);

EXTERN_C void func_800D2B10(void* p, int a) { func_8005F120(p, a); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2B30);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2DD8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D2F48);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3090);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D31E8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3534);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D35F8);

EXTERN_C void func_800D3AC8(Unk_800D3AC8* p, int a) {
    p->unk18 = D_800B8E3C;
    p->vtbl = D_800B8E5C;
    func_800D3D54(p);
    func_800537DC(p->unk10, 0);
    func_8005F120(p, a);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3B28);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3C50);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3D54);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3DE8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D3EAC);

EXTERN_C void func_800D401C(Unk_Sprt50* p, int x, int y) {
    p->vf10(x - p->unk50[D_800B4CF0[0]].x0, y - p->unk50[D_800B4CF0[0]].y0);
}

EXTERN_C void func_800D4074(void* p) { func_800D44D4(operator new(0x738), p); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D40A8);

EXTERN_C void func_800D44CC() {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D44D4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D4674);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D48FC);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D4CC0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D4DC4);

EXTERN_C void func_800D4FC4() {}

EXTERN_C void func_800D4FCC(void* p, int a) { func_8005F120(p, a); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D4FEC);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D5C60);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D5CEC);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D5EFC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D5F94);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D633C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D6654);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D7F10);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D8D18);

EXTERN_C int func_800D8E4C(Unk_800D8E4C* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (p->unk74 && (q->unk18 & 0x4000)) {
        p->vf02();
    }
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D8ECC);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D915C);

EXTERN_C void func_800D91F0() {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D91F8);

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
    func_800D9E4C(p);
    func_800D9C84(p, a);
    func_8002A210(p);
}

EXTERN_C void func_800D9B3C() {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D9B44);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D9C84);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800D9E4C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DADD4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DAEFC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B96BC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B970C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B972C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B975C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB120);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB318);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB5A4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB618);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DB7E8);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DCB4C);

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

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DE3B8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DE59C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DE760);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DE97C);

EXTERN_C void func_800DED0C(Unk_800DED0C* p, int a) { p->unk240 = a != 0; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DED18);

EXTERN_C void func_800DED9C(Unk_800DED9C* p) {
    func_80043DC0(base(p->unk328)->unk8);
}

EXTERN_C void func_800DEDD4(Unk_800DED9C* p, int a) {
    func_8008299C((char*)base(p->unk328)->unk8 + 0x2A0, 0x28, a, 0, 0, 0, 0);
    func_80082E14((char*)base(p->unk328)->unk8 + 0x2A0, 0);
}

EXTERN_C void func_800DEE50(Unk_800DED9C* p, int a) {
    func_8008299C((char*)base(p->unk328)->unk8 + 0x2A0, 0x1E, (a & 7) << 9, 0x14, 0, 0, 0);
    func_80082E14((char*)base(p->unk328)->unk8 + 0x2A0, 0);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DEED4);

EXTERN_C void func_800DEF98(Unk_800DF32C* p, short a, int b) {
    if (p->unk380) {
        switch (b) {
        case 0:
            func_800BCF08(p->unk380, a, 0x65);
            break;
        case 1:
            func_800BCF08(p->unk380, a, 0x66);
            break;
        }
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DEFF8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF098);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF1DC);

EXTERN_C void func_800DF26C(Unk_800DF26C* p) {
    if (p->unk55C) {
        p->unk55C->vf02();
        delete p->unk55C;
        p->unk55C = 0;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF2E8);

EXTERN_C void func_800DF32C(Unk_800DF32C* p) { func_80080BC4(p->unk4F0); }

EXTERN_C void func_800DF34C(Unk_800DF32C* p, int a, int b) {
    int t = 2;
    if (b == 0) {
        t = 3;
    }
    func_800C010C((Unk_800C0054*)p->unk380, a, t);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF37C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF4F4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF604);

EXTERN_C Unk_800DF6B4_obj* func_800DF6B4(Unk_800DF6B4* p) {
    Unk_800DF6B4_obj* o = p->unk4;
    if (o) {
        func_8001A744(p, o);
        o->unk4 = 0;
    }
    return o;
}

EXTERN_C void func_800DF6F0(Unk_800DF6F0* p) {
    Unk_800DF6F0_obj* o;
    while ((o = head(p)) != 0) {
        func_8001A744(p, o);
        o->unk4 = 0;
        delete o;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF758);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF82C);

EXTERN_C void func_800DF938(void* list, int a, int b) {
    Unk_800DF938_obj* o = (Unk_800DF938_obj*)operator new(0x10);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_800171B0;
    o->unk8 = a;
    o->unkC = b;
    func_8001A678(list, o);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DF9A8);

EXTERN_C void func_800DFB08() {}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DFB10);

EXTERN_C void func_800DFBA8(Unk_800DFBA8* p) {
    if (p->unk3C) {
        delete p->unk3C;
        p->unk3C = 0;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DFBF8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800DFC8C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E0390);

EXTERN_C void func_800E07FC(Unk_800E07FC* p, void* a) {
    if (p->unk88) {
        func_800E51F8(p->unk88, a);
    }
}

EXTERN_C signed char func_800E082C(Unk_800E082C* p) { return p->unk2EFC; }

EXTERN_C void func_800E0838(void* p) {
    func_800279A8(p);
    func_800E75BC();
    func_800566E4(p);
    func_80055330(0);
    func_8005549C(9, p, 0, -1);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E0888);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9ADC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9B04);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9B14);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9B20);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9B30);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9B38);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E09C4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E1174);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E1288);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9BB4);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9BB8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9BF8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9C2C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9C5C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E1898);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9CBC);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9CF0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E1BA0);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9DD8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9E2C);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9E58);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E1F28);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9EC0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E26C8);

EXTERN_C void func_800E27C0(Unk_800E27C0* p, int a) {
    if (p->unk84 == 0 && a != 0) {
        if ((p->unk158 == 2 && !func_80062978(p->unk2E80)) || p->unk158 == 1) {
            p->unk158 = 1;
            func_8005549C(10, p, 0, -1);
        }
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E2844);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E2A6C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E2B50);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E2C08);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E2D88);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E31B8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E3250);

EXTERN_C int func_800E382C() {
    int gp;
    func_80018AF4();
    gp = func_80094A20();
    __asm__ volatile("nop\n\tadd $gp, $zero, %0" : : "r"((*(int**)0x110)[0x78 / 4]));
    if (D_800EA7B0[0]) {
        func_800E52D4(D_800EA7B0[0], 4);
    }
    D_800EA7B0[0] = 0;
    __asm__ volatile("add $gp, $zero, %0" : : "r"(gp));
    func_80018B18();
    return 0;
}

EXTERN_C int func_800E38A4() {
    int gp;
    func_80018AF4();
    gp = func_80094A20();
    __asm__ volatile("nop\n\tadd $gp, $zero, %0" : : "r"((*(int**)0x110)[0x78 / 4]));
    if (D_800EA7B0[0]) {
        func_800E52D4(D_800EA7B0[0], 0x8000);
    }
    D_800EA7B0[0] = 0;
    __asm__ volatile("add $gp, $zero, %0" : : "r"(gp));
    func_80018B18();
    return 0;
}

EXTERN_C int func_800E391C() {
    int gp;
    func_80018AF4();
    gp = func_80094A20();
    __asm__ volatile("nop\n\tadd $gp, $zero, %0" : : "r"((*(int**)0x110)[0x78 / 4]));
    if (D_800EA7B0[0]) {
        func_800E52D4(D_800EA7B0[0], 0x100);
    }
    D_800EA7B0[0] = 0;
    __asm__ volatile("add $gp, $zero, %0" : : "r"(gp));
    func_80018B18();
    return 0;
}

EXTERN_C int func_800E3994() {
    int gp;
    func_80018AF4();
    gp = func_80094A20();
    __asm__ volatile("nop\n\tadd $gp, $zero, %0" : : "r"((*(int**)0x110)[0x78 / 4]));
    if (D_800EA7B0[0]) {
        func_800E52D4(D_800EA7B0[0], 0x2000);
    }
    D_800EA7B0[0] = 0;
    __asm__ volatile("add $gp, $zero, %0" : : "r"(gp));
    func_80018B18();
    return 0;
}

EXTERN_C int func_800E3A0C(int a) { return (a + 0x1FFF) / 0x2000; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E3A24);

EXTERN_C void func_800E3AE0() {
    func_80094990();
    CloseEvent(D_800EA7B8[0]);
    CloseEvent(D_800EA7BC[0]);
    CloseEvent(D_800EA7C0[0]);
    CloseEvent(D_800EA7C4[0]);
    func_800949A0();
    D_800EA7B8[0] = -1;
    D_800EA7BC[0] = -1;
    D_800EA7C0[0] = -1;
    D_800EA7C4[0] = -1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E3B68);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E3D8C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E3F04);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E4034);

EXTERN_C void func_800E4228(Unk_800E4228* p) {
    if (p->unk34 != -1) {
        Unk_800E4228_sub* s;
        int cur;
        func_800356F4();
        close(p->unk34);
        s = p->unk4;
        cur = D_800EA7B0[0];
        p->unk34 = -1;
        s->unk4 = -1;
        if (cur == (int)p) {
            D_800EA7B0[0] = 0;
        }
    }
}

EXTERN_C unsigned char* func_800E4290(Unk_800E4290* p) { return p->unk5C; }

EXTERN_C int func_800E429C(Unk_800E4290* p) {
    Unk_800E429C_pos* s = p->unk4;
    int i = s->unk4;
    if (i >= 0 && i < p->unk58) {
        int c = p->unk5C[i];
        s->unk4 = i + 1;
        return c;
    }
    return -1;
}

EXTERN_C void func_800E42EC(Unk_800E4290* p, unsigned char c) {
    Unk_800E429C_pos* s = p->unk4;
    int i = s->unk4;
    if (i >= 0 && i < p->unk58) {
        p->unk5C[i] = c;
        s->unk4 = i + 1;
    }
}

EXTERN_C int func_800E4338(Unk_800E4290* p, void* dst, int n) {
    int pos = p->unk4->unk4;
    if (pos < 0 || p->unk58 < pos + n) {
        return 0;
    }
    func_80025CE0(dst, p->unk5C + pos, n);
    p->unk4->unk4 += n;
    return n;
}

EXTERN_C int func_800E43C0(Unk_800E4290* p, void* src, int n) {
    int pos = p->unk4->unk4;
    if (pos < 0 || p->unk58 < pos + n) {
        return 0;
    }
    func_80025CE0(p->unk5C + pos, src, n);
    p->unk4->unk4 += n;
    return n;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E4448);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E44D4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E4568);

EXTERN_C unsigned int func_800E45F4(Unk_800E4290* p) { return p->unk58; }

EXTERN_C int func_800E4600(int a) { return D_800EA7B0[0] != a; }

EXTERN_C int func_800E4618(void* p, int a) { return a; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E4620);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E46C4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E4920);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E4B10);

EXTERN_C int func_800E4D5C() {
    struct DIRENTRY d;
    func_800E556C();
    return firstfile(D_800EA7C8, &d) != 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E4D8C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E4E70);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9FA8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800B9FD8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA028);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA048);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA090);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA098);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E5024);

EXTERN_C int func_800E51A4(Unk_800E51A4* p) { return *p->unk4 == 0; }

EXTERN_C int func_800E51B8(Unk_800E51EC* p, Unk_800E51B8_arg* a) {
    if (a == 0) {
        p->unk2C = 0;
    } else {
        if (p->unk2C) {
            return 0;
        }
        p->unk2C = &a->unk4;
    }
    return 1;
}

EXTERN_C void* func_800E51EC(Unk_800E51EC* p) { return p->unk38; }

EXTERN_C int func_800E51F8(Unk_800E51EC* p, void* a) {
    if (p->unk38 == a || p->unk34 != -1) {
        return 0;
    }
    p->unk38 = a;
    return 1;
}

EXTERN_C void func_800E522C(Unk_800E522C* p, char* s) {
    int n = func_80094FD0(s);
    if (p->unk40) {
        func_800A0D0C(p->unk40);
    }
    p->unk40 = (char*)func_800A0D2C(n + 1);
    func_80025CE0(p->unk40, s, n);
    p->unk40[n] = 0;
}

EXTERN_C void func_800E52AC(Unk_800E51EC* p, void* a) { func_80025CE0(p->unk54, a, p->unk50 << 7); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E52D4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E5404);

EXTERN_C void func_800E5518(Unk_800E51EC* p) {
    p->unk48 = p->unk44 + 4;
    p->unk4C = p->unk44 + 0x60;
    p->unk54 = p->unk44 + 0x80;
    p->unk5C = p->unk54 + (p->unk50 << 7);
}

EXTERN_C int func_800E5554(Unk_800E51EC* p) {
    int a = p->unk50 * 128;
    int b = p->unk58 + 0x80;
    return a + b;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E556C);

EXTERN_C char* func_800E5614(Unk_800E51EC* p) { return p->unk54; }

EXTERN_C void func_800E5620(Unk_800E5620* p, Unk_Blk32* s) {
    *p->unk4C = *s;
}

EXTERN_C char* func_800E56A8(Unk_800E51EC* p) { return p->unk4C; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E56B4);

EXTERN_C char* func_800E5754(Unk_800E51EC* p) { return p->unk48; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E5760);

EXTERN_C char* func_800E5800(Unk_800E51EC* p) { return p->unk44; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E580C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E59E4);

EXTERN_C void func_800E5B40(Unk_800E5B40* p) {
    func_8002B27C(D_800A4578[0], p->unk6C);
    p->unk6C = 0;
    func_8006323C(p);
    func_800E6EF0(p->unkDC);
    func_80054FE0(p->unk70);
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA0B8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA0E0);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA0F8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA138);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E5B90);

EXTERN_C int func_800E5CC0(void* p, int a) {
    func_8001FC78(a, 0, 0);
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E5CE8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA188);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA1D8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA1F8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA228);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E5FC4);

EXTERN_C void func_800E607C(Unk_800E607C* p, int a) {
    if (a >= 0 && a <= p->unk50) {
        p->unk54 = a;
        if (p->unk58) {
            func_800648E8(p->unk58);
        }
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E60C8);

EXTERN_C void func_800E6198(Unk_800E6198* p) {
    p->unk58 = 0;
    func_80054FE0(p);
}

EXTERN_C void func_800E61B8(void* p) { func_80054C34(p); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E61D8);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA298);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E62C8);

EXTERN_C void func_800E66F0(Unk_800E6750* p, unsigned int a) {
    if (a - 1 < 15) {
        p->unkA0 = a;
        p->unk54[6] = a / 10 + '0';
        p->unk54[7] = a % 10 + '0';
        p->unk5D[0x13] = a / 10 + 0x4F;
        p->unk5D[0x15] = a % 10 + 0x4F;
    }
}

EXTERN_C int func_800E6750(Unk_800E6750* p) { return p->unkA0; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E675C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E6858);

EXTERN_C void* func_800E6A40(Unk_800E6750* p) { return p->unk54; }

EXTERN_C void* func_800E6A48(Unk_800E6750* p) { return p->unk5D; }

EXTERN_C int func_800E6A50(Unk_800E6750* p) { return p->unk50; }

EXTERN_C int func_800E6A5C(Unk_800E6A5C* p, signed char a) {
    if (a < 16 || !D_800EA7E4[0] || (p->unk50 == 0 && p->unkA9 >= 16)) {
        return func_8005409C(p);
    }
    return 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E6AC4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E6E64);

EXTERN_C void func_800E6EF0(void* p) {
    func_80054FE0(p);
    D_800EA7E4[0] = 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E6F14);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E7024);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E714C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E72B0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E7384);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E74B4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E75BC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E77AC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E7870);

EXTERN_C void func_800E7A20(Unk_Sprt28* p, int x, int y) {
    int i = D_800B4CF0[0];
    p->unk28[i].x0 += x;
    p->unk28[i].y0 += y;
    func_8005F1D8(p);
}

EXTERN_C void func_800E7A6C(Unk_Sprt28* p, Unk_ColorSrc* c) {
    p->unk28[D_800B4CF0[0]].r0 = c->unk5;
    p->unk28[D_800B4CF0[0]].g0 = c->unk6;
    p->unk28[D_800B4CF0[0]].b0 = c->unk7;
    func_8005F1D8(p);
}

EXTERN_C void func_800E7AE8(Unk_Sprt28* p, int x, int y) {
    p->vf10(x - p->unk28[D_800B4CF0[0]].x0, y - p->unk28[D_800B4CF0[0]].y0);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E7B40);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E7C44);

EXTERN_C void func_800E7DC4() {}

EXTERN_C void func_800E7DCC(void* p, int a) { func_8005F120(p, a); }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E7DEC);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E8144);

EXTERN_C void func_800E83B8(Unk_800E83B8* p, int a, int b) { p->unk7C = a; p->unk80 = b; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E83C4);

EXTERN_C void func_800E84CC(Unk_800E83B8* p, int a) { p->unk78 = a; }

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E84D4);

EXTERN_C void func_800E85B0(Unk_800E83B8* p) { p->unk68 = 1; }

EXTERN_C void func_800E85BC() {}

EXTERN_C void func_800E85C4(Unk_800E83B8* p, int a) { func_80053BCC(p->unkA8, a, 0); }

EXTERN_C void func_800E85E8() {}

EXTERN_C void func_800E85F0(void* p) {
    if (D_800EA89C[0] == 0) {
        D_800EA89C[0] = p;
        func_800566E4(p);
        func_80055330(0);
        func_8005549C(3, p, 0, -1);
    }
}

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA350);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA380);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA3D0);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA4C8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E8640);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E88D0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E8AF0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E8B9C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E8C34);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E8EF4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E9178);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E936C);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E9498);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E9650);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E9820);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E98E0);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E99C4);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E9A68);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E9C08);

EXTERN_C void func_800E9CA8(Unk_Sprt10* p, Unk_ColorSrc* c) {
    int j = D_800B4CF0[0];
    unsigned char v = c->unk5;
    unsigned int i;
    for (i = 0; i < 0x90; i += 2) {
        p->unk10[i + j].r0 = v;
        p->unk10[i + j].g0 = v;
        p->unk10[i + j].b0 = v;
    }
    func_8005F1D8(p);
}

EXTERN_C void func_800E9D04(Unk_800E9D04* p, int dx, int dy) {
    int b = D_800B4CF0[0];
    int i;
    for (i = 0; i < 0x90; i += 2) {
        p->unk10[i + b].x0 += dx;
        p->unk10[i + b].y0 += dy;
    }
    func_8005F1D8(p);
}

EXTERN_C void func_800E9D70(Unk_Sprt10* p, int x, int y) {
    p->vf10(x - p->unk10[D_800B4CF0[0]].x0, y - p->unk10[D_800B4CF0[0]].y0);
}

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E9DC8);

INCLUDE_ASM("asm/field/nonmatchings/field", func_800E9ECC);

EXTERN_C void func_800EA080() {}

EXTERN_C void func_800EA088(void* p, int a) { func_8005F120(p, a); }

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA550);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA580);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA5D0);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA5F0);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA630);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA728);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA778);

INCLUDE_RODATA("asm/field/nonmatchings/field", D_800BA798);
