// NEAR MISS (1028 vs 1036 bytes): logic, stack layout and the gte_CompMatrix block match; register allocation differs: retail keeps &m1 (sp+0x30) in $s5, &m2 (sp+0x50) in $s0 and the DD058 return slot / &rot (sp+0xA0) in $s1 across the loop, here they are rematerialised with addiu sp. Same problem as func_800DC99C.
#include "common.h"
#include "effect/effect.h"

/* PsyQ inline_c.h GTE macros */
#define gte_SetRotMatrix(r0) __asm__ volatile( \
    "lw $12, 0(%0)\n\t" \
    "lw $13, 4(%0)\n\t" \
    "ctc2 $12, $0\n\t" \
    "ctc2 $13, $1\n\t" \
    "lw $12, 8(%0)\n\t" \
    "lw $13, 12(%0)\n\t" \
    "lw $14, 16(%0)\n\t" \
    "ctc2 $12, $2\n\t" \
    "ctc2 $13, $3\n\t" \
    "ctc2 $14, $4" \
    : : "r"(r0) : "$12", "$13", "$14")
#define gte_ldclmv(r0) __asm__ volatile( \
    "lhu $12, 0(%0)\n\t" \
    "lhu $13, 6(%0)\n\t" \
    "lhu $14, 12(%0)\n\t" \
    "mtc2 $12, $9\n\t" \
    "mtc2 $13, $10\n\t" \
    "mtc2 $14, $11" \
    : : "r"(r0) : "$12", "$13", "$14")
#define gte_rtir() __asm__ volatile("nop\n\tnop\n\t.word 0x4A49E012")
#define gte_stclmv(r0) __asm__ volatile( \
    "mfc2 $12, $9\n\t" \
    "mfc2 $13, $10\n\t" \
    "mfc2 $14, $11\n\t" \
    "sh $12, 0(%0)\n\t" \
    "sh $13, 6(%0)\n\t" \
    "sh $14, 12(%0)" \
    : : "r"(r0) : "$12", "$13", "$14", "memory")
#define gte_SetTransMatrix(r0) __asm__ volatile( \
    "lw $12, 20(%0)\n\t" \
    "lw $13, 24(%0)\n\t" \
    "ctc2 $12, $5\n\t" \
    "lw $14, 28(%0)\n\t" \
    "ctc2 $13, $6\n\t" \
    "ctc2 $14, $7" \
    : : "r"(r0) : "$12", "$13", "$14")
#define gte_ldlv0(r0) __asm__ volatile( \
    "lhu $13, 4(%0)\n\t" \
    "lhu $12, 0(%0)\n\t" \
    "sll $13, $13, 16\n\t" \
    "or $12, $12, $13\n\t" \
    "mtc2 $12, $0\n\t" \
    "lwc2 $1, 8(%0)" \
    : : "r"(r0) : "$12", "$13")
#define gte_rt() __asm__ volatile("nop\n\tnop\n\t.word 0x4A480012")
#define gte_stlvnl(r0) __asm__ volatile( \
    "swc2 $25, 0(%0)\n\t" \
    "swc2 $26, 4(%0)\n\t" \
    "swc2 $27, 8(%0)" \
    : : "r"(r0) : "memory")
#define gte_MulMatrix0(r1, r2, r3) \
    { \
        gte_SetRotMatrix(r1); \
        gte_ldclmv(r2); \
        gte_rtir(); \
        gte_stclmv(r3); \
        gte_ldclmv((char *)(r2) + 2); \
        gte_rtir(); \
        gte_stclmv((char *)(r3) + 2); \
        gte_ldclmv((char *)(r2) + 4); \
        gte_rtir(); \
        gte_stclmv((char *)(r3) + 4); \
    }
#define gte_CompMatrix(r1, r2, r3) \
    { \
        gte_MulMatrix0(r1, r2, r3); \
        gte_SetTransMatrix(r1); \
        gte_ldlv0(&(r2)->t[0]); \
        gte_rt(); \
        gte_stlvnl(&(r3)->t[0]); \
    }

inline void *operator new[](unsigned int, void *p) { return p; }

EXTERN_C int ratan2(int y, int x);
EXTERN_C Vec4 func_800DD058(Vec4 *a, Vec4 *b);
EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, void *rot);
EXTERN_C void func_8003B2F0(void *m, Vec4 *t);
EXTERN_C void ApplyMatrixLV(void *m, Vec4 *in, Vec4 *out);

struct SV_800DC264 {
    short x, y, z, w;
    SV_800DC264() { x = 0; y = 0; z = 0; w = 0; }
};

struct Mat_800DC264 {
    short m[3][3];
    short pad;
    int t[3];
    Mat_800DC264() { func_8003A754(this, 0x1000); }
};

struct Rec_800DC264 {
    int x, y, z;
    int pad;
    SVec4 rot;
    int h;
};

EXTERN_C void func_800DC264(void *self)
{
    if (FIELD_AT(self, void *, 0x2C)) {
        Rec_800DC264 *r;
        int i;
        FIELD_AT(self, Mat_800DC264 *, 0x30) =
            new (func_800A0D2C(FIELD_AT(self, short, 0x0) * sizeof(Mat_800DC264))) Mat_800DC264[FIELD_AT(self, short, 0x0)];
        FIELD_AT(self, int *, 0x34) = (int *)func_800A0D2C(FIELD_AT(self, short, 0x0) * sizeof(int));
        r = FIELD_AT(self, Rec_800DC264 *, 0x2C);
        Vec4 a = FIELD_AT(self, Vec4, 0x4);
        Vec4 b = FIELD_AT(self, Vec4, 0x14);
        Mat_800DC264 m1;
        Mat_800DC264 m2;
        Mat_800DC264 m3;
        Vec4 d;
        d = func_800DD058(&b, &a);
        {
            SV_800DC264 rot;
            rot.x = 0;
            rot.y = ratan2(d.x, d.z) - 0x800;
            rot.z = 0;
            func_8003A7FC(&m1, &rot);
            i = 0;
            while (1) {
                if (!(i < FIELD_AT(self, short, 0x0)))
                    break;
                Vec4 in(r->x, r->y, r->z, 0);
                ApplyMatrixLV(&m1, &in, (Vec4 *)r);
                r->x += a.x;
                r->y += a.y;
                r->z += a.z;
                SVec4 rr = r->rot;
                func_8003A7FC(&m2, &rr);
                gte_CompMatrix(&m1, &m2, &FIELD_AT(self, Mat_800DC264 *, 0x30)[i]);
                Vec4 t(r->x, r->y, r->z, 0);
                func_8003B2F0(&FIELD_AT(self, Mat_800DC264 *, 0x30)[i], &t);
                FIELD_AT(self, int *, 0x34)[i++] = (r++)->h;
            }
        }
        if (FIELD_AT(self, void *, 0x2C))
            func_800A0D0C(FIELD_AT(self, void *, 0x2C));
        FIELD_AT(self, void *, 0x2C) = 0;
    }
}
