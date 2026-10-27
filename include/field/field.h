#ifndef FIELD_FIELD_H
#define FIELD_FIELD_H

#include "common.h"

/* Classes whose real names are unknown are named after the first function that
   uses them. Only the fields seen so far are named. FIELD never uses $gp, so
   globals it reaches are declared as arrays (lui access under -G8). */

/* PsyQ libapi */
struct DIRENTRY { char name[20]; int attr; int size; struct DIRENTRY* next; int head; char system[4]; };
EXTERN_C struct DIRENTRY* firstfile(char*, struct DIRENTRY*);

/* vtables */
EXTERN_C char D_80010178[];
EXTERN_C char D_800B6DF4[];
EXTERN_C char D_800B6ECC[];
EXTERN_C char D_800B6F4C[];
EXTERN_C char D_800B6F74[];
EXTERN_C char D_800B70E4[];
EXTERN_C char D_800B710C[];
EXTERN_C char D_800111BC[];
EXTERN_C char D_800B6EE4[];
EXTERN_C char D_800B6F3C[];
EXTERN_C char D_800B709C[];
EXTERN_C char D_800B70B4[];
EXTERN_C char D_800B70CC[];
EXTERN_C char D_800B70FC[];

EXTERN_C char D_800EA7C8[];
EXTERN_C int D_800B4CF0[];

/* A list whose first node is read through a null-checked pointer to it. */
struct Unk_800BFB64_node { int unk0; int unk4; };
struct Unk_800BFB64_list { struct Unk_800BFB64_node* head; };
inline Unk_800BFB64_node* first(Unk_800BFB64_list* l) { return l ? l->head : 0; }

/* An object with a virtual destructor (deleted through its vtable). */
struct Unk_Deletable { virtual ~Unk_Deletable(); };

/* Base of the objects whose vptr sits at 0x2C. */
struct Unk_Vobj2C {
    char pad0[0x2C];
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4();
    virtual void vf5(); virtual void vf6(); virtual void vf7(); virtual void vf8(); virtual void vf9();
    virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13(); virtual void vf14();
    virtual void vf15(); virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23(); virtual void vf24();
    virtual void vf25(); virtual void vf26(); virtual void vf27(); virtual void vf28(unsigned char);
};

struct Unk_800BA994 { void* vtbl; int unk4; short unk8; short unkA; };
struct Unk_800BA9CC { void* vtbl; };
struct Unk_800BB010_entry { unsigned char unk0; unsigned char unk1; unsigned char unk2; char pad3[0xD]; };
struct Unk_800BB010 { char pad0[0x28]; Unk_800BB010_entry unk28[1]; };
struct Unk_800BB81C { char pad0[0x280]; short unk280; short unk282; char pad284[0x208]; int unk48C; int unk490; };
struct Unk_800BC5F0_sub { int unk0; Unk_Deletable* unk4; };
struct Unk_800BC5F0 { char pad0[0x494]; Unk_800BC5F0_sub unk494; };
struct Unk_800BB230 { char pad0[0x4]; int unk4; char pad8[0x40]; int unk48; };
struct Unk_Pair { int unk0; int unk4; };
struct Unk_800BCBE8 { char pad0[0x4EC]; Unk_Pair unk4EC; Unk_Pair unk4F4; void* unk4FC; int unk500; char pad504[8]; Unk_Pair unk50C; Unk_Pair unk514; void* unk51C; int unk520; void* unk524; char pad528[4]; void* unk52C; void* unk530; void* unk534; void* unk538; void* unk53C; void* unk540; char pad544[0xF8]; int unk63C; char pad640[4]; int unk644; char pad648[0x4]; int unk64C; char pad650[0x4]; int unk654; char pad658[0xC]; int unk664; };
struct Unk_800BD2EC { short unk0; short unk2; };
struct Unk_800BCFD0 { void* vtbl; int unk4; };
struct Unk_800BD3E0 { void* vtbl; struct Unk_800BD3E0* unk4; short unk8; short unkA; signed char unkC; char padD[3]; Unk_800BD2EC* unk10; Unk_800BD2EC* unk14; int unk18; int unk1C; signed char unk20; };
struct Unk_800BF20C { char pad0[0x28]; };
struct Unk_800BDE08_node { int unk0; struct Unk_800BDE08_node* unk4; signed char unk8; char pad9[3]; int unkC; };
struct Unk_800BDE58_node { int unk0; struct Unk_800BDE58_node* unk4; short unk8; char padA[0xE]; int unk18; };
struct Unk_800BF204 { char pad0[0x100]; char unk100; char unk101; char pad102[0x176]; int unk278; char pad27C[0x10]; short unk28C; char pad28E[0x14A]; unsigned short unk3D8; short unk3DA; char pad3DC[0x10]; Unk_800BD3E0* unk3EC; char pad3F0[0x24]; Unk_800BDE58_node* unk414; char pad418[0x2C]; Unk_800BDE08_node* unk444; char pad448[8]; char unk450[0x44]; char unk494[0xB0]; char unk544[0x24]; Unk_800BF20C unk568[1]; };
struct Unk_800BF420 { void* vtbl; int unk4; int unk8; int unkC; signed char unk10; signed char unk11; short unk12; short unk14; short pad16; void* unk18; int unk1C; };
struct Unk_800BF488 { void* vtbl; int unk4; signed char unk8; char pad9; short unkA; int unkC; };
struct Unk_800BF624 { void* vtbl; void* unk4; int unk8; short unkC; };
struct Unk_800BF9BC { char pad0[0x44]; int unk44; char pad48[0x5C8]; Unk_800BFB64_list unk610; };
struct Unk_800BFE48 { void* vtbl; char pad4[0x88]; void* unk8C; char pad90[0x68]; void* unkF8; };
struct Unk_800C0198 { void* vtbl; void* unk4; void* unk8; int unkC; int unk10; };
struct Unk_800C02FC { int unk0; void* unk4; };
struct Unk_800C0540 { char pad0[0x8]; short unk8; short padA; char unkC[0x20]; short unk2C; short pad2E; int unk30; char pad34[4]; int unk38; };
struct Unk_800C07E0 { void* vtbl; int unk4; signed char unk8; char pad9; unsigned short unkA; int unkC; };
struct Unk_800C03CC { void* vtbl; char pad4[8]; void* unkC; char pad10[4]; char unk14[4]; };
struct Unk_800C3DE8 { char pad0[0x68]; int unk68; };
struct Unk_800C46E4 { char pad0[0x44]; int unk44; };
struct Unk_800C9D60_sub : Unk_Vobj2C { char pad30[0x20]; char unk50[4]; };
struct Unk_800C9D60 { char pad0[0x64]; Unk_800C9D60_sub* unk64; };
struct Unk_800C0814 { char pad0[0x6C]; Unk_800C9D60 unk6C; char padD4[0x6FCC]; void* unk70A0; };
struct Unk_800CE30C { char pad0[0x140]; int unk140; int unk144; };
struct Unk_800CEC9C { char pad0[0x20]; int unk20; };
struct Unk_800D05FC { char pad0[0x38]; unsigned char unk38; };
struct Unk_800D56BC { char pad0[0xA40]; int unkA40; };
struct Unk_800DA204 { char pad0[0x22F0]; char unk22F0[4]; };
struct Unk_800DB9F8 { char pad0[0x1C]; Unk_800BFB64_list unk1C; };
struct Unk_800DBA18 { char pad0[0x68]; int unk68; };
struct Unk_800DED0C { char pad0[0x240]; int unk240; };
struct Unk_800DF32C { char pad0[0x380]; void* unk380; char pad384[0x16C]; char unk4F0[4]; };
struct Unk_800E07FC { char pad0[0x88]; void* unk88; };
struct Unk_800E082C { char pad0[0x2EFC]; signed char unk2EFC; };
struct Unk_800E4290 { char pad0[0x58]; int unk58; int unk5C; };
struct Unk_800E51A4 { int unk0; short* unk4; };
struct Unk_800E51EC { char pad0[0x38]; int unk38; char pad3C[8]; int unk44; int unk48; int unk4C; int unk50; void* unk54; int unk58; };
struct Unk_800E6198 { char pad0[0x58]; int unk58; };
struct Unk_800E6750 { char pad0[0x50]; int unk50; char unk54[9]; char unk5D[0x43]; int unkA0; };
struct Unk_800E83B8 { char pad0[0x68]; int unk68; char pad6C[0xC]; int unk78; int unk7C; int unk80; char pad84[0x24]; char unkA8[4]; };

EXTERN_C Unk_800C0814* D_800EA0B8[];

/* Inline helpers. Their calls inside loop conditions keep GCC from rotating
   those loops, as in retail. */
inline int atLast(Unk_800BD3E0* p) { return p->unk18 == p->unkA - 1; }
inline Unk_800BD3E0* next(Unk_800BD3E0* n) { return n->unk4; }
inline Unk_800BDE08_node* next(Unk_800BDE08_node* n) { return n->unk4; }
inline Unk_800BDE58_node* next(Unk_800BDE58_node* n) { return n->unk4; }

/* EXE functions */
EXTERN_C void func_8001A610(void*, int);
EXTERN_C void func_8001D024(void*);
EXTERN_C void func_8001FC78(int, int, int);
EXTERN_C void func_80025CE0(void*, void*, int);
EXTERN_C int func_80053880(void*);
EXTERN_C void func_80053BCC(void*, int, int);
EXTERN_C void func_80054C34(void*);
EXTERN_C void func_80054FE0(void*);
EXTERN_C void func_800553D8(int);
EXTERN_C void func_800557C8(void*, int, int);
EXTERN_C void func_8005F120(void*);
EXTERN_C void* func_80066FB0(void*, void*, int, int, int);
EXTERN_C void func_800670A4(void*);
EXTERN_C void* func_80066DA4(void*, void*, int, int, int);
EXTERN_C void func_80066E04(void*);
EXTERN_C void* func_8008D1F4(void*, int);
EXTERN_C void func_8008D4C0(void*);
EXTERN_C void* func_8008E360(void*);
EXTERN_C void func_8008E504(void*);
EXTERN_C void func_8008ECB4(void*);
EXTERN_C void func_8008ED44(void*);
EXTERN_C void func_80094890(void*);
EXTERN_C void func_800A0D0C(void*);
EXTERN_C void* func_800A0D2C(int);
EXTERN_C short func_8001A6E8(void*);
EXTERN_C void func_80019920(void*, int);
EXTERN_C void func_80019A6C(void*, int, int);
EXTERN_C void func_80019D40(void*);
EXTERN_C void* func_800787B4();
EXTERN_C void func_8007F5B8(void*, int, int);
EXTERN_C void func_80080BC4(void*);

/* FIELD functions */
EXTERN_C int func_800BB5E8(void*);
EXTERN_C void func_800BC394(void*);
EXTERN_C void func_800BC500(void*);
EXTERN_C int func_800BC18C(Unk_800BCBE8*);
EXTERN_C int func_800BC1E8(Unk_800BCBE8*);
EXTERN_C void func_800BC228(void*);
EXTERN_C void func_800BD3E0(Unk_800BD3E0*, signed char);
EXTERN_C void func_800BD3FC(Unk_800BD3E0*);
EXTERN_C void func_800BD410(Unk_800BD3E0*);
EXTERN_C void func_800BD468(Unk_800BD3E0*, int);
EXTERN_C void func_800BD4CC(void*);
EXTERN_C void func_800BD62C(void*, int);
EXTERN_C Unk_800BD3E0* func_800BE200(Unk_800BF204*, int);
EXTERN_C Unk_800BF624* func_800BF624(Unk_800BF624*, void*, int, short);
EXTERN_C void func_800BF66C(void*);
EXTERN_C Unk_800C0198* func_800C0198(Unk_800C0198*, void*, int, void*, int);
EXTERN_C void func_800C01F8(void*);
EXTERN_C void func_800C04A0(void*);
EXTERN_C void func_800C9D60(Unk_800C9D60*, int);
EXTERN_C void func_800C9E48(Unk_800C9D60*);
EXTERN_C void func_800C010C(void*, int, int);
EXTERN_C void func_800CAAD4(void*, int);
EXTERN_C void func_800DB618(void*);
EXTERN_C void func_800E51F8(void*);
EXTERN_C void func_800E556C();

#endif /* FIELD_FIELD_H */
