#include "common.h"
#include "battle/battle.h"

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B7FFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8210);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B82C0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8474);

EXTERN_C int func_800B84EC() { return D_800D5D78 != 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B84FC);

EXTERN_C void func_800B8598(void *p, int flags) { func_8001D024(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B85B8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8778);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B881C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8924);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B89D4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8AA8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8EFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8F5C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B8FF4);

EXTERN_C int func_800B9268(T_B9268 *p) { func_800BB118(p->f554); return 1; }

EXTERN_C int func_800B928C(T_B9268 *p) { func_800BBC04(p->f558); return 1; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B92B0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B92E0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9480);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9530);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9654);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9758);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9844);

EXTERN_C int func_800B98B8() { return D_800D5D7C; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B98C8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B99A4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9A30);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9F48);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800B9FC4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA024);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA248);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA2F4);

EXTERN_C char *func_800BA418(S_800BA418 *p) { return p->f424; }

EXTERN_C S_800BA418_448 *func_800BA420(S_800BA418 *p, int i) { return &p->f448[i]; }

EXTERN_C int func_800BA438(S_800BA418 *p) { return p->f10C; }

EXTERN_C int func_800BA444(S_800BA418 *p, int v) { p->f10C = v; return 1; }

EXTERN_C SVec4 func_800BA450(T_BA450 *p) { return p->f1EC; }

EXTERN_C SVec4 func_800BA47C(T_BA450 *p) { return p->f1E4; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA4A8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA4E4);

EXTERN_C char *func_800BA520(S_800BA418 *p) { return p->f104; }

EXTERN_C char *func_800BA528(S_800BA418 *p) { return p->f164; }

EXTERN_C int func_800BA530(S_800BA418 *p) { return p->s28C; }

EXTERN_C int func_800BA53C(S_800BA418 *p) { return p->s3DA; }

EXTERN_C void func_800BA548(S_800BA418 *p, char v) { p->b101 = v; }

EXTERN_C void func_800BA550(S_800BA418 *p, char v) { p->b100 = v; }

EXTERN_C int func_800BA558(S_800BA418 *p) { return p->f278; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA564);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA594);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA5FC);

EXTERN_C int func_800BA6B4(S_800BA6B4 *p) { if (p->fC) return p->sA; return 0; }

EXTERN_C int func_800BA6D0(S_800BA6B4 *p) { if (p->fC) return p->b8; else return 0; }

EXTERN_C int func_800BA6EC(S_800BA6B4 *p) { return p->fC; }

EXTERN_C void func_800BA6F8(S_800BA6B4 *p, char v) { p->b8 = v; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA700);

EXTERN_C void func_800BA73C(T_VObj *p, int flags) { p->vtbl = D_800B6F6C; func_800BC0C0(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BA764);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BAD6C);

EXTERN_C void func_800BADDC(T_VObj *p, int flags) { p->vtbl = D_800B6F84; func_800BC0C0(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BAE04);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BAFEC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB118);

EXTERN_C void func_800BB188(S_800BA6B4 *p) { p->f14 = 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB190);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB2B0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB354);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB5EC);

EXTERN_C int func_800BB854(S_800BA6B4 *p) { return p->f4; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB860);

EXTERN_C void func_800BB8D0(T_VObj *p, int flags) { p->vtbl = D_800B7054; func_800BC0C0(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BB8F8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BBAD4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BBC04);

EXTERN_C void func_800BBC74(S_800BA6B4 *p) { p->f14 = 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BBC7C);

EXTERN_C void func_800BBCC0(T_VObj *p, int flags) { p->vtbl = D_800B706C; func_800BC0C0(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BBCE8);

EXTERN_C int func_800BBD54(S_800BA6B4 *p) { return p->f14; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BBD60);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BBEE0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BBF84);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC074);

EXTERN_C int func_800BC080(S_800BA6B4 *p) { return p->f4; }

EXTERN_C int func_800BC08C() { return 0; }

EXTERN_C T_VObj *func_800BC094(T_VObj *p, int a, int b) { p->vtbl = D_80010178; p->f4 = 0; p->vtbl = D_800B713C; p->f8 = a; p->fC = b; return p; }

EXTERN_C void func_800BC0C0(T_VObj *p, int flags) { p->vtbl = D_800B713C; func_8001A610(p, flags); }

EXTERN_C int func_800BC0E8(S_800BC0E8 *p, int a, int b) { p->f8 = a; p->fC = b; return 1; }

EXTERN_C int func_800BC0F8() { return 0; }

EXTERN_C void func_800BC100(S_800BA6B4 *p) { p->f10 = 0; }

EXTERN_C int func_800BC108(S_800BA6B4 *p) { return p->f10; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC114);

EXTERN_C void func_800BC158(T_VObj *p, int flags) { p->vtbl = D_800B7154; func_8001D024(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC180);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC1F8);

EXTERN_C int func_800BC270(T_BC270 *p) { func_800B9654(p->f4); return 1; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC294);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC310);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC378);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC3B4);

EXTERN_C int func_800BC420(T_BC420 *p) { return count_of(&p->h4C0); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC440);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC514);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC5A8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC644);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC6C8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC6FC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC704);

EXTERN_C void func_800BC850(T_VObj *p, int flags) { p->vtbl = D_800B71B4; func_8001A610(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BC878);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BCA6C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BCAEC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BCB6C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BCC2C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BCCEC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BCDC0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BCFC4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD0A4);

EXTERN_C int func_800BD158(S_800BA6B4 *p) { return p->f4; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD164);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD284);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD328);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD5C4);

EXTERN_C int func_800BD830(S_800BA6B4 *p) { return p->f4; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD83C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD950);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BD9F4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BDC28);

EXTERN_C int func_800BDE20(S_800BA6B4 *p) { return p->f4; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BDE2C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BDE5C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BDEDC);

EXTERN_C int func_800BE068(S_800BE068 *p) { return p->fC; }

EXTERN_C void func_800BE074(S_800BE068 *p, char v) { p->b8 = v; }

EXTERN_C void func_800BE07C(S_800BE068 *p, short v) { p->sA = v; }

EXTERN_C int func_800BE084(S_800BE068 *p) { return p->b8; }

EXTERN_C int func_800BE090(S_800BE068 *p) { return p->sA; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE09C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE0F8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE108);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE18C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE1F8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE208);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE274);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE29C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE2EC);

EXTERN_C void *func_800BE33C(void *p) { return p; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE344);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE390);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE3B4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE484);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE6B8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE7A4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE928);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BE990);

EXTERN_C void func_800BEBD8() {}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BEBE0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BEDE8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BEE50);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BEF98);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BF1D0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BF3B4);

EXTERN_C void func_800BF3F4() {}

EXTERN_C int func_800BF3FC() { return 0; }

EXTERN_C void func_800BF404() {}

EXTERN_C void func_800BF40C() {}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BF414);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BF5FC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BF76C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BF8B4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BF968);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BF9DC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BFB18);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BFB80);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BFBCC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BFC18);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BFC60);

EXTERN_C int func_800BFCB8(T_BFCB8 *p, int *q) { if (q) return *q; return p->f52C; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800BFCD8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C02C8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C0608);

EXTERN_C void func_800C0670(T_B9268 *p, void *a, int b) { p->f4D0 = a; func_800C0694(p, b); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C0694);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C07F8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C0EB8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1118);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1158);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1254);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C12D0);

EXTERN_C void func_800C1340(T_C1340 *p, int v) { p->f4D0 = v; func_800C1360(p); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1360);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C13CC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C18B4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1924);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C19BC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1A10);

EXTERN_C void func_800C1A44(T_C1A44 *p, int flags) { p->vtblC = D_80017904; func_80074F78(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1A6C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1B48);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1BA8);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6DF0);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6DF4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6E0C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6E64);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6ECC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6EE4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6EFC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F14);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F2C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F44);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F5C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F84);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B6F9C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7004);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7054);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B706C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7084);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B70EC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B713C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7154);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B716C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7184);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B719C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B71B4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7204);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B726C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B72BC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7324);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7374);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7384);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B73A4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1BE4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1E44);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C1F5C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C220C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C2538);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C2814);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C2B70);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C2ECC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C30F0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3374);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C35F8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C38FC);

EXTERN_C int func_800C3CF4() { return 1; }

EXTERN_C int func_800C3CFC() { return 1; }

EXTERN_C int func_800C3D04(T_C3D04 *p, int a, int b, int c) { if (~c & b & 2) { p->b516 = 1; return 0; } return 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3D2C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3DAC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3E34);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3E84);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3F14);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3F84);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C3FF4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C41AC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C435C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C43F0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C4510);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C46F0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C4748);

EXTERN_C void func_800C477C() {}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C4784);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C47D8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C48D8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C4B70);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C4EC4);

EXTERN_C void func_800C5018() {}

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B73D0);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7420);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7518);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7538);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5020);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5124);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5180);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C51D0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5474);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C54D8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C55C4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C56A8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5880);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C59B8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C59EC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5A30);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5AD0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5B18);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5B4C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5CC4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5D84);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5E1C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5EA0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5F08);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C5F84);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C6050);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C6194);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C65C8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C666C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C68D8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C6DF4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7158);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7528);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C757C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7604);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7764);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C78EC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7A28);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7B5C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7D88);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7DD0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7F30);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7F74);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C7FB8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C800C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C8A54);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C8BA4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C8D9C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C8EE4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C8F78);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9284);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9374);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9584);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9674);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9794);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C98F0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9A4C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9B04);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9BFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9D6C);

EXTERN_C int func_800C9E58(T_C9E58 *p, int i) { if (i < p->f848) return p->f84C[i]; return 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9E84);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9EF4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800C9FFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CA1B4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CA710);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CA75C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CA7D4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CA918);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CA9D0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CAAF8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CACD8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CAD5C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CADDC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CB174);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CB8EC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CB9F0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CBA50);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CBA80);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CBB24);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CBB54);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CBB84);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CBBB4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC110);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC1B0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC220);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC298);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC3DC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC7DC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CC98C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CCB98);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CCC4C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CCD70);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CCDCC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CCFC0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CD250);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CD354);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CD488);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CD790);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CDA8C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CDA94);

EXTERN_C void func_800CDAC8(void *p) { func_800C757C(p, 1); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CDAE8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CDD0C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CDE4C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CDED8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CDF64);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE00C);

EXTERN_C void func_800CE044(T_CE044 *p) { p->f8 = 0; func_800CE00C(p); }

EXTERN_C void func_800CE064(T_CE044 *p) { p->f8 = p->fC - 1; func_800CE00C(p); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE090);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE0D4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE110);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE154);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE320);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE4B4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE4E4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE7A4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE854);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE910);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CE9B8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEA00);

EXTERN_C int func_800CEA48() { return 0; }

EXTERN_C int func_800CEA50(void *self, S_800CEA50 *a, S_800CEA50 *b) { return a->fC - b->fC; }

EXTERN_C int func_800CEA60(void *self, S_800CEA50 *a, S_800CEA50 *b) { return a->f10 - b->f10; }

EXTERN_C int func_800CEA70(void *self, S_800CEA50 *a, S_800CEA50 *b) { return a->f14 - b->f14; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEA80);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEB04);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEB5C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEB94);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEBC4);

EXTERN_C void func_800CEC00(T_CEC00 *p) { func_800766D8(p->f90C); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEC24);

EXTERN_C void func_800CEC68() {}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEC70);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CED08);

EXTERN_C int func_800CEE04(T_CEE04 *p, int i) { return p->f7FC[i]; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEE18);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CEFE8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF080);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF0B0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF274);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF2D0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF408);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF764);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF840);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF8E4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF95C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CF9CC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFB08);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFC50);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFCB0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFCBC);

EXTERN_C int func_800CFCC4(T_CFD98 *p, SVec2 v) { return p->f14[v.y][v.x]; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFCF0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFCFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFD2C);

EXTERN_C void func_800CFD64(void *p) { func_800CC110(p); }

EXTERN_C void func_800CFD84(S_800CFCB0 *p, int v) { p->fA0 = v; }

EXTERN_C int func_800CFD8C(S_800CFCB0 *p) { return p->fA0; }

EXTERN_C int func_800CFD98(T_CFD98 *p, int i, int j) { return p->f14[j][i]; }

EXTERN_C int func_800CFDB8(void *self, int v) { return (v & 7) << 9; }

EXTERN_C int func_800CFDC4(void *self, int v) { return ((v + 0x100) / 512) & 7; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFDE0);

EXTERN_C int func_800CFE08(S_800CFCB0 *p) { p->f90 = 0; return p->f8C != 0; }

EXTERN_C int func_800CFE18(S_800CFCB0 *p) { return p->f8C; }

EXTERN_C void func_800CFE24(S_800CFCB0 *p) { p->f8C = 0; p->f90 = 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFE30);

EXTERN_C void func_800CFE64(void *p, int flags) { if (flags & 1) operator delete(p); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFE8C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFEBC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800CFEF4);

EXTERN_C T_CFF44 *func_800CFF44(T_CFF44 *p, SVec2 v, int a) { p->f0 = v; p->f4 = a; return p; }

EXTERN_C S_800CFF68 *func_800CFF68(S_800CFF68 *p, int v) { p->s0 = 0; p->s2 = 0; p->f4 = v; return p; }

EXTERN_C S_800CFF68 *func_800CFF7C(S_800CFF68 *p) { p->s0 = 0; p->s2 = 0; return p; }

EXTERN_C void func_800CFF8C(void *p, int flags) { if (flags & 1) operator delete(p); }

EXTERN_C T_CFFB4 *func_800CFFB4(T_CFFB4 *p, SVec2 *v, int a) { p->f0.x = 0; p->f0.y = 0; p->f0 = *v; p->f4 = a; p->s8 = 0; return p; }

EXTERN_C T_CFFB4 *func_800CFFE0(T_CFFB4 *p, SVec2 *v) { p->f0.x = 0; p->f0.y = 0; p->f0 = *v; p->f4 = 0; p->s8 = 0; return p; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D000C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0048);

EXTERN_C void func_800D0054(T_D0054 *p, int v) { p->f12C += v; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0068);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0074);

EXTERN_C void func_800D00B8(void *self, S_800D00B8 *l) { l->prev = l; l->next = l; l->fC = 0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D00C8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0130);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D019C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0230);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D02E8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D02F4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0300);

EXTERN_C void func_800D030C(S_800D00B8 *l) { l->prev = l; l->next = l; l->fC = 0; }

EXTERN_C void func_800D031C(S_800D00B8 *l, int a, int b) { l->prev = l; l->next = l; l->fC = 1; l->f10 = a; l->f14 = b; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0338);

EXTERN_C void func_800D0370(void *p, int flags) { func_80074E44(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0390);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0404);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0440);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D044C);

EXTERN_C void func_800D0588() {}

EXTERN_C void func_800D0590() {}

EXTERN_C void func_800D0598() { func_8005F440(func_800787B4(), 0x1262); }

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7748);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7768);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7778);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D05C4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0BCC);

EXTERN_C void func_800D0C88() {}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0C90);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0CC0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D0D1C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D10D4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1148);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D119C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1458);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D168C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1758);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1764);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D17A4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1950);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D19F0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1A90);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1B68);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1C50);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D1D38);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D20E0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2254);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7884);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B78D4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B78F4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7924);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D23C0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D24E8);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D255C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2598);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2670);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B79A4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B79F4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7A14);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7A44);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2778);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7A94);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2A2C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2A98);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2C50);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2D60);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2F54);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D2F94);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D3044);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D321C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7ACC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7AFC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D3574);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D3CD4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D3D50);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D3ED0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D401C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D407C);

EXTERN_C void func_800D4094(T_D4094 *p, SVec4 *v) { p->f52 = *v; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D40BC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D41D4);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4290);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D43B0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4518);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4718);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4748);

EXTERN_C void func_800D47C8() {}

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D47D0);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4828);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4968);

EXTERN_C void func_800D4BD4() {}

EXTERN_C void func_800D4BDC(void *p, int flags) { func_8005F120(p, flags); }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4BFC);

EXTERN_C int func_800D4E68(T_D4E68 *p) { return (p->f2280 << 16) | 0x10F0; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D4E7C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D5038);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D5074);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D51FC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7B3C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7B6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7BBC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7BDC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7C1C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7C6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7D64);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7D84);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7DEC);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7E3C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7E5C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7E8C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D5328);

EXTERN_C int func_800D5740(T_D5740 *p) { return (p->b6C[p->f20] << 16) | 0x10DC; }

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D5760);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D596C);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D59AC);

INCLUDE_ASM("asm/battle/nonmatchings/battle", func_800D5AE4);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7F1C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7F6C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7F8C);

INCLUDE_RODATA("asm/battle/nonmatchings/battle", D_800B7FBC);
