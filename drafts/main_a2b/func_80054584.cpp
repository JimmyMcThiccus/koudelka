/* func_80054584: near miss. 4 instructions: store order 0x1C/0x18 after the base ctor call. Uses include/game/a2/a2.h (AT etc.). */
struct C_80054584 : C_80053928 { int unk1C, unk20, unk24; C_80054584(int a) asm("func_80054584"); };
C_80054584::C_80054584(int a) : unk1C(a)
{
    AT(this, void **, 0x18) = D_80013B48;
    unk20 = 10000;
    unk24 = 0;
    func_80054708(this, a);
}
