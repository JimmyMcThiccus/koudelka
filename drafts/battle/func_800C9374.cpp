// func_800C9374: NOT MATCHING. ~80 instructions differ: retail strength-reduces x+i / x-i into two induction registers; ours does not.
// Round-2 scratch prelude below; many of its types are now in battle.h.
#include "common.h"
#include "battle/battle.h"
/* Agent C near misses. Prelude = agentC.cpp prelude + the extra types below. */
EXTERN_C T_C1340 *D_800AFA64[];
EXTERN_C int func_800C13CC(void *p);
EXTERN_C int func_800C07F8(void *p, int a);
struct T_CAD5C_q { char pad[0x514]; short s514; };
struct T_CAD5C { char pad[0xA0]; T_CAD5C_q *fA0; char padA4[0x85C]; int f900; };
struct T_C5D84 { char pad[0x4C6]; short s4C6; short pad4C8; short s4CA; };
/* battle.h declares func_800C5D84 as void(void *, int); retail returns the removed object. */
EXTERN_C T_C5D84 *func_800C5D84_r(T_C5E1C *p, int a) __asm__("func_800C5D84");
struct T_C8EE4 { char pad[0x2C8]; signed char b2C8[1][5]; };
typedef int (*F_C8D9C)(void *p, int a, int *b, int *c);
struct T_C65C8 { char pad[0xA0]; char *fA0; T_C5474 fA4; };
typedef void (*F_C51D0)(void *a, void *b, int c);
EXTERN_C char *func_800C5474(T_C5474 *p);
EXTERN_C void func_800D94F4(void *p);
EXTERN_C void func_800D05C4(T_D0404 *p);
struct T_CCB98 { SVec2 f0; int pad4; int pad8; int fC; int f10; int f14; };
EXTERN_C char D_800B75F0[], D_800B7620[];
EXTERN_C void func_80078C38(void *p, char *fmt, int a, int b, int c, int d, int e, int f, int g, int h, int i);
struct T_C757C { char pad[0x2C4]; int f2C4; };
struct T_C9284 { char pad[0x410]; short s410; char pad412[0xAB]; signed char b4BD; char pad4BE[7]; signed char b4C5; short s4C6; short s4C8; short s4CA; char pad4CC[0x47E]; unsigned char b94A; };
struct T_L2EC {
    SVec2 f0[0x23]; int f8C; int f90;
    void reset() { f8C = 0; f90 = 0; }
    void push(SVec2C v) { f0[f8C++] = *(SVec2 *)&v; }
};
EXTERN_C void func_800C7F30(T_Grids *p, char v);
EXTERN_C int func_800B928C(T_B9268 *p, int *t);
struct T_C9A4C {
    char pad[0x14]; T_C9284 *f14[7][5]; T_C9284 *fA0; char padA4[0x224]; signed char b2C8[7][5]; char pad2EB;
    T_L2EC l2EC; signed char b380[7][5]; signed char b3A3[7][5]; char pad3C6[0x47E]; int f844; int f848; void *f84C[1];
};
EXTERN_C void func_800CA9D0(T_C9A4C *p, int a, int b);
struct SVec2I { short x, y; SVec2I(int a, int b) { x = a; y = b; } };
EXTERN_C void func_800C800C(void *p, SVec2I v, int a, int b, int c);
EXTERN_C void func_800C7D88(T_Grids *p);
EXTERN_C bool func_800C8A54(T_C9A4C *p, int x1, int y1, int x, int y);
EXTERN_C void func_800CE4E4(T_L2EC *l, SVec2C v, int a);
/* func_800CE4B4 is defined returning int in battle.cpp; the caller's codegen needs a bool return. */
EXTERN_C bool func_800CE4B4_b(T_L2EC *p) __asm__("func_800CE4B4");
inline bool l2ec_next(T_L2EC *l) { if (!func_800CE4B4_b(l)) return false; return true; }
inline void add_cell(T_C9A4C *p, int x, int y) {
    if (in_grid(x, y) && !p->b2C8[y][x]) { p->b380[y][x] = 1; p->f84C[p->f848++] = p->f14[y][x]; }
}
struct T_CB8EC_k { int f0; T_CB8EC_k(int v) { f0 = v; } };
EXTERN_C T_BE0F8 *func_800BE0F8(T_BE0F8 *p, T_BE0F8 *q);
inline T_BE0F8 *put(T_BE0F8 *t, const T_CB8EC_k &k) { return func_800BE0F8(t, (T_BE0F8 *)&k); }
struct T_CB8EC { char pad[0x3D0]; int f3D0; };
struct T_CDD0C_v {
    short x, y;
    T_CDD0C_v() { x = 0; y = 0; }
    T_CDD0C_v(short a, short b) { x = a; y = b; }
    bool operator!=(const T_CDD0C_v &o) const { return x != o.x || y != o.y; }
};
/* The empty destructor matters: temporaries then get EH cleanups, which reserves the 16-byte outgoing-arg area even in leaf functions. */
struct T_CDD0C_e {
    T_CDD0C_v f0; int f4; short s8; char padA[0xE];
    T_CDD0C_e() { f0 = T_CDD0C_v(); f4 = 0; s8 = 0; }
    T_CDD0C_e(const T_CDD0C_v &v) { f0 = v; f4 = 0; s8 = 0; }
    T_CDD0C_e(const T_CDD0C_v &v, int a) { f0 = v; f4 = a; s8 = 0; }
    ~T_CDD0C_e() {}
};
struct T_CDD0C { int f0; int f4; int f8; int fC; T_CDD0C_e f10[41]; T_CDD0C_e f3E8; };
struct T_CDD0C2 {
    int f0; int f4; int f8; int fC; T_CDD0C_e f10[41]; T_CDD0C_e f3E8;
    T_CDD0C2() __asm__("func_800CDD0C");
};
EXTERN_C int func_800C7DD0(void *p, int h, int a, int b);
EXTERN_C void func_800C8EE4(T_C8EE4 *p, int a);
EXTERN_C void func_800C7B5C(void *p, int a, void *b, int x, int y);
EXTERN_C void *func_80085AD4(void *p, short x, short y);
/* battle.h declares func_800C78EC as void; retail returns the count. */
EXTERN_C int func_800C78EC_i(T_C9A4C *p, int a) __asm__("func_800C78EC");
inline void place(T_C9A4C *p, int a, int b, int c) { p->b2C8[b][a] = 0; func_800C7764(p, a, b, 1, c); }
struct T_C6050_c { char pad[0x400]; char f400[0x80]; unsigned short h480; char pad482[0x2B]; char b4AD; char b4AE; char pad4AF; int f4B0; int f4B4; short s4B8; };
struct T_C6050_n { T_C6050_n *next; T_C6050_n *prev; int pad8; int fC; };
struct T_C6050 { char pad[0xA4]; T_C5474 fA4; char pad1D4[0x65C]; int f830; };
EXTERN_C void func_80086E14(void *p);
EXTERN_C void func_800D8FF8(void *p);
EXTERN_C void func_800C6194(T_C6050 *p);
inline void c6050_reset(T_C6050 *p, T_C6050_c *c) {
    func_80086E14(c->f400);
    c->f4B0 = 3; c->s4B8 = 0; c->f4B4 = 0; c->b4AD = 0; c->b4AE = 0;
    func_800D8FF8(c->f400);
    ((F_C51D0)func_800C51D0)(&p->fA4, c, c->h480);
}
struct T_CA7D4 { char pad[0xA0]; T_C9284 *fA0; char padA4[0x850]; int f8F4[24]; unsigned char b954; unsigned char b955; };
EXTERN_C void func_800CA918(void *p, int a);
inline bool moved(T_C9284 *q, int x, int y) { return x != q->s4C6 || y != q->s4CA; }
EXTERN_C void func_800C8BA4(T_C9A4C *p, int x1, int y1, int x, int y);
/* battle.h declares func_800C7764 with void *p; the cast copy changes register allocation. */
EXTERN_C void func_800C7764_t(T_C9A4C *p, int x, int y, int d, int max) __asm__("func_800C7764");
struct T_CC7DC_q { char pad[0x4D8]; int f4D8; };
struct T_CC7DC_e {
    T_CDD0C_v f0; void *f4; unsigned short h8; short sA; int fC; int f10; int f14;
    bool at(const T_CDD0C_v &v) { return f0.x == v.x && f0.y == v.y; }
};
struct T_CC7DC { char pad[0x14]; T_C9284 *f14[7][5]; T_CC7DC_q *fA0; char padA4[0x2DC]; signed char b380[7][5]; char pad3A3[0x35]; T_CE044 f3D8; };
inline T_CC7DC_e *cc7dc_first(T_CC7DC *p) { return (T_CC7DC_e *)func_800CE044(&p->f3D8); }
inline T_CC7DC_e *cc7dc_next(T_CC7DC *p) { return (T_CC7DC_e *)func_800CE090(&p->f3D8); }
EXTERN_C void func_800CA7D4(T_CA7D4 *p, int a, int x, int y, int e);
struct T_C9FFC_in { char pad[0x1A]; unsigned short h1A; };
struct T_C9FFC { char pad[0xA0]; T_C9284 *fA0; char padA4[0x322]; T_CDD0C_v s3C6; char pad3CA[2]; int f3CC; int f3D0; };
EXTERN_C void func_800CF95C(T_CF95C *p);
EXTERN_C int func_800CA1B4(T_C9FFC *p, T_CDD0C_v *pos, int dir, int a, int b);
inline int c9ffc_move(T_C9FFC *p, int dir, int arg) {
    int d = (dir - p->f3CC + 8) % 8 / 2;
    if (func_800CA1B4(p, &p->s3C6, d, arg, 0) < 0) { func_8008EF40(14); return 0; }
    func_800CA7D4((T_CA7D4 *)p, 1, p->s3C6.x, p->s3C6.y, 1);
    func_8008EF40(8);
    func_800CF9CC((T_CF95C *)p, p->s3C6.x, p->s3C6.y);
    return 1;
}
inline int c9ffc_dir(T_C9FFC *p, int b, int arg) {
    int dir;
    if (b & 0x10) dir = 0;
    else if (b & 0x20) dir = 2;
    else if (b & 0x40) dir = 4;
    else if (b & 0x80) dir = 6;
    else return 0;
    return c9ffc_move(p, dir, arg);
}
struct T_CE154_k {
    T_CDD0C_v pos; int f4;
    T_CE154_k() {}
    T_CE154_k(T_CDD0C_v v) : pos(v) { f4 = 0; }
    T_CE154_k(int a) { f4 = a; }
};
EXTERN_C int func_800CE854(T_CE154_k *k, T_CDD0C_e *a, T_CDD0C_e *b);
struct T_CA918_cc { unsigned char r, g, b, a; T_CA918_cc() {} };
EXTERN_C void func_8003FB88x(void *p, int a, T_CA918_cc c) __asm__("func_8003FB88");
struct T_C5F84_s { int x, y, z, w; T_C5F84_s() {} T_C5F84_s(short a, short b, short c, short d) { x = a; y = b; z = c; w = d; } };
struct T_C5F84_t : T_C5F84_s { T_C5F84_t(const SVec4 &v) : T_C5F84_s(v.x, v.y, v.z, v.w) {} };
struct T_C5F84 { char pad[0x4C6]; SVec4 f4C6; SVec4 pos() { return f4C6; } };
inline int iabs(int x) { return x < 0 ? -x : x; }
struct T_LNode { T_LNode *next; T_LNode *prev; };
struct T_LIter {
    T_LNode *head; T_LNode *cur; int f8; int fC;
    void first() { cur = head; }
    bool empty() { return head == 0; }
    bool last() { return !empty() && head->prev == cur; }
    void next() { if (head) { if (!last()) cur = cur->next; } }
};
struct T_C8D9C { int pad0; T_LIter it; };
inline T_C9284 *c8d9c_obj(T_LNode *n) { return n ? (T_C9284 *)((char *)n - 0x4A0) : 0; }
EXTERN_C int func_800C8D9C_i(T_C8D9C *p, int side, int *hi, int *lo) __asm__("func_800C8D9C");
struct T_C7604 { char pad[0x82C]; int f82C; int f830; };
inline void c7604_post(int code) {
    T_B9844 *o = (T_B9844 *)func_8001CA10(0x14);
    void *g = D_800AF470[0];
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_80010300;
    o->s8 = 2;
    o->sA = 2;
    o->f10 = code;
    o->fC = 0;
    o->vtbl = D_800102D0;
    func_8001EFE4(g, o);
}
EXTERN_C void func_800BFBCC(T_BFCB8 *p, int a);
EXTERN_C void func_800BFC60(T_BFCB8 *p);
EXTERN_C void func_80085BA4(void *l);
EXTERN_C void func_80085BD8(void *l, int f);
EXTERN_C void func_800C7A28(T_C9A4C *p, void *l, int x, int y);
struct T_CAAF8_n : T_Obj8 { short sC; short sE; };
struct T_CAAF8 { char pad[0x834]; int f834; int f838; int f83C; int f840; };
// func_800CA918: 21 instructions differ: retail keeps q in a2 and the else-branch call does `a0 = a2`; ours reuses a0.
//   func_8003FB88's third arg is a 4-byte colour passed by value.
//@ func_800C9374
EXTERN_C int func_800C9374(T_C9A4C *p, int a, T_C9284 *q, int c, int n) {
    p->f848 = 0;
    func_800CA9D0(p, c, 3);
    func_800C7F30((T_Grids *)p, 0);
    if (c != 12 && !q->s410) return 0;
    int x = q->s4C6, y = q->s4CA;
    add_cell(p, x, y);
    for (int i = 1; i < n + 1; i++) { add_cell(p, x + i, y); add_cell(p, x - i, y); }
    return p->f848;
}
