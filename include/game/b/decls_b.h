#ifndef GAME_B_DECLS_B_H
#define GAME_B_DECLS_B_H

/* Generated once by tools/hoist_decls.py from the units' inline declarations; edit freely. */

/* from main_b.cpp */
EXTERN_C void func_80053964(void *self, int b);

/* from main_b.cpp */
EXTERN_C void func_80058830(void *self, void *b);

/* from main_b.cpp */
EXTERN_C void func_800581E0(void *self);

/* from main_b.cpp */
EXTERN_C void func_80057F20(void *self, unsigned short b);

/* from main_b.cpp */
EXTERN_C int func_80053880(void *self);

/* from main_b.cpp */
EXTERN_C void func_8005800C(void *self, void *b);

/* from main_b.cpp */
EXTERN_C void func_80019D40(List *l);

/* from main_b.cpp */
EXTERN_C void func_80019A6C(List *l, int b, int c);

/* from main_b.cpp */
EXTERN_C int func_80054048(void *self);

/* from main_b.cpp */
struct SV_80054F30 {
    short x, y, z, w;
};

/* from main_b.cpp */
struct Obj_80054F30 {
    char pad[0x44];
    short a;
    SV_80054F30 v;
    short d;
};

/* from main_b.cpp */
EXTERN_C void func_8005854C(void *self, int a, void *v, int d);

/* from main_b.cpp */
EXTERN_C void func_800550FC(void *self, int b);

/* from main_b.cpp */
struct Heap_800A4578 {
    void *p;
    int pad[2];
};
EXTERN_C Heap_800A4578 D_800A4578;
EXTERN_C void func_8002B27C(void *heap, void *p);

/* from main_b.cpp */
EXTERN_C void *D_800B4D84;
EXTERN_C int func_8001A6E8(void *self);

/* from main_b.cpp */
EXTERN_C void func_80053BCC(void *self, void *b, int c);

/* from main_b.cpp */
struct Rec_800557C8 {
    signed char k;
    char pad[3];
    char data[0x14];
};

/* from main_b.cpp */
struct Pair_800557C8 {
    Rec_800557C8 a;
    Rec_800557C8 b;
};

/* from main_b.cpp */
EXTERN_C char D_80013BA0[];
EXTERN_C char D_80013BB8[];
EXTERN_C void func_8001E508(void *self, int flags);

/* from main_b.cpp */
EXTERN_C int D_800B4D98;

/* from main_b.cpp */
EXTERN_C void func_8001FC78(void *p, int b, int c);

/* from main_b.cpp */
struct Str_800AE620 {
    void *p0;
    int n4;
    void *p8;
    int buf[0x20];
};
EXTERN_C Str_800AE620 D_800AE620;
EXTERN_C void func_80019920(void *a, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005717C(void *self, int a, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005388C(void *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8002A210(void *self);
EXTERN_C void func_80056FE0(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void *func_8002EEC4(void *self, void *b);
EXTERN_C void func_8002BA94(void *self);

/* from u_80056E0C.cpp */
EXTERN_C short D_800B4DA8;
EXTERN_C short D_800B4DAA;

/* from u_80056E0C.cpp */
EXTERN_C void func_80059B5C(void *p, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_80059C54(void *self, int b, int c);
EXTERN_C int func_80059D94(void *self, int b);
EXTERN_C void func_8005CCB0(void *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C int func_80058B98(void *self);
EXTERN_C int func_80058C5C(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void func_80059EF8(void *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_80058F08(VObj<0x2C> *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_80027FEC(void *self, void *b);

/* from u_80056E0C.cpp */
struct V_80059584 {
    int a, b, c, d;
};

/* from u_80056E0C.cpp */
struct Obj_80059584 {
    char pad[0xC];
    V_80059584 v[2];
};

/* from u_80056E0C.cpp */
EXTERN_C void func_8001A610(void *self, int flags);

/* from u_80056E0C.cpp */
struct C4_8005AF70 {
    char v[4];
};

/* from u_80056E0C.cpp */
struct Pair_8005B424 {
    short a;
    short b;
};

/* from u_80056E0C.cpp */
struct Ent_8005B424 {
    int pad[2];
    short a;
    short b;
    int pad2;
};

/* from u_80056E0C.cpp */
struct Obj_8005B424 {
    char pad[0x14];
    Ent_8005B424 *ents;
};

/* from u_80056E0C.cpp */
struct VEnt_8005B560 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

/* from u_80056E0C.cpp */
struct Ent_8005B560 {
    int pad[2];
    short a;
    short b;
    int pad2;
};

/* from u_80056E0C.cpp */
struct Obj_8005B560 {
    VEnt_8005B560 *vt;
    char pad[0x10];
    Ent_8005B560 *ents;
};

/* from u_80056E0C.cpp */
EXTERN_C void *func_8005C26C(void *self, void *b, int c);
EXTERN_C void func_8002A110(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005C1E8(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005C088(void *self, int b, int c);

/* from u_80056E0C.cpp */
struct V_8005C238 {
    char pad[0x2C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

/* from u_80056E0C.cpp */
struct V_8005C344 {
    char pad[0x2C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F1D8(void *self);

/* from u_80056E0C.cpp */
struct VEnt_8005D334 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

/* from u_80056E0C.cpp */
EXTERN_C void *func_8005D754(void *self, void *b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F1D8(void *self);

/* from u_80056E0C.cpp */
struct Entry_8005DF10 {
    char pad[0x30];
    unsigned short x;
    unsigned short y;
};

/* from u_80056E0C.cpp */
struct Entry_8005DF54 {
    char pad[0x2C];
    unsigned char rgb[3];
};

/* from u_80056E0C.cpp */
struct VEnt_8005DF98 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_80056E0C.cpp */
EXTERN_C void *func_8005EF58(void *self, void *b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_80056E0C.cpp */
struct Snd_800AE640 {
    int pad[4];
};
EXTERN_C Snd_800AE640 D_800AE640;
EXTERN_C void func_8005FC78(Snd_800AE640 *self, int b, int c);

/* from u_80056E0C.cpp */
EXTERN_C char D_80010178[];
EXTERN_C char D_800111BC[];
EXTERN_C char D_80014BD0[];

/* from u_80056E0C.cpp */
EXTERN_C void func_8005FB04(Snd_800AE640 *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F8EC(Snd_800AE640 *self);

/* from u_8005F238.cpp */
EXTERN_C void func_8005F3E0(void *self);
EXTERN_C void __builtin_delete(void *p);

/* from u_8005F238.cpp */
EXTERN_C void func_80036D8C(void *p);

/* from u_8005F238.cpp */
EXTERN_C int D_800B4DC8;
EXTERN_C int D_800B4DCC;
EXTERN_C void func_8005F47C(void);

/* from u_8005F238.cpp */
EXTERN_C int D_800B4DC4;

/* from u_8005F238.cpp */
struct Arr_8005F704 {
    int pad[2];
    unsigned int count;
    int *items;
};

/* from u_8005F238.cpp */
EXTERN_C signed char D_800AE66C[0x100];
EXTERN_C signed char D_800AE76C[0x100];

/* from u_8005F238.cpp */
EXTERN_C unsigned int func_80053BB4(void *self);
EXTERN_C void *func_80053AE4(void *out, void *self, int i);
EXTERN_C int func_8005F834(signed char *p);

/* from u_8005F238.cpp */
struct Ev_8005F87C {
    signed char v[8];
};

/* from u_8005F238.cpp */
struct Pair_80060188 {
    short a;
    short b;
};

/* from u_8005F238.cpp */
EXTERN_C void func_80060218(void *self, void *src);

/* from u_8005F238.cpp */
EXTERN_C int func_80060D9C(void *self);

/* from u_8005F238.cpp */
struct Obj_80060D9C {
    char pad[0x124];
    signed char a[0x80];
    signed char b[0x7C];
};

/* from u_8005F238.cpp */
struct Obj_800610E4 {
    char pad[0x120];
    short *out;
    char pad2[0xB0];
    short vals[1];
};

/* from u_8005F238.cpp */
struct Obj_80061114 {
    char pad[0x1D4];
    short vals[1];
};

/* from u_8005F238.cpp */
EXTERN_C void func_8008CC20(int b);

/* from u_8005F238.cpp */
struct Ent_80061164 {
    char pad[0x94];
};

/* from u_8005F238.cpp */
EXTERN_C Ent_80061164 D_800AE984[];

/* from u_8005F238.cpp */
struct Ent_80061188 {
    char pad[0x94];
};

/* from u_8005F238.cpp */
struct Obj_80061188 {
    int pad[2];
    Ent_80061188 cur;
    int sel;
    char pad2[0x184];
    Ent_80061188 e[1];
};

/* from u_8005F238.cpp */
struct Ent_800619F4 {
    char pad[0x94];
};

/* from u_8005F238.cpp */
struct Obj_800619F4 {
    char pad[0x23C];
    Ent_800619F4 e[0x30];
};

/* from u_8005F238.cpp */
struct Ent_800620D8 {
    char pad[0x18];
    unsigned char used;
    char pad2[0x7B];
};

/* from u_8005F238.cpp */
struct Blk_80062120 {
    int v[6];
};

/* from u_8005F238.cpp */
struct Clock_800A4534 {
    int pad[3];
    volatile unsigned int ticks;
};

/* from u_8005F238.cpp */
EXTERN_C Clock_800A4534 D_800A4534;

/* from u_8005F238.cpp */
EXTERN_C void func_80062160(unsigned int *out);

/* from u_8005F238.cpp */
struct Obj_80062214 {
    char pad[0xA0];
    char a[0x80];
};

/* from u_8005F238.cpp */
struct Ent_800AE86C : VObj<0x18> {
};

/* from u_8005F238.cpp */
EXTERN_C Ent_800AE86C D_800AE86C[10];

/* from u_8005F238.cpp */
EXTERN_C void func_80053928(void *self);

/* from u_80062610.cpp */
struct Entry_800627E8 {
    int w[40];
};

/* from u_80062610.cpp */
EXTERN_C Entry_800627E8 *D_800B4E30;

/* from u_80062610.cpp */
EXTERN_C int D_800B4E34;

/* from u_80062610.cpp */
EXTERN_C void func_800566E4(void *self);
EXTERN_C void func_80056874(void *self);

/* from u_80062610.cpp */
EXTERN_C void func_8008EF40(int b);

/* from u_80062610.cpp */
EXTERN_C void func_80054FE0(void *self);
EXTERN_C void func_8008EF40(int b);

/* from u_80062610.cpp */
EXTERN_C void func_800588EC(void *self, unsigned int b);

/* from u_80062610.cpp */
EXTERN_C int func_80058270(void *self, int b);

/* from u_80062610.cpp */
struct Entry_800643DC {
    char pad[0x30];
    unsigned short x;
    unsigned short y;
};

/* from u_80062610.cpp */
struct VEnt_80064428 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

/* from u_80062610.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_800658E0.cpp */
EXTERN_C char D_80015384[];
EXTERN_C void func_80039A88(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_80066054(void *self, int b, int c);

/* from u_800658E0.cpp */
struct Vec_80066220 {
    int x, y, z, w;
};

/* from u_800658E0.cpp */
struct Vec_80066260 {
    int x, y, z, w;
};

/* from u_800658E0.cpp */
struct Vec_80066294 {
    int x, y, z, w;
};

/* from u_800658E0.cpp */
struct SVec_800662D4 {
    short x, y, z, w;
};

/* from u_800658E0.cpp */
EXTERN_C void func_80066128(void *self, int b);

/* from u_800658E0.cpp */
struct Word_80066360 {
    char b[4];
};

/* from u_800658E0.cpp */
struct Quad_80066388 {
    int w[4];
};

/* from u_800658E0.cpp */
EXTERN_C int func_80066C7C(void *self);

/* from u_800658E0.cpp */
EXTERN_C char D_800154B4[];

/* from u_800658E0.cpp */
EXTERN_C char D_800154D4[];

/* from u_800658E0.cpp */
EXTERN_C void func_8001D024(void *self, int b);

/* from u_800658E0.cpp */
struct Mgr_800A4544 {
    int pad[4];
};
EXTERN_C Mgr_800A4544 D_800A4544;
EXTERN_C char D_80010338[];
EXTERN_C void func_8001D150(void *self, void *b);

/* from u_800658E0.cpp */
EXTERN_C short func_8008C928(int b);

/* from u_800658E0.cpp */
EXTERN_C char D_800154EC[];

/* from u_800658E0.cpp */
EXTERN_C void func_80054094(void *self, int b);
EXTERN_C void func_80067B1C(void *self, int b, void *c, void *d, int e);

/* from u_800658E0.cpp */
EXTERN_C void func_8006323C(void *self);
EXTERN_C void func_80053CD8(void *self);

/* from u_800658E0.cpp */
struct E28_80068EE8 {
    char pad[0x28];
};

/* from u_800658E0.cpp */
struct Obj_80068EE8 {
    char pad[0x1548];
    E28_80068EE8 e[0x31];
};

/* from u_800658E0.cpp */
struct E6C_800691EC {
    char pad[0x6C];
};

/* from u_800658E0.cpp */
struct E28_800691EC {
    char pad[0x28];
};

/* from u_800658E0.cpp */
struct Obj_800691EC {
    char pad[0x9C];
    E6C_800691EC a[0x31];
    E28_800691EC b[0x31];
};

/* from u_800658E0.cpp */
EXTERN_C void func_80054FC0(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_80054FE0(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800A0D0C(void *p);

/* from u_800658E0.cpp */
struct Word_8006A04C {
    char b[4];
};

/* from u_800658E0.cpp */
// A field copy returned by value; the FIELD cast form calls memcpy instead.
struct Obj_8006A04C {
    char pad[0x20];
    Word_8006A04C w;
};

/* from u_800658E0.cpp */
EXTERN_C char D_800159C4[];

/* from u_800658E0.cpp */
EXTERN_C void func_8006B3D0(void *self, void *b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B058(void *self, int b);
EXTERN_C void func_8006B180(void *self, int b);
EXTERN_C void func_8006B0C0(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B08C(void *self, int b);
EXTERN_C void func_8006B1C8(void *self, int b);
EXTERN_C void func_8006B120(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B3D0(void *self, void *b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006BB04(void *self);
EXTERN_C void *func_8006D344(void *self, void *b, int c, int d, int e);
EXTERN_C int func_8006D8EC(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8006DA60(void *self);

/* from u_800658E0.cpp */
EXTERN_C void *func_8006C95C(void *self, void *b, int c);
EXTERN_C int func_8006CA80(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B618(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B690(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_800BE09C(void *a);
EXTERN_C void func_800BE18C(void *a, void *b);

/* from u_800658E0.cpp */
struct Tmp_8006B850 {
    int a, b;
};

/* from u_800658E0.cpp */
struct Blk_8006B8E8;
EXTERN_C void func_8006C3C8(void *self, int b, Blk_8006B8E8 *c);

/* from u_800658E0.cpp */
struct Blk_8006B8E8 {
    int v[4];
};

/* from u_800658E0.cpp */
EXTERN_C void func_8006C4EC(void *self, int b);

/* from u_800658E0.cpp */
struct V_8006B928 {
    int v[4];
};

/* from u_800658E0.cpp */
EXTERN_C V_8006B928 func_8003B310(void);

/* from u_800658E0.cpp */
EXTERN_C int func_8006BC98(void *self);
EXTERN_C void *func_800A0D2C(int size);
EXTERN_C void func_80025CE0(void *p, int b, int c);

/* from u_800658E0.cpp */
EXTERN_C void func_8008D4C0(void *p);

/* from u_800658E0.cpp */
EXTERN_C void func_8002DC34(void *self, int b, int c);

/* from u_800658E0.cpp */
EXTERN_C void *func_80066FB0(void *self, void *b, int c, int d, int e);
EXTERN_C int func_800670A4(void *self);

/* from u_800658E0.cpp */
struct Blk_8006BEA0 {
    int v[4];
};

/* from u_800658E0.cpp */

/* from u_800658E0.cpp */
EXTERN_C int D_800B4ED4;

/* from u_800658E0.cpp */
EXTERN_C int D_800B4ED0;

/* from u_800658E0.cpp */
EXTERN_C void func_8002BD34(void *self);
EXTERN_C void func_8003944C(void *self, void *b);

/* from u_800658E0.cpp */
struct Data_800B4D1C {
    int pad[4];
};

/* from u_800658E0.cpp */
EXTERN_C Data_800B4D1C D_800B4D1C;

/* from u_800658E0.cpp */
EXTERN_C void func_8002B518(void *self, int b, int c);

/* from u_800658E0.cpp */
struct Vec_8006C61C {
    int x, y, z, w;
};

/* from u_800658E0.cpp */
EXTERN_C char D_80015DBC[];
EXTERN_C void func_8002EC90(void *self, void *b);
EXTERN_C void func_8002EC40(void *self, void *b);

/* from u_800658E0.cpp */
struct Data_800B4C78 {
    int pad[4];
};

/* from u_800658E0.cpp */
struct Data_800B4C98 {
    int pad[4];
};

/* from u_800658E0.cpp */
EXTERN_C Data_800B4C78 D_800B4C78;
EXTERN_C Data_800B4C98 D_800B4C98;

/* from u_800658E0.cpp */
EXTERN_C void func_8002EEFC(void *self);

/* from u_800658E0.cpp */
EXTERN_C char D_80015EB8[];

/* from u_800658E0.cpp */
EXTERN_C char D_80015FD0[];
struct Sub_8006FDD8 {
    int a, b, c, d;
};
struct Obj_8006FDD8 {
    int a;
    int b;
    int c;
    Sub_8006FDD8 sub;
    int d;
};
EXTERN_C Obj_8006FDD8 *func_8006FDD8(Obj_8006FDD8 *self);
struct Flag_800AF408 {
    int v;
    int pad[2];
};
EXTERN_C Flag_800AF408 D_800AF408;
struct Flag_800AF40C {
    int v;
    int pad[2];
};
EXTERN_C Flag_800AF40C D_800AF40C;

/* from u_800658E0.cpp */
struct VEnt_8006F154 {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

/* from u_800658E0.cpp */
struct VEnt_8006F268 {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

/* from u_800658E0.cpp */
EXTERN_C void func_8006F194(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8006F10C(void *self);

/* from u_800658E0.cpp */
struct Obj_8006F31C {
    int pad0;
    int b;
    char pad8[0x9C];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int b);
};

/* from u_800658E0.cpp */
struct VEnt_8006F35C {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

/* from u_800658E0.cpp */
EXTERN_C void func_8006F268(void *self);

/* from u_800658E0.cpp */
struct Four_8006FE6C {
    int v[4];
};

/* from u_800658E0.cpp */
struct Obj_8006FE6C {
    int a;
    int pad;
    int b;
    Four_8006FE6C s;
    int h;
};

/* from u_800658E0.cpp */
struct Four_8006FEA4 {
    int v[4];
};

/* from u_800658E0.cpp */
struct Obj_8006FEA4 {
    int a;
    int b;
    int c;
    Four_8006FEA4 s;
    int h;
};

/* from u_800658E0.cpp */
EXTERN_C char D_80016280[];
EXTERN_C char D_80016298[];
EXTERN_C void *func_8007778C(void *self);
EXTERN_C void *func_800756F8(void *self);

/* from u_800658E0.cpp */
struct Obj_8006FEEC {
    char pad[0x44];
    short items[0x10];
};

/* from u_800658E0.cpp */
EXTERN_C int func_80077854(void *self, int b, int c);
EXTERN_C void func_80077210(void *self, void *b);
EXTERN_C void func_800766D8(void *self);

/* from u_800658E0.cpp */
struct V_80070440 {
    int a, b, c, d;
};

/* from u_800658E0.cpp */
struct V_8007049C {
    int a, b, c, d;
};

/* from u_800658E0.cpp */
struct V_800704F8 {
    int a, b, c, d;
};

/* from u_800658E0.cpp */
EXTERN_C void func_8007AD14(void *self, int b, int c, int d, int e, int f, int g);

/* from u_800658E0.cpp */
EXTERN_C int func_8007ADCC(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8007D744(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8006F3DC(void *self, int b, int c, int d, int e, int f);

/* from u_800658E0.cpp */
EXTERN_C void func_800DE3B8(void *self, int b, int c, int d, int e, int f, int g);

/* from u_800658E0.cpp */
EXTERN_C void func_8007D6D0(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8007FB30(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8008022C(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800802E0(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C int func_8007FE4C(void *self, int b, int c);

/* from u_800658E0.cpp */
EXTERN_C void func_8007FF58(void *self, int b, int c, int d);

/* from u_800658E0.cpp */
EXTERN_C int func_80080110(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C int func_80080130(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C int func_80080180(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C int func_800801D0(void *self, int b, int c);

/* from u_800658E0.cpp */
EXTERN_C void func_800DF758(void *self, int b, int c, int d);

/* from u_800658E0.cpp */
EXTERN_C void func_800DF938(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DF9A8(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DFB10(void *p);

/* from u_800658E0.cpp */
EXTERN_C void func_8007E214(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8007E30C(void *self);

/* from u_800658E0.cpp */
struct V_800714BC {
    int a, b, c, d;
};

/* from u_800658E0.cpp */
EXTERN_C void func_800DED18(void *self, V_800714BC v);

/* from u_800658E0.cpp */
EXTERN_C void func_800DED9C(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DEDD4(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DEE50(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DEED4(void *self);

/* from u_800658E0.cpp */
EXTERN_C void *func_8006FEEC(void *self);
EXTERN_C void func_8006FF50(void *self, int b, int c, void *d);

/* from u_800658E0.cpp */
EXTERN_C void func_80076EF8(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void *func_80076EA8(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800751AC(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8007505C(void *self, void *node);

/* from u_80071A74.cpp */
EXTERN_C void func_80074F78(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void *func_80074E28(void *self);
EXTERN_C char D_80016270[];

/* from u_80071A74.cpp */
struct Obj_80071BDC {
    char pad[0x1C];
    int list[4];
};

/* from u_80071A74.cpp */
EXTERN_C void func_80074E44(void *self, int flags);

/* from u_80071A74.cpp */
EXTERN_C void func_800777E8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void *func_8003912C(void *self, int b);
EXTERN_C void func_80039BEC(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80039C88(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80072B84(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80074564(void *self);
EXTERN_C void func_80073960(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_800232A0(void *self, void *b);

/* from u_80071A74.cpp */
struct Tgt_80072970 {
    char pad[0x1A4];
    short a;
    short b;
    char pad2[0xB0];
    short c;
};

/* from u_80071A74.cpp */
struct View_80072970 {
    char pad[0x44];
    Tgt_80072970 *p;
};

/* from u_80071A74.cpp */
EXTERN_C void func_80044590(void *self);
EXTERN_C void func_80073960(void *self);

/* from u_80071A74.cpp */
struct Vec_8007460C {
    int x, y, z, w;
};

/* from u_80071A74.cpp */
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *p);

/* from u_80071A74.cpp */
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *p);

/* from u_80071A74.cpp */
struct D_80074744 : VPad<0x1DC>, virtual VObj0 {
};

/* from u_80071A74.cpp */
struct A_80074744 {
    int x;
};

/* from u_80071A74.cpp */
struct B_80074744 : A_80074744 {
    int y;
};

/* from u_80071A74.cpp */
struct Vec_80074C50 {
    int x, y, z, w;
};

/* from u_80071A74.cpp */
EXTERN_C char D_800166A8[];

/* from u_80071A74.cpp */
struct Node_80074E78 {
    Node_80074E78 *next;
    Node_80074E78 *prev;
};

/* from u_80071A74.cpp */
struct Node_80074EA4 {
    Node_80074EA4 *next;
    Node_80074EA4 *prev;
};

/* from u_80071A74.cpp */
struct Node_80074EE8 {
    Node_80074EE8 *next;
};

/* from u_80071A74.cpp */
EXTERN_C void func_80074E78(Node_80074E78 *a, Node_80074E78 *b);

/* from u_80071A74.cpp */
EXTERN_C char D_800166B8[];

/* from u_80071A74.cpp */
struct Node_80074FAC {
    Node_80074FAC *next;
    Node_80074FAC *prev;
};

/* from u_80071A74.cpp */
struct List_80074FAC {
    Node_80074FAC *head;
    Node_80074FAC *cur;
};

/* from u_80071A74.cpp */
EXTERN_C int func_80074EE8(Node_80074EE8 *a);

/* from u_80071A74.cpp */
struct List_80075004 {
    Node_80074E78 *head;
    Node_80074E78 *cur;
    int count;
};

/* from u_80071A74.cpp */
EXTERN_C Node_80074EA4 *func_80074EA4(Node_80074EA4 *head);

/* from u_80071A74.cpp */
EXTERN_C void *func_800752B8(void *self);

/* from u_80071A74.cpp */
struct Node_800753F8 {
    Node_800753F8 *next;
    Node_800753F8 *prev;
};

/* from u_80071A74.cpp */
struct Node_80075620 {
    Node_80075620 *next;
    Node_80075620 *prev;
};

/* from u_80071A74.cpp */
EXTERN_C char D_800167F8[];

/* from u_80071A74.cpp */
struct Obj_80075744 {
    void *vtable;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

/* from u_80071A74.cpp */
EXTERN_C void func_8007589C(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_80075EC8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8003546C(void *a, void *b);
EXTERN_C void func_8003714C(void *a);

/* from u_80071A74.cpp */
EXTERN_C void func_80076370(void *self);

/* from u_80071A74.cpp */
EXTERN_C char D_80016878[];

/* from u_80071A74.cpp */
EXTERN_C char D_80016868[];
EXTERN_C void *func_80074F58(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_80076E60(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800752B8(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800785DC(void *self);
EXTERN_C void *func_80076DC4(void *self);

/* from u_80071A74.cpp */
EXTERN_C int func_80075448(void *self, void *b);

/* from u_80071A74.cpp */
EXTERN_C void func_80078564(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800773B0(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void *func_800774D0(void *self, int b);
EXTERN_C void *func_80077478(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800751AC(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8007505C(void *self, void *node);

/* from u_80071A74.cpp */
EXTERN_C char D_80016BD0[];

/* from u_80071A74.cpp */
EXTERN_C void func_800A0D0C(void *p);

/* from u_80071A74.cpp */
EXTERN_C int func_80077C68(void *self);
EXTERN_C int func_80077EA8(void *self);

/* from u_80071A74.cpp */
EXTERN_C char D_80016BC0[];

/* from u_80071A74.cpp */
EXTERN_C void func_800786A0(void *self);
EXTERN_C void func_80074F78(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_800CB174(void *self, int b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_800CB8EC(void *p);
EXTERN_C void func_8001FC78(void *p, int b, int c);

/* from u_80071A74.cpp */
struct D_80079104 : VPad<0xF8>, virtual VObj0 {
};

/* from u_80071A74.cpp */
EXTERN_C void func_8007A1F4(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007B538(void *p, int b, int c, int d, int e, int f);

/* from u_80071A74.cpp */
struct Base0_80079824 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_80079824 {
    int unk0;
};

/* from u_80071A74.cpp */
struct Derived_80079824 : Base0_80079824, Base1_80079824 {
};

/* from u_80071A74.cpp */
EXTERN_C void func_8007E5B0(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8007EDAC(void *self, int b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_8007A1F4(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C int func_80079F6C(void *self, int k);

/* from u_80071A74.cpp */
EXTERN_C char D_80017370[];

/* from u_80071A74.cpp */
EXTERN_C void func_8007AF04(void *self);

/* from u_80071A74.cpp */
struct List_8007AB78;
EXTERN_C void *func_8007A9DC(List_8007AB78 *l, int x);

/* from u_80071A74.cpp */
struct Set_8007AFD0 {
    int unk0;
    int count;
    int items[3];
};

/* from u_80071A74.cpp */
struct Set_8007B014 {
    int unk0;
    int count;
    int items[3];
};

/* from u_80071A74.cpp */
struct Obj_8007B058 {
    int pad;
    int count;
    void *items[1];
};

/* from u_80071A74.cpp */
EXTERN_C void func_800BFABC(void *self, void *b);

/* from u_80071A74.cpp */
EXTERN_C void func_80019D40(List *l);

/* from u_80071A74.cpp */
struct Global_800B4C18 {
    void *p;
    int pad[2];
};
EXTERN_C Global_800B4C18 D_800B4C18;
EXTERN_C void *func_800758F8(void *self, int b, void *c, void *d);
EXTERN_C void func_8001E848(void *self, void *b);

/* from u_80071A74.cpp */
EXTERN_C void func_800766F8(void *self, int b, int c, int d, int e);

/* from u_80071A74.cpp */
EXTERN_C void func_80076848(void *self, int a1, int a2, int a3);

/* from u_80071A74.cpp */
EXTERN_C void func_8007698C(void *self, int b, int c, int d);

/* from u_80071A74.cpp */
EXTERN_C int func_8007669C(void *self, int b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_800766D8(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_80042430(void *a, void *b, int c, int d);
EXTERN_C void func_8007C070(void *self, int b);

/* from u_80071A74.cpp */
struct Obj_8007BFA8 {
    int pad[2];
    void *items[3];
};

/* from u_80071A74.cpp */
EXTERN_C void func_800CF080(void *a, void *b, int c);

/* from u_80071A74.cpp */
EXTERN_C int func_8007C0A8(void *self, int i);
EXTERN_C int func_8007C3C8(void *p, int i);

/* from u_80071A74.cpp */
EXTERN_C char D_800172E8[];
EXTERN_C char D_800172B0[];
EXTERN_C char D_800172F8[];
EXTERN_C void func_8007A994(void *self, int b);
EXTERN_C void func_8006F0B0(void *self, int flags);

/* from u_80071A74.cpp */
EXTERN_C void func_8007DEE8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007DEE8(void *self, int b);

/* from u_80071A74.cpp */
struct Global_800B4D40 {
    void *p;
    int pad[2];
};
EXTERN_C Global_800B4D40 D_800B4D40;
EXTERN_C void func_8007A400(void *self, int b);
EXTERN_C void func_800518A8(void *a, int b, int c, int d);

/* from u_80071A74.cpp */
EXTERN_C void func_800CEE18(void *a);
EXTERN_C void func_800CEFE8(void *a);

/* from u_80071A74.cpp */
EXTERN_C void func_8007B0C8(void *p);
EXTERN_C void func_8007BB48(void *p, int b, int c);

/* from u_80071A74.cpp */
struct Base0_8007CC14 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_8007CC14 {
    int unk0;
};

/* from u_80071A74.cpp */
struct Derived_8007CC14 : Base0_8007CC14, Base1_8007CC14 {
};

/* from u_80071A74.cpp */
EXTERN_C int func_8007CAA8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007CC60(void *self, int b, int c, int d);

/* from u_80071A74.cpp */
struct Blk_8007D6D0 {
    int v[4];
};
EXTERN_C void func_8006FAC0(void *self, void *a, void *b, void *c, void *d, void *e, void *f, Blk_8007D6D0 g, int h);

/* from u_80071A74.cpp */
EXTERN_C void func_80084B78(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007FE1C(void *self, int b);
EXTERN_C void func_800DE97C(void *self, int b);
EXTERN_C void func_8007DE74(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80084674(void *self);

/* from u_80071A74.cpp */
struct Base0_8007DE74 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_8007DE74 {
    int unk0;
    int unk4;
    void *unk8;
    void *unkC;
    void *unk10;
};

/* from u_80071A74.cpp */
struct Derived_8007DE74 : Base0_8007DE74, Base1_8007DE74 {
};

/* from u_80071A74.cpp */
struct Slot_8007E658 {
    void *p;
    int pad;
};

/* from u_80071A74.cpp */
struct Obj_8007E658 {
    char pad[0x1C4];
    Slot_8007E658 slots[4];
};

/* from u_80071A74.cpp */
EXTERN_C void func_8007D994(void *p);

/* from u_80071A74.cpp */
EXTERN_C int func_8006F52C(void *self, int *a, int *b);

/* from u_80071A74.cpp */
EXTERN_C int func_8006F5B4(void *self, int *a, int *b, int *c);

/* from u_80071A74.cpp */
EXTERN_C int func_8006F570(void *self, int *a, int *b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007DDCC(char *p);

/* from u_80071A74.cpp */
EXTERN_C void func_8007A1F4(void *self, int b);

/* from u_80071A74.cpp */
struct Base0_8007FB30 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_8007FB30 {
    int unk0;
    int unk4;
    void *unk8;
};

/* from u_80071A74.cpp */
struct Derived_8007FB30 : Base0_8007FB30, Base1_8007FB30 {
};

/* from u_80071A74.cpp */
EXTERN_C int func_8007FE4C(void *self, int b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_8001A744(void *self, void *p);

/* from u_80071A74.cpp */
EXTERN_C char D_800171B0[];

/* from u_80071A74.cpp */
EXTERN_C void func_800DF6F0(void *self);

/* from u_80071A74.cpp */
EXTERN_C char D_80017190[];
EXTERN_C void *func_800756F8(void *self);

/* from u_80071A74.cpp */
struct Obj_80080468 {
    void *vtable;
    int unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38;
    int pad[5];
    int unk50, unk54;
};

/* from u_80071A74.cpp */
EXTERN_C void func_80080828(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_800808AC(void *self);
EXTERN_C int func_8008D1F4(int a, int b);
EXTERN_C void func_800806F4(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8008ECB4(int a);
EXTERN_C void func_8007EF90(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_800852DC(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8008316C(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_800DFB10(void *p);

/* from u_80071A74.cpp */
struct Arr_80080D4C {
    char pad[0x8];
    int items[1];
};

/* from u_80071A74.cpp */
// The 0x328 member points at a class whose second base sits at +0xB8; the
// upcast's null check is what retail compiles.
struct Base0_80080D74 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_80080D74 {
    int unk0;
    int unk4;
    int unk8;
};

/* from u_80071A74.cpp */
struct Derived_80080D74 : Base0_80080D74, Base1_80080D74 {
};

/* from u_80071A74.cpp */
EXTERN_C void func_80080828(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8001A610(void *self, int flags);

/* from u_80071A74.cpp */
EXTERN_C char D_800171C0[];

/* from u_80071A74.cpp */
EXTERN_C void func_8001A610(void *self, int flags);

/* from u_80071A74.cpp */
EXTERN_C char D_800171D0[];

/* from u_80071A74.cpp */
struct Cmd_800810B8 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_800810B8 {
    char pad[0x3B0];
    Cmd_800810B8 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_80081114 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_80081114 {
    char pad[0x3B0];
    Cmd_80081114 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_80081190 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_80081190 {
    char pad[0x3B0];
    Cmd_80081190 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_80081204 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_80081204 {
    char pad[0x3B0];
    Cmd_80081204 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_800812E4 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_800812E4 {
    char pad[0x3B0];
    Cmd_800812E4 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_80081350 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_80081350 {
    char pad[0x3B0];
    Cmd_80081350 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_800813BC {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_800813BC {
    char pad[0x3B0];
    Cmd_800813BC q[0x20];
};

/* from u_80071A74.cpp */
EXTERN_C void *memset(void *dst, int c, unsigned int n);

/* from u_80071A74.cpp */
struct Obj_800815B4 {
    char pad[0x8];
    int items[1];
};

/* from u_80071A74.cpp */
EXTERN_C char D_80017360[];

/* from u_80071A74.cpp */
struct Obj_80081620 {
    void *vtable;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

/* from u_80071A74.cpp */
EXTERN_C char D_80017380[];

/* from u_80071A74.cpp */
EXTERN_C char D_800173C0[];

/* from u_80071A74.cpp */
EXTERN_C void func_800817C8(void *self);

/* from u_80071A74.cpp */
EXTERN_C char D_80017390[];
EXTERN_C char D_800173A8[];
struct Global_800AFA88 {
    int v;
    int pad[2];
};
EXTERN_C Global_800AFA88 D_800AFA88;
EXTERN_C void *func_8001E40C(void *self, int b, int c, int d, int e);

/* from u_80071A74.cpp */
struct Obj_80081FF8 {
    void *vtable;
    char pad[0x88];
    void *vt8C;
};

/* from u_80071A74.cpp */
EXTERN_C void *func_80081748(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80081DCC(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80081CB8(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80081BA4(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80081A74(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C int func_80081970(void *self, void *x);

/* from u_80082174.cpp */
EXTERN_C void func_80081820(Global_800AFA74 *p, int a, int b, int c, int d, int e);

/* from u_80082174.cpp */
EXTERN_C void func_800817C8(void *self);

/* from u_80082174.cpp */
struct Obj_80082470 {
    short items[0x1A];
    int unk34;
    int unk38;
};

/* from u_80082174.cpp */
EXTERN_C void func_800824C8(void *self);

/* from u_80082174.cpp */
EXTERN_C unsigned short D_800173E0[][10][16];

/* from u_80082174.cpp */
struct Obj_80082670 {
    short items[0x1A];
    int mode;  /* 0x34 */
};

/* from u_80082174.cpp */
EXTERN_C char D_80017758[];

/* from u_80082174.cpp */
struct Obj_800826C0 {
    void *vtable;
    int unk4;
    char unk8;
    char unk9;
    short unkA;
    int unkC, unk10, unk14, unk18, unk1C, unk20;
};

/* from u_80082174.cpp */
struct Obj_80082714 {
    void *vtable;
    int unk4;
    char unk8;
    char unk9;
    short unkA;
    int unkC, unk10, unk14, unk18, unk1C, unk20;
};

/* from u_80082174.cpp */
EXTERN_C char D_80017748[];

/* from u_80082174.cpp */
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C int func_80083F40(void *self, int id);
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C int func_800833F8(void *self);

/* from u_80082174.cpp */
struct Obj_80083EB4 {
    char pad[0x9A];
    short items[0x20];
};

/* from u_80082174.cpp */
struct Obj_80083ED8 {
    char pad[0x9A];
    short ids[0x20];
};

/* from u_80082174.cpp */
struct Obj_80084090 {
    char pad[0xC];
    int items[1];
};

/* from u_80082174.cpp */
EXTERN_C void func_8001A610(void *self, int flags);

/* from u_80082174.cpp */
struct Obj_800840F8 {
    short items[1];
};

/* from u_80082174.cpp */
EXTERN_C void func_800846EC(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_8003D68C(void *a, int b, void *c, int d, int e);

/* from u_80082174.cpp */
EXTERN_C void func_8008299C(void *p, int b, int c, int d, int e, int f, int g);
EXTERN_C void func_80082E14(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80042838(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80085168(void *self, int b);
EXTERN_C void func_80084F58(void *self, int b);
EXTERN_C void func_80084D58(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_8004377C(void *self, short b);

/* from u_80082174.cpp */
EXTERN_C void func_80043740(void *self, short b);

/* from u_80082174.cpp */
EXTERN_C void func_800437A4(void *self, int b);
EXTERN_C void func_800437CC(void *self, int b, int c, int d);

/* from u_80082174.cpp */
EXTERN_C void func_80039DD8(void *p);

/* from u_80082174.cpp */
EXTERN_C void func_800435AC(void *self, int b, int c);

/* from u_80082174.cpp */
EXTERN_C void func_800CDAC8(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_800CDAE8(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_800832F0(void *self);
EXTERN_C void func_800CF2D0(void *p, int b);

/* from u_80082174.cpp */
struct Base0_80085820 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085820 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085820 : Base0_80085820, Base1_80085820 {
};

/* from u_80082174.cpp */
struct S8_80085A08 {
    char v[8];
};

/* from u_80082174.cpp */
struct Pair_80085A60 {
    short a;
    short b;
};

/* from u_80082174.cpp */
EXTERN_C char D_80017BA4[];

/* from u_80082174.cpp */
struct S4_80085B28 {
    char v[4];
};

/* from u_80082174.cpp */
EXTERN_C char D_80017B94[];

/* from u_80082174.cpp */
EXTERN_C void func_80074F78(void *self, int b);

/* from u_80082174.cpp */
struct Derived_80085D7C;
EXTERN_C void func_80085D7C(Derived_80085D7C *self);
EXTERN_C void func_80085DC0(void *self);
EXTERN_C void func_80085C60(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_8008299C(void *p, int b, int c, int d, int e, int f, int g);

/* from u_80082174.cpp */
struct Base0_80085D7C {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085D7C {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085D7C : Base0_80085D7C, Base1_80085D7C {
};

/* from u_80082174.cpp */
struct Base0_80085DC0 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085DC0 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085DC0 : Base0_80085DC0, Base1_80085DC0 {
};

/* from u_80082174.cpp */
struct Derived_80085F90;
EXTERN_C void func_80085F90(Derived_80085F90 *self);
EXTERN_C void func_80085FD4(void *self);
EXTERN_C void func_80085E74(void *self, int b);

/* from u_80082174.cpp */
struct Base0_80085F90 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085F90 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085F90 : Base0_80085F90, Base1_80085F90 {
};

/* from u_80082174.cpp */
struct Base0_80085FD4 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085FD4 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085FD4 : Base0_80085FD4, Base1_80085FD4 {
};

/* from u_80082174.cpp */
struct Derived_800861A4;
EXTERN_C void func_800861A4(Derived_800861A4 *self);
EXTERN_C void func_800861E8(void *self);
EXTERN_C void func_80086088(void *self, int b);

/* from u_80082174.cpp */
struct Base0_800861A4 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_800861A4 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_800861A4 : Base0_800861A4, Base1_800861A4 {
};

/* from u_80082174.cpp */
struct Base0_800861E8 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_800861E8 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_800861E8 : Base0_800861E8, Base1_800861E8 {
};

/* from u_80082174.cpp */
struct Pair_80086338 {
    short a;
    short b;
};

/* from u_80082174.cpp */
struct Pair_80086350 {
    short a;
    short b;
};

/* from u_80082174.cpp */
struct Quad_80086380 {
    short a;
    short b;
    short c;
    short d;
};

/* from u_80082174.cpp */
struct Vec_800863D0 {
    int v[4];
};

/* from u_80082174.cpp */
struct Obj_8008647C {
    char pad[0x4F6];
    short items[1];
};

/* from u_80082174.cpp */
EXTERN_C char D_80017C00[];
EXTERN_C void func_8001AA28(void *self, int b);

/* from u_80082174.cpp */
struct Vec_80086670 {
    short v[5];
};
struct Pair_800867B0 {
    int a;
    int b;
};
struct Snap_800867B0 {
    unsigned short unk0;
    unsigned short unk2;
    int unk4;
    int unk8;
    Pair_800867B0 unkC;
    Vec_80086670 unk14;
    unsigned char unk1E;
};

/* from u_80082174.cpp */
EXTERN_C Vec_80086670 func_80086670(Vec_80086670 &a, void *b);

/* from u_80082174.cpp */
struct Obj_80086DB4 {
    char pad0[0x6];
    short unk6[5];
    char pad10[0x6];
    short unk16[5];
    char pad20[0x50];
    signed char unk70[5];
    char pad75[0xD];
    char unk82;
};

/* from u_80082174.cpp */
EXTERN_C void func_800898F0(void *self);
EXTERN_C void func_8008655C(short *p);
struct Obj_80086DB4;
EXTERN_C void func_80086DB4(Obj_80086DB4 *self);

/* from u_80082174.cpp */
EXTERN_C void func_80089178(void *self, int b);
EXTERN_C void func_80087880(void *self, int b);

/* from u_80082174.cpp */
struct Hist_80089024 {
    short v[4];
};

/* from u_80082174.cpp */
struct Hist_8008906C {
    short v[4];
};

/* from u_80082174.cpp */
struct Bytes4_800890B4 {
    char c[4];
};

/* from u_80082174.cpp */
EXTERN_C void *func_8008672C(char *p);
EXTERN_C void func_800D9218(void *self, int b);

/* from u_80082174.cpp */
union Col_800899AC {
    unsigned char c[8];
    int w[2];
};
EXTERN_C unsigned char *func_800898FC(unsigned char *a, signed char *b);

/* from u_80082174.cpp */
EXTERN_C unsigned char *func_80089954(unsigned char *a, signed char *b);

/* from u_80082174.cpp */
// Eight bytes divided by d, returned by value. Needs maspsx --expand-div (the ASPSX zero checks).
struct Bytes8_80089A4C { unsigned char b[8]; int align[0]; };

/* from u_80082174.cpp */
EXTERN_C int rand(void);

/* from u_80082174.cpp */
EXTERN_C signed char *func_80089DB8(signed char *a, signed char *b);

/* from u_80082174.cpp */
EXTERN_C signed char *func_80089E14(signed char *a, signed char *b);

/* from u_80082174.cpp */
// Signed twin of func_80089A4C.
struct SBytes8_80089F10 { signed char b[8]; int align[0]; };

/* from u_80082174.cpp */
EXTERN_C void func_80023F50(void *self, int b);

/* from u_80082174.cpp */
struct Base0_80089F84 {
    char pad[0x58];
};

/* from u_80082174.cpp */
struct Base1_80089F84 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80089F84 : Base0_80089F84, Base1_80089F84 {
};

/* from u_80082174.cpp */
struct W20_80089658;
EXTERN_C int func_800870E4(char *self, void *b, W20_80089658 *c, int d);

/* from u_80082174.cpp */
EXTERN_C int func_8008B444(int n);

/* from u_80082174.cpp */
struct Hdr_8008B5B4 {
    int w[9];
};
struct Pair16_8008B5B4 {
    unsigned short a;
    unsigned short b;
};
struct Pair32_8008B5B4 {
    int a;
    int b;
};
struct Packed_8008B5B4 {
    Hdr_8008B5B4 hdr;
    Pair16_8008B5B4 e[9];
};
struct Unpacked_8008B5B4 {
    Hdr_8008B5B4 hdr;
    Pair32_8008B5B4 e[9];
};

EXTERN_C char D_80016808[];
struct Col_80065870 {
    short r, g, b, a;
};
EXTERN_C Col_80065870 D_800B4E38;
EXTERN_C Col_80065870 D_800B4E40;
EXTERN_C Col_80065870 D_800B4E48;
EXTERN_C Col_80065870 D_800B4E50;
EXTERN_C char D_80014C38[];
EXTERN_C void func_8008E504(void *p);
EXTERN_C char D_80013B70[];

EXTERN_C void func_80019CFC(void *l);
EXTERN_C void func_8005BFA4(void *self);
EXTERN_C void func_80059A84(void *self);
EXTERN_C short D_800B4DA6;
EXTERN_C char D_80014548[];
EXTERN_C char D_800145B0[];
EXTERN_C int func_8002EB68(void *self);
EXTERN_C void func_800386B8(void *self, int b);
EXTERN_C void func_80060378(void *self);

struct E16_80059800 {
    int a, b;
    short x, y, z, w;
};

struct S_80059800 {
    char pad[0x8];
    short state;
    short pad2;
    E16_80059800 e[2];
};

struct TILE_B {
    int tag;
    unsigned char r0, g0, b0, code;
    short x0, y0;
    short w, h;
};

struct Blk32 {
    char c[32];
};

struct SV2_80055020 {
    short x, y;
};

EXTERN_C void func_800198E0(void *a, int b, int c);
EXTERN_C unsigned short D_800B4D7C;
EXTERN_C void func_8002B174(void *heap, void *p, int c);
EXTERN_C void func_8005D9D4(void *self, int b);
EXTERN_C void func_8005A020(void *self, int b, int c);
EXTERN_C int func_80059E90(VObj<0x2C> *self, int b);
EXTERN_C int func_80059F00(void *self);
EXTERN_C void func_80058A80(void *self);
EXTERN_C VObj0 *func_80019F64(void *l, int i);
EXTERN_C void *__builtin_new(int size);
EXTERN_C void *func_8005D080(void *self, void *b, int c, int d);
EXTERN_C void func_8002DA94(void *self, void *b);
EXTERN_C short D_800B4E2C;

struct MATRIX_B {
    short m[3][3];
    short pad;
    int t[3];
};
struct V3i_B {
    int x, y, z;
};
struct V3s_B {
    short x, y, z;
};

EXTERN_C void func_80039A14(void *self);
EXTERN_C void func_8003A754(void *self, int b);
EXTERN_C void func_8003AD78(void *self, void *b);
EXTERN_C void func_8003B2F0(void *self, void *b);
EXTERN_C void func_8003BC10(MATRIX_B *m, void *b);
EXTERN_C void SetColorMatrix(MATRIX_B *m);
EXTERN_C void SetBackColor(int r, int g, int b);
EXTERN_C void func_800C0920(void);
EXTERN_C int func_8005409C(void *self);
EXTERN_C void func_800631D4(void *self);
EXTERN_C void func_80099C80(int a);
EXTERN_C int func_8006BCF4(void *self);
EXTERN_C int SquareRoot0(int a);
EXTERN_C int func_80080CC8(void *self, int b);
EXTERN_C void func_8007164C(void *self, void *b);
EXTERN_C int func_80077234(void *self, void *b);

EXTERN_C void func_80063714(void *self, unsigned int b);

struct LNode_B {
    LNode_B *next;
    LNode_B *prev;
};

struct LList_B {
    LNode_B *head;
    LNode_B *cur;
    int count;
};

EXTERN_C char D_80016820[];
EXTERN_C char D_80016830[];
EXTERN_C char D_800120F4[];
EXTERN_C char D_8001211C[];
EXTERN_C char D_80012104[];
EXTERN_C char D_800101C0[];
EXTERN_C char D_800101B0[];
EXTERN_C void func_800198AC(void *self, int b);
EXTERN_C void *func_80077254(void *self);
EXTERN_C void func_8001A678(void *self, void *b);
EXTERN_C void func_800C68D8(void *self, int b);
EXTERN_C void func_800C6DF4(void *self, int b);
EXTERN_C void func_800C7158(void *self, int b);

static inline int at_end_B(LList_B *l)
{
    return l->head ? l->head->prev == l->cur : 0;
}

inline void *operator new(unsigned int, void *p)
{
    return p;
}

struct MsgNode_B {
    void *vt;
    int next;
    MsgNode_B()
    {
        vt = D_80010178;
        next = 0;
    }
};

struct Msg_B : MsgNode_B {
    short type;
    short sub;
    Msg_B(short t, short s)
    {
        vt = D_80010300;
        type = t;
        sub = s;
    }
};

struct MsgArg_B : Msg_B {
    int c;
    int d;
    MsgArg_B(short t, short s, int c_, int d_) : Msg_B(t, s)
    {
        vt = D_800102D0;
        c = c_;
        d = d_;
    }
};

struct V4_80085578 {
    int x, y, z, w;
    V4_80085578(int a, int b, int c, int d) { x = a; y = b; z = c; w = d; }
};

struct B4_80081260 {
    char a, b, c, d;
};

EXTERN_C void func_8008FC38(int a);
EXTERN_C void func_8008ED44(void *p);
EXTERN_C int func_80043700(void *self, int a, void *b, int c);
EXTERN_C void func_80042D3C(void *self);

struct B32_B {
    int w[8];
};
struct B8_B {
    short s[4];
};
struct B16_B {
    int w[4];
};
struct SV4_B {
    short x, y, z, w;
};

EXTERN_C char D_80014278[];
EXTERN_C void func_8002DD34(void *self, void *b, int c);
EXTERN_C SV2_80055020 func_80054054(void);
EXTERN_C int func_80054074(int b);
EXTERN_C void func_8002972C(void *self, int a, int b, int c, int d);
EXTERN_C B8_B *func_80053BC0(void *p);
EXTERN_C void func_80063F3C(void *self);
EXTERN_C void func_8003B35C(MATRIX_B *m, void *b, int c);
EXTERN_C void SetLightMatrix(MATRIX_B *m);
EXTERN_C void func_8003B3EC(MATRIX_B *m, void *b, int c);
EXTERN_C MATRIX_B *ScaleMatrix(MATRIX_B *m, void *v);
EXTERN_C void SetRotMatrix(MATRIX_B *m);
EXTERN_C void SetTransMatrix(MATRIX_B *m);
EXTERN_C void *func_8001D25C(void *self, void *b);
EXTERN_C void func_8001D324(void *self, void *b);
EXTERN_C void func_8001A864(void *self, void *b);
EXTERN_C int ratan2(int y, int x);
EXTERN_C void func_80071C78(void *self, void *b);
EXTERN_C void func_80071D90(void *self, void *b, int c);
EXTERN_C void func_800230E8(void *self, void *b);

struct Iter_B {
    List *l;
    int i;
};

static inline void *iter_next_B(Iter_B *it)
{
    return it->i < it->l->count ? ((void **)it->l->pad)[it->i++] : 0;
}

/* the sub-object at Tgt_80072970 + 0x154 */
struct Sub_80055330 {
    char pad[0x104];
    short v;
};

EXTERN_C void func_80059F0C(void *self, int b);
EXTERN_C void func_8005A784(void *self, int b);
EXTERN_C void func_80055624(void *self, int b);
EXTERN_C int func_80053874(void *self);
EXTERN_C void func_80053848(void *self);
EXTERN_C void func_8005BF04(void *self, int b, int c);
EXTERN_C void func_80098E10(void *self);
EXTERN_C void func_80059800(void *self, int a, int b, int c, int d);
EXTERN_C void func_80059888(void *self, unsigned char *b);
EXTERN_C void func_80059790(void *self);
EXTERN_C void func_8005B378(void *self, int b);
EXTERN_C VObj<0x2C> *func_80063E18(void *self, int a, int b, int c);

EXTERN_C char D_800147A0[];
EXTERN_C char D_80014B00[];
struct Pool_8005F50C {
    void *vt;
    int a4;
    unsigned int n;
    int *data;
    int a10;
};

struct E36_8005C968 {
    int w[9];
};

struct E12_8005DFE8 {
    int w[3];
};

struct C20_80060260 {
    char c[20];
};
struct C16_80060260 {
    char c[16];
};
struct C14_80060260 {
    char c[14];
};

EXTERN_C C20_80060260 D_80014C50;
EXTERN_C C16_80060260 D_80014C68;
EXTERN_C C14_80060260 D_80014C7C;
EXTERN_C short D_800B4DAA;
EXTERN_C int func_8005618C(void *p);

EXTERN_C void func_8005549C(int a, void *b, void *c, int d);
EXTERN_C int func_80053830(void *self);

struct E94_80061AAC {
    int w[37];
};

struct S_80061AAC {
    char pad[0x224];
    E94_80061AAC e[8];
};

EXTERN_C void func_80061CC4(void *self);

struct C690_80062610 {
    char c[0x690];
};

EXTERN_C void *func_8005F238(void *self);
EXTERN_C void func_8005F298(void *self, int b, int c);
EXTERN_C int func_8005F28C(void *self);
EXTERN_C void func_8005F248(void *self, int flags);

EXTERN_C int func_80043700(void *self, int a, void *b, int c);

EXTERN_C void func_80055330(int a);
EXTERN_C int func_80043700(void *self, int a, void *b, int c);

EXTERN_C void func_80055A9C(void *self);
EXTERN_C void *func_8001EB60(void *self, int b);
EXTERN_C void *func_8001ED2C(void *self, void *b, int c);
EXTERN_C void *D_800B4D80;
EXTERN_C void func_80055D78(void *self);
EXTERN_C int func_80055F98(char *x);
EXTERN_C void func_80038654(void *self, void *b, int c);

EXTERN_C void func_8005DEA4(void *self, int b);
EXTERN_C void func_800536F0(void *self, void *b);

struct Ent_8007AB78 {
    LNode_B *next;
    LNode_B *prev;
    int pad8;
    int idC;
    int id10;
};
struct List_8007AB78 {
    LNode_B *head;
    LNode_B *cur;
    bool IsEmpty() { return head == 0; }
    bool IsLast() { return IsEmpty() ? false : head->prev == cur; }
    void Next()
    {
        if (!IsEmpty()) {
            if (!IsLast()) {
                cur = cur->next;
            }
        }
    }
    void First() { cur = head; }
    Ent_8007AB78 *Cur() { return (Ent_8007AB78 *)cur; }
};
struct Arr_8007F434 {
    char pad[0x10C];
    B16_B a[16];
};
struct Arr_8007BB48 {
    char pad[8];
    char *o[3];
};
struct Q4_8007C55C {
    int a, b, c, d;
};
struct Msg_8007EF90 {
    void *vt;
    int next;
    short type;
    short sub;
    int c;
    int d;
};
struct Bits_8007FE4C {
    unsigned char *buf;
    int len;
};

EXTERN_C void func_80078658(void *self);
EXTERN_C void func_8003DEA8(void *p);
EXTERN_C void func_80080530(void *self, int a, int b, int c);
EXTERN_C void func_80080AE8(void *self, int b);
EXTERN_C void func_80080B60(void *self, int b);
EXTERN_C void func_8007BDB4(void *self, int a, int b, int c);
EXTERN_C void *func_8007AB78(List_8007AB78 *l, int x);
EXTERN_C void *func_8007AC38(List_8007AB78 *l, int x);
EXTERN_C void func_8007F434(void *self);
EXTERN_C int func_800785A8(void *self);
EXTERN_C void func_80077444(void *self, int b);
EXTERN_C void *func_80077538(void *self, int b);
EXTERN_C void func_80076DF8(void *self, int flags);
EXTERN_C void func_80078610(void *self, int b);
EXTERN_C void *func_8006F04C(void *self);
EXTERN_C void *func_8007A960(void *self);
EXTERN_C void func_8007AF5C(void *self);
EXTERN_C short func_800729E8(void *self, int b);
EXTERN_C void func_80044990(void *p, int a, int b, int c, int d, int e);
EXTERN_C void func_80035EB4(void *p);
EXTERN_C void func_80075828(void *self, int flags);
EXTERN_C void func_80035304(void *self, int b);
EXTERN_C char D_800167C8[];
EXTERN_C char D_80016740[];
EXTERN_C char D_80016758[];
EXTERN_C char D_80016708[];
EXTERN_C char D_800167E0[];
EXTERN_C char D_80012294[];
EXTERN_C char D_80012224[];
EXTERN_C void func_8007CAB4(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_B s, int a12);
EXTERN_C void func_8007D24C(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_B s, int a12);
EXTERN_C void func_8007589C(void *self);
EXTERN_C void *func_800775F0(void *self);
EXTERN_C int func_800771D4(void *self);
EXTERN_C int func_80076FD8(void *self);
EXTERN_C char D_80016878[];
EXTERN_C void func_800DF604(void *n, V4_80085578 s, int e);
EXTERN_C void *func_800DF37C(void *p, int k, V4_80085578 s, int e);
EXTERN_C void func_80048D54(void *buf);
EXTERN_C int func_80046658(void *buf, int a, int b, void *c);
EXTERN_C int *func_80049398(void *buf);
EXTERN_C void func_80048D2C(void *buf, int f);
EXTERN_C void func_80071E90(void *self);
EXTERN_C int func_8006F630(void);
EXTERN_C void func_80043DC0(void *p);
EXTERN_C void func_80072970(void *self);

static inline int empty_8007768C(void *self)
{
    return FIELD_AT(self, int, 0x0) == 0;
}

static inline void clear_80076EF8(void *l)
{
    FIELD_AT(l, int, 0x4) = FIELD_AT(l, int, 0x0);
    while (!empty_8007768C(l)) {
        func_80076E60(l);
    }
}

static inline bool idle_800770B4(void *self)
{
    return FIELD_AT(self, int, 0x20) == 0 && FIELD_AT(self, int, 0x24) == 0 && FIELD_AT(self, int, 0x10) == 0;
}

EXTERN_C void func_80087764(void *self, void *b, int c);
EXTERN_C void func_80086B70(void *self, int c);
EXTERN_C void func_800890F0(void *self, void *b, int c);
EXTERN_C void func_800874C4(void *self, void *b, int c);
EXTERN_C void func_800D96F8(void *self, void *b, int c);
EXTERN_C void func_8008816C(void *self, void *b, int c);
EXTERN_C void func_80086CAC(void *self, int c);
EXTERN_C void func_80087620(void *self, void *b, int c);
EXTERN_C void func_800873A8(void *self, void *b, int c);
EXTERN_C void func_80087C2C(void *self, void *b, int c, int d);
EXTERN_C void *func_8003CEB4(void *self, void *b);
EXTERN_C Col_800899AC *func_800899AC(Col_800899AC *out, Col_800899AC *a, signed char *b);
EXTERN_C void func_80089D80(unsigned char *p, int n);
EXTERN_C void func_800867B0(void *self, Snap_800867B0 *s);

struct U16_8008B4E8 {
    unsigned short v;
    int hi() { return v >> 10; }
} __attribute__((packed));

EXTERN_C void *func_8001FC38(void *self, int b, void *c, int d);
EXTERN_C void func_8008687C(char *self, int b);
static inline int muldiv2_80086EF0(int a, int b, unsigned char c) { return (long long)a * b / c; }
EXTERN_C void *func_80082798(void *self, int b, int c);

EXTERN_C char D_80017CB4[];
EXTERN_C char D_80010118[];
struct S_8008B084 { char pad[0x20]; unsigned char a; char p; short b; int c; short d[12]; short e[16]; };
struct D_8008B084 { char pad[0x477]; unsigned char a; char p[0x54A - 0x478]; short b; int c; char q[0x560 - 0x550]; short d[12]; short e[16]; };
EXTERN_C Snap_800867B0 *func_80086814(void *self, Snap_800867B0 *s);

EXTERN_C void func_800827C4(void *self, int flags);
EXTERN_C char D_80017690[];

EXTERN_C Obj_80082714 *func_80082714(Obj_80082714 *self, int b, int c, int d, int e, int f, int g);
EXTERN_C void func_8008B5B4(Unpacked_8008B5B4 *d, Packed_8008B5B4 *s);
struct H_80082D44 { char pad[0xDA]; short h[32][2]; };
struct W20_80089658 { int w[5]; };
struct C20_80089658 { char c[20]; };

EXTERN_C Packed_8008B5B4 *func_8008B630(Unpacked_8008B5B4 *s, Packed_8008B5B4 *d);
EXTERN_C int func_80086F94(char *self, void *b, int c);
EXTERN_C int func_800D9048(void *self, int b, int c);
EXTERN_C int func_8008A54C(void *self, int b);
EXTERN_C int func_8008B4E8(U16_8008B4E8 *p, int b);
struct T_8008A858 { char pad[0x560]; U16_8008B4E8 d[12]; U16_8008B4E8 e[16]; };

EXTERN_C unsigned char *func_80089AC0(unsigned char *a, unsigned char *b, unsigned char *c, unsigned int d, unsigned int e, unsigned int f);
EXTERN_C signed char *func_80089B44(signed char *a, signed char *b, signed char *c);
EXTERN_C Vec_80086670 *func_80086578(Vec_80086670 *a, void *b);
EXTERN_C Obj_80082470 *func_80082470(Obj_80082470 *self);
EXTERN_C void *func_80082690(void *self);
EXTERN_C void *func_80082768(void *self);
EXTERN_C void func_80083EB4(Obj_80083EB4 *self);
struct O_800827EC { char pad[0x46]; short d[4]; short e; short f[2]; };

/* defined later in the units, called earlier */
EXTERN_C int func_800560E4(int a);
EXTERN_C void *func_800787B4(void);
EXTERN_C void func_8005D228(void *self, int b);
EXTERN_C int func_8005F87C(void *self);
EXTERN_C Ent_800620D8 *func_800620D8(void *self, unsigned int i);

EXTERN_C void func_80065AD0(void *self);
EXTERN_C void func_80099C60(int a, int b);
struct GW_800B4D00 { int v; int pad[2]; };
EXTERN_C GW_800B4D00 D_800B4D00;
EXTERN_C char D_800153FC[];
EXTERN_C char D_800153C4[];
EXTERN_C char D_80015414[];
EXTERN_C char D_80012294[];
EXTERN_C char D_80012224[];
EXTERN_C void func_80035EB4(void *p);
EXTERN_C void func_80035304(void *self, int b);
EXTERN_C int func_80036FC0(void *self, int a, int b);
EXTERN_C void func_80035DE0(void *p);
EXTERN_C void *func_80066D2C(void *self, int b);
EXTERN_C Vec_80066220 *func_80066220(Vec_80066220 *out, Vec_80066220 *a, Vec_80066220 *b);
EXTERN_C void func_8003A7FC(void *m, void *b);
EXTERN_C void func_8003B450(void *out, void *m, void *v);
struct SV3_80065E10 { short x, y, z; };
struct SV2_80069F74 { short w, h; };

struct SVr_658 { short x, y, z, w; };
struct Vr_658 { int x, y, z, w; };
struct SVp_658 {
    short x, y, z, w;
    SVp_658(const SVr_658 &o) { *(SVr_658 *)this = o; }
    SVp_658(const SVp_658 &o) { *(SVr_658 *)this = *(const SVr_658 *)&o; }
};
struct Vp_658 {
    int x, y, z, w;
    Vp_658(const Vr_658 &o) { *(Vr_658 *)this = o; }
    Vp_658(const Vp_658 &o) { *(Vr_658 *)this = *(const Vr_658 *)&o; }
};
extern SVr_658 sv_neg_658(const SVr_658 *a) __asm__("func_800662D4");
extern Vr_658 v_neg_658(const Vr_658 *a) __asm__("func_80066260");
extern Vr_658 v_sub_658(const Vr_658 *a, const Vr_658 *b) __asm__("func_80066294");
extern void m_rot_658(MATRIX_B *m, SVp_658 r) __asm__("func_8003A7FC");
extern Vr_658 m_apply_658(MATRIX_B *m, Vp_658 v) __asm__("func_8003B450");

struct SV2C_80055020 {
    short x, y;
    SV2C_80055020(short a, short b) : x(a), y(b) {}
};
EXTERN_C void func_80055020(void *self, SV2C_80055020 v);
EXTERN_C void *func_80054F28(void *self);
EXTERN_C void func_8005457C(void *self, int b);
EXTERN_C void func_80053F48(void *self, SV2C_80055020 v);
EXTERN_C void func_80053F28(void *self, SV2C_80055020 v);
EXTERN_C void SetDrawMode(void *p, int a, int b, int c, int d);
EXTERN_C void func_80098DC0(void *p, int b);
EXTERN_C void func_8006EACC(void *self, int a, short b);
EXTERN_C void func_8006EBB0(void *self, int a);
EXTERN_C void func_8006EC70(void *self, int a);
EXTERN_C void func_8006EDD8(void *self, void *b);
EXTERN_C void func_8006EE94(void *self);
EXTERN_C void *func_800787B4(void);
EXTERN_C void *func_8008E360(void *p);
EXTERN_C void func_8008E590(void *p, int a, int b);
EXTERN_C void *func_800663EC(void *self, int vb, void *a, int b, int c, int d);
EXTERN_C int func_800665C8(void *self);
struct Obj_8006E73C { void *vt; int f4; short f8, fA; char pad[0x68]; int f74; };
struct A_80069978 { char b[0x1C]; };
struct B_80069978 { char b[0x28]; };
struct O_80069978 { char pad[0x64]; B_80069978 b[8]; char pad2[0x1A4 - 0x64 - 0x140]; A_80069978 a[8]; };

EXTERN_C void func_8006B350(void *self, int b);
EXTERN_C void func_8006B390(void *self, int b);
EXTERN_C void func_8006B2F8(void *self, int b);
EXTERN_C void func_8006B258(void *self, int b);
EXTERN_C void func_800770B4(void *self, int a1, int a2);
static inline void *copy_80071B24(void *self, void *src)
{
    int *v;
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016270;
    v = (int *)((char *)self + 0x1C);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    FIELD_AT(self, int, 0xC) = FIELD_AT(src, int, 0xC);
    FIELD_AT(self, int, 0x10) = FIELD_AT(src, int, 0x10);
    FIELD_AT(self, int, 0x14) = FIELD_AT(src, int, 0x14);
    FIELD_AT(self, int, 0x18) = FIELD_AT(src, int, 0x18);
    FIELD_AT(self, B16_B, 0x1C) = FIELD_AT(src, B16_B, 0x1C);
    FIELD_AT(self, int, 0x2C) = FIELD_AT(src, int, 0x2C);
    FIELD_AT(self, int, 0x30) = FIELD_AT(src, int, 0x30);
    return self;
}

struct A46_8008316C { char pad[0x46]; short e[4]; };
struct S16_800849D0 { int a, b, c, d; };
struct H16_80086CAC { char pad[0x16]; short h[5]; };

struct B48_658 { int w[12]; };

EXTERN_C char D_80012154[];

EXTERN_C char D_8001201C[];

EXTERN_C char D_80012034[];

EXTERN_C char D_80011FE4[];

EXTERN_C void func_8006A3C0(VObj0 *self, void *b);

EXTERN_C void func_8006A588(VObj0 *self, void *b);

EXTERN_C void func_8006A440(void *self, void *b);

EXTERN_C void func_80098DF0(void *p);

EXTERN_C void func_8006A608(void *self, int b);

EXTERN_C void func_8006A6D4(void *self);

struct Sub_8007192C { int a, b, c; void *vt; };

static inline void sub_copy_8007192C(Sub_8007192C *d, const Sub_8007192C *s, void *vt)
{
    d->vt = D_800166B8;
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->vt = vt;
}

struct B16c_658 { char b[16]; };

struct R8_658 { SV2_80069F74 pos; SV2_80069F74 size; };

static inline SV2_80069F74 pos_658(R8_658 r) { return r.pos; }

struct Rect_658 : SV2_80069F74 { short w2, h2; };

struct SV4_658 { short x, y, z, w; };

struct V3_658 { int x, y, z; };

EXTERN_C int func_80069F74(void *self, int n, SV2_80069F74 s, void *src);

EXTERN_C void func_8002E714(void *self, int b);

EXTERN_C char D_800117A4[];

EXTERN_C void func_8002D780(void *self, SV2_80069F74 p);

EXTERN_C void func_8002D24C(void *self, void *r);

EXTERN_C void func_8002DB50(void *self, int b);

EXTERN_C void ApplyMatrixLV(MATRIX_B *m, void *v, void *out);

struct S_80061F80 {
    char pad[8];
    E94_80061AAC cur;
    int idx;
    char pad2[0x224 - 0xA0];
    E94_80061AAC e[8];
};

EXTERN_C void func_800614BC(S_80061AAC *self, int i);
struct S_800615B4 {
    char pad[0x224];
    E94_80061AAC e[48];
    E94_80061AAC f[8];
};

struct Ent2_80081BA4 {
    LNode_B *next;
    LNode_B *prev;
    int pad[4];
    int id18;
    int id1C;
};

static inline void del_80081A74(List_8007AB78 *l, int x)
{
    if (l->IsEmpty()) {
        return;
    }
    l->First();
    do {
        if (((Ent2_80081BA4 *)l->Cur())->id18 == x) {
            VObj<8> *n = (VObj<8> *)func_800752B8(l);
            if (n != 0) {
                n->v00(3);
            }
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
}

static inline void del2_80081A74(List_8007AB78 *l, int x)
{
    if (l->IsEmpty()) {
        return;
    }
    l->First();
    do {
        Ent2_80081BA4 *c = (Ent2_80081BA4 *)l->Cur();
        bool hit = c->id18 == x || c->id1C == x;
        if (hit) {
            VObj<8> *n = (VObj<8> *)func_800752B8(l);
            if (n != 0) {
                n->v00(3);
            }
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
}

static inline void del3_80081CB8(List_8007AB78 *l, int x)
{
    if (l->IsEmpty()) {
        return;
    }
    l->First();
    do {
        if (((Ent2_80081BA4 *)l->Cur())->id1C == x) {
            VObj<8> *n = (VObj<8> *)func_800752B8(l);
            if (n != 0) {
                n->v00(3);
            }
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
}

EXTERN_C char D_800D5DAC[];

EXTERN_C void func_8007BE44(void *self);

EXTERN_C void func_8007BEA8(void *self, int b, int c, int d, int e);

EXTERN_C void func_8007BF48(void *self, int b, int c, int d);

EXTERN_C int func_8007E658(Obj_8007E658 *self);

EXTERN_C void *func_80075788(void *p, int a, int b, int c, int d);

EXTERN_C void func_80075894(void *self, int b);

EXTERN_C char D_800100F8[];

EXTERN_C char D_80010198[];

EXTERN_C char D_80010348[];

EXTERN_C void *func_8007570C(void *self);

struct E8_8007B5F8 {
    int a;
    int b;
};

struct Tab_8007B5F8 {
    char pad[0x1C0];
    E8_8007B5F8 e[8];
};

struct S_800758F8 {
    short a;
    short b;
    int c;
};

EXTERN_C GlobalWord D_800B4DD0;

EXTERN_C int func_8008FD94(int a);

EXTERN_C void func_80080BC4(void *self, int b);

EXTERN_C void func_80086990(void *self, int n, signed char *first, ...);

EXTERN_C void func_80089804(char *out, char *src, int idx, int lo, int hi);

struct P4_8008B150 { char *p[4]; };

struct E8C_8008A188 { char pad[0x20]; char sub[0x6C]; };

EXTERN_C E8C_8008A188 D_800AEBD4[];

EXTERN_C int func_800872B8(char *self, char *b, int c);

struct C70_800873A8 { char pad[0x70]; signed char v[5]; };

struct V4_658 { int v[4]; };

struct Vx_658 { int x, y, z, w; };

EXTERN_C int func_80058404(void *self, int b);

EXTERN_C void TransRot_32(void *v0, void *v1, int *flag);

EXTERN_C void func_8006AE68(void *self);

EXTERN_C int func_8006BA1C(void *self);

EXTERN_C int func_8006BA64(void *self);

EXTERN_C void func_8006AF94(void *self);

EXTERN_C int func_80069ECC(void *self, int a, int b);

extern int f69F74_658(void *self, int n, SV2C_80055020 s, void *src) __asm__("func_80069F74");

static inline void setm_658(MATRIX_B *m) { SetRotMatrix(m); SetTransMatrix(m); }

EXTERN_C int func_800619F4(Obj_800619F4 *self);

static inline void *h8_80064B3C(char *h)
{
    char *v = h ? h + 8 : 0;
    return v ? *(void **)v : 0;
}

struct H6_80086B70 { char pad[0x6]; short h[5]; };

EXTERN_C SBytes8_80089F10 func_80089F10(signed char *src, int d);

struct Q_80088DEC { char pad[0x6]; short a[5]; char p2[6]; short b[5]; };

EXTERN_C void func_8008691C(void *self);

EXTERN_C unsigned short func_800891C0(void *a, void *b, void *c);

struct S6C_800894AC { int w[0x1B]; };

struct R_800894AC { unsigned short a; unsigned char b; char pad; unsigned short s[6]; };

// Matches only if the header prototype is changed to: int func_80086F94(char *self, void *b, int c)
// (currently decls_b.h has void func_80086F94(void *self, int b, int c); verified with a #define-rename test, scratch_c/ag_u_80082174/_proto_86F94.cpp)
EXTERN_C void func_8008691C(void *self);

EXTERN_C void func_8006F67C(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, V4_80085578 v, int a12);

EXTERN_C void func_8003FC48(void *self);

EXTERN_C void func_800D6740(void *p, int b);

EXTERN_C void func_80084824(void *p, int b);

EXTERN_C void func_80094908(void);

EXTERN_C void func_800798EC(void *self, int b);

static inline int any2_80072CFC(void *self)
{
    return FIELD_AT(FIELD_AT(self, char *, 0x13C), unsigned char, 0x12) != 0 || FIELD_AT(FIELD_AT(self, char *, 0x13C), unsigned char, 0x13) != 0;
}

EXTERN_C void func_8006F0E4(void *self, int b);

EXTERN_C void func_8006F0F4(void *self, int b, int c, int d, int e);

EXTERN_C void func_8006F8B4(void *self, int a1, int a2, int a3, int a4, int a5, int a6, V4_80085578 v, int a11);

EXTERN_C void func_8006FCC0(void *self, int a1, int a2, int a3);

EXTERN_C void func_8007B08C(void *self);

EXTERN_C void func_8007F138(void *self);

EXTERN_C void func_800BCBE8(void *p, int *out);

EXTERN_C void func_800BCC00(void *p, int *out);

EXTERN_C void func_800BCC30(void *p, void *out);

EXTERN_C void func_800BCC18(void *p, void *out);

EXTERN_C void func_80080990(void *self, int a, int b, int c);

EXTERN_C void func_800715B0(void *self, int a, int b, int c);

EXTERN_C void func_8007F0A8(void *self, int a, int b, int c, int d);

EXTERN_C int func_8007D024(void *self, int a, int b, int c);

static inline void shift_8007F138(Arr_8007F434 *self)
{
    int i;
    for (i = 15; i > 0; i--) {
        self->a[i] = self->a[i - 1];
    }
}

// near.cpp: best attempts. Sections marked PROTOFIX match exactly (0 diffs) once the noted
// header prototype/declaration is corrected (verified with the header decl renamed away).
// Types used here (List_8007AB78, V4_80085578, ...) are already in include/game/b/decls_b.h.

EXTERN_C void *func_8005F50C(Pool_8005F50C *self, int a, int b, unsigned int n);
EXTERN_C void func_80078520(void *self, void *p);
EXTERN_C void func_800825FC(short *self, int b);

EXTERN_C int D_800B4CF0_w asm("D_800B4CF0");
struct Q16 { int a, b, c, d; };
struct Q16o { char pad[0xC]; Q16 q; };


EXTERN_C void *D_800B4C18_w asm("D_800B4C18");

struct P_TAG_B { unsigned addr : 24; unsigned len : 8; };
struct S_OtB {
    char pad0[0x10];
    unsigned int count;
    unsigned long *tab;
    int add(P_TAG_B *prim, unsigned int i)
    {
        if (i && i < count) {
            prim->addr = tab[i];
            tab[i] = (unsigned long)prim & 0x00ffffff;
            return 1;
        }
        return 0;
    }
};
EXTERN_C S_OtB *D_800B4CFC;
EXTERN_C int func_8005F1B4(void *self);

struct VE_B { short delta; short index; void (*pfn)(void *, int, int); };

struct V4_B { int x, y, z, w; };

EXTERN_C int func_80060118_i(void *self, int b) asm("func_80060118");
EXTERN_C int func_800600A4_i(void *self, int b) asm("func_800600A4");

struct Rc8 { short x, y, w, h; };
struct Pt4w { short x, y; };
struct U8bw { char c[8]; };
EXTERN_C void *func_8005DD4C(void *p, Rc8 r, int c, int d);
EXTERN_C void *func_80064290(void *p, Pt4w r, int c, int d);

struct VEntB { short d; short i; void *f; };
struct VTabB50 { VEntB e[10]; };
struct S_VBB { VEntB *vt; };
struct S_DtorB { S_VBB *vb; char pad4[0x28]; void **vt2C; };
EXTERN_C const VTabB50 D_80014130;
EXTERN_C const VTabB50 D_80014808;
EXTERN_C const VTabB50 D_800149B8;
EXTERN_C const VTabB50 D_8001506C;
EXTERN_C void *D_80014180[];
EXTERN_C void *D_80014858[];
EXTERN_C void *D_80014A08[];
EXTERN_C void *D_800150BC[];
EXTERN_C const VTabB50 D_80014400;
EXTERN_C void *D_80014450[];

EXTERN_C void func_800537DC(void *self, int b);
EXTERN_C void func_80063BE4(void *self);
EXTERN_C void func_80057558(void *self, int b);
EXTERN_C void func_8005BDA4(void *self, int b);
EXTERN_C const VTabB50 D_800142B8;
EXTERN_C void *D_80014308[];
EXTERN_C const VTabB50 D_8001521C;
EXTERN_C void *D_80015364[];
EXTERN_C void *D_8001526C[];
EXTERN_C const VTabB50 D_80014FFC;
EXTERN_C void *D_8001504C[];
EXTERN_C void *D_80014EEC[];

#endif /* GAME_B_DECLS_B_H */
