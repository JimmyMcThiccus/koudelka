// func_800C40B8: 3 differing instructions: $v0/$v1 swapped for the x50 and x58 loads (register allocation).
// typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef short s16;
// typedef unsigned int u32; typedef int s32;
struct H { s32 x0; char d[0x5C]; char e[0x20]; char rows[1][128]; };
struct A { char pad[0x50]; s32 x50; char* x54; H* x58; };
extern "C" char* func_800C40B8(A* p) { char* r = (char*)p->x58->rows; return r + p->x50 * 128; }
