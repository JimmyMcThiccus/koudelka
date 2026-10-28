/* func_8003D384: near miss. D_800B4ED8 is reached with lui in retail; maspsx_extern makes it $gp (toolchain). Uses include/game/a2/a2.h (AT etc.). */
struct S_A2_B4ED8 { char pad[0x94]; int unk94; };
EXTERN_C S_A2_B4ED8 *D_800B4ED8[];
struct S_A2_D384 { int unk0; short unk4; int unk8; };
EXTERN_C void func_8003D384(S_A2_D384 *p, short a, int b)
{
    p->unk4 = a; p->unk8 = b; D_800B4ED8[0]->unk94 = 1;
}
