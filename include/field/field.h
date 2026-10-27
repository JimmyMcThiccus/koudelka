#ifndef FIELD_FIELD_H
#define FIELD_FIELD_H

#include "common.h"

/* Classes whose real names are unknown are named after the first function that
   uses them. Only the fields seen so far are named. */

struct Unk_800BB230 { char pad0[0x4]; int unk4; char pad8[0x40]; int unk48; };
struct Unk_800BCBE8 { char pad0[0x644]; int unk644; char pad648[0x4]; int unk64C; char pad650[0x4]; int unk654; char pad658[0xC]; int unk664; };
struct Unk_800BD3E0 { char pad0[0x8]; short unk8; short unkA; signed char unkC; char padD[3]; int unk10; int unk14; int unk18; char pad1C[4]; signed char unk20; };
struct Unk_800BF204 { char pad0[0x100]; char unk100; char unk101; char pad102[0x176]; int unk278; char pad27C[0x10]; short unk28C; char pad28E[0x14C]; short unk3DA; char pad3DC[0x74]; char unk450[0x44]; char unk494[0xB0]; char unk544[0x24]; };
struct Unk_800BF420 { char pad0[0x8]; int unk8; int unkC; signed char unk10; signed char unk11; short unk12; short unk14; short pad16; int unk18; int unk1C; };
struct Unk_800BF488 { void* vtbl; int unk4; char unk8; char pad9; short unkA; int unkC; };
struct Unk_800BF9BC { char pad0[0x44]; int unk44; char pad48[0x5C8]; char unk610[4]; };
struct Unk_800C0540 { char pad0[0x8]; short unk8; short padA; char unkC[0x20]; short unk2C; short pad2E; int unk30; char pad34[4]; int unk38; };
struct Unk_800C07E0 { void* vtbl; int unk4; signed char unk8; char pad9; unsigned short unkA; int unkC; };
struct Unk_800C46E4 { char pad0[0x44]; int unk44; };
struct Unk_800CEC9C { char pad0[0x20]; int unk20; };
struct Unk_800D05FC { char pad0[0x38]; unsigned char unk38; };
struct Unk_800D56BC { char pad0[0xA40]; int unkA40; };
struct Unk_800DBA18 { char pad0[0x68]; int unk68; };
struct Unk_800DED0C { char pad0[0x240]; int unk240; };
struct Unk_800E082C { char pad0[0x2EFC]; signed char unk2EFC; };
struct Unk_800E4290 { char pad0[0x58]; int unk58; int unk5C; };
struct Unk_800E51EC { char pad0[0x38]; int unk38; char pad3C[8]; int unk44; int unk48; int unk4C; int unk50; int unk54; };
struct Unk_800E6750 { char pad0[0x50]; int unk50; char unk54[9]; char unk5D[0x43]; int unkA0; };
struct Unk_800E83B8 { char pad0[0x68]; int unk68; char pad6C[0xC]; int unk78; int unk7C; int unk80; };

#endif /* FIELD_FIELD_H */
