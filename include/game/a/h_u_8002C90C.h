#ifndef GAME_A_H_U_8002C90C_H
#define GAME_A_H_U_8002C90C_H

/* Declarations for src/main/u_8002C90C.cpp only. */

struct S_8002C918 { void **vt; int a; };
EXTERN_C void *D_8001178C[];

struct S_Sh4 { short a, b, c, d; };
struct S_Sh2 { short a, b; };
EXTERN_C S_Sh4 D_800AC730[];
EXTERN_C S_Sh2 D_800B4CF4[2];

struct VtE { short delta; short index; void *pfn; };
struct S_VObj { VtE *vt; };
EXTERN_C void func_8001D150(void *sched, void *timer);
EXTERN_C void *func_8001A744(void *list, void *item);
EXTERN_C int func_80019CFC(List *l, void *item);
EXTERN_C void func_8001A864(void *a, void *b);
EXTERN_C void func_8002E7A8(void *p, int flags);
EXTERN_C void *D_80010148[];
EXTERN_C void *D_80010160[];
EXTERN_C void *D_80010338[];
EXTERN_C void *D_800117A4[];
struct S_Timer14 {
    void **vt;
    int unk4;
    void *unk8;
    short unkC;
    int unk10;
    S_Timer14(void *t, short d, int n) { vt = D_80010178; unk4 = 0; vt = D_80010338; unk8 = t; unkC = d; unk10 = n; }
};
struct S_Deleter {
    void **vt;
    int unk4;
    void *operator new(unsigned int n) { return __builtin_new(n); }
    S_Deleter()
    {
        vt = D_80010160;
        unk4 = 1;
        char *g = (char *)&D_800AC57C;
        void *s = g ? g + 0xF8 : 0;
        func_8001D150(s, new S_Timer14(this, 0x80, 1));
    }
};
struct S_DeleteObj : S_Deleter {
    void *obj;
    S_DeleteObj(void *o) { vt = D_80010148; obj = o; }
};
struct S_Drawable { void **vt; char pad[0x60]; void *unk64; };
struct S_Lnk64 { int a; S_Lnk64 *next; };
struct S_PtrVec { void **data; int count; };
struct S_Iter {
    S_PtrVec *l;
    int it;
    void *next() { return it < l->count ? l->data[it++] : 0; }
};
#define DRW(p) ((S_Drawable *)(p))

EXTERN_C void *func_8002E714(void *p, int n);
EXTERN_C void func_8002D24C(void *p, void *rect);
struct S_Pt2 { short x, y; };
struct S_Rect8 { S_Pt2 pos; S_Pt2 size; };
EXTERN_C void func_8002D780(void *p, S_Pt2 pos);
struct S_Blk8 { unsigned char b[8]; };
struct S_8002C9D4 {
    void **vt;
    char pad4[0xC];
    int unk10;
    char pad14[4];
    int unk18;
    int unk1C;
    S_Blk8 blk20;
    short unk28;
    short unk2A;
    int unk2C;
    int unk30;
    char pad34[0x30];
    void *unk64;
    S_8002C9D4(const S_8002C9D4 &src);
    S_8002C9D4(const S_8002C9D4 &src, S_Rect8 *rect);
};

#endif /* GAME_A_H_U_8002C90C_H */
