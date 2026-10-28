// near: array version of func_800D75D4 (stride 0xA8, count in a1 spilled to its arg slot). Differs mainly because loop.c hoists the 0xFFFFFF addPrim mask (spilled to the stack) where retail keeps both masks inside the loop; same issue as func_800D6DE8.
#include "common.h"
#include "effect/effect.h"

#define gte_ldv0_800D7170(r0) __asm__ volatile("lwc2 $0, %0
	lwc2 $1, %1" : : "m"(((int *)(r0))[0]), "m"(((int *)(r0))[1]))
#define gte_rtps_800D7170() __asm__ volatile("nop\n\tnop\n\t.word 0x4A180001")
#define gte_mfsxy2_800D7170(r0) __asm__ volatile("mfc2 %0, $14\n\tnop" : "=r"(r0))
#define gte_mfsz3_800D7170(r0) __asm__ volatile("mfc2 %0, $19\n\tnop" : "=r"(r0))

struct Tag_800D7170 {
    unsigned addr : 24;
    unsigned len : 8;
};

struct FT4_800D7170 {
    Tag_800D7170 tag;
    unsigned int rgbc;
    short x0, y0;
    unsigned int uv0;
    short x1, y1;
    unsigned int uv1;
    short x2, y2;
    unsigned int uv2;
    short x3, y3;
    unsigned int uv3;
};

struct OT_800D7170 {
    char pad[0x10];
    unsigned int size;
    Tag_800D7170 *ot;
};

struct Head_800D7170 {
    char pad[0x34];
};

struct Tex_800D7170 {
    unsigned int rgbc;
    unsigned int uv[4];
};

struct Obj_800D7170 : Head_800D7170, Tex_800D7170 {
    FT4_800D7170 prim[2];
    short scale, a, b, c;
    SVec4 pos;
};

EXTERN_C int D_800B4CF0[];
EXTERN_C OT_800D7170 *D_800B4D00[];
EXTERN_C int func_800260A4(int a);
EXTERN_C int func_80026014(int a);

EXTERN_C void func_800D7170(Obj_800D7170 *self, int n)
{
    FT4_800D7170 *p;
    int sxy, sy, sz;
    int dx1, dy1, dx2, dy2;
    Tex_800D7170 *t;
    unsigned int o;
    OT_800D7170 *d;
    while (n--) {
        gte_ldv0_800D7170(&self->pos);
        gte_rtps_800D7170();
        p = &self->prim[D_800B4CF0[0]];
        p->rgbc = self->rgbc;
        gte_mfsxy2_800D7170(sxy);
        sy = sxy >> 16;
        gte_mfsz3_800D7170(sz);
        if (sz > 0) {
            dx1 = FIELD_AT((void *)D_800E583C[0], int, 0x11C) * (short)((self->scale * func_800260A4(self->c + self->b + self->a) + 0x800) >> 12) / sz;
            dy1 = FIELD_AT((void *)D_800E583C[0], int, 0x11C) * (short)((self->scale * func_80026014(self->c + self->b + self->a) + 0x800) >> 12) / sz;
            dx2 = FIELD_AT((void *)D_800E583C[0], int, 0x11C) * (short)((self->scale * func_800260A4(self->c + self->b - (self->a - 0x1000)) + 0x800) >> 12) / sz;
            dy2 = FIELD_AT((void *)D_800E583C[0], int, 0x11C) * (short)((self->scale * func_80026014(self->c + self->b - (self->a - 0x1000)) + 0x800) >> 12) / sz;
            p->x0 = sxy + dx1;
            p->x3 = sxy - dx1;
            p->y0 = sy + dy1;
            p->y3 = sy - dy1;
            p->x1 = sxy + dx2;
            p->x2 = sxy - dx2;
            p->y1 = sy + dy2;
            p->y2 = sy - dy2;
            t = self;
            {
                unsigned int a = t->uv[0], b = t->uv[1], c = t->uv[2], e = t->uv[3];
                p->uv0 = a;
                p->uv1 = b;
                p->uv2 = c;
                p->uv3 = e;
            }
            o = sz >> 2;
            d = D_800B4D00[0];
            if (o && o < d->size) {
                p->tag.addr = d->ot[o].addr;
                *(unsigned int *)&d->ot[o] = (unsigned int)p & 0x00FFFFFF;
            }
        }
        self++;
    }
}
