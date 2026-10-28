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
template <class H> struct VWith : H { VSLOTS };

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
EXTERN_C int func_800BB5E8(void*, unsigned char*);
EXTERN_C int func_800BC394(void*);
struct Unk_800BC500;
EXTERN_C int func_800BC500(Unk_800BC500*, int);
EXTERN_C int func_800BC18C(Unk_800BCBE8*);
EXTERN_C int func_800BC1E8(Unk_800BCBE8*);
EXTERN_C int func_800BC228(void*);
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
struct Unk_800E556C;
EXTERN_C void func_800E556C(Unk_800E556C*, void*);
EXTERN_C void func_800C0860(int);
EXTERN_C void func_800C1000(Unk_800C0814*);
EXTERN_C int func_800C1A74(Unk_800C0814*, int);
EXTERN_C void func_800C1AF0(Unk_800C0814*);
EXTERN_C void func_800C1BB8(Unk_800C0814*);
EXTERN_C void func_800C20B0(void*, int);
EXTERN_C void func_800C2A6C(void*, int);
EXTERN_C void func_800C3E00(Unk_800C3C08*);
EXTERN_C void* func_800C5408(void*, void*);
EXTERN_C int func_800C9DD4(Unk_800C9D60*);
EXTERN_C void func_800C9FAC(void*);
EXTERN_C void func_800CA038(void*);
struct Unk_800CE820;
EXTERN_C void func_800CE820(Unk_800CE820*);
EXTERN_C void* func_800D29D8(void*, void*);
struct Unk_800D3D54;
EXTERN_C void func_800D3D54(Unk_800D3D54*);
EXTERN_C void* func_800D44D4(void*, void*);
EXTERN_C void func_800D9C84(void*, int);
struct Unk_800D9E4C;
EXTERN_C void func_800D9E4C(Unk_800D9E4C*);
EXTERN_C void func_800E6EF0(void*);
EXTERN_C void func_800E75BC();

/* round 2 */
EXTERN_C void func_800CE758(Unk_Derived50*);
EXTERN_C int func_800C02FC(Unk_800C02FC*, int);
EXTERN_C int func_800C0320(Unk_800C02FC*, int);
EXTERN_C int func_800CAF84(Unk_800CAF84*, int);
EXTERN_C void func_800D6D44(Unk_800CD3C8*);
EXTERN_C void func_800C2A0C(Unk_800C2A0C*);
EXTERN_C void func_800C6CCC(Unk_800C6CCC*);
EXTERN_C void func_800C3AAC(Unk_800C3AAC*);
EXTERN_C void func_800CD3C8(Unk_800CD3C8*);
EXTERN_C void func_800C88D8(Unk_800C88D8*);
EXTERN_C void func_800D56C4(void*);
EXTERN_C void func_800D1078(void*);
EXTERN_C int func_800BCE40(void*);
EXTERN_C int func_800BCE90(void*);
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
struct Unk_800E52D4;
EXTERN_C void func_800E52D4(Unk_800E52D4*, int);
struct Unk_800BDD8C_node { int unk0; struct Unk_800BDD8C_node* unk4; char pad8[4]; int unkC; };
struct Unk_800BDD8C { char pad0[0x101]; signed char unk101; char pad102[0x332]; Unk_800BDD8C_node* unk434; };
inline int active(Unk_800BDD8C* p) { return p->unk101; }
EXTERN_C signed char func_800BF5F4(Unk_800BF488*);
struct Unk_800C1A74_sub { char pad0[0x20]; int unk20; };
struct Unk_800C1A74 : VAt<0x18> { char pad1C[0x20]; Unk_800C1A74_sub* unk3C; char pad40[0x2C]; Unk_800C9D60 unk6C; };
EXTERN_C int func_800C9EE8(struct Unk_800C9D90*, struct Unk_FlagArg*);
struct Unk_800D7AF0 { char pad0[0x108]; Unk_Deletable18* unk108; };
EXTERN_C void func_8008299C(void*, int, int, int, int, int, int);
EXTERN_C void func_80082E14(void*, int);
EXTERN_C int func_8005618C(void*);
EXTERN_C void func_800690C8(void*, void*);
EXTERN_C void func_80054F30(void*, int, void*, int);
struct Unk_Short4 { short x, y, z, w; Unk_Short4() {} Unk_Short4(short a, short b) { x = a; y = b; } Unk_Short4(const short& a, const short& b, const short& c, const short& d) { x = a; y = b; z = c; w = d; } };
struct Unk_FlagArg { char pad0[0x18]; unsigned short unk18; };
struct Unk_Fx { short v; short pad; };
EXTERN_C void func_800C0814(int, int);
EXTERN_C void func_800C0890(int);
struct Unk_800DF26C_obj { char pad0[0x18]; virtual ~Unk_800DF26C_obj(); virtual int vf01(...); virtual int vf02(...); };
struct Unk_800DF26C { char pad0[0x55C]; Unk_800DF26C_obj* unk55C; };
struct Unk_800C6E8C : VAt<0x18> { char pad1C[0xBC]; int unkD8; };
struct Unk_800A4534 { char pad0[0xC]; unsigned int unkC; char pad10[0x34]; char* unk44; };
EXTERN_C Unk_800A4534 D_800A4534;
EXTERN_C void func_8002456C(void*);
EXTERN_C void func_80024524(void*);
EXTERN_C void func_800D5F94(void*, int);
struct Unk_800DAD54 { char pad0[0x23A8]; int unk23A8[0x30]; };
EXTERN_C int func_800619F4(void*);
EXTERN_C void func_800691EC(void*, int, int);
EXTERN_C void func_80054CE4(void*);
struct Unk_800E522C { char pad0[0x40]; char* unk40; };
EXTERN_C int func_80094FD0(char*);
struct Unk_800BAC9C : VAt0 { char pad4[4]; short unk8; char padA[0x1A]; TILE unk24[2]; };
struct Unk_800BFD88_r { char pad0[0x1B8]; int unk1B8; unsigned short unk1BC; };
struct Unk_800BFD88 { char pad0[0x610]; Unk_800CAD68_m unk610; char pad61C[0x14]; Unk_800BFD88_r* unk630; };
struct Unk_800D8E4C : VAt<0x18> { char pad1C[0x58]; int unk74; };
inline int func_800CDA28_test(int f) { return (f & 0xC50) && !(f & 0x4000); }
struct Unk_800C6D2C { char pad0[0x64]; char unk64[0x74]; int unkD8; };
struct Unk_800C8938 { char pad0[0x68]; int unk68; char pad6C[0x454]; char unk4C0[4]; };
struct Unk_800CA9C4 : Unk_Pad50, Unk_Base { char pad54[8]; int unk5C; int unk60; int unk64; char pad68[0x1C]; Unk_800BFB64_list unk84; };
EXTERN_C void func_800CA9C4(Unk_800CA9C4*);
EXTERN_C void func_800CAA4C(Unk_800CA9C4*);
EXTERN_C int func_800CAD68(void*);
EXTERN_C void func_800538B4(unsigned char);
EXTERN_C void func_8002DA94(void*, void*);
struct Unk_800E27C0 { char pad0[0x84]; int unk84; char pad88[0xD0]; int unk158; char pad15C[0x2D24]; char unk2E80[4]; };
EXTERN_C int func_80062978(void*);
EXTERN_C void func_800C56B8(void*);
struct Unk_800C5EE0 { char pad0[0x22CC]; char unk22CC[0x8C]; char unk2358[0x154]; char unk24AC[0x78]; char unk2524[0xB4C]; char unk3070[4]; };
EXTERN_C void func_80094990();
EXTERN_C void func_800949A0();
EXTERN_C int CloseEvent(int);
EXTERN_C int D_800EA7B8[];
EXTERN_C int D_800EA7BC[];
EXTERN_C int D_800EA7C0[];
EXTERN_C int D_800EA7C4[];
struct Unk_Blk32 { short v[16]; };
struct Unk_800E5620 { char pad0[0x4C]; Unk_Blk32* unk4C; };
struct Unk_800C0270 { int unk0; void* unk4; char pad8[4]; int unkC; };
struct Unk_800C8384 { char pad0[8]; int unk8; char padC[0x10]; unsigned short unk1C; char pad1E[0x12]; Unk_800BFB64_list* unk30; };
EXTERN_C void func_8005C088(void*, void*, int);
EXTERN_C void* func_800D49D0(void*, int);
EXTERN_C void func_80053964(void*, int);
struct Unk_800E4448_st { short unk0; short pad2; int unk4; };
struct Unk_800E4448 { int unk0; Unk_800E4448_st* unk4; char pad8[0x2C]; int unk34; char pad38[0xC]; void* unk44; };
EXTERN_C int func_800E5554(struct Unk_800E51EC*);
EXTERN_C int read(int, void*, int);
EXTERN_C int write(int, void*, int);
typedef struct { int tag; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; } SPRT_16;
struct Unk_Sprt16_24 : VAt0 { char pad4[4]; short unk8; char padA[0x1A]; SPRT_16 unk24[2]; };
struct Unk_Pt { short x, y; Unk_Pt(short a, short b) { x = a; y = b; } };
EXTERN_C void func_8005C088(void*, void*, int);
EXTERN_C void func_8002DA94(void*, void*);
EXTERN_C void func_800CDEEC(void*);
struct Unk_Pad10 { char pad0[0x10]; };
struct Unk_800D5C60_arg { char pad0[0x1A]; unsigned short unk1A; };
EXTERN_C bool func_800557A0(void*);
struct Unk_800E6E64 { char pad0[0x3C]; void* unk3C; char pad40[0x10]; int unk50; char pad54[0x54]; signed char unkA8; signed char unkA9; };
struct Unk_800E714C; EXTERN_C Unk_800E714C* func_800E714C(Unk_800E714C*, int, int, int, unsigned short);
EXTERN_C void func_8005800C(void*, void*);
struct Unk_800C5734 { char pad0[0x68]; Unk_Elem28 unk68[4]; char padD8_[0]; };
EXTERN_C void func_8006897C(void*, unsigned short, int);
EXTERN_C int func_80068A5C(void*);
EXTERN_C void func_800631D4(void*);
struct Unk_800DF1DC : VAt<0x18> { };
struct Unk_800DF1DC_p { char pad0[0x55C]; Unk_800DF1DC* unk55C; };
EXTERN_C void func_80053F48(void*, Unk_Pt);
EXTERN_C void func_8007EDAC(void*, int, int);
struct Unk_W4 { int a, b, c, d; };
struct Unk_800BFC58_s { char pad0[0x34]; Unk_W4 unk34; };
struct Unk_800BFC58_r { char pad0[0x1B8]; Unk_800BFC58_s* unk1B8; };
struct Unk_800BFC58 { char pad0[0x610]; Unk_800CAD68_m unk610; char pad61C[0x14]; Unk_800BFC58_r* unk630; };
struct Unk_800CCFCC { char pad0[0x20]; int unk20; char pad24[0x18]; void* unk3C; };
EXTERN_C void func_80058270(void*, int);
EXTERN_C int func_80058404(void*, int);
struct Unk_800CDE70 { char pad0[0x50]; int unk50; char pad54[4]; char unk58[4]; };
EXTERN_C char D_800B85F4[];
EXTERN_C char D_800B8608[];
EXTERN_C char D_800B8618[];
struct Unk_800D915C { char pad0[8]; int unk8; char unkC[0x10]; unsigned short unk1C; char pad1E[0x12]; Unk_800BFB64_list* unk30; char pad34[4]; unsigned char unk38; };
EXTERN_C void* func_800D9300(void*, int, void*, int);
struct Unk_800BCDB0 { void* vtbl; int unk4; short unk8; short unkA; int unkC; int unk10; };
EXTERN_C int D_800AF410[];
EXTERN_C int D_800AF40C[];
EXTERN_C void func_8006F154();
struct Unk_E16 { char pad0[0xD]; unsigned char unkD; unsigned char unkE; char padF; };
struct Unk_800D3D54 : Unk_Pad10, Unk_Base { char pad14[8]; int unk1C; char pad20[0xF0]; Unk_E16 unk110[2]; };
EXTERN_C void func_8008687C(Unk_Base*, int);
struct Unk_Ent400 : Unk_Pad400, Unk_Base { char pad404[0xC]; unsigned short unk410; unsigned short unk412; char pad414[0xC]; unsigned short unk420; unsigned short unk422; };
struct Unk_EntTab { int unk0; int unk4; void* unk8[1]; };
struct Unk_EntTabObj : Unk_PadB8, Unk_EntTab { };
struct Unk_EntOwner { char pad0[0x328]; Unk_EntTabObj* unk328; };
inline Unk_EntTab* base(Unk_EntTabObj* o) { return o; }
EXTERN_C Unk_EntOwner* D_800AF470[];
struct Unk_800D5EFC { char pad0[0x3C]; void* unk3C; char pad40[0xAF8]; unsigned int unkB38; int unkB3C; };
EXTERN_C void func_8005816C(void*, int);
struct Unk_800DFB10 { char pad0[0x3C]; VAt<0x18>* unk3C; };
EXTERN_C void func_8007E47C(void*);
EXTERN_C VAt<0x18>* func_800DFC8C(void*, int, void*, int, int);
struct Unk_800E31B8 { char pad0[0x6C]; int unk6C; };
struct Unk_800E8B9C { char pad0[0xFC]; Unk_Deletable18* unkFC; };
EXTERN_C int func_80063744(void*, int);
EXTERN_C void func_800E8C34(void*);
struct Unk_Sprt16_24c : VAt0 { char pad4[4]; short unk8; char padA[0x1A]; SPRT_16 unk24[2]; };
struct Unk_800BF2C0_src { int unk0; int unk4; signed char unk8; signed char unk9; short unkA; short unkC; };
struct C_800BF2C0 {
    void* vtbl; int unk4; int unk8; int unkC; signed char unk10; signed char unk11; short unk12; short unk14; short pad16;
    void* unk18; int unk1C;
    C_800BF2C0(Unk_800BF2C0_src*);
};
struct Unk_800BFCEC_r { char pad0[0x1B8]; Unk_800BFC58_s* unk1B8; };
struct Unk_800BFCEC { char pad0[0x610]; Unk_800CAD68_m unk610; char pad61C[0x14]; Unk_800BFCEC_r* unk630; };
EXTERN_C void func_80039DD8(void*);
EXTERN_C void func_800C7984(void*);
EXTERN_C void func_800C7890(void*);
struct Unk_800C1120_e : Unk_Pad400, VAt<0x9C> { virtual int vf09(...); };
EXTERN_C int D_800B4D5C[];
EXTERN_C int D_800EA0B4[];
struct Unk_Short4v { short x, y, z, w; Unk_Short4v(short a, short b, short c, short d) { x = a; y = b; z = c; w = d; } };
EXTERN_C void func_80043D38(void*, Unk_Short4v);
struct Unk_800D9E4C { char pad0[0x38]; void* unk38; Unk_Deletable* unk3C; };
EXTERN_C void func_8005F5F4(void*, void*, int);
EXTERN_C void func_800215E8(int, void*);
EXTERN_C int D_800B4C38[];
struct Unk_Pad4 { int pad0; };
struct Unk_List2 { Unk_800BFB64_node* head; };
inline Unk_800BFB64_node* first2(Unk_List2* l) { return l ? l->head : 0; }
struct Unk_DualList : Unk_800BFB64_list, Unk_Pad4, Unk_List2 { };
EXTERN_C void func_80019C68(void*, int);
struct Unk_800C497C { char pad0[8]; int unk8; char padC_[0]; short unkC; short unkE; char pad10[0x20]; Unk_DualList* unk30; };
struct Unk_800C4C04_h { char pad0[8]; int unk8; char padC[0x20]; };
struct Unk_800C4C04 : VWith<Unk_800C4C04_h> { Unk_DualList* unk30; };
struct Unk_800CAEE4 { char pad0[0x84]; Unk_DualList unk84; };
struct Unk_Blk2B0 { char v[0x2B0]; };
EXTERN_C Unk_Blk2B0 D_800EA2E8;
struct Unk_Blk40 { char v[0x40]; };
struct Unk_800E56B4 { char pad0[0x48]; Unk_Blk40* unk48; };
struct Unk_Blk80 { char v[0x80]; };
struct Unk_800E5760 { char pad0[0x44]; Unk_Blk80* unk44; };
EXTERN_C Unk_Short2 func_800BE0C8(void*, short);
EXTERN_C void func_800BE264(void*, Unk_Short2);
struct Unk_W2 { int a, b; };
struct Unk_W3 { int a, b, c; };
struct Unk_Dr12 { int tag; Unk_W2 body; };
struct Unk_Dr16 { int tag; Unk_W3 body; };
struct Unk_Hdr38 { char pad0[8]; int unk8; char unkC[0x10]; unsigned short unk1C; char pad1E[0x12]; Unk_800BFB64_list* unk30; char pad34[4]; };
struct Unk_800BF8AC { void* vtbl; int unk4; void* vtbl8; };
EXTERN_C char D_800B6F8C[];
EXTERN_C char D_800B6FF4[];
EXTERN_C char D_80011C44[];
EXTERN_C char D_80011CAC[];
EXTERN_C char D_80011B8C[];
EXTERN_C char D_80011BF4[];
EXTERN_C char D_80011AAC[];
EXTERN_C char D_80011B14[];
EXTERN_C void func_800198AC(void*, int);
EXTERN_C char D_800B77A4[];
EXTERN_C char D_800B77B4[];
EXTERN_C char D_800B77C0[];
EXTERN_C char D_800B77D4[];
struct Unk_800D7F10_o : VAt<0x18> { };
struct Unk_800D7F10 { char pad0[0xDC]; Unk_800D7F10_o* unkDC; };
EXTERN_C char D_800EA76C[];
EXTERN_C void func_800538CC(void*, void*, int);
EXTERN_C Unk_800D7F10_o* func_800D82E0(void*, void*, int, int);
EXTERN_C void func_80053964(void*, int);
struct Unk_800E4620 { int unk0; Unk_800E4448_st* unk4; char pad8[0x2C]; int unk34; int unk38; int unk3C; };
EXTERN_C int func_800E4B10(void*);
EXTERN_C int _card_format(int);
struct Unk_800E99C4 : Unk_Hdr38, Unk_Base { char pad3C[8]; void* unk44; };
EXTERN_C void* func_800E9A68(void*, void*, int);
EXTERN_C Unk_Short2 func_800BE0C8(void*, short);
EXTERN_C void func_800BE264(void*, Unk_Short2);
EXTERN_C void* func_800CA1CC(void*, int, Unk_Pt);
EXTERN_C void func_8002B174(void*, void*, int);
EXTERN_C void func_800CA7A0(void*);
struct Unk_C5 { char c[5]; };
struct Unk_C12 { char c[12]; };
struct Unk_C8 { char c[8]; };
struct Unk_800E556C { char pad0[0x38]; int unk38; char pad3C[4]; Unk_C12* unk40; };
EXTERN_C char D_800BA090[];
EXTERN_C char D_800BA098[];
EXTERN_C char D_800EA7CD[];
struct Unk_V3 { int x, y, z, pad; };
struct Unk_800BED4C_e { int a[3]; int pad; int b[3]; char pad1C[0xC]; };
struct Unk_800BED4C { char pad0[0x28C]; short unk28C; char pad28E[0x26]; Unk_800BED4C_e unk2B4[1]; };
EXTERN_C void VectorNormal(void*, void*);
struct Unk_800CC28C;
EXTERN_C void* func_800CC28C(Unk_800CC28C*, void*, int, void*, int);
struct Unk_Tbl { void** unk0; int unk4; };
struct Unk_TblIt { Unk_Tbl* unk0; int unk4; };
inline void* next(Unk_TblIt* it) {
    if (it->unk4 < it->unk0->unk4) {
        void** a = it->unk0->unk0;
        return a[it->unk4++];
    }
    return 0;
}
struct Unk_GrpNode { int unk0; struct Unk_GrpNode* unk4; char pad8[4]; Unk_TblIt unkC; char pad14[0x1C]; short unk30; };
struct Unk_GrpList { int unk0; Unk_GrpNode* unk4; };
struct Unk_GrpOwner { char pad0[0x450]; Unk_GrpList unk450; };
struct Unk_Flag48 { char pad0[0x48]; int unk48; };
struct Unk_Hdr38d { char pad0[8]; int unk8; char unkC[0x10]; unsigned short unk1C; char pad1E[0x12]; Unk_DualList* unk30; char pad34[4]; };
EXTERN_C void func_80056D60(void*, int);
struct Unk_Elem50 { char pad0[0x50]; };
struct Unk_800C9424 { char pad0[0x70]; Unk_Elem50 unk70[13]; char pad[0x0]; };
struct Unk_800C9424p { char pad0[0x4B0]; VAt<0x2C>* unk4B0; VAt<0x2C>* unk4B4; int unk4B8; int unk4BC; };
EXTERN_C void func_80054054(void*, void*);
EXTERN_C void func_80063BE4(void*);
EXTERN_C void func_80063B14(void*, void*, int);
struct Unk_800DF604_o { char pad0[0x2C]; Unk_Short4v unk2C; Unk_W4 unk34; };
struct Unk_800DF604 { char pad0[0xC]; Unk_800DF604_o* unkC; };
struct Unk_800C8F34_g2 { char pad0[0x18]; unsigned short unk18; };
struct Unk_800C8F34_g { char pad0[0x120]; Unk_800C8F34_g2* unk120; };
struct Unk_800C8F34 : VAt<0x18> { char pad1C[0x50]; int unk6C; char pad70[0x444]; void* unk4B4; };
struct Unk_Hdr2C { char pad0[8]; int unk8; char padC[0x20]; };
struct Unk_800D0704 : VWith<Unk_Hdr2C> { Unk_DualList* unk30; };
struct Unk_800BF520_o { void* vtbl; int unk4; short unk8; short unkA; };
struct Unk_800BF520 { char pad0[0xA]; short unkA; Unk_800BF520_o* unkC; };
EXTERN_C char D_800106EC[];
EXTERN_C char D_80010624[];
EXTERN_C void func_80021F48(void*, int);
struct Unk_800C7EC8 : Unk_Hdr38, Unk_Base { char pad3C[8]; void* unk44; };
EXTERN_C char D_800B4C98[];
EXTERN_C VAt0* func_800D35F8(void*, void*, void*, int);
struct Unk_800BD62C { void* vtbl; char pad4[0x88]; void* unk8C; char pad90[0x68]; void* unkF8; char padFC[0x2EC]; char unk3E8[0x28]; char unk410[0x20]; char unk430[0x10]; char unk440[0x10]; char unk450[0x44]; char unk494[0x14C]; void* unk5E0; };
EXTERN_C char D_800B6F0C[];
EXTERN_C char D_800B6EF4[];
EXTERN_C char D_800B6F24[];
EXTERN_C void func_80051514(void*, int);
EXTERN_C void func_8001E508(void*, int);
EXTERN_C void* D_800EA2DC[];
EXTERN_C Unk_Deletable* D_800EA2E4[];
struct Unk_S3 { short r, g, b; };
struct Unk_800E84D4 { char pad0[0x6C]; int unk6C; void* unk70; void* unk74; };
EXTERN_C void* func_80054AF0(void*, int);
EXTERN_C void* func_80053928(void*);
EXTERN_C void func_80054E18(void*, void*);
struct Unk_800C16DC_g { char pad0[0x1FD]; signed char unk1FD; };
struct Unk_800C16DC : VAt<0x18> { char pad1C[0x93C]; char unk958[0x6050]; char unk69A8[0x6F8]; void* unk70A0; };
EXTERN_C void func_80054F5C(void*);
struct Unk_800BC640;
EXTERN_C void func_800BC640(Unk_800BC640*);
struct Unk_800BBE68;
EXTERN_C int func_800BBE68(Unk_800BBE68*);
EXTERN_C int func_800BC2B0(void*);
struct Unk_800BCAFC { char pad0[0x654]; int unk654; char pad658[0x10]; int unk668; };
struct Unk_800C3B0C { char pad0[0x6C]; char unk6C[0x70]; VAt<0x2C>* unkDC; };
EXTERN_C VAt<0x2C>* func_800C3E40(void*, int);
EXTERN_C void func_800C41E0(void*, unsigned char, int, int);
struct Unk_800C89BC_e : VAt<0x18> { char pad1C[0x34]; };
struct Unk_800C89BC { char pad0[0x6C]; int unk6C; Unk_800C89BC_e unk70[8]; char pad2F0[0x1C0]; void* unk4B0; char pad4B4[0xC]; char unk4C0[0xA4]; char unk564[4]; };
EXTERN_C void func_80061058(void*);
EXTERN_C char D_800B8694[];
EXTERN_C char D_800B8664[];
struct Unk_800D09E8 { char pad0[8]; int unk8; short unkC; short unkE; short unk10; short unk12; char pad14[0x1C]; Unk_DualList* unk30; };
struct Unk_800D5CEC : VAt<0x18> { char pad1C[0x20]; char* unk3C; };
EXTERN_C void _bu_init();
EXTERN_C int OpenEvent(unsigned int, int, int, int (*)());
EXTERN_C int func_800E382C();
EXTERN_C int func_800E38A4();
EXTERN_C int func_800E391C();
EXTERN_C int func_800E3994();
struct Unk_800DCB4C { char pad0[0x3E8]; VAt<0x2C>* unk3E8; };
EXTERN_C VAt<0x2C>* func_80056E0C(void*, int);
EXTERN_C void func_8006BDE0(void*);
EXTERN_C void* D_800B4ED8[];
EXTERN_C void* D_800EA1E0[];
EXTERN_C void* D_800EA1E4[];
EXTERN_C Unk_Deletable* D_800EA1E8[];
EXTERN_C void* D_800EA888[];
EXTERN_C Unk_Deletable* D_800EA88C[];
struct Unk_800CECA8_e : Unk_Pad400, Unk_Base { char pad404[0xC]; short unk410; short unk412; };
struct Unk_800BFB84 { char pad0[0x610]; Unk_DualList unk610; char pad61C[0x14]; Unk_800BFC58_r* unk630; };
inline Unk_W4 get_800BFB84(Unk_W4* w) { int a = w->a, b = w->b, c = w->c, d = w->d; Unk_W4 t; t.a = a; t.b = b; t.c = c; t.d = d; return t; }
struct Unk_800E9820 : Unk_Hdr38d, Unk_Base { };
EXTERN_C int func_80053874(Unk_Base*);
EXTERN_C int func_80053830(Unk_Base*);
inline void* Unk_800E9820_at(Unk_800BFB64_node* n, unsigned int i) { return i < n->unk4 ? ((void**)n->unk0)[i] : 0; }
struct Unk_800D3DE8 { char pad0[0x50]; SPRT unk50[10]; SPRT_16 unk118[0x60]; SPRT_16 unk718[2]; };
EXTERN_C void func_80053CD8(void*);
EXTERN_C void func_80053DDC(void*, void*);
EXTERN_C char D_800B9F28[];
EXTERN_C char D_800B9F34[];
EXTERN_C void func_800C206C(Unk_800C206C*, unsigned char);
struct Unk_800C20B0_h : Unk_Base { int unk4; };
struct Unk_800C20B0 : Unk_Pad50, VWith<Unk_800C20B0_h> { int unk5C; int unk60; int unk64; char pad68[0x40]; void* unkA8; };
struct Unk_800CED70_q { char pad0[0x1B]; unsigned char unk1B; };
EXTERN_C int func_8008A5C8(void*, void*, void*);
struct Unk_Ent400s : Unk_Pad400, Unk_Base { char pad404[0xC]; short unk410; short unk412; char pad414[0xC]; short unk420; short unk422; };
struct Unk_800C2EB8 { char pad0[0x68]; short unk68; short unk6A; Unk_Deletable18* unk6C; char unk70[4]; char unk74[0xDC]; char unk150[4]; };
EXTERN_C void func_80069958(void*);
struct Unk_800E1174_e : VAt<0x18> { char pad1C[0x260]; };
struct Unk_800E1174 { char pad0[0x1C]; Unk_800BFB64_list unk1C; char pad20[0x64]; int unk84; char pad88[0xD0]; int unk158; char pad15C[0xE8]; Unk_800E1174_e unk244[15]; };
EXTERN_C void* func_800550BC(void*);
EXTERN_C int func_80054D78(void*);
EXTERN_C int D_800B4D90[];
struct Unk_800D04E4 { char pad0[8]; int unk8; short unkC; short unkE; short unk10; short unk12; char pad14[0x1C]; Unk_DualList* unk30; };
EXTERN_C void func_800CC534(void*, int);
struct Unk_800C1000 { char pad0[0x68]; int unk68; Unk_800C9D60 unk6C; char padD4[0x168]; Unk_DualList unk23C; char pad248[0x6E58]; void* unk70A0; };
EXTERN_C void func_800C9D20(Unk_800C9D60*);
EXTERN_C void func_800CF830();
EXTERN_C void func_800D0248();
struct Unk_800CD554 : VAt<0x18> { Unk_800BFB64_list unk1C; int unk20; char pad24[0x44]; char unk68[4]; };
EXTERN_C Unk_Short2* func_80054F28(void*);
EXTERN_C void func_80063714(void*, int);
struct Unk_Blk8D { signed char v[0x8D]; };
EXTERN_C Unk_Blk8D D_800EA148;
EXTERN_C void func_8005F238(void*);
EXTERN_C void func_8005F298(void*, int, int);
EXTERN_C void* func_8005F28C(void*);
EXTERN_C void func_8005F3E0(void*);
EXTERN_C void func_8005F248(void*, int);
struct Unk_Ot { char pad0[0x10]; unsigned int unk10; unsigned int* unk14; };
EXTERN_C Unk_Ot* D_800B4CFC[];
struct Unk_800BC640_l { int unk0; Unk_Deletable* unk4; };
struct Unk_800BC640 { char pad0[0x3D8]; short unk3D8; short unk3DA; char pad3DC[0xC]; Unk_800BC640_l unk3E8; char pad3F0[0x20]; Unk_800BC640_l unk410; char pad418[0x18]; Unk_800BC640_l unk430; char pad438[8]; Unk_800BC640_l unk440; char pad448[8]; Unk_800BC640_l unk450; };
inline void clear(Unk_800BC640_l* l) {
    if (l->unk4) {
        delete l->unk4;
        l->unk4 = 0;
    }
}
struct Unk_800E52D4 { int unk0; Unk_800E4448_st* unk4; char pad8[4]; Unk_800BFB64_list unkC; char pad10[0x1C]; VAt0* unk2C; int unk30; };
struct Unk_800E3F04 { void* vtbl; char pad4[4]; void* vtbl8; char padC[0x18]; void* vtbl24; char pad28[0x18]; void* unk40; void* unk44; };
EXTERN_C char D_800BA0E0[];
EXTERN_C char D_800BA0B8[];
EXTERN_C char D_800BA0F8[];
EXTERN_C char D_80012074[];
EXTERN_C char D_8001208C[];
EXTERN_C char D_800120B4[];
EXTERN_C int D_800EA7B4[];
EXTERN_C int DisableEvent(int);
EXTERN_C void func_80035B28(void*, int);
EXTERN_C void func_80035304(void*, int);
struct Unk_800E7384 { char pad0[8]; int unk8; Unk_Short2 unkC; char pad10[0xC]; unsigned short unk1C; char pad1E[0x12]; Unk_800BFB64_list* unk30; char pad34[4]; unsigned int unk38; char* unk3C; };
EXTERN_C void* func_800E7870(void*, int, void*, int);
struct Unk_800BB33C_t { char pad0[0x60]; int unk60; };
struct Unk_800BB33C { void* vtbl; char pad4[0x88]; void* unk8C; char pad90[0x68]; void* unkF8; char padFC[0x570]; Unk_800BB33C_t* unk66C; char pad670[4]; Unk_800BB33C_t* unk674; };
EXTERN_C char D_800B6E9C[];
EXTERN_C char D_800B6E84[];
EXTERN_C char D_800B6EB4[];
EXTERN_C void func_80036D8C(void*);
struct Unk_800CC454_q { short x0, y0, x1, y1, x2, y2, x3, y3; };
EXTERN_C char D_800BA268[];
struct Unk_800E5FC4_r { Unk_Pt pos; short w, h; };
struct C_800E5FC4 { char pad0[0x18]; void* vtbl18; char pad1C[0x34]; int unk50; int unk54; int unk58; C_800E5FC4(int, Unk_800E5FC4_r*); };
EXTERN_C int func_800CEC9C(Unk_800CEC9C*);
struct Unk_800C1C80_e : Unk_Pad400, VAt<0x9C> { virtual int vf03(...); virtual int vf09(...); };
struct Unk_800C7984 : Unk_Hdr38d, Unk_Base { char pad3C[8]; int unk44; int unk48; };
struct Unk_800C7984_g { char pad0[0x1FD]; signed char unk1FD; };
#ifndef UNK_VTBL10_DEFINED
#define UNK_VTBL10_DEFINED
struct Unk_VEnt { short delta; short index; void (*pfn)(void*); };
struct Unk_VTbl10 { Unk_VEnt e[10]; };
struct Unk_VBase { Unk_VTbl10* vptr; };
struct Unk_VbDtor2C { Unk_VBase* vb0; char pad4[0x28]; void* vt2C; };
EXTERN_C void func_8005BDA4(void*, int);
#endif
EXTERN_C const Unk_VTbl10 D_800B7F1C;
EXTERN_C char D_800B7F6C[];
#ifndef UNK_VTBL10_DEFINED
#define UNK_VTBL10_DEFINED
struct Unk_VEnt { short delta; short index; void (*pfn)(void*); };
struct Unk_VTbl10 { Unk_VEnt e[10]; };
struct Unk_VBase { Unk_VTbl10* vptr; };
struct Unk_VbDtor2C { Unk_VBase* vb0; char pad4[0x28]; void* vt2C; };
EXTERN_C void func_8005BDA4(void*, int);
#endif
EXTERN_C const Unk_VTbl10 D_800B87D4;
EXTERN_C char D_800B8824[];
#ifndef UNK_VTBL10_DEFINED
#define UNK_VTBL10_DEFINED
struct Unk_VEnt { short delta; short index; void (*pfn)(void*); };
struct Unk_VTbl10 { Unk_VEnt e[10]; };
struct Unk_VBase { Unk_VTbl10* vptr; };
struct Unk_VbDtor2C { Unk_VBase* vb0; char pad4[0x28]; void* vt2C; };
EXTERN_C void func_8005BDA4(void*, int);
#endif
EXTERN_C const Unk_VTbl10 D_800B928C;
EXTERN_C char D_800B92DC[];
#ifndef UNK_VTBL10_DEFINED
#define UNK_VTBL10_DEFINED
struct Unk_VEnt { short delta; short index; void (*pfn)(void*); };
struct Unk_VTbl10 { Unk_VEnt e[10]; };
struct Unk_VBase { Unk_VTbl10* vptr; };
struct Unk_VbDtor2C { Unk_VBase* vb0; char pad4[0x28]; void* vt2C; };
EXTERN_C void func_8005BDA4(void*, int);
#endif
EXTERN_C const Unk_VTbl10 D_800B7D04;
EXTERN_C char D_800B7C0C[];
EXTERN_C void func_800D48FC();
struct Unk_800E6F14 { char pad0[0x76]; unsigned char unk76; char pad77; unsigned char unk78; char pad79[3]; unsigned char unk7C; char pad7D; unsigned char unk7E; char pad7F[3]; unsigned char unk82; char pad83; unsigned char unk84; };
struct Unk_800D8D18 { char pad0[0x64]; unsigned int unk64; unsigned int unk68; char pad6C[4]; void* unk70; int unk74; };
EXTERN_C void func_8005556C(int, int);
struct Unk_800E5B90 : VAt<0x18> { char pad1C[0x4C]; Unk_800E07FC* unk68; void* unk6C; char unk70[0x50]; char unkC0[4]; };
EXTERN_C char D_800BA138[];
EXTERN_C char D_800BA160[];
struct Unk_C20A { char c[0x20A]; };
EXTERN_C Unk_C20A D_800EA598;
struct Unk_800E60C8 { char pad0[0x3C]; void* unk3C; char pad40[0x10]; int unk50; int unk54; void* unk58; };
EXTERN_C void* func_800646FC(void*, int, void*, int);
EXTERN_C void func_80064884(void*, int, int);
EXTERN_C void func_800CAFE0(void*);
EXTERN_C void func_800CB74C(void*);
EXTERN_C void func_800CB418(void*);
EXTERN_C void func_800CBA70(void*);
struct Unk_800DB7E8_e { char pad0[0x1B]; unsigned char unk1B; char pad1C[0x78]; };
struct Unk_800DB7E8 { char pad0[0x1C]; Unk_800BFB64_list unk1C; char pad20[0x4C]; Unk_Elem28* unk6C; Unk_800DB7E8_e* unk70; };
struct Unk_800DB7E8_a { char pad0[0x18]; unsigned char unk18; char pad19[2]; unsigned char unk1B; };
struct Unk_800D3C50_e { char pad0[0xC]; unsigned char unkC; unsigned char unkD; unsigned char unkE; char padF; };
struct Unk_800D3C50 : Unk_Pad10, Unk_Base { char pad14[8]; int unk1C; char pad20[0xF0]; Unk_800D3C50_e unk110[1]; };
struct Unk_800CC754_s { char pad0[0xC]; VAt0* unkC; short unk10; short unk12; char pad14[8]; unsigned short unk1C; };
struct Unk_800CC754_uv { unsigned char u, v; Unk_800CC754_uv(int x, int y) { u = x; v = y; } };
struct Unk_800CC754 : Unk_Ft4_10 { char pad60_[0x60 - 0x10 - sizeof(POLY_FT4)]; unsigned short unk60; };
EXTERN_C unsigned int func_8005F87C(void*);
struct Unk_800C47B0_e { char pad0[0x54A]; unsigned char unk54A; unsigned char unk54B; };
struct Unk_800C47B0 : Unk_Pad38, Unk_Base { char pad3C[8]; int unk44; unsigned char unk48; char pad49; short unk4A; short unk4C; };
inline Unk_800C47B0_e* ent_800C47B0(Unk_EntTabObj* o, int i) { return (Unk_800C47B0_e*)base(o)->unk8[i]; }
EXTERN_C VAt0* func_8001ED2C(void*, int, int);
EXTERN_C void* D_800B4C18[];
EXTERN_C int TestEvent(int);
struct Unk_800E5404_e : VAt0 { char pad4[6]; unsigned short unkA; VAt0* unkC; };
struct Unk_800E5404 { char pad0[0x30]; int unk30; };
struct Unk_VtEnt_800D17EC { short delta; short index; void* pfn; };
struct Unk_Vt10_800D17EC { Unk_VtEnt_800D17EC e[10]; };
struct Unk_VBase_800D17EC { Unk_Vt10_800D17EC* vptr; };
EXTERN_C Unk_Vt10_800D17EC D_800B8A64;
EXTERN_C char D_800B8AD4[];
EXTERN_C char D_800B8AB4[];
EXTERN_C char D_800B8B04[];
EXTERN_C void func_8005652C(void*, int);
struct Unk_800D17EC { char pad0[0x18]; void* unk18; char pad1C[0x34]; Unk_VBase_800D17EC* unk50; void* unk54; void* unk58; };
struct Unk_800BBE68_q { char pad0[8]; unsigned char unk8; unsigned char unk9; char padA[2]; char unkC[4]; };
struct Unk_800BBE68_r { char pad0[0x254]; void* unk254; };
struct Unk_800BBE68 { char pad0[0x100]; char unk100; char unk101; char pad102[0x176]; Unk_800BBE68_r* unk278; char pad27C[0x16C]; char unk3E8[0x28]; char unk410[0x20]; char unk430[0x10]; char unk440[0x10]; Unk_GrpList unk450; char pad458[0x84]; Unk_800BBE68_q* unk4DC; char pad4E0[0x170]; int unk650; };
EXTERN_C void func_800BD84C(void*, void*, void*, void*, void*, void*);
EXTERN_C void func_800BB81C(Unk_800BB81C*);
EXTERN_C void func_800BED4C(Unk_800BED4C*);
EXTERN_C void func_800BEB2C(void*);
EXTERN_C void func_800BF0E0(void*);
EXTERN_C void func_800BE470(void*, void*);
EXTERN_C void func_800BDEA4(void*, void*);
inline Unk_GrpNode* next_800BBE68(Unk_GrpNode* n) { return n->unk4; }
struct Unk_800D122C { char pad0[0x68]; int unk68; char pad6C[4]; void* unk70; void* unk74; void* unk78; int unk7C; };
EXTERN_C void func_8002972C(void*, int, int, int, int);
inline void* at0(Unk_Tbl* t) { return t->unk4 ? t->unk0[0] : 0; }
struct Unk_800BC500 { char pad0[0x5E0]; Unk_DualList unk5E0; };
EXTERN_C void func_80019CFC(void*, void*);
struct Unk_800E61D8_blk { char v[0xA0]; };
EXTERN_C Unk_800E61D8_blk D_800EA7E8;
struct Unk_800CF028 { char pad0[0x20]; int unk20; char pad24[0x18]; char* unk3C; char pad40[0x18C]; int unk1CC; };
struct Unk_800D2214_o : VAt0 { char pad4[4]; unsigned short unk8; };
struct Unk_800D2214_q { char pad0[0xC]; Unk_800D2214_o* unkC; short unk10; short unk12; char pad14[8]; unsigned short unk1C; };
struct Unk_800D2214_uv { unsigned char u, v; short al[0]; Unk_800D2214_uv(int a, int b) { u = a; v = b; } };
struct Unk_800D2214 : Unk_Drawable { char pad4[0xC]; POLY_GT4 unk10[2]; char pad78[0x30]; Unk_800D2214_uv unkA8; };
struct Unk_W5_800D4CC0 { int a, b, c, d, e; };
struct Unk_800D4CC0 { void* vtbl; int unk4; short unk8; short unkA; int unkC; Unk_W3 unk10[2]; Unk_W5_800D4CC0 unk28[4]; };
EXTERN_C char D_80014BD0[];
EXTERN_C char D_800B8EC4[];
struct Unk_W5_800E9DC8 { int a, b, c, d, e; };
struct Unk_800E9DC8 { void* vtbl; int unk4; short unk8; short unkA; int unkC; Unk_W5_800E9DC8 unk10[0x90]; Unk_W3 unkB50[2]; };
EXTERN_C char D_800BA798[];
EXTERN_C char D_80014BD0[];
struct Unk_Vt50_800CDAAC { int pad0[2]; short d8; short padA; int padC[9]; short d30; short pad32; int pad34[7]; };
struct Unk_800CDAAC_vb { void* vtbl; };
struct Unk_800CDAAC { char pad0[0x18]; void* unk18; char pad1C[0x34]; Unk_800CDAAC_vb* unk50; void* unk54; void* unk58; };
EXTERN_C char D_800B856C[];
EXTERN_C char D_800B854C[];
EXTERN_C char D_800B859C[];
EXTERN_C Unk_Vt50_800CDAAC D_800B84FC;
EXTERN_C void func_80069264(void*, int);
struct Unk_Vt50_800D8ECC { int pad0[2]; short d8; short padA; int padC[9]; short d30; short pad32; int pad34[7]; };
struct Unk_800D8ECC_vb { void* vtbl; };
struct Unk_800D8ECC { char pad0[0x18]; void* unk18; char pad1C[0x34]; Unk_800D8ECC_vb* unk50; void* unk54; void* unk58; };
EXTERN_C char D_800B921C[];
EXTERN_C char D_800B91FC[];
EXTERN_C char D_800B924C[];
EXTERN_C Unk_Vt50_800D8ECC D_800B91AC;
EXTERN_C void func_8005652C(void*, int);
struct Unk_800DF82C { char pad0[0x10]; Unk_800E83B8* unk10; };
struct Unk_800DF82C_t { int w[0x3E]; };
EXTERN_C void func_80074564(void*);
EXTERN_C Unk_800E83B8* func_800E7DEC(void*, int, int, int);
EXTERN_C void func_8001E40C(void*, void*, int, int, int);
struct Unk_800DF4F4_o { void* vtbl; int unk4; void* unk8; };
struct Unk_800DF4F4 { void* vtbl; char pad4[8]; void* unkC; };
EXTERN_C char D_800171D0[];
EXTERN_C char D_800127E4[];
EXTERN_C int D_800B4D28[];
EXTERN_C int D_800B4D30[];
EXTERN_C void func_80039C88(void*, void*);
struct Unk_800C807C { Unk_VBase* vb0; char pad4[0x28]; void* vt2C; char pad30[8]; Unk_800BCFD0 unk38; };
EXTERN_C char D_800104A8[];
EXTERN_C void func_8005BC84(void*, int, int, int);
EXTERN_C void func_800D4674();
struct Unk_C3_800E675C { char c[3]; };
struct Unk_C19_800E675C { char c[19]; };
struct Unk_800E675C_g { char pad0[0x1C4]; int unk1C4; };
struct Unk_800E675C { char pad0[0x85]; char unk85[0x24]; signed char unkA9; };
EXTERN_C char D_800BA2E8[];
EXTERN_C char D_800BA2EC[];

/* forward declarations of functions defined later in field.cpp */
EXTERN_C int func_800E082C(Unk_800E082C* p);
EXTERN_C void func_800E675C(struct Unk_800E675C* p, signed char a);
EXTERN_C void func_8002DD34(void*, void*, int);
EXTERN_C void func_80063340(void*, void*);
EXTERN_C int func_800BC0D8(Unk_800BCBE8* p);
EXTERN_C int func_800BC130(Unk_800BCBE8* p);
EXTERN_C void func_800BD3A8(Unk_800BD3E0* p);
EXTERN_C void func_800BF35C(Unk_800BF420* p, int a);
EXTERN_C void func_800BF4B8(Unk_800BF4B8* p, int a);
EXTERN_C void func_800BF8AC(Unk_800BF8AC* p, int a);
EXTERN_C void func_800BFA54(Unk_800BFA54* p, int a);
EXTERN_C void func_800C03CC(Unk_800C03CC* p, int a);
EXTERN_C void func_800C05D4(Unk_800BF4B8* p, int a);
EXTERN_C void func_800CCF4C(Unk_800CCF18* p);
EXTERN_C int func_800D49C0();
EXTERN_C void func_800D9AF8(void* p, int a);
EXTERN_C void func_800E4228(Unk_800E4228* p);
EXTERN_C void func_800E6F14(Unk_800E6F14* p, int t);
EXTERN_C void func_800E83B8(Unk_800E83B8* p, int a, int b);
EXTERN_C void func_800E84CC(Unk_800E83B8* p, int a);
EXTERN_C void func_800E9C08(Unk_Sprt10* p, int n);
struct Unk_800D1304_s { char pad0[0x8E]; unsigned char unk8E; };
struct Unk_800D1304 : VAt<0x18> { char pad1C[0x4C]; Unk_800D1304_s* unk68; unsigned int unk6C; char pad70[0xC]; int unk7C; };
EXTERN_C void func_800D1490(void*);
struct Unk_800CE6B8_r { int unk0; };
EXTERN_C Unk_800CE6B8_r* func_80062158(void*);
struct Unk_RectP { Unk_Pt a; Unk_Pt b; Unk_RectP(short x, short y, short w, short h) : a(x, y), b(w, h) {} };
struct Unk_800D9B44 { char pad0[8]; int unk8; char padC[0x10]; unsigned short unk1C; char pad1E[0x12]; Unk_800BFB64_list* unk30; char pad34[4]; void* unk38; };
EXTERN_C void* func_80053250(void*, const Unk_RectP&, void*, int);
EXTERN_C void* func_8002860C(void*, const Unk_RectP&, void*, int, int);
EXTERN_C int D_800B4C74;
struct Unk_800CE820_g { char pad0[0x1C4]; int unk1C4; };
struct Unk_800CE820 { char pad0[0x5C]; char unk5C[0x28]; char unk84[0x28]; char unkAC[0x28]; char unkD4[0x1C]; char unkF0[4]; };
EXTERN_C int func_800549D8(void*);
EXTERN_C char D_800B4D6C[];
struct Unk_800E59E4 : VAt<0x18> { char pad1C[4]; int unk20; char pad24[0x44]; Unk_800E07FC* unk68; Unk_800C9D60_sub* unk6C; char unk70[0x50]; char unkC0[0x1C]; char unkDC[4]; };
EXTERN_C void func_800609D0(void*, void*);
EXTERN_C void func_800E6AC4(void*, void*, int);
EXTERN_C Unk_800C9D60_sub* func_800638A8(void*, int);
struct Unk_800DADD4 { char pad0[0x2468]; int unk2468; char pad246C[0x14]; void* unk2480; void* unk2484; };
EXTERN_C char D_800B95BC[];
EXTERN_C char D_800B95F4[];
EXTERN_C char D_800B9604[];
EXTERN_C char D_800B9634[];
EXTERN_C char D_800B9660[];
EXTERN_C char D_800B968C[];
EXTERN_C Unk_Deletable* D_800EA134[];
EXTERN_C Unk_Deletable* D_800EA138[];
EXTERN_C Unk_Deletable* D_800EA13C[];
EXTERN_C Unk_Deletable* D_800EA140[];
EXTERN_C Unk_Deletable* D_800EA144[];
struct Unk_800C57C4 { char pad0[0x20]; int unk20; char pad24[0x18]; Unk_800C9D90_sub* unk3C; char pad40[0x98]; char unkD8[4]; };
EXTERN_C void func_800C5F68(void*);
struct Unk_PtS { short x, y; Unk_PtS(short a, short b) { x = a; y = b; } };
struct Unk_800C2D40 : VAt<0x18> { char pad1C[0x4C]; unsigned short unk68; unsigned short unk6A; void* unk6C; char unk74_[4]; char unk74[0xDC]; char unk150[4]; };
EXTERN_C void func_80069978(void*, const Unk_PtS&, int, int, int);
EXTERN_C void func_80069914(void*);
EXTERN_C void* func_8006753C(void*, int);
struct Unk_Sprt20 { int tag; Unk_W4 body; };
struct Unk_800E7C44 { char pad0[0xA]; unsigned short unkA; char padC[4]; Unk_Dr12 unk10[2]; Unk_Sprt20 unk28[2]; };
struct Unk_PTag { unsigned int addr : 24; unsigned int len : 8; };
inline void addPrimN(unsigned int n, void* prim) {
    Unk_Ot* ot = D_800B4CFC[0];
    if (n && n < ot->unk10) {
        ((Unk_PTag*)prim)->addr = ot->unk14[n];
        ot->unk14[n] = (unsigned int)prim & 0xFFFFFF;
    }
}
EXTERN_C int func_8005F1B4(void*);
struct Unk_800BA800_uv { unsigned char u; unsigned char pad1; unsigned char v; unsigned char pad3; };
struct Unk_800BA800 { void* vtbl; int unk4; short unk8; short unkA; char unkC[0xC]; char unk18[0xC]; SPRT_16 unk24[2]; char pad44_[0]; int unk44; int unk48; };
EXTERN_C void SetDrawMode(void*, int, int, int, int);
EXTERN_C void func_80098DC0(void*, int);
EXTERN_C void func_800BB068(void*, int, int);
EXTERN_C void func_800BADB4(void*);

EXTERN_C void func_800BAC9C(Unk_800BAC9C* p, int x, int y);
EXTERN_C void func_800BAED8(Unk_Sprt16_24c* p, Unk_ColorSrc* c);
EXTERN_C void func_800BB128(Unk_Sprt16_24* p, int u, int v);
EXTERN_C void func_800BB1BC(Unk_800BB1BC* p, Unk_800BB1BC_arg* a);
EXTERN_C void func_800E6E64(Unk_800E6E64* p);
struct Unk_800DE59C_v { short x, y, z, w; };
struct Unk_800DE59C_y { char pad0[0x2C]; Unk_800DE59C_v unk2C; Unk_W4 unk34; };
struct Unk_800DE59C_x { char pad0[0x1B8]; Unk_800DE59C_y* unk1B8; };
struct Unk_800DE59C_b { int unk0; int unk4; Unk_800DE59C_x* unk8; };
struct Unk_800DE59C_h { char pad0[0x14C]; int unk14C; char pad150[4]; Unk_W4 unk154; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; char pad180[0x24]; int unk1A4; char pad1A8[4]; int unk1AC; };
struct Unk_800DE59C : Unk_PadB8, Unk_800DE59C_b { };
inline Unk_800DE59C_b* base(Unk_800DE59C* p) { return p; }
inline Unk_W4 getW(Unk_800DE59C* p) { return base(p)->unk8->unk1B8->unk34; }
EXTERN_C int SquareRoot0(int);
EXTERN_C void func_800DE1E8(void*, int, int, int, int, int, int, Unk_W4, int);
struct Unk_800DE3B8_g { char pad0[0x378]; int unk378; };
struct Unk_800DE3B8 : Unk_PadB8, Unk_800DE59C_b { char padC4[0x88]; int unk14C; char pad150[4]; Unk_W4 unk154; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; char pad180[0x24]; int unk1A4; char pad1A8[4]; int unk1AC; };
inline Unk_800DE59C_b* base(Unk_800DE3B8* p) { return p; }
inline Unk_W4 getW(Unk_800DE3B8* p) { return base(p)->unk8->unk1B8->unk34; }
EXTERN_C int func_800DDE6C(void*, int, int, int, int, int, int);
EXTERN_C void func_8007B538(void*, int, int, int, int, int);
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_8005BC84(void*, int, int, int);
struct Unk_800D8FD4 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; unsigned char unk38; char pad39[0x3]; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_80068770(void*, int);
struct Unk_800CD8D8 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x2220]; void* unk227C; Unk_VbObj vobj; };
EXTERN_C const Unk_VTbl10 D_800B75D4;
EXTERN_C char D_800B7624[];
EXTERN_C char D_800B7644[];
struct Unk_800C4CA0 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; char unk38[8]; void* vt40; };
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_800B79C4;
EXTERN_C char D_800B7A34[];
EXTERN_C char D_800B7A14[];
EXTERN_C char D_800B7A64[];
struct Unk_800C7110 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x8]; char unk64[0x50]; char unkB4[4]; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_8005BC84(void*, int, int, int);
EXTERN_C const Unk_VTbl10 D_800B9534;
EXTERN_C char D_800B943C[];
struct Unk_800D98D0 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; int unk38; int unk3C; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_8005BC84(void*, int, int, int);
EXTERN_C int D_800EA11C[];
EXTERN_C void func_800CF32C();
struct Unk_800CF9A8 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_8005BC84(void*, int, int, int);
EXTERN_C const Unk_VTbl10 D_800B8C3C;
EXTERN_C char D_800B8B44[];
struct Unk_800D18F4 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; int unk38; int unk3C; int unk40; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_8005BC84(void*, int, int, int);
EXTERN_C const Unk_VTbl10 D_800BA728;
EXTERN_C char D_800BA778[];
EXTERN_C char D_800BA630[];
EXTERN_C void func_800537C0(void*);
struct Unk_800E936C { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; char unk38[8]; void* vt40; int unk44; int unk48; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C const Unk_VTbl10 D_800B806C;
EXTERN_C char D_800B8064[];
EXTERN_C char D_800B80DC[];
EXTERN_C char D_800B80BC[];
EXTERN_C char D_800B810C[];
EXTERN_C void func_80056198(void*, int, void*, int, int);
struct Unk_800C9B58 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x8]; int unk64; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_8005BC84(void*, int, int, int);
EXTERN_C const Unk_VTbl10 D_800B891C;
EXTERN_C char D_800B896C[];
EXTERN_C void func_800CFF6C();
struct Unk_800D03B0 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; char unk38; char pad39[0x3]; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_80056364(void*, int, int, int);
struct Unk_800D8A04 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x8]; int unk64; int unk68; int unk6C; int unk70; int unk74; Unk_VbObj vobj; };
EXTERN_C const Unk_VTbl10 D_800B7B9C;
EXTERN_C char D_800B7BEC[];
EXTERN_C char D_800B7AA4[];
EXTERN_C void func_800D3534();
struct Unk_800C7740_h { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[8]; };
struct Unk_800C7740 : Unk_800C7740_h, Unk_Base { int unk3C; void* vt40; };
EXTERN_C const Unk_VTbl10 D_800B8DEC;
EXTERN_C char D_800B8CF4[];
struct Unk_800D2DD8 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; void* unk38; Unk_Deletable* unk3C; };
EXTERN_C const Unk_VTbl10 D_800B8C3C;
EXTERN_C char D_800B8B44[];
struct Unk_800D1A1C { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0xC]; void* unk3C; Unk_Deletable* unk40; };
EXTERN_C const Unk_VTbl10 D_800BA728;
EXTERN_C char D_800BA778[];
EXTERN_C char D_800BA630[];
struct Unk_800E9498_h { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[8]; };
struct Unk_800E9498 : Unk_800E9498_h, Unk_Base { int unk3C; void* vt40; void* unk44; Unk_Deletable* unk48; };
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800B836C;
EXTERN_C char D_800B83DC[];
EXTERN_C char D_800B83BC[];
EXTERN_C char D_800B840C[];
struct Unk_800CD060 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; char unk68[0x1C]; char unk84[4]; };
EXTERN_C const Unk_VTbl10 D_800B7564;
EXTERN_C char D_800B75B4[];
EXTERN_C char D_80013E30[];
EXTERN_C void func_80057558(void*, int);
struct Unk_800C402C { Unk_VBase* vb; char pad4[0x28]; void* vt2C; Unk_DualList unk30; char pad3C[0x1C]; void* vt58; };
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800B74B4;
EXTERN_C char D_800B7484[];
EXTERN_C char D_800B7504[];
EXTERN_C char D_800B7524[];
struct Unk_800C38E0 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x10]; char unk6C[0x50]; char unkBC[4]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800B86F4;
EXTERN_C char D_800B8764[];
EXTERN_C char D_800B8744[];
EXTERN_C char D_800B8794[];
struct Unk_800CF11C { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; Unk_EV<0x6C> unk68[3]; char unk1AC[4]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800B77E4;
EXTERN_C char D_800B7854[];
EXTERN_C char D_800B7834[];
EXTERN_C char D_800B7884[];
EXTERN_C void func_800C68AC(void*, int);
struct Unk_800C59D8 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; Unk_EV<0x1C> unk68[4]; char unkD8[4]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800B844C;
EXTERN_C char D_800B849C[];
EXTERN_C char D_800B84BC[];
struct Unk_800CD6BC { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; char unk68[0x50]; char unkB8[0x1C]; Unk_EV<0x88> unkD4[8]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_800B9094;
EXTERN_C char D_800B9104[];
EXTERN_C char D_800B90E4[];
EXTERN_C char D_800B9134[];
struct Unk_800D80F0 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; char unk68[0x50]; char unkB8[4]; char padBC[0x5C]; char unk118[4]; char pad11C[0x18]; char unk134[4]; char pad138[0x18]; char unk150[4]; char pad154[0x18]; char unk16C[4]; char pad170[0x18]; char unk188[4]; char pad18C[0x18]; char unk1A4[4]; char pad1A8[0x24]; char unk1CC[4]; char pad1D0[0x24]; char unk1F4[4]; char pad1F8[0x24]; char unk21C[4]; char pad220[0x24]; char unk244[4]; char pad248[0x24]; Unk_EV<0x1C> unk26C[4]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800B97E4;
EXTERN_C char D_800B97B4[];
EXTERN_C char D_800B9834[];
EXTERN_C char D_800B9854[];
typedef Unk_EV<0x1C> Unk_800DB318_e;
struct Unk_800DB318 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x10]; Unk_800DB318_e* unk6C; void* unk70; char pad74[0x4]; Unk_EV<0x1C> unk78[2]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800BA580;
EXTERN_C char D_800BA550[];
EXTERN_C char D_800BA5D0[];
EXTERN_C char D_800BA5F0[];
struct Unk_800E8144 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x14]; Unk_Deletable18* unk70; Unk_Deletable18* unk74; char pad78[0xC]; void* unk84; char pad88[0x4]; Unk_EV<0x1C> unk8C[3]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800B7E1C;
EXTERN_C char D_800B7E8C[];
EXTERN_C char D_800B7E6C[];
EXTERN_C char D_800B7EBC[];
struct Unk_800CD060;
EXTERN_C void func_800CD060(Unk_800CD060*, int);
struct Unk_800C94D4 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x14]; Unk_EV<0x50> unk70[8]; Unk_EV<0x1C> unk2F0[8]; Unk_EV<0x1C> unk3D0[8]; char pad4B0[0x10]; char unk4C0[0x50]; char unk510[0x1C]; char unk52C[0x1C]; char unk548[0x1C]; char unk564[4]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800BA188;
EXTERN_C char D_800BA1F8[];
EXTERN_C char D_800BA1D8[];
EXTERN_C char D_800BA228[];
struct Unk_800E5CE8_m { char pad0[0xAC]; Unk_EV<0x1C> unkAC[3]; };
struct Unk_800E5CE8 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x14]; char unk70[0x50]; char unkC0[0x1C]; Unk_800E5CE8_m unkDC; Unk_EV<0x28> unk1DC[3]; char unk254[0x28]; char unk27C[0x28]; char unk2A4[0x28]; char unk2CC[0x1C]; char unk2E8[0x1C]; char unk304[0x1C]; char unk320[0x1C]; char unk33C[4]; };
#ifndef UNK_DESTROY_DEFINED
#define UNK_DESTROY_DEFINED
struct Unk_EVb { char pad0[0x18]; virtual ~Unk_EVb(); };
template <int N> struct Unk_EV : Unk_EVb { char pad1C[N - 0x1C]; };
template <class T> inline void Unk_vecdel(T*& p) { if (p) { T* e = p + ((int*)p)[-2]; if (p != e) { do { --e; e->~T(); } while (p != e); } func_800A0D0C((char*)p - 8); } }
template <class T> inline void Unk_destroy(T* a, int n) { if (a) { T* e = a + n; if (a != e) { T* b = a; do { --e; e->~T(); } while (b != e); } } }
#endif
EXTERN_C void func_8005652C(void*, int);
EXTERN_C const Unk_VTbl10 D_80014E0C;
EXTERN_C char D_80014E7C[];
EXTERN_C char D_80014E5C[];
EXTERN_C char D_80014EAC[];
EXTERN_C const Unk_VTbl10 D_800B8F34;
EXTERN_C char D_800B8FA4[];
EXTERN_C char D_800B8F84[];
EXTERN_C char D_800B8FD4[];
struct Unk_800D633C { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; Unk_EV<0x1C> unk68[50]; Unk_EV<0x1C> unk5E0[26]; Unk_EV<0x1C> unk8B8[10]; Unk_EV<0x1C> unk9D0[4]; char padA40[0x4]; char unkA44[0x50]; char unkA94[0x50]; char unkAE4[0x1C]; char unkB00[0x1C]; char unkB1C[4]; };
EXTERN_C const Unk_VTbl10 D_800B825C;
EXTERN_C char D_800B82AC[];
EXTERN_C char D_800B814C[];
EXTERN_C void func_80057558(void*, int);
struct Unk_800CA5A4 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; Unk_800BFB64_list unk30; char pad34[0x24]; void* vt58; char pad5C[0x28]; Unk_DualList unk84; char pad90[0x14]; char unkA4[8]; char unkAC[8]; char unkB4[4]; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_800630BC(void*, int, int);
EXTERN_C void func_80055020(void*, Unk_Pt);
EXTERN_C const Unk_VTbl10 D_800B74B4;
EXTERN_C char D_800B7484[];
EXTERN_C char D_800B7504[];
EXTERN_C char D_800B7524[];
struct Unk_800C375C { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; int unk68; char unk6C[0x50]; char unkBC[0x1C]; int unkD8; int unkDC; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_80056364(void*, int, int, int);
EXTERN_C void func_80055020(void*, Unk_Pt);
EXTERN_C const Unk_VTbl10 D_800B79C4;
EXTERN_C char D_800B7A34[];
EXTERN_C char D_800B7A14[];
EXTERN_C char D_800B7A64[];
struct Unk_800C6B44 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x8]; char unk64[0x50]; char unkB4[0x1C]; int unkD0; int unkD4; int unkD8; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_800630BC(void*, int, int);
EXTERN_C const Unk_VTbl10 D_800B77E4;
EXTERN_C char D_800B7854[];
EXTERN_C char D_800B7834[];
EXTERN_C char D_800B7884[];
struct Unk_800C5BE8;
EXTERN_C Unk_800C5BE8* func_800C5BE8(Unk_800C5BE8*, int);
struct Unk_800C5544 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; Unk_Elem28 unk68[4]; char unkD8[4]; char padDC[0x32DC]; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_80056364(void*, int, int, int);
EXTERN_C void func_800D0BB4();
struct Unk_800D0E90 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x8]; int unk64; int unk68; int unk6C; char pad70[0x4]; int unk74; int unk78; int unk7C; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_80056364(void*, int, int, int);
EXTERN_C void func_800D0BB4();
EXTERN_C void func_800D1004(Unk_800D1004*, int);
struct Unk_800D0CDC { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x8]; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; Unk_VbObj vobj; };
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C char D_800B737C[];
EXTERN_C char D_800B721C[];
EXTERN_C VAt<0x2C>* func_80057368(void*, int);
EXTERN_C void func_8005D8C4(void*, int, int);
struct Unk_800C1D70 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x28]; void* vt58; int unk5C; int unk60; int unk64; char unk68[0x40]; int unkA8; Unk_VbObj vobj; };
EXTERN_C const Unk_VTbl10 D_800B732C;
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_800630BC(void*, int, int);
EXTERN_C void func_80055020(void*, Unk_Pt);
EXTERN_C char D_800B849C[];
EXTERN_C char D_800B84BC[];
struct Unk_800D0E90;
EXTERN_C Unk_800D0E90* func_800D0E90(Unk_800D0E90*, int);
struct Unk_EB88 { char pad[0x88]; };
struct Unk_800CD224 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; char unk68[0x50]; char unkB8[0x1C]; Unk_EB88 unkD4[8]; short unk514; char pad516[0x2]; Unk_VbObj vobj; };
EXTERN_C char D_80014E7C[];
EXTERN_C const Unk_VTbl10 D_800B844C;
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_800630BC(void*, int, int);
EXTERN_C void func_80055020(void*, Unk_Pt);
EXTERN_C void func_800E62C8(void*);
EXTERN_C void func_800E66F0(struct Unk_800E6750*, unsigned int);
struct Unk_800E580C { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; int unk68; int unk6C; char unk70[0x50]; char unkC0[0x1C]; char unkDC[0x27C]; Unk_VbObj vobj; };
EXTERN_C const Unk_VTbl10 D_800BA188;
EXTERN_C char D_800BA1D8[];
EXTERN_C char D_800BA1F8[];
EXTERN_C char D_800BA228[];
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_800630BC(void*, int, int);
EXTERN_C void func_80063270(void*, Unk_Pt);
struct Unk_800CCD24 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; char unk68[0x1C]; char unk84[0x1C]; Unk_VbObj vobj; };
EXTERN_C char D_800B8334[];
EXTERN_C char D_800B8350[];
EXTERN_C const Unk_VTbl10 D_800B836C;
EXTERN_C char D_800B83BC[];
EXTERN_C char D_800B83DC[];
EXTERN_C char D_800B840C[];
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_80062FA4(void*, int, int, int);
EXTERN_C void func_80062D60(void*, int);
struct Unk_800CEA30_e { char pad0[0x5C]; int unk5C; char pad60[0xC]; };
struct Unk_800CEA30 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; Unk_800CEA30_e unk68[3]; char unk1AC[0x1C]; int unk1C8; int unk1CC; int unk1D0; Unk_VbObj vobj; };
EXTERN_C char D_800B86B4[];
EXTERN_C char D_800B86C4[];
EXTERN_C char D_800B86D8[];
EXTERN_C char D_800B86E8[];
EXTERN_C const Unk_VTbl10 D_800B86F4;
EXTERN_C char D_800B8744[];
EXTERN_C char D_800B8764[];
EXTERN_C char D_800B8794[];
EXTERN_C char D_800EA77E[];
struct Unk_800D7FB4 { char pad0[0xE0]; Unk_800D7F10_o* unkE0; Unk_800D7F10_o* unkE4; };
struct Unk_800D3090 { char pad0[8]; int unk8; char padC[0x10]; unsigned short unk1C; char pad1E[0x12]; Unk_800BFB64_list* unk30; char pad34[4]; int unk38; };
struct Unk_800D3090_r { Unk_Pt a, b; Unk_800D3090_r(short x, short y, short w, short h) : a(x, y), b(w, h) {} };
struct Unk_800D8B40 { char pad0[0x68]; int unk68; VAt<0x2C>* unk6C; void* unk70; int unk74; };
EXTERN_C VAt<0x2C>* func_80057368(void*, int);
struct Unk_800D98D0; EXTERN_C Unk_800D98D0* func_800D98D0(Unk_800D98D0* self, int in_chrg, unsigned short a);
EXTERN_C void* D_800EA120[];
EXTERN_C void* D_800EA124[];
EXTERN_C Unk_Deletable* D_800EA128[];
EXTERN_C Unk_Deletable* D_800EA12C[];
EXTERN_C Unk_Deletable* D_800EA130[];
struct Unk_800D3EAC_c { char pad0[5]; unsigned char r, g, b; };
struct Unk_800D3EAC { char pad0[0x1C]; int unk1C; char pad20[0x30]; SPRT unk50[10]; SPRT_16 unk118[0x60]; SPRT_16 unk718[2]; };
struct Unk_800E9178 { char pad0[0xE4]; int unkE4; int unkE8; int unkEC; int unkF0; VAt<0x2C>* unkF4; VAt<0x2C>* unkF8; };
EXTERN_C VAt<0x2C>* func_80057368(void*, int);
struct Unk_800E936C; EXTERN_C Unk_800E936C* func_800E936C(Unk_800E936C* self, int in_chrg, unsigned short a);
EXTERN_C void func_80069D1C(void*, int, int);
EXTERN_C void func_800E9650(void*, void*);
EXTERN_C void func_80069E60(void*, int);
struct Unk_C1A_800E4920 { char c[0x1A]; };
struct Unk_800E4920 : VAt0 { short* unk4; char pad8[0x2C]; int unk34; };
EXTERN_C int func_800E4034(void*, int, int);
EXTERN_C int erase(char*);
struct Unk_800BAAA0 : VAt0 { char pad4[4]; short unk8; unsigned short unkA; Unk_Dr12 unkC[2]; TILE unk24[2]; int unk44; int unk48; };
struct Unk_800C6F0C { char pad0[0x64]; char unk64[0x6C]; VAt<0x2C>* unkD0; VAt<0x2C>* unkD4; int unkD8; };
EXTERN_C VAt<0x2C>* func_80057368(void*, int);
EXTERN_C VAt<0x2C>* func_800C7230(void*, int, int);
EXTERN_C void func_800CF32C();
EXTERN_C void func_800CFF6C();
struct Unk_800D75B4_a : Unk_Deletable18 { };
struct Unk_800D75B4_b : Unk_Deletable18 { char pad1C[0xC]; };
struct Unk_800D75B4 { char pad0[0x68]; char unk68[0x70]; Unk_800DF26C_obj* unkD8[4]; char padE8[0x10]; void* unkF8; int unkFC; int unk100; int unk104; char pad108[4]; Unk_800D75B4_a* unk10C; Unk_800D75B4_b* unk110; Unk_800D75B4_b* unk114; };
struct Unk_800D1490 : VAt<0x18> { char pad1C[0x4C]; Unk_800D1304_s* unk68; unsigned int unk6C; VAt<0x2C>* unk70; VAt<0x2C>* unk74; Unk_800C9D60_sub* unk78; int unk7C; };
EXTERN_C VAt<0x2C>* func_80057368(void*, int);
struct Unk_800D18F4; EXTERN_C Unk_800D18F4* func_800D18F4(Unk_800D18F4* self, int in_chrg, int b, unsigned short a);
EXTERN_C void func_80069D1C(void*, int, int);
EXTERN_C void func_800D1BA4(void*, void*);
EXTERN_C void func_80069E60(void*, int);
struct Unk_800D7B6C_a { char pad0[0x1C]; Unk_800D7B6C_a() { func_80053928(this); } ~Unk_800D7B6C_a(); };
EXTERN_C void* func_8005464C(void*);
struct Unk_800D7B6C_b { char pad0[0x28]; Unk_800D7B6C_b() { func_8005464C(this); } ~Unk_800D7B6C_b(); };
struct Unk_800D7B6C { char pad0[0xD8]; VAt<0x18>* unkD8; char padDC[0x30]; Unk_800D7B6C_a* unk10C; Unk_800D7B6C_b* unk110; Unk_800D7B6C_b* unk114; };
EXTERN_C VAt<0x18>* func_800694BC(void*, int, int, int);
EXTERN_C void func_800549EC(void*, int);
EXTERN_C void func_800549E4(void*, int);
EXTERN_C void func_8005408C(void*, int);
EXTERN_C char D_800B9078[];
EXTERN_C char D_800B9084[];
struct Unk_800DABA8 : VAt<0x18> { char pad1C[0x20]; void* unk3C; char pad40[0x22B0]; char unk22F0[0x178]; int unk2468; char pad246C[0x10]; VAt<0x18>* unk247C; void* unk2480; void* unk2484; };
EXTERN_C int func_800DB8D8(void*);
EXTERN_C void* func_8005464C(void*);
EXTERN_C void func_80057F20(void*, int);

EXTERN_C void func_800DAD54(Unk_800DAD54* p);
EXTERN_C void func_800DADD4(Unk_800DADD4* p, int a);
#ifndef UNK_VBOBJ_DEFINED
#define UNK_VBOBJ_DEFINED
struct Unk_VbObj { void* vptr; int unk4; };
#endif
EXTERN_C void func_8005BC84(void*, int, int, int);
EXTERN_C const Unk_VTbl10 D_800BA380;
EXTERN_C char D_800BA3D0[];
struct Unk_800E714C { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; int unk38; int unk3C; Unk_VbObj vobj; };
EXTERN_C char D_800B773C[];
struct Unk_W5 { int a, b, c, d, e; };
struct Unk_800C5408 { void* vtbl; int unk4; short unk8; short unkA; int unkC; Unk_W3 unk10[2]; Unk_W5 unk28[2]; Unk_W4 unk50[2]; };
EXTERN_C char D_800B8C8C[];
struct Unk_800D29D8 { void* vtbl; int unk4; short unk8; short unkA; int unkC; POLY_GT4 unk10[2]; Unk_W3 unk78[2]; Unk_W3 unk90[2]; short unkA8; };
EXTERN_C char D_80013B00[];
struct Unk_800D44D4_h { void* vtbl; int unk4; short unk8; short unkA; int unkC; };
struct Unk_800D44D4_b { int a; int b; void* vt; };
struct Unk_800D44D4 : Unk_800D44D4_h, Unk_800D44D4_b { int unk1C; Unk_W3 unk20[4]; Unk_W5 unk50[10]; Unk_W4 unk118[0x60]; Unk_W4 unk718[2]; };
struct Unk_800DBDD8_e { char pad0[0x8B]; unsigned char unk8B; char pad8C[8]; };
struct Unk_800DBDD8 : VAt<0x18> { char pad1C[4]; int unk20; char pad24[0x18]; void* unk3C; char pad40[0x30]; Unk_800DBDD8_e* unk70; };
struct Unk_800E0888_d { virtual int vf00(...); virtual int vf01(...); virtual int vf02(...); virtual int vf03(...); virtual ~Unk_800E0888_d(); };
struct Unk_800E0888 { char pad0[0x7C]; int unk7C; void* unk80; int unk84; Unk_800E0888_d* unk88; char unk8C[0x130]; char unk1BC[0x88]; Unk_800E1174_e unk244[15]; };
EXTERN_C void func_8002798C();
struct Unk_800DF098_e { char pad0[0x1B8]; Unk_800E83B8* unk1B8; };
struct Unk_800DF098 : Unk_EntOwner { char pad32C[0x230]; void* unk55C; };
struct Unk_800D0CDC; EXTERN_C Unk_800D0CDC* func_800D0CDC(Unk_800D0CDC* self, int in_chrg, int a, int b);
EXTERN_C void func_800DEED4(void*, Unk_W3);
EXTERN_C void func_80081820(void*, int, int, int, void*, void*);
EXTERN_C char D_800AFA74[];
struct Unk_800CC138 { char pad0[0x5C]; int unk5C; char pad60[8]; short unk68; short unk6A; char pad6C[0x18]; Unk_DualList unk84; };
EXTERN_C void func_800D04E4(Unk_800D04E4*, int, int, int);
inline Unk_800D04E4* at_800CC138(Unk_List2* l, int i) { return (Unk_800D04E4*)func_80019F64(first2(l), i); }
struct Unk_800C52A0 { char pad0[0x10]; char unk10[0xC]; char unk1C[0xC]; SPRT unk28[2]; SPRT_16 unk50[2]; };
EXTERN_C unsigned short func_80060154(char*, int);
EXTERN_C Unk_Short2 func_80060188(char*, int);
EXTERN_C unsigned short func_800600A4(char*, int);
EXTERN_C char D_800AE640[];
struct Unk_800D56E8 : VAt<0x18> { char pad1C[0x20]; void* unk3C; char pad40[0x1C]; int unk5C; char pad60[0x9E0]; int unkA40; char unkA44[0x50]; char unkA94[0x50]; char unkAE4[0x1C]; char unkB00[0x1C]; char unkB1C[0x1C]; int unkB38; int unkB3C; };
EXTERN_C void func_800D5E24(void*);
EXTERN_C void func_800588C8(void*);
EXTERN_C char* func_80061188(void*, int);
EXTERN_C void func_800540A8(void*);
EXTERN_C int func_80053BB4(void*);
EXTERN_C void func_80053B68(void*);
EXTERN_C void func_800601D8(void*, char*);
EXTERN_C void func_800539D0(void*, void*);
EXTERN_C char D_800B8F2C[];
struct Unk_800C3C54 : VAt<0x18> { char pad1C[0x4C]; int unk68; char pad6C[0x6C]; int unkD8; void* unkDC; };
EXTERN_C void func_800C43DC(void*, unsigned char, unsigned char);
struct Unk_800DCC0C_e : Unk_Pad400, VAt<0x9C> { };
struct Unk_800DCC0C { char pad0[0x64]; Unk_Elem40 unk64[8]; char pad1A4[0x17C]; char unk320[0x6C]; char unk38C[0x50]; int unk3DC; int unk3E0; int unk3E4; char pad3E8[4]; void* unk3EC; void* unk3F0; char pad3F4[8]; Unk_Elem40* unk3FC; };
EXTERN_C void func_8005408C(void*, int);
EXTERN_C short D_80015904[];
struct Unk_Dr20_800D95F8 { unsigned int tag; Unk_W4 body; };
struct Unk_800D95F8 { char pad0[0xA]; unsigned short unkA; char padC[4]; Unk_Dr12 unk10[2]; Unk_Dr20_800D95F8 unk28[2]; };
struct Unk_800D109C_t { int w[10]; };
struct Unk_800D109C { char pad0[0x3C]; void* unk3C; char pad40[0x24]; int unk64; int unk68; int unk6C; VAt<0x2C>* unk70; char pad74[4]; VAt<0x2C>* unk78; int unk7C; };
EXTERN_C void func_80069D1C(void*, int, int);
EXTERN_C void func_800D1BA4(void*, void*);
EXTERN_C void func_80069E60(void*, int);
struct Unk_C13_800E5024 { char c[13]; };
EXTERN_C struct DIRENTRY* nextfile(struct DIRENTRY*);
EXTERN_C char D_800BA0A0[];
EXTERN_C Unk_C13_800E5024 D_800BA0A4;
struct Unk_800E9ECC { char pad0[0xA]; unsigned short unkA; char padC[4]; SPRT unk10[0x90]; Unk_Dr12 unkB50[2]; };
inline void addPrimOt_800E9ECC(Unk_Ot* ot, unsigned int n, void* prim) {
    if (n && n < ot->unk10) {
        *(unsigned int*)prim = (*(unsigned int*)prim & 0xFF000000) | (ot->unk14[n] & 0xFFFFFF);
        ot->unk14[n] = (unsigned int)prim & 0xFFFFFF;
    }
}
inline void addPrimOt2_800E9ECC(Unk_Ot* ot, unsigned int n, void* prim) {
    if (n && n < ot->unk10) {
        ((Unk_PTag*)prim)->addr = ot->unk14[n];
        ot->unk14[n] = (unsigned int)prim & 0xFFFFFF;
    }
}
struct Unk_800DA224 : VAt<0x18> { char pad1C[0x2268]; char unk2284[0x6C]; char unk22F0[0x17C]; VAt<0x2C>* unk246C; VAt<0x18>* unk2470[1]; };
EXTERN_C VAt<0x18>* func_800CDBB4(void*);
EXTERN_C void func_800CDE70(Unk_800CDE70*, int);
EXTERN_C void func_800DAD54(Unk_800DAD54*);
struct Unk_800C2A6C_e : Unk_Pad400, Unk_Base { char pad404[0x38]; unsigned char unk43C[0x114]; int unk550[4]; };
struct Unk_800C2A6C { char pad0[0x20]; int unk20; char pad24[0x12C]; char unk150[0x64]; Unk_Elem40 unk1B4[8]; char pad2F4[0x200]; Unk_Elem40 unk4F4[8]; };
EXTERN_C void func_8008B150(void*, Unk_W4);
EXTERN_C void func_800697A4(void*);
EXTERN_C void func_8005408C(void*, int);
EXTERN_C short D_80015904[];
struct Unk_E6C_800C66D4 { char pad0[0x6C]; };
struct Unk_800C66D4_t { int w[8]; };
struct Unk_800C66D4 { char pad0[0x68]; signed char unk68[0x34]; Unk_E6C_800C66D4 unk9C[0x30]; char pad1BDC[0]; };
EXTERN_C void func_80061AAC(void*, int, int);
EXTERN_C void* func_80053BC0(void*);
struct Unk_800CDF68_v : Unk_Pad400, VAt<0x9C> { };
struct Unk_800CDF68 { char pad0[0x50]; int unk50; short unk54; short unk56; char pad58[0x98]; char unkF0[0x28]; char unk118[0x28]; VAt<0x2C>* unk140; VAt<0x2C>* unk144; };
EXTERN_C int func_800549C4(void*, int);
struct Unk_800C41E0 { char pad0[0x30]; Unk_DualList unk30; char pad3C[0x20]; int unk5C[15]; };
EXTERN_C int func_800C46E4(Unk_800C46E4*);
inline void* at_800C41E0(Unk_List2* l, int i) { return func_80019F64(first2(l), i); }
struct Unk_800D876C_e28 : Unk_Deletable18 { char pad1C[0xC]; };
struct Unk_800D876C { char pad0[0x18]; void* vtbl18; char pad1C[0x34]; char unk50[0x1C]; Unk_Deletable18* unk6C; Unk_Deletable18* unk70; Unk_800D876C_e28* unk74; Unk_800D876C_e28* unk78; };
EXTERN_C char D_800B917C[];
struct Unk_800E88D0_h : VAt<0x18> { Unk_800BFB64_list unk1C; int unk20; char pad24[0x18]; void* unk3C; char pad40[0x18]; };
struct Unk_800E88D0_b { int unk0; };
struct Unk_800E88D0 : Unk_800E88D0_h, Unk_800E88D0_b { char pad5C[0x30]; char unk8C[0x54]; int unkE0; char padE4[0x18]; VAt<0x18>* unkFC; };
EXTERN_C Unk_W2 func_80053AE4(void*, int);
EXTERN_C int func_80060230(const Unk_W2&, char*);
EXTERN_C char D_800BA544[];
EXTERN_C char D_800BA548[];
EXTERN_C void* D_800B4D60[];
struct Unk_800CBA70 : Unk_Pad50, Unk_Base { char pad54[8]; int unk5C; char pad60[8]; short unk68; short unk6A; short unk6C; short unk6E; char pad70[0x14]; Unk_DualList unk84; char pad90[0x14]; char unkA4[0x18]; int unkBC; int unkC0; };
EXTERN_C void func_800CBCCC(void*, int, int, int, int);
EXTERN_C void func_800D0608(Unk_800D0704*, Unk_Short2, Unk_Short2, int);
inline VAt<0x2C>* at_800CBA70(Unk_List2* l, int i) { return (VAt<0x2C>*)func_80019F64(first2(l), i); }
struct Unk_S4_800CBA70 { short x, y, z, w; };
struct Unk_R_800D72B8 { Unk_Pt a, b; Unk_R_800D72B8(short x, short y, short w, short h) : a(x, y), b(w, h) {} };
struct Unk_800D72B8 : VAt<0x18> { char pad1C[0x20]; void* unk3C; char pad40[0x24]; int unk64; char unk68[0x6C]; int unkD4; VAt<0x18>* unkD8; char padDC[0x1C]; Unk_800C9D60_sub* unkF8; VAt<0x2C>* unkFC; void* unk100; void* unk104; };
struct Unk_800D7B6C; EXTERN_C void func_800D7B6C(Unk_800D7B6C* p);
EXTERN_C void func_800D7F10(Unk_800D7F10*);
struct Unk_800D7FB4; EXTERN_C void func_800D7FB4(Unk_800D7FB4* p);
EXTERN_C Unk_800D8FD4* func_800D8FD4(Unk_800D8FD4*, int, unsigned short);

EXTERN_C int func_800DB9F8(Unk_800DB9F8* p);
EXTERN_C void func_800E77AC();
struct Unk_800BF6E4 { char pad0[8]; int unk8; short unkC; };
EXTERN_C char D_800B9E2C[];
EXTERN_C char D_800B9E58[];
EXTERN_C char D_800B9BB4[];
EXTERN_C char D_800B9BF8[];
EXTERN_C char D_800B9BB8[];
EXTERN_C char D_800B9EC0[];
EXTERN_C int func_80054E90(void*);
struct Unk_B8_BF950 { char c[8]; };
inline void cp_BF950(Unk_B8_BF950* d, Unk_B8_BF950* s) { *d = *s; }
struct Unk_800BF950_d { int unk0; Unk_B8_BF950 unk4; Unk_B8_BF950 unkC; Unk_B8_BF950 unk14[3]; };
struct Unk_800BF950_s { int unk0; Unk_B8_BF950 unk4; Unk_B8_BF950 unkC[3]; };
struct Unk_800BC2B0_nb { int unk0; struct Unk_800BC2B0_n* unk4; };
struct Unk_800BC2B0_n : Unk_800BC2B0_nb, VAt0 { };
struct Unk_800BC2B0_q { char pad0[4]; short unk4; char pad6[6]; char unkC[4]; };
struct Unk_800BC2B0 { char pad0[0x498]; Unk_800BC2B0_n* unk498; char pad49C[0x48]; Unk_800BC2B0_q* unk4E4; };
inline Unk_800BC2B0_n* next(Unk_800BC2B0_n* n) { return n->unk4; }
EXTERN_C void func_800BD6E8(void*, void*, int);
struct Unk_E28_DB5A4 { char c[28]; };
struct Unk_E148_DB5A4 { char c[148]; };
struct Unk_S6C_DB5A4 { char pad0[0x1C]; Unk_E28_DB5A4 unk1C[1]; };
struct Unk_800DB5A4 { char pad0[0x6C]; Unk_S6C_DB5A4* unk6C; Unk_E148_DB5A4* unk70; };
EXTERN_C void* func_800198E0(void*, int, int);
struct Unk_Hld3 { void* vb; int unk4; void* unk8; };
struct Unk_800C0344 { void* vtbl; int unk4; short unk8; char padA[2]; Unk_Hld3 unkC; char list[0x14]; short unk2C; char pad2E[2]; int unk30; int unk34; int unk38; };
struct Unk_800DFBF8 { char pad0[0x10]; Unk_Deletable18* unk10; Unk_Deletable18* unk14[10]; };
struct Unk_800C1628 { char pad0[0x3C]; char* unk3C; char pad40[0x2C]; char unk6C[1]; char pad6D[0x7033]; Unk_Derived50* unk70A0; };
EXTERN_C void func_800635FC(void*, void*);
struct Unk_800C7FC8 : Unk_Hdr38d, Unk_Base { char pad3C[0x10]; int unk4C; };
struct Unk_800CDEEC_p { char pad0[0x400]; Unk_Base unk400; char pad404[0xC]; unsigned short unk410; char pad412[0xE]; unsigned short unk420; };
struct Unk_800CDEEC { char pad0[0x50]; int unk50; unsigned short unk54; unsigned short unk56; };
inline Unk_800CDEEC_p* ent_800CDEEC(Unk_EntTabObj* o, int i) { return (Unk_800CDEEC_p*)base(o)->unk8[i]; }
struct Unk_800E7B40 { void* vtbl; int unk4; short unk8; short unkA; int unkC; Unk_W3 unk10[2]; Unk_W5_800D4CC0 unk28[2]; };
EXTERN_C char D_800BA4C8[];
struct Unk_800D94F4 { void* vtbl; int unk4; short unk8; short unkA; int unkC; Unk_W3 unk10[2]; Unk_W5_800D4CC0 unk28[2]; };
EXTERN_C char D_800B93D4[];
EXTERN_C Unk_Vt50_800CDAAC D_800B806C_t asm("D_800B806C");
struct Unk_E1C_D5E24 { char c[0x1C]; };
struct Unk_800D5E24 { char pad0[0x68]; Unk_E1C_D5E24 unk68[50]; Unk_E1C_D5E24 unk5E0[26]; Unk_E1C_D5E24 unk8B8[10]; char pad9D0[0x170]; int unkB40; };
struct Unk_800D9778 { char pad0[0x10]; char unk10[0xC]; char unk1C[0xC]; SPRT unk28[2]; };
struct Unk_800CCAE8 { void* vtbl; int unk4; unsigned short unk8; unsigned short unkA; int unkC; POLY_FT4 unk10[2]; unsigned short unk60; };
EXTERN_C char D_800B82CC[];
struct Unk_hcA : VAt<0x18> { char pad1C[4]; int unk20; char pad24[0x18]; void* unk3C; char pad40[0x22B0]; char unk22F0[4]; };
EXTERN_C void func_800DBA84(void*);
struct Unk_hcB_e : Unk_Pad400, Unk_Base { char pad404[0x14C]; int unk550[4]; };
struct Unk_hcB { char pad0[0xE0]; char unkE0[0x1C]; };
EXTERN_C int func_80061164(Unk_800B4DD0*, int);
struct Unk_DB_A { char c[0x1C]; };
struct Unk_DB_B { char c[0x94]; };
struct Unk_800DB8D8 { char pad0[0x1C]; Unk_800BFB64_list unk1C; char pad20[0x4C]; Unk_DB_A* unk6C; Unk_DB_B* unk70; };
EXTERN_C int func_80061A20(void*, void*);
struct Unk_800CC85C_s { short x, y; };
struct Unk_800CC85C : Unk_Ft4_10 { char pad_[0x60 - 0x10 - sizeof(POLY_FT4)]; unsigned char ox, oy; };
EXTERN_C void func_800C43DC_i(Unk_800C41E0*, unsigned char, unsigned char) asm("func_800C43DC");
EXTERN_C void func_8005F0E4(void*, int);
struct Unk_800E9A68_s { char pad0[0xC]; VAt0* unkC; short unk10; short unk12; char pad14[8]; unsigned short unk1C; };
struct Unk_800E9A68_uv { unsigned char u, v; Unk_800E9A68_uv(int x, int y) { u = x; v = y; } };
typedef struct { unsigned char tp0, tp1, tp2, len; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; } Unk_Sp;
struct Unk_800E9A68 { void* vtbl; char pad4[0xC]; Unk_Sp unk10[0x90]; char pad_[0xB50 - 0x10 - 0x90 * 0x14]; char unkB50[0xC]; char unkB5C[0xC]; };
struct Unk_800D277C : Unk_Drawable { char pad4[0xC]; POLY_GT4 unk10[2]; char dr[4][0xC]; char pad_[0x30 - 0x30]; Unk_800D2214_uv uv; };
struct He_F_p { void* vtbl; int unk4; int unk8; Unk_800DF604_o* unkC; };
struct He_F_ent { void* a; int b; };
EXTERN_C He_F_ent D_800AF5F8[];
EXTERN_C void func_80048D54(void*);
EXTERN_C int func_80046658(void*, void*, int, void*);
EXTERN_C Unk_800DF604_o** func_80049398(void*);
EXTERN_C void func_80048D2C(void*, int);
EXTERN_C void func_80039BEC(void*, void*);
struct He_H_e : Unk_Pad400, Unk_Base { char pad404[0xC]; short unk410; short unk412; char pad414[0xC]; short unk420; short unk422; char pad424[0x53]; unsigned char unk477; char pad478[0xD4]; int unk54C; };
struct He_H_p { char pad0[0x2C4]; int unk2C4; char pad2C8[0xC4]; char unk38C[1]; char pad38D[0x4F]; char* unk3DC; void* unk3E0; void* unk3E4; char pad3E8[0x14]; char* unk3FC; char* unk400; char pad404[0xA8]; char unk4AC[0x28]; char unk4D4[0x28]; char unk4FC[0x28]; char unk524[0x28]; char unk54C[0x28]; char pad574[0x24]; };
struct He_H_p2 { char pad0[0x574]; int unk574; int unk578; };
EXTERN_C void func_800D90E8(Unk_800D90E8*, int);
EXTERN_C int func_8008B130(void*, int);
EXTERN_C void func_80064884(void*, int, int);
struct Unk_800CE154_e : Unk_Pad400, Unk_Base { char pad404[0xC]; short unk410; short unk412; char pad414[0xC]; short unk420; short unk422; char pad424[0x53]; unsigned char unk477; };
struct Unk_800CE154 : VAt<0x18> { char pad1C[0x20]; void* unk3C; char pad40[0x10]; int unk50; char pad54[0x74]; char unkC8[0x28]; char unkF0[0x28]; char unk118[0x28]; void* unk140; void* unk144; };
EXTERN_C void func_80028D10(void*, void*);
inline void* nx_FACC(Unk_TblIt* it) {
    void* x;
    int i = it->unk4;
    if (i < it->unk0->unk4) {
        void** arr = it->unk0->unk0;
        x = arr[i];
        it->unk4 = i + 1;
    } else {
        x = 0;
    }
    return x;
}
struct Unk_800C3E40 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x28]; void* vt58; int unk5C[15]; Unk_VbObj vobj; };
EXTERN_C Unk_800C3E40* func_800C3E40_i(Unk_800C3E40*, int) asm("func_800C3E40");
EXTERN_C void* func_800C44C4(void*, int, unsigned char, int);
struct Unk_800D4DC4 { char pad0[0xA]; unsigned short unkA; char padC[4]; Unk_Dr12 unk10[2]; Unk_Sprt20 unk28[4]; };
struct Unk_800E6858 { char pad0[0x1C]; Unk_800BFB64_list unk1C; char pad20[0x30]; int unk50; char pad54[6]; signed char unk5A; signed char unk5B; char pad5C[0x44]; int unkA0; char padA4[0x184]; char unk228[1]; };
EXTERN_C char D_800BA300[];
EXTERN_C char D_800BA33C[];
EXTERN_C void func_800E6858(Unk_800E6858* p, int mode);
struct Unk_C1438_s { int unk0; int unk4; };
struct Unk_800C1438 { char pad0[0x1C]; Unk_C1438_s unk1C; char pad24[0x18]; char* unk3C; char pad40[0x2C]; char unk6C[1]; char pad6D[0x7033]; Unk_Derived50* unk70A0; };
EXTERN_C int func_800C1438(Unk_800C1438* self, Unk_FlagArg* e);
EXTERN_C int func_80058488(void*, int);
struct Unk_DB120_e { char pad0[0x1C]; Unk_DB120_e() { func_80053928(this); } ~Unk_DB120_e(); };
struct Unk_800DB120 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; int unk68; Unk_DB120_e* unk6C; char* unk70; int unk74; Unk_Elem28 unk78[2]; Unk_VbObj vobj; };
EXTERN_C char D_800B979C[];
EXTERN_C Unk_800DB120* func_800DB120(Unk_800DB120* self, int in_chrg, int n);
struct Hg_E9650_o1 { void* vtbl; int unk4; short unk8; short unkA; };
struct Hg_E9650_s { char pad0[0x14]; int unk14; int unk18; int unk1C; };
struct Hg_E9650_p { char pad0[0x44]; VAt0* unk44; void* unk48; };
struct Hg_Hw { short a, b; };
struct Hg_L { int x; Hg_Hw h; int y, z; };
struct Hg_E9650_o2 { void* vtbl; int unk4; void* vtbl2; void* unkC; Hg_Hw unk10; short unk14; short unk16; int unk18; short unk1C; short unk1E; };
EXTERN_C char D_80010654[];
EXTERN_C char D_80010888[];
EXTERN_C char D_800108A0[];
EXTERN_C char D_800B4C48[];
EXTERN_C void func_80021ACC(void*, int);
EXTERN_C void func_80024BF0(void*, int, int, int);
EXTERN_C void func_80025444(void*, void*, int);
struct Hg_S4 { short r, g, b, a; };
EXTERN_C void func_8005F148(void*, Unk_Short4*);
EXTERN_C void func_800D2908_x(void* p, Hg_S4 c0, Hg_S4 c1, Hg_S4 c2, Hg_S4 c3) asm("func_800D2908");
EXTERN_C void func_800D2214(Unk_800D2214* p, Unk_800D2214_q* q);
struct Unk_800D277C;
EXTERN_C void func_800D277C(Unk_800D277C* p, Unk_Short4* q);
struct Hg_203C : Unk_Gt4_10 { char padx[0x34]; };
struct Hg_E760 : Unk_PadB8, Unk_800DE59C_b { char padC4[0x48]; int unk10C; char pad110[0x3C]; int unk14C; char pad150[4]; Unk_W4 unk154; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; Unk_W4 unk180; int unk190; int unk194; };
inline Unk_800DE59C_b* base(Hg_E760* p) { return p; }
inline Unk_W4 getW(Hg_E760* p) { return base(p)->unk8->unk1B8->unk34; }
EXTERN_C void func_80082C68(void*, int, int, int, int);
struct Unk_800CAD68 { char pad0[0x5C]; int unk5C; char pad60[0x24]; Unk_DualList unk84; };
EXTERN_C unsigned char func_800D05FC(Unk_800D05FC*);
EXTERN_C unsigned char func_800CAD68_i(Unk_800CAD68* p) asm("func_800CAD68");
struct Unk_800D2554 : Unk_Drawable { char pad4[0xC]; POLY_GT4 unk10[2]; Unk_Dr12 unk78[2]; Unk_Dr12 unk90[2]; };
struct Unk_800C44C4 { Unk_VBase* vb; char pad4[8]; Unk_Short2 unkC; char pad10[0x1C]; void* vt2C; char pad30[8]; char unk38[8]; void* vt40; int unk44; unsigned char unk48; char pad49; short unk4A; short unk4C; char pad4E[2]; Unk_VbObj vobj; };
EXTERN_C Unk_800C44C4* func_800C44C4_i(Unk_800C44C4* self, int in_chrg, unsigned char a, unsigned short b) asm("func_800C44C4");
struct Unk_DA6A4_i { int unk20; };
struct Unk_DA6A4_dl : Unk_800BFB64_list, Unk_DA6A4_i, Unk_List2 { };
struct Unk_DA6A4_q { char pad0[0x18]; unsigned short unk18; };
struct Unk_800DA6A4 { char pad0[0x1C]; Unk_DA6A4_dl unk1C; char pad28[0x14]; int unk3C; char pad40[0x22B0]; char unk22F0[0xB8]; int unk23A8[1]; char pad23AC[0xBC]; int unk2468; char pad246C[0x10]; VAt<0x18>* unk247C; char pad2480[8]; char unk2488[4]; };
EXTERN_C int func_800DB7E8(Unk_800DB7E8*, Unk_800DB7E8_a*);
EXTERN_C int func_800DA6A4(Unk_800DA6A4*, Unk_DA6A4_q*);
struct HK_E28 { int w0, w1, w2, w3, w4, w5, w6, w7; unsigned char b0, b1, b2, b3, b4, b5, b6, b7; };
struct HK_VEC { int x, y, z, w; };
struct HK_V { char pad[0x2C]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(short *a, int *b); };
struct HK_V2 : HK_V { char pad30[0x20]; };
struct HK_CV { unsigned char r, g, b, cd; };
struct HK_B { char pad0[0x2C]; short s7C, s7E, s80; short s82; int f84, f88, f8C; char pad40[0x78]; HK_CV fB8; int fBC; };
struct HK_G : HK_V2, HK_B { char pad110[0xC]; int f11C; };
struct HK_T { char pad[0x278]; HK_G *f278; char pad27C[0x10]; short s28C; short pad28E; int f290, f294, f298; int pad29C; int f2A0; unsigned short h2A4, h2A6, h2A8; short pad2AA; unsigned char b2AC, b2AD, b2AE, b2AF; int f2B0; HK_E28 e2D4[3]; HK_VEC n32C[3]; };
EXTERN_C void func_80099C80(int a);
EXTERN_C void func_80065D20(HK_B *g, int i, int x, int y, int z, int r, int gg, int b);
EXTERN_C void func_80065E10(HK_B *g, int i);
struct HK_G2 { char pad[0x94]; int f94; };
EXTERN_C void func_80065D20(HK_B *g, int i, int x, int y, int z, int r, int gg, int b);
EXTERN_C void func_80065E10(HK_B *g, int i);
EXTERN_C int func_800950A0(int);
EXTERN_C int _card_load(int);
EXTERN_C int _card_clear(int);
EXTERN_C int func_800E4D8C(void*);
EXTERN_C int func_800E5404(Unk_800E5404*);
struct Unk_800CAAD4 : Unk_Pad50, Unk_Base { char pad54[8]; int unk5C; char pad60[4]; int unk64; Unk_S4_800CBA70 unk68; int unk70; int unk74; int unk78; char pad7C[4]; int unk80; Unk_DualList unk84; char pad90[0x14]; char unkA4[8]; char unkAC[8]; char unkB4[8]; };
inline void call_CAAD4(VAt<0x2C>* o, Unk_800CAAD4* p, void* q) {
    Unk_S4_800CBA70 r = p->unk68;
    ((void (*)(void*, Unk_S4_800CBA70, void*))func_800D0608)(o, r, q);
}
struct Hm_Pt { short x, y; };
struct Hm_D2B30_s { char pad0[0x14]; int unk14; char pad18[4]; int unk1C; Hm_Pt pt; char pad24[4]; };
struct Unk_800D2B30 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; VAt0* unk38; void* unk3C; Unk_VbObj vobj; };
EXTERN_C Unk_800D2B30* func_800D2B30(Unk_800D2B30* self, int in_chrg, unsigned short a);
struct Unk_800D77F8 : VAt<0x18> { char pad1C[0x20]; void* unk3C; char pad40[0x24]; int unk64; char unk68[0x6C]; int unkD4; VAt<0x18>* unkD8[4]; char padE8[0x10]; Unk_800C9D60_sub* unkF8; char padFC[0xC]; VAt<0x18>* unk108; };
EXTERN_C void func_80054CA0(void*);
EXTERN_C int func_800D77F8(Unk_800D77F8* p, Unk_FlagArg* q);
struct Unk_800E3B68_vb { short a; short b; int c; };
struct Unk_800E3B68 { void* vtbl0; void* vb4; void* vtbl8; void* unkC; char pad10[0x14]; void* vtbl24; void* vb28; int unk2C; int unk30; int unk34; int unk38; int unk3C; char* unk40; char* unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; Unk_800E3B68_vb vb60; };
EXTERN_C char D_80012154[];
EXTERN_C char D_8001201C[];
EXTERN_C char D_80012034[];
EXTERN_C char D_800121AC[];
EXTERN_C Unk_800E3B68* func_800E3B68_i(Unk_800E3B68* p, int in_chrg, int a2, int a3, int a4, char* name) asm("func_800E3B68");
inline void init_vb(Unk_800E3B68_vb* v) { v->a = 0x10; v->b = 0; v->c = -1; }
struct Unk_800E7DEC { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; int unk68; int unk6C; Unk_Deletable18* unk70; Unk_Deletable18* unk74; int unk78; int unk7C; int unk80; char* unk84; int unk88; char unk8C[0x54]; int unkE0; int unkE4[7]; Unk_VbObj vobj; };
EXTERN_C Unk_800E7DEC* func_800E7DEC_i(Unk_800E7DEC* self, int in_chrg, char* s, int a3) asm("func_800E7DEC");
struct HR_Pad40 { char p[0x40]; };
struct HR_Pad48 { char p[0x48]; };
EXTERN_C void* func_800CF9A8_i(void*, int, int) asm("func_800CF9A8");
EXTERN_C void* func_800C807C_i(void*, int, int) asm("func_800C807C");
EXTERN_C void* func_800D2B30_i(void*, int, int) asm("func_800D2B30");
EXTERN_C int func_80026014(int);
EXTERN_C int rand();
EXTERN_C void func_8005D9D4(void*, int);
struct Unk_800C5BE8 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x4]; int unk60; char pad64[0x3270]; int unk32D4; Unk_VbObj vobj; };
#define SUB(o) ((char*)self + o)
EXTERN_C char D_800B78E4[];
EXTERN_C char D_800B7954[];
EXTERN_C char D_800B7934[];
EXTERN_C char D_800B7984[];
EXTERN_C char D_800B78C4[];
EXTERN_C char D_800B78C8[];
EXTERN_C char D_800B78D8[];
EXTERN_C void func_80062FA4_i(void*, int, void*, int) asm("func_80062FA4");
EXTERN_C void func_80062C3C(void*, int, void*, int, int);
EXTERN_C void func_80062848(void*, int, void*, void*, int, int);
EXTERN_C void func_800D508C(void*, int);
EXTERN_C void func_800D0CDC_i(void*, int, int, int) asm("func_800D0CDC");
struct Unk_800CEA30;
EXTERN_C Unk_800CEA30* func_800CEA30(Unk_800CEA30*, int, int, int, int);
struct Unk_800C5EE0;
EXTERN_C void func_800C5EE0(Unk_800C5EE0*);
struct Unk_800E1898 { char pad0[0x1C]; Unk_800BFB64_list unk1C; char pad20[0x64]; int unk84; Unk_800E0888_d* unk88; char unk8C[0x130]; char unk1BC[0x88]; Unk_800E1174_e unk244[15]; };
struct Unk_800E1898b { char pad0[0x158]; int unk158; int unk15C; char pad160[0x2628]; void* unk2788; };
EXTERN_C char D_800B9BB4[];
EXTERN_C char D_800B9BB8[];
EXTERN_C char D_800B9BF8[];
EXTERN_C char D_800B9C7C[];
EXTERN_C char D_800B9CBC[];
EXTERN_C char D_800B9CF0[];
EXTERN_C int func_800E4E70(void*);
struct Unk_800E6750;
EXTERN_C void* func_800E6A40(Unk_800E6750*);
EXTERN_C void func_800E3250(void*, int);
EXTERN_C int func_800E4920_i(void*, int) asm("func_800E4920");
struct Unk_800CE3BC { char pad0[0x18]; void* vt18; char pad1C[0x34]; char unk50[0x8]; void* vt58; char unk5C[0x28]; char unk84[0x28]; char unkAC[0x28]; char unkD4[0x1C]; char unkF0[0x1C]; char unk10C[0x1C]; char unk128[0x1C]; char unk144[0x1C]; };
EXTERN_C void func_80054584(void*, int);
EXTERN_C char D_800B8654[];
EXTERN_C char D_800B8660[];
struct Unk_800C09F0 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0xC]; int unk68; char unk6C[0x70]; char unkDC[0x160]; Unk_Hld3 unk23C; char unk248[0x14]; char unk25C[0x1DC]; char unk438[0x520]; char unk958[0x33C0]; char unk3D18[0x28C4]; char unk65DC[0x2E4]; char unk68C0[0xE8]; char unk69A8[0xE4]; char unk6A8C[0x618]; Unk_VbObj vobj; };
EXTERN_C const Unk_VTbl10 D_800B716C;
EXTERN_C char D_800B713C[];
EXTERN_C char D_800B71BC[];
EXTERN_C char D_800B71DC[];
EXTERN_C char D_800B711C[];
EXTERN_C void* func_800C9B58_c(void*, int) asm("func_800C9B58");
EXTERN_C void* func_800CEA30_c(void*, int, char*, int, int) asm("func_800CEA30");
EXTERN_C void* func_800CD224_c(void*, int) asm("func_800CD224");
EXTERN_C void* func_800C5544_c(void*, int) asm("func_800C5544");
EXTERN_C void* func_800C25DC_c(void*, int) asm("func_800C25DC");
EXTERN_C void* func_800D6720_c(void*, int) asm("func_800D6720");
EXTERN_C void* func_800C375C_c(void*, int) asm("func_800C375C");
EXTERN_C void* func_800C6B44_c(void*, int) asm("func_800C6B44");
EXTERN_C void* func_800C8410_c(void*, int) asm("func_800C8410");
EXTERN_C void* func_800CE3BC_c(void*) asm("func_800CE3BC");
struct Unk_800DA3E4 : VAt<0x18> { char pad1C[0x2260]; int unk227C; int unk2280; char unk2284[0x6C]; char unk22F0[0xB8]; int unk23A8[0x30]; int unk2468; VAt<0x2C>* unk246C; Unk_Deletable18* unk2470[3]; VAt<0x18>* unk247C; Unk_Deletable18* unk2480; Unk_Deletable18* unk2484; char unk2488[4]; };
EXTERN_C void* func_800DB5A4_c(void*, int) asm("func_800DB5A4");
EXTERN_C void func_800614BC(void*, int);
EXTERN_C void func_80061758(void*, void*);
EXTERN_C Unk_800B4DD0* D_800B4DD0_s asm("D_800B4DD0");
struct Unk_800D9EE0 { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x2220]; int unk227C; int unk2280; char pad2284[0x34C]; Unk_VbObj vobj; };
EXTERN_C char D_800B96BC[];
EXTERN_C char D_800B972C[];
EXTERN_C char D_800B970C[];
EXTERN_C char D_800B975C[];
EXTERN_C char D_800B9584[];
EXTERN_C char D_800B95A4[];
EXTERN_C char D_800B95B4[];
EXTERN_C Unk_800D9EE0* func_800D9EE0(Unk_800D9EE0* self, int in_chrg, int a2, int a3, int a4);
struct Unk_VbHdrH { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; };
struct Unk_800C38E0; EXTERN_C void func_800C38E0(Unk_800C38E0*, int);
struct Unk_800D80F0; EXTERN_C void func_800D80F0(Unk_800D80F0*, int);
EXTERN_C void func_800C3468(void*, int);
struct Unk_800C59D8; EXTERN_C void func_800C59D8(Unk_800C59D8*, int);
struct Unk_800CD6BC; EXTERN_C void func_800CD6BC(Unk_800CD6BC*, int);
struct Unk_800CF11C; EXTERN_C void func_800CF11C(Unk_800CF11C*, int);
struct Unk_800C94D4;
EXTERN_C void func_800C94D4(Unk_800C94D4*, int);
EXTERN_C void func_800C0C8C(Unk_800C09F0* self, int in_chrg);
static inline void d_69A8(Unk_800C7110* self, int in_chrg, Unk_VTbl10& vt) {
    self->vt54 = D_800B7A34;
    self->vt58 = D_800B7A14;
    self->vt18 = D_800B7A64;
    self->vb->vptr = (Unk_VTbl10*)&D_800B79C4;
    if (!in_chrg) {
        vt = D_800B79C4;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B79C4).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xDC));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B79C4).e[6].delta + adj;
    }
    func_80053964(self->unkB4, 2);
    ((void (*)(void*, int))func_80054C34)(self->unk64, 2);
    func_8005652C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}
static inline void d_DC(Unk_VbHdrH* s) {
    s->vt58 = D_800B8694;
    s->vt18 = D_800B8664;
    func_80053964((char*)s + 0x144, 2);
    func_80053964((char*)s + 0x128, 2);
    func_80053964((char*)s + 0x10C, 2);
    func_80053964((char*)s + 0xF0, 2);
    func_80053964((char*)s + 0xD4, 2);
    func_80053964((char*)s + 0xAC, 2);
    func_80053964((char*)s + 0x84, 2);
    func_80053964((char*)s + 0x5C, 2);
    func_800537DC((char*)s + 0x50, 0);
    ((void (*)(void*, int))func_80054C34)(s, 2);
}
static inline void d_6C(Unk_VbHdrH* s, int in_chrg, Unk_VTbl10& vt) {
    s->vt54 = D_800B80DC;
    s->vt58 = D_800B80BC;
    s->vt18 = D_800B810C;
    s->vb->vptr = (Unk_VTbl10*)&D_800B806C;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B806C);
        s->vb->vptr = &vt;
    }
    func_8005652C(s, 0);
    if (in_chrg & 2) {
        func_8001A610(s->vb, 0);
    }
}
struct Unk_800CB418 : Unk_Pad50, Unk_Base { char pad54[8]; int unk5C; int unk60; char pad64[8]; short unk6C; short unk6E; int unk70; int unk74; int unk78; char pad7C[4]; int unk80; Unk_DualList unk84; char pad90[0x14]; char unkA4[8]; char unkAC[8]; char unkB4[8]; int unkBC; int unkC0; };
EXTERN_C void func_800D0704_i(void*, void*) asm("func_800D0704");
struct Unk_800C7A7C : Unk_Hdr38d, Unk_Base { char pad3C[8]; int unk44; int unk48; int unk4C; };
struct Unk_C7A7C_e { char pad0[0x14C]; int unk14C; };
struct Unk_C7A7C_o { char pad0[0x328]; Unk_C7A7C_e* unk328; };
EXTERN_C void func_800D3B28(void*, int);
EXTERN_C int func_800C7A7C(Unk_800C7A7C* p);
struct Unk_800C7230_q { char pad0[0x14C]; int unk14C; };
struct Unk_800C7230_p { char pad0[0x328]; Unk_800C7230_q* unk328; };
struct Unk_800C7230 { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x8]; char unk38[0x8]; void* unk40; int unk44; int unk48; int unk4C; Unk_VbObj vobj; };
EXTERN_C unsigned char D_800EA0BC[];
EXTERN_C char D_800B7AA4[];
EXTERN_C char D_800B7BEC[];
EXTERN_C void func_800D31E8(int);
EXTERN_C Unk_800C7230* func_800C7230_i(Unk_800C7230* self, int in_chrg, unsigned short a) asm("func_800C7230");

#endif /* FIELD_FIELD_H */
