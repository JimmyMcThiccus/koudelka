// func_8003D384: matches except the register for %hi(D_800B4ED8): retail `lui $v1; lw $v1, %lo($v1)`,
// this gives `lui $v0; lw $v1, %lo($v0)`. D_800B4ED8 is reached with lui in this file but is a 4-byte
// pointer; small externs get $gp here, so it's declared as an array to force lui.
typedef struct S_800B4ED8 {
    char pad0[0x94];
    int unk94;
} S_800B4ED8;

typedef struct S_8003D384 {
    char pad0[0x4];
    short unk4;
    int unk8;
} S_8003D384;

EXTERN_C S_800B4ED8 *D_800B4ED8[];

EXTERN_C void func_8003D384(S_8003D384 *p, int a, int b)
{
    S_800B4ED8 *d = D_800B4ED8[0];
    p->unk4 = a;
    p->unk8 = b;
    d->unk94 = 1;
}
