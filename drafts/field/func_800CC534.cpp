// func_800CC534: 117 differing, 536 vs 544 bytes. 4 unrolled rotate blocks ((x*c-y*s+0x800)/0x1000 etc., D_800B4CF0 double-buffer, stride 0x28). Retail makes two extra copies in block 1 (s1=c, t0=s) and block 4 uses those copies; blocks 1-3 use the originals. Helper-inline/refs/by-value variants all worse.
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"
struct Unk_800CC534_pt { short x, y; int pad; };
struct Unk_800CC534_e { char pad0[0x18]; Unk_800CC534_pt pt[4]; };
EXTERN_C void func_800CC534(void* vp, int a) {
    int b = D_800B4CF0[0];
    int c = func_800260A4(a);
    int s = func_80026014(a);
    Unk_800CC534_e* q = (Unk_800CC534_e*)((char*)vp + b * 0x28);
    { int x = q->pt[0].x; int t = (x * c - q->pt[0].y * s + 0x800) / 0x1000; q->pt[0].x = t; q->pt[0].y = (x * s + q->pt[0].y * c + 0x800) / 0x1000; }
    { int x = q->pt[1].x; int t = (x * c - q->pt[1].y * s + 0x800) / 0x1000; q->pt[1].x = t; q->pt[1].y = (x * s + q->pt[1].y * c + 0x800) / 0x1000; }
    { int x = q->pt[2].x; int t = (x * c - q->pt[2].y * s + 0x800) / 0x1000; q->pt[2].x = t; q->pt[2].y = (x * s + q->pt[2].y * c + 0x800) / 0x1000; }
    { int x = q->pt[3].x; int t = (x * c - q->pt[3].y * s + 0x800) / 0x1000; q->pt[3].x = t; q->pt[3].y = (x * s + q->pt[3].y * c + 0x800) / 0x1000; }
    func_8005F1D8(vp);
}
