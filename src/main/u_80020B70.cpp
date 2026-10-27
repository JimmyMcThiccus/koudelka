#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

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

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80020BE0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80020C64);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80020D44);

EXTERN_C void func_80020D90(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80020DB0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80020E00);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80020E40);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80020EF8);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_8002101C);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021060);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800210A4);

EXTERN_C S_80021274 *func_80021144(S_80021274 *p)
{
    int i;
    for (i = 15; i >= 0; i--)
        p->unk0[i] = 0;
    p->unk40 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021168);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800211F4);

EXTERN_C void func_80021274(S_80021274 *p)
{
    int i;
    for (i = 15; i >= 0; i--)
        p->unk0[i] = 0;
    p->unk40 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021294);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021300);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021348);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_8002141C);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021478);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800215E8);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800216A4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021764);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800218B4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_8002190C);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021ACC);

EXTERN_C int func_80021B54()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021B5C);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021C04);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021F48);

EXTERN_C int func_80021FE4()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021FEC);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022094);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022438);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800224A8);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022518);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_8002256C);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800225C0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022670);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800226A0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800226F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022730);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800227E0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022810);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022868);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022920);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022974);

EXTERN_C int func_800229B0(S_800229B0 *p)
{
    if (p->unk10 == 0) {
        return 0;
    } else {
        return p->unk10->unk8;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800229D4);

EXTERN_C int func_80022A04(S_80022A04 *p)
{
    return p->unk10;
}

EXTERN_C int func_80022A10(S_80022A04 *p)
{
    return p->unk10;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022A1C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022AB4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022B24);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022C34);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022CF0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022D64);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022E28);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022FB8);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800230E8);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800232A0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80023450);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_8002385C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80023AEC);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80023B94);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80023C40);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80023CB8);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80023F50);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800240C0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800244A4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024524);

EXTERN_C int func_8002456C(S_8002456C *p)
{
    return p->unk26 ? --p->unk26 == 0 : 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024594);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_8002466C);

EXTERN_C void func_800246C4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800107C8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800246EC);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024770);

EXTERN_C int func_80024858(S_80024858 *p)
{
    return p->unk10;
}

EXTERN_C int func_80024864(S_80024858 *p)
{
    return p->unk18 != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024870);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800248BC);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024940);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024974);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024A80);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024AF0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024BB0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024BF0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024CA0);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024D40);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024E44);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024EE4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024FA8);

EXTERN_C void func_80024FE4()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024FEC);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80025050);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_8002510C);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80025268);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800107C8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800107F0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80010800);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800252F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_8002537C);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80025444);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80025714);

EXTERN_C void func_80025808()
{
    func_8001DEB8(&D_800B4C48, 2);
}

EXTERN_C void func_80025830()
{
    func_800252F8(&D_800B4C48);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80010840);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80010858);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80010888);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800108A0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800108C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800110C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800110F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011124);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011154);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001116C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800111A4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800111BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800111FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011254);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001126C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800112D4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800112F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011304);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001136C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011384);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011394);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001147C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800114CC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001151C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001162C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001167C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001178C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800117A4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800117BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800117D4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001183C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800118DC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800118FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001199C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011A44);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011AAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011B14);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011B5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011B8C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011BF4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011C44);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011CAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011D04);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011D6C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011DBC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011E24);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011E74);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011E8C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011EF4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011F44);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011F5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011F74);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011FE4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001201C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012034);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012074);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001208C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800120B4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800120F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012104);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001211C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012154);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800121AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012224);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012294);
