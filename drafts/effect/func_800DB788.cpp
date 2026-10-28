// ~119 differ but logic and stack layout match: (1) GCC keeps &to (sp+0x10) in $s3 across calls, retail rematerialises it (one fewer saved reg, ang in $s2/pos in $s3); (2) retail's 16-byte copies use $t1-$t4, this uses $a3,$t0-$t2. Temps vs locals: 'dir = f()' / 'e = f()' (assignment) gives the retail temp+copy layout.
#include "common.h"
#include "effect/effect.h"

EXTERN_C Vec4 func_800DBD5C(Vec4 *a, Vec4 *b);
EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C int ratan2(int y, int x);
EXTERN_C int SquareRoot0(int a);
EXTERN_C void ApplyMatrixLV(void *m, Vec4 *v, Vec4 *out);

struct Mat_800DB788 {
    int m[8];
    Mat_800DB788() { func_8003A754(this, 0x1000); }
};

EXTERN_C void func_800DB788(SlotSet *self, SVec4 *ang, Vec4 *pos)
{
    void *o = (void *)(self->slots[2] ? self->slots[2] : self->slots[0]);
    Vec4 to = FIELD_AT(o, Vec4, 0x5C);
    Vec4 from = FIELD_AT(o, Vec4, 0x4C);
    Vec4 dir;
    dir = func_800DBD5C(&from, &to);
    Mat_800DB788 m;
    SVec4 rot;
    rot.x = 0;
    rot.y = ratan2(dir.x, dir.z) - 0x800;
    rot.z = 0;
    rot.w = 0;
    int x = -1000;
    if (dir.x < 0)
        x = 1000;
    Vec4 off(x, -2000, -7000, 0);
    func_8003A7FC(&m, &rot);
    ApplyMatrixLV(&m, &off, pos);
    pos->x += from.x;
    pos->y += from.y;
    pos->z += from.z;
    Vec4 e;
    e = func_800DBD5C(pos, &to);
    ang->x = ratan2(e.y, SquareRoot0(e.x * e.x + e.z * e.z));
    ang->y = ratan2(e.x, e.z) - 0x800;
    ang->z = 0;
}
