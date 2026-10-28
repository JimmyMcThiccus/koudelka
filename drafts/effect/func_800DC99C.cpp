// NEAR MISS (696 vs 700 bytes): logic and stack layout match; register allocation differs: retail keeps the func_800DD058 return-slot address (sp+0x40, later &v) in $s1->$s5 and the matrix 'this' (sp+0x58) in $s0->$s6 (copied right after func_8003A754); here &m is recomputed after ratan2 and the temp address lands in $s0.
#include "common.h"
#include "effect/effect.h"

/* PsyQ inline_c.h GTE macros */
#define gte_ldlvl(r0) __asm__ volatile( \
    "lhu $12, 0(%0)\n\t" \
    "lhu $13, 4(%0)\n\t" \
    "lhu $14, 8(%0)\n\t" \
    "mtc2 $12, $9\n\t" \
    "mtc2 $13, $10\n\t" \
    "mtc2 $14, $11" \
    : : "r"(r0) : "$12", "$13", "$14")
#define gte_sqr0() __asm__ volatile("nop\n\tnop\n\t.word 0x4AA00428")
#define gte_stmac1(r0) __asm__ volatile("swc2 $25, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac3(r0) __asm__ volatile("swc2 $27, 0(%0)" : : "r"(r0) : "memory")

inline void *operator new[](unsigned int, void *p) { return p; }

EXTERN_C int ratan2(int y, int x);
EXTERN_C int SquareRoot0(int a);
EXTERN_C Vec4 func_800DD058(Vec4 *a, Vec4 *b);
EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, void *rot);
EXTERN_C void ApplyMatrixLV(void *m, Vec4 *in, Vec4 *out);

struct SV_800DC99C {
    short x, y, z, w;
    SV_800DC99C() { x = 0; y = 0; z = 0; w = 0; }
    SV_800DC99C(short ax, short ay, short az, short aw) : x(ax), y(ay), z(az), w(aw) {}
};

struct Mat_800DC99C {
    int m[8];
    Mat_800DC99C() { func_8003A754(this, 0x1000); }
};

struct Raw_800DC99C {
    int m[8];
};

inline Raw_800DC99C *mat_init_800DC99C(Raw_800DC99C *m)
{
    func_8003A754(m, 0x1000);
    return m;
}

struct Rec_800DC99C {
    int x, y, z;
    int pad[2];
};

EXTERN_C void func_800DC99C(void *self)
{
    if (FIELD_AT(self, void *, 0x2C)) {
        Rec_800DC99C *r;
        int i;
        FIELD_AT(self, SV_800DC99C *, 0x30) =
            new (func_800A0D2C(FIELD_AT(self, short, 0x0) * sizeof(SV_800DC99C))) SV_800DC99C[FIELD_AT(self, short, 0x0)];
        Vec4 a = FIELD_AT(self, Vec4, 0x4);
        Vec4 b = FIELD_AT(self, Vec4, 0x14);
        r = FIELD_AT(self, Rec_800DC99C *, 0x2C);
        Vec4 d;
        d = func_800DD058(&b, &a);
        {
            Vec4 v(0, 0, 0, 0);
            SV_800DC99C rot;
            Raw_800DC99C m;
            Vec4 *pv = &v;
            Raw_800DC99C *pm = mat_init_800DC99C(&m);
            rot.x = 0;
            rot.y = ratan2(d.x, d.z) - 0x800;
            rot.z = 0;
            func_8003A7FC(pm, &rot);
            i = 0;
            while (1) {
                int ry;
                int p, q;
                if (!(i < FIELD_AT(self, short, 0x0)))
                    break;
                Vec4 in(r->x, r->y, r->z, 0);
                ApplyMatrixLV(pm, &in, pv);
                gte_ldlvl(pv);
                gte_sqr0();
                ry = ratan2(v.x, v.z) - 0x800;
                gte_stmac1(&p);
                gte_stmac3(&q);
                SV_800DC99C s(ratan2(v.y, SquareRoot0(p + q)), ry, 0, 0);
                v.x += a.x;
                v.y += a.y;
                v.z += a.z;
                r->x = v.x;
                r->y = v.y;
                r->z = v.z;
                FIELD_AT(self, SV_800DC99C *, 0x30)[i].x = s.x;
                FIELD_AT(self, SV_800DC99C *, 0x30)[i].y = s.y;
                FIELD_AT(self, SV_800DC99C *, 0x30)[i].z = s.z;
                i++;
                r++;
            }
        }
    }
}
