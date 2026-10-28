/* func_8004B8F8: near miss. body prim stores use this+off instead of the member base register. Uses include/game/a2/a2.h (AT etc.). */
struct S_A2_PolyG3 { unsigned char tag[3]; unsigned char len; unsigned char r0, g0, b0, code; char rest[0x14]; S_A2_PolyG3() { len = 6; code = 0x30; } };
struct S_A2_G3x2 { S_A2_PolyG3 p[2]; void set() { p[0].len = 6; p[0].code = 0x30; p[1].len = 6; p[1].code = 0x30; } };
struct C_8004B8F8 : C_800497FC { char pad10[8]; S_A2_G3x2 m; C_8004B8F8() asm("func_8004B8F8"); };
C_8004B8F8::C_8004B8F8()
{
    m.set();
    vt = D_80012F50;
}
