#ifndef GAME_A_H_U_80020368_H
#define GAME_A_H_U_80020368_H

/* Declarations for src/main/u_80020368.cpp only. */

EXTERN_C int func_80019CFC(List *l, void *item);
struct S_Arr8 { int *p; int n; int *q; int buf[8]; };

EXTERN_C int func_80019C24(List *l, void *item);
struct S_80020884 { int a; int unk4; char pad[0x40]; short unk48; short unk4A; unsigned int unk4C; };
struct S_80020884_Out { char pad[0x14]; int unk14; };
struct S_80020984 { char pad[0x28]; Holder h; };

struct VtE { short delta; short index; void *pfn; };
struct S_VObj { VtE *vt; };
#define VCALL0(o, k) ((void (*)(void *))(o)->vt[k].pfn)((char *)(o) + (o)->vt[k].delta)
struct S_PtrVec { S_VObj **data; int count; };
struct S_Iter {
    S_PtrVec *l;
    int it;
    S_VObj *next() { return it < l->count ? l->data[it++] : 0; }
    S_VObj *prev() { if (it > 0) return l->data[--it]; return 0; }
};
#define G_6C4 (*(S_Iter *)&D_800AC6C4)
struct S_80020734 { int a; S_VObj *unk4; char pad[0x40]; short unk48; short unk4A; int unk4C; short unk50; short unk52; int unk54; };
struct S_80020734_B { char pad[0xC]; int unkC; };
struct S_800207C4_R { char pad[8]; void *unk8; char padC[8]; int unk14; };
struct S_800207C4 { int a; S_VObj *unk4; char pad[0x40]; short unk48; short unk4A; unsigned int unk4C; short unk50; short unk52; int unk54; };
struct S_80020A30 { int a; S_VObj *unk4; S_Iter iter; };

#endif /* GAME_A_H_U_80020368_H */
