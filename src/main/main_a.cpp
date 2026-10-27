#include "common.h"

typedef struct S_800186B0 {
    void *p;
    int data[1];
} S_800186B0;

EXTERN_C void func_800198E0(void *a, int b, int c);

EXTERN_C S_800186B0 *func_800186B0(S_800186B0 *s)
{
    s->p = s->data;
    func_800198E0(s->data, 2, 0);
    return s;
}

#include "shared/vbase.h"

EXTERN_C int D_800B4BFC; // call counter, in .sdata
EXTERN_C void func_80094990();
EXTERN_C Item *func_80019F64(List *l, int i);

EXTERN_C void func_800186E8(Holder *h)
{
    if (++D_800B4BFC == 1) {
        func_80094990();
        for (int i = 0; i < count_of(h); i++)
            func_80019F64(h, i)->run();
    }
}

#include "game/a/main_a.h"

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018788);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018840);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800188D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018970);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018A20);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018A58);

EXTERN_C void func_80018A88()
{
    func_800186E8(&D_800A451C);
}

EXTERN_C void func_80018AAC()
{
    func_80018788(&D_800A451C);
}

EXTERN_C void func_80018AD0()
{
    func_80018840(&D_800A451C);
}

EXTERN_C void func_80018AF4()
{
    func_800188D4(&D_800A451C);
}

EXTERN_C void func_80018B18()
{
    func_80018970(&D_800A451C);
}

EXTERN_C void func_80018B3C()
{
    func_80019920((List *)((S_800186B0 *)&D_800A451C)->p, 0);
}

EXTERN_C void func_80018B64()
{
    func_800186B0((S_800186B0 *)&D_800A451C);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018B88);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018BE4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018C1C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018C90);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018D80);

EXTERN_C int func_80018DF4(int *p)
{
    return p ? p[-1] - 8 : 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018E10);

EXTERN_C S_80018E5C *func_80018E5C(S_80018E5C *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800100C0;
    p->unk88 = 0;
    p->unk8 = a;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018E88);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018EDC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018F0C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80018FA8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800190A0);

EXTERN_C int func_8001914C(S_8001914C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019158);

EXTERN_C void func_800191FC()
{
    D_800A4534.unkC++;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001921C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019274);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800192C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800193AC);

EXTERN_C void func_80019478()
{
    func_80019158(&D_800A4534);
}

EXTERN_C int func_8001949C(S_8001949C *p)
{
    return p->unkC;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800194A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", main);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800100C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800100D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019648);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800196C8);

EXTERN_C void func_80019820()
{
    func_8001D024(&D_800B4C00, 2);
}

EXTERN_C void func_80019848()
{
    func_80019648(&D_800B4C00);
}

EXTERN_C void func_8001986C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", printf);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019894);

INCLUDE_ASM("asm/main/nonmatchings/main_a", puts);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800198A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800198AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800198E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019920);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019974);

EXTERN_C int func_80019A18(S_80019A18 *p, int v)
{
    int old = p->unk10;
    p->unk10 = v;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019A24);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019A6C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019B2C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019BA0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019C24);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019C68);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019CFC);

EXTERN_C void func_80019D40(S_80019D40 *p)
{
    if (p->unk10 == 0)
        p->unk4 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019D5C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019F0C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019F64);

EXTERN_C int func_80019FB4(S_80019FB4 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80019FC0);

EXTERN_C void func_8001A00C(S_80019FB4 *p, int v)
{
    p->unk8 = v;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800100F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A014);

EXTERN_C void func_8001A030(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A050);

EXTERN_C int func_8001A080(S_8001A080 *p)
{
    return p->unk4 ? *p->unk0 : 0;
}

EXTERN_C void func_8001A0AC(void *p, int a)
{
    func_80019A6C(p, a, 0);
}

EXTERN_C void func_8001A0CC(S_8001A080 *p, int a)
{
    func_80019A6C(p, a, p->unk4);
}

EXTERN_C void func_8001A0F0(S_8001A080 *p, int a)
{
    func_80019A6C(p, a, p->unk4);
}

EXTERN_C int func_8001A114(S_8001A114 *p)
{
    return p->unk8;
}

EXTERN_C int func_8001A120(S_8001A114 *p)
{
    return p->unk4 == 0;
}

EXTERN_C int func_8001A12C(S_8001A114 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A138);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A1A0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A220);

EXTERN_C S_8001A294 *func_8001A294(S_8001A294 *p, int a, int b)
{
    p->vtbl = D_80010118;
    p->unk4 = a;
    p->unk8 = b;
    return p;
}

EXTERN_C void func_8001A2B0(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A2D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A354);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010118);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A3BC);

EXTERN_C void func_8001A46C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A48C);

EXTERN_C void func_8001A53C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A55C);

EXTERN_C void func_8001A5F0(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A610);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A678);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A6A8);

EXTERN_C int func_8001A6E8(S_8001A6E8 *p)
{
    int n = 0;
    while (p) {
        p = p->unk4;
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A708);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A744);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A7B4);

EXTERN_C void func_8001A844(void *p, int a)
{
    func_8001A678(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A864);

EXTERN_C int func_8001A8B8(S_8001A8B8 *p, int v)
{
    p->unk4 = v;
    return v;
}

EXTERN_C void func_8001A8C4(S_8001A8B8 *p)
{
    p->unk4 = 0;
}

EXTERN_C int func_8001A8CC(S_8001A8B8 *p)
{
    return p->unk4;
}

EXTERN_C S_8001A294 *func_8001A8D8(S_8001A294 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A8F0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001A970);

EXTERN_C int *func_8001AA28(int *p, int n)
{
    int *q = p;
    while (n--)
        *q++ = 0;
    return p;
}

EXTERN_C S_Vobj *func_8001AA54(S_Vobj *p)
{
    p->vtbl = D_80010198;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001AA68);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001AB50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001AC38);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001AC80);

EXTERN_C void func_8001ACB4()
{
    D_800B4C04 = func_8001ACDC(operator new(0x4008));
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010148);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010160);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010178);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010198);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800101B0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800101C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001ACDC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001AD18);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001AD68);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001ADE0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001AEFC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001AF8C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B0C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B134);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B1C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B26C);

EXTERN_C void func_8001B2D8(void *p)
{
    func_8001B0C0(D_800B4C04, p);
}

EXTERN_C int func_8001B300(char *a, char *b)
{
    return a + 8 < b;
}

EXTERN_C int func_8001B30C(S_8001B30C *p)
{
    return p->unk4;
}

EXTERN_C void func_8001B318(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B338);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B394);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B424);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800101E8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800101F8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010210);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010260);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010278);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010288);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800102A0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800102B0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800102C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800102D0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800102E8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010300);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010328);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010338);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010348);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010360);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010378);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010388);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800103A0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800103B8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800103D0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800103E0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800103F8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010408);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010420);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010438);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010450);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010460);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010470);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010480);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B46C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B8C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001B910);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001BBBC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001BE20);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001BE9C);

EXTERN_C void func_8001C2AC()
{
    func_8001C2D0((S_Vobj *)&D_800B4C10);
}

EXTERN_C S_Vobj *func_8001C2D0(S_Vobj *p)
{
    p->vtbl = D_800101E8;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C2E4);

EXTERN_C void func_8001C36C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C38C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C580);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C5DC);

EXTERN_C int func_8001C658(S_8001C658 *p)
{
    return p->unk4 != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C664);

EXTERN_C void func_8001C6A0(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_8001C6C0(S_8001C658 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4 *func_8001C6CC(S_Vobj4 *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800102B0;
    p->unk8 = 0;
    p->unkC = a;
    return p;
}

EXTERN_C void func_8001C6F8(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C718);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C7D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C89C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C8D8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C974);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001C9D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CA10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CA58);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CAA4);

EXTERN_C void func_8001CAE0(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CB00);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CB7C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CC00);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CC84);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CCC8);

EXTERN_C int func_8001CD10(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CD1C(S_8001CD10 *p)
{
    return p->unk4 != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CD28);

EXTERN_C int func_8001CD6C(S_8001CD10 *p)
{
    return p->unk4;
}

EXTERN_C void func_8001CD78(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_8001CD98(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDA4(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDB0(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDBC(S_8001CD10 *p)
{
    return p->unk8;
}

EXTERN_C int func_8001CDC8(S_8001CD10 *p)
{
    return p->unkA;
}

EXTERN_C int func_8001CDD4(S_8001CD10 *p)
{
    return p->unk10;
}

EXTERN_C int func_8001CDE0(S_8001CD10 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CDEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CE24);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CE5C);

EXTERN_C S_Vobj4 *func_8001CE94(S_Vobj4 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_80010300;
    return p;
}

EXTERN_C void func_8001CEB8(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CED8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001CF68);

EXTERN_C int func_8001CFF8(S_8001CFF8 *p)
{
    return p->unk4;
}

EXTERN_C void func_8001D004(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C void func_8001D024(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80010348;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D04C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D0E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D150);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D25C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D2C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D324);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D3A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D490);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D4C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D540);

EXTERN_C S_8001A294 *func_8001D5A8(S_8001A294 *p)
{
    p->vtbl = D_80010328;
    p->unk4 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D5C0);

EXTERN_C int func_8001D62C(S_8001D62C *p)
{
    return p->unk10;
}

EXTERN_C void func_8001D638(S_8001D62C *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_8001D640(S_8001D62C *p)
{
    return p->unkC;
}

EXTERN_C int func_8001D64C(S_8001D62C *p)
{
    return p->unk8;
}

EXTERN_C void func_8001D658(void *p, int a)
{
    func_8001A6A8(p, a);
}

EXTERN_C int func_8001D678(S_8001D62C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D684);

EXTERN_C S_Vobj *func_8001D6B4(S_Vobj *p)
{
    p->vtbl = D_80010348;
    return p;
}

EXTERN_C int func_8001D6C8(S_8001D6C8 *p)
{
    return D_800A4534.unkC < p->unk14;
}

EXTERN_C void func_8001D6E0(S_8001D6C8 *p, int a)
{
    unsigned int t = D_800A4534.unkC;
    p->unk18 = t;
    p->unk14 = t + a;
}

EXTERN_C void func_8001D700(S_8001D6C8 *p, int a)
{
    unsigned int t = D_800A4534.unkC;
    p->unk14 = t;
    p->unk18 = t + a;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D720);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D76C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D7B0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D8A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001D9F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001DB04);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001DBB8);

EXTERN_C void func_8001DDD0()
{
    func_8001D7B0(&D_800AC57C);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001DDF4);

EXTERN_C void func_8001DEB8(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800103E0;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001DEE0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001DF58);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001DFC0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E03C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E07C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E15C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E1AC);

EXTERN_C S_8001E23C *func_8001E23C(S_8001E23C *p)
{
    p->unk0 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E248);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E288);

EXTERN_C void func_8001E2D8(S_8001E23C *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_8001E2E0(S_8001E23C *p)
{
    return p->unkC;
}

EXTERN_C int func_8001E2EC(S_8001E23C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E2F8);

EXTERN_C S_Vobj *func_8001E330(S_Vobj *p)
{
    p->vtbl = D_800103E0;
    return p;
}

EXTERN_C int func_8001E344()
{
    return D_800B4C24++;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E360);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E40C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E508);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E57C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E6AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E758);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E7C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E804);

EXTERN_C void func_8001E840(S_8001E840 *p)
{
    p->unk98 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E848);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001E9A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001EAAC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001EB60);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001EBD8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001EC98);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001ED2C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001EE58);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001EEC0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001EFE4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F048);

EXTERN_C void func_8001F074(char *p, int a)
{
    func_8001F094(p + 0xAC, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F094);

EXTERN_C void func_8001F134()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC688)->p, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F15C);

EXTERN_C S_Vobj *func_8001F1A8(S_Vobj *p)
{
    p->vtbl = D_800103F8;
    return p;
}

EXTERN_C unsigned short func_8001F1BC(S_8001F1BC *p, int v)
{
    unsigned short old = p->unk94;
    p->unk94 = v;
    return old;
}

EXTERN_C int func_8001F1CC(S_8001F1CC *p)
{
    return p->unk98;
}

EXTERN_C int func_8001F1D8(S_8001F1CC *p)
{
    return p->unk4;
}

EXTERN_C S_8001F1BC *func_8001F1E4()
{
    return D_800B4C18;
}

EXTERN_C int func_8001F1F0(S_8001F1CC *p)
{
    return p->unkF0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F1FC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F2C4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F360);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F3DC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F460);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F514);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F544);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F598);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F60C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F67C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F6E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F788);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F85C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F930);

EXTERN_C S_8001F964_Derived *func_8001F964(S_8001F964 *p)
{
    return (S_8001F964_Derived *)p->unkC;
}

EXTERN_C int func_8001F980(S_8001F980 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F98C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001F9C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FA6C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FA9C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FAD4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FB0C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FB4C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FB9C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FBF4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FC38);

EXTERN_C void func_8001FC78(S_8001FC78 *p, int a, int b)
{
    func_80020734(p->unk8, a, p, b);
}

EXTERN_C int func_8001FCA4(S_8001FCA4 *p)
{
    return p->unk8->unk4;
}

EXTERN_C void func_8001FCB8(S_8001FC78 *p)
{
    func_800208D4(p->unk8);
}

EXTERN_C void func_8001FCDC(S_8001FC78 *p)
{
    func_80020948(p->unk8);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FD00);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FD90);

EXTERN_C int func_8001FE20()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FE28);

EXTERN_C int func_8001FEB0()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FEB8);

EXTERN_C int func_8001FF40()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8001FF48);

EXTERN_C int func_8001FFD0(S_8001FFD0 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4 *func_8001FFDC(S_Vobj4 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800104A8;
    return p;
}

EXTERN_C void func_80020000(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_80020020(S_8001FFD0 *p)
{
    return (p->unk12 >> 3) & 1;
}

EXTERN_C int func_80020034(S_8001FFD0 *p)
{
    return (p->unk12 >> 2) & 1;
}

EXTERN_C int func_80020048(S_8001FFD0 *p)
{
    return (p->unk12 >> 1) & 1;
}

EXTERN_C int func_8002005C(S_8001FFD0 *p)
{
    return p->unk12 & 0x1;
}

EXTERN_C void func_80020068(S_8001FFD0 *p, int v)
{
    p->unk12 = v;
}

EXTERN_C void func_80020070(S_8001FFD0 *p, int v)
{
    p->unk8 = v;
}

EXTERN_C void func_80020078(S_8001FFD0 *p, int v)
{
    p->unkC = v;
}

EXTERN_C void func_80020080(S_8001FFD0 *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_80020088(S_8001FFD0 *p)
{
    return p->unk12;
}

EXTERN_C int func_80020094(S_8001FFD0 *p)
{
    return p->unk8;
}

EXTERN_C int func_800200A0(S_8001FFD0 *p)
{
    return p->unkC;
}

EXTERN_C int func_800200AC(S_8001FFD0 *p)
{
    return p->unk10 & 0xFF00;
}

EXTERN_C int func_800200B8(S_8001FFD0 *p)
{
    return p->unk10;
}

EXTERN_C int func_800200C4(S_8001FFD0 *p)
{
    return p->unk4;
}

EXTERN_C void func_800200D0(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800200F0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800104A8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800104F8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010508);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010538);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010588);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800201DC);

EXTERN_C int func_800202B4()
{
    return 0;
}

EXTERN_C int func_800202BC()
{
    return 0;
}

EXTERN_C int func_800202C4()
{
    return 0;
}

EXTERN_C int func_800202CC()
{
    return 0;
}

EXTERN_C int func_800202D4()
{
    return 0;
}

EXTERN_C void func_800202DC()
{
    func_8001A610(&D_800AC6A8, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020304);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020368);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002042C);

EXTERN_C void func_80020510(S_80020510 *p, int v)
{
    p->unk1A = v;
}

EXTERN_C void func_80020518(S_80020510 *p, int v)
{
    p->unk18 = v;
}

EXTERN_C int func_80020520(S_80020510 *p)
{
    return p->unk1A;
}

EXTERN_C int func_8002052C(S_80020510 *p)
{
    return p->unk18;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020538);

EXTERN_C void func_800205B4(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800205D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002068C);

EXTERN_C void func_8002072C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020734);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800207C4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020884);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800208D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020948);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020984);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800209F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020A30);

EXTERN_C void func_80020B08()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC6C4)->p, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020B30);

EXTERN_C int func_80020B70(S_80020B70 *p)
{
    return count_of(&p->unk28) == 0;
}

EXTERN_C int func_80020B90(S_80020B90 *p)
{
    return p->unk4;
}

EXTERN_C void func_80020B9C(S_80020B90 *p, int v)
{
    p->unk54 = v;
}

EXTERN_C int func_80020BA4(S_80020B90 *p)
{
    return p->unk52;
}

EXTERN_C void func_80020BB0(S_80020B90 *p, int v)
{
    p->unk52 = v;
}

EXTERN_C int func_80020BB8(S_80020B90 *p)
{
    return p->unk50;
}

EXTERN_C void func_80020BC4(S_80020B90 *p, int v)
{
    p->unk50 = v;
}

EXTERN_C int func_80020BCC(S_80020B90 *p)
{
    return p->unk4A;
}

EXTERN_C void func_80020BD8(S_80020B90 *p, int v)
{
    p->unk4A = v;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020BE0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020C64);

EXTERN_C void func_80020D24(S_80020D24 *p, int v)
{
    p->unk14 = v;
}

EXTERN_C int func_80020D2C(S_80020D24 *p)
{
    return p->unk14;
}

EXTERN_C int func_80020D38(S_80020D24 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020D44);

EXTERN_C void func_80020D90(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020DB0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020E00);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020E40);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80020EF8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002101C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021060);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800210A4);

EXTERN_C S_80021274 *func_80021144(S_80021274 *p)
{
    int i;
    for (i = 15; i >= 0; i--)
        p->unk0[i] = 0;
    p->unk40 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021168);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800211F4);

EXTERN_C void func_80021274(S_80021274 *p)
{
    int i;
    for (i = 15; i >= 0; i--)
        p->unk0[i] = 0;
    p->unk40 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021294);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021300);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021348);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002141C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021478);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800215E8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800216A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021764);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800218B4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002190C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021ACC);

EXTERN_C int func_80021B54()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021B5C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021C04);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021F48);

EXTERN_C int func_80021FE4()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80021FEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022094);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022438);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800224A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022518);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002256C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800225C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022670);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800226A0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800226F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022730);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800227E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022810);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022868);

EXTERN_C void func_800228A0(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C void func_800228C0(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C void func_800228E0(void *p, int a)
{
    func_80020DB0(p, a);
}

EXTERN_C void func_80022900(void *p, int a)
{
    func_80020DB0(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022920);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022974);

EXTERN_C int func_800229B0(S_800229B0 *p)
{
    if (p->unk10 == 0) {
        return 0;
    } else {
        return p->unk10->unk8;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800229D4);

EXTERN_C int func_80022A04(S_80022A04 *p)
{
    return p->unk10;
}

EXTERN_C int func_80022A10(S_80022A04 *p)
{
    return p->unk10;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022A1C);

EXTERN_C int func_80022A70(S_80022A04 *p)
{
    return p->unk8;
}

EXTERN_C int func_80022A7C(S_80022A04 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4h *func_80022A88(S_Vobj4h *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800106EC;
    p->unk8 = 0;
    p->unkA = a;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022AB4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022B24);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022C34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022CF0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022D64);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022E28);

EXTERN_C int func_80022F64(S_80022F64 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4 *func_80022F70(S_Vobj4 *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_80010734;
    p->unk8 = a;
    return p;
}

EXTERN_C void func_80022F98(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80022FB8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800230E8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800232A0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80023450);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002385C);

EXTERN_C void func_80023988(char *p, int a)
{
    func_8001A8F0(p + 0x108, a, 0x20);
}

EXTERN_C int func_800239AC(S_800239AC *p, int v)
{
    int old = p->unk104;
    p->unk104 = v;
    return old;
}

EXTERN_C void *func_800239B8(S_800239AC *p)
{
    return &p->unk108;
}

EXTERN_C int func_800239C0(S_800239C0 *p)
{
    int r = 0;
    if (!p->unk9C)
        r = p->unkC0 == 0;
    return r;
}

EXTERN_C int func_800239E4(S_800239AC *p)
{
    return p->unk106;
}

EXTERN_C int func_800239F0()
{
    return 0x24;
}

EXTERN_C void *func_800239F8(S_800239AC *p)
{
    return &p->unk9C;
}

EXTERN_C void func_80023A00(S_80023A24 *p)
{
    D_800B4C3C &= ~(1 << p->unk106);
}

EXTERN_C void func_80023A24(S_80023A24 *p)
{
    D_800B4C3C |= 1 << p->unk106;
}

EXTERN_C void func_80023A44()
{
    D_800B4C40 = func_800A1B9C() != 0;
}

EXTERN_C void func_80023A68()
{
    PadEnableCom(0);
}

EXTERN_C void func_80023A88()
{
    PadEnableCom(D_800B4C3C);
}

EXTERN_C void func_80023AAC()
{
    PadStopCom();
}

EXTERN_C void func_80023ACC()
{
    PadStartCom();
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80023AEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80023B94);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80023C40);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80023CB8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80023F50);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800105B4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800105DC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800105F4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001060C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010624);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010654);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010684);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010694);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800106A4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800106BC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800106EC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010714);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010734);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001075C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010774);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001079C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800240C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800244A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024524);

EXTERN_C int func_8002456C(S_8002456C *p)
{
    return p->unk26 ? --p->unk26 == 0 : 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024594);

EXTERN_C int func_80024634(S_80024634 *p)
{
    return p->unk26 == 0;
}

EXTERN_C int func_80024640(S_80024634 *p)
{
    return p->unk25;
}

EXTERN_C int func_8002464C(S_80020B70 *p)
{
    return count_of(&p->unk28);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002466C);

EXTERN_C void func_800246C4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800107C8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800246EC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024770);

EXTERN_C int func_80024858(S_80024858 *p)
{
    return p->unk10;
}

EXTERN_C int func_80024864(S_80024858 *p)
{
    return p->unk18 != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024870);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800248BC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024940);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024974);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024A80);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024AF0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024BB0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024BF0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024CA0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024D40);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024E44);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024EE4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024FA8);

EXTERN_C void func_80024FE4()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80024FEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025050);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002510C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025268);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800107C8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800107F0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010800);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800252F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002537C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025444);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025714);

EXTERN_C void func_80025808()
{
    func_8001DEB8(&D_800B4C48, 2);
}

EXTERN_C void func_80025830()
{
    func_800252F8(&D_800B4C48);
}

EXTERN_C void func_80025854(void *p, int a)
{
    func_8001DEB8(p, a);
}

EXTERN_C int func_80025874(S_80025874 *p)
{
    return p->unk24;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025880);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025960);

EXTERN_C int func_800259F8(S_800259F8 *p)
{
    return p->unk1C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025A04);

EXTERN_C void *func_80025A5C(S_800259F8 *p)
{
    return &p->unk10;
}

EXTERN_C S_Rgb func_80025A64(S_80025A64 *p)
{
    return p->unk10;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025A84);

EXTERN_C S_Rgb func_80025B0C(S_80025A64 *p)
{
    return p->unk14;
}

EXTERN_C int func_80025B2C(S_800259F8 *p)
{
    return p->unkC;
}

EXTERN_C int func_80025B38(S_800259F8 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025B44);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025BE0);

EXTERN_C void func_80025C50(unsigned short *a, unsigned short *b)
{
    *a = *b;
}

EXTERN_C S_80025C5C *func_80025C5C(S_80025C5C *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C S_80025C5C *func_80025C68(S_80025C5C *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C int func_80025C74(S_80025C5C *p)
{
    return p->unk0;
}

EXTERN_C void *func_80025C80(void *p)
{
    return p;
}

EXTERN_C S_80025C88 *func_80025C88(S_80025C88 *p, int a, int b, int c, int d)
{
    p->unk0 = c;
    p->unk2 = a;
    p->unk4 = b;
    p->unk1 = d;
    return p;
}

EXTERN_C void *func_80025CA4(void *p)
{
    return p;
}

EXTERN_C void func_80025CAC(unsigned short *a, unsigned short *b)
{
    *a = *b;
}

EXTERN_C unsigned short *func_80025CB8(unsigned short *a, unsigned short *b)
{
    *a = *b;
    return a;
}

EXTERN_C S_80025CC8 *func_80025CC8(S_80025CC8 *p, int a, int b)
{
    p->unk0 = a;
    p->unk1 = b;
    return p;
}

EXTERN_C void *func_80025CD8(void *p)
{
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80025CE0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80026014);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800260A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80026138);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80026190);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800261B4);

EXTERN_C int func_800261D4()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800261DC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80026214);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80026274);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800262E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800263C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80026420);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80026558);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002673C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80026920);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800269B8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80027408);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002758C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80027754);

EXTERN_C void func_800278D8()
{
    D_800B4C50 = -1;
    D_800B4C52 = -1;
}

EXTERN_C S_8001A294 *func_800278EC(S_8001A294 *p, int a)
{
    p->vtbl = D_80011124;
    p->unk4 = a;
    p->vtbl = D_800110F4;
    return p;
}

EXTERN_C void func_80027910(void *p, int a)
{
    func_80026138(p, a);
}

EXTERN_C S_8001A294 *func_80027930(S_8001A294 *p, int a)
{
    p->vtbl = D_80011124;
    p->unk4 = a;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80027948);

EXTERN_C void func_8002798C()
{
    if (D_800B4C58)
        D_800B4C58--;
}

EXTERN_C void func_800279A8()
{
    D_800B4C58++;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800279C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010840);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010858);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80010888);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800108A0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800108C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800110C4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800110F4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011124);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80027A60);

EXTERN_C int func_80027D90(S_80027D90 *p)
{
    return p->unk14;
}

EXTERN_C void func_80027D9C(S_80027D90 *p)
{
    p->unkC = 3;
}

EXTERN_C void func_80027DA8(S_80027D90 *p)
{
    p->unkC = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80027DB0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80027DFC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80027E30);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80027FB0);

EXTERN_C S_80027FEC *func_80027FEC(S_80027FEC *p, S_80027FEC *q)
{
    q->unk8 = p->unk8;
    q->unkA = p->unkA;
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028004);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028064);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800280A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800280F8);

EXTERN_C void func_80028158(void *p, void *q)
{
    func_8002DC34(q, (int)p, 0);
}

EXTERN_C void func_80028184(S_80028184 *p)
{
    p->unk8 = 0;
}

EXTERN_C void func_8002818C(S_80028184 *p, int v)
{
    p->unkA = v;
}

EXTERN_C int func_80028194(S_80028184 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4h *func_800281A0(S_Vobj4h *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800111BC;
    p->unk8 = 0;
    p->unkA = a;
    return p;
}

EXTERN_C void func_800281CC(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_800281EC(S_80028184 *p)
{
    return p->unk4;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001116C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800111A4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800111BC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800281F8);

EXTERN_C S_80027FEC *func_80028230(S_80027FEC *p, S_80027FEC *q)
{
    func_80027FEC(p, q);
    return q;
}

EXTERN_C void func_80028258(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028278);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800282AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028330);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028374);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001126C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800283AC);

EXTERN_C void func_80028428(void *p, int a)
{
    func_8001DEB8(p, a);
}

EXTERN_C int func_80028448(S_80028448 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028454);

EXTERN_C void *func_800284AC(void *p, void *q)
{
    func_80028710(p, q);
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800284D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800285CC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002860C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028710);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800287C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800288D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028A24);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028AE8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028B90);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028C08);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028C80);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028D10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028DC4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028F10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028F58);

EXTERN_C void func_80028FA0(void *p, int a)
{
    func_80028DC4(p, a);
}

EXTERN_C int func_80028FC0(S_80028FC0 *p)
{
    return p->unk4;
}

EXTERN_C void func_80028FCC()
{
    D_800B4C70 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80028FD8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800112F4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011304);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002900C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029414);

EXTERN_C void func_8002970C(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C S_8002972C *func_8002972C(S_8002972C *p, int a, int b, int c, int d)
{
    p->vtbl = D_80011384;
    p->unk5 = a;
    p->unk6 = b;
    p->unk7 = c;
    p->unk4 = d & 1;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029758);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029850);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002991C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029A14);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029BBC);

EXTERN_C int func_80029BF4(S_80029BF4 *p)
{
    return p->unk7;
}

EXTERN_C int func_80029C00(S_80029BF4 *p)
{
    return p->unk6;
}

EXTERN_C int func_80029C0C(S_80029BF4 *p)
{
    return p->unk5;
}

EXTERN_C S_8001A294 *func_80029C18(S_8001A294 *p, S_8001A294 *q)
{
    p->vtbl = D_80011384;
    p->unk4 = q->unk4;
    return p;
}

EXTERN_C void func_80029C34(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029C54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029D74);

EXTERN_C void func_80029EB8()
{
}

EXTERN_C void func_80029EC0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029EC8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029F30);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80029FC0);

EXTERN_C void func_8002A004(S_8002A004 *p)
{
    if (p->unk28 == 0)
        p->unk28 = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A020);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A064);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A09C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A0D0);

EXTERN_C void func_8002A110(S_8002A110 *p)
{
    p->unk28 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A118);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A168);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A1BC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A210);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A274);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A2D8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A33C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A37C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A3C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A400);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A444);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A484);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A4C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A55C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A5F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A65C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A698);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A728);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A7B8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A864);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A910);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002A9BC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AA8C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AB5C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AC2C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AC60);

EXTERN_C void func_8002AD0C(void *p, S_8002AD0C *q)
{
    func_8002A064(p, q->unk0, q->unk2);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AD38);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002ADA8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AE14);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AE50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AE8C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AEE0);

EXTERN_C void *func_8002AF34(S_8002AF34 *p)
{
    return &p->unkC;
}

EXTERN_C S_Rgb func_8002AF3C(S_80025A64 *p)
{
    return p->unk10;
}

EXTERN_C S_Rgb func_8002AF5C(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C int func_8002AF7C(S_8002AF34 *p)
{
    return p->unk24;
}

EXTERN_C int func_8002AF88(S_8002AF34 *p)
{
    return p->unk20;
}

EXTERN_C int func_8002AF94(S_8002AF94 *p)
{
    int r = 0;
    if (p->unk8)
        r = p->unk28 != 0;
    return r;
}

EXTERN_C int func_8002AFB8(S_8002AF34 *p)
{
    return p->unk1C;
}

EXTERN_C void func_8002AFC4(S_8002AF34 *p, int v)
{
    p->unk1C = v;
}

EXTERN_C int func_8002AFCC(S_8002AF34 *p)
{
    return p->unk8;
}

EXTERN_C int func_8002AFD8(S_8002AF34 *p)
{
    return p->unk4;
}

EXTERN_C void func_8002AFE4(S_8002AF34 *p, int v)
{
    p->unk4 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002AFEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B108);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B174);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B27C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B36C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B47C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B518);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B5B4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B67C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B6FC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B7A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B854);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B904);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002B9B4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002BA94);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002BB34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002BBD4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002BC08);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002BCD0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002BD34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002BDFC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C084);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C0E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C120);

EXTERN_C int func_8002C15C(S_8002C15C *p)
{
    return count_of(&p->unk30);
}

EXTERN_C int func_8002C17C(S_8002C17C *p)
{
    return p->unk8;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C188);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C2B8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C498);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C514);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C5EC);

EXTERN_C int func_8002C6C8(S_8002C6C8 *p)
{
    return p->unk8;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C6D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C7DC);

EXTERN_C void func_8002C8A4()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC710)->p, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C8CC);

EXTERN_C int func_8002C90C(S_8002C90C *p)
{
    return p->unk4;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011384);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011394);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001147C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800114CC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001151C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001162C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001167C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C918);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C93C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C974);

EXTERN_C void func_8002C9B4(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002C9D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002CA64);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002CB44);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002CC60);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002CDC0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002D020);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002D1E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002D24C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002D780);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002D8AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002D94C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002DA94);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002DB50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002DC34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002DD34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002DE7C);

EXTERN_C void func_8002DED8(void *p, int a)
{
    func_8002DD34(p, a);
}

EXTERN_C void func_8002DEF8(void *p, int a, int b)
{
    func_8002DC34(p, a, b);
}

EXTERN_C void func_8002DF18(void *p, int a)
{
    func_8002DA94(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002DF38);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002DF9C);

EXTERN_C void func_8002E000(void *p, int a)
{
    func_8002D8AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E020);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E054);

EXTERN_C S_Rgb func_8002E088(S_8002E088 *p)
{
    return p->unk28;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E0A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E2AC);

EXTERN_C void *func_8002E4B8(S_8002E4B8 *p)
{
    return &p->unk20;
}

EXTERN_C void func_8002E4C0(S_8002E4B8 *p)
{
    p->unk2C = 1;
}

EXTERN_C void func_8002E4CC(S_8002E4B8 *p)
{
    p->unk2C = 0;
}

EXTERN_C void func_8002E4D4(S_8002E4B8 *p, int v)
{
    p->unk1C = v;
}

EXTERN_C int func_8002E4DC(S_8002E4B8 *p)
{
    return p->unk1C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E4E8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E564);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E5B0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E5D0);

EXTERN_C int func_8002E5F0()
{
    return D_800AC809[0] != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E600);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E69C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E714);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E7A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E814);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E898);

EXTERN_C int func_8002E908(S_8002E908 *p)
{
    return p->unk10;
}

EXTERN_C int func_8002E914(S_8002E908 *p)
{
    return p->unk10;
}

EXTERN_C int func_8002E920(S_8002E908 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E92C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002E9D0);

EXTERN_C int func_8002EA0C(S_8002E908 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EA18);

EXTERN_C void func_8002EA50(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800117A4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800117BC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800117D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EA70);

EXTERN_C void func_8002EAAC()
{
}

EXTERN_C void func_8002EAB4()
{
}

EXTERN_C void func_8002EABC()
{
}

EXTERN_C void func_8002EAC4()
{
}

EXTERN_C void func_8002EACC()
{
}

EXTERN_C void func_8002EAD4()
{
}

EXTERN_C void func_8002EADC(S_8002E908 *p, int a, int b)
{
    p->unk8 = a;
    p->unkA = b;
}

EXTERN_C void func_8002EAE8(S_8002E908 *p, int a, int b)
{
    p->unkC = a;
    p->unkE = b;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EAF4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EB68);

EXTERN_C S_8002EBF0 *func_8002EBF0(S_8002EBF0 *p)
{
    p->unk0 = 0;
    p->unk2 = 0;
    return p;
}

EXTERN_C S_8002EC00 *func_8002EC00(S_8002EC00 *p)
{
    p->unk0 = 0;
    p->unk2 = 0;
    p->unk4 = 0;
    p->unk6 = 0;
    return p;
}

EXTERN_C S_8002EC18 *func_8002EC18(S_8002EC18 *p)
{
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    return p;
}

EXTERN_C void func_8002EC30()
{
}

EXTERN_C int func_8002EC38()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EC40);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EC90);

EXTERN_C void func_8002ECE0()
{
}

EXTERN_C void func_8002ECE8()
{
}

EXTERN_C void func_8002ECF0()
{
    func_80019920((List *)&D_800AC820, 2);
}

EXTERN_C void func_8002ED18()
{
    func_800198E0(&D_800AC820, 0x10, 0);
}

EXTERN_C void *func_8002ED44(void *p, int a, int b)
{
    func_800198E0(p, a, b);
    return p;
}

EXTERN_C void func_8002ED6C(S_8002ED6C *p)
{
    func_80019C68(p, p->unk4 - 1);
}

EXTERN_C void *func_8002ED90(S_8002ED90 *p)
{
    return &p->unk8;
}

EXTERN_C S_Rgb func_8002ED98(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C S_Rgb func_8002EDB8(S_80025A64 *p)
{
    return p->unk8;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EDD8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EE10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EE40);

EXTERN_C void func_8002EE7C(void *p, int a)
{
    func_8002EE9C(p, a);
}

EXTERN_C void func_8002EE9C(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800118DC;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EEC4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EEFC);

EXTERN_C int func_8002EF64(S_8002EF64 *p)
{
    return p->unk10;
}

EXTERN_C S_8002EC18 *func_8002EF70(S_8002EC18 *p)
{
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002EF88);

EXTERN_C void func_8002F004(void *p, void *q)
{
    func_8002DB50(q, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F028);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F180);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F1BC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F21C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F2A4);

EXTERN_C int func_8002F32C(S_8002F32C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F338);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F464);

EXTERN_C int func_8002F4C4()
{
    return 0;
}

EXTERN_C int func_8002F4CC(S_8002F4CC *p)
{
    return p->unk14;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F4D8);

EXTERN_C void func_8002F520(void *p, int a)
{
    func_8002EEFC(p, a);
}

EXTERN_C void *func_8002F540(S_8002F4CC *p)
{
    return &p->unkC;
}

EXTERN_C void func_8002F548()
{
}

EXTERN_C int func_8002F550()
{
    return -1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F558);

EXTERN_C int func_8002F580(unsigned int a)
{
    return (a >> 5) & 3;
}

EXTERN_C int func_8002F58C(int a, int b)
{
    return (a & 0xFF9F) | ((b & 3) << 5);
}

EXTERN_C int func_8002F5A0(int v)
{
    int old = D_800B4D00;
    D_800B4D00 = v;
    return old;
}

EXTERN_C void func_8002F5B0(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F5D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F614);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F7D4);

EXTERN_C int func_8002F818(S_8002F818 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F824);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F874);

EXTERN_C int func_8002F8D0()
{
    return 0;
}

EXTERN_C void func_8002F8D8()
{
}

EXTERN_C S_8002F8E0 *func_8002F8E0(S_8002F8E0 *p)
{
    p->vtbl = D_80011B5C;
    p->unk0 = 0;
    return p;
}

EXTERN_C int func_8002F8F8(int *p, int i)
{
    return p[i];
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F90C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F960);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002F998);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FA20);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FA50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FAF8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FB8C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FC40);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FCF4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FD5C);

EXTERN_C int func_8002FD98(S_8002FD98 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FDA4);

EXTERN_C int func_8002FE3C(void *p, int i)
{
    return D_800B4D08[i];
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FE54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8002FEC8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030084);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800300C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800301BC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030358);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030384);

EXTERN_C int func_800303FC()
{
    return 0;
}

EXTERN_C void func_80030404()
{
}

EXTERN_C void func_8003040C()
{
}

EXTERN_C void func_80030414()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003041C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800304B4);

EXTERN_C int func_80030520()
{
    return 0;
}

EXTERN_C int func_80030528(S_80030528 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030534);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030608);

EXTERN_C int *func_80030694(int *p)
{
    func_8001AA28(p, 6);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800306C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030714);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003074C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800307D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030804);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800308B0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030940);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800309F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030AA8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030B10);

EXTERN_C int func_80030B4C(S_80030B4C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030B58);

EXTERN_C int func_80030BF0(int a)
{
    return (a + 1) & 3;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030BFC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030C70);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030E9C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80030EE0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80031030);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800311CC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800311F8);

EXTERN_C int func_80031278()
{
    return 0x28;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80031280);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800313BC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800313E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003148C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800318A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80031CE4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003212C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032174);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800321D8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032264);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800322C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032334);

EXTERN_C void func_800323C0(S_800323C0 *p, S_800323C0_Node *n)
{
    if (p->unk8)
        n->unk4 = p->unk8;
    p->unk8 = n;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800323DC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032504);

EXTERN_C int func_80032920(S_80032920 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003292C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032A10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032A9C);

EXTERN_C void func_80032B14(S_Rgb *a, S_Rgb *b)
{
    *a = *b;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032B2C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032BD8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032C80);

EXTERN_C S_Prim *func_80032CBC(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 5;
    p->code = 0x28;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032CD4);

EXTERN_C int func_80032D54()
{
    return 0x2C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032D5C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032EB0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032ED4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80032F80);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033404);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800338A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033D34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033D7C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033DAC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033DDC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033E40);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033ECC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033F30);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80033F9C);

EXTERN_C void func_80034028(S_800323C0 *p, S_800323C0_Node *n)
{
    if (p->unk8)
        n->unk4 = p->unk8;
    p->unk8 = n;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034044);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034184);

EXTERN_C int func_80034608(S_80034608 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034614);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034710);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003479C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034854);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003488C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800348E4);

EXTERN_C S_80034924_B *func_80034924(S_80034924_A *p, S_80034924_B *q)
{
    int a = p->unk4, b = p->unk8, c = p->unkC, d = p->unk10;
    q->unkC = a;
    q->unk14 = b;
    q->unk1C = c;
    q->unk24 = d;
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003494C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800349F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034AA0);

EXTERN_C S_Prim *func_80034AF4(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 9;
    p->code = 0x2C;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034B0C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034B84);

EXTERN_C S_80034BA8 *func_80034BA8(S_80034BA8 *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C int func_80034BB4(S_80034BB4 *p)
{
    return (p->unk3 >> 1) & 1;
}

EXTERN_C void func_80034BC8(int *a, int *b)
{
    *a = *b;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034BD4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034EBC);

EXTERN_C void func_80034F24(S_80034F24 *p, int a)
{
    p->unk6 = (p->unk6 & 0xFF9F) | ((a & 3) << 5);
}

EXTERN_C int func_80034F40(S_80034F40 *p)
{
    return (p->unk6 >> 5) & 3;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80034F54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800351A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003525C);

EXTERN_C int func_800352D4()
{
    return 0;
}

EXTERN_C int func_800352DC(S_800352DC *p)
{
    return p->unk4;
}

EXTERN_C void func_800352E8(S_800352DC *p, int v)
{
    p->unk4 = v;
}

EXTERN_C S_Vobj *func_800352F0(S_Vobj *p)
{
    p->vtbl = D_80011FE4;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035304);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035384);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003546C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003556C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035678);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800356F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003572C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800357E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003585C);

EXTERN_C int func_800358D4(S_800358D4 *p)
{
    return p->unk1C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800358E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035910);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035940);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003598C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035A28);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035AB0);

EXTERN_C void func_80035AE4()
{
}

EXTERN_C int func_80035AEC()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035AF4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035B28);

EXTERN_C void func_80035B5C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035B64);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035B98);

EXTERN_C void func_80035BF0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035BF8);

EXTERN_C void func_80035C28()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035C30);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035CA8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035CD8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035CF8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035D4C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035DE0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035E4C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035EB4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035F18);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80035F80);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036000);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036090);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036110);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800361C8);

EXTERN_C void func_8003635C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036364);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800118DC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800118FC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001199C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011A44);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011AAC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011B14);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011B5C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011B8C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011BF4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011C44);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011CAC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011D04);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011D6C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011DBC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011E24);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011E74);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011E8C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011EF4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011F44);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011F5C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011F74);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80011FE4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001201C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012034);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012074);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001208C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800120B4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800120F4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012104);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001211C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012154);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800121AC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012224);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012294);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036554);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036674);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800366F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036780);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036850);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036D8C);

EXTERN_C void *func_80036EB8(void *p, void *q)
{
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036EC0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036F14);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036F54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80036FC0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800370D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003714C);

EXTERN_C int func_80037258(S_80037258 *p)
{
    return p->unk28;
}

EXTERN_C void func_80037264()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC854)->p, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003728C);

EXTERN_C int func_800372C0(S_800372C0 *p)
{
    return p->unk2C + p->unk4->unk4;
}

EXTERN_C int func_800372D4(S_80037258 *p)
{
    return p->unk2C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800372E0);

EXTERN_C int func_80037380()
{
    return D_800B4D0C;
}

EXTERN_C int func_8003738C(void *p, int a)
{
    return (a & 0x1D) != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037398);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800373F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037440);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800374F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037524);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037554);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037584);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800375B4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800375E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037688);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800376D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037834);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001231C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001232C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800378A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037934);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800379D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037A20);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012364);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001237C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800123EC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012404);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80037AAC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800382A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003831C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800384C4);

EXTERN_C void func_80038508()
{
    func_80037688(&D_800AC86C);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003852C);

EXTERN_C int func_800385E4(S_800385E4 *p)
{
    return p->unk10;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800385F0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038654);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800386B8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038764);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800387D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038834);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038898);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800388FC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038938);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038978);

EXTERN_C int func_800389B8()
{
    return 1;
}

EXTERN_C int func_800389C0()
{
    return 1;
}

EXTERN_C int func_800389C8()
{
    return 1;
}

EXTERN_C int func_800389D0()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800389D8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038B0C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038C20);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012484);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001252C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001257C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012594);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001260C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001262C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038C64);

EXTERN_C void func_80038D14(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038D34);

EXTERN_C void func_80038E2C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038E34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038E98);

EXTERN_C int func_80038EF0(S_80038EF0 *p)
{
    return p->unk24;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038EFC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80038FB8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003906C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003912C);

EXTERN_C void func_800391DC(S_800391DC *p, int a, int b)
{
    p->unk64 = b;
    p->unk48->unk14 = a;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800391EC);

EXTERN_C int func_800392C8(S_800392C8 *p)
{
    return p->unk24;
}

EXTERN_C void func_800392D4(void *p)
{
    func_8003C320(p, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800392F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039388);

EXTERN_C void func_80039444(S_80039444 *p, int v)
{
    p->unk50 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003944C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003950C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039610);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039710);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039824);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039928);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039960);

EXTERN_C int func_800399A4(S_800399A4 *p)
{
    return p->unk4;
}

EXTERN_C void func_800399B0(S_800399B0 *p)
{
    p->unk4 = p->unk0->unk4;
}

EXTERN_C void func_800399C4(S_800399A4 *p)
{
    p->unk4 = 0;
}

EXTERN_C void func_800399CC(S_800399A4 *p, int v)
{
    p->unk4 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800399D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039A14);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039A88);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039BEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039C88);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039D38);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039D94);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039DD8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039E80);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80039F80);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A010);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A150);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A214);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A318);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A350);

EXTERN_C void func_8003A394(void *p, int a)
{
    func_80039824(p, a);
}

EXTERN_C void func_8003A3B4(void *p, int a)
{
    func_80039710(p, a);
}

EXTERN_C void func_8003A3D4(void *p, int a)
{
    func_80039610(p, a);
}

EXTERN_C void func_8003A3F4(void *p, int a)
{
    func_8003950C(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A414);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A454);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A490);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A4C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A4F0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A538);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A574);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A624);

EXTERN_C void func_8003A654(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A674);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A6B4);

EXTERN_C void *func_8003A6F4(S_8003A6F4 *p)
{
    return &p->unk34;
}

EXTERN_C void *func_8003A6FC(S_8003A6F4 *p)
{
    return &p->unk2C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A704);

EXTERN_C int func_8003A738(S_8003A6F4 *p)
{
    return p->unk24;
}

EXTERN_C void func_8003A744(S_8003A6F4 *p)
{
    p->unk24 = 0;
}

EXTERN_C void func_8003A74C(S_8003A6F4 *p, int v)
{
    p->unk24 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A754);

EXTERN_C void *func_8003A7A4(void *p, int a)
{
    func_8001A8F0(p, a, 8);
    return p;
}

EXTERN_C void *func_8003A7D0(void *p, int a)
{
    func_8001A8F0(p, a, 8);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003A7FC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003ABEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003AD78);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B168);

EXTERN_C S_8003B2F0 *func_8003B2F0(S_8003B2F0 *p, S_8003B2F0_V *v)
{
    int a = v->unk0, b = v->unk4, c = v->unk8;
    p->unk14.unk0 = a;
    p->unk14.unk4 = b;
    p->unk14.unk8 = c;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B310);

EXTERN_C MATRIX *func_8003B334(MATRIX *p, MATRIX *q)
{
    MulMatrix(p, q);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B35C);

EXTERN_C MATRIX *func_8003B3C0(MATRIX *p, MATRIX *q)
{
    CompMatrix(p, q, p);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B3EC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B450);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B598);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B68C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B780);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B834);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B8AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B960);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003B9D8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BA78);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BAD8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BB78);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BBD8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BC10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BC50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BC84);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BCB0);

EXTERN_C void func_8003BCE0(MATRIX *m, int i, SVECTOR *v)
{
    m->m[0][i] = v->vx;
    m->m[1][i] = v->vy;
    m->m[2][i] = v->vz;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BD08);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BDB8);

EXTERN_C S_Short func_8003BE68(S_Short *a, S_Short *b)
{
    S_Short r;
    int t = a->v;
    t += b->v;
    r.v = t;
    return r;
}

EXTERN_C S_Int func_8003BE84(S_Int *a, S_Int *b)
{
    S_Int r;
    r.v = a->v + b->v;
    return r;
}

EXTERN_C S_8003BEA0 *func_8003BEA0(S_8003BEA0 *p, int i)
{
    return &p[i];
}

EXTERN_C void *func_8003BEB4(void *p)
{
    return p;
}

EXTERN_C void *func_8003BEBC(void *p)
{
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BEC4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BEF8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003BF30);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C01C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C0D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C1E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C270);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C2E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C320);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C3E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C434);

EXTERN_C void func_8003C4CC(void *p, int a)
{
    func_8003BEC4(p, a);
}

EXTERN_C void func_8003C4EC()
{
    func_8003C510(&D_800B4D1C);
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012674);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800126DC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800126F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C510);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C524);

EXTERN_C int func_8003C584(S_8003C584 *p)
{
    if (p->unk48 != 0) {
        return p->unk48->unk14;
    } else {
        return 0;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C5A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C5EC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C764);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003C908);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CA10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CAD0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CB50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CC78);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CE00);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CE44);

EXTERN_C int func_8003CE88(S_8003CE88 *p)
{
    return p->unk8;
}

EXTERN_C int func_8003CE94(S_8003CE88 *p)
{
    return p->unk14;
}

EXTERN_C void func_8003CEA0(S_8003CE88 *p, int v)
{
    p->unk14 = v;
}

EXTERN_C int func_8003CEA8(S_8003CE88 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CEB4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CEEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003CF24);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003D00C);

EXTERN_C void func_8003D358(S_8003D358 *p, int a, S_Rgb c)
{
    p->unkC = a;
    p->unkE = c;
}

EXTERN_C void *func_8003D37C(S_8003D37C *p)
{
    return &p->unkE;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003D384);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003D3A0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003D68C);

EXTERN_C int func_8003D9F0(S_8003D9F0 *p)
{
    return p->unkC;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003D9FC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003DB1C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003DC54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003DEA8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003E124);

EXTERN_C int func_8003E170(S_8003E170 *p)
{
    return func_8003E658(p, p->unk13C);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003E198);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003E5F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003E658);

EXTERN_C void func_8003EBC4(S_8003EBC4 *p, int v)
{
    p->unk1B8 = v;
}

EXTERN_C void func_8003EBCC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003EBD4);

EXTERN_C void func_8003ECE4(S_8003ECE4 *p, int *a, int *b)
{
    *a = p->unk100;
    *b = p->unk104;
}

EXTERN_C void func_8003ECFC(S_8003ECFC *p, int a, int b)
{
    p->unk100 = a;
    if (b)
        p->unk104 = b;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003ED10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003ED90);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003F1C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003F3DC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003F594);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003F73C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003F7E8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003F850);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003F8CC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FA50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FAEC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FB88);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FC08);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FC48);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FC84);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FD30);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FD70);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FD9C);

EXTERN_C int func_8003FDDC(S_8003FDDC *p)
{
    return p->unk144;
}

EXTERN_C void *func_8003FDE8(S_8003FDDC *p)
{
    return &p->unk146;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FDF0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FE34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FE64);

EXTERN_C void func_8003FEA8(S_8003FDDC *p, int v)
{
    p->unk138 = v;
}

EXTERN_C void func_8003FEB0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FEB8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8003FEF4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004007C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800400D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800401AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800401F0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004025C);

EXTERN_C int func_80040294(S_80040294 *p, short a)
{
    return p->unk28 + a * 16;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800402A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800402E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800404C8);

EXTERN_C int func_800406A0(S_800406A0 *p)
{
    return p->unk1C;
}

EXTERN_C int func_800406AC(S_800406A0 *p)
{
    return p->unk13;
}

EXTERN_C int func_800406B8(S_800406A0 *p)
{
    return p->unk12;
}

EXTERN_C int func_800406C4(S_800406A0 *p)
{
    return p->unk14;
}

EXTERN_C int func_800406D0(S_800406A0 *p)
{
    return p->unk10;
}

EXTERN_C int func_800406DC(S_800406A0 *p)
{
    return p->unkE;
}

EXTERN_C int func_800406E8(S_800406A0 *p)
{
    return p->unkC;
}

EXTERN_C int func_800406F4(S_800406A0 *p)
{
    return p->unkA;
}

EXTERN_C int func_80040700(S_800406A0 *p)
{
    return p->unk8;
}

EXTERN_C int func_8004070C(S_800406A0 *p)
{
    return p->unk2C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80040718);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80040C10);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800410F4);

EXTERN_C void *func_800419A8(void *p)
{
    func_80040718(p);
    return p;
}

EXTERN_C S_800419D0 *func_800419D0(S_800419D0 *p)
{
    p->unk4 = 0x1000;
    p->unk0 = 0x1000;
    p->unk10 = 0;
    p->unk12 = 0;
    p->unk14 = 0x2000;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800419F4);

EXTERN_C int func_80041B44(int a)
{
    D_800B4D30 = 0;
    D_800B4D2C = a;
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80041B54);

EXTERN_C void func_80041BF8(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80041C18);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80041C50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80041C88);

EXTERN_C S_80041CB8 *func_80041CB8(S_80041CB8 *p)
{
    p->unk4 = 0;
    p->unk0 = 1;
    return p;
}

EXTERN_C int func_80041CCC(S_80041CCC *p)
{
    return p->unk0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80041CD8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80041D84);

EXTERN_C S_80041E28 *func_80041E28(S_80041E28 *p, int a, int b, int c, int d)
{
    p->vtbl = D_800127FC;
    p->unk4 = a;
    p->unk14 = 0;
    p->unk8 = b;
    p->unkC = c;
    p->unk10 = d;
    return p;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012724);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001276C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001277C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012794);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800127AC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800127D4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800127E4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800127FC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012814);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012864);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001287C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001289C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800128CC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80041E54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80042140);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800423A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80042430);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800424B0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004252C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800425A8);

EXTERN_C void func_80042818()
{
}

EXTERN_C void func_80042820()
{
}

EXTERN_C void func_80042828()
{
}

EXTERN_C void func_80042830()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80042838);

EXTERN_C void func_8004296C()
{
}

EXTERN_C void func_80042974()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004297C);

EXTERN_C int func_80042A74()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80042A7C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80042D3C);

EXTERN_C int func_80042E08()
{
    return 1;
}

EXTERN_C int func_80042E10()
{
    return 1;
}

EXTERN_C int func_80042E18()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80042E20);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80042EF0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043060);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800433CC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043460);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043540);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800435AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800435E8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043680);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800436C0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043700);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043740);

EXTERN_C void func_8004377C(S_8004377C *p, int a)
{
    p->unk11A = a;
    if (p->unk220 == 0) {
        p->unkF8 = 0;
        p->unk120++;
    }
    p->unk138 = 0;
}

EXTERN_C void func_800437A4(S_8004377C *p, int a)
{
    p->unk11C = a;
    if (p->unk220 == 0) {
        p->unkF8 = 0;
        p->unk120++;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800437CC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043808);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004387C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043A94);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043D38);

EXTERN_C S_80043D94_V func_80043D94(S_80043D94 *p)
{
    return p->unk284;
}

EXTERN_C void func_80043DC0(S_80043DC0 *p)
{
    p->unk26C = 0;
    p->unk26E = 0;
    p->unk270 = 0;
    p->unk20C = D_800A4534.unkC + 20;
}

EXTERN_C int func_80043DE8()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80043DF0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044590);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004463C);

EXTERN_C void func_8004467C(S_8004467C *p)
{
    p->unk214 = 0;
}

EXTERN_C void func_80044684(S_8004467C *p)
{
    p->unk214 = 1;
}

EXTERN_C void func_80044690(S_80044690 *p)
{
    p->unkF8 = 0;
    p->unk220 = 0;
    p->unk120++;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800446A8);

EXTERN_C int func_80044730()
{
    return 1;
}

EXTERN_C void func_80044738()
{
}

EXTERN_C int func_80044740(S_80044740 *p)
{
    func_80043DF0(p->unk4);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044764);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800447D8);

EXTERN_C void func_80044814(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044834);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044890);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044990);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044A3C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044BE4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044C7C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044CE0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80044F18);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800450E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045120);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800451A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045264);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004561C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800456F4);

EXTERN_C void func_8004580C(S_8004580C *p, int v, int i)
{
    p->unkF8[i] = v;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004581C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045850);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800459D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045B38);

EXTERN_C void func_80045C88(S_80045C88 *p, int a)
{
    p->unk1C[p->unk44++] = a;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045CAC);

EXTERN_C int func_80045D18(S_80045D18 *p)
{
    return p->unk30;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045D24);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045DC8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045E6C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045EB8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80045F84);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004600C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80046078);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800460E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004616C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800461F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004637C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800464E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80046658);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800467CC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80046844);

EXTERN_C void func_800468D0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800468D8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80046948);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001295C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012974);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001298C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_8001299C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800129AC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800129C4);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800129FC);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012A18);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80046998);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80048C30);

EXTERN_C void func_80048D2C(void *p, int a)
{
    if (a & 1)
        operator delete(p);
}

EXTERN_C void *func_80048D54(void *p)
{
    return p;
}

EXTERN_C void func_80048D5C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80048D64);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004921C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049250);

EXTERN_C void *func_80049398(void *p)
{
    return p;
}

EXTERN_C S_1F80000C *func_800493A0(void *p, int i)
{
    return &D_1F80000C[i];
}

EXTERN_C int func_800493BC(S_800493BC *p)
{
    return p->unkB;
}

EXTERN_C void func_800493C8(S_800493C8 *p, int a)
{
    p->unk8 = (a << 24) | (p->unk8 & 0xFFFFFF);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800493E8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049420);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049488);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049594);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800495D8);

EXTERN_C S_1F800010 *func_80049618(void *p, int i)
{
    return &D_1F800010[i];
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004962C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049680);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049748);

EXTERN_C unsigned int *func_800497A8(unsigned int *p)
{
    int i;
    unsigned int c = 0x30808080;
    for (i = 2; i >= 0; i--)
        p[i] = c;
    return p;
}

EXTERN_C void func_800497D4(int *a, int *b)
{
    int i;
    for (i = 0; i < 3; i++)
        *a++ = *b++;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012BC8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012BF8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012C28);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012C58);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800497FC);

EXTERN_C void func_80049858()
{
}

EXTERN_C int func_80049860()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049868);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004991C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800499D0);

EXTERN_C int func_80049A7C(void *p, int i)
{
    return D_800B4D3C[i];
}

EXTERN_C void func_80049A94(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049AB4);

EXTERN_C void *func_80049B2C(S_80049B2C *p)
{
    return &p->unk44;
}

EXTERN_C int func_80049B34()
{
    return 0x20;
}

EXTERN_C int func_80049B3C()
{
    return 0;
}

EXTERN_C void func_80049B44()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049B4C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049CE4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049D2C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049E98);

EXTERN_C void func_80049F00(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012CF8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049F28);

EXTERN_C void *func_80049FA0(S_80049FA0 *p)
{
    return &p->unk44;
}

EXTERN_C int func_80049FA8()
{
    return 0;
}

EXTERN_C void func_80049FB0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80049FB8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A16C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A2F4);

EXTERN_C void func_8004A35C(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012CF8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A384);

EXTERN_C void *func_8004A404(S_8004A404 *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004A40C()
{
    return 0x24;
}

EXTERN_C int func_8004A414()
{
    return 0;
}

EXTERN_C void func_8004A41C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A424);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A5C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A610);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A640);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A670);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A7F0);

EXTERN_C void func_8004A874(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A89C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A954);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A98C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004A9E4);

EXTERN_C S_8004AA24_B *func_8004AA24(S_8004AA24_A *p, S_8004AA24_B *q)
{
    int a = p->unk4, b = p->unk8, c = p->unkC;
    q->unkC = a;
    q->unk14 = b;
    q->unk1C = c;
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004AA44);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004AAF0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004AB98);

EXTERN_C S_Prim *func_8004ABEC(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 7;
    p->code = 0x24;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004AC04);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004AE24);

EXTERN_C void func_8004AE8C(S_80034F24 *p, int a)
{
    p->unk6 = (p->unk6 & 0xFF9F) | ((a & 3) << 5);
}

EXTERN_C int func_8004AEA8(S_80034F40 *p)
{
    return (p->unk6 >> 5) & 3;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004AEBC);

EXTERN_C void *func_8004AF3C(S_8004AF3C *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004AF44()
{
    return 0;
}

EXTERN_C void func_8004AF4C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004AF54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004B124);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004B2C4);

EXTERN_C void func_8004B348(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004B370);

EXTERN_C void *func_8004B3F0(S_8004B3F0 *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004B3F8()
{
    return 0;
}

EXTERN_C void func_8004B400()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004B408);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004B690);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004B83C);

EXTERN_C void func_8004B8C8(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

EXTERN_C int func_8004B8F0()
{
    return 0x30;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004B8F8);

EXTERN_C void func_8004B970(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004B998);

EXTERN_C void *func_8004BA18(S_8004BA18 *p)
{
    return &p->unk5C;
}

EXTERN_C int func_8004BA20()
{
    return 0;
}

EXTERN_C void func_8004BA28()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004BA30);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004BBCC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004BC14);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004BD84);

EXTERN_C void func_8004BE10(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004BE38);

EXTERN_C void *func_8004BEB8(S_8004BEB8 *p)
{
    return &p->unk58;
}

EXTERN_C int func_8004BEC0()
{
    return 0;
}

EXTERN_C void func_8004BEC8()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004BED0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C08C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C0D4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C254);

EXTERN_C void func_8004C2E4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

EXTERN_C int func_8004C30C()
{
    return 0x34;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C314);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C35C);

EXTERN_C void func_8004C3D4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C3FC);

EXTERN_C void *func_8004C474(S_8004C474 *p)
{
    return &p->unk78;
}

EXTERN_C int func_8004C47C()
{
    return 0;
}

EXTERN_C void func_8004C484()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C48C);

EXTERN_C char *func_8004C660(void *p, char *q)
{
    func_8004C314(p, q);
    return q + 0x18;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C688);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C6EC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C738);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C8D0);

EXTERN_C void func_8004C960(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004C988);

EXTERN_C void *func_8004CA00(S_8004CA00 *p)
{
    return &p->unk78;
}

EXTERN_C int func_8004CA08()
{
    return 0;
}

EXTERN_C void func_8004CA10()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004CA18);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004CC7C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004CE14);

EXTERN_C void func_8004CEA4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

EXTERN_C unsigned int *func_8004CECC(unsigned int *p)
{
    int i;
    unsigned int c = 0x38808080;
    for (i = 3; i >= 0; i--)
        p[i] = c;
    return p;
}

EXTERN_C void func_8004CEF8(int *a, int *b)
{
    int i;
    for (i = 0; i < 4; i++)
        *a++ = *b++;
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012CF8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012D70);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012DE8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012E60);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012ED8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012F50);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80012FC0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013038);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800130B0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013120);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013198);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004CF20);

EXTERN_C void func_8004CF7C()
{
}

EXTERN_C int func_8004CF84()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004CF8C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D040);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D0F4);

EXTERN_C int func_8004D1A0(void *p, int a)
{
    return (a + 1) & 3;
}

EXTERN_C void func_8004D1AC(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D1CC);

EXTERN_C void *func_8004D244(S_8004D244 *p)
{
    return &p->unk50;
}

EXTERN_C int func_8004D24C()
{
    return 0x28;
}

EXTERN_C int func_8004D254()
{
    return 0;
}

EXTERN_C void func_8004D25C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D264);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D464);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D4AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D678);

EXTERN_C void func_8004D6E0(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013280;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D708);

EXTERN_C void *func_8004D780(S_8004D780 *p)
{
    return &p->unk50;
}

EXTERN_C int func_8004D788()
{
    return 0;
}

EXTERN_C void func_8004D790()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D798);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004D9AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004DB8C);

EXTERN_C void func_8004DBF4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013280;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004DC1C);

EXTERN_C void *func_8004DC8C(S_8004DC8C *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004DC94()
{
    return 0x2C;
}

EXTERN_C int func_8004DC9C()
{
    return 0;
}

EXTERN_C void func_8004DCA4()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004DCAC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004DEDC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004DF24);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004DF54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004DF84);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004E17C);

EXTERN_C void func_8004E200(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004E228);

EXTERN_C void *func_8004E298(S_8004E298 *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004E2A0()
{
    return 0;
}

EXTERN_C void func_8004E2A8()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004E2B0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004E4FC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004E700);

EXTERN_C void func_8004E784(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004E7AC);

EXTERN_C void *func_8004E81C(S_8004E81C *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004E824()
{
    return 0;
}

EXTERN_C void func_8004E82C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004E834);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004EB28);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004ED40);

EXTERN_C void func_8004EDCC(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

EXTERN_C int func_8004EDF4()
{
    return 0x38;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004EDFC);

EXTERN_C void func_8004EE74(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004EE9C);

EXTERN_C void *func_8004EF1C(S_8004EF1C *p)
{
    return &p->unk74;
}

EXTERN_C int func_8004EF24()
{
    return 0;
}

EXTERN_C void func_8004EF2C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004EF34);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F144);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F18C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F368);

EXTERN_C void func_8004F3F4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F41C);

EXTERN_C void *func_8004F49C(S_8004F49C *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004F4A4()
{
    return 0;
}

EXTERN_C void func_8004F4AC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F4B4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F6F0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F738);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F924);

EXTERN_C void func_8004F9B4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

EXTERN_C int func_8004F9DC()
{
    return 0x3C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004F9E4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004FA2C);

EXTERN_C void func_8004FAA4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004FACC);

EXTERN_C void *func_8004FB4C(S_8004FB4C *p)
{
    return &p->unk98;
}

EXTERN_C int func_8004FB54()
{
    return 0;
}

EXTERN_C void func_8004FB5C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004FB64);

EXTERN_C char *func_8004FDC8(void *p, char *q)
{
    func_8004F9E4(p, q);
    return q + 0x1C;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004FDF0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004FE54);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8004FEA0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800500B4);

EXTERN_C void func_80050144(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8005016C);

EXTERN_C void *func_800501EC(S_800501EC *p)
{
    return &p->unk98;
}

EXTERN_C int func_800501F4()
{
    return 0;
}

EXTERN_C void func_800501FC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80050204);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800504E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800506F4);

EXTERN_C void func_80050784(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013280);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800132F8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013370);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800133E8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013460);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800134D8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013548);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800135C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013638);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800136A8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013720);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800507AC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800507D4);

EXTERN_C S_80050838 *func_80050838(S_80050838 *p)
{
    p->unk0 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80050844);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80050874);

EXTERN_C void func_80050E38(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80050E58);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80050EA4);

EXTERN_C void *func_800514C0(void *p)
{
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800514C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051514);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051564);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800515A4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800515F4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800518A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051930);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051A2C);

EXTERN_C void func_80051A7C(S_80051A7C *p, int a)
{
    if (p->unk104 == 0)
        p->unk104 = a;
    p->unk124 = 0;
    p->unkFC++;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051AA4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051B70);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051C3C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051CB0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051D80);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051E50);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051E90);

EXTERN_C int func_80051ECC(S_80051ECC *p)
{
    return p->unk11A;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051ED8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051F0C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80051FB8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80052044);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800520BC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80052100);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8005226C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800523DC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800525EC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80052640);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80052778);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8005287C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8005294C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80052B60);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80052C8C);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800137C0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800137D8);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_800137F0);

INCLUDE_RODATA("asm/main/nonmatchings/main_a", D_80013808);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80052E40);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80052FB8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800530B8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053250);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800532EC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053360);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8005340C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800534F8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053568);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800535E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053658);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800536F0);

EXTERN_C int func_80053794(S_80053794 *p)
{
    return p->unk4;
}

EXTERN_C void func_800537A0(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C S_800537C0 *func_800537C0(S_800537C0 *p)
{
    p->vtbl = D_80013B00;
    p->unk0 = 0;
    p->unk4 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800537DC);

EXTERN_C int func_80053830(S_80053830 *p)
{
    return --p->unk4 > 0;
}

EXTERN_C void func_80053848(S_80053830 *p)
{
    if (p->unk4 >= 2)
        p->unk4 = 1;
}

EXTERN_C int func_80053868(S_80053794 *p)
{
    return p->unk0;
}

EXTERN_C int func_80053874(S_80053794 *p)
{
    return p->unk4;
}

EXTERN_C int func_80053880(S_80053794 *p)
{
    return p->unk4 < 1;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8005388C);

EXTERN_C void func_800538B4(int v)
{
    D_800B4D5C = v;
}

EXTERN_C void func_800538C0(int v)
{
    D_800B4D60 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800538CC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053928);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053964);

EXTERN_C void func_800539C0()
{
}

EXTERN_C void func_800539C8()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800539D0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053AE4);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053B68);

EXTERN_C int func_80053BB4(S_80053BB4 *p)
{
    return p->unk14;
}

EXTERN_C int func_80053BC0(S_80053BB4 *p)
{
    return p->unk10;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053BCC);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053C6C);

EXTERN_C void func_80053CD8(void *p)
{
    func_80053BCC(p, &D_800B4D64, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053D00);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053DDC);

EXTERN_C void func_80053F28(S_80025A64 *p, S_Rgb c)
{
    p->unkC = c;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053F48);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80053FB0);

EXTERN_C void func_8005402C(S_8005402C *p, int a, int b)
{
    p->unkC += a;
    p->unkE += b;
}

EXTERN_C int func_80054048(S_80054048 *p)
{
    return p->unk8;
}

EXTERN_C S_Rgb func_80054054(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C int func_80054074(S_80054048 *p)
{
    return p->unk4 & 0x3;
}

EXTERN_C int func_80054080(S_80054048 *p)
{
    return p->unk4;
}

EXTERN_C void func_8005408C(S_80054048 *p, int v)
{
    p->unk4 = v;
}

EXTERN_C void func_80054094(S_80054048 *p, int v)
{
    p->unk0 = v;
}

EXTERN_C int func_8005409C(S_80054048 *p)
{
    return p->unk0 == 0;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800540A8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054258);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800543A0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054414);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800544AC);

EXTERN_C void func_8005457C(S_8005457C *p, int v)
{
    p->unk8 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054584);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800545E0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_8005464C);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054690);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800546C8);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054708);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_800548F0);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054920);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054950);

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054980);

EXTERN_C int func_800549B0(S_800549B0 *p, int a)
{
    return p->unk1C == a;
}

EXTERN_C int func_800549C4(S_800549B0 *p, int a)
{
    return p->unk1C != a;
}

EXTERN_C int func_800549D8(S_800549D8 *p)
{
    return p->unk1C;
}

EXTERN_C void func_800549E4(S_800549D8 *p, int v)
{
    p->unk24 = v;
}

EXTERN_C void func_800549EC(S_800549D8 *p, int v)
{
    p->unk20 = v;
}

EXTERN_C void func_800549F4()
{
}

EXTERN_C void func_800549FC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/main_a", func_80054A04);
