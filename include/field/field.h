#ifndef FIELD_FIELD_H
#define FIELD_FIELD_H

#include "common.h"

/* Classes whose real names are unknown are named after the first function that
   uses them. Only the fields seen so far are named. FIELD never uses $gp, so
   globals it reaches are declared as arrays (lui access under -G8). */

/* PsyQ libapi */
struct DIRENTRY { char name[20]; int attr; int size; struct DIRENTRY* next; int head; char system[4]; };
EXTERN_C struct DIRENTRY* firstfile(char*, struct DIRENTRY*);

/* PsyQ libgpu primitives */
typedef struct { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; } SPRT;
typedef struct {
    int tag;
    unsigned char r0, g0, b0, code;
    short x0, y0; unsigned char u0, v0; unsigned short clut;
    short x1, y1; unsigned char u1, v1; unsigned short tpage;
    short x2, y2; unsigned char u2, v2; unsigned short pad1;
    short x3, y3; unsigned char u3, v3; unsigned short pad2;
} POLY_FT4;
typedef struct {
    int tag;
    unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut;
    unsigned char r1, g1, b1, p1; short x1, y1; unsigned char u1, v1; unsigned short tpage;
    unsigned char r2, g2, b2, p2; short x2, y2; unsigned char u2, v2; unsigned short pad2;
    unsigned char r3, g3, b3, p3; short x3, y3; unsigned char u3, v3; unsigned short pad3;
} POLY_GT4;

typedef struct { int tag; unsigned char r0, g0, b0, code; short x0, y0; short w, h; } TILE;

/* Generic polymorphic objects: VAt<N> has its vptr at offset N, VAt0 at 0. Slots
   take (...) so any int/pointer arguments pass; returns are int. A class that
   re-declares a slot makes calls load the vptr before adjusting `this`. */
#define VSLOTS10(a) virtual int vf##a##0(...); virtual int vf##a##1(...); virtual int vf##a##2(...);     virtual int vf##a##3(...); virtual int vf##a##4(...); virtual int vf##a##5(...); virtual int vf##a##6(...);     virtual int vf##a##7(...); virtual int vf##a##8(...); virtual int vf##a##9(...);
#define VSLOTS VSLOTS10(0) VSLOTS10(1) VSLOTS10(2) VSLOTS10(3) VSLOTS10(4)
template <int N> struct VAt { char vpad[N]; VSLOTS };
struct VAt0 { VSLOTS };

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
EXTERN_C char D_800B8E3C[];
EXTERN_C char D_800B8E5C[];
EXTERN_C char D_800102D0[];
EXTERN_C char D_80010300[];
EXTERN_C char D_80010338[];

EXTERN_C char D_800EA7C8[];
EXTERN_C int D_800B4CF0[];
EXTERN_C char D_800A4544[];
EXTERN_C char D_800A454C[];

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

/* Drawable objects: vptr at 0, primitives double-buffered by D_800B4CF0. */
struct Unk_Drawable {
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4();
    virtual void vf5(); virtual void vf6(); virtual void vf7(); virtual void vf8(); virtual void vf9();
    virtual void vf10(int, int);
};
struct Unk_ColorSrc { int unk0; char unk4; unsigned char unk5; unsigned char unk6; unsigned char unk7; unsigned short unk8; };
struct Unk_Sprt10 : Unk_Drawable { char pad4[0xC]; SPRT unk10[1]; };
struct Unk_Sprt28 : Unk_Drawable { char pad4[0x24]; SPRT unk28[1]; };
struct Unk_Sprt50 : Unk_Drawable { char pad4[0x4C]; SPRT unk50[1]; };
struct Unk_Ft4_10 : Unk_Drawable { char pad4[0xC]; POLY_FT4 unk10[1]; };
struct Unk_Gt4_10 : Unk_Drawable { char pad4[0xC]; POLY_GT4 unk10[1]; };

/* Pointer conversions to a base at 0x38 / 0x50 (null-checked). */
struct Unk_Pad38 { char pad0[0x38]; };
struct Unk_Pad50 { char pad0[0x50]; };
struct Unk_Base { int unk0; };
struct Unk_Derived38 : Unk_Pad38, Unk_Base { };
struct Unk_Derived50 : Unk_Pad50, Unk_Base { };
struct Unk_PadB8 { char pad0[0xB8]; };
struct Unk_800DED9C_base { int unk0; int unk4; void* unk8; };
struct Unk_800DED9C_obj : Unk_PadB8, Unk_800DED9C_base { };
struct Unk_800DED9C { char pad0[0x328]; Unk_800DED9C_obj* unk328; };

/* Objects deleted through a vptr at 0x18. */
struct Unk_Deletable18 { char pad0[0x18]; virtual ~Unk_Deletable18(); };

struct Unk_800BA994 { void* vtbl; int unk4; short unk8; short unkA; };
struct Unk_800BA9CC { void* vtbl; };
struct Unk_800BB010_entry { unsigned char unk0; unsigned char unk1; unsigned char unk2; char pad3[0xD]; };
struct Unk_800BB010 { char pad0[0x28]; Unk_800BB010_entry unk28[1]; };
struct Unk_800BB81C { char pad0[0x280]; short unk280; short unk282; char pad284[0x208]; int unk48C; int unk490; };
struct Unk_800BC5F0_sub { int unk0; Unk_Deletable* unk4; };
struct Unk_800BC5F0 { char pad0[0x494]; Unk_800BC5F0_sub unk494; };
struct Unk_800BB230 { char pad0[0x4]; int unk4; char pad8[0x40]; int unk48; };
struct Unk_Pair { int unk0; int unk4; };
struct Unk_800BCBE8 { char pad0[0x4EC]; Unk_Pair unk4EC; Unk_Pair unk4F4; void* unk4FC; int unk500; void* unk504; int unk508; Unk_Pair unk50C; Unk_Pair unk514; void* unk51C; int unk520; void* unk524; char pad528[4]; void* unk52C; void* unk530; void* unk534; void* unk538; void* unk53C; void* unk540; char pad544[0xF8]; int unk63C; char pad640[4]; int unk644; char pad648[0x4]; int unk64C; char pad650[0x4]; int unk654; char pad658[0xC]; int unk664; };
struct Unk_800BD2EC { short unk0; short unk2; };
struct Unk_800BCFD0 { void* vtbl; int unk4; };
struct Unk_800BD3E0 { void* vtbl; struct Unk_800BD3E0* unk4; short unk8; short unkA; signed char unkC; char padD[3]; Unk_800BD2EC* unk10; Unk_800BD2EC* unk14; int unk18; int unk1C; signed char unk20; };
struct Unk_800BF20C { char pad0[0x28]; };
struct Unk_800BDE08_node { int unk0; struct Unk_800BDE08_node* unk4; signed char unk8; char pad9[3]; int unkC; };
struct Unk_800BDE58_node { int unk0; struct Unk_800BDE58_node* unk4; short unk8; char padA[0xE]; int unk18; };
struct Unk_800BF204 { char pad0[0x100]; char unk100; char unk101; char pad102[0x176]; int unk278; char pad27C[0x10]; short unk28C; char pad28E[0x14A]; unsigned short unk3D8; short unk3DA; char pad3DC[0x10]; Unk_800BD3E0* unk3EC; char pad3F0[0x24]; Unk_800BDE58_node* unk414; char pad418[0x2C]; Unk_800BDE08_node* unk444; char pad448[8]; char unk450[0x44]; char unk494[0xB0]; char unk544[0x24]; Unk_800BF20C unk568[1]; char pad590[0xEC]; void* unk67C; };
struct Unk_800BF420 { void* vtbl; int unk4; int unk8; int unkC; signed char unk10; signed char unk11; short unk12; short unk14; short pad16; void* unk18; int unk1C; };
struct Unk_800BF488 { void* vtbl; int unk4; signed char unk8; char pad9; short unkA; int unkC; };
struct Unk_800BF4B8 { void* vtbl; int unk4; signed char unk8; char pad9; short unkA; Unk_Deletable* unkC; };
struct Unk_800BCA88 { void* vtbl; int unk4; short unk8; short unkA; void* unkC; int unk10; };
struct Unk_800BD010 { void* vtbl; int unk4; void* unk8; short unkC; short padE; int unk10; };
struct Unk_800C0424_node { int unk0; struct Unk_800C0424_node* unk4; };
struct Unk_800C0424 { char pad0[0xC]; Unk_800BFB64_list unkC; char pad10[0x24]; int unk34; int unk38; };
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
struct Unk_800DF32C { char pad0[0x380]; struct Unk_800BCBE8* unk380; char pad384[0x16C]; char unk4F0[4]; };
struct Unk_800E07FC { char pad0[0x88]; struct Unk_800E51EC* unk88; };
struct Unk_800E082C { char pad0[0x2EFC]; signed char unk2EFC; };
struct Unk_800E429C_pos { int unk0; int unk4; };
struct Unk_800E4290 { int unk0; Unk_800E429C_pos* unk4; char pad8[0x50]; unsigned int unk58; unsigned char* unk5C; };
struct Unk_800E51A4 { int unk0; short* unk4; };
struct Unk_800E51EC { char pad0[0x2C]; void* unk2C; char pad30[4]; int unk34; void* unk38; char pad3C[8]; char* unk44; char* unk48; char* unk4C; int unk50; char* unk54; int unk58; char* unk5C; };
struct Unk_800E6198 { char pad0[0x58]; int unk58; };
struct Unk_800E6750 { char pad0[0x50]; int unk50; char unk54[9]; char unk5D[0x43]; int unkA0; };
struct Unk_800E83B8 { char pad0[0x68]; int unk68; char pad6C[0xC]; int unk78; int unk7C; int unk80; char pad84[0x24]; char unkA8[4]; };

EXTERN_C Unk_800C0814* D_800EA0B8[];

struct Unk_800C0054_node { int unk0; struct Unk_800C0054_node* unk4; char pad8[0xE]; unsigned short unk16; char pad18[0x2C]; int unk44; };
struct Unk_800C0054 { char pad0[0x498]; Unk_800C0054_node* unk498; };
struct Unk_800A4578 { char pad0[0x1D2]; unsigned char unk1D2; };
struct Unk_800B4DD0 { char pad0[0x1FB]; signed char unk1FB; };
struct Unk_800AF478 { int unk0; int unk4; int unk8; int unkC; };
struct Unk_800C13E4 { char pad0[0x68]; int unk68; };
struct Unk_800C206C { char pad0[0xA8]; Unk_Vobj2C* unkA8; };
struct Unk_800C259C : Unk_Pad50, Unk_Base { char pad54[0xC]; int unk60; };
struct Unk_800C2A0C { char pad0[0xC4]; char unkC4[4]; };
struct Unk_800C3AAC { char pad0[0xBC]; char unkBC[4]; };
struct Unk_800C6CCC { char pad0[0xB4]; char unkB4[4]; };
struct Unk_800C88D8 { char pad0[0x510]; char unk510[4]; };
struct Unk_800CD3C8 { char pad0[0xB8]; char unkB8[4]; };
struct Unk_800C3C08 { char pad0[0x68]; int unk68; char unk6C[0x70]; void* unkDC; };
struct Unk_800C6104 { char pad0[0x227C]; char unk227C[0x1058]; int unk32D4; };
struct Unk_800C6DB0 { char pad0[0xD4]; Unk_Vobj2C* unkD4; int unkD8; };
struct Unk_800C7F80_head { int unk0; int unk4; int unk8; char padC[0x2C]; };
struct Unk_800C7F80 : Unk_800C7F80_head, Unk_Base { };
struct Unk_800CAF84 { char pad0[0x84]; Unk_800BFB64_list unk84; };
struct Unk_800CCF18 { char pad0[0x20]; int unk20; };
struct Unk_800CD678 { char pad0[0x68]; char unk68[4]; };
struct Unk_800CD9F0 { char pad0[0x227C]; void* unk227C; };
struct Unk_800CEC60_elem { char pad0[0x6C]; };
struct Unk_800CEC60 { char pad0[0x68]; Unk_800CEC60_elem unk68[1]; };
struct Unk_800CEFC4 { char pad0[0x1C8]; int unk1C8; int unk1CC; };
struct Unk_800D103C_arg { char pad0[0x90]; unsigned char unk90; };
struct Unk_800D1004 { char pad0[0x3C]; int unk3C; char pad40[0x24]; int unk64; Unk_800D103C_arg* unk68; };
struct Unk_800D142C { char pad0[0x68]; int unk68; };
struct Unk_800D3AC8 { void* vtbl; char pad4[0xC]; char unk10[8]; void* unk18; };
struct Unk_800D5844 { char pad0[0xA44]; char unkA44[0x50]; char unkA94[4]; };
struct Unk_Elem28 { char pad0[28]; };
struct Unk_Elem40 { char pad0[40]; };
struct Unk_800D8970 { char pad0[0x70]; Unk_Elem28* unk70; Unk_Elem40* unk74; Unk_Elem40* unk78; };
struct Unk_800DBA24 { char pad0[0x74]; Unk_Deletable18* unk74; };
struct Unk_800DFBA8 { char pad0[0x3C]; Unk_Deletable18* unk3C; };
struct Unk_800DF6B4_obj { int unk0; int unk4; };
struct Unk_800DF6B4 { int unk0; Unk_800DF6B4_obj* unk4; };
struct Unk_800E51B8_arg { int unk0; int unk4; };
struct Unk_800E5B40 { char pad0[0x6C]; void* unk6C; char unk70[0x6C]; char unkDC[4]; };
struct Unk_800E607C { char pad0[0x50]; int unk50; int unk54; void* unk58; };

EXTERN_C short D_800EA0A8[];
EXTERN_C int D_800EA0B0[];
EXTERN_C int D_800EA2E0[];
EXTERN_C int D_800EA7B0[];
EXTERN_C int D_800EA7E4[];
EXTERN_C void* D_800EA89C[];
EXTERN_C Unk_800A4578* D_800A4578[];
EXTERN_C Unk_800B4DD0* D_800B4DD0[];
EXTERN_C Unk_800AF478 D_800AF478[];

/* Inline helpers. Their calls inside loop conditions keep GCC from rotating
   those loops, as in retail. */
inline Unk_800DED9C_base* base(Unk_800DED9C_obj* o) { return o; }
inline Unk_800C0424_node* next(Unk_800C0424_node* n) { return n->unk4; }
inline int atLast(Unk_800BD3E0* p) { return p->unk18 == p->unkA - 1; }
inline Unk_800BD3E0* next(Unk_800BD3E0* n) { return n->unk4; }
inline Unk_800BDE08_node* next(Unk_800BDE08_node* n) { return n->unk4; }
inline Unk_800BDE58_node* next(Unk_800BDE58_node* n) { return n->unk4; }
inline Unk_800C0054_node* next(Unk_800C0054_node* n) { return n->unk4; }

/* EXE functions */
EXTERN_C void func_8001A610(void*, int);
EXTERN_C void func_8001D024(void*);
EXTERN_C void func_8001FC78(int, int, int);
EXTERN_C void* func_8001CA10(int);
EXTERN_C void func_8001D150(void*, void*);
EXTERN_C void* func_8001D25C(void*, void*);
EXTERN_C void func_8001D324(void*, void*);
EXTERN_C void func_8001EFE4(void*, void*);
EXTERN_C void func_80024FEC(void*, int);
EXTERN_C void func_8008C928(int);
EXTERN_C void func_8001A744(void*, void*);
EXTERN_C void func_800279A8(void*);
EXTERN_C void func_8002A210(void*);
EXTERN_C void func_8002B27C(void*, void*);
EXTERN_C void func_80043DC0(void*);
EXTERN_C void func_800537DC(void*, int);
EXTERN_C void func_80053848(Unk_Base*);
EXTERN_C void func_8005388C(Unk_Base*, int);
EXTERN_C void func_80053C6C(void*, void*);
EXTERN_C void func_80053FB0(void*, int, int);
EXTERN_C void func_80054094(void*, int);
EXTERN_C void func_8005457C(void*, int);
EXTERN_C void func_80054708(void*, int);
EXTERN_C void func_80054EB4(void*, int, int);
EXTERN_C void func_80054FC0(void*);
EXTERN_C void func_800550FC(void*, int);
EXTERN_C void func_80055330(int);
EXTERN_C void func_8005549C(int, void*, int, int);
EXTERN_C void func_800566E4(void*);
EXTERN_C void func_80056874(void*);
EXTERN_C int func_80056BA8(void*, int);
EXTERN_C void func_8005783C(int);
EXTERN_C void func_8005F1D8(void*);
EXTERN_C void func_80062188(void*);
EXTERN_C void func_8006323C(void*);
EXTERN_C void func_800648E8(void*);
EXTERN_C int func_800689E0(void*);
EXTERN_C void func_80068E60(void*);
EXTERN_C void func_80068EE8(void*);
EXTERN_C void func_80080A2C(void*, int, int, int, int);
EXTERN_C void func_8008EF40(int);
EXTERN_C void func_80025CE0(void*, void*, int);
EXTERN_C int func_80053880(void*);
EXTERN_C void func_80053BCC(void*, int, int);
EXTERN_C void func_80054C34(void*);
EXTERN_C void func_80054FE0(void*);
EXTERN_C void func_800553D8(int);
EXTERN_C void func_800557C8(void*, int, int);
EXTERN_C void func_8005F120(void*, int);
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
EXTERN_C struct Unk_800DF32C* func_800787B4();
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
EXTERN_C int func_800BF66C(void*);
EXTERN_C Unk_800C0198* func_800C0198(Unk_800C0198*, void*, int, void*, int);
EXTERN_C int func_800C01F8(void*);
EXTERN_C void func_800C04A0(void*);
EXTERN_C void func_800C9D60(Unk_800C9D60*, int);
EXTERN_C void func_800C9E48(Unk_800C9D60*);
EXTERN_C int func_800C010C(struct Unk_800C0054*, int, int);
EXTERN_C void func_800CAAD4(void*, int);
EXTERN_C void func_800DB618(void*);
EXTERN_C int func_800E51F8(struct Unk_800E51EC*, void*);
EXTERN_C void func_800E556C();
EXTERN_C void func_800C0860(int);
EXTERN_C void func_800C1000(Unk_800C0814*);
EXTERN_C int func_800C1A74(Unk_800C0814*, int);
EXTERN_C void func_800C1AF0(Unk_800C0814*);
EXTERN_C void func_800C1BB8(Unk_800C0814*);
EXTERN_C void func_800C20B0(void*, int);
EXTERN_C void func_800C2A6C(void*, int);
EXTERN_C void func_800C3E00(Unk_800C3C08*);
EXTERN_C void func_800C5408(void*, void*);
EXTERN_C int func_800C9DD4(Unk_800C9D60*);
EXTERN_C void func_800C9FAC(void*);
EXTERN_C void func_800CA038(void*);
EXTERN_C void func_800CE820(void*);
EXTERN_C void func_800D29D8(void*, void*);
EXTERN_C void func_800D3D54(void*);
EXTERN_C void func_800D44D4(void*, void*);
EXTERN_C void func_800D9C84(void*, int);
EXTERN_C void func_800D9E4C(void*);
EXTERN_C void func_800E6EF0(void*);
EXTERN_C void func_800E75BC();

/* round 2 */
EXTERN_C void func_800BFE94(Unk_800BFE48*, int);
EXTERN_C void func_800C9E04(Unk_800C9D60*);
struct Unk_800CAD68_m : Unk_Pair, Unk_800BFB64_list { };
EXTERN_C int func_8005409C(void*);
struct Unk_Short2 { short x, y; };
struct Unk_800C9D90_sub : Unk_Pad50, VAt<8> { virtual int vf02(...); };
struct Unk_800C9D90 { char pad0[0x64]; Unk_800C9D90_sub* unk64; };
struct Unk_800BB1BC : VAt0 { char pad4[4]; short unk8; char padA[0x1E]; TILE unk28[2]; };
struct Unk_800BB1BC_arg { char pad0[8]; unsigned short unk8; };
struct Unk_800BFA54 { void* vtbl; char pad4[0x88]; void* unk8C; char pad90[0x68]; void* unkF8; char padFC[0x514]; void* unk610; };
EXTERN_C char D_800B706C[];
EXTERN_C char D_800B7054[];
EXTERN_C char D_800B7084[];
struct Unk_800DF6F0_obj : Unk_Deletable { int unk4; };
struct Unk_800DF6F0 { int unk0; Unk_800DF6F0_obj* unk4; };
inline Unk_800DF6F0_obj* head(Unk_800DF6F0* p) { return p->unk4; }
struct Unk_800E6A5C { char pad0[0x50]; int unk50; char pad54[0x55]; signed char unkA9; };
struct Unk_800C4F50 { char pad0[0x28]; SPRT unk28[2]; TILE unk50[2]; };
struct Unk_800E9D04 { char pad0[0x10]; SPRT unk10[0x90]; };
struct Unk_800DF938_obj { void* vtbl; int unk4; int unk8; int unkC; };
EXTERN_C char D_800171B0[];
EXTERN_C void func_8001A678(void*, void*);
struct Unk_800CE7AC : Unk_Pad50, VAt<8> { };
EXTERN_C void func_80055624(void*, int);
EXTERN_C void func_80062160(void*);
struct Unk_800D8CA4 { char pad0[0x6C]; void* unk6C; void* unk70; int unk74; };
struct Unk_800D90E8 : VAt<0x2C> { char pad30[8]; unsigned char unk38; };
EXTERN_C void* func_80019F64(void*, int);
struct Unk_800E4228_sub { int unk0; int unk4; };
struct Unk_800E4228 { int unk0; Unk_800E4228_sub* unk4; char pad8[0x2C]; int unk34; };
EXTERN_C void func_800356F4();
EXTERN_C int close(int);
struct Unk_800D4BFC { char pad0[0x28]; SPRT unk28[4]; };
struct Unk_Pad400 { char pad0[0x400]; };
struct C_800BD220 {
    void* vtbl; int unk4; short unk8; short unkA; signed char unkC; void* unk10; void* unk14; int unk18; int unk1C;
    signed char unk20; int unk24;
    C_800BD220(short, short, signed char);
};
struct Unk_800C6380_arg { char pad0[0x18]; unsigned short unk18; };
EXTERN_C int func_8005618C(void*);
EXTERN_C void func_800690C8(void*, void*);
EXTERN_C void func_80018AF4();
EXTERN_C int func_80094A20();
EXTERN_C void func_80018B18();
EXTERN_C void func_800E52D4(int, int);
struct Unk_800BDD8C_node { int unk0; struct Unk_800BDD8C_node* unk4; char pad8[4]; int unkC; };
struct Unk_800BDD8C { char pad0[0x101]; signed char unk101; char pad102[0x332]; Unk_800BDD8C_node* unk434; };
inline int active(Unk_800BDD8C* p) { return p->unk101; }
EXTERN_C signed char func_800BF5F4(Unk_800BF488*);
struct Unk_800C1A74_sub { char pad0[0x20]; int unk20; };
struct Unk_800C1A74 : VAt<0x18> { char pad1C[0x20]; Unk_800C1A74_sub* unk3C; char pad40[0x2C]; Unk_800C9D60 unk6C; };
EXTERN_C int func_800C9EE8(Unk_800C9D60*);
struct Unk_800D7AF0 { char pad0[0x108]; Unk_Deletable18* unk108; };

#endif /* FIELD_FIELD_H */
