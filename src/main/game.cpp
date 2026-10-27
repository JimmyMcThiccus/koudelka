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

// GCC 2.x vtable entries are {short delta; short index; pfn}; run() is the first slot.
struct Item {
    virtual void run();
};

struct List {
    int pad;
    int count;
};

struct Holder : virtual List {
};

EXTERN_C int D_800B4BFC; // call counter, in .sdata
EXTERN_C void func_80094990();
EXTERN_C Item *func_80019F64(List *l, int i);

// Converting to the virtual base each time keeps the null checks retail has.
inline int count_of(List *l) { return l->count; }

EXTERN_C void func_800186E8(Holder *h)
{
    if (++D_800B4BFC == 1) {
        func_80094990();
        for (int i = 0; i < count_of(h); i++)
            func_80019F64(h, i)->run();
    }
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018788);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018840);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800188D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018970);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018A20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018A58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018A88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018AAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018AD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018AF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018B18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018B3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018B64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018B88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018BE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018C1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018C90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018D80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018DF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018E10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018E5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018E88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018EDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018F0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80018FA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800190A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001914C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019158);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800191FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001921C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019274);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800192C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800193AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019478);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001949C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800194A8);

INCLUDE_ASM("asm/main/nonmatchings/game", main);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800100C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800100D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019648);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800196C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019820);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019848);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001986C);

INCLUDE_ASM("asm/main/nonmatchings/game", printf);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019894);

INCLUDE_ASM("asm/main/nonmatchings/game", puts);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800198A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800198AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800198E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019920);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019974);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019A18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019A24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019A6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019B2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019BA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019C24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019C68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019CFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019D40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019D5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019F0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019F64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019FB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80019FC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A00C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800100F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A014);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A030);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A050);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A080);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A0AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A0CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A0F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A114);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A120);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A12C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A138);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A1A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A220);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A294);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A2B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A2D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A354);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010118);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A3BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A46C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A48C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A53C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A55C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A5F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A610);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A678);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A6A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A6E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A708);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A744);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A7B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A844);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A864);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A8B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A8C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A8CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A8D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A8F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001A970);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AA28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AA54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AA68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AB50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AC38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AC80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001ACB4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010148);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010160);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010178);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010198);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800101B0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800101C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001ACDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AD18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AD68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001ADE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AEFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001AF8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B0C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B134);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B1C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B26C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B2D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B300);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B30C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B318);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B338);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B394);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B424);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800101E8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800101F8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010210);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010260);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010278);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010288);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800102A0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800102B0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800102C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800102D0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800102E8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010300);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010328);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010338);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010348);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010360);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010378);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010388);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800103A0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800103B8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800103D0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800103E0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800103F8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010408);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010420);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010438);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010450);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010460);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010470);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010480);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B46C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B8C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001B910);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001BBBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001BE20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001BE9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C2AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C2D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C2E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C36C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C38C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C580);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C5DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C664);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C6A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C6C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C6CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C6F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C718);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C7D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C89C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C8D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C974);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001C9D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CA10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CA58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CAA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CAE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CB00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CB7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CC00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CC84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CCC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CD10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CD1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CD28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CD6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CD78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CD98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CDA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CDB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CDBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CDC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CDD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CDE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CDEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CE24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CE5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CE94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CEB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CED8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CF68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001CFF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D004);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D024);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D04C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D0E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D150);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D25C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D2C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D324);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D3A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D490);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D4C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D540);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D5A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D5C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D62C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D638);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D640);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D64C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D678);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D684);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D6B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D6C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D6E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D700);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D720);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D76C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D7B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D8A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001D9F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001DB04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001DBB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001DDD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001DDF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001DEB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001DEE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001DF58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001DFC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E03C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E07C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E15C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E1AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E23C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E248);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E288);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E2D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E2E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E2EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E2F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E330);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E344);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E360);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E40C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E508);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E57C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E6AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E758);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E7C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E804);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E840);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E848);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001E9A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001EAAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001EB60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001EBD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001EC98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001ED2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001EE58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001EEC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001EFE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F048);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F074);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F094);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F134);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F15C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F1A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F1BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F1CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F1D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F1E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F1F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F1FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F2C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F360);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F3DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F460);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F514);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F544);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F598);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F60C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F67C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F6E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F788);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F85C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F930);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F964);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F980);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F98C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001F9C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FA6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FA9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FAD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FB0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FB4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FB9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FBF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FC38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FC78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FCA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FCB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FCDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FD00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FD90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FE20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FE28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FEB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FEB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FF40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FF48);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FFD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8001FFDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020000);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020020);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020034);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020048);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002005C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020068);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020070);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020078);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020080);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020088);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020094);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800200A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800200AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800200B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800200C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800200D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800200F0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800104A8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800104F8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010508);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010538);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010588);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800201DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800202B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800202BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800202C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800202CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800202D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800202DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020304);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020368);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002042C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020510);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020518);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020520);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002052C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020538);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800205B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800205D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002068C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002072C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020734);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800207C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020884);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800208D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020948);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020984);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800209F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020A30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020B08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020B30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020B70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020B90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020B9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020BA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020BB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020BB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020BC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020BCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020BD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020BE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020C64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020D24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020D2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020D38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020D44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020D90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020DB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020E00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020E40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80020EF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002101C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021060);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800210A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021144);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021168);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800211F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021274);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021294);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021300);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021348);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002141C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021478);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800215E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800216A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021764);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800218B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002190C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021ACC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021B54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021B5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021C04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021F48);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021FE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80021FEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022094);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022438);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800224A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022518);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002256C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800225C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022670);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800226A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800226F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022730);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800227E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022810);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022868);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800228A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800228C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800228E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022900);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022920);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022974);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800229B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800229D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022A04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022A10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022A1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022A70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022A7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022A88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022AB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022B24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022C34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022CF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022D64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022E28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022F64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022F70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022F98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80022FB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800230E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800232A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023450);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002385C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023988);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800239AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800239B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800239C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800239E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800239F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800239F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023A00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023A24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023A44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023A68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023A88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023AAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023ACC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023AEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023B94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023C40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023CB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80023F50);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800105B4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800105DC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800105F4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001060C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010624);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010654);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010684);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010694);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800106A4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800106BC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800106EC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010714);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010734);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001075C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010774);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001079C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800240C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800244A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024524);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002456C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024594);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024634);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024640);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002464C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002466C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800246C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800246EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024770);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024858);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024864);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024870);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800248BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024940);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024974);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024A80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024AF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024BB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024BF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024CA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024D40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024E44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024EE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024FA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024FE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80024FEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025050);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002510C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025268);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800107C8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800107F0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010800);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800252F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002537C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025444);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025714);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025808);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025830);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025854);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025874);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025880);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025960);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800259F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025A04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025A5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025A64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025A84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025B0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025B2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025B38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025B44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025BE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025C50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025C5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025C68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025C74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025C80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025C88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025CA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025CAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025CB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025CC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025CD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80025CE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80026014);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800260A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80026138);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80026190);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800261B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800261D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800261DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80026214);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80026274);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800262E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800263C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80026420);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80026558);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002673C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80026920);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800269B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027408);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002758C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027754);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800278D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800278EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027910);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027930);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027948);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002798C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800279A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800279C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010840);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010858);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80010888);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800108A0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800108C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800110C4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800110F4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011124);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027A60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027D90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027D9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027DA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027DB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027DFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027E30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027FB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80027FEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028004);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028064);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800280A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800280F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028158);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028184);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002818C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028194);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800281A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800281CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800281EC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001116C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800111A4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800111BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800281F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028230);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028258);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028278);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800282AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028330);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028374);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001126C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800283AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028428);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028448);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028454);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800284AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800284D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800285CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002860C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028710);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800287C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800288D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028A24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028AE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028B90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028C08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028C80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028D10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028DC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028F10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028F58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028FA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028FC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028FCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80028FD8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800112F4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011304);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002900C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002970C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002972C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029758);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029850);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002991C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029A14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029BBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029BF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029C00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029C0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029C18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029C34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029C54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029D74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029EB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029EC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029EC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029F30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80029FC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A004);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A020);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A064);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A09C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A0D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A110);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A118);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A168);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A1BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A210);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A274);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A2D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A33C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A37C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A3C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A400);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A444);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A484);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A4C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A55C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A5F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A65C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A698);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A728);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A7B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A864);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A910);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002A9BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AA8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AB5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AC2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AC60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AD0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AD38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ADA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AE14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AE50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AE8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AEE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AF34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AF3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AF5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AF7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AF88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AF94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AFB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AFC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AFCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AFD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AFE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002AFEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B108);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B174);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B27C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B36C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B47C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B518);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B5B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B67C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B6FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B7A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B854);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B904);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002B9B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002BA94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002BB34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002BBD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002BC08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002BCD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002BD34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002BDFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C084);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C0E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C120);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C15C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C17C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C188);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C2B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C498);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C514);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C5EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C6C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C6D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C7DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C8A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C8CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C90C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011384);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011394);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001147C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800114CC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001151C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001162C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001167C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C918);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C93C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C974);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C9B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002C9D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002CA64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002CB44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002CC60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002CDC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002D020);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002D1E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002D24C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002D780);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002D8AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002D94C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DA94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DB50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DC34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DD34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DE7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DED8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DEF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DF18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DF38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002DF9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E000);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E020);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E054);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E088);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E0A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E2AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E4B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E4C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E4CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E4D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E4DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E4E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E564);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E5B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E5D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E5F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E600);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E69C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E714);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E7A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E814);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E898);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E908);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E914);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E920);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E92C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002E9D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EA0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EA18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EA50);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800117A4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800117BC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800117D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EA70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EAAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EAB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EABC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EAC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EACC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EAD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EADC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EAE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EAF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EB68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EBF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EC00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EC18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EC30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EC38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EC40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EC90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ECE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ECE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ECF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ED18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ED44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ED6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ED90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002ED98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EDB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EDD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EE10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EE40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EE7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EE9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EEC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EEFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EF64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EF70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002EF88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F004);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F028);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F180);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F1BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F21C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F2A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F32C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F338);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F464);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F4C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F4CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F4D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F520);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F540);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F548);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F550);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F558);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F580);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F58C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F5A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F5B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F5D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F614);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F7D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F818);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F824);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F874);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F8D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F8D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F8E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F8F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F90C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F960);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002F998);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FA20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FA50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FAF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FB8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FC40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FCF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FD5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FD98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FDA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FE3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FE54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8002FEC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030084);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800300C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800301BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030358);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030384);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800303FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030404);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003040C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003041C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800304B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030520);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030528);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030534);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030608);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030694);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800306C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030714);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003074C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800307D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030804);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800308B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030940);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800309F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030AA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030B10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030B4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030B58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030BF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030BFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030C70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030E9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80030EE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80031030);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800311CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800311F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80031278);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80031280);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800313BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800313E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003148C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800318A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80031CE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003212C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032174);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800321D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032264);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800322C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032334);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800323C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800323DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032504);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032920);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003292C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032A10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032A9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032B14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032B2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032BD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032C80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032CBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032CD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032D54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032D5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032EB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032ED4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80032F80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033404);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800338A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033D34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033D7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033DAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033DDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033E40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033ECC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033F30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80033F9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034028);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034044);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034184);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034608);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034614);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034710);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003479C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034854);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003488C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800348E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034924);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003494C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800349F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034AA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034AF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034B0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034B84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034BA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034BB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034BC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034BD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034EBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034F24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034F40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80034F54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800351A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003525C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800352D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800352DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800352E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800352F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035304);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035384);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003546C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003556C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035678);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800356F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003572C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800357E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003585C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800358D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800358E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035910);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035940);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003598C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035A28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035AB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035AE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035AEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035AF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035B28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035B5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035B64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035B98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035BF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035BF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035C28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035C30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035CA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035CD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035CF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035D4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035DE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035E4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035EB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035F18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80035F80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036000);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036090);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036110);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800361C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003635C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036364);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800118DC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800118FC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001199C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011A44);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011AAC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011B14);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011B5C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011B8C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011BF4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011C44);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011CAC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011D04);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011D6C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011DBC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011E24);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011E74);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011E8C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011EF4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011F44);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011F5C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011F74);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80011FE4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001201C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012034);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012074);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001208C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800120B4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800120F4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012104);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001211C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012154);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800121AC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012224);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012294);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036554);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036674);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800366F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036780);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036850);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036D8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036EB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036EC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036F14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036F54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80036FC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800370D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003714C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037258);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037264);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003728C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800372C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800372D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800372E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037380);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003738C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037398);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800373F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037440);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800374F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037524);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037554);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037584);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800375B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800375E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037688);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800376D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037834);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001231C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001232C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800378A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037934);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800379D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037A20);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012364);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001237C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800123EC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012404);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80037AAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800382A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003831C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800384C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038508);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003852C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800385E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800385F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038654);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800386B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038764);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800387D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038834);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038898);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800388FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038938);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038978);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800389B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800389C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800389C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800389D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800389D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038B0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038C20);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012484);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001252C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001257C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012594);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001260C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001262C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038C64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038D14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038D34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038E2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038E34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038E98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038EF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038EFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80038FB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003906C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003912C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800391DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800391EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800392C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800392D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800392F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039388);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039444);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003944C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003950C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039610);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039710);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039824);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039928);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039960);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800399A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800399B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800399C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800399CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800399D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039A14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039A88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039BEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039C88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039D38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039D94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039DD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039E80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80039F80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A010);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A150);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A214);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A318);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A350);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A394);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A3B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A3D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A3F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A454);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A490);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A4C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A4F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A538);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A574);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A624);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A654);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A674);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A6B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A6F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A6FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A704);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A738);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A744);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A74C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A754);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A7A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A7D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003A7FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003ABEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003AD78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B168);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B2F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B310);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B334);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B35C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B3C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B3EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B450);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B598);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B68C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B780);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B834);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B8AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B960);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003B9D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BA78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BAD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BB78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BBD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BC10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BC50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BC84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BCB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BCE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BD08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BDB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BE68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BE84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BEA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BEB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BEBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BEC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BEF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003BF30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C01C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C0D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C1E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C270);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C2E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C320);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C3E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C434);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C4CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C4EC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012674);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800126DC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800126F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C510);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C524);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C584);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C5A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C5EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C764);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003C908);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CA10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CAD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CB50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CC78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CE00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CE44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CE88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CE94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CEA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CEA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CEB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CEEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003CF24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003D00C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003D358);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003D37C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003D384);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003D3A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003D68C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003D9F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003D9FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003DB1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003DC54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003DEA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003E124);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003E170);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003E198);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003E5F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003E658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003EBC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003EBCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003EBD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003ECE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003ECFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003ED10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003ED90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003F1C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003F3DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003F594);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003F73C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003F7E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003F850);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003F8CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FA50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FAEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FB88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FC08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FC48);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FC84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FD30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FD70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FD9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FDDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FDE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FDF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FE34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FE64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FEA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FEB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FEB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8003FEF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004007C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800400D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800401AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800401F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004025C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80040294);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800402A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800402E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800404C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800406A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800406AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800406B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800406C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800406D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800406DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800406E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800406F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80040700);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004070C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80040718);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80040C10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800410F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800419A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800419D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800419F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041B44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041B54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041BF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041C18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041C50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041C88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041CB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041CCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041CD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041D84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041E28);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012724);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001276C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001277C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012794);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800127AC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800127D4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800127E4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800127FC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012814);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012864);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001287C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001289C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800128CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80041E54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042140);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800423A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042430);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800424B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004252C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800425A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042818);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042820);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042828);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042830);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042838);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004296C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042974);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004297C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042A74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042A7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042D3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042E08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042E10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042E18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042E20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80042EF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043060);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800433CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043460);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043540);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800435AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800435E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043680);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800436C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043700);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043740);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004377C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800437A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800437CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043808);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004387C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043A94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043D38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043D94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043DC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043DE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80043DF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044590);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004463C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004467C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044684);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044690);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800446A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044730);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044738);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044740);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044764);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800447D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044814);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044834);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044890);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044990);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044A3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044BE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044C7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044CE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80044F18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800450E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045120);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800451A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045264);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004561C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800456F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004580C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004581C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045850);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800459D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045B38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045C88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045CAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045D18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045D24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045DC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045E6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045EB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80045F84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004600C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80046078);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800460E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004616C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800461F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004637C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800464E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80046658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800467CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80046844);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800468D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800468D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80046948);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001295C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012974);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001298C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001299C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800129AC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800129C4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800129FC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012A18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80046998);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80048C30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80048D2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80048D54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80048D5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80048D64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004921C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049250);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049398);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800493A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800493BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800493C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800493E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049420);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049488);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049594);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800495D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049618);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004962C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049680);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049748);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800497A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800497D4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012BC8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012BF8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012C28);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012C58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800497FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049858);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049860);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049868);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004991C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800499D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049A7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049A94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049AB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049B2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049B34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049B3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049B44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049B4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049CE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049D2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049E98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049F00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049F28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049FA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049FA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049FB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80049FB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A16C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A2F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A35C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A384);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A404);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A40C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A41C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A424);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A5C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A610);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A640);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A670);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A7F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A874);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A89C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A954);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A98C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004A9E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AA24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AA44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AAF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AB98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004ABEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AC04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AE24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AE8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AEA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AEBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AF3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AF44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AF4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004AF54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B124);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B2C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B348);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B370);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B3F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B3F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B400);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B408);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B690);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B83C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B8C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B8F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B8F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B970);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004B998);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BA18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BA20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BA28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BA30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BBCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BC14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BD84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BE10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BE38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BEB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BEC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BEC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004BED0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C08C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C0D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C254);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C2E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C30C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C314);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C35C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C3D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C3FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C474);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C47C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C484);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C48C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C660);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C688);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C6EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C738);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C8D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C960);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004C988);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CA00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CA08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CA10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CA18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CC7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CE14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CEA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CECC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CEF8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012CF8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012D70);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012DE8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012E60);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012ED8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012F50);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80012FC0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013038);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800130B0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013120);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013198);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CF20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CF7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CF84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004CF8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D040);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D0F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D1A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D1AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D1CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D244);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D24C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D254);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D25C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D264);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D464);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D4AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D678);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D6E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D708);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D780);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D788);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D790);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D798);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004D9AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DB8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DBF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DC1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DC8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DC94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DC9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DCA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DCAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DEDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DF24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DF54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004DF84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E17C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E200);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E228);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E298);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E2A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E2A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E2B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E4FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E700);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E784);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E7AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E81C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E824);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E82C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004E834);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EB28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004ED40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EDCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EDF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EDFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EE74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EE9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EF1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EF24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EF2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004EF34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F144);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F18C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F368);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F3F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F41C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F49C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F4A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F4AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F4B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F6F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F738);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F924);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F9B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F9DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004F9E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FA2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FAA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FACC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FB4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FB54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FB5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FB64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FDC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FDF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FE54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8004FEA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800500B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050144);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005016C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800501EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800501F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800501FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050204);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800504E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800506F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050784);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013280);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800132F8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013370);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800133E8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013460);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800134D8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013548);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800135C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013638);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800136A8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013720);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800507AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800507D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050838);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050844);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050874);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050E38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050E58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80050EA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800514C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800514C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051514);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051564);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800515A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800515F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800518A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051930);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051A2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051A7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051AA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051B70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051C3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051CB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051D80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051E50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051E90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051ECC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051ED8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051F0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80051FB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80052044);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800520BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80052100);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005226C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800523DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800525EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80052640);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80052778);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005287C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005294C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80052B60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80052C8C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800137C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800137D8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800137F0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013808);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80052E40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80052FB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800530B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053250);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800532EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053360);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005340C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800534F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053568);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800535E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800536F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053794);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800537A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800537C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800537DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053830);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053848);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053868);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053874);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053880);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005388C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800538B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800538C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800538CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053928);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053964);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800539C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800539C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800539D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053AE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053B68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053BB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053BC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053BCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053C6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053CD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053D00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053DDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053F28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053F48);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80053FB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005402C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054048);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054054);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054074);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054080);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005408C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054094);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005409C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800540A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054258);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800543A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800544AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005457C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054584);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800545E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005464C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054690);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800546C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054708);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800548F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054920);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054950);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054980);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800549B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800549C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800549D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800549E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800549EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800549F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800549FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054A04);

EXTERN_C void func_80053964(void *self);

EXTERN_C void func_80054A2C(void *self)
{
    func_80053964(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054A4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054AF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054B98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054C34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054CA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054CE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054D18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054D48);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054D78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054DA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054DD8);

#include "game/b/field.h"

EXTERN_C int func_80054E0C(void *self)
{
    return FIELD_AT(self, unsigned short, 0x44) != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054E18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054E54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054E90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054EB4);

EXTERN_C void * func_80054F28(void *self)
{
    return (char *)self + 0x40;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054F30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054F5C);

EXTERN_C void func_800550FC(void *self, int b);

EXTERN_C void func_80054FC0(void *self)
{
    func_800550FC(self, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80054FE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80055020);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800550BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800550FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80055330);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800553D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005549C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005556C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80055624);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800557A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800557C8);

EXTERN_C void *D_800B4D84;

EXTERN_C int func_80055838(int value)
{
    int old = FIELD_AT(D_800B4D84, int, 0x44E8);
    FIELD_AT(D_800B4D84, int, 0x44E8) = value;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005584C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800558DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005591C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80055A9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80055D78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80055F0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80055F98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800560E4);

EXTERN_C int D_800B4D98;

EXTERN_C int func_8005618C(void)
{
    return D_800B4D98 == 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056198);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056364);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005652C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800566E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056874);

EXTERN_C void func_80056B3C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056B44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056BA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056C18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056D60);

EXTERN_C int func_80056D9C(void)
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056DA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056DCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056E0C);

EXTERN_C void func_8005717C(void *self);

EXTERN_C void func_80056F9C(void *self)
{
    FIELD_AT(self, int, 0xA0) = 0;
    func_8005717C(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056FBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80056FE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80057010);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80057150);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005717C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80057214);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80057368);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80057558);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800576A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800576F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005783C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80057878);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80057C7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80057F20);

EXTERN_C void func_80059B5C(void *p);

EXTERN_C void func_80057FEC(void *self)
{
    func_80059B5C((char *)self + 0x5C);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005800C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800580B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005816C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800581E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058270);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058404);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058488);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005854C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800585F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058654);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058728);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058830);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800588C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800588EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058910);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058A04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058A80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058B98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058C5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058D98);

EXTERN_C void func_80058EE8(void *self, int lo, int hi)
{
    if (lo >= hi) {
        FIELD_AT(self, int, 0x38) = lo;
        FIELD_AT(self, int, 0x3C) = hi;
        FIELD_AT(self, int, 0x40) = hi;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058F08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80058F68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059300);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800593A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800594A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059584);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800595F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800596A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059790);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059800);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059888);

EXTERN_C int func_8005992C(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C void func_8001A610(void *self);

EXTERN_C void func_80059938(void *self)
{
    func_8001A610(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059958);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059A84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059B5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059C54);

EXTERN_C void func_80059D8C(void *self, int b)
{
    FIELD_AT(self, int, 0x38) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059D94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059E90);

EXTERN_C void func_80059EF8(void *self, int b)
{
    FIELD_AT(self, int, 0x60) = b;
}

EXTERN_C int func_80059F00(void *self)
{
    return FIELD_AT(self, int, 0x60);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80059F0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005A020);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005A120);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005A31C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005A518);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005A62C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005A784);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005A934);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005ABE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005AF70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005AFF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B0F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B2F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B378);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B424);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B450);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B4D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B560);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B5B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B66C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005B7A8);

EXTERN_C void func_8005BC7C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005BC84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005BDA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005BF04);

EXTERN_C void func_8005BF48(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005BF50);

EXTERN_C void func_8005C1E8(void *self);

EXTERN_C void func_8005BFA4(void *self)
{
    func_8005C1E8(self);
}

EXTERN_C void func_8005C088(void *self, int b, int c);

EXTERN_C void func_8005BFC4(void *self, int b)
{
    func_8005C088(self, b, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005BFE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C088);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C1E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C238);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C26C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C2B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C344);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C380);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C3C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C570);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C608);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C6E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C77C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C7EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C8B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C910);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005C968);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005CA4C);

EXTERN_C void func_8005F120(void *self);

EXTERN_C void func_8005CB68(void *self)
{
    func_8005F120(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005CB88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005CCB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005CD5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005CE1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005CEB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005CF78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D080);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D228);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D264);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D2D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D334);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D384);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D3B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D624);

EXTERN_C void func_8005D228(void *self);

EXTERN_C void func_8005D734(void *self)
{
    func_8005D228(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D754);

EXTERN_C void func_8005F120(void *self);

EXTERN_C void func_8005D8A4(void *self)
{
    func_8005F120(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D8C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005D9D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005DB68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005DC44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005DD4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005DEA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005DF10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005DF54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005DF98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005DFE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005E0E0);

EXTERN_C void func_8005E244(void)
{
}

EXTERN_C void func_8005F120(void *self);

EXTERN_C void func_8005E24C(void *self)
{
    func_8005F120(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005E26C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005E404);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005E4CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005E924);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005EA9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005EAFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005EB30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005EDF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005EF58);

EXTERN_C void func_8005F120(void *self);

EXTERN_C void func_8005F090(void *self)
{
    func_8005F120(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F0B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F0E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F120);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F148);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F1B4);

EXTERN_C void func_8005F1D8(void *self)
{
    FIELD_AT(self, int, 0xC) = 1;
}

EXTERN_C void func_8005F1E4(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F1EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F214);

EXTERN_C void *func_8005F238(void *self)
{
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x0) = 0;
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F248);

EXTERN_C int func_8005F28C(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F298);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F3E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F440);

EXTERN_C int D_800B4DC4;

EXTERN_C int func_8005F470(void)
{
    return D_800B4DC4 != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F47C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F50C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F5F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F698);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F704);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F730);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F834);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F87C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005F8EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005FB04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8005FC78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800600A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060118);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060154);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060188);

EXTERN_C void *func_800601C8(void *self)
{
    FIELD_AT(self, char, 0x1) = 0;
    FIELD_AT(self, char, 0x0) = 0;
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800601D8);

EXTERN_C void *func_80060200(void *self, void *src)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(src, char, 0x0);
    FIELD_AT(self, char, 0x1) = FIELD_AT(src, char, 0x1);
    return self;
}

EXTERN_C void func_80060218(void *self, void *src)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(src, char, 0x0);
    FIELD_AT(self, char, 0x1) = FIELD_AT(src, char, 0x1);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060230);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013940);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013A38);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013A88);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013AA8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013B00);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013B20);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013B48);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013B70);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013BA0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013BB8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013BD0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013C00);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013C50);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013C70);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013CB0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013D00);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013E10);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013E30);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013F40);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013F90);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80013FB0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800140C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014110);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014130);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014180);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014278);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800142B8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014308);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014400);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014450);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014548);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800145B0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014658);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014750);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800147A0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014808);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014858);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014950);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800149B8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014A08);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014B00);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014B68);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014BD0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014C38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060260);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060378);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060588);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800609D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060D6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060D9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80060DF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061030);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061058);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800610E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061114);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061138);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061164);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061188);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800611D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800614BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800615B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061758);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800619F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061A20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061AAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061BF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061CC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061E9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80061F80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800620D8);

EXTERN_C void * func_80062118(void *self)
{
    return (char *)self + 0x1A4;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062120);

EXTERN_C void * func_80062158(void *self)
{
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062160);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062188);

EXTERN_C void *func_800621F8(void *self)
{
    void *r = 0;
    if (FIELD_AT(self, signed char, 0xA0) != 0) {
        r = (char *)self + 0xA0;
    }
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062214);

EXTERN_C int func_80062238(void *self, unsigned int bit)
{
    return ((((signed char *)self + 0x1F9)[bit >> 3] >> (bit & 7)) ^ 1) & 1;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062258);

EXTERN_C int func_80062280(void *self, int b)
{
    int old = FIELD_AT(self, int, 0x4);
    FIELD_AT(self, int, 0x4) = b;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006228C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006237C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800624A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006255C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800625C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062610);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062764);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800627E8);

EXTERN_C void * func_80062834(void *self)
{
    return self;
}

EXTERN_C int D_800B4E34;

EXTERN_C int func_8006283C(void)
{
    return D_800B4E34;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062848);

EXTERN_C int func_80062978(void *self)
{
    int old = FIELD_AT(self, int, 0x6C) != 0;
    FIELD_AT(self, int, 0x6C) = 0;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062988);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062A90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062C3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062D60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062E70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062E9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80062FA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800630BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800631D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006323C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063270);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063340);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063584);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800635FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063714);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063744);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800637A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800638A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800639F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063B14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063BE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063CA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063D64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063E18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063F3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80063FFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800640D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064188);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064290);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800643DC);

EXTERN_C void func_80064420(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064428);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064478);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064570);

EXTERN_C void func_800646D4(void)
{
}

EXTERN_C void func_8005F120(void *self);

EXTERN_C void func_800646DC(void *self)
{
    func_8005F120(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800646FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064884);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800648E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064B3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064C78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80064E0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065458);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065870);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800658E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065A00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065AA0);

EXTERN_C void func_80065AC8(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065AD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065B5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065C64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065D20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065E10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80065EE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066054);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066128);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800661F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066220);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066260);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066294);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800662D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066308);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066330);

EXTERN_C void * func_80066358(void *self)
{
    return (char *)self + 0xB8;
}

struct Word_80066360 {
    char b[4];
};

EXTERN_C void func_80066360(void *self, Word_80066360 *src)
{
    FIELD_AT(self, Word_80066360, 0xB8) = *src;
    FIELD_AT(self, int, 0xBC) = 1;
}

EXTERN_C void * func_80066380(void *self)
{
    return (char *)self + 0x68;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066388);

EXTERN_C void * func_800663D4(void *self)
{
    return (char *)self + 0x48;
}

EXTERN_C void * func_800663DC(void *self)
{
    return (char *)self + 0x98;
}

EXTERN_C void * func_800663E4(void *self)
{
    return (char *)self + 0x78;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800663EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800664F8);

EXTERN_C int func_800665BC(void *self)
{
    return FIELD_AT(self, int, 0x28);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800665C8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014CAC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014CFC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014D1C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014D5C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014DAC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014DCC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014E0C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014E5C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014E7C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014EAC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014EEC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80014FFC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001504C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001506C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800150BC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800151B4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001521C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001526C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015364);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015384);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800153C4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800153FC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066690);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066798);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800667C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006692C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066A54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066AF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066BC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066C7C);

EXTERN_C void func_80066D14(void *self)
{
    FIELD_AT(self, int, 0x60) = 1;
}

EXTERN_C int func_80066D20(void *self)
{
    return FIELD_AT(self, int, 0x48);
}

EXTERN_C char D_800154B4[];

EXTERN_C void *func_80066D2C(void *self, int b)
{
    FIELD_AT(self, void *, 0x0) = D_800154B4;
    FIELD_AT(self, int, 0x4) = b;
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066D44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066D78);

EXTERN_C void func_80066D9C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066DA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066DDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066E04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066E7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066F8C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800154B4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800154D4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800154EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80066FB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006707C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800670A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80067134);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80067450);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800674C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006753C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80067ABC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015570);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015580);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015594);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800155AC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800155BC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800155CC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800155D8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800155E4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800155F0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800155FC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015608);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015614);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015620);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001562C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015640);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015654);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015668);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015678);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80067B1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800680A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006821C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800682A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068310);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068380);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800156B0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015700);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015720);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015750);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015790);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800157E0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015800);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015830);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068660);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068770);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006897C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800689E0);

EXTERN_C int func_80068A50(void *self)
{
    return FIELD_AT(self, int, 0x1D04);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068A5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068B14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068E60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068EE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80068F3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800690C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800691EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80069264);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800694BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800697A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80069914);

EXTERN_C void func_80054FE0(void *self);

EXTERN_C void func_80069958(void *self)
{
    func_80054FE0(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80069978);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80069B2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80069D1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80069E60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80069ECC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80069F74);

EXTERN_C int func_8006A040(void *self)
{
    return FIELD_AT(self, int, 0x1C);
}

struct Word_8006A04C {
    char b[4];
};

// A field copy returned by value; the FIELD cast form calls memcpy instead.
struct Obj_8006A04C {
    char pad[0x20];
    Word_8006A04C w;
};

EXTERN_C Word_8006A04C func_8006A04C(Obj_8006A04C *self)
{
    return self->w;
}

EXTERN_C int func_8006A06C(void *self)
{
    return FIELD_AT(self, int, 0x14);
}

EXTERN_C int func_8006A078(void *self)
{
    return FIELD_AT(self, int, 0x18);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A084);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A194);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A1BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A3C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A440);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A4E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A588);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A608);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A6D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A784);

EXTERN_C void func_8006A80C(void *self)
{
    FIELD_AT(self, int, 0x48) = 1;
}

EXTERN_C void func_8006A818(void *self)
{
    FIELD_AT(self, int, 0x48) = 0;
}

EXTERN_C int func_8006A820(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006A82C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006AB18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006AD40);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015914);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015964);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015984);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800159C4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015A14);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015B34);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015B84);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015B9C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015BB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006AE68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006AF94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B024);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B058);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B08C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B0C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B120);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B180);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B1C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B210);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B258);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B2B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B2F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B350);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B390);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B3D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B540);

INCLUDE_ASM("asm/main/nonmatchings/game", SsGetMute);

EXTERN_C int func_8006B5CC(void)
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B5D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B618);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B690);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B740);

EXTERN_C void func_8006B7B8(void *self)
{
    if (FIELD_AT(self, int, 0x274) != 0) {
        FIELD_AT(self, int, 0x270) = 0;
        FIELD_AT(self, int, 0x274) = 0;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B7D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B814);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B850);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B884);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B8E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B928);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006B988);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BA1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BA64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BB04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BC98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BCF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BD34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BDE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BE4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BEA0);

EXTERN_C int func_8006BECC(void)
{
    return 1;
}

EXTERN_C int func_8006BED4(void)
{
    return 1;
}

EXTERN_C int func_8006BEDC(void *self)
{
    return FIELD_AT(self, int, 0x22C);
}

EXTERN_C void func_8006BEE8(void *self)
{
    FIELD_AT(self, int, 0x22C) = 0;
}

EXTERN_C void func_8006BEF0(void *self)
{
    FIELD_AT(self, int, 0x22C) = 1;
}

EXTERN_C void func_8006BEFC(void *self)
{
    FIELD_AT(self, int, 0x94) = 1;
}

EXTERN_C void func_8006BF08(void *self)
{
    FIELD_AT(self, int, 0x2C0) = 0;
    FIELD_AT(self, int, 0x2BC) = 0;
    FIELD_AT(self, int, 0x2B8) = 0;
}

EXTERN_C void * func_8006BF18(void *self)
{
    return (char *)self + 0x2B8;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BF20);

EXTERN_C void func_8006BF44(void *self)
{
    FIELD_AT(self, int, 0x268) = 0;
}

EXTERN_C void func_8006BF4C(void *self)
{
    FIELD_AT(self, int, 0x268) = 1;
}

EXTERN_C int func_8006BF58(void *self)
{
    return FIELD_AT(self, int, 0x278);
}

EXTERN_C void func_8006BF64(void *self, int b)
{
    FIELD_AT(self, int, 0x278) = b;
    FIELD_AT(self, int, 0x26C) = 0;
}

EXTERN_C void func_8006BF70(void *self, int b)
{
    FIELD_AT(self, int, 0x254) = b;
}

EXTERN_C int func_8006BF78(void *self)
{
    return FIELD_AT(self, int, 0x254);
}

EXTERN_C void * func_8006BF84(void *self)
{
    return (char *)self + 0x7C;
}

EXTERN_C void * func_8006BF8C(void *self)
{
    return (char *)self + 0x84;
}

EXTERN_C int D_800B4ED8;

EXTERN_C int func_8006BF94(void)
{
    return D_800B4ED8;
}

EXTERN_C void * func_8006BFA0(void *self)
{
    return (char *)self + 0x2A0;
}

EXTERN_C int func_8006BFA8(void *self)
{
    return FIELD_AT(self, int, 0x260);
}

EXTERN_C void func_8006BFB4(void *self, int b)
{
    FIELD_AT(self, int, 0x28C) = FIELD_AT(b, int, 0x0);
}

EXTERN_C int func_8006BFC0(void *self)
{
    return FIELD_AT(self, int, 0x28C);
}

EXTERN_C int D_800B4ED4;

EXTERN_C void func_8006BFCC(void *self)
{
    FIELD_AT(self, int, 0x28C) = D_800B4ED4;
}

EXTERN_C int D_800B4ED0;

EXTERN_C int func_8006BFD8(void)
{
    return D_800B4ED0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006BFE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C204);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C29C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C310);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C36C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C3C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C4EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C61C);

EXTERN_C int func_8006C650(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C65C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C77C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C8D8);

EXTERN_C void func_8002EEFC(void *self);

EXTERN_C void func_8006C93C(void *self)
{
    func_8002EEFC(self);
}

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015C0C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015C5C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015C9C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015DBC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015E5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C95C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006C9F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006CA80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006CAF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006CBCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006CD98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006CF84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006D290);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006D344);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006D768);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006D8EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006D964);

EXTERN_C void func_8006DA60(void *self)
{
    FIELD_AT(self, int, 0x60) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006DA6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006DF68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006E234);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006E73C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006E8BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006E8E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006EACC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006EBB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006EC70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006EDD8);

EXTERN_C void func_8006EE8C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006EE94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006EF84);

EXTERN_C int func_8006F040(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F04C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F0B0);

EXTERN_C void func_8006F0E4(void *self, int b)
{
    FIELD_AT(self, int, 0x0) = b;
}

EXTERN_C void func_8006F0EC(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
}

EXTERN_C void func_8006F0F4(void *self, int b, int c, int d, int e)
{
    FIELD_AT(self, int, 0x94) = b;
    FIELD_AT(self, int, 0x98) = c;
    FIELD_AT(self, int, 0x9C) = d;
    FIELD_AT(self, int, 0xA0) = e;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F10C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F154);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F194);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F268);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F2A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F2E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F31C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F35C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015EA0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015EB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F3DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F52C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F570);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F5B4);

// Larger than -G8, so it is reached with lui/%lo like retail, not $gp.
struct GameMode_800AF410 {
    int state;
    int pad[2];
};

EXTERN_C GameMode_800AF410 D_800AF410;

EXTERN_C int func_8006F630(void)
{
    switch (D_800AF410.state) {
    case 0:
    case 5:
        D_800AF410.state = 0;
        return 1;
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F67C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006F8B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FA84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FAC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FCC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FDD8);

EXTERN_C void func_8006FE08(void *self, int b, int c, int d)
{
    FIELD_AT(self, int, 0x20) = c;
    FIELD_AT(self, int, 0x24) = d;
}

EXTERN_C void func_8006FE14(void *self, int b, int c, int d, int e, int f)
{
    FIELD_AT(self, int, 0x20) = c;
    FIELD_AT(self, int, 0x24) = d;
    FIELD_AT(self, int, 0x28) = e;
    FIELD_AT(self, int, 0x2C) = f;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FE30);

EXTERN_C void func_8006FE58(void *self, int b)
{
    FIELD_AT(self, int, 0x0) = b;
}

EXTERN_C void func_8006FE60(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x0) = b;
    FIELD_AT(self, int, 0x8) = c;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FE6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FEA4);

EXTERN_C int func_8006FEDC(void)
{
    return D_800AF410.state;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FEEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FF50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8006FFDC);

EXTERN_C void func_80070030(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070038);

EXTERN_C int func_8007027C(void)
{
    return 0;
}

EXTERN_C int func_80070284(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0xC);
}

EXTERN_C int func_80070298(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0x10);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800702AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800702CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800702EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070384);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070440);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007049C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800704F8);

EXTERN_C int func_80070554(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0x30);
}

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80015FD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070568);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070DA0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070DF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070E34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070E60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070E98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070F30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80070FC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071080);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800710C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071148);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800711D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800711FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071224);

EXTERN_C int func_80071250(void)
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071258);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071280);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800712A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800712D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800712F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071320);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071348);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071370);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071398);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800713C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800713EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007143C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071464);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071490);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800714BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071510);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071538);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071560);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071588);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800715B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007164C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071820);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071880);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071904);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007192C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071A40);

EXTERN_C void func_80076EF8(void *self);

EXTERN_C void func_80071A74(void *self)
{
    func_80076EF8(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071A94);

EXTERN_C void func_800751AC(void *self);

EXTERN_C void func_80071AC4(void *self)
{
    func_800751AC(self);
}

EXTERN_C void func_8007505C(void *self);

EXTERN_C void func_80071AE4(void *self)
{
    func_8007505C(self);
}

EXTERN_C void func_80074F78(void *self);

EXTERN_C void func_80071B04(void *self)
{
    func_80074F78(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071B24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071BDC);

EXTERN_C void func_80074E44(void *self);

EXTERN_C void func_80071C24(void *self)
{
    func_80074E44(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071C44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071C78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071D90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071E90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071F08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80071F6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80072130);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800722EC);

EXTERN_C void func_80072508(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80072510);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80072534);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800725F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80072634);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800727DC);

EXTERN_C int func_800728C0(void)
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800728C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80072970);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800729E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80072B84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80072CFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80072E70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80073960);

EXTERN_C void func_80073980(void *self)
{
    FIELD_AT(self, short, 0x5C8) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007398C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80073C04);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016270);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016280);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016298);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800162B0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016300);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016310);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800163A8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800163C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800163E0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016410);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074468);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074564);

EXTERN_C void func_800745A8(void *self, int b)
{
    FIELD_AT(self, short, 0x5CE) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800745B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007460C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007464C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800746C4);

EXTERN_C void func_8007473C(void *self, int b)
{
    FIELD_AT(self, short, 0x5CA) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074744);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007479C);

EXTERN_C void func_800749A8(void)
{
}

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800164C8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016518);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016528);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800165C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800165E0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800165F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800749B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074AB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074C50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074C90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074E28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074E44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074E78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074EA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074EE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074F1C);

EXTERN_C int func_80074F40(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_80074F4C(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074F58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074F78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80074FAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075004);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007505C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800750B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075128);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800751AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075220);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800752B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075358);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800753F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075448);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800755AC);

EXTERN_C int func_800755C8(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

EXTERN_C int func_800755D4(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800755E0(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800755EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075620);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075674);

EXTERN_C void func_80075698(void *self)
{
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800756A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800756D4);

EXTERN_C int func_800756EC(void *self)
{
    return FIELD_AT(self, int, 0x0) == 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800166A8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800166B8);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_800166C8);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_800166F0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016708);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016740);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016758);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800167C8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800167E0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800167F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800756F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007570C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075744);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075788);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075828);

EXTERN_C void func_80075894(void *self, int b)
{
    FIELD_AT(self, int, 0x18) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007589C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800758F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075A40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075B4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075DD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075E50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075EC8);

EXTERN_C void func_80075EC8(void *self, int b);

EXTERN_C void func_80075FB4(void *self)
{
    func_80075EC8(self, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80075FD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076038);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076370);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007669C);

EXTERN_C void func_80076370(void *self);

EXTERN_C void func_800766D8(void *self)
{
    func_80076370(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800766F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076848);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007698C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076AEC);

EXTERN_C int func_80076BE8(void *self)
{
    return FIELD_AT(self, int, 0x144);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076BF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076C1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076CD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076D70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076DC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076DF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076E60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076EA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076EF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80076FD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800770B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800771D4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077210);

EXTERN_C void func_80075448(void *self);

EXTERN_C void func_80077234(void *self)
{
    func_80075448(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077254);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077334);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800773B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077444);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077478);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800774D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077538);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800775A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800775F0);

EXTERN_C void func_80077640(void *self)
{
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
}

EXTERN_C void func_800751AC(void *self);

EXTERN_C void func_8007764C(void *self)
{
    func_800751AC(self);
}

EXTERN_C void func_8007505C(void *self);

EXTERN_C void func_8007766C(void *self)
{
    func_8007505C(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007768C);

EXTERN_C int func_800776D8(void *self)
{
    int old = FIELD_AT(self, int, 0x10);
    FIELD_AT(self, int, 0x10) = 0;
    return old;
}

EXTERN_C int func_800776E4(void *self)
{
    return FIELD_AT(self, int, 0x10);
}

EXTERN_C int func_800776F0(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800776FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077750);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007778C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800777E8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016820);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016830);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016868);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016878);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077854);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077A44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077BF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077C2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077C40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077C68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80077EA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80078520);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80078564);

EXTERN_C int func_800785A0(void)
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800785A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800785DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80078610);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80078658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800786A0);

EXTERN_C void func_800786EC(void)
{
}

EXTERN_C void func_800786F4(void)
{
}

EXTERN_C void func_800786FC(void *self)
{
    FIELD_AT(self, int, 0x1C) = 5;
}

EXTERN_C void func_80078708(void *self)
{
    FIELD_AT(self, int, 0x1C) = 4;
}

EXTERN_C void func_80078714(void *self)
{
    FIELD_AT(self, int, 0x1C) = 3;
}

EXTERN_C void func_80078720(void *self)
{
    FIELD_AT(self, int, 0x1C) = 2;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007872C);

EXTERN_C void func_80078740(void *self)
{
    FIELD_AT(self, int, 0x1C) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007874C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007876C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80078784);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007879C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800787B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800787C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80078A30);

EXTERN_C int func_80078C38(void)
{
    return 0;
}

EXTERN_C void func_80078C40(void)
{
}

EXTERN_C void func_80078C48(void)
{
}

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016BC0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80016BD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80078C50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007908C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800790BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079104);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079168);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800792C8);

EXTERN_C void func_8007A1F4(void *self, int b);

EXTERN_C void func_800797FC(void *self)
{
    func_8007A1F4(self, 0);
}

EXTERN_C void func_8007981C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079824);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079868);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800798C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800798EC);

EXTERN_C void func_80079910(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079918);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079ABC);

EXTERN_C void func_8007A1F4(void *self, int b);

EXTERN_C void func_80079C18(void *self)
{
    func_8007A1F4(self, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079C38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079D64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079E8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079F48);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80079F6C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A13C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A198);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A1F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A3CC);

EXTERN_C void func_8007A400(void *self, int b)
{
    FIELD_AT(self, int, 0x364) = 2;
    FIELD_AT(self, int, 0x36C) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A410);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A434);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A960);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A994);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007A9DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007AA9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007AB78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007AC38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007AD14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007ADCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007AE34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007AF04);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_80017010);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_80017030);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_80017048);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_8001705C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017068);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017070);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_80017078);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_80017090);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_800170A8);

INCLUDE_RODATA("asm/main/nonmatchings/game", jtbl_800170C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800170F0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017140);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017160);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017178);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017190);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800171B0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800171C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800171D0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800171E0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017210);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017260);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017280);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017298);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800172B0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800172E8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800172F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007AF5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007AFD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B014);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B058);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B08C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B0C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B108);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B1FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B2B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B2E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B36C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B404);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B538);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B5F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007B738);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BB48);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BC3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BCF0);

EXTERN_C void func_8007BDAC(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BDB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BE44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BEA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BEE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BF18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BF48);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BF84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007BFA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C008);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C070);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C0A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C3C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C55C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C640);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C6A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C7B0);

EXTERN_C void func_8007DEE8(void *self, int b);

EXTERN_C void func_8007C9A4(void *self)
{
    func_8007DEE8(self, 3);
}

EXTERN_C void func_8007DEE8(void *self, int b);

EXTERN_C void func_8007C9C4(void *self)
{
    func_8007DEE8(self, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007C9E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007CA44);

EXTERN_C int func_8007CAA8(void *self, int b)
{
    int old = FIELD_AT(self, int, 0x11C);
    FIELD_AT(self, int, 0x11C) = b;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007CAB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007CB64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007CC14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007CC60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007CCB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007CCDC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007CE64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007D024);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007D24C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007D498);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007D6D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007D744);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007D824);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007D994);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007DB04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007DC00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007DDCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007DDFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007DE74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007DEE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007E214);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007E30C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007E414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007E47C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007E5B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007E658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007E684);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007E8C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007EAC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007EDAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007EF90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F0A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F138);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F434);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F4F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F538);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F55C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F580);

EXTERN_C int func_8007F5A4(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x240);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F5B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F62C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F6A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F6C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F738);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F7AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F820);

EXTERN_C void func_8007F894(void)
{
}

EXTERN_C void func_8007A1F4(void *self, int b);

EXTERN_C void func_8007F89C(void *self)
{
    func_8007A1F4(self, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F8BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F940);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007F9B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007FA58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007FB30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007FB78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007FC90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007FD60);

EXTERN_C void func_8007FE1C(void *self, int b)
{
    FIELD_AT(self, int, 0x548) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007FE24);

EXTERN_C void func_8007FE3C(void *self, int b)
{
    FIELD_AT(self, int, 0x564) = b;
    FIELD_AT(self, int, 0x560) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007FE4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8007FF58);

EXTERN_C void func_8007FE4C(void *self, int b, int c);

EXTERN_C void func_80080110(void *self, int b)
{
    func_8007FE4C(self, b, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080130);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080180);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800801D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008022C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800802E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080350);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800803E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080418);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080468);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800804D8);

EXTERN_C int func_80080528(void)
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080530);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080614);

EXTERN_C void func_800806EC(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800806F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080828);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800808AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080990);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080A2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080AE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080B60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080BC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080C40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080C64);

EXTERN_C void func_800DFB10(void *p);

EXTERN_C void func_80080C90(void *self)
{
    func_800DFB10((char *)self + 0x4B0);
}

EXTERN_C int func_80080CB0(void *self)
{
    return FIELD_AT(self, int, 0x568);
}

EXTERN_C int func_80080CBC(void *self, int b)
{
    return (b & 0x7) << 9;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080CC8);

EXTERN_C int func_80080CE4(void *self)
{
    return FIELD_AT(self, int, 0x328);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080CF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080D14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080D30);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080D4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080D74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080D94);

EXTERN_C int func_80080E28(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x150);
}

EXTERN_C int func_80080E3C(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x14C);
}

EXTERN_C void func_80080828(void *self);

EXTERN_C void func_80080E50(void *self)
{
    func_80080828(self);
}

EXTERN_C int func_80080E70(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C int func_80080E7C(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080E88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080EB4);

EXTERN_C void func_8001A610(void *self);

EXTERN_C void func_80080ED8(void *self)
{
    func_8001A610(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080EF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080F88);

EXTERN_C int func_80080FAC(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C int func_80080FB8(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080FC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80080FF0);

EXTERN_C void func_8001A610(void *self);

EXTERN_C void func_80081014(void *self)
{
    func_8001A610(self);
}

EXTERN_C void func_80081034(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x0) = b;
    FIELD_AT(self, int, 0x4) = c;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081040);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081050);

EXTERN_C int func_80081060(void *self, int b)
{
    return (b & 0x7) << 9;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008106C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081088);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800810B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081114);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081190);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081204);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081260);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800812E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081350);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800813BC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008140C);

EXTERN_C int func_80081434(void *self, int b)
{
    return (b & 0x7) << 9;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081440);

EXTERN_C int func_8008145C(void *self)
{
    return FIELD_AT(self, int, 0x384);
}

EXTERN_C int func_80081468(void *self)
{
    return FIELD_AT(self, int, 0x380);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081474);

EXTERN_C int func_800814C4(void *self)
{
    return FIELD_AT(self, int, 0x32C);
}

EXTERN_C int func_800814D0(void *self)
{
    return FIELD_AT(self, int, 0x370);
}

EXTERN_C int func_800814DC(void *self)
{
    return FIELD_AT(self, int, 0x378);
}

EXTERN_C void func_800814E8(void)
{
}

EXTERN_C int func_800814F0(void *self)
{
    return FIELD_AT(self, int, 0x150);
}

EXTERN_C int func_800814FC(void *self)
{
    return FIELD_AT(self, int, 0x14C);
}

EXTERN_C int func_80081508(void *self, int b)
{
    return (b & 0x7) << 9;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081514);

EXTERN_C int func_80081530(void *self)
{
    return FIELD_AT(self, int, 0x2C);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008153C);

EXTERN_C char D_800AFA58[];

EXTERN_C void * func_80081558(void)
{
    return D_800AFA58;
}

EXTERN_C int func_80081564(void *self)
{
    return FIELD_AT(self, int, 0x18);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081570);

EXTERN_C char D_800AFA64[];

EXTERN_C void * func_8008158C(void)
{
    return D_800AFA64;
}

EXTERN_C int func_80081598(void *self)
{
    return FIELD_AT(self, int, 0x14);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800815A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800815B4);

EXTERN_C int func_800815C8(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C int func_800815D4(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800815E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800815F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081620);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008168C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800816B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081748);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081780);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800817C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081820);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081970);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081A74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081BA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081CB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081DCC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081ED0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80081FF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082058);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800820B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082150);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082174);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008219C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800821C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800821EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082214);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082238);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082260);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800822A4);

EXTERN_C void func_800817C8(void *self);

EXTERN_C void func_800822B4(void *self)
{
    func_800817C8(self);
}

EXTERN_C int func_800822D4(void *self)
{
    return FIELD_AT(self, int, 0x10);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800822E0);

EXTERN_C int func_80082374(void *self)
{
    return FIELD_AT(self, int, 0x10);
}

EXTERN_C int func_80082380(void *self)
{
    return FIELD_AT(self, int, 0x1C);
}

EXTERN_C int func_8008238C(void *self)
{
    return FIELD_AT(self, int, 0x18);
}

EXTERN_C int func_80082398(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800823A4);

EXTERN_C void func_80074E44(void *self);

EXTERN_C void func_80082450(void *self)
{
    func_80074E44(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082470);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800824A0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017360);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017370);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017380);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017390);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800173A8);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800173C0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800173D0);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800173E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800824C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800825FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082670);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082690);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800826C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082714);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082768);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082798);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800827C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800827EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800828E4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017690);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017748);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017758);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008299C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082C68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082D44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082E14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082E60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082EB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80082F5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008316C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80083268);

EXTERN_C void func_80083310(void *self);

EXTERN_C void func_800832B0(void *self)
{
    FIELD_AT(self, char, 0x8E) = 0;
    func_80083310(self);
}

EXTERN_C void func_80083310(void *self);

EXTERN_C void func_800832D0(void *self)
{
    FIELD_AT(self, char, 0x99) = 0;
    func_80083310(self);
}

EXTERN_C void func_80083310(void *self);

EXTERN_C void func_800832F0(void *self)
{
    func_80083310(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80083310);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80083360);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800833AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800833F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80083EB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80083ED8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80083F40);

EXTERN_C int func_80084044(void *self, int b)
{
    return (b & 0x7) << 9;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084050);

EXTERN_C int func_8008406C(void *self)
{
    return FIELD_AT(self, signed char, 0xA) != 0;
}

EXTERN_C short func_80084078(void *self)
{
    return FIELD_AT(self, short, 0x8);
}

EXTERN_C short func_80084084(void *self)
{
    return FIELD_AT(self, short, 0xA);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084090);

EXTERN_C int func_800840A4(void *self)
{
    return FIELD_AT(self, int, 0x20);
}

EXTERN_C unsigned char func_800840B0(void *self)
{
    return FIELD_AT(self, unsigned char, 0x8);
}

EXTERN_C void func_800840BC(void *self, int b)
{
    FIELD_AT(self, short, 0xA) = b;
}

EXTERN_C int func_800840C4(void *self)
{
    return FIELD_AT(self, signed char, 0x9) != 0;
}

EXTERN_C void func_800840D0(void *self, int b)
{
    FIELD_AT(self, char, 0x9) = b;
}

EXTERN_C void func_8001A610(void *self);

EXTERN_C void func_800840D8(void *self)
{
    func_8001A610(self);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800840F8);

EXTERN_C int func_80084118(void *self)
{
    return FIELD_AT(self, int, 0x38);
}

EXTERN_C int func_80084124(void *self)
{
    return FIELD_AT(self, int, 0x34);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084130);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084454);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084674);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800846EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008478C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800847C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084824);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800849D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084AD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084B78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084BF8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084C50);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017910);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017914);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017964);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017974);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017994);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_800179AC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017A44);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017ADC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017B94);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017BA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084D58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80084F58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085168);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800852A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800852DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008533C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800853D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085454);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085478);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008549C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800854FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085554);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085578);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085614);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085670);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085710);

EXTERN_C void func_800857A0(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800857A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800857E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085820);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008586C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085A08);

EXTERN_C void func_80085A58(void *self)
{
    FIELD_AT(self, char, 0x4C4) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085A60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085A98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085AD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085B28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085B7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085BA4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085BD8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085C00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085C60);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085D7C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085DC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085E14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085E74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085F90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80085FD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086028);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086088);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800861A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800861E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008623C);

EXTERN_C int func_80086288(void *self)
{
    return FIELD_AT(self, int, 0x540);
}

EXTERN_C void func_80086294(void *self, int b)
{
    FIELD_AT(self, int, 0x540) = b;
}

EXTERN_C short func_8008629C(void *self)
{
    return FIELD_AT(self, short, 0x53E);
}

EXTERN_C void func_800862A8(void *self, int b)
{
    FIELD_AT(self, short, 0x53E) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800862B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800862E4);

EXTERN_C signed char func_80086300(void *self)
{
    return FIELD_AT(self, signed char, 0x4C5);
}

EXTERN_C void func_8008630C(void *self, int b)
{
    FIELD_AT(self, char, 0x4C5) = b;
}

EXTERN_C short func_80086314(void *self)
{
    return FIELD_AT(self, short, 0x4C8);
}

EXTERN_C short func_80086320(void *self)
{
    return FIELD_AT(self, short, 0x4CA);
}

EXTERN_C short func_8008632C(void *self)
{
    return FIELD_AT(self, short, 0x4C6);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086338);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086350);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086380);

EXTERN_C int func_800863AC(void *self)
{
    return FIELD_AT(self, signed char, 0x4C4) != 0;
}

EXTERN_C signed char func_800863B8(void *self)
{
    return FIELD_AT(self, signed char, 0x4BD);
}

EXTERN_C signed char func_800863C4(void *self)
{
    return FIELD_AT(self, signed char, 0x4BC);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800863D0);

EXTERN_C short func_80086400(void *self)
{
    return FIELD_AT(self, short, 0x4BE);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008640C);

EXTERN_C void func_80086454(void *self, int b)
{
    FIELD_AT(self, char, 0x4BC) = b;
}

EXTERN_C short func_8008645C(void *self)
{
    return FIELD_AT(self, short, 0x4E2);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086468);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008647C);

EXTERN_C int func_80086490(void *self)
{
    return FIELD_AT(self, int, 0x4D8);
}

EXTERN_C int func_8008649C(void *self)
{
    return FIELD_AT(self, int, 0x4D4);
}

EXTERN_C void func_800864A8(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x4D4) = b;
    FIELD_AT(self, int, 0x4D8) = c;
}

EXTERN_C int func_800864B4(void *self)
{
    return FIELD_AT(self, int, 0x4D0);
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800864C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086518);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008655C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086578);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086670);

EXTERN_C int func_800866F0(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x8) & b;
}

EXTERN_C int func_800866FC(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x6) & b;
}

EXTERN_C int func_80086708(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x4) & b;
}

EXTERN_C int func_80086714(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x2) & b;
}

EXTERN_C int func_80086720(void *self, int b)
{
    return FIELD_AT(self, unsigned short, 0x0) & b;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008672C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086740);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008677C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800867B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086814);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008687C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008691C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086990);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086A20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086B70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086CAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086DB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086E14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086E74);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086EF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80086F94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800870E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087284);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800872B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800873A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800874C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087620);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087764);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087880);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008792C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800879CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087A58);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087AF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087B78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087C2C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087CFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087D98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087E50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087EF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80087FC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008805C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80088114);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008816C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80088280);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80088310);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800883A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80088794);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008891C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80088C8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80088DEC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017C00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80088F34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089024);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008906C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800890B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800890F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089178);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800891C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800893EC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800894AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089658);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008972C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089804);

EXTERN_C void func_800898F0(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800898FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089954);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800899AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800899FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089A4C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089AC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089B44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089BF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089D28);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089D80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089DB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089E14);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089E70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089EC0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089F10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089F84);

EXTERN_C void func_80089FC8(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80089FD0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008A188);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008A2A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008A54C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008A5C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008A770);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008A858);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008A93C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008A96C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008AC28);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017CB4);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017CCC);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017D1C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017D2C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017D4C);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017D64);

INCLUDE_RODATA("asm/main/nonmatchings/game", D_80017DFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008ACC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008AE38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008AE68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008AFE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B084);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B130);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B150);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B258);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B30C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B444);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B4B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B4E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B574);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B58C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B5A4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B5B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B630);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B6B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B888);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B96C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008B9C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BA68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BAC4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BB20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BBB0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BC0C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BD04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BE08);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BE50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BECC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BF78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008BFEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C060);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C168);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C27C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C3AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C414);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C448);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C4B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C4F0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C52C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C6B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C6F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C724);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C748);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C76C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C790);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C7B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C928);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C970);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008C9A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CA50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CB84);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CBE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CC20);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CC88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CD1C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CD88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CDA8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CE18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008CFD4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D038);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D08C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D114);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D1E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D1F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D450);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D4C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D5A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D5E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D6AC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D6E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D808);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D84C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D8F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D950);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008D97C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008DA00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008DACC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008DBEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008DC78);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008DCE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008DD50);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008DEE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E024);

EXTERN_C void func_8008E060(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E068);

EXTERN_C void * func_8008E0B0(void *self)
{
    return (char *)self + 0x58;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E0B8);

EXTERN_C void func_8008E104(void)
{
}

EXTERN_C unsigned char func_8008E10C(void *self)
{
    return FIELD_AT(self, unsigned char, 0x2E);
}

EXTERN_C void func_8008E118(void *self, int b)
{
    FIELD_AT(self, char, 0x2D) = b;
}

EXTERN_C void func_8008E120(void *self, int b)
{
    FIELD_AT(self, int, 0xAC) = b;
}

EXTERN_C void func_8008E128(void *self, int b, int c)
{
    FIELD_AT(self, int, 0xB0) = b;
    FIELD_AT(self, char, 0x2F) = c;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E134);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E1B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E210);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E2A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E308);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E360);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E504);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E590);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E678);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E698);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E70C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E75C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008E994);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008EA9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008EB40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008ECB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008ED44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008EDE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008EE24);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008EECC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008EF18);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008EF40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008EF64);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008F0CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008F1DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008F4B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008F618);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FA34);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FAB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FB80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FC38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FD04);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FD44);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FD94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FDE4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FEAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8008FFF0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009031C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80090550);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80090724);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80090A88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80090AAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80090CF4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800912DC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091334);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800916A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800916F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091708);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091720);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091740);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091760);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091778);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091798);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800917C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800917E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091800);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091878);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091894);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800918B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800918E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800918F8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091910);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091958);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800919C4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091A10);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091A5C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091AB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091B38);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091B68);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091B90);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091BAC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091BC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091C94);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091D70);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091ED0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80091FB4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009200C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092054);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009209C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800920E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009212C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092178);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800921C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092210);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092258);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800922A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800922B4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800922CC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800922E4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009231C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092354);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800923A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092408);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092440);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092478);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800924D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092508);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092540);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092584);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800925D0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009261C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092668);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800926B8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092754);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800927C8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092910);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092A98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092ACC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092B00);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092B3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092B98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092BFC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092C54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092CC8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092DE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092F54);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092F88);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80092FBC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093018);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093088);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800930E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093154);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009327C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800933E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009341C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093450);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093524);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093610);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800936A0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800936D8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093710);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093788);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093800);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093858);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800938B4);

EXTERN_C int func_80093928(void *self, int b, int c)
{
    return c + 3;
}

EXTERN_C int func_80093930(void *self, int b, int c)
{
    return c + 2;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093938);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800939A8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800939F4);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093A40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093A80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093AEC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093B3C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093BB8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093C9C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093CE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093D8C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093DE8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093E80);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093EE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093F40);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093F98);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80093FE0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009422C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800942E0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80094330);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800944E8);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80094500);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80094548);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009459C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800945FC);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80094664);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800946B0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009471C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009478C);

EXTERN_C int func_800947B8(void)
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_800947C0);

INCLUDE_ASM("asm/main/nonmatchings/game", func_80094800);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009482C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009484C);

INCLUDE_ASM("asm/main/nonmatchings/game", func_8009486C);

EXTERN_C void func_80094888(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/game", func_80094890);

INCLUDE_ASM("asm/main/nonmatchings/game", func_800948B4);

EXTERN_C void func_80094908(void)
{
}
