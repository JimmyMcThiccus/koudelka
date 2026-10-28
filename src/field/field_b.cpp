#include "common.h"
#include "field/field.h"

EXTERN_C void func_800DE3B8(Unk_800DE3B8* p, int a, int n, int b, int c, int d, int e) {
    Unk_800DE59C_v* y;
    if (n <= 0) {
        n = -1;
    }
    p->unk168 = n;
    p->unk16C = b;
    p->unk154 = getW(p);
    y = &base(p)->unk8->unk1B8->unk2C;
    p->unk164 = (((short)SquareRoot0(y->x * y->x + y->y * y->y + y->z * y->z) + 0x100) / 512) & 7;
    p->unk174 = c;
    p->unk178 = d;
    p->unk17C = e;
    p->unk170 = p->unk14C;
    if (p->unk1AC) {
        p->unk1A4 = 4;
    }
    func_800DDE6C(p, a, n, b, c, d, e);
    if ((unsigned int)(((Unk_800DE3B8_g*)D_800AF470[0])->unk378 - 3) < 2) {
        func_8007B538((Unk_800DE59C_b*)p, 1, 1, 0, 0, 0);
    }
    p->unk1AC = 0;
}

EXTERN_C void func_800DE59C(Unk_800DE59C* q, int a, int n, int b, int c, int d, int e, Unk_W4 v, int x) {
    Unk_800DE59C_h* p = (Unk_800DE59C_h*)q;
    Unk_800DE59C_v* y;
    if (n <= 0) {
        n = -1;
    }
    p->unk168 = n;
    p->unk16C = b;
    p->unk154 = getW(q);
    y = &base(q)->unk8->unk1B8->unk2C;
    p->unk164 = (((short)SquareRoot0(y->x * y->x + y->y * y->y + y->z * y->z) + 0x100) / 512) & 7;
    p->unk174 = c;
    p->unk178 = d;
    p->unk17C = e;
    p->unk170 = p->unk14C;
    if (p->unk1AC) {
        p->unk1A4 = 5;
    }
    func_800DE1E8(q, a, n, b, c, d, e, v, x);
    p->unk1AC = 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800DE760);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800DE97C);

EXTERN_C void func_800DED0C(Unk_800DED0C* p, int a) { p->unk240 = a != 0; }

EXTERN_C void func_800DED18(Unk_800DED9C* p, Unk_Short2 a, Unk_Short2 b, Unk_Short2 c, Unk_Short2 d) {
    void* o = base(p->unk328)->unk8;
    func_80043D38(o, Unk_Short4v(a.x, b.x, c.x, d.x));
}

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

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800DEED4);

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

EXTERN_C void func_800DEFF8(Unk_800DF32C* p, short x, int mode) {
    if (p->unk380) {
        switch (mode) {
        case 0:
            func_800BCF08(p->unk380, x, 0x68);
            break;
        case 1:
            func_800BCF08(p->unk380, x, 0x67);
            break;
        case 2:
            func_800BCF08(p->unk380, x, 0x6A);
            break;
        case 3:
            func_800BCF08(p->unk380, x, 0x69);
            break;
        }
    }
}

EXTERN_C void func_800DF098(Unk_800DF098* p, int a, Unk_W3 s, int x, int y) {
    if (p->unk55C) {
        return;
    }
    p->unk55C = (void*)func_800D0CDC((Unk_800D0CDC*)operator new(0x88), 1, a, 1);
    func_800DEED4(p, s);
    if (*(int*)((char*)((Unk_800DF098_e*)base(p->unk328)->unk8[0])->unk1B8 + 0x38) - s.b < 400) {
        func_8008299C((char*)base(p->unk328)->unk8[0] + 0x2A0, 0x28, 5, 0, 0, 0, 0);
    } else {
        func_8008299C((char*)base(p->unk328)->unk8[0] + 0x2A0, 0x28, 6, 0, 0, 0, 0);
    }
    func_80082E14((char*)base(p->unk328)->unk8[0] + 0x2A0, 0);
    func_80081820(D_800AFA74, 0x4B, (y << 16) | 0x20C8, 2, p, p);
}

EXTERN_C void func_800DF1DC(Unk_800DF1DC_p* p, int a) {
    if (p->unk55C) {
        func_80053F48(p->unk55C, Unk_Pt(0x35, 0x40));
        p->unk55C->vf01();
    }
    func_8007EDAC(p, a, 0x23);
}

EXTERN_C void func_800DF26C(Unk_800DF26C* p) {
    if (p->unk55C) {
        p->unk55C->vf02();
        delete p->unk55C;
        p->unk55C = 0;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800DF2E8);

EXTERN_C void func_800DF32C(Unk_800DF32C* p) { func_80080BC4(p->unk4F0); }

EXTERN_C void func_800DF34C(Unk_800DF32C* p, int a, int b) {
    int t = 2;
    if (b == 0) {
        t = 3;
    }
    func_800C010C((Unk_800C0054*)p->unk380, a, t);
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800DF37C);

EXTERN_C void func_800DF4F4(Unk_800DF4F4* p, int flag) {
    p->vtbl = D_800171D0;
    if (p->unkC) {
        func_80039C88(D_800B4ED8[0] ? (char*)D_800B4ED8[0] + 0x50 : 0, p->unkC);
        Unk_800DF4F4_o* s = (Unk_800DF4F4_o*)operator new(0xC);
        void* c = p->unkC;
        s->vtbl = D_800127E4;
        s->unk4 = 4;
        s->unk8 = c;
        char* l = D_800A4544;
        Unk_800BD010* o = (Unk_800BD010*)operator new(0x14);
        o->vtbl = D_80010178;
        o->unk4 = 0;
        o->vtbl = D_80010338;
        o->unk8 = s;
        o->unkC = 0x80;
        o->unk10 = 1;
        func_8001D150(l, o);
        int n1 = D_800B4D28[0];
        int n2 = D_800B4D30[0];
        p->unkC = 0;
        D_800B4D28[0] = n1 + 1;
        D_800B4D30[0] = n2 + 1;
    }
    func_8001A610(p, flag);
}

EXTERN_C void func_800DF604(Unk_800DF604* p, Unk_W4 a, int b) {
    Unk_800DF604_o* o = p->unkC;
    if (o) {
        o->unk34 = a;
        func_80039DD8(o);
        Unk_Short4v v(0, (b & 7) << 9, 0, 0);
        o = p->unkC;
        o->unk2C = v;
        func_80039DD8(o);
    }
}

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

EXTERN_C void func_800DF758(Unk_800DF82C* p, int a, int b, int e) {
    int f;
    func_80074564(base(D_800AF470[0]->unk328)->unk8[0]);
    func_800DF6F0((Unk_800DF6F0*)p);
    p->unk10 = func_800E7DEC(operator new(0x108), 1, a, 0);
    if (e < 0) {
        f = 1;
    } else {
        f = (e << 16) | 0x201E;
    }
    func_800E83B8(p->unk10, (int)D_800AF470[0], f);
    ((VAt<0x18>*)p->unk10)->vf01();
}

EXTERN_C void func_800DF82C(Unk_800DF82C* p, int a, int b, int c, int e) {
    int f;
    Unk_800DF82C_t t;
    func_80074564(base(D_800AF470[0]->unk328)->unk8[0]);
    func_800DF6F0((Unk_800DF6F0*)p);
    p->unk10 = func_800E7DEC(operator new(0x108), 1, a, 0);
    func_800E84CC(p->unk10, c);
    if (e < 0) {
        f = 1;
    } else {
        f = (e << 16) | 0x201E;
    }
    func_8001E40C(&t, D_800AF470[0], 2, 0x100, 0);
    func_800E83B8(p->unk10, (int)&t, f);
    func_8001E508(&t, 2);
    ((VAt<0x18>*)p->unk10)->vf01();
}

EXTERN_C void func_800DF938(void* list, int a, int b) {
    Unk_800DF938_obj* o = (Unk_800DF938_obj*)operator new(0x10);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_800171B0;
    o->unk8 = a;
    o->unkC = b;
    func_8001A678(list, o);
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800DF9A8);

EXTERN_C void func_800DFB08() {}

EXTERN_C void func_800DFB10(Unk_800DFB10* p) {
    func_8007E47C(D_800AF470[0]->unk328);
    if (!p->unk3C) {
        p->unk3C = func_800DFC8C(operator new(0x2F08), 1, D_800AF470[0], 0x3001, 1);
    }
    p->unk3C->vf01();
}

EXTERN_C void func_800DFBA8(Unk_800DFBA8* p) {
    if (p->unk3C) {
        delete p->unk3C;
        p->unk3C = 0;
    }
}

EXTERN_C void func_800DFBF8(Unk_800DFBF8* p) {
    int i;
    if (!p->unk10) return;
    delete p->unk10;
    p->unk10 = 0;
    for (i = 0; i < 10; i++) {
        if (!p->unk14[i]) break;
        delete p->unk14[i];
        p->unk14[i] = 0;
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800DFC8C);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E0390);

EXTERN_C void func_800E07FC(Unk_800E07FC* p, void* a) {
    if (p->unk88) {
        func_800E51F8(p->unk88, a);
    }
}

EXTERN_C int func_800E082C(Unk_800E082C* p) { return p->unk2EFC; }

EXTERN_C void func_800E0838(void* p) {
    func_800279A8(p);
    func_800E75BC();
    func_800566E4(p);
    func_80055330(0);
    func_8005549C(9, p, 0, -1);
}

EXTERN_C void func_800E0888(Unk_800E0888* p) {
    delete p->unk88;
    p->unk88 = 0;
    func_80054FE0(p->unk8C);
    func_80054FE0(p->unk1BC);
    for (int i = 0; i < 15; i++) {
        p->unk244[i].vf02();
    }
    p->unk84 = 0;
    func_8006323C(p);
    func_80062160(D_800B4DD0[0]);
    int v = p->unk7C;
    Unk_800BCA88* o = (Unk_800BCA88*)func_8001CA10(0x14);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_80010300;
    o->unk8 = 2;
    o->unkA = 7;
    o->unkC = p;
    o->vtbl = D_800102D0;
    o->unk10 = v;
    func_8001EFE4(p->unk80, o);
    func_800E77AC();
    func_8002798C();
}

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9ADC);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9B04);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9B14);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9B20);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9B30);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9B38);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E09C4);

EXTERN_C int func_800E1174(Unk_800E1174* p, Unk_FlagArg* q) {
    int r;
    func_8001FC78((int)q, 0, 0);
    r = 0;
    if (func_80054D78(func_800550BC(p)) && p->unk158 == 5) {
        r = q->unk18 == 0x4000;
    }
    if (r) {
        int i;
        D_800B4D90[0] = 1;
        for (i = 0; i < 15; i++) {
            p->unk244[i].vf02();
        }
        func_80019D40(first(&p->unk1C));
        p->unk84 = 0;
        p->unk158 = 1;
        func_8005549C(10, p, 0, -1);
    }
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E1288);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9BB4);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9BB8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9BF8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9C2C);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9C5C);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E1898);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9CBC);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9CF0);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E1BA0);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9DD8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9E2C);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9E58);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E1F28);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9EC0);

EXTERN_C void func_800E26C8(char* p, int k) {
    switch (k) {
    case 7:
        *(int*)(p + 0x84) = 0;
        func_800E2A6C(p, (int)D_800B9E2C, 0x14, (int)D_800B9BB4, 0);
        break;
    case 4:
        func_800E2A6C(p, (int)D_800B9E58, 0x1B, (int)D_800B9BB4, 0);
        break;
    case 1:
        *(int*)(p + 0x84) = 0;
        func_800E2A6C(p, (int)D_800B9BF8, 0x18, (int)D_800B9BB4, 0);
        break;
    case 3:
        *(int*)(p + 0x84) = 0;
        func_800E2A6C(p, (int)D_800B9BB8, 0x1E, (int)D_800B9BB4, 0);
        break;
    case -1:
    default:
        *(int*)(p + 0x84) = 0;
        func_800E2A6C(p, (int)D_800B9EC0, 0xF, (int)D_800B9BB4, 0);
        break;
    }
    if (func_80054E90(p + 0x1BC)) {
        func_80054CE4(p + 0x1BC);
    } else {
        func_80054FC0(p + 0x1BC);
    }
}

EXTERN_C void func_800E27C0(Unk_800E27C0* p, int a) {
    if (p->unk84 == 0 && a != 0) {
        if ((p->unk158 == 2 && !func_80062978(p->unk2E80)) || p->unk158 == 1) {
            p->unk158 = 1;
            func_8005549C(10, p, 0, -1);
        }
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E2844);

EXTERN_C void func_800E2A6C(char* p, int a, int b, int c, int d) {
    char* t = p + 0x20C;
    func_8005457C(t, 0);
    if (d == 0) {
        func_80053F48(t, Unk_Pt(4, 8));
        func_80053CD8(p + 0x228);
    } else {
        func_80053F48(t, Unk_Pt(4, 2));
        func_80053BCC(p + 0x228, c, d);
    }
    func_80053BCC(p + 0x20C, a, b);
}

EXTERN_C void func_800E2B50(char* p, int a) {
    if (a == 0) {
        func_80053CD8(p + 0x114);
    } else {
        func_80053BCC(p + 0x114, (int)D_800B9F28, 4);
        func_80054708(p + 0x130, a);
        {
            char s[0x20];
            func_800538CC(s, D_800B9F34, 1);
            func_80053DDC(p + 0x114, s);
            func_80053964(s, 2);
        }
        func_80053DDC(p + 0x114, p + 0x130);
    }
    func_80053CD8(p + 0x130);
}

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9F28);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9F34);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E2C08);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E2D88);

EXTERN_C void func_800E31B8(Unk_800E31B8* p) {
    if (p->unk6C) {
        for (unsigned int i = 0; i < 3; i++) {
            Unk_Ent400* e = (Unk_Ent400*)base(((Unk_EntOwner*)func_800787B4())->unk328)->unk8[i];
            func_8008687C(e, 0);
            e->unk410 = e->unk412;
            e->unk420 = e->unk422;
        }
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E3250);

EXTERN_C int func_800E382C() {
    int gp;
    func_80018AF4();
    gp = func_80094A20();
    __asm__ volatile("nop\n\tadd $gp, $zero, %0" : : "r"((*(int**)0x110)[0x78 / 4]));
    if (D_800EA7B0[0]) {
        func_800E52D4((Unk_800E52D4*)D_800EA7B0[0], 4);
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
        func_800E52D4((Unk_800E52D4*)D_800EA7B0[0], 0x8000);
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
        func_800E52D4((Unk_800E52D4*)D_800EA7B0[0], 0x100);
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
        func_800E52D4((Unk_800E52D4*)D_800EA7B0[0], 0x2000);
    }
    D_800EA7B0[0] = 0;
    __asm__ volatile("add $gp, $zero, %0" : : "r"(gp));
    func_80018B18();
    return 0;
}

EXTERN_C int func_800E3A0C(int a) { return (a + 0x1FFF) / 0x2000; }

EXTERN_C void func_800E3A24() {
    _bu_init();
    func_80094990();
    D_800EA7B8[0] = OpenEvent(0xF4000001, 4, 0x1000, func_800E382C);
    D_800EA7BC[0] = OpenEvent(0xF4000001, 0x8000, 0x1000, func_800E38A4);
    D_800EA7C0[0] = OpenEvent(0xF4000001, 0x100, 0x1000, func_800E391C);
    D_800EA7C4[0] = OpenEvent(0xF4000001, 0x2000, 0x1000, func_800E3994);
    func_800949A0();
}

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

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E3B68);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E3D8C);

EXTERN_C void func_800E3F04(Unk_800E3F04* p, int a) {
    p->vtbl8 = D_800BA0E0;
    p->vtbl24 = D_800BA0B8;
    p->vtbl = D_800BA0F8;
    if (p->unk44) {
        operator delete[](p->unk44);
    }
    func_800E4228((Unk_800E4228*)p);
    if (p->unk40) {
        operator delete[](p->unk40);
    }
    int c = D_800EA7B4[0];
    p->unk40 = 0;
    D_800EA7B4[0] = --c;
    if (c == 0) {
        DisableEvent(D_800EA7B8[0]);
        DisableEvent(D_800EA7BC[0]);
        DisableEvent(D_800EA7C0[0]);
        DisableEvent(D_800EA7C4[0]);
        func_800E3AE0();
    }
    p->vtbl8 = D_80012074;
    p->vtbl24 = D_8001208C;
    p->vtbl = D_800120B4;
    func_80035B28(&p->vtbl24, 0);
    func_80035304(p, 0);
    if (a & 1) {
        operator delete(p);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E4034);

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

EXTERN_C int func_800E4448(Unk_800E4448* p) {
    p->unk4->unk0 = 4;
    if (p->unk34 == -1 || D_800EA7B0[0] != 0) {
        return 0;
    }
    D_800EA7B0[0] = (int)p;
    read(p->unk34, p->unk44, func_800E5554((Unk_800E51EC*)p));
    p->unk4->unk4 = -1;
    p->unk4->unk0 = 1;
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E44D4);

EXTERN_C int func_800E4568(Unk_800E4448* p) {
    p->unk4->unk0 = 4;
    if (p->unk34 == -1 || D_800EA7B0[0] != 0) {
        return 0;
    }
    D_800EA7B0[0] = (int)p;
    write(p->unk34, p->unk44, func_800E5554((Unk_800E51EC*)p));
    p->unk4->unk4 = -1;
    p->unk4->unk0 = 1;
    return 1;
}

EXTERN_C unsigned int func_800E45F4(Unk_800E4290* p) { return p->unk58; }

EXTERN_C int func_800E4600(int a) { return D_800EA7B0[0] != a; }

EXTERN_C int func_800E4618(void* p, int a) { return a; }

EXTERN_C int func_800E4620(Unk_800E4620* p) {
    int r;
    p->unk4->unk0 = 4;
    if (p->unk34 != -1 || D_800EA7B0[0] != 0) {
        return -1;
    }
    r = func_800E4B10(p);
    if (r != 0 && r != 4) {
        return r;
    }
    r = (_card_format(p->unk38 + p->unk3C) != 1) << 1;
    Unk_800E4448_st* s = p->unk4;
    if (r) {
        s->unk0 = 2;
    } else {
        s->unk0 = 0;
    }
    return r;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E46C4);

EXTERN_C int func_800E4920(Unk_800E4920* p, int a) {
    int r;
    unsigned int i;
    int st;
    *p->unk4 = 4;
    if (p->unk34 != -1 || D_800EA7B0[0]) {
        return -1;
    }
    r = func_800E4034(p, a, 1);
    if (r == 0) {
    p->vf02();
    i = 0;
    func_800E556C((Unk_800E556C*)p, (void*)a);
    {
        Unk_C1A_800E4920 n = *(Unk_C1A_800E4920*)D_800EA7C8;
        st = erase(n.c) ? 0 : 2;
        while (st && i < 30) {
            Unk_800E5404_e* e = (Unk_800E5404_e*)func_8001ED2C(D_800B4C18[0], 2, 1);
            if (e) {
                if (e->unkA == 4 && e->unkC) {
                    e->unkC->vf00(3);
                }
                e->vf01();
            }
            st = erase(n.c) ? 0 : 2;
            i++;
        }
    }
    *p->unk4 = st ? 2 : 0;
    }
    return r;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E4B10);

EXTERN_C int func_800E4D5C(Unk_800E556C* p, void* s) {
    struct DIRENTRY d;
    func_800E556C(p, s);
    return firstfile(D_800EA7C8, &d) != 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E4D8C);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E4E70);

EXTERN_C int func_800E5024(Unk_800E556C* p) {
    char path[7];
    struct DIRENTRY d;
    Unk_C13_800E5024 pat;
    int nfree, used;
    *(Unk_C5*)path = *(Unk_C5*)(!p->unk38 ? D_800BA090 : D_800BA098);
    nfree = 15;
    used = 0;
    path[6] = 0;
    pat = D_800BA0A4;
    path[5] = D_800BA0A0[0];
    for (int r = firstfile(path, &d) != 0; r; r = nextfile(&d) != 0) {
        int same = 1;
        for (int i = 11; i >= 0; i--) {
            if (!same) {
                break;
            }
            if (((signed char*)d.name)[i] != ((signed char*)pat.c)[i]) {
                same = 0;
            }
        }
        if (!same) {
            used += 1 + (d.size - 1) / 8192;
        }
        nfree -= 1 + (d.size - 1) / 8192;
    }
    return (nfree << 4) + used;
}

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
        operator delete[](p->unk40);
    }
    p->unk40 = (char*)operator new[](n + 1);
    func_80025CE0(p->unk40, s, n);
    p->unk40[n] = 0;
}

EXTERN_C void func_800E52AC(Unk_800E51EC* p, void* a) { func_80025CE0(p->unk54, a, p->unk50 << 7); }

EXTERN_C void func_800E52D4(Unk_800E52D4* p, int a) {
    p->unk30 = a;
    if (a == 4) {
        p->unk4->unk4 = 0;
        p->unk4->unk0 = 0;
    } else {
        Unk_800BFB64_node* n;
        VAt0* x;
        p->unk4->unk4 = -1;
        p->unk4->unk0 = 1;
        n = first(&p->unkC);
        x = n->unk4 ? ((VAt0**)n->unk0)[0] : 0;
        if (x && a != 4) {
            x->vf01(0);
            func_80019C68(first(&p->unkC), 0);
        }
    }
    if (p->unk2C) {
        if (a == 4) {
            p->unk2C->vf00(0);
        } else {
            p->unk2C->vf01(0);
        }
        p->unk2C = 0;
    }
}

EXTERN_C int func_800E5404(Unk_800E5404* p) {
    unsigned int i = 0;
    while (p->unk30 == -1 && i < 60) {
        Unk_800E5404_e* e = (Unk_800E5404_e*)func_8001ED2C(D_800B4C18[0], 2, 1);
        if (e) {
            if (e->unkA == 4 && e->unkC) {
                e->unkC->vf00(3);
            }
            e->vf01();
        }
        i++;
    }
    TestEvent(D_800EA7B8[0]);
    TestEvent(D_800EA7BC[0]);
    TestEvent(D_800EA7C0[0]);
    TestEvent(D_800EA7C4[0]);
    int old = p->unk30;
    p->unk30 = -1;
    return old;
}

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

EXTERN_C void func_800E556C(Unk_800E556C* p, void* s) {
    *(Unk_C5*)D_800EA7C8 = *(Unk_C5*)(!p->unk38 ? D_800BA090 : D_800BA098);
    *(Unk_C12*)D_800EA7CD = *p->unk40;
    *(Unk_C8*)(D_800EA7CD + 12) = *(Unk_C8*)s;
    D_800EA7CD[20] = 0;
}

EXTERN_C char* func_800E5614(Unk_800E51EC* p) { return p->unk54; }

EXTERN_C void func_800E5620(Unk_800E5620* p, Unk_Blk32* s) {
    *p->unk4C = *s;
}

EXTERN_C char* func_800E56A8(Unk_800E51EC* p) { return p->unk4C; }

EXTERN_C void func_800E56B4(Unk_800E56B4* p, Unk_Blk40* s) {
    *p->unk48 = *s;
}

EXTERN_C char* func_800E5754(Unk_800E51EC* p) { return p->unk48; }

EXTERN_C void func_800E5760(Unk_800E5760* p, Unk_Blk80* s) {
    *p->unk44 = *s;
}

EXTERN_C char* func_800E5800(Unk_800E51EC* p) { return p->unk44; }

EXTERN_C Unk_800E580C* func_800E580C(Unk_800E580C* self, int in_chrg, int a) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_800630BC(self, 0, 2);
    self->vb->vptr = (Unk_VTbl10*)&D_800BA188;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800BA188);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800BA188).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x358));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800BA188).e[6].delta + adj;
    }
    self->vt54 = D_800BA1F8;
    self->vt58 = D_800BA1D8;
    self->vt18 = D_800BA228;
    func_80054AF0(self->unk70, 1);
    func_800538CC(self->unkC0, D_800BA138, 0x12);
    func_800E62C8(self->unkDC);
    self->unk68 = a;
    func_80055020(self->unkDC, Unk_Pt(0x20, 0x98));
    func_800E66F0((Unk_800E6750*)self->unkDC, 1);
    func_80054EB4(self->unk70, 0xF0, 0x15);
    func_80053F48(self->unk70, Unk_Pt(0x28, 0x38));
    func_80054E18(self->unk70, self->unkC0);
    {
        register Unk_800E580C* r asm("$2") = self;
        r->unk6C = 0;
        return r;
    }
    return self;
}

EXTERN_C void func_800E59E4(Unk_800E59E4* p) {
    void* buf;
    func_800E07FC(p->unk68, 0);
    buf = operator new[](0x1AA0);
    func_800609D0(D_800B4DD0[0], buf);
    func_800E6AC4(p->unkDC, buf, 1);
    if (buf) {
        operator delete[](buf);
    }
    func_800E675C((Unk_800E675C*)p->unkDC, func_800E082C((Unk_800E082C*)p->unk68));
    func_80053BCC(p->unkC0, (int)D_800BA138, 0x12);
    p->unk20 = 0;
    func_80054FC0(p->unk70);
    func_800E6E64((Unk_800E6E64*)p->unkDC);
    func_800631D4(p);
    p->unk6C = func_800638A8(operator new(0x64), 1);
    func_8002B174(D_800A4578[0], p->unk6C, -1);
    p->unk6C->vf27();
    Unk_Pt v(0x11A, 0x3C);
    func_80063B14(p->unk6C, &v, 2);
    p->unk6C->vf3();
}

EXTERN_C void func_800E5B40(Unk_800E5B40* p) {
    func_8002B27C(D_800A4578[0], p->unk6C);
    p->unk6C = 0;
    func_8006323C(p);
    func_800E6EF0(p->unkDC);
    func_80054FE0(p->unk70);
}

EXTERN_C int func_800E5B90(Unk_800E5B90* p, Unk_FlagArg* q) {
    int f = q->unk18;
    if (f & 0x80) {
        func_800E07FC(p->unk68, 0);
        func_80053BCC(p->unkC0, (int)D_800BA138, 0x12);
        func_80054CE4(p->unk70);
        func_80063BE4(p->unk6C);
        Unk_Pt v(0x11A, 0x3C);
        func_80063B14(p->unk6C, &v, 2);
        func_8008EF40(8);
    } else if (f & 0x20) {
        func_800E07FC(p->unk68, (void*)0x10);
        func_80053BCC(p->unkC0, (int)D_800BA160, 0x12);
        func_80054CE4(p->unk70);
        func_80063BE4(p->unk6C);
        Unk_Pt v(0x1C, 0x3C);
        func_80063B14(p->unk6C, &v, 1);
        func_8008EF40(8);
    } else if (f & 0x4000) {
        p->vf02();
    } else {
        func_80063340(p, q);
    }
    return 1;
}

EXTERN_C int func_800E5CC0(void* p, int a) {
    func_8001FC78(a, 0, 0);
    return 1;
}

EXTERN_C void func_800E5CE8(Unk_800E5CE8* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800BA1F8;
    self->vt58 = D_800BA1D8;
    self->vt18 = D_800BA228;
    self->vb->vptr = (Unk_VTbl10*)&D_800BA188;
    if (!in_chrg) {
        vt = D_800BA188;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800BA188).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x358));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800BA188).e[6].delta + adj;
    }
    Unk_800E5CE8_m* m = &self->unkDC;
    func_80053964(self->unk33C, 2);
    func_80053964(self->unk320, 2);
    func_80053964(self->unk304, 2);
    func_80053964(self->unk2E8, 2);
    func_80053964(self->unk2CC, 2);
    func_80053964(self->unk2A4, 2);
    func_80053964(self->unk27C, 2);
    func_80053964(self->unk254, 2);
    Unk_destroy(self->unk1DC, 3);
    Unk_destroy(m->unkAC, 3);
    ((void (*)(void*, int))func_80054C34)(m, 2);
    func_80053964(self->unkC0, 2);
    ((void (*)(void*, int))func_80054C34)(self->unk70, 2);
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

C_800E5FC4::C_800E5FC4(int a, Unk_800E5FC4_r* s) {
    func_80054AF0(this, 1);
    vtbl18 = D_800BA268;
    unk50 = a;
    unk54 = 0;
    unk58 = 0;
    func_80054EB4(this, s->w, s->h);
    func_80053F48(this, Unk_800E5FC4_r(*s).pos);
}

EXTERN_C void func_800E607C(Unk_800E607C* p, int a) {
    if (a >= 0 && a <= p->unk50) {
        p->unk54 = a;
        if (p->unk58) {
            func_800648E8(p->unk58);
        }
    }
}

EXTERN_C void func_800E60C8(Unk_800E60C8* p) {
    func_80054FC0(p);
    if (p->unk58 == 0) {
        void* o = operator new(0x58);
        short w = func_80054F28(p)->x - 0x10;
        short h = func_80054F28(p)->y - 8;
        Unk_Short4 r(8, 4);
        r.z = w;
        r.w = h;
        p->unk58 = func_800646FC(o, 1, &r, 2);
        func_80064884(p->unk58, p->unk50, 0);
        ((void (*)(void*, int))func_800648E8)(p->unk58, p->unk54);
        func_8005800C(p->unk3C, p->unk58);
    }
}

EXTERN_C void func_800E6198(Unk_800E6198* p) {
    p->unk58 = 0;
    func_80054FE0(p);
}

EXTERN_C void func_800E61B8(void* p) { func_80054C34(p); }

EXTERN_C void func_800E61D8() {
    char o[8];
    func_8005F238(o);
    func_8005F298(o, 0x14346, 0x800);
    D_800EA7E8 = *(Unk_800E61D8_blk*)func_8005F28C(o);
    func_8005F3E0(o);
    func_8005F248(o, 2);
}

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9FA8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800B9FD8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA028);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA048);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA090);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA098);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA0A0);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA0A4);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA0B8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA0E0);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA0F8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA138);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA160);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA188);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA1D8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA1F8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA228);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA268);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA298);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E62C8);

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

EXTERN_C void func_800E675C(Unk_800E675C* p, signed char a) {
    if (a < 16) {
        if (p->unkA9 >= 16) {
            D_800EA7E4[0] = 0;
        }
        *(Unk_C3_800E675C*)p->unk85 = *(Unk_C3_800E675C*)D_800BA2E8;
    } else {
        D_800EA7E4[0] = 1;
        *(Unk_C19_800E675C*)(p->unk85 + 2) = *(Unk_C19_800E675C*)D_800BA2EC;
    }
    p->unkA9 = a;
    func_800E6F14((Unk_800E6F14*)p, ((Unk_800E675C_g*)D_800B4DD0[0])->unk1C4);
}

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA2E8);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA2EC);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E6858);

EXTERN_C void* func_800E6A40(Unk_800E6750* p) { return p->unk54; }

EXTERN_C void* func_800E6A48(Unk_800E6750* p) { return p->unk5D; }

EXTERN_C int func_800E6A50(Unk_800E6750* p) { return p->unk50; }

EXTERN_C int func_800E6A5C(Unk_800E6A5C* p, signed char a) {
    if (a < 16 || !D_800EA7E4[0] || (p->unk50 == 0 && p->unkA9 >= 16)) {
        return func_8005409C(p);
    }
    return 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E6AC4);

EXTERN_C void func_800E6E64(Unk_800E6E64* p) {
    int t = p->unk3C == 0;
    func_80054FC0(p);
    if (t && p->unk50 == 0) {
        func_8005800C(p->unk3C, func_800E714C((Unk_800E714C*)operator new(0x48), 1, p->unkA8, p->unkA9 < 16 ? p->unkA9 : 10, 2));
    }
}

EXTERN_C void func_800E6EF0(void* p) {
    func_80054FE0(p);
    D_800EA7E4[0] = 0;
}

EXTERN_C void func_800E6F14(Unk_800E6F14* p, int t) {
    int s = t % 60;
    int m = t / 60;
    int h;
    p->unk82 = s / 10 + 0x4F;
    p->unk84 = s % 10 + 0x4F;
    s = m % 60;
    h = m / 60;
    p->unk7C = s / 10 + 0x4F;
    p->unk7E = s % 10 + 0x4F;
    p->unk76 = h / 10 + 0x4F;
    p->unk78 = h % 10 + 0x4F;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E7024);

EXTERN_C Unk_800E714C* func_800E714C(Unk_800E714C* self, int in_chrg, int a, int b, unsigned short c) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_8005BC84(self, 0, c, 0x10);
    self->vb->vptr = (Unk_VTbl10*)&D_800BA380;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800BA380);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800BA380).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x40));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800BA380).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800BA380).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800BA380).e[9].delta + adj;
    }
    self->vt2C = D_800BA3D0;
    self->unk38 = a;
    self->unk3C = b;
    Unk_Pt pt(8, 4);
    ((VAt<0x2C>*)self)->vf07(pt.x, pt.y);
    return self;
}

#define p ((Unk_Hdr38d*)vp)
EXTERN_C void func_800E72B0(void* vp, unsigned char a) {
    if (p->unk8) {
        Unk_W2 t;
        func_8002972C(&t, a, a, a, 1);
        for (int i = ((Unk_800BFB64_node*)(p->unk30 ? p->unk30->Unk_800BFB64_list::head : 0))->unk4 - 1; i >= 0; i--) {
            ((VAt0*)func_80019F64(first2(p->unk30), i))->vf11(&t);
        }
        func_800198AC(&t, 2);
    }
}
#undef p

EXTERN_C void func_800E7384(Unk_800E7384* p, void* a) {
    if (p->unk8) {
        Unk_Short2 v;
        unsigned int i;
        Unk_800BFB64_node* n;
        func_8005C088(p, a, 1);
        v = p->unkC;
        for (i = 0; i < p->unk38; i++) {
            Unk_800BFB64_node* m = first(p->unk30);
            func_80019A6C(m, (int)func_800E7870(operator new(0x50), i, &v, p->unk1C), m->unk4);
            v.x += 0x20;
        }
        v.x = p->unkC.x + 0x90;
        n = first(p->unk30);
        func_80019A6C(n, (int)func_800E7870(operator new(0x50), (int)(p->unk3C + 0x10), &v, p->unk1C), n->unk4);
        func_8002DA94(a, p->unk30);
    }
}

EXTERN_C void func_800E74B4(Unk_VbDtor2C* self, int in_chrg) {
    self->vt2C = D_800BA3D0;
    self->vb0->vptr = (Unk_VTbl10*)&D_800BA380;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800BA380;
        char* full;
        int adj;
        self->vb0->vptr = &vt;
        vt.e[1].delta = D_800BA380.e[1].delta + (adj = (char*)self - (full = (char*)self->vb0 - 0x40));
        vt.e[5].delta = D_800BA380.e[5].delta + adj;
        vt.e[7].delta = D_800BA380.e[7].delta + adj;
        vt.e[9].delta = D_800BA380.e[9].delta + adj;
    }
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb0, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E75BC);

EXTERN_C void func_800E77AC() {
    if (D_800EA888[0]) {
        unsigned int i;
        func_80024FEC(D_800EA888[0], 0);
        func_8005F5F4(operator new(0x14), D_800EA888[0], 2);
        D_800EA888[0] = 0;
        for (i = 0; i < 4; i++) {
            func_800215E8(D_800B4C38[0], D_800EA88C[i]);
            delete D_800EA88C[i];
            D_800EA88C[i] = 0;
        }
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E7870);

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

EXTERN_C Unk_800E7B40* func_800E7B40(Unk_800E7B40* s) {
    Unk_800E7B40* o = (Unk_800E7B40*)operator new(0x50);
    o->vtbl = D_80010178;
    o->unk4 = s->unk4;
    o->vtbl = D_800111BC;
    o->unk8 = s->unk8;
    o->unkA = s->unkA;
    o->vtbl = D_80014BD0;
    o->unkC = s->unkC;
    o->vtbl = D_800BA4C8;
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
        int n = 1;
        Unk_W5_800D4CC0* q = s->unk28;
        do {
            *d = *q;
            d++;
            q++;
        } while (--n != -1);
    }
    return o;
}

EXTERN_C int func_800E7C44(Unk_800E7C44* p) {
    if (func_8005F1B4(p)) {
        int b = D_800B4CF0[0];
        Unk_Sprt20* s = &p->unk28[b ^ 1];
        Unk_Sprt20* d = &p->unk28[b];
        int w0 = s->body.a, w1 = s->body.b, w2 = s->body.c, w3 = s->body.d;
        d->body.a = w0;
        d->body.b = w1;
        d->body.c = w2;
        d->body.d = w3;
    }
    addPrimN(p->unkA, &p->unk28[D_800B4CF0[0]]);
    addPrimN(p->unkA, &p->unk10[D_800B4CF0[0]]);
    return 2;
}

EXTERN_C void func_800E7DC4() {}

EXTERN_C void func_800E7DCC(void* p, int a) { func_8005F120(p, a); }

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E7DEC);

EXTERN_C void func_800E8144(Unk_800E8144* self, int in_chrg) {
    Unk_VTbl10 vt;
    self->vt54 = D_800BA550;
    self->vt58 = D_800BA5D0;
    self->vt18 = D_800BA5F0;
    self->vb->vptr = (Unk_VTbl10*)&D_800BA580;
    if (!in_chrg) {
        vt = D_800BA580;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800BA580).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x100));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800BA580).e[6].delta + adj;
    }
    if (self->unk84) {
        operator delete[](self->unk84);
    }
    self->unk84 = 0;
    delete self->unk70;
    self->unk70 = 0;
    delete self->unk74;
    self->unk74 = 0;
    Unk_destroy(self->unk8C, 3);
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

EXTERN_C void func_800E83B8(Unk_800E83B8* p, int a, int b) { p->unk7C = a; p->unk80 = b; }

EXTERN_C void func_800E83C4(char* p) {
    func_8005457C(p + 0x8C, 0);
    func_80053F48(p + 0x8C, Unk_Pt(0x88 - func_8005F87C(p + 0x8C) / 2, 0));
    func_8005457C(p + 0xA8, 0);
    func_80053F48(p + 0xA8, Unk_Pt(0x88 - func_8005F87C(p + 0xA8) / 2, 0xD));
    func_8005457C(p + 0xC4, 0);
    func_80053F48(p + 0xC4, Unk_Pt(0x88 - func_8005F87C(p + 0xC4) / 2, 0x1A));
}

EXTERN_C void func_800E84CC(Unk_800E83B8* p, int a) { p->unk78 = a; }

EXTERN_C void func_800E84D4(Unk_800E84D4* p, int a) {
    p->unk6C = a;
    if (a == 0) {
        return;
    }
    if (p->unk70) {
        func_80053BCC(p, 0, 0);
        func_80053BCC(p->unk74, 0, 0);
        return;
    }
    p->unk70 = func_80054AF0(operator new(0x50), 1);
    func_80054EB4(p->unk70, 0x130, 0x14);
    func_80053F48(p->unk70, Unk_Pt(8, 0x30));
    if (!p->unk74) {
        p->unk74 = func_80053928(operator new(0x1C));
    }
    func_80054E18(p->unk70, p->unk74);
}

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

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA350);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA380);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA3D0);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA4C8);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E8640);

EXTERN_C int func_800E88D0(Unk_800E88D0* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (func_8005618C(q)) {
        return 1;
    }
    unsigned short f = q->unk18;
    if (f & 0x80) {
        func_8001FC78((int)q, (int)(Unk_800E88D0_b*)p, 1);
        p->unk20 = ((int (*)(void*, int))func_80058270)(p->unk3C, -1);
    } else if (f & 0x20) {
        func_8001FC78((int)q, (int)(Unk_800E88D0_b*)p, 1);
        p->unk20 = ((int (*)(void*, int))func_80058270)(p->unk3C, 1);
    } else if (f & 0x1000) {
        int ok = 0;
        if (func_80060230(func_80053AE4(p->unk8C, 0), D_800BA544)) {
            ok = func_80060230(func_80053AE4(p->unk8C, 1), D_800BA548) != 0;
        }
        if (ok) {
            func_8007E47C(((Unk_EntOwner*)func_800787B4())->unk328);
            p->unkFC = func_800DFC8C(operator new(0x2F08), 1, D_800B4D60[0], 4, 1);
            p->unkFC->vf01();
        }
    } else if (f & 0x2000) {
        if (first(&p->unk1C)->unk4 == p->unkE0) {
            p->vf02();
        } else {
            VAt<0x18>* o = (VAt<0x18>*)func_800550BC(p);
            if (o && func_8005409C(o)) {
                func_8008EF40(0xC);
                o->vf01();
            }
        }
    }
    return 1;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E8AF0);

EXTERN_C int func_800E8B9C(Unk_800E8B9C* p, int a) {
    if (func_80063744(p, a)) {
        return 1;
    }
    switch (a) {
    case 3:
        func_800E8C34(p);
        return 1;
    case 4:
        delete p->unkFC;
        p->unkFC = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E8C34);

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E8EF4);

EXTERN_C void func_800E9178(Unk_800E9178* p) {
    VAt<0x2C>* o;
    if (p->unkF8) {
        func_8002B27C(p->unkF4, p->unkF8);
        p->unkF8 = 0;
        func_8002B27C(D_800A4578[0], p->unkF4);
        p->unkF4 = 0;
    }
    p->unkF4 = func_80057368(operator new(0x64), 1);
    func_8002B174(D_800A4578[0], p->unkF4, -1);
    o = p->unkF4;
    o->vf07(0, 0);
    o->vf08(0x140, 0xF0);
    p->unkF4->vf27();
    p->unkF4->vf03();
    p->unkF8 = (VAt<0x2C>*)func_800E936C((Unk_800E936C*)operator new(0x54), 1, 2);
    {
        char s[0x28];
        func_80069D1C(s, (p->unkE8 + p->unkF0 - 2) * 9 + 0x1531E, 0x4800);
        func_800E9650(p->unkF8, s);
        func_80069E60(s, 2);
    }
    p->unkF4->vf29(p->unkF8, -1);
    p->unkF8->vf03();
    if (p->unkEC < p->unkE8 + p->unkF0) {
        p->unkE4 = 0;
    }
    p->unkF0++;
}

EXTERN_C Unk_800E936C* func_800E936C(Unk_800E936C* self, int in_chrg, unsigned short a) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_8005BC84(self, 0, a, 0x10);
    func_800537C0(self->unk38);
    self->vb->vptr = (Unk_VTbl10*)&D_800BA728;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800BA728);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800BA728).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x4C));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800BA728).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800BA728).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800BA728).e[9].delta + adj;
    }
    {
        register Unk_800E936C* r asm("$2") = self;
        r->vt40 = D_800BA778;
        r->vt2C = D_800BA630;
        r->unk48 = 0;
        r->unk44 = 0;
        return r;
    }
}

EXTERN_C void func_800E9498(Unk_800E9498* self, int in_chrg) {
    self->vt40 = D_800BA778;
    self->vt2C = D_800BA630;
    self->vb->vptr = (Unk_VTbl10*)&D_800BA728;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800BA728;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800BA728).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x4C));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800BA728).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800BA728).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800BA728).e[9].delta + adj;
    }
    if (!func_80053880((Unk_Base*)self)) {
        func_80055624((char*)self + 0x38, 0);
    }
    if (self->unk44) {
        func_80024FEC(self->unk44, 0);
        func_8005F5F4(operator new(0x14), self->unk44, 2);
        self->unk44 = 0;
        func_800215E8(*(const int*)D_800B4C38, self->unk48);
        delete self->unk48;
        self->unk48 = 0;
    }
    func_800537DC((char*)self + 0x38, 0);
    func_8005BDA4(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}

INCLUDE_ASM("asm/field/nonmatchings/field_b", func_800E9650);

EXTERN_C int func_800E9820(Unk_800E9820* p) {
    if (p->unk8) {
        Unk_Sprt10* s = (Unk_Sprt10*)Unk_800E9820_at(first2(p->unk30), 0);
        func_800E9C08(s, 0x1A - func_80053874(p));
    }
    return func_80053830(p) != 0;
}

#define p ((Unk_Hdr38d*)vp)
EXTERN_C void func_800E98E0(void* vp, unsigned char a) {
    if (p->unk8 && ((Unk_800BFB64_node*)(p->unk30 ? p->unk30->Unk_800BFB64_list::head : 0))->unk4 > 0) {
        Unk_W2 t;
        func_8002972C(&t, a, a, a, 1);
        ((VAt0*)at0((Unk_Tbl*)first2(p->unk30)))->vf11(&t);
        func_800198AC(&t, 2);
    }
}
#undef p

EXTERN_C void func_800E99C4(Unk_800E99C4* p, void* a) {
    if (p->unk8) {
        Unk_800BFB64_node* n;
        func_8005C088(p, a, 1);
        n = first(p->unk30);
        func_80019A6C(n, (int)func_800E9A68(operator new(0xB68), p->unk44, p->unk1C), n->unk4);
        func_8002DA94(a, p->unk30);
        func_8005388C(p, 0x1A);
    }
}

EXTERN_C void* func_800E9A68(void* vp, void* sv, int a) {
    Unk_800E9A68* p = (Unk_800E9A68*)vp;
    Unk_800E9A68_s* s = (Unk_800E9A68_s*)sv;
    func_8005F0E4(p, a);
    p->vtbl = D_800BA798;
    SetDrawMode(p->unkB50, 0, 1, s->unk1C, 0);
    SetDrawMode(p->unkB5C, 0, 1, s->unk1C, 0);
    int u;
    if (s->unkC == 0) {
        u = s->unk10 & 0x3F;
    } else if (s->unkC->vf02()) {
        u = (s->unk10 << 1) & 0x7F;
    } else {
        u = s->unk10 << 2;
    }
    Unk_800E9A68_uv t(u, s->unk12);
    unsigned short clut = *(unsigned short*)((char*)s->unkC + 8);
    unsigned i = 0;
    do {
        ((Unk_Sp*)&p->unk10[i])->len = 4;
        ((Unk_Sp*)&p->unk10[i])->code = 0x64;
        p->unk10[i].w = 0x20;
        p->unk10[i].h = 0xE;
        p->unk10[i].r0 = 0;
        p->unk10[i].g0 = 0;
        p->unk10[i].b0 = 0;
        p->unk10[i].x0 = ((i >> 1) & 7) * p->unk10[i].w + 0x20;
        p->unk10[i].y0 = (i >> 4) * p->unk10[i].h + 0xAA;
        p->unk10[i].u0 = t.u + ((i >> 1) & 7) * p->unk10[i].w;
        p->unk10[i].v0 = t.v + (i >> 4) * p->unk10[i].h;
        p->unk10[i].clut = clut;
    } while (++i < 0x90);
    return p;
}

EXTERN_C void func_800E9C08(Unk_Sprt10* p, int n) {
    int b = D_800B4CF0[0];
    int i = n < 9 ? 0 : (n - 8) * 8;
    for (; i <= n * 8 && i < 0x90; i += 2) {
        p->unk10[i + b].r0 += 16;
        p->unk10[i + b].g0 += 16;
        p->unk10[i + b].b0 += 16;
    }
    func_8005F1D8(p);
}

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

EXTERN_C Unk_800E9DC8* func_800E9DC8(Unk_800E9DC8* s) {
    Unk_800E9DC8* o = (Unk_800E9DC8*)operator new(0xB68);
    o->vtbl = D_80010178;
    o->unk4 = s->unk4;
    o->vtbl = D_800111BC;
    o->unk8 = s->unk8;
    o->unkA = s->unkA;
    o->vtbl = D_80014BD0;
    o->unkC = s->unkC;
    o->vtbl = D_800BA798;
    {
        Unk_W5_800E9DC8* d = o->unk10;
        int n = 0x8F;
        Unk_W5_800E9DC8* q = s->unk10;
        do {
            *d = *q;
            d++;
            q++;
        } while (--n != -1);
    }
    {
        Unk_W3* d = o->unkB50;
        int n = 1;
        Unk_W3* q = s->unkB50;
        do {
            *d = *q;
            d++;
            q++;
        } while (--n != -1);
    }
    return o;
}

EXTERN_C int func_800E9ECC(Unk_800E9ECC* p) {
    int b = D_800B4CF0[0];
    int nb = b ^ 1;
    unsigned int i;
    if (func_8005F1B4(p)) {
        for (i = 0; i < 0x90; i += 2) {
            int* s = (int*)&p->unk10[i + nb];
            int* d = (int*)&p->unk10[i + b];
            int w0 = s[1], w1 = s[2], w2 = s[3], w3 = s[4];
            d[1] = w0;
            d[2] = w1;
            d[3] = w2;
            d[4] = w3;
        }
    }
    Unk_Ot* ot = D_800B4CFC[0];
    for (i = 0; i < 0x90; i += 2) {
        addPrimOt_800E9ECC(ot, p->unkA, &p->unk10[i] + b);
    }
    addPrimOt2_800E9ECC(ot, p->unkA, &p->unkB50[b]);
    return 0x49;
}

EXTERN_C void func_800EA080() {}

EXTERN_C void func_800EA088(void* p, int a) { func_8005F120(p, a); }

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA544);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA548);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA550);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA580);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA5D0);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA5F0);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA630);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA728);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA778);

INCLUDE_RODATA("asm/field/nonmatchings/field_b", D_800BA798);
