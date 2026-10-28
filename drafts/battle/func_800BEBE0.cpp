// func_800BEBE0: NOT MATCHING. ~126 differ but mostly a 1-insn shift: prologue param loads (h,i lhu) scheduled after vtbl/e instead of before; end volatile D_800A4534.fC load order/regs
// Round-2 scratch prelude below; many of its types are now in battle.h.
#include "common.h"
/* Near misses from agent B; the prelude is a copy of agentB.cpp's (needs the old D_800AEBD4 decl for C3D2C). */
/* battle.h declares these with other signatures; retail returns the first arg (BE09C, BE108)
   and C1A6C takes a second arg. Landing: change battle.h to the declarations below. */
#define func_800BE09C func_800BE09C_hdr
#define func_800BE108 func_800BE108_hdr
#define func_800C1A6C func_800C1A6C_hdr
#define func_800C5020 func_800C5020_hdr
#define func_800C0694 func_800C0694_hdr
#include "battle/battle.h"
#undef func_800BE09C
#undef func_800BE108
#undef func_800C1A6C
#undef func_800C5020
#undef func_800C0694
EXTERN_C T_BE0F8 *func_800BE09C(T_BE0F8 *p);
EXTERN_C T_BE0F8 *func_800BE108(T_BE0F8 *p, void *q);
EXTERN_C void *func_800C1A6C(void *p, int team);
EXTERN_C void *func_800C5020(void *p, char *s, int n);
EXTERN_C int func_800C0694(struct T_C0694 *p, int a);
struct T_BE208 { int v[6]; };
EXTERN_C T_BE208 *func_80062118(void *p);
EXTERN_C void func_80062120(void *p, void *src);
EXTERN_C void func_800BE29C(int *p, int a);
EXTERN_C void func_800BE2EC(int *p, int a);
struct T_BE108 { char pad[0x18]; unsigned short h18; };
struct T_C19BC { char pad[0x1B8]; void *f1B8; char pad1BC[0x2D4]; unsigned short h490; char pad492[0x2A]; signed char b4BC; char pad4BD[0x13]; T_C19BC *f4D0; char pad4D4[0x38]; short s50C; char b50E; };
struct T_C18B4_328 { char pad[0xB8]; char fB8[0x5C]; void *f114; };
struct T_BF414_b { char pad[8]; T_AFA58 *f8[3]; };
struct T_BF414_x { T_AFA58 *e[6]; };
struct T_C1924_e { unsigned char a, b, c, d; };
struct T_C19BC_g { char pad[0x328]; T_C18B4_328 *f328; void *f32C; char pad330[0x80]; T_C1924_e e3B0[32]; };
EXTERN_C void func_800C18B4(T_C19BC *p, int x);
struct T_C435C { int pad0, pad4; int f8; char padC[0x24]; Holder *f30; char pad34[0x10]; char f44[8]; int f4C; int f50; };
struct T_C4510;
EXTERN_C T_C4510 *func_800C4510(T_C4510 *p, SVec4 *pos, int a, int flags);
struct T_C5A30_q { char pad[0x4A0]; char f4A0[4]; char pad4A4[0x20]; signed char b4C4; char pad4C5; short s4C6; short s4C8; short s4CA; };
EXTERN_C char *func_80075448(void *a, void *b);
EXTERN_C void func_80085A60(void *q, SVec2C v);
struct T_It {
    S_800D00B8 *head;
    S_800D00B8 *cur;
    bool empty() { return head == 0; }
    bool last2() { if (empty()) return false; return head->prev == cur; }
    bool is_last() { if (head == 0) return false; return head->prev == cur; }
    void next() { if (!empty()) { if (!last2()) cur = cur->next; } }
};
struct T_C55C4_e { short s0; char b2; signed char b3; };
struct T_C55C4_o { char pad[0x4BC]; signed char b4BC; };
inline int team_of(void *o) { return ((T_C55C4_o *)o)->b4BC; }
struct T_C55C4 : T_It { char pad8[0x108]; T_C55C4_e e110[7]; };
EXTERN_C VTable D_800B7384[];
struct T_BE6B8 { VTable *vtbl; T_Obj0 *f4; T_Obj0 *f8[7]; short s24; short s26; };
struct T_C1158_v { char pad[0x2C]; SVec4 v2C; T_VEC f34; };
EXTERN_C int SquareRoot0(int a);
EXTERN_C int func_80026014(int a);
EXTERN_C int func_800260A4(int a);
struct T_C1158 { char pad[0x1B8]; T_C1158_v *f1B8; char pad1BC[0xE4]; char f2A0[0x230]; T_C1158 *f4D0; };
EXTERN_C int ratan2(int y, int x);
struct T_C47D8_10 { short s[6]; };
struct T_C47D8_1C { int a, b, c; };
struct T_C47D8 { VTable *vtbl; int f4; short s8; short sA; int fC; SVec4 f10; SVec2 f18; T_C47D8_1C f1C[2]; int f34; int f38; };
EXTERN_C VTable D_800111BC[], D_80014BD0[];
struct T_C1E44 { char pad[0x400]; char f400[0x112]; char b512; char b513; };
EXTERN_C int func_80089024(void *p);
EXTERN_C int func_8008906C(void *p);
EXTERN_C int func_800890B4(void *p);
struct T_C5020 { char pad[8]; VTable *vtbl8; char fC[0x1C]; char f28[4]; };
EXTERN_C VTable D_800B75A0[];
EXTERN_C void func_800537C0(void *p);
EXTERN_C void func_800538CC(void *p, char *s, int a);
EXTERN_C void func_80054AF0(void *p, int a);
EXTERN_C void func_80053FB0(void *p, int a, int b);
EXTERN_C void func_80054E18(void *p, void *q);
EXTERN_C void func_80055020(void *p, SVec2C v);
EXTERN_C void func_80054EB4(void *p, int a, int b);
EXTERN_C void func_80054FC0(void *p);
struct T_C5880_e { char pad[0x18]; };
struct T_C5880 { VTable *vtbl; char f4[0xA0]; T_D019C fA4; char pad2C4[0x124]; T_C5880_e a3E8[41]; char pad7C0[0x148]; void *f908; };
EXTERN_C VTable D_800B7748[];
inline void reset_nodes(T_D0054 *p) { S_800D00B8 *l; while ((l = (S_800D00B8 *)func_800751AC(p)) != 0) { l->prev = l; l->next = l; l->fC = 0; } p->f12C = 0; }
EXTERN_C void func_800C1BA8(void *p);
EXTERN_C void func_800D0074(T_D0054 *p);
EXTERN_C void func_800D0588(void *p);
EXTERN_C void func_800C1A44(T_C1A44 *p, int flags);
struct T_BEE50 { char pad[0x10]; unsigned char b10, b11, b12, b13; char pad14[0x10]; unsigned char b24; };
struct T_BEE50_r { unsigned char x, y; short al[0]; };
struct T_BF76C { char pad[0x2A0]; char f2A0[0x160]; char f400[0x80]; unsigned short h480; char pad482[0x32]; int f4B4; unsigned short h4B8; };
EXTERN_C void func_800D8F98(void *p);
EXTERN_C void func_800CAAF8(void *g, void *p, SVec2 *v);
struct T_BF5FC;
EXTERN_C void func_800BF414(T_BF5FC *p);
EXTERN_C int func_800BF5FC(T_BF5FC *p);
struct T_C0694_B {
    char pad[0x9C];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(int a);
};
struct T_C0694 { char pad[0x2A0]; char f2A0[0x160]; char f400[0xAD]; char b4AD; char pad4AE[0xF]; signed char b4BD; char pad4BE[0x12];
    int f4D0; int f4D4; int f4D8; char pad4DC[0x30]; short s50C; char pad50E[0x2E]; short s53C; short s53E; char pad540[0x38]; unsigned char b578[1];
    int bits(int i) { unsigned char *q = &b578[i * 2]; return (unsigned)(q[1] << 8 | q[0]) >> 10; } };
struct T_C0694_e { unsigned char lo, hi; };
inline int e_bits(T_C0694_e *e) { return (unsigned)(e->hi << 8 | e->lo) >> 10; }
EXTERN_C int func_800C9D6C(void *g, void *p, int a, int b, int c, int n);
EXTERN_C void func_80085F90(void *p);
EXTERN_C int func_800BFCB8(T_BFCB8 *p, int *q);
EXTERN_C void func_800BFC18(T_BFCB8 *p);
struct T_C5B4C_q { char pad[0x4BD]; signed char b4BD; char pad4BE[6]; signed char b4C4; };
EXTERN_C void func_80085A08(void *q, SVec4 v, int b);
EXTERN_C void func_800849D0(void *q, T_VEC v, int a, int b);
EXTERN_C void func_800CDED8(T_CE044 *l, SVec2 *v, void *q);
inline void d0230_init(T_D0230 *p) { func_80074F58(p); p->vtblC = D_800B7768; T_D0230_n *e = p->nodes; for (int i = 9; i != -1; i--) { func_80074E28((T_D0338 *)e); e->vtbl8 = D_800B7778; e->fC = 0; e++; } p->f12C = 0; memset(p->pad10, 0xFF, 0x100); memset(p->pad10 + 0x100, 0xFF, 0x1C); }
inline void cfe8c_init(T_CFE8C *p) { SVec2 *q = p->f0; for (int i = 0x22; i != -1; i--) { q->x = 0; q->y = 0; q++; } p->f8C = 0; p->f90 = 0; }
struct T_C56A8 { VTable *vtbl; char f4[0x10]; int f14[7][5]; int fA0; T_D0230 fA4; int f2C4; char pad2C8[0x24]; T_CFE8C f2EC;
    char pad380[0x46]; short s3C6; short s3C8; char pad3CA[2]; int f3CC; int f3D0; int f3D4; char f3D8[0x400]; int f7D8; char pad7DC[0x38];
    int f814; int f818; int f81C; char pad820[0xE0]; int f900; int f904; int f908; char pad90C[0x28]; int f934; int f938; T_VEC v93C; char pad94C[8]; char b954; char b955; };
EXTERN_C void func_800756F8(void *p);
EXTERN_C void func_800C1A10(void *p);
EXTERN_C void func_800CDD0C(void *p);
struct T_BE7A4_v { virtual void v1(); virtual void v2(); virtual int v3(); };
struct T_BE7A4_o { char pad[0xC]; T_BE7A4_v *fC; short s10; short s12; char pad14[8]; unsigned short h1C; };
struct T_BE7A4_c { char a, b; short al[0]; T_BE7A4_c(int x, int y) { a = x; b = y; } };
struct T_BE7A4_8 { char pad[8]; unsigned short h8; };
struct T_BE7A4_e { short x, y, z; };
struct T_BE7A4 { int pad0; T_BE7A4_o *f4; T_BE7A4_8 *f8[8]; int f28; int pad2C; T_BE7A4_e e30[1]; };
EXTERN_C unsigned short func_800BE928(T_BE7A4 *p, unsigned short id);
struct T_BEBE0;
EXTERN_C T_BEBE0 *func_800BEBE0(T_BEBE0 *p, int a, int b, unsigned short c, T_BFB18_t *t, unsigned short d, short *e, short *f, T_BE7A4_c *g, unsigned short h, unsigned short i);
struct T_C4510_pb { unsigned char r, g, b, code; short x, y; int w; };
struct T_C4510_p { int tag; T_C4510_pb b; };
struct T_C4510_q { int tag; int a, b, c; };
struct T_C4510 { VTable *vtbl; int f4; short s8; short sA; int fC; SVec4 f10; SVec2 f18; T_C47D8_1C f1C[2]; unsigned int f34; T_C4510_p *f38; };
EXTERN_C T_BCB6C_c D_800B4CB0[];
EXTERN_C void func_800C4EC4(T_C4510 *p);
EXTERN_C void func_800C4B70(T_C4510 *p, int a, int flags);
typedef void (*F_5F0E4)(void *p, int a);
EXTERN_C T_VEC func_800BF3B4(T_VEC *a, T_VEC *b);
struct T_BF1D0_g { char pad[0x2C8]; T_VEC v2C8; };
EXTERN_C T_VEC func_800BF1D0(void *self, T_VEC *b);
struct T_BEBE0 { VTable *vtbl; int f4; int f8; short sC; short sE; short s10; short s12; T_V0 *f14; void *f18; int f1C; int f20;
    char b24; char b25; char b26; char pad27; T_VEC v28; };
EXTERN_C void func_800BEE50(T_BEBE0 *p, T_BEE50_r *a, T_BEE50_r *b);
EXTERN_C void *func_800B7FFC(void *n, int a, int b, T_BE7A4_c *c, T_BEE50_r *d, T_BEE50_r *e, int f, int g);
struct T_BF5FC_n { char pad[0xC]; short sC; short sE; };
struct T_BF5FC { char pad[0x2A0]; char f2A0[0x21C]; signed char b4BC; signed char b4BD; char pad4BE[2]; void *f4C0; char pad4C4[0x20]; signed char b4E4; };
EXTERN_C void *func_800D7048(void *n, int team, void *a, void *b, void *c, void *d, void *e, void *f);
EXTERN_C void func_80043460(void *p, SVec2C v, int a, int b);
EXTERN_C void func_80043540(void *p, SVec2C v, int a);
struct T_BE7A4;
EXTERN_C void func_800BE7A4(T_BE7A4 *p, int id, void *x, unsigned short d, int e, unsigned short f);
EXTERN_C VTable D_800B73A4[];
struct T_BEDE8 { VTable *vtbl; int pad[4]; T_Obj0 *f14; };
inline int grid_at(T_CFD98 *p, SVec2 v) { return p->f14[v.y][v.x]; }
EXTERN_C void func_800C1BE4(T_C19BC *p, T_C19BC *q);
EXTERN_C void func_800C19BC(T_C19BC *a, int unused, T_C19BC *b);
EXTERN_C void func_800CBB84(void *p);
struct T_C3E34_r { char pad[0x24]; T_BE0F8 e[11]; int pad7C; };
struct T_C3E34 { char pad[0x4BD]; signed char b4BD; char pad4BE[0x7E]; short s53C; short s53E; int f540; char pad544[4]; unsigned short h548; char pad54A[0x12]; T_C3E34_r r[1]; };
inline T_BE0F8 *row_at(T_C3E34_r *r, int j) { return &r->e[j]; }
struct T_C3DAC { char pad[0x14]; T_C3E34_r r; };
struct T_EBD4 { char pad[0x44]; T_BE0F8 e[9]; };
EXTERN_C T_C3E34 *func_800C9E58(void *p, int a);
EXTERN_C T_C3DAC *func_80061188(void *p, int a);
EXTERN_C void func_800C3DAC(T_C3E34 *p, int a, int eq, int *o1, int *o2);
EXTERN_C void func_800C3D2C(T_C3E34 *p, int i, int k, int *o1, int *o2);
EXTERN_C void func_800C3E34(T_C3E34 *p, int i, int j, int *o1, int *o2);
EXTERN_C void func_800C3F14(T_C3E34 *p, int *o1, int *o2);
struct T_C4784_e { char pad[8]; short x, y; char padC[4]; };
struct T_C4784 : T_D47D0_B { char pad4[0x34]; T_C4784_e *f38; };

inline void C3E34_get(T_C3E34_r *r, int j, int *o1, int *o2) {
    *o1 = r->e[j].f0;
    int v = r->e[j].f4;
    *o2 = v;
    if (!v) {
        *o1 = r->e[0].f0;
        *o2 = r->e[0].f4;
    }
}
struct T_C1A6C_n { T_C1A6C_n *next; T_C1A6C_n *prev; };
struct T_C1A6C_o { char pad[0x4BC]; signed char b4BC; };
/* List iterator: head at 0, current at 4; nodes sit at 0x4A0 inside their objects. */
struct T_C1A6C {
    T_C1A6C_n *head;
    T_C1A6C_n *cur;
    bool empty() { return head == 0; }
    bool last2() { if (empty()) return false; return head->prev == cur; }
    bool is_last() { if (head == 0) return false; return head->prev == cur; }
    void next() { if (!empty()) { if (!last2()) cur = cur->next; } }
    T_C1A6C_o *get() { return cur ? (T_C1A6C_o *)((char *)cur - 0x4A0) : 0; }
};
// func_800C3D2C: 10 differ (with own T_EBD4 D_800AEBD4[] decl; battle.h now declares D_800AEBD4 as T_AEBD4[] and the cast form is 31 off): register choice only (i*0x8C in a1 vs a0, loads in a0/v0 vs v0/v1)
//@ func_800BEBE0
EXTERN_C T_BEBE0 *func_800BEBE0(T_BEBE0 *p, int a, int b, unsigned short c, T_BFB18_t *t, unsigned short d, short *e, short *f, T_BE7A4_c *g, unsigned short h, unsigned short i) {
    int hh = h;
    int ii = i;
    p->vtbl = D_800B73A4;
    p->f4 = a;
    p->f8 = b;
    p->sC = c;
    p->sE = d;
    p->s10 = *e;
    p->s12 = *f;
    p->b24 = 0;
    p->b26 = 0;
    T_VEC *v = &p->v28;
    p->v28.x = 0;
    v->y = 0;
    v->z = 0;
    v->w = 0;
    T_V0 *x = func_8003BEF8(operator new(0x4C));
    T_BE390 *gg = D_800B4ED8[0];
    p->f14 = x;
    func_80039BEC((T_B9480_g *)gg, (int)x);
    p->v28 = func_800BF1D0(p, (T_VEC *)t);
    T_C1158_v *fv = (T_C1158_v *)p->f14;
    fv->f34 = p->v28;
    func_80039DD8(fv);
    T_BEE50_r ra, rb;
    func_800BEE50(p, &ra, &rb);
    T_BE7A4_c c2 = *g;
    T_BEE50_r a2 = ra;
    T_BEE50_r b2 = rb;
    p->f18 = func_800B7FFC(operator new(0xA0), 0x40, 0x40, &c2, &a2, &b2, hh, ii);
    p->f14->v5(p->f18);
    char *gl = (char *)&D_800A4534 + 0x10;
    T_BC180 *o = (T_BC180 *)operator new(0x14);
    o->vtbl = D_80010178;
    o->f4 = 0;
    o->vtbl = D_80010338;
    o->sC = 0x80;
    o->f8 = p;
    o->f10 = 1;
    func_8001D150(gl, o);
    p->f20 = 0;
    p->b25 = 0;
    p->f1C = D_800A4534.fC & ~1;
    return p;
}
